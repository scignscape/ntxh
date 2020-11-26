/********************************************************************************
** Form generated from reading UI file 'HelpBrowser.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPBROWSER_H
#define UI_HELPBROWSER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_HelpBrowser
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QToolButton *backButton;
    QToolButton *forwardButton;
    QToolButton *homeButton;
    QSpacerItem *horizontalSpacer;
    QLineEdit *searchLineEdit;
    QToolButton *searchButton;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *doneButton;

    void setupUi(QDialog *HelpBrowser)
    {
        if (HelpBrowser->objectName().isEmpty())
            HelpBrowser->setObjectName(QString::fromUtf8("HelpBrowser"));
        HelpBrowser->resize(546, 684);
        verticalLayout = new QVBoxLayout(HelpBrowser);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        backButton = new QToolButton(HelpBrowser);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icons/Back.png"), QSize(), QIcon::Normal, QIcon::Off);
        backButton->setIcon(icon);
        backButton->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(backButton);

        forwardButton = new QToolButton(HelpBrowser);
        forwardButton->setObjectName(QString::fromUtf8("forwardButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/icons/Forward.png"), QSize(), QIcon::Normal, QIcon::Off);
        forwardButton->setIcon(icon1);
        forwardButton->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(forwardButton);

        homeButton = new QToolButton(HelpBrowser);
        homeButton->setObjectName(QString::fromUtf8("homeButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/icons/Home.png"), QSize(), QIcon::Normal, QIcon::Off);
        homeButton->setIcon(icon2);
        homeButton->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(homeButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        searchLineEdit = new QLineEdit(HelpBrowser);
        searchLineEdit->setObjectName(QString::fromUtf8("searchLineEdit"));

        horizontalLayout->addWidget(searchLineEdit);

        searchButton = new QToolButton(HelpBrowser);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/icons/Search.png"), QSize(), QIcon::Normal, QIcon::Off);
        searchButton->setIcon(icon3);
        searchButton->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(searchButton);


        verticalLayout->addLayout(horizontalLayout);

        textBrowser = new QTextBrowser(HelpBrowser);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setFrameShape(QFrame::StyledPanel);

        verticalLayout->addWidget(textBrowser);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        doneButton = new QPushButton(HelpBrowser);
        doneButton->setObjectName(QString::fromUtf8("doneButton"));
        doneButton->setAutoDefault(false);

        horizontalLayout_2->addWidget(doneButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(HelpBrowser);
        QObject::connect(doneButton, SIGNAL(clicked()), HelpBrowser, SLOT(close()));

        QMetaObject::connectSlotsByName(HelpBrowser);
    } // setupUi

    void retranslateUi(QDialog *HelpBrowser)
    {
        HelpBrowser->setWindowTitle(QApplication::translate("HelpBrowser", "Help Browser", nullptr));
        HelpBrowser->setStyleSheet(QApplication::translate("HelpBrowser", "QToolButton {\n"
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
"   border-color: #b00;\n"
"}\n"
"\n"
"\n"
"QToolButton:checked {\n"
"   border-color: #b00;\n"
"}\n"
"\n"
"QToolTip {\n"
"   border: 2px solid darkkhaki;\n"
"   padding: 2px;\n"
"   border-radius: 3px;\n"
"   opacity: 500;\n"
"   font-size: 12px;\n"
"}\n"
"\n"
"QTextBrowser#content { \n"
"   paddin"
                        "g: 20px;\n"
"}", nullptr));
#ifndef QT_NO_TOOLTIP
        backButton->setToolTip(QApplication::translate("HelpBrowser", "Back", nullptr));
#endif // QT_NO_TOOLTIP
        backButton->setText(QApplication::translate("HelpBrowser", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        forwardButton->setToolTip(QApplication::translate("HelpBrowser", "Forward", nullptr));
#endif // QT_NO_TOOLTIP
        forwardButton->setText(QApplication::translate("HelpBrowser", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        homeButton->setToolTip(QApplication::translate("HelpBrowser", "Index page", nullptr));
#endif // QT_NO_TOOLTIP
        homeButton->setText(QApplication::translate("HelpBrowser", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        searchButton->setToolTip(QApplication::translate("HelpBrowser", "Search", nullptr));
#endif // QT_NO_TOOLTIP
        searchButton->setText(QApplication::translate("HelpBrowser", "...", nullptr));
        textBrowser->setStyleSheet(QString());
        doneButton->setText(QApplication::translate("HelpBrowser", "Done", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HelpBrowser: public Ui_HelpBrowser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPBROWSER_H