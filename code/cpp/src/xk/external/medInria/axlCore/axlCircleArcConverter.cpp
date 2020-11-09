/* axlCircleArcConverter.cpp ---
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
#include "axlCircleArc.h"
#include "axlCircleArcConverter.h"

#include <dtkCoreSupport/dtkAbstractDataFactory.h>

#include "axlPoint.h"

#include <cmath>

class axlCircleArcConverterPrivate {
public:
    axlCircleArc *data;
    axlMesh* output;
    int startIndex;
    int endIndex;
    double precision;
    double angularResolution;
};

axlCircleArcConverter::axlCircleArcConverter(void) : axlAbstractDataConverter(), d(new axlCircleArcConverterPrivate) {
    d->data = NULL;
    d->output = NULL;
    d->startIndex = -1;
    d->endIndex = -1;
    d->precision = 0.1;
    d->angularResolution = 0.02;
}

axlCircleArcConverter::~axlCircleArcConverter(void) {
    delete d;
    d = NULL;
}

QString axlCircleArcConverter::description(void) const {
    return "Converter from axlCircleArcConverter to axlMesh";
}

QString axlCircleArcConverter::identifier() const {
    return "axlCircleArcConverter";
}

QStringList axlCircleArcConverter::fromTypes(void) const {
    return QStringList() << "axlCircleArcConverter" << "axlCircleArc";
}

QString axlCircleArcConverter::toType (void) const {
    return "axlMesh";
}

bool axlCircleArcConverter::registered(void) {
    return dtkAbstractDataFactory::instance()->registerDataConverterType("axlCircleArcConverter", QStringList(), "axlMesh", createaxlCircleArcConverter);
}

axlMesh* axlCircleArcConverter::toMesh(void) {
    if(!d->data)
        return NULL;

    // If output is NULL, create a new one
    if (!d->output)
        d->output = new axlMesh;

    // Normal
    axlPoint n = d->data->normal();
    n.normalize();

    // Center
    axlPoint c = d->data->center();
    // First point
    axlPoint p1 = d->data->point1();
    // Second point
    axlPoint p2 = d->data->point2();
    // Angle (c-p1 ; c-p2)
    axlPoint cp1 = p1-c;
    axlPoint cp2 = p2-c;
    // Second axis in repere (c; p1, pp2, normal)
    axlPoint cpp2 = axlPoint::crossProduct(n, cp1);

    // Compute angle between cp1 and cp2
    double angle = std::atan2(axlPoint::dotProduct(cp2/cp2.norm(), cpp2/cpp2.norm()), (axlPoint::dotProduct(cp1/cp1.norm(), cp2/cp2.norm())));
    if (angle < 0.)
        angle += 2*M_PI;

    // Number of edges within mesh, according to radius, angle and precision
    int nbEdges = std::ceil(angle/d->angularResolution);

    // Create new edge to record vertices list
    int arcIndex = d->output->push_back_new_edge();

    // If start and end points don't already exist
    if (d->startIndex == -1 && d->endIndex == -1) {
        // Add vertices to mesh
        for (int k = 0; k <= nbEdges; k++) {
            // Current angle
            double theta = k*angle / nbEdges;
            // Current point according to angle
            axlPoint currPoint = c + cp1*std::cos(theta) + cpp2*std::sin(theta);
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
            // Current angle
            double theta = k*angle / nbEdges;
            // Current point according to angle
            axlPoint currPoint = c + cp1*std::cos(theta) + cpp2*std::sin(theta);
            // Add current edge
            d->output->edgePushBack(arcIndex, d->output->vertex_count());
            // Add current point to mesh
            d->output->push_back_vertex(currPoint);
        }

        // Add edge between last last and last points of circle arc
        d->output->edgePushBack(arcIndex, d->endIndex);
    } else {
        dtkError() << "Error within axlCircleArcConverter::toMesh: one point already exists and not the other one.";
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

void axlCircleArcConverter::setData(dtkAbstractData* data) {
    if(axlCircleArc* circleArc = dynamic_cast<axlCircleArc*>(data))
        d->data = circleArc;
}

void axlCircleArcConverter::setParams(int channel, int index) {
    if (channel == 0)
        d->startIndex = index;
    else if (channel == 1)
        d->endIndex = index;
    else
        dtkWarn() << "axlCircleArcConverter::setParams usage: channel must be 0 or 1.";
}

void axlCircleArcConverter::setOutput(axlAbstractData *output) {
    d->output = static_cast<axlMesh*>(output);
}

void axlCircleArcConverter::setPrecision(double eps) {
    d->precision = eps;
}

dtkAbstractDataConverter* createaxlCircleArcConverter(void) {
    return new axlCircleArcConverter;
}
