// package facsanadu.gui.view.gate;


#include "GateRendererEllipse.h"

#include "GateHandle.h"

#include <QPointF>

#include <QtMath>

#include "../gates/GateEllipse.h"

#include "../ViewSettings.h"
#include "../ViewTransform.h"

#include "../transformations/TransformationStack.h"


/*
    public void move2(MainWindow w, double dx, double dy)
     {
     if(viewsettings.indexX==cg.indexX)
      cg.x=dx;
     else if(viewsettings.indexY==cg.indexX)
      cg.y=dx;
     
     if(viewsettings.indexX==cg.indexY)
      cg.x=dy;
     else if(viewsettings.indexY==cg.indexY)
      cg.y=dy;
     
     gate.updateInternal();
     w.handleEvent(new EventGatesMoved());
     }

    public double getX()
     {
     return pHm.x();
     }

    public double getY()
     {
     return pHm.y();
     }
    });
*/


class GateHandle_Mid : public GateHandle
{
 QPointF pHm;

public:


 GateHandle_Mid(QPointF p) : pHm(p) {}

 void move2(MainWindow* w, double dx, double dy) Q_DECL_OVERRIDE;
 /*  {
   if(viewsettings->indexX()==cg->indexX)
   cg->x1=dx;
   else if(viewsettings->indexY()==cg->indexX)
   cg->y1=dx;
   
   if(viewsettings->indexX()==cg->indexY)
   cg->x1=dy;
   else if(viewsettings->indexY()==cg->indexY)
   cg->y1=dy;
   
   gate->updateInternal();
   w.handleEvent(new EventGatesMoved());
   }
  */
 
 double getX() Q_DECL_OVERRIDE
 {
  return pHm.x();//x[0];
 }

 double getY() Q_DECL_OVERRIDE
 {
  return pHm.y();//y[0];
 }
};

void GateHandle_Mid::move2(MainWindow* w, double dx, double dy)
{
 Q_UNUSED(w)
 Q_UNUSED(dx)
 Q_UNUSED(dy)
}



/*
    public void move2(MainWindow w, double dx, double dy)
     {
     if(viewsettings.indexX==cg.indexX)
      cg.rx=Math.abs(dx-cg.x);
     else if(viewsettings.indexY==cg.indexX)
      cg.ry=Math.abs(dx-cg.x);
     gate.updateInternal();
     w.handleEvent(new EventGatesMoved());
     }

    public double getX()
     {
     return pHx.x();
     }
    public double getY()
     {
     return pHx.y();
     }
*/

//class EllipseGate;

 // // Right
class GateHandle_R : public GateHandle
{
  QPointF pHx;

public:


 GateHandle_R(QPointF p) : pHx(p) {}

 void move2(MainWindow* w, double dx, double dy) Q_DECL_OVERRIDE;
 /*  public void move2(MainWindow w, double dx, double dy)
   {
   if(viewsettings->indexX()==cg->indexX)
     cg->x2=dx;
   else if(viewsettings->indexY()==cg->indexX)
     cg->y2=dx;
   
   if(viewsettings->indexX()==cg->indexY)
     cg->x2=dy;
   else if(viewsettings->indexY()==cg->indexY)
     cg->y2=dy;
   
   gate->updateInternal();
   w.handleEvent(new EventGatesMoved());
   }
 */

 double getX() Q_DECL_OVERRIDE
 {
  return pHx.x();
 }

 double getY() Q_DECL_OVERRIDE
 {
  return pHx.y();
 }
};

void GateHandle_R::move2(MainWindow* w, double dx, double dy)
{
 Q_UNUSED(w)
 Q_UNUSED(dx)
 Q_UNUSED(dy)
}



 // // Bottom
class GateHandle_B : public GateHandle
{
  QPointF pHy;

public:


 GateHandle_B(QPointF p) : pHy(p) {}

 void move2(MainWindow* w, double dx, double dy) Q_DECL_OVERRIDE;
 /*  public void move2(MainWindow w, double dx, double dy)
   {
   if(viewsettings->indexX()==cg->indexX)
     cg->x2=dx;
   else if(viewsettings->indexY()==cg->indexX)
     cg->y2=dx;
   
   if(viewsettings->indexX()==cg->indexY)
     cg->x2=dy;
   else if(viewsettings->indexY()==cg->indexY)
     cg->y2=dy;
   
   gate->updateInternal();
   w.handleEvent(new EventGatesMoved());
   }
 */

 double getX() Q_DECL_OVERRIDE
 {
  return pHy.x();
 }

 double getY() Q_DECL_OVERRIDE
 {
  return pHy.y();
 }
};

void GateHandle_B::move2(MainWindow* w, double dx, double dy)
{
 Q_UNUSED(w)
 Q_UNUSED(dx)
 Q_UNUSED(dy)
}



