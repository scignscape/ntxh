
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DHAX_APPLICATION_CONTROLLER__H
#define DHAX_APPLICATION_CONTROLLER__H


#include "accessors.h"

#include <QString>
#include <QMap>

class DHAX_Main_Window;
class DHAX_Display_Image_Data;
class Zoom_and_Navigate_Frame;
class DHAX_Image_Viewer;
class DHAX_Image_Scene_Item;
class DHAX_Main_Window_Receiver;
class DHAX_UDP_Controller;

class DHAX_Integration_Controller;
class DHAX_Main_Window_Controller;

class DHAX_Application_Controller //: public QObject
{
 //Q_OBJECT

 DHAX_Main_Window* application_main_window_;

 DHAX_Main_Window_Controller* main_window_controller_;

// QString current_image_file_path_;
// DHAX_Display_Image_Data* display_image_data_;
// Zoom_and_Navigate_Frame* zoom_frame_;
// DHAX_Image_Viewer* image_viewer_;
// DHAX_Image_Scene_Item* image_scene_item_;
// DHAX_Main_Window_Receiver* main_window_receiver_;
 DHAX_UDP_Controller* udp_controller_;

 QMap<QString, DHAX_Integration_Controller*> integration_controllers_;

public:

 DHAX_Application_Controller();

 ACCESSORS(DHAX_Main_Window* ,application_main_window)
// ACCESSORS(Zoom_and_Navigate_Frame* ,zoom_frame)
// ACCESSORS(DHAX_Display_Image_Data* ,display_image_data)
// ACCESSORS(DHAX_Image_Viewer* ,image_viewer)
// ACCESSORS(DHAX_Main_Window_Receiver* ,main_window_receiver)
 ACCESSORS(DHAX_UDP_Controller* ,udp_controller)
 ACCESSORS(DHAX_Main_Window_Controller* ,main_window_controller)

// void take_screenshot();
// void load_image();
// void load_image(QString file_path);
// void init_image_scene_item(DHAX_Image_Scene_Item* si);

 void init_udp_controller();
 void dispatch_datagram(QByteArray qba);
 void init_integration_controllers();

 void load_image(QString file_path);

};


#endif //  DHAX_MAIN_WINDOW_MENUS__H


