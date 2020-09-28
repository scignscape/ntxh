
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
public:

 int indexX, indexY;

 double x, y;

 double rx, ry;

 void updateInternal()
 {
  setUpdated();
 }
 
 bool classify(QList<double> obs)
 {
  double dx=(obs[indexX] - x) / rx;
  double dy=(obs[indexY] - y) / ry;
  return (dx*dx) + (dy*dy) <= 1;
 }

};

#endif // GateEllipse__H

