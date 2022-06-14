
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DHAX_APPLICATION_CONTROLLER__H
#define DHAX_APPLICATION_CONTROLLER__H


#include "accessors.h"

#include "global-types.h"


#include <QString>
#include <QMap>
#include <QDir>

#include <QSize>

class DHAX_Main_Window;
class DHAX_Display_Image_Data;
class Zoom_and_Navigate_Frame;
class DHAX_Image_Viewer;
class DHAX_Image_Scene_Item;
class DHAX_Main_Window_Receiver;
class DHAX_UDP_Controller;
class Page_and_Search_Frame;

class DHAX_Integration_Controller;
class DHAX_Main_Window_Controller;
class DHAX_Application_Receiver;

class DHAX_Graphics_Frame;

class DHAX_Forge_Controller;

class DHAX_Application_State;

class Main_Window_Dialog;
typedef Main_Window_Dialog Image_Editor_Dialog_Window;

class DHAX_Application_Controller
{
 DHAX_Application_State* application_state_;

 DHAX_Main_Window* application_main_window_;

 Image_Editor_Dialog_Window* current_image_editor_dialog_window_;

 DHAX_Main_Window_Controller* main_window_controller_;
 DHAX_Main_Window_Receiver* main_window_receiver_;
 DHAX_Application_Receiver* application_receiver_;

 DHAX_Forge_Controller* forge_controller_;

// QString current_image_file_path_;
// DHAX_Display_Image_Data* display_image_data_;
// Zoom_and_Navigate_Frame* zoom_frame_;
// DHAX_Image_Viewer* image_viewer_;
// DHAX_Image_Scene_Item* image_scene_item_;
// DHAX_Main_Window_Receiver* main_window_receiver_;
 DHAX_UDP_Controller* udp_controller_;

 QMap<QString, DHAX_Integration_Controller*> integration_controllers_;

 DHAX_Graphics_Frame* graphics_frame_;

 u4 autogen_index_;

 QSize old_main_window_size_;

 //?
// QString mesh_position_;
// QString mesh_file_path_;
 QString txt_filename_path_;

 Image_Editor_Dialog_Window* open_image_editor_dialog_window();


public:

 DHAX_Application_Controller();

 ACCESSORS(DHAX_Main_Window* ,application_main_window)
// ACCESSORS(Zoom_and_Navigate_Frame* ,zoom_frame)
// ACCESSORS(DHAX_Display_Image_Data* ,display_image_data)
// ACCESSORS(DHAX_Image_Viewer* ,image_viewer)
// ACCESSORS(DHAX_Main_Window_Receiver* ,main_window_receiver)
 ACCESSORS(DHAX_UDP_Controller* ,udp_controller)
 ACCESSORS(DHAX_Main_Window_Controller* ,main_window_controller)
 ACCESSORS(DHAX_Application_Receiver* ,application_receiver)
 ACCESSORS(DHAX_Application_State* ,application_state)

 ACCESSORS(DHAX_Forge_Controller* ,forge_controller)

 ACCESSORS(DHAX_Graphics_Frame* ,graphics_frame)

// void take_screenshot();
// void load_image();
// void load_image(QString file_path);
// void init_image_scene_item(DHAX_Image_Scene_Item* si);

 static void r8_vector_to_qba(const QVector<r8>& data, QByteArray& qba);

 DHAX_Forge_Controller* check_init_forge_controller();

 void change_image_margins(QVector<u1> margins, u1 cim);

 void init_udp_controller();
 void dispatch_datagram(QByteArray qba);
 void init_integration_controllers();

 void load_image(QString file_path);
 void load_notes();

 void handle_edit_image_requested();

 void init_image_scene_item(DHAX_Image_Scene_Item *si);

 void send_freecad_reset();
 void send_meshlab_reset();
 void view_contours();

 void view_trimap(QString path);


 void calculate_fb_gaussian();

 void launch_edge_detection_dialog();

 QString get_current_image_folder();
 QString get_current_image_complete_base_name();
 QDir get_current_image_dir();
 QString get_current_image_file_path();


 QColor handle_change_color(QString application_role);

 void handle_image_path_show_folder();
 void handle_change_image_border_color();
 void handle_change_scene_background_color();
 void handle_change_scene_margins_color();
 void handle_change_image_margins(QVector<u1> values, u1 context);

 void handle_set_border_visible();
 void handle_unset_border_visible();

 void handle_set_image_pen_visible();
 void handle_unset_image_pen_visible();

 void handle_set_edit_transform_open_automatically();
 void handle_unset_edit_transform_open_automatically();

 void handle_expand_window();
 void handle_unexpand_window();

 void handle_view_contour_info(QString path);
 void save_current_notation(bool with_comment);
 void handle_save_requested();
 void convert_notation_to_curve();



 void handle_complate_and_save_requested(bool with_comment);
 void handle_polyline_save_requested(bool with_comment);

 void launch_color_mean_dialog(QString folder, QStringList qsl);

#ifdef USE_IFC
 void run_ifc_convert();
#endif


};


#endif //  DHAX_APPLICATION_CONTROLLER__H


