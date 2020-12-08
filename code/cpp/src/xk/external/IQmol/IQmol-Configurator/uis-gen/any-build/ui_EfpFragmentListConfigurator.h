/********************************************************************************
** Form generated from reading UI file 'EfpFragmentListConfigurator.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EFPFRAGMENTLISTCONFIGURATOR_H
#define UI_EFPFRAGMENTLISTCONFIGURATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
            EFPFragmentListConfigurator->setObjectName(QStringLiteral("EFPFragmentListConfigurator"));
        EFPFragmentListConfigurator->resize(279, 250);
        EFPFragmentListConfigurator->setSizeGripEnabled(false);
        verticalLayout = new QVBoxLayout(EFPFragmentListConfigurator);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(EFPFragmentListConfigurator);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        ballsAndSticks = new QRadioButton(groupBox);
        ballsAndSticks->setObjectName(QStringLiteral("ballsAndSticks"));
        ballsAndSticks->setChecked(false);

        gridLayout_2->addWidget(ballsAndSticks, 0, 0, 1, 1);

        tubes = new QRadioButton(groupBox);
        tubes->setObjectName(QStringLiteral("tubes"));
        tubes->setChecked(true);

        gridLayout_2->addWidget(tubes, 0, 1, 1, 1);

        spaceFilling = new QRadioButton(groupBox);
        spaceFilling->setObjectName(QStringLiteral("spaceFilling"));

        gridLayout_2->addWidget(spaceFilling, 1, 0, 1, 1);

        wireFrame = new QRadioButton(groupBox);
        wireFrame->setObjectName(QStringLiteral("wireFrame"));

        gridLayout_2->addWidget(wireFrame, 1, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(EFPFragmentListConfigurator);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout->addWidget(label_12, 0, 0, 1, 1);

        atomRadiusScale = new QSlider(groupBox_2);
        atomRadiusScale->setObjectName(QStringLiteral("atomRadiusScale"));
        atomRadiusScale->setMinimum(1);
        atomRadiusScale->setMaximum(20);
        atomRadiusScale->setPageStep(1);
        atomRadiusScale->setValue(10);
        atomRadiusScale->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(atomRadiusScale, 0, 1, 1, 1);

        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout->addWidget(label_13, 1, 0, 1, 1);

        bondRadiusScale = new QSlider(groupBox_2);
        bondRadiusScale->setObjectName(QStringLiteral("bondRadiusScale"));
        bondRadiusScale->setMinimum(1);
        bondRadiusScale->setMaximum(20);
        bondRadiusScale->setPageStep(1);
        bondRadiusScale->setValue(10);
        bondRadiusScale->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(bondRadiusScale, 1, 1, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        resetButton = new QPushButton(EFPFragmentListConfigurator);
        resetButton->setObjectName(QStringLiteral("resetButton"));

        horizontalLayout_2->addWidget(resetButton);

        okButton = new QPushButton(EFPFragmentListConfigurator);
        okButton->setObjectName(QStringLiteral("okButton"));

        horizontalLayout_2->addWidget(okButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(EFPFragmentListConfigurator);
        QObject::connect(okButton, SIGNAL(clicked()), EFPFragmentListConfigurator, SLOT(close()));

        okButton->setDefault(true);


        QMetaObject::connectSlotsByName(EFPFragmentListConfigurator);
    } // setupUi

    void retranslateUi(QDialog *EFPFragmentListConfigurator)
    {
        EFPFragmentListConfigurator->setWindowTitle(QApplication::translate("EfpFragmentListConfigurator", "Configure EFP Fragments", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("EfpFragmentListConfigurator", "Render", Q_NULLPTR));
        ballsAndSticks->setText(QApplication::translate("EfpFragmentListConfigurator", "Balls and Sticks", Q_NULLPTR));
        tubes->setText(QApplication::translate("EfpFragmentListConfigurator", "Tubes", Q_NULLPTR));
        spaceFilling->setText(QApplication::translate("EfpFragmentListConfigurator", "Space Filling", Q_NULLPTR));
        wireFrame->setText(QApplication::translate("EfpFragmentListConfigurator", "Wire Frame", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("EfpFragmentListConfigurator", "Scaling", Q_NULLPTR));
        label_12->setText(QApplication::translate("EfpFragmentListConfigurator", "Atom Radius", Q_NULLPTR));
        label_13->setText(QApplication::translate("EfpFragmentListConfigurator", "Bond Radius", Q_NULLPTR));
        resetButton->setText(QApplication::translate("EfpFragmentListConfigurator", "Reset", Q_NULLPTR));
        okButton->setText(QApplication::translate("EfpFragmentListConfigurator", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EfpFragmentListConfigurator: public Ui_EfpFragmentListConfigurator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EFPFRAGMENTLISTCONFIGURATOR_H
