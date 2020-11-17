/********************************************************************************
** Form generated from reading UI file 'InfoConfigurator.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOCONFIGURATOR_H
#define UI_INFOCONFIGURATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
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
            InfoConfigurator->setObjectName(QString::fromUtf8("InfoConfigurator"));
        InfoConfigurator->resize(305, 324);
        verticalLayout = new QVBoxLayout(InfoConfigurator);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(InfoConfigurator);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        label_4 = new QLabel(InfoConfigurator);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        label = new QLabel(InfoConfigurator);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        label_2 = new QLabel(InfoConfigurator);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        label_9 = new QLabel(InfoConfigurator);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 4, 0, 1, 1);

        label_8 = new QLabel(InfoConfigurator);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 5, 0, 1, 1);

        label_6 = new QLabel(InfoConfigurator);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 6, 0, 1, 1);

        label_7 = new QLabel(InfoConfigurator);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 7, 0, 1, 1);

        label_5 = new QLabel(InfoConfigurator);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 8, 0, 1, 1);

        atomsLabel = new QLabel(InfoConfigurator);
        atomsLabel->setObjectName(QString::fromUtf8("atomsLabel"));

        gridLayout->addWidget(atomsLabel, 2, 1, 1, 1);

        electronsLabel = new QLabel(InfoConfigurator);
        electronsLabel->setObjectName(QString::fromUtf8("electronsLabel"));

        gridLayout->addWidget(electronsLabel, 3, 1, 1, 1);

        formulaLabel = new QLabel(InfoConfigurator);
        formulaLabel->setObjectName(QString::fromUtf8("formulaLabel"));
        formulaLabel->setTextFormat(Qt::RichText);

        gridLayout->addWidget(formulaLabel, 4, 1, 1, 1);

        massLabel = new QLabel(InfoConfigurator);
        massLabel->setObjectName(QString::fromUtf8("massLabel"));

        gridLayout->addWidget(massLabel, 5, 1, 1, 1);

        energyLabel = new QLabel(InfoConfigurator);
        energyLabel->setObjectName(QString::fromUtf8("energyLabel"));

        gridLayout->addWidget(energyLabel, 6, 1, 1, 1);

        dipoleLabel = new QLabel(InfoConfigurator);
        dipoleLabel->setObjectName(QString::fromUtf8("dipoleLabel"));

        gridLayout->addWidget(dipoleLabel, 7, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        multiplicitySpin = new QSpinBox(InfoConfigurator);
        multiplicitySpin->setObjectName(QString::fromUtf8("multiplicitySpin"));
        multiplicitySpin->setEnabled(true);
        multiplicitySpin->setMinimum(1);
        multiplicitySpin->setSingleStep(2);

        horizontalLayout_2->addWidget(multiplicitySpin);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_2, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        chargeSpin = new QSpinBox(InfoConfigurator);
        chargeSpin->setObjectName(QString::fromUtf8("chargeSpin"));
        chargeSpin->setEnabled(true);
        chargeSpin->setMinimum(-99);

        horizontalLayout->addWidget(chargeSpin);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 0, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        symmetryLabel = new QLabel(InfoConfigurator);
        symmetryLabel->setObjectName(QString::fromUtf8("symmetryLabel"));
        symmetryLabel->setTextFormat(Qt::RichText);

        horizontalLayout_4->addWidget(symmetryLabel);

        horizontalSpacer_4 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        detectSymmetryButton = new QPushButton(InfoConfigurator);
        detectSymmetryButton->setObjectName(QString::fromUtf8("detectSymmetryButton"));

        horizontalLayout_4->addWidget(detectSymmetryButton);


        gridLayout->addLayout(horizontalLayout_4, 8, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        okButton = new QPushButton(InfoConfigurator);
        okButton->setObjectName(QString::fromUtf8("okButton"));
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
        InfoConfigurator->setWindowTitle(QApplication::translate("InfoConfigurator", "Dialog", nullptr));
        label_3->setText(QApplication::translate("InfoConfigurator", "Total charge:", nullptr));
        label_4->setText(QApplication::translate("InfoConfigurator", "Multiplicity:", nullptr));
        label->setText(QApplication::translate("InfoConfigurator", "Number of atoms:", nullptr));
        label_2->setText(QApplication::translate("InfoConfigurator", "Number of electrons:", nullptr));
        label_9->setText(QApplication::translate("InfoConfigurator", "Chemical formula:", nullptr));
        label_8->setText(QApplication::translate("InfoConfigurator", "Molecular mass:", nullptr));
        label_6->setText(QApplication::translate("InfoConfigurator", "Energy:", nullptr));
        label_7->setText(QApplication::translate("InfoConfigurator", "Dipole moment:", nullptr));
        label_5->setText(QApplication::translate("InfoConfigurator", "Point group:", nullptr));
        atomsLabel->setText(QApplication::translate("InfoConfigurator", "atoms", nullptr));
        electronsLabel->setText(QApplication::translate("InfoConfigurator", "electrons", nullptr));
        formulaLabel->setText(QApplication::translate("InfoConfigurator", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Lucida Grande'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">formula</p></body></html>", nullptr));
        massLabel->setText(QApplication::translate("InfoConfigurator", "mass", nullptr));
        energyLabel->setText(QApplication::translate("InfoConfigurator", "energy", nullptr));
        dipoleLabel->setText(QApplication::translate("InfoConfigurator", "dipole", nullptr));
        symmetryLabel->setText(QApplication::translate("InfoConfigurator", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Lucida Grande'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">This<span style=\" font-size:16pt; vertical-align:sub;\">sd</span></p></body></html>", nullptr));
        detectSymmetryButton->setText(QApplication::translate("InfoConfigurator", "Detect", nullptr));
        okButton->setText(QApplication::translate("InfoConfigurator", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InfoConfigurator: public Ui_InfoConfigurator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOCONFIGURATOR_H
