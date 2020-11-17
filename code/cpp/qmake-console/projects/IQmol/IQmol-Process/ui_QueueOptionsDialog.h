/********************************************************************************
** Form generated from reading UI file 'QueueOptionsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUEUEOPTIONSDIALOG_H
#define UI_QUEUEOPTIONSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QueueOptionsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLineEdit *query;
    QLabel *label_7;
    QLabel *label_4;
    QLabel *label_2;
    QLineEdit *submit;
    QLineEdit *kill;
    QLabel *queueInfoLabel;
    QLineEdit *queueInfo;
    QLabel *label;
    QLineEdit *jobFileList;
    QGroupBox *runFileGroupBox;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *runFileTemplate;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QSpinBox *updateInterval;
    QLabel *jobLimitLabel;
    QSpinBox *jobLimit;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QueueOptionsDialog)
    {
        if (QueueOptionsDialog->objectName().isEmpty())
            QueueOptionsDialog->setObjectName(QString::fromUtf8("QueueOptionsDialog"));
        QueueOptionsDialog->resize(483, 462);
        QueueOptionsDialog->setStyleSheet(QString::fromUtf8(" QToolTip {\n"
"    border: 2px solid darkkhaki;\n"
"    padding: 2px;\n"
"    border-radius: 3px;\n"
"    opacity: 500;\n"
"    font-size: 12px;\n"
"    color: #000;\n"
"    background-color: #EEE;\n"
"}"));
        verticalLayout = new QVBoxLayout(QueueOptionsDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(QueueOptionsDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        query = new QLineEdit(groupBox);
        query->setObjectName(QString::fromUtf8("query"));

        gridLayout_2->addWidget(query, 1, 1, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 1, 0, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        submit = new QLineEdit(groupBox);
        submit->setObjectName(QString::fromUtf8("submit"));

        gridLayout_2->addWidget(submit, 0, 1, 1, 1);

        kill = new QLineEdit(groupBox);
        kill->setObjectName(QString::fromUtf8("kill"));

        gridLayout_2->addWidget(kill, 3, 1, 1, 1);

        queueInfoLabel = new QLabel(groupBox);
        queueInfoLabel->setObjectName(QString::fromUtf8("queueInfoLabel"));

        gridLayout_2->addWidget(queueInfoLabel, 5, 0, 1, 1);

        queueInfo = new QLineEdit(groupBox);
        queueInfo->setObjectName(QString::fromUtf8("queueInfo"));

        gridLayout_2->addWidget(queueInfo, 5, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 4, 0, 1, 1);

        jobFileList = new QLineEdit(groupBox);
        jobFileList->setObjectName(QString::fromUtf8("jobFileList"));

        gridLayout_2->addWidget(jobFileList, 4, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        runFileGroupBox = new QGroupBox(QueueOptionsDialog);
        runFileGroupBox->setObjectName(QString::fromUtf8("runFileGroupBox"));
        verticalLayout_2 = new QVBoxLayout(runFileGroupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        runFileTemplate = new QTextEdit(runFileGroupBox);
        runFileTemplate->setObjectName(QString::fromUtf8("runFileTemplate"));

        verticalLayout_2->addWidget(runFileTemplate);


        verticalLayout->addWidget(runFileGroupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(QueueOptionsDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        updateInterval = new QSpinBox(QueueOptionsDialog);
        updateInterval->setObjectName(QString::fromUtf8("updateInterval"));
        updateInterval->setMinimum(5);
        updateInterval->setMaximum(999);
        updateInterval->setSingleStep(5);
        updateInterval->setValue(10);

        horizontalLayout->addWidget(updateInterval);

        jobLimitLabel = new QLabel(QueueOptionsDialog);
        jobLimitLabel->setObjectName(QString::fromUtf8("jobLimitLabel"));

        horizontalLayout->addWidget(jobLimitLabel);

        jobLimit = new QSpinBox(QueueOptionsDialog);
        jobLimit->setObjectName(QString::fromUtf8("jobLimit"));
        jobLimit->setMinimum(0);
        jobLimit->setMaximum(1024);

        horizontalLayout->addWidget(jobLimit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(QueueOptionsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

        QWidget::setTabOrder(buttonBox, submit);
        QWidget::setTabOrder(submit, query);
        QWidget::setTabOrder(query, kill);
        QWidget::setTabOrder(kill, runFileTemplate);
        QWidget::setTabOrder(runFileTemplate, updateInterval);
        QWidget::setTabOrder(updateInterval, jobLimit);

        retranslateUi(QueueOptionsDialog);
        QObject::connect(buttonBox, SIGNAL(rejected()), QueueOptionsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(QueueOptionsDialog);
    } // setupUi

    void retranslateUi(QDialog *QueueOptionsDialog)
    {
        QueueOptionsDialog->setWindowTitle(QApplication::translate("QueueOptionsDialog", "Queue Options", nullptr));
        groupBox->setTitle(QApplication::translate("QueueOptionsDialog", "Commands", nullptr));
        label_7->setText(QApplication::translate("QueueOptionsDialog", "Query", nullptr));
        label_4->setText(QApplication::translate("QueueOptionsDialog", "Kill", nullptr));
        label_2->setText(QApplication::translate("QueueOptionsDialog", "Submit", nullptr));
        queueInfoLabel->setText(QApplication::translate("QueueOptionsDialog", "Queue Info", nullptr));
        label->setText(QApplication::translate("QueueOptionsDialog", "Job File List", nullptr));
        runFileGroupBox->setTitle(QApplication::translate("QueueOptionsDialog", "Run File Template", nullptr));
        runFileTemplate->setHtml(QApplication::translate("QueueOptionsDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Lucida Grande'; font-size:13pt;\"><br /></span></p></body></html>", nullptr));
        label_3->setText(QApplication::translate("QueueOptionsDialog", "Update Interval", nullptr));
        updateInterval->setSuffix(QApplication::translate("QueueOptionsDialog", " s", nullptr));
        jobLimitLabel->setText(QApplication::translate("QueueOptionsDialog", "Job Limit", nullptr));
#ifndef QT_NO_TOOLTIP
        jobLimit->setToolTip(QApplication::translate("QueueOptionsDialog", "Maximum number of concurrent jobs.\n"
"Note this is ignored on PBS servers.", nullptr));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class QueueOptionsDialog: public Ui_QueueOptionsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUEUEOPTIONSDIALOG_H
