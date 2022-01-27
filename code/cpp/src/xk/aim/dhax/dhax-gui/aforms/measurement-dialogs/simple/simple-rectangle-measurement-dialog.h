
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

class Solid_Color_Label : public QWidget
{
 QColor color_;
 u1 font_pixel_size_, text_width_, width_, height_, corners_, text_offset_;

 protected:
   void paintEvent(QPaintEvent* e) Q_DECL_OVERRIDE;

 public:
  Solid_Color_Label(QColor color, u1 font_pixel_size = 10, u1 text_width = 64, u1 width = 22,
    u1 height = 14, u1 corners = 6, u1 text_offset = 3)
    :  QWidget(), color_(color), font_pixel_size_(font_pixel_size), text_width_(text_width),
       width_(width), height_(height), corners_(corners), text_offset_(text_offset)
  {
   setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
   setMinimumSize(width_ + text_width_ + text_offset, height_);
  }
};

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
 QFrame* info_frame_;

 QVector<QLabel*> parameter_labels_;
// QVector<Solid_Color_Label*> parameter_labels_;



// QLabel* width_label_;
// QLabel* height_label_;
// QLabel* area_label_;
// QLabel* perimeter_label_;

 //QVector<QPushButton*> solid_color_button_;
 //QVector<QLabel*> solid_color_labels_;
 QVector<Solid_Color_Label*> solid_color_labels_;


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
