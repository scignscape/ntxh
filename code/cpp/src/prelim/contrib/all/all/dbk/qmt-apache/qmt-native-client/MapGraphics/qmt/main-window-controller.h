
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#ifndef MAIN_WINDOW_CONTROLLER__H
#define MAIN_WINDOW_CONTROLLER__H

//#include "qmt-accessors.h"
//#include "qmt-global-types.h"

#include "qmt-gis-utils.h"

#include <QString>
#include <QList>

#include <QPoint>

//class QMT_Server_Response;

class MapGraphicsView;

class Main_Window_Controller
{
 QStringList map_styles_by_name_;

 MapGraphicsView* view_;

 QMT_GIS_Utils gis_utils_;

 // //  TODO: as in DHAX this could be part of a separate "app data" class
  //    for now leave it here but I'll make it a pointer so it can move easily
 QMap<QString, QString>* info_files_;

// QString request_path_;
// QString actual_path_;

// u4 size_;

public:

 Main_Window_Controller(MapGraphicsView* view);

 void reset_map_style(QPoint qp);

 void show_llcoords(QPoint qp);
 void llcoords_to_street_address(QPoint qp);

 void load_bus_data();

 void load_incident_reports();

 void set_info_file(QString key, QString value)
 {
  (*info_files_)[key] = value;
 }

 QString get_info_file(QString key)
 {
  return info_files_->value(key);
 }

// ACCESSORS(QString ,request_path)
// ACCESSORS(QString ,actual_path)
// ACCESSORS(u4 ,size)

};



#endif // MAIN_WINDOW_CONTROLLER__H
