/********************************************************************************
** Form generated from reading UI file 'ExcitedStatesConfigurator.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXCITEDSTATESCONFIGURATOR_H
#define UI_EXCITEDSTATESCONFIGURATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
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
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ExcitedStatesConfigurator
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QFrame *moFrame;
    QLabel *orbitalLabel;
    QTableWidget *energyTable;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *unitsCombo;
    QSpacerItem *horizontalSpacer_2;
    QFrame *spectrumFrame;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *impulseButton;
    QRadioButton *gaussianButton;
    QRadioButton *lorentzianButton;
    QFrame *line_2;
    QLabel *widthLabel;
    QSlider *widthSlider;
    QFrame *line;
    QPushButton *resetZoomButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;

    void setupUi(QDialog *ExcitedStatesConfigurator)
    {
        if (ExcitedStatesConfigurator->objectName().isEmpty())
            ExcitedStatesConfigurator->setObjectName(QStringLiteral("ExcitedStatesConfigurator"));
        ExcitedStatesConfigurator->resize(702, 505);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ExcitedStatesConfigurator->sizePolicy().hasHeightForWidth());
        ExcitedStatesConfigurator->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(ExcitedStatesConfigurator);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        moFrame = new QFrame(ExcitedStatesConfigurator);
        moFrame->setObjectName(QStringLiteral("moFrame"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(moFrame->sizePolicy().hasHeightForWidth());
        moFrame->setSizePolicy(sizePolicy1);
        moFrame->setFrameShape(QFrame::StyledPanel);
        moFrame->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(moFrame, 0, 1, 1, 1);

        orbitalLabel = new QLabel(ExcitedStatesConfigurator);
        orbitalLabel->setObjectName(QStringLiteral("orbitalLabel"));

        gridLayout->addWidget(orbitalLabel, 1, 1, 1, 1);

        energyTable = new QTableWidget(ExcitedStatesConfigurator);
        if (energyTable->columnCount() < 3)
            energyTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        energyTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        energyTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        energyTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        energyTable->setObjectName(QStringLiteral("energyTable"));
        energyTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        energyTable->setSelectionMode(QAbstractItemView::SingleSelection);
        energyTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        energyTable->horizontalHeader()->setCascadingSectionResizes(true);

        gridLayout->addWidget(energyTable, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(ExcitedStatesConfigurator);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        unitsCombo = new QComboBox(ExcitedStatesConfigurator);
        unitsCombo->setObjectName(QStringLiteral("unitsCombo"));

        horizontalLayout->addWidget(unitsCombo);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        spectrumFrame = new QFrame(ExcitedStatesConfigurator);
        spectrumFrame->setObjectName(QStringLiteral("spectrumFrame"));
        sizePolicy1.setHeightForWidth(spectrumFrame->sizePolicy().hasHeightForWidth());
        spectrumFrame->setSizePolicy(sizePolicy1);
        spectrumFrame->setFrameShape(QFrame::StyledPanel);
        spectrumFrame->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(spectrumFrame);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        impulseButton = new QRadioButton(ExcitedStatesConfigurator);
        impulseButton->setObjectName(QStringLiteral("impulseButton"));
        impulseButton->setChecked(true);

        horizontalLayout_2->addWidget(impulseButton);

        gaussianButton = new QRadioButton(ExcitedStatesConfigurator);
        gaussianButton->setObjectName(QStringLiteral("gaussianButton"));

        horizontalLayout_2->addWidget(gaussianButton);

        lorentzianButton = new QRadioButton(ExcitedStatesConfigurator);
        lorentzianButton->setObjectName(QStringLiteral("lorentzianButton"));

        horizontalLayout_2->addWidget(lorentzianButton);

        line_2 = new QFrame(ExcitedStatesConfigurator);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_2);

        widthLabel = new QLabel(ExcitedStatesConfigurator);
        widthLabel->setObjectName(QStringLiteral("widthLabel"));

        horizontalLayout_2->addWidget(widthLabel);

        widthSlider = new QSlider(ExcitedStatesConfigurator);
        widthSlider->setObjectName(QStringLiteral("widthSlider"));
        widthSlider->setMinimum(10);
        widthSlider->setMaximum(110);
        widthSlider->setValue(30);
        widthSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(widthSlider);

        line = new QFrame(ExcitedStatesConfigurator);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line);

        resetZoomButton = new QPushButton(ExcitedStatesConfigurator);
        resetZoomButton->setObjectName(QStringLiteral("resetZoomButton"));
        resetZoomButton->setAutoDefault(false);

        horizontalLayout_2->addWidget(resetZoomButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        closeButton = new QPushButton(ExcitedStatesConfigurator);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setAutoDefault(true);

        horizontalLayout_2->addWidget(closeButton);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(1, 1);

        retranslateUi(ExcitedStatesConfigurator);
        QObject::connect(closeButton, SIGNAL(clicked()), ExcitedStatesConfigurator, SLOT(close()));

        QMetaObject::connectSlotsByName(ExcitedStatesConfigurator);
    } // setupUi

    void retranslateUi(QDialog *ExcitedStatesConfigurator)
    {
        ExcitedStatesConfigurator->setWindowTitle(QApplication::translate("ExcitedStatesConfigurator", "Excited States", Q_NULLPTR));
        ExcitedStatesConfigurator->setStyleSheet(QApplication::translate("ExcitedStatesConfigurator", "QToolButton {\n"
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
        orbitalLabel->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = energyTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ExcitedStatesConfigurator", "Energy (eV)", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = energyTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ExcitedStatesConfigurator", "Strength", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = energyTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ExcitedStatesConfigurator", "<S^2>", Q_NULLPTR));
        label->setText(QApplication::translate("ExcitedStatesConfigurator", "Units", Q_NULLPTR));
        impulseButton->setText(QApplication::translate("ExcitedStatesConfigurator", "Impulse", Q_NULLPTR));
        gaussianButton->setText(QApplication::translate("ExcitedStatesConfigurator", "Gaussian", Q_NULLPTR));
        lorentzianButton->setText(QApplication::translate("ExcitedStatesConfigurator", "Lorentzian", Q_NULLPTR));
        widthLabel->setText(QApplication::translate("ExcitedStatesConfigurator", "Width", Q_NULLPTR));
        resetZoomButton->setText(QApplication::translate("ExcitedStatesConfigurator", "Reset Zoom", Q_NULLPTR));
        closeButton->setText(QApplication::translate("ExcitedStatesConfigurator", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ExcitedStatesConfigurator: public Ui_ExcitedStatesConfigurator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXCITEDSTATESCONFIGURATOR_H
