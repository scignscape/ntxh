
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "xcsd-local-histogram-dialog.h"

#include "xcsd-2d/xcsd-image.h"

#include <QGraphicsRectItem>

XCSD_Local_Histogram_Dialog::Rect_Item::Rect_Item(const QRect& rect, u2 h, QColor color)
  :  QGraphicsRectItem(rect), hue(h), color_code(0)
{
 QBrush qbr(color);
 setBrush(qbr);
 setAcceptHoverEvents(true);
}

void XCSD_Local_Histogram_Dialog::Rect_Item::hoverEnterEvent(QGraphicsSceneHoverEvent* event)
{
 QColor color(brush().color());
 int hh = color.hue();
 u1 s = color.hsvSaturation();
 u1 v = color.value();
 qDebug() << "hh = " << hh;
 //color.setHsv(360 - hh, s, v);
 color.setHsv(360 - hh, 200, 200);

 qDebug() << "hh1 = " << color.hsvHue();

 QPen pen;
 pen.setColor(color);
 pen.setWidth(9);
 setPen(pen);
 update();
}

void XCSD_Local_Histogram_Dialog::Rect_Item::hoverLeaveEvent(QGraphicsSceneHoverEvent* event)
{
 QPen pen;
 pen.setColor(Qt::black);
 pen.setWidth(1);
 setPen(pen);
 update();
}


XCSD_Local_Histogram_Dialog::XCSD_Local_Histogram_Dialog(QWidget* parent,
  pr2 totals, QMap<s2, Histogram_Group_Summary>* data)
  :  QDialog(parent)
{
 image_height_ = 520;
 max_bin_height_  = 200;
 min_bin_height_  = 10;
 bin_base_  = 260;
 bin_width_  = 9;

 max_group_height_  = 200;
 min_group_height_  = 10;


 auto [largest_group_total, largest_bin] = totals;

 graphics_scene_ = new QGraphicsScene(this);
 graphics_view_ = new QGraphicsView(this);

 graphics_view_->setScene(graphics_scene_);

 u2 h = 0;
 for(s2 hue = 0, go_on = 1; go_on; ++hue)
 {
  if(hue == 360)
  {
   hue = -1;
   go_on = 0;
  }
  auto it = data->find(hue);
  if(it == data->end())
    continue;

  {
   Histogram_Group_Summary& hgs = it.value();
   u2 most = hgs.max;
   QColor color = XCSD_Image::rgb555_to_qcolor(most);
   u2 height = (((r8) hgs.total) / largest_group_total) * (max_group_height_ - min_group_height_);

   QRect rect(h, bin_base_,
     ((bin_width_ + 1) * it.value().counts.size()) - 1, min_group_height_ + height);
//    qDebug() << "rect = " << rect;


   Rect_Item* ri = new Rect_Item(rect, hue, color);
   graphics_scene_->addItem(ri);
//   ri->setBrush(qbr);
//   ri->setFlags(QGraphicsItem::ItemIsSelectable);

//  painter.setBrush(qbr);
//  painter.drawRect(rect);
  }

  for(pr2 pr : it.value().counts)
  {
   u2 v = pr.second;

   QColor color = XCSD_Image::rgb555_to_qcolor(pr.first);

//    qDebug() << "color = " << color;


   u2 height = (((r8) pr.second) / largest_bin) * (max_bin_height_ - min_bin_height_);

//    qDebug() << "v = " << v << ", height = " << height;

   QRect rect(h, bin_base_, bin_width_, -(min_bin_height_ + height));
//    qDebug() << "rect = " << rect;


   QBrush qbr(color);

   Rect_Item* ri = new Rect_Item(rect, hue, color);

   graphics_scene_->addItem(ri); //Rect(rect)->setBrush(qbr);

   QFont font;
   font.setPointSize(7);
   if(hue < 10)
     graphics_scene_->addText(QString::number(hue), font)->setPos(rect.bottomLeft() - QPoint{-2, 2});
     //painter.drawText(rect.bottomLeft() - QPoint{-2, 2}, QString::number(hue));
   else if(hue < 100)
   {
    graphics_scene_->addText(QString::number(hue % 10), font)->setPos(rect.bottomLeft() - QPoint{-2, 2});
    graphics_scene_->addText(QString::number((hue / 10) % 10),
      font)->setPos(rect.bottomLeft() - QPoint{-2, 10});

//    painter.drawText(rect.bottomLeft() - QPoint{-2, 2}, QString::number(hue % 10));
//    painter.drawText(rect.bottomLeft() - QPoint{-2, 10},
//      QString::number( (hue / 10) %  10) );
   }
   else
   {
    graphics_scene_->addText(QString::number(hue % 10), font)->setPos(rect.bottomLeft() - QPoint{-1, 12});
    graphics_scene_->addText(QString::number((hue / 10) % 10),
      font)->setPos(rect.bottomLeft() - QPoint{-1, 20});
    graphics_scene_->addText(QString::number((hue / 100) % 10),
      font)->setPos(rect.bottomLeft() - QPoint{-1, 28});
   }
   h += 10;
  }
 }

 main_layout_ = new QVBoxLayout;

 main_layout_->addWidget(graphics_view_);
 setLayout(main_layout_);

}


