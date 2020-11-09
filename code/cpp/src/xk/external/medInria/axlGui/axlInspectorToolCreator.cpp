/* axlInspectorToolCreator.cpp ---
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

#include "axlInspectorToolCreator.h"
#include "axlInspectorObjectController.h"
#include "axlInspectorObjectManagerTreeItem.h"

#include <axlCore/axlPoint.h>
#include <axlCore/axlLine.h>
#include <axlCore/axlAbstractData.h>
#include <dtkCoreSupport/dtkAbstractProcessFactory.h>
#include <dtkCoreSupport/dtkAbstractProcess.h>
#include <dtkGuiSupport/dtkColorButton.h>

#include <axlCore/axlDataDynamic.h>
#include <axlCore/axlLineCreator.h>
//#include <axlCore/axlMiddleLine.h>

#include <QtGui>

class axlInspectorToolCreatorPrivate
{
};

axlInspectorToolCreator::axlInspectorToolCreator(QWidget *parent) : axlInspectorToolInterface(parent), d(new axlInspectorToolCreatorPrivate)
{

}

axlInspectorToolCreator::~axlInspectorToolCreator(void)
{
    delete d;

    d = NULL;
}

void axlInspectorToolCreator::setController(axlInspectorObjectController *controller)
{
    Q_UNUSED(controller);
}

QList<axlAbstractData *> axlInspectorToolCreator::returnInputsList(void){
    QList<axlAbstractData *> list;
    return list;

}


void axlInspectorToolCreator::run(void)
{

}
