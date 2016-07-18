#ifndef K2STATUSV2_H
#define K2STATUSV2_H

#include <QMainWindow>
#include <QLabel>
#include <QtEndian>
#include <QInputDialog>
#include "stninfo.h"
#include "ewmessagemgr.h"  // EW Message Manager
#include "k2udpsock.h"     // UDP Socket
#include "udpconfig.h"     // UDP Configuration
#include "aboutme.h"       // About Me Box
#include "metadatatable.h" // Station Table
#include "k2logger.h"
#include "k2graph.h"

namespace Ui {
class K2StatusV2;
}

class K2StatusV2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit K2StatusV2(QWidget *parent = 0);
    ~K2StatusV2();

private:
    Ui::K2StatusV2 *ui;
    bool debug;
    bool connected;
    K2UDPSock*     EWUdpSock;
    AboutMe*       MyHelp;
    UDPConfig*     MyUDPConfig;
    EWMessageMgr*  MyMsgMgr;
    StnInfo*       MyStnInfo;
    QLabel*        status;
    MetadataTable* MyMetaDataTable;
    K2Logger *     MyK2Logger;
    K2Graph *      MyK2Graph;
    QString        currentsta;
    QAction*       showGT;
    QAction*       showGV;
    QMenu          context;



private slots:
    void showStatusMessage(const QString &message);
    void appendToDebugBrowser(const QString &message);
    void resizeTable();
    void DebugToggle();
    void addStation();
    void connectUDP();
    void disconnectUDP();
    void nothing();
    void onClicked(QPoint);
    void volt();
    void temp();

signals:
    void sendDebug(bool);
    void sendStation(QString);

};

#endif // K2STATUSV2_H
