
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dhax-gui-environment.h"

#include "dhax-main-window.h"
#include "dhax-graphics-view.h"
#include "dhax-main-window-frame.h"
#include "dhax-graphics-frame.h"
#include "dhax-graphics-scene.h"

#include "dhax-data/ann/dhax-annotation-environment.h"
#include "dhax-data/ann/dhax-annotation-instance.h"

#include "dhax-gui/image-viewer/dhax-image-viewer.h"

#include <QBoxLayout>
#include <QLabel>

DHAX_GUI_Environment::DHAX_GUI_Environment()
  :  main_window_(nullptr),
     graphics_view_(nullptr),
     main_window_frame_(nullptr),
     graphics_scene_(nullptr),
     graphics_frame_(nullptr),
     image_viewer_(nullptr)
{

}


DHAX_Annotation_Environment*
 DHAX_GUI_Environment::init_annotation_environment()
{
 annotation_environment_ = new DHAX_Annotation_Environment;
 return annotation_environment_;
}


void DHAX_GUI_Environment::init_main_window()
{
 main_window_ = new DHAX_Main_Window;
}

void DHAX_GUI_Environment::init_graphics_view()
{
 graphics_view_ = new DHAX_Graphics_View;
 graphics_view_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
 graphics_view_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
}

void DHAX_GUI_Environment::init_graphics_frame_layout(QBoxLayout::Direction qbd,
  QBoxLayout::Direction secqbd)
{
 if(graphics_view_)
   graphics_frame_->set_graphics_view(graphics_view_);

 if(image_viewer_)
 {
  graphics_frame_->set_image_viewer(image_viewer_);
  graphics_frame_->set_display_image_data(image_viewer_->display_image_data());
 }
 graphics_frame_->init_layout(qbd, secqbd);
 if(graphics_scene_)
   graphics_view_->setScene(graphics_scene_);

 QObject::connect(graphics_frame_, &DHAX_Graphics_Frame::close_requested,
    [this](bool) {main_window_->close();});
}

void DHAX_GUI_Environment::init_main_window_frame_layout(QBoxLayout::Direction qbd)
{
 QBoxLayout* qbl = new QBoxLayout(qbd);
 if(graphics_frame_)
   qbl->addWidget(graphics_frame_);
 main_window_frame_->setLayout(qbl);
}


void DHAX_GUI_Environment::show_annotation_on_current_image(
  DHAX_Annotation_Instance* dai)
{
 if(dai->fits<QGraphicsRectItem>())
 {
  QRectF qrf;
  dai->init_as(qrf);
  QGraphicsRectItem* qgri = graphics_scene_->addRect(qrf);
 }
}

void DHAX_GUI_Environment::show_image(QString path)
{
 image_viewer_->load_image(path);
// QPixmap qpm(path);
// graphics_scene_->addPixmap(qpm);
}

void DHAX_GUI_Environment::init_main_window_frame()
{
 main_window_frame_ = new DHAX_Main_Window_Frame;
 main_window_->setCentralWidget(main_window_frame_);
}

void DHAX_GUI_Environment::init_graphics_frame()
{
 graphics_frame_ = new DHAX_Graphics_Frame;
}

void DHAX_GUI_Environment::init_graphics_scene()
{
 graphics_scene_ = new DHAX_Graphics_Scene;
 main_window_->setCentralWidget(main_window_frame_);
}

void DHAX_GUI_Environment::show_main_window()
{
 main_window_->show();
}


void DHAX_GUI_Environment::init_image_viewer()
{
 image_viewer_ = new DHAX_Image_Viewer;
 image_viewer_->set_main_window(main_window_);

 image_viewer_->set_scrolled_image_view(graphics_view_);
 image_viewer_->set_scrolled_image_scene(graphics_scene_);

}

