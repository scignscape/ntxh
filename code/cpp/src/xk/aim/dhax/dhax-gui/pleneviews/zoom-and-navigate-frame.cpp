
#include "zoom-and-navigate-frame.h"

#include "styles.h"

#include <QDebug>
#include <QLabel>

#include <QDir>

#include "styles.h"

#include "QFontIcon/qfonticon.h"


Zoom_and_Navigate_Frame::Zoom_and_Navigate_Frame(QWidget* parent)
  :  QFrame(parent)
{
 image_data_ = nullptr;
 current_selected_annotation_ = nullptr;

 QString _button_style_sheet = colorful_small_button_style_sheet_();
 auto button_style_sheet = [_button_style_sheet](u1 sz = 10)
 {
  return _button_style_sheet.arg(sz);
 };

 handle_zoom_ok_ = false;
 initial_zoom_position_ = 25;
 initial_annotation_zoom_position_ = 100;

 last_zoom_position_ = -1;
 last_annotation_zoom_position_ = -1;

 zoom_in_button_ = new QPushButton(this);
 zoom_out_button_ = new QPushButton(this);
 make_back_button(zoom_out_button_);
 make_forward_button(zoom_in_button_);

// QString s1 = QString("%1").arg(QChar(5184));
// zoom_in_button_ = new QPushButton(s1, this);
// zoom_in_button_->setStyleSheet("QPushButton{font-size: 12pt;"
//                                "font-weight: bold;"
//                                "color: brown;}");
//// zoom_in_button_->setFont(zif);
// zoom_in_button_->setMaximumWidth(25);
// zoom_in_button_->setMaximumHeight(15);


// QString s2 = QString("%1").arg(QChar(5189));
// zoom_out_button_ = new QPushButton(s2, this);
// zoom_out_button_->setStyleSheet("QPushButton{font-size: 12pt;"
//                                "font-weight: bold; padding:0px; "
//                                "color: brown;}");
// zoom_out_button_->setMaximumWidth(25);
// zoom_out_button_->setMaximumHeight(15);

 zoom_buttons_layout_ = new QHBoxLayout;

 reset_zoom_button_ = new QPushButton("Reset", this);
 reset_zoom_button_->setMaximumWidth(85);

 reset_zoom_button_->setStyleSheet(button_style_sheet());


 repeat_zoom_button_ = new QPushButton("Repeat", this);
 repeat_zoom_button_->setMaximumWidth(85);
 repeat_zoom_button_->setStyleSheet(button_style_sheet());
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


 zoom_slider_[2]->setEnabled(false);

 ((ctkRangeSlider*) zoom_slider_[0])->setMinimumValue(initial_zoom_position_);
 ((ctkRangeSlider*) zoom_slider_[0])->setMaximumValue(100 - initial_zoom_position_);

 ((ctkRangeSlider*) zoom_slider_[1])->setMinimumValue(initial_zoom_position_);
 ((ctkRangeSlider*) zoom_slider_[1])->setMaximumValue(100 - initial_zoom_position_);

 zoom_sliders_group_box_ = new QGroupBox("Zoom (Image)", this);
 zoom_sliders_top_group_box_ = new QGroupBox("Notes/Image", this);

// zoom_sliders_group_box_->setStyleSheet(soft_group_box_style_sheet_().arg(99));
// zoom_sliders_top_group_box_->setStyleSheet(soft_group_box_style_sheet_().arg(12));

 zoom_sliders_group_box_->setStyleSheet(tight_soft_group_box_style_sheet_().arg(83));
 zoom_sliders_top_group_box_->setStyleSheet(tight_left_soft_group_box_style_sheet_().arg(5));

 // zoom_sliders_group_box_[1] = new QGroupBox("Notes", this);
// zoom_sliders_group_box_[2] = new QGroupBox("Notes and Image", this);

 zoom_sliders_group_box_layout_ = new QVBoxLayout;
 zoom_sliders_top_group_box_layout_ = new QHBoxLayout;
// zoom_sliders_group_box_layout_[1] = new QVBoxLayout;
// zoom_sliders_group_box_layout_[2] = new QVBoxLayout;


 zoom_sliders_group_box_layout_->addLayout(zoom_buttons_layout_);
 zoom_sliders_group_box_layout_->addWidget(zoom_slider_[0]);

 zoom_sliders_group_box_->setLayout(zoom_sliders_group_box_layout_);

 zoom_sliders_group_box_layout_->setContentsMargins(10,2,0,2);
 zoom_sliders_top_group_box_layout_->setContentsMargins(0,0,0,0);

 main_layout_ = new QVBoxLayout;

// main_layout_->setContentsMargins(0,0,0,0);
// main_layout_->setSpacing(2);
// main_layout_->setMargin(0);

// main_layout_->addWidget(zoom_slider_[0]);

// main_layout_->addStretch(1);

 zoom_sliders_top_group_box_layout_->addWidget(zoom_slider_[1], 3);
 zoom_sliders_top_group_box_layout_->addWidget(zoom_slider_[2], 1);

 zoom_sliders_group_box_layout_->setContentsMargins(1,2,0,2);

 reset_all_button_ = new QPushButton("Reset (All)", this);
 reset_all_button_->setMaximumWidth(85);

 reset_all_button_->setStyleSheet(button_style_sheet());
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

 //image_top_left_button_ = new QPushButton("Image Top Left", this);
 image_top_left_button_ = new QPushButton(QChar(0x2751), this);
// image_top_left_button_ = new QPushButton(QChar(0x29C9), this);



 set_multiline_tooltip(image_top_left_button_, "Image Top Left",
   "Positions image so that its top-left corner coincides with top-left corner of the viewport.");
 image_top_left_button_->setMinimumWidth(50);
 image_top_left_button_->setMaximumHeight(20);

 image_top_left_button_->setStyleSheet(button_style_sheet(12));

 center_image_button_ = new QPushButton(QChar(0x29C9), this);
 center_image_button_->setMinimumWidth(50);
 center_image_button_->setMaximumHeight(20);
 set_multiline_tooltip(center_image_button_, "Center Image",
   "Positions image so that the viewport is centered on its center.");

 center_image_button_->setStyleSheet(button_style_sheet(15));


 connect(image_top_left_button_, SIGNAL(clicked(bool)),
   this, SIGNAL(image_top_left_button_clicked(bool)));

 connect(center_image_button_, SIGNAL(clicked(bool)),
   this, SIGNAL(center_image_button_clicked(bool)));

 multi_draw_ckb_ = new QCheckBox(" ", this);

 //?bottom_layout_ = new QHBoxLayout;

 connect(multi_draw_ckb_, &QCheckBox::stateChanged,
   [this](int st)
 {
  if(st == Qt::Unchecked)
    Q_EMIT multi_draw_unset();
  else if(st == Qt::Checked)
    Q_EMIT multi_draw_set();
 });

 pan_mode_button_ = new QPushButton("Pan/Pull", this);

 set_multiline_tooltip(pan_mode_button_, "Set Pan or Pull Mode",
   R"(
Pan Mode (first click, or left check box) scrolls the viewport by dragging the image;
Pull Mode (second click, or right check box) moves the image/page relative to its margins
   )");

 pan_mode_button_->setMinimumWidth(65);
 pan_mode_button_->setMaximumWidth(65);
 pan_mode_button_->setMinimumHeight(21);
 pan_mode_button_->setMaximumHeight(21);
 pan_mode_button_->setCheckable(true);
 pan_mode_button_->setChecked(false);
 pan_mode_button_->setStyleSheet(colorful_toggle_button_mixed_style_sheet_());
 connect(pan_mode_button_, &QPushButton::clicked,  [this](bool state)
 {
  // // ckb state: pull mode = 1  temp pull mode = 2  temp pan mode = 3
  if(state)
  {
   // //  pull mode
   if(pan_mode_button_->property("ckb-state").toUInt() == 1)
   {
    pan_mode_button_->setProperty("ckb-state", 0);
    pan_mode_button_->setChecked(false);
    pan_mode_button_->setStyleSheet(colorful_toggle_button_mixed_style_sheet_());
    pull_mode_ckb_->setChecked(false);
    Q_EMIT pull_mode_changed(false);
    return;
   }
  }
  else
  {
   pan_mode_button_->setProperty("ckb-state", 1);
   pan_mode_button_->setStyleSheet(colorful_toggle_button_mixed_style_sheet_());
   pan_mode_ckb_->setChecked(false);
   pull_mode_ckb_->setChecked(true);
   Q_EMIT pull_mode_changed(true);
   return;
  }

  pan_mode_ckb_->setChecked(state);
  Q_EMIT pan_mode_changed(state);
 });

 QString check_path;

 // //  set up icons
 {
  QString path = QDir::currentPath();

  check_path = path + "/_check_icon.png";

  QFontIcon::addFont(":/fontawesome.ttf");

  QIcon check = FIcon(QChar(0x2713));
  QPixmap p = check.pixmap(13, 13);
  p.save(check_path);
 }

 pan_mode_ckb_ = new QCheckBox(" ", this);
 set_multiline_tooltip(pan_mode_ckb_, "Pan Mode",
   R"(
Scrolls the viewport when dragging the image; can be temprarily
activated by pressing the <i>shift</i> or <i>meta</i> key while moving the mouse
   )");

 connect(pan_mode_ckb_, &QPushButton::clicked,
    [this](bool state)
 {
  pan_mode_button_->setChecked(state);
  if(state)
  {
   if(pull_mode_ckb_->isChecked())
   {
    pan_mode_button_->setProperty("ckb-state", 0);
    pull_mode_ckb_->setChecked(false);
   }
  }
  Q_EMIT pan_mode_changed(state);
 });

 QString ckb_stylesheet = R"(QCheckBox::indicator {
  subcontrol-position: %1 bottom;
 }
 )";

 QString ckb_basic_stylesheet = R"(
