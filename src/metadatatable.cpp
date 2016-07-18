#include "metadatatable.h"

MetadataTable::MetadataTable(QObject *parent)
    : QAbstractTableModel(parent)
{
    stnSetup = false;
}

// The column count. Reimplemented Virtual (Req)
int MetadataTable::columnCount(const QModelIndex &parent = QModelIndex()) const
{
    Q_UNUSED(parent);
    return Ncol;
}

// The row count, Reimplemented Virtual (Req)
int MetadataTable::rowCount(const QModelIndex &parent = QModelIndex()) const
{
    Q_UNUSED(parent);
    return StatInfo->Stations.size();
}

// The data value, Reimplemented Virtual (Req)
QVariant MetadataTable::data(const QModelIndex &index, int role) const
{
    // IF NOT VALID
    if(!index.isValid()){
        return QVariant();
    }
    else
    {
        StaInfo* currentSta;
        currentSta = StatInfo->Stations.value(StatName.at(index.row()));

        // TEXT
        if(role == Qt::DisplayRole){

            switch(index.column()){
                case Ttim:
                    if (currentSta->LatestTime == -1)
                        return "Waiting...";
                    else
                        return currentSta->LatestDateTime.toString("dd/MM/yy HH:mm:ss");
                    break;
                case Ttsc:
                    switch (currentSta->TimeSrc) {
                    case -1:
                        return "Waiting...";
                    case 0:
                        return QString("Set from RTC");
                    case 1:
                        return QString("Set from Keyboard");
                    case 2:
                        return QString("Set from External Pulse");
                    case 3:
                        return QString("Set from Internal GPS");
                    default:
                        return QString("Set from (?)");
                    }
                case Thws:
                    if (currentSta->LatestHWStatus == 2)
                        return "Waiting...";
                    if (currentSta->LatestHWStatus == 1)
                        return "OK";
                    if (currentSta->LatestHWStatus == 0)
                        return "FAULT";
                case Tbts:
                    if (currentSta->LatestBTStatus == 2)
                        return "Waiting...";
                    if (currentSta->LatestBTStatus == 1)
                        return "Charging";
                    if (currentSta->LatestBTStatus == 0)
                        return "Not Charging";
                case Tfac:
                    if (currentSta->LatestFaultC.isEmpty() || currentSta->LatestFaultOk == 3)
                        return "Waiting...";
                    else
                        return currentSta->LatestFaultC;
                case Tevt:
                    if (currentSta->LatestNevent == -1)
                        return "Waiting...";
                    else
                        return QString::number(currentSta->LatestNevent);
                case Tds1:
                    if (currentSta->disk1space == -1)
                        return "Waiting...";
                    else
                        return currentSta->LatestDisk1;
                case Tds2:
                    if (currentSta->disk2space == -1)
                        return "Waiting...";
                    else
                        return currentSta->LatestDisk2;
                case Tvol:
                    if (currentSta->LatestVoltage == 9999)
                        return "Waiting...";
                    else
                        return QString::number(currentSta->LatestVoltage);
                case Ttem:
                    if (currentSta->LatestTemperature == 9999)
                        return "Waiting...";
                    else
                        return QString::number(currentSta->LatestTemperature);
                case Tser:
                    if (currentSta->Serial == -1)
                        return "Waiting...";
                    else
                        return QString::number(currentSta->Serial);
                case Tsta:
                    return StatName.at(index.row());
                case Tnet:
                    return currentSta->Network;
                default:
                    return QVariant();
            }
        }

        // Background color
        if(role == Qt::BackgroundRole){
            // Setup time difference
            QDateTime now;
            now = QDateTime::currentDateTime();
            qint64 diff = currentSta->LatestDateTime.secsTo(now);

            switch(index.column()){
            case Ttim:
                if (currentSta->LatestTime == -1)
                    return QBrush(Qt::white);
                else
                    if(diff < 300)                              // Before  05 min
                        return QBrush(QColor(0,255,0));
                    else if (diff >= 300 && diff < 600)         // Between 05-10 min
                        return QBrush(QColor(72,255,0));
                    else if (diff >= 600 && diff < 1800)        // Between 10-30 min
                        return QBrush(QColor(145,255,0));
                    else if (diff >= 1800 && diff < 3600)       // Between 30-60 min
                        return QBrush(QColor(218,255,0));
                    else if (diff >= 3600 && diff < 21600)      // Between 01-06 hrs
                        return QBrush(QColor(255,218,0));
                    else if (diff >= 21600 && diff < 43200)     // Between 06-12 hrs
                        return QBrush(QColor(255,145,0));
                    else if (diff >= 43200 && diff < 86400)     // Between 12-24 hrs
                        return QBrush(QColor(255,72,0));
                    else if (diff >= 86400)                     // After   24 hrs
                        return QBrush(QColor(255,0,0));
            case Ttsc:
                switch (currentSta->TimeSrc) {
                    case -1:
                        return QBrush(Qt::white);
                    case 0:
                        return QBrush(Qt::red);
                    case 1:
                        return QBrush(Qt::yellow);
                    case 2:
                        return QBrush(Qt::yellow);
                    case 3:
                        return QBrush(Qt::green);
                    default:
                        return QBrush(Qt::red);
                }
            case Thws:
                if (currentSta->LatestHWStatus == 2)
                    return QBrush(Qt::white);
                if (currentSta->LatestHWStatus == 1)
                    return QBrush(Qt::green);
                if (currentSta->LatestHWStatus == 0)
                    return QBrush(Qt::red);
            case Tbts:
                if (currentSta->LatestBTStatus == 2)
                    return QBrush(Qt::white);
                if (currentSta->LatestBTStatus == 1)
                    return QBrush(Qt::green);
                if (currentSta->LatestBTStatus == 0)
                    return QBrush(Qt::red);
            case Tfac:
                if (currentSta->LatestFaultC.isEmpty() || currentSta->LatestFaultOk == 3)
                    return QBrush(Qt::white);
                else {
                    if(currentSta->LatestFaultOk)
                        return QBrush(Qt::green);
                    else
                        return QBrush(Qt::red);
                }
            case Tevt:
                if (currentSta->LatestNevent == -1)
                    return QBrush(Qt::white);
                else {
                    if (currentSta->LatestNevent > 100)
                        return QBrush(Qt::red);
                    else
                        return QBrush(Qt::green);
                }
            case Tds1:
                if (currentSta->disk1space == -1)
                    return QBrush(Qt::white);
                else
                    if ((currentSta->disk1space < 10 && currentSta->disk1sfx == 'K') || currentSta->LatestDisk1 == "Not Ready")
                        return QBrush(Qt::red);
                    else
                        return QBrush(Qt::green);
            case Tds2:
                if (currentSta->disk2space == -1)
                    return QBrush(Qt::white);
                else
                    if ((currentSta->disk2space < 10 && currentSta->disk2sfx == 'K') || currentSta->LatestDisk2 == "Not Ready")
                        return QBrush(Qt::red);
                    else
                        return QBrush(Qt::green);
            case Tvol:
                if (currentSta->LatestVoltage == 9999)
                    return QBrush(Qt::white);
                else
                    if(currentSta->LatestVoltage <= 11 || currentSta->LatestVoltage >= 14)
                        return QBrush(Qt::red);
                    else
                        return QBrush(Qt::green);
            case Ttem:
                if (currentSta->LatestTemperature == 9999)
                    return QBrush(Qt::white);
                else
                    if (currentSta->LatestTemperature >= 45)
                        return QBrush(Qt::red);
                    else
                        return QBrush(Qt::green);
            case Tser:
                return QBrush(Qt::white);
            case Tsta:
                return QBrush(Qt::white);
            case Tnet:
                return QBrush(Qt::white);
            default:
                return QBrush(Qt::white);
            }
        }
    }
    return QVariant();
}

