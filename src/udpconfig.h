#ifndef UDPCONFIG_H
#define UDPCONFIG_H

#include <QDialog>
#include <QVariant>
#include <QHostAddress>
#include <QFileDialog>

namespace Ui {
class UDPConfig;
}

// This is the UDP Socket Configuration
class UDPConfig : public QDialog
{
    Q_OBJECT

public:
    explicit UDPConfig(QWidget *parent = 0);
    ~UDPConfig();
    struct udpconfig {
        QVariant MyIPAddress;
        QVariant Port;
        QVariant LogFolder;
    };
    QFileDialog *myFolder;
    udpconfig config;

private:
    Ui::UDPConfig *ui;
    void accept();
};

#endif // UDPCONFIG_H
