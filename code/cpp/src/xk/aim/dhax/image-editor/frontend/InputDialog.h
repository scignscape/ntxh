#ifndef MULTIPLEINPUTDIALOG_H
#define MULTIPLEINPUTDIALOG_H

#include <QSpinBox>
#include <QDialog>

#include "global-types.h"

class QLabel;

class InputDialog : public QDialog
{
 Q_OBJECT

public:


 struct Input_Field {

   u1 label_index;
   u1 layout_index;
   r8 default_value;
   s4 int_min;
   s4 int_max;
   r8 double_min;
   r8 double_max;
   r8 increment;

  Input_Field& index(u1 i)
  {
   label_index = i; layout_index = i; return *this;
  }

  template<typename T>
  Input_Field& index_end(T& t)
  {
   return index(t.size());
  }

  template<typename T>
  T& into(T& t)
  {
   t.push_back(*this);
   return t;
  }

  template<typename T>
  T& index_into(T& t)
  {
   index(t.size());
   return into(t);
  }

 };

 static Input_Field _infield(r8 default_value, r4 increment)
 {
  return {0, 0, default_value, 0, 0, 0, 0, increment};
 }

 static Input_Field _infield(r8 default_value, r8 increment, s4 decimal_or_int_min)
 {
  return {0, 0, default_value, decimal_or_int_min, decimal_or_int_min, 0, 0, increment};
 }

 static Input_Field _infield(r8 default_value, r8 increment, s4 int_min, s4 int_max)
 {
  return {0, 0, default_value, int_min, int_max, 0, 0, increment};
 }

 static Input_Field _infield(r8 default_value, r8 increment, QPair<r8, r8> double_min_max, s4 decimal = 0)
 {
  return {0, 0, default_value, decimal, decimal, double_min_max.first, double_min_max.second, increment};
 }

 static QList<int> getFields(QWidget *parent, QList<QString>& field_labels, int min, int max, int step, bool *ok);

 static QList<QPair<int, double>>
   getFields(QWidget* parent, QList<QString>& field_labels, QVector<Input_Field>& input_fields, bool *ok);

// static QList<QPair<int, double>>
//   getFields(QWidget *parent, QList<QPair<QString, Input_Field>>& input_fields, bool *ok);

private:

 explicit InputDialog(const QList<QString>& field_labels, int min=0, int max=100, int step=1, QWidget *parent = nullptr);

 InputDialog(QWidget* parent, const QList<QString>& field_labels, const QVector<Input_Field>& input_fields);

 QList<QAbstractSpinBox* > values_;
 QList<QString> field_labels_;
 int min_;
 int max_;
 int step_;

 QVector<Input_Field> input_fields_;

};

#endif // MULTIPLEINPUTDIALOG_H
