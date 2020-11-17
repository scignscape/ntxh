/********************************************************************************
** Form generated from reading UI file 'GridInfoDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRIDINFODIALOG_H
#define UI_GRIDINFODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_GridInfoDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *gridTable;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;

    void setupUi(QDialog *GridInfoDialog)
    {
        if (GridInfoDialog->objectName().isEmpty())
            GridInfoDialog->setObjectName(QString::fromUtf8("GridInfoDialog"));
        GridInfoDialog->resize(665, 285);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GridInfoDialog->sizePolicy().hasHeightForWidth());
        GridInfoDialog->setSizePolicy(sizePolicy);
        GridInfoDialog->setStyleSheet(QString::fromUtf8("QToolButton {\n"
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
"}\n"
"\n"
"QToolTip {\n"
"   border: 2px solid darkkhaki;\n"
"   p"
                        "adding: 2px;\n"
"   border-radius: 3px;\n"
"   opacity: 500;\n"
"   font-size: 12px;\n"
"}"));
        verticalLayout = new QVBoxLayout(GridInfoDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridTable = new QTableWidget(GridInfoDialog);
        if (gridTable->columnCount() < 4)
            gridTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        gridTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        gridTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        gridTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        gridTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        gridTable->setObjectName(QString::fromUtf8("gridTable"));
        gridTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        gridTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        gridTable->setShowGrid(false);

        verticalLayout->addWidget(gridTable);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closeButton = new QPushButton(GridInfoDialog);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setAutoDefault(false);

        horizontalLayout->addWidget(closeButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(GridInfoDialog);
        QObject::connect(closeButton, SIGNAL(clicked()), GridInfoDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(GridInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *GridInfoDialog)
    {
        GridInfoDialog->setWindowTitle(QApplication::translate("GridInfoDialog", "Grid Information", nullptr));
        QTableWidgetItem *___qtablewidgetitem = gridTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("GridInfoDialog", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = gridTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("GridInfoDialog", "Data Size (kB)", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = gridTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("GridInfoDialog", "Step Size", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = gridTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("GridInfoDialog", "Bounding Box", nullptr));
        closeButton->setText(QApplication::translate("GridInfoDialog", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GridInfoDialog: public Ui_GridInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRIDINFODIALOG_H
