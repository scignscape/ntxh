/********************************************************************************
** Form generated from reading UI file 'CameraDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERADIALOG_H
#define UI_CAMERADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CameraDialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout;
    QRadioButton *perspectiveButton;
    QRadioButton *orthographicButton;
    QHBoxLayout *horizontalLayout;
    QLabel *fieldOfViewLabel;
    QSpinBox *fieldOfView;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_3;
    QDial *autoRotation;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *loopCheckBox;
    QCheckBox *bounceCheckBox;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QDoubleSpinBox *rValue;
    QLabel *thetaLabel;
    QSpinBox *thetaValue;
    QLabel *phiLabel;
    QSpinBox *phiValue;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QPushButton *stopButton;
    QPushButton *playButton;
    QPushButton *deleteFrameButton;
    QPushButton *addFrameButton;
    QLabel *label_2;
    QDoubleSpinBox *time;
    QPushButton *resetButton;
    QTableWidget *frameTable;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *okButton;

    void setupUi(QDialog *CameraDialog)
    {
        if (CameraDialog->objectName().isEmpty())
            CameraDialog->setObjectName(QString::fromUtf8("CameraDialog"));
        CameraDialog->resize(418, 558);
        verticalLayout_4 = new QVBoxLayout(CameraDialog);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        groupBox_3 = new QGroupBox(CameraDialog);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout = new QVBoxLayout(groupBox_3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        perspectiveButton = new QRadioButton(groupBox_3);
        perspectiveButton->setObjectName(QString::fromUtf8("perspectiveButton"));
        perspectiveButton->setChecked(true);

        verticalLayout->addWidget(perspectiveButton);

        orthographicButton = new QRadioButton(groupBox_3);
        orthographicButton->setObjectName(QString::fromUtf8("orthographicButton"));

        verticalLayout->addWidget(orthographicButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        fieldOfViewLabel = new QLabel(groupBox_3);
        fieldOfViewLabel->setObjectName(QString::fromUtf8("fieldOfViewLabel"));

        horizontalLayout->addWidget(fieldOfViewLabel);

        fieldOfView = new QSpinBox(groupBox_3);
        fieldOfView->setObjectName(QString::fromUtf8("fieldOfView"));
        fieldOfView->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        fieldOfView->setMinimum(5);
        fieldOfView->setMaximum(180);
        fieldOfView->setSingleStep(5);
        fieldOfView->setValue(45);

        horizontalLayout->addWidget(fieldOfView);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_4->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(CameraDialog);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_3 = new QVBoxLayout(groupBox_4);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        autoRotation = new QDial(groupBox_4);
        autoRotation->setObjectName(QString::fromUtf8("autoRotation"));
        autoRotation->setMinimum(-10);
        autoRotation->setMaximum(10);
        autoRotation->setNotchesVisible(true);

        verticalLayout_3->addWidget(autoRotation);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        loopCheckBox = new QCheckBox(groupBox_4);
        loopCheckBox->setObjectName(QString::fromUtf8("loopCheckBox"));

        horizontalLayout_6->addWidget(loopCheckBox);

        bounceCheckBox = new QCheckBox(groupBox_4);
        bounceCheckBox->setObjectName(QString::fromUtf8("bounceCheckBox"));

        horizontalLayout_6->addWidget(bounceCheckBox);


        verticalLayout_3->addLayout(horizontalLayout_6);


        horizontalLayout_4->addWidget(groupBox_4);


        verticalLayout_4->addLayout(horizontalLayout_4);

        groupBox_2 = new QGroupBox(CameraDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_5 = new QHBoxLayout(groupBox_2);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_5->addWidget(label);

        rValue = new QDoubleSpinBox(groupBox_2);
        rValue->setObjectName(QString::fromUtf8("rValue"));
        rValue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        rValue->setMinimum(0.000000000000000);
        rValue->setMaximum(999.990000000000009);

        horizontalLayout_5->addWidget(rValue);

        thetaLabel = new QLabel(groupBox_2);
        thetaLabel->setObjectName(QString::fromUtf8("thetaLabel"));

        horizontalLayout_5->addWidget(thetaLabel);

        thetaValue = new QSpinBox(groupBox_2);
        thetaValue->setObjectName(QString::fromUtf8("thetaValue"));
        thetaValue->setWrapping(true);
        thetaValue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        thetaValue->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        thetaValue->setMaximum(180);
        thetaValue->setSingleStep(15);
        thetaValue->setValue(0);

        horizontalLayout_5->addWidget(thetaValue);

        phiLabel = new QLabel(groupBox_2);
        phiLabel->setObjectName(QString::fromUtf8("phiLabel"));

        horizontalLayout_5->addWidget(phiLabel);

        phiValue = new QSpinBox(groupBox_2);
        phiValue->setObjectName(QString::fromUtf8("phiValue"));
        phiValue->setWrapping(true);
        phiValue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        phiValue->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        phiValue->setMaximum(360);
        phiValue->setSingleStep(15);

        horizontalLayout_5->addWidget(phiValue);

        horizontalSpacer_4 = new QSpacerItem(55, 35, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout_4->addWidget(groupBox_2);

        groupBox = new QGroupBox(CameraDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        stopButton = new QPushButton(groupBox);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));

        gridLayout->addWidget(stopButton, 1, 3, 1, 1);

        playButton = new QPushButton(groupBox);
        playButton->setObjectName(QString::fromUtf8("playButton"));
        playButton->setAutoDefault(false);

        gridLayout->addWidget(playButton, 0, 3, 1, 1);

        deleteFrameButton = new QPushButton(groupBox);
        deleteFrameButton->setObjectName(QString::fromUtf8("deleteFrameButton"));

        gridLayout->addWidget(deleteFrameButton, 1, 2, 1, 1);

        addFrameButton = new QPushButton(groupBox);
        addFrameButton->setObjectName(QString::fromUtf8("addFrameButton"));
        addFrameButton->setAutoDefault(false);

        gridLayout->addWidget(addFrameButton, 0, 2, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        time = new QDoubleSpinBox(groupBox);
        time->setObjectName(QString::fromUtf8("time"));
        time->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(time, 0, 1, 1, 1);

        resetButton = new QPushButton(groupBox);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        resetButton->setAutoDefault(false);

        gridLayout->addWidget(resetButton, 1, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        frameTable = new QTableWidget(groupBox);
        if (frameTable->columnCount() < 2)
            frameTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        frameTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        frameTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        frameTable->setObjectName(QString::fromUtf8("frameTable"));

        verticalLayout_2->addWidget(frameTable);


        verticalLayout_4->addWidget(groupBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        okButton = new QPushButton(CameraDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        horizontalLayout_2->addWidget(okButton);


        verticalLayout_4->addLayout(horizontalLayout_2);

        QWidget::setTabOrder(frameTable, autoRotation);
        QWidget::setTabOrder(autoRotation, perspectiveButton);
        QWidget::setTabOrder(perspectiveButton, orthographicButton);
        QWidget::setTabOrder(orthographicButton, rValue);
        QWidget::setTabOrder(rValue, thetaValue);
        QWidget::setTabOrder(thetaValue, okButton);
        QWidget::setTabOrder(okButton, fieldOfView);
        QWidget::setTabOrder(fieldOfView, phiValue);

        retranslateUi(CameraDialog);

        QMetaObject::connectSlotsByName(CameraDialog);
    } // setupUi

    void retranslateUi(QDialog *CameraDialog)
    {
        CameraDialog->setWindowTitle(QApplication::translate("CameraDialog", "Configure Camera", nullptr));
        groupBox_3->setTitle(QApplication::translate("CameraDialog", "Projection", nullptr));
        perspectiveButton->setText(QApplication::translate("CameraDialog", "Perspective", nullptr));
        orthographicButton->setText(QApplication::translate("CameraDialog", "Orthographic", nullptr));
        fieldOfViewLabel->setText(QApplication::translate("CameraDialog", "Field of View", nullptr));
        groupBox_4->setTitle(QApplication::translate("CameraDialog", "Auto Rotation", nullptr));
        loopCheckBox->setText(QApplication::translate("CameraDialog", "Loop", nullptr));
        bounceCheckBox->setText(QApplication::translate("CameraDialog", "Bounce", nullptr));
        groupBox_2->setTitle(QApplication::translate("CameraDialog", "Position", nullptr));
        label->setText(QApplication::translate("CameraDialog", "r", nullptr));
        thetaLabel->setText(QApplication::translate("CameraDialog", "t", nullptr));
        phiLabel->setText(QApplication::translate("CameraDialog", "<html><head/><body><p>p</p></body></html>", nullptr));
        groupBox->setTitle(QApplication::translate("CameraDialog", "Path", nullptr));
        stopButton->setText(QApplication::translate("CameraDialog", "Stop", nullptr));
        playButton->setText(QApplication::translate("CameraDialog", "Play", nullptr));
        deleteFrameButton->setText(QApplication::translate("CameraDialog", "Delete Frame", nullptr));
        addFrameButton->setText(QApplication::translate("CameraDialog", "Add Frame", nullptr));
        label_2->setText(QApplication::translate("CameraDialog", "Time", nullptr));
        time->setSuffix(QApplication::translate("CameraDialog", "s", nullptr));
        resetButton->setText(QApplication::translate("CameraDialog", "Reset", nullptr));
        QTableWidgetItem *___qtablewidgetitem = frameTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("CameraDialog", "Time", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = frameTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("CameraDialog", "Frame", nullptr));
        okButton->setText(QApplication::translate("CameraDialog", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CameraDialog: public Ui_CameraDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERADIALOG_H
