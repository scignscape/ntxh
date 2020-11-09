/*
   @author: Hung NGUYEN Inria 2014
*/

#ifndef AXL_COMPOSITE_CURVE_WRITER_H
#define AXL_COMPOSITE_CURVE_WRITER_H

#include <axlCore/axlAbstractDataWriter.h>
#include "axlCoreExport.h"

class AXLCORE_EXPORT axlCompositeCurveWriter : public axlAbstractDataWriter {
    Q_OBJECT

public:
    axlCompositeCurveWriter(void);
    virtual ~axlCompositeCurveWriter(void);

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

dtkAbstractDataWriter *createaxlCompositeCurveWriter(void);

#endif // AXL_COMPOSITE_CURVE_WRITER_H