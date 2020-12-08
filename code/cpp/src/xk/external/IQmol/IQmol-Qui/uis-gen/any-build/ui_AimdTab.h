/********************************************************************************
** Form generated from reading UI file 'AimdTab.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AIMDTAB_H
#define UI_AIMDTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AimdTab
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *_4;
    QCheckBox *deuterate;
    QComboBox *aimd_initial_velocities;
    QSpinBox *aimd_steps;
    QSpinBox *aimd_time_step;
    QLabel *label_82;
    QLabel *label_61;
    QSpinBox *aimd_fictitious_mass;
    QLabel *label_83;
    QComboBox *aimd_method;
    QSpinBox *aimd_temp;
    QLabel *label_84;
    QLabel *label_86;
    QLabel *label_87;
    QSpacerItem *horizontalSpacer_18;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *AimdTab)
    {
        if (AimdTab->objectName().isEmpty())
            AimdTab->setObjectName(QStringLiteral("AimdTab"));
        AimdTab->resize(461, 163);
        verticalLayout = new QVBoxLayout(AimdTab);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        _4 = new QGridLayout();
        _4->setObjectName(QStringLiteral("_4"));
        deuterate = new QCheckBox(AimdTab);
        deuterate->setObjectName(QStringLiteral("deuterate"));

        _4->addWidget(deuterate, 2, 0, 1, 1);

        aimd_initial_velocities = new QComboBox(AimdTab);
        aimd_initial_velocities->setObjectName(QStringLiteral("aimd_initial_velocities"));

        _4->addWidget(aimd_initial_velocities, 1, 1, 1, 1);

        aimd_steps = new QSpinBox(AimdTab);
        aimd_steps->setObjectName(QStringLiteral("aimd_steps"));

        _4->addWidget(aimd_steps, 0, 3, 1, 1);

        aimd_time_step = new QSpinBox(AimdTab);
        aimd_time_step->setObjectName(QStringLiteral("aimd_time_step"));

        _4->addWidget(aimd_time_step, 1, 3, 1, 1);

        label_82 = new QLabel(AimdTab);
        label_82->setObjectName(QStringLiteral("label_82"));

        _4->addWidget(label_82, 3, 2, 1, 1);

        label_61 = new QLabel(AimdTab);
        label_61->setObjectName(QStringLiteral("label_61"));

        _4->addWidget(label_61, 1, 2, 1, 1);

        aimd_fictitious_mass = new QSpinBox(AimdTab);
        aimd_fictitious_mass->setObjectName(QStringLiteral("aimd_fictitious_mass"));
        aimd_fictitious_mass->setMaximum(9999);

        _4->addWidget(aimd_fictitious_mass, 3, 3, 1, 1);

        label_83 = new QLabel(AimdTab);
        label_83->setObjectName(QStringLiteral("label_83"));

        _4->addWidget(label_83, 1, 0, 1, 1);

        aimd_method = new QComboBox(AimdTab);
        aimd_method->setObjectName(QStringLiteral("aimd_method"));

        _4->addWidget(aimd_method, 0, 1, 1, 1);

        aimd_temp = new QSpinBox(AimdTab);
        aimd_temp->setObjectName(QStringLiteral("aimd_temp"));
        aimd_temp->setMaximum(9999);

        _4->addWidget(aimd_temp, 2, 3, 1, 1);

        label_84 = new QLabel(AimdTab);
        label_84->setObjectName(QStringLiteral("label_84"));

        _4->addWidget(label_84, 0, 0, 1, 1);

        label_86 = new QLabel(AimdTab);
        label_86->setObjectName(QStringLiteral("label_86"));

        _4->addWidget(label_86, 0, 2, 1, 1);

        label_87 = new QLabel(AimdTab);
        label_87->setObjectName(QStringLiteral("label_87"));

        _4->addWidget(label_87, 2, 2, 1, 1);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        _4->addItem(horizontalSpacer_18, 0, 4, 1, 1);


        verticalLayout->addLayout(_4);

        verticalSpacer = new QSpacerItem(17, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(AimdTab);

        QMetaObject::connectSlotsByName(AimdTab);
    } // setupUi

    void retranslateUi(QWidget *AimdTab)
    {
        AimdTab->setWindowTitle(QApplication::translate("AimdTab", "Form", Q_NULLPTR));
        deuterate->setText(QApplication::translate("AimdTab", "Deuterate", Q_NULLPTR));
        aimd_time_step->setSuffix(QApplication::translate("AimdTab", " a.u.", Q_NULLPTR));
        label_82->setText(QApplication::translate("AimdTab", "Electron Mass", Q_NULLPTR));
        label_61->setText(QApplication::translate("AimdTab", "Time Step", Q_NULLPTR));
        aimd_fictitious_mass->setSuffix(QApplication::translate("AimdTab", " a.u.", Q_NULLPTR));
        label_83->setText(QApplication::translate("AimdTab", "Initial Velocities", Q_NULLPTR));
        aimd_temp->setSuffix(QApplication::translate("AimdTab", " K", Q_NULLPTR));
        label_84->setText(QApplication::translate("AimdTab", "Method", Q_NULLPTR));
        label_86->setText(QApplication::translate("AimdTab", "Number of Steps", Q_NULLPTR));
        label_87->setText(QApplication::translate("AimdTab", "Temperature", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AimdTab: public Ui_AimdTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AIMDTAB_H
