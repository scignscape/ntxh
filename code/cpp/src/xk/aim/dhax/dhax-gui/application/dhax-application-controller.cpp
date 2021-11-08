
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

#include "image-viewer/dhax-image-scene-item.h"
#include "application/dhax-application-receiver.h"

#include "textio.h"

USING_KANS(TextIO)

#include "dgi-opencv/dgi-image.h"
#include "dgi-opencv/dgi-demo-frame.h"

USING_KANS(DGI)

#include <QMenuBar>

#include <QImageReader>
#include <QImageWriter>


#include <QGuiApplication>
#include <QTimer>
#include <QDebug>
#include <QFile>
#include <QScreen>

#include <QFileDialog>


DHAX_Application_Controller::DHAX_Application_Controller()
  :  application_main_window_(nullptr),
     main_window_controller_(nullptr),
     application_receiver_(nullptr),
    // display_image_data_(nullptr),
//     zoom_frame_(nullptr),
//     image_scene_item_(nullptr),
//     main_window_receiver_(nullptr),
     udp_controller_(nullptr)
{

}


void DHAX_Application_Controller::init_image_scene_item(DHAX_Image_Scene_Item* si)
{
 si->self_connect(SIGNAL(save_notation_requested(bool)),
   application_receiver_, SLOT(handle_save_notation(bool)));

 si->self_connect(SIGNAL(convert_notation_requested()),
   application_receiver_, SLOT(handle_convert_notation()));

 si->self_connect(SIGNAL(save_notation_requested(bool)),
   application_receiver_, SLOT(handle_save_notation(bool)));

// si->self_connect(SIGNAL(convert_notation_requested()),
//   application_receiver_, SLOT(handle_convert_notation()));

// si->self_connect(&DHAX_Image_Scene_Item::convert_notation,
//   application_receiver_, SLOT(handle_convert_notation()));


 si->self_connect(SIGNAL(polygon_save_notation_requested()),
   application_receiver_, SLOT(handle_polygon_save_notation()));

//?
// si->self_connect(&DHAX_Image_Scene_Item::polygon_save_notation,
//   application_receiver_, &DHAX_Application_Receiver::handle_polygon_save_notation);



 si->self_connect(SIGNAL(polygon_complete_and_save_notation_requested()),
   application_receiver_, SLOT(handle_polygon_complete_and_save_notation()));


 si->self_connect(SIGNAL(meshlab_reset_requested()),
   application_receiver_,
   SLOT(handle_meshlab_reset()));


 si->self_connect(SIGNAL(freecad_reset_requested()),
   application_receiver_,
   SLOT(handle_freecad_reset()));


 //init_image_scene_item
}


void DHAX_Application_Controller::r8_vector_to_qba(const QVector<r8>& data, QByteArray& qba)
{
 if(data.isEmpty())
   return;
 qba = QByteArray::number(data[0]);

 for(u2 i = 1; i < data.size(); ++i)
 {
  qba += ";" + QByteArray::number(data[i]);
 }
}



void DHAX_Application_Controller::send_freecad_reset()
{

}

void DHAX_Application_Controller::send_meshlab_reset()
{
 QVector<r8> data(8);

 DHAX_Meshlab_Integration_Data& mid = *application_main_window_->main_window_data()->meshlab_integration();


 data[0] = mid.meshlab_track_info().scalar();
 data[1] = mid.meshlab_track_info().x();
 data[2] = mid.meshlab_track_info().y();
 data[3] = mid.meshlab_track_info().z();

 data[4] = mid.meshlab_scale_info();
 data[5] = mid.meshlab_center_position().x();
 data[6] = mid.meshlab_center_position().y();
 data[7] = mid.meshlab_center_position().z();

 QByteArray qba;
 r8_vector_to_qba(data, qba);

 qba.prepend(mid.meshlab_file_path().toLatin1() + "*");
 qba.prepend(mid.mesh_file_path().toLatin1() + "*");

 udp_controller_->wrap_and_send_datagram(qba);
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



void DHAX_Application_Controller::view_contours()
{
 QString image_filename_path = main_window_controller_->current_image_file_path();
 if(image_filename_path.isEmpty())
   return;

 QFileInfo qfi(image_filename_path);

 copy_binary_file_to_folder_with_rename(image_filename_path,
   DEFAULT_DHAX_TEMP_FOLDER, "iat-temp-image" );

 QString ini = DEFAULT_DHAX_TEMP_FOLDER "/iat-temp-image." + qfi.suffix();
 QString thei;
 thei = DEFAULT_DHAX_TEMP_FOLDER "/iat-temp-image-conv." + qfi.suffix();
 QImageReader reader;
 reader.setFileName(ini);

 QImage image = reader.read();
 QImage converted = image.convertToFormat(QImage::Format_RGB888);
 QImageWriter writer;
 writer.setFileName(thei);
 writer.write(converted);

 DGI_Image* dgi = new DGI_Image(thei);

 dgi->load();

 Demo_Transform_Group* dtg = new Demo_Transform_Group(dgi);
 dgi->init_demo_transform_group(*dtg);

 dgi->to_csv(DEFAULT_DGI_TEMP_FOLDER "/iat-temp-image.csv");

 QDialog* dlg = new QDialog(application_main_window_);

 dlg->setWindowTitle("Contour View");

 DGI_Demo_Frame* fr = new DGI_Demo_Frame(*dtg, 200, 800, 300);

 fr->setContextMenuPolicy(Qt::CustomContextMenu);

 fr->connect(fr, &QFrame::customContextMenuRequested,
   [this, fr, dgi](QPoint pos)
 {
  QMenu* menu = new QMenu(fr);
  menu->addAction("View Contour Info", [this, dgi]
  {
   handle_view_contour_info(dgi->saved_csv_path());
  });

  menu->popup(fr->mapToGlobal(pos));
 });

 QVBoxLayout* vbl = new QVBoxLayout;
 vbl->addWidget(fr);

 dlg->setLayout(vbl);
 dlg->show();
}

void DHAX_Application_Controller::handle_view_contour_info(QString path)
{

}
