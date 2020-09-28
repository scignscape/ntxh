

// // license___here

// package facsanadu.gui.view.tool;

#include "ViewToolDrawRange.h"

ViewToolDrawRange::ViewToolDrawRange(ViewWidget* w)
{
 isDrawing_ = nullptr;
 vw_ = w;
}

 // //Mouse button released
void ViewToolDrawRange::mouseReleaseEvent(QMouseEvent* ev)
{
 Q_UNUSED(ev)
/*
 isDrawing=null;
 w.sendEvent(new EventSetViewTool(ViewToolChoice.SELECT));
 emitEvent(new EventGatesChanged());
*/
}
 
void ViewToolDrawRange::emitEvent(FacsanaduEvent* e)
{
 Q_UNUSED(e)
// w.mainWindow.handleEvent(e);

}

 /**
  * Mouse moved
  */
void ViewToolDrawRange::mouseMoveEvent(QMouseEvent* event)
{
 Q_UNUSED(event)
/*
 if(isDrawing!=null)
 {
  GateRange grect=(GateRange)isDrawing;
  
  QPointF p = w.trans.mapScreenToFcs(event.posF()); 
  
  grect.x2=p.x();
  grect.updateInternal();
  w.sendEvent(new EventGatesMoved());
 }
*/
}
 
 /**
  * Mouse button pressed
  */
void ViewToolDrawRange::mousePressEvent(QMouseEvent* event)
{
 Q_UNUSED(event)
/*
 if(event.button()==MouseButton.LeftButton)
 {
  QPointF p = w.trans.mapScreenToFcs(event.posF()); 
  
  GateRange grect=new GateRange();
  grect.index=w.getIndexX();
  grect.x1=grect.x2=p.x();
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
void ViewToolDrawRange::mouseDoubleClickEvent(QMouseEvent* event)
{
 Q_UNUSED(event)
}
 
// @Override
bool ViewToolDrawRange::allowHandle()
{
 return isDrawing_ == nullptr;
}


