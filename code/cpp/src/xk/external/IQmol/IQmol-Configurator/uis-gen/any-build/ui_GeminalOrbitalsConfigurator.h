/********************************************************************************
** Form generated from reading UI file 'GeminalOrbitalsConfigurator.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GEMINALORBITALSCONFIGURATOR_H
#define UI_GEMINALORBITALSCONFIGURATOR_H

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
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_GeminalOrbitalsConfigurator
{
public:
    QHBoxLayout *horizontalLayout_5;
    QGridLayout *gridLayout_2;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *negativeColorButton;
    QLabel *negativeLabel;
    QToolButton *positiveColorButton;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout;
    QComboBox *surfaceType;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *orbitalRangeMin;
    QLabel *label_10;
    QComboBox *orbitalRangeMax;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *cancelButton;
    QPushButton *addToQueueButton;
    QPushButton *calculateButton;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_7;
    QSlider *opacity;
    QLabel *label_7;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_3;
    QDoubleSpinBox *isovalue;
    QCheckBox *simplifyMeshCheckBox;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QSlider *quality;
    QLabel *label_6;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_9;
    QComboBox *comboBox;
    QLabel *label_8;
    QComboBox *comboBox_2;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout;
    QFrame *energyFrame;
    QLabel *energyLabel;

    void setupUi(QDialog *GeminalOrbitalsConfigurator)
    {
        if (GeminalOrbitalsConfigurator->objectName().isEmpty())
            GeminalOrbitalsConfigurator->setObjectName(QString::fromUtf8("GeminalOrbitalsConfigurator"));
        GeminalOrbitalsConfigurator->resize(724, 333);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GeminalOrbitalsConfigurator->sizePolicy().hasHeightForWidth());
        GeminalOrbitalsConfigurator->setSizePolicy(sizePolicy);
        horizontalLayout_5 = new QHBoxLayout(GeminalOrbitalsConfigurator);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_11 = new QLabel(GeminalOrbitalsConfigurator);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setEnabled(true);

        gridLayout_2->addWidget(label_11, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        negativeColorButton = new QToolButton(GeminalOrbitalsConfigurator);
        negativeColorButton->setObjectName(QString::fromUtf8("negativeColorButton"));
        negativeColorButton->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"   background-color: rgb(255, 0, 0);\n"
"}"));
        negativeColorButton->setIconSize(QSize(32, 16));

        horizontalLayout_4->addWidget(negativeColorButton);

        negativeLabel = new QLabel(GeminalOrbitalsConfigurator);
        negativeLabel->setObjectName(QString::fromUtf8("negativeLabel"));

        horizontalLayout_4->addWidget(negativeLabel);

        positiveColorButton = new QToolButton(GeminalOrbitalsConfigurator);
        positiveColorButton->setObjectName(QString::fromUtf8("positiveColorButton"));
        positiveColorButton->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"   background-color: rgb(0, 0, 255);\n"
"}"));
        positiveColorButton->setIconSize(QSize(32, 16));

        horizontalLayout_4->addWidget(positiveColorButton);

        label_9 = new QLabel(GeminalOrbitalsConfigurator);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_4->addWidget(label_9);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);


        gridLayout_2->addLayout(horizontalLayout_4, 5, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        surfaceType = new QComboBox(GeminalOrbitalsConfigurator);
        surfaceType->addItem(QString());
        surfaceType->addItem(QString());
        surfaceType->addItem(QString());
        surfaceType->addItem(QString());
        surfaceType->setObjectName(QString::fromUtf8("surfaceType"));

        horizontalLayout->addWidget(surfaceType);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout_2->addLayout(horizontalLayout, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 7, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        orbitalRangeMin = new QComboBox(GeminalOrbitalsConfigurator);
        orbitalRangeMin->setObjectName(QString::fromUtf8("orbitalRangeMin"));
        orbitalRangeMin->setEnabled(true);

        horizontalLayout_2->addWidget(orbitalRangeMin);

        label_10 = new QLabel(GeminalOrbitalsConfigurator);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_2->addWidget(label_10);

        orbitalRangeMax = new QComboBox(GeminalOrbitalsConfigurator);
        orbitalRangeMax->setObjectName(QString::fromUtf8("orbitalRangeMax"));
        orbitalRangeMax->setEnabled(true);

        horizontalLayout_2->addWidget(orbitalRangeMax);

        horizontalSpacer_2 = new QSpacerItem(60, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 1, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        cancelButton = new QPushButton(GeminalOrbitalsConfigurator);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setAutoDefault(false);

        horizontalLayout_8->addWidget(cancelButton);

        addToQueueButton = new QPushButton(GeminalOrbitalsConfigurator);
        addToQueueButton->setObjectName(QString::fromUtf8("addToQueueButton"));

        horizontalLayout_8->addWidget(addToQueueButton);

        calculateButton = new QPushButton(GeminalOrbitalsConfigurator);
        calculateButton->setObjectName(QString::fromUtf8("calculateButton"));

        horizontalLayout_8->addWidget(calculateButton);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);


        gridLayout_2->addLayout(horizontalLayout_8, 8, 0, 1, 2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        opacity = new QSlider(GeminalOrbitalsConfigurator);
        opacity->setObjectName(QString::fromUtf8("opacity"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(opacity->sizePolicy().hasHeightForWidth());
        opacity->setSizePolicy(sizePolicy1);
        opacity->setMinimumSize(QSize(78, 0));
        opacity->setMaximum(100);
        opacity->setValue(50);
        opacity->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(opacity);


        gridLayout_2->addLayout(horizontalLayout_7, 6, 1, 1, 1);

        label_7 = new QLabel(GeminalOrbitalsConfigurator);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(label_7, 0, 0, 1, 1);

        label_3 = new QLabel(GeminalOrbitalsConfigurator);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 3, 0, 1, 1);

        label = new QLabel(GeminalOrbitalsConfigurator);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 6, 0, 1, 1);

        label_4 = new QLabel(GeminalOrbitalsConfigurator);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 4, 0, 1, 1);

        label_12 = new QLabel(GeminalOrbitalsConfigurator);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_2->addWidget(label_12, 5, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        isovalue = new QDoubleSpinBox(GeminalOrbitalsConfigurator);
        isovalue->setObjectName(QString::fromUtf8("isovalue"));
        isovalue->setDecimals(3);
        isovalue->setMinimum(0.001000000000000);
        isovalue->setMaximum(99.998999999999995);
        isovalue->setSingleStep(0.001000000000000);
        isovalue->setValue(0.020000000000000);

        horizontalLayout_3->addWidget(isovalue);

        simplifyMeshCheckBox = new QCheckBox(GeminalOrbitalsConfigurator);
        simplifyMeshCheckBox->setObjectName(QString::fromUtf8("simplifyMeshCheckBox"));
        simplifyMeshCheckBox->setChecked(true);

        horizontalLayout_3->addWidget(simplifyMeshCheckBox);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        gridLayout_2->addLayout(horizontalLayout_3, 3, 1, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(GeminalOrbitalsConfigurator);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_6->addWidget(label_5);

        quality = new QSlider(GeminalOrbitalsConfigurator);
        quality->setObjectName(QString::fromUtf8("quality"));
        sizePolicy1.setHeightForWidth(quality->sizePolicy().hasHeightForWidth());
        quality->setSizePolicy(sizePolicy1);
        quality->setMinimum(1);
        quality->setMaximum(7);
        quality->setSingleStep(1);
        quality->setPageStep(1);
        quality->setValue(3);
        quality->setOrientation(Qt::Horizontal);
        quality->setTickPosition(QSlider::TicksBelow);
        quality->setTickInterval(1);

        horizontalLayout_6->addWidget(quality);

        label_6 = new QLabel(GeminalOrbitalsConfigurator);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);


        gridLayout_2->addLayout(horizontalLayout_6, 4, 1, 1, 1);

        label_2 = new QLabel(GeminalOrbitalsConfigurator);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        comboBox = new QComboBox(GeminalOrbitalsConfigurator);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_9->addWidget(comboBox);

        label_8 = new QLabel(GeminalOrbitalsConfigurator);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_9->addWidget(label_8);

        comboBox_2 = new QComboBox(GeminalOrbitalsConfigurator);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        horizontalLayout_9->addWidget(comboBox_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);


        gridLayout_2->addLayout(horizontalLayout_9, 2, 1, 1, 1);


        horizontalLayout_5->addLayout(gridLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        energyFrame = new QFrame(GeminalOrbitalsConfigurator);
        energyFrame->setObjectName(QString::fromUtf8("energyFrame"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(energyFrame->sizePolicy().hasHeightForWidth());
        energyFrame->setSizePolicy(sizePolicy3);
        energyFrame->setFrameShape(QFrame::StyledPanel);
        energyFrame->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(energyFrame);

        energyLabel = new QLabel(GeminalOrbitalsConfigurator);
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

        retranslateUi(GeminalOrbitalsConfigurator);

        addToQueueButton->setDefault(false);
        calculateButton->setDefault(true);


        QMetaObject::connectSlotsByName(GeminalOrbitalsConfigurator);
    } // setupUi

    void retranslateUi(QDialog *GeminalOrbitalsConfigurator)
    {
        GeminalOrbitalsConfigurator->setWindowTitle(QApplication::translate("GeminalOrbitalsConfigurator", "Add Surface", nullptr));
        GeminalOrbitalsConfigurator->setStyleSheet(QApplication::translate("GeminalOrbitalsConfigurator", "QToolButton {\n"
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
        label_11->setText(QApplication::translate("GeminalOrbitalsConfigurator", "Geminal(s):", nullptr));
        negativeColorButton->setText(QString());
        negativeLabel->setText(QApplication::translate("GeminalOrbitalsConfigurator", "Negative", nullptr));
        positiveColorButton->setText(QString());
        label_9->setText(QApplication::translate("GeminalOrbitalsConfigurator", "Positive", nullptr));
        surfaceType->setItemText(0, QApplication::translate("GeminalOrbitalsConfigurator", "Orbital", nullptr));
        surfaceType->setItemText(1, QApplication::translate("GeminalOrbitalsConfigurator", "Density", nullptr));
        surfaceType->setItemText(2, QApplication::translate("GeminalOrbitalsConfigurator", "Spin Density", nullptr));
        surfaceType->setItemText(3, QApplication::translate("GeminalOrbitalsConfigurator", "Spin-Only Density", nullptr));

        label_10->setText(QApplication::translate("GeminalOrbitalsConfigurator", "to", nullptr));
        cancelButton->setText(QApplication::translate("GeminalOrbitalsConfigurator", "Cancel", nullptr));
        addToQueueButton->setText(QApplication::translate("GeminalOrbitalsConfigurator", "Add To Queue", nullptr));
        calculateButton->setText(QApplication::translate("GeminalOrbitalsConfigurator", "Calculate", nullptr));
        label_7->setText(QApplication::translate("GeminalOrbitalsConfigurator", "Type:", nullptr));
        label_3->setText(QApplication::translate("GeminalOrbitalsConfigurator", "Isovalue:", nullptr));
        label->setText(QApplication::translate("GeminalOrbitalsConfigurator", "Opacity:", nullptr));
        label_4->setText(QApplication::translate("GeminalOrbitalsConfigurator", "Quality:", nullptr));
        label_12->setText(QApplication::translate("GeminalOrbitalsConfigurator", "Colors: ", nullptr));
        simplifyMeshCheckBox->setText(QApplication::translate("GeminalOrbitalsConfigurator", "Simplify Mesh", nullptr));
        label_5->setText(QApplication::translate("GeminalOrbitalsConfigurator", "Low", nullptr));
        label_6->setText(QApplication::translate("GeminalOrbitalsConfigurator", "High", nullptr));
        label_2->setText(QApplication::translate("GeminalOrbitalsConfigurator", "Orbitals", nullptr));
        label_8->setText(QApplication::translate("GeminalOrbitalsConfigurator", "to", nullptr));
        energyLabel->setText(QApplication::translate("GeminalOrbitalsConfigurator", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GeminalOrbitalsConfigurator: public Ui_GeminalOrbitalsConfigurator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GEMINALORBITALSCONFIGURATOR_H
