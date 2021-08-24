
#include "zoom-and-navigate-frame.h"

#include <QDebug>

#include "styles.h"


Zoom_and_Navigate_Frame::Zoom_and_Navigate_Frame(QWidget* parent)
  :  QFrame(parent)
{
 image_data_ = nullptr;

 QString button_style_sheet = colorful_small_button_style_sheet_();

 handle_zoom_ok_ = false;
 initial_zoom_position_ = 25;
 initial_annotation_zoom_position_ = 100;

 last_zoom_position_ = -1;
 last_annotation_zoom_position_ = -1;

 QString s1 = QString("%1").arg(QChar(5184));
 zoom_in_button_ = new QPushButton(s1, this);
 zoom_in_button_->setStyleSheet("QPushButton{font-size: 12pt;"
                                "font-weight: bold;"
                                "color: brown;}");
// zoom_in_button_->setFont(zif);
 zoom_in_button_->setMaximumWidth(25);
 zoom_in_button_->setMaximumHeight(15);


 QString s2 = QString("%1").arg(QChar(5189));
 zoom_out_button_ = new QPushButton(s2, this);
 zoom_out_button_->setStyleSheet("QPushButton{font-size: 12pt;"
                                "font-weight: bold; padding:0px; "
                                "color: brown;}");
 zoom_out_button_->setMaximumWidth(25);
 zoom_out_button_->setMaximumHeight(15);

 zoom_buttons_layout_ = new QHBoxLayout;

 reset_zoom_button_ = new QPushButton("Reset Zoom", this);
 reset_zoom_button_->setMaximumWidth(85);

 reset_zoom_button_->setStyleSheet(button_style_sheet);


 repeat_zoom_button_ = new QPushButton("Repeat Zoom", this);
 repeat_zoom_button_->setMaximumWidth(85);
 repeat_zoom_button_->setStyleSheet(button_style_sheet);
 repeat_zoom_button_->setEnabled(false);

 zoom_buttons_layout_->addWidget(repeat_zoom_button_);

 zoom_buttons_layout_->addStretch();

 zoom_buttons_layout_->addWidget(zoom_in_button_);

 zoom_buttons_layout_->addSpacing(10);

 zoom_buttons_layout_->addWidget(zoom_out_button_);

 zoom_buttons_layout_->addStretch();

 zoom_buttons_layout_->addWidget(reset_zoom_button_);

 connect(repeat_zoom_button_, SIGNAL(clicked(bool)), this, SLOT(handle_repeat_zoom(bool)));

 connect(reset_zoom_button_, SIGNAL(clicked(bool)), this, SLOT(handle_reset_zoom(bool)));

 connect(zoom_in_button_, SIGNAL(clicked(bool)), this, SLOT(handle_zoom_in_discrete(bool)));
 connect(zoom_out_button_, SIGNAL(clicked(bool)), this, SLOT(handle_zoom_out_discrete(bool)));


// zoom_slider_[2] = nullptr;

 zoom_slider_[0] = new ctkRangeSlider(Qt::Horizontal, this);
 zoom_slider_[1] = new ctkRangeSlider(Qt::Horizontal, this);
 zoom_slider_[2] = new QSlider(Qt::Horizontal, this);

 zoom_slider_[2]->setRange(0, 2 * initial_annotation_zoom_position_);
 zoom_slider_[2]->setValue(initial_annotation_zoom_position_);

 connect(zoom_slider_[0], SIGNAL(minimumValueChanged(int)), this,
   SLOT(handle_zoom_minimum_value_changed(int)));

 connect(zoom_slider_[0], SIGNAL(maximumValueChanged(int)), this,
   SLOT(handle_zoom_maximum_value_changed(int)));


 connect(zoom_slider_[1], SIGNAL(minimumValueChanged(int)), this,
   SLOT(handle_top_zoom_minimum_value_changed(int)));

 connect(zoom_slider_[1], SIGNAL(maximumValueChanged(int)), this,
   SLOT(handle_top_zoom_maximum_value_changed(int)));

 connect(zoom_slider_[2], SIGNAL(valueChanged(int)), this,
   SLOT(handle_annotation_zoom_value_changed(int)));


 ((ctkRangeSlider*) zoom_slider_[0])->setMinimumValue(initial_zoom_position_);
 ((ctkRangeSlider*) zoom_slider_[0])->setMaximumValue(100 - initial_zoom_position_);

 ((ctkRangeSlider*) zoom_slider_[1])->setMinimumValue(initial_zoom_position_);
 ((ctkRangeSlider*) zoom_slider_[1])->setMaximumValue(100 - initial_zoom_position_);

 zoom_sliders_group_box_ = new QGroupBox("Zoom (Image)", this);
 zoom_sliders_top_group_box_ = new QGroupBox("Notes/Image", this);

 zoom_sliders_group_box_->setStyleSheet(soft_group_box_style_sheet_().arg(99));
 zoom_sliders_top_group_box_->setStyleSheet(soft_group_box_style_sheet_().arg(12));

 // zoom_sliders_group_box_[1] = new QGroupBox("Notes", this);
// zoom_sliders_group_box_[2] = new QGroupBox("Notes and Image", this);

 zoom_sliders_group_box_layout_ = new QVBoxLayout;
 zoom_sliders_top_group_box_layout_ = new QHBoxLayout;
// zoom_sliders_group_box_layout_[1] = new QVBoxLayout;
// zoom_sliders_group_box_layout_[2] = new QVBoxLayout;


 zoom_sliders_group_box_layout_->addLayout(zoom_buttons_layout_);
 zoom_sliders_group_box_layout_->addWidget(zoom_slider_[0]);

 zoom_sliders_group_box_->setLayout(zoom_sliders_group_box_layout_);

 main_layout_ = new QVBoxLayout;

// main_layout_->addWidget(zoom_slider_[0]);

// main_layout_->addStretch(1);

 zoom_sliders_top_group_box_layout_->addWidget(zoom_slider_[1], 3);
 zoom_sliders_top_group_box_layout_->addWidget(zoom_slider_[2], 1);

 reset_all_button_ = new QPushButton("Reset (All)", this);
 reset_all_button_->setMaximumWidth(85);

 reset_all_button_->setStyleSheet(button_style_sheet);
 reset_all_button_->setEnabled(false);

 connect(reset_all_button_, SIGNAL(clicked(bool)), this, SLOT(handle_reset_all(bool)));


 zoom_sliders_top_group_box_layout_->addWidget(reset_all_button_);

 zoom_sliders_top_group_box_->setLayout(zoom_sliders_top_group_box_layout_);

 main_layout_->addWidget(zoom_sliders_top_group_box_);

 main_layout_->addStretch(3);

 main_layout_->addWidget(zoom_sliders_group_box_);

 // zoom_sliders_group_box_layout_[1]->addWidget(zoom_slider_[1]);
 // zoom_sliders_group_box_layout_[2]->addWidget(zoom_slider_[2]);
 // zoom_sliders_group_box_[1]->setLayout(zoom_sliders_group_box_layout_[1]);
 // zoom_sliders_group_box_[2]->setLayout(zoom_sliders_group_box_layout_[2]);

 // main_layout_->addWidget(zoom_sliders_group_box_[1]);
 // main_layout_->addWidget(zoom_sliders_group_box_[2]);

 main_layout_->addStretch(2);

 image_top_left_button_ = new QPushButton("Image Top Left", this);
 image_top_left_button_->setMinimumWidth(110);

 image_top_left_button_->setStyleSheet(button_style_sheet);

 center_image_button_ = new QPushButton("Center Image", this);
 center_image_button_->setMinimumWidth(110);
 center_image_button_->setStyleSheet(button_style_sheet);

 position_buttons_layout_ = new QHBoxLayout;

 position_buttons_layout_->addStretch();
 position_buttons_layout_->addWidget(image_top_left_button_);
 position_buttons_layout_->addWidget(center_image_button_);
 position_buttons_layout_->addStretch();

 main_layout_->addLayout(position_buttons_layout_);

 connect(image_top_left_button_, SIGNAL(clicked(bool)),
   this, SIGNAL(image_top_left_button_clicked(bool)));

 connect(center_image_button_, SIGNAL(clicked(bool)),
   this, SIGNAL(center_image_button_clicked(bool)));

 multi_draw_ckb_ = new QCheckBox("Multi-Draw", this);

 bottom_layout_ = new QHBoxLayout;

 connect(multi_draw_ckb_, &QCheckBox::stateChanged,
   [this](int st)
 {
  if(st == Qt::Unchecked)
    Q_EMIT multi_draw_unset();
  else if(st == Qt::Checked)
    Q_EMIT multi_draw_set();
 });

 pan_mode_button_ = new QPushButton("Pan Mode", this);
 pan_mode_button_->setMinimumWidth(75);

 pan_mode_button_->setCheckable(true);
 pan_mode_button_->setChecked(false);

 pan_mode_button_->setStyleSheet(colorful_toggle_button_mixed_style_sheet_());

 connect(pan_mode_button_, SIGNAL(clicked(bool)), this, SIGNAL(pan_mode_changed(bool)));

 bottom_layout_->addWidget(pan_mode_button_);
 bottom_layout_->addStretch();
 bottom_layout_->addWidget(multi_draw_ckb_);


 main_layout_->addLayout(bottom_layout_);

 setLayout(main_layout_);

 //setMaximumHeight(190);

}

