/*
   @author: Hung NGUYEN Inria 2014
*/

#ifndef AXL_TABULATED_CYLINDER_WRITER_H
#define AXL_TABULATED_CYLINDER_WRITER_H

#include <axlCore/axlAbstractDataWriter.h>
#include "axlCoreExport.h"

class AXLCORE_EXPORT axlTabulatedCylinderWriter : public axlAbstractDataWriter {
    Q_OBJECT

public:
    axlTabulatedCylinderWriter(void);
    virtual ~axlTabulatedCylinderWriter(void);

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

dtkAbstractDataWriter *createaxlTabulatedCylinderWriter(void);

#endif // AXL_TABULATED_CYLINDER_WRITER_H