/********************************************************************************
** Form generated from reading UI file 'OptionListEditor.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONLISTEDITOR_H
#define UI_OPTIONLISTEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_OptionListEditor
{
public:
    QVBoxLayout *vboxLayout;
    QFrame *frame;
    QHBoxLayout *hboxLayout;
    QGroupBox *groupBox;
    QVBoxLayout *vboxLayout1;
    QListWidget *optionList;
    QVBoxLayout *vboxLayout2;
    QSpacerItem *spacerItem;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QSpacerItem *spacerItem1;
    QPushButton *upButton;
    QPushButton *downButton;
    QSpacerItem *spacerItem2;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *OptionListEditor)
    {
        if (OptionListEditor->objectName().isEmpty())
            OptionListEditor->setObjectName(QStringLiteral("OptionListEditor"));
        OptionListEditor->resize(366, 352);
        vboxLayout = new QVBoxLayout(OptionListEditor);
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        frame = new QFrame(OptionListEditor);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        hboxLayout = new QHBoxLayout(frame);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        vboxLayout1 = new QVBoxLayout(groupBox);
        vboxLayout1->setObjectName(QStringLiteral("vboxLayout1"));
        optionList = new QListWidget(groupBox);
        optionList->setObjectName(QStringLiteral("optionList"));

        vboxLayout1->addWidget(optionList);


        hboxLayout->addWidget(groupBox);

        vboxLayout2 = new QVBoxLayout();
        vboxLayout2->setObjectName(QStringLiteral("vboxLayout2"));
        spacerItem = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        vboxLayout2->addItem(spacerItem);

        addButton = new QPushButton(frame);
        addButton->setObjectName(QStringLiteral("addButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(addButton->sizePolicy().hasHeightForWidth());
        addButton->setSizePolicy(sizePolicy1);

        vboxLayout2->addWidget(addButton);

        deleteButton = new QPushButton(frame);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        sizePolicy1.setHeightForWidth(deleteButton->sizePolicy().hasHeightForWidth());
        deleteButton->setSizePolicy(sizePolicy1);

        vboxLayout2->addWidget(deleteButton);

        spacerItem1 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout2->addItem(spacerItem1);

        upButton = new QPushButton(frame);
        upButton->setObjectName(QStringLiteral("upButton"));
        sizePolicy1.setHeightForWidth(upButton->sizePolicy().hasHeightForWidth());
        upButton->setSizePolicy(sizePolicy1);

        vboxLayout2->addWidget(upButton);

        downButton = new QPushButton(frame);
        downButton->setObjectName(QStringLiteral("downButton"));
        sizePolicy1.setHeightForWidth(downButton->sizePolicy().hasHeightForWidth());
        downButton->setSizePolicy(sizePolicy1);

        vboxLayout2->addWidget(downButton);

        spacerItem2 = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout2->addItem(spacerItem2);

        okButton = new QPushButton(frame);
        okButton->setObjectName(QStringLiteral("okButton"));
        sizePolicy1.setHeightForWidth(okButton->sizePolicy().hasHeightForWidth());
        okButton->setSizePolicy(sizePolicy1);

        vboxLayout2->addWidget(okButton);

        cancelButton = new QPushButton(frame);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        sizePolicy1.setHeightForWidth(cancelButton->sizePolicy().hasHeightForWidth());
        cancelButton->setSizePolicy(sizePolicy1);

        vboxLayout2->addWidget(cancelButton);


        hboxLayout->addLayout(vboxLayout2);


        vboxLayout->addWidget(frame);


        retranslateUi(OptionListEditor);
        QObject::connect(okButton, SIGNAL(clicked()), OptionListEditor, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), OptionListEditor, SLOT(reject()));

        QMetaObject::connectSlotsByName(OptionListEditor);
    } // setupUi

    void retranslateUi(QDialog *OptionListEditor)
    {
        OptionListEditor->setWindowTitle(QApplication::translate("OptionListEditor", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("OptionListEditor", "Options", Q_NULLPTR));
        addButton->setText(QApplication::translate("OptionListEditor", "Add", Q_NULLPTR));
        deleteButton->setText(QApplication::translate("OptionListEditor", "Delete", Q_NULLPTR));
        upButton->setText(QApplication::translate("OptionListEditor", "Move Up", Q_NULLPTR));
        downButton->setText(QApplication::translate("OptionListEditor", "Move Down", Q_NULLPTR));
        okButton->setText(QApplication::translate("OptionListEditor", "OK", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("OptionListEditor", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class OptionListEditor: public Ui_OptionListEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONLISTEDITOR_H
