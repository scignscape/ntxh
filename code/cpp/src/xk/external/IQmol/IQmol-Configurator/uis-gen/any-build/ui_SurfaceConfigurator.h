/********************************************************************************
** Form generated from reading UI file 'SurfaceConfigurator.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SURFACECONFIGURATOR_H
#define UI_SURFACECONFIGURATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
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
            SurfaceConfigurator->setObjectName(QStringLiteral("SurfaceConfigurator"));
        SurfaceConfigurator->resize(523, 248);
        SurfaceConfigurator->setStyleSheet(QLatin1String("QToolButton {\n"
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
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_9 = new QLabel(SurfaceConfigurator);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        negativeColorButton = new QToolButton(SurfaceConfigurator);
        negativeColorButton->setObjectName(QStringLiteral("negativeColorButton"));
        negativeColorButton->setStyleSheet(QLatin1String("QToolButton {\n"
"   background-color: rgb(255, 0, 0);\n"
"}"));
        negativeColorButton->setIconSize(QSize(32, 16));

        horizontalLayout_4->addWidget(negativeColorButton);

        negativeLabel = new QLabel(SurfaceConfigurator);
        negativeLabel->setObjectName(QStringLiteral("negativeLabel"));

        horizontalLayout_4->addWidget(negativeLabel);

        minValue = new QDoubleSpinBox(SurfaceConfigurator);
        minValue->setObjectName(QStringLiteral("minValue"));
        minValue->setDecimals(4);
        minValue->setMinimum(-99.99);
        minValue->setSingleStep(0.01);

        horizontalLayout_4->addWidget(minValue);

        positiveColorButton = new QToolButton(SurfaceConfigurator);
        positiveColorButton->setObjectName(QStringLiteral("positiveColorButton"));
        positiveColorButton->setStyleSheet(QLatin1String("QToolButton {\n"
"   background-color: rgb(0, 0, 255);\n"
"}"));
        positiveColorButton->setIconSize(QSize(32, 16));

        horizontalLayout_4->addWidget(positiveColorButton);

        positiveLabel = new QLabel(SurfaceConfigurator);
        positiveLabel->setObjectName(QStringLiteral("positiveLabel"));

        horizontalLayout_4->addWidget(positiveLabel);

        maxValue = new QDoubleSpinBox(SurfaceConfigurator);
        maxValue->setObjectName(QStringLiteral("maxValue"));
        maxValue->setDecimals(4);
        maxValue->setSingleStep(0.01);

        horizontalLayout_4->addWidget(maxValue);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);


        gridLayout->addLayout(horizontalLayout_4, 0, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        propertyCombo = new QComboBox(SurfaceConfigurator);
        propertyCombo->setObjectName(QStringLiteral("propertyCombo"));

        horizontalLayout_3->addWidget(propertyCombo);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        label_3 = new QLabel(SurfaceConfigurator);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        areaLabel = new QLabel(SurfaceConfigurator);
        areaLabel->setObjectName(QStringLiteral("areaLabel"));

        horizontalLayout_3->addWidget(areaLabel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout_3, 2, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        fillButton = new QRadioButton(SurfaceConfigurator);
        fillButton->setObjectName(QStringLiteral("fillButton"));
        fillButton->setChecked(true);

        horizontalLayout->addWidget(fillButton);

        linesButton = new QRadioButton(SurfaceConfigurator);
        linesButton->setObjectName(QStringLiteral("linesButton"));

        horizontalLayout->addWidget(linesButton);

        dotsButton = new QRadioButton(SurfaceConfigurator);
        dotsButton->setObjectName(QStringLiteral("dotsButton"));

        horizontalLayout->addWidget(dotsButton);

        ambientOcclusionCheckBox = new QCheckBox(SurfaceConfigurator);
        ambientOcclusionCheckBox->setObjectName(QStringLiteral("ambientOcclusionCheckBox"));
        ambientOcclusionCheckBox->setEnabled(false);

        horizontalLayout->addWidget(ambientOcclusionCheckBox);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        clipCheckBox = new QCheckBox(SurfaceConfigurator);
        clipCheckBox->setObjectName(QStringLiteral("clipCheckBox"));

        horizontalLayout->addWidget(clipCheckBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 3, 1, 1, 1);

        label_2 = new QLabel(SurfaceConfigurator);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        label_10 = new QLabel(SurfaceConfigurator);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 2, 0, 1, 1);

        label_8 = new QLabel(SurfaceConfigurator);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 4, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        swapColorsButton = new QCheckBox(SurfaceConfigurator);
        swapColorsButton->setObjectName(QStringLiteral("swapColorsButton"));

        horizontalLayout_6->addWidget(swapColorsButton);

        centerButton = new QCheckBox(SurfaceConfigurator);
        centerButton->setObjectName(QStringLiteral("centerButton"));

        horizontalLayout_6->addWidget(centerButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);


        gridLayout->addLayout(horizontalLayout_6, 1, 1, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        transparencySlider = new QSlider(SurfaceConfigurator);
        transparencySlider->setObjectName(QStringLiteral("transparencySlider"));
        transparencySlider->setMaximum(100);
        transparencySlider->setValue(99);
        transparencySlider->setSliderPosition(99);
        transparencySlider->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(transparencySlider);


        gridLayout->addLayout(horizontalLayout_7, 4, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        okButton = new QPushButton(SurfaceConfigurator);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setAutoDefault(false);

        horizontalLayout_2->addWidget(okButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(SurfaceConfigurator);
        QObject::connect(okButton, SIGNAL(clicked()), SurfaceConfigurator, SLOT(close()));

        QMetaObject::connectSlotsByName(SurfaceConfigurator);
    } // setupUi

    void retranslateUi(QDialog *SurfaceConfigurator)
    {
        SurfaceConfigurator->setWindowTitle(QApplication::translate("SurfaceConfigurator", "Configure Surface", Q_NULLPTR));
        label_9->setText(QApplication::translate("SurfaceConfigurator", "Colors:", Q_NULLPTR));
        negativeColorButton->setText(QString());
        negativeLabel->setText(QApplication::translate("SurfaceConfigurator", "Negative", Q_NULLPTR));
        positiveColorButton->setText(QString());
        positiveLabel->setText(QApplication::translate("SurfaceConfigurator", "Positive", Q_NULLPTR));
        propertyCombo->clear();
        propertyCombo->insertItems(0, QStringList()
         << QApplication::translate("SurfaceConfigurator", "None", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("SurfaceConfigurator", "Surface Area:", Q_NULLPTR));
        areaLabel->setText(QApplication::translate("SurfaceConfigurator", "area", Q_NULLPTR));
        fillButton->setText(QApplication::translate("SurfaceConfigurator", "Fill", Q_NULLPTR));
        linesButton->setText(QApplication::translate("SurfaceConfigurator", "Lines", Q_NULLPTR));
        dotsButton->setText(QApplication::translate("SurfaceConfigurator", "Dots", Q_NULLPTR));
        ambientOcclusionCheckBox->setText(QApplication::translate("SurfaceConfigurator", "AO", Q_NULLPTR));
        clipCheckBox->setText(QApplication::translate("SurfaceConfigurator", "Clip", Q_NULLPTR));
        label_2->setText(QApplication::translate("SurfaceConfigurator", "Render", Q_NULLPTR));
        label_10->setText(QApplication::translate("SurfaceConfigurator", "Property", Q_NULLPTR));
        label_8->setText(QApplication::translate("SurfaceConfigurator", "Opacity", Q_NULLPTR));
        swapColorsButton->setText(QApplication::translate("SurfaceConfigurator", "Swap Colors", Q_NULLPTR));
        centerButton->setText(QApplication::translate("SurfaceConfigurator", "Center Gradient", Q_NULLPTR));
        okButton->setText(QApplication::translate("SurfaceConfigurator", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SurfaceConfigurator: public Ui_SurfaceConfigurator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SURFACECONFIGURATOR_H