QCheckBox::indicator {
subcontrol-position: %1 bottom;
   }
   )";


 QString ckb_color_stylesheet = R"(
QCheckBox::indicator {
subcontrol-position: %1 bottom; border:1px solid %2;
   }
QCheckBox::indicator:checked {
image: url(%3);
   }
QCheckBox::indicator:unchecked {
  image: none;
   }
   )";

 pan_mode_ckb_->setStyleSheet(ckb_color_stylesheet
   .arg("right").arg("#E95289").arg(check_path));

 pan_mode_ckb_->setMaximumWidth(15);

// qDebug() << ckb_color_stylesheet_red.arg("right").arg(check_path);

// pull_mode_button_ = new QPushButton("Pull Mode", this);
// pull_mode_button_->setMaximumWidth(75);
// pull_mode_button_->setCheckable(true);
// pull_mode_button_->setChecked(false);
// pull_mode_button_->setStyleSheet(colorful_toggle_button_mixed_style_sheet_());
// connect(pull_mode_button_, &QPushButton::clicked,  [this](bool state)
// {
//  pull_mode_ckb_->setChecked(state);
//  Q_EMIT pull_mode_changed(state);
// });

 pull_mode_ckb_ = new QCheckBox(" ", this);
 set_multiline_tooltip(pull_mode_ckb_, "Pull Mode",
   R"(
In this mode, dragging causes the image to move relative to its
margins (top/left margins decrease while bottom/right increase or vice-verse);
can be temprarily activated by pressing the <i>control</i> or
<i>shift</i>+<i>meta</i> key(s) while moving the mouse
   )");

 connect(pull_mode_ckb_, &QPushButton::clicked,
    [this](bool state)
 {
  if(pan_mode_ckb_->isChecked())
  {
   pan_mode_ckb_->setChecked(false);
  }

//  pull_mode_button_->setChecked(state);
  pan_mode_button_->setChecked(false);
  pan_mode_button_->setProperty("ckb-state", (u1)state);
  pan_mode_button_->setStyleSheet(colorful_toggle_button_mixed_style_sheet_());

  Q_EMIT pull_mode_changed(state);
 });

 pull_mode_ckb_->setStyleSheet(ckb_color_stylesheet
   .arg("left").arg("#60AC8F").arg(check_path));

 pull_mode_ckb_->setMaximumWidth(15);

 QString two_line_label_stylesheet = R"(
   QLabel{font-size:7pt;}
   )";

 margin_pull_mode_ckb_  = new QCheckBox(" ", this);
 margin_pull_mode_ckb_->setMaximumWidth(15);
 margin_pull_mode_ckb_->setStyleSheet(ckb_basic_stylesheet.arg("right"));
 margin_pull_mode_ckb_label_ = new QLabel("Margin\nAdjust", this);
 margin_pull_mode_ckb_label_->setStyleSheet(two_line_label_stylesheet);
