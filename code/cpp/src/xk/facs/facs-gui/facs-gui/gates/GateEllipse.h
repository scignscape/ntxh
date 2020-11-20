
// // license___here_h


#ifndef GateEllipse__H
#define GateEllipse__H

#include "gate-info.h"

#include <QtGlobal>

// package facsanadu.gates;

/**
 * 
 * Rectangular gate
 * 
 * @author Johan Henriksson
 *
 */
class GateEllipse : Gate
{
 int indexX_;
 int indexY_;

 double x_;
 double y_;

 double rx_;
 double ry_;


public:

 GateEllipse();

 ACCESSORS(int ,indexX)
 ACCESSORS(int ,indexY)

 ACCESSORS(double ,x)
 ACCESSORS(double ,y)

 ACCESSORS(double ,rx)
 ACCESSORS(double ,ry)

 void updateInternal()
 {
  setUpdated();
 }
 
 bool classify(QList<double> obs)
 {
  double dx = (obs[indexX_] - x_) / rx_;
  double dy = (obs[indexY_] - y_) / ry_;
  return (dx*dx) + (dy*dy) <= 1;
 }

};

#endif // GateEllipse__H

