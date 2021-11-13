
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include "dhax-application-receiver.h"

//#include "dhax-main-window.h"
//#include "dhax-main-window-controller.h"

#include "dhax-application-controller.h"
#include "dhax-external-application-controller.h"

#include <QMenuBar>

#include <QGuiApplication>
#include <QTimer>
#include <QDebug>
#include <QFile>
#include <QScreen>


DHAX_Application_Receiver::DHAX_Application_Receiver()
  :  application_main_window_(nullptr),
     application_controller_(nullptr)
{

}

void DHAX_Application_Receiver::handle_load_notes()
{
 application_controller_->load_notes();
}

void DHAX_Application_Receiver::handle_freecad_reset()
{
 application_controller_->send_freecad_reset();
}


void DHAX_Application_Receiver::handle_meshlab_reset()
{
 application_controller_->send_meshlab_reset();
}


void DHAX_Application_Receiver::handle_convert_notation()
{
 application_controller_->convert_notation_to_curve();
}

#ifdef USE_IFC
void DHAX_Application_Receiver::handle_ifc_convert()
{
 application_controller_->run_ifc_convert();
}
#endif


void DHAX_Application_Receiver::handle_save_notation(bool with_comment)
{
 application_controller_->save_current_notation(with_comment);
}


void DHAX_Application_Receiver::handle_polygon_complete_and_save_notation()
{
 application_controller_->handle_complate_and_save_requested(false);
}

void DHAX_Application_Receiver::handle_polygon_complete_and_save_notation_with_comment()
{
 application_controller_->handle_complate_and_save_requested(true);
}

void DHAX_Application_Receiver::handle_polygon_save_notation()
{
 //?application_controller_->save_current_notation(false);
}

void DHAX_Application_Receiver::handle_view_contours()
{
 application_controller_->view_contours();
}

void DHAX_Application_Receiver::handle_view_3d()
{
 external_application_controller_->view_3d();
}

void DHAX_Application_Receiver::handle_view_360()
{
 external_application_controller_->view_360();
}

void DHAX_Application_Receiver::handle_view_cad()
{
 external_application_controller_->view_cad();
}

void DHAX_Application_Receiver::handle_run_forge_workflow()
{
 external_application_controller_->run_forge_workflow();
}
