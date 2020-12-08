//=============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2007 by PGMed@FIT         \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/06/21                          \n
 *
 * $Id: mdsSusan.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Modified Susan corner detector.
 */

#ifndef MDS_ICD_SUSAN_H
#define MDS_ICD_SUSAN_H

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
 * Modified Susan corner detector.
 * - Parameter I is a used image type.
 */
template <class I>
class CSusanDetector : public CImageCornerDetector<I>
{
public:
    //! Image corner detector base.
    typedef CImageCornerDetector<I> base;
    typedef typename base::tImage tImage;
    typedef typename base::tPixel tPixel;

    //! Maximal value stored in the internal lookup table.
    enum { MAX_LUT = 255 };

    //! Size of the internal lookup table.
    enum { LUT_SIZE = 2 * MAX_LUT + 1 };

    //! Threshold used to suppress non-corner points.
    enum { DIFF_THRESHOLD = 700 };

public:
    //! Constructor.
    //! - First parameter represents normalized detection threshold. 
    //! - Second parameter affects evaluation of difference of two pixels.
    inline CSusanDetector(double dThreshold, double dWidth = 20.0);

    //! Destructor.
    ~CSusanDetector() {}


    //! Corner detection in a given image.
    //! - Magnitude image is produced.
    //! - Returns false on failure.
    bool operator()(const tImage& SrcImage, tImage& DstImage);

    //! Returns detection threshold.
    double getThreshold() { return m_dThreshold; }

    //! Sets the detection threshold.
    inline void setThreshold(double dThreshold);

    //! Returns the width parameter.
    double getWidth() { return m_dWidth; }

    //! Sets the width parameter.
    inline void setWidth(double dWidth);

protected:
    //! Susan corner detector parameters.
	double m_dThreshold, m_dWidth, m_dInvWidth;

    //! Internal lookup table used for fast computation of the exp() function.
    mds::math::CStaticVector<int, LUT_SIZE> m_LUT;

protected:
    //! Returns true if any neighbouring pixel has greater value
    //! than a given threshold.
    bool checkNeighbours(CFImage& Image, tSize x, tSize y, tFloatPixel T);

    //! Initializes internal lookup table.
    void initLUT();

    //! Returns difference of two given pixels.
    inline int getDiff(int a, int b);
};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "mdsSusan.hxx"


} // namespace img
} // namespace mds

#endif // MDS_ICD_SUSAN_H

