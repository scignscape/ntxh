/* axlAbstractVisitorParametric.h ---
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

#ifndef AXLABSTRACTVISITORPARAMETRIC_H
#define AXLABSTRACTVISITORPARAMETRIC_H

#include "axlCoreExport.h"

#include <axlCore/axlAbstractVisitor.h>

#include <QtGui>

class axlAbstractVisitorParametricPrivate;
class axlPoint;
class axlInspectorObjectInterface;

class AXLCORE_EXPORT axlAbstractVisitorParametric : public axlAbstractVisitor
{
    Q_OBJECT

public:
    axlAbstractVisitorParametric(QObject* parent = NULL);
    virtual ~axlAbstractVisitorParametric(void);

//public:
    //virtual axlInspectorObjectInterface *form(void);

public :
    virtual axlPoint eval(double u);
    virtual axlPoint eval(double u, double v);
    virtual axlPoint eval(double u, double v, double w);


private:
    axlAbstractVisitorParametricPrivate *d;
};
#endif // AXLABSTRACTVISITORPARAMETRIC_H
