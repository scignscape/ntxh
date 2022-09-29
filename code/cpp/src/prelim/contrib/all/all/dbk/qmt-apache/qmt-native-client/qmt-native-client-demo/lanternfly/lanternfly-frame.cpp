
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "lanternfly-frame.h"


#include "MapGraphicsView.h"
#include "MapGraphicsScene.h"

#include "qmt-client-layer.h"
#include "qmt-client-context-menu-handler.h"
#include "qmt-client-location-focus.h"

Lanternfly_Frame::Lanternfly_Frame() : QFrame(nullptr)
{
 main_layout_ = new QVBoxLayout;

 scene_ = new MapGraphicsScene;
 view_ = new MapGraphicsView;

 client_layer_ = new QMT_Client_Layer(scene_, view_);
 view_->set_qmt_client_layer_base(client_layer_);

 client_context_menu_handler_ = new QMT_Client_Context_Menu_Handler(view_);
 view_->set_qmt_client_context_menu_handler_base(client_context_menu_handler_);

 qmt_client_location_focus_ = new QMT_Client_Location_Focus(this);
 view_->set_qmt_client_location_focus_base(qmt_client_location_focus_);


 view_->set_coords_notify_callback([this](const QPointF qpf)
 {
  coords_line_edit_->setText(QString("%1,%2").arg(qpf.y()).arg(qpf.x()));
 });

 view_->setScene(scene_);

 main_layout_->addWidget(view_);

 coords_line_edit_ = new QLineEdit("0,0");

 main_layout_->addWidget(coords_line_edit_);

 setLayout(main_layout_);
}

void Lanternfly_Frame::adopt_location(QString name)
{
 QString ok = qmt_client_location_focus_->adopt_location(name);
 if(!ok.isEmpty())
 {
  if(view_->coords_notify_callback())
  {
   view_->coords_notify_callback()({
     qmt_client_location_focus_->current_central_longitude(),
     qmt_client_location_focus_->current_central_latitude()});
  }
 }
}


void Lanternfly_Frame::set_view_zoom_level(quint8 level)
{
 view_->setZoomLevel(level);
}


void Lanternfly_Frame::center_on(qreal longitude, qreal latitude)
{
 view_->centerOn(longitude, latitude);
}


void Lanternfly_Frame::set_tile_source(QSharedPointer<MapTileSource> src)
{
 view_->setTileSource(src);
}
