/* axlLineConverter.cpp ---
 *
 * Author: Valentin Michelet
 * Copyright (C) 2008-2011 - Valentin Michelet, Inria.
 * Created: Tue Apr 30 11:03:18 2012 (+0100)
 * Version: $Id$
 *     Update #: 50
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "axlMesh.h"
#include "axlLine.h"
#include "axlLineConverter.h"
#include <dtkCoreSupport/dtkAbstractDataFactory.h>
#include "axlPoint.h"

#include <cmath>

class axlLineConverterPrivate {
public:
    axlLine* data;
    axlMesh* output;
    int startIndex;
    int endIndex;
    int nbsegments;
    double precision;
};

axlLineConverter::axlLineConverter(void) : axlAbstractDataConverter(), d(new axlLineConverterPrivate) {
    d->data = NULL;
    d->output = NULL;
    d->startIndex = -1;
    d->endIndex = -1;
    d->nbsegments = 1;
    d->precision = 0.1;
}

axlLineConverter::~axlLineConverter(void) {
    delete d;
    d = NULL;
}

QString axlLineConverter::description(void) const {
    return "Converter from axlLineConverter to axlMesh";
}

QString axlLineConverter::identifier() const {
    return "axlLineConverter";
}

QStringList axlLineConverter::fromTypes(void) const {
    return QStringList() << "axlLineConverter" << "axlLine";
}

QString axlLineConverter::toType (void) const {
    return "axlMesh";
}

bool axlLineConverter::registered(void) {
    return dtkAbstractDataFactory::instance()->registerDataConverterType("axlLineConverter", QStringList(), "axlMesh", createaxlLineConverter);
}

axlMesh* axlLineConverter::toMesh(void) {
    if(!d->data)
        return NULL;

    if (!d->output) {
        d->output = new axlMesh;
    }

    // Compute segment length
    double length = axlPoint::distance(d->data->firstPoint(), d->data->secondPoint());
    // Number of edges within mesh, according to precision and length
    int nbEdges = d->nbsegments;//std::ceil(length/d->precision);

    // Determine segment direction vector
    axlPoint direction(d->data->secondPoint()->operator -(d->data->firstPoint()));
    // Normalize it
    direction.normalize();

    // Create new edge to record vertices list
    int arcIndex = d->output->push_back_new_edge();

    // If start and end points don't already exist
    if (d->startIndex == -1 && d->endIndex == -1) {
        // Add vertices to mesh
        for (int k = 0; k <= nbEdges; k++) {
            // Compute current shift value from first point
            double step = (length*k)/nbEdges;
            // Current point
            axlPoint currPoint(d->data->firstPoint()->operator + (direction*step));
            // Add current point to mesh
            d->output->push_back_vertex(currPoint);
        }

        // Get number of points within mesh
        int nbPointsInMesh = d->output->vertex_count();

        // Add edge between first and second points of circle arc
        d->output->edgePushBack(arcIndex, nbPointsInMesh-nbEdges-1);

        // Add other edges to mesh
        for (int k = 0; k < nbPointsInMesh-1; k++) {
            d->output->edgePushBack(arcIndex, k+1);
        }

        // Add edge between last last and last points of circle arc
        d->output->edgePushBack(arcIndex, nbPointsInMesh-2);
    // If start and end points already exist
    } else if (d->startIndex != -1 && d->endIndex != -1) {
        // Add edge between first and second points of circle arc
        d->output->edgePushBack(arcIndex, d->startIndex);

        // Add vertices to mesh
        for (int k = 1; k <= nbEdges-1; k++) {
            // Compute current shift value from first point
            double step = (length*k)/nbEdges;
            // Current point
            axlPoint currPoint(d->data->firstPoint()->operator +(direction*step));
            // Add current edge to mesh
            d->output->edgePushBack(arcIndex, d->output->vertex_count());
            // Add current point to mesh
            d->output->push_back_vertex(currPoint);
        }

        // Add edge between last last and last points of circle arc
        d->output->edgePushBack(arcIndex, d->endIndex);
    } else {
        dtkError() << "Error within axlLineConverter::toMesh: one point already exists and not the other one.";
    }

    // Set mesh parameters
    d->output->vertex_show() = false;
    d->output->normal_used() = false;
    d->output->color_used() = true;
    d->output->edge_show() = true;
    d->output->face_show() = false;
    d->output->isPlanar() = true;

    d->output->setColor(d->data->color());
    d->output->setOpacity(d->data->opacity());
    d->output->setShader(d->data->shader());

    return d->output;
}

void axlLineConverter::setData(dtkAbstractData* data) {
    if(axlLine* line = dynamic_cast<axlLine*>(data))
        d->data = line;
}

void axlLineConverter::setParams(int channel, int index) {
    if (channel == 0)
        d->startIndex = index;
    else if (channel == 1)
        d->endIndex = index;
    else
        dtkWarn() << "axlLineConverter::setParams usage: channel must be 0 or 1.";
}

void axlLineConverter::setOutput(axlAbstractData* output) {
    d->output = static_cast<axlMesh*>(output);
}

void axlLineConverter::setPrecision(double eps) {
    d->precision = eps;
}

dtkAbstractDataConverter* createaxlLineConverter(void) {
    return new axlLineConverter;
}
