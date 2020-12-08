/********************************************************************************
** Form generated from reading UI file 'ClippingPlaneConfigurator.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIPPINGPLANECONFIGURATOR_H
#define UI_CLIPPINGPLANECONFIGURATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ClippingPlaneConfigurator
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QDoubleSpinBox *xValue;
    QLabel *label_5;
    QLabel *label;
    QDoubleSpinBox *yValue;
    QLabel *label_7;
    QDoubleSpinBox *zValue;
    QLabel *phiLabel;
    QLabel *thetaLabel;
    QLabel *label_2;
    QSpinBox *thetaValue;
    QSpinBox *phiValue;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *okButton;

    void setupUi(QDialog *ClippingPlaneConfigurator)
    {
        if (ClippingPlaneConfigurator->objectName().isEmpty())
            ClippingPlaneConfigurator->setObjectName(QStringLiteral("ClippingPlaneConfigurator"));
        ClippingPlaneConfigurator->resize(358, 126);
        verticalLayout = new QVBoxLayout(ClippingPlaneConfigurator);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_6 = new QLabel(ClippingPlaneConfigurator);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 0, 3, 1, 1);

        xValue = new QDoubleSpinBox(ClippingPlaneConfigurator);
        xValue->setObjectName(QStringLiteral("xValue"));
        xValue->setMinimum(-99.99);

        gridLayout->addWidget(xValue, 0, 2, 1, 1);

        label_5 = new QLabel(ClippingPlaneConfigurator);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 0, 1, 1, 1);

        label = new QLabel(ClippingPlaneConfigurator);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        yValue = new QDoubleSpinBox(ClippingPlaneConfigurator);
        yValue->setObjectName(QStringLiteral("yValue"));
        yValue->setMinimum(-99.99);

        gridLayout->addWidget(yValue, 0, 4, 1, 1);

        label_7 = new QLabel(ClippingPlaneConfigurator);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 0, 5, 1, 1);

        zValue = new QDoubleSpinBox(ClippingPlaneConfigurator);
        zValue->setObjectName(QStringLiteral("zValue"));
        zValue->setMinimum(-99.99);

        gridLayout->addWidget(zValue, 0, 6, 1, 1);

        phiLabel = new QLabel(ClippingPlaneConfigurator);
        phiLabel->setObjectName(QStringLiteral("phiLabel"));

        gridLayout->addWidget(phiLabel, 1, 5, 1, 1);

        thetaLabel = new QLabel(ClippingPlaneConfigurator);
        thetaLabel->setObjectName(QStringLiteral("thetaLabel"));

        gridLayout->addWidget(thetaLabel, 1, 3, 1, 1);

        label_2 = new QLabel(ClippingPlaneConfigurator);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 3);

        thetaValue = new QSpinBox(ClippingPlaneConfigurator);
        thetaValue->setObjectName(QStringLiteral("thetaValue"));
        thetaValue->setMaximum(180);
        thetaValue->setSingleStep(15);

        gridLayout->addWidget(thetaValue, 1, 4, 1, 1);

        phiValue = new QSpinBox(ClippingPlaneConfigurator);
        phiValue->setObjectName(QStringLiteral("phiValue"));
        phiValue->setMaximum(360);
        phiValue->setSingleStep(15);

        gridLayout->addWidget(phiValue, 1, 6, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        okButton = new QPushButton(ClippingPlaneConfigurator);
        okButton->setObjectName(QStringLiteral("okButton"));

        horizontalLayout_2->addWidget(okButton);


        verticalLayout->addLayout(horizontalLayout_2);

        QWidget::setTabOrder(xValue, yValue);
        QWidget::setTabOrder(yValue, zValue);
        QWidget::setTabOrder(zValue, okButton);

        retranslateUi(ClippingPlaneConfigurator);

        QMetaObject::connectSlotsByName(ClippingPlaneConfigurator);
    } // setupUi

    void retranslateUi(QDialog *ClippingPlaneConfigurator)
    {
        ClippingPlaneConfigurator->setWindowTitle(QApplication::translate("ClippingPlaneConfigurator", "Configure Clipping Plane", Q_NULLPTR));
        label_6->setText(QApplication::translate("ClippingPlaneConfigurator", "Y", Q_NULLPTR));
        label_5->setText(QApplication::translate("ClippingPlaneConfigurator", "X", Q_NULLPTR));
        label->setText(QApplication::translate("ClippingPlaneConfigurator", "Origin", Q_NULLPTR));
        label_7->setText(QApplication::translate("ClippingPlaneConfigurator", "Z", Q_NULLPTR));
        phiLabel->setText(QApplication::translate("ClippingPlaneConfigurator", "<html><head/><body><p>p</p></body></html>", Q_NULLPTR));
        thetaLabel->setText(QApplication::translate("ClippingPlaneConfigurator", "<html><head/><body><p>t</p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("ClippingPlaneConfigurator", "Normal Direction", Q_NULLPTR));
        okButton->setText(QApplication::translate("ClippingPlaneConfigurator", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ClippingPlaneConfigurator: public Ui_ClippingPlaneConfigurator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIPPINGPLANECONFIGURATOR_H
