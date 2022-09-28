
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "qmt-client-layer-base.h"

//#include "MapGraphicsView.h"

#include "global-types.h"

#include <QMessageBox>

#include <QGeoServiceProvider>
#include <QGeoCodingManager>
#include <QGeoCoordinate>

#include <QGeoCodeReply>

#include <QDebug>

#include "CircleObject.h"
#include "PolygonObject.h"

#include "MapGraphicsScene.h"


QMT_Client_Layer_Base::QMT_Client_Layer_Base(MapGraphicsScene* scene)
  :  scene_(scene), current_style_(nullptr)
{
}


PolygonObject* QMT_Client_Layer_Base::add_polygon_object(r8 latitude,
  r8 longitude, QPolygonF* polygon, QColor color)
{
 PolygonObject* result = new PolygonObject(*polygon, color);
 return add_object(latitude, longitude, result);
}

CircleObject* QMT_Client_Layer_Base::add_circle_object(r8 latitude,
  r8 longitude, u2 radius, QColor color)
{
 CircleObject* result = new CircleObject(radius, false, color);
 return add_object(latitude, longitude, result);
}

void* QMT_Client_Layer_Base::adopt_style(QString name)
{
 current_style_ = style_names_.value(name, current_style_);
 return current_style_;
}

void* QMT_Client_Layer_Base::define_and_adopt_style(QString name, const std::type_info& model,
 QVector<QColor> colors, QVector<r8> params, u1 complexity)
{
 current_style_ = define_style(name, model, colors, params, complexity);
 return current_style_;
}

void* QMT_Client_Layer_Base::define_and_adopt_style(QString name,
   QVector<QColor> colors, QPolygonF polygon)
{
 current_style_ = define_style(name, colors, polygon);
 return current_style_;
}

void QMT_Client_Layer_Base::add_d0_marks(const QVector<QPair<QList<r8>, QStringList>>& coords_and_texts)
{
 for(auto& pr : coords_and_texts)
   add_d0_mark(pr.first, pr.second);
}
