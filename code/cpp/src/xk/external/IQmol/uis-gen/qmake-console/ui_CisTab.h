/********************************************************************************
** Form generated from reading UI file 'CisTab.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CISTAB_H
#define UI_CISTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CisTab
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *_3;
    QCheckBox *cis_ampl_anal;
    QLabel *label_cis_state_derivative;
    QCheckBox *cis_moments;
    QSpinBox *cis_state_derivative;
    QSpacerItem *spacerItem;
    QCheckBox *xcis;
    QSpinBox *cis_n_roots;
    QCheckBox *sts_mom;
    QCheckBox *spin_flip_xcis;
    QLabel *label_91;
    QCheckBox *rpa;
    QCheckBox *cis_singlets;
    QCheckBox *spin_flip;
    QCheckBox *cis_mulliken;
    QCheckBox *cis_triplets;
    QCheckBox *cis_relaxed_density;
    QLabel *label_118;
    QSpinBox *nto_pairs;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *CisTab)
    {
        if (CisTab->objectName().isEmpty())
            CisTab->setObjectName(QString::fromUtf8("CisTab"));
        CisTab->resize(426, 200);
        verticalLayout = new QVBoxLayout(CisTab);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        _3 = new QGridLayout();
        _3->setObjectName(QString::fromUtf8("_3"));
        cis_ampl_anal = new QCheckBox(CisTab);
        cis_ampl_anal->setObjectName(QString::fromUtf8("cis_ampl_anal"));

        _3->addWidget(cis_ampl_anal, 4, 2, 1, 4);

        label_cis_state_derivative = new QLabel(CisTab);
        label_cis_state_derivative->setObjectName(QString::fromUtf8("label_cis_state_derivative"));

        _3->addWidget(label_cis_state_derivative, 1, 0, 1, 1);

        cis_moments = new QCheckBox(CisTab);
        cis_moments->setObjectName(QString::fromUtf8("cis_moments"));

        _3->addWidget(cis_moments, 4, 0, 1, 2);

        cis_state_derivative = new QSpinBox(CisTab);
        cis_state_derivative->setObjectName(QString::fromUtf8("cis_state_derivative"));

        _3->addWidget(cis_state_derivative, 1, 1, 1, 1);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        _3->addItem(spacerItem, 0, 5, 1, 1);

        xcis = new QCheckBox(CisTab);
        xcis->setObjectName(QString::fromUtf8("xcis"));

        _3->addWidget(xcis, 1, 3, 1, 1);

        cis_n_roots = new QSpinBox(CisTab);
        cis_n_roots->setObjectName(QString::fromUtf8("cis_n_roots"));

        _3->addWidget(cis_n_roots, 0, 1, 1, 1);

        sts_mom = new QCheckBox(CisTab);
        sts_mom->setObjectName(QString::fromUtf8("sts_mom"));

        _3->addWidget(sts_mom, 5, 0, 1, 2);

        spin_flip_xcis = new QCheckBox(CisTab);
        spin_flip_xcis->setObjectName(QString::fromUtf8("spin_flip_xcis"));

        _3->addWidget(spin_flip_xcis, 1, 4, 1, 1);

        label_91 = new QLabel(CisTab);
        label_91->setObjectName(QString::fromUtf8("label_91"));

        _3->addWidget(label_91, 0, 0, 1, 1);

        rpa = new QCheckBox(CisTab);
        rpa->setObjectName(QString::fromUtf8("rpa"));

        _3->addWidget(rpa, 0, 3, 1, 1);

        cis_singlets = new QCheckBox(CisTab);
        cis_singlets->setObjectName(QString::fromUtf8("cis_singlets"));

        _3->addWidget(cis_singlets, 0, 2, 1, 1);

        spin_flip = new QCheckBox(CisTab);
        spin_flip->setObjectName(QString::fromUtf8("spin_flip"));

        _3->addWidget(spin_flip, 0, 4, 1, 1);

        cis_mulliken = new QCheckBox(CisTab);
        cis_mulliken->setObjectName(QString::fromUtf8("cis_mulliken"));

        _3->addWidget(cis_mulliken, 3, 0, 1, 2);

        cis_triplets = new QCheckBox(CisTab);
        cis_triplets->setObjectName(QString::fromUtf8("cis_triplets"));

        _3->addWidget(cis_triplets, 1, 2, 1, 1);

        cis_relaxed_density = new QCheckBox(CisTab);
        cis_relaxed_density->setObjectName(QString::fromUtf8("cis_relaxed_density"));

        _3->addWidget(cis_relaxed_density, 3, 2, 1, 4);

        label_118 = new QLabel(CisTab);
        label_118->setObjectName(QString::fromUtf8("label_118"));

        _3->addWidget(label_118, 2, 0, 1, 1);

        nto_pairs = new QSpinBox(CisTab);
        nto_pairs->setObjectName(QString::fromUtf8("nto_pairs"));

        _3->addWidget(nto_pairs, 2, 1, 1, 1);


        verticalLayout->addLayout(_3);

        verticalSpacer = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(CisTab);

        QMetaObject::connectSlotsByName(CisTab);
    } // setupUi

    void retranslateUi(QWidget *CisTab)
    {
        CisTab->setWindowTitle(QApplication::translate("CisTab", "Form", nullptr));
        cis_ampl_anal->setText(QApplication::translate("CisTab", "Analyze Amplitudes", nullptr));
        label_cis_state_derivative->setText(QApplication::translate("CisTab", "State To Optimize", nullptr));
        cis_moments->setText(QApplication::translate("CisTab", "Excited State Moments", nullptr));
        xcis->setText(QApplication::translate("CisTab", "XCIS", nullptr));
        sts_mom->setText(QApplication::translate("CisTab", "Transition Moments", nullptr));
        spin_flip_xcis->setText(QApplication::translate("CisTab", "SF-XCIS", nullptr));
        label_91->setText(QApplication::translate("CisTab", "Number of Roots", nullptr));
        rpa->setText(QApplication::translate("CisTab", "RPA", nullptr));
        cis_singlets->setText(QApplication::translate("CisTab", "Singlets", nullptr));
        spin_flip->setText(QApplication::translate("CisTab", "Spin Flip", nullptr));
        cis_mulliken->setText(QApplication::translate("CisTab", "State Mulliken Charges", nullptr));
        cis_triplets->setText(QApplication::translate("CisTab", "Triplets", nullptr));
        cis_relaxed_density->setText(QApplication::translate("CisTab", "Analyze Relaxed Density", nullptr));
        label_118->setText(QApplication::translate("CisTab", "NTO Pairs", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CisTab: public Ui_CisTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CISTAB_H
