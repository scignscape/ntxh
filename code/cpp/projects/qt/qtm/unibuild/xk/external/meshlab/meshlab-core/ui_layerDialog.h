/********************************************************************************
** Form generated from reading UI file 'layerDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAYERDIALOG_H
#define UI_LAYERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_layerDialog
{
public:
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout;
    QTreeWidget *meshTreeWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QToolButton *bW1;
    QToolButton *bW2;
    QToolButton *bW3;
    QToolButton *bW4;
    QSpacerItem *horizontalSpacer;
    QToolButton *bV1;
    QToolButton *bV2;
    QToolButton *bV3;
    QToolButton *bV4;
    QVBoxLayout *renderingLayout;
    QVBoxLayout *rasterLayout;
    QTreeWidget *rasterTreeWidget;
    QVBoxLayout *subLayout;
    QTreeWidget *decParsTree;
    QPlainTextEdit *logPlainTextEdit;

    void setupUi(QDockWidget *layerDialog)
    {
        if (layerDialog->objectName().isEmpty())
            layerDialog->setObjectName(QString::fromUtf8("layerDialog"));
        layerDialog->resize(298, 816);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(layerDialog->sizePolicy().hasHeightForWidth());
        layerDialog->setSizePolicy(sizePolicy);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        verticalLayout = new QVBoxLayout(dockWidgetContents);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        meshTreeWidget = new QTreeWidget(dockWidgetContents);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        meshTreeWidget->setHeaderItem(__qtreewidgetitem);
        meshTreeWidget->setObjectName(QString::fromUtf8("meshTreeWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(2);
        sizePolicy1.setHeightForWidth(meshTreeWidget->sizePolicy().hasHeightForWidth());
        meshTreeWidget->setSizePolicy(sizePolicy1);
        meshTreeWidget->setSizeIncrement(QSize(0, 1));
        meshTreeWidget->setIndentation(10);

        verticalLayout->addWidget(meshTreeWidget);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        bW1 = new QToolButton(dockWidgetContents);
        bW1->setObjectName(QString::fromUtf8("bW1"));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        bW1->setFont(font);

        horizontalLayout->addWidget(bW1);

        bW2 = new QToolButton(dockWidgetContents);
        bW2->setObjectName(QString::fromUtf8("bW2"));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        bW2->setFont(font1);

        horizontalLayout->addWidget(bW2);

        bW3 = new QToolButton(dockWidgetContents);
        bW3->setObjectName(QString::fromUtf8("bW3"));
        bW3->setFont(font1);

        horizontalLayout->addWidget(bW3);

        bW4 = new QToolButton(dockWidgetContents);
        bW4->setObjectName(QString::fromUtf8("bW4"));
        bW4->setFont(font1);

        horizontalLayout->addWidget(bW4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        bV1 = new QToolButton(dockWidgetContents);
        bV1->setObjectName(QString::fromUtf8("bV1"));
        bV1->setFont(font1);

        horizontalLayout->addWidget(bV1);

        bV2 = new QToolButton(dockWidgetContents);
        bV2->setObjectName(QString::fromUtf8("bV2"));
        bV2->setFont(font1);

        horizontalLayout->addWidget(bV2);

        bV3 = new QToolButton(dockWidgetContents);
        bV3->setObjectName(QString::fromUtf8("bV3"));
        bV3->setFont(font1);

        horizontalLayout->addWidget(bV3);

        bV4 = new QToolButton(dockWidgetContents);
        bV4->setObjectName(QString::fromUtf8("bV4"));
        bV4->setFont(font1);

        horizontalLayout->addWidget(bV4);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addLayout(verticalLayout_2);

        renderingLayout = new QVBoxLayout();
        renderingLayout->setObjectName(QString::fromUtf8("renderingLayout"));

        verticalLayout->addLayout(renderingLayout);

        rasterLayout = new QVBoxLayout();
        rasterLayout->setObjectName(QString::fromUtf8("rasterLayout"));
        rasterTreeWidget = new QTreeWidget(dockWidgetContents);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QString::fromUtf8("1"));
        rasterTreeWidget->setHeaderItem(__qtreewidgetitem1);
        rasterTreeWidget->setObjectName(QString::fromUtf8("rasterTreeWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Ignored);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(rasterTreeWidget->sizePolicy().hasHeightForWidth());
        rasterTreeWidget->setSizePolicy(sizePolicy2);
        rasterTreeWidget->setIndentation(10);

        rasterLayout->addWidget(rasterTreeWidget);


        verticalLayout->addLayout(rasterLayout);

        subLayout = new QVBoxLayout();
        subLayout->setObjectName(QString::fromUtf8("subLayout"));
        decParsTree = new QTreeWidget(dockWidgetContents);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem();
        __qtreewidgetitem2->setText(0, QString::fromUtf8("1"));
        decParsTree->setHeaderItem(__qtreewidgetitem2);
        decParsTree->setObjectName(QString::fromUtf8("decParsTree"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Ignored);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(decParsTree->sizePolicy().hasHeightForWidth());
        decParsTree->setSizePolicy(sizePolicy3);
        decParsTree->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        decParsTree->setIndentation(10);
        decParsTree->header()->setVisible(false);

        subLayout->addWidget(decParsTree);


        verticalLayout->addLayout(subLayout);

        logPlainTextEdit = new QPlainTextEdit(dockWidgetContents);
        logPlainTextEdit->setObjectName(QString::fromUtf8("logPlainTextEdit"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(1);
        sizePolicy4.setHeightForWidth(logPlainTextEdit->sizePolicy().hasHeightForWidth());
        logPlainTextEdit->setSizePolicy(sizePolicy4);
        logPlainTextEdit->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout->addWidget(logPlainTextEdit);

        layerDialog->setWidget(dockWidgetContents);

        retranslateUi(layerDialog);

        QMetaObject::connectSlotsByName(layerDialog);
    } // setupUi

    void retranslateUi(QDockWidget *layerDialog)
    {
        layerDialog->setWindowTitle(QCoreApplication::translate("layerDialog", "Layer Dialog", nullptr));
#if QT_CONFIG(tooltip)
        bW1->setToolTip(QCoreApplication::translate("layerDialog", "CTRL-click to store view, click to recall", nullptr));
#endif // QT_CONFIG(tooltip)
        bW1->setText(QCoreApplication::translate("layerDialog", "1", nullptr));
#if QT_CONFIG(tooltip)
        bW2->setToolTip(QCoreApplication::translate("layerDialog", "CTRL-click to store view, click to recall", nullptr));
#endif // QT_CONFIG(tooltip)
        bW2->setText(QCoreApplication::translate("layerDialog", "2", nullptr));
#if QT_CONFIG(tooltip)
        bW3->setToolTip(QCoreApplication::translate("layerDialog", "CTRL-click to store view, click to recall", nullptr));
#endif // QT_CONFIG(tooltip)
        bW3->setText(QCoreApplication::translate("layerDialog", "3", nullptr));
#if QT_CONFIG(tooltip)
        bW4->setToolTip(QCoreApplication::translate("layerDialog", "CTRL-click to store view, click to recall", nullptr));
#endif // QT_CONFIG(tooltip)
        bW4->setText(QCoreApplication::translate("layerDialog", "4", nullptr));
#if QT_CONFIG(tooltip)
        bV1->setToolTip(QCoreApplication::translate("layerDialog", "CTRL-click to store layer visibility, click to recall", nullptr));
#endif // QT_CONFIG(tooltip)
        bV1->setText(QCoreApplication::translate("layerDialog", "1", nullptr));
#if QT_CONFIG(tooltip)
        bV2->setToolTip(QCoreApplication::translate("layerDialog", "CTRL-click to store layer visibility, click to recall", nullptr));
#endif // QT_CONFIG(tooltip)
        bV2->setText(QCoreApplication::translate("layerDialog", "2", nullptr));
#if QT_CONFIG(tooltip)
        bV3->setToolTip(QCoreApplication::translate("layerDialog", "CTRL-click to store layer visibility, click to recall", nullptr));
#endif // QT_CONFIG(tooltip)
        bV3->setText(QCoreApplication::translate("layerDialog", "3", nullptr));
#if QT_CONFIG(tooltip)
        bV4->setToolTip(QCoreApplication::translate("layerDialog", "CTRL-click to store layer visibility, click to recall", nullptr));
#endif // QT_CONFIG(tooltip)
        bV4->setText(QCoreApplication::translate("layerDialog", "4", nullptr));
    } // retranslateUi

};

namespace Ui {
    class layerDialog: public Ui_layerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAYERDIALOG_H
