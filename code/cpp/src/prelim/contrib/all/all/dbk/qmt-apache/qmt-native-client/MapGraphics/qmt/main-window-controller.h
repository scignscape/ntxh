
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

// QString request_path_;
// QString actual_path_;

// u4 size_;

public:

 Main_Window_Controller(MapGraphicsView* view);

 void reset_map_style(QPoint qp);

 void show_llcoords(QPoint qp);
 void llcoords_to_street_address(QPoint qp);

// ACCESSORS(QString ,request_path)
// ACCESSORS(QString ,actual_path)
// ACCESSORS(u4 ,size)

};



#endif // MAIN_WINDOW_CONTROLLER__H
