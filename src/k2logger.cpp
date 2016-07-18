#include "k2logger.h"

K2Logger::K2Logger(QObject *parent) : QObject(parent)
{
    enabled = false;
    ready = false;
}

void K2Logger::enableLogging(bool swenable)
{
    if (ready){
        if (!enabled &&  swenable){  // We are starting
            enabled = true;
        }
        if ( enabled && !swenable){ // We are stopping
            enabled = false;
        }
        if ( enabled &&  swenable){  // What happened we were already enabled...
            return;
        }
        if (!enabled && !swenable){  // What Happened we were already disabled...
            return;
    }
    }
}

void K2Logger::setupStations(StnInfo *stn)
{
    Stations = stn;
    ready = true;
}

void K2Logger::startLog(QMutex *mutex, QString name){
    if(enabled){
        StaInfo * MySta;
        MySta = Stations->Stations.value(name);
        QFile Log;
        Log.setFileName(myDirectory.filePath(name+QString("_log.csv")));
        if (!Log.open(QIODevice::ReadWrite|QIODevice::Append|QIODevice::Text))
            return;
        QTextStream line(&Log);
        line << QString::number(MySta->LatestTimeExtPkg) << ", "
             << QString::number(MySta->LatestTimeExcel,'f',10) << ", "
             << QString::number(MySta->LatestTemperature) << ", "
             << QString::number(MySta->LatestVoltage) << ", ";
        if(MySta->LatestBTStatus)
            line << QString("C  \n");
        else
            line << QString("NC \n");
        writeXML(name);
        Log.close();
        mutex->unlock();
    } else{
        mutex->unlock();
        return;
    }
}

