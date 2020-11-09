//@author: Hung NGUYEN 9:17 AM 20/05/2014

#ifndef AXL_COMPOSITE_CURVE_READER_H
#define AXL_COMPOSITE_CURVE_READER_H

#include <axlCore/axlAbstractDataReader.h>
#include "axlCoreExport.h"

class AXLCORE_EXPORT axlCompositeCurveReader : public axlAbstractDataReader {
    Q_OBJECT

public:
    axlCompositeCurveReader(void);
    virtual ~axlCompositeCurveReader(void);

    QString identifier(void) const;
    QString description(void) const;
    QStringList handled(void) const;

    static bool registered(void);

    bool accept(const QDomNode& node);
    bool reject(const QDomNode& node);

    axlAbstractData *read(const QDomNode& node);
};

dtkAbstractDataReader *createaxlCompositeCurveReader(void);

#endif // AXL_COMPOSITE_CURVE_H
