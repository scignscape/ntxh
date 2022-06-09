
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DHAX_MAIN_WINDOW_RECEIVER__H
#define DHAX_MAIN_WINDOW_RECEIVER__H

#include <QObject>

#include "accessors.h"

#include "xcsd-2d/xcsd-sdi-structures.h"

class DHAX_Main_Window;
class DHAX_Main_Window_Controller;
class DHAX_Annotation_Instance;

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

 void handle_take_screenshot();
 void handle_load_image();
 void handle_show_xcsd_scene();

 void handle_calculate_local_color_histograms();
 void handle_save_local_color_histograms();

 void handle_save_fb_gradient_trimap();

 void handle_load_pdf();
 void handle_complete_polygon();
 void handle_meshlab_import_info();
 void handle_freecad_import_info();

 void handle_draw_bezier();
 void handle_draw_cubic_path();
 void handle_draw_quad_path();

 void handle_get_annotation_comments(DHAX_Annotation_Instance* dai);

 void handle_show_local_histogram(rc2);

};


#endif //  DHAX_MAIN_WINDOW_RECEIVER__H


