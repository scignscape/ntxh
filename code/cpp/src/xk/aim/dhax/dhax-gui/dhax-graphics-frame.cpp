
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include "dhax-graphics-frame.h"

#include "subwindows/shape-select-frame.h"
#include "subwindows/zoom-and-navigate-frame.h"

#include "dhax-graphics-view.h"

#include "image-viewer/dhax-display-image-data.h"
#include "image-viewer/dhax-image-viewer.h"


DHAX_Graphics_Frame::DHAX_Graphics_Frame(QWidget* parent)
  :  QFrame(parent), main_layout_(nullptr),
     shape_select_frame_(nullptr), display_image_data_(nullptr),
     zoom_frame_(nullptr), image_viewer_(nullptr),
     graphics_view_(nullptr), secondary_layout_(nullptr)
{

}

void DHAX_Graphics_Frame::init_layout(QBoxLayout::Direction qbd,
  QBoxLayout::Direction secqbd)
{
 main_layout_ = new QBoxLayout(qbd);
 secondary_layout_ = new QBoxLayout(secqbd);
 shape_select_frame_ = new Shape_Select_Frame(this);
 zoom_frame_ = new Zoom_and_Navigate_Frame(this);

 secondary_layout_->addWidget(zoom_frame_);
 secondary_layout_->addWidget(shape_select_frame_);

 main_layout_->addLayout(secondary_layout_);

 if(graphics_view_)
   main_layout_->addWidget(graphics_view_);

 setLayout(main_layout_);

 connect(zoom_frame_, SIGNAL(zoom_factor_changed(r8)), this, SLOT(handle_zoom_factor_changed(r8)));

 connect(shape_select_frame_, SIGNAL(save_requested(bool)), this, SLOT(handle_save_requested(bool)));

 connect(shape_select_frame_, SIGNAL(close_requested(bool)), this, SIGNAL(close_requested(bool)));


 connect(zoom_frame_, &Zoom_and_Navigate_Frame::image_top_left_button_clicked, [this](bool)
 {
  image_viewer_->recenter_scroll_top_left();
 });

 connect(zoom_frame_, &Zoom_and_Navigate_Frame::center_image_button_clicked, [this](bool)
 {
  image_viewer_->recenter_scroll_center();
 });

 connect(zoom_frame_, &Zoom_and_Navigate_Frame::pan_mode_changed, [this](bool mode)
 {
  if(mode)
    display_image_data_->set_pan_mode();
  else
    display_image_data_->unset_pan_mode();
 });

 connect(zoom_frame_, &Zoom_and_Navigate_Frame::multi_draw_set, [this]()
 {
  display_image_data_->set_multi_draw();
 });

 connect(zoom_frame_, &Zoom_and_Navigate_Frame::multi_draw_unset, [this]()
 {
  display_image_data_->unset_multi_draw();
 });

 // assume a rectangle to begin with ...
 setup_shape_rectangle();

 connect(shape_select_frame_,
   &Shape_Select_Frame::shape_selection_changed, [this](QString sel)
 {
  if(sel == "Rectangle")
    setup_shape_rectangle();
  else if(sel == "Polygon")
    setup_shape_polygon();
  else if(sel == "Ellipse")
    setup_shape_ellipse();
 });


}

void DHAX_Graphics_Frame::setup_shape_rectangle()
{
 display_image_data_->reset();
 display_image_data_->enableSquareDraw();
}

void DHAX_Graphics_Frame::setup_shape_polygon()
{
 display_image_data_->reset();
 display_image_data_->enablePolygonDraw();
}

void DHAX_Graphics_Frame::setup_shape_ellipse()
{
 display_image_data_->reset();
 display_image_data_->enableEllipseDraw();
}

void DHAX_Graphics_Frame::setup_highlight(bool checked)
{
 display_image_data_->enableHighlight(checked);
}