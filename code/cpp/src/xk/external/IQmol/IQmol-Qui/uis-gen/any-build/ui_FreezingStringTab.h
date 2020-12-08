/********************************************************************************
** Form generated from reading UI file 'FreezingStringTab.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FREEZINGSTRINGTAB_H
#define UI_FREEZINGSTRINGTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FreezingStringTab
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QComboBox *fsm_opt_mode;
    QLabel *label_67;
    QLabel *label_78;
    QLabel *label_77;
    QLabel *label_69;
    QComboBox *fsm_mode;
    QSpinBox *fsm_nnode;
    QSpinBox *fsm_ngrad;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *FreezingStringTab)
    {
        if (FreezingStringTab->objectName().isEmpty())
            FreezingStringTab->setObjectName(QStringLiteral("FreezingStringTab"));
        FreezingStringTab->resize(396, 99);
        verticalLayout = new QVBoxLayout(FreezingStringTab);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        fsm_opt_mode = new QComboBox(FreezingStringTab);
        fsm_opt_mode->setObjectName(QStringLiteral("fsm_opt_mode"));

        gridLayout->addWidget(fsm_opt_mode, 1, 3, 1, 1);

        label_67 = new QLabel(FreezingStringTab);
        label_67->setObjectName(QStringLiteral("label_67"));

        gridLayout->addWidget(label_67, 0, 0, 1, 1);

        label_78 = new QLabel(FreezingStringTab);
        label_78->setObjectName(QStringLiteral("label_78"));

        gridLayout->addWidget(label_78, 1, 2, 1, 1);

        label_77 = new QLabel(FreezingStringTab);
        label_77->setObjectName(QStringLiteral("label_77"));

        gridLayout->addWidget(label_77, 0, 2, 1, 1);

        label_69 = new QLabel(FreezingStringTab);
        label_69->setObjectName(QStringLiteral("label_69"));

        gridLayout->addWidget(label_69, 1, 0, 1, 1);

        fsm_mode = new QComboBox(FreezingStringTab);
        fsm_mode->setObjectName(QStringLiteral("fsm_mode"));

        gridLayout->addWidget(fsm_mode, 0, 3, 1, 1);

        fsm_nnode = new QSpinBox(FreezingStringTab);
        fsm_nnode->setObjectName(QStringLiteral("fsm_nnode"));

        gridLayout->addWidget(fsm_nnode, 0, 1, 1, 1);

        fsm_ngrad = new QSpinBox(FreezingStringTab);
        fsm_ngrad->setObjectName(QStringLiteral("fsm_ngrad"));

        gridLayout->addWidget(fsm_ngrad, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 4, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(FreezingStringTab);

        QMetaObject::connectSlotsByName(FreezingStringTab);
    } // setupUi

    void retranslateUi(QWidget *FreezingStringTab)
    {
        FreezingStringTab->setWindowTitle(QApplication::translate("FreezingStringTab", "Form", Q_NULLPTR));
        label_67->setText(QApplication::translate("FreezingStringTab", "Nodes", Q_NULLPTR));
        label_78->setText(QApplication::translate("FreezingStringTab", "Opt Method", Q_NULLPTR));
        label_77->setText(QApplication::translate("FreezingStringTab", "Interpolation", Q_NULLPTR));
        label_69->setText(QApplication::translate("FreezingStringTab", "Gradient Steps", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FreezingStringTab: public Ui_FreezingStringTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FREEZINGSTRINGTAB_H
