
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
class DHAX_External_Application_Controller;

class DHAX_Application_Receiver : public QObject
{
 Q_OBJECT

 DHAX_Main_Window* application_main_window_;
 DHAX_Application_Controller* application_controller_;
 DHAX_External_Application_Controller* external_application_controller_;

public:

 DHAX_Application_Receiver();

 ACCESSORS(DHAX_Main_Window* ,application_main_window)
 ACCESSORS(DHAX_Application_Controller* ,application_controller)
 ACCESSORS(DHAX_External_Application_Controller* ,external_application_controller)

public Q_SLOTS:

 void handle_save_notation(bool with_comment);
 void handle_polygon_save_notation();
 void handle_freecad_reset();
 void handle_meshlab_reset();
 void handle_convert_notation();
 void handle_polygon_complete_and_save_notation();

 void handle_view_contours();
 void handle_view_3d();
 void handle_view_360();
 void handle_view_cad();

 void handle_run_forge_workflow();


// void handle_take_screenshot();
// void handle_load_image();

};


#endif //  DHAX_APPLICATION_RECEIVER__H


