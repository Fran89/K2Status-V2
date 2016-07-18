#include "k2statusv2.h"
#include "ui_k2statusv2.h"

K2StatusV2::K2StatusV2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::K2StatusV2)
{
    // Setup
    ui->setupUi(this);
    ui->mainToolBar->hide();
    ui->actionDisconnect->setDisabled(true);
    ui->actionGraph->setDisabled(true);
    connect(ui->actionQuit,SIGNAL(triggered(bool)),qApp,SLOT(quit()));

    // Context Menu
    showGT = context.addAction("Show Temperature Graph");
    showGV = context.addAction("Show Voltage Graph");
    connect(showGT,SIGNAL(triggered(bool)),this,SLOT(temp()));
    connect(showGV,SIGNAL(triggered(bool)),this,SLOT(volt()));

    // Debug?
    debug = false;
    ui->textBrowser->hide();
    connect(ui->actionDebug_Mode,SIGNAL(triggered(bool)),this,SLOT(DebugToggle()));

    // UDP Configuration
    MyUDPConfig = new UDPConfig;
    connected = false;
    connect(ui->actionAdd_a_Connection,SIGNAL(triggered(bool)),MyUDPConfig,SLOT(exec()));
    connect(ui->actionDisconnect,SIGNAL(triggered(bool)),this,SLOT(disconnectUDP()));
    connect(MyUDPConfig,SIGNAL(accepted()),this,SLOT(connectUDP()));
    connect(MyUDPConfig,SIGNAL(rejected()),this,SLOT(nothing()));

    // About Help
    MyHelp = new AboutMe;
    connect(ui->actionAbout_Me,SIGNAL(triggered(bool)),MyHelp,SLOT(show()));
    connect(ui->actionAbout_QT,SIGNAL(triggered(bool)),qApp,SLOT(aboutQt()));

    // Setup Socket
    EWUdpSock = new K2UDPSock(this);
    connect(this,SIGNAL(sendDebug(bool)),EWUdpSock,SLOT(setDebug(bool)));
    connect(EWUdpSock,SIGNAL(debugMessage(QString)),this,SLOT(appendToDebugBrowser(QString)));

    // EW Message Manager
    MyMsgMgr = new EWMessageMgr;
    EWUdpSock->setupEWMsgMgr(MyMsgMgr);

    // Station Info and connect the EW Msg Manager to Station Info
    MyStnInfo = new StnInfo;
    connect(MyMsgMgr,SIGNAL(exportK2Status(K2INFO_HEADER*,STATUS_INFO*,QMutex*)),
            MyStnInfo,SLOT(recieveK2Status(K2INFO_HEADER*,STATUS_INFO*,QMutex*)));
    connect(MyMsgMgr,SIGNAL(exportK2Status2(K2INFO_HEADER*,EXT2_STATUS_INFO*,QMutex*)),
            MyStnInfo,SLOT(recieveK2Status2(K2INFO_HEADER*,EXT2_STATUS_INFO*,QMutex*)));
    connect(MyMsgMgr,SIGNAL(exportK2HeaderS(K2INFO_HEADER*,K2_HEADER*,QMutex*)),
            MyStnInfo,SLOT(recieveK2HeaderS(K2INFO_HEADER*,K2_HEADER*,QMutex*)));
    connect(MyStnInfo,SIGNAL(debugMessage(QString)),this,SLOT(appendToDebugBrowser(QString)));
    connect(MyStnInfo,SIGNAL(statusMessage(QString)),this,SLOT(showStatusMessage(QString)));

    // New MetadataTable and connect Station Info to DataTable
    MyMetaDataTable = new MetadataTable(this);
    connect(MyMetaDataTable,SIGNAL(debugMessage(QString)), this,SLOT(appendToDebugBrowser(QString)));
    MyMetaDataTable->setStationInfo(MyStnInfo);
    ui->MyMetadataTableView->setModel(MyMetaDataTable);
    connect(MyStnInfo,SIGNAL(stationAdded(QMutex*)),MyMetaDataTable,SLOT(addStaInformation(QMutex*)));
    connect(MyStnInfo,SIGNAL(stationsUpdated()),MyMetaDataTable,SLOT(updateMetadata()));

    // Setup Table View
    connect(MyStnInfo,SIGNAL(stationsUpdated()),this,SLOT(resizeTable()));
    ui->MyMetadataTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->MyMetadataTableView->setSelectionMode(QAbstractItemView::SingleSelection);

    // Setup Logging
    MyK2Logger = new K2Logger;
    connect(ui->actionEnable_Logging,SIGNAL(toggled(bool)),MyK2Logger,SLOT(enableLogging(bool)));
    MyK2Logger->setupStations(MyStnInfo);
    ui->actionEnable_Logging->setChecked(true);
    connect(MyStnInfo,SIGNAL(stationLogEvt(QMutex*,QString)),MyK2Logger,SLOT(startLog(QMutex*,QString)));
    connect(MyStnInfo,SIGNAL(stationXmlEvt(QString)),MyK2Logger,SLOT(writeXML(QString)));

    // Add a station
    ui->actionLoad_Station_list->setDisabled(true);
    connect(ui->actionLoad_Station_list,SIGNAL(triggered(bool)),this,SLOT(addStation()));

    // Add K2 Graph;
    MyK2Graph = new K2Graph(false,this);
    MyK2Graph->setStations(MyStnInfo);
    ui->MyMetadataTableView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->actionGraph,SIGNAL(triggered(bool)),MyK2Graph,SLOT(show()));
    connect(MyStnInfo,SIGNAL(stationsUpdated()),MyK2Graph,SLOT(stnupdated()));
    connect(ui->MyMetadataTableView,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(onClicked(QPoint)));


    // Status
    status = new QLabel;
    ui->statusBar->addWidget(status);
    
}

