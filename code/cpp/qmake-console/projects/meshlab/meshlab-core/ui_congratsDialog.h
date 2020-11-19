/********************************************************************************
** Form generated from reading UI file 'congratsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONGRATSDIALOG_H
#define UI_CONGRATSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CongratsDialog
{
public:
    QVBoxLayout *vboxLayout;
    QTextBrowser *congratsTextBrowser;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CongratsDialog)
    {
        if (CongratsDialog->objectName().isEmpty())
            CongratsDialog->setObjectName(QString::fromUtf8("CongratsDialog"));
        CongratsDialog->setWindowModality(Qt::ApplicationModal);
        CongratsDialog->resize(641, 449);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CongratsDialog->sizePolicy().hasHeightForWidth());
        CongratsDialog->setSizePolicy(sizePolicy);
        vboxLayout = new QVBoxLayout(CongratsDialog);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        congratsTextBrowser = new QTextBrowser(CongratsDialog);
        congratsTextBrowser->setObjectName(QString::fromUtf8("congratsTextBrowser"));
        congratsTextBrowser->setSource(QUrl(QString::fromUtf8("qrc:/images/100mesh.html")));
        congratsTextBrowser->setOpenExternalLinks(true);

        vboxLayout->addWidget(congratsTextBrowser);

        buttonBox = new QDialogButtonBox(CongratsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel);

        vboxLayout->addWidget(buttonBox);


        retranslateUi(CongratsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CongratsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CongratsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CongratsDialog);
    } // setupUi

    void retranslateUi(QDialog *CongratsDialog)
    {
        CongratsDialog->setWindowTitle(QApplication::translate("CongratsDialog", "MeshLab Congratulations!", nullptr));
        congratsTextBrowser->setHtml(QApplication::translate("CongratsDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Congratulations</span>! <br /><br />You have successfully used MeshLab to open and process more than one hundred meshes!<br />We hope that this means that you have found MeshLab useful.<br /><br />Please consider to send a short email to the developers of MeshLab, describing how MeshLab fitted your needs, attach to the email some screenshots of your processed meshes and tell us your impression about MeshLab. <br /><br />MeshLab is developed on public funding and assessment of its impact on the whole "
                        "community is necessary, so, please, spend a couple of minutes writing down a mail to us (or at least connect with the MeshLab FaceBook page).<br /><br />Thanks for using MeshLab<br /><br />Paolo Cignoni<br /><br /><a href=\"http://www.facebook.com/MeshLab\"><img src=\":images/facebook.gif\" /></a></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CongratsDialog: public Ui_CongratsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONGRATSDIALOG_H
