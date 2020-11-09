/* axlInspectorToolCreatorCone.h ---
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

#ifndef AXLINSPECTORTOOLCREATORCONE_H
#define AXLINSPECTORTOOLCREATORCONE_H

#include "axlGuiExport.h"
#include "axlInspectorToolFactory.h"
#include "axlInspectorToolCreator.h"

class dtkAbstractData;
class axlAbstractData;
class axlDouble;


#include <QtWidgets>

class axlInspectorObjectController;

class axlInspectorToolCreatorConePrivate;

class AXLGUI_EXPORT axlInspectorToolCreatorCone : public axlInspectorToolCreator
{
    Q_OBJECT

public:
    axlInspectorToolCreatorCone(QWidget *parent = 0);
    ~axlInspectorToolCreatorCone(void);

    void setController(axlInspectorObjectController *controller);
    QList<axlAbstractData *> returnInputsList(void);

signals:
    void dataInserted(axlAbstractData *data);
//    void doubleInputInserted(QList<axlDouble *> dataList);


public slots:
    void run(void);

private:
    axlInspectorToolCreatorConePrivate *d;
};

AXLGUI_EXPORT axlInspectorToolInterface *createaxlInspectorToolCreatorCone(void);

#endif //AXLINSPECTORTOOLCREATORCONE_H
