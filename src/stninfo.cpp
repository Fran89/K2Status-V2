#include "stninfo.h"

StnInfo::StnInfo(QObject *parent) : QObject(parent)
{
    temp = new QMutex;
}
StnInfo::~StnInfo(){
    delete temp;
}

// Recieves K2 Status Info
void StnInfo::recieveK2Status(K2INFO_HEADER *header, STATUS_INFO *status, QMutex *mutex)
{
    StaInfo* myStation;
    myStation = stationIndex(header);
    if (myStation == NULL)
        return;

    // Set Serial Number
    //qint32 Serial;
    //Serial = qFromBigEndian<quint32>(info->serialNumber); // I'm not sure I need to convert it
    myStation->Serial = status->serialNumber;

    // Set Time
    time_t Time;
    Time = (time_t)(qFromBigEndian<quint32>(status->systemTime) + K2_TIME_CONV);
    myStation->LatestTime = Time;
    myStation->LatestDateTime.setTime_t(myStation->LatestTime);
    emit debugMessage(myStation->LatestDateTime.toString("dd/MM/yy HH:mm:ss:zzz"));

    // Set Time Source
    myStation->TimeSrc = status->clockSource;

    // Set HW Status
    if(status->hardwareStatus == SF_OK)
        myStation->LatestHWStatus = true;
    else
        myStation->LatestHWStatus = false;

    //Battery Status
    // K2 says battery voltage is zero when it is charging
    int tempbat;
    tempbat = (int) status->batteryStatus;
    if (tempbat > 0)
        myStation->LatestBTStatus = 0;
    else
        myStation->LatestBTStatus = 1;

    // Drive Status
    unsigned short wtemp1, wtemp2;
    double diskfree;
    char tempchar=0;
    int inde;
    QString Temp;
    for (inde = 0; inde < 2; inde++) {
        wtemp1 = qFromBigEndian<quint16>(status->driveStatus[inde]);
        if (wtemp1 & SF_NOT_READY) {
            if(inde==0){
                myStation->LatestDisk1 = QString("Not Ready");
                myStation->disk1space = 0;
                myStation->disk1sfx = 0;
            }
            else{
                myStation->LatestDisk2 = QString("Not Ready");
                myStation->disk2space = 0;
                myStation->disk2sfx = 0;
            }
        }
        else{
            if ((wtemp1 & SF_GB) == SF_GB){
                tempchar = 'G';
                diskfree = 1073741824.0;   /* `giga' bytes */
            }
            else{
                if ((wtemp1 & SF_MB) == SF_MB) {
                    tempchar = 'M';
                    diskfree = 1048576.0;  /* `mega' bytes */
                }
                else {
                    if ((wtemp1 & SF_KB) == SF_KB) {
                        tempchar = 'K';
                        diskfree = 1024.0;  /* `Kilo' bytes */
                    }
                }
            }
            wtemp2 = wtemp1 & SF_FREE;
            diskfree *= (double)wtemp2;
            if(inde==0){
                myStation->LatestDisk1 = QString::number(wtemp2) + QString(" ") + QString(tempchar);
                myStation->disk1space = wtemp2;
                myStation->disk1sfx = tempchar;
            }
            else{
                myStation->LatestDisk2 = QString::number(wtemp2) + QString(" ") + QString(tempchar);
                myStation->disk2space = wtemp2;
                myStation->disk2sfx =tempchar;
            }
        }
    }

    // Events Registered
    myStation->LatestNevent = qFromBigEndian<quint16>(status->events);
    //

    //emit debugMessage("GOT STATUS for: " + myStation->Station + " " + myStation->Network);
    emit stationsUpdated();
    emit stationXmlEvt(header->sta);
    emit statusMessage("Last updated station " +myStation->Station+ " at "+QDateTime::currentDateTime().toString("dd/MM/yy HH:mm:ss")+" local time");
    mutex->unlock();
}

