
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


void DHAX_Main_Window_Receiver::handle_take_screenshot_requested()
{
 main_window_controller_->take_screenshot();
}

void DHAX_Main_Window_Receiver::handle_load_image_requested()
{
 main_window_controller_->load_image();
}
