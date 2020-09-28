

// // license___here

#include "ViewToolDrawPoly.h"


// package facsanadu.gui.view.tool;

ViewToolDrawPoly::ViewToolDrawPoly(ViewWidget* w)
{
 isDrawing_ = nullptr;

 vw_ = w;
}
 
 /**
* Mouse button pressed
*/
void ViewToolDrawPoly::mousePressEvent(QMouseEvent* event)
{
 Q_UNUSED(event)
/*
 if(event.button()==MouseButton.LeftButton && !w.viewsettings.isHistogram())
 {
  QPointF p = w.trans.mapScreenToFcs(event.posF()); 
 
  boolean justcreated=false;
  GatePolygon g;
  if(isDrawing_ != nullptr)
    g=isDrawing;
  else
  { 
   justcreated=true;
   g=new GatePolygon();
   g.indexX=w.getIndexX();
   g.indexY=w.getIndexY();
   isDrawing=g;
   w.addGate(g);
   g.setUniqueColor();
  }
  g.addPoint(p.x(), p.y());
  if(justcreated)
    g.addPoint(p.x(), p.y());
  g.updateInternal();
 
  w.sendEvent(new EventGatesMoved());
 }
*/
}

 /**
* Mouse button released
*/
void ViewToolDrawPoly::mouseReleaseEvent(QMouseEvent* ev)
{
 Q_UNUSED(ev)
// emitEvent(new EventGatesChanged());
}

void ViewToolDrawPoly::emitEvent(FacsanaduEvent* e)
{
 Q_UNUSED(e)
// w.mainWindow.handleEvent(e);
}

 /**
* Mouse moved
*/
void ViewToolDrawPoly::mouseMoveEvent(QMouseEvent* event)
{
 Q_UNUSED(event)
 /*
 if(isDrawing!=null)
 {
  GatePolygon g=isDrawing;
 
  QPointF p = w.trans.mapScreenToFcs(event.posF()); 

  g.setPoint(g.getNumPoints()-1, p.x(), p.y());
  g.updateInternal();
  emitEvent(new EventGatesMoved());
 }
 */
}


 /**
* Mouse button double-clicked
*/
void ViewToolDrawPoly::mouseDoubleClickEvent(QMouseEvent* event)
{
 Q_UNUSED(event)
/*
 if(isDrawing!=null)
 {
  isDrawing.removeRedundantPoints();
  isDrawing=null;
  w.sendEvent(new EventSetViewTool(ViewToolChoice.SELECT));
  emitEvent(new EventGatesChanged());
 }
*/
}


bool ViewToolDrawPoly::allowHandle()
{
 return isDrawing_ == nullptr;
}

