/********************************************************************************
** Form generated from reading UI file 'SymmetryConfigurator.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYMMETRYCONFIGURATOR_H
#define UI_SYMMETRYCONFIGURATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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
            SymmetryConfigurator->setObjectName(QStringLiteral("SymmetryConfigurator"));
        SymmetryConfigurator->resize(351, 272);
        verticalLayout = new QVBoxLayout(SymmetryConfigurator);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        characterTable = new QTableView(SymmetryConfigurator);
        characterTable->setObjectName(QStringLiteral("characterTable"));

        verticalLayout->addWidget(characterTable);

        notesLabel = new QLabel(SymmetryConfigurator);
        notesLabel->setObjectName(QStringLiteral("notesLabel"));
        QFont font;
        font.setPointSize(11);
        notesLabel->setFont(font);

        verticalLayout->addWidget(notesLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closeButton = new QPushButton(SymmetryConfigurator);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        horizontalLayout->addWidget(closeButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(SymmetryConfigurator);
        QObject::connect(closeButton, SIGNAL(clicked()), SymmetryConfigurator, SLOT(close()));

        QMetaObject::connectSlotsByName(SymmetryConfigurator);
    } // setupUi

    void retranslateUi(QWidget *SymmetryConfigurator)
    {
        SymmetryConfigurator->setWindowTitle(QApplication::translate("SymmetryConfigurator", "Form", Q_NULLPTR));
        notesLabel->setText(QApplication::translate("SymmetryConfigurator", "Notes:", Q_NULLPTR));
        closeButton->setText(QApplication::translate("SymmetryConfigurator", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SymmetryConfigurator: public Ui_SymmetryConfigurator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYMMETRYCONFIGURATOR_H
