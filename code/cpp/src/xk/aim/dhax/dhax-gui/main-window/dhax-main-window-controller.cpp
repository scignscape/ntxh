
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include "dhax-main-window-controller.h"

#include "dhax-main-window.h"

#include <QMenuBar>

#include <QGuiApplication>
#include <QTimer>
#include <QDebug>
#include <QFile>
#include <QScreen>


DHAX_Main_Window_Controller::DHAX_Main_Window_Controller()
{

}


void DHAX_Main_Window_Controller::handle_take_screenshot_requested()
{
 QScreen* screen = QGuiApplication::primaryScreen();
 if (!screen)
   return;

 QTimer::singleShot(10000, [=]
 {
  QPixmap pixmap = screen->grabWindow(application_main_window_->winId());
  QString path = SCREENSHOTS_FOLDER "/dhax.png";
  qDebug() << "Saving to path: " << path;

  QFile file(path);
  if(file.open(QIODevice::WriteOnly))
  {
   pixmap.save(&file, "PNG");
  }
 });

}

