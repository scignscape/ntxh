
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include "dhax-main-window-receiver.h"

#include "dhax-main-window.h"
#include "dhax-main-window-controller.h"

#include <QMenuBar>

#include <QGuiApplication>
#include <QTimer>
#include <QDebug>
#include <QFile>
#include <QScreen>


DHAX_Main_Window_Receiver::DHAX_Main_Window_Receiver()
  :  application_main_window_(nullptr),
     main_window_controller_(nullptr)
{

}


void DHAX_Main_Window_Receiver::handle_draw_bezier()
{
 main_window_controller_->draw_demo_bezier();
}


void DHAX_Main_Window_Receiver::handle_draw_cubic_path()
{
 main_window_controller_->draw_demo_cubic();
}


void DHAX_Main_Window_Receiver::handle_draw_quad_path()
{
 main_window_controller_->draw_demo_quad();
}


void DHAX_Main_Window_Receiver::handle_get_annotation_comments(DHAX_Annotation_Instance* dai)
{
 main_window_controller_->show_annotation_comments(dai);
}

void DHAX_Main_Window_Receiver::handle_complete_polygon()
{
 main_window_controller_->complete_polygon();
}


void DHAX_Main_Window_Receiver::handle_meshlab_import_info()
{
 application_main_window_->show_meshlab_import_info();
}


void DHAX_Main_Window_Receiver::handle_freecad_import_info()
{
 application_main_window_->show_freecad_import_info();
}


void DHAX_Main_Window_Receiver::handle_take_screenshot()
{
 main_window_controller_->take_screenshot();
}

void DHAX_Main_Window_Receiver::handle_load_image()
{
 main_window_controller_->load_image();
}

void DHAX_Main_Window_Receiver::handle_show_xcsd_scene()
{
 main_window_controller_->show_xcsd_scene();
}


void DHAX_Main_Window_Receiver::handle_calculate_local_color_histograms()
{
 main_window_controller_->calculate_local_color_histograms();
}


void DHAX_Main_Window_Receiver::handle_load_pdf()
{
 main_window_controller_->load_pdf();
}
