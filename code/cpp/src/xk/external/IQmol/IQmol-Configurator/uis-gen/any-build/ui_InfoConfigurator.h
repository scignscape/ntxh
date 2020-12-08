/********************************************************************************
** Form generated from reading UI file 'InfoConfigurator.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOCONFIGURATOR_H
#define UI_INFOCONFIGURATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_InfoConfigurator
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_9;
    QLabel *label_8;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_5;
    QLabel *atomsLabel;
    QLabel *electronsLabel;
    QLabel *formulaLabel;
    QLabel *massLabel;
    QLabel *energyLabel;
    QLabel *dipoleLabel;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *multiplicitySpin;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpinBox *chargeSpin;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QLabel *symmetryLabel;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *detectSymmetryButton;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *okButton;

    void setupUi(QDialog *InfoConfigurator)
    {
        if (InfoConfigurator->objectName().isEmpty())
            InfoConfigurator->setObjectName(QStringLiteral("InfoConfigurator"));
        InfoConfigurator->resize(305, 324);
        verticalLayout = new QVBoxLayout(InfoConfigurator);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_3 = new QLabel(InfoConfigurator);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        label_4 = new QLabel(InfoConfigurator);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        label = new QLabel(InfoConfigurator);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        label_2 = new QLabel(InfoConfigurator);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        label_9 = new QLabel(InfoConfigurator);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 4, 0, 1, 1);

        label_8 = new QLabel(InfoConfigurator);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 5, 0, 1, 1);

        label_6 = new QLabel(InfoConfigurator);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 6, 0, 1, 1);

        label_7 = new QLabel(InfoConfigurator);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 7, 0, 1, 1);

        label_5 = new QLabel(InfoConfigurator);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 8, 0, 1, 1);

        atomsLabel = new QLabel(InfoConfigurator);
        atomsLabel->setObjectName(QStringLiteral("atomsLabel"));

        gridLayout->addWidget(atomsLabel, 2, 1, 1, 1);

        electronsLabel = new QLabel(InfoConfigurator);
        electronsLabel->setObjectName(QStringLiteral("electronsLabel"));

        gridLayout->addWidget(electronsLabel, 3, 1, 1, 1);

        formulaLabel = new QLabel(InfoConfigurator);
        formulaLabel->setObjectName(QStringLiteral("formulaLabel"));
        formulaLabel->setTextFormat(Qt::RichText);

        gridLayout->addWidget(formulaLabel, 4, 1, 1, 1);

        massLabel = new QLabel(InfoConfigurator);
        massLabel->setObjectName(QStringLiteral("massLabel"));

        gridLayout->addWidget(massLabel, 5, 1, 1, 1);

        energyLabel = new QLabel(InfoConfigurator);
        energyLabel->setObjectName(QStringLiteral("energyLabel"));

        gridLayout->addWidget(energyLabel, 6, 1, 1, 1);

        dipoleLabel = new QLabel(InfoConfigurator);
        dipoleLabel->setObjectName(QStringLiteral("dipoleLabel"));

        gridLayout->addWidget(dipoleLabel, 7, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        multiplicitySpin = new QSpinBox(InfoConfigurator);
        multiplicitySpin->setObjectName(QStringLiteral("multiplicitySpin"));
        multiplicitySpin->setEnabled(true);
        multiplicitySpin->setMinimum(1);
        multiplicitySpin->setSingleStep(2);

        horizontalLayout_2->addWidget(multiplicitySpin);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_2, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        chargeSpin = new QSpinBox(InfoConfigurator);
        chargeSpin->setObjectName(QStringLiteral("chargeSpin"));
        chargeSpin->setEnabled(true);
        chargeSpin->setMinimum(-99);

        horizontalLayout->addWidget(chargeSpin);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 0, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        symmetryLabel = new QLabel(InfoConfigurator);
        symmetryLabel->setObjectName(QStringLiteral("symmetryLabel"));
        symmetryLabel->setTextFormat(Qt::RichText);

        horizontalLayout_4->addWidget(symmetryLabel);

        horizontalSpacer_4 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        detectSymmetryButton = new QPushButton(InfoConfigurator);
        detectSymmetryButton->setObjectName(QStringLiteral("detectSymmetryButton"));

        horizontalLayout_4->addWidget(detectSymmetryButton);


        gridLayout->addLayout(horizontalLayout_4, 8, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        okButton = new QPushButton(InfoConfigurator);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setAutoDefault(true);

        horizontalLayout_3->addWidget(okButton);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(InfoConfigurator);
        QObject::connect(okButton, SIGNAL(clicked()), InfoConfigurator, SLOT(close()));

        okButton->setDefault(true);


        QMetaObject::connectSlotsByName(InfoConfigurator);
    } // setupUi

    void retranslateUi(QDialog *InfoConfigurator)
    {
        InfoConfigurator->setWindowTitle(QApplication::translate("InfoConfigurator", "Dialog", Q_NULLPTR));
        label_3->setText(QApplication::translate("InfoConfigurator", "Total charge:", Q_NULLPTR));
        label_4->setText(QApplication::translate("InfoConfigurator", "Multiplicity:", Q_NULLPTR));
        label->setText(QApplication::translate("InfoConfigurator", "Number of atoms:", Q_NULLPTR));
        label_2->setText(QApplication::translate("InfoConfigurator", "Number of electrons:", Q_NULLPTR));
        label_9->setText(QApplication::translate("InfoConfigurator", "Chemical formula:", Q_NULLPTR));
        label_8->setText(QApplication::translate("InfoConfigurator", "Molecular mass:", Q_NULLPTR));
        label_6->setText(QApplication::translate("InfoConfigurator", "Energy:", Q_NULLPTR));
        label_7->setText(QApplication::translate("InfoConfigurator", "Dipole moment:", Q_NULLPTR));
        label_5->setText(QApplication::translate("InfoConfigurator", "Point group:", Q_NULLPTR));
        atomsLabel->setText(QApplication::translate("InfoConfigurator", "atoms", Q_NULLPTR));
        electronsLabel->setText(QApplication::translate("InfoConfigurator", "electrons", Q_NULLPTR));
        formulaLabel->setText(QApplication::translate("InfoConfigurator", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Lucida Grande'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">formula</p></body></html>", Q_NULLPTR));
        massLabel->setText(QApplication::translate("InfoConfigurator", "mass", Q_NULLPTR));
        energyLabel->setText(QApplication::translate("InfoConfigurator", "energy", Q_NULLPTR));
        dipoleLabel->setText(QApplication::translate("InfoConfigurator", "dipole", Q_NULLPTR));
        symmetryLabel->setText(QApplication::translate("InfoConfigurator", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Lucida Grande'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">This<span style=\" font-size:16pt; vertical-align:sub;\">sd</span></p></body></html>", Q_NULLPTR));
        detectSymmetryButton->setText(QApplication::translate("InfoConfigurator", "Detect", Q_NULLPTR));
        okButton->setText(QApplication::translate("InfoConfigurator", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InfoConfigurator: public Ui_InfoConfigurator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOCONFIGURATOR_H
