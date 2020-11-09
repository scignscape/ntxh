/* axlInspectorToolCreatorPlane.h ---
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

#ifndef AXLINSPECTORTOOLCREATORPLANE_H
#define AXLINSPECTORTOOLCREATORPLANE_H

#include "axlGuiExport.h"
#include "axlInspectorToolCreator.h"

class dtkAbstractData;
class axlAbstractData;


#include <QtWidgets>

class axlInspectorObjectController;

class axlInspectorToolCreatorPlanePrivate;

class AXLGUI_EXPORT axlInspectorToolCreatorPlane : public axlInspectorToolCreator
{
    Q_OBJECT

public:
    axlInspectorToolCreatorPlane(QWidget *parent = 0);
    ~axlInspectorToolCreatorPlane(void);

    void setController(axlInspectorObjectController *controller);
    QList<axlAbstractData *> returnInputsList(void);

signals:
    void dataInserted(axlAbstractData *data);

public slots:
    void run(void);

private:
    axlInspectorToolCreatorPlanePrivate *d;
};

AXLGUI_EXPORT axlInspectorToolInterface *createaxlInspectorToolCreatorPlane(void);

#endif //axlInspectorToolCreatorPlane_H
