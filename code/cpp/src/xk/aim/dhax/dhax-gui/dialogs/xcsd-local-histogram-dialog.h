
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef XCSD_LOCAL_HISTOGRAM_DIALOG__H
#define XCSD_LOCAL_HISTOGRAM_DIALOG__H



#include "xcsd-2d/xcsd-sdi-structures.h"

#include <QImage>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QVBoxLayout>

#include <QDialog>



#include "accessors.h"

//XCNS_(XCSD)

//class XCSD_XPixel;

#include "xcsd-2d/xcsd-sdi-structures.h"

#include "xcsd-2d/local-histogram-data.h"

#include <QGraphicsRectItem>


class XCSD_Local_Histogram_Dialog : public QDialog
{
 struct Rect_Item : QGraphicsRectItem {
   u2 color_code;
   u2 hue;
   Rect_Item(const QRect& rect, u2 h, QColor color);

   void hoverEnterEvent(QGraphicsSceneHoverEvent* event) Q_DECL_OVERRIDE;
   void hoverLeaveEvent(QGraphicsSceneHoverEvent* event) Q_DECL_OVERRIDE;


 };

 QMap<s2, Histogram_Group_Summary>* data_;

 u2 image_height_; // = 520;
 u2 max_bin_height_; //  = 200;
 u2 min_bin_height_; //  = 10;
 u2 bin_base_; //  = 260;
 u2 bin_width_; //  = 9;

 u2 max_group_height_; //  = 200;
 u2 min_group_height_; //  = 10;

 QVBoxLayout* main_layout_;
 QGraphicsScene* graphics_scene_;
 QGraphicsView* graphics_view_;


public:

 XCSD_Local_Histogram_Dialog(QWidget* parent,
   pr2 totals, //largest_group_total,
   QMap<s2, Histogram_Group_Summary>* data);

};


//_XCNS(XCSD)

#endif // XCSD_LOCAL_HISTOGRAM_DIALOG__H
