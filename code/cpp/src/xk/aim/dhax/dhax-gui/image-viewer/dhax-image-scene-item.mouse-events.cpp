
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dhax-image-scene-item.h"

#include <QMessageBox>
#include <QScrollBar>
#include <QGraphicsProxyWidget>
#include <QMenu>

#include "main-window/dhax-main-window.h"

#include "dhax-graphics-view.h"


template<>
void DHAX_Image_Scene_Item::handle_mouse_event<
  DHAX_Image_Scene_Item::Mouse_Event_Modes::Left_Edit>(QMouseEvent* mev)
{

}

template<>
void DHAX_Image_Scene_Item::handle_mouse_event<
  DHAX_Image_Scene_Item::Mouse_Event_Modes::Left_Move>(QMouseEvent* mev)
{

}

template<>
void DHAX_Image_Scene_Item::handle_mouse_event<
  DHAX_Image_Scene_Item::Mouse_Event_Modes::Left_Init>(QMouseEvent* mev)
{
 if(data_->multi_draw)
 {
  data_->check_hold_drawn_shape();
 }
 else
 {
  data_->check_reset_drawn_shape();
//  if(data_->check_reset_drawn_shape())
//    update();
 }

//?
// if(!data_->drawingSquareEnabled_ && !data_->drawingEllipseEnabled_ && !data_->drawingPolygonEnabled_)
//   QMessageBox::warning(this,"Warning!","Please select the shape's form");
// else
// {
//  if(!data_->nameSelected_)
//   data_->nameSelected_ = true;
//  if(!data_->nameSelected_)
//   QMessageBox::warning(this,"Warning!","Please select an instance name");
//  else
//  {
//   data_->shapeID_.clear();

 DHAX_Drawn_Shape::Shape_Kinds sk = data_->current_enabled_shape_kind();

 switch(sk)
 {
 default: break;
 case DHAX_Drawn_Shape::Shape_Kinds::Ellipse:
 case DHAX_Drawn_Shape::Shape_Kinds::Rectangle:
  {
     // //  don't need to test for this here ...
     //if(data_->mStartPoint_.isNull())
   data_->mStartPoint_ = mev->pos();
   data_->mEndPoint_ = mev->pos();
   data_->isMoving_ = true;
   update();
  }
  break;
 case DHAX_Drawn_Shape::Shape_Kinds::Polygon:
  {
   data_->point_pairs_.push_back({mev->pos(), mev->pos()});
   data_->isMoving_ = true;
   update();
  }
  break;
 }
}

template<>
void DHAX_Image_Scene_Item::handle_mouse_event<
  DHAX_Image_Scene_Item::Mouse_Event_Modes::Left_Move_Release>(QMouseEvent* mev)
{
 DHAX_Drawn_Shape::Shape_Kinds sk = data_->current_enabled_shape_kind();

 DHAX_Drawn_Shape* dds = data_->check_current_drawn_shape(); //get_current_drawn_shape_

 switch(sk)
 {
 default: break;

 case DHAX_Drawn_Shape::Shape_Kinds::Polygon:
  {
   data_->point_pairs_.last().second = mev->pos();
   data_->isMoving_ = false;
  }
  break;

 case DHAX_Drawn_Shape::Shape_Kinds::Ellipse:
 case DHAX_Drawn_Shape::Shape_Kinds::Rectangle:
  {
   dds->points() << data_->mStartPoint_ << mev->pos();
   data_->isMoving_ = false;
  }
  break;
 }
}

template<>
void DHAX_Image_Scene_Item::handle_mouse_event<
  DHAX_Image_Scene_Item::Mouse_Event_Modes::Left_Edit_Release>(QMouseEvent* mev)
{

}

template<>
void DHAX_Image_Scene_Item::handle_mouse_event<
  DHAX_Image_Scene_Item::Mouse_Event_Modes::Right_Edit>(QMouseEvent* mev)
{

}

template<>
void DHAX_Image_Scene_Item::handle_mouse_event<
  DHAX_Image_Scene_Item::Mouse_Event_Modes::Right_Move>(QMouseEvent* mev)
{

}

template<>
void DHAX_Image_Scene_Item::handle_mouse_event<
  DHAX_Image_Scene_Item::Mouse_Event_Modes::Right_Init>(QMouseEvent* mev)
{

}



template<>
void DHAX_Image_Scene_Item::handle_mouse_event<
  DHAX_Image_Scene_Item::Mouse_Event_Modes::Right_Click_Iso>(QMouseEvent* mev)
{
 QMenu* menu = new QMenu(nullptr);
 menu->setAttribute(Qt::WA_DeleteOnClose);

 if(meshlab_import_count_ && *meshlab_import_count_)
 {
  menu->addAction("MeshLab Import Info", [this]
  {
   Q_EMIT meshlab_import_info_requested();
  });

  menu->addAction("MeshLab Reset", [this]
  {
   Q_EMIT meshlab_reset_requested();
  });
 }

 if(freecad_import_count_ && *freecad_import_count_)
 {
  menu->addAction("FreeCAD Import Info", [this]
  {
   Q_EMIT freecad_import_info_requested();
  });

  menu->addAction("FreeCAD Reset", [this]
  {
   Q_EMIT freecad_reset_requested();
  });
 }


 if(!data_->point_pairs_.isEmpty())
 {
  menu->addAction("Complete Polygon", [this]
  {
   Q_EMIT complete_polygon_requested();
  });

  menu->addAction("Save Notation", [this]
  {
   Q_EMIT polygon_save_notation_requested();
  });

  menu->addAction("Complete and Save", [this]
  {
   Q_EMIT polygon_complete_and_save_notation_requested();
  });

  menu->addAction("Save Notation with Comment", [this]
  {
  });

  menu->addAction("Complete and Save with Comment", [this]
  {
  });

  menu->addAction("Cancel Notation", [this]
  {
   cancel_notation();
//   data_->check_clear_last_canceled_drawn_shapes();
//   data_->cancel_current_drawn_shape();

//   update();
  });

 }

 else if(data_->get_current_drawn_shape())
 {
  menu->addAction("Save Notation", [this]
  {
//   qDebug() << "this = " << this;
//   this->handle_save_notation_requested();
   Q_EMIT save_notation_requested(false);
//   Q_EMIT onLineDraw({});
  });

  menu->addAction("Save Notation with Comment", [this]
  {
   Q_EMIT save_notation_requested(true);
  });

  menu->addAction("Convert Notation", [this]
  {
   Q_EMIT  convert_notation_requested();
  });

  menu->addAction("Cancel Notation", [this]
  {
   cancel_notation();
//   data_->check_clear_last_canceled_drawn_shapes();
//   data_->cancel_current_drawn_shape();

//   update();
  });
 }

 if(data_->active_curve())
 {
  menu->addAction("Draw Bezier", [this]
  {
   Q_EMIT draw_bezier_requested();
  });

  menu->addAction("Draw Cubic", [this]
  {
   Q_EMIT draw_cubic_path_requested();
  });

  menu->addAction("Draw Quad", [this]
  {
   Q_EMIT draw_quad_path_requested();
  });

  menu->addAction("Draw Arc", [this]
  {
   //Q_EMIT draw_quad_path_requested();
  });

  menu->addAction("Hide Diagonal", [this]
  {
   //Q_EMIT draw_quad_path_requested();
  });
 }

 QPoint pos = this_proxy_widget_->mapToScene(mev->pos()).toPoint();
 QPoint pos1 = containing_image_view_->mapFromScene(pos);

 menu->popup(containing_image_view_->viewport()->mapToGlobal(pos1));
}



void DHAX_Image_Scene_Item::_handle_mouse_event(QMouseEvent* mev, Mouse_Event_Modes mem)
{
 switch(mem)
 {
#define TEMP_MACRO(x) case Mouse_Event_Modes::x: handle_mouse_event<Mouse_Event_Modes::x>(mev); return;
  TEMP_MACRO(Left_Edit)TEMP_MACRO(Left_Move)TEMP_MACRO(Left_Init)
  TEMP_MACRO(Right_Edit)TEMP_MACRO(Right_Move)TEMP_MACRO(Right_Init)
  TEMP_MACRO(Left_Move_Release)TEMP_MACRO(Left_Edit_Release)
  TEMP_MACRO(Right_Click_Iso)
   default:break;
 }
}


