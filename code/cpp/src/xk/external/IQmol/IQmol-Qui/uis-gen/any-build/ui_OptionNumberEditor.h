/********************************************************************************
** Form generated from reading UI file 'OptionNumberEditor.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONNUMBEREDITOR_H
#define UI_OPTIONNUMBEREDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_OptionNumberEditor
{
public:
    QVBoxLayout *vboxLayout;
    QFrame *frame;
    QVBoxLayout *vboxLayout1;
    QLabel *label;
    QHBoxLayout *hboxLayout;
    QVBoxLayout *vboxLayout2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_4;
    QVBoxLayout *vboxLayout3;
    QLineEdit *minEdit;
    QLineEdit *maxEdit;
    QLineEdit *defaultEdit;
    QLineEdit *stepEdit;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *OptionNumberEditor)
    {
        if (OptionNumberEditor->objectName().isEmpty())
            OptionNumberEditor->setObjectName(QStringLiteral("OptionNumberEditor"));
        OptionNumberEditor->resize(248, 217);
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(OptionNumberEditor->sizePolicy().hasHeightForWidth());
        OptionNumberEditor->setSizePolicy(sizePolicy);
        vboxLayout = new QVBoxLayout(OptionNumberEditor);
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout->setContentsMargins(9, 9, 9, 9);
#endif
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        frame = new QFrame(OptionNumberEditor);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        vboxLayout1 = new QVBoxLayout(frame);
#ifndef Q_OS_MAC
        vboxLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout1->setContentsMargins(9, 9, 9, 9);
#endif
        vboxLayout1->setObjectName(QStringLiteral("vboxLayout1"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));

        vboxLayout1->addWidget(label);

        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        vboxLayout2 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout2->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout2->setContentsMargins(0, 0, 0, 0);
#endif
        vboxLayout2->setObjectName(QStringLiteral("vboxLayout2"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));

        vboxLayout2->addWidget(label_2);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));

        vboxLayout2->addWidget(label_3);

        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));

        vboxLayout2->addWidget(label_5);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));

        vboxLayout2->addWidget(label_4);


        hboxLayout->addLayout(vboxLayout2);

        vboxLayout3 = new QVBoxLayout();
#ifndef Q_OS_MAC
        vboxLayout3->setSpacing(6);
#endif
        vboxLayout3->setContentsMargins(0, 0, 0, 0);
        vboxLayout3->setObjectName(QStringLiteral("vboxLayout3"));
        minEdit = new QLineEdit(frame);
        minEdit->setObjectName(QStringLiteral("minEdit"));

        vboxLayout3->addWidget(minEdit);

        maxEdit = new QLineEdit(frame);
        maxEdit->setObjectName(QStringLiteral("maxEdit"));

        vboxLayout3->addWidget(maxEdit);

        defaultEdit = new QLineEdit(frame);
        defaultEdit->setObjectName(QStringLiteral("defaultEdit"));

        vboxLayout3->addWidget(defaultEdit);

        stepEdit = new QLineEdit(frame);
        stepEdit->setObjectName(QStringLiteral("stepEdit"));

        vboxLayout3->addWidget(stepEdit);


        hboxLayout->addLayout(vboxLayout3);


        vboxLayout1->addLayout(hboxLayout);

        hboxLayout1 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout1->setSpacing(6);
#endif
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        hboxLayout1->setObjectName(QStringLiteral("hboxLayout1"));
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem);

        okButton = new QPushButton(frame);
        okButton->setObjectName(QStringLiteral("okButton"));

        hboxLayout1->addWidget(okButton);

        cancelButton = new QPushButton(frame);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        hboxLayout1->addWidget(cancelButton);


        vboxLayout1->addLayout(hboxLayout1);


        vboxLayout->addWidget(frame);


        retranslateUi(OptionNumberEditor);
        QObject::connect(okButton, SIGNAL(clicked()), OptionNumberEditor, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), OptionNumberEditor, SLOT(reject()));

        QMetaObject::connectSlotsByName(OptionNumberEditor);
    } // setupUi

    void retranslateUi(QDialog *OptionNumberEditor)
    {
        OptionNumberEditor->setWindowTitle(QApplication::translate("OptionNumberEditor", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("OptionNumberEditor", "Edit variable parameters:", Q_NULLPTR));
        label_2->setText(QApplication::translate("OptionNumberEditor", "Minimum", Q_NULLPTR));
        label_3->setText(QApplication::translate("OptionNumberEditor", "Maximum", Q_NULLPTR));
        label_5->setText(QApplication::translate("OptionNumberEditor", "Default value", Q_NULLPTR));
        label_4->setText(QApplication::translate("OptionNumberEditor", "Step size", Q_NULLPTR));
        okButton->setText(QApplication::translate("OptionNumberEditor", "OK", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("OptionNumberEditor", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class OptionNumberEditor: public Ui_OptionNumberEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONNUMBEREDITOR_H
