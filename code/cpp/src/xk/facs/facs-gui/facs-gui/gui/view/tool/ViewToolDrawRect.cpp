

// // license___here

// package facsanadu.gui.view.tool;

#include "ViewToolDrawRect.h"

ViewToolDrawRect::ViewToolDrawRect(ViewWidget* w)
{
 isDrawing_ = nullptr;
 vw_ = w;
}
 
void ViewToolDrawRect::mouseReleaseEvent(QMouseEvent* ev)
{
 Q_UNUSED(ev)
 /*
 isDrawing=null;
 w.sendEvent(new EventSetViewTool(ViewToolChoice.SELECT));
 emitEvent(new EventGatesChanged());
 */
}

void ViewToolDrawRect::emitEvent(FacsanaduEvent* e)
{
 Q_UNUSED(e)
 // w.mainWindow.handleEvent(e);
}
 
 /**
  * Mouse moved
  */
void ViewToolDrawRect::mouseMoveEvent(QMouseEvent* event)
{
 Q_UNUSED(event)
 /*
 if(isDrawing!=null)
 {
  GateRect grect=(GateRect)isDrawing;
 
  QPointF p = w.trans.mapScreenToFcs(event.posF()); 
 
  grect.x2=p.x();
  grect.y2=p.y();
  grect.updateInternal();
  emitEvent(new EventGatesMoved());
 }
 */
}

 
 /**
  * Mouse button pressed
  */
void ViewToolDrawRect::mousePressEvent(QMouseEvent* event)
{
 Q_UNUSED(event)
 /*
 if(event.button()==MouseButton.LeftButton && !w.viewsettings.isHistogram())
 {
  QPointF p = w.trans.mapScreenToFcs(event.posF()); 
 
  GateRect grect=new GateRect();
  grect.indexX=w.getIndexX();
  grect.indexY=w.getIndexY();
  grect.x1=grect.x2=p.x();
  grect.y1=grect.y2=p.y();
  grect.updateInternal();
  isDrawing=grect;

  w.addGate(grect);
  grect.setUniqueColor();
  w.sendEvent(new EventGatesMoved());
 }
 */
}

 /**
  * Mouse button double-clicked
  */
void ViewToolDrawRect::mouseDoubleClickEvent(QMouseEvent* event)
{
 Q_UNUSED(event)
}
 
 
bool ViewToolDrawRect::allowHandle()
{
 return isDrawing_ == nullptr;
}

