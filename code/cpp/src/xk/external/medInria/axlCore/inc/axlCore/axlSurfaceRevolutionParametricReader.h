//Author: Hung NGUYEN 9:17 AM 25/08/2014

#ifndef AXL_SURFACE_REVOLUTION_PARAMETRIC_READER_H
#define AXL_SURFACE_REVOLUTION_PARAMETRIC_READER_H

#include <axlCore/axlAbstractDataReader.h>
#include "axlCoreExport.h"

class AXLCORE_EXPORT axlSurfaceRevolutionParametricReader : public axlAbstractDataReader {
    Q_OBJECT

public:
    axlSurfaceRevolutionParametricReader(void);
    virtual ~axlSurfaceRevolutionParametricReader(void);

    QString identifier(void) const;
    QString description(void) const;
    QStringList handled(void) const;

    static bool registered(void);

    bool accept(const QDomNode& node);
    bool reject(const QDomNode& node);

    axlAbstractData *read(const QDomNode& node);
};

dtkAbstractDataReader *createaxlSurfaceRevolutionParametricReader(void);

#endif // AXL_SURFACE_REVOLUTION_PARAMETRIC_READER_H
