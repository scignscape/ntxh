//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2010 by Michal Spanel          \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2010/01/19                          \n
 *
 * $Id: mdsCvImageRef.h 1920 2010-11-06 18:26:41Z spanel $
 *
 * Description:
 * - Provides reference counting mechanism on OpenCV images.
 */

#ifndef MDS_CvImageRef_H
#define MDS_CvImageRef_H

#include <MDSTk/Base/mdsSetup.h>

#ifdef MDS_OPENCV_ENABLED

#include <MDSTk/Base/mdsRefData.h>
#include <MDSTk/Base/mdsException.h>

#include "mdsCvTraits.h"


namespace mds
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
    MDS_DECLARE_EXCEPTION(CBadImageAlloc, "Failed to allocate IplImage struct or image data");
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
    //! - Throws mds::img::cv::CBadImageAlloc() exception on failure.
    inline CvImageRef();

    //! This constructor does no allocation of the data.
    //! - Be sure that the method create() is used somewhere!
    //! - Use with care!
    inline CvImageRef(EEmptyConst);

    //! Destructor.
    inline ~CvImageRef();

    //! Allocates image data of a given size.
    //! - In case of several references to the existing data, the reference
    //!   counter is decremented and new data are allocated.
    //! - Returns reference to this.
    //! - Throws mds::img::cv::CBadImageAlloc() exception on failure.
    inline CvImageRef& create(tSize Width, tSize Height);

    //! Creates a subimage of a given image.
    //! - Makes own copy of the data.
    //! - Throws mds::img::cv::CBadImageAlloc() exception on failure.
    inline CvImageRef& create(const CvImageRef& Data,
                              tSize Col,
                              tSize Row,
                              tSize Width,
                              tSize Height
                              );

    //! Creates a subimage of a given image.
    //! - Makes reference to the data.
    //! - Throws mds::img::cv::CBadImageAlloc() exception on failure.
    inline CvImageRef& create(const CvImageRef& Data,
                              tSize Col,
                              tSize Row,
                              tSize Width,
                              tSize Height,
                              EMakeRef
                              );

    //! Allocates imade data and copies the specified one.
    //! - Returns reference to this.
    //! - Throws mds::img::cv::CBadImageAlloc() exception on failure.
    inline CvImageRef& create(const CvImageRef& Data);

    //! Creates image from the IplImage directly image.
    //! - Takes full control over the image including deallocation of the memory!
    //! - Returns reference to this.
    inline CvImageRef& create(IplImage *pImage);

    //! Makes a new reference to existing image data.
    //! - Returns reference to this.
    //! - Throws mds::img::cv::CBadImageAlloc() exception on failure.
    inline CvImageRef& create(const CvImageRef& Data, EMakeRef);

    //! Decreases the number of references and deallocates
    //! the image data if neccessary.
    //! - Use with care!
    inline CvImageRef& detach();


    //! Returns pointer to the IplImage.
    const IplImage *asIpl() const { return m_pImage; }
    IplImage *asIpl() { return m_pImage; }

    //! Returns IplImage image width.
    int getWidth() const { return m_pImage->width; }
//    int getWidth() const { return m_pImage ? m_pImage->width : 0; }

    //! Returns IplImage height.
    int getHeight() const { return m_pImage->height; }
//    int getHeight() const { return m_pImage ? m_pImage->height : 0; }

    //! Returns the image depth (see predefined OpenCV constants).
    int getDepth() const { return CvTraits<T>::getDepth(); }

    //! Returns the number of channels.
    int getChannels() const { return CvTraits<T>::getChannels(); }

    //! Returns pixel size in bytes.
    int getPixelSize() const { return CvTraits<T>::getPixelSize(); }

    //! Returns offset between two neighbouring elements in a column.
    int getRowOffset() const { return CvTraits<T>::convWidthStep(m_pImage->widthStep); }
//    int getRowOffset() const { return m_pImage ? CvTraits<T>::convWidthStep(m_pImage->widthStep) : 0; }

    //! Returns offset between two neighbouring elements in a row.
    int getColOffset() const { return 1; }

    //! Returns the number of references to the data.
    int getNumOfReferences() const { return m_pRef ? m_pRef->m_iReferences : 0; }


    //! Returns pointer to the underlying image data.
    T *getPtr()
    {
        return reinterpret_cast<T *>(m_pImage->imageData);
//        return m_pImage ? reinterpret_cast<T *>(m_pImage->imageData) : 0;
    }
    const T *getPtr() const
    {
        return reinterpret_cast<const T *>(m_pImage->imageData);
//        return m_pImage ? reinterpret_cast<const T *>(m_pImage->imageData) : 0;
    }

    //! Returns size of the underlying image data in pixels.
    int getSize() const
    {
        return m_pImage->height * CvTraits<T>::convWidthStep(m_pImage->widthStep);
//        return m_pImage ? (m_pImage->height * CvTraits<T>::convWidthStep(m_pImage->widthStep)) : 0;
    }


    //! Creates ROI within the current image (see OpenCV linbrary for details).
    //! - If any ROI already exists, its coordinates are taken into acocunt as well.
    inline CvImageRef& makeROI(int Col, int Row, int Width, int Height);

    //! Returns the current ROI within the image (see OpenCV linbrary for details).
    CvRect getROI() const
    {
        return cvGetImageROI(m_pImage);
//        return m_pImage ? cvGetImageROI(m_pImage) : cvRect(0, 0, 0, 0);
    }

    //! Returns the ROI width.
    int getROIWidth() const { return m_pImage->roi ? m_pImage->roi->width : m_pImage->width; }
//    int getROIWidth() const { return m_pImage ? m_pImage->roi ? m_pImage->roi->width : m_pImage->width; : 0; }

    //! Returns the ROI height.
    int getROIHeight() const { return m_pImage->roi ? m_pImage->roi->height : m_pImage->height; }
//    int getROIHeight() const { return m_pImage ? m_pImage->roi ? m_pImage->roi->height : m_pImage->height; : 0; }

    //! Returns pointer to the ROI image data.
    T *getROIPtr()
    {
//        if( !m_pImage ) { return 0; }
        int Offset = m_pImage->roi ? m_pImage->roi->yOffset * m_pImage->widthStep + m_pImage->roi->xOffset : 0;
        return reinterpret_cast<T *>(m_pImage->imageData + Offset);
    }
    const T *getROIPtr() const
    {
//        if( !m_pImage ) { return 0; }
        int Offset = m_pImage->roi ? m_pImage->roi->yOffset * m_pImage->widthStep + m_pImage->roi->xOffset : 0;
        return reinterpret_cast<T *>(m_pImage->imageData + Offset);
    }

    //! Clears ROI within the image (the whole image is selected).
    inline CvImageRef& resetROI();

protected:
    //! Structure containing number of references to the image.
    struct SRefInfo /*: public CSmallValueObject<>*/
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

    //! Pointer to the structure containing the number of references.
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
#include "mdsCvImageRef.hxx"


} // namespace img
} // namespace mds

#endif // MDS_OPENCV_ENABLED
#endif // MDS_CvImageRef_H
