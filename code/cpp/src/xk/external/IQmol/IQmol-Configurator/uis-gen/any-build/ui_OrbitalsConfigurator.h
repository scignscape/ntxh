/********************************************************************************
** Form generated from reading UI file 'OrbitalsConfigurator.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORBITALSCONFIGURATOR_H
#define UI_ORBITALSCONFIGURATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_OrbitalsConfigurator
{
public:
    QHBoxLayout *horizontalLayout_5;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *cancelButton;
    QPushButton *addToQueueButton;
    QPushButton *calculateButton;
    QPushButton *densityMatrixButton;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QSlider *quality;
    QLabel *label_6;
    QCheckBox *simplifyMeshCheckBox;
    QLabel *label_4;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *orbitalRangeMin;
    QLabel *label_10;
    QComboBox *orbitalRangeMax;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_7;
    QSlider *opacity;
    QLabel *label;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout;
    QComboBox *surfaceType;
    QPushButton *mullikenDecompositionsButton;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *negativeColorButton;
    QLabel *negativeLabel;
    QToolButton *positiveColorButton;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_9;
    QRadioButton *percentageRadio;
    QDoubleSpinBox *isovalue;
    QCheckBox *atomicUnits;
    QSpacerItem *horizontalSpacer_4;
    QLabel *orbitalLabel;
    QRadioButton *isovalueRadio;
    QVBoxLayout *verticalLayout;
    QFrame *energyFrame;
    QLabel *energyLabel;

    void setupUi(QDialog *OrbitalsConfigurator)
    {
        if (OrbitalsConfigurator->objectName().isEmpty())
            OrbitalsConfigurator->setObjectName(QString::fromUtf8("OrbitalsConfigurator"));
        OrbitalsConfigurator->resize(724, 318);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(OrbitalsConfigurator->sizePolicy().hasHeightForWidth());
        OrbitalsConfigurator->setSizePolicy(sizePolicy);
        horizontalLayout_5 = new QHBoxLayout(OrbitalsConfigurator);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        cancelButton = new QPushButton(OrbitalsConfigurator);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setAutoDefault(false);

        horizontalLayout_8->addWidget(cancelButton);

        addToQueueButton = new QPushButton(OrbitalsConfigurator);
        addToQueueButton->setObjectName(QString::fromUtf8("addToQueueButton"));

        horizontalLayout_8->addWidget(addToQueueButton);

        calculateButton = new QPushButton(OrbitalsConfigurator);
        calculateButton->setObjectName(QString::fromUtf8("calculateButton"));

        horizontalLayout_8->addWidget(calculateButton);

        densityMatrixButton = new QPushButton(OrbitalsConfigurator);
        densityMatrixButton->setObjectName(QString::fromUtf8("densityMatrixButton"));

        horizontalLayout_8->addWidget(densityMatrixButton);

        horizontalSpacer_6 = new QSpacerItem(1, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);


        gridLayout_2->addLayout(horizontalLayout_8, 7, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 6, 1, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(OrbitalsConfigurator);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_6->addWidget(label_5);

        quality = new QSlider(OrbitalsConfigurator);
        quality->setObjectName(QString::fromUtf8("quality"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(quality->sizePolicy().hasHeightForWidth());
        quality->setSizePolicy(sizePolicy1);
        quality->setMinimum(1);
        quality->setMaximum(7);
        quality->setSingleStep(1);
        quality->setPageStep(1);
        quality->setValue(4);
        quality->setOrientation(Qt::Horizontal);
        quality->setTickPosition(QSlider::TicksBelow);
        quality->setTickInterval(1);

        horizontalLayout_6->addWidget(quality);

        label_6 = new QLabel(OrbitalsConfigurator);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        simplifyMeshCheckBox = new QCheckBox(OrbitalsConfigurator);
        simplifyMeshCheckBox->setObjectName(QString::fromUtf8("simplifyMeshCheckBox"));
        simplifyMeshCheckBox->setChecked(true);

        horizontalLayout_6->addWidget(simplifyMeshCheckBox);


        gridLayout_2->addLayout(horizontalLayout_6, 3, 1, 1, 1);

        label_4 = new QLabel(OrbitalsConfigurator);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        label_12 = new QLabel(OrbitalsConfigurator);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_2->addWidget(label_12, 4, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        orbitalRangeMin = new QComboBox(OrbitalsConfigurator);
        orbitalRangeMin->setObjectName(QString::fromUtf8("orbitalRangeMin"));
        orbitalRangeMin->setEnabled(false);

        horizontalLayout_2->addWidget(orbitalRangeMin);

        label_10 = new QLabel(OrbitalsConfigurator);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_2->addWidget(label_10);

        orbitalRangeMax = new QComboBox(OrbitalsConfigurator);
        orbitalRangeMax->setObjectName(QString::fromUtf8("orbitalRangeMax"));
        orbitalRangeMax->setEnabled(false);

        horizontalLayout_2->addWidget(orbitalRangeMax);

        horizontalSpacer_2 = new QSpacerItem(1, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 1, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        opacity = new QSlider(OrbitalsConfigurator);
        opacity->setObjectName(QString::fromUtf8("opacity"));
        sizePolicy1.setHeightForWidth(opacity->sizePolicy().hasHeightForWidth());
        opacity->setSizePolicy(sizePolicy1);
        opacity->setMinimumSize(QSize(78, 0));
        opacity->setMaximum(100);
        opacity->setValue(50);
        opacity->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(opacity);


        gridLayout_2->addLayout(horizontalLayout_7, 5, 1, 1, 1);

        label = new QLabel(OrbitalsConfigurator);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 5, 0, 1, 1);

        label_7 = new QLabel(OrbitalsConfigurator);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(label_7, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        surfaceType = new QComboBox(OrbitalsConfigurator);
        surfaceType->addItem(QString());
        surfaceType->addItem(QString());
        surfaceType->addItem(QString());
        surfaceType->addItem(QString());
        surfaceType->setObjectName(QString::fromUtf8("surfaceType"));

        horizontalLayout->addWidget(surfaceType);

        mullikenDecompositionsButton = new QPushButton(OrbitalsConfigurator);
        mullikenDecompositionsButton->setObjectName(QString::fromUtf8("mullikenDecompositionsButton"));

        horizontalLayout->addWidget(mullikenDecompositionsButton);

        horizontalSpacer = new QSpacerItem(1, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout_2->addLayout(horizontalLayout, 0, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        negativeColorButton = new QToolButton(OrbitalsConfigurator);
        negativeColorButton->setObjectName(QString::fromUtf8("negativeColorButton"));
        negativeColorButton->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"   background-color: rgb(255, 0, 0);\n"
"}"));
        negativeColorButton->setIconSize(QSize(32, 16));

        horizontalLayout_4->addWidget(negativeColorButton);

        negativeLabel = new QLabel(OrbitalsConfigurator);
        negativeLabel->setObjectName(QString::fromUtf8("negativeLabel"));

        horizontalLayout_4->addWidget(negativeLabel);

        positiveColorButton = new QToolButton(OrbitalsConfigurator);
        positiveColorButton->setObjectName(QString::fromUtf8("positiveColorButton"));
        positiveColorButton->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"   background-color: rgb(0, 0, 255);\n"
"}"));
        positiveColorButton->setIconSize(QSize(32, 16));

        horizontalLayout_4->addWidget(positiveColorButton);

        label_9 = new QLabel(OrbitalsConfigurator);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_4->addWidget(label_9);

        horizontalSpacer_10 = new QSpacerItem(1, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);


        gridLayout_2->addLayout(horizontalLayout_4, 4, 1, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        percentageRadio = new QRadioButton(OrbitalsConfigurator);
        percentageRadio->setObjectName(QString::fromUtf8("percentageRadio"));

        horizontalLayout_9->addWidget(percentageRadio);

        isovalue = new QDoubleSpinBox(OrbitalsConfigurator);
        isovalue->setObjectName(QString::fromUtf8("isovalue"));
        isovalue->setDecimals(4);
        isovalue->setMinimum(0.000100000000000);
        isovalue->setMaximum(99.999899999999997);
        isovalue->setSingleStep(0.001000000000000);
        isovalue->setValue(0.020000000000000);

        horizontalLayout_9->addWidget(isovalue);

        atomicUnits = new QCheckBox(OrbitalsConfigurator);
        atomicUnits->setObjectName(QString::fromUtf8("atomicUnits"));

        horizontalLayout_9->addWidget(atomicUnits);

        horizontalSpacer_4 = new QSpacerItem(1, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_4);


        gridLayout_2->addLayout(horizontalLayout_9, 2, 1, 1, 1);

        orbitalLabel = new QLabel(OrbitalsConfigurator);
        orbitalLabel->setObjectName(QString::fromUtf8("orbitalLabel"));
        orbitalLabel->setEnabled(true);

        gridLayout_2->addWidget(orbitalLabel, 1, 0, 1, 1);

        isovalueRadio = new QRadioButton(OrbitalsConfigurator);
        isovalueRadio->setObjectName(QString::fromUtf8("isovalueRadio"));
        isovalueRadio->setChecked(true);

        gridLayout_2->addWidget(isovalueRadio, 2, 0, 1, 1);


        horizontalLayout_5->addLayout(gridLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        energyFrame = new QFrame(OrbitalsConfigurator);
        energyFrame->setObjectName(QString::fromUtf8("energyFrame"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(energyFrame->sizePolicy().hasHeightForWidth());
        energyFrame->setSizePolicy(sizePolicy3);
        energyFrame->setFrameShape(QFrame::StyledPanel);
        energyFrame->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(energyFrame);

        energyLabel = new QLabel(OrbitalsConfigurator);
        energyLabel->setObjectName(QString::fromUtf8("energyLabel"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(energyLabel->sizePolicy().hasHeightForWidth());
        energyLabel->setSizePolicy(sizePolicy4);
        energyLabel->setMinimumSize(QSize(0, 0));

        verticalLayout->addWidget(energyLabel);


        horizontalLayout_5->addLayout(verticalLayout);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 2);

        retranslateUi(OrbitalsConfigurator);

        addToQueueButton->setDefault(false);
        calculateButton->setDefault(true);


        QMetaObject::connectSlotsByName(OrbitalsConfigurator);
    } // setupUi

    void retranslateUi(QDialog *OrbitalsConfigurator)
    {
        OrbitalsConfigurator->setWindowTitle(QApplication::translate("OrbitalsConfigurator", "Add Surface", nullptr));
        OrbitalsConfigurator->setStyleSheet(QApplication::translate("OrbitalsConfigurator", "QToolButton {\n"
"   color: #333;\n"
"   background-color: #666;\n"
"   border-width: 2px;\n"
"   border-color: #CCC;\n"
"   border-style: solid;\n"
"   border-radius: 5;\n"
"   padding: 0px;\n"
"   min-width: 50px;\n"
"   max-width: 50px;\n"
"   min-height: 30px;\n"
"   max-height: 30px;\n"
"}\n"
"\n"
"QToolButton:pressed {\n"
"   border-color: #222;\n"
"}\n"
"", nullptr));
        cancelButton->setText(QApplication::translate("OrbitalsConfigurator", "Cancel", nullptr));
        addToQueueButton->setText(QApplication::translate("OrbitalsConfigurator", "Add To Queue", nullptr));
        calculateButton->setText(QApplication::translate("OrbitalsConfigurator", "Calculate", nullptr));
        densityMatrixButton->setText(QApplication::translate("OrbitalsConfigurator", "1st DM", nullptr));
        label_5->setText(QApplication::translate("OrbitalsConfigurator", "Low", nullptr));
        label_6->setText(QApplication::translate("OrbitalsConfigurator", "High", nullptr));
        simplifyMeshCheckBox->setText(QApplication::translate("OrbitalsConfigurator", "Simplify Mesh", nullptr));
        label_4->setText(QApplication::translate("OrbitalsConfigurator", "Quality:", nullptr));
        label_12->setText(QApplication::translate("OrbitalsConfigurator", "Colors: ", nullptr));
        label_10->setText(QApplication::translate("OrbitalsConfigurator", "to", nullptr));
        label->setText(QApplication::translate("OrbitalsConfigurator", "Opacity:", nullptr));
        label_7->setText(QApplication::translate("OrbitalsConfigurator", "Type:", nullptr));
        surfaceType->setItemText(0, QApplication::translate("OrbitalsConfigurator", "Orbital", nullptr));
        surfaceType->setItemText(1, QApplication::translate("OrbitalsConfigurator", "Density", nullptr));
        surfaceType->setItemText(2, QApplication::translate("OrbitalsConfigurator", "Spin Density", nullptr));
        surfaceType->setItemText(3, QApplication::translate("OrbitalsConfigurator", "Spin-Only Density", nullptr));

        mullikenDecompositionsButton->setText(QApplication::translate("OrbitalsConfigurator", "Decompositions", nullptr));
        negativeColorButton->setText(QString());
        negativeLabel->setText(QApplication::translate("OrbitalsConfigurator", "Negative", nullptr));
        positiveColorButton->setText(QString());
        label_9->setText(QApplication::translate("OrbitalsConfigurator", "Positive", nullptr));
        percentageRadio->setText(QApplication::translate("OrbitalsConfigurator", "Percentage", nullptr));
        atomicUnits->setText(QApplication::translate("OrbitalsConfigurator", "Atomic Units", nullptr));
        orbitalLabel->setText(QApplication::translate("OrbitalsConfigurator", "Orbital(s):", nullptr));
        isovalueRadio->setText(QApplication::translate("OrbitalsConfigurator", "Isovalue", nullptr));
        energyLabel->setText(QApplication::translate("OrbitalsConfigurator", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OrbitalsConfigurator: public Ui_OrbitalsConfigurator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORBITALSCONFIGURATOR_H
