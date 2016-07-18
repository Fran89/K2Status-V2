#ifndef K2LOGGER_H
#define K2LOGGER_H

#include <QObject>
#include <QDir>
#include <QList>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QDomDocument>
#include <QDomNodeList>
#include <QDebug>
#include "stninfo.h"

class K2Logger : public QObject
{
    Q_OBJECT
public:
    explicit K2Logger(QObject *parent = 0);
    void setupStations(StnInfo* stn);
    void setupPath(QDir user);

signals:

public slots:
    void enableLogging(bool swenable);
    void startLog(QMutex * mutex, QString name);
    void writeXML(QString name);

private:
    bool enabled;
    bool ready;
    QMutex writing;
    QDir XMLDir;
    QFile StaXML;
    QDir myDirectory;
    StnInfo * Stations;
    QDomElement writeTextElement(QString name, QString value);
};

#endif // K2LOGGER_H
