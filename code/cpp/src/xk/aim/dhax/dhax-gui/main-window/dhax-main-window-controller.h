
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DHAX_MAIN_WINDOW_CONTROLLER__H
#define DHAX_MAIN_WINDOW_CONTROLLER__H


#include "accessors.h"

#include <QString>

class DHAX_Main_Window;
class DHAX_Display_Image_Data;
class Zoom_and_Navigate_Frame;
class DHAX_Image_Viewer;
class DHAX_Image_Scene_Item;
class DHAX_Main_Window_Receiver;
class DHAX_Application_Controller;

class DHAX_Main_Window_Controller //: public QObject
{
 //Q_OBJECT

 DHAX_Main_Window* application_main_window_;
 QString current_image_file_path_;
 DHAX_Display_Image_Data* display_image_data_;
 Zoom_and_Navigate_Frame* zoom_frame_;
 DHAX_Image_Viewer* image_viewer_;
 DHAX_Image_Scene_Item* image_scene_item_;
 DHAX_Main_Window_Receiver* main_window_receiver_;
 DHAX_Application_Controller* application_controller_;

public:

 DHAX_Main_Window_Controller();

 ACCESSORS(DHAX_Main_Window* ,application_main_window)
 ACCESSORS(Zoom_and_Navigate_Frame* ,zoom_frame)
 ACCESSORS(DHAX_Display_Image_Data* ,display_image_data)
 ACCESSORS(DHAX_Image_Viewer* ,image_viewer)
 ACCESSORS(DHAX_Main_Window_Receiver* ,main_window_receiver)
 ACCESSORS(DHAX_Application_Controller* ,application_controller)
 ACCESSORS(QString ,current_image_file_path)
 ACCESSORS(DHAX_Image_Scene_Item* ,image_scene_item)

 void take_screenshot();
 void load_image();
 void load_image(QString file_path);
 void init_image_scene_item(DHAX_Image_Scene_Item* si);

 void complete_polygon();


 void draw_demo_bezier();
 void draw_demo_cubic();
 void draw_demo_quad();
};


#endif //  DHAX_MAIN_WINDOW_MENUS__H


