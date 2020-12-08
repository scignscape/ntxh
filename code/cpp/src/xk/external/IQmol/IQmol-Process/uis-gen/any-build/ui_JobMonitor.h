/********************************************************************************
** Form generated from reading UI file 'JobMonitor.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOBMONITOR_H
#define UI_JOBMONITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JobMonitor
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTableWidget *processTable;
    QHBoxLayout *horizontalLayout;
    QPushButton *clearListButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *JobMonitor)
    {
        if (JobMonitor->objectName().isEmpty())
            JobMonitor->setObjectName(QStringLiteral("JobMonitor"));
        JobMonitor->resize(589, 298);
        JobMonitor->setStyleSheet(QLatin1String(" QToolTip {\n"
"    border: 2px solid darkkhaki;\n"
"    padding: 2px;\n"
"    border-radius: 3px;\n"
"    opacity: 500;\n"
"    font-size: 12px;\n"
"    color: #000;\n"
"    background-color: #EEE;\n"
"}"));
        centralwidget = new QWidget(JobMonitor);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        processTable = new QTableWidget(centralwidget);
        if (processTable->columnCount() < 5)
            processTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        processTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        processTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        processTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        processTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        processTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        processTable->setObjectName(QStringLiteral("processTable"));
        processTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        processTable->setSelectionMode(QAbstractItemView::SingleSelection);
        processTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        processTable->setShowGrid(false);
        processTable->setGridStyle(Qt::NoPen);
        processTable->setSortingEnabled(true);
        processTable->horizontalHeader()->setCascadingSectionResizes(true);
        processTable->horizontalHeader()->setMinimumSectionSize(30);
        processTable->verticalHeader()->setCascadingSectionResizes(true);

        verticalLayout->addWidget(processTable);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        clearListButton = new QPushButton(centralwidget);
        clearListButton->setObjectName(QStringLiteral("clearListButton"));

        horizontalLayout->addWidget(clearListButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closeButton = new QPushButton(centralwidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        horizontalLayout->addWidget(closeButton);


        verticalLayout->addLayout(horizontalLayout);

        JobMonitor->setCentralWidget(centralwidget);
        menubar = new QMenuBar(JobMonitor);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 589, 22));
        JobMonitor->setMenuBar(menubar);
        statusbar = new QStatusBar(JobMonitor);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        JobMonitor->setStatusBar(statusbar);

        retranslateUi(JobMonitor);
        QObject::connect(closeButton, SIGNAL(clicked()), JobMonitor, SLOT(close()));

        QMetaObject::connectSlotsByName(JobMonitor);
    } // setupUi

    void retranslateUi(QMainWindow *JobMonitor)
    {
        JobMonitor->setWindowTitle(QApplication::translate("JobMonitor", "Job Monitor", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = processTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("JobMonitor", "Job", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = processTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("JobMonitor", "Server", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = processTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("JobMonitor", "Submit Time", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = processTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("JobMonitor", "Run Time", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = processTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("JobMonitor", "Status", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        clearListButton->setToolTip(QApplication::translate("JobMonitor", "Removes finished and killed jobs from the list", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        clearListButton->setText(QApplication::translate("JobMonitor", "Clear List", Q_NULLPTR));
        closeButton->setText(QApplication::translate("JobMonitor", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class JobMonitor: public Ui_JobMonitor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOBMONITOR_H
