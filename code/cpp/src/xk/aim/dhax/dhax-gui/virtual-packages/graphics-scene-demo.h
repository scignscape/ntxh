
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef GRAPHICS_SCENE_DEMO__H
#define GRAPHICS_SCENE_DEMO__H


#include "global-types.h"

#include "accessors.h"

#include <QBrush>
#include <QPen>
#include <QColor>
#include <QPointF>
#include <QGraphicsProxyWidget>

class DHAX_Graphics_Scene;

#include "image-viewer/dhax-image-scene-item.h"


class Graphics_Scene_Demo
{
 DHAX_Graphics_Scene* scene_;
// QGraphicsProxyWidget* image_display_scene_item_;
 DHAX_Image_Scene_Item* image_display_scene_item_;

 QMap<u1, QPair<QGraphicsEllipseItem*, r8>> controls_;

public:

 Graphics_Scene_Demo();

 ACCESSORS(DHAX_Graphics_Scene* ,scene)
// ACCESSORS(QGraphicsProxyWidget* ,image_display_scene_item)
 ACCESSORS(DHAX_Image_Scene_Item* ,image_display_scene_item)

 void add_triple_dots(r8 x1, r8 y1, r8 x2, r8 y2, r8 x3, r8 y3);
 void draw_circle(const QPointF& center,
   r8 radius, QColor brush_color, QColor pen_color, u1 index);

 void draw_cubic_path();
 void draw_quad_path();

};


#endif //  GRAPHICS_SCENE_DEMO__H


