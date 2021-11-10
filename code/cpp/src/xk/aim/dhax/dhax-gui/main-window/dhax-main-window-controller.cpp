
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include "dhax-main-window-controller.h"

#include "dhax-main-window.h"

#include "image-viewer/dhax-display-image-data.h"
#include "subwindows/zoom-and-navigate-frame.h"

#include "image-viewer/dhax-image-viewer.h"

#include "image-viewer/dhax-image-scene-item.h"

#include "main-window/dhax-main-window-receiver.h"
#include "main-window/dhax-main-window-data.h"

#include "integration/meshlab/dhax-meshlab-integration-data.h"
#include "integration/freecad/dhax-freecad-integration-data.h"

#include "application/dhax-application-controller.h"

#include <QMenuBar>

#include <QGuiApplication>
#include <QTimer>
#include <QDebug>
#include <QFile>
#include <QScreen>

#include <QFileDialog>


DHAX_Main_Window_Controller::DHAX_Main_Window_Controller()
  :  display_image_data_(nullptr),
     zoom_frame_(nullptr),
     image_scene_item_(nullptr),
     main_window_receiver_(nullptr),
     application_controller_(nullptr)
{

}


void DHAX_Main_Window_Controller::init_image_scene_item(DHAX_Image_Scene_Item *si)
{
 image_scene_item_ = si;

 application_controller_->init_image_scene_item(si);

 si->set_meshlab_import_count(application_main_window_->
   main_window_data()->meshlab_integration()->meshlab_import_count());

 si->set_freecad_import_count(application_main_window_->
   main_window_data()->freecad_integration()->freecad_import_count());

// application_controller_

//?
// si->set_freecad_import_count(application_main_window_->
//   main_window_data()->freecad_integration()->freecad_import_count());


//?
// image_scene_item_->setGeometry(0,0,0,0);
// image_scene_item_->setObjectName(QString::fromUtf8("ImageDisplayWidget"));
// // //


 //image_scene_item_->self_connect()

// image_scene_item_->connect(image_scene_item_,SIGNAL(save_notation_requested(bool)),
//   main_window_receiver_, SLOT(handle_save_notation_requested(bool)));

// image_scene_item_->connect(image_scene_item_,SIGNAL(convert_notation_requested()),
//   main_window_receiver_, SLOT(handle_convert_notation_requested()));

// image_scene_item_->connect(image_scene_item_,SIGNAL(polygon_save_notation_requested()),
//   main_window_receiver_, SLOT(handle_polygon_save_notation_requested()));
// image_scene_item_->connect(image_scene_item_,SIGNAL(polygon_complete_and_save_notation_requested()),
//   main_window_receiver_, SLOT(handle_polygon_complete_and_save_notation_requested()));

 image_scene_item_->self_connect(SIGNAL(complete_polygon_requested()),
   main_window_receiver_, SLOT(handle_complete_polygon()));

 image_scene_item_->self_connect(SIGNAL(meshlab_import_info_requested()),
   main_window_receiver_, SLOT(handle_meshlab_import_info()));
   //show_meshlab_import_info

 image_scene_item_->self_connect(SIGNAL(freecad_import_info_requested()),
   main_window_receiver_, SLOT(handle_freecad_import_info()));

 image_scene_item_->self_connect(SIGNAL(draw_bezier_requested()),
   main_window_receiver_,
   SLOT(handle_draw_bezier()));

 image_scene_item_->self_connect(SIGNAL(draw_cubic_path_requested()),
   main_window_receiver_,
   SLOT(handle_draw_cubic_path()));

 image_scene_item_->self_connect(SIGNAL(draw_quad_path_requested()),
   main_window_receiver_,
   SLOT(handle_draw_quad_path()));

// image_scene_item_->self_connect(SIGNAL(meshlab_reset_requested()),
//   main_window_receiver_,
//   SLOT(send_meshlab_reset()));

// image_scene_item_->self_connect(SIGNAL(freecad_import_info_requested()),
//   main_window_receiver_,
//   SLOT(show_freecad_import_info()));


}

void DHAX_Main_Window_Controller::load_image()
{
 // // set it temporarily
 QString ws =  ROOT_FOLDER "/../pics";

 QString filters = "Images (*.jpg *.png *.bmp)";
 QFileDialog qdialog;

 QString file_path = qdialog.getOpenFileName(application_main_window_, "Open Image", ws, filters);

 if(!file_path.isNull())
 {
  load_image(file_path);
 }

}

void DHAX_Main_Window_Controller::load_image(QString file_path)
{
 current_image_file_path_ = file_path;
 display_image_data_->setNameSelected(true);

 zoom_frame_->reset_with_image_data(&current_image_file_path_);

 image_viewer_->load_image(current_image_file_path_);

// display_->update();
// display_->repaint();

 init_image_scene_item(image_viewer_->image_scene_item());

 QTimer::singleShot(0, [this]
 {
  image_viewer_->recenter_scroll_top_left();
 });


}


void DHAX_Main_Window_Controller::take_screenshot()
{
 QScreen* screen = QGuiApplication::primaryScreen();
 if (!screen)
   return;

 QTimer::singleShot(10000, [=]
 {
  QPixmap pixmap = screen->grabWindow(application_main_window_->winId());
  QString path = SCREENSHOTS_FOLDER "/dhax.png";
  qDebug() << "Saving to path: " << path;

  QFile file(path);
  if(file.open(QIODevice::WriteOnly))
  {
   pixmap.save(&file, "PNG");
  }
 });

}

