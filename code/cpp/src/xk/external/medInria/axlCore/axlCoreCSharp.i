/* axlCoreCSharp.i --- Core layer swig interface definition
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2013 - Meriadeg Perrinel, Inria.
 * Created: Tue Jan  8 13:04:15 2009 (+0100)
 * Version: $Id$
 * Last-Updated: Jul  11 16:52 2013(+0100)
 *           By: Anais Ducoffe
 *     Update #:
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLCORECSHARP_I
#define AXLCORECSHARP_I


%module axlcore
%include "axlCoreWrap.i"


// /////////////////////////////////////////////////////////////////
// Helper functions
// /////////////////////////////////////////////////////////////////

%{

axlAbstractSurfaceBSpline *to_axl_surface_bspline(dtkAbstractData *data)
{
    return dynamic_cast<axlAbstractSurfaceBSpline *>(data);
}

axlAbstractCurveBSpline *to_axl_curve_bspline(dtkAbstractData *data)
{
    return dynamic_cast<axlAbstractCurveBSpline *>(data);
}

axlMesh *to_axl_mesh(dtkAbstractData *data)
{
    return dynamic_cast<axlMesh *>(data);
}

axlShape *to_axl_shape(dtkAbstractData *data)
{
    return dynamic_cast<axlShape *>(data);
}

axlCircleArc *to_axl_circle_arc(dtkAbstractData *data)
{
    return dynamic_cast<axlCircleArc *>(data);
}

axlMeshWriter *to_axl_mesh_writer(dtkAbstractDataWriter *data)
{
    return dynamic_cast<axlMeshWriter *>(data);
}


axlPointWriter *to_axl_point_writer(dtkAbstractDataWriter *data)
{
    return dynamic_cast<axlPointWriter *>(data);
}

%}
axlAbstractSurfaceBSpline *to_axl_surface_bspline(dtkAbstractData *data);
axlAbstractCurveBSpline *to_axl_curve_bspline(dtkAbstractData *data);
axlMesh *to_axl_mesh(dtkAbstractData *data);
axlShape *to_axl_shape(dtkAbstractData *data);
axlMeshWriter *to_axl_mesh_writer(dtkAbstractDataWriter *data);
axlPointWriter *to_axl_point_writer(dtkAbstractDataWriter *data);
axlCircleArc *to_axl_circle_arc(dtkAbstractData *data);
#endif

