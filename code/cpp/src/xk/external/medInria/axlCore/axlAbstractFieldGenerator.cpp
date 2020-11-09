/* axlAbstractFieldGenerator.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2011 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov 11 16:58:59 2011 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Dec  6 15:32:45 2010 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 22
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlAbstractFieldGenerator.h"
#include "axlAbstractField.h"

#include <dtkCoreSupport/dtkGlobal.h>

#include <QtCore>

axlAbstractFieldGenerator::axlAbstractFieldGenerator(void) : axlAbstractProcess()
{

}

axlAbstractFieldGenerator::~axlAbstractFieldGenerator(void)
{
}

void axlAbstractFieldGenerator::setInput(dtkAbstractData *data, int channel)
{
    Q_UNUSED(data);
    Q_UNUSED(channel);
}

int axlAbstractFieldGenerator::update(void)
{
     DTK_DEFAULT_IMPLEMENTATION;

     return 0;
}

QString axlAbstractFieldGenerator::description(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;

    return QString();
}
