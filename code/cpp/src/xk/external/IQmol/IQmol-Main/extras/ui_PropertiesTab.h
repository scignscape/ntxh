/********************************************************************************
** Form generated from reading UI file 'PropertiesTab.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROPERTIESTAB_H
#define UI_PROPERTIESTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PropertiesTab
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *_7;
    QLabel *label_169;
    QComboBox *moprop;
    QCheckBox *moprop_save_last_gpx;
    QSpacerItem *spacerItem;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *PropertiesTab)
    {
        if (PropertiesTab->objectName().isEmpty())
            PropertiesTab->setObjectName(QString::fromUtf8("PropertiesTab"));
        PropertiesTab->resize(332, 75);
        verticalLayout = new QVBoxLayout(PropertiesTab);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        _7 = new QHBoxLayout();
        _7->setObjectName(QString::fromUtf8("_7"));
        label_169 = new QLabel(PropertiesTab);
        label_169->setObjectName(QString::fromUtf8("label_169"));

        _7->addWidget(label_169);

        moprop = new QComboBox(PropertiesTab);
        moprop->setObjectName(QString::fromUtf8("moprop"));

        _7->addWidget(moprop);

        moprop_save_last_gpx = new QCheckBox(PropertiesTab);
        moprop_save_last_gpx->setObjectName(QString::fromUtf8("moprop_save_last_gpx"));

        _7->addWidget(moprop_save_last_gpx);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        _7->addItem(spacerItem);


        verticalLayout->addLayout(_7);

        verticalSpacer = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(PropertiesTab);

        QMetaObject::connectSlotsByName(PropertiesTab);
    } // setupUi

    void retranslateUi(QWidget *PropertiesTab)
    {
        PropertiesTab->setWindowTitle(QApplication::translate("PropertiesTab", "Form", nullptr));
        label_169->setText(QApplication::translate("PropertiesTab", "Property", nullptr));
        moprop_save_last_gpx->setText(QApplication::translate("PropertiesTab", "Save G[Px] Data", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PropertiesTab: public Ui_PropertiesTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROPERTIESTAB_H