// The header data, Reimplemented Virtual
QVariant MetadataTable::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole)
        return QVariant();
    if(orientation == Qt::Horizontal){
        switch (section){
            case Tnet:
                return tr("Network");
            case Tsta:
                return tr("Station");
            case Tser:
                return tr("Serial #");
            case Tvol:
                return tr("Voltage");
            case Ttem:
                return tr("Temperature");
            case Thws:
                return tr("HW Status");
            case Tbts:
                return tr("BT Status");
            case Tfac:
                return tr("Fault Code");
            case Ttim:
                return tr("Time");
            case Ttsc:
                return tr("Time Src");
            case Tds1:
                return tr("Disk 1");
            case Tds2:
                return tr("Disk 2");
            case Tevt:
                return tr("Events");
            default:
                return QVariant();
        }
    }
    if(orientation == Qt::Vertical){
        return QString::number(section+1);
    }
    return QVariant();
}

// Setup The station info.
void MetadataTable::setStationInfo(StnInfo *MyStations)
{
    StatInfo = MyStations;
    stnSetup = true;
    emit debugMessage("Station Info setup correctly.");
}

// Add Station Information
void MetadataTable::addStaInformation(QMutex* temp)
{
    StatName.clear();
    StatName = StatInfo->Stations.uniqueKeys();
    beginInsertRows(QModelIndex(),rowCount(),rowCount());
    endInsertRows();
    temp->unlock();
}

// Update Station Data
void MetadataTable::updateMetadata()
{
    QVector<int> updRoles;
    updRoles.append(Qt::BackgroundRole);
    updRoles.append(Qt::DisplayRole);
    dataChanged(index(0,0),index(rowCount(),columnCount()),updRoles);
}
