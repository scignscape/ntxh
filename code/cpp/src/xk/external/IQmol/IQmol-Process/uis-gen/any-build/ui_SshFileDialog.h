/********************************************************************************
** Form generated from reading UI file 'SshFileDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SSHFILEDIALOG_H
#define UI_SSHFILEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SshFileDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *publicKey;
    QLabel *label_3;
    QLineEdit *privateKey;
    QLabel *label_2;
    QLineEdit *knownHosts;
    QLabel *label;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SshFileDialog)
    {
        if (SshFileDialog->objectName().isEmpty())
            SshFileDialog->setObjectName(QString::fromUtf8("SshFileDialog"));
        SshFileDialog->resize(397, 152);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SshFileDialog->sizePolicy().hasHeightForWidth());
        SshFileDialog->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(SshFileDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        publicKey = new QLineEdit(SshFileDialog);
        publicKey->setObjectName(QString::fromUtf8("publicKey"));

        gridLayout->addWidget(publicKey, 2, 1, 1, 1);

        label_3 = new QLabel(SshFileDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        privateKey = new QLineEdit(SshFileDialog);
        privateKey->setObjectName(QString::fromUtf8("privateKey"));

        gridLayout->addWidget(privateKey, 1, 1, 1, 1);

        label_2 = new QLabel(SshFileDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        knownHosts = new QLineEdit(SshFileDialog);
        knownHosts->setObjectName(QString::fromUtf8("knownHosts"));

        gridLayout->addWidget(knownHosts, 0, 1, 1, 1);

        label = new QLabel(SshFileDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(SshFileDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(SshFileDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SshFileDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SshFileDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SshFileDialog);
    } // setupUi

    void retranslateUi(QDialog *SshFileDialog)
    {
        SshFileDialog->setWindowTitle(QApplication::translate("SshFileDialog", "SSH File Locations", nullptr));
#ifndef QT_NO_TOOLTIP
        publicKey->setToolTip(QApplication::translate("SshFileDialog", "Location of the SSH public key file.  Typically this is the \n"
"same file name as for the private key, but with .pub \n"
"appended.", nullptr));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("SshFileDialog", "Public Key", nullptr));
#ifndef QT_NO_TOOLTIP
        privateKey->setToolTip(QApplication::translate("SshFileDialog", "Location of the SSH identity file.  For protocol 1 this is usually \n"
"located in $HOME/.ssh/identity. For protocol 2 this is usually \n"
"located in either $HOME/.ssh/id_rsa or $HOME/.ssh/id_dsa.", nullptr));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("SshFileDialog", "Private Key", nullptr));
#ifndef QT_NO_TOOLTIP
        knownHosts->setToolTip(QApplication::translate("SshFileDialog", "This is the location of the known_hosts file.\n"
"Typically this is in $HOME/.ssh/known_hosts", nullptr));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("SshFileDialog", "Known Hosts", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SshFileDialog: public Ui_SshFileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SSHFILEDIALOG_H