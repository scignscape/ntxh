/********************************************************************************
** Form generated from reading UI file 'BackgroundConfigurator.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BACKGROUNDCONFIGURATOR_H
#define UI_BACKGROUNDCONFIGURATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BackgroundConfigurator
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QToolButton *backgroundColorButton;
    QToolButton *foregroundColorButton;
    QCheckBox *makeDefaultButton;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *applyButton;
    QPushButton *okButton;

    void setupUi(QDialog *BackgroundConfigurator)
    {
        if (BackgroundConfigurator->objectName().isEmpty())
            BackgroundConfigurator->setObjectName(QString::fromUtf8("BackgroundConfigurator"));
        BackgroundConfigurator->resize(317, 149);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BackgroundConfigurator->sizePolicy().hasHeightForWidth());
        BackgroundConfigurator->setSizePolicy(sizePolicy);
        BackgroundConfigurator->setSizeGripEnabled(false);
        verticalLayout = new QVBoxLayout(BackgroundConfigurator);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(BackgroundConfigurator);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(BackgroundConfigurator);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        backgroundColorButton = new QToolButton(BackgroundConfigurator);
        backgroundColorButton->setObjectName(QString::fromUtf8("backgroundColorButton"));

        gridLayout->addWidget(backgroundColorButton, 0, 1, 1, 1);

        foregroundColorButton = new QToolButton(BackgroundConfigurator);
        foregroundColorButton->setObjectName(QString::fromUtf8("foregroundColorButton"));

        gridLayout->addWidget(foregroundColorButton, 1, 1, 1, 1);

        makeDefaultButton = new QCheckBox(BackgroundConfigurator);
        makeDefaultButton->setObjectName(QString::fromUtf8("makeDefaultButton"));

        gridLayout->addWidget(makeDefaultButton, 1, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        applyButton = new QPushButton(BackgroundConfigurator);
        applyButton->setObjectName(QString::fromUtf8("applyButton"));
        applyButton->setAutoDefault(false);

        horizontalLayout_2->addWidget(applyButton);

        okButton = new QPushButton(BackgroundConfigurator);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setAutoDefault(false);

        horizontalLayout_2->addWidget(okButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(BackgroundConfigurator);

        okButton->setDefault(true);


        QMetaObject::connectSlotsByName(BackgroundConfigurator);
    } // setupUi

    void retranslateUi(QDialog *BackgroundConfigurator)
    {
        BackgroundConfigurator->setWindowTitle(QApplication::translate("BackgroundConfigurator", "Configure Background", nullptr));
        BackgroundConfigurator->setStyleSheet(QApplication::translate("BackgroundConfigurator", "QToolButton {\n"
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
        label_2->setText(QApplication::translate("BackgroundConfigurator", "Foreground Color", nullptr));
        label->setText(QApplication::translate("BackgroundConfigurator", "Background Color", nullptr));
        backgroundColorButton->setStyleSheet(QString());
        backgroundColorButton->setText(QString());
        foregroundColorButton->setStyleSheet(QString());
        foregroundColorButton->setText(QString());
        makeDefaultButton->setText(QApplication::translate("BackgroundConfigurator", "Make Default", nullptr));
        applyButton->setText(QApplication::translate("BackgroundConfigurator", "Apply", nullptr));
        okButton->setText(QApplication::translate("BackgroundConfigurator", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BackgroundConfigurator: public Ui_BackgroundConfigurator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BACKGROUNDCONFIGURATOR_H
