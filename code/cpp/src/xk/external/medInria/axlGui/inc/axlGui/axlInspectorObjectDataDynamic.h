/* axlInspectorObjectDataDynamic.h ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2013- Anais Ducoffe, Inria.
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLINSPECTOROBJECTDATADYNAMIC_H
#define AXLINSPECTOROBJECTDATADYNAMIC_H

#include "axlGuiExport.h"
#include <axlGui/axlInspectorObjectFactory.h>
#include "axlInspectorUtils.h"

#include <QtWidgets>

class axlDataDynamic;
class dtkAbstractData;

class axlInspectorObjectDataDynamicPrivate;

class AXLGUI_EXPORT axlInspectorObjectDataDynamic: public axlInspectorObjectInterface //QFrame
{
    Q_OBJECT

public:
     axlInspectorObjectDataDynamic(QWidget *parent = 0);
    ~axlInspectorObjectDataDynamic(void);

    QSize sizeHint(void) const;

public slots:
    void setData(axlDataDynamic *dynamicData);

private:
    axlInspectorObjectDataDynamicPrivate *d;
};

#endif // AXLINSPECTOROBJECTDATADYNAMIC_H
