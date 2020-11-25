
// // license___here_h

#ifndef TransformationLog__H
#define TransformationLog__H

#include "Transformation.h"

#include "global-types.h"

// package facsanadu.transformations;

// // Transformation

class TransformationLog : public Transformation 
{
 r8 log0_default_; 

public:

 TransformationLog(r8 log0_default = 0);

 void transform(QList<double>& v);
 void invert(QList<double>& v);

 void transform(QVector<double>& v);
 void invert(QVector<double>& v);

 double transform(double x, int index);
 double invert(double x, int index);
};

#endif //  TransformationLog__H


