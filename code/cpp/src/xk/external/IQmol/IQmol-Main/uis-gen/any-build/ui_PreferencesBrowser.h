/********************************************************************************
** Form generated from reading UI file 'PreferencesBrowser.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREFERENCESBROWSER_H
#define UI_PREFERENCESBROWSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PreferencesBrowser
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLineEdit *logFileLineEdit;
    QHBoxLayout *horizontalLayout;
    QSpinBox *undoLimit;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_5;
    QSpinBox *labelFontSize;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *forceFieldCombo;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *fragmentDirectoryLineEdit;
    QLabel *label_6;
    QLabel *label_4;
    QLabel *label_2;
    QPushButton *browseQChemDatabaseFileButton;
    QLineEdit *qchemDatabaseFileLineEdit;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *logFileHiddenCheckBox;
    QCheckBox *loggingEnabledCheckBox;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *browseLogFileButton;
    QPushButton *browseFragmentDirectoryButton;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *resetButton;
    QSpacerItem *horizontalSpacer_5;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PreferencesBrowser)
    {
        if (PreferencesBrowser->objectName().isEmpty())
            PreferencesBrowser->setObjectName(QStringLiteral("PreferencesBrowser"));
        PreferencesBrowser->resize(661, 299);
        PreferencesBrowser->setStyleSheet(QLatin1String("QToolButton {\n"
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
"   border-color: #222;\n"
"}\n"
"\n"
"\n"
"QToolButton:checked {\n"
"   border-color: #b00;\n"
"}\n"
"\n"
" QToolTip {\n"
"    border: 2px solid darkkhaki;\n"
"    padding: 2px;\n"
"    border-radius: 3px;\n"
"    opacity: 500;\n"
"    font-size: 12px;\n"
"    color: #000;\n"
"    background-color:"
                        " #EEE;\n"
"}"));
        verticalLayout = new QVBoxLayout(PreferencesBrowser);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_3 = new QLabel(PreferencesBrowser);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 3, 0, 1, 1);

        logFileLineEdit = new QLineEdit(PreferencesBrowser);
        logFileLineEdit->setObjectName(QStringLiteral("logFileLineEdit"));

        gridLayout_2->addWidget(logFileLineEdit, 4, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        undoLimit = new QSpinBox(PreferencesBrowser);
        undoLimit->setObjectName(QStringLiteral("undoLimit"));
        undoLimit->setValue(5);

        horizontalLayout->addWidget(undoLimit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_5 = new QLabel(PreferencesBrowser);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout->addWidget(label_5);

        labelFontSize = new QSpinBox(PreferencesBrowser);
        labelFontSize->setObjectName(QStringLiteral("labelFontSize"));
        labelFontSize->setMinimum(6);
        labelFontSize->setMaximum(36);
        labelFontSize->setValue(14);

        horizontalLayout->addWidget(labelFontSize);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout_2->addLayout(horizontalLayout, 1, 1, 1, 1);

        label = new QLabel(PreferencesBrowser);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        forceFieldCombo = new QComboBox(PreferencesBrowser);
        forceFieldCombo->setObjectName(QStringLiteral("forceFieldCombo"));

        horizontalLayout_2->addWidget(forceFieldCombo);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 1, 1, 1);

        fragmentDirectoryLineEdit = new QLineEdit(PreferencesBrowser);
        fragmentDirectoryLineEdit->setObjectName(QStringLiteral("fragmentDirectoryLineEdit"));

        gridLayout_2->addWidget(fragmentDirectoryLineEdit, 2, 1, 1, 1);

        label_6 = new QLabel(PreferencesBrowser);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 4, 0, 1, 1);

        label_4 = new QLabel(PreferencesBrowser);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        label_2 = new QLabel(PreferencesBrowser);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        browseQChemDatabaseFileButton = new QPushButton(PreferencesBrowser);
        browseQChemDatabaseFileButton->setObjectName(QStringLiteral("browseQChemDatabaseFileButton"));

        gridLayout_2->addWidget(browseQChemDatabaseFileButton, 3, 2, 1, 1);

        qchemDatabaseFileLineEdit = new QLineEdit(PreferencesBrowser);
        qchemDatabaseFileLineEdit->setObjectName(QStringLiteral("qchemDatabaseFileLineEdit"));

        gridLayout_2->addWidget(qchemDatabaseFileLineEdit, 3, 1, 1, 1);

        label_7 = new QLabel(PreferencesBrowser);
        label_7->setObjectName(QStringLiteral("label_7"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(11);
        label_7->setFont(font);

        gridLayout_2->addWidget(label_7, 6, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        logFileHiddenCheckBox = new QCheckBox(PreferencesBrowser);
        logFileHiddenCheckBox->setObjectName(QStringLiteral("logFileHiddenCheckBox"));

        horizontalLayout_3->addWidget(logFileHiddenCheckBox);

        loggingEnabledCheckBox = new QCheckBox(PreferencesBrowser);
        loggingEnabledCheckBox->setObjectName(QStringLiteral("loggingEnabledCheckBox"));

        horizontalLayout_3->addWidget(loggingEnabledCheckBox);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        gridLayout_2->addLayout(horizontalLayout_3, 5, 1, 1, 1);

        browseLogFileButton = new QPushButton(PreferencesBrowser);
        browseLogFileButton->setObjectName(QStringLiteral("browseLogFileButton"));

        gridLayout_2->addWidget(browseLogFileButton, 4, 2, 1, 1);

        browseFragmentDirectoryButton = new QPushButton(PreferencesBrowser);
        browseFragmentDirectoryButton->setObjectName(QStringLiteral("browseFragmentDirectoryButton"));

        gridLayout_2->addWidget(browseFragmentDirectoryButton, 2, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        resetButton = new QPushButton(PreferencesBrowser);
        resetButton->setObjectName(QStringLiteral("resetButton"));

        horizontalLayout_4->addWidget(resetButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        buttonBox = new QDialogButtonBox(PreferencesBrowser);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_4->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(PreferencesBrowser);
        QObject::connect(buttonBox, SIGNAL(rejected()), PreferencesBrowser, SLOT(close()));

        QMetaObject::connectSlotsByName(PreferencesBrowser);
    } // setupUi

    void retranslateUi(QDialog *PreferencesBrowser)
    {
        PreferencesBrowser->setWindowTitle(QApplication::translate("PreferencesBrowser", "IQmol Preferences", Q_NULLPTR));
        label_3->setText(QApplication::translate("PreferencesBrowser", "QChem Database File", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        logFileLineEdit->setToolTip(QApplication::translate("PreferencesBrowser", "Changes to the log file location require IQmol to be restarted", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("PreferencesBrowser", "Label Font Size", Q_NULLPTR));
        labelFontSize->setSuffix(QApplication::translate("PreferencesBrowser", " pt", Q_NULLPTR));
        label->setText(QApplication::translate("PreferencesBrowser", "Default Force Field:", Q_NULLPTR));
        forceFieldCombo->clear();
        forceFieldCombo->insertItems(0, QStringList()
         << QApplication::translate("PreferencesBrowser", "MMFF94", Q_NULLPTR)
         << QApplication::translate("PreferencesBrowser", "MMFF94s", Q_NULLPTR)
         << QApplication::translate("PreferencesBrowser", "UFF", Q_NULLPTR)
         << QApplication::translate("PreferencesBrowser", "Ghemical", Q_NULLPTR)
         << QApplication::translate("PreferencesBrowser", "Gaff", Q_NULLPTR)
        );
        label_6->setText(QApplication::translate("PreferencesBrowser", "Log File:", Q_NULLPTR));
        label_4->setText(QApplication::translate("PreferencesBrowser", "Maximum Undo Level:", Q_NULLPTR));
        label_2->setText(QApplication::translate("PreferencesBrowser", "Fragment Directory:", Q_NULLPTR));
        browseQChemDatabaseFileButton->setText(QApplication::translate("PreferencesBrowser", "Browse", Q_NULLPTR));
        label_7->setText(QApplication::translate("PreferencesBrowser", "Log file changes will not take effect until restart", Q_NULLPTR));
        logFileHiddenCheckBox->setText(QApplication::translate("PreferencesBrowser", "Hide Log File", Q_NULLPTR));
        loggingEnabledCheckBox->setText(QApplication::translate("PreferencesBrowser", "Logging Enabled", Q_NULLPTR));
        browseLogFileButton->setText(QApplication::translate("PreferencesBrowser", "Browse", Q_NULLPTR));
        browseFragmentDirectoryButton->setText(QApplication::translate("PreferencesBrowser", "Browse", Q_NULLPTR));
        resetButton->setText(QApplication::translate("PreferencesBrowser", "Reset", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PreferencesBrowser: public Ui_PreferencesBrowser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREFERENCESBROWSER_H
