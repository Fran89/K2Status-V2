/********************************************************************************
** Form generated from reading UI file 'k2graph.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_K2GRAPH_H
#define UI_K2GRAPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_K2Graph
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QCustomPlot *Graph;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *graphTemp;
    QPushButton *graphVolt;
    QComboBox *comboBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *K2Graph)
    {
        if (K2Graph->objectName().isEmpty())
            K2Graph->setObjectName(QStringLiteral("K2Graph"));
        K2Graph->resize(964, 623);
        centralwidget = new QWidget(K2Graph);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        Graph = new QCustomPlot(centralwidget);
        Graph->setObjectName(QStringLiteral("Graph"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Graph->sizePolicy().hasHeightForWidth());
        Graph->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(Graph);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        graphTemp = new QPushButton(centralwidget);
        graphTemp->setObjectName(QStringLiteral("graphTemp"));

        horizontalLayout->addWidget(graphTemp);

        graphVolt = new QPushButton(centralwidget);
        graphVolt->setObjectName(QStringLiteral("graphVolt"));

        horizontalLayout->addWidget(graphVolt);

        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout);

        K2Graph->setCentralWidget(centralwidget);
        menubar = new QMenuBar(K2Graph);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 964, 19));
        K2Graph->setMenuBar(menubar);
        statusbar = new QStatusBar(K2Graph);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        K2Graph->setStatusBar(statusbar);

        retranslateUi(K2Graph);

        QMetaObject::connectSlotsByName(K2Graph);
    } // setupUi

    void retranslateUi(QMainWindow *K2Graph)
    {
        K2Graph->setWindowTitle(QApplication::translate("K2Graph", "MainWindow", 0));
        label->setText(QString());
        graphTemp->setText(QApplication::translate("K2Graph", "Graph Temperature", 0));
        graphVolt->setText(QApplication::translate("K2Graph", "Graph Voltage", 0));
    } // retranslateUi

};

namespace Ui {
    class K2Graph: public Ui_K2Graph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_K2GRAPH_H
