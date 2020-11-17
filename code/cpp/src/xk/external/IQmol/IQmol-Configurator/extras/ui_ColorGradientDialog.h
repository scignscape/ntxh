/********************************************************************************
** Form generated from reading UI file 'ColorGradientDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORGRADIENTDIALOG_H
#define UI_COLORGRADIENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ColorGradientDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QGraphicsView *gradientView;
    QHBoxLayout *buttonLayout;
    QToolButton *color31;
    QSpacerItem *horizontalSpacer;
    QToolButton *color32;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *color33;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *gradientCombo;
    QSpacerItem *horizontalSpacer_7;
    QLabel *stopsLabel;
    QSpinBox *stopsSpin;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ColorGradientDialog)
    {
        if (ColorGradientDialog->objectName().isEmpty())
            ColorGradientDialog->setObjectName(QString::fromUtf8("ColorGradientDialog"));
        ColorGradientDialog->resize(354, 208);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ColorGradientDialog->sizePolicy().hasHeightForWidth());
        ColorGradientDialog->setSizePolicy(sizePolicy);
        ColorGradientDialog->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"   color: #333;\n"
"   border-width: 1px;\n"
"   border-color: #333;\n"
"   border-style: solid;\n"
"   border-radius: 1;\n"
"   padding: 0px;\n"
"   min-width: 12px;\n"
"   max-width: 12px;\n"
"   min-height: 12px;\n"
"   max-height: 12px;\n"
"}\n"
"\n"
"QGraphicsView {\n"
"   color: #333;\n"
"   border-width: 1px;\n"
"   border-color: #333;\n"
"   border-style: solid;\n"
"   border-radius: 1;\n"
"   padding: 0px;\n"
"   min-width: 300px;\n"
"   max-width: 3000px;\n"
"   min-height: 35px;\n"
"   max-height: 35px;\n"
"}"));
        verticalLayout = new QVBoxLayout(ColorGradientDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(ColorGradientDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gradientView = new QGraphicsView(frame);
        gradientView->setObjectName(QString::fromUtf8("gradientView"));

        verticalLayout_2->addWidget(gradientView);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName(QString::fromUtf8("buttonLayout"));
        color31 = new QToolButton(frame);
        color31->setObjectName(QString::fromUtf8("color31"));

        buttonLayout->addWidget(color31);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonLayout->addItem(horizontalSpacer);

        color32 = new QToolButton(frame);
        color32->setObjectName(QString::fromUtf8("color32"));

        buttonLayout->addWidget(color32);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonLayout->addItem(horizontalSpacer_2);

        color33 = new QToolButton(frame);
        color33->setObjectName(QString::fromUtf8("color33"));

        buttonLayout->addWidget(color33);


        verticalLayout_2->addLayout(buttonLayout);


        verticalLayout->addWidget(frame);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        gradientCombo = new QComboBox(ColorGradientDialog);
        gradientCombo->addItem(QString());
        gradientCombo->addItem(QString());
        gradientCombo->addItem(QString());
        gradientCombo->setObjectName(QString::fromUtf8("gradientCombo"));

        horizontalLayout_2->addWidget(gradientCombo);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        stopsLabel = new QLabel(ColorGradientDialog);
        stopsLabel->setObjectName(QString::fromUtf8("stopsLabel"));
        stopsLabel->setEnabled(true);

        horizontalLayout_2->addWidget(stopsLabel);

        stopsSpin = new QSpinBox(ColorGradientDialog);
        stopsSpin->setObjectName(QString::fromUtf8("stopsSpin"));
        stopsSpin->setEnabled(true);
        stopsSpin->setKeyboardTracking(false);
        stopsSpin->setMinimum(1);
        stopsSpin->setMaximum(15);
        stopsSpin->setSingleStep(2);
        stopsSpin->setValue(3);

        horizontalLayout_2->addWidget(stopsSpin);


        verticalLayout->addLayout(horizontalLayout_2);

        buttonBox = new QDialogButtonBox(ColorGradientDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ColorGradientDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ColorGradientDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ColorGradientDialog, SLOT(reject()));

        gradientCombo->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(ColorGradientDialog);
    } // setupUi

    void retranslateUi(QDialog *ColorGradientDialog)
    {
        ColorGradientDialog->setWindowTitle(QApplication::translate("ColorGradientDialog", "Color Gradient Editor", nullptr));
        gradientView->setStyleSheet(QApplication::translate("ColorGradientDialog", "QGraphicsView {\n"
"   background-color: QLinearGradient( x1: 0, y1: 1, x2: 1, y2: 1, \n"
"          stop: 0 #f00,\n"
"          stop: 0.5 #fff, \n"
"          stop: 1 #00f);\n"
"}", nullptr));
        color31->setStyleSheet(QApplication::translate("ColorGradientDialog", "QToolButton {\n"
"   background-color: #f00;\n"
"}", nullptr));
        color31->setText(QString());
        color32->setStyleSheet(QApplication::translate("ColorGradientDialog", "QToolButton {\n"
"   background-color: #fff;\n"
"}", nullptr));
        color32->setText(QString());
        color33->setStyleSheet(QApplication::translate("ColorGradientDialog", "QToolButton {\n"
"   background-color: #00f;\n"
"}", nullptr));
        color33->setText(QString());
        gradientCombo->setItemText(0, QApplication::translate("ColorGradientDialog", "Default", nullptr));
        gradientCombo->setItemText(1, QApplication::translate("ColorGradientDialog", "Spectrum", nullptr));
        gradientCombo->setItemText(2, QApplication::translate("ColorGradientDialog", "Custom", nullptr));

        stopsLabel->setText(QApplication::translate("ColorGradientDialog", "Stops", nullptr));
        buttonBox->setStyleSheet(QApplication::translate("ColorGradientDialog", "QToolButton {\n"
"   color: #333;\n"
"   border-width: 1px;\n"
"   border-color: #333;\n"
"   border-style: solid;\n"
"   border-radius: 1;\n"
"   padding: 0px;\n"
"   min-width: 15px;\n"
"   max-width: 15px;\n"
"   min-height: 15px;\n"
"   max-height: 15px;\n"
"}", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ColorGradientDialog: public Ui_ColorGradientDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORGRADIENTDIALOG_H