// Recieves K2 Status 2 Info
void StnInfo::recieveK2Status2(K2INFO_HEADER *header, EXT2_STATUS_INFO *status2, QMutex *mutex)
{
    StaInfo* myStation;
    myStation = stationIndex(header);
    if (myStation == NULL)
        return;

    // Retrive Fault Codes
    quint16 fault;
    fault = qFromBigEndian<quint16>(status2->fault);
    if (fault != 0) {
        if (fault & FAULT_SYSTEM){
            myStation->LatestFaultC = QString("bad parameters");
            myStation->LatestFaultOk = false;
        }
        if (fault & FAULT_FLASH){
            myStation->LatestFaultC = QString("flash error");
            myStation->LatestFaultOk = false;
        }
        if (fault & FAULT_RAM){
            myStation->LatestFaultC = QString("ram error at ") + QString::number(qFromBigEndian<quint32>(status2->lastRAMError));
            myStation->LatestFaultOk = false;
        }
        if (fault & FAULT_PCMCIA){
            myStation->LatestFaultC = QString("bad/missing PCMCIA");
            myStation->LatestFaultOk = false;
        }
        if (fault & FAULT_DSP){
            myStation->LatestFaultC = QString("failed to load DSP");
            myStation->LatestFaultOk = false;
        }
        if (fault & FAULT_PARMBLK){
            myStation->LatestFaultC = QString("param block CRC error");
            myStation->LatestFaultOk = false;
        }
        if (fault & FAULT_FLASH_MAINTENANCE){
            myStation->LatestFaultC = QString("flash maintenance required");
            myStation->LatestFaultOk = false;
        }
    }
    else{
        myStation->LatestFaultC = QString("OK");
        myStation->LatestFaultOk = true;
    }

    //emit debugMessage("GOT STATUS V2 for: "+ QString(header->sta));
    emit stationXmlEvt(header->sta);
    emit stationsUpdated();
    emit statusMessage("Last updated station " +myStation->Station+ " at "+QDateTime::currentDateTime().toString("dd/MM/yy HH:mm:ss")+" local time");
    mutex->unlock();
}

// Recieves K2 Extended Status
void StnInfo::recieveK2HeaderS(K2INFO_HEADER *header, K2_HEADER *infheader, QMutex *mutex)
{
    StaInfo* myStation;
    myStation = stationIndex(header);
    if (myStation == NULL)
        return;

    // Set Log Time
    time_t now;
    now = time(0);
    double time_now = (double) now;
    myStation->LatestTimeExtPkg = now;
    myStation->LatestTimeExcel  = (time_now/86400.0)+25569.0;

    // Temperature (can also be aquired from EXT2)
    qint16 temp;
    temp = qFromBigEndian<quint16>(infheader->roParms.misc.temperature);
    myStation->LatestTemperature = temp/10.0;

    // Battery Voltage (might be aquired from STATUS)
    qint16 batt_voltx10;
    double batv;

    batt_voltx10 = qFromBigEndian<quint16>(infheader->roParms.misc.batteryVoltage);

    if (batt_voltx10 < 0) {
        batt_voltx10 = -batt_voltx10;
        batv = batt_voltx10 / 10.0;
        myStation->LatestVoltage = batv;
        myStation->LatestBTStatus = true;
    }
    else {
        batv = batt_voltx10 / 10.0;
        myStation->LatestVoltage = batv;
        myStation->LatestBTStatus = false;
    }

    emit debugMessage("GOT K2 HEADER for: "+ QString(header->sta));
    QMutex* another = new QMutex;
    another->lock();
    emit stationLogEvt(another,header->sta);
    emit stationsUpdated();
    mutex->unlock();
    delete another;
    emit statusMessage("Last updated station " +myStation->Station+ " at "+QDateTime::currentDateTime().toString("dd/MM/yy HH:mm:ss")+" local time");
}

// Reloads from latest XML
void StnInfo::reloadStations(QDir latestDir)
{
    QFile XMLFile;
    QDomDocument doc;
    if (!latestDir.cd("./K2Logs/Latest")){
        qErrnoWarning("No such directory");
        return;
    }
    XMLFile.setFileName(latestDir.filePath("./Stations.xml"));
    if (!XMLFile.open(QIODevice::ReadOnly)) {
        qErrnoWarning("Cannot open the file");
        return;
    }
    // Parse file
    if (!doc.setContent(&XMLFile)) {
       qErrnoWarning("Cannot parse the content");
       XMLFile.close();
       return;
    }
    XMLFile.close();

    QDomElement root;
    QDomNodeList elm;
    // Load list
    if(doc.documentElement().tagName() == "stations"){
        root = doc.documentElement();
        elm  = root.childNodes();
    }

    for (int i = 0; i < elm.size(); i++){
        if(elm.at(i).isElement()){
            StaInfo *mySta;
            QDomElement myLatest = elm.at(i).toElement();
            mySta = stationIndex(myLatest);
            if(mySta->Station != "NULL"){
                QDomNodeList staelm;
                staelm = elm.at(i).childNodes();
                for(int j = 0; j < staelm.size(); j++){
                    QDomElement current = staelm.at(j).toElement();
                    if(current.tagName() == "time"){
                        mySta->LatestTime = current.text().toInt();
                        mySta->LatestTimeExtPkg = current.text().toInt();
                        mySta->LatestDateTime.setTime_t(current.text().toInt());
                    }
                    if(current.tagName() == "tsrc")
                        mySta->TimeSrc = current.text().toInt();
                    if(current.tagName() == "volt")
                        mySta->LatestVoltage = current.text().toDouble();
                    if(current.tagName() == "temp")
                        mySta->LatestTemperature = current.text().toDouble();
                    if(current.tagName() == "btstat")
                        mySta->LatestBTStatus = current.text().toInt();
                    if(current.tagName() == "hwstat")
                        mySta->LatestHWStatus = current.text().toInt();
                    if(current.tagName() == "faultbool")
                        mySta->LatestFaultOk = current.text().toInt();
                    if(current.tagName() == "faultstring"){
                        if(current.text().isEmpty() && mySta->LatestFaultOk){
                            mySta->LatestFaultC = "OK";
                        }
                        else{
                            mySta->LatestFaultC = current.text();
                        }
                    }
                    if(current.tagName() == "d1space")
                        mySta->disk1space = current.text().toInt();
                    if(current.tagName() == "d2space")
                        mySta->disk2space = current.text().toInt();
                    if(current.tagName() == "d1sfx"){
                        mySta->disk1sfx = current.text().toInt();
                        if(mySta->disk1sfx == 0)
                            mySta->LatestDisk1 = "Not Ready";
                        else
                            mySta->LatestDisk1 = QString::number(mySta->disk1space) + " " + mySta->disk1sfx;
                    }
                    if(current.tagName() == "d2sfx"){
                        mySta->disk2sfx = current.text().toInt();
                        if(mySta->disk2sfx == 0)
                            mySta->LatestDisk2 = "Not Ready";
                        else
                            mySta->LatestDisk2 = QString::number(mySta->disk2space) + " " + mySta->disk2sfx;
                    }
                    if(current.tagName() == "nevt")
                        mySta->LatestNevent = current.text().toInt();
                }
            }
            stationsUpdated();
        }
    }
    emit statusMessage("Reloaded all stations at " +QDateTime::currentDateTime().toString("dd/MM/yy HH:mm:ss")+" local time");

}

