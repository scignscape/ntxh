
#ifndef ZOOM_AND_NAVIGATE_FRAME__H
#define ZOOM_AND_NAVIGATE_FRAME__H

#include <QFrame>

#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>
#include <QCheckBox>
#include <QButtonGroup>

// subwindows/
#include "range-slider.h"

#include "global-types.h"


class Zoom_and_Navigate_Frame : public QFrame
{
 Q_OBJECT

 QPushButton* zoom_in_button_;
 QPushButton* zoom_out_button_;

 QPushButton* pan_mode_button_;

 QPushButton* image_top_left_button_;
 QPushButton* center_image_button_;

 ctkRangeSlider* zoom_slider_;

 QHBoxLayout* zoom_buttons_layout_;
 QVBoxLayout* main_layout_;
 QHBoxLayout* position_buttons_layout_;


 bool handle_zoom_ok_;
 int initial_zoom_position_;

 void adjust_zoom(int z);
 void direct_adjust_zoom(int z);

 void recenter_image();


public:

 Zoom_and_Navigate_Frame(QWidget* parent);

Q_SIGNALS:

 void zoom_factor_changed(r8 factor);

 void center_image_button_clicked(bool);
 void image_top_left_button_clicked(bool);

 void pan_mode_changed(bool);

public Q_SLOTS:

 void handle_zoom_minimum_value_changed(int val);
 void handle_zoom_maximum_value_changed(int val);


};


#endif
