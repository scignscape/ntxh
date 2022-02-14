#include "InputDialog.h"

#include <QLabel>
#include <QSpinBox>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QDebug>

#include <QEventLoop>

#include "styles.h"

//heap is managed by parent Widget (no leak), implementation with smart ptr is not suitable in this case.
//objects are used over the scope of this class.

InputDialog::InputDialog(const QList<QString>& field_labels, int min, int max, int step,
  QWidget *parent, int initial_value) : QDialog(parent),
  field_labels_(field_labels), min_(min), max_(max), step_(step)
{

 QFormLayout* layout = new QFormLayout(this);

 for(const QString& field : field_labels)
 {
  QLabel* label = new QLabel(field, this);
  QSpinBox* edit = new QSpinBox(this);
  edit->setMinimum(min);
  edit->setMaximum(max);
  edit->setSingleStep(step);
  edit->setValue(initial_value);
  layout->addRow(label, edit);
  values_ << edit;
 }

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


 layout->addWidget(button_box_);

 connect(button_box_, &QDialogButtonBox::accepted,
         this, &InputDialog::accept);

 connect(button_box_, &QDialogButtonBox::rejected,
         this, &InputDialog::reject);

 setLayout(layout);
}


InputDialog::InputDialog(QWidget* parent, const QList<QString>& field_labels, const QVector<Input_Field>& input_fields)
 : QDialog(parent),
  field_labels_(field_labels), input_fields_(input_fields), min_(0), max_(0), step_(0)
{

 QFormLayout* layout = new QFormLayout(this);

 for(const Input_Field& infield : input_fields)
 {
  QString field = field_labels[infield.label_index];
  QLabel* label = new QLabel(field, this);
  QPushButton* zbutton = new QPushButton("0", this);
  zbutton->setStyleSheet(light_small_thin_white_button_style_sheet_().arg(7));
  zbutton->setMaximumHeight(18);
  zbutton->setMaximumWidth(18);
//  zbutton->setMinimumWidth(42);
  QHBoxLayout* hbl = new QHBoxLayout;

  if(infield.int_min == infield.int_max)
  {
   QDoubleSpinBox* dedit = new QDoubleSpinBox(this);
   dedit->setMinimum(infield.double_min);
   dedit->setMaximum(infield.double_max);
   dedit->setSingleStep(infield.increment);
   dedit->setValue(infield.default_value);
   if(infield.default_value == 0)
     zbutton->setProperty("suppressed", true);
   dedit->setDecimals(2 - infield.int_min);
   hbl->addWidget(dedit);
   hbl->addWidget(zbutton);
   connect(zbutton, &QPushButton::clicked, [dedit](bool)
   {
    dedit->setValue(0);
   });
   connect(dedit, QOverload<double>::of(&QDoubleSpinBox::valueChanged), [zbutton](double v)
   {
    zbutton->setProperty("suppressed", v == 0);
    zbutton->setStyleSheet(zbutton->styleSheet());
   });
   layout->insertRow(infield.layout_index, label, hbl);
   values_ << dedit;
  }
  else
  {
   QSpinBox* edit = new QSpinBox(this);
   edit->setMinimum(infield.int_min);
   edit->setMaximum(infield.int_max);
   edit->setValue((s4)infield.default_value);
   edit->setSingleStep((s4)infield.increment);
   hbl->addWidget(edit);
   hbl->addWidget(zbutton);
   if(infield.default_value == 0)
     zbutton->setProperty("suppressed", true);
   connect(zbutton, &QPushButton::clicked, [edit](bool)
   {
    edit->setValue(0);
   });
   connect(edit, QOverload<int>::of(&QSpinBox::valueChanged), [zbutton](double v)
   {
    zbutton->setProperty("suppressed", v == 0);
    zbutton->setStyleSheet(zbutton->styleSheet());
   });
   layout->insertRow(infield.layout_index, label, hbl);
   values_ << edit;
  }
 }

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


 layout->addWidget(button_box_);

 connect(button_box_, &QDialogButtonBox::accepted,
         this, &InputDialog::accept);

 connect(button_box_, &QDialogButtonBox::rejected,
         this, &InputDialog::reject);

 setLayout(layout);
}


QList<QPair<int, double>>
InputDialog::getFields(QWidget* parent, QList<QString>& field_labels, QVector<Input_Field>& input_fields, bool *ok)
{
 InputDialog* dialog = new InputDialog(parent, field_labels, input_fields);

 QList<QPair<int, double>> result;

 bool okInput = false;

 QEventLoop loop;
 connect(dialog, &QDialog::finished, [&loop, &okInput](int result)
 {
  okInput = result == QDialog::Accepted;
  loop.exit();
 });

 dialog->show();

 loop.exec();

 if(okInput)
 {
  *ok = okInput;
  foreach(auto value, dialog->values_)
  {
   if(QSpinBox* sb = qobject_cast<QSpinBox*>(value))
     result << QPair<int, double>{((QSpinBox*)value)->value(), 0.};
   else
     result << QPair<int, double>{0, ((QDoubleSpinBox*)value)->value()};
  }
 }

 dialog->deleteLater();
 return result;
}


QList<int> InputDialog::getFields(QWidget *parent, QList<QString>& fields, int min,
  int max, int step, bool *ok, int initial_value)
{
 InputDialog* dialog = new InputDialog(fields, min, max, step, parent, initial_value);

 QList<int> result;

 bool okInput = dialog->exec();

 if(okInput)
 {
  *ok = okInput;
  foreach(auto value, dialog->values_)
  {
   result << ((QSpinBox*)value)->value();
  }
 }

 dialog->deleteLater();
 return result;
}

