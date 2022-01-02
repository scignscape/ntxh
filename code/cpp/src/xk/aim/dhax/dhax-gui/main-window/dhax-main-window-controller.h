
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
class Page_and_Search_Frame;
class DHAX_Image_Viewer;
class DHAX_Image_Scene_Item;
class DHAX_Main_Window_Receiver;
class DHAX_Application_Controller;
class DHAX_Annotation_Instance;

class PDF_Document_Controller;


class DHAX_Main_Window_Controller //: public QObject
{
 //Q_OBJECT

 DHAX_Main_Window* application_main_window_;
 QString current_image_file_path_;
 DHAX_Display_Image_Data* display_image_data_;
 Zoom_and_Navigate_Frame* zoom_frame_;
 Page_and_Search_Frame* page_and_search_frame_;
 DHAX_Image_Viewer* image_viewer_;
 DHAX_Image_Scene_Item* image_scene_item_;
 DHAX_Main_Window_Receiver* main_window_receiver_;
 DHAX_Application_Controller* application_controller_;

 PDF_Document_Controller* document_controller_;

public:

 DHAX_Main_Window_Controller();

 ACCESSORS(DHAX_Main_Window* ,application_main_window)
 ACCESSORS(Zoom_and_Navigate_Frame* ,zoom_frame)
 ACCESSORS(Page_and_Search_Frame* ,page_and_search_frame)
 ACCESSORS(DHAX_Display_Image_Data* ,display_image_data)
 ACCESSORS(DHAX_Image_Viewer* ,image_viewer)
 ACCESSORS(DHAX_Main_Window_Receiver* ,main_window_receiver)
 ACCESSORS(DHAX_Application_Controller* ,application_controller)
 ACCESSORS(QString ,current_image_file_path)
 ACCESSORS(DHAX_Image_Scene_Item* ,image_scene_item)

 void check_init_document_controller();

 // //  for some reason delaying this call
  //    using a 0-second QTimer is necessary
  //    to get the scroll to work properly ...
 void delayed_image_viewer_recenter_scroll_top_left();

 void take_screenshot();
 void load_image();
 void load_pdf();
 void load_image(QString file_path);
 void init_image_scene_item(DHAX_Image_Scene_Item* si);

 void show_annotation_comments(DHAX_Annotation_Instance* dai);

 void complete_polygon();
 void init_polyline();


 void draw_demo_bezier();
 void draw_demo_cubic();
 void draw_demo_quad();
};


#endif //  DHAX_MAIN_WINDOW_MENUS__H


