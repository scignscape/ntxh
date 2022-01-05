
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dhax-image-viewer.h"

#include "dhax-image-scene-item.h"
#include "dhax-display-image-data.h"

#include "dhax-graphics-scene.h"
#include "dhax-graphics-view.h"


#include <QGraphicsProxyWidget>
#include <QDebug>


DHAX_Image_Viewer::DHAX_Image_Viewer(QWidget* parent)
  :  QWidget(parent), scrolled_image_view_(nullptr),
     scrolled_image_scene_(nullptr),
     scrolled_image_pixmap_item_(nullptr),
     background_rectangle_(nullptr),
     background_rectangle_center_x_(0),
     background_rectangle_center_y_(0),
     main_layout_(0),
     image_scene_item_(nullptr),
     display_image_data_(new DHAX_Display_Image_Data),
     main_window_(nullptr)
{
}


void DHAX_Image_Viewer::reset_scale(r8 factor)
{
 scrolled_image_pixmap_item_->setScale(factor);
 recenter_image();
}


void DHAX_Image_Viewer::mouseMoveEvent(QMouseEvent *mouseEvent)
{
 qDebug() << " ... ";
}


void DHAX_Image_Viewer::recenter_image()
{
 int w = scrolled_image_pixmap_item_->boundingRect().width() *
   scrolled_image_pixmap_item_->scale();
 int h = scrolled_image_pixmap_item_->boundingRect().height() *
   scrolled_image_pixmap_item_->scale();

 int new_left = background_rectangle_center_x_ - (w/2);
 int new_top = background_rectangle_center_y_ - (h/2);

 scrolled_image_pixmap_item_->setPos(new_left, new_top);
}


void DHAX_Image_Viewer::recenter_scroll_center()
{
 if(!image_scene_item_)
   return;

 image_scene_item_->reset_background_to_original_position();

 scrolled_image_view_->centerOn(background_rectangle_center_x_, background_rectangle_center_y_);
}


void DHAX_Image_Viewer::recenter_scroll_top_left()
{
 if(!image_scene_item_)
   return;

 image_scene_item_->reset_background_to_original_position();

 qreal width = scrolled_image_view_->viewport()->width();
 qreal height = scrolled_image_view_->viewport()->height();

 QPointF pos = scrolled_image_pixmap_item_->pos();
 pos += {width/2, height/2};

 scrolled_image_view_->centerOn(pos);
}


void DHAX_Image_Viewer::cancel_notation()
{
 image_scene_item_->cancel_notation();
}


void DHAX_Image_Viewer::draw_circle(const QPointF& center,
  r8 radius, QColor brush_color, QColor pen_color, u1 index)
{
 QBrush qbr(brush_color);
 QPen qpen(pen_color);
 QGraphicsEllipseItem* el = scrolled_image_scene_->addEllipse(center.x() - radius,
   center.y() - radius, radius * 2, radius * 2, qpen, qbr);
 el->setParentItem(scrolled_image_pixmap_item_);
 el->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);

 if(index)
   controls_[index] = {el, radius};
}

void DHAX_Image_Viewer::load_image(QPixmap pixmap)
{
 scrolled_image_pixmap_ = new QPixmap(pixmap);
 complete_load_image();
}

void DHAX_Image_Viewer::complete_load_image()
{
 int sipw = scrolled_image_pixmap_->width();
 int siph = scrolled_image_pixmap_->height();


 background_rectangle_ = scrolled_image_scene_->addRect(0, 0, sipw * 2, siph * 2);

 background_rectangle_center_x_ = background_rectangle_->boundingRect().x() +
   (background_rectangle_->boundingRect().width() / 2);

 background_rectangle_center_y_ = background_rectangle_->boundingRect().y() +
   (background_rectangle_->boundingRect().height() / 2);


 display_image_data_->setView(scrolled_image_pixmap_->toImage());


  // //  always new ?
 image_scene_item_ = new DHAX_Image_Scene_Item;// (this);
 image_scene_item_->set_data(display_image_data_);
 image_scene_item_->set_containing_image_view(scrolled_image_view_);


 image_scene_item_->resize(sipw, siph);

 image_scene_item_->setParent(nullptr);

 //QGraphicsProxyWidget* w =  scrolled_image_scene_->addWidget(image_scene_item_);

 _Proxy_Widget* w = scrolled_image_scene_->add_proxy_widget(image_scene_item_);
 w->setPos(sipw/2,siph/2);

 //?
 if(background_center_rectangle_)
   delete background_center_rectangle_;

 background_center_rectangle_ = scrolled_image_scene_->addRect(
   (sipw/2) - 10, (siph/2) - 10, sipw + 20, siph + 20);

 image_scene_item_->set_original_position(background_center_rectangle_->pos());

 background_center_rectangle_->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
 reset_background_center_rectangle_color();

// QGraphicsRectItem* foreground_center_rectangle_ = scrolled_image_scene_->addRect(
//   (sipw/2) - 10, (siph/2) - 10, sipw, siph);
// foreground_center_rectangle_->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
// foreground_center_rectangle_->setVisible(false);
// QBrush qbr;
// qbr.setColor(QColor::fromRgba(qRgba(200, 200, 100, 100)));
// qbr.setStyle(Qt::BrushStyle::SolidPattern);
// foreground_center_rectangle_->setBrush(qbr);

 //foreground_center_rectangle


 w->graphicsItem()->setParentItem(background_center_rectangle_);

 image_scene_item_->set_this_proxy_widget(w);
 image_scene_item_->set_background_item(background_center_rectangle_);


 scrolled_image_pixmap_item_ = w;

 //?
 recenter_scroll_center();
}

void DHAX_Image_Viewer::reset_background_center_rectangle_color()
{
 background_center_rectangle_->setBrush(application_colors_->value("image-background-center-rectangle-color"));
}

void DHAX_Image_Viewer::load_image(QString file_path)
{
// main_layout_->removeWidget(scrolled_image_view_);
// scrolled_image_view_ = new QGraphicsView(this);


// main_layout_->addWidget(scrolled_image_view_);

// scrolled_image_view_->setScene(scrolled_image_scene_);

//// main_layout_->update();


 scrolled_image_pixmap_ = new QPixmap(file_path);

 complete_load_image();

}
