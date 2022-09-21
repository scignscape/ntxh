#ifndef ui_fImagingSubtypePredictor_H
#define ui_fImagingSubtypePredictor_H

#include <QtCore/QVariant>
// #include <QtGui/QAction>
// #include <QtGui/QApplication>
// #include <QtGui/QButtonGroup>
// #include <QtGui/QCheckBox>
// #include <QtGui/QDialog>
// #include <QtGui/QFrame>
// #include <QtGui/QGridLayout>
// #include <QtGui/QHBoxLayout>
// #include <QtGui/QHeaderView>
// #include <QtGui/QLabel>
// #include <QtGui/QLineEdit>
// #include <QtGui/QPushButton>
// #include <QtGui/QSpacerItem>
// #include <QtGui/QSpinBox>
// NEW CHANGES
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QGroupBox>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class ui_fImagingSubtypePredictor
{
public:
	QGridLayout *gridLayout_3;
	QVBoxLayout * verticalLayout;
	QGroupBox *classificationGroupBox;
	QGridLayout * classificationGridLayout;
	QGroupBox *outputGroupBox;
	QRadioButton * rdNewClassification;
	QRadioButton * rdExistingClassification;
	QRadioButton *rdCreateModel;
	QLineEdit * svmModelFileName;
	QPushButton * svmModelButton;
	QLineEdit * testSubjectsDirectoryName;
	QPushButton * testSubjectsDirectoryButton;


	QLineEdit * existingMaskDirectoryName;
	QPushButton * existingMasksButton;

	QGridLayout *outputGridLayout;
	QLabel	*outputDirectoryLabel;
	QLabel	*trainingDirectoryLabel;
	QLabel	*testDirectoryLabel;
	QLabel	*modelDirectoryLabel;


	QLineEdit *outputDirectoryName;
	QPushButton *outputDirectoryButton;

	QPushButton * confirmButton;
	QPushButton * cancelButton;

	QCheckBox * cbT1Data;
	QCheckBox * cbDTIData;
	QCheckBox * cbPerfData;
	QCheckBox * cbDistanceData;

	QHBoxLayout * horizontalLayout;

	void setupUi(QDialog *fImagingSubtypeDialog)
	{

		if (fImagingSubtypeDialog->objectName().isEmpty())
			fImagingSubtypeDialog->setObjectName(QString::fromUtf8("fImagingSubtypeDialog"));
		fImagingSubtypeDialog->setWindowModality(Qt::ApplicationModal);
		fImagingSubtypeDialog->resize(200, 200); // needs to be screenSize dependent
		QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
		sizePolicy.setHorizontalStretch(0);
		sizePolicy.setVerticalStretch(0);
		sizePolicy.setHeightForWidth(fImagingSubtypeDialog->sizePolicy().hasHeightForWidth());
		fImagingSubtypeDialog->setSizePolicy(sizePolicy);
		fImagingSubtypeDialog->setMinimumSize(QSize(0, 0));

    //fImagingSubtypeDialog->setModal(true);
		gridLayout_3 = new QGridLayout(fImagingSubtypeDialog);
		gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));

		//--------------------------------------------------------------------
		classificationGroupBox = new QGroupBox(fImagingSubtypeDialog);
		classificationGroupBox->setTitle(QString::fromStdString("Classification"));
		classificationGridLayout = new QGridLayout(classificationGroupBox);
		classificationGridLayout->setObjectName(QString::fromUtf8("imagestabgridLayout3"));

		rdNewClassification = new QRadioButton(classificationGroupBox);
		rdNewClassification->setObjectName(QString::fromUtf8("newClassification"));
		rdExistingClassification = new QRadioButton(classificationGroupBox);
		rdExistingClassification->setObjectName(QString::fromUtf8("existingClassification"));
		rdCreateModel = new QRadioButton(classificationGroupBox);
		rdCreateModel->setObjectName(QString::fromUtf8("createModel"));

		svmModelFileName = new QLineEdit(classificationGroupBox);
		svmModelFileName->setObjectName(QString::fromUtf8("svmModeFileName"));
		QSizePolicy sizePolicy13(QSizePolicy::Preferred, QSizePolicy::Fixed);
		sizePolicy13.setHorizontalStretch(0);
		sizePolicy13.setVerticalStretch(0);
		sizePolicy13.setHeightForWidth(svmModelFileName->sizePolicy().hasHeightForWidth());
		svmModelFileName->setSizePolicy(sizePolicy13);
		svmModelFileName->setAlignment(Qt::AlignCenter | Qt::AlignTrailing | Qt::AlignVCenter);
    //svmModelFileName->setText("../data/recurrence/");

		testSubjectsDirectoryName = new QLineEdit(classificationGroupBox);
		testSubjectsDirectoryName->setObjectName(QString::fromUtf8("testSubjectsDirectoryName"));
		sizePolicy13.setHeightForWidth(testSubjectsDirectoryName->sizePolicy().hasHeightForWidth());
		testSubjectsDirectoryName->setSizePolicy(sizePolicy13);
		testSubjectsDirectoryName->setAlignment(Qt::AlignCenter | Qt::AlignTrailing | Qt::AlignVCenter);

		existingMaskDirectoryName = new QLineEdit(classificationGroupBox);
		existingMaskDirectoryName->setObjectName(QString::fromUtf8("existingMaskDirectoryName"));
		sizePolicy13.setHeightForWidth(existingMaskDirectoryName->sizePolicy().hasHeightForWidth());
		existingMaskDirectoryName->setSizePolicy(sizePolicy13);
		existingMaskDirectoryName->setAlignment(Qt::AlignCenter | Qt::AlignTrailing | Qt::AlignVCenter);

		svmModelButton = new QPushButton(classificationGroupBox);
		svmModelButton->setObjectName(QString::fromUtf8("svmModelButton"));
		//QPixmap pixmap("../data/images/images/OpenIcon.png");
		//QIcon ButtonIcon(pixmap);
		//svmModelButton->setIcon(ButtonIcon);
		//svmModelButton->setIconSize(QSize(20, 20)); // needs to be screenSize dependent
		svmModelButton->setText(QString("Browse"));

		testSubjectsDirectoryButton = new QPushButton(classificationGroupBox);
		testSubjectsDirectoryButton->setObjectName(QString::fromUtf8("testSubjectsDirectoryButton"));
		//testSubjectsDirectoryButton->setIcon(ButtonIcon);
		//testSubjectsDirectoryButton->setIconSize(QSize(20, 20));
		testSubjectsDirectoryButton->setText(QString("Browse"));
		testSubjectsDirectoryButton->setToolTip(QString("Directory containing Test subjects"));

		existingMasksButton = new QPushButton(classificationGroupBox);
		existingMasksButton->setObjectName(QString::fromUtf8("existingMasksButton"));
		//existingMasksButton->setIcon(ButtonIcon);
		//existingMasksButton->setIconSize(QSize(20, 20)); // needs to be screenSize dependent
		existingMasksButton->setText(QString("Browse"));
		// existingMasksButton->setToolTip(QString("Directory containing Training subjects"));
		existingMasksButton->setWhatsThis(QString("&nbsp;The meaning of the Source field depends "
			"on the Type field:"
			"<ul>"
			"<li><b>Books</b> have a Publisher"
			"<li><b>Articles</b> have a Journal name with "
			"volume and issue number"
			"<li><b>Theses</b> have an Institution name "
			"and a Department name"
			"</ul>"));

		trainingDirectoryLabel = new QLabel(classificationGroupBox);
		sizePolicy13.setHeightForWidth(trainingDirectoryLabel->sizePolicy().hasHeightForWidth());
		trainingDirectoryLabel->setSizePolicy(sizePolicy13);
		trainingDirectoryLabel->setAlignment(Qt::AlignRight);

		testDirectoryLabel = new QLabel(classificationGroupBox);
		sizePolicy13.setHeightForWidth(testDirectoryLabel->sizePolicy().hasHeightForWidth());
		testDirectoryLabel->setSizePolicy(sizePolicy13);
		testDirectoryLabel->setAlignment(Qt::AlignRight);

		modelDirectoryLabel = new QLabel(classificationGroupBox);
		sizePolicy13.setHeightForWidth(modelDirectoryLabel->sizePolicy().hasHeightForWidth());
		modelDirectoryLabel->setSizePolicy(sizePolicy13);
		modelDirectoryLabel->setAlignment(Qt::AlignRight);

		classificationGridLayout->addWidget(rdNewClassification, 0, 0, 1, 6);
		classificationGridLayout->addWidget(rdExistingClassification, 1, 0, 1, 6);
		classificationGridLayout->addWidget(modelDirectoryLabel, 2, 0, 1, 1);
		classificationGridLayout->addWidget(svmModelFileName, 2, 1, 1, 4);
		classificationGridLayout->addWidget(svmModelButton, 2, 5, 1, 1);

		classificationGridLayout->addWidget(testDirectoryLabel, 3, 0, 1, 1);
		classificationGridLayout->addWidget(testSubjectsDirectoryName, 3, 1, 1, 4);
		classificationGridLayout->addWidget(testSubjectsDirectoryButton, 3, 5, 1, 1);

		classificationGridLayout->addWidget(rdCreateModel, 4, 0, 1, 6);
		classificationGridLayout->addWidget(trainingDirectoryLabel, 5, 0, 1, 1);
		classificationGridLayout->addWidget(existingMaskDirectoryName, 5, 1, 1, 4);
		classificationGridLayout->addWidget(existingMasksButton, 5, 5, 1, 1);

		// classificationGridLayout->addWidget(line_3, 4, 1, 1, 2);

		cbT1Data = new QCheckBox(classificationGroupBox);
		cbT1Data->setObjectName(QString::fromUtf8("cbT1Data"));
		cbDTIData = new QCheckBox(classificationGroupBox);
		cbDTIData->setObjectName(QString::fromUtf8("cbDTIData"));
		cbPerfData = new QCheckBox(classificationGroupBox);
		cbPerfData->setObjectName(QString::fromUtf8("cbPerfData"));
		cbDistanceData = new QCheckBox(classificationGroupBox);
		cbDistanceData->setObjectName(QString::fromUtf8("cbDistanceData"));


		horizontalLayout = new QHBoxLayout();
		horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

		horizontalLayout->addWidget(cbT1Data);
		//horizontalLayout->addWidget(cbT2Data);
		//horizontalLayout->addWidget(cbT1ceData);
		//horizontalLayout->addWidget(cbT2FlairData);
		horizontalLayout->addWidget(cbDTIData);
		horizontalLayout->addWidget(cbPerfData);
		horizontalLayout->addWidget(cbDistanceData);

		classificationGridLayout->addLayout(horizontalLayout, 5, 0, 1, 3);
		//--------------------------output-------------------------------------------------------


		outputGroupBox = new QGroupBox(fImagingSubtypeDialog);
		outputGroupBox->setTitle(QString::fromStdString("Output"));

		outputGridLayout = new QGridLayout(outputGroupBox);
		outputGridLayout->setObjectName(QString::fromUtf8("outputGridLayout"));

		outputDirectoryLabel = new QLabel(outputGroupBox);
		sizePolicy13.setHeightForWidth(outputDirectoryLabel->sizePolicy().hasHeightForWidth());
		outputDirectoryLabel->setSizePolicy(sizePolicy13);
		outputDirectoryLabel->setAlignment(Qt::AlignRight);




		outputDirectoryName = new QLineEdit("");
		outputDirectoryName->setObjectName(QString::fromUtf8("outputDirectoryName"));
		sizePolicy13.setHeightForWidth(outputDirectoryName->sizePolicy().hasHeightForWidth());
		outputDirectoryName->setSizePolicy(sizePolicy13);
		outputDirectoryName->setAlignment(Qt::AlignCenter | Qt::AlignTrailing | Qt::AlignVCenter);

		outputDirectoryButton = new QPushButton(outputGroupBox);
		outputDirectoryButton->setObjectName(QString::fromUtf8("outputDirectoryButton"));
		//outputDirectoryButton->setIcon(ButtonIcon);
		//outputDirectoryButton->setIconSize(QSize(20, 20)); // needs to be screenSize dependent
		outputDirectoryButton->setText(QString("Browse"));

		outputGridLayout->addWidget(outputDirectoryLabel, 0, 0, 1, 1);
		outputGridLayout->addWidget(outputDirectoryName, 0, 1, 1, 4);
		outputGridLayout->addWidget(outputDirectoryButton, 0, 5, 1, 1);

		gridLayout_3->addWidget(classificationGroupBox, 0, 0, 1, 2);
		gridLayout_3->addWidget(outputGroupBox, 1, 0, 1, 2);


		confirmButton = new QPushButton(fImagingSubtypeDialog);
		confirmButton->setObjectName(QString::fromUtf8("confirm"));
		//confirmButton->setIcon(ButtonIcon);
		confirmButton->setIconSize(QSize(20, 20)); // needs to be screenSize dependent

		cancelButton = new QPushButton(fImagingSubtypeDialog);
    cancelButton->setObjectName(QString::fromUtf8("Cancel"));
		//cancelButton->setIcon(ButtonIcon);
		cancelButton->setIconSize(QSize(20, 20)); // needs to be screenSize dependent

		gridLayout_3->addWidget(confirmButton, 2, 0, 1, 1);
		gridLayout_3->addWidget(cancelButton, 2, 1, 1, 1);

		retranslateUi(fImagingSubtypeDialog);

		QMetaObject::connectSlotsByName(fImagingSubtypeDialog);
	} // setupUi

	void retranslateUi(QDialog *fImagingSubtypeDialog)
	{
		// fImagingSubtypeDialog->setWindowTitle(QApplication::translate("fImagingSubtypeDialog", "Glioblastoma Infiltration Index", 0, QApplication::UnicodeUTF8));
		// rdNewClassification->setText(QApplication::translate("fImagingSubtypeDialog", "Subject based", 0, QApplication::UnicodeUTF8));
		// rdExistingClassification->setText(QApplication::translate("fImagingSubtypeDialog", "Use existing model", 0, QApplication::UnicodeUTF8));
		// rdCreateModel->setText(QApplication::translate("fImagingSubtypeDialog", "Train new model", 0, QApplication::UnicodeUTF8));
		// confirmButton->setText(QApplication::translate("fImagingSubtypeDialog", "Confirm", 0, QApplication::UnicodeUTF8));
		// cancelButton->setText(QApplication::translate("fImagingSubtypeDialog", "Cancel", 0, QApplication::UnicodeUTF8));
      //
		// cbT1Data->setText(QApplication::translate("fImagingSubtypeDialog", "Conventional (T1, T2, Flair, T1Gd)", 0, QApplication::UnicodeUTF8));
		// cbDTIData->setText(QApplication::translate("fImagingSubtypeDialog", "DTI", 0, QApplication::UnicodeUTF8));
		// cbPerfData->setText(QApplication::translate("fImagingSubtypeDialog", "Perfusion", 0, QApplication::UnicodeUTF8));
		// cbDistanceData->setText(QApplication::translate("fImagingSubtypeDialog", "Distance", 0, QApplication::UnicodeUTF8));
      //
		// modelDirectoryLabel->setText(QApplication::translate("fImagingSubtypeDialog", "Model Directory:", 0, QApplication::UnicodeUTF8));
		// trainingDirectoryLabel->setText(QApplication::translate("fImagingSubtypeDialog", "Training Directory:", 0, QApplication::UnicodeUTF8));
		// testDirectoryLabel->setText(QApplication::translate("fImagingSubtypeDialog", "Test Directory:", 0, QApplication::UnicodeUTF8));
		// outputDirectoryLabel->setText(QApplication::translate("fImagingSubtypeDialog", "Output Directory:", 0, QApplication::UnicodeUTF8));
		// NEW CHANGES
		fImagingSubtypeDialog->setWindowTitle(QApplication::translate("fImagingSubtypeDialog", "Glioblastoma Infiltration Index", 0));
		rdNewClassification->setText(QApplication::translate("fImagingSubtypeDialog", "Subject based", 0));
		rdExistingClassification->setText(QApplication::translate("fImagingSubtypeDialog", "Use existing model", 0));
		rdCreateModel->setText(QApplication::translate("fImagingSubtypeDialog", "Train new model", 0));
		confirmButton->setText(QApplication::translate("fImagingSubtypeDialog", "Confirm", 0));
		cancelButton->setText(QApplication::translate("fImagingSubtypeDialog", "Cancel", 0));

		cbT1Data->setText(QApplication::translate("fImagingSubtypeDialog", "Conventional (T1, T2, Flair, T1Gd)", 0));
		cbDTIData->setText(QApplication::translate("fImagingSubtypeDialog", "DTI", 0));
		cbPerfData->setText(QApplication::translate("fImagingSubtypeDialog", "Perfusion", 0));
		cbDistanceData->setText(QApplication::translate("fImagingSubtypeDialog", "Distance", 0));

		modelDirectoryLabel->setText(QApplication::translate("fImagingSubtypeDialog", "Model Directory:", 0));
		trainingDirectoryLabel->setText(QApplication::translate("fImagingSubtypeDialog", "Training Directory:", 0));
		testDirectoryLabel->setText(QApplication::translate("fImagingSubtypeDialog", "Test Directory:", 0));
		outputDirectoryLabel->setText(QApplication::translate("fImagingSubtypeDialog", "Output Directory:", 0));


	} // retranslateUi

};

namespace Ui {
	class fImagingSubtypePredictor : public ui_fImagingSubtypePredictor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ui_fImagingSubtypeDialog_H
