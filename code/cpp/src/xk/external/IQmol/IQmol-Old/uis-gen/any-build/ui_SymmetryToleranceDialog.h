/********************************************************************************
** Form generated from reading UI file 'SymmetryToleranceDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYMMETRYTOLERANCEDIALOG_H
#define UI_SYMMETRYTOLERANCEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SymmetryToleranceDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QSlider *toleranceSlider;
    QLabel *symmetryToleranceLabel;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *applyButton;
    QPushButton *resetButton;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SymmetryToleranceDialog)
    {
        if (SymmetryToleranceDialog->objectName().isEmpty())
            SymmetryToleranceDialog->setObjectName(QStringLiteral("SymmetryToleranceDialog"));
        SymmetryToleranceDialog->resize(403, 169);
        verticalLayout = new QVBoxLayout(SymmetryToleranceDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(SymmetryToleranceDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setTextFormat(Qt::RichText);
        label->setWordWrap(true);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        toleranceSlider = new QSlider(SymmetryToleranceDialog);
        toleranceSlider->setObjectName(QStringLiteral("toleranceSlider"));
        toleranceSlider->setMaximum(100);
        toleranceSlider->setPageStep(10);
        toleranceSlider->setValue(10);
        toleranceSlider->setSliderPosition(10);
        toleranceSlider->setOrientation(Qt::Horizontal);
        toleranceSlider->setTickPosition(QSlider::TicksBelow);

        horizontalLayout->addWidget(toleranceSlider);

        symmetryToleranceLabel = new QLabel(SymmetryToleranceDialog);
        symmetryToleranceLabel->setObjectName(QStringLiteral("symmetryToleranceLabel"));

        horizontalLayout->addWidget(symmetryToleranceLabel);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        applyButton = new QPushButton(SymmetryToleranceDialog);
        applyButton->setObjectName(QStringLiteral("applyButton"));

        horizontalLayout_2->addWidget(applyButton);

        resetButton = new QPushButton(SymmetryToleranceDialog);
        resetButton->setObjectName(QStringLiteral("resetButton"));

        horizontalLayout_2->addWidget(resetButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(SymmetryToleranceDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_2->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(SymmetryToleranceDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SymmetryToleranceDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SymmetryToleranceDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SymmetryToleranceDialog);
    } // setupUi

    void retranslateUi(QDialog *SymmetryToleranceDialog)
    {
        SymmetryToleranceDialog->setWindowTitle(QApplication::translate("SymmetryToleranceDialog", "Symmetry Tolerance", Q_NULLPTR));
        label->setText(QApplication::translate("SymmetryToleranceDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Lucida Grande'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Higher values will find more symmetric structures, but may lead to undesired changes in the geometry.</p></body></html>", Q_NULLPTR));
        symmetryToleranceLabel->setText(QApplication::translate("SymmetryToleranceDialog", "0.10", Q_NULLPTR));
        applyButton->setText(QApplication::translate("SymmetryToleranceDialog", "Apply", Q_NULLPTR));
        resetButton->setText(QApplication::translate("SymmetryToleranceDialog", "Reset", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SymmetryToleranceDialog: public Ui_SymmetryToleranceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYMMETRYTOLERANCEDIALOG_H
