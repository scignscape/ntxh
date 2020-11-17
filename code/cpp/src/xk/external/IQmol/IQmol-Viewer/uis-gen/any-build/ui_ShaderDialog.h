/********************************************************************************
** Form generated from reading UI file 'ShaderDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHADERDIALOG_H
#define UI_SHADERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShaderDialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QTabWidget *shaderFilterTabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_10;
    QComboBox *shaderCombo;
    QSpacerItem *horizontalSpacer_4;
    QGridLayout *gridLayout_2;
    QLabel *label0;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QSlider *slider0;
    QSlider *slider1;
    QSlider *slider2;
    QLabel *label4;
    QSlider *slider4;
    QLabel *label5;
    QSlider *slider5;
    QSlider *slider3;
    QGroupBox *optionBox;
    QGridLayout *gridLayout_5;
    QCheckBox *checkBox0;
    QCheckBox *checkBox1;
    QCheckBox *checkBox2;
    QCheckBox *checkBox3;
    QCheckBox *checkBox4;
    QCheckBox *checkBox5;
    QGroupBox *lightBox;
    QGridLayout *gridLayout_4;
    QCheckBox *lightBox0;
    QCheckBox *lightBox1;
    QCheckBox *lightBox2;
    QCheckBox *lightBox3;
    QCheckBox *lightBox5;
    QCheckBox *lightBox4;
    QSpacerItem *verticalSpacer;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *antialias;
    QCheckBox *border;
    QCheckBox *ambientOcclusion;
    QGroupBox *aoOptionsGroupBox;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QSlider *aoRadius;
    QLabel *label_2;
    QSlider *aoStrength;
    QLabel *label_3;
    QSlider *aoTotal;
    QSpacerItem *verticalSpacer_2;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLabel *label_9;
    QComboBox *bondTexture;
    QLabel *label_8;
    QLabel *label_13;
    QComboBox *surfaceTexture;
    QSpacerItem *horizontalSpacer;
    QComboBox *atomTexture;
    QComboBox *background;
    QLabel *label_7;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_7;
    QFrame *atomSampleFrame;
    QFrame *surfaceSampleFrame;
    QGroupBox *lightBox_2;
    QGridLayout *gridLayout_6;
    QCheckBox *povLightFront;
    QCheckBox *povLightHighlight;
    QCheckBox *povLightLeft;
    QCheckBox *povLightLower;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *generatePovRay;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *saveAsDefault;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *okButton;

    void setupUi(QDialog *ShaderDialog)
    {
        if (ShaderDialog->objectName().isEmpty())
            ShaderDialog->setObjectName(QString::fromUtf8("ShaderDialog"));
        ShaderDialog->resize(516, 607);
        ShaderDialog->setStyleSheet(QString::fromUtf8("QToolButton {\n"
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
        verticalLayout_4 = new QVBoxLayout(ShaderDialog);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        shaderFilterTabWidget = new QTabWidget(ShaderDialog);
        shaderFilterTabWidget->setObjectName(QString::fromUtf8("shaderFilterTabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_10 = new QLabel(tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_5->addWidget(label_10);

        shaderCombo = new QComboBox(tab);
        shaderCombo->setObjectName(QString::fromUtf8("shaderCombo"));

        horizontalLayout_5->addWidget(shaderCombo);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_5);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label0 = new QLabel(tab);
        label0->setObjectName(QString::fromUtf8("label0"));

        gridLayout_2->addWidget(label0, 0, 0, 1, 1);

        label1 = new QLabel(tab);
        label1->setObjectName(QString::fromUtf8("label1"));

        gridLayout_2->addWidget(label1, 1, 0, 1, 1);

        label2 = new QLabel(tab);
        label2->setObjectName(QString::fromUtf8("label2"));

        gridLayout_2->addWidget(label2, 2, 0, 1, 1);

        label3 = new QLabel(tab);
        label3->setObjectName(QString::fromUtf8("label3"));

        gridLayout_2->addWidget(label3, 3, 0, 1, 1);

        slider0 = new QSlider(tab);
        slider0->setObjectName(QString::fromUtf8("slider0"));
        slider0->setMaximum(100);
        slider0->setValue(50);
        slider0->setSliderPosition(50);
        slider0->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(slider0, 0, 1, 1, 1);

        slider1 = new QSlider(tab);
        slider1->setObjectName(QString::fromUtf8("slider1"));
        slider1->setMaximum(100);
        slider1->setValue(50);
        slider1->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(slider1, 1, 1, 1, 1);

        slider2 = new QSlider(tab);
        slider2->setObjectName(QString::fromUtf8("slider2"));
        slider2->setMaximum(100);
        slider2->setValue(50);
        slider2->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(slider2, 2, 1, 1, 1);

        label4 = new QLabel(tab);
        label4->setObjectName(QString::fromUtf8("label4"));

        gridLayout_2->addWidget(label4, 4, 0, 1, 1);

        slider4 = new QSlider(tab);
        slider4->setObjectName(QString::fromUtf8("slider4"));
        slider4->setMaximum(100);
        slider4->setValue(50);
        slider4->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(slider4, 4, 1, 1, 1);

        label5 = new QLabel(tab);
        label5->setObjectName(QString::fromUtf8("label5"));

        gridLayout_2->addWidget(label5, 5, 0, 1, 1);

        slider5 = new QSlider(tab);
        slider5->setObjectName(QString::fromUtf8("slider5"));
        slider5->setMaximum(100);
        slider5->setValue(50);
        slider5->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(slider5, 5, 1, 1, 1);

        slider3 = new QSlider(tab);
        slider3->setObjectName(QString::fromUtf8("slider3"));
        slider3->setMaximum(100);
        slider3->setValue(50);
        slider3->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(slider3, 3, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        optionBox = new QGroupBox(tab);
        optionBox->setObjectName(QString::fromUtf8("optionBox"));
        gridLayout_5 = new QGridLayout(optionBox);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        checkBox0 = new QCheckBox(optionBox);
        checkBox0->setObjectName(QString::fromUtf8("checkBox0"));

        gridLayout_5->addWidget(checkBox0, 0, 0, 1, 1);

        checkBox1 = new QCheckBox(optionBox);
        checkBox1->setObjectName(QString::fromUtf8("checkBox1"));

        gridLayout_5->addWidget(checkBox1, 0, 1, 1, 1);

        checkBox2 = new QCheckBox(optionBox);
        checkBox2->setObjectName(QString::fromUtf8("checkBox2"));

        gridLayout_5->addWidget(checkBox2, 1, 0, 1, 1);

        checkBox3 = new QCheckBox(optionBox);
        checkBox3->setObjectName(QString::fromUtf8("checkBox3"));

        gridLayout_5->addWidget(checkBox3, 1, 1, 1, 1);

        checkBox4 = new QCheckBox(optionBox);
        checkBox4->setObjectName(QString::fromUtf8("checkBox4"));

        gridLayout_5->addWidget(checkBox4, 2, 0, 1, 1);

        checkBox5 = new QCheckBox(optionBox);
        checkBox5->setObjectName(QString::fromUtf8("checkBox5"));

        gridLayout_5->addWidget(checkBox5, 2, 1, 1, 1);


        verticalLayout->addWidget(optionBox);

        lightBox = new QGroupBox(tab);
        lightBox->setObjectName(QString::fromUtf8("lightBox"));
        gridLayout_4 = new QGridLayout(lightBox);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        lightBox0 = new QCheckBox(lightBox);
        lightBox0->setObjectName(QString::fromUtf8("lightBox0"));

        gridLayout_4->addWidget(lightBox0, 0, 0, 1, 1);

        lightBox1 = new QCheckBox(lightBox);
        lightBox1->setObjectName(QString::fromUtf8("lightBox1"));

        gridLayout_4->addWidget(lightBox1, 0, 1, 1, 1);

        lightBox2 = new QCheckBox(lightBox);
        lightBox2->setObjectName(QString::fromUtf8("lightBox2"));

        gridLayout_4->addWidget(lightBox2, 0, 2, 1, 1);

        lightBox3 = new QCheckBox(lightBox);
        lightBox3->setObjectName(QString::fromUtf8("lightBox3"));

        gridLayout_4->addWidget(lightBox3, 1, 0, 1, 1);

        lightBox5 = new QCheckBox(lightBox);
        lightBox5->setObjectName(QString::fromUtf8("lightBox5"));

        gridLayout_4->addWidget(lightBox5, 1, 2, 1, 1);

        lightBox4 = new QCheckBox(lightBox);
        lightBox4->setObjectName(QString::fromUtf8("lightBox4"));

        gridLayout_4->addWidget(lightBox4, 1, 1, 1, 1);


        verticalLayout->addWidget(lightBox);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        shaderFilterTabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        antialias = new QCheckBox(tab_2);
        antialias->setObjectName(QString::fromUtf8("antialias"));

        verticalLayout_3->addWidget(antialias);

        border = new QCheckBox(tab_2);
        border->setObjectName(QString::fromUtf8("border"));

        verticalLayout_3->addWidget(border);

        ambientOcclusion = new QCheckBox(tab_2);
        ambientOcclusion->setObjectName(QString::fromUtf8("ambientOcclusion"));

        verticalLayout_3->addWidget(ambientOcclusion);

        aoOptionsGroupBox = new QGroupBox(tab_2);
        aoOptionsGroupBox->setObjectName(QString::fromUtf8("aoOptionsGroupBox"));
        aoOptionsGroupBox->setEnabled(false);
        verticalLayout_2 = new QVBoxLayout(aoOptionsGroupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(aoOptionsGroupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        aoRadius = new QSlider(aoOptionsGroupBox);
        aoRadius->setObjectName(QString::fromUtf8("aoRadius"));
        aoRadius->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(aoRadius, 0, 1, 1, 1);

        label_2 = new QLabel(aoOptionsGroupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        aoStrength = new QSlider(aoOptionsGroupBox);
        aoStrength->setObjectName(QString::fromUtf8("aoStrength"));
        aoStrength->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(aoStrength, 1, 1, 1, 1);

        label_3 = new QLabel(aoOptionsGroupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        aoTotal = new QSlider(aoOptionsGroupBox);
        aoTotal->setObjectName(QString::fromUtf8("aoTotal"));
        aoTotal->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(aoTotal, 2, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        verticalLayout_3->addWidget(aoOptionsGroupBox);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        shaderFilterTabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_5 = new QVBoxLayout(tab_3);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        groupBox_2 = new QGroupBox(tab_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_3->addWidget(label_9, 2, 0, 1, 1);

        bondTexture = new QComboBox(groupBox_2);
        bondTexture->setObjectName(QString::fromUtf8("bondTexture"));

        gridLayout_3->addWidget(bondTexture, 2, 1, 1, 1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 1, 0, 1, 1);

        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_3->addWidget(label_13, 3, 0, 1, 1);

        surfaceTexture = new QComboBox(groupBox_2);
        surfaceTexture->setObjectName(QString::fromUtf8("surfaceTexture"));

        gridLayout_3->addWidget(surfaceTexture, 3, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(52, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 1, 2, 1, 1);

        atomTexture = new QComboBox(groupBox_2);
        atomTexture->setObjectName(QString::fromUtf8("atomTexture"));

        gridLayout_3->addWidget(atomTexture, 1, 1, 1, 1);

        background = new QComboBox(groupBox_2);
        background->addItem(QString());
        background->addItem(QString());
        background->addItem(QString());
        background->addItem(QString());
        background->setObjectName(QString::fromUtf8("background"));

        gridLayout_3->addWidget(background, 0, 1, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_3->addWidget(label_7, 0, 0, 1, 1);


        verticalLayout_5->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(tab_3);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_7 = new QGridLayout(groupBox_3);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        atomSampleFrame = new QFrame(groupBox_3);
        atomSampleFrame->setObjectName(QString::fromUtf8("atomSampleFrame"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(atomSampleFrame->sizePolicy().hasHeightForWidth());
        atomSampleFrame->setSizePolicy(sizePolicy);
        atomSampleFrame->setMinimumSize(QSize(200, 150));
        atomSampleFrame->setFrameShape(QFrame::StyledPanel);
        atomSampleFrame->setFrameShadow(QFrame::Raised);

        gridLayout_7->addWidget(atomSampleFrame, 0, 2, 1, 1);

        surfaceSampleFrame = new QFrame(groupBox_3);
        surfaceSampleFrame->setObjectName(QString::fromUtf8("surfaceSampleFrame"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(surfaceSampleFrame->sizePolicy().hasHeightForWidth());
        surfaceSampleFrame->setSizePolicy(sizePolicy1);
        surfaceSampleFrame->setMinimumSize(QSize(200, 150));
        surfaceSampleFrame->setFrameShape(QFrame::StyledPanel);
        surfaceSampleFrame->setFrameShadow(QFrame::Raised);

        gridLayout_7->addWidget(surfaceSampleFrame, 0, 3, 1, 1);


        verticalLayout_5->addWidget(groupBox_3);

        lightBox_2 = new QGroupBox(tab_3);
        lightBox_2->setObjectName(QString::fromUtf8("lightBox_2"));
        gridLayout_6 = new QGridLayout(lightBox_2);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        povLightFront = new QCheckBox(lightBox_2);
        povLightFront->setObjectName(QString::fromUtf8("povLightFront"));
        povLightFront->setChecked(true);

        gridLayout_6->addWidget(povLightFront, 0, 0, 1, 1);

        povLightHighlight = new QCheckBox(lightBox_2);
        povLightHighlight->setObjectName(QString::fromUtf8("povLightHighlight"));

        gridLayout_6->addWidget(povLightHighlight, 0, 1, 1, 1);

        povLightLeft = new QCheckBox(lightBox_2);
        povLightLeft->setObjectName(QString::fromUtf8("povLightLeft"));
        povLightLeft->setChecked(true);

        gridLayout_6->addWidget(povLightLeft, 0, 2, 1, 1);

        povLightLower = new QCheckBox(lightBox_2);
        povLightLower->setObjectName(QString::fromUtf8("povLightLower"));

        gridLayout_6->addWidget(povLightLower, 1, 0, 1, 1);


        verticalLayout_5->addWidget(lightBox_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        generatePovRay = new QPushButton(tab_3);
        generatePovRay->setObjectName(QString::fromUtf8("generatePovRay"));

        horizontalLayout->addWidget(generatePovRay);


        verticalLayout_5->addLayout(horizontalLayout);

        shaderFilterTabWidget->addTab(tab_3, QString());

        verticalLayout_4->addWidget(shaderFilterTabWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        saveAsDefault = new QPushButton(ShaderDialog);
        saveAsDefault->setObjectName(QString::fromUtf8("saveAsDefault"));

        horizontalLayout_2->addWidget(saveAsDefault);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        okButton = new QPushButton(ShaderDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        horizontalLayout_2->addWidget(okButton);


        verticalLayout_4->addLayout(horizontalLayout_2);

        QWidget::setTabOrder(shaderFilterTabWidget, shaderCombo);
        QWidget::setTabOrder(shaderCombo, slider0);
        QWidget::setTabOrder(slider0, slider1);
        QWidget::setTabOrder(slider1, slider2);
        QWidget::setTabOrder(slider2, slider3);
        QWidget::setTabOrder(slider3, slider4);
        QWidget::setTabOrder(slider4, slider5);
        QWidget::setTabOrder(slider5, checkBox0);
        QWidget::setTabOrder(checkBox0, checkBox1);
        QWidget::setTabOrder(checkBox1, checkBox2);
        QWidget::setTabOrder(checkBox2, checkBox3);
        QWidget::setTabOrder(checkBox3, checkBox4);
        QWidget::setTabOrder(checkBox4, checkBox5);
        QWidget::setTabOrder(checkBox5, lightBox0);
        QWidget::setTabOrder(lightBox0, lightBox1);
        QWidget::setTabOrder(lightBox1, lightBox2);
        QWidget::setTabOrder(lightBox2, lightBox3);
        QWidget::setTabOrder(lightBox3, lightBox4);
        QWidget::setTabOrder(lightBox4, lightBox5);
        QWidget::setTabOrder(lightBox5, saveAsDefault);
        QWidget::setTabOrder(saveAsDefault, okButton);
        QWidget::setTabOrder(okButton, aoRadius);
        QWidget::setTabOrder(aoRadius, aoTotal);
        QWidget::setTabOrder(aoTotal, border);
        QWidget::setTabOrder(border, antialias);
        QWidget::setTabOrder(antialias, ambientOcclusion);
        QWidget::setTabOrder(ambientOcclusion, aoStrength);

        retranslateUi(ShaderDialog);
        QObject::connect(okButton, SIGNAL(clicked()), ShaderDialog, SLOT(close()));

        shaderFilterTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ShaderDialog);
    } // setupUi

    void retranslateUi(QDialog *ShaderDialog)
    {
        ShaderDialog->setWindowTitle(QApplication::translate("ShaderDialog", "Appearance", nullptr));
        label_10->setText(QApplication::translate("ShaderDialog", "Shader", nullptr));
        label0->setText(QApplication::translate("ShaderDialog", "Label0", nullptr));
        label1->setText(QApplication::translate("ShaderDialog", "Label1", nullptr));
        label2->setText(QApplication::translate("ShaderDialog", "Label2", nullptr));
        label3->setText(QApplication::translate("ShaderDialog", "Label3", nullptr));
        label4->setText(QApplication::translate("ShaderDialog", "Label4", nullptr));
        label5->setText(QApplication::translate("ShaderDialog", "Lable6", nullptr));
        optionBox->setTitle(QApplication::translate("ShaderDialog", "Options", nullptr));
        checkBox0->setText(QApplication::translate("ShaderDialog", "checkBox0", nullptr));
        checkBox1->setText(QApplication::translate("ShaderDialog", "checkBox1", nullptr));
        checkBox2->setText(QApplication::translate("ShaderDialog", "checkBox2", nullptr));
        checkBox3->setText(QApplication::translate("ShaderDialog", "checkBox3", nullptr));
        checkBox4->setText(QApplication::translate("ShaderDialog", "checkBox4", nullptr));
        checkBox5->setText(QApplication::translate("ShaderDialog", "checkBox5", nullptr));
        lightBox->setTitle(QApplication::translate("ShaderDialog", "Lights", nullptr));
        lightBox0->setText(QApplication::translate("ShaderDialog", "Backlight", nullptr));
        lightBox1->setText(QApplication::translate("ShaderDialog", "Top", nullptr));
        lightBox2->setText(QApplication::translate("ShaderDialog", "Highlight", nullptr));
        lightBox3->setText(QApplication::translate("ShaderDialog", "Left", nullptr));
        lightBox5->setText(QApplication::translate("ShaderDialog", "Right", nullptr));
        lightBox4->setText(QApplication::translate("ShaderDialog", "Center", nullptr));
        shaderFilterTabWidget->setTabText(shaderFilterTabWidget->indexOf(tab), QApplication::translate("ShaderDialog", "Shader", nullptr));
        antialias->setText(QApplication::translate("ShaderDialog", "Antialias Edges", nullptr));
        border->setText(QApplication::translate("ShaderDialog", "Border", nullptr));
        ambientOcclusion->setText(QApplication::translate("ShaderDialog", "Ambient Occlusion", nullptr));
        aoOptionsGroupBox->setTitle(QApplication::translate("ShaderDialog", "Options", nullptr));
        label->setText(QApplication::translate("ShaderDialog", "Radius", nullptr));
        label_2->setText(QApplication::translate("ShaderDialog", "Strength", nullptr));
        label_3->setText(QApplication::translate("ShaderDialog", "Total", nullptr));
        shaderFilterTabWidget->setTabText(shaderFilterTabWidget->indexOf(tab_2), QApplication::translate("ShaderDialog", "Effects", nullptr));
        groupBox_2->setTitle(QApplication::translate("ShaderDialog", "Textures", nullptr));
        label_9->setText(QApplication::translate("ShaderDialog", "Bond", nullptr));
        label_8->setText(QApplication::translate("ShaderDialog", "Atom", nullptr));
        label_13->setText(QApplication::translate("ShaderDialog", "Surface", nullptr));
        background->setItemText(0, QApplication::translate("ShaderDialog", "None", nullptr));
        background->setItemText(1, QApplication::translate("ShaderDialog", "Default", nullptr));
        background->setItemText(2, QApplication::translate("ShaderDialog", "Black", nullptr));
        background->setItemText(3, QApplication::translate("ShaderDialog", "White", nullptr));

        label_7->setText(QApplication::translate("ShaderDialog", "Background", nullptr));
        groupBox_3->setTitle(QApplication::translate("ShaderDialog", "Sample", nullptr));
        lightBox_2->setTitle(QApplication::translate("ShaderDialog", "Lights", nullptr));
        povLightFront->setText(QApplication::translate("ShaderDialog", "Front", nullptr));
        povLightHighlight->setText(QApplication::translate("ShaderDialog", "Highlight", nullptr));
        povLightLeft->setText(QApplication::translate("ShaderDialog", "Left", nullptr));
        povLightLower->setText(QApplication::translate("ShaderDialog", "Lower", nullptr));
        generatePovRay->setText(QApplication::translate("ShaderDialog", "Generate POV-Ray File", nullptr));
        shaderFilterTabWidget->setTabText(shaderFilterTabWidget->indexOf(tab_3), QApplication::translate("ShaderDialog", "POV-Ray", nullptr));
        saveAsDefault->setText(QApplication::translate("ShaderDialog", "Save As Default", nullptr));
        okButton->setText(QApplication::translate("ShaderDialog", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShaderDialog: public Ui_ShaderDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHADERDIALOG_H
