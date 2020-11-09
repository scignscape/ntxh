
//Author: Hung NGUYEN 9:17 AM 20/05/2014


#ifndef AXLSURFACEREVOLUTIONWRITER_H
#define AXLSURFACEREVOLUTIONWRITER_H

#include <axlCore/axlAbstractDataWriter.h>
#include "axlCoreExport.h"

class AXLCORE_EXPORT axlSurfaceRevolutionWriter : public axlAbstractDataWriter {
    Q_OBJECT

public:
    axlSurfaceRevolutionWriter(void);
    virtual ~axlSurfaceRevolutionWriter(void);

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

dtkAbstractDataWriter *createaxlSurfaceRevolutionWriter(void);

#endif // AXLSURFACEREVOLUTIONWRITER_H