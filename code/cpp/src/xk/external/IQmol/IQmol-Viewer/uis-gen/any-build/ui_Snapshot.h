/********************************************************************************
** Form generated from reading UI file 'Snapshot.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SNAPSHOT_H
#define UI_SNAPSHOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QSpinBox *spinBox;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QLabel *label_3;
    QLabel *label_4;
    QCheckBox *checkBox_6;
    QLabel *label_5;
    QSpinBox *spinBox_4;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(591, 401);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(230, 340, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 60, 61, 17));
        comboBox = new QComboBox(Dialog);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(170, 50, 111, 26));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 100, 91, 17));
        spinBox = new QSpinBox(Dialog);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(200, 100, 61, 25));
        spinBox->setMaximum(16);
        checkBox = new QCheckBox(Dialog);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(100, 220, 141, 21));
        checkBox_2 = new QCheckBox(Dialog);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(350, 210, 151, 21));
        checkBox_3 = new QCheckBox(Dialog);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(100, 240, 87, 21));
        checkBox_4 = new QCheckBox(Dialog);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(100, 310, 161, 21));
        checkBox_5 = new QCheckBox(Dialog);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setGeometry(QRect(100, 260, 87, 21));
        spinBox_2 = new QSpinBox(Dialog);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(100, 150, 63, 25));
        spinBox_3 = new QSpinBox(Dialog);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setGeometry(QRect(250, 150, 63, 25));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 160, 61, 17));
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(190, 150, 61, 17));
        checkBox_6 = new QCheckBox(Dialog);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));
        checkBox_6->setGeometry(QRect(50, 180, 161, 21));
        label_5 = new QLabel(Dialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(360, 190, 91, 17));
        spinBox_4 = new QSpinBox(Dialog);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        spinBox_4->setGeometry(QRect(450, 180, 63, 25));

        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        comboBox->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QApplication::translate("Dialog", "Format", nullptr));
        comboBox->setItemText(0, QApplication::translate("Dialog", "BMP", nullptr));
        comboBox->setItemText(1, QApplication::translate("Dialog", "JPG", nullptr));
        comboBox->setItemText(2, QApplication::translate("Dialog", "PNG", nullptr));
        comboBox->setItemText(3, QApplication::translate("Dialog", "TIFF", nullptr));
        comboBox->setItemText(4, QApplication::translate("Dialog", "PDF", nullptr));
        comboBox->setItemText(5, QApplication::translate("Dialog", "EPS", nullptr));
        comboBox->setItemText(6, QApplication::translate("Dialog", "SVG", nullptr));

        label_2->setText(QApplication::translate("Dialog", "Oversampling", nullptr));
        spinBox->setPrefix(QApplication::translate("Dialog", "x ", nullptr));
        checkBox->setText(QApplication::translate("Dialog", "Crop Bounding Box", nullptr));
        checkBox_2->setText(QApplication::translate("Dialog", "Include Background", nullptr));
        checkBox_3->setText(QApplication::translate("Dialog", "Tree Sort", nullptr));
        checkBox_4->setText(QApplication::translate("Dialog", "Disable Transparency", nullptr));
        checkBox_5->setText(QApplication::translate("Dialog", "Compress", nullptr));
        label_3->setText(QApplication::translate("Dialog", "Width", nullptr));
        label_4->setText(QApplication::translate("Dialog", "Height", nullptr));
        checkBox_6->setText(QApplication::translate("Dialog", "Preserve Aspect Ratio", nullptr));
        label_5->setText(QApplication::translate("Dialog", "Image Quality", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SNAPSHOT_H