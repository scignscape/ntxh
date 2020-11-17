/********************************************************************************
** Form generated from reading UI file 'LogMessageDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGMESSAGEDIALOG_H
#define UI_LOGMESSAGEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogMessageDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTextBrowser *logTextBrowser;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *filterCombo;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;

    void setupUi(QWidget *LogMessageDialog)
    {
        if (LogMessageDialog->objectName().isEmpty())
            LogMessageDialog->setObjectName(QString::fromUtf8("LogMessageDialog"));
        LogMessageDialog->resize(742, 268);
        verticalLayout = new QVBoxLayout(LogMessageDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        logTextBrowser = new QTextBrowser(LogMessageDialog);
        logTextBrowser->setObjectName(QString::fromUtf8("logTextBrowser"));

        verticalLayout->addWidget(logTextBrowser);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(LogMessageDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        filterCombo = new QComboBox(LogMessageDialog);
        filterCombo->addItem(QString());
        filterCombo->addItem(QString());
        filterCombo->addItem(QString());
        filterCombo->addItem(QString());
        filterCombo->addItem(QString());
        filterCombo->addItem(QString());
        filterCombo->setObjectName(QString::fromUtf8("filterCombo"));

        horizontalLayout->addWidget(filterCombo);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closeButton = new QPushButton(LogMessageDialog);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        horizontalLayout->addWidget(closeButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(LogMessageDialog);
        QObject::connect(closeButton, SIGNAL(clicked()), LogMessageDialog, SLOT(close()));

        filterCombo->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(LogMessageDialog);
    } // setupUi

    void retranslateUi(QWidget *LogMessageDialog)
    {
        LogMessageDialog->setWindowTitle(QApplication::translate("LogMessageDialog", "IQmol Log Messages", nullptr));
        label->setText(QApplication::translate("LogMessageDialog", "Filter", nullptr));
        filterCombo->setItemText(0, QApplication::translate("LogMessageDialog", "Trace", nullptr));
        filterCombo->setItemText(1, QApplication::translate("LogMessageDialog", "Debug", nullptr));
        filterCombo->setItemText(2, QApplication::translate("LogMessageDialog", "Info", nullptr));
        filterCombo->setItemText(3, QApplication::translate("LogMessageDialog", "Warn", nullptr));
        filterCombo->setItemText(4, QApplication::translate("LogMessageDialog", "Error", nullptr));
        filterCombo->setItemText(5, QApplication::translate("LogMessageDialog", "Fatal", nullptr));

        closeButton->setText(QApplication::translate("LogMessageDialog", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogMessageDialog: public Ui_LogMessageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGMESSAGEDIALOG_H
