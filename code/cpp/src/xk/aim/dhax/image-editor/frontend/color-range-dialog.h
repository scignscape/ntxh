
#ifndef COLOR_RANGE_DIALOG__H
#define COLOR_RANGE_DIALOG__H

#include <QSpinBox>
#include <QDialog>

#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include <QColor>
#include <QSlider>

#include "global-types.h"


class Color_Range_Dialog : public QDialog
{
 Q_OBJECT

 QGridLayout* main_layout_;
 QGridLayout* details_layout_;

 QLabel* central_color_label_;
 QLineEdit* central_color_line_edit_;
 QPushButton* central_color_select_button_;

 QLabel* offset_label_;
 QSpinBox* offset_spin_box_;
 QPushButton* offset_confirm_buttom_;
 QSlider* offset_slider_;

 QLabel* red_green_label_;
 QLabel* red_blue_label_;
 QLabel* green_blue_label_;


 QColor central_color_;

 u1 offset_;

public:

 Color_Range_Dialog(QColor central_color, QWidget* parent = nullptr);

 void draw_label_pixmaps();


};

#endif //  COLOR_RANGE_DIALOG__H
