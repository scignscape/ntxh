/********************************************************************************
** Form generated from reading UI file 'FileConfigurator.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILECONFIGURATOR_H
#define UI_FILECONFIGURATOR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FileConfigurator
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *textLargerButton;
    QToolButton *textSmallerButton;
    QLineEdit *searchBox;
    QToolButton *searchButton;
    QFrame *frame;
    QVBoxLayout *_2;
    QTextBrowser *textDisplay;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;

    void setupUi(QDialog *FileConfigurator)
    {
        if (FileConfigurator->objectName().isEmpty())
            FileConfigurator->setObjectName(QString::fromUtf8("FileConfigurator"));
        FileConfigurator->resize(650, 576);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FileConfigurator->sizePolicy().hasHeightForWidth());
        FileConfigurator->setSizePolicy(sizePolicy);
        FileConfigurator->setStyleSheet(QString::fromUtf8("QToolButton {\n"
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
"   min-width: 28px;\n"
"   max-width: 28px;\n"
"   min-height: 28px;\n"
"   max-height: 28px;\n"
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
"}\n"
"\n"
"QToolTip {\n"
"   border: 2px solid darkkhaki;\n"
"   p"
                        "adding: 2px;\n"
"   border-radius: 3px;\n"
"   opacity: 500;\n"
"   font-size: 12px;\n"
"}"));
        verticalLayout = new QVBoxLayout(FileConfigurator);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        textLargerButton = new QToolButton(FileConfigurator);
        textLargerButton->setObjectName(QString::fromUtf8("textLargerButton"));
        QFont font;
        textLargerButton->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/T24.png"), QSize(), QIcon::Normal, QIcon::Off);
        textLargerButton->setIcon(icon);
        textLargerButton->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(textLargerButton);

        textSmallerButton = new QToolButton(FileConfigurator);
        textSmallerButton->setObjectName(QString::fromUtf8("textSmallerButton"));
        textSmallerButton->setFont(font);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/icons/T14.png"), QSize(), QIcon::Normal, QIcon::Off);
        textSmallerButton->setIcon(icon1);
        textSmallerButton->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(textSmallerButton);

        searchBox = new QLineEdit(FileConfigurator);
        searchBox->setObjectName(QString::fromUtf8("searchBox"));

        horizontalLayout_2->addWidget(searchBox);

        searchButton = new QToolButton(FileConfigurator);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/icons/Search.png"), QSize(), QIcon::Normal, QIcon::Off);
        searchButton->setIcon(icon2);
        searchButton->setIconSize(QSize(18, 18));

        horizontalLayout_2->addWidget(searchButton);


        verticalLayout->addLayout(horizontalLayout_2);

        frame = new QFrame(FileConfigurator);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        _2 = new QVBoxLayout(frame);
        _2->setSpacing(4);
        _2->setContentsMargins(6, 6, 6, 6);
        _2->setObjectName(QString::fromUtf8("_2"));
        textDisplay = new QTextBrowser(frame);
        textDisplay->setObjectName(QString::fromUtf8("textDisplay"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Courier New"));
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setWeight(50);
        font1.setStrikeOut(false);
        textDisplay->setFont(font1);

        _2->addWidget(textDisplay);


        verticalLayout->addWidget(frame);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closeButton = new QPushButton(FileConfigurator);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setAutoDefault(false);

        horizontalLayout->addWidget(closeButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(FileConfigurator);
        QObject::connect(closeButton, SIGNAL(clicked()), FileConfigurator, SLOT(close()));

        QMetaObject::connectSlotsByName(FileConfigurator);
    } // setupUi

    void retranslateUi(QDialog *FileConfigurator)
    {
        FileConfigurator->setWindowTitle(QApplication::translate("FileConfigurator", "View File", nullptr));
#ifndef QT_NO_TOOLTIP
        textLargerButton->setToolTip(QApplication::translate("FileConfigurator", "Bigger text", nullptr));
#endif // QT_NO_TOOLTIP
        textLargerButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        textSmallerButton->setToolTip(QApplication::translate("FileConfigurator", "Smaller text", nullptr));
#endif // QT_NO_TOOLTIP
        textSmallerButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        searchButton->setToolTip(QApplication::translate("FileConfigurator", "Search", nullptr));
#endif // QT_NO_TOOLTIP
        searchButton->setText(QApplication::translate("FileConfigurator", "...", nullptr));
        closeButton->setText(QApplication::translate("FileConfigurator", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileConfigurator: public Ui_FileConfigurator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILECONFIGURATOR_H
