/* axlInspectorToolCreatorPoint.h ---
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

#ifndef AXLINSPECTORTOOLCREATORPOINT_H
#define AXLINSPECTORTOOLCREATORPOINT_H

#include "axlGuiExport.h"
#include "axlInspectorToolCreator.h"

class dtkAbstractData;
class axlAbstractData;


#include <QtWidgets>

class axlInspectorObjectController;

class axlInspectorToolCreatorPointPrivate;

class AXLGUI_EXPORT axlInspectorToolCreatorPoint : public axlInspectorToolCreator
{
    Q_OBJECT

public:
     axlInspectorToolCreatorPoint(QWidget *parent = 0);
    ~axlInspectorToolCreatorPoint(void);

     void setController(axlInspectorObjectController *controller);

signals:
          void dataInserted(axlAbstractData *data);


public slots:
    void run(void);

private:
    axlInspectorToolCreatorPointPrivate *d;
};

#endif //AXLINSPECTORTOOLCREATORPOINT_H
