#ifndef AXLSURFACEBSPLINEREADER_H
#define AXLSURFACEBSPLINEREADER_H

#include <axlCore/axlAbstractDataReader.h>
#include "axlCoreExport.h"

class AXLCORE_EXPORT axlShapeBSplineReader : public axlAbstractDataReader
{
    Q_OBJECT

public:
    axlShapeBSplineReader();
    ~axlShapeBSplineReader();

public:
    QString identifier(void) const;
    QString description(void) const;
    QStringList handled(void) const;

    static bool registered(void);

public:
    bool accept(const QDomNode& node);
    bool reject(const QDomNode& node);

    axlAbstractData *read(const QDomNode& node);
};

dtkAbstractDataReader *createaxlShapeBSplineReader(void);

#endif // AXLSURFACEBSPLINEREADER_H
