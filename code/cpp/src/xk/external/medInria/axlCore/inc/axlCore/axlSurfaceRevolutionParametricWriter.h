
/* @author: Hung NGUYEN 9:17 AM 20/05/2014 */


#ifndef AXL_SURFACE_REVOLUTION_PARAMETRIC_WRITER_H
#define AXL_SURFACE_REVOLUTION_PARAMETRIC_WRITER_H

#include <axlCore/axlAbstractDataWriter.h>
#include "axlCoreExport.h"

class AXLCORE_EXPORT axlSurfaceRevolutionParametricWriter : public axlAbstractDataWriter {
    Q_OBJECT

public:
    axlSurfaceRevolutionParametricWriter(void);
    virtual ~axlSurfaceRevolutionParametricWriter(void);

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

dtkAbstractDataWriter *createaxlSurfaceRevolutionParametricWriter(void);

#endif // AXL_SURFACE_REVOLUTION_PARAMETRIC_WRITER_H