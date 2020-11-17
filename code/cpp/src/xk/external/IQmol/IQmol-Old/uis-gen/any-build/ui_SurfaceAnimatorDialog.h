/********************************************************************************
** Form generated from reading UI file 'SurfaceAnimatorDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SURFACEANIMATORDIALOG_H
#define UI_SURFACEANIMATORDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SurfaceAnimatorDialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QListWidget *fileList;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QSpinBox *interpolationFrames;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *reverseButton;
    QToolButton *upButton;
    QToolButton *downButton;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_8;
    QLabel *label;
    QLabel *label_3;
    QSlider *transparencySlider;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *negativeColorButton;
    QLabel *negativeLabel;
    QToolButton *positiveColorButton;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_3;
    QDoubleSpinBox *isovalue;
    QLabel *toLabel;
    QDoubleSpinBox *isovalue2;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QRadioButton *fillButton;
    QRadioButton *linesButton;
    QRadioButton *dotsButton;
    QSpacerItem *horizontalSpacer;
    QCheckBox *simplifyMesh;
    QGroupBox *playbackBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QToolButton *backButton;
    QToolButton *playButton;
    QToolButton *forwardButton;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *loopButton;
    QCheckBox *bounceButton;
    QCheckBox *updateBondsButton;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *speedLabel;
    QSlider *speedSlider;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *cancelButton;
    QPushButton *calculateButton;

    void setupUi(QDialog *SurfaceAnimatorDialog)
    {
        if (SurfaceAnimatorDialog->objectName().isEmpty())
            SurfaceAnimatorDialog->setObjectName(QString::fromUtf8("SurfaceAnimatorDialog"));
        SurfaceAnimatorDialog->resize(407, 646);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SurfaceAnimatorDialog->sizePolicy().hasHeightForWidth());
        SurfaceAnimatorDialog->setSizePolicy(sizePolicy);
        verticalLayout_4 = new QVBoxLayout(SurfaceAnimatorDialog);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBox = new QGroupBox(SurfaceAnimatorDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        fileList = new QListWidget(groupBox);
        fileList->setObjectName(QString::fromUtf8("fileList"));
        fileList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        fileList->setAlternatingRowColors(true);
        fileList->setSelectionMode(QAbstractItemView::SingleSelection);

        verticalLayout_3->addWidget(fileList);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        interpolationFrames = new QSpinBox(groupBox);
        interpolationFrames->setObjectName(QString::fromUtf8("interpolationFrames"));
        interpolationFrames->setMinimum(0);
        interpolationFrames->setMaximum(99);
        interpolationFrames->setValue(10);

        horizontalLayout_2->addWidget(interpolationFrames);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        reverseButton = new QToolButton(groupBox);
        reverseButton->setObjectName(QString::fromUtf8("reverseButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/Up-down.png"), QSize(), QIcon::Normal, QIcon::Off);
        reverseButton->setIcon(icon);
        reverseButton->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(reverseButton);

        upButton = new QToolButton(groupBox);
        upButton->setObjectName(QString::fromUtf8("upButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/icons/Up.png"), QSize(), QIcon::Normal, QIcon::Off);
        upButton->setIcon(icon1);
        upButton->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(upButton);

        downButton = new QToolButton(groupBox);
        downButton->setObjectName(QString::fromUtf8("downButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/icons/Down.png"), QSize(), QIcon::Normal, QIcon::Off);
        downButton->setIcon(icon2);
        downButton->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(downButton);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_4->addWidget(groupBox);

        groupBox_3 = new QGroupBox(SurfaceAnimatorDialog);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 4, 0, 1, 1);

        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 3, 0, 1, 1);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        transparencySlider = new QSlider(groupBox_3);
        transparencySlider->setObjectName(QString::fromUtf8("transparencySlider"));
        transparencySlider->setMaximum(100);
        transparencySlider->setValue(99);
        transparencySlider->setSliderPosition(99);
        transparencySlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(transparencySlider, 4, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        negativeColorButton = new QToolButton(groupBox_3);
        negativeColorButton->setObjectName(QString::fromUtf8("negativeColorButton"));
        negativeColorButton->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"   background-color: rgb(255, 0, 0);\n"
"}"));
        negativeColorButton->setIconSize(QSize(32, 16));

        horizontalLayout_4->addWidget(negativeColorButton);

        negativeLabel = new QLabel(groupBox_3);
        negativeLabel->setObjectName(QString::fromUtf8("negativeLabel"));

        horizontalLayout_4->addWidget(negativeLabel);

        positiveColorButton = new QToolButton(groupBox_3);
        positiveColorButton->setObjectName(QString::fromUtf8("positiveColorButton"));
        positiveColorButton->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"   background-color: rgb(0, 0, 255);\n"
"}"));
        positiveColorButton->setIconSize(QSize(32, 16));

        horizontalLayout_4->addWidget(positiveColorButton);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_4->addWidget(label_9);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);


        gridLayout->addLayout(horizontalLayout_4, 3, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        isovalue = new QDoubleSpinBox(groupBox_3);
        isovalue->setObjectName(QString::fromUtf8("isovalue"));
        isovalue->setDecimals(3);
        isovalue->setMinimum(0.001000000000000);
        isovalue->setMaximum(99.998999999999995);
        isovalue->setSingleStep(0.001000000000000);
        isovalue->setValue(0.020000000000000);

        horizontalLayout_3->addWidget(isovalue);

        toLabel = new QLabel(groupBox_3);
        toLabel->setObjectName(QString::fromUtf8("toLabel"));

        horizontalLayout_3->addWidget(toLabel);

        isovalue2 = new QDoubleSpinBox(groupBox_3);
        isovalue2->setObjectName(QString::fromUtf8("isovalue2"));
        isovalue2->setDecimals(3);
        isovalue2->setMinimum(0.001000000000000);
        isovalue2->setMaximum(99.998999999999995);
        isovalue2->setSingleStep(0.001000000000000);
        isovalue2->setValue(0.020000000000000);

        horizontalLayout_3->addWidget(isovalue2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout_3, 2, 1, 1, 1);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        fillButton = new QRadioButton(groupBox_3);
        fillButton->setObjectName(QString::fromUtf8("fillButton"));
        fillButton->setChecked(true);

        horizontalLayout->addWidget(fillButton);

        linesButton = new QRadioButton(groupBox_3);
        linesButton->setObjectName(QString::fromUtf8("linesButton"));

        horizontalLayout->addWidget(linesButton);

        dotsButton = new QRadioButton(groupBox_3);
        dotsButton->setObjectName(QString::fromUtf8("dotsButton"));

        horizontalLayout->addWidget(dotsButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 0, 1, 1, 1);

        simplifyMesh = new QCheckBox(groupBox_3);
        simplifyMesh->setObjectName(QString::fromUtf8("simplifyMesh"));
        simplifyMesh->setChecked(true);

        gridLayout->addWidget(simplifyMesh, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        verticalLayout_4->addWidget(groupBox_3);

        playbackBox = new QGroupBox(SurfaceAnimatorDialog);
        playbackBox->setObjectName(QString::fromUtf8("playbackBox"));
        verticalLayout = new QVBoxLayout(playbackBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        backButton = new QToolButton(playbackBox);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/icons/GoBack.png"), QSize(), QIcon::Normal, QIcon::Off);
        backButton->setIcon(icon3);
        backButton->setIconSize(QSize(24, 24));

        horizontalLayout_5->addWidget(backButton);

        playButton = new QToolButton(playbackBox);
        playButton->setObjectName(QString::fromUtf8("playButton"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/resources/icons/Play.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon4.addFile(QString::fromUtf8(":/resources/icons/Stop.png"), QSize(), QIcon::Normal, QIcon::On);
        playButton->setIcon(icon4);
        playButton->setIconSize(QSize(24, 24));
        playButton->setCheckable(true);

        horizontalLayout_5->addWidget(playButton);

        forwardButton = new QToolButton(playbackBox);
        forwardButton->setObjectName(QString::fromUtf8("forwardButton"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/resources/icons/GoForward.png"), QSize(), QIcon::Normal, QIcon::Off);
        forwardButton->setIcon(icon5);
        forwardButton->setIconSize(QSize(24, 24));

        horizontalLayout_5->addWidget(forwardButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        loopButton = new QCheckBox(playbackBox);
        loopButton->setObjectName(QString::fromUtf8("loopButton"));
        loopButton->setChecked(false);

        horizontalLayout_6->addWidget(loopButton);

        bounceButton = new QCheckBox(playbackBox);
        bounceButton->setObjectName(QString::fromUtf8("bounceButton"));

        horizontalLayout_6->addWidget(bounceButton);

        updateBondsButton = new QCheckBox(playbackBox);
        updateBondsButton->setObjectName(QString::fromUtf8("updateBondsButton"));

        horizontalLayout_6->addWidget(updateBondsButton);

        horizontalSpacer_6 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        speedLabel = new QLabel(playbackBox);
        speedLabel->setObjectName(QString::fromUtf8("speedLabel"));

        horizontalLayout_7->addWidget(speedLabel);

        speedSlider = new QSlider(playbackBox);
        speedSlider->setObjectName(QString::fromUtf8("speedSlider"));
        speedSlider->setMinimum(1);
        speedSlider->setMaximum(100);
        speedSlider->setValue(25);
        speedSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(speedSlider);


        verticalLayout->addLayout(horizontalLayout_7);


        verticalLayout_4->addWidget(playbackBox);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);

        cancelButton = new QPushButton(SurfaceAnimatorDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setAutoDefault(false);

        horizontalLayout_8->addWidget(cancelButton);

        calculateButton = new QPushButton(SurfaceAnimatorDialog);
        calculateButton->setObjectName(QString::fromUtf8("calculateButton"));

        horizontalLayout_8->addWidget(calculateButton);


        verticalLayout_4->addLayout(horizontalLayout_8);

        QWidget::setTabOrder(calculateButton, fileList);
        QWidget::setTabOrder(fileList, interpolationFrames);
        QWidget::setTabOrder(interpolationFrames, upButton);
        QWidget::setTabOrder(upButton, downButton);
        QWidget::setTabOrder(downButton, fillButton);
        QWidget::setTabOrder(fillButton, linesButton);
        QWidget::setTabOrder(linesButton, dotsButton);
        QWidget::setTabOrder(dotsButton, simplifyMesh);
        QWidget::setTabOrder(simplifyMesh, isovalue);
        QWidget::setTabOrder(isovalue, isovalue2);
        QWidget::setTabOrder(isovalue2, negativeColorButton);
        QWidget::setTabOrder(negativeColorButton, positiveColorButton);
        QWidget::setTabOrder(positiveColorButton, transparencySlider);
        QWidget::setTabOrder(transparencySlider, backButton);
        QWidget::setTabOrder(backButton, playButton);
        QWidget::setTabOrder(playButton, forwardButton);
        QWidget::setTabOrder(forwardButton, loopButton);
        QWidget::setTabOrder(loopButton, bounceButton);
        QWidget::setTabOrder(bounceButton, updateBondsButton);
        QWidget::setTabOrder(updateBondsButton, speedSlider);
        QWidget::setTabOrder(speedSlider, cancelButton);

        retranslateUi(SurfaceAnimatorDialog);
        QObject::connect(cancelButton, SIGNAL(clicked()), SurfaceAnimatorDialog, SLOT(close()));

        calculateButton->setDefault(true);


        QMetaObject::connectSlotsByName(SurfaceAnimatorDialog);
    } // setupUi

    void retranslateUi(QDialog *SurfaceAnimatorDialog)
    {
        SurfaceAnimatorDialog->setWindowTitle(QApplication::translate("SurfaceAnimatorDialog", "Create Animation", nullptr));
        SurfaceAnimatorDialog->setStyleSheet(QApplication::translate("SurfaceAnimatorDialog", "QToolButton {\n"
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
        groupBox->setStyleSheet(QApplication::translate("SurfaceAnimatorDialog", "QToolButton {\n"
"   color: #333;\n"
"   background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, \n"
"          stop: 0 #fff,\n"
"          stop: 0.5 #eee, \n"
"          stop: 1 #999);\n"
"   border-width: 2px;\n"
"   border-color: #333;\n"
"   border-style: solid;\n"
"   border-radius: 5;\n"
"   padding: 0px;\n"
"   font-size: 24px;\n"
"   min-width: 34px;\n"
"   max-width: 34px;\n"
"   min-height: 34px;\n"
"   max-height: 34px;\n"
"}\n"
"\n"
"QToolButton:disabled {\n"
"  background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, \n"
"          stop: 0 #fff,\n"
"          stop: 0.5 #eee, \n"
"          stop: 1 #bbb);\n"
"   border-color: #aaa;\n"
"   color: #aaa;\n"
"}\n"
"\n"
"QToolButton:pressed {\n"
"   background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, \n"
"          stop: 0 #999,\n"
"          stop: 0.5 #eee, \n"
"          stop: 1 #fff);\n"
"}\n"
"\n"
"\n"
"QToolButton:checked {\n"
"   border-color: #b00;\n"
"   background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, \n"
""
                        "          stop: 0 #999,\n"
"          stop: 0.5 #eee, \n"
"          stop: 1 #fff);\n"
"}\n"
"\n"
"QToolTip {\n"
"   border: 2px solid darkkhaki;\n"
"   padding: 2px;\n"
"   border-radius: 3px;\n"
"   opacity: 500;\n"
"   font-size: 12px;\n"
"}", nullptr));
        groupBox->setTitle(QApplication::translate("SurfaceAnimatorDialog", "Cube File Frames", nullptr));
        label_4->setText(QApplication::translate("SurfaceAnimatorDialog", "Interpolation Frames", nullptr));
#ifndef QT_NO_TOOLTIP
        reverseButton->setToolTip(QApplication::translate("SurfaceAnimatorDialog", "Reverse file list order", nullptr));
#endif // QT_NO_TOOLTIP
        reverseButton->setText(QApplication::translate("SurfaceAnimatorDialog", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        upButton->setToolTip(QApplication::translate("SurfaceAnimatorDialog", "Move selection up", nullptr));
#endif // QT_NO_TOOLTIP
        upButton->setText(QApplication::translate("SurfaceAnimatorDialog", "+", nullptr));
#ifndef QT_NO_TOOLTIP
        downButton->setToolTip(QApplication::translate("SurfaceAnimatorDialog", "Move selection down", nullptr));
#endif // QT_NO_TOOLTIP
        downButton->setText(QApplication::translate("SurfaceAnimatorDialog", "-", nullptr));
        groupBox_3->setTitle(QApplication::translate("SurfaceAnimatorDialog", "Surface Render", nullptr));
        label_8->setText(QApplication::translate("SurfaceAnimatorDialog", "Opacity", nullptr));
        label->setText(QApplication::translate("SurfaceAnimatorDialog", "Colors", nullptr));
        label_3->setText(QApplication::translate("SurfaceAnimatorDialog", "Isovalue", nullptr));
        negativeColorButton->setText(QString());
        negativeLabel->setText(QApplication::translate("SurfaceAnimatorDialog", "Negative", nullptr));
        positiveColorButton->setText(QString());
        label_9->setText(QApplication::translate("SurfaceAnimatorDialog", "Positive", nullptr));
        toLabel->setText(QApplication::translate("SurfaceAnimatorDialog", "To", nullptr));
        label_2->setText(QApplication::translate("SurfaceAnimatorDialog", "Render", nullptr));
        fillButton->setText(QApplication::translate("SurfaceAnimatorDialog", "Fill", nullptr));
        linesButton->setText(QApplication::translate("SurfaceAnimatorDialog", "Lines", nullptr));
        dotsButton->setText(QApplication::translate("SurfaceAnimatorDialog", "Dots", nullptr));
#ifndef QT_NO_TOOLTIP
        simplifyMesh->setToolTip(QApplication::translate("SurfaceAnimatorDialog", "Use mesh decimation to reduce the complexity of the surface mesh", nullptr));
#endif // QT_NO_TOOLTIP
        simplifyMesh->setText(QApplication::translate("SurfaceAnimatorDialog", "Simplify Mesh", nullptr));
        playbackBox->setStyleSheet(QApplication::translate("SurfaceAnimatorDialog", "QToolButton {\n"
"   color: #333;\n"
"   background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, \n"
"          stop: 0 #fff,\n"
"          stop: 0.5 #eee, \n"
"          stop: 1 #999);\n"
"   border-width: 2px;\n"
"   border-color: #333;\n"
"   border-style: solid;\n"
"   border-radius: 5;\n"
"   padding: 0px;\n"
"   font-size: 24px;\n"
"   min-width: 34px;\n"
"   max-width: 34px;\n"
"   min-height: 34px;\n"
"   max-height: 34px;\n"
"}\n"
"\n"
"QToolButton:disabled {\n"
"  background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, \n"
"          stop: 0 #fff,\n"
"          stop: 0.5 #eee, \n"
"          stop: 1 #bbb);\n"
"   border-color: #aaa;\n"
"   color: #aaa;\n"
"}\n"
"\n"
"\n"
"QToolButton:pressed {\n"
"   background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, \n"
"          stop: 0 #999,\n"
"          stop: 0.5 #eee, \n"
"          stop: 1 #fff);\n"
"}\n"
"\n"
"\n"
"QToolButton:checked {\n"
"   border-color: #b00;\n"
"}\n"
"\n"
"QToolTip {\n"
"   border: 2px solid darkkhaki;\n"
"   p"
                        "adding: 2px;\n"
"   border-radius: 3px;\n"
"   opacity: 500;\n"
"   font-size: 10px;\n"
"}", nullptr));
        playbackBox->setTitle(QApplication::translate("SurfaceAnimatorDialog", "Playback", nullptr));
#ifndef QT_NO_TOOLTIP
        backButton->setToolTip(QApplication::translate("SurfaceAnimatorDialog", "Show previous conformer", nullptr));
#endif // QT_NO_TOOLTIP
        backButton->setText(QApplication::translate("SurfaceAnimatorDialog", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        playButton->setToolTip(QApplication::translate("SurfaceAnimatorDialog", "Start and stop animation", nullptr));
#endif // QT_NO_TOOLTIP
        playButton->setStyleSheet(QApplication::translate("SurfaceAnimatorDialog", "QToolButton:checked {\n"
"   border-color: #333;\n"
"}", nullptr));
        playButton->setText(QApplication::translate("SurfaceAnimatorDialog", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        forwardButton->setToolTip(QApplication::translate("SurfaceAnimatorDialog", "Show next conformer", nullptr));
#endif // QT_NO_TOOLTIP
        forwardButton->setText(QApplication::translate("SurfaceAnimatorDialog", "...", nullptr));
        loopButton->setText(QApplication::translate("SurfaceAnimatorDialog", "Loop", nullptr));
#ifndef QT_NO_TOOLTIP
        bounceButton->setToolTip(QApplication::translate("SurfaceAnimatorDialog", "Reverses the loop at the end", nullptr));
#endif // QT_NO_TOOLTIP
        bounceButton->setText(QApplication::translate("SurfaceAnimatorDialog", "Bounce", nullptr));
#ifndef QT_NO_TOOLTIP
        updateBondsButton->setToolTip(QApplication::translate("SurfaceAnimatorDialog", "Reperceive bond for each conformer", nullptr));
#endif // QT_NO_TOOLTIP
        updateBondsButton->setText(QApplication::translate("SurfaceAnimatorDialog", "Update Bonds", nullptr));
        speedLabel->setText(QApplication::translate("SurfaceAnimatorDialog", "Speed", nullptr));
#ifndef QT_NO_TOOLTIP
        speedSlider->setToolTip(QApplication::translate("SurfaceAnimatorDialog", "Controls the speed of animation", nullptr));
#endif // QT_NO_TOOLTIP
        cancelButton->setText(QApplication::translate("SurfaceAnimatorDialog", "Cancel", nullptr));
        calculateButton->setText(QApplication::translate("SurfaceAnimatorDialog", "Calculate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SurfaceAnimatorDialog: public Ui_SurfaceAnimatorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SURFACEANIMATORDIALOG_H
