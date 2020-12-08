/********************************************************************************
** Form generated from reading UI file 'VectorConstraintConfigurator.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VECTORCONSTRAINTCONFIGURATOR_H
#define UI_VECTORCONSTRAINTCONFIGURATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
            VectorConstraintConfigurator->setObjectName(QStringLiteral("VectorConstraintConfigurator"));
        VectorConstraintConfigurator->resize(389, 158);
        verticalLayout_2 = new QVBoxLayout(VectorConstraintConfigurator);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(VectorConstraintConfigurator);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        xLabel = new QLabel(VectorConstraintConfigurator);
        xLabel->setObjectName(QStringLiteral("xLabel"));

        horizontalLayout_3->addWidget(xLabel);

        xValue = new QDoubleSpinBox(VectorConstraintConfigurator);
        xValue->setObjectName(QStringLiteral("xValue"));
        xValue->setDecimals(3);
        xValue->setMinimum(-100);
        xValue->setMaximum(100);
        xValue->setSingleStep(0.01);

        horizontalLayout_3->addWidget(xValue);

        yLabel = new QLabel(VectorConstraintConfigurator);
        yLabel->setObjectName(QStringLiteral("yLabel"));

        horizontalLayout_3->addWidget(yLabel);

        yValue = new QDoubleSpinBox(VectorConstraintConfigurator);
        yValue->setObjectName(QStringLiteral("yValue"));
        yValue->setDecimals(3);
        yValue->setMinimum(-100);
        yValue->setMaximum(100);
        yValue->setSingleStep(0.01);

        horizontalLayout_3->addWidget(yValue);

        zLabel = new QLabel(VectorConstraintConfigurator);
        zLabel->setObjectName(QStringLiteral("zLabel"));

        horizontalLayout_3->addWidget(zLabel);

        zValue = new QDoubleSpinBox(VectorConstraintConfigurator);
        zValue->setObjectName(QStringLiteral("zValue"));
        zValue->setDecimals(3);
        zValue->setMinimum(-100);
        zValue->setMaximum(100);
        zValue->setSingleStep(0.01);

        horizontalLayout_3->addWidget(zValue);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        radioButton = new QRadioButton(VectorConstraintConfigurator);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        horizontalLayout_2->addWidget(radioButton);

        constrainButton = new QRadioButton(VectorConstraintConfigurator);
        constrainButton->setObjectName(QStringLiteral("constrainButton"));

        horizontalLayout_2->addWidget(constrainButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        deleteButton = new QPushButton(VectorConstraintConfigurator);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));

        horizontalLayout->addWidget(deleteButton);

        horizontalSpacer_2 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        cancelButton = new QPushButton(VectorConstraintConfigurator);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);

        applyButton = new QPushButton(VectorConstraintConfigurator);
        applyButton->setObjectName(QStringLiteral("applyButton"));

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
        VectorConstraintConfigurator->setWindowTitle(QApplication::translate("VectorConstraintConfigurator", "Set Position", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        VectorConstraintConfigurator->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("VectorConstraintConfigurator", "Set position of atom 1:", Q_NULLPTR));
        xLabel->setText(QApplication::translate("VectorConstraintConfigurator", "X", Q_NULLPTR));
        xValue->setSuffix(QString());
        yLabel->setText(QApplication::translate("VectorConstraintConfigurator", "Y", Q_NULLPTR));
        yValue->setSuffix(QString());
        zLabel->setText(QApplication::translate("VectorConstraintConfigurator", "Z", Q_NULLPTR));
        zValue->setSuffix(QString());
        radioButton->setText(QApplication::translate("VectorConstraintConfigurator", "Set", Q_NULLPTR));
        constrainButton->setText(QApplication::translate("VectorConstraintConfigurator", "Constrain", Q_NULLPTR));
        deleteButton->setText(QApplication::translate("VectorConstraintConfigurator", "Delete", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("VectorConstraintConfigurator", "Cancel", Q_NULLPTR));
        applyButton->setText(QApplication::translate("VectorConstraintConfigurator", "Set", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VectorConstraintConfigurator: public Ui_VectorConstraintConfigurator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VECTORCONSTRAINTCONFIGURATOR_H
