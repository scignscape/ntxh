#ifndef axlShapeBSplineConverter_H
#define axlShapeBSplineConverter_H

#include "axlCoreExport.h"
#include <axlCore/axlAbstractDataConverter.h>

class AXLCORE_EXPORT axlShapeBSplineConverterPrivate;

class AXLCORE_EXPORT axlShapeBSplineConverter : public axlAbstractDataConverter
{
    Q_OBJECT

public:
    axlShapeBSplineConverter();
    ~axlShapeBSplineConverter();

    QString  description (void) const;
    QStringList fromTypes(void) const;
    QString       toType (void) const;

public:
    void setData(dtkAbstractData *data);
    dtkAbstractData *data(void) const;

    QList<QString> getLabels(int i);

public:
    static bool registered(void);

public slots:
    axlMesh *toMesh(void);

private :
    axlShapeBSplineConverterPrivate *d;

private :
    bool isContained(axlMesh *mesh);

private :
    int isInterior(int i, int n_u, int n_v);
    QPair<int,int > whatEdge(int numFace,int i, int n_u, int n_v);

    void insertEdge(axlMesh *mesh,int numEdge);
    void insertFace(axlMesh *mesh,int numFace);

    void createNewInteriorEdge(void);

};

dtkAbstractDataConverter *createaxlShapeBSplineConverter(void);

#endif // axlShapeBSplineConverter_H

