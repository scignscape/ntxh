
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


void Main_Window_Controller::load_incident_reports()
{
 QString path = QFileDialog::getOpenFileName(view_, "Select Incident Reports File", ROOT_FOLDER);
 if(path.isEmpty())
   return;
 set_info_file("incidents", path);
}



u4 Main_Window_Controller::match_locations_in_text_file(QString file_path,
  r8 query_latitude, r8 query_longitude,
  u4 number_of_results, u1 latitude_column,
  u1 longitude_column, u1 column_separator,
  QVector<QPair<QVector<r8>, QStringList>>& results,
  u1 number_of_header_lines, QVector<u1> other_location_columns)
{
 QFile infile(file_path);
 if(!infile.open(QIODevice::ReadOnly))
  return 0;

 for(u1 i = 0; i < number_of_header_lines; ++i)
 {
  if(!infile.atEnd())
    // // header
    infile.readLine();
 }

 u1 larger_column_plus_one = qMax(latitude_column, longitude_column) + 1;

 QVector<QList<QByteArray>> matches(number_of_results);
 QVector<double> deltas(number_of_results);

 double max_delta = 0;
 u4 max_delta_index = 0;
 u4 matches_active_size = 0;

// //u1 count = 0;
// if(!infile.atEnd())
//  // //  read the header line
//  infile.readLine();
// while(!infile.atEnd())
// {
//  QByteArray qba = infile.readLine();
//  QList<QByteArray> fields = qba.split(',');
//  // //  stop_id,stop_code,stop_name,stop_desc,stop_lat,stop_lon,zone_id
//  r8 lat = fields[4].toDouble();
//  r8 lon = fields[5].toDouble();


 while(!infile.atEnd())
 {
  QByteArray line = infile.readLine().simplified();

  if(line.isEmpty())
    continue;

  // //  this is a hack to strip commas inside quotes, which for
   //    demo purposes could be assumed always to precede spaces

  line.replace(", ", "$");

  QList<QByteArray> qbas = line.split(column_separator);
  if(qbas.size() < larger_column_plus_one)
    continue;

  r8 latitude = qbas[latitude_column].toDouble();
  r8 longitude = qbas[longitude_column].toDouble();

  r8 dlat = latitude - query_latitude;
  r8 dlon = longitude - query_longitude;

  QVector2D v2d(dlat, dlon);
  double len = v2d.length();
  if(matches_active_size < number_of_results)
  {
   // // there's room for any candidate no matter how distant
   matches[matches_active_size] = qbas;
   deltas[matches_active_size] = len;
   if(len > max_delta)
   {
    max_delta_index = matches_active_size;
    max_delta = len;
   }
   ++matches_active_size;
  }
  else if(len < max_delta)
  {
   // //  replace the most distant match
   //    don't bother sorting, we'll just calculate the new largest distance
   matches[max_delta_index] = qbas;
   deltas[max_delta_index] = len;
   auto it = std::max_element(deltas.begin(), deltas.end());
   max_delta_index = std::distance(deltas.begin(), it);
   max_delta = *it;
  }
 }
 infile.close();

 for(u4 excess = matches_active_size; excess < number_of_results; ++excess)
 {
  matches.removeLast();
 }

 u1 number_of_location_columns = 3 + other_location_columns.size();

 QSet<u1> location_column_set(other_location_columns.begin(),
   other_location_columns.end());

 location_column_set.insert(latitude_column);
 location_column_set.insert(longitude_column);

 // //  this is to leave an extra column for item-specific
  //    data that may be added later, like graphics item style ...
 u1 number_of_extra_info_columns = 1;

 u1 index = 0;
 QVector<QPair<QVector<r8>, QStringList>> info(matches.length());
 std::transform(matches.begin(), matches.end(), info.begin(),
   [&deltas, &index, number_of_extra_info_columns, &location_column_set,
    &other_location_columns, number_of_location_columns,
    latitude_column, longitude_column]
   (const QList<QByteArray> qbas) -> decltype (info.value(0))
 {
  u1 number_of_non_location_columns = qbas.size() - number_of_location_columns;

  number_of_non_location_columns += number_of_extra_info_columns;

  QVector<r8> location_fields(number_of_location_columns);
  // //  recalculating the lat/lon but this seems more
   //    efficient than storing then overwriting the lat/lon
   //    for all temporary values.  Plus I suppose it's not
   //    impossible that some variation on the algorithm
   //    might allow a hook where the lat/lon registered
   //    in the result set might differ somehow than
   //    the one involved in calculating distances
   //    (maybe different levels of precision?)
  u1 f = 0;
  location_fields[f] = qbas[latitude_column].toDouble();
  location_fields[++f] = qbas[longitude_column].toDouble();
  location_fields[++f] = deltas[index];
  ++index;
  for(u1 oc : other_location_columns)
    location_fields[++f] = qbas[oc].toDouble();

  // //  this could be more efficient if we know all matches
   //    have the same number of columns, they we would
   //    could form a list of non-location columns ahead of
   //    time.  But I'm not sure that would be a noticeable
   //    optimization and anyways it might be better to
   //    support different-length matches
  QVector<QString> svec(number_of_non_location_columns);
  for(u1 c = 0, sc = number_of_extra_info_columns; sc < number_of_non_location_columns; ++c)
  {
   if(location_column_set.contains(c))
     continue;

   svec[sc] = QString::fromLatin1(qbas[c]);

   // //  again, due to the hack to deal with commas-in-quotes
   svec[sc].replace("$", ", ");
   ++sc;
  }

  return {location_fields, svec.toList()};
 });

 results.resize(info.size());

 // //  an alternative would be to filter out results
  //    that exceed some threshold distance ...
 std::partial_sort_copy(info.begin(), info.end(), results.begin(), results.end(),
   [](QPair<QVector<r8>, QStringList>& lhs, QPair<QVector<r8>, QStringList>& rhs)
 {
  return lhs.second[2] < rhs.second[2];
 });

 return matches_active_size;
}


void Main_Window_Controller::track_incidents()
{
 QString path = "/home/nlevisrael/gits/acle/lat-lon.txt";

 QFile infile(path);
 if(!infile.open(QIODevice::ReadOnly))
  return;

 // EVENT_ID_CNTY		EVENT_DATE			EVENT_TYPE		LATITUDE	LONGITUDE TIMESTAMP

 if(!infile.atEnd())
   // // header
   infile.readLine();

 while(!infile.atEnd())
 {
  QByteArray line = infile.readLine().simplified();
  QList<QByteArray> qbas = line.split(' ');
  if(qbas.length() < 6)
   continue;
  QString event_id = QString::fromLatin1(qbas[0]);
  QString event_date_string = QString::fromLatin1(qbas[1]);
  //QDate event_date = QDate::fromString(QString::fromLatin1(qbas[1]), Qt::DateFormat::);
  QString event_type = QString::fromLatin1(qbas[2]);
  r8 latitude = qbas[3].toDouble();
  r8 longitude = qbas[4].toDouble();

  QDate event_date = QDate::fromString(event_date_string, "dd-MMMM-yy");

 }

}


void Main_Window_Controller::load_bus_data()
{
 QString path = QFileDialog::getOpenFileName(view_, "Select File (it should match \"stops.txt\")", ROOT_FOLDER);
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


