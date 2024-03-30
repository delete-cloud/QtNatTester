#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QMap>
#include <QTextEdit>
#include "nat_detect_thread.h"

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void updateNatDetectionResults(const QString &natType, const QString &logMsg);

signals:
    void natDetectionResults(const QString &natType, const QString &localAddress, const QString &publicAddress);

private slots:
    void onGetButtonClicked();

private:
    QComboBox *serverComboBox;
    QLineEdit *natTypeLineEdit;
    QLineEdit *localEndPointLineEdit;
    QLineEdit *publicEndPointLineEdit;
    QPushButton *getButton;
    QMap<QString, QString> serverPortMap;
    QTextEdit *logWidget;

//    NatDetect *natDetect;
//    NatDetectThread *natDetectThread;


    void setupUi();
};

#endif // MAINWINDOW_H
