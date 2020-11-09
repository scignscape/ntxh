#ifndef AXLCURVEONPARAMSURFACE_CONVERTER_H
#define AXLCURVEONPARAMSURFACE_CONVERTER_H

#include <axlCore/axlAbstractDataConverter.h> 

class axlCurveOnParamSurfaceConverterPrivate;

class AXLCORE_EXPORT axlCurveOnParamSurfaceConverter : public axlAbstractDataConverter
{
    Q_OBJECT
public:
	 axlCurveOnParamSurfaceConverter(void);
	 ~axlCurveOnParamSurfaceConverter(void);

	 QString  description (void) const;
     QString  identifier  (void) const;

     QStringList fromTypes(void) const;
     QString       toType (void) const;

	 static bool registered(void);
	 void setData(dtkAbstractData *data);
public slots:
    axlMesh *toMesh(void);

private:
    axlCurveOnParamSurfaceConverterPrivate *d;
};

dtkAbstractDataConverter *createaxlCurveOnParamSurfaceConverter(void);
#endif //AXLCURVEONPARAMSURFACE_CONVERTER_H