/********************************************************************************
** Form generated from reading UI file 'MullikenDecompositionsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULLIKENDECOMPOSITIONSDIALOG_H
#define UI_MULLIKENDECOMPOSITIONSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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
            MullikenDecompositionsDialog->setObjectName(QStringLiteral("MullikenDecompositionsDialog"));
        MullikenDecompositionsDialog->resize(643, 485);
        verticalLayout = new QVBoxLayout(MullikenDecompositionsDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(MullikenDecompositionsDialog);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        decompositionTable = new QTableWidget(MullikenDecompositionsDialog);
        decompositionTable->setObjectName(QStringLiteral("decompositionTable"));

        verticalLayout->addWidget(decompositionTable);

        buttonBox = new QDialogButtonBox(MullikenDecompositionsDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
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
        MullikenDecompositionsDialog->setWindowTitle(QApplication::translate("MullikenDecompositionsDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("MullikenDecompositionsDialog", "Decompositions", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MullikenDecompositionsDialog: public Ui_MullikenDecompositionsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULLIKENDECOMPOSITIONSDIALOG_H
