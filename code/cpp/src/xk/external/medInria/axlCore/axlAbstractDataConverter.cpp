/* axlAbstractDataConverter.cpp ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Tue Jan 24 10:54:46 2012 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Jan 24 10:57:21 2012 (+0100)
 *           By: Julien Wintz
 *     Update #: 19
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlAbstractDataConverter.h"

#include <dtkCoreSupport/dtkGlobal.h>

axlAbstractDataConverter::axlAbstractDataConverter(void) : dtkAbstractDataConverter()
{

}

axlAbstractDataConverter::~axlAbstractDataConverter(void)
{

}

//! Mesh conversion
/*!
 *  Try converting an axlAbstractData to an axlMesh.
 *
 * \return An axlMesh if the conversion succeeded, NULL otherwise.
 */

axlMesh *axlAbstractDataConverter::toMesh(void)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return NULL;
}

void axlAbstractDataConverter::setParams(int channel, int index) {
    DTK_UNUSED(channel);
    DTK_UNUSED(index);
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractDataConverter::setOutput(axlAbstractData* output) {
    DTK_UNUSED(output);
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractDataConverter::setPrecision(double eps) {
    DTK_UNUSED(eps);
    DTK_DEFAULT_IMPLEMENTATION;
}
