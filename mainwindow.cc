#include "mainwindow.h"
#include "nat_detect_thread.h"
#include <QVBoxLayout>
#include <QFormLayout>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMap>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

    // 设置界面
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    QFormLayout *formLayout = new QFormLayout();

    // STUN 服务器和端口的映射,目前只支持 UDP， IPV4的 STUN 服务器， 标准为RFC 3489
    serverPortMap["stun.miwifi.com"] = "3478";
    serverPortMap["stun.qq.com"] = "3478";
    serverPortMap["stun.syncthing.net"] = "3478";


    // 创建界面元素
    serverComboBox = new QComboBox(this);
            foreach (const QString &server, serverPortMap.keys()) {
            serverComboBox->addItem(server);
            }

    natTypeLineEdit = new QLineEdit(this);
    natTypeLineEdit->setReadOnly(true);

//    localEndPointLineEdit = new QLineEdit(this);
//    localEndPointLineEdit->setReadOnly(true);
//    publicEndPointLineEdit = new QLineEdit(this);
//    publicEndPointLineEdit->setReadOnly(true);

    formLayout->addRow(new QLabel("STUN服务器:"), serverComboBox);
    formLayout->addRow(new QLabel("NAT类型:"), natTypeLineEdit);
//    formLayout->addRow(new QLabel("本地地址:"), localEndPointLineEdit);
//    formLayout->addRow(new QLabel("公网地址:"), publicEndPointLineEdit);

    getButton = new QPushButton("检测");
    connect(getButton, &QPushButton::clicked, this, &MainWindow::onGetButtonClicked);

    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(getButton);

////    QThread *thread = new QThread(this);
//    natDetectThread = new NatDetectThread(this);
//    natDetectThread->moveToThread(natDetectThread);
////    connect(natDetectThread, &NatDetectThread::startNatDetection, this, &MainWindow::onGetButtonClicked);
////    connect(this, &MainWindow::onGetButtonClicked, natDetectThread, &NatDetectThread::startNatDetection);
//    connect(natDetectThread, &NatDetectThread::natDetectionFinished, this, &MainWindow::updateNatDetectionResults);
}


void MainWindow::onGetButtonClicked() {
    // 确保 comboBox 和 getButton 被禁用，防止重复点击
    serverComboBox->setEnabled(false);
    getButton->setEnabled(false);

    // 获取用户选择的 STUN 服务器和端口
    QString server = serverComboBox->currentText();
    QString portStr = serverPortMap.value(server);
    int port = portStr.toInt();

    // 创建 NAT 检测线程
    NatDetectThread* natDetectThread = new NatDetectThread(this);
    natDetectThread->setServerAndPort(server, port);

    // 将线程的完成信号连接到主窗口的更新函数
    connect(natDetectThread, &NatDetectThread::natDetectionFinished, this, &MainWindow::updateNatDetectionResults);
    connect(natDetectThread, &QThread::finished, natDetectThread, &QObject::deleteLater);

    // 启动线程
    natDetectThread->start();
}


void MainWindow::updateNatDetectionResults(const QString &natType, const QString &localAddress, const QString &publicAddress) {
    // comboBox与getButton设置为可选
    serverComboBox->setEnabled(true);
    getButton->setEnabled(true);

    // 更新界面上的 NAT 检测结果
    natTypeLineEdit->setText(natType);
//    localEndPointLineEdit->setText(localAddress);
//    publicEndPointLineEdit->setText(publicAddress);
}
