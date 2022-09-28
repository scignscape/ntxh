
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "main-window-controller.h"

#include "MapGraphicsView.h"

#include "dialogs/tile-server-select-dialog.h"

#include "global-types.h"

#include <QMessageBox>

#include <QGeoLocation>
#include <QGeoAddress>

#include <QFileDialog>

#include <QDebug>

Main_Window_Controller::Main_Window_Controller(MapGraphicsView* view)
  :  view_(view), info_files_(_auto_new(info_files_))
{

}


void Main_Window_Controller::load_bus_data()
{
 QString path = QFileDialog::getOpenFileName(view_, "Select File (it should match \"stops.txt\"", ROOT_FOLDER);
 if(path.isEmpty())
   return;
 set_info_file("bus", path);
}

void Main_Window_Controller::reset_map_style(QPoint qp)
{
 Tile_Server_Select_Dialog* tsd = new Tile_Server_Select_Dialog;
 tsd->move(qp);

 QObject::connect(tsd, &Tile_Server_Select_Dialog::update_requested, [this](QDialog* dlg,
   Tile_Server_Select_Dialog::Summary summary)
 {
  qDebug() << "Host: %1\nUrl: %2\nAPI Key: %3"_qt
    .arg(summary.host)
    .arg(summary.url)
    .arg(summary.api_key);

  QSharedPointer<MapTileSource> mts = view_->tileSource();

  mts->set_current_host(summary.host);

  mts->set_current_url(summary.url.replace("@@", summary.api_key));
   // mts->set_current_local_host(summary);

  mts->update_hosts();
  mts->update_host_cache();

  view_->force_reset();

  dlg->close();
 });

 tsd->show();
}

void Main_Window_Controller::show_llcoords(QPoint qp)
{
 QPointF ll = view_->mapToScene(qp);

 QString coords = "Latitude: %1, Longitude: %2"_qt.arg(ll.x()).arg(ll.y());

 QMessageBox::information(nullptr, "Coordinates: ", coords);
}

void Main_Window_Controller::llcoords_to_street_address(QPoint qp)
{
 QPointF ll = view_->mapToScene(qp);

 QMT_GIS_Utils::Result_Callbacks cbs; // {};
 cbs.failure = [](QVariant, QString error_string)
 {
  qDebug() << error_string;
 };

 cbs.success = [ll](QVariant qvar)
 {
  QList<QGeoLocation> reply_locations =
    qvar.value<QList<QGeoLocation>>();

  int length = reply_locations.length();
  if(length == 0)
  {
   QMessageBox::information(nullptr, "Geographic Location Lookup Error",
     "The lookup returned with no results.");
   return;
  }
  QGeoLocation loc1 = reply_locations.first();
  QGeoAddress address = loc1.address();
  QString address_string = "Coordinates: %1, %2\nCity: %3\n"
    "State: %4\nStreet: %5\nPostal Code: %6\n\nFull Text:\n\n%7"_qt
    .arg(ll.y()).arg(ll.x()).arg(address.city()).arg(address.state())
    .arg(address.street()).arg(address.postalCode()).arg(address.text());
  if(length == 1)
  {
   QMessageBox mbox(QMessageBox::Information,
     "Geographic Location Lookup Result",
     "The lookup for latitude %1, longitude %2 returned with one result, "
     "in %3, %4."_qt
       .arg(ll.x()).arg(ll.y()).arg(address.city()).arg(address.country()));
   mbox.setDetailedText(address_string);

   mbox.show();
  }
  else
  {
   QMessageBox mbox(QMessageBox::Information,
     "Geographic Location Lookup Result",
     "The lookup for latitude %1, longitude %2 returned with %5 results. "
     "Here is the first, in %3, %4."_qt
       .arg(ll.x()).arg(ll.y()).arg(address.city()).arg(address.country()).arg(length));
   mbox.setDetailedText(address_string);

   mbox.exec();
  }

 };


 gis_utils_.get_street_address_from_ll(ll, cbs);

}


