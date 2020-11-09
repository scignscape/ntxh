/* axlAbstractVisitor.h ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2013 - Anais Ducoffe, Inria.
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLABSTRACTVISITOR_H
#define AXLABSTRACTVISITOR_H

#include "axlCoreExport.h"

#include <dtkCoreSupport/dtkAbstractObject.h>

#include <QtGui>

class axlAbstractVisitorPrivate;
class axlInspectorObjectInterface;

class AXLCORE_EXPORT axlAbstractVisitor : public dtkAbstractObject
{
    Q_OBJECT

public:
    axlAbstractVisitor(QObject* parent = NULL);
    virtual ~axlAbstractVisitor(void);

//public:
    //virtual axlInspectorObjectInterface *form(void);


private:
    axlAbstractVisitorPrivate *d;
};
#endif // AXLABSTRACTVISITOR_H
