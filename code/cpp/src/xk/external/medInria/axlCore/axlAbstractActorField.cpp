/* axlAbstractActorField.cpp ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 16:58:59 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Nov  9 17:09:38 2010 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 19
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlAbstractActorField.h"
#include "axlAbstractField.h"

#include <dtkCoreSupport/dtkAbstractData.h>
#include <dtkCoreSupport/dtkGlobal.h>

class axlAbstractActorFieldPrivate
{
public:
};

axlAbstractActorField::axlAbstractActorField(): d(new axlAbstractActorFieldPrivate)
{
}

axlAbstractActorField::~axlAbstractActorField(void)
{
    delete d;

    d = NULL;
}

axlAbstractField *axlAbstractActorField::field(void)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return NULL;
}
axlAbstractField *axlAbstractActorField::magnitude(void)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return NULL;
}

axlAbstractActor *axlAbstractActorField::actorField(void)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return NULL;
}

double axlAbstractActorField::colRangeMin(void){
    DTK_DEFAULT_IMPLEMENTATION;

    return 0.0;
}

double axlAbstractActorField::colRangeMax(void){
    DTK_DEFAULT_IMPLEMENTATION;

    return 0.0;
}

double axlAbstractActorField::maxValue(void){
    DTK_DEFAULT_IMPLEMENTATION;

    return 0.0;
}

double axlAbstractActorField::minValue(void){
    DTK_DEFAULT_IMPLEMENTATION;

    return 0.0;
}

int axlAbstractActorField::isoCount(void){
    DTK_DEFAULT_IMPLEMENTATION;

    return 0;
}

double axlAbstractActorField::isoRangeMin(void){
    DTK_DEFAULT_IMPLEMENTATION;

    return 0.0;
}

double axlAbstractActorField::isoRangeMax(void){
    DTK_DEFAULT_IMPLEMENTATION;

    return 0.0;
}

double axlAbstractActorField::glyphScale(void){
    DTK_DEFAULT_IMPLEMENTATION;

    return 0.0;
}

double axlAbstractActorField::streamRadius(void){
    DTK_DEFAULT_IMPLEMENTATION;

    return 0.0;
}

void axlAbstractActorField::setActiveFieldKind(void)
{
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractActorField::setInteractor(void *interactor){
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractActorField::setData(dtkAbstractData *field){
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractActorField::setActorField(axlAbstractActor *actorField){
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractActorField::setColRangeMin(double min){
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractActorField::setColRangeMax(double max){
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractActorField::setIsoCount(int count){
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractActorField::setIsoRangeMin(double min){
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractActorField::setIsoRangeMax(double max){
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractActorField::setGlyphScale(double scale){
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractActorField::setStreamPropagation(double propagation){
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractActorField::setStreamRadius(double radius){
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractActorField::setStreamDirection(int direction){
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractActorField::displayAsNoneScalar(void){
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractActorField::displayAsNoneVector(void){
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractActorField::displayAsColor(void){
    DTK_DEFAULT_IMPLEMENTATION;
}
void axlAbstractActorField::displayAsIso(void){
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractActorField::displayAsHedge(void){
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractActorField::displayAsGlyph(void){
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractActorField::displayAsStream(void){
    DTK_DEFAULT_IMPLEMENTATION;
}

void axlAbstractActorField::onIsoRadiusChanged(double radius)
{
    Q_UNUSED(radius);
}


void axlAbstractActorField::update(void){
    DTK_DEFAULT_IMPLEMENTATION;
}

void *axlAbstractActorField::scalarColorMapper(void){
    DTK_DEFAULT_IMPLEMENTATION;

    return NULL;
}
