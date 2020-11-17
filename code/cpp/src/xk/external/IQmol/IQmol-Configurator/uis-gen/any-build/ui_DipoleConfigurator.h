/********************************************************************************
** Form generated from reading UI file 'DipoleConfigurator.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIPOLECONFIGURATOR_H
#define UI_DIPOLECONFIGURATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DipoleConfigurator
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *dipoleLabel;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *dipoleVector;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QSlider *scaleSlider;
    QLabel *label_4;
    QToolButton *colorButton;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;

    void setupUi(QDialog *DipoleConfigurator)
    {
        if (DipoleConfigurator->objectName().isEmpty())
            DipoleConfigurator->setObjectName(QString::fromUtf8("DipoleConfigurator"));
        DipoleConfigurator->resize(386, 169);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DipoleConfigurator->sizePolicy().hasHeightForWidth());
        DipoleConfigurator->setSizePolicy(sizePolicy);
        DipoleConfigurator->setStyleSheet(QString::fromUtf8("QToolButton {\n"
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
        verticalLayout = new QVBoxLayout(DipoleConfigurator);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        dipoleLabel = new QLabel(DipoleConfigurator);
        dipoleLabel->setObjectName(QString::fromUtf8("dipoleLabel"));

        gridLayout->addWidget(dipoleLabel, 0, 1, 1, 1);

        label_2 = new QLabel(DipoleConfigurator);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        dipoleVector = new QLabel(DipoleConfigurator);
        dipoleVector->setObjectName(QString::fromUtf8("dipoleVector"));

        gridLayout->addWidget(dipoleVector, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(DipoleConfigurator);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        scaleSlider = new QSlider(DipoleConfigurator);
        scaleSlider->setObjectName(QString::fromUtf8("scaleSlider"));
        scaleSlider->setMinimum(1);
        scaleSlider->setMaximum(100);
        scaleSlider->setValue(25);
        scaleSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(scaleSlider);

        label_4 = new QLabel(DipoleConfigurator);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        colorButton = new QToolButton(DipoleConfigurator);
        colorButton->setObjectName(QString::fromUtf8("colorButton"));

        horizontalLayout_3->addWidget(colorButton);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closeButton = new QPushButton(DipoleConfigurator);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setAutoDefault(false);

        horizontalLayout->addWidget(closeButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(DipoleConfigurator);
        QObject::connect(closeButton, SIGNAL(clicked()), DipoleConfigurator, SLOT(close()));

        QMetaObject::connectSlotsByName(DipoleConfigurator);
    } // setupUi

    void retranslateUi(QDialog *DipoleConfigurator)
    {
        DipoleConfigurator->setWindowTitle(QApplication::translate("DipoleConfigurator", "Dipole Options", nullptr));
        dipoleLabel->setText(QApplication::translate("DipoleConfigurator", "value", nullptr));
        label_2->setText(QApplication::translate("DipoleConfigurator", "Dipole:   ", nullptr));
        dipoleVector->setText(QApplication::translate("DipoleConfigurator", "vector", nullptr));
        label->setText(QApplication::translate("DipoleConfigurator", "Scale", nullptr));
#ifndef QT_NO_TOOLTIP
        scaleSlider->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_4->setText(QApplication::translate("DipoleConfigurator", "Color", nullptr));
#ifndef QT_NO_TOOLTIP
        colorButton->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        colorButton->setText(QString());
        closeButton->setText(QApplication::translate("DipoleConfigurator", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DipoleConfigurator: public Ui_DipoleConfigurator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIPOLECONFIGURATOR_H
