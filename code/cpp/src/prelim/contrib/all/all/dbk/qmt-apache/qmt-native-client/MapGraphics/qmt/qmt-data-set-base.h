
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)



#ifndef QMT_DATA_SET_BASE__H
#define QMT_DATA_SET_BASE__H

//#include "qmt-accessors.h"

#include "global-types.h"

#include <QString>
#include <QList>

#include <QPoint>

#include <QMap>

#include <functional>

#include <QVariant>

#include <QPolygonF>

#include "accessors.h"

#include "typeindex"

#include "MapGraphicsScene.h"

#include <typeinfo>

class MapGraphicsScene;
class MapGraphicsView;

class CircleObject;
class PolygonObject;
class QPolygonF;

class QMT_Data_Set_Base
{
public:

 union _r8_or_ptr { r8 _r8; void* _ptr; };

 struct Match_Info
 {
  QVector<_r8_or_ptr> location_fields;
  QStringList text_fields;
 };

protected:
 QString single_file_path_;
 QString folder_path_;

 QVector<Match_Info> current_matches_;



public:


 QMT_Data_Set_Base();


 ACCESSORS(QString ,single_file_path)
 ACCESSORS(QString ,folder_path)

 ACCESSORS__RGET(QVector<Match_Info> ,current_matches)

 u4 match_locations_in_text_file(QString file_path, r8 query_latitude, r8 query_longitude,
   u4 number_of_results, u1 latitude_column,
   u1 longitude_column, u1 column_separator,
   s4 allow_duplicates = 0,
   u1 number_of_header_lines = 1, QVector<u1> other_location_columns = {});


};

// QMT_Client_Context_Menu_Handler

#endif //QMT_CLIENT_LAYER_BASE__H
