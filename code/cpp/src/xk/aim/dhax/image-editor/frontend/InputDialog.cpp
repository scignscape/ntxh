#include "InputDialog.h"

#include <QLabel>
#include <QSpinBox>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QDebug>

//heap is managed by parent Widget (no leak), implementation with smart ptr is not suitable in this case.
//objects are used over the scope of this class.

InputDialog::InputDialog(const QList<QString>& field_labels, int min, int max, int step, QWidget *parent) : QDialog(parent),
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
  edit->setValue(0);
  layout->addRow(label, edit);
  values_ << edit;
 }

 QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                                                    Qt::Horizontal, this);

 layout->addWidget(buttonBox);

 connect(buttonBox, &QDialogButtonBox::accepted,
         this, &InputDialog::accept);

 connect(buttonBox, &QDialogButtonBox::rejected,
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

  if(infield.int_min == infield.int_max)
  {
   QDoubleSpinBox* dedit = new QDoubleSpinBox(this);
   dedit->setMinimum(infield.double_min);
   dedit->setMaximum(infield.double_max);
   dedit->setSingleStep(infield.increment);
   dedit->setValue(infield.default_value);
   dedit->setDecimals(2 - infield.int_min);
   layout->insertRow(infield.layout_index, label, dedit);
   values_ << dedit;
  }
  else
  {
   QSpinBox* edit = new QSpinBox(this);
   edit->setMinimum(infield.int_min);
   edit->setMaximum(infield.int_max);
   edit->setValue((s4)infield.default_value);
   edit->setSingleStep((s4)infield.increment);
   layout->insertRow(infield.layout_index, label, edit);
   values_ << edit;
  }
 }

 QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                                                    Qt::Horizontal, this);

 layout->addWidget(buttonBox);

 connect(buttonBox, &QDialogButtonBox::accepted,
         this, &InputDialog::accept);

 connect(buttonBox, &QDialogButtonBox::rejected,
         this, &InputDialog::reject);

 setLayout(layout);
}


QList<QPair<int, double>>
InputDialog::getFields(QWidget* parent, QList<QString>& field_labels, QVector<Input_Field>& input_fields, bool *ok)
{
 InputDialog* dialog = new InputDialog(parent, field_labels, input_fields);

 QList<QPair<int, double>> result;

 bool okInput = dialog->exec();

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


QList<int> InputDialog::getFields(QWidget *parent, QList<QString>& fields, int min, int max, int step, bool *ok)
{
 InputDialog* dialog = new InputDialog(fields, min, max, step, parent);

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

