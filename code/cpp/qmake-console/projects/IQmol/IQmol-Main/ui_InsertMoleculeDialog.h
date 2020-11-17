/********************************************************************************
** Form generated from reading UI file 'InsertMoleculeDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTMOLECULEDIALOG_H
#define UI_INSERTMOLECULEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_InsertMoleculeDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *identifier;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *smiles;
    QRadioButton *inchi;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *InsertMoleculeDialog)
    {
        if (InsertMoleculeDialog->objectName().isEmpty())
            InsertMoleculeDialog->setObjectName(QString::fromUtf8("InsertMoleculeDialog"));
        InsertMoleculeDialog->resize(431, 146);
        verticalLayout = new QVBoxLayout(InsertMoleculeDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(InsertMoleculeDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        identifier = new QLineEdit(InsertMoleculeDialog);
        identifier->setObjectName(QString::fromUtf8("identifier"));

        horizontalLayout->addWidget(identifier);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        smiles = new QRadioButton(InsertMoleculeDialog);
        smiles->setObjectName(QString::fromUtf8("smiles"));
        smiles->setChecked(true);

        horizontalLayout_2->addWidget(smiles);

        inchi = new QRadioButton(InsertMoleculeDialog);
        inchi->setObjectName(QString::fromUtf8("inchi"));

        horizontalLayout_2->addWidget(inchi);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        label_2 = new QLabel(InsertMoleculeDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setPointSize(11);
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        buttonBox = new QDialogButtonBox(InsertMoleculeDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(InsertMoleculeDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), InsertMoleculeDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), InsertMoleculeDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(InsertMoleculeDialog);
    } // setupUi

    void retranslateUi(QDialog *InsertMoleculeDialog)
    {
        InsertMoleculeDialog->setWindowTitle(QApplication::translate("InsertMoleculeDialog", "Insert Molecule", nullptr));
        label->setText(QApplication::translate("InsertMoleculeDialog", "Identifier:", nullptr));
        smiles->setText(QApplication::translate("InsertMoleculeDialog", "SMILES", nullptr));
        inchi->setText(QApplication::translate("InsertMoleculeDialog", "InChi", nullptr));
        label_2->setText(QApplication::translate("InsertMoleculeDialog", "Note: Some structures may not be built correctly.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InsertMoleculeDialog: public Ui_InsertMoleculeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTMOLECULEDIALOG_H
