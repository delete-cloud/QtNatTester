#include "nat_detect.h"

QString logMessage; // 存放日志信息
QString localEndPoint = "";
QString publicEndPoint = "";

static void customLogWriter(int level, const char *buffer, int len){
    Q_UNUSED(level);
    QString logMsg = QString::fromUtf8(buffer, len);
    if(logMsg.contains("Local address is")){
        QRegularExpression re("Local address is ([\\d\\.]+):(\\d+)");
        QRegularExpressionMatch match = re.match(logMsg);
        if (match.hasMatch()) {
            localEndPoint = match.captured(1) + ":" + match.captured(2);
        }
    }

    if(logMsg.contains("CHANGED-ADDRESS: length=8, IPv4 addr")){

        if(publicEndPoint == ""){
            publicEndPoint = extractPubLicIpAddressAndPort(logMsg);
        }
    }
    logMessage.append(logMsg);
}

static QString extractPubLicIpAddressAndPort(const QString &input) {
    QRegularExpression re("MAPPED-ADDRESS: length=\\d+, IPv4 addr=([\\d\\.]+:\\d+)");
    QRegularExpressionMatch match = re.match(input);
    if (match.hasMatch()) {
        return match.captured(1);
    } else {
        return QString();
    }
}

static void my_nat_detect_callback(void *user_data, const pj_stun_nat_detect_result *res) {
    NatDetect *detector = reinterpret_cast<NatDetect*>(user_data);

    // 获取日志信息
    QString logMsg = logMessage;
    if (res->status == PJ_SUCCESS) {
        QString natType = pj_stun_get_nat_name(res->nat_type);

        // 在主线程中发出信号
        QMetaObject::invokeMethod(detector, "natDetectionFinished",
                                  Qt::QueuedConnection,
                                  Q_ARG(QString, natType),
                                  Q_ARG(QString, logMsg));

    } else {
        // 在主线程中发出信号表明检测失败
        QMetaObject::invokeMethod(detector, "natDetectionFinished",
                                  Qt::QueuedConnection,
                                  Q_ARG(QString, "Detection failed"),
                                  Q_ARG(QString, logMsg));
    }

    detector->stopNatDetection();
}

NatDetect::NatDetect(QObject *parent)
        : QObject(parent), pool(nullptr), ioqueue(nullptr), timer_heap(nullptr), continue_polling(false) {
    // 初始化 PJNATH 和设置配置
    pj_init();
    pjlib_util_init();
    pjnath_init();

    pj_log_set_log_func(customLogWriter);

    pj_caching_pool_init(&cp, &pj_pool_factory_default_policy, 0);
    pool = pj_pool_create(&cp.factory, "nat_detect", 512, 512, NULL);
    pj_timer_heap_create(pool, 100, &timer_heap);
    pj_ioqueue_create(pool, 32, &ioqueue);
    pj_stun_config_init(&cfg, &cp.factory, 0, ioqueue, timer_heap);
}

NatDetect::~NatDetect() {
    // 清理资源
    if (continue_polling) {
        stop_event_loop();
        std::cout << "Event loop stopped" << std::endl;
    }
    pj_timer_heap_destroy(timer_heap);
    pj_ioqueue_destroy(ioqueue);
    pj_pool_release(pool);
    pj_caching_pool_destroy(&cp);
    pj_shutdown();
}

void NatDetect::startNatDetection() {
//    logMessage.clear();
    // 开始 NAT 检测逻辑和事件循环
    onNatDetect(server, port);
}

void NatDetect::onNatDetect(const QString& server, int port) {
    // 实现 NAT 检测逻辑并调用回调函数
    pj_status_t status;
    char* serverStr = (char *)server.toStdString().c_str();
    pj_str_t stunServer = pj_str(serverStr); // 设置STUN服务器地址
    pj_sockaddr_in server_addr;

    // 解析STUN服务器地址
    status = pj_sockaddr_in_init(&server_addr, &stunServer, port); // STUN服务器端口
    if (status != PJ_SUCCESS) {
        std::cerr << "Error initializing stunServer address" << std::endl;
        return;
    }else {
        std::cout << "Server address initialized" << std::endl;
    }

    // 调用 pj_stun_detect_nat_type 启动 NAT 检测
    status = pj_stun_detect_nat_type(&server_addr, &cfg, (void *)this, my_nat_detect_callback);
    if (status != PJ_SUCCESS) {
        std::cerr << "Error starting NAT detection" << std::endl;
        return;
    }

    std::cout << "NAT Detection started" << std::endl;

    // 启动事件循环处理异步事件
    start_event_loop();
}

void NatDetect::start_event_loop() {
    continue_polling = true;

    pj_time_val timeout = {0, 50};

    while (continue_polling) {
        pj_ioqueue_poll(ioqueue, &timeout);
        pj_timer_heap_poll(timer_heap, &timeout);
    }

}

void NatDetect::stop_event_loop() {
    continue_polling = false;
}

void NatDetect::stopNatDetection() {
    stop_event_loop();
}

void NatDetect::setServerAndPort(const QString &server, int port) {
    // 设置 STUN 服务器和端口
    this->server = server;
    this->port = port;
}

[[maybe_unused]] const QString& NatDetect::customLog(int level, const char *buffer, int len) {
    Q_UNUSED(level);
    // 将日志信息发送到GUI线程
    QString logMsg = QString::fromUtf8(buffer, len);
    emit logReceived(logMsg);  // 假设这是一个自定义的信号
}


