/********************************************************************************
** Form generated from reading UI file 'AdcTab.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADCTAB_H
#define UI_ADCTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdcTab
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayoutADC2;
    QCheckBox *adc_prop_cd;
    QCheckBox *adc_prop_soc;
    QCheckBox *adc_ecorr;
    QGridLayout *gridLayout;
    QLabel *label_adc1;
    QLineEdit *qui_adc_states2;
    QLabel *label_adc2;
    QLineEdit *qui_adc_states1;
    QLabel *label_adc_core;
    QSpinBox *qui_adc_core;
    QCheckBox *adc_prop_tpa;
    QCheckBox *adc_prop_es;
    QSpacerItem *horizontalSpacer;
    QCheckBox *adc_prop_es2es;
    QCheckBox *adc_do_diis;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *AdcTab)
    {
        if (AdcTab->objectName().isEmpty())
            AdcTab->setObjectName(QString::fromUtf8("AdcTab"));
        AdcTab->resize(391, 234);
        verticalLayout = new QVBoxLayout(AdcTab);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayoutADC2 = new QGridLayout();
        gridLayoutADC2->setObjectName(QString::fromUtf8("gridLayoutADC2"));
        adc_prop_cd = new QCheckBox(AdcTab);
        adc_prop_cd->setObjectName(QString::fromUtf8("adc_prop_cd"));

        gridLayoutADC2->addWidget(adc_prop_cd, 3, 0, 1, 1);

        adc_prop_soc = new QCheckBox(AdcTab);
        adc_prop_soc->setObjectName(QString::fromUtf8("adc_prop_soc"));

        gridLayoutADC2->addWidget(adc_prop_soc, 3, 1, 1, 1);

        adc_ecorr = new QCheckBox(AdcTab);
        adc_ecorr->setObjectName(QString::fromUtf8("adc_ecorr"));

        gridLayoutADC2->addWidget(adc_ecorr, 2, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_adc1 = new QLabel(AdcTab);
        label_adc1->setObjectName(QString::fromUtf8("label_adc1"));

        gridLayout->addWidget(label_adc1, 0, 0, 1, 1);

        qui_adc_states2 = new QLineEdit(AdcTab);
        qui_adc_states2->setObjectName(QString::fromUtf8("qui_adc_states2"));

        gridLayout->addWidget(qui_adc_states2, 1, 1, 1, 1);

        label_adc2 = new QLabel(AdcTab);
        label_adc2->setObjectName(QString::fromUtf8("label_adc2"));

        gridLayout->addWidget(label_adc2, 1, 0, 1, 1);

        qui_adc_states1 = new QLineEdit(AdcTab);
        qui_adc_states1->setObjectName(QString::fromUtf8("qui_adc_states1"));

        gridLayout->addWidget(qui_adc_states1, 0, 1, 1, 1);

        label_adc_core = new QLabel(AdcTab);
        label_adc_core->setObjectName(QString::fromUtf8("label_adc_core"));

        gridLayout->addWidget(label_adc_core, 2, 0, 1, 1);

        qui_adc_core = new QSpinBox(AdcTab);
        qui_adc_core->setObjectName(QString::fromUtf8("qui_adc_core"));

        gridLayout->addWidget(qui_adc_core, 2, 1, 1, 1);


        gridLayoutADC2->addLayout(gridLayout, 0, 0, 1, 1);

        adc_prop_tpa = new QCheckBox(AdcTab);
        adc_prop_tpa->setObjectName(QString::fromUtf8("adc_prop_tpa"));

        gridLayoutADC2->addWidget(adc_prop_tpa, 2, 0, 1, 1);

        adc_prop_es = new QCheckBox(AdcTab);
        adc_prop_es->setObjectName(QString::fromUtf8("adc_prop_es"));

        gridLayoutADC2->addWidget(adc_prop_es, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(166, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayoutADC2->addItem(horizontalSpacer, 3, 2, 1, 1);

        adc_prop_es2es = new QCheckBox(AdcTab);
        adc_prop_es2es->setObjectName(QString::fromUtf8("adc_prop_es2es"));

        gridLayoutADC2->addWidget(adc_prop_es2es, 1, 1, 1, 1);

        adc_do_diis = new QCheckBox(AdcTab);
        adc_do_diis->setObjectName(QString::fromUtf8("adc_do_diis"));

        gridLayoutADC2->addWidget(adc_do_diis, 4, 0, 1, 1);


        verticalLayout->addLayout(gridLayoutADC2);

        verticalSpacer = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

#ifndef QT_NO_SHORTCUT
        label_adc1->setBuddy(qui_adc_states1);
        label_adc2->setBuddy(qui_adc_states2);
#endif // QT_NO_SHORTCUT

        retranslateUi(AdcTab);

        QMetaObject::connectSlotsByName(AdcTab);
    } // setupUi

    void retranslateUi(QWidget *AdcTab)
    {
        AdcTab->setWindowTitle(QApplication::translate("AdcTab", "Form", nullptr));
        adc_prop_cd->setText(QApplication::translate("AdcTab", "Circular Dichroism", nullptr));
        adc_prop_soc->setText(QApplication::translate("AdcTab", "Spin-Orbit Coupling", nullptr));
        adc_ecorr->setText(QApplication::translate("AdcTab", "Energy Corrections", nullptr));
        label_adc1->setText(QApplication::translate("AdcTab", "Singlet States", nullptr));
        label_adc2->setText(QApplication::translate("AdcTab", "Triplet States", nullptr));
        label_adc_core->setText(QApplication::translate("AdcTab", "Core Orbitals", nullptr));
        adc_prop_tpa->setText(QApplication::translate("AdcTab", "Two-Photon Absorption", nullptr));
        adc_prop_es->setText(QApplication::translate("AdcTab", "Excited State Properties", nullptr));
        adc_prop_es2es->setText(QApplication::translate("AdcTab", "State-to-State Properties", nullptr));
        adc_do_diis->setText(QApplication::translate("AdcTab", "Use DIIS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdcTab: public Ui_AdcTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADCTAB_H
