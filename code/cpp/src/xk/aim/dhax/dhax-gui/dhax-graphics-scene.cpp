
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include "dhax-graphics-scene.h"


DHAX_Graphics_Scene::DHAX_Graphics_Scene()
  :  QGraphicsScene()
{
// QRadialGradient gradient(50, 50, 800);
//       gradient.setColorAt(0.9, QColor::fromRgb(0, 150,140));
//       gradient.setColorAt(0.6, QColor::fromRgb(255, 0, 0));
//       gradient.setColorAt(0.2, QColor::fromRgb(0, 0, 0));
//       gradient.setColorAt(0, QColor::fromRgb(0, 200, 0));

 QBrush* brush = new QBrush(Qt::lightGray);
 setBackgroundBrush(*brush);
}
