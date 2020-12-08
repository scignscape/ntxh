/********************************************************************************
** Form generated from reading UI file 'BoundingBoxDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOUNDINGBOXDIALOG_H
#define UI_BOUNDINGBOXDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BoundingBoxDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label_5;
    QDoubleSpinBox *xMin;
    QLabel *label;
    QDoubleSpinBox *yMin;
    QDoubleSpinBox *zMin;
    QLabel *label_2;
    QLabel *label_3;
    QDoubleSpinBox *zMax;
    QDoubleSpinBox *xMax;
    QDoubleSpinBox *yMax;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *BoundingBoxDialog)
    {
        if (BoundingBoxDialog->objectName().isEmpty())
            BoundingBoxDialog->setObjectName(QStringLiteral("BoundingBoxDialog"));
        BoundingBoxDialog->resize(403, 153);
        verticalLayout = new QVBoxLayout(BoundingBoxDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_4 = new QLabel(BoundingBoxDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        label_5 = new QLabel(BoundingBoxDialog);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        xMin = new QDoubleSpinBox(BoundingBoxDialog);
        xMin->setObjectName(QStringLiteral("xMin"));
        xMin->setDecimals(4);
        xMin->setMinimum(-99.99);

        gridLayout->addWidget(xMin, 1, 1, 1, 1);

        label = new QLabel(BoundingBoxDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 1, 1, 1);

        yMin = new QDoubleSpinBox(BoundingBoxDialog);
        yMin->setObjectName(QStringLiteral("yMin"));
        yMin->setDecimals(4);
        yMin->setMinimum(-99.99);

        gridLayout->addWidget(yMin, 1, 2, 1, 1);

        zMin = new QDoubleSpinBox(BoundingBoxDialog);
        zMin->setObjectName(QStringLiteral("zMin"));
        zMin->setDecimals(4);
        zMin->setMinimum(-99.99);

        gridLayout->addWidget(zMin, 1, 3, 1, 1);

        label_2 = new QLabel(BoundingBoxDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        label_3 = new QLabel(BoundingBoxDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 0, 3, 1, 1);

        zMax = new QDoubleSpinBox(BoundingBoxDialog);
        zMax->setObjectName(QStringLiteral("zMax"));
        zMax->setDecimals(4);
        zMax->setMinimum(-99.99);

        gridLayout->addWidget(zMax, 2, 3, 1, 1);

        xMax = new QDoubleSpinBox(BoundingBoxDialog);
        xMax->setObjectName(QStringLiteral("xMax"));
        xMax->setDecimals(4);
        xMax->setMinimum(-99.99);

        gridLayout->addWidget(xMax, 2, 1, 1, 1);

        yMax = new QDoubleSpinBox(BoundingBoxDialog);
        yMax->setObjectName(QStringLiteral("yMax"));
        yMax->setDecimals(4);
        yMax->setMinimum(-99.99);

        gridLayout->addWidget(yMax, 2, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(BoundingBoxDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

        QWidget::setTabOrder(xMin, yMin);
        QWidget::setTabOrder(yMin, zMin);
        QWidget::setTabOrder(zMin, xMax);
        QWidget::setTabOrder(xMax, yMax);
        QWidget::setTabOrder(yMax, zMax);
        QWidget::setTabOrder(zMax, buttonBox);

        retranslateUi(BoundingBoxDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), BoundingBoxDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), BoundingBoxDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(BoundingBoxDialog);
    } // setupUi

    void retranslateUi(QDialog *BoundingBoxDialog)
    {
        BoundingBoxDialog->setWindowTitle(QApplication::translate("BoundingBoxDialog", "Edit Bounding Box", Q_NULLPTR));
        label_4->setText(QApplication::translate("BoundingBoxDialog", "Minimum", Q_NULLPTR));
        label_5->setText(QApplication::translate("BoundingBoxDialog", "Maximum", Q_NULLPTR));
        label->setText(QApplication::translate("BoundingBoxDialog", "X", Q_NULLPTR));
        label_2->setText(QApplication::translate("BoundingBoxDialog", "Y", Q_NULLPTR));
        label_3->setText(QApplication::translate("BoundingBoxDialog", "Z", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BoundingBoxDialog: public Ui_BoundingBoxDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOUNDINGBOXDIALOG_H
