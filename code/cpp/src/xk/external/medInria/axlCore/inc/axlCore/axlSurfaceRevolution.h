//Author: Hung NGUYEN 9:17 AM 20/05/2014

#ifndef AXLSURFACEREVOLUTION_H
#define AXLSURFACEREVOLUTION_H

#include "axlCoreExport.h"
#include <axlCore/axlAbstractData.h>
#include <axlCore/axlAbstractCurve.h>
#include <axlCore/axlAbstractSurfaceParametric.h>
#include <axlCore/axlPoint.h>
#include <axlCore/axlLine.h>

#include <QtCore>

class axlSurfaceRevolutionPrivate;

class AXLCORE_EXPORT axlSurfaceRevolution : public axlAbstractSurface
{

Q_OBJECT



public:

axlSurfaceRevolution(QObject *parent = 0);

axlSurfaceRevolution(axlLine *axe,QList<axlAbstractCurve *> curves,double theta1, double theta2, QObject *parent = 0);

 ~axlSurfaceRevolution();



virtual QString description(void) const;

virtual QString identifier(void) const;



axlLine *getAxe();

QList<axlAbstractCurve *> getCurves();

double getStartAngle();

double getEndAngle();

int countCurve();

axlAbstractCurve *getCurve(int id);





void setAxe(axlLine *line);

void setAxe(axlPoint *point1, axlPoint *point2);

void setCurves(QList<axlAbstractCurve *> curves);

void setStartAngle(double ang);

void setEndAngle(double ang);

void setAngle(double startAngle,double endAngle);





axlSurfaceRevolution& operator =(const axlSurfaceRevolution& other);





private:

axlSurfaceRevolutionPrivate *d;

};



//to be registered to the data factory.

dtkAbstractData *createaxlSurfaceRevolution(void);



#endif
