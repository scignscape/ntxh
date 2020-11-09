/* axlAbstractCurve.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 16:58:59 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Dec  6 15:46:18 2010 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 21
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLPOINTSET_H
#define AXLPOINTSET_H

#include "axlCoreExport.h"
#include "axlPoint.h"
#include "axlAbstractData.h"

class axlPointSetPrivate;

class AXLCORE_EXPORT axlPointSet : public axlAbstractData
{
    Q_OBJECT

public:

    axlPointSet(void);

    /// Virtual destructor, enables safe inheritance.
    virtual ~axlPointSet(void);

    virtual QString description(void) const;
    virtual QString identifier(void) const;

    QString objectType(void) const;


    static bool registered(void);

    bool isPlanar(void) const;
    void setPlanar(const bool isPlanar);
    bool isUniqueColor(void) const;
    void setUniqueColor(const bool uniqueColor);
    int numberOfPoints(void) const;
    void push_front(axlPoint *p);
    void push_back(axlPoint *p);

    QDebug printAxlAbstractPoints(QDebug dbg);

    void printAxlPointSet(void);

    void *points(void) const;
    void *points(void);

    axlPoint *value(int n) const;
    axlPoint *value(int n);


private:
    axlPointSetPrivate *d;
};

dtkAbstractData *createaxlPointSet(void);

#endif //AXLPOINTSET_H
