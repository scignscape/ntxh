
#include "bim-select-dialog.h"

#include "styles.h"

#include <QPushButton>

#include <QDebug>
#include <QMessageBox>

#include "ScignStage-ling/subwindows/scignstage-clickable-label.h"


void _dg_info_cb(QObject* obj, QMouseEvent* event,
  ScignStage_Clickable_Label* scl, QString text)
{
 BIM_Select_Dialog* dlg = qobject_cast<BIM_Select_Dialog*>(obj);
 dlg->dg_info_cb(text);
 scl->unstyle();
}


void _dg_label_cb(QObject* obj, QString text)
{
 BIM_Select_Dialog* dlg = qobject_cast<BIM_Select_Dialog*>(obj);
 dlg->dg_label_cb(text);
}

void BIM_Select_Dialog::dg_label_cb(QString text)
{
 Q_EMIT text_chosen(text);
 //qDebug() << "label " << text;
}

void BIM_Select_Dialog::dg_info_cb(QString text)
{
 QString msg = text;
 msg.replace("Ifc", "Industry Foundation Classes").replace("x", " version ");
 QMessageBox::information(this, msg, text);

// qDebug() << "info " << text;
}


BIM_Select_Dialog::BIM_Select_Dialog(QWidget* parent)
  :  QDialog(parent)
{
 main_layout_ = new QVBoxLayout;

 labels_layout_ = new QGridLayout;

 setWindowTitle("IFC Vocab");

 int dg_max_col = 4;

 QStringList dg_links
 {
  "Ifc2x3",
  "Ifc2x3",
  "Ifc4",
  "Ifc4",
  "Ifc4x1",
  "Ifc4x1",
  "Ifc4x2",
  "Ifc4x2",
  "Ifc4x3_rc1",
  "Ifc4x3_rc1",
  "Ifc4x3_rc2",
  "Ifc4x3_rc2",
  "Ifc4x3_rc3",
  "Ifc4x3_rc3",
  "Ifc4x3_rc4",
  "Ifc4x3_rc4",
 };

 int j = 0;

 for(QString qs : dg_links)
 {
  // //  Uncomment to regenerate files ...
   //    QString path = QString(",%1/%2.txt",).arg(DEPENDENCY_GRAMMAR_ABOUT_FOLDER).arg(qs);
   //    save_file(path, ",\n@\n",);

  ScignStage_Clickable_Label* scl = new ScignStage_Clickable_Label(this);
  scl->setText(qs);
  scl->set_text_data(qs);
  scl->set_cb_parent(this);
  scl->set_cb({&_dg_label_cb, &_dg_info_cb});
  scl->setAlignment(Qt::AlignLeft);

  scl->setStyleSheet("*[styled_info=\"true\"] {"
    "background-color:yellow;}");

  labels_layout_->addWidget(scl, j/dg_max_col, j%dg_max_col);
  ++j;
 }
 labels_layout_->setRowStretch(((j-1)/dg_max_col)+1, 1);

 setStyleSheet(
    "ScignStage_Clickable_Label:hover{"
      "background-color:white;border:1px ridge rgb(130, 40, 0);}"
    );

 main_layout_->addLayout(labels_layout_);


// ScignStage_Clickable_Label* scl = new ScignStage_Clickable_Label(this);
// scl->set_text_data(",xxx",);
// scl->setText(",xxx",);

// main_layout_->addWidget(scl);

 button_box_ = new QDialogButtonBox(this);

 //?url_label_ = new QLabel(this);
  //?url_label_->setText(url);

// name_qle_ = new QLineEdit(this);

 button_ok_ = new QPushButton("OK");
 //? button_proceed_ = new QPushButton("Proceed");
 button_cancel_ = new QPushButton("Cancel");

 button_ok_->setDefault(false);
 button_ok_->setAutoDefault(false);

 //?button_proceed_->setDefault(false);
 //?button_proceed_->setAutoDefault(false);

 button_cancel_->setDefault(true);

 button_ok_->setStyleSheet(basic_button_style_sheet_());
 button_cancel_->setStyleSheet(basic_button_style_sheet_());


 //?button_ok_->setEnabled(false);
 button_box_->addButton(button_ok_, QDialogButtonBox::AcceptRole);
 //?button_box_->addButton(button_proceed_, QDialogButtonBox::ApplyRole);
 button_box_->addButton(button_cancel_, QDialogButtonBox::RejectRole);


 connect(button_box_, SIGNAL(accepted()), this, SLOT(accept()));
 connect(button_box_, SIGNAL(rejected()), this, SLOT(close()));

 main_layout_->addWidget(button_box_);

 setLayout(main_layout_);
}


BIM_Select_Dialog::~BIM_Select_Dialog()
{

}