void Zoom_and_Navigate_Frame::reset_with_image_data(void* image_data)
{

 image_data_ = image_data;

// ((ctkRangeSlider*) zoom_slider_[0])->setMinimumValue(initial_zoom_position_);
// ((ctkRangeSlider*) zoom_slider_[1])->setMinimumValue(initial_zoom_position_);
// ((ctkRangeSlider*) zoom_slider_[2])->setMinimumValue(initial_annotation_zoom_position_);

 last_zoom_position_ = -1;
 last_annotation_zoom_position_ = -1;

 handle_reset_all(false);

 repeat_zoom_button_->setEnabled(false);
}


void Zoom_and_Navigate_Frame::handle_reset_zoom(bool)
{
 int v =  ((ctkRangeSlider*) zoom_slider_[0])->minimumValue();
 if(v != initial_zoom_position_)
 {
  last_zoom_position_ = ((ctkRangeSlider*) zoom_slider_[0])->minimumValue();
  ((ctkRangeSlider*) zoom_slider_[0])->setMinimumValue(initial_zoom_position_);
  ((ctkRangeSlider*) zoom_slider_[1])->setMinimumValue(initial_zoom_position_);
  repeat_zoom_button_->setEnabled(true);
 }
}

void Zoom_and_Navigate_Frame::handle_reset_all(bool)
{
 last_annotation_zoom_position_ = zoom_slider_[2]->value();
 handle_reset_zoom(false);
 zoom_slider_[2]->setValue(100);
 reset_all_button_->setEnabled(false);
}

void Zoom_and_Navigate_Frame::handle_repeat_zoom(bool)
{
 if(last_zoom_position_ != (u2) -1)
 {
  ((ctkRangeSlider*) zoom_slider_[0])->setMinimumValue(last_zoom_position_);
  last_zoom_position_ = -1;
  repeat_zoom_button_->setEnabled(false);
 }

 if(last_annotation_zoom_position_ != (u2) -1)
 {
  zoom_slider_[2]->setValue(last_annotation_zoom_position_);
  last_annotation_zoom_position_ = -1;
 }
}

void Zoom_and_Navigate_Frame::handle_zoom_in_discrete(bool)
{
 int v =  ((ctkRangeSlider*) zoom_slider_[0])->minimumValue();

 if(v == 50)
   return;

 if(v > 43)
   v = 50;

 else
 {
  u1 vmod = v%5;
  v -= vmod;

  if(vmod < 3)
    v += 5;
  else
    v += 10;

 }

 ((ctkRangeSlider*) zoom_slider_[0])->setMinimumValue(v);
 ((ctkRangeSlider*) zoom_slider_[1])->setMinimumValue(v);
}

void Zoom_and_Navigate_Frame::handle_zoom_out_discrete(bool)
{
 if(!image_data_) return;

 int v =  ((ctkRangeSlider*) zoom_slider_[0])->minimumValue();

 if(v == 1)
   return;

 if(v < 7)
   v = 1;
 else
 {
  u1 vmod = v%5;

  if(vmod < 2)
    v -= 5;

  v -= vmod;
 }

  ((ctkRangeSlider*) zoom_slider_[0])->setMinimumValue(v);
  ((ctkRangeSlider*) zoom_slider_[1])->setMinimumValue(v);
}




