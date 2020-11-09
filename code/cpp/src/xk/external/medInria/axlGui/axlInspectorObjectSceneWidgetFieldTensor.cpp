/* axlInspectorObjectSceneWidgetFieldTensor.cpp ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Fri Dec 17 22:48:33 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Fri Jun 17 17:18:47 2011 (+0200)
 *           By: Thibaud Kloczko
 *     Update #: 11
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlInspectorObjectSceneWidgetFieldTensor.h"

#include <axlCore/axlAbstractField.h>

class axlInspectorObjectSceneWidgetFieldTensorPrivate
{
public:
    axlAbstractField *field;
};

axlInspectorObjectSceneWidgetFieldTensor::axlInspectorObjectSceneWidgetFieldTensor(QWidget *parent) : QWidget(parent), d(new axlInspectorObjectSceneWidgetFieldTensorPrivate)
{
    d->field = NULL;
}

axlInspectorObjectSceneWidgetFieldTensor::~axlInspectorObjectSceneWidgetFieldTensor(void)
{
    delete d;

    d = NULL;
}

void axlInspectorObjectSceneWidgetFieldTensor::setField(axlAbstractField *field)
{
    d->field = field;
}
