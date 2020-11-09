//Author: Hung NGUYEN 9:17 AM 25/08/2014





#ifndef AXLSURFACEREVOLUTIONPARAMETRIC_H

#define AXLSURFACEREVOLUTIONPARAMETRIC_H





#include "axlCoreExport.h"

#include <axlCore/axlAbstractData.h>

#include <axlCore/axlAbstractCurve.h>
#include <axlCore/axlAbstractSurfaceParametric.h>
#include <axlCore/axlPoint.h>

#include <axlCore/axlLine.h>



#include <QtCore>





class axlSurfaceRevolutionParametricPrivate;


class AXLCORE_EXPORT axlSurfaceRevolutionParametric : public axlAbstractSurfaceParametric
{

Q_OBJECT



public:

axlSurfaceRevolutionParametric(QObject *parent = 0);

axlSurfaceRevolutionParametric(axlLine *axe,axlAbstractCurve *curve,double theta1, double theta2, QObject *parent = 0);

 ~axlSurfaceRevolutionParametric();



virtual QString description(void) const;

virtual QString identifier(void) const;



axlLine *getAxe();

axlAbstractCurve *getCurve();

double getStartAngle();

double getEndAngle();




void setAxe(axlLine *line);

void setAxe(axlPoint *point1, axlPoint *point2);

void setCurve(axlAbstractCurve *curve);

void setStartAngle(double ang);

void setEndAngle(double ang);

void setAngle(double startAngle,double endAngle);




axlSurfaceRevolutionParametric& operator =(const axlSurfaceRevolutionParametric& other);





private:

axlSurfaceRevolutionParametricPrivate *d;



};



//to be registered to the data factory.

dtkAbstractData *createaxlSurfaceRevolutionParametric(void);



#endif
