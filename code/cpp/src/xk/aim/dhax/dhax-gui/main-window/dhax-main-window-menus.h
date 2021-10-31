
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DHAX_MAIN_WINDOW_MENUS__H
#define DHAX_MAIN_WINDOW_MENUS__H

#include <QMenu>
#include <QMap>

#include "accessors.h"

class DHAX_Main_Window;

class DHAX_Main_Window_Menus
{
 DHAX_Main_Window* parent_;

 QMap<QString, QMenu*> menus_;

// QMenu* help_menu_;
// QMenu* tools_menu_;

public:

 DHAX_Main_Window_Menus();

 ACCESSORS(DHAX_Main_Window* ,parent)

 void init_menu(QString label);
 QMenu* menu(QString label);

};


#endif //  DHAX_MAIN_WINDOW_MENUS__H


