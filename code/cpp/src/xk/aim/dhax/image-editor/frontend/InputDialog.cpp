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

 u1 index = 0;
 for(const QString& field : field_labels)
 {
  QLabel* label = new QLabel(field, this);
  QSpinBox* edit = new QSpinBox(this);

  Input_Field infield = input_fields_[index];
  if(infield.int_min == 0 && infield.int_max == 0)
  {
   edit->setMinimum(infield.double_min);
   edit->setMaximum(infield.double_max);
  }
  else
  {
   edit->setMinimum(infield.int_min);
   edit->setMaximum(infield.int_max);
  }
  edit->setSingleStep(infield.increment);
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


QList<int> InputDialog::getFields(QWidget *parent, QList<QString> fields, int min, int max, int step, bool *ok)
{
 InputDialog* dialog = new InputDialog(fields, min, max, step, parent);

 QList<int> list;

 bool okInput = dialog->exec();

 if(okInput){
  *ok = okInput;
  foreach(auto value, dialog->values_)
  {
   list << value->value();
  }
 }

 dialog->deleteLater();
 return list;
}
