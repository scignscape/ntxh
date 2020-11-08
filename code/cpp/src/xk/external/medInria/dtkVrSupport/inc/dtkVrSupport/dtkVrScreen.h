/* dtkVrScreen.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Fri Feb 12 18:56:02 2010 (+0100)
 * Version: $Id: e6e3206677c026bc5611426290e4041311b71ddb $
 * Last-Updated: Tue Apr 24 19:37:47 2012 (+0200)
 *           By: Julien Wintz
 *     Update #: 32
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#pragma once

#include <dtkVrSupportExport.h>

#include <dtkMathSupport/dtkVector3D.h>

#include <QtWidgets>

class dtkVrScreenPrivate;

class  DTKVRSUPPORT_EXPORT dtkVrScreen
{
public:
    dtkVrScreen(const dtkDeprecated::dtkVector3D<double>& lowerLeft, const dtkDeprecated::dtkVector3D<double>& lowerRight, const dtkDeprecated::dtkVector3D<double>& upperLeft);
    dtkVrScreen(const dtkVrScreen& other);
    ~dtkVrScreen(void);

    void   initialize(void);
    void uninitialize(void);

    const dtkDeprecated::dtkVector3D<double>& lowerLeft(void) const;
    const dtkDeprecated::dtkVector3D<double>& upperLeft(void) const;
    const dtkDeprecated::dtkVector3D<double>& lowerRight(void) const;
    const dtkDeprecated::dtkVector3D<double>& upperRight(void) const;

    const dtkDeprecated::dtkVector3D<double>& up(void) const;
    const dtkDeprecated::dtkVector3D<double>& right(void) const;

    double width(void) const;
    double height(void) const;

    static const dtkDeprecated::dtkVector3D<double> screens[5][3];

private:
    dtkVrScreenPrivate *d;
};
