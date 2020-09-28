
// // license___here

#include "ViewToolDrawEllipse.h"


// package facsanadu.gui.view.tool;


/**
 * 
 * Tool to draw ellipse gates
 * 
 * @author Johan Henriksson
 *
 */

ViewToolDrawEllipse::ViewToolDrawEllipse(ViewWidget* w)
{
 isDrawing_ = nullptr;

 vw_ = w;
}
 
 /**
  * Mouse button released
  */
void ViewToolDrawEllipse::mouseReleaseEvent(QMouseEvent* ev)
{
 Q_UNUSED(ev)
/*
 isDrawing=null;
 emitEvent(new EventGatesChanged());
 w.sendEvent(new EventSetViewTool(ViewToolChoice.SELECT));
*/
}

void ViewToolDrawEllipse::emitEvent(FacsanaduEvent* e)
{
 Q_UNUSED(e)
 // w.mainWindow.handleEvent(e);
}

 /**
  * Mouse moved
  */
void ViewToolDrawEllipse::mouseMoveEvent(QMouseEvent* event)
{
 Q_UNUSED(event)
/*
 if(isDrawing!=null)
 {
  GateEllipse grect=(GateEllipse)isDrawing;
   
  QPointF p = w.trans.mapScreenToFcs(event.posF()); 
   
  grect.rx=p.x()-grect.x;
  grect.ry=p.y()-grect.y;
  grect.updateInternal();
  w.sendEvent(new EventGatesMoved());
 }
*/
}

 
 /**
  * Mouse button pressed
  */
void ViewToolDrawEllipse::mousePressEvent(QMouseEvent* event)
{
 Q_UNUSED(event)
/*
 if(event.button()==MouseButton.LeftButton && !w.viewsettings.isHistogram())
 {
  QPointF p = w.trans.mapScreenToFcs(event.posF()); 
   
  GateEllipse grect=new GateEllipse();
  grect.indexX=w.getIndexX();
  grect.indexY=w.getIndexY();
  grect.x=p.x();
  grect.y=p.y();
  grect.updateInternal();
  isDrawing=grect;

  w.addGate(grect);
  grect.setUniqueColor();
  emitEvent(new EventGatesMoved());
 }
*/  
}

 /**
  * Mouse button double-clicked
  */
void ViewToolDrawEllipse::mouseDoubleClickEvent(QMouseEvent* event)
{
 Q_UNUSED(event)
}
 
 
bool ViewToolDrawEllipse::allowHandle()
{
 return isDrawing_ == nullptr;
}


