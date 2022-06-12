
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

void DHAX_Application_Receiver::handle_load_notes(call_Stamp_u2 callstamp)
{
 application_controller_->load_notes(/*callstamp*/);
}

void DHAX_Application_Receiver::handle_freecad_reset(call_Stamp_u2 callstamp)
{
 application_controller_->send_freecad_reset(/*callstamp*/);
}


void DHAX_Application_Receiver::handle_meshlab_reset(call_Stamp_u2 callstamp)
{
 application_controller_->send_meshlab_reset(/*callstamp*/);
}


void DHAX_Application_Receiver::handle_convert_notation(call_Stamp_u2 callstamp)
{
 application_controller_->convert_notation_to_curve(/*callstamp*/);
}

#ifdef USE_IFC
void DHAX_Application_Receiver::handle_ifc_convert(call_Stamp_u2 callstamp)
{
 application_controller_->run_ifc_convert(/*callstamp*/);
}
#endif

void DHAX_Application_Receiver::handle_calculate_fb_gaussian(call_Stamp_u2 callstamp)
{
 application_controller_->calculate_fb_gaussian(/*callstamp*/);
}


void DHAX_Application_Receiver::handle_launch_edge_detection_dialog(call_Stamp_u2 callstamp)
{
 application_controller_->launch_edge_detection_dialog(/*callstamp*/);
}

void DHAX_Application_Receiver::handle_save_notation(bool with_comment)
{
 application_controller_->save_current_notation(with_comment);
}


void DHAX_Application_Receiver::handle_edit_image(call_Stamp_u2 callstamp)
{
 application_controller_->handle_edit_image_requested(/*callstamp*/);
}

void DHAX_Application_Receiver::handle_polygon_complete_and_save_notation(call_Stamp_u2 callstamp)
{
 application_controller_->handle_complate_and_save_requested(false);
}

void DHAX_Application_Receiver::handle_polygon_complete_and_save_notation_with_comment(call_Stamp_u2 callstamp)
{
 application_controller_->handle_complate_and_save_requested(true);
}

void DHAX_Application_Receiver::handle_polyline_save_notation(bool with_comment)
{
 application_controller_->handle_polyline_save_requested(with_comment);
}


void DHAX_Application_Receiver::handle_view_contours(call_Stamp_u2 callstamp)
{
 application_controller_->view_contours(/*callstamp*/);
}

void DHAX_Application_Receiver::handle_view_3d(call_Stamp_u2 callstamp)
{
 external_application_controller_->view_3d(/*callstamp*/);
}

void DHAX_Application_Receiver::handle_view_360(call_Stamp_u2 callstamp)
{
 external_application_controller_->view_360(/*callstamp*/);
}

void DHAX_Application_Receiver::handle_view_cad(call_Stamp_u2 callstamp)
{
 external_application_controller_->view_cad(/*callstamp*/);
}

void DHAX_Application_Receiver::handle_run_forge_workflow(call_Stamp_u2 callstamp)
{
 external_application_controller_->run_forge_workflow(/*callstamp*/);
}