// margin_pull_mode_ckb_label_->setMaximumWidth(25);

 set_multiline_tooltip(margin_pull_mode_ckb_label_, "Use Pull Mode to Adjust Sides/Margins",
   R"(When checked, pulling the image/page against its background
   will cause the margins to temporarily change, with the option
   of keeping those changes.  Use this feature as an alternative
   to setting vertical and/or side margins manually.)"); //, 7);

 margin_pull_mode_ckb_->setToolTip(margin_pull_mode_ckb_label_->toolTip());

//? position_buttons_layout_ = new QHBoxLayout;
 position_buttons_layout_ = new QGridLayout;

 position_buttons_layout_->addWidget(pan_mode_ckb_, 0, 0, 2, 1);//, Qt::AlignRight);
 position_buttons_layout_->addWidget(pan_mode_button_, 0, 1, 3, 1);//, Qt::AlignLeft);
 position_buttons_layout_->addWidget(pull_mode_ckb_, 0, 2, 2, 1);//, Qt::AlignLeft);
 position_buttons_layout_->addWidget(margin_pull_mode_ckb_, 0, 3, 2, 1);//, Qt::AlignLeft);
 position_buttons_layout_->addWidget(margin_pull_mode_ckb_label_, 0, 4, 2, 1);//, Qt::AlignLeft);
