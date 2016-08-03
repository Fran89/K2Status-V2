#include "k2graph.h"
#include "ui_k2graph.h"

K2Graph::K2Graph(bool mssm, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::K2Graph)
{
    ui->setupUi(this);
    ssm = mssm;
    ready = ready1 = ready2= false;
    if (ssm){
        ui->comboBox->hide();
        ui->graphTemp->hide();
        ui->graphVolt->hide();
    }
    else
        ui->comboBox->clear();
    this->setWindowTitle("Station Graphs");
}

K2Graph::~K2Graph()
{
    delete ui;
}

void K2Graph::stnupdated(){
    ready = ready1 && ready2;
    if(!ssm && ready){
        Stations = MySta->Stations.keys();
        ui->comboBox->clear();
        for(int i =0; i < Stations.size(); i++)
            ui->comboBox->addItem(Stations.at(i));
    }
}

void K2Graph::showVGraph(QString sta){
    if((ready1 || ssm) && ready2){

        // Set Log File
        QFile file;
        file.setFileName(MyDir.filePath("./K2Logs/" + sta + "_log.csv"));

        currentStaLD.clear();

        if (file.open(QIODevice::ReadOnly))
            ui->label->setText(sta);
        else
            ui->label->setText("ERROR: NO SUCH FILE");

        while (!file.atEnd()){
            QByteArray line = file.readLine();
            if(line.split(',').size() == 5){
                currentStaLD.time.append(line.split(',').at(0).toDouble());
                currentStaLD.extime.append(line.split(',').at(1).toDouble());
                currentStaLD.temp.append(line.split(',').at(2).toDouble());
                currentStaLD.volt.append(line.split(',').at(3).toDouble());
                currentStaLD.chrg.append(line.split(',').at(4));
            }
        }
        ui->Graph->clearItems();
        ui->Graph->clearGraphs();
        ui->Graph->addGraph();

        ui->Graph->graph()->setPen(QPen(Qt::blue));
        //ui->Graph->graph()->setBrush(QBrush(QColor(240, 255, 200)));
        ui->Graph->graph()->setData(currentStaLD.time,
                                    currentStaLD.volt);
        ui->Graph->xAxis->rescale();
        ui->Graph->yAxis->rescale();
        QCPRange range;
        range = ui-> Graph->yAxis->range();
        ui->Graph->yAxis->setRangeLower(range.lower-0.5);


        // Set Axis Lable
        ui->Graph->xAxis->setLabel("Date (GMT)");
        ui->Graph->xAxis->setAutoTickStep(true);
        //ui->Graph->xAxis->setTickStep(86400);
        //ui->Graph->xAxis->setSubTickCount(1);
        ui->Graph->yAxis->setLabel("Voltage (V)");

        //ui->Graph->graph()->addData(time, Archive.at(idx).Voltage);

        // configure bottom axis to show date and time instead of number:
        ui->Graph->xAxis->setTickLabelType(QCPAxis::ltDateTime);
        ui->Graph->xAxis->setDateTimeFormat("d/MM/yyyy");
        ui->Graph->replot();
    }
}

void K2Graph::showTGraph(QString sta){
    if((ready1 || ssm) && ready2){

        // Set Log File
        QFile file;
        file.setFileName(MyDir.filePath("./K2Logs/" + sta + "_log.csv"));

        currentStaLD.clear();

        if (file.open(QIODevice::ReadOnly))
            ui->label->setText(sta);
        else
            ui->label->setText("ERROR: NO SUCH FILE");

        while (!file.atEnd()){
            QByteArray line = file.readLine();
            if(line.split(',').size() == 5){
                currentStaLD.time.append(line.split(',').at(0).toDouble());
                currentStaLD.extime.append(line.split(',').at(1).toDouble());
                currentStaLD.temp.append(line.split(',').at(2).toDouble());
                currentStaLD.volt.append(line.split(',').at(3).toDouble());
                currentStaLD.chrg.append(line.split(',').at(4));
            }
        }
        ui->Graph->clearItems();
        ui->Graph->clearGraphs();
        ui->Graph->addGraph();

        ui->Graph->graph()->setPen(QPen(Qt::blue));
        //ui->Graph->graph()->setBrush(QBrush(QColor(240, 255, 200)));
        ui->Graph->graph()->setData(currentStaLD.time,
                                    currentStaLD.temp);
        ui->Graph->xAxis->rescale();
        ui->Graph->yAxis->rescale();
        QCPRange range;
        range = ui-> Graph->yAxis->range();
        ui->Graph->yAxis->setRangeLower(range.lower-0.5);


        // Set Axis Lable
        ui->Graph->xAxis->setLabel("Date (GMT)");
        ui->Graph->xAxis->setAutoTickStep(true);
        //ui->Graph->xAxis->setTickStep(86400);
        //ui->Graph->xAxis->setSubTickCount(1);
        ui->Graph->yAxis->setLabel("Temperature (C)");

        //ui->Graph->graph()->addData(time, Archive.at(idx).Voltage);

        // configure bottom axis to show date and time instead of number:
        ui->Graph->xAxis->setTickLabelType(QCPAxis::ltDateTime);
        ui->Graph->xAxis->setDateTimeFormat("d/MM/yyyy");
        ui->Graph->replot();
    }
}

void K2Graph::setStations(StnInfo * stn){
    if(!ready1){
        MySta = stn;
        ready1 = true;
    }
}
void K2Graph::setPath(QDir dir){
    if(!ready2){
        MyDir = dir;
        ready2 = true;
    }
}

void K2Graph::logData::clear(){
    time.clear();
    extime.clear();
    volt.clear();
    temp.clear();
    chrg.clear();
}

void K2Graph::on_graphTemp_clicked()
{
    showTGraph(ui->comboBox->currentText());
}

void K2Graph::on_graphVolt_clicked()
{
    showVGraph(ui->comboBox->currentText());

}
