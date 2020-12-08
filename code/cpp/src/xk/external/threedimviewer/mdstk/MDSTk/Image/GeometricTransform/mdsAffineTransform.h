//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2009 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2008/12/16                          \n
 *
 * $Id: mdsAffineTransform.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Geometrical image transformations.
 */

#ifndef MDS_AffineTransform_H
#define MDS_AffineTransform_H

#include <MDSTk/Math/mdsBase.h>

#include "mdsImageTransform.h"
#include "mdsAffineMatrix.h"


namespace mds
{
namespace img
{

//==============================================================================
/*!
 * Base class for all geometrical image transformations.
 */
template <class I, template <typename> class Interpolator>
class CAffineTransform : public CImageTransform<I,Interpolator>
{
public:
    // Base types.
    typedef CImageTransform<I,Interpolator> tBase;
    typedef typename tBase::tImage tImage;
    typedef typename tBase::tPixel tPixel;
    using tBase::interpolate;

    //! Affine transformation matrix.
    typedef CAffineMatrix tMatrix;

    //! Point/vector coordinates.
    typedef typename CAffineMatrix::tCoords3 tCoords3;

public:
    //! Default constructor.
    CAffineTransform(int iFlags = 0) : tBase(iFlags) {}

    //! Virtual destructor.
    virtual ~CAffineTransform() {}

    //! Applies the geometrical transformation.
    //! - Returns false on failure.
    virtual bool operator()(const tImage& SrcImage, tImage& DstImage);

    //! Changes the transformation matrix.
    void setMatrix(const tMatrix& m)
    {
        m_InvMatrix = m_Matrix = m;
        m_InvMatrix.invert();
    }

    //! Returns the current transformation matrix.
    const tMatrix& getMatrix() const { return m_Matrix; }
    const tMatrix& getInvMatrix() const { return m_InvMatrix; }

    //! Forward point transformation.
    tCoords3 warp(const tCoords3& v) const
    {
        return m_Matrix.preMult(v);
    }
    void warp2(tCoords3& v) const
    {
        m_Matrix.preMult2(v);
    }
    void warp(const tCoords3& Src, tCoords3& Dst) const
    {
        m_Matrix.preMult(Src, Dst);
    }

    //! Backward point transformation.
    tCoords3 warpBack(const tCoords3& v) const
    {
        return m_InvMatrix.preMult(v);
    }
    void warpBack2(tCoords3& v) const
    {
        m_InvMatrix.preMult2(v);
    }
    void warpBack(const tCoords3& Src, tCoords3& Dst) const
    {
        m_InvMatrix.preMult(Src, Dst);
    }

protected:
    //! Forward and backward transformation matrix.
    tMatrix m_Matrix, m_InvMatrix;
};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "mdsAffineTransform.hxx"


} // namespace img
} // namespace mds

#endif // MDS_AffineTransform_H
