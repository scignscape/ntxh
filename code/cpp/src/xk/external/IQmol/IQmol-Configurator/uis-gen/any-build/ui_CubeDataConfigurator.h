/********************************************************************************
** Form generated from reading UI file 'CubeDataConfigurator.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUBEDATACONFIGURATOR_H
#define UI_CUBEDATACONFIGURATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
            CubeDataConfigurator->setObjectName(QStringLiteral("CubeDataConfigurator"));
        CubeDataConfigurator->resize(331, 184);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CubeDataConfigurator->sizePolicy().hasHeightForWidth());
        CubeDataConfigurator->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(CubeDataConfigurator);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_3 = new QLabel(CubeDataConfigurator);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_5->addWidget(label_3);

        isovalue = new QDoubleSpinBox(CubeDataConfigurator);
        isovalue->setObjectName(QStringLiteral("isovalue"));
        isovalue->setDecimals(3);
        isovalue->setMinimum(0.001);
        isovalue->setMaximum(99.999);
        isovalue->setSingleStep(0.001);
        isovalue->setValue(0.02);

        horizontalLayout_5->addWidget(isovalue);

        horizontalSpacer_4 = new QSpacerItem(238, 33, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        signedButton = new QCheckBox(CubeDataConfigurator);
        signedButton->setObjectName(QStringLiteral("signedButton"));
        signedButton->setChecked(true);

        horizontalLayout->addWidget(signedButton);

        simplifyMeshCheckBox = new QCheckBox(CubeDataConfigurator);
        simplifyMeshCheckBox->setObjectName(QStringLiteral("simplifyMeshCheckBox"));
        simplifyMeshCheckBox->setChecked(true);

        horizontalLayout->addWidget(simplifyMeshCheckBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_12 = new QLabel(CubeDataConfigurator);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_4->addWidget(label_12);

        negativeColorButton = new QToolButton(CubeDataConfigurator);
        negativeColorButton->setObjectName(QStringLiteral("negativeColorButton"));
        negativeColorButton->setStyleSheet(QLatin1String("QToolButton {\n"
"   background-color: rgb(255, 0, 0);\n"
"}"));
        negativeColorButton->setIconSize(QSize(32, 16));

        horizontalLayout_4->addWidget(negativeColorButton);

        negativeLabel = new QLabel(CubeDataConfigurator);
        negativeLabel->setObjectName(QStringLiteral("negativeLabel"));

        horizontalLayout_4->addWidget(negativeLabel);

        positiveColorButton = new QToolButton(CubeDataConfigurator);
        positiveColorButton->setObjectName(QStringLiteral("positiveColorButton"));
        positiveColorButton->setStyleSheet(QLatin1String("QToolButton {\n"
"   background-color: rgb(0, 0, 255);\n"
"}"));
        positiveColorButton->setIconSize(QSize(32, 16));

        horizontalLayout_4->addWidget(positiveColorButton);

        positiveLabel = new QLabel(CubeDataConfigurator);
        positiveLabel->setObjectName(QStringLiteral("positiveLabel"));

        horizontalLayout_4->addWidget(positiveLabel);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);

        cancelButton = new QPushButton(CubeDataConfigurator);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setAutoDefault(false);

        horizontalLayout_8->addWidget(cancelButton);

        calculateButton = new QPushButton(CubeDataConfigurator);
        calculateButton->setObjectName(QStringLiteral("calculateButton"));

        horizontalLayout_8->addWidget(calculateButton);


        verticalLayout->addLayout(horizontalLayout_8);


        retranslateUi(CubeDataConfigurator);
        QObject::connect(cancelButton, SIGNAL(clicked()), CubeDataConfigurator, SLOT(close()));

        calculateButton->setDefault(true);


        QMetaObject::connectSlotsByName(CubeDataConfigurator);
    } // setupUi

    void retranslateUi(QDialog *CubeDataConfigurator)
    {
        CubeDataConfigurator->setWindowTitle(QApplication::translate("CubeDataConfigurator", "Add Surface", Q_NULLPTR));
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
"", Q_NULLPTR));
        label_3->setText(QApplication::translate("CubeDataConfigurator", "Isosurface Value:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        signedButton->setToolTip(QApplication::translate("CubeDataConfigurator", "A signed surface will disply both the \n"
"positive and negative isosurfaces.  \n"
"Uncheck if only one surface is desired.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        signedButton->setText(QApplication::translate("CubeDataConfigurator", "Signed", Q_NULLPTR));
        simplifyMeshCheckBox->setText(QApplication::translate("CubeDataConfigurator", "Simplify Mesh", Q_NULLPTR));
        label_12->setText(QApplication::translate("CubeDataConfigurator", "Colors: ", Q_NULLPTR));
        negativeColorButton->setText(QString());
        negativeLabel->setText(QApplication::translate("CubeDataConfigurator", "Negative", Q_NULLPTR));
        positiveColorButton->setText(QString());
        positiveLabel->setText(QApplication::translate("CubeDataConfigurator", "Positive", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("CubeDataConfigurator", "Cancel", Q_NULLPTR));
        calculateButton->setText(QApplication::translate("CubeDataConfigurator", "Calculate", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CubeDataConfigurator: public Ui_CubeDataConfigurator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUBEDATACONFIGURATOR_H
