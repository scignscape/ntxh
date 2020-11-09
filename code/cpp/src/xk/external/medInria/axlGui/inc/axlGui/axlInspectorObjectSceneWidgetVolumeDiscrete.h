/* axlInspectorObjectSceneWidgetVolumeDiscrete.h ---
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

#ifndef AXLINSPECTOROBJECTSCENEWIDGETVOLUMEDISCRETE_H
#define AXLINSPECTOROBJECTSCENEWIDGETVOLUMEDISCRETE_H

#include <QtWidgets>
#include "axlGuiExport.h"

class axlAbstractView;
class axlInspectorObjectSceneWidgetVolumeDiscretePrivate;
class dtkAbstractData;

class AXLGUI_EXPORT axlInspectorObjectSceneWidgetVolumeDiscrete : public QFrame
{
    Q_OBJECT

public:
     axlInspectorObjectSceneWidgetVolumeDiscrete(QWidget *parent = 0);
    ~axlInspectorObjectSceneWidgetVolumeDiscrete(void);

public slots:
    void setData(dtkAbstractData *data);
    void setView(axlAbstractView *view);

private:
    axlInspectorObjectSceneWidgetVolumeDiscretePrivate *d;
};

#endif // AXLINSPECTOROBJECTSCENEWIDGETVOLUMEDISCRETE_H
