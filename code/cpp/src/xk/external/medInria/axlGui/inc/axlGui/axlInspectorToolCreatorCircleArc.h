/* axlInspectorToolCreatorCircleArc.h ---
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

#ifndef AXLINSPECTORTOOLCREATORCIRCLEARC_H
#define AXLINSPECTORTOOLCREATORCIRCLEARC_H

#include "axlGuiExport.h"
#include "axlInspectorToolCreator.h"

class dtkAbstractData;
class axlAbstractData;


#include <QtWidgets>

class axlInspectorObjectController;

class axlInspectorToolCreatorCircleArcPrivate;

class AXLGUI_EXPORT axlInspectorToolCreatorCircleArc : public axlInspectorToolCreator {
    Q_OBJECT

public:
    axlInspectorToolCreatorCircleArc(QWidget *parent = 0);
    virtual ~axlInspectorToolCreatorCircleArc(void);

    void setController(axlInspectorObjectController *controller);
    QList<axlAbstractData *> returnInputsList(void);

signals:
    void dataInserted(axlAbstractData *data);

public slots:
    void manageNormal(double);
    void manageCenter(double);
    void inverseNormal(void);
    void run(void);

private:
    axlInspectorToolCreatorCircleArcPrivate *d;
};

AXLGUI_EXPORT axlInspectorToolInterface *createaxlInspectorToolCreatorCircleArc(void);

#endif // AXLINSPECTORTOOLCREATORCIRCLEARC_H
