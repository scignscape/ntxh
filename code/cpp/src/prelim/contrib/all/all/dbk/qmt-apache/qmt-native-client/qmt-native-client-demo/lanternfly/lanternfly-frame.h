
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef LANTERNFLY_FRAME__H
#define LANTERNFLY_FRAME__H


#include <QFrame>
#include <QVBoxLayout>
#include <QLineEdit>

#include "accessors.h"

class MapGraphicsScene;
class MapGraphicsView;

class MapTileSource;

class QMT_Client_Layer;
class QMT_Client_Context_Menu_Handler;
class QMT_Client_Location_Focus;


class Lanternfly_Frame : public QFrame
{
 QVBoxLayout* main_layout_;

 MapGraphicsScene* scene_;
 MapGraphicsView* view_;

 QLineEdit* coords_line_edit_;

 QMT_Client_Layer* client_layer_;
 QMT_Client_Context_Menu_Handler* client_context_menu_handler_;
 QMT_Client_Location_Focus* qmt_client_location_focus_;

public:

 Lanternfly_Frame();

 ACCESSORS(MapGraphicsView* ,view)

 void set_tile_source(QSharedPointer<MapTileSource> src);

 void set_view_zoom_level(quint8 level);

 void center_on(qreal longitude, qreal latitude);

 void adopt_location(QString name);

 MapGraphicsScene* scene()
 {
  return scene_;
 }

};


#endif // LANTERNFLY_FRAME__H

