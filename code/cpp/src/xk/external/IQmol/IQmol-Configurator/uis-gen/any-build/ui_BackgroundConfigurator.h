/********************************************************************************
** Form generated from reading UI file 'BackgroundConfigurator.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BACKGROUNDCONFIGURATOR_H
#define UI_BACKGROUNDCONFIGURATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
            BackgroundConfigurator->setObjectName(QStringLiteral("BackgroundConfigurator"));
        BackgroundConfigurator->resize(317, 149);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BackgroundConfigurator->sizePolicy().hasHeightForWidth());
        BackgroundConfigurator->setSizePolicy(sizePolicy);
        BackgroundConfigurator->setSizeGripEnabled(false);
        verticalLayout = new QVBoxLayout(BackgroundConfigurator);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(BackgroundConfigurator);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(BackgroundConfigurator);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        backgroundColorButton = new QToolButton(BackgroundConfigurator);
        backgroundColorButton->setObjectName(QStringLiteral("backgroundColorButton"));

        gridLayout->addWidget(backgroundColorButton, 0, 1, 1, 1);

        foregroundColorButton = new QToolButton(BackgroundConfigurator);
        foregroundColorButton->setObjectName(QStringLiteral("foregroundColorButton"));

        gridLayout->addWidget(foregroundColorButton, 1, 1, 1, 1);

        makeDefaultButton = new QCheckBox(BackgroundConfigurator);
        makeDefaultButton->setObjectName(QStringLiteral("makeDefaultButton"));

        gridLayout->addWidget(makeDefaultButton, 1, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        applyButton = new QPushButton(BackgroundConfigurator);
        applyButton->setObjectName(QStringLiteral("applyButton"));
        applyButton->setAutoDefault(false);

        horizontalLayout_2->addWidget(applyButton);

        okButton = new QPushButton(BackgroundConfigurator);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setAutoDefault(false);

        horizontalLayout_2->addWidget(okButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(BackgroundConfigurator);

        okButton->setDefault(true);


        QMetaObject::connectSlotsByName(BackgroundConfigurator);
    } // setupUi

    void retranslateUi(QDialog *BackgroundConfigurator)
    {
        BackgroundConfigurator->setWindowTitle(QApplication::translate("BackgroundConfigurator", "Configure Background", Q_NULLPTR));
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
"", Q_NULLPTR));
        label_2->setText(QApplication::translate("BackgroundConfigurator", "Foreground Color", Q_NULLPTR));
        label->setText(QApplication::translate("BackgroundConfigurator", "Background Color", Q_NULLPTR));
        backgroundColorButton->setStyleSheet(QString());
        backgroundColorButton->setText(QString());
        foregroundColorButton->setStyleSheet(QString());
        foregroundColorButton->setText(QString());
        makeDefaultButton->setText(QApplication::translate("BackgroundConfigurator", "Make Default", Q_NULLPTR));
        applyButton->setText(QApplication::translate("BackgroundConfigurator", "Apply", Q_NULLPTR));
        okButton->setText(QApplication::translate("BackgroundConfigurator", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BackgroundConfigurator: public Ui_BackgroundConfigurator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BACKGROUNDCONFIGURATOR_H
