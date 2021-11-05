
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include "dhax-application-controller.h"

//#include "dhax-main-window.h"

//#include "image-viewer/dhax-display-image-data.h"
//#include "subwindows/zoom-and-navigate-frame.h"

//#include "image-viewer/dhax-image-viewer.h"

//#include "image-viewer/dhax-image-scene-item.h"

//#include "main-window/dhax-main-window-receiver.h"
//#include "main-window/dhax-main-window-data.h"

#include "network/dhax-udp-controller.h"

#include "integration/meshlab/dhax-meshlab-integration-data.h"
#include "integration/freecad/dhax-freecad-integration-data.h"

#include "integration/meshlab/dhax-meshlab-integration-controller.h"
//#include "integration/freecad/dhax-freecad-integration-controller.h"

#include "integration/dhax-integration-controller.h"

#include "main-window/dhax-main-window.h"
#include "main-window/dhax-main-window-controller.h"
#include "main-window/dhax-main-window-data.h"

#include <QMenuBar>

#include <QGuiApplication>
#include <QTimer>
#include <QDebug>
#include <QFile>
#include <QScreen>

#include <QFileDialog>


DHAX_Application_Controller::DHAX_Application_Controller()
  :  application_main_window_(nullptr),
     main_window_controller_(nullptr),


    // display_image_data_(nullptr),
//     zoom_frame_(nullptr),
//     image_scene_item_(nullptr),
//     main_window_receiver_(nullptr),
     udp_controller_(nullptr)
{

}


void DHAX_Application_Controller::load_image(QString file_path)
{
 main_window_controller_->load_image(file_path);
}

void DHAX_Application_Controller::init_integration_controllers()
{
 DHAX_Meshlab_Integration_Data* md = new DHAX_Meshlab_Integration_Data;
 application_main_window_->main_window_data()->set_meshlab_integration(md);
 md->init_import_count();

 DHAX_Meshlab_Integration_Controller* meshlab = new DHAX_Meshlab_Integration_Controller;
 integration_controllers_["meshlab"] = meshlab;
 meshlab->set_application_controller(this);
 meshlab->set_integration_data(md);
 //meshlab->set_integration_data()
}


void DHAX_Application_Controller::init_udp_controller()
{
 //udp_controller_->
}


void DHAX_Application_Controller::dispatch_datagram(QByteArray qba)
{
 QByteArray num = qba.left(3);
 int size = num.toInt();
 QByteArray qbam = qba.mid(3, size);
 QString text = QString::fromLatin1(qbam);

 QString origin;

 if(text.startsWith('+'))
 {
  int ix = text.indexOf('+', 1);
  if(ix != -1)
  {
   origin = text.mid(1, ix - 1);
   text = text.mid(ix + 1);
  }
 }

 if(!origin.isEmpty())
 {
  if(DHAX_Integration_Controller* ic = integration_controllers_.value(origin.toLower()))
  {
   ic->read_datagram(text);
  }
 }

// if(true) // // perhaps some origin won't require an outgoing ...
//   check_init_udp_outgoing_socket();

// if(origin.isEmpty() || origin == "MeshLab")
// {
////  read_udp_meshlab(text);
// }
// else if(origin == "FreeCAD")
// {
////  read_udp_freecad(text);
// }

}

