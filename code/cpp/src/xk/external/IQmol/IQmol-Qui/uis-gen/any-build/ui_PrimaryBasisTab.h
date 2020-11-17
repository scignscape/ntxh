/********************************************************************************
** Form generated from reading UI file 'PrimaryBasisTab.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRIMARYBASISTAB_H
#define UI_PRIMARYBASISTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PrimaryBasisTab
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QComboBox *qui_primary_basis;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *PrimaryBasisTab)
    {
        if (PrimaryBasisTab->objectName().isEmpty())
            PrimaryBasisTab->setObjectName(QString::fromUtf8("PrimaryBasisTab"));
        PrimaryBasisTab->resize(302, 84);
        verticalLayout = new QVBoxLayout(PrimaryBasisTab);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        qui_primary_basis = new QComboBox(PrimaryBasisTab);
        qui_primary_basis->setObjectName(QString::fromUtf8("qui_primary_basis"));

        horizontalLayout->addWidget(qui_primary_basis);

        horizontalSpacer = new QSpacerItem(53, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(PrimaryBasisTab);

        QMetaObject::connectSlotsByName(PrimaryBasisTab);
    } // setupUi

    void retranslateUi(QWidget *PrimaryBasisTab)
    {
        PrimaryBasisTab->setWindowTitle(QApplication::translate("PrimaryBasisTab", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PrimaryBasisTab: public Ui_PrimaryBasisTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRIMARYBASISTAB_H
