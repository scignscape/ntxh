/********************************************************************************
** Form generated from reading UI file 'NmrConfigurator.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NMRCONFIGURATOR_H
#define UI_NMRCONFIGURATOR_H

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

class Ui_NmrConfigurator
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QTableWidget *shieldingsTable;
    QGridLayout *gridLayout;
    QComboBox *systemCombo;
    QLabel *label;
    QLabel *label_3;
    QComboBox *isotopeCombo;
    QLabel *label_2;
    QComboBox *methodCombo;
    QVBoxLayout *verticalLayout_2;
    QFrame *spectrumFrame;
    QHBoxLayout *horizontalLayout;
    QRadioButton *impulseButton;
    QRadioButton *lorentzianButton;
    QLabel *widthLabel;
    QSlider *widthSlider;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;

    void setupUi(QDialog *NmrConfigurator)
    {
        if (NmrConfigurator->objectName().isEmpty())
            NmrConfigurator->setObjectName(QStringLiteral("NmrConfigurator"));
        NmrConfigurator->resize(935, 438);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(NmrConfigurator->sizePolicy().hasHeightForWidth());
        NmrConfigurator->setSizePolicy(sizePolicy);
        NmrConfigurator->setToolTipDuration(0);
        NmrConfigurator->setStyleSheet(QLatin1String("QToolButton {\n"
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
        horizontalLayout_2 = new QHBoxLayout(NmrConfigurator);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        shieldingsTable = new QTableWidget(NmrConfigurator);
        if (shieldingsTable->columnCount() < 3)
            shieldingsTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        shieldingsTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        shieldingsTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        shieldingsTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        shieldingsTable->setObjectName(QStringLiteral("shieldingsTable"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(shieldingsTable->sizePolicy().hasHeightForWidth());
        shieldingsTable->setSizePolicy(sizePolicy1);
        shieldingsTable->setMinimumSize(QSize(260, 0));
        shieldingsTable->setMaximumSize(QSize(240, 16777215));
        shieldingsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        shieldingsTable->setSelectionMode(QAbstractItemView::SingleSelection);
        shieldingsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        shieldingsTable->horizontalHeader()->setCascadingSectionResizes(true);
        shieldingsTable->horizontalHeader()->setDefaultSectionSize(60);
        shieldingsTable->horizontalHeader()->setMinimumSectionSize(60);
        shieldingsTable->horizontalHeader()->setStretchLastSection(true);
        shieldingsTable->verticalHeader()->setCascadingSectionResizes(true);

        verticalLayout->addWidget(shieldingsTable);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        systemCombo = new QComboBox(NmrConfigurator);
        systemCombo->setObjectName(QStringLiteral("systemCombo"));

        gridLayout->addWidget(systemCombo, 1, 1, 1, 1);

        label = new QLabel(NmrConfigurator);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(NmrConfigurator);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        isotopeCombo = new QComboBox(NmrConfigurator);
        isotopeCombo->setObjectName(QStringLiteral("isotopeCombo"));

        gridLayout->addWidget(isotopeCombo, 0, 1, 1, 1);

        label_2 = new QLabel(NmrConfigurator);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        methodCombo = new QComboBox(NmrConfigurator);
        methodCombo->setObjectName(QStringLiteral("methodCombo"));

        gridLayout->addWidget(methodCombo, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        spectrumFrame = new QFrame(NmrConfigurator);
        spectrumFrame->setObjectName(QStringLiteral("spectrumFrame"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(spectrumFrame->sizePolicy().hasHeightForWidth());
        spectrumFrame->setSizePolicy(sizePolicy2);
        spectrumFrame->setMinimumSize(QSize(300, 0));
        spectrumFrame->setContextMenuPolicy(Qt::DefaultContextMenu);
        spectrumFrame->setFrameShape(QFrame::StyledPanel);
        spectrumFrame->setFrameShadow(QFrame::Raised);

        verticalLayout_2->addWidget(spectrumFrame);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        impulseButton = new QRadioButton(NmrConfigurator);
        impulseButton->setObjectName(QStringLiteral("impulseButton"));
        impulseButton->setChecked(true);

        horizontalLayout->addWidget(impulseButton);

        lorentzianButton = new QRadioButton(NmrConfigurator);
        lorentzianButton->setObjectName(QStringLiteral("lorentzianButton"));

        horizontalLayout->addWidget(lorentzianButton);

        widthLabel = new QLabel(NmrConfigurator);
        widthLabel->setObjectName(QStringLiteral("widthLabel"));

        horizontalLayout->addWidget(widthLabel);

        widthSlider = new QSlider(NmrConfigurator);
        widthSlider->setObjectName(QStringLiteral("widthSlider"));
        widthSlider->setMinimum(1);
        widthSlider->setMaximum(100);
        widthSlider->setValue(30);
        widthSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(widthSlider);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closeButton = new QPushButton(NmrConfigurator);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setAutoDefault(false);

        horizontalLayout->addWidget(closeButton);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout_2->setStretch(0, 1);

        horizontalLayout_2->addLayout(verticalLayout_2);


        retranslateUi(NmrConfigurator);
        QObject::connect(closeButton, SIGNAL(clicked()), NmrConfigurator, SLOT(close()));

        QMetaObject::connectSlotsByName(NmrConfigurator);
    } // setupUi

    void retranslateUi(QDialog *NmrConfigurator)
    {
        NmrConfigurator->setWindowTitle(QApplication::translate("NmrConfigurator", "NMR Spectrum", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = shieldingsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("NmrConfigurator", "Atom", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = shieldingsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("NmrConfigurator", "Shielding", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = shieldingsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("NmrConfigurator", "Chem. Shift", Q_NULLPTR));
        label->setText(QApplication::translate("NmrConfigurator", "Spectrum", Q_NULLPTR));
        label_3->setText(QApplication::translate("NmrConfigurator", "Reference", Q_NULLPTR));
        isotopeCombo->clear();
        isotopeCombo->insertItems(0, QStringList()
         << QApplication::translate("NmrConfigurator", "Shieldings", Q_NULLPTR)
         << QApplication::translate("NmrConfigurator", "Proton (1H)", Q_NULLPTR)
         << QApplication::translate("NmrConfigurator", "Boron (11B)", Q_NULLPTR)
         << QApplication::translate("NmrConfigurator", "Carbon (13C)", Q_NULLPTR)
         << QApplication::translate("NmrConfigurator", "Nitrogen (15N)", Q_NULLPTR)
         << QApplication::translate("NmrConfigurator", "Flourine (19F)", Q_NULLPTR)
         << QApplication::translate("NmrConfigurator", "Silicon (29Si)", Q_NULLPTR)
         << QApplication::translate("NmrConfigurator", "Phosphorous (31P)", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("NmrConfigurator", "Method", Q_NULLPTR));
        impulseButton->setText(QApplication::translate("NmrConfigurator", "Impulse", Q_NULLPTR));
        lorentzianButton->setText(QApplication::translate("NmrConfigurator", "Spectrum", Q_NULLPTR));
        widthLabel->setText(QApplication::translate("NmrConfigurator", "Width", Q_NULLPTR));
        closeButton->setText(QApplication::translate("NmrConfigurator", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NmrConfigurator: public Ui_NmrConfigurator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NMRCONFIGURATOR_H
