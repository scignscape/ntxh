/********************************************************************************
** Form generated from reading UI file 'CameraDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERADIALOG_H
#define UI_CAMERADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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
            CameraDialog->setObjectName(QStringLiteral("CameraDialog"));
        CameraDialog->resize(418, 558);
        verticalLayout_4 = new QVBoxLayout(CameraDialog);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        groupBox_3 = new QGroupBox(CameraDialog);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout = new QVBoxLayout(groupBox_3);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        perspectiveButton = new QRadioButton(groupBox_3);
        perspectiveButton->setObjectName(QStringLiteral("perspectiveButton"));
        perspectiveButton->setChecked(true);

        verticalLayout->addWidget(perspectiveButton);

        orthographicButton = new QRadioButton(groupBox_3);
        orthographicButton->setObjectName(QStringLiteral("orthographicButton"));

        verticalLayout->addWidget(orthographicButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        fieldOfViewLabel = new QLabel(groupBox_3);
        fieldOfViewLabel->setObjectName(QStringLiteral("fieldOfViewLabel"));

        horizontalLayout->addWidget(fieldOfViewLabel);

        fieldOfView = new QSpinBox(groupBox_3);
        fieldOfView->setObjectName(QStringLiteral("fieldOfView"));
        fieldOfView->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        fieldOfView->setMinimum(5);
        fieldOfView->setMaximum(180);
        fieldOfView->setSingleStep(5);
        fieldOfView->setValue(45);

        horizontalLayout->addWidget(fieldOfView);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_4->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(CameraDialog);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        verticalLayout_3 = new QVBoxLayout(groupBox_4);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        autoRotation = new QDial(groupBox_4);
        autoRotation->setObjectName(QStringLiteral("autoRotation"));
        autoRotation->setMinimum(-10);
        autoRotation->setMaximum(10);
        autoRotation->setNotchesVisible(true);

        verticalLayout_3->addWidget(autoRotation);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        loopCheckBox = new QCheckBox(groupBox_4);
        loopCheckBox->setObjectName(QStringLiteral("loopCheckBox"));

        horizontalLayout_6->addWidget(loopCheckBox);

        bounceCheckBox = new QCheckBox(groupBox_4);
        bounceCheckBox->setObjectName(QStringLiteral("bounceCheckBox"));

        horizontalLayout_6->addWidget(bounceCheckBox);


        verticalLayout_3->addLayout(horizontalLayout_6);


        horizontalLayout_4->addWidget(groupBox_4);


        verticalLayout_4->addLayout(horizontalLayout_4);

        groupBox_2 = new QGroupBox(CameraDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout_5 = new QHBoxLayout(groupBox_2);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_5->addWidget(label);

        rValue = new QDoubleSpinBox(groupBox_2);
        rValue->setObjectName(QStringLiteral("rValue"));
        rValue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        rValue->setMinimum(0);
        rValue->setMaximum(999.99);

        horizontalLayout_5->addWidget(rValue);

        thetaLabel = new QLabel(groupBox_2);
        thetaLabel->setObjectName(QStringLiteral("thetaLabel"));

        horizontalLayout_5->addWidget(thetaLabel);

        thetaValue = new QSpinBox(groupBox_2);
        thetaValue->setObjectName(QStringLiteral("thetaValue"));
        thetaValue->setWrapping(true);
        thetaValue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        thetaValue->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        thetaValue->setMaximum(180);
        thetaValue->setSingleStep(15);
        thetaValue->setValue(0);

        horizontalLayout_5->addWidget(thetaValue);

        phiLabel = new QLabel(groupBox_2);
        phiLabel->setObjectName(QStringLiteral("phiLabel"));

        horizontalLayout_5->addWidget(phiLabel);

        phiValue = new QSpinBox(groupBox_2);
        phiValue->setObjectName(QStringLiteral("phiValue"));
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
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        stopButton = new QPushButton(groupBox);
        stopButton->setObjectName(QStringLiteral("stopButton"));

        gridLayout->addWidget(stopButton, 1, 3, 1, 1);

        playButton = new QPushButton(groupBox);
        playButton->setObjectName(QStringLiteral("playButton"));
        playButton->setAutoDefault(false);

        gridLayout->addWidget(playButton, 0, 3, 1, 1);

        deleteFrameButton = new QPushButton(groupBox);
        deleteFrameButton->setObjectName(QStringLiteral("deleteFrameButton"));

        gridLayout->addWidget(deleteFrameButton, 1, 2, 1, 1);

        addFrameButton = new QPushButton(groupBox);
        addFrameButton->setObjectName(QStringLiteral("addFrameButton"));
        addFrameButton->setAutoDefault(false);

        gridLayout->addWidget(addFrameButton, 0, 2, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        time = new QDoubleSpinBox(groupBox);
        time->setObjectName(QStringLiteral("time"));
        time->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(time, 0, 1, 1, 1);

        resetButton = new QPushButton(groupBox);
        resetButton->setObjectName(QStringLiteral("resetButton"));
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
        frameTable->setObjectName(QStringLiteral("frameTable"));

        verticalLayout_2->addWidget(frameTable);


        verticalLayout_4->addWidget(groupBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        okButton = new QPushButton(CameraDialog);
        okButton->setObjectName(QStringLiteral("okButton"));

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
        CameraDialog->setWindowTitle(QApplication::translate("CameraDialog", "Configure Camera", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("CameraDialog", "Projection", Q_NULLPTR));
        perspectiveButton->setText(QApplication::translate("CameraDialog", "Perspective", Q_NULLPTR));
        orthographicButton->setText(QApplication::translate("CameraDialog", "Orthographic", Q_NULLPTR));
        fieldOfViewLabel->setText(QApplication::translate("CameraDialog", "Field of View", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("CameraDialog", "Auto Rotation", Q_NULLPTR));
        loopCheckBox->setText(QApplication::translate("CameraDialog", "Loop", Q_NULLPTR));
        bounceCheckBox->setText(QApplication::translate("CameraDialog", "Bounce", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("CameraDialog", "Position", Q_NULLPTR));
        label->setText(QApplication::translate("CameraDialog", "r", Q_NULLPTR));
        thetaLabel->setText(QApplication::translate("CameraDialog", "t", Q_NULLPTR));
        phiLabel->setText(QApplication::translate("CameraDialog", "<html><head/><body><p>p</p></body></html>", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("CameraDialog", "Path", Q_NULLPTR));
        stopButton->setText(QApplication::translate("CameraDialog", "Stop", Q_NULLPTR));
        playButton->setText(QApplication::translate("CameraDialog", "Play", Q_NULLPTR));
        deleteFrameButton->setText(QApplication::translate("CameraDialog", "Delete Frame", Q_NULLPTR));
        addFrameButton->setText(QApplication::translate("CameraDialog", "Add Frame", Q_NULLPTR));
        label_2->setText(QApplication::translate("CameraDialog", "Time", Q_NULLPTR));
        time->setSuffix(QApplication::translate("CameraDialog", "s", Q_NULLPTR));
        resetButton->setText(QApplication::translate("CameraDialog", "Reset", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = frameTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("CameraDialog", "Time", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = frameTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("CameraDialog", "Frame", Q_NULLPTR));
        okButton->setText(QApplication::translate("CameraDialog", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CameraDialog: public Ui_CameraDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERADIALOG_H
