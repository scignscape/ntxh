/********************************************************************************
** Form generated from reading UI file 'PrimaryBasisTab.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRIMARYBASISTAB_H
#define UI_PRIMARYBASISTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
            PrimaryBasisTab->setObjectName(QStringLiteral("PrimaryBasisTab"));
        PrimaryBasisTab->resize(302, 84);
        verticalLayout = new QVBoxLayout(PrimaryBasisTab);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        qui_primary_basis = new QComboBox(PrimaryBasisTab);
        qui_primary_basis->setObjectName(QStringLiteral("qui_primary_basis"));

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
        PrimaryBasisTab->setWindowTitle(QApplication::translate("PrimaryBasisTab", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PrimaryBasisTab: public Ui_PrimaryBasisTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRIMARYBASISTAB_H
