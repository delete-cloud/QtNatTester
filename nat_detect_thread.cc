#include "nat_detect_thread.h"

NatDetectThread::NatDetectThread(QObject *parent) : QThread(parent) {
    natDetect = new NatDetect(this);
//    natDetect->moveToThread(this);
    connect(this, &NatDetectThread::startNatDetection, natDetect, &NatDetect::startNatDetection);
    connect(natDetect, &NatDetect::natDetectionFinished, this, &NatDetectThread::natDetectionFinished);
}

void NatDetectThread::setServerAndPort(const QString &server, int port) {
    natDetect->setServerAndPort(server, port);
}

void NatDetectThread::run() {
    pj_thread_desc initdec;
    pj_thread_t* thread = nullptr;
    pj_status_t status;

    // 检查线程是否已注册
    if (!pj_thread_is_registered()) {
        pj_bzero(&initdec, sizeof(initdec));
        status = pj_thread_register("NatDetectThread", initdec, &thread);
        if (status != PJ_SUCCESS) {
            // 处理错误
            std::cout << "线程注册失败\n";
            return;
        }
        std::cout << "线程注册成功\n";
    }

    startNatDetection();
//    exec();
}
