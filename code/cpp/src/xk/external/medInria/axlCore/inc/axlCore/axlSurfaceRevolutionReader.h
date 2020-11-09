//Author: Hung NGUYEN 9:17 AM 20/05/2014

#ifndef AXLSURFACEREVOLUTIONREADER_H
#define AXLSURFACEREVOLUTIONREADER_H

#include <axlCore/axlAbstractDataReader.h>
#include "axlCoreExport.h"

class AXLCORE_EXPORT axlSurfaceRevolutionReader : public axlAbstractDataReader {
    Q_OBJECT

public:
    axlSurfaceRevolutionReader(void);
    virtual ~axlSurfaceRevolutionReader(void);

    QString identifier(void) const;
    QString description(void) const;
    QStringList handled(void) const;

    static bool registered(void);

    bool accept(const QDomNode& node);
    bool reject(const QDomNode& node);

    axlAbstractData *read(const QDomNode& node);
};

dtkAbstractDataReader *createaxlSurfaceRevolutionReader(void);

#endif // AXLSURFACEREVOLUTIONREADER_H
