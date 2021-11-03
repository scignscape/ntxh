
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dhax-menu-system.h"

#include "dhax-main-window-menus.h"
#include "dhax-main-window.h"
#include "dhax-signal-generator.h"


#include <QMenuBar>


DHAX_Menu_System::DHAX_Menu_System()
{
// tools_menu:
//  take screenshot

//// file menu
//   load image
//   load annotations
//   quit

//   save annotation
//   convert aim ...




// help menu
}

void DHAX_Menu_System::init_menus()
{
 menus_ = new DHAX_Main_Window_Menus;
 menus_->set_parent(main_window_);

 menus_->init_menu("File");
 menus_->init_menu("Help");
 menus_->init_menu("Tools");

 DHAX_Signal_Generator* sg = main_window_->signal_generator();

 QMenu* file = menus_->menu("File");
 file->addAction("Load Image", [sg]
 {
  sg->emit_load_image_requested();
 });


 QMenu* tools = menus_->menu("Tools");
 tools->addAction("Take Screenshot", [sg]
 {
  sg->emit_take_screenshot_requested();
 });

}
