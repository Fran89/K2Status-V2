#ifndef K2UDPSOCK_H
#define K2UDPSOCK_H
#include <QUdpSocket>
#include <QByteArray>
#include <QDebug>
#include "ewmessagemgr.h"
#include "include/ew_packet.h"


// This socket connect to a UDP Port and Transmits Recieved Packages to the EW Message Manager
class K2UDPSock : public QUdpSocket
{
    Q_OBJECT
public:
    K2UDPSock(QObject *parent = 0);
    K2UDPSock(const QUdpSocket &);
    void setupEWMsgMgr(EWMessageMgr *EWmsgMgr);

public slots:
    void setDebug(bool pdebug);

private:
    EWMessageMgr *msgMgr;
    bool debug;
    bool msgsetup;

private slots:
    void proccessData();

signals:
    void debugMessage(QString);

};

#endif // K2UDPSOCK_H
