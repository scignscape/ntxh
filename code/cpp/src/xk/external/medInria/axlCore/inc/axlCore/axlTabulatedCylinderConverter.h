#ifndef AXL_TABULATED_CYLINDER_CONVERTER_H
#define AXL_TABULATED_CYLINDER_CONVERTER_H

#include "axlLine.h"
#include "axlPoint.h"
#include "axlCircleArc.h"
#include "axlAbstractCurveBSpline.h"
#include "axlTabulatedCylinder.h"
#include "axlSamplingCurve.h"
#include <axlCore/axlAbstractDataConverter.h> 

class axlTabulatedCylinderConverterPrivate;

class AXLCORE_EXPORT axlTabulatedCylinderConverter : public axlAbstractDataConverter
{
    Q_OBJECT
public:
	 axlTabulatedCylinderConverter(void);
	 ~axlTabulatedCylinderConverter(void);

	 QString  description (void) const;
     QString  identifier  (void) const;

     QStringList fromTypes(void) const;
     QString       toType (void) const;

	 static bool registered(void);
	 void setData(dtkAbstractData *data);
public slots:
    axlMesh *toMesh(void);

private:
    axlTabulatedCylinderConverterPrivate *d;
};

//===========================================================================================================================

/*
   The functions support to create Mesh
*/


//============================================================================================================================

dtkAbstractDataConverter *createaxlTabulatedCylinderConverter(void);

#endif