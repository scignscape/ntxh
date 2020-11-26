/********************************************************************************
** Form generated from reading UI file 'GeometryConstraintDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GEOMETRYCONSTRAINTDIALOG_H
#define UI_GEOMETRYCONSTRAINTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QSpinBox *atom4;
    QDoubleSpinBox *constraintValue;
    QLabel *label_2;
    QLabel *label_4;
    QSpinBox *atom1;
    QLabel *label;
    QComboBox *constraintType;
    QToolButton *addConstraint;
    QSpinBox *atom2;
    QLabel *label_5;
    QLabel *label_3;
    QSpinBox *atom3;
    QSpacerItem *spacerItem;
    QHBoxLayout *hboxLayout;
    QGroupBox *groupBox_3;
    QVBoxLayout *vboxLayout1;
    QHBoxLayout *hboxLayout1;
    QLabel *label_8;
    QComboBox *dummyType;
    QSpacerItem *spacerItem1;
    QHBoxLayout *hboxLayout2;
    QLabel *label_9;
    QSpinBox *dAtom1;
    QLabel *label_10;
    QSpinBox *dAtom2;
    QLabel *label_11;
    QSpinBox *dAtom3;
    QSpacerItem *spacerItem2;
    QToolButton *addDummyAtom;
    QGroupBox *groupBox_2;
    QVBoxLayout *vboxLayout2;
    QHBoxLayout *hboxLayout3;
    QLabel *label_7;
    QSpacerItem *spacerItem3;
    QSpinBox *fixedAtom;
    QHBoxLayout *hboxLayout4;
    QLabel *label_14;
    QCheckBox *fixX;
    QCheckBox *fixY;
    QCheckBox *fixZ;
    QSpacerItem *spacerItem4;
    QToolButton *addFixedAtom;
    QGroupBox *groupBox_4;
    QHBoxLayout *hboxLayout5;
    QLabel *label_13;
    QSpinBox *targetAtom;
    QLabel *label_12;
    QSpinBox *cAtom1;
    QSpinBox *cAtom2;
    QSpinBox *cAtom3;
    QSpinBox *cAtom4;
    QSpacerItem *spacerItem5;
    QToolButton *addConnectivityButton;
    QTableWidget *constraintTable;
    QHBoxLayout *hboxLayout6;
    QSpacerItem *spacerItem6;
    QPushButton *deleteButton;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(637, 566);
        QSizePolicy sizePolicy(static_cast<QSizePolicy::Policy>(0), static_cast<QSizePolicy::Policy>(0));
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog->sizePolicy().hasHeightForWidth());
        Dialog->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Lucida Grande"));
        font.setPointSize(13);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(50);
        font.setStrikeOut(false);
        Dialog->setFont(font);
        vboxLayout = new QVBoxLayout(Dialog);
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout->setContentsMargins(9, 9, 9, 9);
#endif
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
#ifndef Q_OS_MAC
        gridLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(9, 9, 9, 9);
#endif
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 0, 5, 1, 1);

        atom4 = new QSpinBox(groupBox);
        atom4->setObjectName(QString::fromUtf8("atom4"));
        atom4->setMaximum(999);
        atom4->setMinimum(1);
        atom4->setValue(4);

        gridLayout->addWidget(atom4, 1, 4, 1, 1);

        constraintValue = new QDoubleSpinBox(groupBox);
        constraintValue->setObjectName(QString::fromUtf8("constraintValue"));
        constraintValue->setWrapping(false);
        constraintValue->setDecimals(3);
        constraintValue->setMaximum(180.000000000000000);
        constraintValue->setMinimum(-180.000000000000000);
        constraintValue->setSingleStep(0.001000000000000);

        gridLayout->addWidget(constraintValue, 1, 5, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 3, 1, 1);

        atom1 = new QSpinBox(groupBox);
        atom1->setObjectName(QString::fromUtf8("atom1"));
        atom1->setMaximum(999);
        atom1->setMinimum(1);

        gridLayout->addWidget(atom1, 1, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        constraintType = new QComboBox(groupBox);
        constraintType->addItem(QString());
        constraintType->addItem(QString());
        constraintType->addItem(QString());
        constraintType->addItem(QString());
        constraintType->addItem(QString());
        constraintType->addItem(QString());
        constraintType->setObjectName(QString::fromUtf8("constraintType"));

        gridLayout->addWidget(constraintType, 1, 0, 1, 1);

        addConstraint = new QToolButton(groupBox);
        addConstraint->setObjectName(QString::fromUtf8("addConstraint"));
        const QIcon icon = QIcon(QString::fromUtf8("resources/icons/plus.png"));
        addConstraint->setIcon(icon);

        gridLayout->addWidget(addConstraint, 1, 7, 1, 1);

        atom2 = new QSpinBox(groupBox);
        atom2->setObjectName(QString::fromUtf8("atom2"));
        atom2->setMaximum(999);
        atom2->setMinimum(1);
        atom2->setValue(2);

        gridLayout->addWidget(atom2, 1, 2, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 4, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        atom3 = new QSpinBox(groupBox);
        atom3->setObjectName(QString::fromUtf8("atom3"));
        atom3->setMaximum(999);
        atom3->setMinimum(1);
        atom3->setValue(3);

        gridLayout->addWidget(atom3, 1, 3, 1, 1);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem, 1, 6, 1, 1);


        vboxLayout->addWidget(groupBox);

        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        groupBox_3 = new QGroupBox(Dialog);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        vboxLayout1 = new QVBoxLayout(groupBox_3);
#ifndef Q_OS_MAC
        vboxLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout1->setContentsMargins(9, 9, 9, 9);
#endif
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        hboxLayout1 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout1->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
#endif
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        hboxLayout1->addWidget(label_8);

        dummyType = new QComboBox(groupBox_3);
        dummyType->addItem(QString());
        dummyType->addItem(QString());
        dummyType->setObjectName(QString::fromUtf8("dummyType"));

        hboxLayout1->addWidget(dummyType);

        spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem1);


        vboxLayout1->addLayout(hboxLayout1);

        hboxLayout2 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout2->setSpacing(6);
#endif
        hboxLayout2->setContentsMargins(0, 0, 0, 0);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        hboxLayout2->addWidget(label_9);

        dAtom1 = new QSpinBox(groupBox_3);
        dAtom1->setObjectName(QString::fromUtf8("dAtom1"));
        dAtom1->setMinimum(1);

        hboxLayout2->addWidget(dAtom1);

        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        hboxLayout2->addWidget(label_10);

        dAtom2 = new QSpinBox(groupBox_3);
        dAtom2->setObjectName(QString::fromUtf8("dAtom2"));
        dAtom2->setMinimum(1);
        dAtom2->setValue(2);

        hboxLayout2->addWidget(dAtom2);

        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        hboxLayout2->addWidget(label_11);

        dAtom3 = new QSpinBox(groupBox_3);
        dAtom3->setObjectName(QString::fromUtf8("dAtom3"));
        dAtom3->setMinimum(1);
        dAtom3->setValue(3);

        hboxLayout2->addWidget(dAtom3);

        spacerItem2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacerItem2);

        addDummyAtom = new QToolButton(groupBox_3);
        addDummyAtom->setObjectName(QString::fromUtf8("addDummyAtom"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Lucida Grande"));
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setWeight(50);
        font1.setStrikeOut(false);
        addDummyAtom->setFont(font1);
        addDummyAtom->setIcon(icon);

        hboxLayout2->addWidget(addDummyAtom);


        vboxLayout1->addLayout(hboxLayout2);


        hboxLayout->addWidget(groupBox_3);

        groupBox_2 = new QGroupBox(Dialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        vboxLayout2 = new QVBoxLayout(groupBox_2);
#ifndef Q_OS_MAC
        vboxLayout2->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout2->setContentsMargins(9, 9, 9, 9);
#endif
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        hboxLayout3 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout3->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout3->setContentsMargins(0, 0, 0, 0);
#endif
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        hboxLayout3->addWidget(label_7);

        spacerItem3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout3->addItem(spacerItem3);

        fixedAtom = new QSpinBox(groupBox_2);
        fixedAtom->setObjectName(QString::fromUtf8("fixedAtom"));
        fixedAtom->setMinimum(1);

        hboxLayout3->addWidget(fixedAtom);


        vboxLayout2->addLayout(hboxLayout3);

        hboxLayout4 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout4->setSpacing(6);
#endif
        hboxLayout4->setContentsMargins(0, 0, 0, 0);
        hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        hboxLayout4->addWidget(label_14);

        fixX = new QCheckBox(groupBox_2);
        fixX->setObjectName(QString::fromUtf8("fixX"));
        fixX->setChecked(true);

        hboxLayout4->addWidget(fixX);

        fixY = new QCheckBox(groupBox_2);
        fixY->setObjectName(QString::fromUtf8("fixY"));
        fixY->setChecked(true);

        hboxLayout4->addWidget(fixY);

        fixZ = new QCheckBox(groupBox_2);
        fixZ->setObjectName(QString::fromUtf8("fixZ"));
        fixZ->setChecked(true);

        hboxLayout4->addWidget(fixZ);

        spacerItem4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout4->addItem(spacerItem4);

        addFixedAtom = new QToolButton(groupBox_2);
        addFixedAtom->setObjectName(QString::fromUtf8("addFixedAtom"));
        addFixedAtom->setIcon(icon);

        hboxLayout4->addWidget(addFixedAtom);


        vboxLayout2->addLayout(hboxLayout4);


        hboxLayout->addWidget(groupBox_2);


        vboxLayout->addLayout(hboxLayout);

        groupBox_4 = new QGroupBox(Dialog);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        hboxLayout5 = new QHBoxLayout(groupBox_4);
#ifndef Q_OS_MAC
        hboxLayout5->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout5->setContentsMargins(9, 9, 9, 9);
#endif
        hboxLayout5->setObjectName(QString::fromUtf8("hboxLayout5"));
        label_13 = new QLabel(groupBox_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        hboxLayout5->addWidget(label_13);

        targetAtom = new QSpinBox(groupBox_4);
        targetAtom->setObjectName(QString::fromUtf8("targetAtom"));

        hboxLayout5->addWidget(targetAtom);

        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        hboxLayout5->addWidget(label_12);

        cAtom1 = new QSpinBox(groupBox_4);
        cAtom1->setObjectName(QString::fromUtf8("cAtom1"));

        hboxLayout5->addWidget(cAtom1);

        cAtom2 = new QSpinBox(groupBox_4);
        cAtom2->setObjectName(QString::fromUtf8("cAtom2"));

        hboxLayout5->addWidget(cAtom2);

        cAtom3 = new QSpinBox(groupBox_4);
        cAtom3->setObjectName(QString::fromUtf8("cAtom3"));

        hboxLayout5->addWidget(cAtom3);

        cAtom4 = new QSpinBox(groupBox_4);
        cAtom4->setObjectName(QString::fromUtf8("cAtom4"));

        hboxLayout5->addWidget(cAtom4);

        spacerItem5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout5->addItem(spacerItem5);

        addConnectivityButton = new QToolButton(groupBox_4);
        addConnectivityButton->setObjectName(QString::fromUtf8("addConnectivityButton"));
        addConnectivityButton->setIcon(icon);

        hboxLayout5->addWidget(addConnectivityButton);


        vboxLayout->addWidget(groupBox_4);

        constraintTable = new QTableWidget(Dialog);
        if (constraintTable->columnCount() < 7)
            constraintTable->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        constraintTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        constraintTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        constraintTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        constraintTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        constraintTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        constraintTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        constraintTable->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        constraintTable->setObjectName(QString::fromUtf8("constraintTable"));
        constraintTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        constraintTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        constraintTable->setAlternatingRowColors(true);
        constraintTable->setSelectionMode(QAbstractItemView::SingleSelection);
        constraintTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        constraintTable->setShowGrid(false);
        constraintTable->setGridStyle(Qt::NoPen);
        constraintTable->setSortingEnabled(false);

        vboxLayout->addWidget(constraintTable);

        hboxLayout6 = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout6->setSpacing(6);
#endif
        hboxLayout6->setContentsMargins(0, 0, 0, 0);
        hboxLayout6->setObjectName(QString::fromUtf8("hboxLayout6"));
        spacerItem6 = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout6->addItem(spacerItem6);

        deleteButton = new QPushButton(Dialog);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        hboxLayout6->addWidget(deleteButton);

        okButton = new QPushButton(Dialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        hboxLayout6->addWidget(okButton);

        cancelButton = new QPushButton(Dialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        hboxLayout6->addWidget(cancelButton);


        vboxLayout->addLayout(hboxLayout6);

        QWidget::setTabOrder(constraintType, atom1);
        QWidget::setTabOrder(atom1, atom2);
        QWidget::setTabOrder(atom2, atom3);
        QWidget::setTabOrder(atom3, atom4);
        QWidget::setTabOrder(atom4, constraintValue);
        QWidget::setTabOrder(constraintValue, addConstraint);
        QWidget::setTabOrder(addConstraint, fixedAtom);
        QWidget::setTabOrder(fixedAtom, fixX);
        QWidget::setTabOrder(fixX, fixY);
        QWidget::setTabOrder(fixY, fixZ);
        QWidget::setTabOrder(fixZ, addFixedAtom);
        QWidget::setTabOrder(addFixedAtom, dummyType);
        QWidget::setTabOrder(dummyType, dAtom1);
        QWidget::setTabOrder(dAtom1, dAtom2);
        QWidget::setTabOrder(dAtom2, dAtom3);
        QWidget::setTabOrder(dAtom3, addDummyAtom);
        QWidget::setTabOrder(addDummyAtom, constraintTable);
        QWidget::setTabOrder(constraintTable, deleteButton);
        QWidget::setTabOrder(deleteButton, okButton);
        QWidget::setTabOrder(okButton, cancelButton);

        retranslateUi(Dialog);
        QObject::connect(okButton, SIGNAL(clicked()), Dialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), Dialog, SLOT(reject()));

        okButton->setDefault(true);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Edit Constraints", nullptr));
        groupBox->setTitle(QApplication::translate("Dialog", "Constraint", nullptr));
        label_6->setText(QApplication::translate("Dialog", "Value", nullptr));
        label_2->setText(QApplication::translate("Dialog", "Atom A", nullptr));
        label_4->setText(QApplication::translate("Dialog", "Atom C", nullptr));
        label->setText(QApplication::translate("Dialog", "Type:", nullptr));
        constraintType->setItemText(0, QApplication::translate("Dialog", "Stretch", nullptr));
        constraintType->setItemText(1, QApplication::translate("Dialog", "Bend", nullptr));
        constraintType->setItemText(2, QApplication::translate("Dialog", "Out of plane", nullptr));
        constraintType->setItemText(3, QApplication::translate("Dialog", "Dihedral", nullptr));
        constraintType->setItemText(4, QApplication::translate("Dialog", "Co-planar", nullptr));
        constraintType->setItemText(5, QApplication::translate("Dialog", "Perpendicular", nullptr));

#ifndef QT_NO_TOOLTIP
        addConstraint->setToolTip(QApplication::translate("Dialog", "Add constraint", nullptr));
#endif // QT_NO_TOOLTIP
        addConstraint->setText(QApplication::translate("Dialog", "+", nullptr));
        label_5->setText(QApplication::translate("Dialog", "Atom D", nullptr));
        label_3->setText(QApplication::translate("Dialog", "Atom B", nullptr));
        groupBox_3->setTitle(QApplication::translate("Dialog", "Dummy Atom:", nullptr));
        label_8->setText(QApplication::translate("Dialog", "Type:", nullptr));
        dummyType->setItemText(0, QApplication::translate("Dialog", "Plane Normal", nullptr));
        dummyType->setItemText(1, QApplication::translate("Dialog", "Angle Bisector", nullptr));

        label_9->setText(QApplication::translate("Dialog", "Atom A", nullptr));
        label_10->setText(QApplication::translate("Dialog", "B", nullptr));
        label_11->setText(QApplication::translate("Dialog", "C", nullptr));
#ifndef QT_NO_TOOLTIP
        addDummyAtom->setToolTip(QApplication::translate("Dialog", "Add constraint", nullptr));
#endif // QT_NO_TOOLTIP
        addDummyAtom->setText(QApplication::translate("Dialog", "+", nullptr));
        groupBox_2->setTitle(QApplication::translate("Dialog", "Fixed Atom:", nullptr));
        label_7->setText(QApplication::translate("Dialog", "Atom Number:", nullptr));
        label_14->setText(QApplication::translate("Dialog", "Fix", nullptr));
        fixX->setText(QApplication::translate("Dialog", "X", nullptr));
        fixY->setText(QApplication::translate("Dialog", "Y", nullptr));
        fixZ->setText(QApplication::translate("Dialog", "Z", nullptr));
#ifndef QT_NO_TOOLTIP
        addFixedAtom->setToolTip(QApplication::translate("Dialog", "Add constraint", nullptr));
#endif // QT_NO_TOOLTIP
        addFixedAtom->setText(QApplication::translate("Dialog", "+", nullptr));
        groupBox_4->setTitle(QApplication::translate("Dialog", "Add Connectivity", nullptr));
        label_13->setText(QApplication::translate("Dialog", "Atom", nullptr));
        label_12->setText(QApplication::translate("Dialog", "Connect To Atoms", nullptr));
#ifndef QT_NO_TOOLTIP
        addConnectivityButton->setToolTip(QApplication::translate("Dialog", "Add constraint", nullptr));
#endif // QT_NO_TOOLTIP
        addConnectivityButton->setText(QApplication::translate("Dialog", "+", nullptr));
        QTableWidgetItem *___qtablewidgetitem = constraintTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Dialog", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = constraintTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Dialog", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = constraintTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Dialog", "Atom 1", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = constraintTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Dialog", "Atom 2", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = constraintTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Dialog", "Atom 3", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = constraintTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("Dialog", "Atom 4", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = constraintTable->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("Dialog", "Value", nullptr));
        deleteButton->setText(QApplication::translate("Dialog", "Delete", nullptr));
        okButton->setText(QApplication::translate("Dialog", "OK", nullptr));
        cancelButton->setText(QApplication::translate("Dialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GEOMETRYCONSTRAINTDIALOG_H