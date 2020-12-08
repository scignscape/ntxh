/********************************************************************************
** Form generated from reading UI file 'TransitionStateTab.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSITIONSTATETAB_H
#define UI_TRANSITIONSTATETAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TransitionStateTab
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_27;
    QLabel *label_212;
    QSpinBox *geom_opt_mode;
    QSpacerItem *horizontalSpacer_27;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *TransitionStateTab)
    {
        if (TransitionStateTab->objectName().isEmpty())
            TransitionStateTab->setObjectName(QStringLiteral("TransitionStateTab"));
        TransitionStateTab->resize(298, 74);
        verticalLayout = new QVBoxLayout(TransitionStateTab);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setObjectName(QStringLiteral("horizontalLayout_27"));
        label_212 = new QLabel(TransitionStateTab);
        label_212->setObjectName(QStringLiteral("label_212"));

        horizontalLayout_27->addWidget(label_212);

        geom_opt_mode = new QSpinBox(TransitionStateTab);
        geom_opt_mode->setObjectName(QStringLiteral("geom_opt_mode"));

        horizontalLayout_27->addWidget(geom_opt_mode);

        horizontalSpacer_27 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_27->addItem(horizontalSpacer_27);


        verticalLayout->addLayout(horizontalLayout_27);

        verticalSpacer = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(TransitionStateTab);

        QMetaObject::connectSlotsByName(TransitionStateTab);
    } // setupUi

    void retranslateUi(QWidget *TransitionStateTab)
    {
        TransitionStateTab->setWindowTitle(QApplication::translate("TransitionStateTab", "Form", Q_NULLPTR));
        label_212->setText(QApplication::translate("TransitionStateTab", "Follow Mode", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TransitionStateTab: public Ui_TransitionStateTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSITIONSTATETAB_H
