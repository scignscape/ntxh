/********************************************************************************
** Form generated from reading UI file 'QueueResourcesDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUEUERESOURCESDIALOG_H
#define UI_QUEUERESOURCESDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QueueResourcesDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *walltime;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QSpinBox *memory;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QSpinBox *ncpus;
    QSpinBox *scratch;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *queue;
    QSpacerItem *horizontalSpacer_3;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QueueResourcesDialog)
    {
        if (QueueResourcesDialog->objectName().isEmpty())
            QueueResourcesDialog->setObjectName(QString::fromUtf8("QueueResourcesDialog"));
        QueueResourcesDialog->resize(280, 229);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QueueResourcesDialog->sizePolicy().hasHeightForWidth());
        QueueResourcesDialog->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(QueueResourcesDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(QueueResourcesDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        walltime = new QLineEdit(QueueResourcesDialog);
        walltime->setObjectName(QString::fromUtf8("walltime"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(walltime->sizePolicy().hasHeightForWidth());
        walltime->setSizePolicy(sizePolicy1);
        walltime->setMinimumSize(QSize(82, 0));
        walltime->setMaximumSize(QSize(82, 16777215));
        walltime->setMaxLength(10);

        gridLayout->addWidget(walltime, 1, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(QueueResourcesDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout_2, 1, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 2, 2, 1, 1);

        memory = new QSpinBox(QueueResourcesDialog);
        memory->setObjectName(QString::fromUtf8("memory"));
        sizePolicy1.setHeightForWidth(memory->sizePolicy().hasHeightForWidth());
        memory->setSizePolicy(sizePolicy1);
        memory->setMinimumSize(QSize(101, 0));
        memory->setMaximumSize(QSize(101, 16777215));
        memory->setMinimum(1);
        memory->setMaximum(99999);
        memory->setSingleStep(100);
        memory->setValue(1000);

        gridLayout->addWidget(memory, 2, 1, 1, 1);

        label_4 = new QLabel(QueueResourcesDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label_5 = new QLabel(QueueResourcesDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        label_6 = new QLabel(QueueResourcesDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        ncpus = new QSpinBox(QueueResourcesDialog);
        ncpus->setObjectName(QString::fromUtf8("ncpus"));
        ncpus->setMaximumSize(QSize(101, 16777215));
        ncpus->setMinimum(1);
        ncpus->setMaximum(999);
        ncpus->setValue(1);

        gridLayout->addWidget(ncpus, 4, 1, 1, 1);

        scratch = new QSpinBox(QueueResourcesDialog);
        scratch->setObjectName(QString::fromUtf8("scratch"));
        sizePolicy1.setHeightForWidth(scratch->sizePolicy().hasHeightForWidth());
        scratch->setSizePolicy(sizePolicy1);
        scratch->setMinimumSize(QSize(101, 0));
        scratch->setMaximumSize(QSize(101, 16777215));
        scratch->setMinimum(1);
        scratch->setMaximum(999999);
        scratch->setSingleStep(500);
        scratch->setValue(1000);

        gridLayout->addWidget(scratch, 3, 1, 1, 1);

        label_2 = new QLabel(QueueResourcesDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        queue = new QComboBox(QueueResourcesDialog);
        queue->setObjectName(QString::fromUtf8("queue"));

        horizontalLayout_3->addWidget(queue);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout_3, 0, 1, 1, 2);


        verticalLayout_2->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(QueueResourcesDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);

        QWidget::setTabOrder(buttonBox, queue);
        QWidget::setTabOrder(queue, walltime);
        QWidget::setTabOrder(walltime, memory);
        QWidget::setTabOrder(memory, scratch);
        QWidget::setTabOrder(scratch, ncpus);

        retranslateUi(QueueResourcesDialog);

        QMetaObject::connectSlotsByName(QueueResourcesDialog);
    } // setupUi

    void retranslateUi(QDialog *QueueResourcesDialog)
    {
        QueueResourcesDialog->setWindowTitle(QApplication::translate("QueueResourcesDialog", "Resource Limits", nullptr));
        label_3->setText(QApplication::translate("QueueResourcesDialog", "Wall Time", nullptr));
#ifndef QT_NO_TOOLTIP
        walltime->setToolTip(QApplication::translate("QueueResourcesDialog", "This value can be accessed by ${WALLTIME}\n"
"in the run file template", nullptr));
#endif // QT_NO_TOOLTIP
        walltime->setText(QApplication::translate("QueueResourcesDialog", "100:00:00", nullptr));
        label->setText(QApplication::translate("QueueResourcesDialog", "(h:mm:ss)", nullptr));
#ifndef QT_NO_TOOLTIP
        memory->setToolTip(QApplication::translate("QueueResourcesDialog", "This value can be accessed by ${MEMORY}\n"
"in the run file template", nullptr));
#endif // QT_NO_TOOLTIP
        memory->setSuffix(QApplication::translate("QueueResourcesDialog", " Mb", nullptr));
        label_4->setText(QApplication::translate("QueueResourcesDialog", "Memory", nullptr));
        label_5->setText(QApplication::translate("QueueResourcesDialog", "Scratch", nullptr));
        label_6->setText(QApplication::translate("QueueResourcesDialog", "CPUs", nullptr));
#ifndef QT_NO_TOOLTIP
        ncpus->setToolTip(QApplication::translate("QueueResourcesDialog", "This value can be accessed by ${NCPUS}\n"
"in the run file template", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        scratch->setToolTip(QApplication::translate("QueueResourcesDialog", "This value can be accessed by ${SCRATCH}\n"
"in the run file template", nullptr));
#endif // QT_NO_TOOLTIP
        scratch->setSuffix(QApplication::translate("QueueResourcesDialog", " Mb", nullptr));
        label_2->setText(QApplication::translate("QueueResourcesDialog", "Queue", nullptr));
#ifndef QT_NO_TOOLTIP
        queue->setToolTip(QApplication::translate("QueueResourcesDialog", "This value can be accessed by ${QUEUE}\n"
"in the run file template", nullptr));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class QueueResourcesDialog: public Ui_QueueResourcesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUEUERESOURCESDIALOG_H
