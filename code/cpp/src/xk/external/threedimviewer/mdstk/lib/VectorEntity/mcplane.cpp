////////////////////////////////////////////////////////////
// $Id: mcplane.cpp 1451 2009-04-22 07:42:32Z spanel $
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// includes

#include <VectorEntity/mcplane.h>

using namespace vctl;

MCPlane::MCRelativePosition MCPlane::Position(MCVertex * v1, MCVertex * v2, MCVertex & intersection)
{
    IsValid();
    double dv1 = ToPlaneEquation(v1);
    double dv2 = ToPlaneEquation(v2);
    if(fabs(dv1) < DOUBLE_MIN)
    {
        if(fabs(dv2) < DOUBLE_MIN)
            return BOTH_IN_PLANE;
        else
        {
            intersection.SetX(v1->GetX());
            intersection.SetY(v1->GetY());
            intersection.SetZ(v1->GetZ());
            return FIRST_VERTEX_IN_PLANE;
        }
    }
    else if(fabs(dv2) < DOUBLE_MIN)
    {
        intersection.SetX(v2->GetX());
        intersection.SetY(v2->GetY());
        intersection.SetZ(v2->GetZ());
        return SECOND_VERTEX_IN_PLANE;
    }
    else if((dv1 * dv2) < 0.0)
    {
        double u = dv1 / (dv1 - dv2);
        edgeVector.Make(v1, v2);
        intersection.SetX(v1->GetX() + u * edgeVector.GetX());
        intersection.SetY(v1->GetY() + u * edgeVector.GetY());
        intersection.SetZ(v1->GetZ() + u * edgeVector.GetZ());
        return INTERSECTS;
    }
    else
        return OUT_OF_PLANE;
}

