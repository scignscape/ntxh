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
   s4 int_min;
   s4 int_max;
   r8 double_min;
   r8 double_max;
   r4 increment;
   s1 decimal_digits;

 };

 static QList<int> getFields(QWidget *parent, QList<QString> fields_label, int min, int max, int step, bool *ok);

 static QList<QPair<int, double>>
   getFields(QWidget *parent, QList<QPair<QString, Input_Field>>& input_fields, bool *ok);


private:

 explicit InputDialog(const QList<QString>& field_labels, int min=0, int max=100, int step=1, QWidget *parent = nullptr);

 InputDialog(QWidget* parent, const QList<QString>& field_labels, const QVector<Input_Field>& input_fields);

 QList<QSpinBox* > values_;
 QList<QString> field_labels_;
 int min_;
 int max_;
 int step_;

 QVector<Input_Field> input_fields_;

};

#endif // MULTIPLEINPUTDIALOG_H
