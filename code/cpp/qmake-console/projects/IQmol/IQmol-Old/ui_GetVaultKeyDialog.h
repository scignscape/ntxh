/********************************************************************************
** Form generated from reading UI file 'GetVaultKeyDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETVAULTKEYDIALOG_H
#define UI_GETVAULTKEYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_GetVaultKeyDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *infoLabel;
    QLineEdit *password;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *GetVaultKeyDialog)
    {
        if (GetVaultKeyDialog->objectName().isEmpty())
            GetVaultKeyDialog->setObjectName(QString::fromUtf8("GetVaultKeyDialog"));
        GetVaultKeyDialog->resize(226, 123);
        verticalLayout = new QVBoxLayout(GetVaultKeyDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        infoLabel = new QLabel(GetVaultKeyDialog);
        infoLabel->setObjectName(QString::fromUtf8("infoLabel"));

        verticalLayout->addWidget(infoLabel);

        password = new QLineEdit(GetVaultKeyDialog);
        password->setObjectName(QString::fromUtf8("password"));
        password->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(password);

        buttonBox = new QDialogButtonBox(GetVaultKeyDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(GetVaultKeyDialog);
        QObject::connect(buttonBox, SIGNAL(rejected()), GetVaultKeyDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(GetVaultKeyDialog);
    } // setupUi

    void retranslateUi(QDialog *GetVaultKeyDialog)
    {
        GetVaultKeyDialog->setWindowTitle(QApplication::translate("GetVaultKeyDialog", "Enter Key", nullptr));
        infoLabel->setText(QApplication::translate("GetVaultKeyDialog", "Enter Password Vault key:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GetVaultKeyDialog: public Ui_GetVaultKeyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETVAULTKEYDIALOG_H
