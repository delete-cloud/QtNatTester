#ifndef NATDETECT_H
#define NATDETECT_H

#include <QObject>
#include <QThread>
#include <pjlib.h>
#include <pjlib-util.h>
#include <pjnath.h>
#include <pj/log.h>
#include <iostream>

static void customLogWriter(int level, const char *buffer, int len);

class NatDetect : public QObject {
Q_OBJECT

public:
    explicit NatDetect(QObject *parent = nullptr);
    virtual ~NatDetect();

    void startNatDetection();
    void stopNatDetection();
    void setServerAndPort(const QString &server, int port);
    const QString& customLog(int level, const char *buffer, int len);

signals:
    void natDetectionStarted();
    void natDetectionFinished(const QString &natType, const QString &localAddress, const QString &publicAddress);
    void logReceived(const QString &logMessage);

private:
    void onNatDetect(const QString& server, int port);
    void start_event_loop();
    void stop_event_loop();

    pj_pool_t *pool;
    pj_ioqueue_t *ioqueue;
    pj_timer_heap_t *timer_heap;
    pj_caching_pool cp;
    pj_stun_config cfg;
    volatile bool continue_polling;

    QString server;
    int port;
};

#endif
