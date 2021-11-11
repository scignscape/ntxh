
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DHAX_IMAGE_SCENE_ITEM__H
#define DHAX_IMAGE_SCENE_ITEM__H

#include <QFrame>
#include <QBoxLayout>
#include <QGraphicsRectItem>

#include "accessors.h"

#include "global-types.h"

#include "dhax-display-image-data.h"

class DHAX_Graphics_Scene;
class DHAX_Graphics_View;

class DHAX_Display_Image_Data;
class DHAX_Main_Window;

class DHAX_Annotation_Instance;

class DHAX_Drawn_Shape;

class DHAX_Image_Scene_Item : public QWidget
{
 Q_OBJECT

private:


// QPixmap* scrolled_image_pixmap_;

//// QPixmap* original_scrolled_image_pixmap_;
//// QMap<int, QPixmap*> pixmaps_by_contrast_measure_;


// //QGraphicsScene *scene
// QGraphicsView* scrolled_image_view_;
// QGraphicsScene* scrolled_image_scene_;
// QGraphicsPixmapItem* scrolled_image_pixmap_item_;

// QGraphicsRectItem* background_rectangle_;

// int background_rectangle_center_x_;
// int background_rectangle_center_y_;

// QVBoxLayout* main_layout_;

// void recenter_image();

 DHAX_Display_Image_Data* data_;

 QGraphicsProxyWidget* this_proxy_widget_;

 QGraphicsItem* background_item_;

 DHAX_Graphics_View* containing_image_view_;

 QPointF original_position_;

 u4* meshlab_import_count_;
 u4* freecad_import_count_;

 QVector<QPair<DHAX_Annotation_Instance*, r8>> saved_dhax_annotations_;

// QGraphics

 enum class Mouse_Event_Modes { N_A, Left_Edit, Left_Move,
   Left_Init, Right_Edit, Right_Move, Right_Init,
   Left_Move_Release, Left_Edit_Release,
   Right_Click_Iso   };

 template<Mouse_Event_Modes mem>
 void handle_mouse_event(QMouseEvent* mev);

 void _handle_mouse_event(QMouseEvent* mev, Mouse_Event_Modes mem);

 void paintEvent_draw_point_pairs(QVector<QPair<QPoint, QPoint>>& pairs, QPainter& painter,
   QPen& pen, QPen& shape_pen);

 void paintEvent_draw_drawn_shape(DHAX_Drawn_Shape* dds, QString text,
   QPainter& painter, QPen& pen, QPen& shape_pen);

 void paintEvent_draw_drawn_shape(DHAX_Drawn_Shape* dds,
   QPainter& painter, QPen& pen, QPen& shape_pen)
 {
  paintEvent_draw_drawn_shape(dds, {}, painter, pen, shape_pen);
 }

 void paintEvent_draw_annotation(DHAX_Annotation_Instance& axa, QPainter& painter,
   QPen& pen, QPen& shape_pen, r8 resize_factor);

 void paintEvent_draw_vertex_handles(const QVector<const QPoint*>& points, QPainter& painter);

public:

 DHAX_Image_Scene_Item(QWidget *parent = 0);

 USE_SELF_CONNECT(normal)
 USE_SELF_CONNECT(lambda)

 ACCESSORS(DHAX_Display_Image_Data* ,data)
 ACCESSORS(QGraphicsProxyWidget* ,this_proxy_widget)
 ACCESSORS(QPointF ,original_position)
 ACCESSORS(QGraphicsItem* ,background_item)
 ACCESSORS(DHAX_Graphics_View* ,containing_image_view)
 ACCESSORS(u4* ,meshlab_import_count)
 ACCESSORS(u4* ,freecad_import_count)


 enum shapes{ square, ellipse, polygon };

 void cancel_notation();


 void reset_background_to_original_position();

 void add_dhax_annotation(DHAX_Annotation_Instance* dai, r8 resize_factor)
 {
  saved_dhax_annotations_.push_back({dai, resize_factor});
 }

 ACCESSORS(MACRO_PASTE(QVector<QPair<DHAX_Annotation_Instance*, r8>>) ,saved_dhax_annotations)

Q_SIGNALS:

 //?
 void onLineDraw(QList<DHAX_Display_Image_Data::shape>);
 void setTuple(QString);

 void save_notation_requested(bool);
 void polygon_complete_and_save_notation_requested();
 void polygon_save_notation_requested();
 void complete_polygon_requested();
 void meshlab_import_info_requested();
 void meshlab_reset_requested();
 void freecad_import_info_requested();
 void freecad_reset_requested();

 void draw_bezier_requested();
 void draw_cubic_path_requested();
 void draw_quad_path_requested();

 void convert_notation_requested();


protected:
 void paintEvent(QPaintEvent *); //metodo per la stampa su schermo di tutte le annotazioni e le varie operazioni effettuate dall'utente
 void mousePressEvent(QMouseEvent *mouseEvent); //metodo per la gestione del click da parte dell'utente
 void mouseReleaseEvent(QMouseEvent *mouseEvent); //metodo per la gestione del rilascio del tasto premuto dall'utente
 void mouseMoveEvent(QMouseEvent *mouseEvent); //metodo per gestione del movimento del mouse e la posizione del puntatore sull'immagine
 void mouseDoubleClickEvent(QMouseEvent *mouseEvent); //metodo per la gestione del doppio click dell'utente


};

#endif //  DHAX_IMAGE_SCENE_ITEM__H