void K2Logger::writeXML(QString name){
    StaInfo * StaName;
    StaName = Stations->Stations.value(name);
    QDomDocument doc;
    QDomNode root;
    QDomNodeList elm;
    // Open file
    if (!StaXML.open(QIODevice::ReadOnly)) {
        qErrnoWarning("Cannot open the file");
        return;
    }

    // Parse file
    if (!doc.setContent(&StaXML)) {
       qErrnoWarning("Cannot parse the content");
       StaXML.close();
       return;
    }
    StaXML.close();

    // Load list
    if(doc.documentElement().tagName() == "stations"){
        root = doc.documentElement();
        elm  = root.childNodes();
    }

    // Search
    bool found = false;
    int index = 0;
    for(int i = 0; i < elm.size(); i++){
        for(int j =0; j < elm.at(i).attributes().size(); j++){
            QDomAttr Curr= elm.at(i).attributes().item(j).toAttr();
            if (Curr.name() == "name" && Curr.value() == StaName->Station){
                found = true;
                index = i;
                break;
            }
        }
        if(found)
            break;
    }

    //Modify Data
    if (!found) {
        QDomElement station = doc.createElement("station");
        station.setAttribute("name",StaName->Station);
        station.setAttribute("name",StaName->Station);
        station.setAttribute("network",StaName->Network);
        station.setAttribute("serial", StaName->Serial);
        station.appendChild(writeTextElement("time", QString::number(StaName->LatestTime)));
        station.appendChild(writeTextElement("tsrc", QString::number(StaName->TimeSrc)));
        station.appendChild(writeTextElement("volt", QString::number(StaName->LatestVoltage)));
        station.appendChild(writeTextElement("temp", QString::number(StaName->LatestTemperature)));
        station.appendChild(writeTextElement("btstat", QString::number(StaName->LatestBTStatus)));
        station.appendChild(writeTextElement("hwstat", QString::number(StaName->LatestHWStatus)));
        station.appendChild(writeTextElement("faultbool", QString::number(StaName->LatestFaultOk)));
        station.appendChild(writeTextElement("faultstring", StaName->LatestFaultC));
        station.appendChild(writeTextElement("d1space", QString::number(StaName->disk1space)));
        station.appendChild(writeTextElement("d1sfx", QString::number(StaName->disk1sfx)));
        station.appendChild(writeTextElement("d2space", QString::number(StaName->disk2space)));
        station.appendChild(writeTextElement("d2sfx", QString::number(StaName->disk2sfx)));
        station.appendChild(writeTextElement("nevt", QString::number(StaName->LatestNevent)));
        root.appendChild(station);
    } else {
        QDomElement station = elm.at(index).toElement();
        station.attributeNode("serial").setValue(QString::number(StaName->Serial));
        QDomNodeList info = station.childNodes();
        for (int i = 0; i < info.size(); i++){
            if(info.at(i).isElement()){
                if(info.at(i).toElement().tagName() == "time")
                    info.at(i).toElement().firstChild().setNodeValue(QString::number(StaName->LatestTime));
                if(info.at(i).toElement().tagName() == "tsrc")
                    info.at(i).toElement().firstChild().setNodeValue(QString::number(StaName->TimeSrc));
                if(info.at(i).toElement().tagName() == "volt")
                    info.at(i).toElement().firstChild().setNodeValue(QString::number(StaName->LatestVoltage));
                if(info.at(i).toElement().tagName() == "temp")
                    info.at(i).toElement().firstChild().setNodeValue(QString::number(StaName->LatestTemperature));
                if(info.at(i).toElement().tagName() == "btstat")
                    info.at(i).toElement().firstChild().setNodeValue(QString::number(StaName->LatestBTStatus));
                if(info.at(i).toElement().tagName() == "hwstat")
                    info.at(i).toElement().firstChild().setNodeValue(QString::number(StaName->LatestHWStatus));
                if(info.at(i).toElement().tagName() == "faultbool")
                    info.at(i).toElement().firstChild().setNodeValue(QString::number(StaName->LatestFaultOk));
                if(info.at(i).toElement().tagName() == "faultstring")
                    info.at(i).toElement().firstChild().setNodeValue(StaName->LatestFaultC);
                if(info.at(i).toElement().tagName() == "d1space")
                    info.at(i).toElement().firstChild().setNodeValue(QString::number(StaName->disk1space));
                if(info.at(i).toElement().tagName() == "d1sfx")
                    info.at(i).toElement().firstChild().setNodeValue(QString::number(StaName->disk1sfx));
                if(info.at(i).toElement().tagName() == "d2space")
                    info.at(i).toElement().firstChild().setNodeValue(QString::number(StaName->disk2space));
                if(info.at(i).toElement().tagName() == "d2sfx")
                    info.at(i).toElement().firstChild().setNodeValue(QString::number(StaName->disk2sfx));
                if(info.at(i).toElement().tagName() == "nevt")
                    info.at(i).toElement().firstChild().setNodeValue(QString::number(StaName->LatestNevent));
            }
        }
    }
    writing.lock();
    // Save content back to the file
    if (!StaXML.open(QIODevice::Truncate | QIODevice::WriteOnly)) {
        return;
    }
    StaXML.write(doc.toByteArray());
    StaXML.close();
    writing.unlock();
}

QDomElement K2Logger::writeTextElement(QString name, QString value)
{
    QDomDocument temp;
    QDomElement tempEle = temp.createElement(name);
    QDomText tempTxt = temp.createTextNode(value);
    tempEle.appendChild(tempTxt);
    return tempEle;
}

void K2Logger::setupPath(QDir user){
    myDirectory = user;
    if(!myDirectory.cd("./K2Logs")){
        myDirectory.mkdir("./K2Logs");
        myDirectory.cd("./K2Logs");
    }
    XMLDir = myDirectory;
    if(!XMLDir.cd("./Latest")){
        XMLDir.mkdir("./Latest");
        XMLDir.cd("./Latest");
    }
    StaXML.setFileName(XMLDir.filePath("Stations.xml"));
    if (!StaXML.open(QIODevice::ReadWrite)) {
        qErrnoWarning("Cannot open the file");
    }
    QDomDocument doc;
    // Parse file
    if (!doc.setContent(&StaXML)) {
       doc.appendChild(doc.createElement("stations"));
       StaXML.write(doc.toByteArray());
       StaXML.close();
    } else {
       StaXML.close();
    }
}