// Checks for station information, returns the station. Should station not exist add it.
StaInfo* StnInfo::stationIndex(K2INFO_HEADER *header)
{
    StaInfo* query = new StaInfo(header->sta);
    if (!Stations.contains(header->sta)) {
        query->Network = header->net;
        Stations[header->sta] = query;
        emit stationAdded(temp);
        temp->lock();
        return Stations.value(header->sta);
    } else {
        if (query->Network.isEmpty())
            query->Network = header->net;
        return Stations.value(header->sta);
    }
}

// Checks for station information, returns the station. Should station not exist add it.
StaInfo* StnInfo::stationIndex(QDomElement station){
    StaInfo* query;
    if (station.hasAttribute("name") && station.hasAttribute("network") && station.hasAttribute("serial"))
         query = new StaInfo(station.attribute("name"));
    else {
        query = new StaInfo();
        return query;
    }

    if (!Stations.contains(station.attribute("name"))) {
        query->Network = station.attribute("network");
        query->Serial = station.attribute("serial").toInt();
        Stations[station.attribute("name")] = query;
        emit stationAdded(temp);
        temp->lock();
        return Stations.value(station.attribute("name"));
    } else {
        return Stations.value(station.attribute("name"));
    }
}

// Checks for station information, returns the station. Should station not exist add it.
StaInfo* StnInfo::stationIndex(QString station, QString network){
    StaInfo* query;
    query = new StaInfo(station);
    if (!Stations.contains(station)) {
        query->Network = network;
        Stations[station] = query;
        emit stationAdded(temp);
        temp->lock();
        emit stationXmlEvt(station);
        return Stations.value(station);
    } else {
        return Stations.value(station);
    }
}

/******* STA INFO DEFINITIONS *******/
StaInfo::StaInfo()
{
    Station = "NULL";
    Serial            =  -1;
    LatestTime        =  -1;
    LatestDateTime    =  QDateTime::currentDateTime();
    TimeSrc           =  -1;
    LatestTimeExtPkg  =  -1;
    LatestTimeExcel   =  -1;
    LatestVoltage     =  9999;
    LatestTemperature =  9999;
    LatestHWStatus    =  2;
    LatestBTStatus    =  2;
    LatestFaultC.clear();
    LatestFaultOk     =  3;
    LatestDisk1.clear ();
    disk1space        =  -1;
    disk1sfx          =  -1;
    LatestDisk2.clear ();
    disk2space        =  -1;
    disk2sfx          =  -1;
    LatestNevent      =  -1;
}

StaInfo::StaInfo(QString Sta)
{
    Station = Sta;
    Serial            =  -1;
    LatestTime        =  -1;
    LatestDateTime    =  QDateTime::currentDateTime();
    TimeSrc           =  -1;
    LatestTimeExtPkg  =  -1;
    LatestTimeExcel   =  -1;
    LatestVoltage     =  9999;
    LatestTemperature =  9999;
    LatestHWStatus    =  2;
    LatestBTStatus    =  2;
    LatestFaultC.clear();
    LatestFaultOk     =  3;
    LatestDisk1.clear ();
    disk1space        =  -1;
    disk1sfx          =  -1;
    LatestDisk2.clear ();
    disk2space        =  -1;
    disk2sfx          =  -1;
    LatestNevent      =  -1;
}

bool StaInfo::operator == (const StaInfo& rhs) const
{
    return Station == rhs.Station;
}
