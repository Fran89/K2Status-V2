/********************************************************************************
** Form generated from reading UI file 'udpconfig.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UDPCONFIG_H
#define UI_UDPCONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_UDPConfig
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QFormLayout *formLayout_2;
    QLabel *label_3;
    QLineEdit *UDPIP;
    QLabel *label_2;
    QLineEdit *UDPPort;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout;
    QLineEdit *folderName;
    QPushButton *foldttrig;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *UDPConfig)
    {
        if (UDPConfig->objectName().isEmpty())
            UDPConfig->setObjectName(QStringLiteral("UDPConfig"));
        UDPConfig->resize(400, 300);
        verticalLayout = new QVBoxLayout(UDPConfig);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(UDPConfig);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout->addWidget(label);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_3 = new QLabel(UDPConfig);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_3);

        UDPIP = new QLineEdit(UDPConfig);
        UDPIP->setObjectName(QStringLiteral("UDPIP"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, UDPIP);

        label_2 = new QLabel(UDPConfig);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_2);

        UDPPort = new QLineEdit(UDPConfig);
        UDPPort->setObjectName(QStringLiteral("UDPPort"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, UDPPort);

        label_4 = new QLabel(UDPConfig);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        folderName = new QLineEdit(UDPConfig);
        folderName->setObjectName(QStringLiteral("folderName"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(folderName->sizePolicy().hasHeightForWidth());
        folderName->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(folderName);

        foldttrig = new QPushButton(UDPConfig);
        foldttrig->setObjectName(QStringLiteral("foldttrig"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(30);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(foldttrig->sizePolicy().hasHeightForWidth());
        foldttrig->setSizePolicy(sizePolicy1);
        foldttrig->setMinimumSize(QSize(30, 0));
        foldttrig->setMaximumSize(QSize(40, 16777215));

        horizontalLayout->addWidget(foldttrig);


        formLayout_2->setLayout(2, QFormLayout::FieldRole, horizontalLayout);


        verticalLayout->addLayout(formLayout_2);

        verticalSpacer = new QSpacerItem(20, 150, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(UDPConfig);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(UDPConfig);
        QObject::connect(buttonBox, SIGNAL(accepted()), UDPConfig, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), UDPConfig, SLOT(reject()));

        QMetaObject::connectSlotsByName(UDPConfig);
    } // setupUi

    void retranslateUi(QDialog *UDPConfig)
    {
        UDPConfig->setWindowTitle(QApplication::translate("UDPConfig", "Dialog", 0));
        label->setText(QApplication::translate("UDPConfig", "K2Status UDP Configuration", 0));
        label_3->setText(QApplication::translate("UDPConfig", "UDP Bind IP Address:", 0));
        label_2->setText(QApplication::translate("UDPConfig", "UPD Bind Port:", 0));
        label_4->setText(QApplication::translate("UDPConfig", "TextLabel", 0));
        foldttrig->setText(QApplication::translate("UDPConfig", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class UDPConfig: public Ui_UDPConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UDPCONFIG_H
