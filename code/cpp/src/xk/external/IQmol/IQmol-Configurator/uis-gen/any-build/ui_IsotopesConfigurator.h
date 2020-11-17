/********************************************************************************
** Form generated from reading UI file 'IsotopesConfigurator.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ISOTOPESCONFIGURATOR_H
#define UI_ISOTOPESCONFIGURATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_IsotopesConfigurator
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *temperatureSpinBox;
    QLabel *label_2;
    QDoubleSpinBox *pressureSpinBox;
    QSpacerItem *horizontalSpacer;
    QTableWidget *isotopeTable;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *IsotopesConfigurator)
    {
        if (IsotopesConfigurator->objectName().isEmpty())
            IsotopesConfigurator->setObjectName(QString::fromUtf8("IsotopesConfigurator"));
        IsotopesConfigurator->resize(383, 238);
        verticalLayout = new QVBoxLayout(IsotopesConfigurator);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(IsotopesConfigurator);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        temperatureSpinBox = new QDoubleSpinBox(IsotopesConfigurator);
        temperatureSpinBox->setObjectName(QString::fromUtf8("temperatureSpinBox"));
        temperatureSpinBox->setMaximum(999.990000000000009);
        temperatureSpinBox->setValue(298.180000000000007);

        horizontalLayout->addWidget(temperatureSpinBox);

        label_2 = new QLabel(IsotopesConfigurator);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        pressureSpinBox = new QDoubleSpinBox(IsotopesConfigurator);
        pressureSpinBox->setObjectName(QString::fromUtf8("pressureSpinBox"));
        pressureSpinBox->setSingleStep(0.100000000000000);
        pressureSpinBox->setValue(1.000000000000000);

        horizontalLayout->addWidget(pressureSpinBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        isotopeTable = new QTableWidget(IsotopesConfigurator);
        if (isotopeTable->columnCount() < 3)
            isotopeTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        isotopeTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        isotopeTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        isotopeTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        isotopeTable->setObjectName(QString::fromUtf8("isotopeTable"));

        verticalLayout->addWidget(isotopeTable);

        buttonBox = new QDialogButtonBox(IsotopesConfigurator);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(IsotopesConfigurator);
        QObject::connect(buttonBox, SIGNAL(accepted()), IsotopesConfigurator, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), IsotopesConfigurator, SLOT(reject()));

        QMetaObject::connectSlotsByName(IsotopesConfigurator);
    } // setupUi

    void retranslateUi(QDialog *IsotopesConfigurator)
    {
        IsotopesConfigurator->setWindowTitle(QApplication::translate("IsotopesConfigurator", "Dialog", nullptr));
        label->setText(QApplication::translate("IsotopesConfigurator", "Temperature", nullptr));
        temperatureSpinBox->setSuffix(QApplication::translate("IsotopesConfigurator", " K", nullptr));
        label_2->setText(QApplication::translate("IsotopesConfigurator", "Pressure", nullptr));
        pressureSpinBox->setSuffix(QApplication::translate("IsotopesConfigurator", " atm", nullptr));
        QTableWidgetItem *___qtablewidgetitem = isotopeTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("IsotopesConfigurator", "Element", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = isotopeTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("IsotopesConfigurator", "Isotopic Mass", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = isotopeTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("IsotopesConfigurator", "Atom Indices", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IsotopesConfigurator: public Ui_IsotopesConfigurator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ISOTOPESCONFIGURATOR_H
