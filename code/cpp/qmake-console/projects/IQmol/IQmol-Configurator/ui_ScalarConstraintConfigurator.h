/********************************************************************************
** Form generated from reading UI file 'ScalarConstraintConfigurator.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCALARCONSTRAINTCONFIGURATOR_H
#define UI_SCALARCONSTRAINTCONFIGURATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ScalarConstraintConfigurator
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *setButton;
    QRadioButton *constrainButton;
    QRadioButton *scanButton;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QDoubleSpinBox *value;
    QLabel *labelTo;
    QDoubleSpinBox *valueMax;
    QLabel *labelPoints;
    QSpinBox *points;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *deleteButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *cancelButton;
    QPushButton *applyButton;

    void setupUi(QDialog *ScalarConstraintConfigurator)
    {
        if (ScalarConstraintConfigurator->objectName().isEmpty())
            ScalarConstraintConfigurator->setObjectName(QString::fromUtf8("ScalarConstraintConfigurator"));
        ScalarConstraintConfigurator->resize(453, 129);
        verticalLayout = new QVBoxLayout(ScalarConstraintConfigurator);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        setButton = new QRadioButton(ScalarConstraintConfigurator);
        setButton->setObjectName(QString::fromUtf8("setButton"));
        setButton->setChecked(true);

        horizontalLayout_2->addWidget(setButton);

        constrainButton = new QRadioButton(ScalarConstraintConfigurator);
        constrainButton->setObjectName(QString::fromUtf8("constrainButton"));

        horizontalLayout_2->addWidget(constrainButton);

        scanButton = new QRadioButton(ScalarConstraintConfigurator);
        scanButton->setObjectName(QString::fromUtf8("scanButton"));

        horizontalLayout_2->addWidget(scanButton);

        label = new QLabel(ScalarConstraintConfigurator);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        value = new QDoubleSpinBox(ScalarConstraintConfigurator);
        value->setObjectName(QString::fromUtf8("value"));
        value->setDecimals(4);
        value->setSingleStep(0.010000000000000);

        horizontalLayout_4->addWidget(value);

        labelTo = new QLabel(ScalarConstraintConfigurator);
        labelTo->setObjectName(QString::fromUtf8("labelTo"));

        horizontalLayout_4->addWidget(labelTo);

        valueMax = new QDoubleSpinBox(ScalarConstraintConfigurator);
        valueMax->setObjectName(QString::fromUtf8("valueMax"));
        valueMax->setDecimals(4);
        valueMax->setSingleStep(0.010000000000000);

        horizontalLayout_4->addWidget(valueMax);

        labelPoints = new QLabel(ScalarConstraintConfigurator);
        labelPoints->setObjectName(QString::fromUtf8("labelPoints"));

        horizontalLayout_4->addWidget(labelPoints);

        points = new QSpinBox(ScalarConstraintConfigurator);
        points->setObjectName(QString::fromUtf8("points"));
        points->setMinimum(2);
        points->setMaximum(999);

        horizontalLayout_4->addWidget(points);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        deleteButton = new QPushButton(ScalarConstraintConfigurator);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        horizontalLayout_3->addWidget(deleteButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        cancelButton = new QPushButton(ScalarConstraintConfigurator);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout_3->addWidget(cancelButton);

        applyButton = new QPushButton(ScalarConstraintConfigurator);
        applyButton->setObjectName(QString::fromUtf8("applyButton"));

        horizontalLayout_3->addWidget(applyButton);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(ScalarConstraintConfigurator);
        QObject::connect(cancelButton, SIGNAL(clicked()), ScalarConstraintConfigurator, SLOT(reject()));
        QObject::connect(applyButton, SIGNAL(clicked()), ScalarConstraintConfigurator, SLOT(accept()));

        applyButton->setDefault(true);


        QMetaObject::connectSlotsByName(ScalarConstraintConfigurator);
    } // setupUi

    void retranslateUi(QDialog *ScalarConstraintConfigurator)
    {
        ScalarConstraintConfigurator->setWindowTitle(QApplication::translate("ScalarConstraintConfigurator", "Set Value", nullptr));
#ifndef QT_NO_TOOLTIP
        ScalarConstraintConfigurator->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        setButton->setText(QApplication::translate("ScalarConstraintConfigurator", "Set", nullptr));
        constrainButton->setText(QApplication::translate("ScalarConstraintConfigurator", "Constrain", nullptr));
        scanButton->setText(QApplication::translate("ScalarConstraintConfigurator", "Scan", nullptr));
        label->setText(QApplication::translate("ScalarConstraintConfigurator", "Distance between atom 1 and 2: ", nullptr));
        value->setSuffix(QString());
        labelTo->setText(QApplication::translate("ScalarConstraintConfigurator", "To", nullptr));
        labelPoints->setText(QApplication::translate("ScalarConstraintConfigurator", "Points", nullptr));
        deleteButton->setText(QApplication::translate("ScalarConstraintConfigurator", "Delete", nullptr));
        cancelButton->setText(QApplication::translate("ScalarConstraintConfigurator", "Cancel", nullptr));
        applyButton->setText(QApplication::translate("ScalarConstraintConfigurator", "Apply", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScalarConstraintConfigurator: public Ui_ScalarConstraintConfigurator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCALARCONSTRAINTCONFIGURATOR_H
