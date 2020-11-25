
// // license___here_h

#ifndef TransformationLinear__H
#define TransformationLinear__H

#include "Transformation.h"

#include "global-types.h"

#include "accessors.h"

// package facsanadu.transformations;

// // Transformation

class TransformationLinear : public Transformation 
{
 s4 shift1_;
 r8 skew_;
 s4 shift2_;
 

public:

 TransformationLinear(s4 s1 = 0, r8 sk = 1, s4 s2 = 0);


 ACCESSORS(s4 ,shift1)

 ACCESSORS(r8 ,skew)

 ACCESSORS(s4 ,shift2)


 void transform(QList<double>& v);
 void invert(QList<double>& v);

 void transform(QVector<double>& v);
 void invert(QVector<double>& v);

 double transform(double x, int index);
 double invert(double x, int index);
};

#endif //  TransformationLog__H


