#ifndef METADATATABLE_H
#define METADATATABLE_H
#include "stninfo.h"
#include "time.h"
#include <QString>
#include <QList>
#include <QVariant>
#include <QBrush>
#include <QDateTime>
#include <QAbstractTableModel>

// This class is meant to recieve information from the StationInfo and update the UI
class MetadataTable : public QAbstractTableModel
{
    Q_OBJECT
    
public:
    explicit MetadataTable(QObject *parent);
    void setStationInfo(StnInfo* MyStations);

public slots:
    void addStaInformation(QMutex *temp);
    void updateMetadata();
    
private:
    StnInfo *StatInfo;
    QList<QString> StatName;
    bool stnSetup;
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    //Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    //bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    //QModelIndex index(int row, int column, const QModelIndex &parent) const;
    //QModelIndex parent(const QModelIndex &child) const;
    void updateColors();

signals:
    void debugMessage(QString);

};

#endif // METADATATABLE_H
