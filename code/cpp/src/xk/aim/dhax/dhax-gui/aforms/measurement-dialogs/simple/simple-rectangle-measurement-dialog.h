
#ifndef SIMPLE_RECTANGLE_MEASUREMENT_DIALOG__H
#define SIMPLE_RECTANGLE_MEASUREMENT_DIALOG__H

#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDialog>

#include <QTableWidget>
#include <QFrame>

#include <QLabel>

#include <QScrollArea>

#include <QFormLayout>

#include "global-types.h"

#include "aforms/simple/simple-rectangle-annotation.h"

//class Simple_Rectangle_Annotation;


class Simple_Rectangle_Measurement_Dialog : public QDialog
{
 Q_OBJECT


 Simple_Rectangle_Annotation* annotation_;

 QDialogButtonBox* button_box_;
 QPushButton* button_ok_;
 QPushButton* button_cancel_;

 QVBoxLayout* main_layout_;
 //QGridLayout* labels_layout_;
 QFormLayout* info_layout_;

 QScrollArea* info_scroll_area_;

 QVector<QLabel*> parameter_labels_;
// QLabel* width_label_;
// QLabel* height_label_;
// QLabel* area_label_;
// QLabel* perimeter_label_;

 template<typename NUM_Type>
 QLabel* new_QLabel(NUM_Type value)
 {
  return new QLabel(QString::number(value), this);
 }


public:


 Simple_Rectangle_Measurement_Dialog(Simple_Rectangle_Annotation* ann, QWidget* parent);
 ~Simple_Rectangle_Measurement_Dialog();



Q_SIGNALS:


};




#endif //  SIMPLE_RECTANGLE_MEASUREMENT_DIALOG__H
