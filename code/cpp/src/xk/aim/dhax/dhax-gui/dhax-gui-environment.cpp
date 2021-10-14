
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dhax-gui-environment.h"

#include "dhax-main-window.h"
#include "dhax-graphics-view.h"
#include "dhax-main-window-frame.h"


DHAX_GUI_Environment::DHAX_GUI_Environment()
  :  main_window_(nullptr),
     graphics_view_(nullptr), main_window_frame_(nullptr)
{

}


void DHAX_GUI_Environment::init_main_window()
{
 main_window_ = new DHAX_Main_Window;
}

void DHAX_GUI_Environment::init_graphics_view()
{
 graphics_view_ = new DHAX_Graphics_View;
}

void DHAX_GUI_Environment::init_main_window_frame()
{
 main_window_frame_ = new DHAX_Main_Window_Frame;
 main_window_->setCentralWidget(main_window_frame_);
}

void DHAX_GUI_Environment::show_main_window()
{
 main_window_->show();
}
