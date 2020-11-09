/* axlInspectorToolCreatorPointSet.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Wed Mar 16 17:17:53 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Wed Mar 16 17:37:04 2011 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 14
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLINSPECTORTOOLCREATORPOINTSET_H
#define AXLINSPECTORTOOLCREATORPOINTSET_H

#include "axlGuiExport.h"

class dtkAbstractData;
class axlAbstractData;


#include <QtWidgets>

class axlInspectorObjectController;

class axlInspectorToolCreatorPointSetPrivate;

class AXLGUI_EXPORT axlInspectorToolCreatorPointSet : public QFrame
{
    Q_OBJECT

public:
     axlInspectorToolCreatorPointSet(QWidget *parent = 0);
    ~axlInspectorToolCreatorPointSet(void);

     void setController(axlInspectorObjectController *controller);

signals:
          void dataInserted(axlAbstractData *data);


public slots:
    void run(void);

private:
    axlInspectorToolCreatorPointSetPrivate *d;
};

#endif //axlInspectorToolCreatorPointSet_H
