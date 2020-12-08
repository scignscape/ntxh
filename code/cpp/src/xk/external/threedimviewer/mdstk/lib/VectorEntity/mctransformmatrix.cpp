////////////////////////////////////////////////////////////
// $Id: mctransformmatrix.cpp 2088 2012-02-13 12:04:18Z spanel $
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// include soubory

#include <VectorEntity/mctransformmatrix.h>

using namespace vctl;

////////////////////////////////////////////////////////////
//

MCTransformMatrix & MCTransformMatrix::makeRotateX(double rotation_angle)
{
    // 1.0,  0.0,    0.0,    0.0, 
    // 0.0,  cosa,   sina,   0.0, 
    // 0.0,  -sina,  cosa,   0.0, 
    // 0.0,  0.0,    0.0,    1.0

    // calculatce sin and cos functions for given angle
    double cosa = cos(rotation_angle); 
    double sina = sin(rotation_angle); 

    // set identity matrix
    this->makeIdentity();

    // set matrix values
    set(1, 1, cosa);
    set(1, 2, sina);
    set(2, 1, -sina);
    set(2, 2, cosa);

    // return result matrix
    return *this;
}

////////////////////////////////////////////////////////////
//

MCTransformMatrix & MCTransformMatrix::makeRotateY(double rotation_angle)
{
    // cose,  0.0  sine, 0.0, 
    // 0.0,   1.0, 0.0,  0.0, 
    // -sine, 0.0, cose, 0.0, 
    // 0.0,   0.0, 0.0,  1.0

    // calculatce sin and cos functions for given angle
    double cosa = cos(rotation_angle); 
    double sina = sin(rotation_angle); 

    // set identity matrix
    makeIdentity();

    // set matrix values
    set(0, 0, cosa);
    set(0, 2, sina);
    set(2, 0, -sina);
    set(2, 2, cosa);

    // return result matrix
    return *this;
}

////////////////////////////////////////////////////////////
//

MCTransformMatrix & MCTransformMatrix::makeRotateZ(double rotation_angle)
{
    // cose,  sine, 0.0, 0.0, 
    // -sine, cose, 0.0, 0.0, 
    // 0.0,   0.0,  1.0, 0.0, 
    // 0.0,   0.0,  0.0, 1.0

    // calculatce sin and cos functions for given angle
    double cosa = cos(rotation_angle); 
    double sina = sin(rotation_angle); 

    // set identity matrix
    makeIdentity();

    // set matrix values
    set(0, 0, cosa);
    set(0, 1, sina);
    set(1, 0, -sina);
    set(1, 1, cosa);

    // return result matrix
    return *this;
}

////////////////////////////////////////////////////////////
//

MCTransformMatrix & MCTransformMatrix::makeTranslation(double dx, double dy, double dz)
{
    // 1.0,  0.0,  0.0, 0.0, 
    // 0.0,  1.0,  0.0, 0.0, 
    // 0.0,  0.0,  1.0, 0.0, 
    // dx,   dy,   dz,  1.0

    // set identity matrix
    makeIdentity();

    // set matrix values
    set(3, 0, dx);
    set(3, 1, dy);
    set(3, 2, dz);

    // return result matrix
    return *this;
}

////////////////////////////////////////////////////////////
//

MCTransformMatrix & MCTransformMatrix::makeScale(double sx, double sy, double sz)
{
    // sx,   0.0,  0.0, 0.0, 
    // 0.0,  sy,   0.0, 0.0, 
    // 0.0,  0.0,  sz,  0.0, 
    // 0.0,  0.0,  0.0, 1.0

    // set identity matrix
    makeIdentity();

    // set matrix values
    set(0, 0, sx);
    set(1, 1, sy);
    set(2, 2, sz);

    // return result matrix
    return *this;
}

////////////////////////////////////////////////////////////
//

MCTransformMatrix & MCTransformMatrix::addRotateX(double rotation_angle)
{
    // multiplicate rotation matrix to the matrix
    postMult(MCTransformMatrix().makeRotateX(rotation_angle));

    // return result matrix
    return *this;
}

////////////////////////////////////////////////////////////
//

MCTransformMatrix & MCTransformMatrix::addRotateY(double rotation_angle)
{
    // multiplicate rotation matrix to the matrix
    postMult(MCTransformMatrix().makeRotateY(rotation_angle));

    // return result matrix
    return *this;
}

////////////////////////////////////////////////////////////
//

MCTransformMatrix & MCTransformMatrix::addRotateZ(double rotation_angle)
{
    // multiplicate rotation matrix to the matrix
    postMult(MCTransformMatrix().makeRotateZ(rotation_angle));

    // return result matrix
    return *this;
}

////////////////////////////////////////////////////////////
//

MCTransformMatrix & MCTransformMatrix::addScale(double sx, double sy, double sz)
{
    MCTransformMatrix       tm;         // temporary matrix

    // make rotation transfromation
    tm.makeScale(sx, sy, sz);

    // multiplicate rotation to the matrix
    this->postMult(tm);

    // return result matrix
    return *this;
}

////////////////////////////////////////////////////////////
//

MCTransformMatrix & MCTransformMatrix::addTranslation(double dx, double dy, double dz)
{
    MCTransformMatrix       tm;         // temporary matrix

    // make rotation transfromation
    tm.makeTranslation(dx, dy, dz);

    // multiplicate rotation to the matrix
    this->postMult(tm);

    // return result matrix
    return *this;
}

////////////////////////////////////////////////////////////
//

MCTransformMatrix::tCoords3 MCTransformMatrix::preMult(const tCoords3 & v, mds::img::tCoordinate coord_weight) const
{
    mds::img::tCoordinate x = v.x() * at(0,0) + v.y() * at(1,0) + v.z() * at(2,0) + coord_weight * at(3, 0);
    mds::img::tCoordinate y = v.x() * at(0,1) + v.y() * at(1,1) + v.z() * at(2,1) + coord_weight * at(3, 1);
    mds::img::tCoordinate z = v.x() * at(0,2) + v.y() * at(1,2) + v.z() * at(2,2) + coord_weight * at(3, 2);

    return tCoords3(x, y, z);
}


////////////////////////////////////////////////////////////
//

void MCTransformMatrix::preMult2(tCoords3 & v, mds::img::tCoordinate coord_weight) const
{
    mds::img::tCoordinate x = v.x() * at(0,0) + v.y() * at(1,0) + v.z() * at(2,0) + coord_weight * at(3, 0);
    mds::img::tCoordinate y = v.x() * at(0,1) + v.y() * at(1,1) + v.z() * at(2,1) + coord_weight * at(3, 1);
    mds::img::tCoordinate z = v.x() * at(0,2) + v.y() * at(1,2) + v.z() * at(2,2) + coord_weight * at(3, 2);

    v.x() = x;
    v.y() = y;
    v.z() = z;
}

////////////////////////////////////////////////////////////
//

void MCTransformMatrix::preMult(const tCoords3 & v, mds::img::tCoordinate coord_weight, tCoords3 & r) const
{
    r.x() = v.x() * at(0,0) + v.y() * at(1,0) + v.z() * at(2,0) + coord_weight * at(3, 0);
    r.y() = v.x() * at(0,1) + v.y() * at(1,1) + v.z() * at(2,1) + coord_weight * at(3, 1);
    r.z() = v.x() * at(0,2) + v.y() * at(1,2) + v.z() * at(2,2) + coord_weight * at(3, 2);
}

////////////////////////////////////////////////////////////
//

void MCTransformMatrix::postMult(const MCTransformMatrix & mm)
{
    tMatrix44 tm = *this;           // temporary matrix

    // cycle for matrices multiplication
    for( mds::tSize i = 0; i < 4; ++i )
    {
        for( mds::tSize j = 0; j < 4; ++j )
        {
            // calculate new matrix value
            this->set(i, j, tm(i, 0) * mm(0, j) + tm(i, 1) * mm(1, j) + tm(i, 2) * mm(2, j) + tm(i, 3) * mm(3, j) );
        }
    }
}

////////////////////////////////////////////////////////////
//

void MCTransformMatrix::makeIdentity()
{
    // set matrix values
    set(0, 0, 1.0);
    set(0, 1, 0.0);
    set(0, 2, 0.0);
    set(0, 3, 0.0);

    set(1, 0, 0.0);
    set(1, 1, 1.0);
    set(1, 2, 0.0);
    set(1, 3, 0.0);
    
    set(2, 0, 0.0);
    set(2, 1, 0.0);
    set(2, 2, 1.0);
    set(2, 3, 0.0);
    
    set(3, 0, 0.0);
    set(3, 1, 0.0);
    set(3, 2, 0.0);
    set(3, 3, 1.0);
}

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
