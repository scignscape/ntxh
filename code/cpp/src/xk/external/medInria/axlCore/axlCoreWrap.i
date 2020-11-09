/* axlCoreWrap.i --- Core layer swig interface definition
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2013 - Meriadeg Perrinel, Inria.
 * Created: Tue Jan  8 13:04:15 2009 (+0100)
 * Version: $Id$
 * Last-Updated: Jan  8 13:04:15 2013 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #:
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLCOREWRAP_I
#define AXLCOREWRAP_I

%module axlcore

%include "dtkCore.i"

%array_class(int, intArray);

%{

#include <axlCore/axlAbstractData.h>

#include <axlCore/axlAbstractVolume.h>
#include <axlCore/axlAbstractVolumeParametric.h>
#include <axlCore/axlAbstractVolumeImplicit.h>
#include <axlCore/axlAbstractVolumeRational.h>
#include <axlCore/axlAbstractVolumeBSpline.h>
//#include <axlCore/axlAbstractVolumeNurbs.h>

#include <axlCore/axlAbstractSurface.h>
#include <axlCore/axlAbstractSurfaceParametric.h>
#include <axlCore/axlAbstractSurfaceImplicit.h>
#include <axlCore/axlAbstractSurfaceTrimmed.h>
#include <axlCore/axlAbstractSurfaceBSpline.h>
//#include <axlCore/axlAbstractSurfaceNurbs.h>

#include <axlCore/axlAbstractCurve.h>
#include <axlCore/axlAbstractCurveParametric.h>
#include <axlCore/axlAbstractCurveImplicit.h>
#include <axlCore/axlAbstractCurveRational.h>
#include <axlCore/axlAbstractCurveBSpline.h>
//#include <axlCore/axlAbstractCurveNurbs.h>

#include <axlCore/axlCone.h>
#include <axlCore/axlCylinder.h>
#include <axlCore/axlEllipsoid.h>
#include <axlCore/axlLine.h>
#include <axlCore/axlMesh.h>
#include <axlCore/axlPlane.h>
#include <axlCore/axlPoint.h>
#include <axlCore/axlSphere.h>
#include <axlCore/axlTorus.h>
#include <axlCore/axlPointWriter.h>
#include <axlCore/axlMeshWriter.h>
#include <axlCore/axlShape.h>
#include <axlCore/axlCircleArc.h>

#include <axlCore/axlWriter.h>
#include <axlCore/axlReader.h>

#include <axlCore/axlAbstractView.h>

#include <axlCore/axlAbstractField.h>
#include <axlCore/axlAbstractDataComposite.h>

#include <axlCore/axlDouble.h>
#include <axlCore/axlInteger.h>

%}

// /////////////////////////////////////////////////////////////////
// Undefine preprocessing macros
// /////////////////////////////////////////////////////////////////
#undef  AXLCORE_EXPORT
#define AXLCORE_EXPORT
/*
#undef  AXLGUI_EXPORT
#define AXLGUI_EXPORT*/

//#undef SWIGPYTHON
//#undef SWIGCSHARP
// /////////////////////////////////////////////////////////////////
// Ignore rules for axAbstractData and const QString&
// /////////////////////////////////////////////////////////////////

%ignore shader;


// /////////////////////////////////////////////////////////////////
// Undefine signals
// /////////////////////////////////////////////////////////////////

%ignore updated();
%ignore samplingChanged();
%ignore dataChanged();
%ignore modifiedField();
%ignore modifiedGeometry();
%ignore modifiedProperty();


    // from axlAbstractView
%ignore inserted();
%ignore insertData(axlAbstractData *);
%ignore stateChanged(dtkAbstractData *,int);
%ignore lightPositionChanged(double, double, double);

%ignore dataSetInserted(QList<dtkAbstractData *>);
%ignore dataSetInserted(QList<axlAbstractData *>);
%ignore dataSetFieldsChanged(QList<axlAbstractData *>, QString);

%ignore edgeSelected(int,int,int);

// /////////////////////////////////////////////////////////////////
// Wrapper append rules
// /////////////////////////////////////////////////////////////////
%feature("pythonappend") axlAbstractView::add(dtkAbstractData *) %{args[0].thisown = False %}

// /////////////////////////////////////////////////////////////////
// Wrapper input
// /////////////////////////////////////////////////////////////////

%include "axlAbstractData.h"

// Volume
%include "axlAbstractVolume.h"
%include "axlAbstractVolumeImplicit.h"
%include "axlAbstractVolumeParametric.h"
%include "axlAbstractVolumeRational.h"
%include "axlAbstractVolumeBSpline.h"
//%include "axlAbstractVolumeNurbs.h"

// Surface
%include "axlAbstractSurface.h"
%include "axlAbstractSurfaceImplicit.h"
%include "axlAbstractSurfaceParametric.h"
%include "axlAbstractSurfaceTrimmed.h"
%include "axlAbstractSurfaceBSpline.h"
//%include "axlAbstractSurfaceNurbs.h"

// Curve
%include "axlAbstractCurve.h"
%include "axlAbstractCurveImplicit.h"
%include "axlAbstractCurveParametric.h"
%include "axlAbstractCurveRational.h"
%include "axlAbstractCurveBSpline.h"
//%include "axlAbstractCurveNurbs.h"

// Atomic data

%include "axlCone.h"
%include "axlCylinder.h"
%include "axlEllipsoid.h"
%include "axlLine.h"
%include "axlMesh.h"
%include "axlPlane.h"
%include "axlPoint.h"
%include "axlSphere.h"
%include "axlTorus.h"
%include "axlShape.h"
%include "axlCircleArc.h"

//Writer
%include "axlPointWriter.h"
%include "axlMeshWriter.h"
%include "axlWriter.h"

//Reader
%include "axlReader.h"

// others
%include "axlAbstractView.h"
%include "axlAbstractField.h"
%include "axlAbstractDataComposite.h"
%include "axlDouble.h"
%include "axlInteger.h"

#endif
