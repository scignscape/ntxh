/* axlCorePython.i --- Core layer swig interface definition
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

#ifndef AXLCOREPYTHON_I
#define AXLCOREPYTHON_I

%module axlcore




%include "axlCoreWrap.i"


// /////////////////////////////////////////////////////////////////
// Helper functions
// /////////////////////////////////////////////////////////////////

%{


axlAbstractData *to_axl_data(dtkAbstractData *data)
{
    return dynamic_cast<axlAbstractData *>(data);
}

// To Volume taxonomy


axlAbstractVolume *to_axl_volume(dtkAbstractData *data)
{
    return dynamic_cast<axlAbstractVolume *>(data);
}

axlAbstractVolumeParametric *to_axl_volume_parametric(dtkAbstractData *data)
{
    return dynamic_cast<axlAbstractVolumeParametric *>(data);
}

axlAbstractVolumeImplicit *to_axl_volume_implicit(dtkAbstractData *data)
{
    return dynamic_cast<axlAbstractVolumeImplicit *>(data);
}

axlAbstractVolumeBSpline *to_axl_volume_bspline(dtkAbstractData *data)
{
    return dynamic_cast<axlAbstractVolumeBSpline *>(data);
}

axlAbstractVolumeRational *to_axl_volume_rational(dtkAbstractData *data)
{
    return dynamic_cast<axlAbstractVolumeRational *>(data);
}

//axlAbstractVolumeNurbs *to_axl_volume_nurbs(dtkAbstractData *data)
//{
//    return dynamic_cast<axlAbstractVolumeNurbs *>(data);
//}

// To Surface taxonomy


axlAbstractSurface *to_axl_surface(dtkAbstractData *data)
{
    return dynamic_cast<axlAbstractSurface *>(data);
}

axlAbstractSurfaceParametric *to_axl_surface_parametric(dtkAbstractData *data)
{
    return dynamic_cast<axlAbstractSurfaceParametric *>(data);
}

axlAbstractSurfaceImplicit *to_axl_surface_implicit(dtkAbstractData *data)
{
    return dynamic_cast<axlAbstractSurfaceImplicit *>(data);
}

axlAbstractSurfaceBSpline *to_axl_surface_bspline(dtkAbstractData *data)
{
    return dynamic_cast<axlAbstractSurfaceBSpline *>(data);
}

//axlAbstractSurfaceNurbs *to_axl_surface_nurbs(dtkAbstractData *data)
//{
//    return dynamic_cast<axlAbstractSurfaceNurbs *>(data);
//}

axlAbstractSurfaceTrimmed *to_axl_surface_trimmed(dtkAbstractData *data)
{
    return dynamic_cast<axlAbstractSurfaceTrimmed *>(data);
}

// To Curve taxonomy


axlAbstractCurve *to_axl_curve(dtkAbstractData *data)
{
    return dynamic_cast<axlAbstractCurve *>(data);
}

axlAbstractCurveParametric *to_axl_curve_parametric(dtkAbstractData *data)
{
    return dynamic_cast<axlAbstractCurveParametric *>(data);
}

axlAbstractCurveImplicit *to_axl_curve_implicit(dtkAbstractData *data)
{
    return dynamic_cast<axlAbstractCurveImplicit *>(data);
}

axlAbstractCurveBSpline *to_axl_curve_bspline(dtkAbstractData *data)
{
    return dynamic_cast<axlAbstractCurveBSpline *>(data);
}

axlAbstractCurveRational *to_axl_curve_rational(dtkAbstractData *data)
{
    return dynamic_cast<axlAbstractCurveRational *>(data);
}

//axlAbstractCurveNurbs *to_axl_curve_nurbs(dtkAbstractData *data)
//{
//    return dynamic_cast<axlAbstractCurveNurbs *>(data);
//}

// To Atomic data


axlCone *to_axl_cone(dtkAbstractData *data)
{
    return dynamic_cast<axlCone *>(data);
}

axlCylinder *to_axl_cylinder(dtkAbstractData *data)
{
    return dynamic_cast<axlCylinder *>(data);
}

axlEllipsoid *to_axl_ellipsoid(dtkAbstractData *data)
{
    return dynamic_cast<axlEllipsoid *>(data);
}

axlLine *to_axl_line(dtkAbstractData *data)
{
    return dynamic_cast<axlLine *>(data);
}

axlMesh *to_axl_mesh(dtkAbstractData *data)
{
    return dynamic_cast<axlMesh *>(data);
}

axlPlane *to_axl_plane(dtkAbstractData *data)
{
    return dynamic_cast<axlPlane *>(data);
}

axlPoint *to_axl_point(dtkAbstractData *data)
{
    return dynamic_cast<axlPoint *>(data);
}

axlSphere *to_axl_sphere(dtkAbstractData *data)
{
    return dynamic_cast<axlSphere *>(data);
}

axlTorus *to_axl_torus(dtkAbstractData *data)
{
    return dynamic_cast<axlTorus *>(data);
}

axlAbstractField *to_axl_field(dtkAbstractData *data)
{
    return dynamic_cast<axlAbstractField *>(data);
}

void add(axlAbstractView *view, PyObject *data)
{
    Py_XINCREF(data);

    dtkAbstractData *arg2 ;
    void *argp2 = 0 ;
    int res2 = 0 ;

    res2 = SWIG_ConvertPtr(data, &argp2,SWIGTYPE_p_dtkAbstractData, 0);
    if (SWIG_IsOK(res2)) {
        arg2 = reinterpret_cast< dtkAbstractData * >(argp2);
        view->add(arg2);
    }
    else
        qDebug()<< "sorry but your data is not a dtkAbstractData *";
}




// View helper
/*void insert(axlAbstractView *view, axlAbstractData *data)
{
   view->dataToInsert(data);
}*/

