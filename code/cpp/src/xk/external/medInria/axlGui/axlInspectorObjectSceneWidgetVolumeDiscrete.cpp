/* axlInspectorObjectSceneWidgetVolumeDiscrete.cpp ---
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

#include "axlInspectorObjectSceneWidgetVolumeDiscrete.h"
#include "axlAbstractVolumeDiscreteEditor.h"

#include <axlCore/axlAbstractView.h>
#include <axlCore/axlAbstractVolumeDiscrete.h>

#include <dtkCoreSupport/dtkAbstractData.h>

class axlInspectorObjectSceneWidgetVolumeDiscretePrivate
{
public:
    axlAbstractVolumeDiscreteEditor *editor;
};

axlInspectorObjectSceneWidgetVolumeDiscrete::axlInspectorObjectSceneWidgetVolumeDiscrete(QWidget *parent) : QFrame(parent), d(new axlInspectorObjectSceneWidgetVolumeDiscretePrivate)
{
    //d->editor = new axlVolumeEditor(this);//factory
    d->editor = dynamic_cast<axlAbstractVolumeDiscreteEditor *>(axlInspectorObjectFactory::instance()->create("axlVolumeDiscreteEditor"));

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    if(d->editor){
        layout->addWidget(d->editor);
    }
}

axlInspectorObjectSceneWidgetVolumeDiscrete::~axlInspectorObjectSceneWidgetVolumeDiscrete(void)
{
    delete d;
}

void axlInspectorObjectSceneWidgetVolumeDiscrete::setData(dtkAbstractData *data)
{
    if(axlAbstractVolumeDiscrete *volume = dynamic_cast<axlAbstractVolumeDiscrete *>(data)){
        if(d->editor)
            d->editor->setVolume(volume);
    }
}

void axlInspectorObjectSceneWidgetVolumeDiscrete::setView(axlAbstractView *view)
{
    if(d->editor)
        d->editor->setView(view);
}
