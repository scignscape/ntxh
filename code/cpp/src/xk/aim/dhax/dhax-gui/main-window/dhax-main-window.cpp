
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dhax-main-window.h"

#include "dhax-main-window-menus.h"


DHAX_Main_Window::DHAX_Main_Window()
  :  QMainWindow()
{

}


void DHAX_Main_Window::init_menus()
{
 menus_ = new DHAX_Main_Window_Menus;
 menus_->set_parent(this);

 menus_->init_menu("File");
 menus_->init_menu("Help");
 menus_->init_menu("Tools");

}
