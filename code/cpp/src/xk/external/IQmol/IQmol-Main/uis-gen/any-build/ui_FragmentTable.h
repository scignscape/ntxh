/********************************************************************************
** Form generated from reading UI file 'FragmentTable.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAGMENTTABLE_H
#define UI_FRAGMENTTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FragmentTable
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *functionalGroupsButton;
    QRadioButton *efpButton;
    QRadioButton *moleculesButton;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QTreeWidget *fragmentList;
    QVBoxLayout *verticalLayout;
    QFrame *viewWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *selectButton;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QFrame *FragmentTable)
    {
        if (FragmentTable->objectName().isEmpty())
            FragmentTable->setObjectName(QString::fromUtf8("FragmentTable"));
        FragmentTable->resize(412, 306);
        FragmentTable->setFrameShape(QFrame::StyledPanel);
        FragmentTable->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(FragmentTable);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        functionalGroupsButton = new QRadioButton(FragmentTable);
        functionalGroupsButton->setObjectName(QString::fromUtf8("functionalGroupsButton"));
        functionalGroupsButton->setChecked(true);

        horizontalLayout_4->addWidget(functionalGroupsButton);

        efpButton = new QRadioButton(FragmentTable);
        efpButton->setObjectName(QString::fromUtf8("efpButton"));
        efpButton->setChecked(false);

        horizontalLayout_4->addWidget(efpButton);

        moleculesButton = new QRadioButton(FragmentTable);
        moleculesButton->setObjectName(QString::fromUtf8("moleculesButton"));

        horizontalLayout_4->addWidget(moleculesButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        fragmentList = new QTreeWidget(FragmentTable);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        fragmentList->setHeaderItem(__qtreewidgetitem);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(fragmentList);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(fragmentList);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(fragmentList);
        fragmentList->setObjectName(QString::fromUtf8("fragmentList"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(fragmentList->sizePolicy().hasHeightForWidth());
        fragmentList->setSizePolicy(sizePolicy);
        fragmentList->setMinimumSize(QSize(180, 180));
        fragmentList->setMaximumSize(QSize(180, 500));
        QFont font;
        font.setKerning(true);
        fragmentList->setFont(font);
        fragmentList->setIndentation(12);
        fragmentList->setRootIsDecorated(true);
        fragmentList->header()->setVisible(false);

        horizontalLayout_3->addWidget(fragmentList);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        viewWidget = new QFrame(FragmentTable);
        viewWidget->setObjectName(QString::fromUtf8("viewWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(viewWidget->sizePolicy().hasHeightForWidth());
        viewWidget->setSizePolicy(sizePolicy1);
        viewWidget->setMinimumSize(QSize(180, 180));
        viewWidget->setFrameShape(QFrame::Panel);
        viewWidget->setFrameShadow(QFrame::Sunken);
        viewWidget->setLineWidth(2);
        viewWidget->setMidLineWidth(2);

        verticalLayout->addWidget(viewWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(48, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        selectButton = new QPushButton(FragmentTable);
        selectButton->setObjectName(QString::fromUtf8("selectButton"));

        horizontalLayout->addWidget(selectButton);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(58, 38, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_3);


        retranslateUi(FragmentTable);

        QMetaObject::connectSlotsByName(FragmentTable);
    } // setupUi

    void retranslateUi(QFrame *FragmentTable)
    {
        FragmentTable->setWindowTitle(QApplication::translate("FragmentTable", "Frame", nullptr));
        functionalGroupsButton->setText(QApplication::translate("FragmentTable", "Functional Group", nullptr));
        efpButton->setText(QApplication::translate("FragmentTable", "EFP", nullptr));
        moleculesButton->setText(QApplication::translate("FragmentTable", "Molecules", nullptr));

        const bool __sortingEnabled = fragmentList->isSortingEnabled();
        fragmentList->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem = fragmentList->topLevelItem(0);
        ___qtreewidgetitem->setText(0, QApplication::translate("FragmentTable", "Solvents", nullptr));
        QTreeWidgetItem *___qtreewidgetitem1 = ___qtreewidgetitem->child(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("FragmentTable", "Acetone", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem->child(1);
        ___qtreewidgetitem2->setText(0, QApplication::translate("FragmentTable", "Acetonitrile", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem->child(2);
        ___qtreewidgetitem3->setText(0, QApplication::translate("FragmentTable", "Benzene", nullptr));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem->child(3);
        ___qtreewidgetitem4->setText(0, QApplication::translate("FragmentTable", "Carbon Tetracholoride", nullptr));
        QTreeWidgetItem *___qtreewidgetitem5 = ___qtreewidgetitem->child(4);
        ___qtreewidgetitem5->setText(0, QApplication::translate("FragmentTable", "Water", nullptr));
        QTreeWidgetItem *___qtreewidgetitem6 = fragmentList->topLevelItem(1);
        ___qtreewidgetitem6->setText(0, QApplication::translate("FragmentTable", "Gases", nullptr));
        QTreeWidgetItem *___qtreewidgetitem7 = ___qtreewidgetitem6->child(0);
        ___qtreewidgetitem7->setText(0, QApplication::translate("FragmentTable", "Ammonia", nullptr));
        QTreeWidgetItem *___qtreewidgetitem8 = ___qtreewidgetitem6->child(1);
        ___qtreewidgetitem8->setText(0, QApplication::translate("FragmentTable", "Methane", nullptr));
        QTreeWidgetItem *___qtreewidgetitem9 = ___qtreewidgetitem6->child(2);
        ___qtreewidgetitem9->setText(0, QApplication::translate("FragmentTable", "Oxygen (O2)", nullptr));
        QTreeWidgetItem *___qtreewidgetitem10 = fragmentList->topLevelItem(2);
        ___qtreewidgetitem10->setText(0, QApplication::translate("FragmentTable", "Bases", nullptr));
        fragmentList->setSortingEnabled(__sortingEnabled);

        viewWidget->setStyleSheet(QApplication::translate("FragmentTable", "background: white", nullptr));
        selectButton->setText(QApplication::translate("FragmentTable", "Select", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FragmentTable: public Ui_FragmentTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAGMENTTABLE_H