// position_buttons_layout_->addWidget(pull_mode_button_, 0, 3, 3, 1, Qt::AlignLeft);
 position_buttons_layout_->addWidget(image_top_left_button_, 0, 6, 2, 1);
 position_buttons_layout_->addWidget(center_image_button_, 0, 8, 2, 1);

// QVBoxLayout* mdlayout = new QVBoxLayout;
// QLabel* mdlabel = new QLabel("Multi-Draw", this);
// multi_draw_ckb_->setText("");
// mdlayout->addStretch();
// mdlayout->addWidget(multi_draw_ckb_, 0, Qt::AlignCenter);
// mdlayout->addWidget(mdlabel, 0, Qt::AlignTop);
// mdlayout->addStretch();
// mdlayout->setContentsMargins(0,0,0,0);
// mdlayout->setMargin(0);
// mdlayout->setSpacing(0);
// position_buttons_layout_->addLayout(mdlayout, 0, 5, 3, 1);

 position_buttons_layout_->setMargin(0);
 position_buttons_layout_->setContentsMargins(0,0,0,0);
 position_buttons_layout_->setSpacing(0);


 multi_draw_ckb_->setMaximumWidth(15);
 multi_draw_ckb_->setStyleSheet(ckb_stylesheet.arg("left"));

 multi_draw_ckb_label_ = new QLabel("Multi\nDraw", this);
 multi_draw_ckb_label_->setStyleSheet(two_line_label_stylesheet);

 set_multiline_tooltip(multi_draw_ckb_label_, "Multi-Draw Mode",
   R"(When checked, clicking on a page/image while a provisional
   annotation is visible will have the effect of preserving
   that part of the annotation and creating a disjoint
   annotation shape with multiple segments, rather
   than delete the prior-creaeted shape and replacing it
   with a new one.)");
 multi_draw_ckb_->setToolTip(multi_draw_ckb_label_->toolTip());

 position_buttons_layout_->addWidget(multi_draw_ckb_, 0, 10, 2, 1); //, Qt::AlignTop);
 position_buttons_layout_->addWidget(multi_draw_ckb_label_, 0, 11, 2, 1);// Qt::AlignTop);
