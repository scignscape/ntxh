/********************************************************************************
** Form generated from reading UI file 'AxesConfigurator.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AXESCONFIGURATOR_H
#define UI_AXESCONFIGURATOR_H

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
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AxesConfigurator
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QCheckBox *xCheckBox;
    QCheckBox *yCheckBox;
    QCheckBox *zCheckBox;
    QLabel *label;
    QSlider *scaleSlider;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *okButton;

    void setupUi(QDialog *AxesConfigurator)
    {
        if (AxesConfigurator->objectName().isEmpty())
            AxesConfigurator->setObjectName(QStringLiteral("AxesConfigurator"));
        AxesConfigurator->resize(215, 117);
        verticalLayout = new QVBoxLayout(AxesConfigurator);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        xCheckBox = new QCheckBox(AxesConfigurator);
        xCheckBox->setObjectName(QStringLiteral("xCheckBox"));
        xCheckBox->setChecked(true);

        gridLayout->addWidget(xCheckBox, 0, 2, 1, 1);

        yCheckBox = new QCheckBox(AxesConfigurator);
        yCheckBox->setObjectName(QStringLiteral("yCheckBox"));
        yCheckBox->setChecked(true);

        gridLayout->addWidget(yCheckBox, 0, 0, 1, 1);

        zCheckBox = new QCheckBox(AxesConfigurator);
        zCheckBox->setObjectName(QStringLiteral("zCheckBox"));
        zCheckBox->setChecked(true);

        gridLayout->addWidget(zCheckBox, 0, 1, 1, 1);

        label = new QLabel(AxesConfigurator);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        scaleSlider = new QSlider(AxesConfigurator);
        scaleSlider->setObjectName(QStringLiteral("scaleSlider"));
        scaleSlider->setMinimum(10);
        scaleSlider->setMaximum(200);
        scaleSlider->setValue(100);
        scaleSlider->setSliderPosition(100);
        scaleSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(scaleSlider, 1, 1, 1, 2);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        okButton = new QPushButton(AxesConfigurator);
        okButton->setObjectName(QStringLiteral("okButton"));

        horizontalLayout_2->addWidget(okButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(AxesConfigurator);

        QMetaObject::connectSlotsByName(AxesConfigurator);
    } // setupUi

    void retranslateUi(QDialog *AxesConfigurator)
    {
        AxesConfigurator->setWindowTitle(QApplication::translate("AxesConfigurator", "Configure Mesh", Q_NULLPTR));
        xCheckBox->setText(QApplication::translate("AxesConfigurator", "Z Axis", Q_NULLPTR));
        yCheckBox->setText(QApplication::translate("AxesConfigurator", "X Axis", Q_NULLPTR));
        zCheckBox->setText(QApplication::translate("AxesConfigurator", "Y Axis", Q_NULLPTR));
        label->setText(QApplication::translate("AxesConfigurator", "Scale", Q_NULLPTR));
        okButton->setText(QApplication::translate("AxesConfigurator", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AxesConfigurator: public Ui_AxesConfigurator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AXESCONFIGURATOR_H
