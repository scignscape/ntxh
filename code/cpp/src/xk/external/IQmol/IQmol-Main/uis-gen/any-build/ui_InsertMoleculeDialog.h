/********************************************************************************
** Form generated from reading UI file 'InsertMoleculeDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTMOLECULEDIALOG_H
#define UI_INSERTMOLECULEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
            InsertMoleculeDialog->setObjectName(QStringLiteral("InsertMoleculeDialog"));
        InsertMoleculeDialog->resize(431, 146);
        verticalLayout = new QVBoxLayout(InsertMoleculeDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(InsertMoleculeDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        identifier = new QLineEdit(InsertMoleculeDialog);
        identifier->setObjectName(QStringLiteral("identifier"));

        horizontalLayout->addWidget(identifier);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        smiles = new QRadioButton(InsertMoleculeDialog);
        smiles->setObjectName(QStringLiteral("smiles"));
        smiles->setChecked(true);

        horizontalLayout_2->addWidget(smiles);

        inchi = new QRadioButton(InsertMoleculeDialog);
        inchi->setObjectName(QStringLiteral("inchi"));

        horizontalLayout_2->addWidget(inchi);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        label_2 = new QLabel(InsertMoleculeDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setPointSize(11);
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        buttonBox = new QDialogButtonBox(InsertMoleculeDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
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
        InsertMoleculeDialog->setWindowTitle(QApplication::translate("InsertMoleculeDialog", "Insert Molecule", Q_NULLPTR));
        label->setText(QApplication::translate("InsertMoleculeDialog", "Identifier:", Q_NULLPTR));
        smiles->setText(QApplication::translate("InsertMoleculeDialog", "SMILES", Q_NULLPTR));
        inchi->setText(QApplication::translate("InsertMoleculeDialog", "InChi", Q_NULLPTR));
        label_2->setText(QApplication::translate("InsertMoleculeDialog", "Note: Some structures may not be built correctly.", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InsertMoleculeDialog: public Ui_InsertMoleculeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTMOLECULEDIALOG_H
