/* axlAbstractDataComposite.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 16:58:59 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Dec  6 15:32:45 2010 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 22
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLABSTRACTDATACOMPOSITE_H
#define AXLABSTRACTDATACOMPOSITE_H

#include "axlCoreExport.h"

#include "axlAbstractData.h"

#include <QtCore>

class axlAbstractDataCompositePrivate;

class AXLCORE_EXPORT axlAbstractDataComposite : public axlAbstractData
{
    Q_OBJECT

public:
             axlAbstractDataComposite(void);
    virtual ~axlAbstractDataComposite(void);

public :
    void add(dtkAbstractData *data);
    bool get(dtkAbstractData * data);
    void set(QList<dtkAbstractData *> data);
    void remove(dtkAbstractData *data);
    int count(void);

    dtkAbstractData *get(int i);

    virtual QString description(void) const;
    virtual QString identifier  (void) const;



signals:
    void updated(void);
    void samplingChanged();



private:
    axlAbstractDataCompositePrivate *d;
};
#endif //AXLABSTRACTDATACOMPOSITE_H
