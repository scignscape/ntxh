

// // license___here

// package facsanadu.gui.view.tool;

#include "ViewToolDrawSelect.h"


ViewToolDrawSelect::ViewToolDrawSelect(ViewWidget* w)
{
 vw_ = w;
}
 
 /**
* Mouse button released
*/
void ViewToolDrawSelect::mouseReleaseEvent(QMouseEvent* ev)
{
 Q_UNUSED(ev)
}

 /**
* Mouse moved
*/
void ViewToolDrawSelect::mouseMoveEvent(QMouseEvent* event)
{
 Q_UNUSED(event)
}

 
 /**
* Mouse button pressed
*/
void ViewToolDrawSelect::mousePressEvent(QMouseEvent* event)
{
 Q_UNUSED(event)
}

 /**
* Mouse button double-clicked
*/
void ViewToolDrawSelect::mouseDoubleClickEvent(QMouseEvent* event)
{
 Q_UNUSED(event)
}
 
bool ViewToolDrawSelect::allowHandle()
{
 return true;
}

