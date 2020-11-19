/********************************************************************************
** Form generated from reading UI file 'aboutDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_aboutDialog
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBoxSx;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelMLLogo;
    QLabel *labelMLName;
    QSpacerItem *spacer_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelVCGLogo_4;
    QLabel *labelVCGDescription;
    QSpacerItem *spacer;
    QVBoxLayout *verticalLayout;
    QLabel *labelVCGDescription_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *spacerItem;
    QPushButton *okButton;

    void setupUi(QDialog *aboutDialog)
    {
        if (aboutDialog->objectName().isEmpty())
            aboutDialog->setObjectName(QString::fromUtf8("aboutDialog"));
        aboutDialog->resize(815, 565);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(aboutDialog->sizePolicy().hasHeightForWidth());
        aboutDialog->setSizePolicy(sizePolicy);
        aboutDialog->setMinimumSize(QSize(0, 0));
        aboutDialog->setMaximumSize(QSize(65536, 65536));
        QIcon icon;
        icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        aboutDialog->setWindowIcon(icon);
        aboutDialog->setModal(true);
        gridLayout = new QGridLayout(aboutDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBoxSx = new QGroupBox(aboutDialog);
        groupBoxSx->setObjectName(QString::fromUtf8("groupBoxSx"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBoxSx->sizePolicy().hasHeightForWidth());
        groupBoxSx->setSizePolicy(sizePolicy1);
        groupBoxSx->setFlat(false);
        gridLayout_2 = new QGridLayout(groupBoxSx);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        labelMLLogo = new QLabel(groupBoxSx);
        labelMLLogo->setObjectName(QString::fromUtf8("labelMLLogo"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelMLLogo->sizePolicy().hasHeightForWidth());
        labelMLLogo->setSizePolicy(sizePolicy2);
        labelMLLogo->setPixmap(QPixmap(QString::fromUtf8(":/images/meshlabLogo_256x256.png")));
        labelMLLogo->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(labelMLLogo);

        labelMLName = new QLabel(groupBoxSx);
        labelMLName->setObjectName(QString::fromUtf8("labelMLName"));
        labelMLName->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(labelMLName);


        horizontalLayout->addLayout(verticalLayout_2);

        spacer_2 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(spacer_2);

        label = new QLabel(groupBoxSx);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(0, 300));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label->setWordWrap(true);
        label->setMargin(3);
        label->setOpenExternalLinks(true);

        horizontalLayout->addWidget(label);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        labelVCGLogo_4 = new QLabel(groupBoxSx);
        labelVCGLogo_4->setObjectName(QString::fromUtf8("labelVCGLogo_4"));
        sizePolicy2.setHeightForWidth(labelVCGLogo_4->sizePolicy().hasHeightForWidth());
        labelVCGLogo_4->setSizePolicy(sizePolicy2);
        labelVCGLogo_4->setMinimumSize(QSize(186, 150));
        labelVCGLogo_4->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));
        labelVCGLogo_4->setScaledContents(false);

        horizontalLayout_4->addWidget(labelVCGLogo_4);

        labelVCGDescription = new QLabel(groupBoxSx);
        labelVCGDescription->setObjectName(QString::fromUtf8("labelVCGDescription"));
        labelVCGDescription->setOpenExternalLinks(true);

        horizontalLayout_4->addWidget(labelVCGDescription);

        spacer = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(spacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        labelVCGDescription_2 = new QLabel(groupBoxSx);
        labelVCGDescription_2->setObjectName(QString::fromUtf8("labelVCGDescription_2"));
        labelVCGDescription_2->setWordWrap(true);
        labelVCGDescription_2->setOpenExternalLinks(true);

        verticalLayout->addWidget(labelVCGDescription_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        spacerItem = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(spacerItem);

        okButton = new QPushButton(groupBoxSx);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        horizontalLayout_2->addWidget(okButton);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_4->addLayout(verticalLayout);


        gridLayout_2->addLayout(horizontalLayout_4, 1, 0, 1, 1);


        gridLayout->addWidget(groupBoxSx, 0, 0, 1, 1);


        retranslateUi(aboutDialog);
        QObject::connect(okButton, SIGNAL(clicked()), aboutDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(aboutDialog);
    } // setupUi

    void retranslateUi(QDialog *aboutDialog)
    {
        aboutDialog->setWindowTitle(QApplication::translate("aboutDialog", "About MeshLab", nullptr));
        groupBoxSx->setTitle(QString());
        labelMLLogo->setText(QString());
        labelMLName->setText(QApplication::translate("aboutDialog", "MESHLAB VERSION BUILT ON XXX", nullptr));
        label->setText(QApplication::translate("aboutDialog", "<p><strong>General Info:&nbsp;<a href=\"http://www.meshlab.net\">www.meshlab.net</a></strong></p>\n"
"<p>MeshLab is the most used open source system for processing and editing 3D triangular meshes. It provides a set of tools for editing, cleaning, healing, inspecting, rendering, texturing and converting meshes. It offers features for processing raw data produced by 3D digitization tools/devices and for preparing models for 3D printing. The system is heavily based on the <a href=\"http://www.vcglib.net\">VCG library</a>. <br />Source code is available on <a href=\"https://github.com/cnr-isti-vclab/meshlab\">GitHub </a>(protected by GPL).</p>\n"
"<p><strong>References</strong><br />Remember that the simplest way to show your appreciation of the MeshLab system is to remember citing it whenever you have used some of its functionalities. Please check the <a href=\"http://www.meshlab.net/#references\">list of the many publications</a> related with MeshLab.</p>", nullptr));
        labelVCGLogo_4->setText(QString());
        labelVCGDescription->setText(QApplication::translate("aboutDialog", "<p>Copyright(C) 2005-2020</p>\n"
"<p>Paolo Cignoni<br /><a href=\"http://vcg.isti.cnr.it/%7Ecignoni\">http://vcg.isti.cnr.it/~cignoni</a></p>\n"
"<p>Visual Computing Lab<br /><a href=\"http://vcg.isti.cnr.it\">http://vcg.isti.cnr.it</a></p>\n"
"<p>ISTI - CNR<br /><a href=\"http://www.isti.cnr.it\">http://www.isti.cnr.it</a></p>", nullptr));
        labelVCGDescription_2->setText(QApplication::translate("aboutDialog", "<p><strong>Contacts</strong><br />For detailed bug reports, meaningful feature requests and grounded technical issues please use the <a href=\"https://github.com/cnr-isti-vclab/meshlab/issues\">GitHub services</a>.<br />For any other high-level question about MeshLab (<em>no bugs or feature requests, please</em>) contact:<br />- Paolo Cignoni (<a href=\"mailto:p.cignoni@isti.cnr.it?subject=%5BMeshLab%5D%20Info%20request\">paolo.cignoni@isti.cnr.it</a>)<br />The complete list of contributors is available <a href=\"https://github.com/cnr-isti-vclab/meshlab/graphs/contributors\">here</a>.<br />Some of the contributors of MeshLab have received financial support from various projects, acknowledged <a href=\"http://vcg.isti.cnr.it/projects.php\">here</a>.</p>", nullptr));
        okButton->setText(QApplication::translate("aboutDialog", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class aboutDialog: public Ui_aboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
