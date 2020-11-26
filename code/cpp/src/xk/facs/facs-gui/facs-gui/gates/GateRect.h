
// // license___here_h


#ifndef GateRect__H
#define GateRect__H

#include "gate-info.h"

#include "accessors.h"


#include <QtGlobal>

class QRectF;

// package facsanadu.gates;

// author Johan Henriksson

class GateRect : public Gate
{
 int indexX_;
 int indexY_;

 double x1_;
 double x2_;

 double y1_;
 double y2_;

 double ix1_;
 double ix2_;

 double iy1_;
 double iy2_;

 QRectF* force_;


public:

 GateRect(QRectF* force = nullptr);

 ACCESSORS(int ,indexX)
 ACCESSORS(int ,indexY)

 ACCESSORS(double ,x1)
 ACCESSORS(double ,x2)

 ACCESSORS(double ,y1)
 ACCESSORS(double ,y2)

 ACCESSORS(double ,ix1)
 ACCESSORS(double ,ix2)

 ACCESSORS(double ,iy1)
 ACCESSORS(double ,iy2)

 ACCESSORS(QRectF* ,force)


 void updateInternal()
 {
  ix1_ = qMin(x1_, x2_);
  iy1_ = qMin(y1_, y2_);
  
  ix2_ = qMax(x1_, x2_);
  iy2_ = qMax(y1_, y2_);
  setUpdated();
 }
 
 bool classify(QList<double>& obs)
 {
  return
    obs[indexX_] >= ix1_ && obs[indexX_] <= ix2_ &&
    obs[indexY_] >= iy1_ && obs[indexY_] <= iy2_;
 }

 bool classify(QVector<double>& obs)
 {
  return
    obs[indexX_] >= ix1_ && obs[indexX_] <= ix2_ &&
    obs[indexY_] >= iy1_ && obs[indexY_] <= iy2_;
 }

 QString class_name() const
 {
  return "GateRect";
 }

};

#endif // __H

