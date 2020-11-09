/* axlLineCreator.cpp ---
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2012, Anais Ducoffe, INRIA.
 */

/* Commentary:
 */

/* Change log:
 *
 */

#include "axlLineCreator.h"
#include <axlCore/axlPoint.h>
#include <axlCore/axlLine.h>
#include <axlCore/axlDataDynamic.h>
#include <axlCore/axlAbstractData.h>

#include <dtkCoreSupport/dtkAbstractProcessFactory.h>

//////////////////////////////////////////////////////////
////axlLineCreatorPrivate
//////////////////////////////////////////////////////////

class axlLineCreatorPrivate {

public:
    axlPoint *point1;
    axlPoint *point2;
    axlLine *output;
};

//////////////////////////////////////////////////////////
//// axlLineCreatorPrivate
//////////////////////////////////////////////////////////
axlLineCreator::axlLineCreator(QObject *parent ) : axlAbstractCreatorProcess(), d(new axlLineCreatorPrivate) {
    d->point1 = NULL;
    d->point2 = NULL;
    d->output = NULL;

    dtkAbstractProcessFactory::instance()->registerProcessType("axlLineCreator", createaxlLineCreator);
}

axlLineCreator::axlLineCreator(const axlLineCreator *other, QObject *parent) : axlAbstractCreatorProcess(), d(new axlLineCreatorPrivate) {
    d->point1 = dynamic_cast<axlPoint *>(other->getInput(0));
    d->point2 = dynamic_cast<axlPoint *>(other->getInput(1));
    d->output = NULL;//dynamic_cast<axlLine *>(other->output());
}

axlLineCreator::~axlLineCreator(void) {
    delete d;
    d = NULL;
}

axlAbstractData *axlLineCreator::getInput(int channel) const {
    if (channel == 0) {
        return d->point1;
    } else {
        return d->point2;
    }
}

bool axlLineCreator::hasParameters(void) {
        return false;
}


dtkAbstractData *axlLineCreator::output(void) {
    return d->output;
}

dtkAbstractData *axlLineCreator::output(int channel) {
    return d->output;
}

void axlLineCreator::setInput(dtkAbstractData *newData, int channel) {
    if (dynamic_cast<axlAbstractData *>(newData)) {
        axlAbstractData *axlData = dynamic_cast<axlAbstractData *>(newData);
        if (dynamic_cast<axlPoint *>(axlData)) {
            axlPoint *point = dynamic_cast<axlPoint *>(axlData);
            if (channel == 0) {
                d->point1 = point;
            } else {
                d->point2 = point;
            }
        }
    }
}

int axlLineCreator::update(void) {
    axlLine *newLine = NULL;
    if (d->output == NULL) {
        if (d->point1 && d->point2) {
            newLine =  new axlLine(d->point1, d->point2);
            d->output = newLine;
            return 1;
        } else {
            return 0;
        }
    } else {
        if (d->point1 && d->point2) {
            d->output->onFirstPointChanged(d->point1);
            d->output->onSecondPointChanged(d->point2);
            return 1;
        } else {
            return 0;
        }
    }
}

QString axlLineCreator::description(void) const {
    return "create a line with two points";
}


QString axlLineCreator::identifier(void) const {
    return "axlLineCreator";
}

dtkAbstractProcess *createaxlLineCreator(void) {
    return new axlLineCreator;
}
