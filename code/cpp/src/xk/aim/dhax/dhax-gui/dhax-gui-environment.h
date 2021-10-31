
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DHAX_GUI_ENVIRONMENT__H
#define DHAX_GUI_ENVIRONMENT__H

#include "accessors.h"

#include <QBoxLayout>

#include <QMap>


class DHAX_Main_Window;
class DHAX_Graphics_View;
class DHAX_Main_Window_Frame;
class DHAX_Graphics_Frame;
class DHAX_Graphics_Scene;

class DHAX_Annotation_Environment;
class DHAX_Image_Viewer;
class DHAX_Annotation_Instance;


class DHAX_GUI_Environment
{
 DHAX_Main_Window* main_window_;
 DHAX_Graphics_View* graphics_view_;
 DHAX_Main_Window_Frame* main_window_frame_;
 DHAX_Graphics_Scene* graphics_scene_;
 DHAX_Graphics_Frame* graphics_frame_;
 DHAX_Annotation_Environment* annotation_environment_;
 DHAX_Image_Viewer* image_viewer_;

 void* last_loaded_vpo_;
 QMap<QString, void*> loaded_vpos_;

public:

 DHAX_GUI_Environment();

 ACCESSORS(void* ,last_loaded_vpo)

 void init_main_window();
 void init_main_window_menus();
 void init_graphics_view();
 void init_image_viewer();
 void init_graphics_scene();
 void init_graphics_frame();
 void init_graphics_frame_layout(QBoxLayout::Direction qbd, QBoxLayout::Direction secqbd);
 void init_main_window_frame();
 void init_main_window_frame_layout(QBoxLayout::Direction qbd);
 void show_image(QString path);
 void show_main_window();
 DHAX_Annotation_Environment* init_annotation_environment();
 void show_annotation_on_current_image(DHAX_Annotation_Instance* dai);

 void load_new_virtual_package_object(QString class_name);

};


#endif //  DHAX_GUI_ENVIRONMENT__H


