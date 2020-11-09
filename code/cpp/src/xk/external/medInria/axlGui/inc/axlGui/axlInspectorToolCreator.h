/* axlInspectorToolCreator.h ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2013 - Anais Ducoffe, Inria.
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLINSPECTORTOOLCREATOR_H
#define AXLINSPECTORTOOLCREATOR_H

#include "axlGuiExport.h"
#include <axlGui/axlInspectorToolFactory.h>

class dtkAbstractData;
class axlAbstractData;
class axlDouble;


#include <QtWidgets>

class axlInspectorObjectController;

class axlInspectorToolCreatorPrivate;
class axlAbstractData;

class AXLGUI_EXPORT axlInspectorToolCreator : public axlInspectorToolInterface
{
    Q_OBJECT

public:
    axlInspectorToolCreator(QWidget *parent = 0);
    ~axlInspectorToolCreator(void);

    virtual void setController(axlInspectorObjectController *controller);
    virtual QList<axlAbstractData *> returnInputsList(void);

signals:
    void dataInserted(axlAbstractData *data);


public slots:
    virtual void run(void);

private:
    axlInspectorToolCreatorPrivate *d;
};

#endif // AXLINSPECTORTOOLCREATOR_H
