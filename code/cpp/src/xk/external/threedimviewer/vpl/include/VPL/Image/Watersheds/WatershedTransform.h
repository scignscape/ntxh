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
 * Medical Data Segmentation Toolkit (MDSTk)            \n
 * Copyright (c) 2003-2009 by Michal Spanel             \n
 *
 * Authors: Jiri Zahradka, xzahra14@stud.fit.vutbr.cz   \n
 *          Michal Spanel, spanel@fit.vutbr.cz          \n
 * Date:    2008/12/19                                  \n
 *
 * $Id:
 *
 * File description:
 * - Implementation of a watershed transformation.
 */

#ifndef VPL_WatershedTransform_H
#define VPL_WatershedTransform_H

#include <VPL/Base/StaticAssert.h>
#include <VPL/Base/HasOptions.h>

#include "../Image.h"
#include "../ImageFunctions/General.h"

// STL
#include <vector>
#include <deque>


namespace vpl
{
namespace img
{

//==============================================================================
/*
 * Type definitions.
 */

namespace WatershedTransform
{
    //! Watershed transform options.
    enum EOptions
    {
        BASINS      = 1,    //! Produces an image containing labelled basins (default).
        WATERSHEDS  = 2     //! Produces watersheds instead of region labels.
    };
}


//==============================================================================
/*!
 * Class providing watershed transform.
 * - Fast-watersheds algorithm.
 * - The algorithm cannot be applied to float images.
 * - Parameter I is an image type.
 */
template <class I>
class CWatershedTransform : public vpl::base::CHasOptions
{
public:
    //! Check that I is an image. You will see name of this enum somewhere
    //! in compiler error message if the type I is not image.
    enum { TEMPLATE_PARAMETER_IS_NOT_IMAGE = I::CLASS_IMAGE };

    //! Input image type.
	typedef typename I::tImage tImage;

	//! Input image pixel type.
	typedef typename I::tPixel tPixel;

    //! Output image containing labels of found image regions.
    typedef CImage32 tRegionImage;

	//! Output image pixel type.
	typedef typename CImage32::tPixel tRegionNumber;

public:
    //! Constructor.
    CWatershedTransform(int Flags = WatershedTransform::BASINS)
        : vpl::base::CHasOptions(Flags)
        , m_CurrentRegion(0)
    {
        // Check whether the image pixels is a fundamental integral type
        VPL_STATIC_ASSERT(CTypeTraits<tPixel>::isFundamental && CTypeTraits<tPixel>::isIntegral,
                          IMAGE_PIXEL_IS_NOT_A_FUNDAMENTAL_INTEGRAL_TYPE
                          );
    }

    //! Destructor.
	~CWatershedTransform() {}

	//! Estimates watershed transform of a given edge image.
	//! - Produces a label image whose image pixels represent indexes
	//!   of image regions.
	bool operator()(const tImage& SrcImage, tRegionImage& DstImage);

	//! Returns the final number of regions.
	int getNumOfRegions() const { return int(m_CurrentRegion); }

protected:
    //! Histogram (queue) item.
    typedef std::pair<tSize, tSize> tPixelInfo;

    //! Image histogram column.
    typedef std::deque<tPixelInfo> tQueue;

    //! Image histogram.
    typedef std::vector<tQueue> tHistogram;

    //! Helper distance image.
    typedef CImage16 tDistanceImage;

    //! Distance from a region minimum.
    typedef typename CImage16::tPixel tDistance;

protected:
    //! Helper distance image.
    tDistanceImage m_DistanceImage;

    //! Labeled image.
    tRegionImage m_RegionImage;

    //! Input image histogram.
    tHistogram m_Histogram;

    //! Number of regions.
    tRegionNumber m_CurrentRegion;

protected:
    //! Prepares the image histogram.
    void createHistogram(const tImage& SrcImage);

    //! Clears the histogram.
    void clearHistogram();

    //! Prepares all pixels whose intensity is equal to a given level for further processing.
    //! - All pixels marked using the MASK value are going to be flooded.
    void preparePixels(tQueue& Fifo, int Level);

    //! V z�vislosti na ��slech okoln�ch region� je nastaveno ��slo regionu aktu�ln�ho pixelu.
    //! - Sousedn� pixely,kter� maj� ��slo regionu MASK a vzd�lenost od povod� 0, p�id� do fronty
    //!   k dal��mu zpracov�n� a nastav� jim novou vzd�lenost od povod�.
    void assignRegionNumber(const tPixelInfo& Point,
                            tQueue& Fifo,
                            tDistance CurrentDistance
                            );

    //! Zkou�� naj�t nov� lok�ln� minima na �rovn� dan� parametrem level
    //! - Pokud je nov� minimum nalezeno pokou�� se o jeho zv�t�en�/rozta�en� testov�n�m a p�id�v�n�m okoln�ch bod�
    bool checkNewMinima(tQueue& Fifo, int Level);

    //! Copies data from the internal helper segmented image.
    //! Labels all border pixels (watersheds) with respect to the neighbouring regions.
    void clearBorderPixels(tRegionImage& Image);

    //! Copies data from the internal helper segmented image.
    //! Marks all border pixels.
    void makeBorderPixels(tRegionImage& Image);
};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "WatershedTransform.hxx"


} // namespace vpl
} // namespace img

#endif // VPL_WatershedTransform_H
