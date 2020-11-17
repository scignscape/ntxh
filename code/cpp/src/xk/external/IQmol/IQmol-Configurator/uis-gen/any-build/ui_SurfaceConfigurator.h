/********************************************************************************
** Form generated from reading UI file 'SurfaceConfigurator.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SURFACECONFIGURATOR_H
#define UI_SURFACECONFIGURATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
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

class Ui_SurfaceConfigurator
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *negativeColorButton;
    QLabel *negativeLabel;
    QDoubleSpinBox *minValue;
    QToolButton *positiveColorButton;
    QLabel *positiveLabel;
    QDoubleSpinBox *maxValue;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *propertyCombo;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_3;
    QLabel *areaLabel;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QRadioButton *fillButton;
    QRadioButton *linesButton;
    QRadioButton *dotsButton;
    QCheckBox *ambientOcclusionCheckBox;
    QSpacerItem *horizontalSpacer_6;
    QCheckBox *clipCheckBox;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QLabel *label_10;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *swapColorsButton;
    QCheckBox *centerButton;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_7;
    QSlider *transparencySlider;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *okButton;

    void setupUi(QDialog *SurfaceConfigurator)
    {
        if (SurfaceConfigurator->objectName().isEmpty())
            SurfaceConfigurator->setObjectName(QString::fromUtf8("SurfaceConfigurator"));
        SurfaceConfigurator->resize(523, 248);
        SurfaceConfigurator->setStyleSheet(QString::fromUtf8("QToolButton {\n"
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
"QToolButton[gradient=\"true\"] {\n"
"   border-width: 1px; \n"
"   border-color: #333;\n"
"   border-style: solid; \n"
"   border-radius: 1; \n"
"   padding: 0px; \n"
"   min-width: 200px;\n"
"   height: 30px;\n"
"}\n"
"\n"
"QToolButton:pressed {\n"
"   border-color: #222;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(SurfaceConfigurator);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_9 = new QLabel(SurfaceConfigurator);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        negativeColorButton = new QToolButton(SurfaceConfigurator);
        negativeColorButton->setObjectName(QString::fromUtf8("negativeColorButton"));
        negativeColorButton->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"   background-color: rgb(255, 0, 0);\n"
"}"));
        negativeColorButton->setIconSize(QSize(32, 16));

        horizontalLayout_4->addWidget(negativeColorButton);

        negativeLabel = new QLabel(SurfaceConfigurator);
        negativeLabel->setObjectName(QString::fromUtf8("negativeLabel"));

        horizontalLayout_4->addWidget(negativeLabel);

        minValue = new QDoubleSpinBox(SurfaceConfigurator);
        minValue->setObjectName(QString::fromUtf8("minValue"));
        minValue->setDecimals(4);
        minValue->setMinimum(-99.989999999999995);
        minValue->setSingleStep(0.010000000000000);

        horizontalLayout_4->addWidget(minValue);

        positiveColorButton = new QToolButton(SurfaceConfigurator);
        positiveColorButton->setObjectName(QString::fromUtf8("positiveColorButton"));
        positiveColorButton->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"   background-color: rgb(0, 0, 255);\n"
"}"));
        positiveColorButton->setIconSize(QSize(32, 16));

        horizontalLayout_4->addWidget(positiveColorButton);

        positiveLabel = new QLabel(SurfaceConfigurator);
        positiveLabel->setObjectName(QString::fromUtf8("positiveLabel"));

        horizontalLayout_4->addWidget(positiveLabel);

        maxValue = new QDoubleSpinBox(SurfaceConfigurator);
        maxValue->setObjectName(QString::fromUtf8("maxValue"));
        maxValue->setDecimals(4);
        maxValue->setSingleStep(0.010000000000000);

        horizontalLayout_4->addWidget(maxValue);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);


        gridLayout->addLayout(horizontalLayout_4, 0, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        propertyCombo = new QComboBox(SurfaceConfigurator);
        propertyCombo->addItem(QString());
        propertyCombo->setObjectName(QString::fromUtf8("propertyCombo"));

        horizontalLayout_3->addWidget(propertyCombo);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        label_3 = new QLabel(SurfaceConfigurator);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        areaLabel = new QLabel(SurfaceConfigurator);
        areaLabel->setObjectName(QString::fromUtf8("areaLabel"));

        horizontalLayout_3->addWidget(areaLabel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout_3, 2, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        fillButton = new QRadioButton(SurfaceConfigurator);
        fillButton->setObjectName(QString::fromUtf8("fillButton"));
        fillButton->setChecked(true);

        horizontalLayout->addWidget(fillButton);

        linesButton = new QRadioButton(SurfaceConfigurator);
        linesButton->setObjectName(QString::fromUtf8("linesButton"));

        horizontalLayout->addWidget(linesButton);

        dotsButton = new QRadioButton(SurfaceConfigurator);
        dotsButton->setObjectName(QString::fromUtf8("dotsButton"));

        horizontalLayout->addWidget(dotsButton);

        ambientOcclusionCheckBox = new QCheckBox(SurfaceConfigurator);
        ambientOcclusionCheckBox->setObjectName(QString::fromUtf8("ambientOcclusionCheckBox"));
        ambientOcclusionCheckBox->setEnabled(false);

        horizontalLayout->addWidget(ambientOcclusionCheckBox);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        clipCheckBox = new QCheckBox(SurfaceConfigurator);
        clipCheckBox->setObjectName(QString::fromUtf8("clipCheckBox"));

        horizontalLayout->addWidget(clipCheckBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 3, 1, 1, 1);

        label_2 = new QLabel(SurfaceConfigurator);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        label_10 = new QLabel(SurfaceConfigurator);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 2, 0, 1, 1);

        label_8 = new QLabel(SurfaceConfigurator);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 4, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        swapColorsButton = new QCheckBox(SurfaceConfigurator);
        swapColorsButton->setObjectName(QString::fromUtf8("swapColorsButton"));

        horizontalLayout_6->addWidget(swapColorsButton);

        centerButton = new QCheckBox(SurfaceConfigurator);
        centerButton->setObjectName(QString::fromUtf8("centerButton"));

        horizontalLayout_6->addWidget(centerButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);


        gridLayout->addLayout(horizontalLayout_6, 1, 1, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        transparencySlider = new QSlider(SurfaceConfigurator);
        transparencySlider->setObjectName(QString::fromUtf8("transparencySlider"));
        transparencySlider->setMaximum(100);
        transparencySlider->setValue(99);
        transparencySlider->setSliderPosition(99);
        transparencySlider->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(transparencySlider);


        gridLayout->addLayout(horizontalLayout_7, 4, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        okButton = new QPushButton(SurfaceConfigurator);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setAutoDefault(false);

        horizontalLayout_2->addWidget(okButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(SurfaceConfigurator);
        QObject::connect(okButton, SIGNAL(clicked()), SurfaceConfigurator, SLOT(close()));

        QMetaObject::connectSlotsByName(SurfaceConfigurator);
    } // setupUi

    void retranslateUi(QDialog *SurfaceConfigurator)
    {
        SurfaceConfigurator->setWindowTitle(QApplication::translate("SurfaceConfigurator", "Configure Surface", nullptr));
        label_9->setText(QApplication::translate("SurfaceConfigurator", "Colors:", nullptr));
        negativeColorButton->setText(QString());
        negativeLabel->setText(QApplication::translate("SurfaceConfigurator", "Negative", nullptr));
        positiveColorButton->setText(QString());
        positiveLabel->setText(QApplication::translate("SurfaceConfigurator", "Positive", nullptr));
        propertyCombo->setItemText(0, QApplication::translate("SurfaceConfigurator", "None", nullptr));

        label_3->setText(QApplication::translate("SurfaceConfigurator", "Surface Area:", nullptr));
        areaLabel->setText(QApplication::translate("SurfaceConfigurator", "area", nullptr));
        fillButton->setText(QApplication::translate("SurfaceConfigurator", "Fill", nullptr));
        linesButton->setText(QApplication::translate("SurfaceConfigurator", "Lines", nullptr));
        dotsButton->setText(QApplication::translate("SurfaceConfigurator", "Dots", nullptr));
        ambientOcclusionCheckBox->setText(QApplication::translate("SurfaceConfigurator", "AO", nullptr));
        clipCheckBox->setText(QApplication::translate("SurfaceConfigurator", "Clip", nullptr));
        label_2->setText(QApplication::translate("SurfaceConfigurator", "Render", nullptr));
        label_10->setText(QApplication::translate("SurfaceConfigurator", "Property", nullptr));
        label_8->setText(QApplication::translate("SurfaceConfigurator", "Opacity", nullptr));
        swapColorsButton->setText(QApplication::translate("SurfaceConfigurator", "Swap Colors", nullptr));
        centerButton->setText(QApplication::translate("SurfaceConfigurator", "Center Gradient", nullptr));
        okButton->setText(QApplication::translate("SurfaceConfigurator", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SurfaceConfigurator: public Ui_SurfaceConfigurator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SURFACECONFIGURATOR_H
