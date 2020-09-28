
// // license___here_h


#ifndef ViewToolDrawEllipse__H
#define ViewToolDrawEllipse__H


#include "ViewTool.h"

#include <QMouseEvent>

class FacsanaduEvent;

// package facsanadu.gui.view.tool;

class Gate;
class ViewWidget;

// // Tool to draw ellipse gates

class ViewToolDrawEllipse : public ViewTool
{
 Q_OBJECT

 Gate* isDrawing_;// = null;

 ViewWidget* vw_;

public:

 ViewToolDrawEllipse(ViewWidget* vw);

 /**
  * Mouse button released
  */
 void mouseReleaseEvent(QMouseEvent* ev) Q_DECL_OVERRIDE;

 void emitEvent(FacsanaduEvent* e);

 /**
  * Mouse moved
  */
 void mouseMoveEvent(QMouseEvent* event) Q_DECL_OVERRIDE;
 
 /**
  * Mouse button pressed
  */
 void mousePressEvent(QMouseEvent* event) Q_DECL_OVERRIDE;

 /**
  * Mouse button double-clicked
  */
 void mouseDoubleClickEvent(QMouseEvent* event) Q_DECL_OVERRIDE;

 bool allowHandle()  Q_DECL_OVERRIDE;

};

#endif // __H
 



