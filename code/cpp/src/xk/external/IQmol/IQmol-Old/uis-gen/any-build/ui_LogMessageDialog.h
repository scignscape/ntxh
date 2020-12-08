/********************************************************************************
** Form generated from reading UI file 'LogMessageDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGMESSAGEDIALOG_H
#define UI_LOGMESSAGEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
            LogMessageDialog->setObjectName(QStringLiteral("LogMessageDialog"));
        LogMessageDialog->resize(742, 268);
        verticalLayout = new QVBoxLayout(LogMessageDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        logTextBrowser = new QTextBrowser(LogMessageDialog);
        logTextBrowser->setObjectName(QStringLiteral("logTextBrowser"));

        verticalLayout->addWidget(logTextBrowser);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(LogMessageDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        filterCombo = new QComboBox(LogMessageDialog);
        filterCombo->setObjectName(QStringLiteral("filterCombo"));

        horizontalLayout->addWidget(filterCombo);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closeButton = new QPushButton(LogMessageDialog);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        horizontalLayout->addWidget(closeButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(LogMessageDialog);
        QObject::connect(closeButton, SIGNAL(clicked()), LogMessageDialog, SLOT(close()));

        filterCombo->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(LogMessageDialog);
    } // setupUi

    void retranslateUi(QWidget *LogMessageDialog)
    {
        LogMessageDialog->setWindowTitle(QApplication::translate("LogMessageDialog", "IQmol Log Messages", Q_NULLPTR));
        label->setText(QApplication::translate("LogMessageDialog", "Filter", Q_NULLPTR));
        filterCombo->clear();
        filterCombo->insertItems(0, QStringList()
         << QApplication::translate("LogMessageDialog", "Trace", Q_NULLPTR)
         << QApplication::translate("LogMessageDialog", "Debug", Q_NULLPTR)
         << QApplication::translate("LogMessageDialog", "Info", Q_NULLPTR)
         << QApplication::translate("LogMessageDialog", "Warn", Q_NULLPTR)
         << QApplication::translate("LogMessageDialog", "Error", Q_NULLPTR)
         << QApplication::translate("LogMessageDialog", "Fatal", Q_NULLPTR)
        );
        closeButton->setText(QApplication::translate("LogMessageDialog", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LogMessageDialog: public Ui_LogMessageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGMESSAGEDIALOG_H
