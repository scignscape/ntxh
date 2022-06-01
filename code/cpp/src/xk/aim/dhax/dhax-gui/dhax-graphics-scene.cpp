
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dhax-graphics-scene.h"

#include "subwindows/xcsd-tierbox-scene-item.h"


DHAX_Graphics_Scene::DHAX_Graphics_Scene()
  :  QGraphicsScene(), hover_rect_(nullptr)
{
// QRadialGradient gradient(50, 50, 800);
//       gradient.setColorAt(0.9, QColor::fromRgb(0, 150,140));
//       gradient.setColorAt(0.6, QColor::fromRgb(255, 0, 0));
//       gradient.setColorAt(0.2, QColor::fromRgb(0, 0, 0));
//       gradient.setColorAt(0, QColor::fromRgb(0, 200, 0));
}

void DHAX_Graphics_Scene::set_background_color(QColor c)
{
 setBackgroundBrush(QBrush(c));
}

void DHAX_Graphics_Scene::add_tierbox_pixmap(QString path, rc2 rc, u2 x_corner, u2 y_corner)
{
// QPixmap pixmap;
// pixmap.load(path);

 if(!hover_rect_)
 {
  hover_rect_ = new QGraphicsRectItem(0, 0, 27, 27);
  QColor clr(100, 200, 150, 100);
  QBrush qbr(clr);
  hover_rect_->setBrush(qbr);
  QPen qpen;
//  qpen.setStyle(Qt::PenStyle::DashDotDotLine);
  QColor clr1(0, 20, 15, 200);
  qpen.setColor(clr1);
  qpen.setWidthF(1.5);
  hover_rect_->setPen(qpen);
  addItem(hover_rect_);
  hover_rect_->setZValue(1);
 }

 hover_rect_->setVisible(false);

 XCSD_Tierbox_Scene_Item* xtsi = new XCSD_Tierbox_Scene_Item(this, path, rc);

 xtsi->set_scene_hover_rect(hover_rect_);

 //xtsi->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
 xtsi->setPos(x_corner, y_corner);

 addItem(xtsi);
}


void DHAX_Graphics_Scene::handle_tierbox_hover_leave(XCSD_Tierbox_Scene_Item* xtsi)
{
 hover_rect_->setVisible(false);
}


void DHAX_Graphics_Scene::handle_tierbox_hover_enter(XCSD_Tierbox_Scene_Item* xtsi)
{
 rc2 rc = xtsi->row_column_pos();

 u2 x_corner = rc.c * 27;
 u2 y_corner = rc.r * 27;

 hover_rect_->setVisible(true);

 hover_rect_->setPos(x_corner, y_corner);

 qDebug() << "xy corner = " << x_corner << ", " << y_corner;
}

//void DHAX_Graphics_Scene::set_foreground_color(QColor c)
//{
// setForegroundBrush(QBrush(c));
//}
