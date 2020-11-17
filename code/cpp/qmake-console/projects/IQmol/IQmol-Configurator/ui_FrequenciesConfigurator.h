/********************************************************************************
** Form generated from reading UI file 'FrequenciesConfigurator.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FREQUENCIESCONFIGURATOR_H
#define UI_FREQUENCIESCONFIGURATOR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
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
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FrequenciesConfigurator
{
public:
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QTableWidget *frequencyTable;
    QLabel *zpveLabel;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *backButton;
    QToolButton *playButton;
    QToolButton *forwardButton;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_4;
    QToolButton *colorButton;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QSlider *amplitudeSlider;
    QLabel *label_2;
    QSlider *speedSlider;
    QCheckBox *loopButton;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDoubleSpinBox *scaleFactor;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_2;
    QFrame *spectrumFrame;
    QHBoxLayout *horizontalLayout;
    QRadioButton *impulseButton;
    QFrame *line_3;
    QRadioButton *gaussianButton;
    QRadioButton *lorentzianButton;
    QLabel *widthLabel;
    QSlider *widthSlider;
    QFrame *line;
    QCheckBox *ramanCheckbox;
    QPushButton *resetViewButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;

    void setupUi(QDialog *FrequenciesConfigurator)
    {
        if (FrequenciesConfigurator->objectName().isEmpty())
            FrequenciesConfigurator->setObjectName(QString::fromUtf8("FrequenciesConfigurator"));
        FrequenciesConfigurator->resize(1106, 387);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FrequenciesConfigurator->sizePolicy().hasHeightForWidth());
        FrequenciesConfigurator->setSizePolicy(sizePolicy);
        FrequenciesConfigurator->setStyleSheet(QString::fromUtf8("QToolButton {\n"
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
"QToolButton:checked {\n"
"   border-color: #b00;\n"
"}\n"
"\n"
"QToolTip {\n"
"   border: 2px solid darkkhaki;\n"
"   padding: 2p"
                        "x;\n"
"   border-radius: 3px;\n"
"   opacity: 500;\n"
"   font-size: 12px;\n"
"}"));
        horizontalLayout_4 = new QHBoxLayout(FrequenciesConfigurator);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frequencyTable = new QTableWidget(FrequenciesConfigurator);
        if (frequencyTable->columnCount() < 3)
            frequencyTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        frequencyTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        frequencyTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        frequencyTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        frequencyTable->setObjectName(QString::fromUtf8("frequencyTable"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frequencyTable->sizePolicy().hasHeightForWidth());
        frequencyTable->setSizePolicy(sizePolicy1);
        frequencyTable->setMinimumSize(QSize(300, 0));
        frequencyTable->setMaximumSize(QSize(16777215, 16777215));
        frequencyTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        frequencyTable->setSelectionMode(QAbstractItemView::SingleSelection);
        frequencyTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        frequencyTable->horizontalHeader()->setCascadingSectionResizes(true);
        frequencyTable->horizontalHeader()->setDefaultSectionSize(100);
        frequencyTable->horizontalHeader()->setMinimumSectionSize(60);
        frequencyTable->horizontalHeader()->setStretchLastSection(true);
        frequencyTable->verticalHeader()->setCascadingSectionResizes(true);

        verticalLayout->addWidget(frequencyTable);

        zpveLabel = new QLabel(FrequenciesConfigurator);
        zpveLabel->setObjectName(QString::fromUtf8("zpveLabel"));

        verticalLayout->addWidget(zpveLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        backButton = new QToolButton(FrequenciesConfigurator);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/GoBack.png"), QSize(), QIcon::Normal, QIcon::Off);
        backButton->setIcon(icon);
        backButton->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(backButton);

        playButton = new QToolButton(FrequenciesConfigurator);
        playButton->setObjectName(QString::fromUtf8("playButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/icons/Play.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/resources/icons/Stop.png"), QSize(), QIcon::Normal, QIcon::On);
        playButton->setIcon(icon1);
        playButton->setIconSize(QSize(24, 24));
        playButton->setCheckable(true);

        horizontalLayout_2->addWidget(playButton);

        forwardButton = new QToolButton(FrequenciesConfigurator);
        forwardButton->setObjectName(QString::fromUtf8("forwardButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/icons/GoForward.png"), QSize(), QIcon::Normal, QIcon::Off);
        forwardButton->setIcon(icon2);
        forwardButton->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(forwardButton);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_4 = new QLabel(FrequenciesConfigurator);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        colorButton = new QToolButton(FrequenciesConfigurator);
        colorButton->setObjectName(QString::fromUtf8("colorButton"));

        horizontalLayout_2->addWidget(colorButton);


        verticalLayout->addLayout(horizontalLayout_2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(1);
        label = new QLabel(FrequenciesConfigurator);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        amplitudeSlider = new QSlider(FrequenciesConfigurator);
        amplitudeSlider->setObjectName(QString::fromUtf8("amplitudeSlider"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(amplitudeSlider->sizePolicy().hasHeightForWidth());
        amplitudeSlider->setSizePolicy(sizePolicy2);
        amplitudeSlider->setMinimumSize(QSize(220, 0));
        amplitudeSlider->setMinimum(1);
        amplitudeSlider->setMaximum(100);
        amplitudeSlider->setValue(25);
        amplitudeSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(amplitudeSlider, 0, 1, 1, 1);

        label_2 = new QLabel(FrequenciesConfigurator);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        speedSlider = new QSlider(FrequenciesConfigurator);
        speedSlider->setObjectName(QString::fromUtf8("speedSlider"));
        sizePolicy2.setHeightForWidth(speedSlider->sizePolicy().hasHeightForWidth());
        speedSlider->setSizePolicy(sizePolicy2);
        speedSlider->setMinimumSize(QSize(220, 0));
        speedSlider->setMinimum(1);
        speedSlider->setMaximum(100);
        speedSlider->setValue(25);
        speedSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(speedSlider, 1, 1, 1, 1);

        loopButton = new QCheckBox(FrequenciesConfigurator);
        loopButton->setObjectName(QString::fromUtf8("loopButton"));
        sizePolicy2.setHeightForWidth(loopButton->sizePolicy().hasHeightForWidth());
        loopButton->setSizePolicy(sizePolicy2);
        loopButton->setChecked(true);

        gridLayout_2->addWidget(loopButton, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(FrequenciesConfigurator);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        scaleFactor = new QDoubleSpinBox(FrequenciesConfigurator);
        scaleFactor->setObjectName(QString::fromUtf8("scaleFactor"));
        scaleFactor->setDecimals(3);
        scaleFactor->setMinimum(0.800000000000000);
        scaleFactor->setMaximum(1.200000000000000);
        scaleFactor->setSingleStep(0.001000000000000);
        scaleFactor->setValue(1.000000000000000);

        horizontalLayout_3->addWidget(scaleFactor);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        gridLayout_2->addLayout(horizontalLayout_3, 2, 1, 1, 1);

        gridLayout_2->setColumnStretch(1, 1);

        verticalLayout->addLayout(gridLayout_2);


        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        spectrumFrame = new QFrame(FrequenciesConfigurator);
        spectrumFrame->setObjectName(QString::fromUtf8("spectrumFrame"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(spectrumFrame->sizePolicy().hasHeightForWidth());
        spectrumFrame->setSizePolicy(sizePolicy3);
        spectrumFrame->setMinimumSize(QSize(300, 0));
        spectrumFrame->setContextMenuPolicy(Qt::DefaultContextMenu);
        spectrumFrame->setFrameShape(QFrame::StyledPanel);
        spectrumFrame->setFrameShadow(QFrame::Raised);

        verticalLayout_2->addWidget(spectrumFrame);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        impulseButton = new QRadioButton(FrequenciesConfigurator);
        impulseButton->setObjectName(QString::fromUtf8("impulseButton"));
        impulseButton->setChecked(true);

        horizontalLayout->addWidget(impulseButton);

        line_3 = new QFrame(FrequenciesConfigurator);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_3);

        gaussianButton = new QRadioButton(FrequenciesConfigurator);
        gaussianButton->setObjectName(QString::fromUtf8("gaussianButton"));

        horizontalLayout->addWidget(gaussianButton);

        lorentzianButton = new QRadioButton(FrequenciesConfigurator);
        lorentzianButton->setObjectName(QString::fromUtf8("lorentzianButton"));

        horizontalLayout->addWidget(lorentzianButton);

        widthLabel = new QLabel(FrequenciesConfigurator);
        widthLabel->setObjectName(QString::fromUtf8("widthLabel"));

        horizontalLayout->addWidget(widthLabel);

        widthSlider = new QSlider(FrequenciesConfigurator);
        widthSlider->setObjectName(QString::fromUtf8("widthSlider"));
        widthSlider->setMinimum(10);
        widthSlider->setMaximum(110);
        widthSlider->setValue(30);
        widthSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(widthSlider);

        line = new QFrame(FrequenciesConfigurator);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        ramanCheckbox = new QCheckBox(FrequenciesConfigurator);
        ramanCheckbox->setObjectName(QString::fromUtf8("ramanCheckbox"));

        horizontalLayout->addWidget(ramanCheckbox);

        resetViewButton = new QPushButton(FrequenciesConfigurator);
        resetViewButton->setObjectName(QString::fromUtf8("resetViewButton"));

        horizontalLayout->addWidget(resetViewButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closeButton = new QPushButton(FrequenciesConfigurator);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setAutoDefault(false);

        horizontalLayout->addWidget(closeButton);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout_2->setStretch(0, 1);

        horizontalLayout_4->addLayout(verticalLayout_2);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 2);

        retranslateUi(FrequenciesConfigurator);
        QObject::connect(closeButton, SIGNAL(clicked()), FrequenciesConfigurator, SLOT(close()));

        QMetaObject::connectSlotsByName(FrequenciesConfigurator);
    } // setupUi

    void retranslateUi(QDialog *FrequenciesConfigurator)
    {
        FrequenciesConfigurator->setWindowTitle(QApplication::translate("FrequenciesConfigurator", "Vibrational Frequencies", nullptr));
        QTableWidgetItem *___qtablewidgetitem = frequencyTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("FrequenciesConfigurator", "Freq. (cm\342\201\273\302\271)", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = frequencyTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("FrequenciesConfigurator", "Intens. (km/mol)", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = frequencyTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("FrequenciesConfigurator", "Raman (\342\204\2534 amu\342\201\273\302\271)", nullptr));
        zpveLabel->setText(QApplication::translate("FrequenciesConfigurator", "ZPVE:", nullptr));
#ifndef QT_NO_TOOLTIP
        backButton->setToolTip(QApplication::translate("FrequenciesConfigurator", "Move to previous frequency", nullptr));
#endif // QT_NO_TOOLTIP
        backButton->setText(QApplication::translate("FrequenciesConfigurator", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        playButton->setToolTip(QApplication::translate("FrequenciesConfigurator", "Start and stop animation", nullptr));
#endif // QT_NO_TOOLTIP
        playButton->setStyleSheet(QApplication::translate("FrequenciesConfigurator", "QToolButton:checked {\n"
"   border-color: #333;\n"
"}", nullptr));
        playButton->setText(QApplication::translate("FrequenciesConfigurator", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        forwardButton->setToolTip(QApplication::translate("FrequenciesConfigurator", "Move to next frequency", nullptr));
#endif // QT_NO_TOOLTIP
        forwardButton->setText(QApplication::translate("FrequenciesConfigurator", "...", nullptr));
        label_4->setText(QApplication::translate("FrequenciesConfigurator", "Vector Color", nullptr));
#ifndef QT_NO_TOOLTIP
        colorButton->setToolTip(QApplication::translate("FrequenciesConfigurator", "Select the displacement vector color", nullptr));
#endif // QT_NO_TOOLTIP
        colorButton->setText(QString());
        label->setText(QApplication::translate("FrequenciesConfigurator", "Amplitude  ", nullptr));
#ifndef QT_NO_TOOLTIP
        amplitudeSlider->setToolTip(QApplication::translate("FrequenciesConfigurator", "This slider controls the magnitude of both the displacement vectors and animation.", nullptr));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("FrequenciesConfigurator", "Speed", nullptr));
#ifndef QT_NO_TOOLTIP
        speedSlider->setToolTip(QApplication::translate("FrequenciesConfigurator", "Controls the speed of animation", nullptr));
#endif // QT_NO_TOOLTIP
        loopButton->setText(QApplication::translate("FrequenciesConfigurator", "Loop", nullptr));
        label_3->setText(QApplication::translate("FrequenciesConfigurator", "Scale Factor", nullptr));
        impulseButton->setText(QApplication::translate("FrequenciesConfigurator", "Impulse", nullptr));
        gaussianButton->setText(QApplication::translate("FrequenciesConfigurator", "Gaussian", nullptr));
        lorentzianButton->setText(QApplication::translate("FrequenciesConfigurator", "Lorentzian", nullptr));
        widthLabel->setText(QApplication::translate("FrequenciesConfigurator", "Width", nullptr));
        ramanCheckbox->setText(QApplication::translate("FrequenciesConfigurator", "Raman", nullptr));
        resetViewButton->setText(QApplication::translate("FrequenciesConfigurator", "Reset View", nullptr));
        closeButton->setText(QApplication::translate("FrequenciesConfigurator", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrequenciesConfigurator: public Ui_FrequenciesConfigurator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FREQUENCIESCONFIGURATOR_H
