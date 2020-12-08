//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/04/26                          \n
 *
 * $Id: mdsGaussian.h 1863 2010-08-31 20:40:15Z spanel $
 * 
 * Description:
 * - 3D Gaussian smoothing filter.
 */

#ifndef MDS_VF_GAUSSIAN_H
#define MDS_VF_GAUSSIAN_H

#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Math/mdsBase.h>
#include <MDSTk/Module/mdsProgress.h>

#include "../mdsVolumeFilter.h"
#include "../mdsVolumeFunctions.h"
#include "../mdsKernel.h"

#include <cmath>


namespace mds
{
namespace img
{

//==============================================================================
/*!
 * 3D Gaussian smoothing filter.
 * - Parameter V is a volume type.
 * - Policy N is used for filter response normalization.
 * - Gaussian filter kernel is defined by the following function: \n
 *                         1                         (x^2 + y^2 + z^2)  \n
 *   G_sigma(x,y,z) = ---------------------- * exp(- -----------------) \n
 *                    (2 * pi)^3/2 * sigma^3            2 * sigma^2     \n
 */
template <class V>
class CVolumeGaussFilter
    : public CVolumeFilter<V>
    , public CKernel3D
    , public mds::mod::CProgress
{
public:
    //! Volume filter base.
    typedef CVolumeFilter<V> base;
    typedef typename base::tVolume tVolume;
    typedef typename base::tVoxel tVoxel;

public:
    //! Constructor that creates Gaussian filter having a specified standard
    //! deviation ("sigma" parameter).
    CVolumeGaussFilter(double dSigma) : CKernel3D(sigma2Size(dSigma))
    {
        MDS_ASSERT(dSigma > 0.0);

        initKernel(dSigma);
    }

    //! Constructor that creates Gaussian filter having the standard
    //! deviation corresponding to a given kernel size.
    CVolumeGaussFilter(tSize Size) : CKernel3D(Size)
    {
        initKernel(size2Sigma(Size));
    }

    //! Destructor
    ~CVolumeGaussFilter() {}


    //! Filtering of input/source image. Point filter responses are written
    //! to the destination image.
    //! - Returns false on failure.
    bool operator()(const tVolume& SrcVolume, tVolume& DstVolume);

    //! Returns filter response at specified volume point.
    //! - Value is not normalized!
    tVoxel getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z)
    {
        // Compute filter response
        return tVoxel(convolve<CKernel3D::tData>(SrcVolume, x, y, z, *this));
    }

    //! Returns filter standard deviation.
    double getSigma() const { return m_dSigma; }

    //! Sets the filter size.
    inline void resize(tSize Size);

    //! Sets the filter standard deviation.
    inline void setSigma(double dSigma);


    //! Returns kernel size corresponding to a given sigma parameter.
    inline static tSize sigma2Size(double dSigma);

    //! Returns sigma parametr according to a given kernel size.
    inline static double size2Sigma(tSize Size);

    //! Returns value of the Gaussian function.
    inline static double getGaussianFuncValue(double dX,
                                              double dY,
                                              double dZ,
                                              double dSigma
                                              );

protected:
    //! Standard deviation ("sigma") of the Gaussian filter.
    double m_dSigma;

protected:
    //! Computes the Gaussian filter kernel.
    void initKernel(double dSigma);
};


//==============================================================================
/*!
 * 3D Gaussian smoothing filter having kernel 3x3x3.
 * - Parameter V is a used volume type.
 * - Kernel definition: \n
 *    [ 0  1  0 ]   \n
 *    [ 1  3  1 ]   \n
 *    [ 0  1  0 ]   \n
 *   1 [ 1  3  1 ]  \n
 *  -- [ 3  9  3 ]  \n
 *  39 [ 1  3  1 ]  \n
 *      [ 0  1  0 ] \n
 *      [ 1  3  1 ] \n
 *      [ 0  1  0 ] \n
 */
template <class V>
class CVolumeGauss3Filter : public CVolumeFilter<V>, public mds::mod::CProgress
{
public:
    //! Volume filter base.
    typedef CVolumeFilter<V> base;
    typedef typename base::tVolume tVolume;
    typedef typename base::tVoxel tVoxel;

public:
    //! Number used to divide filter response
    static const int DENOM = 39;

    //! Filter kernel
    static const CKernel3D::tData KERNEL[];

public:
    //! Default constructor.
    CVolumeGauss3Filter() {}

    //! Destructor.
    ~CVolumeGauss3Filter() {}

    //! Filtering of input/source volume.
    //! - Returns false on failure
    bool operator()(const tVolume& SrcVolume, tVolume& DstVolume);

    //! Returns filter response at specified volume position.
    //! - Value is not normalized!
    tVoxel getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z);

    //! Returns filter standard deviation.
    tSize getSize() const { return 3; }

};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "mdsGaussian.hxx"


} // namespace img
} // namespace mds

#endif // MDS_VF_GAUSSIAN_H

