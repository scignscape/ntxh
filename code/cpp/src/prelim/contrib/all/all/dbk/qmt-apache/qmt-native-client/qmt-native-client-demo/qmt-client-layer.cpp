
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "qmt-client-layer.h"

//#include "MapGraphicsView.h"

#include "global-types.h"

#include <QMessageBox>

#include <QGeoServiceProvider>
#include <QGeoCodingManager>
#include <QGeoCoordinate>

#include <QGeoCodeReply>

#include <QDebug>

#include "CircleObject.h"


QMT_Client_Layer::QMT_Client_Layer(MapGraphicsScene* scene,  MapGraphicsView* view)
 : QMT_Client_Layer_Base(scene, view)
{
}

void* QMT_Client_Layer::define_style(QString name, QString context_menu_handler,
  QVector<QColor> colors, QPolygonF polygon)
{
 Style_Params* sp = new Style_Params;
 sp->brush_color = colors.value(0);
 sp->pen_color = colors.value(1);
 sp->model = Known_Style_Models::QGraphicsPolygon;
 sp->polygon = new QPolygonF(polygon);
 sp->context_menu_handler = context_menu_handler;
 sp->name = name;
 style_names_[name] = sp;
 return sp;
}

void* QMT_Client_Layer::define_style(QString name, QString context_menu_handler, const std::type_info& model,
   QVector<QColor> colors, QVector<r8> params, u1 complexity)
{
 Known_Style_Models ksm = parse_style_model(model);
 u1 color_complexity = complexity >> 4,
   shape_complexity = complexity &0x0F;

 Style_Params* sp = new Style_Params;

 switch (ksm)
 {
 case Known_Style_Models::QGraphicsEllipse:
  sp->brush_color = colors.value(0);
  sp->pen_color = colors.value(1);
  sp->x_radius = params.value(0);
  sp->y_radius = params.value(1, sp->x_radius);
  sp->pen_width = params.value(2);
  if( (shape_complexity == 0) && (sp->x_radius == sp->y_radius) )
    sp->model = Known_Style_Models::QGraphicsEllipse_Circle;
  else if (shape_complexity > 2)
    sp->model = Known_Style_Models::QGraphicsEllipse_Circle;
  break;
 default: break;
 }

 if(sp->model == Known_Style_Models::N_A)
   sp->model = ksm;

 sp->context_menu_handler = context_menu_handler;
 style_names_[name] = sp;
 return sp;
}

void QMT_Client_Layer::add_d0_mark(r8 latitude, r8 longitude, QStringList text)
{
 add_d0_mark({latitude, longitude}, text);
}



QString QMT_Client_Layer::get_style_params_name(MapGraphicsObject* mgo)
{
 if(Style_Params* sp = (Style_Params*) mgo->style_params())
 {
  return sp->name;
 }
 return {};
}


QString QMT_Client_Layer::get_context_menu_handler_name(MapGraphicsObject* mgo)
{
 if(Style_Params* sp = (Style_Params*) mgo->style_params())
 {
  return sp->context_menu_handler;
 }
 return {};
}

void QMT_Client_Layer::add_d0_mark(QVector<r8> coords, QStringList text)
{
 Style_Params* sp = (Style_Params*) current_style_;

 CircleObject* co = nullptr;
// PolygonObject* po;

 static r4 default_select_margin = 110;

 switch (sp->model)
 {
 case Known_Style_Models::QGraphicsEllipse_Circle:
   co = add_circle_object(coords[0], coords[1], sp->x_radius, sp->brush_color);
   break;

 case Known_Style_Models::QGraphicsPolygon:
   co = add_polygon_object(coords[0], coords[1], sp->polygon, sp->brush_color,
     std::isnan(sp->select_margin)? default_select_margin : sp->select_margin);
   co->clearFlag(MapGraphicsObject::ObjectIsMovable);
   break;
 }

 if(co)
 {
  co->set_style_params(sp);
//  QPair<r8, QStringList> pr {coords.value(2), text};
//  co->set_client_data(QVariant::fromValue<QPair<r8, QStringList>>(pr));

  QVector<QVariant> vv {QVariant(text), QVariant(coords.value(2))};
  co->set_client_data(QVariant::fromValue<QVector<QVariant>>(vv));

 }

}


