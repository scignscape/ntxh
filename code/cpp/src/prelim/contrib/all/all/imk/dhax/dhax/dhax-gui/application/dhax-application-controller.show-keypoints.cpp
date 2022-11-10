
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifdef USE_OpenCV


#include "dhax-application-controller.h"

#include "main-window/dhax-main-window-controller.h"

#include "dhax-graphics-scene.h"
#include "dhax-graphics-frame.h"
#include "image-viewer/dhax-image-scene-item.h"

#include <QGraphicsRectItem>

#include <QMenu>
#include <QAction>


struct KeyPoint_Graphics_Item : QGraphicsRectItem
{
 cv::KeyPoint keypoint;

 QBrush hover_brush_;
 QBrush normal_brush_;

 KeyPoint_Graphics_Item(QRect rect, QBrush qbr, QBrush hqbr, cv::KeyPoint& kp, QPen pen = Qt::NoPen)
   :  QGraphicsRectItem(rect), keypoint(kp), normal_brush_(qbr), hover_brush_(hqbr)
 {
  setBrush(qbr);
  setPen(pen);

  setAcceptHoverEvents(true);
 }

 void hoverEnterEvent(QGraphicsSceneHoverEvent* event) Q_DECL_OVERRIDE;
 void hoverLeaveEvent(QGraphicsSceneHoverEvent* event) Q_DECL_OVERRIDE;
 void contextMenuEvent(QGraphicsSceneContextMenuEvent* event)  Q_DECL_OVERRIDE;

};


void KeyPoint_Graphics_Item::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    QMenu* menu = new QMenu;
    menu->addAction("Action 1");
    menu->addAction("Action 2");
    QAction* a = menu->exec(event->screenPos());
    qDebug("User clicked %s", qPrintable(a->text()));
}


void KeyPoint_Graphics_Item::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
 setBrush(hover_brush_);
 update();
}

void KeyPoint_Graphics_Item::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
 setBrush(normal_brush_);
 update();
}


void DHAX_Application_Controller::show_keypoints(std::shared_ptr<QMap<QString, std::shared_ptr<DHAX_Stat_Assessment>>>
  transforms_map,
  QString file_path, std::vector<cv::KeyPoint>& keypoints)
{
 load_image(file_path);

 DHAX_Graphics_Scene& scene = *graphics_frame_->graphics_scene();
 DHAX_Image_Scene_Item* dsi = main_window_controller_->image_scene_item();

 dsi->set_current_transforms_map(transforms_map);
 //scene.cur

 QColor color = Qt::cyan;
 QBrush qbr(color);

 QColor hcolor = Qt::white;
 QBrush hqbr(hcolor);


 u1 radius = 3, rx2 = radius * 2;
 for(cv::KeyPoint kp : keypoints)
 {
 // QGraphicsScene*
  u2 x = kp.pt.x, y = kp.pt.y;

  //QGraphicsRectItem*
  //qgri =
  scene.addRect(x - radius, y - radius, rx2, rx2, Qt::NoPen, qbr);

  KeyPoint_Graphics_Item* kpgi = new KeyPoint_Graphics_Item(QRect(x - radius, y - radius,
    rx2, rx2), qbr, hqbr, kp);

  scene.addItem(kpgi);



 }
}
#endif
