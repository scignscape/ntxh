/********************************************************************************
** Form generated from reading UI file 'MoleculeConfigurator.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOLECULECONFIGURATOR_H
#define UI_MOLECULECONFIGURATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
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

class Ui_MoleculeConfigurator
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QRadioButton *wireFrame;
    QRadioButton *ballsAndSticks;
    QRadioButton *spaceFilling;
    QRadioButton *tubes;
    QRadioButton *plastic;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QSlider *atomRadiusScale;
    QSlider *bondRadiusScale;
    QLabel *label_14;
    QSlider *chargeRadiusScale;
    QLabel *label_13;
    QLabel *label_12;
    QCheckBox *smallerHydrogens;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *resetButton;
    QPushButton *okButton;

    void setupUi(QDialog *MoleculeConfigurator)
    {
        if (MoleculeConfigurator->objectName().isEmpty())
            MoleculeConfigurator->setObjectName(QStringLiteral("MoleculeConfigurator"));
        MoleculeConfigurator->resize(285, 340);
        MoleculeConfigurator->setSizeGripEnabled(false);
        verticalLayout_3 = new QVBoxLayout(MoleculeConfigurator);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox = new QGroupBox(MoleculeConfigurator);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        wireFrame = new QRadioButton(groupBox);
        wireFrame->setObjectName(QStringLiteral("wireFrame"));

        gridLayout_2->addWidget(wireFrame, 1, 1, 1, 1);

        ballsAndSticks = new QRadioButton(groupBox);
        ballsAndSticks->setObjectName(QStringLiteral("ballsAndSticks"));
        ballsAndSticks->setChecked(true);

        gridLayout_2->addWidget(ballsAndSticks, 0, 0, 1, 1);

        spaceFilling = new QRadioButton(groupBox);
        spaceFilling->setObjectName(QStringLiteral("spaceFilling"));

        gridLayout_2->addWidget(spaceFilling, 1, 0, 1, 1);

        tubes = new QRadioButton(groupBox);
        tubes->setObjectName(QStringLiteral("tubes"));

        gridLayout_2->addWidget(tubes, 0, 1, 1, 1);

        plastic = new QRadioButton(groupBox);
        plastic->setObjectName(QStringLiteral("plastic"));

        gridLayout_2->addWidget(plastic, 2, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(MoleculeConfigurator);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        atomRadiusScale = new QSlider(groupBox_2);
        atomRadiusScale->setObjectName(QStringLiteral("atomRadiusScale"));
        atomRadiusScale->setMinimum(1);
        atomRadiusScale->setMaximum(20);
        atomRadiusScale->setPageStep(1);
        atomRadiusScale->setValue(10);
        atomRadiusScale->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(atomRadiusScale, 0, 1, 1, 1);

        bondRadiusScale = new QSlider(groupBox_2);
        bondRadiusScale->setObjectName(QStringLiteral("bondRadiusScale"));
        bondRadiusScale->setMinimum(1);
        bondRadiusScale->setMaximum(20);
        bondRadiusScale->setPageStep(1);
        bondRadiusScale->setValue(10);
        bondRadiusScale->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(bondRadiusScale, 1, 1, 1, 1);

        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout->addWidget(label_14, 2, 0, 1, 1);

        chargeRadiusScale = new QSlider(groupBox_2);
        chargeRadiusScale->setObjectName(QStringLiteral("chargeRadiusScale"));
        chargeRadiusScale->setMinimum(1);
        chargeRadiusScale->setMaximum(20);
        chargeRadiusScale->setPageStep(1);
        chargeRadiusScale->setValue(10);
        chargeRadiusScale->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(chargeRadiusScale, 2, 1, 1, 1);

        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout->addWidget(label_13, 1, 0, 1, 1);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout->addWidget(label_12, 0, 0, 1, 1);

        smallerHydrogens = new QCheckBox(groupBox_2);
        smallerHydrogens->setObjectName(QStringLiteral("smallerHydrogens"));

        gridLayout->addWidget(smallerHydrogens, 3, 0, 1, 2);


        verticalLayout->addLayout(gridLayout);


        verticalLayout_3->addWidget(groupBox_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        resetButton = new QPushButton(MoleculeConfigurator);
        resetButton->setObjectName(QStringLiteral("resetButton"));

        horizontalLayout_2->addWidget(resetButton);

        okButton = new QPushButton(MoleculeConfigurator);
        okButton->setObjectName(QStringLiteral("okButton"));

        horizontalLayout_2->addWidget(okButton);


        verticalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(MoleculeConfigurator);
        QObject::connect(okButton, SIGNAL(clicked()), MoleculeConfigurator, SLOT(close()));

        okButton->setDefault(true);


        QMetaObject::connectSlotsByName(MoleculeConfigurator);
    } // setupUi

    void retranslateUi(QDialog *MoleculeConfigurator)
    {
        MoleculeConfigurator->setWindowTitle(QApplication::translate("MoleculeConfigurator", "Configure Molecule", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MoleculeConfigurator", "Render", Q_NULLPTR));
        wireFrame->setText(QApplication::translate("MoleculeConfigurator", "Wire Frame", Q_NULLPTR));
        ballsAndSticks->setText(QApplication::translate("MoleculeConfigurator", "Balls and Sticks", Q_NULLPTR));
        spaceFilling->setText(QApplication::translate("MoleculeConfigurator", "Space Filling", Q_NULLPTR));
        tubes->setText(QApplication::translate("MoleculeConfigurator", "Tubes", Q_NULLPTR));
        plastic->setText(QApplication::translate("MoleculeConfigurator", "Plastic Model", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MoleculeConfigurator", "Radii", Q_NULLPTR));
        label_14->setText(QApplication::translate("MoleculeConfigurator", "Charges", Q_NULLPTR));
        label_13->setText(QApplication::translate("MoleculeConfigurator", "Bonds", Q_NULLPTR));
        label_12->setText(QApplication::translate("MoleculeConfigurator", "Atoms", Q_NULLPTR));
        smallerHydrogens->setText(QApplication::translate("MoleculeConfigurator", "Smaller Hydrogen Atoms", Q_NULLPTR));
        resetButton->setText(QApplication::translate("MoleculeConfigurator", "Reset", Q_NULLPTR));
        okButton->setText(QApplication::translate("MoleculeConfigurator", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MoleculeConfigurator: public Ui_MoleculeConfigurator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOLECULECONFIGURATOR_H
