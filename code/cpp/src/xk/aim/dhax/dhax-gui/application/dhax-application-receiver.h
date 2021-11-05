
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DHAX_APPLICATION_RECEIVER__H
#define DHAX_APPLICATION_RECEIVER__H

#include <QObject>

#include "accessors.h"

class DHAX_Main_Window;
class DHAX_Application_Controller;

class DHAX_Application_Receiver : public QObject
{
 Q_OBJECT

 DHAX_Main_Window* application_main_window_;
 DHAX_Application_Controller* application_controller_;

public:

 DHAX_Application_Receiver();

 ACCESSORS(DHAX_Main_Window* ,application_main_window)
 ACCESSORS(DHAX_Application_Controller* ,application_controller)

public Q_SLOTS:

// void handle_take_screenshot_requested();
// void handle_load_image_requested();

};


#endif //  DHAX_APPLICATION_RECEIVER__H


