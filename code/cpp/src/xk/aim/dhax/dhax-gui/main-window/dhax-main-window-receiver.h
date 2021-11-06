
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DHAX_MAIN_WINDOW_RECEIVER__H
#define DHAX_MAIN_WINDOW_RECEIVER__H

#include <QObject>

#include "accessors.h"

class DHAX_Main_Window;
class DHAX_Main_Window_Controller;

class DHAX_Main_Window_Receiver : public QObject
{
 Q_OBJECT

 DHAX_Main_Window* application_main_window_;
 DHAX_Main_Window_Controller* main_window_controller_;

public:

 DHAX_Main_Window_Receiver();

 ACCESSORS(DHAX_Main_Window* ,application_main_window)
 ACCESSORS(DHAX_Main_Window_Controller* ,main_window_controller)

public Q_SLOTS:

 void handle_take_screenshot_requested();
 void handle_load_image_requested();
 void handle_complete_polygon_requested();
 void handle_meshlab_import_info_requested();
 void handle_freecad_import_info_requested();

 void handle_draw_bezier_requested();
 void handle_draw_cubic_path_requested();
 void handle_draw_quad_path_requested();


};


#endif //  DHAX_MAIN_WINDOW_RECEIVER__H


