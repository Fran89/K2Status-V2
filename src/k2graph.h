#ifndef K2GRAPH_H
#define K2GRAPH_H

#include <QMainWindow>
#include <stninfo.h>
#include "qcustomplot.h"

namespace Ui {
class K2Graph;
}

class K2Graph : public QMainWindow
{
    Q_OBJECT

public:
    explicit K2Graph(bool mssm, QWidget *parent = 0);
    ~K2Graph();
    void setStations(StnInfo*stn);
    void setPath(QDir dir);
    class logData {
    public:
        QVector<double> time;
        QVector<double> extime;
        QVector<double> temp;
        QVector<double> volt;
        QVector<QString> chrg;
        void clear();
    };

public slots:
    void stnupdated();
    void showTGraph(QString sta);
    void showVGraph(QString sta);

private slots:
    void on_graphTemp_clicked();

    void on_graphVolt_clicked();

private:
    Ui::K2Graph *ui;
    StnInfo* MySta;
    QList<QString> Stations;
    QDir MyDir;
    bool ssm;
    bool ready1, ready2, ready;
    logData currentStaLD;
};

#endif // K2GRAPH_H
