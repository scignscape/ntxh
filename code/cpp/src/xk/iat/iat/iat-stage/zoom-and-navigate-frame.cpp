
#include "zoom-and-navigate-frame.h"

#include <QDebug>


Zoom_and_Navigate_Frame::Zoom_and_Navigate_Frame(QWidget* parent)
  :  QFrame(parent)
{
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


 zoom_slider_ = new ctkRangeSlider(Qt::Horizontal, this);


 connect(zoom_slider_, SIGNAL(minimumValueChanged(int)), this,
   SLOT(handle_zoom_minimum_value_changed(int)));

 connect(zoom_slider_, SIGNAL(maximumValueChanged(int)), this,
   SLOT(handle_zoom_maximum_value_changed(int)));


 main_layout_ = new QVBoxLayout;
 main_layout_->addLayout(zoom_buttons_layout_);
 main_layout_->addWidget(zoom_slider_);

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

 //?scrolled_image_pixmap_item_->setScale(adj_ratio);

}

void Zoom_and_Navigate_Frame::adjust_zoom(int z)
{
 //  v == 50  r == 3
 //  v == 1   r == 1/10

 // v / 10

 if(handle_zoom_ok_)
 {
  direct_adjust_zoom(z);

  recenter_image();
 }
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


