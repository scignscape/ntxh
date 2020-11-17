/********************************************************************************
** Form generated from reading UI file 'AuxiliaryBasisTab.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUXILIARYBASISTAB_H
#define UI_AUXILIARYBASISTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuxiliaryBasisTab
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_test;
    QComboBox *auxiliary_basis;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *AuxiliaryBasisTab)
    {
        if (AuxiliaryBasisTab->objectName().isEmpty())
            AuxiliaryBasisTab->setObjectName(QString::fromUtf8("AuxiliaryBasisTab"));
        AuxiliaryBasisTab->resize(302, 84);
        verticalLayout = new QVBoxLayout(AuxiliaryBasisTab);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_test = new QLabel(AuxiliaryBasisTab);
        label_test->setObjectName(QString::fromUtf8("label_test"));

        horizontalLayout->addWidget(label_test);

        auxiliary_basis = new QComboBox(AuxiliaryBasisTab);
        auxiliary_basis->setObjectName(QString::fromUtf8("auxiliary_basis"));

        horizontalLayout->addWidget(auxiliary_basis);

        horizontalSpacer = new QSpacerItem(53, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(AuxiliaryBasisTab);

        QMetaObject::connectSlotsByName(AuxiliaryBasisTab);
    } // setupUi

    void retranslateUi(QWidget *AuxiliaryBasisTab)
    {
        AuxiliaryBasisTab->setWindowTitle(QApplication::translate("AuxiliaryBasisTab", "Form", nullptr));
        label_test->setText(QApplication::translate("AuxiliaryBasisTab", "RI Fitting Basis", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuxiliaryBasisTab: public Ui_AuxiliaryBasisTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUXILIARYBASISTAB_H
