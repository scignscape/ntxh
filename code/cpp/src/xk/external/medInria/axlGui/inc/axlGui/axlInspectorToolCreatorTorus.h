/* axlInspectorToolCreatorTorus.h ---
 *
 * Author: Valentin Michelet
 * Copyright (C) 2008 - Valentin Michelet, Inria.
 * Created: Tue Nov  9 16:58:59 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Dec  6 15:46:18 2010 (+0100)
 *           By: Valentin Michelet
 *     Update #: 21
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLINSPECTORTOOLCREATORTORUS_H
#define AXLINSPECTORTOOLCREATORTORUS_H

#include "axlGuiExport.h"
#include <axlGui/axlInspectorToolFactory.h>
#include <axlGui/axlInspectorToolCreator.h>

class dtkAbstractData;
class axlAbstractData;
class axlDouble;


#include <QtWidgets>

class axlInspectorObjectController;

class axlInspectorToolCreatorTorusPrivate;

class AXLGUI_EXPORT axlInspectorToolCreatorTorus : public axlInspectorToolCreator {
    Q_OBJECT

public:
    axlInspectorToolCreatorTorus(QWidget *parent = 0);
    virtual ~axlInspectorToolCreatorTorus(void);

    void setController(axlInspectorObjectController *controller);
    QList<axlAbstractData *> returnInputsList(void);

signals:
    void dataInserted(axlAbstractData *data);

public slots:
    void run(void);

private:
    axlInspectorToolCreatorTorusPrivate *d;
};

AXLGUI_EXPORT axlInspectorToolInterface *createaxlInspectorToolCreatorTorus(void);

#endif // AXLINSPECTORTOOLCREATORTORUS_H
