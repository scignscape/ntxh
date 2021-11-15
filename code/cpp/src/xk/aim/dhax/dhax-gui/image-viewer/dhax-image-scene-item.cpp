
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dhax-image-scene-item.h"

#include "dhax-display-image-data.h"

#include "dhax-data/ann/dhax-annotation-instance.h"

#include <QGraphicsProxyWidget>

#include <QPainter>
#include <QDebug>


void DHAX_Image_Scene_Item::reset_background_to_original_position()
{
 background_item_->setPos(original_position_);
}

DHAX_Image_Scene_Item::DHAX_Image_Scene_Item(QWidget *parent) : QWidget(parent)
{
 containing_image_view_ = nullptr;

 setAutoFillBackground(true);
 setBackgroundRole(QPalette::Window);
 setAcceptDrops(true);
 setMouseTracking(true);
}


DHAX_Annotation_Instance* DHAX_Image_Scene_Item::get_annotation_comments()
{
 if(saved_dhax_annotations_.isEmpty())
   return nullptr;//{};
 for(QPair<DHAX_Annotation_Instance*, double> pr : saved_dhax_annotations_)
 {
  if(pr.first)
  {
   if(pr.first->comment().isEmpty())
    continue;
   return pr.first;
  }
 }
 return nullptr;//{};
}

void DHAX_Image_Scene_Item::uncancel_notation(DHAX_Drawn_Shape* dds)
{
 data_->set_current_drawn_shape(dds);
 data_->last_canceled_drawn_shapes().takeLast();
// data_->check_clear_last_canceled_drawn_shapes();
// data_->cancel_current_drawn_shape();

 update();
}

void DHAX_Image_Scene_Item::cancel_notation()
{
 data_->check_clear_last_canceled_drawn_shapes();
 data_->cancel_current_drawn_shape();

 update();
}


void DHAX_Image_Scene_Item::paintEvent_draw_vertex_handles(
  const QVector<const QPoint*>& points, QPainter& painter)
{
 int r = data_->radius_;
 QPoint pr(r, r);
 QPoint pr1(r - 1, r - 1);

 u1 i = 0;
 for(const QPoint* const point : points)
 {
//  QRect rect(*point - pr, *point + pr1);
//  painter.fillRect(rect, QColor(data_->sqRed_, data_->sqGreen_, data_->sqBlue_));

  draw_control_square(*point, painter, ++i);

 }
}

void DHAX_Image_Scene_Item::paintEvent_draw_point_pairs(QVector<QPair<QPoint, QPoint>>& pairs, QPainter& painter,
  QPen& pen, QPen& shape_pen, QPen& back_pen)
{
 u1 count = 0;
 QPoint sec;

 QPen local_pen;
 QBrush local_brush;

 if(true) //  drawn shape is selected ...
 {
  local_pen = shape_pen;
  local_brush = QBrush(QColor(data_->shapeRed_, data_->shapeGreen_, data_->shapeBlue_), Qt::Dense6Pattern);
 }
 else
 {
  local_pen = pen;
  local_brush = QBrush(QColor(data_->myRed_, data_->myGreen_, data_->myBlue_), Qt::Dense6Pattern);
 }

 for(QPair<QPoint, QPoint>& pr : pairs)
 {

  painter.setPen(back_pen);
  painter.setBrush(QBrush());
  painter.drawLine(pr.first, pr.second);
  if(count)
    painter.drawLine(sec, pr.first);

  painter.setPen(local_pen);
  painter.setBrush(local_brush);
  painter.drawLine(pr.first, pr.second);
  if(count)
    painter.drawLine(sec, pr.first);


  ++count;
  sec = pr.second;

  paintEvent_draw_vertex_handles({&pr.first, &pr.second}, painter);
 }

// Display_Drawn_Shape dds;
// dds.init_from_axfi_annotation(axa, resize_factor);
// paintEvent_draw_point_pairs(&dds, painter, pen, shape_pen);
}



void DHAX_Image_Scene_Item::paintEvent_draw_annotation(DHAX_Annotation_Instance& dai, QPainter& painter,
  QPen& pen, QPen& shape_pen, r8 resize_factor)
{
 DHAX_Drawn_Shape dds;
 dds.init_from_dhax_annotation(dai, resize_factor);
 paintEvent_draw_drawn_shape(&dds, dai.scoped_identifiers_to_string(),
   painter, pen, shape_pen);
}

void DHAX_Image_Scene_Item::paintEvent_draw_drawn_shape(DHAX_Drawn_Shape* dds,
  QString text, QPainter& painter, QPen& pen, QPen& shape_pen)
{
 static QPoint text_offest (5, -3);

 static int text_height_offset = 2;
 static int text_width_offset = 1;
 static int double_text_width_offset = 2*text_width_offset;


 if(!text.isEmpty())
 {
  QSize sz = QFontMetrics(painter.font()).size(Qt::TextSingleLine, text);

//?  painter.setBrush(Qt::white);
  painter.setBrush(Qt::white);
  painter.setBrush(QColor(data_->sqRed_, data_->sqGreen_, data_->sqBlue_));

  QPoint bl = dds->points()[0] + text_offest;

  painter.setPen({});
  painter.drawRect(bl.x() - text_width_offset,
    bl.y() - sz.height() + text_height_offset,
    sz.width() + double_text_width_offset, sz.height() + text_height_offset);

  painter.setPen(Qt::black);
  painter.drawText(dds->points()[0] + text_offest, text);

//  painter.setPen(Qt::white);

  //painter.setBrush(Qt::white);


 }

 if(true) //  drawn shape is selected ...
 {
  painter.setPen(shape_pen);
  painter.setBrush(QBrush(QColor(data_->shapeRed_, data_->shapeGreen_, data_->shapeBlue_), Qt::Dense6Pattern));
 }
 else
 {
  painter.setPen(pen);
  painter.setBrush(QBrush(QColor(data_->myRed_, data_->myGreen_, data_->myBlue_), Qt::Dense6Pattern));
 }

// painter.drawText(QPoint(data_->allEdits_[i].shapePoints.first().rx()+5,
//   data_->allEdits_[i].shapePoints.first().ry()-3), data_->allEdits_.at(i).id);

 bool polyline = false;

 switch (dds->shape_kind())
 {
 case DHAX_Drawn_Shape::Shape_Kinds::Rectangle:
  {
   const QPoint& tl = dds->points()[0];
   const QPoint& br = dds->points()[1];

   QRect rect(tl, br);
   painter.drawRect(rect);

   QPoint tr = rect.topRight();
   QPoint bl = rect.bottomLeft();

   paintEvent_draw_vertex_handles({&tl, &tr, &br, &bl}, painter);

//   {
//    painter.fillRect(rect, QColor(data_->sqRed_, data_->sqGreen_, data_->sqBlue_))
//   }

//   QPoint temp = data_->allEdits_.at(i).shapePoints.at(2);
//   QRect square(data_->allEdits_[i].shapePoints.first().rx(),data_->allEdits_[i].shapePoints.first().ry(),
//               (temp.rx() - data_->allEdits_[i].shapePoints.first().rx()),
//               (temp.ry() - data_->allEdits_[i].shapePoints.first().ry()));
//   painter.drawRect(square);
//   for(int j = 0; j < data_->allEdits_.at(i).shapePoints.size(); ++j)
//   {
//    QRect rect(data_->allEdits_[i].shapePoints[j].rx() - data_->radius_,
//               data_->allEdits_[i].shapePoints[j].ry()- data_->radius_ , data_->radius_ * 2, data_->radius_ * 2);
//    painter.fillRect(rect, QColor(data_->sqRed_, data_->sqGreen_, data_->sqBlue_));
//   }
  }
  break;

 case DHAX_Drawn_Shape::Shape_Kinds::Ellipse:
  {
   const QPoint& tl = dds->points()[0];
   const QPoint& br = dds->points()[1];

   QRect rect(tl, br);
   painter.drawEllipse(rect);

   QPoint tr = rect.topRight();
   QPoint bl = rect.bottomLeft();

   paintEvent_draw_vertex_handles({&tl, &tr, &br, &bl}, painter);

  }
  break;

 case DHAX_Drawn_Shape::Shape_Kinds::Polyline:
  polyline = true;
  // fallthrough
  [[fallthrough]];
 case DHAX_Drawn_Shape::Shape_Kinds::Non_Regular_Polygon:
  {
   u1 count = 0;
   QPoint last;
   QVector<const QPoint*> ptrs;
   ptrs.resize(dds->points().size());
   for(const QPoint& qp : dds->points())
   {
    ptrs[count] = &qp;
    ++count;
    if(count == 1)
    {
     last = qp;
     continue;
    }
    painter.drawLine(last, qp);
    last = qp;
   }
   if((count > 2) && !polyline)
     painter.drawLine(last, dds->points().first());
   paintEvent_draw_vertex_handles(ptrs, painter);
  }
  break;

 default:
  break;
 }
// painter.drawText(QPoint(data_->allEdits_[i].shapePoints.first().rx()+5,
//   data_->allEdits_[i].shapePoints.first().ry()-3), data_->allEdits_.at(i).id);

}


void DHAX_Image_Scene_Item::draw_control_square(const QPoint& center,
  QPainter& painter, u1 wind)
{
 int r = data_->radius_;
 QPoint pr(r, r);
 QPoint pr1(r - 1, r - 1);

 QRect rect(center - pr, center + pr1);
 //painter.fillRect(rect, QColor(data_->sqRed_, data_->sqGreen_, data_->sqBlue_));

 //QRect rect(center.x() - data_->radius_, center.y() - data_->radius_, data_->radius_*2, data_->radius_*2);

 u1 sgradient_base = 0;
 u1 sgradient_mid = 100;
 u1 wind_multiple = 30;
 QConicalGradient sgradient;
 sgradient.setAngle(wind * wind_multiple);
 sgradient.setCenter(center);//.x() - data_->radius_/2,
                     //center.y() - data_->radius_/2);
 sgradient.setColorAt(0.0, QColor(data_->sqRed_,data_->sqGreen_,data_->sqBlue_));
 sgradient.setColorAt(0.15, QColor(data_->sqRed_,data_->sqGreen_,data_->sqBlue_));
 sgradient.setColorAt(0.2, QColor(sgradient_mid,sgradient_mid,sgradient_base));
 sgradient.setColorAt(0.25, QColor(data_->sqRed_,data_->sqGreen_,data_->sqBlue_));
 sgradient.setColorAt(0.5, QColor(data_->sqRed_,data_->sqGreen_,data_->sqBlue_));
 sgradient.setColorAt(0.55, QColor(sgradient_mid,sgradient_base,sgradient_mid));
 sgradient.setColorAt(0.6, QColor(data_->sqRed_,data_->sqGreen_,data_->sqBlue_));
 sgradient.setColorAt(0.8, QColor(data_->sqRed_,data_->sqGreen_,data_->sqBlue_));
 sgradient.setColorAt(0.85, QColor(sgradient_base,sgradient_mid,sgradient_mid));
 sgradient.setColorAt(0.9, QColor(data_->sqRed_,data_->sqGreen_,data_->sqBlue_));
 sgradient.setColorAt(1, QColor(data_->sqRed_,data_->sqGreen_,data_->sqBlue_));
 painter.fillRect(rect, sgradient);
}


void DHAX_Image_Scene_Item::paintEvent(QPaintEvent*)
{
 QPainter painter(this);
 QPen myPen(QColor(data_->myRed_, data_->myGreen_,data_->myBlue_), data_->thickness_, Qt::SolidLine); //myPen per tutte le shape

 u1 gradient_base = 140;
 QConicalGradient gradient;
 gradient.setSpread(QGradient::ReflectSpread);
 gradient.setCenter( ((rect().topLeft() + rect().center())/2) );
 gradient.setAngle(-65);
   gradient.setColorAt(0, QColor(data_->shapeRed_,gradient_base,gradient_base,data_->shapeAlpha_));
   gradient.setColorAt(0.05, QColor(data_->shapeRed_,data_->shapeGreen_,gradient_base,data_->shapeAlpha_));
   gradient.setColorAt(0.1, QColor(data_->shapeRed_,data_->shapeGreen_,data_->shapeBlue_,data_->shapeAlpha_));
   gradient.setColorAt(0.15, QColor(gradient_base, data_->shapeGreen_, data_->shapeBlue_,data_->shapeAlpha_));
   gradient.setColorAt(0.2, QColor(gradient_base, data_->shapeGreen_, gradient_base,data_->shapeAlpha_));
   gradient.setColorAt(0.25, QColor(data_->shapeRed_, data_->shapeGreen_, gradient_base,data_->shapeAlpha_));
   gradient.setColorAt(0.3, QColor(data_->shapeRed_, gradient_base, data_->shapeBlue_,data_->shapeAlpha_));
   gradient.setColorAt(0.35, QColor(gradient_base, gradient_base, data_->shapeBlue_,data_->shapeAlpha_));
   gradient.setColorAt(0.4, QColor(0,255,0,data_->shapeAlpha_));
   gradient.setColorAt(0.45, QColor(255,255,0,data_->shapeAlpha_));
   gradient.setColorAt(0.5, QColor(0,255,255,data_->shapeAlpha_));
   gradient.setColorAt(0.55, QColor(255,255,0,data_->shapeAlpha_));
   gradient.setColorAt(0.6, QColor(0,255,0,data_->shapeAlpha_));
   gradient.setColorAt(0.65, QColor(gradient_base, gradient_base, data_->shapeBlue_,data_->shapeAlpha_));
   gradient.setColorAt(0.7, QColor(data_->shapeRed_, gradient_base, data_->shapeBlue_,data_->shapeAlpha_));
   gradient.setColorAt(0.75, QColor(data_->shapeRed_, data_->shapeGreen_, gradient_base,data_->shapeAlpha_));
   gradient.setColorAt(0.8, QColor(gradient_base, data_->shapeGreen_, gradient_base,data_->shapeAlpha_));
   gradient.setColorAt(0.85, QColor(gradient_base, data_->shapeGreen_, data_->shapeBlue_,data_->shapeAlpha_));
   gradient.setColorAt(0.9, QColor(data_->shapeRed_,data_->shapeGreen_,data_->shapeBlue_,data_->shapeAlpha_));
   gradient.setColorAt(0.95, QColor(data_->shapeRed_,data_->shapeGreen_,gradient_base,data_->shapeAlpha_));
   gradient.setColorAt(1, QColor(data_->shapeRed_,gradient_base,gradient_base,data_->shapeAlpha_));


//   auto p = QPen(gradient, 4.0);
   QPen shapePen(gradient, data_->thickness_, Qt::DashDotDotLine); //shapePen

//   QPen back_pen(QColor(25,255,225,data_->shapeBackAlpha_), data_->back_thickness_, Qt::SolidLine); //shapePen
//   QPen back_pen(QColor(255,55,25,data_->shapeBackAlpha_), data_->back_thickness_, Qt::SolidLine); //shapePen
   QPen back_pen(QColor(125,215,255,data_->shapeBackAlpha_), data_->back_thickness_, Qt::SolidLine); //shapePen

// QPen shapePen(QColor(data_->shapeRed_, data_->shapeGreen_, data_->shapeBlue_), data_->thickness_, Qt::SolidLine);
 myPen.setCapStyle(Qt::RoundCap);
 shapePen.setCapStyle(Qt::RoundCap);
 painter.setPen(shapePen);
 painter.setBrush(QBrush(QColor(data_->shapeRed_, data_->shapeGreen_, data_->shapeBlue_),Qt::Dense6Pattern)); //permette a painter di creare shape traslucide
 if(!data_->m_background_.isNull())
   painter.drawImage(0, 0, data_->m_background_); //riempe lo sfonfo con l'immagine scelta dall'utente

 if(!data_->editing_)
 {          //drawingSquareEnabled_
  if(data_->current_enabled_shape_kind()
       == DHAX_Display_Image_Data::Shape_Kinds::Rectangle
       && data_->isMoving_)
  {
   data_->points_.clear();
   data_->points_ << data_->mStartPoint_ << QPoint(data_->mStartPoint_.rx(),data_->mEndPoint_.ry())
           << data_->mEndPoint_ << QPoint(data_->mEndPoint_.rx(), data_->mStartPoint_.ry());

   QRect square(data_->mStartPoint_.rx(), data_->mStartPoint_.ry(),
     (data_->mEndPoint_.rx() - data_->mStartPoint_.rx()), (data_->mEndPoint_.ry()-data_->mStartPoint_.ry()));

   painter.setPen(back_pen);
   painter.drawRect(square);

   painter.setPen(shapePen);
   painter.drawRect(square);


   for(int i=0; i < data_->points_.size(); ++i)
   {
    draw_control_square(data_->points_[i], painter, i + 1);

//    QRect rect(data_->points_[i].rx() - data_->radius_, data_->points_[i].ry() - data_->radius_, data_->radius_*2, data_->radius_*2);

//    u1 sgradient_base = 0;
//    QConicalGradient sgradient;
//    sgradient.setCenter(data_->points_[i].rx() - data_->radius_/2,
//                        data_->points_[i].ry() - data_->radius_/2);
//    sgradient.setColorAt(0, QColor(sgradient_base,sgradient_base,sgradient_base));
//    sgradient.setColorAt(1, QColor(data_->sqRed_,data_->sqGreen_,data_->sqBlue_));
//    //sgradient.setColorAt(1, QColor(sgradient_base,sgradient_base,sgradient_base));
//    painter.fillRect(rect, sgradient);

    //painter.fillRect(rect, QColor(data_->sqRed_, data_->sqGreen_, data_->sqBlue_));

    //qDebug() << "fr: " << rect;

   }
  }
                //drawingEllipseEnabled_
  if(data_->current_enabled_shape_kind()
       == DHAX_Display_Image_Data::Shape_Kinds::Ellipse
       && data_->isMoving_)
  {
   data_->points_.clear();
   data_->points_ << data_->mStartPoint_ << QPoint(data_->mStartPoint_.rx(), data_->mEndPoint_.ry())
     << data_->mEndPoint_ << QPoint(data_->mEndPoint_.rx(), data_->mStartPoint_.ry());

   QRect ellipse(data_->mStartPoint_.rx(), data_->mStartPoint_.ry(),
     (data_->mEndPoint_.rx() - data_->mStartPoint_.rx()), (data_->mEndPoint_.ry() - data_->mStartPoint_.ry()));


   painter.setPen(back_pen);
   painter.drawEllipse(ellipse);

   painter.setPen(shapePen);
   painter.drawEllipse(ellipse);


   for(int i=0; i<data_->points_.size(); ++i)
   {
    draw_control_square(data_->points_[i], painter, i + 1);
//    QRect rect(data_->points_[i].rx() - data_->radius_, data_->points_[i].ry() - data_->radius_, data_->radius_*2, data_->radius_*2);
//    painter.fillRect(rect, QColor(data_->sqRed_, data_->sqGreen_, data_->sqBlue_));
   }
  }

  if(data_->shapeMoving_)
  {
   qDebug() << "m2 ...";

   int diffx = (data_->mEndPoint_.rx() - data_->mStartPoint_.rx());
   int diffy = (data_->mEndPoint_.ry() - data_->mStartPoint_.ry());

   for(int i=0; i < data_->allEdits_[data_->shapePosition_].shapePoints.size();++i)
   {
    int coox = data_->allEdits_[data_->shapePosition_].shapePoints[i].rx()+diffx;
    if(coox<0)
      coox=0;
    if(coox>this->size().width())
      coox=this->size().width();

    int cooy = data_->allEdits_[data_->shapePosition_].shapePoints[i].ry()+diffy;
    if(cooy<0)
      cooy=0;
    if(cooy > this->size().height())
      cooy=this->size().height();
    data_->allEdits_[data_->shapePosition_].shapePoints.replace(i,QPoint(coox,cooy));
   }

   data_->mStartPoint_ = data_->mEndPoint_;
  }
 }
 else
 {
  qDebug() << "end ...";

  data_->allEdits_[data_->shapePosition_].shapePoints.replace(data_->pointPosition_, data_->mEndPoint_);

  if(data_->allEdits_[data_->shapePosition_].form == square || data_->allEdits_[data_->shapePosition_].form==ellipse)
  {
   if(data_->pointPosition_ == 0)
   {
    data_->mStartPoint_= data_->allEdits_[data_->shapePosition_].shapePoints.at(2);
    data_->allEdits_[data_->shapePosition_].shapePoints.replace(1,QPoint(data_->mEndPoint_.rx(),data_->mStartPoint_.ry()));
    data_->allEdits_[data_->shapePosition_].shapePoints.replace(3,QPoint(data_->mStartPoint_.rx(),data_->mEndPoint_.ry()));
   }
   if(data_->pointPosition_ == 1)
   {
    data_->mStartPoint_ = data_->allEdits_[data_->shapePosition_].shapePoints.at(3);
    data_->allEdits_[data_->shapePosition_].shapePoints.replace(0, QPoint(data_->mEndPoint_.rx(), data_->mStartPoint_.ry()));
    data_->allEdits_[data_->shapePosition_].shapePoints.replace(2, QPoint(data_->mStartPoint_.rx(), data_->mEndPoint_.ry()));
   }
   if(data_->pointPosition_ == 2)
   {
    data_->mStartPoint_ = data_->allEdits_[data_->shapePosition_].shapePoints.at(0);
    data_->allEdits_[data_->shapePosition_].shapePoints.replace(3, QPoint(data_->mEndPoint_.rx(),data_->mStartPoint_.ry()));
    data_->allEdits_[data_->shapePosition_].shapePoints.replace(1, QPoint(data_->mStartPoint_.rx(),data_->mEndPoint_.ry()));
   }
   if(data_->pointPosition_ == 3)
   {
    data_->mStartPoint_ = data_->allEdits_[data_->shapePosition_].shapePoints.at(1);
    data_->allEdits_[data_->shapePosition_].shapePoints.replace(2, QPoint(data_->mEndPoint_.rx(), data_->mStartPoint_.ry()));
    data_->allEdits_[data_->shapePosition_].shapePoints.replace(0, QPoint(data_->mStartPoint_.rx(), data_->mEndPoint_.ry()));
   }
  }
  data_->mStartPoint_ = QPoint();
  data_->mEndPoint_ = QPoint();
 }


 if(!data_->point_pairs_.isEmpty())
 {
  paintEvent_draw_point_pairs(data_->point_pairs_, painter,
    myPen, shapePen, back_pen);
 }

 if(!data_->held_drawn_shapes_.isEmpty())
 {
  // //  any setup?
  for(DHAX_Drawn_Shape* dds : data_->held_drawn_shapes())
    paintEvent_draw_drawn_shape(dds, painter, myPen, shapePen);
 }

 if(DHAX_Drawn_Shape* dds = data_->current_drawn_shape())
 {
  paintEvent_draw_drawn_shape(dds, painter, myPen, shapePen);
 }

 if(!saved_dhax_annotations_.isEmpty())
 {
  // //  any setup?
  for(QPair<DHAX_Annotation_Instance*, r8> pr : saved_dhax_annotations_)
  {
   paintEvent_draw_annotation(*pr.first, painter, myPen, shapePen, pr.second);
  }

//      Display_Drawn_Shape* dds : data_->held_drawn_shapes())
//    paintEvent_draw_drawn_shape(dds, painter, myPen, shapePen);
 }


 if(!data_->allEdits_.isEmpty())
 {
  for(int i = 0; i < data_->allEdits_.size(); ++i)
  {
   if(!(data_->allEdits_.at(i).id.isNull()))
   {
    if(data_->allEdits_.at(i).id == data_->shapeID_)
    {
     painter.setPen(shapePen);
     painter.setBrush(QBrush(QColor(data_->shapeRed_, data_->shapeGreen_, data_->shapeBlue_), Qt::Dense6Pattern));
    }
    else
    {
     painter.setPen(myPen);
     painter.setBrush(QBrush(QColor(data_->myRed_, data_->myGreen_, data_->myBlue_), Qt::Dense6Pattern));
    }
    painter.drawText(QPoint(data_->allEdits_[i].shapePoints.first().rx()+5,
      data_->allEdits_[i].shapePoints.first().ry()-3), data_->allEdits_.at(i).id);
   }
   else
   {
    painter.setPen(shapePen);
    painter.setBrush(QBrush(QColor(data_->shapeRed_, data_->shapeGreen_, data_->shapeBlue_),Qt::Dense6Pattern));
   }

   if(data_->allEdits_.at(i).form ==square)
   {
    QPoint temp = data_->allEdits_.at(i).shapePoints.at(2);
    QRect square(data_->allEdits_[i].shapePoints.first().rx(),data_->allEdits_[i].shapePoints.first().ry(),
                 (temp.rx() - data_->allEdits_[i].shapePoints.first().rx()),
                 (temp.ry() - data_->allEdits_[i].shapePoints.first().ry()));
    painter.drawRect(square);
    for(int j = 0; j < data_->allEdits_.at(i).shapePoints.size(); ++j)
    {
     QRect rect(data_->allEdits_[i].shapePoints[j].rx() - data_->radius_,
                data_->allEdits_[i].shapePoints[j].ry()- data_->radius_ , data_->radius_ * 2, data_->radius_ * 2);
     painter.fillRect(rect, QColor(data_->sqRed_, data_->sqGreen_, data_->sqBlue_));
    }
   }
   if(data_->allEdits_.at(i).form==ellipse)
   {
    QPoint temp = data_->allEdits_.at(i).shapePoints.at(2);
    QRect ellipse(data_->allEdits_[i].shapePoints.first().rx(), data_->allEdits_[i].shapePoints.first().ry(),
                  (temp.rx() - data_->allEdits_[i].shapePoints.first().rx()),
                  (temp.ry() - data_->allEdits_[i].shapePoints.first().ry()));
    painter.drawEllipse(ellipse);
    for(int j=0; j < data_->allEdits_.at(i).shapePoints.size(); ++j)
    {
     QRect rect(data_->allEdits_[i].shapePoints[j].rx() - data_->radius_,
                data_->allEdits_[i].shapePoints[j].ry() - data_->radius_, data_->radius_ * 2,data_->radius_ * 2);
     painter.fillRect(rect, QColor(data_->sqRed_, data_->sqGreen_, data_->sqBlue_));
    }
   }
   if(data_->allEdits_.at(i).form==polygon)
   {
    QVector<QPoint> vect;
    for(int j = 0; j < data_->allEdits_.at(i).shapePoints.size(); ++j)
    {
     vect.append(data_->allEdits_.at(i).shapePoints.at(j));
    }
    QPolygon poly(vect);
    painter.drawPolygon(poly);
    for(int j = 0; j < data_->allEdits_.at(i).shapePoints.size(); ++j)
    {
     QRect rect(data_->allEdits_[i].shapePoints[j].rx() - data_->radius_,
                data_->allEdits_[i].shapePoints[j].ry() - data_->radius_,
                data_->radius_ * 2, data_->radius_ * 2);
     painter.fillRect(rect, QColor(data_->sqRed_,data_->sqGreen_,data_->sqBlue_));
    }
   }
  }
 }

 if(!data_->mTempPoint_.isNull())
 {
  QRect highlightEx(data_->mTempPoint_.rx() - (data_->radius_ + 3), data_->mTempPoint_.ry()- (data_->radius_ + 3),
                    (data_->radius_ + 3) * 2, (data_->radius_ + 3) * 2);
  painter.fillRect(highlightEx, Qt::gray);
  QRect highlightIn(data_->mTempPoint_.rx() - data_->radius_, data_->mTempPoint_.ry() - data_->radius_, data_->radius_ * 2, data_->radius_ * 2);
  painter.fillRect(highlightIn, QColor(data_->sqRed_, data_->sqGreen_, data_->sqBlue_));
  data_->mTempPoint_ = QPoint();
 }
}

void DHAX_Image_Scene_Item::mousePressEvent(QMouseEvent* mev)
{
// return;

 if(data_->pan_mode)
 {
  mev->ignore();
  return;
 }

 Mouse_Event_Modes mem = Mouse_Event_Modes::N_A;

 if(mev->button() == Qt::LeftButton) //  !data_->editing_ && !data_->shapeMoving_
 {
  if(data_->editing_)
    mem = Mouse_Event_Modes::Left_Edit;
  else if(data_->shapeMoving_)
    mem = Mouse_Event_Modes::Left_Move;
  else
    mem = Mouse_Event_Modes::Left_Init;
 }

 _handle_mouse_event(mev, mem);
}


void DHAX_Image_Scene_Item::mouseReleaseEvent(QMouseEvent* mev)
{
// return;

 if(data_->pan_mode)
 {
  mev->ignore();
  return;
 }

 Mouse_Event_Modes mem = Mouse_Event_Modes::N_A;

 if(mev->button() == Qt::LeftButton) //  !data_->editing_ && !data_->shapeMoving_
 {
  if(data_->isMoving_)
  {
   mem = Mouse_Event_Modes::Left_Move_Release;
  }
 }

 else if(mev->button() == Qt::RightButton)
 {
  Qt::MouseButtons mbs = mev->buttons();

  if( (data_->isMoving_) && (mbs & Qt::LeftButton))
  {
   mem = Mouse_Event_Modes::Right_Click_Temp_Release;
  }
  // //  any other possibilities?
  else
    mem = Mouse_Event_Modes::Right_Click_Iso;
 }

 _handle_mouse_event(mev, mem);

 return;

 if(mev->button() == Qt::RightButton && (data_->editing_ || data_->shapePosition_ != -1))
 {
  if(data_->editing_)
  {
   data_->isMoving_ = false;
   data_->editing_ = false; //fine
   onLineDraw(data_->allEdits_);
   data_->pointPosition_ = 0;
   data_->shapePosition_ = -1;
  }
  if(data_->shapePosition_ != -1)
  {
   data_->mEndPoint_ = mev->pos();
   data_->shapeMoving_ = false; //fine
   onLineDraw(data_->allEdits_);
   data_->mStartPoint_ = QPoint();
   data_->mEndPoint_ = QPoint();
   data_->shapePosition_ = -1;
  }
  update();
 }
}

void DHAX_Image_Scene_Item::mouseMoveEvent(QMouseEvent *mouseEvent)
{
// QGraphicsView* v = qobject_cast<QGraphicsView*>(parent());
// v->mouseMoveEvent(mouseEvent);

 if(data_->pan_mode)
 {
  mouseEvent->ignore();
  return;
 }

 if(data_->isMoving_ || data_->shapeMoving_)
 {

  // //  added polygon logic
  if(data_->point_pairs_.isEmpty())
  {
   data_->mEndPoint_ = mouseEvent->pos();
  }
  else
  {
   data_->point_pairs_.last().second = mouseEvent->pos();
  }

  update();
 }

 if(!data_->allEdits_.isEmpty() && !data_->isMoving_ && data_->checked_ && !data_->shapeMoving_)
 {
  for(int i=0; i < data_->allEdits_.size(); ++i)
  {
   for(int j=0; j < data_->allEdits_.at(i).shapePoints.size(); ++j)
   {
    if(mouseEvent->pos().x() >= data_->allEdits_[i].shapePoints[j].x() - data_->radius_ &&
       mouseEvent->pos().x() <= data_->allEdits_[i].shapePoints[j].x() + data_->radius_ &&
       mouseEvent->pos().y() >= data_->allEdits_[i].shapePoints[j].y() - data_->radius_ &&
       mouseEvent->pos().y() <= data_->allEdits_[i].shapePoints[j].y() + data_->radius_)
         data_->mTempPoint_ = data_->allEdits_.at(i).shapePoints.at(j);
    update();
   }
  }
 }

 if(data_->current_enabled_shape_kind()
      == DHAX_Display_Image_Data::Shape_Kinds::Ellipse
      && data_->points_.size() >= 3)
 {
  if(mouseEvent->pos().x() >= data_->points_.first().x() - data_->radius_ &&
     mouseEvent->pos().x() <= data_->points_.first().x() + data_->radius_ &&
     mouseEvent->pos().y() >= data_->points_.first().y() - data_->radius_ &&
     mouseEvent->pos().y() <= data_->points_.first().y() + data_->radius_)
  {
   data_->mTempPoint_ = data_->points_.first();
   update();
  }
 }
}

void DHAX_Image_Scene_Item::mouseDoubleClickEvent(QMouseEvent *mouseEvent)
{

 if(data_->pan_mode)
 {
  mouseEvent->ignore();
  return;
 }

 if(mouseEvent->button() == Qt::LeftButton)
 {
  if(data_->current_enabled_shape_kind()
       == DHAX_Display_Image_Data::Shape_Kinds::Non_Regular_Polygon
       && data_->points_.size() >= 3)
  {
   data_->isMoving_ = false;
   DHAX_Display_Image_Data::shape another;
   another.form = polygon;
   another.shapePoints = data_->points_;
   data_->allEdits_ << another;
   onLineDraw(data_->allEdits_);
   data_->mStartPoint_ = QPoint();
   data_->mEndPoint_ = QPoint();
   data_->points_.clear();
   update();
  }
 }
}

