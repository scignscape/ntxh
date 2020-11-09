/* axlInspectorToolCreatorSphere.h ---
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

#ifndef AXLINSPECTORTOOLCREATORSPHERE_H
#define AXLINSPECTORTOOLCREATORSPHERE_H

#include "axlGuiExport.h"
#include <axlGui/axlInspectorToolFactory.h>
#include <axlGui/axlInspectorToolCreator.h>

class dtkAbstractData;
class axlAbstractData;
class axlDouble;


#include <QtWidgets>

class axlInspectorObjectController;

class axlInspectorToolCreatorSpherePrivate;

class AXLGUI_EXPORT axlInspectorToolCreatorSphere : public axlInspectorToolCreator
{
    Q_OBJECT

public:
    axlInspectorToolCreatorSphere(QWidget *parent = 0);
    ~axlInspectorToolCreatorSphere(void);

    void setController(axlInspectorObjectController *controller);
    QList<axlAbstractData *> returnInputsList(void);

signals:
    void dataInserted(axlAbstractData *data);


public slots:
    void run(void);

private:
    axlInspectorToolCreatorSpherePrivate *d;
};

AXLGUI_EXPORT axlInspectorToolInterface *createaxlInspectorToolCreatorSphere(void);

#endif //AXLINSPECTORTOOLCREATORSPHERE_H
