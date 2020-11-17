/********************************************************************************
** Form generated from reading UI file 'ServerConfigurationListDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERCONFIGURATIONLISTDIALOG_H
#define UI_SERVERCONFIGURATIONLISTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ServerConfigurationListDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *serverListTable;
    QVBoxLayout *verticalLayout;
    QToolButton *addServerButton;
    QToolButton *configureServerButton;
    QToolButton *removeServerButton;
    QToolButton *upButton;
    QToolButton *downButton;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;

    void setupUi(QDialog *ServerConfigurationListDialog)
    {
        if (ServerConfigurationListDialog->objectName().isEmpty())
            ServerConfigurationListDialog->setObjectName(QString::fromUtf8("ServerConfigurationListDialog"));
        ServerConfigurationListDialog->resize(583, 304);
        ServerConfigurationListDialog->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"   color: #333;\n"
"   background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, \n"
"          stop: 0 #fff,\n"
"          stop: 0.5 #eee, \n"
"          stop: 1 #999);\n"
"   border-width: 2px;\n"
"   border-color: #333;\n"
"   border-style: solid;\n"
"   border-radius: 5;\n"
"   padding: 0px;\n"
"   font-size: 24px;\n"
"   min-width: 34px;\n"
"   max-width: 34px;\n"
"   min-height: 34px;\n"
"   max-height: 34px;\n"
"}\n"
"\n"
"QToolButton:disabled {\n"
"  background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, \n"
"          stop: 0 #fff,\n"
"          stop: 0.5 #eee, \n"
"          stop: 1 #bbb);\n"
"   border-color: #aaa;\n"
"   color: #aaa;\n"
"}\n"
"\n"
"QToolButton:pressed {\n"
"   background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, \n"
"          stop: 0 #999,\n"
"          stop: 0.5 #eee, \n"
"          stop: 1 #fff);\n"
"}\n"
"\n"
"\n"
"QToolButton:checked {\n"
"   border-color: #b00;\n"
"   background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, \n"
""
                        "          stop: 0 #999,\n"
"          stop: 0.5 #eee, \n"
"          stop: 1 #fff);\n"
"}\n"
"\n"
" QToolTip {\n"
"    border: 2px solid darkkhaki;\n"
"    padding: 2px;\n"
"    border-radius: 3px;\n"
"    opacity: 500;\n"
"    font-size: 12px;\n"
"    color: #000;\n"
"    background-color: #EEE;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(ServerConfigurationListDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        serverListTable = new QTableWidget(ServerConfigurationListDialog);
        if (serverListTable->columnCount() < 4)
            serverListTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        serverListTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        serverListTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        serverListTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        serverListTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        serverListTable->setObjectName(QString::fromUtf8("serverListTable"));
        serverListTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        serverListTable->setSelectionMode(QAbstractItemView::SingleSelection);
        serverListTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        serverListTable->setShowGrid(false);
        serverListTable->horizontalHeader()->setMinimumSectionSize(30);
        serverListTable->verticalHeader()->setCascadingSectionResizes(true);

        horizontalLayout_2->addWidget(serverListTable);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        addServerButton = new QToolButton(ServerConfigurationListDialog);
        addServerButton->setObjectName(QString::fromUtf8("addServerButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/Add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addServerButton->setIcon(icon);
        addServerButton->setIconSize(QSize(24, 24));

        verticalLayout->addWidget(addServerButton);

        configureServerButton = new QToolButton(ServerConfigurationListDialog);
        configureServerButton->setObjectName(QString::fromUtf8("configureServerButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/icons/Configure.png"), QSize(), QIcon::Normal, QIcon::Off);
        configureServerButton->setIcon(icon1);
        configureServerButton->setIconSize(QSize(24, 24));

        verticalLayout->addWidget(configureServerButton);

        removeServerButton = new QToolButton(ServerConfigurationListDialog);
        removeServerButton->setObjectName(QString::fromUtf8("removeServerButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/icons/Remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        removeServerButton->setIcon(icon2);
        removeServerButton->setIconSize(QSize(24, 24));

        verticalLayout->addWidget(removeServerButton);

        upButton = new QToolButton(ServerConfigurationListDialog);
        upButton->setObjectName(QString::fromUtf8("upButton"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/icons/Up.png"), QSize(), QIcon::Normal, QIcon::Off);
        upButton->setIcon(icon3);
        upButton->setIconSize(QSize(24, 24));

        verticalLayout->addWidget(upButton);

        downButton = new QToolButton(ServerConfigurationListDialog);
        downButton->setObjectName(QString::fromUtf8("downButton"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/resources/icons/Down.png"), QSize(), QIcon::Normal, QIcon::Off);
        downButton->setIcon(icon4);
        downButton->setIconSize(QSize(24, 24));

        verticalLayout->addWidget(downButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closeButton = new QPushButton(ServerConfigurationListDialog);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        horizontalLayout->addWidget(closeButton);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(ServerConfigurationListDialog);
        QObject::connect(closeButton, SIGNAL(clicked()), ServerConfigurationListDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(ServerConfigurationListDialog);
    } // setupUi

    void retranslateUi(QDialog *ServerConfigurationListDialog)
    {
        ServerConfigurationListDialog->setWindowTitle(QApplication::translate("ServerConfigurationListDialog", "Server List", nullptr));
        QTableWidgetItem *___qtablewidgetitem = serverListTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ServerConfigurationListDialog", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = serverListTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ServerConfigurationListDialog", "Address", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = serverListTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ServerConfigurationListDialog", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = serverListTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ServerConfigurationListDialog", "User", nullptr));
#ifndef QT_NO_TOOLTIP
        addServerButton->setToolTip(QApplication::translate("ServerConfigurationListDialog", "Add new server", nullptr));
#endif // QT_NO_TOOLTIP
        addServerButton->setText(QApplication::translate("ServerConfigurationListDialog", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        configureServerButton->setToolTip(QApplication::translate("ServerConfigurationListDialog", "Configure selected server", nullptr));
#endif // QT_NO_TOOLTIP
        configureServerButton->setText(QApplication::translate("ServerConfigurationListDialog", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        removeServerButton->setToolTip(QApplication::translate("ServerConfigurationListDialog", "Remove slected server", nullptr));
#endif // QT_NO_TOOLTIP
        removeServerButton->setText(QApplication::translate("ServerConfigurationListDialog", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        upButton->setToolTip(QApplication::translate("ServerConfigurationListDialog", "Move server up", nullptr));
#endif // QT_NO_TOOLTIP
        upButton->setText(QApplication::translate("ServerConfigurationListDialog", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        downButton->setToolTip(QApplication::translate("ServerConfigurationListDialog", "Move server down", nullptr));
#endif // QT_NO_TOOLTIP
        downButton->setText(QApplication::translate("ServerConfigurationListDialog", "...", nullptr));
        closeButton->setText(QApplication::translate("ServerConfigurationListDialog", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ServerConfigurationListDialog: public Ui_ServerConfigurationListDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERCONFIGURATIONLISTDIALOG_H
