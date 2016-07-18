#ifndef STNINFO_H
#define STNINFO_H
#include "ewmessagemgr.h"
#include <QObject>
#include <QDateTime>
#include <QtEndian>
#include <QMap>
#include <QDir>
#include <QDomDocument>
#include <time.h>

// This class is the actual data structure
class StaInfo : public QObject{
    Q_OBJECT
public:
    // Init
    StaInfo();
    StaInfo(QString Sta);

    // Station Information
    QString Station;
    QString Network;
    qint32  Serial;

    // Timing
    time_t    LatestTime;
    QDateTime LatestDateTime;
    qint8     TimeSrc;
    // This one is different and usually once every 30min;
    time_t    LatestTimeExtPkg;
    double    LatestTimeExcel;

    // Extended Package Volt/Temperatue
    double  LatestVoltage;
    double  LatestTemperature;

    qint8    LatestHWStatus;
    qint8    LatestBTStatus;
    QString LatestFaultC;
    qint8    LatestFaultOk;
    QString LatestDisk1;
    qint32  disk1space;
    qint8   disk1sfx;
    QString LatestDisk2;
    qint32  disk2space;
    qint8   disk2sfx;
    qint16  LatestNevent;
    bool operator ==(const StaInfo &rhs) const;
};

// This class recieves information from the EW Message Manager and collects it into it's own data structure
// It's also meant to transmit the data to the Metadata Table...
class StnInfo : public QObject
{
    Q_OBJECT
public:
    explicit StnInfo(QObject *parent = 0);
    ~StnInfo();
    QMap<QString, StaInfo*> Stations;
    void reloadStations(QDir latestDir);

signals:
    void stationsUpdated();
    void stationAdded(QMutex*);
    void stationLogEvt(QMutex*,QString);
    void stationXmlEvt(QString);
    void debugMessage(QString);
    void statusMessage(QString);

public slots:
    StaInfo *stationIndex(K2INFO_HEADER *header);
    StaInfo *stationIndex(QDomElement station);
    StaInfo *stationIndex(QString station, QString network);
    void recieveK2Status  (K2INFO_HEADER* header, STATUS_INFO* status, QMutex* mutex);
    void recieveK2Status2 (K2INFO_HEADER* header, EXT2_STATUS_INFO* status2, QMutex* mutex);
    void recieveK2HeaderS (K2INFO_HEADER* header, K2_HEADER* infheader, QMutex * mutex);
private:
    QMutex* temp;
};

#endif // STNINFO_H
