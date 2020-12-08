//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)       \n
 * Copyright (c) 2003-2007 by PGMed@FIT            \n
 *
 * Author:  Petr Hyna, xhynap00@stud.fit.vutbr.cz  \n
 *          (modified by Michal Spanel)            \n
 * Date:    2007/04/12                             \n
 *
 * $Id: mdsHarris.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Harris corner detector.
 */

#ifndef MDS_ICD_HARRIS_H
#define MDS_ICD_HARRIS_H

#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Math/mdsBase.h>

#include "../mdsPixelTraits.h"
#include "../mdsImageCornerDetector.h"
#include "../mdsImageFiltering.h"
#include "../mdsVector3.h"

#include <cmath>


namespace mds
{
namespace img
{

//==============================================================================
/*!
 * Harris corner detector.
 * - It's better to smoooth input image using the Gaussian filter beforehand.
 * - Parameter I is a used image type.
 */
template <class I>
class CHarris : public CImageCornerDetector<I>
{
public:
    //! Image corner detector base.
    typedef CImageCornerDetector<I> base;
    typedef typename base::tImage tImage;
    typedef typename base::tPixel tPixel;

public:
    //! Constructor.
    //! - Standard deviation of gaussian window used to estimate eigen values.
    //! - Cornerness threshold.
    //! - Tuneable parameter.
    CHarris(double dSigma, double dThreshold, double dKappa)
        : m_GaussFilter(dSigma)
        , m_dThreshold(dThreshold)
		, m_dKappa(dKappa)
    {
        MDS_ASSERT(dThreshold <= 1000 && dKappa <= 0.25 && dKappa >= 0.01);
    }

    //! Destructor.
    ~CHarris() {}
 

    //! Corner detection in a given image.
    //! - Magnitude image is produced.
    //! - Returns false on failure.
    bool operator()(const tImage& SrcImage, tImage& DstImage);

    //! Returns threshold of the non-maximal suppression algorithm.
    double getThreshold() { return m_dThreshold; }

    //! Sets threshold of the non-maximal suppression algorithm.
    inline void setThreshold(double dThreshold);

	//! Returns width of the filter for getting corners.
    double getKappa() { return m_dKappa; }

    //! Sets width of the filter for gettig corners.
    inline void setKappa(double dKappa);

protected:
    //! Gaussian filter.
    CGaussFilter<CFImage> m_GaussFilter;    
    CSobelX<CFImage> m_SobelX;
    CSobelY<CFImage> m_SobelY;

    //! Harris corner detector parameters.
	double m_dThreshold, m_dKappa;

protected:
    //! Returns true if any neighbouring pixel has greater value
    //! than a given threshold.
    bool checkNeighbours(CFImage& Image, tSize x, tSize y, tFloatPixel T);
};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "mdsHarris.hxx"


} // namespace img
} // namespace mds

#endif // MDS_ICD_HARRIS_H

