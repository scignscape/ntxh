/********************************************************************************
** Form generated from reading UI file 'MolecularSurfacesConfigurator.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOLECULARSURFACESCONFIGURATOR_H
#define UI_MOLECULARSURFACESCONFIGURATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_MolecularSurfacesConfigurator
{
public:
    QHBoxLayout *horizontalLayout_5;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *negativeColorButton;
    QLabel *negativeLabel;
    QToolButton *positiveColorButton;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *cancelButton;
    QPushButton *calculateButton;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout;
    QComboBox *surfaceType;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_7;
    QSlider *opacity;
    QHBoxLayout *horizontalLayout_3;
    QDoubleSpinBox *isovalue;
    QCheckBox *simplifyMeshCheckBox;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QSlider *quality;
    QLabel *label_6;
    QLabel *isovalueLabel;
    QLabel *label_7;

    void setupUi(QDialog *MolecularSurfacesConfigurator)
    {
        if (MolecularSurfacesConfigurator->objectName().isEmpty())
            MolecularSurfacesConfigurator->setObjectName(QString::fromUtf8("MolecularSurfacesConfigurator"));
        MolecularSurfacesConfigurator->resize(356, 261);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MolecularSurfacesConfigurator->sizePolicy().hasHeightForWidth());
        MolecularSurfacesConfigurator->setSizePolicy(sizePolicy);
        horizontalLayout_5 = new QHBoxLayout(MolecularSurfacesConfigurator);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        negativeColorButton = new QToolButton(MolecularSurfacesConfigurator);
        negativeColorButton->setObjectName(QString::fromUtf8("negativeColorButton"));
        negativeColorButton->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"   background-color: rgb(255, 0, 0);\n"
"}"));
        negativeColorButton->setIconSize(QSize(32, 16));

        horizontalLayout_4->addWidget(negativeColorButton);

        negativeLabel = new QLabel(MolecularSurfacesConfigurator);
        negativeLabel->setObjectName(QString::fromUtf8("negativeLabel"));

        horizontalLayout_4->addWidget(negativeLabel);

        positiveColorButton = new QToolButton(MolecularSurfacesConfigurator);
        positiveColorButton->setObjectName(QString::fromUtf8("positiveColorButton"));
        positiveColorButton->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"   background-color: rgb(0, 0, 255);\n"
"}"));
        positiveColorButton->setIconSize(QSize(32, 16));

        horizontalLayout_4->addWidget(positiveColorButton);

        label_9 = new QLabel(MolecularSurfacesConfigurator);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_4->addWidget(label_9);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);


        gridLayout_2->addLayout(horizontalLayout_4, 3, 1, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);

        cancelButton = new QPushButton(MolecularSurfacesConfigurator);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setAutoDefault(false);

        horizontalLayout_8->addWidget(cancelButton);

        calculateButton = new QPushButton(MolecularSurfacesConfigurator);
        calculateButton->setObjectName(QString::fromUtf8("calculateButton"));

        horizontalLayout_8->addWidget(calculateButton);


        gridLayout_2->addLayout(horizontalLayout_8, 6, 0, 1, 2);

        label_4 = new QLabel(MolecularSurfacesConfigurator);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 2, 0, 1, 1);

        label = new QLabel(MolecularSurfacesConfigurator);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 4, 0, 1, 1);

        label_12 = new QLabel(MolecularSurfacesConfigurator);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_2->addWidget(label_12, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        surfaceType = new QComboBox(MolecularSurfacesConfigurator);
        surfaceType->setObjectName(QString::fromUtf8("surfaceType"));

        horizontalLayout->addWidget(surfaceType);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout_2->addLayout(horizontalLayout, 0, 1, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        opacity = new QSlider(MolecularSurfacesConfigurator);
        opacity->setObjectName(QString::fromUtf8("opacity"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(opacity->sizePolicy().hasHeightForWidth());
        opacity->setSizePolicy(sizePolicy1);
        opacity->setMinimumSize(QSize(78, 0));
        opacity->setMaximum(100);
        opacity->setValue(50);
        opacity->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(opacity);


        gridLayout_2->addLayout(horizontalLayout_7, 4, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        isovalue = new QDoubleSpinBox(MolecularSurfacesConfigurator);
        isovalue->setObjectName(QString::fromUtf8("isovalue"));
        isovalue->setDecimals(4);
        isovalue->setMinimum(0.000400000000000);
        isovalue->setMaximum(99.998999999999995);
        isovalue->setSingleStep(0.001000000000000);
        isovalue->setValue(0.020000000000000);

        horizontalLayout_3->addWidget(isovalue);

        simplifyMeshCheckBox = new QCheckBox(MolecularSurfacesConfigurator);
        simplifyMeshCheckBox->setObjectName(QString::fromUtf8("simplifyMeshCheckBox"));
        simplifyMeshCheckBox->setChecked(true);

        horizontalLayout_3->addWidget(simplifyMeshCheckBox);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        gridLayout_2->addLayout(horizontalLayout_3, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 5, 1, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(MolecularSurfacesConfigurator);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_6->addWidget(label_5);

        quality = new QSlider(MolecularSurfacesConfigurator);
        quality->setObjectName(QString::fromUtf8("quality"));
        sizePolicy1.setHeightForWidth(quality->sizePolicy().hasHeightForWidth());
        quality->setSizePolicy(sizePolicy1);
        quality->setMinimum(1);
        quality->setMaximum(7);
        quality->setSingleStep(1);
        quality->setPageStep(1);
        quality->setValue(3);
        quality->setOrientation(Qt::Horizontal);
        quality->setTickPosition(QSlider::TicksBelow);
        quality->setTickInterval(1);

        horizontalLayout_6->addWidget(quality);

        label_6 = new QLabel(MolecularSurfacesConfigurator);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);


        gridLayout_2->addLayout(horizontalLayout_6, 2, 1, 1, 1);

        isovalueLabel = new QLabel(MolecularSurfacesConfigurator);
        isovalueLabel->setObjectName(QString::fromUtf8("isovalueLabel"));

        gridLayout_2->addWidget(isovalueLabel, 1, 0, 1, 1);

        label_7 = new QLabel(MolecularSurfacesConfigurator);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(label_7, 0, 0, 1, 1);


        horizontalLayout_5->addLayout(gridLayout_2);

        horizontalLayout_5->setStretch(0, 1);

        retranslateUi(MolecularSurfacesConfigurator);

        calculateButton->setDefault(true);


        QMetaObject::connectSlotsByName(MolecularSurfacesConfigurator);
    } // setupUi

    void retranslateUi(QDialog *MolecularSurfacesConfigurator)
    {
        MolecularSurfacesConfigurator->setWindowTitle(QApplication::translate("MolecularSurfacesConfigurator", "Add Surface", nullptr));
        MolecularSurfacesConfigurator->setStyleSheet(QApplication::translate("MolecularSurfacesConfigurator", "QToolButton {\n"
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
        negativeColorButton->setText(QString());
        negativeLabel->setText(QApplication::translate("MolecularSurfacesConfigurator", "Negative", nullptr));
        positiveColorButton->setText(QString());
        label_9->setText(QApplication::translate("MolecularSurfacesConfigurator", "Positive", nullptr));
        cancelButton->setText(QApplication::translate("MolecularSurfacesConfigurator", "Cancel", nullptr));
        calculateButton->setText(QApplication::translate("MolecularSurfacesConfigurator", "Calculate", nullptr));
        label_4->setText(QApplication::translate("MolecularSurfacesConfigurator", "Quality:", nullptr));
        label->setText(QApplication::translate("MolecularSurfacesConfigurator", "Opacity:", nullptr));
        label_12->setText(QApplication::translate("MolecularSurfacesConfigurator", "Colors: ", nullptr));
        simplifyMeshCheckBox->setText(QApplication::translate("MolecularSurfacesConfigurator", "Simplify Mesh", nullptr));
        label_5->setText(QApplication::translate("MolecularSurfacesConfigurator", "Low", nullptr));
        label_6->setText(QApplication::translate("MolecularSurfacesConfigurator", "High", nullptr));
        isovalueLabel->setText(QApplication::translate("MolecularSurfacesConfigurator", "Isovalue:", nullptr));
        label_7->setText(QApplication::translate("MolecularSurfacesConfigurator", "Type:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MolecularSurfacesConfigurator: public Ui_MolecularSurfacesConfigurator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOLECULARSURFACESCONFIGURATOR_H
