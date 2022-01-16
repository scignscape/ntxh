
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DHAX_GRAPHICS_SCENE__H
#define DHAX_GRAPHICS_SCENE__H

#include <QGraphicsScene>

#include <QDebug>

#include <QGraphicsProxyWidget>
#include <QGraphicsSceneMouseEvent>

class _Proxy_Widget : public QGraphicsProxyWidget
{
public:

 void mousePressEvent(QGraphicsSceneMouseEvent* mev) Q_DECL_OVERRIDE
 {
  qDebug() << "smev = " << mev;
  this->QGraphicsProxyWidget::mousePressEvent(mev);
 }

 void mouseMoveEvent(QGraphicsSceneMouseEvent* mev) Q_DECL_OVERRIDE
 {
  qDebug() << "mmev = " << mev;
  this->QGraphicsProxyWidget::mouseMoveEvent(mev);
 }

 void mouseReleaseEvent(QGraphicsSceneMouseEvent* mev) Q_DECL_OVERRIDE
 {
  qDebug() << "rmev = " << mev;
  this->QGraphicsProxyWidget::mouseReleaseEvent(mev);
 }

};


class DHAX_Graphics_Scene : public QGraphicsScene
{

public:

 DHAX_Graphics_Scene();

 _Proxy_Widget* add_proxy_widget(QWidget* w)
 {
  return (_Proxy_Widget*) addWidget(w);
 }

 void set_background_color(QColor c);

};

#endif //  DHAX_GRAPHICS_SCENE__H






