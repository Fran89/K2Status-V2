/********************************************************************************
** Form generated from reading UI file 'k2statusv2.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_K2STATUSV2_H
#define UI_K2STATUSV2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_K2StatusV2
{
public:
    QAction *actionLoad_Station_list;
    QAction *actionAdd_a_Connection;
    QAction *actionGraph;
    QAction *actionAbout_Me;
    QAction *actionAbout_QT;
    QAction *actionDebug_Mode;
    QAction *actionQuit;
    QAction *actionDisconnect;
    QAction *actionEnable_Logging;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTableView *MyMetadataTableView;
    QTextBrowser *textBrowser;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *K2StatusV2)
    {
        if (K2StatusV2->objectName().isEmpty())
            K2StatusV2->setObjectName(QStringLiteral("K2StatusV2"));
        K2StatusV2->resize(986, 551);
        actionLoad_Station_list = new QAction(K2StatusV2);
        actionLoad_Station_list->setObjectName(QStringLiteral("actionLoad_Station_list"));
        actionAdd_a_Connection = new QAction(K2StatusV2);
        actionAdd_a_Connection->setObjectName(QStringLiteral("actionAdd_a_Connection"));
        actionGraph = new QAction(K2StatusV2);
        actionGraph->setObjectName(QStringLiteral("actionGraph"));
        actionAbout_Me = new QAction(K2StatusV2);
        actionAbout_Me->setObjectName(QStringLiteral("actionAbout_Me"));
        actionAbout_QT = new QAction(K2StatusV2);
        actionAbout_QT->setObjectName(QStringLiteral("actionAbout_QT"));
        actionDebug_Mode = new QAction(K2StatusV2);
        actionDebug_Mode->setObjectName(QStringLiteral("actionDebug_Mode"));
        actionQuit = new QAction(K2StatusV2);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionDisconnect = new QAction(K2StatusV2);
        actionDisconnect->setObjectName(QStringLiteral("actionDisconnect"));
        actionEnable_Logging = new QAction(K2StatusV2);
        actionEnable_Logging->setObjectName(QStringLiteral("actionEnable_Logging"));
        actionEnable_Logging->setCheckable(true);
        centralWidget = new QWidget(K2StatusV2);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        MyMetadataTableView = new QTableView(centralWidget);
        MyMetadataTableView->setObjectName(QStringLiteral("MyMetadataTableView"));

        verticalLayout->addWidget(MyMetadataTableView);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy);
        textBrowser->setMinimumSize(QSize(0, 0));
        textBrowser->setMaximumSize(QSize(16777215, 100));
        textBrowser->setBaseSize(QSize(0, 0));

        verticalLayout->addWidget(textBrowser);

        K2StatusV2->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(K2StatusV2);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 986, 19));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        K2StatusV2->setMenuBar(menuBar);
        mainToolBar = new QToolBar(K2StatusV2);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        K2StatusV2->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(K2StatusV2);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        K2StatusV2->setStatusBar(statusBar);

        menuBar->addAction(menuMenu->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuMenu->addAction(actionAdd_a_Connection);
        menuMenu->addAction(actionDisconnect);
        menuMenu->addSeparator();
        menuMenu->addAction(actionLoad_Station_list);
        menuMenu->addAction(actionGraph);
        menuMenu->addAction(actionEnable_Logging);
        menuMenu->addSeparator();
        menuMenu->addAction(actionQuit);
        menuHelp->addAction(actionDebug_Mode);
        menuHelp->addAction(actionAbout_Me);
        menuHelp->addAction(actionAbout_QT);

        retranslateUi(K2StatusV2);

        QMetaObject::connectSlotsByName(K2StatusV2);
    } // setupUi

    void retranslateUi(QMainWindow *K2StatusV2)
    {
        K2StatusV2->setWindowTitle(QApplication::translate("K2StatusV2", "K2StatusV2", 0));
        actionLoad_Station_list->setText(QApplication::translate("K2StatusV2", "Add a Station", 0));
        actionAdd_a_Connection->setText(QApplication::translate("K2StatusV2", "Connect to EW (UDP)", 0));
        actionGraph->setText(QApplication::translate("K2StatusV2", "Graph", 0));
        actionAbout_Me->setText(QApplication::translate("K2StatusV2", "About Me", 0));
        actionAbout_QT->setText(QApplication::translate("K2StatusV2", "About QT", 0));
        actionDebug_Mode->setText(QApplication::translate("K2StatusV2", "Debug Mode", 0));
        actionQuit->setText(QApplication::translate("K2StatusV2", "Quit", 0));
        actionDisconnect->setText(QApplication::translate("K2StatusV2", "Disconnect", 0));
        actionEnable_Logging->setText(QApplication::translate("K2StatusV2", "Enable Logging", 0));
        menuMenu->setTitle(QApplication::translate("K2StatusV2", "Menu", 0));
        menuHelp->setTitle(QApplication::translate("K2StatusV2", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class K2StatusV2: public Ui_K2StatusV2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_K2STATUSV2_H
