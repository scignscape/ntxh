/********************************************************************************
** Form generated from reading UI file 'MullikenDecompositionsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULLIKENDECOMPOSITIONSDIALOG_H
#define UI_MULLIKENDECOMPOSITIONSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MullikenDecompositionsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *decompositionTable;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *MullikenDecompositionsDialog)
    {
        if (MullikenDecompositionsDialog->objectName().isEmpty())
            MullikenDecompositionsDialog->setObjectName(QString::fromUtf8("MullikenDecompositionsDialog"));
        MullikenDecompositionsDialog->resize(643, 485);
        verticalLayout = new QVBoxLayout(MullikenDecompositionsDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(MullikenDecompositionsDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        decompositionTable = new QTableWidget(MullikenDecompositionsDialog);
        decompositionTable->setObjectName(QString::fromUtf8("decompositionTable"));

        verticalLayout->addWidget(decompositionTable);

        buttonBox = new QDialogButtonBox(MullikenDecompositionsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(MullikenDecompositionsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), MullikenDecompositionsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MullikenDecompositionsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(MullikenDecompositionsDialog);
    } // setupUi

    void retranslateUi(QDialog *MullikenDecompositionsDialog)
    {
        MullikenDecompositionsDialog->setWindowTitle(QApplication::translate("MullikenDecompositionsDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("MullikenDecompositionsDialog", "Decompositions", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MullikenDecompositionsDialog: public Ui_MullikenDecompositionsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULLIKENDECOMPOSITIONSDIALOG_H
