
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "qmt-client-context-menu-handler.h"

#include "qmt-client-layer.h"

//#include "MapGraphicsView.h"

#include "global-types.h"

#include <QMessageBox>

#include <QGeoServiceProvider>
#include <QGeoCodingManager>
#include <QGeoCoordinate>

#include <QGeoCodeReply>

#include <QDebug>

#include "MapGraphicsView.h"

#include "CircleObject.h"

#include <QMenu>


QMT_Client_Context_Menu_Handler::QMT_Client_Context_Menu_Handler(MapGraphicsView* view)
  :  QMT_Client_Context_Menu_Handler_Base(view)
{
}


void QMT_Client_Context_Menu_Handler::handle_context_menu_on_mgo
  (QGraphicsSceneContextMenuEvent* event, MapGraphicsObject* mgo)
{
 if(!mgo)
   // // in case it's deleted for some reason before the menu item is selected
   return;

 QStringList qsl = mgo->client_data().value<QVector<QVariant>>()
   .first().value<QStringList>();

 QString context_menu_handler = qsl.first();
 if(context_menu_handler.isEmpty())
   context_menu_handler = QMT_Client_Layer::get_context_menu_handler_name(mgo);
 if(context_menu_handler.isEmpty())
 {
  qDebug() << "Unknown context menu handler slot requested (no name provided).";
  qDebug() << " The style name was " << QMT_Client_Layer::get_style_params_name(mgo);
  return;
 }
 bool ok = QMetaObject::invokeMethod(this, context_menu_handler.toLatin1(),
   Qt::DirectConnection,
   Q_ARG(QGraphicsSceneContextMenuEvent* ,event),
   Q_ARG(MapGraphicsObject* ,mgo));
 if(!ok)
   qDebug() << "Unknown context menu handler slot requested: " << context_menu_handler;
}

void QMT_Client_Context_Menu_Handler::handle_bus_stop_context_menu(QGraphicsSceneContextMenuEvent* event,
  MapGraphicsObject* mgo)
{
 QPoint pos3 = mgo->map_pos_to_view() + event->pos().toPoint();
 qDebug() << "pos3 = " << pos3;

 QMenu* menu = new QMenu;
 menu->addAction("Get Stop Info", [mgo]
 {
  QStringList qsl = mgo->client_data().value<QVector<QVariant>>()
    .first().value<QStringList>();
  qDebug() << "ON: " << qsl;

  QString msg = "Code %1\n\n%2\n\nLatitude: %3\nLongitude: %4"_qt
    .arg(qsl.value(2)).arg(qsl.value(3).replace('"', ""))
    .arg(mgo->latitude()).arg(mgo->longitude());

  QMessageBox* mbox = new QMessageBox(QMessageBox::Information,
    "Bus Stop Info",
    "For Stop #%1"_qt
      .arg(qsl.value(1))); // ll.x()).arg(ll.y()).arg(address.city()).arg(address.country()));
  mbox->setDetailedText(msg);

  mbox->show();

 });

 menu->popup(view_->mapToGlobal(pos3));

// pos += event->pos();

// qDebug() << "epos = " << pos;


}

