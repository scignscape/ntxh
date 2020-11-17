/********************************************************************************
** Form generated from reading UI file 'VectorConstraintConfigurator.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VECTORCONSTRAINTCONFIGURATOR_H
#define UI_VECTORCONSTRAINTCONFIGURATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_VectorConstraintConfigurator
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QLabel *xLabel;
    QDoubleSpinBox *xValue;
    QLabel *yLabel;
    QDoubleSpinBox *yValue;
    QLabel *zLabel;
    QDoubleSpinBox *zValue;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton;
    QRadioButton *constrainButton;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *deleteButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *cancelButton;
    QPushButton *applyButton;

    void setupUi(QDialog *VectorConstraintConfigurator)
    {
        if (VectorConstraintConfigurator->objectName().isEmpty())
            VectorConstraintConfigurator->setObjectName(QString::fromUtf8("VectorConstraintConfigurator"));
        VectorConstraintConfigurator->resize(389, 158);
        verticalLayout_2 = new QVBoxLayout(VectorConstraintConfigurator);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(VectorConstraintConfigurator);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        xLabel = new QLabel(VectorConstraintConfigurator);
        xLabel->setObjectName(QString::fromUtf8("xLabel"));

        horizontalLayout_3->addWidget(xLabel);

        xValue = new QDoubleSpinBox(VectorConstraintConfigurator);
        xValue->setObjectName(QString::fromUtf8("xValue"));
        xValue->setDecimals(3);
        xValue->setMinimum(-100.000000000000000);
        xValue->setMaximum(100.000000000000000);
        xValue->setSingleStep(0.010000000000000);

        horizontalLayout_3->addWidget(xValue);

        yLabel = new QLabel(VectorConstraintConfigurator);
        yLabel->setObjectName(QString::fromUtf8("yLabel"));

        horizontalLayout_3->addWidget(yLabel);

        yValue = new QDoubleSpinBox(VectorConstraintConfigurator);
        yValue->setObjectName(QString::fromUtf8("yValue"));
        yValue->setDecimals(3);
        yValue->setMinimum(-100.000000000000000);
        yValue->setMaximum(100.000000000000000);
        yValue->setSingleStep(0.010000000000000);

        horizontalLayout_3->addWidget(yValue);

        zLabel = new QLabel(VectorConstraintConfigurator);
        zLabel->setObjectName(QString::fromUtf8("zLabel"));

        horizontalLayout_3->addWidget(zLabel);

        zValue = new QDoubleSpinBox(VectorConstraintConfigurator);
        zValue->setObjectName(QString::fromUtf8("zValue"));
        zValue->setDecimals(3);
        zValue->setMinimum(-100.000000000000000);
        zValue->setMaximum(100.000000000000000);
        zValue->setSingleStep(0.010000000000000);

        horizontalLayout_3->addWidget(zValue);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        radioButton = new QRadioButton(VectorConstraintConfigurator);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        horizontalLayout_2->addWidget(radioButton);

        constrainButton = new QRadioButton(VectorConstraintConfigurator);
        constrainButton->setObjectName(QString::fromUtf8("constrainButton"));

        horizontalLayout_2->addWidget(constrainButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        deleteButton = new QPushButton(VectorConstraintConfigurator);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        horizontalLayout->addWidget(deleteButton);

        horizontalSpacer_2 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        cancelButton = new QPushButton(VectorConstraintConfigurator);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout->addWidget(cancelButton);

        applyButton = new QPushButton(VectorConstraintConfigurator);
        applyButton->setObjectName(QString::fromUtf8("applyButton"));

        horizontalLayout->addWidget(applyButton);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(VectorConstraintConfigurator);
        QObject::connect(applyButton, SIGNAL(clicked()), VectorConstraintConfigurator, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), VectorConstraintConfigurator, SLOT(reject()));

        applyButton->setDefault(true);


        QMetaObject::connectSlotsByName(VectorConstraintConfigurator);
    } // setupUi

    void retranslateUi(QDialog *VectorConstraintConfigurator)
    {
        VectorConstraintConfigurator->setWindowTitle(QApplication::translate("VectorConstraintConfigurator", "Set Position", nullptr));
#ifndef QT_NO_TOOLTIP
        VectorConstraintConfigurator->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("VectorConstraintConfigurator", "Set position of atom 1:", nullptr));
        xLabel->setText(QApplication::translate("VectorConstraintConfigurator", "X", nullptr));
        xValue->setSuffix(QString());
        yLabel->setText(QApplication::translate("VectorConstraintConfigurator", "Y", nullptr));
        yValue->setSuffix(QString());
        zLabel->setText(QApplication::translate("VectorConstraintConfigurator", "Z", nullptr));
        zValue->setSuffix(QString());
        radioButton->setText(QApplication::translate("VectorConstraintConfigurator", "Set", nullptr));
        constrainButton->setText(QApplication::translate("VectorConstraintConfigurator", "Constrain", nullptr));
        deleteButton->setText(QApplication::translate("VectorConstraintConfigurator", "Delete", nullptr));
        cancelButton->setText(QApplication::translate("VectorConstraintConfigurator", "Cancel", nullptr));
        applyButton->setText(QApplication::translate("VectorConstraintConfigurator", "Set", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VectorConstraintConfigurator: public Ui_VectorConstraintConfigurator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VECTORCONSTRAINTCONFIGURATOR_H
