#include "k2udpsock.h"


K2UDPSock::K2UDPSock(QObject *parent) :
    QUdpSocket(parent)
{
    // Set Debug
    debug = false;
    msgsetup = false;
    // Message Manager
    connect(this,SIGNAL(readyRead()),this,SLOT(proccessData()));

}

// Pass pending datagram to EW Message Manager for proccessing
void K2UDPSock::proccessData(){
    // To be executed if we have recieved a UDP Packet
    while (this->hasPendingDatagrams()) {
        // Declare EW Packet and some QByteArrays
        PACKET packet;
        QByteArray data;
        data.resize(this->pendingDatagramSize());

        // Get the Packet put the data in an Array
        this->readDatagram(data.data(),data.size());
        memcpy(&packet,data,data.size());

        if (msgsetup)
            msgMgr->proccess_UDPpacket(packet,data);

    }
}

// Are we debbuging (not needed anymore)
void K2UDPSock::setDebug(bool pdebug)
{
    debug = pdebug;
}

// Setup the EW Msg Manager
void K2UDPSock::setupEWMsgMgr(EWMessageMgr *EWmsgMgr)
{
    msgMgr = EWmsgMgr;
    msgsetup = true;
    emit debugMessage("Message Manager has been setup succesfully");
}
