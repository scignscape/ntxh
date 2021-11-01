
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DHAX_MAIN_WINDOW_CONTROLLER__H
#define DHAX_MAIN_WINDOW_CONTROLLER__H

#include <QObject>

#include "accessors.h"

class DHAX_Main_Window;

class DHAX_Main_Window_Controller : public QObject
{
 Q_OBJECT

 DHAX_Main_Window* application_main_window_;


public:

 DHAX_Main_Window_Controller();

 ACCESSORS(DHAX_Main_Window* ,application_main_window)

public Q_SLOTS:

 void handle_take_screenshot_requested();

};


#endif //  DHAX_MAIN_WINDOW_MENUS__H


