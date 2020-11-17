/********************************************************************************
** Form generated from reading UI file 'SymmetryConfigurator.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYMMETRYCONFIGURATOR_H
#define UI_SYMMETRYCONFIGURATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SymmetryConfigurator
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *characterTable;
    QLabel *notesLabel;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;

    void setupUi(QWidget *SymmetryConfigurator)
    {
        if (SymmetryConfigurator->objectName().isEmpty())
            SymmetryConfigurator->setObjectName(QString::fromUtf8("SymmetryConfigurator"));
        SymmetryConfigurator->resize(351, 272);
        verticalLayout = new QVBoxLayout(SymmetryConfigurator);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        characterTable = new QTableView(SymmetryConfigurator);
        characterTable->setObjectName(QString::fromUtf8("characterTable"));

        verticalLayout->addWidget(characterTable);

        notesLabel = new QLabel(SymmetryConfigurator);
        notesLabel->setObjectName(QString::fromUtf8("notesLabel"));
        QFont font;
        font.setPointSize(11);
        notesLabel->setFont(font);

        verticalLayout->addWidget(notesLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closeButton = new QPushButton(SymmetryConfigurator);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        horizontalLayout->addWidget(closeButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(SymmetryConfigurator);
        QObject::connect(closeButton, SIGNAL(clicked()), SymmetryConfigurator, SLOT(close()));

        QMetaObject::connectSlotsByName(SymmetryConfigurator);
    } // setupUi

    void retranslateUi(QWidget *SymmetryConfigurator)
    {
        SymmetryConfigurator->setWindowTitle(QApplication::translate("SymmetryConfigurator", "Form", nullptr));
        notesLabel->setText(QApplication::translate("SymmetryConfigurator", "Notes:", nullptr));
        closeButton->setText(QApplication::translate("SymmetryConfigurator", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SymmetryConfigurator: public Ui_SymmetryConfigurator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYMMETRYCONFIGURATOR_H
