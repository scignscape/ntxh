/********************************************************************************
** Form generated from reading UI file 'EomTab.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EOMTAB_H
#define UI_EOMTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EomTab
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *qui_eom_ee;
    QRadioButton *qui_eom_sf;
    QRadioButton *qui_eom_ip;
    QRadioButton *qui_eom_ea;
    QRadioButton *qui_eom_dip;
    QSpacerItem *horizontalSpacer_11;
    QGridLayout *gridLayout_7;
    QLabel *label_eom1;
    QLineEdit *qui_eom_states1;
    QSpacerItem *horizontalSpacer_16;
    QLabel *label_eom2;
    QLineEdit *qui_eom_states2;
    QCheckBox *cc_eom_properties;
    QCheckBox *cc_eom_transition_properties;
    QCheckBox *eom_ref_prop_te;
    QLabel *label_cc_state_to_opt;
    QLineEdit *cc_state_to_opt;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *EomTab)
    {
        if (EomTab->objectName().isEmpty())
            EomTab->setObjectName(QString::fromUtf8("EomTab"));
        EomTab->resize(488, 172);
        verticalLayout = new QVBoxLayout(EomTab);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        qui_eom_ee = new QRadioButton(EomTab);
        qui_eom_ee->setObjectName(QString::fromUtf8("qui_eom_ee"));

        horizontalLayout_6->addWidget(qui_eom_ee);

        qui_eom_sf = new QRadioButton(EomTab);
        qui_eom_sf->setObjectName(QString::fromUtf8("qui_eom_sf"));

        horizontalLayout_6->addWidget(qui_eom_sf);

        qui_eom_ip = new QRadioButton(EomTab);
        qui_eom_ip->setObjectName(QString::fromUtf8("qui_eom_ip"));

        horizontalLayout_6->addWidget(qui_eom_ip);

        qui_eom_ea = new QRadioButton(EomTab);
        qui_eom_ea->setObjectName(QString::fromUtf8("qui_eom_ea"));

        horizontalLayout_6->addWidget(qui_eom_ea);

        qui_eom_dip = new QRadioButton(EomTab);
        qui_eom_dip->setObjectName(QString::fromUtf8("qui_eom_dip"));

        horizontalLayout_6->addWidget(qui_eom_dip);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_11);


        verticalLayout->addLayout(horizontalLayout_6);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_eom1 = new QLabel(EomTab);
        label_eom1->setObjectName(QString::fromUtf8("label_eom1"));

        gridLayout_7->addWidget(label_eom1, 0, 0, 1, 1);

        qui_eom_states1 = new QLineEdit(EomTab);
        qui_eom_states1->setObjectName(QString::fromUtf8("qui_eom_states1"));

        gridLayout_7->addWidget(qui_eom_states1, 0, 1, 1, 1);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_16, 0, 3, 1, 1);

        label_eom2 = new QLabel(EomTab);
        label_eom2->setObjectName(QString::fromUtf8("label_eom2"));

        gridLayout_7->addWidget(label_eom2, 1, 0, 1, 1);

        qui_eom_states2 = new QLineEdit(EomTab);
        qui_eom_states2->setObjectName(QString::fromUtf8("qui_eom_states2"));

        gridLayout_7->addWidget(qui_eom_states2, 1, 1, 1, 1);

        cc_eom_properties = new QCheckBox(EomTab);
        cc_eom_properties->setObjectName(QString::fromUtf8("cc_eom_properties"));

        gridLayout_7->addWidget(cc_eom_properties, 0, 2, 1, 1);

        cc_eom_transition_properties = new QCheckBox(EomTab);
        cc_eom_transition_properties->setObjectName(QString::fromUtf8("cc_eom_transition_properties"));

        gridLayout_7->addWidget(cc_eom_transition_properties, 1, 2, 1, 1);

        eom_ref_prop_te = new QCheckBox(EomTab);
        eom_ref_prop_te->setObjectName(QString::fromUtf8("eom_ref_prop_te"));

        gridLayout_7->addWidget(eom_ref_prop_te, 2, 2, 1, 1);

        label_cc_state_to_opt = new QLabel(EomTab);
        label_cc_state_to_opt->setObjectName(QString::fromUtf8("label_cc_state_to_opt"));

        gridLayout_7->addWidget(label_cc_state_to_opt, 2, 0, 1, 1);

        cc_state_to_opt = new QLineEdit(EomTab);
        cc_state_to_opt->setObjectName(QString::fromUtf8("cc_state_to_opt"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cc_state_to_opt->sizePolicy().hasHeightForWidth());
        cc_state_to_opt->setSizePolicy(sizePolicy);
        cc_state_to_opt->setMaximumSize(QSize(1677715, 16777215));
        cc_state_to_opt->setSizeIncrement(QSize(0, 0));

        gridLayout_7->addWidget(cc_state_to_opt, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_7);

        verticalSpacer = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(EomTab);

        QMetaObject::connectSlotsByName(EomTab);
    } // setupUi

    void retranslateUi(QWidget *EomTab)
    {
        EomTab->setWindowTitle(QApplication::translate("EomTab", "Form", nullptr));
        qui_eom_ee->setText(QApplication::translate("EomTab", "EE", nullptr));
        qui_eom_sf->setText(QApplication::translate("EomTab", "SF", nullptr));
        qui_eom_ip->setText(QApplication::translate("EomTab", "IP", nullptr));
        qui_eom_ea->setText(QApplication::translate("EomTab", "EA", nullptr));
        qui_eom_dip->setText(QApplication::translate("EomTab", "DIP", nullptr));
        label_eom1->setText(QApplication::translate("EomTab", "Singlets", nullptr));
        label_eom2->setText(QApplication::translate("EomTab", "Triplets", nullptr));
        cc_eom_properties->setText(QApplication::translate("EomTab", "Excited State Properties", nullptr));
        cc_eom_transition_properties->setText(QApplication::translate("EomTab", "Transition Properties", nullptr));
        eom_ref_prop_te->setText(QApplication::translate("EomTab", "2 Electron Transition Properties", nullptr));
        label_cc_state_to_opt->setText(QApplication::translate("EomTab", "State to optimize", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EomTab: public Ui_EomTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EOMTAB_H
