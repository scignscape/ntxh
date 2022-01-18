
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DHAX_IMAGE_VIEWER__H
#define DHAX_IMAGE_VIEWER__H

#include <QFrame>
#include <QBoxLayout>
#include <QGraphicsRectItem>

#include "accessors.h"

#include "global-types.h"

#include "application/dhax-application-state.h"

class DHAX_Graphics_Scene;
class DHAX_Graphics_View;

class DHAX_Image_Scene_Item;
class DHAX_Display_Image_Data;
class DHAX_Main_Window;

class DHAX_Application_State;


class DHAX_Image_Viewer : public QWidget
{
 Q_OBJECT

 QPixmap* scrolled_image_pixmap_;

 // QPixmap* original_scrolled_image_pixmap_;
 // QMap<int, QPixmap*> pixmaps_by_contrast_measure_;


 //QGraphicsScene *scene
 DHAX_Graphics_View* scrolled_image_view_;
 DHAX_Graphics_Scene* scrolled_image_scene_;

 //QGraphicsPixmapItem* scrolled_image_pixmap_item_;
 QGraphicsProxyWidget* scrolled_image_pixmap_item_;

 DHAX_Application_State* application_state_;

 QGraphicsRectItem* background_rectangle_;
 QGraphicsRectItem* background_center_rectangle_;

 int background_rectangle_center_x_;
 int background_rectangle_center_y_;

 QVBoxLayout* main_layout_;

 DHAX_Image_Scene_Item* image_scene_item_;

 DHAX_Display_Image_Data* display_image_data_;

 DHAX_Main_Window* main_window_;

 void recenter_image();

 // //  what should be the item class here?
 QMap<u1, QPair<QGraphicsEllipseItem*, r8>> controls_;


public:

 DHAX_Image_Viewer(QWidget *parent = nullptr);


 ACCESSORS__GET(DHAX_Image_Scene_Item* ,image_scene_item)
 ACCESSORS__GET(DHAX_Display_Image_Data* ,display_image_data)
 ACCESSORS(DHAX_Main_Window* ,main_window)

 ACCESSORS(DHAX_Graphics_View* ,scrolled_image_view)
 ACCESSORS(DHAX_Graphics_Scene* ,scrolled_image_scene)
 ACCESSORS(QGraphicsProxyWidget* ,scrolled_image_pixmap_item)

 ACCESSORS(DHAX_Application_State* ,application_state)

 //?ACCESSORS(MACRO_PASTE(const QMap<QString, QColor>*) ,application_colors)

 void reset_background_center_rectangle_color();
 void reset_background_rectangle_color();

 QPointF control_center(u1 index)
 {
  QGraphicsEllipseItem* el = controls_[index].first;

  return {el->rect().topLeft().x() + el->pos().x() + controls_[index].second,
     el->rect().topLeft().y() + el->pos().y() + controls_[index].second};
 }

 void recenter_scroll_center();
 void recenter_scroll_top_left();

 //QPair<u4, u4> update_image_margins(const DHAX_Application_State::Image_Margins& im);
 void update_image_margins(const DHAX_Application_State::Image_Margins& im);

 void load_image(QString file_path);

 void load_image(QPixmap pixmap);

 void complete_load_image();

 void reset_scale(r8 factor);

 void cancel_notation();

 void draw_circle(const QPointF& center, r8 radius, QColor brush_color,
   QColor pen_color, u1 index);

 void mouseMoveEvent(QMouseEvent *mouseEvent);

};

#endif //  DHAX_IMAGE_VIEWER__H




