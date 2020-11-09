//Author: Hung NGUYEN 9:17 AM 20/05/2014


#ifndef AXLSURFACEREVOLUTIONCONVERTER_H
#define AXLSURFACEREVOLUTIONCONVERTER_H

#include <axlCore/axlAbstractDataConverter.h>
#include "axlPoint.h"
#include "axlLine.h"
#include "axlCircleArc.h"
#include "axlAbstractCurveBSpline.h"

class axlSurfaceRevolutionConverterPrivate;


class AXLCORE_EXPORT axlSurfaceRevolutionConverter : public axlAbstractDataConverter
{
    Q_OBJECT
public:
     axlSurfaceRevolutionConverter(void);
    ~axlSurfaceRevolutionConverter(void);

    QString  description (void) const;
    QString  identifier  (void) const;

    QStringList fromTypes(void) const;
    QString       toType (void) const;

public:
    static bool registered(void);

public slots:
    axlMesh *toMesh(void);

public:
    void setData(dtkAbstractData *data);

private:
    axlSurfaceRevolutionConverterPrivate *d;
	double angle(axlPoint vCompute, axlPoint vRef, axlPoint normal);
	double angleOfArc(const axlCircleArc *arc);
	axlPoint normalCCWArc(const axlCircleArc& arc);
	axlPoint *rotatePoint(double a, double b, double c, double x, double y,double z, double u, double v, double w, double alpha);
	axlPoint* RotatePoint(axlPoint a,axlPoint x,axlPoint u, double alpha);
	axlPoint* RotatePoint(axlLine *line,axlPoint *x, double alpha);
	QList<axlPoint *> Sampling(axlAbstractCurve *curve);

};

dtkAbstractDataConverter *createaxlSurfaceRevolutionConverter(void);


#endif