K2StatusV2::~K2StatusV2()
{
    delete ui;
    delete MyHelp;
}

// Show Status Message
void K2StatusV2::showStatusMessage(const QString &message)
{
    status->setText(message);
}

// Append to Debug Browser
void K2StatusV2::appendToDebugBrowser(const QString &message)
{
    ui->textBrowser->append(message);
}

// Toggle Debug Mode
void K2StatusV2::DebugToggle()
{
    if(debug){
        debug = false;
        emit sendDebug(debug);
        ui->textBrowser->hide();
        showStatusMessage("Debug mode is off");
    } else {
        debug = true;
        emit sendDebug(debug);
        ui->textBrowser->show();
        showStatusMessage("Debug mode is on");
    }
}

// Connect to EW UDP
void K2StatusV2::connectUDP()
{

    showStatusMessage("Connecting");
    appendToDebugBrowser("UDP Connecting");
    quint16 Port = MyUDPConfig->config.Port.toInt();
    QHostAddress IP(MyUDPConfig->config.MyIPAddress.toString());
    MyK2Logger->setupPath(QDir(MyUDPConfig->config.LogFolder.toString()));
    MyStnInfo->reloadStations(QDir(MyUDPConfig->config.LogFolder.toString()));
    MyK2Graph->setPath(QDir(MyUDPConfig->config.LogFolder.toString()));
    MyK2Graph->stnupdated();
    if (!connected){
        if (EWUdpSock->bind(IP,Port)) {
            connected = true;
            showStatusMessage("Connected!");
            ui->actionAdd_a_Connection->setDisabled(true);
            ui->actionLoad_Station_list->setEnabled(true);
            ui->actionGraph->setEnabled(true);
            ui->actionDisconnect->setEnabled(true);
            appendToDebugBrowser("K2Status connected");
        }
        else {
            connected = false;
            showStatusMessage("Could not connect, is the port being used?");
            appendToDebugBrowser("K2Status could not connect");
        }
    }
}

// Disconnect UDP
void K2StatusV2::disconnectUDP()
{
    if(connected){
        EWUdpSock->close();
        showStatusMessage("Disconnected");
        ui->actionLoad_Station_list->setDisabled(true);
        ui->actionAdd_a_Connection->setEnabled(true);
        ui->actionGraph->setDisabled(true);
        ui->actionDisconnect->setDisabled(true);
        connected=false;
    }
}

// Do nothing if canceled
void K2StatusV2::nothing(){
    showStatusMessage("Not Connecting");
}

// Resize Table
void K2StatusV2::resizeTable(){
    ui->MyMetadataTableView->resizeColumnsToContents();
    ui->MyMetadataTableView->repaint();
    this->setFixedWidth(ui->MyMetadataTableView->horizontalHeader()->length()+45);
}

// Add a station
void K2StatusV2::addStation(){
    QString staName;
    QString netName;
    bool stard;
    staName = QInputDialog::getText(this,"Add a station", "Station" ,QLineEdit::Normal,"NULL",&stard);
    netName = QInputDialog::getText(this,"Station Network", "Network" ,QLineEdit::Normal,"XX",&stard);
    if(stard && staName != "NULL" && netName != "XX" && !staName.isEmpty() && !netName.isEmpty())
        MyStnInfo->stationIndex(staName,netName);
    appendToDebugBrowser("Added: " + staName);
    MyK2Graph->stnupdated();
}

// On clicked
void K2StatusV2::onClicked(QPoint index){
    int row;
    row = ui->MyMetadataTableView->rowAt(index.y());
    if(row >= 0){
        currentsta.clear();
        currentsta = MyStnInfo->Stations.value(MyStnInfo->Stations.keys().at(row))->Station;
        context.exec(QCursor::pos());
    }
    return;
}

void K2StatusV2::volt(){
    appendToDebugBrowser(currentsta);
    K2Graph *station;
    station = new K2Graph(true,this);
    station->setAttribute( Qt::WA_DeleteOnClose, true );
    station->setWindowTitle(currentsta + " Voltage");
    station->setPath(QDir(MyUDPConfig->config.LogFolder.toString()));
    station->showVGraph(currentsta);
    station->show();

    currentsta.clear();
}

void K2StatusV2::temp(){
    appendToDebugBrowser(currentsta);
    K2Graph *station;
    station = new K2Graph(true,this);
    station->setAttribute( Qt::WA_DeleteOnClose, true );
    station->setWindowTitle(currentsta + " Temperature");
    station->setPath(QDir(MyUDPConfig->config.LogFolder.toString()));
    station->showTGraph(currentsta);
    station->show();

    currentsta.clear();
}
