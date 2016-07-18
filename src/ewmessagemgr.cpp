#include "ewmessagemgr.h"

EWMessageMgr::EWMessageMgr(QObject *parent) :
    QObject(parent)
{
    Start = false;
    mutex = new QMutex;
}

EWMessageMgr::~EWMessageMgr(){
    delete mutex;
}

// This function is meant to procces the UDP Packets, a different (but similar) funcion will be created for the TCP packets
// A Mutex is passed to StnInfo so that the data is not deleted before it is proccesed, it is a safety, but not needed.
void EWMessageMgr::proccess_UDPpacket(PACKET packet, QByteArray data)
{

    // If the Packet is Complete
    if (packet.lastOfMsg && packet.fragNum == 0 ) {

        // Declare a new K2infoPacket, put the Package payload bay in there
        MyK2Info = new K2infoPacket;
        memcpy(MyK2Info, &packet.text, data.size()-UDP_HDR);

        // If it's a K2 regular status packet
        if(MyK2Info->k2info.data_type==2) {

            // Initialize Structures
            STATUS_INFO        *MyK2Stat;
            MyK2Head = new K2INFO_HEADER;
            MyK2Stat = new STATUS_INFO;

            // Extract Info and put it back into a data structure
            memcpy(MyK2Head,data.mid(UDP_HDR,sizeof(K2INFO_HEADER)).data(),sizeof(K2INFO_HEADER));
            memcpy(MyK2Stat,data.mid(sizeof(K2INFO_HEADER)+UDP_HDR).data(),sizeof(STATUS_INFO));
            // Finish Extraction

            // Update UI
            emit exportK2Status(MyK2Head, MyK2Stat, mutex);
            mutex->lock();

            // Destroy Structures
            delete[] MyK2Head;
            delete[] MyK2Stat;
        }

        // If its a K2 extended status packet v2
        if(MyK2Info->k2info.data_type==4) {

            // Initialize Structures
            EXT2_STATUS_INFO   *MyK2Stat2;
            MyK2Head  = new K2INFO_HEADER;
            MyK2Stat2 = new EXT2_STATUS_INFO;

            // Extract Info and put it back into a data structure
            memcpy(MyK2Head  ,data.mid(UDP_HDR,sizeof(K2INFO_HEADER)).data(),sizeof(K2INFO_HEADER));
            memcpy(MyK2Stat2 ,data.mid(sizeof(K2INFO_HEADER)+UDP_HDR).data(),sizeof(EXT2_STATUS_INFO));
            // Finish Extraction

            // Update UI
            emit exportK2Status2(MyK2Head,MyK2Stat2, mutex);
            mutex->lock();

            // Destroy Structures
            delete[] MyK2Head;
            delete[] MyK2Stat2;
        }

        // Delete K2infoPacket
        delete[] MyK2Info;
    }

    // If not it must be the super long Params Packet ... sigh
    if (packet.fragNum == 0 && !packet.lastOfMsg) {

        // Declare a new K2infoPacket, put the Package payload bay in there
        MyK2Info = new K2infoPacket;
        memcpy(MyK2Info, &packet.text, data.size()-UDP_HDR);

        //Clear our Memory
        MyK2HDR.clear();

        // Declare a new K2HDR Array, put the Package payload in there
        MyK2HDR.resize(data.size()-UDP_HDR);
        memcpy(MyK2HDR.data(),data.mid(UDP_HDR),data.size()-UDP_HDR);

        //We Have begun
        Start = true;

        // Destroy K2infoPacket
        delete[] MyK2Info;

    }

    // The continuation of the last Params Packet
    if (packet.fragNum == 1 && packet.lastOfMsg) {

        if (Start == true) { //yes we did begin this is the continuation, (Remember to code in continuity ie check packet num)
            int nsize = data.size()-UDP_HDR;
            int csize = MyK2HDR.size();

            // Tack on the previous package Info
            MyK2HDR.resize(csize+nsize);
            MyK2HDR.append(data.mid(UDP_HDR).data());

            // Create a the K2INFO Header again and Initialize a new K2_HEADER Instance
            MyK2Head = new K2INFO_HEADER;
            K2_HEADER *MyK2HDS;
            MyK2HDS = new K2_HEADER;

            // Extract the information
            memcpy(MyK2Head,MyK2HDR.data(), sizeof(K2INFO_HEADER));
            memcpy(MyK2HDS,MyK2HDR.mid(sizeof(K2INFO_HEADER)).data(), sizeof(K2_HEADER));
            // Finish Extraction

            // Update UI
            emit exportK2HeaderS(MyK2Head, MyK2HDS, mutex);
            mutex->lock();

            delete[] MyK2Head;
            delete[] MyK2HDS;
            Start = false;
        }

        else if (Start == false){ // We lost a packet.
            MyK2HDR.clear();
            Start = false;
        }

    }

}

