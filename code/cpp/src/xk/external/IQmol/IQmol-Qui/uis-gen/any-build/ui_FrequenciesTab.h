/********************************************************************************
** Form generated from reading UI file 'FrequenciesTab.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FREQUENCIESTAB_H
#define UI_FREQUENCIESTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrequenciesTab
{
public:
    QVBoxLayout *verticalLayout;
    QCheckBox *raman;
    QCheckBox *isotopes;
    QCheckBox *hess_proj_trm;
    QCheckBox *anharmonic;
    QHBoxLayout *_6;
    QSpacerItem *spacerItem;
    QLabel *vciLabel;
    QSpinBox *vci;
    QSpacerItem *spacerItem1;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *FrequenciesTab)
    {
        if (FrequenciesTab->objectName().isEmpty())
            FrequenciesTab->setObjectName(QStringLiteral("FrequenciesTab"));
        FrequenciesTab->resize(414, 159);
        verticalLayout = new QVBoxLayout(FrequenciesTab);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        raman = new QCheckBox(FrequenciesTab);
        raman->setObjectName(QStringLiteral("raman"));

        verticalLayout->addWidget(raman);

        isotopes = new QCheckBox(FrequenciesTab);
        isotopes->setObjectName(QStringLiteral("isotopes"));

        verticalLayout->addWidget(isotopes);

        hess_proj_trm = new QCheckBox(FrequenciesTab);
        hess_proj_trm->setObjectName(QStringLiteral("hess_proj_trm"));

        verticalLayout->addWidget(hess_proj_trm);

        anharmonic = new QCheckBox(FrequenciesTab);
        anharmonic->setObjectName(QStringLiteral("anharmonic"));

        verticalLayout->addWidget(anharmonic);

        _6 = new QHBoxLayout();
        _6->setObjectName(QStringLiteral("_6"));
        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        _6->addItem(spacerItem);

        vciLabel = new QLabel(FrequenciesTab);
        vciLabel->setObjectName(QStringLiteral("vciLabel"));

        _6->addWidget(vciLabel);

        vci = new QSpinBox(FrequenciesTab);
        vci->setObjectName(QStringLiteral("vci"));

        _6->addWidget(vci);

        spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        _6->addItem(spacerItem1);


        verticalLayout->addLayout(_6);

        verticalSpacer = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(FrequenciesTab);

        QMetaObject::connectSlotsByName(FrequenciesTab);
    } // setupUi

    void retranslateUi(QWidget *FrequenciesTab)
    {
        FrequenciesTab->setWindowTitle(QApplication::translate("FrequenciesTab", "Form", Q_NULLPTR));
        raman->setText(QApplication::translate("FrequenciesTab", "Raman Frequencies", Q_NULLPTR));
        isotopes->setText(QApplication::translate("FrequenciesTab", "Isotopic Analysis", Q_NULLPTR));
        hess_proj_trm->setText(QApplication::translate("FrequenciesTab", "Project Out Translational And Rotational Degrees Of Freedom", Q_NULLPTR));
        anharmonic->setText(QApplication::translate("FrequenciesTab", "Compute Anharmonic Corrections", Q_NULLPTR));
        vciLabel->setText(QApplication::translate("FrequenciesTab", "VCI Quanta", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FrequenciesTab: public Ui_FrequenciesTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FREQUENCIESTAB_H