void GateRendererEllipse::render(const Gate* gate, QPainter& p, ViewTransform* w, 
   const ViewSettings* viewsettings, QList<GateHandle*> handles)
{
 const GateEllipse* cg = (GateEllipse*) gate;
 
 if(viewsettings->coversXandY( cg->indexX, cg->indexY ))
 {
  //Figure out which dimension is what
  QList<double> x {0, 0};
  QList<double> y {0, 0};

  if(viewsettings->indexX() == cg->indexX)
  {
   x[0] = cg->x;
   x[1] = cg->rx;
  }
  if(viewsettings->indexY() == cg->indexX)
  {
   y[0] = cg->x;
   y[1] = cg->rx;
  }
  
  if(viewsettings->indexX()==cg->indexY)
  {
   x[0] = cg->y;
   x[1] = cg->ry;
  }
  if(viewsettings->indexY()==cg->indexY)
  {
   y[0] = cg->y;
   y[1] = cg->ry;
  }

  QPointF pHm = w->mapFcsToScreen( QPointF(x[0], y[0]) );
  QPointF pHx = w->mapFcsToScreen( QPointF(x[0] + x[1], y[0]) );
  QPointF pHy = w->mapFcsToScreen( QPointF(x[0], y[0] + y[1]) );

  QPointF p1 = w->mapFcsToScreen( QPointF(x[0] - x[1], y[0] - y[1]) );
  QPointF p2 = w->mapFcsToScreen( QPointF(x[0] + x[1], y[0] + y[1]) );

  if(!viewsettings->transformation()->isEmpty())
  {
    //  //  why does transformation preclude an ellipse?
   QVector<QPointF> points;
   int ns=64;
   for(int i=0; i<ns; i++)
   {
    qreal alpha = (2 * M_PI) * (i / ns);
    QPointF pv = w->mapFcsToScreen(QPointF(x[0] + (qCos(alpha) * x[1]),
      y[0] + (qSin(alpha) * y[1]) ) );
    points.push_back(pv);
   }
 
   QPolygonF poly(points); //=new QPolygonF
   
   p.drawPolygon(poly);
  }
  else
  {
   p.drawEllipse(QRectF(p1, p2));
  }
  p.drawText(p1, gate->name());

  //Mid handle
  handles.append(new GateHandle_Mid(pHm));

  //Lower right
  handles.append(new GateHandle_R(pHx));

  //Bottom
  handles.append(new GateHandle_B(pHy));
 }
}

/*
  final GateEllipse cg=(GateEllipse)gate;
  if(viewsettings.coversXandY(cg.indexX, cg.indexY))
   {
   //Figure out which dimension is what
   final double x[]=new double[]{0,0};
   final double y[]=new double[]{0,0};
   if(viewsettings.indexX==cg.indexX)
    {
    x[0]=cg.x;
    x[1]=cg.rx;
    }
   if(viewsettings.indexY==cg.indexX)
    {
    y[0]=cg.x;
    y[1]=cg.rx;
    }
   
   if(viewsettings.indexX==cg.indexY)
    {
    x[0]=cg.y;
    x[1]=cg.ry;
    }
   if(viewsettings.indexY==cg.indexY)
    {
    y[0]=cg.y;
    y[1]=cg.ry;
    }


   final QPointF pHm=w.mapFcsToScreen(new QPointF(x[0],     y[0]));
   final QPointF pHx=w.mapFcsToScreen(new QPointF(x[0]+x[1],y[0]));
   final QPointF pHy=w.mapFcsToScreen(new QPointF(x[0],     y[0]+y[1]));

   
   final QPointF p1=w.mapFcsToScreen(new QPointF(x[0]-x[1],y[0]-y[1]));
   final QPointF p2=w.mapFcsToScreen(new QPointF(x[0]+x[1],y[0]+y[1]));
   if(!viewsettings.transformation.isEmpty())
    {
    QPolygonF poly=new QPolygonF();
    int ns=64;
    for(int i=0;i<ns;i++)
     {
     double alpha=2*Math.PI*i/ns;
     QPointF pv=w.mapFcsToScreen(new QPointF(x[0]+Math.cos(alpha)*x[1],y[0]+Math.sin(alpha)*y[1]));
     poly.add(pv);
     }
    
    p.drawPolygon(poly);
    }
   else
    {
    p.drawEllipse(new QRectF(p1,p2));
    }
   p.drawText(p1, gate.name);

   //Mid handle
   handles.add(new GateHandle()
    {
    public void move2(MainWindow w, double dx, double dy)
     {
     if(viewsettings.indexX==cg.indexX)
      cg.x=dx;
     else if(viewsettings.indexY==cg.indexX)
      cg.y=dx;
     
     if(viewsettings.indexX==cg.indexY)
      cg.x=dy;
     else if(viewsettings.indexY==cg.indexY)
      cg.y=dy;
     
     gate.updateInternal();
     w.handleEvent(new EventGatesMoved());
     }

    public double getX()
     {
     return pHm.x();
     }

    public double getY()
     {
     return pHm.y();
     }
    });

   //Right
   handles.add(new GateHandle()
    {
    public void move2(MainWindow w, double dx, double dy)
     {
     if(viewsettings.indexX==cg.indexX)
      cg.rx=Math.abs(dx-cg.x);
     else if(viewsettings.indexY==cg.indexX)
      cg.ry=Math.abs(dx-cg.x);
     gate.updateInternal();
     w.handleEvent(new EventGatesMoved());
     }

    public double getX()
     {
     return pHx.x();
     }
    public double getY()
     {
     return pHx.y();
     }
    });
   

   //Bottom
   handles.add(new GateHandle()
    {
    public void move2(MainWindow w, double dx, double dy)
     {
     if(viewsettings.indexX==cg.indexY)
      cg.rx=Math.abs(dy-cg.x);
     else if(viewsettings.indexY==cg.indexY)
      cg.ry=Math.abs(dy-cg.y);
     
     gate.updateInternal();
     w.handleEvent(new EventGatesMoved());
     }

    public double getX()
     {
     return pHy.x();
     }
    public double getY()
     {
     return pHy.y();
     }
    });

   
   }
  }
*/
//}
