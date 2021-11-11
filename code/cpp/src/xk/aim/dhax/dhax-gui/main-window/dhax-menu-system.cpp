
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dhax-menu-system.h"

#include "dhax-main-window-menus.h"
#include "dhax-main-window.h"
#include "dhax-signal-generator.h"


#include <QMenuBar>


DHAX_Menu_System::DHAX_Menu_System()
{
// tools_menu:
//  take screenshot

//// file menu
//   load image
//   load annotations
//   quit

//   save annotation
//   convert aim ...




// help menu
}

void DHAX_Menu_System::init_menus()
{
 menus_ = new DHAX_Main_Window_Menus;
 menus_->set_parent(main_window_);

 menus_->init_menu("File");
 menus_->init_menu("Help");
 menus_->init_menu("Tools");

 DHAX_Signal_Generator* sg = main_window_->signal_generator();

 DHAX_Menu& file_menu = *menus_->menu("File");
 file_menu.add_action("Load Image") << [sg]
 {
  sg->emit_load_image_requested();
 };

 file_menu.addSeparator();
 file_menu.add_action("Load Notes") << [sg]
 {
  sg->emit_load_notes_requested();
 };

 //file_menu.addAction(action_load_annotations);

 file_menu.add_action("View Contours (Open CV)") << [sg]
 {
  sg->emit_view_contours_requested();
 };

 file_menu.add_action("View 3D (MeshLab)") << [sg]
 {
  sg->emit_view_3d_requested();
 };

 file_menu.add_action("View 360 (Matterport)") << [sg]
 {
  sg->emit_view_360_requested();
 };

 file_menu.add_action("View CAD/3D (FreeCAD)") << [sg]
 {
  sg->emit_view_cad_requested();
 };

 file_menu.addSeparator();

 file_menu.add_action("Run Forge Workflow (Forge API)") << [sg]
 {
  sg->emit_run_forge_workflow_requested();
 };

 file_menu.addSeparator();
 file_menu.add_action("Quit") << [sg]
 {
  sg->emit_quit_requested();
 };


 DHAX_Menu& tools = *menus_->menu("Tools");

#ifdef USE_IFC
 tools.add_action("IFC Convert ...") << [sg]
 {
  //QApplication* qapp = qApp;
  sg->emit_ifc_convert_requested();
  //ifc_convert_run_main(qapp);
 };
#endif

 tools.add_action("Take Screenshot") << [sg]
 {
  sg->emit_take_screenshot_requested();
 };

}
