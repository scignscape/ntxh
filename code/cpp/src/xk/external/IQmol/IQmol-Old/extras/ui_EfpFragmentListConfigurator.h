/********************************************************************************
** Form generated from reading UI file 'EfpFragmentListConfigurator.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EFPFRAGMENTLISTCONFIGURATOR_H
#define UI_EFPFRAGMENTLISTCONFIGURATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EfpFragmentListConfigurator
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QRadioButton *ballsAndSticks;
    QRadioButton *tubes;
    QRadioButton *spaceFilling;
    QRadioButton *wireFrame;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *label_12;
    QSlider *atomRadiusScale;
    QLabel *label_13;
    QSlider *bondRadiusScale;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *resetButton;
    QPushButton *okButton;

    void setupUi(QDialog *EFPFragmentListConfigurator)
    {
        if (EFPFragmentListConfigurator->objectName().isEmpty())
            EFPFragmentListConfigurator->setObjectName(QString::fromUtf8("EFPFragmentListConfigurator"));
        EFPFragmentListConfigurator->resize(279, 250);
        EFPFragmentListConfigurator->setSizeGripEnabled(false);
        verticalLayout = new QVBoxLayout(EFPFragmentListConfigurator);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(EFPFragmentListConfigurator);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        ballsAndSticks = new QRadioButton(groupBox);
        ballsAndSticks->setObjectName(QString::fromUtf8("ballsAndSticks"));
        ballsAndSticks->setChecked(false);

        gridLayout_2->addWidget(ballsAndSticks, 0, 0, 1, 1);

        tubes = new QRadioButton(groupBox);
        tubes->setObjectName(QString::fromUtf8("tubes"));
        tubes->setChecked(true);

        gridLayout_2->addWidget(tubes, 0, 1, 1, 1);

        spaceFilling = new QRadioButton(groupBox);
        spaceFilling->setObjectName(QString::fromUtf8("spaceFilling"));

        gridLayout_2->addWidget(spaceFilling, 1, 0, 1, 1);

        wireFrame = new QRadioButton(groupBox);
        wireFrame->setObjectName(QString::fromUtf8("wireFrame"));

        gridLayout_2->addWidget(wireFrame, 1, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(EFPFragmentListConfigurator);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 0, 0, 1, 1);

        atomRadiusScale = new QSlider(groupBox_2);
        atomRadiusScale->setObjectName(QString::fromUtf8("atomRadiusScale"));
        atomRadiusScale->setMinimum(1);
        atomRadiusScale->setMaximum(20);
        atomRadiusScale->setPageStep(1);
        atomRadiusScale->setValue(10);
        atomRadiusScale->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(atomRadiusScale, 0, 1, 1, 1);

        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout->addWidget(label_13, 1, 0, 1, 1);

        bondRadiusScale = new QSlider(groupBox_2);
        bondRadiusScale->setObjectName(QString::fromUtf8("bondRadiusScale"));
        bondRadiusScale->setMinimum(1);
        bondRadiusScale->setMaximum(20);
        bondRadiusScale->setPageStep(1);
        bondRadiusScale->setValue(10);
        bondRadiusScale->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(bondRadiusScale, 1, 1, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        resetButton = new QPushButton(EFPFragmentListConfigurator);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));

        horizontalLayout_2->addWidget(resetButton);

        okButton = new QPushButton(EFPFragmentListConfigurator);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        horizontalLayout_2->addWidget(okButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(EFPFragmentListConfigurator);
        QObject::connect(okButton, SIGNAL(clicked()), EFPFragmentListConfigurator, SLOT(close()));

        okButton->setDefault(true);


        QMetaObject::connectSlotsByName(EFPFragmentListConfigurator);
    } // setupUi

    void retranslateUi(QDialog *EFPFragmentListConfigurator)
    {
        EFPFragmentListConfigurator->setWindowTitle(QApplication::translate("EfpFragmentListConfigurator", "Configure EFP Fragments", nullptr));
        groupBox->setTitle(QApplication::translate("EfpFragmentListConfigurator", "Render", nullptr));
        ballsAndSticks->setText(QApplication::translate("EfpFragmentListConfigurator", "Balls and Sticks", nullptr));
        tubes->setText(QApplication::translate("EfpFragmentListConfigurator", "Tubes", nullptr));
        spaceFilling->setText(QApplication::translate("EfpFragmentListConfigurator", "Space Filling", nullptr));
        wireFrame->setText(QApplication::translate("EfpFragmentListConfigurator", "Wire Frame", nullptr));
        groupBox_2->setTitle(QApplication::translate("EfpFragmentListConfigurator", "Scaling", nullptr));
        label_12->setText(QApplication::translate("EfpFragmentListConfigurator", "Atom Radius", nullptr));
        label_13->setText(QApplication::translate("EfpFragmentListConfigurator", "Bond Radius", nullptr));
        resetButton->setText(QApplication::translate("EfpFragmentListConfigurator", "Reset", nullptr));
        okButton->setText(QApplication::translate("EfpFragmentListConfigurator", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EfpFragmentListConfigurator: public Ui_EfpFragmentListConfigurator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EFPFRAGMENTLISTCONFIGURATOR_H