// View helper
axlAbstractView *to_axl_view(dtkAbstractView *view)
{
    return dynamic_cast<axlAbstractView *>(view);
}

// Data & process creation helper
dtkAbstractData *newData(QString label)
{
    return dtkAbstractDataFactory::instance()->create(label);
}

// Data & process creation helper
dtkAbstractProcess *newProcess(QString label)
{
    return dtkAbstractProcessFactory::instance()->create(label);
}



%}

axlAbstractData *to_axl_data(dtkAbstractData *data);
//volume
axlAbstractVolume *to_axl_volume(dtkAbstractData *data);
axlAbstractVolumeParametric *to_axl_volume_parametric(dtkAbstractData *data);
axlAbstractVolumeImplicit *to_axl_volume_implicit(dtkAbstractData *data);
axlAbstractVolumeBSpline *to_axl_volume_bspline(dtkAbstractData *data);
axlAbstractVolumeRational *to_axl_volume_rational(dtkAbstractData *data);
//axlAbstractVolumeNurbs *to_axl_volume_nurbs(dtkAbstractData *data);

//surface
axlAbstractSurface *to_axl_surface(dtkAbstractData *data);
axlAbstractSurfaceParametric *to_axl_surface_parametric(dtkAbstractData *data);
axlAbstractSurfaceImplicit *to_axl_surface_implicit(dtkAbstractData *data);
axlAbstractSurfaceBSpline *to_axl_surface_bspline(dtkAbstractData *data);
//axlAbstractSurfaceNurbs *to_axl_surface_nurbs(dtkAbstractData *data);
axlAbstractSurfaceTrimmed *to_axl_surface_trimmed(dtkAbstractData *data);
//curve
axlAbstractCurve *to_axl_curve(dtkAbstractData *data);
axlAbstractCurveParametric *to_axl_curve_parametric(dtkAbstractData *data);
axlAbstractCurveImplicit *to_axl_curve_implicit(dtkAbstractData *data);
axlAbstractCurveBSpline *to_axl_curve_bspline(dtkAbstractData *data);
axlAbstractCurveRational *to_axl_curve_rational(dtkAbstractData *data);
//axlAbstractCurveNurbs *to_axl_curve_nurbs(dtkAbstractData *data);
//atomic data
axlCone *to_axl_cone(dtkAbstractData *data);
axlCylinder *to_axl_cylinder(dtkAbstractData *data);
axlEllipsoid *to_axl_ellipsoid(dtkAbstractData *data);
axlLine *to_axl_line(dtkAbstractData *data);
axlMesh *to_axl_mesh(dtkAbstractData *data);
axlPlane *to_axl_plane(dtkAbstractData *data);
axlPoint *to_axl_point(dtkAbstractData *data);
axlSphere *to_axl_sphere(dtkAbstractData *data);
axlTorus *to_axl_torus(dtkAbstractData *data);
//field
axlAbstractField *to_axl_field(dtkAbstractData *data);

//others
void add(axlAbstractView *view, PyObject *data);
/*void insertDataFromView(axlAbstractView *view, axlAbstractData *data);*/
axlAbstractView *to_axl_view(dtkAbstractView *view);
dtkAbstractData *newData(QString label);
dtkAbstractProcess *newProcess(QString label);

#endif
