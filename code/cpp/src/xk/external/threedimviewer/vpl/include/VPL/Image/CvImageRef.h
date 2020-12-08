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
 * Copyright (c) 2010 by Michal Spanel       
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2010/01/19                       
 *
 * Description:
 * - Provides reference counting mechanism on OpenCV images.
 */

#ifndef VPL_CvImageRef_H
#define VPL_CvImageRef_H

#include <VPL/Base/Setup.h>

#ifdef VPL_OPENCV_ENABLED

#include <VPL/Base/RefData.h>
#include <VPL/Base/Exception.h>

#include "CvTraits.h"

// OpenCV
#include <opencv2/core/core_c.h>
//#include <cv.h>


namespace vpl
{
namespace img
{

//==============================================================================
/*
 * Global definitions.
 */

namespace cv
{
    //! Exception thrown when OpenCV functions like cvCreateImage() have failed.
    VPL_DECLARE_EXCEPTION(CBadImageAlloc, "Failed to allocate IplImage struct or image data")
}


//==============================================================================
/*!
 * Class template providing mechanism of reference counting
 * to IplImage data (see the OpenCV library documentation).
 */
template <typename T>
class CvImageRef
{
public:
    //! Image pixel type.
    typedef T tData;

public:
    //! Default constructor allocates data of zero size.
    //! - Throws vpl::img::cv::CBadImageAlloc() exception on failure.
    inline CvImageRef();

    //! This constructor does no allocation of the data.
    //! - Be sure that one of the methods resize(), copy() or makeRef()
    //!   are used somewhere!
    //! - Use with care!
    inline CvImageRef(EEmptyConst);

    //! Destructor.
    inline ~CvImageRef();

    //! Allocates image data of a given size.
    //! - In case of several references to the existing data, the reference
    //!   counter is decremented and new data are allocated.
    //! - Returns reference to this.
    //! - Throws vpl::img::cv::CBadImageAlloc() exception on failure.
    inline CvImageRef& resize(tSize Width, tSize Height);

    //! Creates a subimage of a given image.
    //! - Makes own copy of the data.
    //! - Throws vpl::img::cv::CBadImageAlloc() exception on failure.
    inline CvImageRef& copy(const CvImageRef& Data,
                            tSize Col,
                            tSize Row,
                            tSize Width,
                            tSize Height
                            );

    //! Allocates image data and copies the specified one.
    //! - Returns reference to this.
    //! - Throws vpl::img::cv::CBadImageAlloc() exception on failure.
    inline CvImageRef& copy(const CvImageRef& Data);

    //! Creates reference to a part of the given image.
    //! - Makes reference to the data.
    //! - Throws vpl::img::cv::CBadImageAlloc() exception on failure.
    inline CvImageRef& makeRef(const CvImageRef& Data,
                               tSize Col,
                               tSize Row,
                               tSize Width,
                               tSize Height
                               );

    //! Makes a new reference to existing image data.
    //! - Returns reference to this.
    //! - Throws vpl::img::cv::CBadImageAlloc() exception on failure.
    inline CvImageRef& makeRef(const CvImageRef& Data);

    //! Creates image from the IplImage image.
    //! - Takes full control over the image including deallocation of the memory!
    //! - Returns reference to this.
    inline CvImageRef& fromIpl(IplImage *pImage);

    //! Decreases the number of references and deallocates
    //! the image data if neccessary.
    //! - Use with care!
    inline CvImageRef& detach();


    //! Returns pointer to the IplImage.
    const IplImage *asIpl() const { return m_pImage; }
    IplImage *asIpl() { return m_pImage; }

    //! Returns IplImage image width.
    int getWidth() const { return m_pImage->width; }

    //! Returns IplImage height.
    int getHeight() const { return m_pImage->height; }

    //! Returns the image depth (see predefined OpenCV constants).
    int getDepth() const { return CvTraits<T>::getDepth(); }

    //! Returns the number of channels.
    int getChannels() const { return CvTraits<T>::getChannels(); }

    //! Returns pixel size in bytes.
    int getPixelSize() const { return CvTraits<T>::getPixelSize(); }

    //! Returns offset between two neighbouring elements in a column.
    int getRowOffset() const { return CvTraits<T>::convWidthStep(m_pImage->widthStep); }

    //! Returns offset between two neighbouring elements in a row.
    int getColOffset() const { return 1; }

    //! Returns the number of references to the data.
    int getNumOfReferences() const { return m_pRef ? m_pRef->m_iReferences : 0; }


    //! Returns pointer to the underlying image data.
    T *getPtr()
    {
        return reinterpret_cast<T *>(m_pImage->imageData);
    }
    const T *getPtr() const
    {
        return reinterpret_cast<const T *>(m_pImage->imageData);
    }

    //! Returns size of the underlying image data in pixels.
    int getSize() const
    {
        return m_pImage->height * CvTraits<T>::convWidthStep(m_pImage->widthStep);
    }


    //! Creates ROI within the current image (see OpenCV linbrary for details).
    //! - If any ROI already exists, its coordinates are taken into acocunt as well.
    inline CvImageRef& makeROI(int Col, int Row, int Width, int Height);

    //! Returns the current ROI within the image (see OpenCV linbrary for details).
    CvRect getROI() const
    {
        return cvGetImageROI(m_pImage);
    }

    //! Returns the ROI width.
    int getROIWidth() const { return m_pImage->roi ? m_pImage->roi->width : m_pImage->width; }

    //! Returns the ROI height.
    int getROIHeight() const { return m_pImage->roi ? m_pImage->roi->height : m_pImage->height; }

    //! Returns pointer to the ROI image data.
    T *getROIPtr()
    {
        int Offset = m_pImage->roi ? m_pImage->roi->yOffset * m_pImage->widthStep + m_pImage->roi->xOffset : 0;
        return reinterpret_cast<T *>(m_pImage->imageData + Offset);
    }
    const T *getROIPtr() const
    {
        int Offset = m_pImage->roi ? m_pImage->roi->yOffset * m_pImage->widthStep + m_pImage->roi->xOffset : 0;
        return reinterpret_cast<T *>(m_pImage->imageData + Offset);
    }

    //! Clears ROI within the image (the whole image is selected).
    inline CvImageRef& resetROI();

protected:
    //! Structure containing number of references to the image.
    struct SRefInfo
    {
        //! The number of references to the image.
        //! - Zero if there is no reference.
        mutable int m_iReferences;
        
        //! Constructor that initializes the number of references.
        SRefInfo(int NumOfRefs = 1) : m_iReferences(NumOfRefs) {}
        
        //! Empty destructor.
        ~SRefInfo() {}
        
        //! Increases the number of references.
        void addReference() const
        {
            ++m_iReferences;
        }

        //! Decreases the number of references.
        //! - Returns true if the final number of references
        //!   is equal to zero, thus the object must be deleted.
        bool delReference()
        {
            return ((--m_iReferences) == 0);
        }
    };

    //! Pointer to the structure holding the number of references.
    SRefInfo *m_pRef;

    //! Pointer to the Ipl image.
    IplImage *m_pImage;

protected:
    //! Protected copy constructor.
    CvImageRef(const CvImageRef&);

    //! Protected assignment operator.
    CvImageRef& operator =(const CvImageRef&);
};


//==============================================================================
/*
 * Method templates
 */

// Include file containing method templates
#include "CvImageRef.hxx"


} // namespace img
} // namespace vpl

#endif // VPL_OPENCV_ENABLED
#endif // VPL_CvImageRef_H
