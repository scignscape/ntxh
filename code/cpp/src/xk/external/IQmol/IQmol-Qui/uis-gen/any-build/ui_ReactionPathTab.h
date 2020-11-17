/********************************************************************************
** Form generated from reading UI file 'ReactionPathTab.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REACTIONPATHTAB_H
#define UI_REACTIONPATHTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReactionPathTab
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_55;
    QComboBox *rpath_direction;
    QLabel *label_57;
    QSpinBox *rpath_max_cycles;
    QSpacerItem *horizontalSpacer_19;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *ReactionPathTab)
    {
        if (ReactionPathTab->objectName().isEmpty())
            ReactionPathTab->setObjectName(QString::fromUtf8("ReactionPathTab"));
        ReactionPathTab->resize(363, 89);
        verticalLayout = new QVBoxLayout(ReactionPathTab);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_55 = new QLabel(ReactionPathTab);
        label_55->setObjectName(QString::fromUtf8("label_55"));

        horizontalLayout_3->addWidget(label_55);

        rpath_direction = new QComboBox(ReactionPathTab);
        rpath_direction->setObjectName(QString::fromUtf8("rpath_direction"));

        horizontalLayout_3->addWidget(rpath_direction);

        label_57 = new QLabel(ReactionPathTab);
        label_57->setObjectName(QString::fromUtf8("label_57"));

        horizontalLayout_3->addWidget(label_57);

        rpath_max_cycles = new QSpinBox(ReactionPathTab);
        rpath_max_cycles->setObjectName(QString::fromUtf8("rpath_max_cycles"));

        horizontalLayout_3->addWidget(rpath_max_cycles);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_19);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(ReactionPathTab);

        QMetaObject::connectSlotsByName(ReactionPathTab);
    } // setupUi

    void retranslateUi(QWidget *ReactionPathTab)
    {
        ReactionPathTab->setWindowTitle(QApplication::translate("ReactionPathTab", "Form", nullptr));
        label_55->setText(QApplication::translate("ReactionPathTab", "Direction", nullptr));
        label_57->setText(QApplication::translate("ReactionPathTab", "Max Cycles", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReactionPathTab: public Ui_ReactionPathTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REACTIONPATHTAB_H
