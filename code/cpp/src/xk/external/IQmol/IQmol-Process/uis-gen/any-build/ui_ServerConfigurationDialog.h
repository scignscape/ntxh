/********************************************************************************
** Form generated from reading UI file 'ServerConfigurationDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERCONFIGURATIONDIALOG_H
#define UI_SERVERCONFIGURATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ServerConfigurationDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLabel *typeLabel;
    QHBoxLayout *horizontalLayout;
    QComboBox *queueSystem;
    QPushButton *configureQueueButton;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_7;
    QRadioButton *localRadioButton;
    QRadioButton *sshRadioButton;
    QRadioButton *sftpRadioButton;
    QRadioButton *httpRadioButton;
    QRadioButton *httpsRadioButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *configureSshButton;
    QLineEdit *serverName;
    QLabel *label;
    QGroupBox *remoteHostGroupBox;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_3;
    QLabel *label_4;
    QLabel *userNameLabel;
    QLabel *workingDirectoryLabel;
    QLabel *authenticationLabel;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *hostAddress;
    QLabel *label_3;
    QSpinBox *port;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *authentication;
    QSpacerItem *horizontalSpacer_3;
    QLabel *authenticationPortLabel;
    QSpinBox *authenticationPort;
    QLineEdit *userName;
    QLineEdit *workingDirectory;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *testConnectionButton;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *loadButton;
    QPushButton *exportButton;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ServerConfigurationDialog)
    {
        if (ServerConfigurationDialog->objectName().isEmpty())
            ServerConfigurationDialog->setObjectName(QStringLiteral("ServerConfigurationDialog"));
        ServerConfigurationDialog->setEnabled(true);
        ServerConfigurationDialog->resize(607, 422);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ServerConfigurationDialog->sizePolicy().hasHeightForWidth());
        ServerConfigurationDialog->setSizePolicy(sizePolicy);
        ServerConfigurationDialog->setStyleSheet(QLatin1String("QToolButton {\n"
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
"   min-width: 24px;\n"
"   max-width: 24px;\n"
"   min-height: 24px;\n"
"   max-height: 24px;\n"
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
" QToolTip {\n"
"    border: 2px solid darkkhaki;\n"
"    padding: 2px;\n"
"    border-radius: 3px;\n"
"    opacity: 500;\n"
"    font-size: 12px;\n"
"    color: #000;\n"
"    background-color: #EEE;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(ServerConfigurationDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        typeLabel = new QLabel(ServerConfigurationDialog);
        typeLabel->setObjectName(QStringLiteral("typeLabel"));

        gridLayout->addWidget(typeLabel, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        queueSystem = new QComboBox(ServerConfigurationDialog);
        queueSystem->setObjectName(QStringLiteral("queueSystem"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(queueSystem->sizePolicy().hasHeightForWidth());
        queueSystem->setSizePolicy(sizePolicy1);
        queueSystem->setMinimumSize(QSize(0, 0));
        queueSystem->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        horizontalLayout->addWidget(queueSystem);

        configureQueueButton = new QPushButton(ServerConfigurationDialog);
        configureQueueButton->setObjectName(QStringLiteral("configureQueueButton"));

        horizontalLayout->addWidget(configureQueueButton);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);


        gridLayout->addLayout(horizontalLayout, 2, 1, 1, 1);

        label_2 = new QLabel(ServerConfigurationDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        localRadioButton = new QRadioButton(ServerConfigurationDialog);
        localRadioButton->setObjectName(QStringLiteral("localRadioButton"));
        localRadioButton->setChecked(true);

        horizontalLayout_7->addWidget(localRadioButton);

        sshRadioButton = new QRadioButton(ServerConfigurationDialog);
        sshRadioButton->setObjectName(QStringLiteral("sshRadioButton"));

        horizontalLayout_7->addWidget(sshRadioButton);

        sftpRadioButton = new QRadioButton(ServerConfigurationDialog);
        sftpRadioButton->setObjectName(QStringLiteral("sftpRadioButton"));

        horizontalLayout_7->addWidget(sftpRadioButton);

        httpRadioButton = new QRadioButton(ServerConfigurationDialog);
        httpRadioButton->setObjectName(QStringLiteral("httpRadioButton"));

        horizontalLayout_7->addWidget(httpRadioButton);

        httpsRadioButton = new QRadioButton(ServerConfigurationDialog);
        httpsRadioButton->setObjectName(QStringLiteral("httpsRadioButton"));

        horizontalLayout_7->addWidget(httpsRadioButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        configureSshButton = new QPushButton(ServerConfigurationDialog);
        configureSshButton->setObjectName(QStringLiteral("configureSshButton"));
        configureSshButton->setEnabled(false);

        horizontalLayout_7->addWidget(configureSshButton);


        gridLayout->addLayout(horizontalLayout_7, 0, 1, 1, 1);

        serverName = new QLineEdit(ServerConfigurationDialog);
        serverName->setObjectName(QStringLiteral("serverName"));

        gridLayout->addWidget(serverName, 1, 1, 1, 1);

        label = new QLabel(ServerConfigurationDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        remoteHostGroupBox = new QGroupBox(ServerConfigurationDialog);
        remoteHostGroupBox->setObjectName(QStringLiteral("remoteHostGroupBox"));
        remoteHostGroupBox->setEnabled(false);
        verticalLayout = new QVBoxLayout(remoteHostGroupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_4 = new QLabel(remoteHostGroupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_3->addWidget(label_4, 0, 0, 1, 1);

        userNameLabel = new QLabel(remoteHostGroupBox);
        userNameLabel->setObjectName(QStringLiteral("userNameLabel"));

        gridLayout_3->addWidget(userNameLabel, 2, 0, 1, 1);

        workingDirectoryLabel = new QLabel(remoteHostGroupBox);
        workingDirectoryLabel->setObjectName(QStringLiteral("workingDirectoryLabel"));

        gridLayout_3->addWidget(workingDirectoryLabel, 3, 0, 1, 1);

        authenticationLabel = new QLabel(remoteHostGroupBox);
        authenticationLabel->setObjectName(QStringLiteral("authenticationLabel"));

        gridLayout_3->addWidget(authenticationLabel, 1, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        hostAddress = new QLineEdit(remoteHostGroupBox);
        hostAddress->setObjectName(QStringLiteral("hostAddress"));

        horizontalLayout_6->addWidget(hostAddress);

        label_3 = new QLabel(remoteHostGroupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_6->addWidget(label_3);

        port = new QSpinBox(remoteHostGroupBox);
        port->setObjectName(QStringLiteral("port"));
        port->setMinimum(0);
        port->setMaximum(65535);
        port->setValue(22);

        horizontalLayout_6->addWidget(port);


        gridLayout_3->addLayout(horizontalLayout_6, 0, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        authentication = new QComboBox(remoteHostGroupBox);
        authentication->setObjectName(QStringLiteral("authentication"));
        sizePolicy1.setHeightForWidth(authentication->sizePolicy().hasHeightForWidth());
        authentication->setSizePolicy(sizePolicy1);
        authentication->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        horizontalLayout_2->addWidget(authentication);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        authenticationPortLabel = new QLabel(remoteHostGroupBox);
        authenticationPortLabel->setObjectName(QStringLiteral("authenticationPortLabel"));

        horizontalLayout_2->addWidget(authenticationPortLabel);

        authenticationPort = new QSpinBox(remoteHostGroupBox);
        authenticationPort->setObjectName(QStringLiteral("authenticationPort"));
        authenticationPort->setMaximum(65535);
        authenticationPort->setValue(8882);

        horizontalLayout_2->addWidget(authenticationPort);


        gridLayout_3->addLayout(horizontalLayout_2, 1, 1, 1, 1);

        userName = new QLineEdit(remoteHostGroupBox);
        userName->setObjectName(QStringLiteral("userName"));

        gridLayout_3->addWidget(userName, 2, 1, 1, 1);

        workingDirectory = new QLineEdit(remoteHostGroupBox);
        workingDirectory->setObjectName(QStringLiteral("workingDirectory"));

        gridLayout_3->addWidget(workingDirectory, 3, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        testConnectionButton = new QPushButton(remoteHostGroupBox);
        testConnectionButton->setObjectName(QStringLiteral("testConnectionButton"));

        horizontalLayout_3->addWidget(testConnectionButton);


        gridLayout_3->addLayout(horizontalLayout_3, 4, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_3);


        verticalLayout_2->addWidget(remoteHostGroupBox);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        loadButton = new QPushButton(ServerConfigurationDialog);
        loadButton->setObjectName(QStringLiteral("loadButton"));

        horizontalLayout_4->addWidget(loadButton);

        exportButton = new QPushButton(ServerConfigurationDialog);
        exportButton->setObjectName(QStringLiteral("exportButton"));

        horizontalLayout_4->addWidget(exportButton);

        horizontalSpacer = new QSpacerItem(288, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(ServerConfigurationDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_4->addWidget(buttonBox);


        verticalLayout_2->addLayout(horizontalLayout_4);

        QWidget::setTabOrder(buttonBox, localRadioButton);
        QWidget::setTabOrder(localRadioButton, sshRadioButton);
        QWidget::setTabOrder(sshRadioButton, httpRadioButton);
        QWidget::setTabOrder(httpRadioButton, httpsRadioButton);
        QWidget::setTabOrder(httpsRadioButton, configureSshButton);
        QWidget::setTabOrder(configureSshButton, serverName);
        QWidget::setTabOrder(serverName, queueSystem);
        QWidget::setTabOrder(queueSystem, hostAddress);
        QWidget::setTabOrder(hostAddress, port);
        QWidget::setTabOrder(port, authentication);
        QWidget::setTabOrder(authentication, userName);
        QWidget::setTabOrder(userName, workingDirectory);
        QWidget::setTabOrder(workingDirectory, testConnectionButton);
        QWidget::setTabOrder(testConnectionButton, loadButton);
        QWidget::setTabOrder(loadButton, exportButton);

        retranslateUi(ServerConfigurationDialog);
        QObject::connect(buttonBox, SIGNAL(rejected()), ServerConfigurationDialog, SLOT(reject()));

        authentication->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ServerConfigurationDialog);
    } // setupUi

    void retranslateUi(QDialog *ServerConfigurationDialog)
    {
        ServerConfigurationDialog->setWindowTitle(QApplication::translate("ServerConfigurationDialog", "Edit Server", Q_NULLPTR));
        typeLabel->setText(QApplication::translate("ServerConfigurationDialog", "Queue System", Q_NULLPTR));
        queueSystem->clear();
        queueSystem->insertItems(0, QStringList()
         << QApplication::translate("ServerConfigurationDialog", "Basic", Q_NULLPTR)
         << QApplication::translate("ServerConfigurationDialog", "PBS", Q_NULLPTR)
         << QApplication::translate("ServerConfigurationDialog", "SGE", Q_NULLPTR)
         << QApplication::translate("ServerConfigurationDialog", "SLURM", Q_NULLPTR)
         << QApplication::translate("ServerConfigurationDialog", "Web", Q_NULLPTR)
         << QApplication::translate("ServerConfigurationDialog", "Web - Anonymous", Q_NULLPTR)
        );
#ifndef QT_NO_TOOLTIP
        queueSystem->setToolTip(QApplication::translate("ServerConfigurationDialog", "Basic simply runs the qchem command on the server.  \n"
"\n"
"Use PBS or SGE if there is a queue system on the server.  \n"
"You will be prompted for additional resource limits when \n"
"submitting a job.\n"
"\n"
"Use Web for HTTP/HTTPS servers", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        configureQueueButton->setText(QApplication::translate("ServerConfigurationDialog", "Configure", Q_NULLPTR));
        label_2->setText(QApplication::translate("ServerConfigurationDialog", "Connection", Q_NULLPTR));
        localRadioButton->setText(QApplication::translate("ServerConfigurationDialog", "Local", Q_NULLPTR));
        sshRadioButton->setText(QApplication::translate("ServerConfigurationDialog", "SSH", Q_NULLPTR));
        sftpRadioButton->setText(QApplication::translate("ServerConfigurationDialog", "SFTP", Q_NULLPTR));
        httpRadioButton->setText(QApplication::translate("ServerConfigurationDialog", "HTTP", Q_NULLPTR));
        httpsRadioButton->setText(QApplication::translate("ServerConfigurationDialog", "HTTPS", Q_NULLPTR));
        configureSshButton->setText(QApplication::translate("ServerConfigurationDialog", "Configure SSH", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        serverName->setToolTip(QApplication::translate("ServerConfigurationDialog", "Server mnemonic (does not have to match actual server name)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        serverName->setText(QApplication::translate("ServerConfigurationDialog", "Server", Q_NULLPTR));
        label->setText(QApplication::translate("ServerConfigurationDialog", "Server Name", Q_NULLPTR));
        remoteHostGroupBox->setTitle(QApplication::translate("ServerConfigurationDialog", "Remote Host", Q_NULLPTR));
        label_4->setText(QApplication::translate("ServerConfigurationDialog", "Host Address", Q_NULLPTR));
        userNameLabel->setText(QApplication::translate("ServerConfigurationDialog", "User Name", Q_NULLPTR));
        workingDirectoryLabel->setText(QApplication::translate("ServerConfigurationDialog", "Working Directory", Q_NULLPTR));
        authenticationLabel->setText(QApplication::translate("ServerConfigurationDialog", "Authentication", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        hostAddress->setToolTip(QApplication::translate("ServerConfigurationDialog", "Server name or IP address", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("ServerConfigurationDialog", "Port", Q_NULLPTR));
        authentication->clear();
        authentication->insertItems(0, QStringList()
         << QApplication::translate("ServerConfigurationDialog", "SSH Agent", Q_NULLPTR)
         << QApplication::translate("ServerConfigurationDialog", "SSH Public Key", Q_NULLPTR)
         << QApplication::translate("ServerConfigurationDialog", "SSH Host Based", Q_NULLPTR)
         << QApplication::translate("ServerConfigurationDialog", "SSH Keyboard Interactive", Q_NULLPTR)
         << QApplication::translate("ServerConfigurationDialog", "SSH Prompt", Q_NULLPTR)
        );
        authenticationPortLabel->setText(QApplication::translate("ServerConfigurationDialog", "Port", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        userName->setToolTip(QApplication::translate("ServerConfigurationDialog", "Account name on the server", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        workingDirectory->setToolTip(QApplication::translate("ServerConfigurationDialog", "This is the directory on the server where calculations will be run", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        testConnectionButton->setText(QApplication::translate("ServerConfigurationDialog", "Test Connection", Q_NULLPTR));
        loadButton->setText(QApplication::translate("ServerConfigurationDialog", "Load", Q_NULLPTR));
        exportButton->setText(QApplication::translate("ServerConfigurationDialog", "Export", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ServerConfigurationDialog: public Ui_ServerConfigurationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERCONFIGURATIONDIALOG_H
