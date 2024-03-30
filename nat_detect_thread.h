#ifndef NATTYPETEST_NAT_DETECT_THREAD_H
#define NATTYPETEST_NAT_DETECT_THREAD_H

#include <QThread>
#include "nat_detect.h"

class NatDetectThread : public QThread {
Q_OBJECT
public:
    explicit NatDetectThread(QObject *parent = nullptr);

    void setServerAndPort(const QString &server, int port);

signals:
    void startNatDetection();
    void natDetectionFinished(const QString &natType, const QString &logMsg);

protected:
    void run() override;

private:
    NatDetect *natDetect = nullptr;
    QString server;
    int port;
};


#endif
