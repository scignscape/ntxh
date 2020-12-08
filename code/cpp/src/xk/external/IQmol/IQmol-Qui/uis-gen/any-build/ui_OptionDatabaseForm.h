/********************************************************************************
** Form generated from reading UI file 'OptionDatabaseForm.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONDATABASEFORM_H
#define UI_OPTIONDATABASEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OptionDatabaseForm
{
public:
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout;
    QGroupBox *groupBox_2;
    QVBoxLayout *vboxLayout1;
    QListWidget *optionList;
    QHBoxLayout *hboxLayout1;
    QPushButton *addButton;
    QSpacerItem *spacerItem;
    QPushButton *deleteButton;
    QSpacerItem *spacerItem1;
    QVBoxLayout *vboxLayout2;
    QSpacerItem *spacerItem2;
    QFrame *frame;
    QHBoxLayout *hboxLayout2;
    QGridLayout *gridLayout;
    QHBoxLayout *hboxLayout3;
    QLabel *label;
    QComboBox *typeCombo;
    QSpacerItem *spacerItem3;
    QHBoxLayout *hboxLayout4;
    QLabel *label_4;
    QComboBox *optionsCombo;
    QHBoxLayout *hboxLayout5;
    QLabel *label_5;
    QComboBox *widgetCombo;
    QHBoxLayout *hboxLayout6;
    QPushButton *editButton;
    QSpacerItem *spacerItem4;
    QSpacerItem *spacerItem5;
    QGroupBox *groupBox;
    QVBoxLayout *vboxLayout3;
    QTextEdit *descriptionText;
    QHBoxLayout *hboxLayout7;
    QSpacerItem *spacerItem6;
    QPushButton *quitButton;

    void setupUi(QWidget *OptionDatabaseForm)
    {
        if (OptionDatabaseForm->objectName().isEmpty())
            OptionDatabaseForm->setObjectName(QStringLiteral("OptionDatabaseForm"));
        OptionDatabaseForm->resize(681, 566);
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(OptionDatabaseForm->sizePolicy().hasHeightForWidth());
        OptionDatabaseForm->setSizePolicy(sizePolicy);
        hboxLayout = new QHBoxLayout(OptionDatabaseForm);
        hboxLayout->setSpacing(6);
        hboxLayout->setContentsMargins(9, 9, 9, 9);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        vboxLayout = new QVBoxLayout();
        vboxLayout->setSpacing(6);
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        groupBox_2 = new QGroupBox(OptionDatabaseForm);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QSizePolicy sizePolicy1(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(7));
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        groupBox_2->setAlignment(Qt::AlignCenter);
        vboxLayout1 = new QVBoxLayout(groupBox_2);
        vboxLayout1->setSpacing(6);
        vboxLayout1->setContentsMargins(9, 9, 9, 9);
        vboxLayout1->setObjectName(QStringLiteral("vboxLayout1"));
        optionList = new QListWidget(groupBox_2);
        optionList->setObjectName(QStringLiteral("optionList"));
        QSizePolicy sizePolicy2(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(7));
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(optionList->sizePolicy().hasHeightForWidth());
        optionList->setSizePolicy(sizePolicy2);
        optionList->setMinimumSize(QSize(0, 20));

        vboxLayout1->addWidget(optionList);


        vboxLayout->addWidget(groupBox_2);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        hboxLayout1->setObjectName(QStringLiteral("hboxLayout1"));
        addButton = new QPushButton(OptionDatabaseForm);
        addButton->setObjectName(QStringLiteral("addButton"));

        hboxLayout1->addWidget(addButton);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem);

        deleteButton = new QPushButton(OptionDatabaseForm);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));

        hboxLayout1->addWidget(deleteButton);


        vboxLayout->addLayout(hboxLayout1);


        hboxLayout->addLayout(vboxLayout);

        spacerItem1 = new QSpacerItem(16, 596, QSizePolicy::Fixed, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem1);

        vboxLayout2 = new QVBoxLayout();
        vboxLayout2->setSpacing(6);
        vboxLayout2->setContentsMargins(0, 0, 0, 0);
        vboxLayout2->setObjectName(QStringLiteral("vboxLayout2"));
        spacerItem2 = new QSpacerItem(424, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout2->addItem(spacerItem2);

        frame = new QFrame(OptionDatabaseForm);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        hboxLayout2 = new QHBoxLayout(frame);
        hboxLayout2->setSpacing(6);
        hboxLayout2->setContentsMargins(9, 9, 9, 9);
        hboxLayout2->setObjectName(QStringLiteral("hboxLayout2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        hboxLayout3 = new QHBoxLayout();
        hboxLayout3->setSpacing(6);
        hboxLayout3->setContentsMargins(0, 0, 0, 0);
        hboxLayout3->setObjectName(QStringLiteral("hboxLayout3"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));

        hboxLayout3->addWidget(label);

        typeCombo = new QComboBox(frame);
        typeCombo->setObjectName(QStringLiteral("typeCombo"));
        QSizePolicy sizePolicy3(static_cast<QSizePolicy::Policy>(3), static_cast<QSizePolicy::Policy>(0));
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(typeCombo->sizePolicy().hasHeightForWidth());
        typeCombo->setSizePolicy(sizePolicy3);
        typeCombo->setMinimumSize(QSize(100, 0));

        hboxLayout3->addWidget(typeCombo);

        spacerItem3 = new QSpacerItem(86, 32, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout3->addItem(spacerItem3);


        gridLayout->addLayout(hboxLayout3, 0, 0, 1, 1);

        hboxLayout4 = new QHBoxLayout();
        hboxLayout4->setSpacing(6);
        hboxLayout4->setContentsMargins(0, 0, 0, 0);
        hboxLayout4->setObjectName(QStringLiteral("hboxLayout4"));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        QSizePolicy sizePolicy4(static_cast<QSizePolicy::Policy>(1), static_cast<QSizePolicy::Policy>(1));
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy4);

        hboxLayout4->addWidget(label_4);

        optionsCombo = new QComboBox(frame);
        optionsCombo->setObjectName(QStringLiteral("optionsCombo"));
        sizePolicy3.setHeightForWidth(optionsCombo->sizePolicy().hasHeightForWidth());
        optionsCombo->setSizePolicy(sizePolicy3);
        optionsCombo->setMinimumSize(QSize(150, 0));
        optionsCombo->setEditable(false);

        hboxLayout4->addWidget(optionsCombo);


        gridLayout->addLayout(hboxLayout4, 1, 0, 1, 1);

        hboxLayout5 = new QHBoxLayout();
        hboxLayout5->setSpacing(6);
        hboxLayout5->setContentsMargins(0, 0, 0, 0);
        hboxLayout5->setObjectName(QStringLiteral("hboxLayout5"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy4.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy4);

        hboxLayout5->addWidget(label_5);

        widgetCombo = new QComboBox(frame);
        widgetCombo->setObjectName(QStringLiteral("widgetCombo"));
        QSizePolicy sizePolicy5(static_cast<QSizePolicy::Policy>(1), static_cast<QSizePolicy::Policy>(0));
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(widgetCombo->sizePolicy().hasHeightForWidth());
        widgetCombo->setSizePolicy(sizePolicy5);

        hboxLayout5->addWidget(widgetCombo);


        gridLayout->addLayout(hboxLayout5, 0, 1, 1, 1);

        hboxLayout6 = new QHBoxLayout();
        hboxLayout6->setSpacing(6);
        hboxLayout6->setContentsMargins(0, 0, 0, 0);
        hboxLayout6->setObjectName(QStringLiteral("hboxLayout6"));
        editButton = new QPushButton(frame);
        editButton->setObjectName(QStringLiteral("editButton"));
        sizePolicy5.setHeightForWidth(editButton->sizePolicy().hasHeightForWidth());
        editButton->setSizePolicy(sizePolicy5);

        hboxLayout6->addWidget(editButton);

        spacerItem4 = new QSpacerItem(51, 32, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout6->addItem(spacerItem4);


        gridLayout->addLayout(hboxLayout6, 1, 1, 1, 1);


        hboxLayout2->addLayout(gridLayout);

        spacerItem5 = new QSpacerItem(16, 70, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacerItem5);


        vboxLayout2->addWidget(frame);

        groupBox = new QGroupBox(OptionDatabaseForm);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy6(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(7));
        sizePolicy6.setHorizontalStretch(2);
        sizePolicy6.setVerticalStretch(1);
        sizePolicy6.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy6);
        groupBox->setMinimumSize(QSize(300, 250));
        vboxLayout3 = new QVBoxLayout(groupBox);
        vboxLayout3->setSpacing(6);
        vboxLayout3->setContentsMargins(9, 9, 9, 9);
        vboxLayout3->setObjectName(QStringLiteral("vboxLayout3"));
        descriptionText = new QTextEdit(groupBox);
        descriptionText->setObjectName(QStringLiteral("descriptionText"));
        QSizePolicy sizePolicy7(static_cast<QSizePolicy::Policy>(7), static_cast<QSizePolicy::Policy>(7));
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(1);
        sizePolicy7.setHeightForWidth(descriptionText->sizePolicy().hasHeightForWidth());
        descriptionText->setSizePolicy(sizePolicy7);

        vboxLayout3->addWidget(descriptionText);


        vboxLayout2->addWidget(groupBox);

        hboxLayout7 = new QHBoxLayout();
        hboxLayout7->setSpacing(6);
        hboxLayout7->setContentsMargins(0, 0, 0, 0);
        hboxLayout7->setObjectName(QStringLiteral("hboxLayout7"));
        spacerItem6 = new QSpacerItem(211, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout7->addItem(spacerItem6);

        quitButton = new QPushButton(OptionDatabaseForm);
        quitButton->setObjectName(QStringLiteral("quitButton"));

        hboxLayout7->addWidget(quitButton);


        vboxLayout2->addLayout(hboxLayout7);


        hboxLayout->addLayout(vboxLayout2);


        retranslateUi(OptionDatabaseForm);

        QMetaObject::connectSlotsByName(OptionDatabaseForm);
    } // setupUi

    void retranslateUi(QWidget *OptionDatabaseForm)
    {
        OptionDatabaseForm->setWindowTitle(QApplication::translate("OptionDatabaseForm", "Form", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("OptionDatabaseForm", "Option list", Q_NULLPTR));
        addButton->setText(QApplication::translate("OptionDatabaseForm", "Add", Q_NULLPTR));
        deleteButton->setText(QApplication::translate("OptionDatabaseForm", "Delete", Q_NULLPTR));
        label->setText(QApplication::translate("OptionDatabaseForm", "Data Type", Q_NULLPTR));
        typeCombo->clear();
        typeCombo->insertItems(0, QStringList()
         << QApplication::translate("OptionDatabaseForm", "Integer", Q_NULLPTR)
         << QApplication::translate("OptionDatabaseForm", "Logical", Q_NULLPTR)
         << QApplication::translate("OptionDatabaseForm", "String", Q_NULLPTR)
         << QApplication::translate("OptionDatabaseForm", "Real", Q_NULLPTR)
         << QApplication::translate("OptionDatabaseForm", "Array", Q_NULLPTR)
        );
        label_4->setText(QApplication::translate("OptionDatabaseForm", "Default", Q_NULLPTR));
        label_5->setText(QApplication::translate("OptionDatabaseForm", "Widget", Q_NULLPTR));
        widgetCombo->clear();
        widgetCombo->insertItems(0, QStringList()
         << QApplication::translate("OptionDatabaseForm", "None", Q_NULLPTR)
         << QApplication::translate("OptionDatabaseForm", "Combo box", Q_NULLPTR)
         << QApplication::translate("OptionDatabaseForm", "Check box", Q_NULLPTR)
         << QApplication::translate("OptionDatabaseForm", "Line edit", Q_NULLPTR)
         << QApplication::translate("OptionDatabaseForm", "Spin box", Q_NULLPTR)
         << QApplication::translate("OptionDatabaseForm", "Double spin box", Q_NULLPTR)
         << QApplication::translate("OptionDatabaseForm", "Radio button", Q_NULLPTR)
        );
        editButton->setText(QApplication::translate("OptionDatabaseForm", "Edit Options", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("OptionDatabaseForm", "Documentation", Q_NULLPTR));
        quitButton->setText(QApplication::translate("OptionDatabaseForm", "Quit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class OptionDatabaseForm: public Ui_OptionDatabaseForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONDATABASEFORM_H
