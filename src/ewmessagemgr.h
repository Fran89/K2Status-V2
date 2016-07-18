#ifndef EWMESSAGEMGR_H
#define EWMESSAGEMGR_H

#include <QObject>
#include <QByteArray>
#include <QMutex>
#include "include/ew_packet.h"
#include "include/k2info.h"
#include "include/k2pktdef.h"
#include "include/nkwhdrs.h"
#include "include/TableDef.h"

// This EW Message Manager Recieves data from the UDP Server (or TCP Server, when implemented) and send the resulting K2 Packets to Station Info (StnInfo)
class EWMessageMgr : public QObject
{
    Q_OBJECT
public:
    EWMessageMgr(QObject *parent = 0);
    ~EWMessageMgr();
    void proccess_UDPpacket(PACKET packet, QByteArray data);

private:
    K2infoPacket  *MyK2Info;
    K2INFO_HEADER *MyK2Head;
    QByteArray     MyK2HDR;
    QMutex *mutex;
    bool Start;
signals:
    void exportK2Status (K2INFO_HEADER*,STATUS_INFO*, QMutex*);
    void exportK2Status2(K2INFO_HEADER*,EXT2_STATUS_INFO*, QMutex*);
    void exportK2HeaderS(K2INFO_HEADER*,K2_HEADER*, QMutex*);
};

#endif // EWMESSAGEMGR_H
