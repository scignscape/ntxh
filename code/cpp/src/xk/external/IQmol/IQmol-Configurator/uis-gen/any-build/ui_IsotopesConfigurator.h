/********************************************************************************
** Form generated from reading UI file 'IsotopesConfigurator.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ISOTOPESCONFIGURATOR_H
#define UI_ISOTOPESCONFIGURATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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
            IsotopesConfigurator->setObjectName(QStringLiteral("IsotopesConfigurator"));
        IsotopesConfigurator->resize(383, 238);
        verticalLayout = new QVBoxLayout(IsotopesConfigurator);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(IsotopesConfigurator);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        temperatureSpinBox = new QDoubleSpinBox(IsotopesConfigurator);
        temperatureSpinBox->setObjectName(QStringLiteral("temperatureSpinBox"));
        temperatureSpinBox->setMaximum(999.99);
        temperatureSpinBox->setValue(298.18);

        horizontalLayout->addWidget(temperatureSpinBox);

        label_2 = new QLabel(IsotopesConfigurator);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        pressureSpinBox = new QDoubleSpinBox(IsotopesConfigurator);
        pressureSpinBox->setObjectName(QStringLiteral("pressureSpinBox"));
        pressureSpinBox->setSingleStep(0.1);
        pressureSpinBox->setValue(1);

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
        isotopeTable->setObjectName(QStringLiteral("isotopeTable"));

        verticalLayout->addWidget(isotopeTable);

        buttonBox = new QDialogButtonBox(IsotopesConfigurator);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
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
        IsotopesConfigurator->setWindowTitle(QApplication::translate("IsotopesConfigurator", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("IsotopesConfigurator", "Temperature", Q_NULLPTR));
        temperatureSpinBox->setSuffix(QApplication::translate("IsotopesConfigurator", " K", Q_NULLPTR));
        label_2->setText(QApplication::translate("IsotopesConfigurator", "Pressure", Q_NULLPTR));
        pressureSpinBox->setSuffix(QApplication::translate("IsotopesConfigurator", " atm", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = isotopeTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("IsotopesConfigurator", "Element", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = isotopeTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("IsotopesConfigurator", "Isotopic Mass", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = isotopeTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("IsotopesConfigurator", "Atom Indices", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class IsotopesConfigurator: public Ui_IsotopesConfigurator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ISOTOPESCONFIGURATOR_H
