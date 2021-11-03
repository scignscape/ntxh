
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DHAX_MENU_SYSTEM__H
#define DHAX_MENU_SYSTEM__H

#include <QMenu>
#include <QMap>

#include "accessors.h"


class DHAX_Main_Window;
class DHAX_Main_Window_Menus;


class DHAX_Menu_System
{
 DHAX_Main_Window* main_window_;
 DHAX_Main_Window_Menus* menus_;

// QMenu* help_menu_;
// QMenu* tools_menu_;

public:

 DHAX_Menu_System();

 ACCESSORS(DHAX_Main_Window* ,main_window)

 void init_menus();

};


#endif //  DHAX_MENU_SYSTEM__H


