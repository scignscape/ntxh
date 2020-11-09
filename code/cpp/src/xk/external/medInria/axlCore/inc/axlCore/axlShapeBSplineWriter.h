#ifndef AXLSURFACEBSPLINEWRITER_H
#define AXLSURFACEBSPLINEWRITER_H

#include <axlCore/axlAbstractDataWriter.h>
#include "axlCoreExport.h"

class AXLCORE_EXPORT axlShapeBSplineWriter : public axlAbstractDataWriter
{
    Q_OBJECT

public:
    axlShapeBSplineWriter();
    ~ axlShapeBSplineWriter();
public:
    QString identifier(void) const;
    QString description(void) const;
    QStringList handled(void) const;

    static bool registered(void);

public:
    bool accept(dtkAbstractData *data);
    bool reject(dtkAbstractData *data);

    QDomElement write(QDomDocument *doc, dtkAbstractData *data);

private :
    QDomElement elementByWriter(axlAbstractDataWriter *axl_writer, QDomDocument *doc, dtkAbstractData *data);
};

dtkAbstractDataWriter *createaxlShapeBSplineWriter(void);

#endif // AXLSURFACEBSPLINEWRITER_H
