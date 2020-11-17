/********************************************************************************
** Form generated from reading UI file 'ToolBar.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLBAR_H
#define UI_TOOLBAR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ToolBar
{
public:
    QHBoxLayout *horizontalLayout;
    QToolButton *newMoleculeButton;
    QToolButton *openButton;
    QToolButton *saveButton;
    QFrame *line;
    QToolButton *manipulateButton;
    QFrame *line_4;
    QToolButton *buildButton;
    QToolButton *elementSelectButton;
    QToolButton *fragmentSelectButton;
    QToolButton *addHydrogensButton;
    QToolButton *minimizeEnergyButton;
    QFrame *line_2;
    QToolButton *selectButton;
    QToolButton *deleteSelectionButton;
    QFrame *line_3;
    QToolButton *takeSnapshotButton;
    QToolButton *recordButton;
    QToolButton *fullScreenButton;
    QFrame *line_5;
    QToolButton *showHelpButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *ToolBar)
    {
        if (ToolBar->objectName().isEmpty())
            ToolBar->setObjectName(QString::fromUtf8("ToolBar"));
        ToolBar->resize(805, 56);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ToolBar->sizePolicy().hasHeightForWidth());
        ToolBar->setSizePolicy(sizePolicy);
        ToolBar->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"   color: #333;\n"
"   background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, \n"
"          stop: 0 #fff,\n"
"          stop: 0.5 #eee, \n"
"          stop: 1 #999);\n"
"   border-width: 2px;\n"
"   border-color: #333;\n"
"   border-style: solid;\n"
"   border-radius: 5;\n"
"   padding: 0px;\n"
"   font-size: 24px;\n"
"   min-width: 34px;\n"
"   max-width: 34px;\n"
"   min-height: 34px;\n"
"   max-height: 34px;\n"
"}\n"
"\n"
"QToolButton:disabled {\n"
"  background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, \n"
"          stop: 0 #fff,\n"
"          stop: 0.5 #eee, \n"
"          stop: 1 #bbb);\n"
"   border-color: #aaa;\n"
"   color: #aaa;\n"
"}\n"
"\n"
"QToolButton:pressed {\n"
"   background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, \n"
"          stop: 0 #999,\n"
"          stop: 0.5 #eee, \n"
"          stop: 1 #fff);\n"
"}\n"
"\n"
"\n"
"QToolButton:checked {\n"
"   border-color: #b00;\n"
"   background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, \n"
""
                        "          stop: 0 #999,\n"
"          stop: 0.5 #eee, \n"
"          stop: 1 #fff);\n"
"}\n"
"\n"
"\n"
" QToolTip {\n"
"    border: 2px solid darkkhaki;\n"
"    padding: 2px;\n"
"    border-radius: 3px;\n"
"    opacity: 500;\n"
"    font-size: 12px;\n"
"    color: #000;\n"
"    background-color: #EEE;\n"
"}"));
        horizontalLayout = new QHBoxLayout(ToolBar);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 6);
        newMoleculeButton = new QToolButton(ToolBar);
        newMoleculeButton->setObjectName(QString::fromUtf8("newMoleculeButton"));
        newMoleculeButton->setEnabled(true);
        newMoleculeButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/NewDocument.png"), QSize(), QIcon::Normal, QIcon::Off);
        newMoleculeButton->setIcon(icon);
        newMoleculeButton->setIconSize(QSize(24, 24));
        newMoleculeButton->setCheckable(false);

        horizontalLayout->addWidget(newMoleculeButton);

        openButton = new QToolButton(ToolBar);
        openButton->setObjectName(QString::fromUtf8("openButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/icons/Open.png"), QSize(), QIcon::Normal, QIcon::Off);
        openButton->setIcon(icon1);
        openButton->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(openButton);

        saveButton = new QToolButton(ToolBar);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/icons/Save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveButton->setIcon(icon2);
        saveButton->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(saveButton);

        line = new QFrame(ToolBar);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        manipulateButton = new QToolButton(ToolBar);
        manipulateButton->setObjectName(QString::fromUtf8("manipulateButton"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/icons/Manipulate.png"), QSize(), QIcon::Normal, QIcon::Off);
        manipulateButton->setIcon(icon3);
        manipulateButton->setIconSize(QSize(24, 24));
        manipulateButton->setCheckable(true);

        horizontalLayout->addWidget(manipulateButton);

        line_4 = new QFrame(ToolBar);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_4);

        buildButton = new QToolButton(ToolBar);
        buildButton->setObjectName(QString::fromUtf8("buildButton"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/resources/icons/Equipment.png"), QSize(), QIcon::Normal, QIcon::Off);
        buildButton->setIcon(icon4);
        buildButton->setIconSize(QSize(24, 24));
        buildButton->setCheckable(true);
        buildButton->setChecked(false);

        horizontalLayout->addWidget(buildButton);

        elementSelectButton = new QToolButton(ToolBar);
        elementSelectButton->setObjectName(QString::fromUtf8("elementSelectButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(34);
        sizePolicy1.setVerticalStretch(34);
        sizePolicy1.setHeightForWidth(elementSelectButton->sizePolicy().hasHeightForWidth());
        elementSelectButton->setSizePolicy(sizePolicy1);
        elementSelectButton->setMinimumSize(QSize(38, 38));
        QFont font;
        elementSelectButton->setFont(font);
        elementSelectButton->setStyleSheet(QString::fromUtf8("font-size: 18px;\n"
"\n"
"\n"
"QToolTip {\n"
"   border: 2px solid darkkhaki;\n"
"   padding: 2px;\n"
"   border-radius: 3px;\n"
"   opacity: 200;\n"
"   font-size: 12px;\n"
"}"));
        elementSelectButton->setCheckable(true);

        horizontalLayout->addWidget(elementSelectButton);

        fragmentSelectButton = new QToolButton(ToolBar);
        fragmentSelectButton->setObjectName(QString::fromUtf8("fragmentSelectButton"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/resources/icons/AddFragment.png"), QSize(), QIcon::Normal, QIcon::Off);
        fragmentSelectButton->setIcon(icon5);
        fragmentSelectButton->setIconSize(QSize(24, 24));
        fragmentSelectButton->setCheckable(true);

        horizontalLayout->addWidget(fragmentSelectButton);

        addHydrogensButton = new QToolButton(ToolBar);
        addHydrogensButton->setObjectName(QString::fromUtf8("addHydrogensButton"));
        addHydrogensButton->setFont(font);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/resources/icons/AddHydrogens.png"), QSize(), QIcon::Normal, QIcon::Off);
        addHydrogensButton->setIcon(icon6);
        addHydrogensButton->setIconSize(QSize(24, 24));
        addHydrogensButton->setPopupMode(QToolButton::InstantPopup);
        addHydrogensButton->setToolButtonStyle(Qt::ToolButtonIconOnly);
        addHydrogensButton->setAutoRaise(false);

        horizontalLayout->addWidget(addHydrogensButton);

        minimizeEnergyButton = new QToolButton(ToolBar);
        minimizeEnergyButton->setObjectName(QString::fromUtf8("minimizeEnergyButton"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/resources/icons/Minimize.png"), QSize(), QIcon::Normal, QIcon::Off);
        minimizeEnergyButton->setIcon(icon7);
        minimizeEnergyButton->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(minimizeEnergyButton);

        line_2 = new QFrame(ToolBar);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_2);

        selectButton = new QToolButton(ToolBar);
        selectButton->setObjectName(QString::fromUtf8("selectButton"));
        selectButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/resources/icons/MagicWand.png"), QSize(), QIcon::Normal, QIcon::Off);
        selectButton->setIcon(icon8);
        selectButton->setIconSize(QSize(24, 24));
        selectButton->setCheckable(true);

        horizontalLayout->addWidget(selectButton);

        deleteSelectionButton = new QToolButton(ToolBar);
        deleteSelectionButton->setObjectName(QString::fromUtf8("deleteSelectionButton"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/resources/icons/Delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteSelectionButton->setIcon(icon9);
        deleteSelectionButton->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(deleteSelectionButton);

        line_3 = new QFrame(ToolBar);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_3);

        takeSnapshotButton = new QToolButton(ToolBar);
        takeSnapshotButton->setObjectName(QString::fromUtf8("takeSnapshotButton"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/resources/icons/Camera.png"), QSize(), QIcon::Normal, QIcon::Off);
        takeSnapshotButton->setIcon(icon10);
        takeSnapshotButton->setIconSize(QSize(28, 28));

        horizontalLayout->addWidget(takeSnapshotButton);

        recordButton = new QToolButton(ToolBar);
        recordButton->setObjectName(QString::fromUtf8("recordButton"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/resources/icons/Movie.png"), QSize(), QIcon::Normal, QIcon::Off);
        recordButton->setIcon(icon11);
        recordButton->setIconSize(QSize(28, 28));
        recordButton->setCheckable(true);

        horizontalLayout->addWidget(recordButton);

        fullScreenButton = new QToolButton(ToolBar);
        fullScreenButton->setObjectName(QString::fromUtf8("fullScreenButton"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/resources/icons/Display.png"), QSize(), QIcon::Normal, QIcon::Off);
        fullScreenButton->setIcon(icon12);
        fullScreenButton->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(fullScreenButton);

        line_5 = new QFrame(ToolBar);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_5);

        showHelpButton = new QToolButton(ToolBar);
        showHelpButton->setObjectName(QString::fromUtf8("showHelpButton"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/resources/icons/Help.png"), QSize(), QIcon::Normal, QIcon::Off);
        showHelpButton->setIcon(icon13);
        showHelpButton->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(showHelpButton);

        horizontalSpacer = new QSpacerItem(43, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(ToolBar);

        QMetaObject::connectSlotsByName(ToolBar);
    } // setupUi

    void retranslateUi(QWidget *ToolBar)
    {
        ToolBar->setWindowTitle(QApplication::translate("ToolBar", "Form", nullptr));
#ifndef QT_NO_TOOLTIP
        newMoleculeButton->setToolTip(QApplication::translate("ToolBar", "New Molecule", nullptr));
#endif // QT_NO_TOOLTIP
        newMoleculeButton->setText(QApplication::translate("ToolBar", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        openButton->setToolTip(QApplication::translate("ToolBar", "Open File", nullptr));
#endif // QT_NO_TOOLTIP
        openButton->setText(QApplication::translate("ToolBar", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        saveButton->setToolTip(QApplication::translate("ToolBar", "Save", nullptr));
#endif // QT_NO_TOOLTIP
        saveButton->setStyleSheet(QString());
        saveButton->setText(QApplication::translate("ToolBar", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        manipulateButton->setToolTip(QApplication::translate("ToolBar", "Manipulate Mode", nullptr));
#endif // QT_NO_TOOLTIP
        manipulateButton->setStyleSheet(QString());
        manipulateButton->setText(QApplication::translate("ToolBar", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        buildButton->setToolTip(QApplication::translate("ToolBar", "Build Mode (Alt)", nullptr));
#endif // QT_NO_TOOLTIP
        buildButton->setStyleSheet(QString());
        buildButton->setText(QApplication::translate("ToolBar", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        elementSelectButton->setToolTip(QApplication::translate("ToolBar", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Lucida Grande'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Build Element</span></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        elementSelectButton->setText(QApplication::translate("ToolBar", "C", nullptr));
#ifndef QT_NO_TOOLTIP
        fragmentSelectButton->setToolTip(QApplication::translate("ToolBar", "Add Fragment", nullptr));
#endif // QT_NO_TOOLTIP
        fragmentSelectButton->setStyleSheet(QString());
        fragmentSelectButton->setText(QApplication::translate("ToolBar", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        addHydrogensButton->setToolTip(QApplication::translate("ToolBar", "Add Hydrogens", nullptr));
#endif // QT_NO_TOOLTIP
        addHydrogensButton->setText(QApplication::translate("ToolBar", "H", nullptr));
#ifndef QT_NO_TOOLTIP
        minimizeEnergyButton->setToolTip(QApplication::translate("ToolBar", "Minimize Energy", nullptr));
#endif // QT_NO_TOOLTIP
        minimizeEnergyButton->setStyleSheet(QString());
        minimizeEnergyButton->setText(QApplication::translate("ToolBar", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        selectButton->setToolTip(QApplication::translate("ToolBar", "Select Mode (Shift)", nullptr));
#endif // QT_NO_TOOLTIP
        selectButton->setText(QApplication::translate("ToolBar", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        deleteSelectionButton->setToolTip(QApplication::translate("ToolBar", "Delete Selection", nullptr));
#endif // QT_NO_TOOLTIP
        deleteSelectionButton->setStyleSheet(QString());
        deleteSelectionButton->setText(QApplication::translate("ToolBar", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        takeSnapshotButton->setToolTip(QApplication::translate("ToolBar", "Save picture", nullptr));
#endif // QT_NO_TOOLTIP
        takeSnapshotButton->setStyleSheet(QString());
        takeSnapshotButton->setText(QApplication::translate("ToolBar", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        recordButton->setToolTip(QApplication::translate("ToolBar", "Record animation", nullptr));
#endif // QT_NO_TOOLTIP
        recordButton->setStyleSheet(QString());
        recordButton->setText(QApplication::translate("ToolBar", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        fullScreenButton->setToolTip(QApplication::translate("ToolBar", "Full Screen Mode", nullptr));
#endif // QT_NO_TOOLTIP
        fullScreenButton->setStyleSheet(QString());
        fullScreenButton->setText(QApplication::translate("ToolBar", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        showHelpButton->setToolTip(QApplication::translate("ToolBar", "Show Help", nullptr));
#endif // QT_NO_TOOLTIP
        showHelpButton->setStyleSheet(QString());
        showHelpButton->setText(QApplication::translate("ToolBar", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ToolBar: public Ui_ToolBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLBAR_H
