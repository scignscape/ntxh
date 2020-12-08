//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)        \n
 * Copyright (c) 2003-2005 by Michal Spanel         \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz      \n
 * Date:    2005/10/07                              \n
 *
 * $Id: mdsZeroCrossings.h 1863 2010-08-31 20:40:15Z spanel $
 * 
 * Description:
 * - Zero crossings of the LoG filter.
 */

#ifndef MDS_IED_ZEROCROSSINGS_H
#define MDS_IED_ZEROCROSSINGS_H

#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Math/mdsBase.h>

#include "../mdsPixelTraits.h"
#include "../mdsImageEdgeDetector.h"
#include "../mdsImageFiltering.h"

#include <cmath>


namespace mds
{
namespace img
{

//==============================================================================
/*!
 * Zero crossings of the LoG filter.
 * - Parameter I is a used image type.
 */
template <class I>
class CZeroCrossDetector : public CImageEdgeDetector<I>
{
public:
    //! Image edge detector base.
    typedef CImageEdgeDetector<I> base;
    typedef typename base::tImage tImage;
    typedef typename base::tPixel tPixel;

public:
    //! Default constructor.
    //! - Standard deviation ("sigma" parameter) of the LoG filter.
    //! - Threshold for the gradient magnitude.
    CZeroCrossDetector(double dSigma, double dThreshold)
        : m_Filter(dSigma)
        , m_dThreshold(dThreshold)
    {
        MDS_ASSERT(dThreshold <= 1.0 && dThreshold >= 0.0);
    }

    //! Destructor.
    ~CZeroCrossDetector() {}


    //! Edge detection in a given image.
    //! - Returns false on failure
    bool operator()(const tImage& SrcImage, tImage& DstImage);

    //! Returns LoG filter standard deviation.
    double getSigma() const { return m_Filter.getSigma(); }

    //! Sets the LoG filter standard deviation.
    void setSigma(double dSigma) { m_Filter.setSigma(dSigma); }

    //! Return threshold for the gradient magnitude.
    double getThreshold() { return m_dThreshold; }

    //! Returns gradient magnitude threshold.
    inline void setThreshold(double dThreshold);

protected:
    //! LoG filter.
    CLoGFilter<tImage, CShiftZero2Gray> m_Filter;

    //! Magnitude threshold.
    double m_dThreshold;

protected:
    //! Checks if the pixel is on edge.
    inline bool isEdge(const tImage& Image, tSize x, tSize y);

    //! Computes the gradient magnitude.
    inline double computeGradient(const tImage& Image, tSize x, tSize y);
};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "mdsZeroCrossings.hxx"


} // namespace img
} // namespace mds

#endif // MDS_IED_ZEROCROSSINGS_H

