//==============================================================================
/* This file comes from MDSTk software and was modified for
 * 
 * VPL - Voxel Processing Library
 * Changes are Copyright 2014 3Dim Laboratory s.r.o.
 * All rights reserved.
 * 
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 * 
 * The original MDSTk legal notice can be found below.
 * 
 * Medical Data Segmentation Toolkit (MDSTk) 
 * Copyright (c) 2003-2006 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/04/26                       
 * 
 * Description:
 * - 3D Gaussian smoothing filter.
 */

#ifndef VPL_VF_GAUSSIAN_H
#define VPL_VF_GAUSSIAN_H

#include <VPL/Base/Assert.h>
#include <VPL/Math/Base.h>
#include <VPL/Module/Progress.h>

#include "../SeparableVolumeFilter.h"
#include "../VolumeFunctions.h"
#include "../Kernel.h"

#include <cmath>


namespace vpl
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
 *                    (2 * pi)^3/2 * sigma^3            2 * sigma^2  
 */
template <class V>
class CVolumeGaussFilter
    : public CSeparableVolumeFilter<V>
    , public vpl::mod::CProgress
{
public:
    //! Volume filter base.
    typedef CSeparableVolumeFilter<V> base;
    typedef typename base::tVolume tVolume;
    typedef typename base::tVoxel tVoxel;

    //! Subvolume block size
    enum { BLOCK_SIZE = 128 };

public:
    //! Constructor that creates Gaussian filter having a specified standard
    //! deviation ("sigma" parameter).
    CVolumeGaussFilter(double dSigma)
    {
        VPL_ASSERT(dSigma > 0.0);

        initializeKernels(dSigma);
    }

    //! Constructor that creates Gaussian filter having the standard
    //! deviation corresponding to a given kernel size.
    CVolumeGaussFilter(tSize Size) 
    {
        initializeKernels(size2Sigma(Size));
    }

    //! Destructor
    ~CVolumeGaussFilter() {}


    //! Filtering of input/source image. Point filter responses are written
    //! to the destination image.
    //! - Returns false on failure.
    bool operator()(const tVolume& SrcVolume, tVolume& DstVolume);

    //! Returns filter response at specified volume point.
    //! - Value is not normalized!
    tVoxel getResponse(const tVolume& SrcVolume, tSize x, tSize y, tSize z);

    //! Returns filter standard deviation.
    double getSigma() const { return m_dSigma; }

    //! Returns filter standard deviation.
    virtual tSize getSize() const
    {
        return std::max(base::m_kernelX.getSize(), std::max(base::m_kernelY.getSize(), base::m_kernelZ.getSize()));
    }

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
    void initializeKernels(double dSigma);
};



//==============================================================================
/*!
 * 3D Gaussian smoothing filter having kernel 3x3x3.
 * - Parameter V is a used volume type.
 * - Kernel definition: \n
 *    [ 0  1  0 ]
 *    [ 1  3  1 ]
 *    [ 0  1  0 ]
 *   1 [ 1  3  1 ]  \n
 *  -- [ 3  9  3 ]  \n
 *  39 [ 1  3  1 ]  \n
 *      [ 0  1  0 ] \n
 *      [ 1  3  1 ] \n
 *      [ 0  1  0 ] \n
 */
template <class V>
class CVolumeGauss3Filter : public CVolumeFilter<V>, public vpl::mod::CProgress
{
public:
    //! Volume filter base.
    typedef CSeparableVolumeFilter<V> base;
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
    virtual tSize getSize() const { return 3; }

};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "Gaussian.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_VF_GAUSSIAN_H

