/* axlInspectorToolCreatorCylinder.h ---
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

#ifndef AXLINSPECTORTOOLCREATORCYLINDER_H
#define AXLINSPECTORTOOLCREATORCYLINDER_H

#include "axlGuiExport.h"
#include "axlInspectorToolCreator.h"

class dtkAbstractData;
class axlAbstractData;
class axlDouble;


#include <QtWidgets>

class axlInspectorObjectController;

class axlInspectorToolCreatorCylinderPrivate;


class AXLGUI_EXPORT axlInspectorToolCreatorCylinder : public axlInspectorToolCreator
{
    Q_OBJECT

public:
    axlInspectorToolCreatorCylinder(QWidget *parent = 0);
    ~axlInspectorToolCreatorCylinder(void);

    void setController(axlInspectorObjectController *controller);
    QList<axlAbstractData *> returnInputsList(void);

signals:
    void dataInserted(axlAbstractData *data);


public slots:
    void run(void);

private:
    axlInspectorToolCreatorCylinderPrivate *d;
};

AXLGUI_EXPORT axlInspectorToolInterface *createaxlInspectorToolCreatorCylinder(void);


#endif //AXLINSPECTORTOOLCREATORCYLINDER_H
