
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "main-window-controller.h"

#include "MapGraphicsView.h"

#include "global-types.h"

#include <QMessageBox>


Main_Window_Controller::Main_Window_Controller(MapGraphicsView* view)
  :  view_(view)
{

}

void Main_Window_Controller::reset_map_style(QPoint qp)
{

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

 gis_utils_;

}


