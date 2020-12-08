/********************************************************************************
** Form generated from reading UI file 'AttenuationParameterTab.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATTENUATIONPARAMETERTAB_H
#define UI_ATTENUATIONPARAMETERTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AttenuationParameterTab
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_test;
    QDoubleSpinBox *omega;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *AttenuationParameterTab)
    {
        if (AttenuationParameterTab->objectName().isEmpty())
            AttenuationParameterTab->setObjectName(QStringLiteral("AttenuationParameterTab"));
        AttenuationParameterTab->resize(302, 84);
        verticalLayout = new QVBoxLayout(AttenuationParameterTab);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_test = new QLabel(AttenuationParameterTab);
        label_test->setObjectName(QStringLiteral("label_test"));

        horizontalLayout->addWidget(label_test);

        omega = new QDoubleSpinBox(AttenuationParameterTab);
        omega->setObjectName(QStringLiteral("omega"));
        omega->setDecimals(3);

        horizontalLayout->addWidget(omega);

        horizontalSpacer = new QSpacerItem(53, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(AttenuationParameterTab);

        QMetaObject::connectSlotsByName(AttenuationParameterTab);
    } // setupUi

    void retranslateUi(QWidget *AttenuationParameterTab)
    {
        AttenuationParameterTab->setWindowTitle(QApplication::translate("AttenuationParameterTab", "Form", Q_NULLPTR));
        label_test->setText(QApplication::translate("AttenuationParameterTab", "Omega", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AttenuationParameterTab: public Ui_AttenuationParameterTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATTENUATIONPARAMETERTAB_H
