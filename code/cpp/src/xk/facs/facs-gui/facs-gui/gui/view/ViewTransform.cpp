
// // license___here

#include "ViewTransform.h"

#include "ViewSettings.h"

#include "transformations/TransformationStack.h"

#include <QDebug>


// package facsanadu.gui.view;

//import com.trolltech.qt.core.QPointF;

// //

ViewTransform::ViewTransform()
 :  viewsettings_(nullptr)
{
 //How far the graph is pushed from the boundary (where labels are placed)
 graphOffsetXY_ = 30;
 
 //ViewSettings viewsettings_;
 internalHeight_ = 0;
 internalWidth_ = 0;
}

void ViewTransform::setTotalHeight(int h)
{
 internalHeight_ = h - graphOffsetXY_;
}
 
 /**
  * Set the total view width
  */
void ViewTransform::setTotalWidth(int w)
{
 internalWidth_ = w - graphOffsetXY_;
}

 /**
  * Get the total height of the view
  */
int ViewTransform::getTotalHeight()
{
 return graphOffsetXY_ + internalHeight_;
}
 
 /**
  * Set the total width of the view
  */
int ViewTransform::getTotalWidth()
{
 return graphOffsetXY_ + internalWidth_;
}
 
double ViewTransform::getTotalScaleX()
{
 return viewsettings_->scaleX() * internalWidth_; 
}

double ViewTransform::getTotalScaleY()
{
 return viewsettings_->scaleY() * internalHeight_; 
}

 /**
  * Map screen space to FCS value
  */
QPointF ViewTransform::mapScreenToFcs(const QPointF& pos)
{
 int h = internalHeight_ - 1;
 double x = (pos.x() - graphOffsetXY_) / getTotalScaleX();
 double y = (h - pos.y()) / getTotalScaleY();
 x = viewsettings_->transformation()->invert(x, viewsettings_->indexX() );
 y = viewsettings_->transformation()->invert(y, viewsettings_->indexY() );
 //QPointF p=new QPointF(x,y);
 return {x, y}; 
}

 /**
  * Map FCS value to screen space
  */
QPointF ViewTransform::mapFcsToScreen(const QPointF& pos)
{
//  int h=internalHeight-1;
 QPointF p {
     //  pos.x()*getTotalScaleX()+graphOffsetXY,
   (double) mapFcsToScreenX( (double) pos.x()), 
   (double) mapFcsToScreenY( (double) pos.y()) //h - pos.y()*getTotalScaleY()
 };
 return p;
}

int ViewTransform::mapFcsToScreenX(double x)
{
 x = viewsettings_->transformation()->perform(x, viewsettings_->indexX() );
   //?qDebug() << "do trans ... x = " << x << " , internalWidth_ = " << internalWidth_;

 //? return x;
 //? 
 int result = mapGeneralToScreenX(viewsettings_->scaleX() * x);
   //?qDebug() << "do trans ... x r = " << result;
 return result; 


// return mapGeneralToScreenX(viewsettings_->scaleX() * x);
}

int ViewTransform::mapFcsToScreenY(double y)
{
 y = viewsettings_->transformation()->perform(y, viewsettings_->indexY() );
  //?qDebug() << "do trans ... y = " << y  << " , internalHeight_ = " << internalHeight_;

 //?return y;
  //? 

   //? qDebug() << "vsy: " << viewsettings_->scaleY();
 
 int result = mapGeneralToScreenY(viewsettings_->scaleY() * y);
   //? qDebug() << "do trans ... y r = " << result;
 return result; 
}

 
int ViewTransform::mapGeneralToScreenX(double x)
{
 return graphOffsetXY_ + (int)(x * internalWidth_);
}

int ViewTransform::mapGeneralToScreenY(double y)
{
 int h = internalHeight_ - 1;
 return h - ((int)(y * h));
}


