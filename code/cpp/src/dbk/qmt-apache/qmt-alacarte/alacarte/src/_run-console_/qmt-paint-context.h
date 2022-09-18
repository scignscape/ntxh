
#ifndef QMT_PAINT_CONTEXT__H
#define QMT_PAINT_CONTEXT__H

#include <QString>

#include <string>

#include "qmt-accessors.h"

#include "qmt-global-types.h"

#include <QPainter>

class QMT_Paint_Context
{
 QImage* base_image_;

public:

 QMT_Paint_Context(QImage* image);


 QLine make_vline(const QPoint& center, u2 half_height);
 QLine make_hline(const QPoint& center, u2 half_width);
 QRect make_rectangle_from_center(const QPoint& center, u2 width, u2 height);
 QRect make_square_from_center(const QPoint& center, u2 half_side);
 void center_transpose(QRect& rect);

 void draw_gappy_rectangle(QPainter& painter, const QRect& rect, u2 gap);
 void draw_gappy_rectangle_as_octagon(QPainter& painter, const QRect& rect, u2 gap);

};


#endif // QMT_PAINTER__H
