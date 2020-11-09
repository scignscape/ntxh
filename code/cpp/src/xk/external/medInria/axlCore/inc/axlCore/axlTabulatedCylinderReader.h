//@author: Hung NGUYEN 9:17 AM 20/05/2014

#ifndef AXL_TABULATED_CYLINDER_READER_H
#define AXL_TABULATED_CYLINDER_READER_H

#include <axlCore/axlAbstractDataReader.h>
#include "axlCoreExport.h"

class AXLCORE_EXPORT axlTabulatedCylinderReader : public axlAbstractDataReader {
    Q_OBJECT

public:
    axlTabulatedCylinderReader(void);
    virtual ~axlTabulatedCylinderReader(void);

    QString identifier(void) const;
    QString description(void) const;
    QStringList handled(void) const;

    static bool registered(void);

    bool accept(const QDomNode& node);
    bool reject(const QDomNode& node);

    axlAbstractData *read(const QDomNode& node);
};

dtkAbstractDataReader *createaxlTabulatedCylinderReader(void);

#endif // AXL_COMPOSITE_CURVE_H
