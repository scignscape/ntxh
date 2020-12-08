/********************************************************************************
** Form generated from reading UI file 'AuxiliaryBasisTab.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUXILIARYBASISTAB_H
#define UI_AUXILIARYBASISTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
            AuxiliaryBasisTab->setObjectName(QStringLiteral("AuxiliaryBasisTab"));
        AuxiliaryBasisTab->resize(302, 84);
        verticalLayout = new QVBoxLayout(AuxiliaryBasisTab);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_test = new QLabel(AuxiliaryBasisTab);
        label_test->setObjectName(QStringLiteral("label_test"));

        horizontalLayout->addWidget(label_test);

        auxiliary_basis = new QComboBox(AuxiliaryBasisTab);
        auxiliary_basis->setObjectName(QStringLiteral("auxiliary_basis"));

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
        AuxiliaryBasisTab->setWindowTitle(QApplication::translate("AuxiliaryBasisTab", "Form", Q_NULLPTR));
        label_test->setText(QApplication::translate("AuxiliaryBasisTab", "RI Fitting Basis", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AuxiliaryBasisTab: public Ui_AuxiliaryBasisTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUXILIARYBASISTAB_H
