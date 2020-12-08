/********************************************************************************
** Form generated from reading UI file 'CisTab.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CISTAB_H
#define UI_CISTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
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
            CisTab->setObjectName(QStringLiteral("CisTab"));
        CisTab->resize(426, 200);
        verticalLayout = new QVBoxLayout(CisTab);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        _3 = new QGridLayout();
        _3->setObjectName(QStringLiteral("_3"));
        cis_ampl_anal = new QCheckBox(CisTab);
        cis_ampl_anal->setObjectName(QStringLiteral("cis_ampl_anal"));

        _3->addWidget(cis_ampl_anal, 4, 2, 1, 4);

        label_cis_state_derivative = new QLabel(CisTab);
        label_cis_state_derivative->setObjectName(QStringLiteral("label_cis_state_derivative"));

        _3->addWidget(label_cis_state_derivative, 1, 0, 1, 1);

        cis_moments = new QCheckBox(CisTab);
        cis_moments->setObjectName(QStringLiteral("cis_moments"));

        _3->addWidget(cis_moments, 4, 0, 1, 2);

        cis_state_derivative = new QSpinBox(CisTab);
        cis_state_derivative->setObjectName(QStringLiteral("cis_state_derivative"));

        _3->addWidget(cis_state_derivative, 1, 1, 1, 1);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        _3->addItem(spacerItem, 0, 5, 1, 1);

        xcis = new QCheckBox(CisTab);
        xcis->setObjectName(QStringLiteral("xcis"));

        _3->addWidget(xcis, 1, 3, 1, 1);

        cis_n_roots = new QSpinBox(CisTab);
        cis_n_roots->setObjectName(QStringLiteral("cis_n_roots"));

        _3->addWidget(cis_n_roots, 0, 1, 1, 1);

        sts_mom = new QCheckBox(CisTab);
        sts_mom->setObjectName(QStringLiteral("sts_mom"));

        _3->addWidget(sts_mom, 5, 0, 1, 2);

        spin_flip_xcis = new QCheckBox(CisTab);
        spin_flip_xcis->setObjectName(QStringLiteral("spin_flip_xcis"));

        _3->addWidget(spin_flip_xcis, 1, 4, 1, 1);

        label_91 = new QLabel(CisTab);
        label_91->setObjectName(QStringLiteral("label_91"));

        _3->addWidget(label_91, 0, 0, 1, 1);

        rpa = new QCheckBox(CisTab);
        rpa->setObjectName(QStringLiteral("rpa"));

        _3->addWidget(rpa, 0, 3, 1, 1);

        cis_singlets = new QCheckBox(CisTab);
        cis_singlets->setObjectName(QStringLiteral("cis_singlets"));

        _3->addWidget(cis_singlets, 0, 2, 1, 1);

        spin_flip = new QCheckBox(CisTab);
        spin_flip->setObjectName(QStringLiteral("spin_flip"));

        _3->addWidget(spin_flip, 0, 4, 1, 1);

        cis_mulliken = new QCheckBox(CisTab);
        cis_mulliken->setObjectName(QStringLiteral("cis_mulliken"));

        _3->addWidget(cis_mulliken, 3, 0, 1, 2);

        cis_triplets = new QCheckBox(CisTab);
        cis_triplets->setObjectName(QStringLiteral("cis_triplets"));

        _3->addWidget(cis_triplets, 1, 2, 1, 1);

        cis_relaxed_density = new QCheckBox(CisTab);
        cis_relaxed_density->setObjectName(QStringLiteral("cis_relaxed_density"));

        _3->addWidget(cis_relaxed_density, 3, 2, 1, 4);

        label_118 = new QLabel(CisTab);
        label_118->setObjectName(QStringLiteral("label_118"));

        _3->addWidget(label_118, 2, 0, 1, 1);

        nto_pairs = new QSpinBox(CisTab);
        nto_pairs->setObjectName(QStringLiteral("nto_pairs"));

        _3->addWidget(nto_pairs, 2, 1, 1, 1);


        verticalLayout->addLayout(_3);

        verticalSpacer = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(CisTab);

        QMetaObject::connectSlotsByName(CisTab);
    } // setupUi

    void retranslateUi(QWidget *CisTab)
    {
        CisTab->setWindowTitle(QApplication::translate("CisTab", "Form", Q_NULLPTR));
        cis_ampl_anal->setText(QApplication::translate("CisTab", "Analyze Amplitudes", Q_NULLPTR));
        label_cis_state_derivative->setText(QApplication::translate("CisTab", "State To Optimize", Q_NULLPTR));
        cis_moments->setText(QApplication::translate("CisTab", "Excited State Moments", Q_NULLPTR));
        xcis->setText(QApplication::translate("CisTab", "XCIS", Q_NULLPTR));
        sts_mom->setText(QApplication::translate("CisTab", "Transition Moments", Q_NULLPTR));
        spin_flip_xcis->setText(QApplication::translate("CisTab", "SF-XCIS", Q_NULLPTR));
        label_91->setText(QApplication::translate("CisTab", "Number of Roots", Q_NULLPTR));
        rpa->setText(QApplication::translate("CisTab", "RPA", Q_NULLPTR));
        cis_singlets->setText(QApplication::translate("CisTab", "Singlets", Q_NULLPTR));
        spin_flip->setText(QApplication::translate("CisTab", "Spin Flip", Q_NULLPTR));
        cis_mulliken->setText(QApplication::translate("CisTab", "State Mulliken Charges", Q_NULLPTR));
        cis_triplets->setText(QApplication::translate("CisTab", "Triplets", Q_NULLPTR));
        cis_relaxed_density->setText(QApplication::translate("CisTab", "Analyze Relaxed Density", Q_NULLPTR));
        label_118->setText(QApplication::translate("CisTab", "NTO Pairs", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CisTab: public Ui_CisTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CISTAB_H
