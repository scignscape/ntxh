/********************************************************************************
** Form generated from reading UI file 'AxesMeshConfigurator.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AXESMESHCONFIGURATOR_H
#define UI_AXESMESHCONFIGURATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AxesMeshConfigurator
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer;
    QRadioButton *cartesianButton;
    QRadioButton *polarButton;
    QSpacerItem *horizontalSpacer_6;
    QCheckBox *yzCheckBox;
    QCheckBox *xyCheckBox;
    QCheckBox *xzCheckBox;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QRadioButton *totalButton;
    QSpinBox *ticksSpinBox;
    QSpacerItem *horizontalSpacer_12;
    QRadioButton *stepButton;
    QDoubleSpinBox *stepSpinBox;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *okButton;

    void setupUi(QDialog *AxesMeshConfigurator)
    {
        if (AxesMeshConfigurator->objectName().isEmpty())
            AxesMeshConfigurator->setObjectName(QString::fromUtf8("AxesMeshConfigurator"));
        AxesMeshConfigurator->resize(251, 258);
        verticalLayout = new QVBoxLayout(AxesMeshConfigurator);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 3, 1, 1);

        cartesianButton = new QRadioButton(AxesMeshConfigurator);
        cartesianButton->setObjectName(QString::fromUtf8("cartesianButton"));
        cartesianButton->setChecked(true);

        gridLayout_3->addWidget(cartesianButton, 0, 0, 1, 1);

        polarButton = new QRadioButton(AxesMeshConfigurator);
        polarButton->setObjectName(QString::fromUtf8("polarButton"));

        gridLayout_3->addWidget(polarButton, 1, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_6, 0, 1, 1, 1);

        yzCheckBox = new QCheckBox(AxesMeshConfigurator);
        yzCheckBox->setObjectName(QString::fromUtf8("yzCheckBox"));

        gridLayout_3->addWidget(yzCheckBox, 2, 2, 1, 1);

        xyCheckBox = new QCheckBox(AxesMeshConfigurator);
        xyCheckBox->setObjectName(QString::fromUtf8("xyCheckBox"));
        xyCheckBox->setChecked(true);

        gridLayout_3->addWidget(xyCheckBox, 0, 2, 1, 1);

        xzCheckBox = new QCheckBox(AxesMeshConfigurator);
        xzCheckBox->setObjectName(QString::fromUtf8("xzCheckBox"));

        gridLayout_3->addWidget(xzCheckBox, 1, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        groupBox = new QGroupBox(AxesMeshConfigurator);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        totalButton = new QRadioButton(groupBox);
        totalButton->setObjectName(QString::fromUtf8("totalButton"));
        totalButton->setChecked(true);

        gridLayout->addWidget(totalButton, 0, 0, 1, 1);

        ticksSpinBox = new QSpinBox(groupBox);
        ticksSpinBox->setObjectName(QString::fromUtf8("ticksSpinBox"));
        ticksSpinBox->setMaximum(20);
        ticksSpinBox->setValue(10);

        gridLayout->addWidget(ticksSpinBox, 0, 1, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_12, 0, 2, 1, 1);

        stepButton = new QRadioButton(groupBox);
        stepButton->setObjectName(QString::fromUtf8("stepButton"));

        gridLayout->addWidget(stepButton, 1, 0, 1, 1);

        stepSpinBox = new QDoubleSpinBox(groupBox);
        stepSpinBox->setObjectName(QString::fromUtf8("stepSpinBox"));
        stepSpinBox->setEnabled(false);
        stepSpinBox->setDecimals(1);
        stepSpinBox->setMinimum(0.500000000000000);
        stepSpinBox->setMaximum(10.000000000000000);
        stepSpinBox->setSingleStep(0.500000000000000);
        stepSpinBox->setValue(1.000000000000000);

        gridLayout->addWidget(stepSpinBox, 1, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        okButton = new QPushButton(AxesMeshConfigurator);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        horizontalLayout_2->addWidget(okButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(AxesMeshConfigurator);
        QObject::connect(totalButton, SIGNAL(clicked(bool)), stepSpinBox, SLOT(setDisabled(bool)));
        QObject::connect(totalButton, SIGNAL(clicked(bool)), ticksSpinBox, SLOT(setEnabled(bool)));
        QObject::connect(stepButton, SIGNAL(clicked(bool)), ticksSpinBox, SLOT(setDisabled(bool)));
        QObject::connect(stepButton, SIGNAL(clicked(bool)), stepSpinBox, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(AxesMeshConfigurator);
    } // setupUi

    void retranslateUi(QDialog *AxesMeshConfigurator)
    {
        AxesMeshConfigurator->setWindowTitle(QApplication::translate("AxesMeshConfigurator", "Configure Mesh", nullptr));
        cartesianButton->setText(QApplication::translate("AxesMeshConfigurator", "Cartesian", nullptr));
        polarButton->setText(QApplication::translate("AxesMeshConfigurator", "Polar", nullptr));
        yzCheckBox->setText(QApplication::translate("AxesMeshConfigurator", "Y-Z Plane", nullptr));
        xyCheckBox->setText(QApplication::translate("AxesMeshConfigurator", "X-Y Plane", nullptr));
        xzCheckBox->setText(QApplication::translate("AxesMeshConfigurator", "X-Z Plane", nullptr));
        groupBox->setTitle(QApplication::translate("AxesMeshConfigurator", "Ticks", nullptr));
        totalButton->setText(QApplication::translate("AxesMeshConfigurator", "Total", nullptr));
        stepButton->setText(QApplication::translate("AxesMeshConfigurator", "Step", nullptr));
        stepSpinBox->setSuffix(QApplication::translate("AxesMeshConfigurator", " \303\205", nullptr));
        okButton->setText(QApplication::translate("AxesMeshConfigurator", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AxesMeshConfigurator: public Ui_AxesMeshConfigurator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AXESMESHCONFIGURATOR_H
