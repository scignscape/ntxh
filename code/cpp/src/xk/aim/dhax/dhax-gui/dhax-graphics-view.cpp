
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#include "dhax-graphics-view.h"

#include <QDebug>

#include <QGuiApplication>



DHAX_Graphics_View::DHAX_Graphics_View(QWidget* parent)
  :  QGraphicsView(parent)
{
 mouse_keyboard_data_.set_containing_metaobject(this->metaObject());
}


void DHAX_Graphics_View::mouseReleaseEvent(QMouseEvent* mouseEvent)
{
 Qt::KeyboardModifiers ks = QGuiApplication::keyboardModifiers();
 Qt::MouseButtons bs = mouseEvent->buttons();
 mouse_keyboard_data_.check_update(bs, ks, mouse_keyboard_modifiers_callback_);

}


void DHAX_Graphics_View::mouseMoveEvent(QMouseEvent* mouseEvent)
{
 Qt::KeyboardModifiers ks = QGuiApplication::keyboardModifiers();
 Qt::MouseButtons bs = mouseEvent->buttons();
 mouse_keyboard_data_.check_update(bs, ks, mouse_keyboard_modifiers_callback_);

// if(ks != Qt::NoModifier)
// {
//   mouse_move_modifiers_callback_(this->metaObject(), ks);
// }

 //this->metaObject();


// static int count = 0;

// qDebug() << " ... " << ++count;
}

