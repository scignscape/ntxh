
#ifndef COLOR_RANGE_DIALOG__H
#define COLOR_RANGE_DIALOG__H

#include <QSpinBox>
#include <QDialog>

#include <QDialogButtonBox>

#include <QGroupBox>
#include <QRadioButton>

#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include <QColor>
#include <QSlider>

#include <QCheckBox>

#include "global-types.h"

#include "accessors.h"


class Color_Range_Dialog : public QDialog
{
 Q_OBJECT

 QDialogButtonBox* button_box_;
 QPushButton* button_proceed_;
 QPushButton* button_cancel_;


 QGridLayout* main_layout_;
 QGridLayout* details_layout_;

 QLabel* central_color_label_;
 QLineEdit* central_color_line_edit_;
 QPushButton* central_color_select_button_;

 QLabel* offset_label_;
 QSpinBox* offset_spin_box_;
 QPushButton* offset_confirm_buttom_;
 QSlider* offset_slider_;

 QLabel* background_color_label_;
 QLineEdit* background_color_line_edit_;
 QPushButton* background_color_select_button_;

 QSpinBox* background_opacity_spin_box_;
 QCheckBox* background_color_fully_transparent_;

 QLabel* red_green_label_;
 QLabel* red_blue_label_;
 QLabel* green_blue_label_;


 QColor background_color_;
 QColor central_color_;

 u1 offset_;
 u1 background_opacity_;
 u1 old_background_opacity_;

 QGroupBox* metric_group_box_;
 QRadioButton* max_difference_button_;
 QRadioButton* sum_difference_button_;
 QRadioButton* vector_difference_button_;
 QCheckBox* weighted_check_box_;



public:

 Color_Range_Dialog(QColor central_color, QWidget* parent = nullptr);

 void draw_label_pixmaps();

 ACCESSORS__GET(QColor ,central_color)
 ACCESSORS__GET(u1 ,offset)
 ACCESSORS__GET(QColor ,background_color)
 ACCESSORS__GET(u1 ,background_opacity)

 enum class Metric_Codes {
  N_A = 0, Max_Difference = 1, Sum_Difference = 2, Vector_Difference = 3,
  Weighted_Max_Difference = 4, Weighted_Sum_Difference = 5, Weighted_Vector_Difference = 6,
  Exact_Match = 7
 };

 u1 get_metric_code();

};

#endif //  COLOR_RANGE_DIALOG__H