// position_buttons_layout_->addWidget(mdlabel, 1, 5, 1, 1, Qt::AlignTop);

 position_buttons_layout_->setColumnStretch(5, 1);
 position_buttons_layout_->setColumnMinimumWidth(5, 3);
 position_buttons_layout_->setColumnMinimumWidth(7, 3);
 position_buttons_layout_->setColumnStretch(9, 1);
// position_buttons_layout_->setColumnMinimumWidth(8, 10);

//? position_buttons_layout_->addWidget(pan_mode_button_);
// position_buttons_layout_->addStretch();
// position_buttons_layout_->addWidget(image_top_left_button_);
// position_buttons_layout_->addWidget(center_image_button_);
// position_buttons_layout_->addStretch();
// // bottom_layout_->addWidget(multi_draw_ckb_);
// position_buttons_layout_->addWidget(multi_draw_ckb_);


 main_layout_->addLayout(position_buttons_layout_);

// status_label_ = new QLabel("Status", this);
// status_text_ = new QLabel("Awaiting Text", this);
// bottom_layout_->addWidget(status_label_);
// bottom_layout_->addWidget(status_text_);
// bottom_layout_->addStretch();

//? main_layout_->addLayout(bottom_layout_);

 setLayout(main_layout_);

 //setMaximumHeight(190);

}

void Zoom_and_Navigate_Frame::indicate_temporary_pull_mode()
{
 pan_mode_button_->setProperty("ckb-state", 2);
 pan_mode_button_->setStyleSheet(colorful_toggle_button_mixed_style_sheet_());
}


void Zoom_and_Navigate_Frame::indicate_temporary_pan_mode()
{
 pan_mode_button_->setProperty("ckb-state", 3);
 pan_mode_button_->setStyleSheet(colorful_toggle_button_mixed_style_sheet_());
}

void Zoom_and_Navigate_Frame::unindicate_temporary_pull_mode()
{
 pan_mode_button_->setProperty("ckb-state", 0);
 pan_mode_button_->setStyleSheet(colorful_toggle_button_mixed_style_sheet_());
}

void Zoom_and_Navigate_Frame::unindicate_temporary_pan_mode()
{
 pan_mode_button_->setProperty("ckb-state", 0);
 pan_mode_button_->setStyleSheet(colorful_toggle_button_mixed_style_sheet_());
}

void Zoom_and_Navigate_Frame::unindicate_temporary_modes()
{
 pan_mode_button_->setProperty("ckb-state", 0);
 pan_mode_button_->setStyleSheet(colorful_toggle_button_mixed_style_sheet_());
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

void Zoom_and_Navigate_Frame::reset_current_selected_annotation(AXFI_Annotation* axa)
{
 current_selected_annotation_ = axa;
 zoom_slider_[2]->setEnabled(true);
}

void Zoom_and_Navigate_Frame::handle_top_zoom_minimum_value_changed(int val)
{
 u2 v1 = ((ctkRangeSlider*) zoom_slider_[0])->minimumValue();
 handle_zoom_minimum_value_changed(val);
 u2 v2 = ((ctkRangeSlider*) zoom_slider_[0])->minimumValue();

 adjust_annotation_zoom_slider(v2 - v1);
}


void Zoom_and_Navigate_Frame::adjust_annotation_zoom_slider(s2 diff)
{
 zoom_slider_[2]->setEnabled(true);

 // //  note: annotations increase left to right, not out to in ...
 u2 z = zoom_slider_[2]->value();
 zoom_slider_[2]->setValue(z + (diff * 2));

 if(!current_selected_annotation_)
   zoom_slider_[2]->setEnabled(false);
}


void Zoom_and_Navigate_Frame::handle_top_zoom_maximum_value_changed(int val)
{
 u2 v1 = ((ctkRangeSlider*) zoom_slider_[0])->minimumValue();
 handle_zoom_maximum_value_changed(val);
 u2 v2 = ((ctkRangeSlider*) zoom_slider_[0])->minimumValue();

 zoom_slider_[2]->setEnabled(true);

 adjust_annotation_zoom_slider(v2 - v1);
}

void Zoom_and_Navigate_Frame::handle_annotation_zoom_value_changed(int)
{
 reset_all_button_->setEnabled(true);

 // //   needs a selected annotation ...
}