void Zoom_and_Navigate_Frame::recenter_image()
{
// int w = scrolled_image_pixmap_item_->boundingRect().width() *
//   scrolled_image_pixmap_item_->scale();
// int h = scrolled_image_pixmap_item_->boundingRect().height() *
//   scrolled_image_pixmap_item_->scale();

// int new_left = background_rectangle_center_x_ - (w/2);
// int new_top = background_rectangle_center_y_ - (h/2);

// scrolled_image_pixmap_item_->setPos(new_left, new_top);

}


void Zoom_and_Navigate_Frame::direct_adjust_zoom(int z)
{
 qreal vr = (qreal)z / 10;

 qreal adj_ratio = vr * (2.0/5.0);

 //qDebug() << "ar = " << adj_ratio ;

 Q_EMIT(zoom_factor_changed(adj_ratio));

 //?scrolled_image_pixmap_item_->setScale(adj_ratio);

}

void Zoom_and_Navigate_Frame::adjust_zoom(int z)
{
 if(!handle_zoom_ok_)
 {
  if(z == initial_zoom_position_)
    return;
  handle_zoom_ok_ = true;
 }

 direct_adjust_zoom(z);

 recenter_image();
}

void Zoom_and_Navigate_Frame::handle_zoom_minimum_value_changed(int val)
{
 ((ctkRangeSlider*) zoom_slider_[0])->setMaximumValue(100 - val);
 ((ctkRangeSlider*) zoom_slider_[1])->setMaximumValue(100 - val);

 if(!image_data_) return;

 if(val > 0)
 {
  adjust_zoom(val);
 }
}

void Zoom_and_Navigate_Frame::handle_zoom_maximum_value_changed(int val)
{
 ((ctkRangeSlider*) zoom_slider_[0])->setMinimumValue(100 - val);
 ((ctkRangeSlider*) zoom_slider_[1])->setMinimumValue(100 - val);

 if(!image_data_) return;

 if(val > 0)
 {
  adjust_zoom(100 - val);
 }
}

void Zoom_and_Navigate_Frame::handle_top_zoom_minimum_value_changed(int val)
{
 if(!image_data_)
 {
  handle_zoom_minimum_value_changed(val);
  return;
 }

 u2 v1 = ((ctkRangeSlider*) zoom_slider_[0])->minimumValue();
 handle_zoom_minimum_value_changed(val);
 u2 v2 = ((ctkRangeSlider*) zoom_slider_[0])->minimumValue();

 // //  note: annotations increase left to right, not out to in ...
 s2 diff = v2 - v1;
 u2 z = zoom_slider_[2]->value();
 zoom_slider_[2]->setValue(z + (diff * 2));
}

void Zoom_and_Navigate_Frame::handle_top_zoom_maximum_value_changed(int val)
{
 if(!image_data_)
 {
  handle_zoom_maximum_value_changed(val);
  return;
 }

 u2 v1 = ((ctkRangeSlider*) zoom_slider_[0])->minimumValue();
 handle_zoom_maximum_value_changed(val);
 u2 v2 = ((ctkRangeSlider*) zoom_slider_[0])->minimumValue();

 // //  note: annotations increase left to right, not out to in ...
 s2 diff = v2 - v1;
 u2 z = zoom_slider_[2]->value();
 zoom_slider_[2]->setValue(z + (diff * 2));
}

void Zoom_and_Navigate_Frame::handle_annotation_zoom_value_changed(int)
{
 reset_all_button_->setEnabled(true);

 // //   needs a selected annotation ...
}

