/********************************************************************************
** Form generated from reading UI file 'GeometryListConfigurator.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GEOMETRYLISTCONFIGURATOR_H
#define UI_GEOMETRYLISTCONFIGURATOR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_GeometryListConfigurator
{
public:
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *energyTable;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *backButton;
    QToolButton *playButton;
    QToolButton *forwardButton;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *loopButton;
    QCheckBox *bounceButton;
    QCheckBox *updateBondsButton;
    QHBoxLayout *horizontalLayout_4;
    QLabel *speedLabel;
    QSlider *speedSlider;
    QVBoxLayout *verticalLayout;
    QFrame *plotFrame;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *resetViewButton;
    QPushButton *closeButton;

    void setupUi(QDialog *GeometryListConfigurator)
    {
        if (GeometryListConfigurator->objectName().isEmpty())
            GeometryListConfigurator->setObjectName(QString::fromUtf8("GeometryListConfigurator"));
        GeometryListConfigurator->resize(862, 441);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GeometryListConfigurator->sizePolicy().hasHeightForWidth());
        GeometryListConfigurator->setSizePolicy(sizePolicy);
        GeometryListConfigurator->setStyleSheet(QString::fromUtf8("QToolButton {\n"
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
"   font-size: 12px;\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(GeometryListConfigurator);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        energyTable = new QTableWidget(GeometryListConfigurator);
        if (energyTable->columnCount() < 1)
            energyTable->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        energyTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        energyTable->setObjectName(QString::fromUtf8("energyTable"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(energyTable->sizePolicy().hasHeightForWidth());
        energyTable->setSizePolicy(sizePolicy1);
        energyTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        energyTable->setSelectionMode(QAbstractItemView::SingleSelection);
        energyTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        energyTable->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_2->addWidget(energyTable);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        backButton = new QToolButton(GeometryListConfigurator);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/GoBack.png"), QSize(), QIcon::Normal, QIcon::Off);
        backButton->setIcon(icon);
        backButton->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(backButton);

        playButton = new QToolButton(GeometryListConfigurator);
        playButton->setObjectName(QString::fromUtf8("playButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/icons/Play.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/resources/icons/Stop.png"), QSize(), QIcon::Normal, QIcon::On);
        playButton->setIcon(icon1);
        playButton->setIconSize(QSize(24, 24));
        playButton->setCheckable(true);

        horizontalLayout_2->addWidget(playButton);

        forwardButton = new QToolButton(GeometryListConfigurator);
        forwardButton->setObjectName(QString::fromUtf8("forwardButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/icons/GoForward.png"), QSize(), QIcon::Normal, QIcon::Off);
        forwardButton->setIcon(icon2);
        forwardButton->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(forwardButton);

        horizontalSpacer_2 = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        loopButton = new QCheckBox(GeometryListConfigurator);
        loopButton->setObjectName(QString::fromUtf8("loopButton"));
        loopButton->setChecked(false);

        horizontalLayout_5->addWidget(loopButton);

        bounceButton = new QCheckBox(GeometryListConfigurator);
        bounceButton->setObjectName(QString::fromUtf8("bounceButton"));

        horizontalLayout_5->addWidget(bounceButton);

        updateBondsButton = new QCheckBox(GeometryListConfigurator);
        updateBondsButton->setObjectName(QString::fromUtf8("updateBondsButton"));

        horizontalLayout_5->addWidget(updateBondsButton);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        speedLabel = new QLabel(GeometryListConfigurator);
        speedLabel->setObjectName(QString::fromUtf8("speedLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(speedLabel->sizePolicy().hasHeightForWidth());
        speedLabel->setSizePolicy(sizePolicy2);

        horizontalLayout_4->addWidget(speedLabel);

        speedSlider = new QSlider(GeometryListConfigurator);
        speedSlider->setObjectName(QString::fromUtf8("speedSlider"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(speedSlider->sizePolicy().hasHeightForWidth());
        speedSlider->setSizePolicy(sizePolicy3);
        speedSlider->setMinimumSize(QSize(200, 0));
        speedSlider->setMinimum(1);
        speedSlider->setMaximum(100);
        speedSlider->setValue(25);
        speedSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(speedSlider);


        verticalLayout_2->addLayout(horizontalLayout_4);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        plotFrame = new QFrame(GeometryListConfigurator);
        plotFrame->setObjectName(QString::fromUtf8("plotFrame"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(plotFrame->sizePolicy().hasHeightForWidth());
        plotFrame->setSizePolicy(sizePolicy4);
        plotFrame->setContextMenuPolicy(Qt::DefaultContextMenu);
        plotFrame->setFrameShape(QFrame::StyledPanel);
        plotFrame->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(plotFrame);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        resetViewButton = new QPushButton(GeometryListConfigurator);
        resetViewButton->setObjectName(QString::fromUtf8("resetViewButton"));

        horizontalLayout->addWidget(resetViewButton);

        closeButton = new QPushButton(GeometryListConfigurator);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setAutoDefault(false);

        horizontalLayout->addWidget(closeButton);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(verticalLayout);


        retranslateUi(GeometryListConfigurator);
        QObject::connect(closeButton, SIGNAL(clicked()), GeometryListConfigurator, SLOT(close()));

        QMetaObject::connectSlotsByName(GeometryListConfigurator);
    } // setupUi

    void retranslateUi(QDialog *GeometryListConfigurator)
    {
        GeometryListConfigurator->setWindowTitle(QApplication::translate("GeometryListConfigurator", "Geometries", nullptr));
        QTableWidgetItem *___qtablewidgetitem = energyTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("GeometryListConfigurator", "Energy", nullptr));
#ifndef QT_NO_TOOLTIP
        backButton->setToolTip(QApplication::translate("GeometryListConfigurator", "Show previous conformer", nullptr));
#endif // QT_NO_TOOLTIP
        backButton->setText(QApplication::translate("GeometryListConfigurator", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        playButton->setToolTip(QApplication::translate("GeometryListConfigurator", "Start and stop animation", nullptr));
#endif // QT_NO_TOOLTIP
        playButton->setStyleSheet(QApplication::translate("GeometryListConfigurator", "QToolButton:checked {\n"
"   border-color: #333;\n"
"}", nullptr));
        playButton->setText(QApplication::translate("GeometryListConfigurator", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        forwardButton->setToolTip(QApplication::translate("GeometryListConfigurator", "Show next conformer", nullptr));
#endif // QT_NO_TOOLTIP
        forwardButton->setText(QApplication::translate("GeometryListConfigurator", "...", nullptr));
        loopButton->setText(QApplication::translate("GeometryListConfigurator", "Loop", nullptr));
#ifndef QT_NO_TOOLTIP
        bounceButton->setToolTip(QApplication::translate("GeometryListConfigurator", "Reverses the loop at the end", nullptr));
#endif // QT_NO_TOOLTIP
        bounceButton->setText(QApplication::translate("GeometryListConfigurator", "Bounce", nullptr));
#ifndef QT_NO_TOOLTIP
        updateBondsButton->setToolTip(QApplication::translate("GeometryListConfigurator", "Reperceive bond for each conformer", nullptr));
#endif // QT_NO_TOOLTIP
        updateBondsButton->setText(QApplication::translate("GeometryListConfigurator", "Update Bonds", nullptr));
        speedLabel->setText(QApplication::translate("GeometryListConfigurator", "Speed", nullptr));
#ifndef QT_NO_TOOLTIP
        speedSlider->setToolTip(QApplication::translate("GeometryListConfigurator", "Controls the speed of animation", nullptr));
#endif // QT_NO_TOOLTIP
        resetViewButton->setText(QApplication::translate("GeometryListConfigurator", "Reset View", nullptr));
        closeButton->setText(QApplication::translate("GeometryListConfigurator", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GeometryListConfigurator: public Ui_GeometryListConfigurator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GEOMETRYLISTCONFIGURATOR_H
