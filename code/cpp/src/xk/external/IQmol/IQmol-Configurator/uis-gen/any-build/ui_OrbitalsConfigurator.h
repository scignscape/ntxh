/********************************************************************************
** Form generated from reading UI file 'OrbitalsConfigurator.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORBITALSCONFIGURATOR_H
#define UI_ORBITALSCONFIGURATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
            OrbitalsConfigurator->setObjectName(QStringLiteral("OrbitalsConfigurator"));
        OrbitalsConfigurator->resize(724, 318);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(OrbitalsConfigurator->sizePolicy().hasHeightForWidth());
        OrbitalsConfigurator->setSizePolicy(sizePolicy);
        horizontalLayout_5 = new QHBoxLayout(OrbitalsConfigurator);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        cancelButton = new QPushButton(OrbitalsConfigurator);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setAutoDefault(false);

        horizontalLayout_8->addWidget(cancelButton);

        addToQueueButton = new QPushButton(OrbitalsConfigurator);
        addToQueueButton->setObjectName(QStringLiteral("addToQueueButton"));

        horizontalLayout_8->addWidget(addToQueueButton);

        calculateButton = new QPushButton(OrbitalsConfigurator);
        calculateButton->setObjectName(QStringLiteral("calculateButton"));

        horizontalLayout_8->addWidget(calculateButton);

        densityMatrixButton = new QPushButton(OrbitalsConfigurator);
        densityMatrixButton->setObjectName(QStringLiteral("densityMatrixButton"));

        horizontalLayout_8->addWidget(densityMatrixButton);

        horizontalSpacer_6 = new QSpacerItem(1, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);


        gridLayout_2->addLayout(horizontalLayout_8, 7, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 6, 1, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_5 = new QLabel(OrbitalsConfigurator);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_6->addWidget(label_5);

        quality = new QSlider(OrbitalsConfigurator);
        quality->setObjectName(QStringLiteral("quality"));
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
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_6->addWidget(label_6);

        simplifyMeshCheckBox = new QCheckBox(OrbitalsConfigurator);
        simplifyMeshCheckBox->setObjectName(QStringLiteral("simplifyMeshCheckBox"));
        simplifyMeshCheckBox->setChecked(true);

        horizontalLayout_6->addWidget(simplifyMeshCheckBox);


        gridLayout_2->addLayout(horizontalLayout_6, 3, 1, 1, 1);

        label_4 = new QLabel(OrbitalsConfigurator);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        label_12 = new QLabel(OrbitalsConfigurator);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_2->addWidget(label_12, 4, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        orbitalRangeMin = new QComboBox(OrbitalsConfigurator);
        orbitalRangeMin->setObjectName(QStringLiteral("orbitalRangeMin"));
        orbitalRangeMin->setEnabled(false);

        horizontalLayout_2->addWidget(orbitalRangeMin);

        label_10 = new QLabel(OrbitalsConfigurator);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_2->addWidget(label_10);

        orbitalRangeMax = new QComboBox(OrbitalsConfigurator);
        orbitalRangeMax->setObjectName(QStringLiteral("orbitalRangeMax"));
        orbitalRangeMax->setEnabled(false);

        horizontalLayout_2->addWidget(orbitalRangeMax);

        horizontalSpacer_2 = new QSpacerItem(1, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 1, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        opacity = new QSlider(OrbitalsConfigurator);
        opacity->setObjectName(QStringLiteral("opacity"));
        sizePolicy1.setHeightForWidth(opacity->sizePolicy().hasHeightForWidth());
        opacity->setSizePolicy(sizePolicy1);
        opacity->setMinimumSize(QSize(78, 0));
        opacity->setMaximum(100);
        opacity->setValue(50);
        opacity->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(opacity);


        gridLayout_2->addLayout(horizontalLayout_7, 5, 1, 1, 1);

        label = new QLabel(OrbitalsConfigurator);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 5, 0, 1, 1);

        label_7 = new QLabel(OrbitalsConfigurator);
        label_7->setObjectName(QStringLiteral("label_7"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(label_7, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        surfaceType = new QComboBox(OrbitalsConfigurator);
        surfaceType->setObjectName(QStringLiteral("surfaceType"));

        horizontalLayout->addWidget(surfaceType);

        mullikenDecompositionsButton = new QPushButton(OrbitalsConfigurator);
        mullikenDecompositionsButton->setObjectName(QStringLiteral("mullikenDecompositionsButton"));

        horizontalLayout->addWidget(mullikenDecompositionsButton);

        horizontalSpacer = new QSpacerItem(1, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout_2->addLayout(horizontalLayout, 0, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        negativeColorButton = new QToolButton(OrbitalsConfigurator);
        negativeColorButton->setObjectName(QStringLiteral("negativeColorButton"));
        negativeColorButton->setStyleSheet(QLatin1String("QToolButton {\n"
"   background-color: rgb(255, 0, 0);\n"
"}"));
        negativeColorButton->setIconSize(QSize(32, 16));

        horizontalLayout_4->addWidget(negativeColorButton);

        negativeLabel = new QLabel(OrbitalsConfigurator);
        negativeLabel->setObjectName(QStringLiteral("negativeLabel"));

        horizontalLayout_4->addWidget(negativeLabel);

        positiveColorButton = new QToolButton(OrbitalsConfigurator);
        positiveColorButton->setObjectName(QStringLiteral("positiveColorButton"));
        positiveColorButton->setStyleSheet(QLatin1String("QToolButton {\n"
"   background-color: rgb(0, 0, 255);\n"
"}"));
        positiveColorButton->setIconSize(QSize(32, 16));

        horizontalLayout_4->addWidget(positiveColorButton);

        label_9 = new QLabel(OrbitalsConfigurator);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_4->addWidget(label_9);

        horizontalSpacer_10 = new QSpacerItem(1, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);


        gridLayout_2->addLayout(horizontalLayout_4, 4, 1, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        percentageRadio = new QRadioButton(OrbitalsConfigurator);
        percentageRadio->setObjectName(QStringLiteral("percentageRadio"));

        horizontalLayout_9->addWidget(percentageRadio);

        isovalue = new QDoubleSpinBox(OrbitalsConfigurator);
        isovalue->setObjectName(QStringLiteral("isovalue"));
        isovalue->setDecimals(4);
        isovalue->setMinimum(0.0001);
        isovalue->setMaximum(99.9999);
        isovalue->setSingleStep(0.001);
        isovalue->setValue(0.02);

        horizontalLayout_9->addWidget(isovalue);

        atomicUnits = new QCheckBox(OrbitalsConfigurator);
        atomicUnits->setObjectName(QStringLiteral("atomicUnits"));

        horizontalLayout_9->addWidget(atomicUnits);

        horizontalSpacer_4 = new QSpacerItem(1, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_4);


        gridLayout_2->addLayout(horizontalLayout_9, 2, 1, 1, 1);

        orbitalLabel = new QLabel(OrbitalsConfigurator);
        orbitalLabel->setObjectName(QStringLiteral("orbitalLabel"));
        orbitalLabel->setEnabled(true);

        gridLayout_2->addWidget(orbitalLabel, 1, 0, 1, 1);

        isovalueRadio = new QRadioButton(OrbitalsConfigurator);
        isovalueRadio->setObjectName(QStringLiteral("isovalueRadio"));
        isovalueRadio->setChecked(true);

        gridLayout_2->addWidget(isovalueRadio, 2, 0, 1, 1);


        horizontalLayout_5->addLayout(gridLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        energyFrame = new QFrame(OrbitalsConfigurator);
        energyFrame->setObjectName(QStringLiteral("energyFrame"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(energyFrame->sizePolicy().hasHeightForWidth());
        energyFrame->setSizePolicy(sizePolicy3);
        energyFrame->setFrameShape(QFrame::StyledPanel);
        energyFrame->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(energyFrame);

        energyLabel = new QLabel(OrbitalsConfigurator);
        energyLabel->setObjectName(QStringLiteral("energyLabel"));
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
        OrbitalsConfigurator->setWindowTitle(QApplication::translate("OrbitalsConfigurator", "Add Surface", Q_NULLPTR));
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
"", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("OrbitalsConfigurator", "Cancel", Q_NULLPTR));
        addToQueueButton->setText(QApplication::translate("OrbitalsConfigurator", "Add To Queue", Q_NULLPTR));
        calculateButton->setText(QApplication::translate("OrbitalsConfigurator", "Calculate", Q_NULLPTR));
        densityMatrixButton->setText(QApplication::translate("OrbitalsConfigurator", "1st DM", Q_NULLPTR));
        label_5->setText(QApplication::translate("OrbitalsConfigurator", "Low", Q_NULLPTR));
        label_6->setText(QApplication::translate("OrbitalsConfigurator", "High", Q_NULLPTR));
        simplifyMeshCheckBox->setText(QApplication::translate("OrbitalsConfigurator", "Simplify Mesh", Q_NULLPTR));
        label_4->setText(QApplication::translate("OrbitalsConfigurator", "Quality:", Q_NULLPTR));
        label_12->setText(QApplication::translate("OrbitalsConfigurator", "Colors: ", Q_NULLPTR));
        label_10->setText(QApplication::translate("OrbitalsConfigurator", "to", Q_NULLPTR));
        label->setText(QApplication::translate("OrbitalsConfigurator", "Opacity:", Q_NULLPTR));
        label_7->setText(QApplication::translate("OrbitalsConfigurator", "Type:", Q_NULLPTR));
        surfaceType->clear();
        surfaceType->insertItems(0, QStringList()
         << QApplication::translate("OrbitalsConfigurator", "Orbital", Q_NULLPTR)
         << QApplication::translate("OrbitalsConfigurator", "Density", Q_NULLPTR)
         << QApplication::translate("OrbitalsConfigurator", "Spin Density", Q_NULLPTR)
         << QApplication::translate("OrbitalsConfigurator", "Spin-Only Density", Q_NULLPTR)
        );
        mullikenDecompositionsButton->setText(QApplication::translate("OrbitalsConfigurator", "Decompositions", Q_NULLPTR));
        negativeColorButton->setText(QString());
        negativeLabel->setText(QApplication::translate("OrbitalsConfigurator", "Negative", Q_NULLPTR));
        positiveColorButton->setText(QString());
        label_9->setText(QApplication::translate("OrbitalsConfigurator", "Positive", Q_NULLPTR));
        percentageRadio->setText(QApplication::translate("OrbitalsConfigurator", "Percentage", Q_NULLPTR));
        atomicUnits->setText(QApplication::translate("OrbitalsConfigurator", "Atomic Units", Q_NULLPTR));
        orbitalLabel->setText(QApplication::translate("OrbitalsConfigurator", "Orbital(s):", Q_NULLPTR));
        isovalueRadio->setText(QApplication::translate("OrbitalsConfigurator", "Isovalue", Q_NULLPTR));
        energyLabel->setText(QApplication::translate("OrbitalsConfigurator", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class OrbitalsConfigurator: public Ui_OrbitalsConfigurator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORBITALSCONFIGURATOR_H
