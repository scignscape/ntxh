/* axlInspectorToolCreatorLine.h ---
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

#ifndef AXLINSPECTORTOOLCREATORLINE_H
#define AXLINSPECTORTOOLCREATORLINE_H

#include "axlGuiExport.h"
#include <axlGui/axlInspectorToolFactory.h>
#include <axlGui/axlInspectorToolCreator.h>

class axlAbstractData;
class axlDouble;


#include <QtWidgets>

class axlInspectorObjectController;
class axlInspectorToolCreatorLinePrivate;

class AXLGUI_EXPORT axlInspectorToolCreatorLine : public axlInspectorToolCreator
{
    Q_OBJECT

public:
    axlInspectorToolCreatorLine(QWidget *parent = 0);
    ~axlInspectorToolCreatorLine(void);

    void setController(axlInspectorObjectController *controller);
    QList<axlAbstractData *> returnInputsList(void);

signals:
    void dataInserted(axlAbstractData *data);


public slots:
    void run(void);

private:
    axlInspectorToolCreatorLinePrivate *d;
};

AXLGUI_EXPORT axlInspectorToolInterface *createaxlInspectorToolCreatorLine(void);

#endif //AXLINSPECTORTOOLCREATORLINE_H
