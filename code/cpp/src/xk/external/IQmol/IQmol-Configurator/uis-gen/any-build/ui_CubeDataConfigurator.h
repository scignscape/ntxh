/********************************************************************************
** Form generated from reading UI file 'CubeDataConfigurator.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUBEDATACONFIGURATOR_H
#define UI_CUBEDATACONFIGURATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CubeDataConfigurator
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QDoubleSpinBox *isovalue;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QCheckBox *signedButton;
    QCheckBox *simplifyMeshCheckBox;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_12;
    QToolButton *negativeColorButton;
    QLabel *negativeLabel;
    QToolButton *positiveColorButton;
    QLabel *positiveLabel;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *cancelButton;
    QPushButton *calculateButton;

    void setupUi(QDialog *CubeDataConfigurator)
    {
        if (CubeDataConfigurator->objectName().isEmpty())
            CubeDataConfigurator->setObjectName(QString::fromUtf8("CubeDataConfigurator"));
        CubeDataConfigurator->resize(331, 184);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CubeDataConfigurator->sizePolicy().hasHeightForWidth());
        CubeDataConfigurator->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(CubeDataConfigurator);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(CubeDataConfigurator);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_5->addWidget(label_3);

        isovalue = new QDoubleSpinBox(CubeDataConfigurator);
        isovalue->setObjectName(QString::fromUtf8("isovalue"));
        isovalue->setDecimals(3);
        isovalue->setMinimum(0.001000000000000);
        isovalue->setMaximum(99.998999999999995);
        isovalue->setSingleStep(0.001000000000000);
        isovalue->setValue(0.020000000000000);

        horizontalLayout_5->addWidget(isovalue);

        horizontalSpacer_4 = new QSpacerItem(238, 33, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        signedButton = new QCheckBox(CubeDataConfigurator);
        signedButton->setObjectName(QString::fromUtf8("signedButton"));
        signedButton->setChecked(true);

        horizontalLayout->addWidget(signedButton);

        simplifyMeshCheckBox = new QCheckBox(CubeDataConfigurator);
        simplifyMeshCheckBox->setObjectName(QString::fromUtf8("simplifyMeshCheckBox"));
        simplifyMeshCheckBox->setChecked(true);

        horizontalLayout->addWidget(simplifyMeshCheckBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_12 = new QLabel(CubeDataConfigurator);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_4->addWidget(label_12);

        negativeColorButton = new QToolButton(CubeDataConfigurator);
        negativeColorButton->setObjectName(QString::fromUtf8("negativeColorButton"));
        negativeColorButton->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"   background-color: rgb(255, 0, 0);\n"
"}"));
        negativeColorButton->setIconSize(QSize(32, 16));

        horizontalLayout_4->addWidget(negativeColorButton);

        negativeLabel = new QLabel(CubeDataConfigurator);
        negativeLabel->setObjectName(QString::fromUtf8("negativeLabel"));

        horizontalLayout_4->addWidget(negativeLabel);

        positiveColorButton = new QToolButton(CubeDataConfigurator);
        positiveColorButton->setObjectName(QString::fromUtf8("positiveColorButton"));
        positiveColorButton->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"   background-color: rgb(0, 0, 255);\n"
"}"));
        positiveColorButton->setIconSize(QSize(32, 16));

        horizontalLayout_4->addWidget(positiveColorButton);

        positiveLabel = new QLabel(CubeDataConfigurator);
        positiveLabel->setObjectName(QString::fromUtf8("positiveLabel"));

        horizontalLayout_4->addWidget(positiveLabel);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);

        cancelButton = new QPushButton(CubeDataConfigurator);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setAutoDefault(false);

        horizontalLayout_8->addWidget(cancelButton);

        calculateButton = new QPushButton(CubeDataConfigurator);
        calculateButton->setObjectName(QString::fromUtf8("calculateButton"));

        horizontalLayout_8->addWidget(calculateButton);


        verticalLayout->addLayout(horizontalLayout_8);


        retranslateUi(CubeDataConfigurator);
        QObject::connect(cancelButton, SIGNAL(clicked()), CubeDataConfigurator, SLOT(close()));

        calculateButton->setDefault(true);


        QMetaObject::connectSlotsByName(CubeDataConfigurator);
    } // setupUi

    void retranslateUi(QDialog *CubeDataConfigurator)
    {
        CubeDataConfigurator->setWindowTitle(QApplication::translate("CubeDataConfigurator", "Add Surface", nullptr));
        CubeDataConfigurator->setStyleSheet(QApplication::translate("CubeDataConfigurator", "QToolButton {\n"
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
        label_3->setText(QApplication::translate("CubeDataConfigurator", "Isosurface Value:", nullptr));
#ifndef QT_NO_TOOLTIP
        signedButton->setToolTip(QApplication::translate("CubeDataConfigurator", "A signed surface will disply both the \n"
"positive and negative isosurfaces.  \n"
"Uncheck if only one surface is desired.", nullptr));
#endif // QT_NO_TOOLTIP
        signedButton->setText(QApplication::translate("CubeDataConfigurator", "Signed", nullptr));
        simplifyMeshCheckBox->setText(QApplication::translate("CubeDataConfigurator", "Simplify Mesh", nullptr));
        label_12->setText(QApplication::translate("CubeDataConfigurator", "Colors: ", nullptr));
        negativeColorButton->setText(QString());
        negativeLabel->setText(QApplication::translate("CubeDataConfigurator", "Negative", nullptr));
        positiveColorButton->setText(QString());
        positiveLabel->setText(QApplication::translate("CubeDataConfigurator", "Positive", nullptr));
        cancelButton->setText(QApplication::translate("CubeDataConfigurator", "Cancel", nullptr));
        calculateButton->setText(QApplication::translate("CubeDataConfigurator", "Calculate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CubeDataConfigurator: public Ui_CubeDataConfigurator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUBEDATACONFIGURATOR_H
