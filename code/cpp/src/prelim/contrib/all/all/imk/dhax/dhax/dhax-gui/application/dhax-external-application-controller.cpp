
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include "dhax-external-application-controller.h"

#include "main-window/dhax-main-window.h"

#include "rpdf/webgl-view-dialog.h"

#include "dhax-application-controller.h"

#include "dhax-forge-controller.h"

#include "textio.h"

USING_KANS(TextIO)

#include <QMenuBar>

#include <QGuiApplication>
#include <QTimer>
#include <QDebug>
#include <QFile>
#include <QScreen>

#include <QFileDialog>

#include <QProcess>


DHAX_External_Application_Controller::DHAX_External_Application_Controller()
  :  application_main_window_(nullptr),
     application_controller_(nullptr), current_wgl_dialog_(nullptr)
{
 save_area_folder_ = ROOT_FOLDER "/../save-area";
}




void DHAX_External_Application_Controller::view_3d()
{
 QString path = qApp->applicationDirPath();
 QDir qd(path);

 QString ap = qd.absoluteFilePath("meshlab-console");

 QProcess cmd;
 cmd.startDetached(ap, {});

}


void DHAX_External_Application_Controller::prepare_video_recorder()
{
 qDebug() << "prepare_video_recorder";

// QString cmd = "";

 QDir qd(SSR_BIN_FOLDER);

 QString ap = qd.absoluteFilePath("simplescreenrecorder");
 qDebug() << "ap = " << ap;

 QProcess cmd;
 cmd.startDetached(ap, {});

 QTimer::singleShot(2000, [this]()
 {
  test_ssr_datagram();
 });
}

void DHAX_External_Application_Controller::test_ssr_datagram()
{
 qDebug() << "test ssr";

 QRect rect;

 if(current_wgl_dialog_)
 {
  rect = current_wgl_dialog_->get_web_view_geometry();
  qDebug() << "rect = " << rect;
  application_controller_->send_ssr_reset(rect);
 }
 else
   application_controller_->send_ssr_reset("--------------");

}

void DHAX_External_Application_Controller::view_360()
{
 if(current_wgl_dialog_)
 {
  current_wgl_dialog_->setWindowState(current_wgl_dialog_->windowState()
    & ~Qt::WindowMinimized | Qt::WindowActive);
  current_wgl_dialog_->reset_tab_selection();
  return;
 }

 current_wgl_dialog_ = new WebGL_View_Dialog(nullptr);

 current_wgl_dialog_->setWindowTitle("360 Mode");

 application_main_window_->connect(current_wgl_dialog_, &WebGL_View_Dialog::snapshot_saved,
   [this](QString file_path)
 {
  qDebug() << "loading " << file_path;
  current_wgl_dialog_->setWindowState(current_wgl_dialog_->windowState()
    | Qt::WindowMinimized);


  QString copy_path = copy_binary_file_to_folder(file_path, save_area_folder_);

  if(copy_path.isEmpty())
    application_controller_->load_image(file_path);
  else
    application_controller_->load_image(copy_path);
 });

 current_wgl_dialog_->show();

}

void DHAX_External_Application_Controller::view_cad()
{
 QDir qd(FREECAD_BIN_FOLDER);

 QString ap = qd.absoluteFilePath("FreeCAD");
 qDebug() << "ap = " << ap;

 QProcess cmd;
 cmd.startDetached(ap, {});
}


void DHAX_External_Application_Controller::run_forge_workflow()
{
 DHAX_Forge_Controller* dfc = application_controller_->check_init_forge_controller();
 dfc->run_workflow();
}
