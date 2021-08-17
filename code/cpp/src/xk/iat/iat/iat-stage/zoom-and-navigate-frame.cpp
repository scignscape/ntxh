
#include "zoom-and-navigate-frame.h"

#include <QDebug>


Zoom_and_Navigate_Frame::Zoom_and_Navigate_Frame(QWidget* parent)
  :  QFrame(parent)
{
 handle_zoom_ok_ = false;
 initial_zoom_position_ = 25;

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
 zoom_buttons_layout_->addStretch();

 zoom_buttons_layout_->addWidget(zoom_in_button_);
 zoom_buttons_layout_->addWidget(zoom_out_button_);

 zoom_buttons_layout_->addStretch();

 pan_mode_button_ = new QPushButton("Pan Mode", this);
 zoom_buttons_layout_->addWidget(pan_mode_button_);
 pan_mode_button_->setCheckable(true);
 pan_mode_button_->setChecked(false);

 connect(pan_mode_button_, SIGNAL(clicked(bool)), this, SIGNAL(pan_mode_changed(bool)));


 zoom_slider_ = new ctkRangeSlider(Qt::Horizontal, this);


 connect(zoom_slider_, SIGNAL(minimumValueChanged(int)), this,
   SLOT(handle_zoom_minimum_value_changed(int)));

 connect(zoom_slider_, SIGNAL(maximumValueChanged(int)), this,
   SLOT(handle_zoom_maximum_value_changed(int)));

 zoom_slider_->setMinimumValue(initial_zoom_position_);
 zoom_slider_->setMaximumValue(100 - initial_zoom_position_);

 main_layout_ = new QVBoxLayout;
 main_layout_->addLayout(zoom_buttons_layout_);
 main_layout_->addWidget(zoom_slider_);



 image_top_left_button_ = new QPushButton("Image Top Left", this);
 image_top_left_button_->setMinimumWidth(110);

 center_image_button_ = new QPushButton("Center Image", this);
 center_image_button_->setMinimumWidth(110);

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

 setLayout(main_layout_);

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
 zoom_slider_->setMaximumValue(100 - val);

 if(val > 0)
 {
  adjust_zoom(val);
 }

 //qDebug() << "min " << val;
}

void Zoom_and_Navigate_Frame::handle_zoom_maximum_value_changed(int val)
{
 zoom_slider_->setMinimumValue(100 - val);

 if(val > 0)
 {
  adjust_zoom(100 - val);
 }
}


