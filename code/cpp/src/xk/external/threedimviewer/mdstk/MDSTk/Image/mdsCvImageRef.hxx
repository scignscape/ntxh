//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2010 by Michal Spanel          \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2010/01/19                          \n
 *
 * $Id: mdsCvImageRef.hxx 1707 2010-05-05 11:00:46Z spanel $
 *
 * Description:
 * - Provides reference counting mechanism on OpenCV images.
 */

//==============================================================================
/*
 * Methods templates.
 */

template <typename T>
inline CvImageRef<T>& CvImageRef<T>::detach()
{
    if( m_pRef )
    {
        if( m_pRef->delReference() )
        {
            // Release image header as well as the data
            cvReleaseImage(&m_pImage);
            delete m_pRef;
        }
        else
        {
            cvReleaseImageHeader(&m_pImage);
        }
        m_pRef = 0;
        m_pImage = 0;
    }

    return *this;
}


template <typename T>
inline CvImageRef<T>::CvImageRef()
{
    m_pImage = cvCreateImage(cvSize(0, 0), getDepth(), getChannels());
    if( !m_pImage )
    {
        throw cv::CBadImageAlloc();
    }
    m_pRef = new SRefInfo(1);
}


template <typename T>
inline CvImageRef<T>::CvImageRef(EEmptyConst) : m_pRef(0), m_pImage(0)
{
}


template <typename T>
CvImageRef<T>::~CvImageRef()
{
    detach();
}


template <typename T>
inline CvImageRef<T>& CvImageRef<T>::create(tSize Width, tSize Height)
{
    detach();

    m_pImage = cvCreateImage(cvSize(Width, Height), getDepth(), getChannels());
    if( !m_pImage )
    {
        throw cv::CBadImageAlloc();
    }
    m_pRef = new SRefInfo(1);

    return *this;
}


template <typename T>
inline CvImageRef<T>& CvImageRef<T>::create(const CvImageRef& Data,
                                            tSize Col,
                                            tSize Row,
                                            tSize Width,
                                            tSize Height
                                            )
{
    detach();

    // Limit size of the image
    Width = mds::math::getMin(Col + Width, Data.m_pImage->width) - Col;
    Height = mds::math::getMin(Row + Height, Data.m_pImage->height) - Row;

    // Create a new image
    m_pImage = cvCreateImage(cvSize(Width, Height), getDepth(), getChannels());
    if( !m_pImage )
    {
        throw cv::CBadImageAlloc();
    }
    m_pRef = new SRefInfo(1);

    // Copy the data
    static const int PixelSize = getPixelSize();
    for( tSize j = 0; j < Height; ++j )
    {
        mds::base::memCopy(m_pImage->imageData + j * m_pImage->widthStep,
                           Data.m_pImage->imageData + (j + Row) * Data.m_pImage->widthStep + Col * PixelSize,
                           Width * PixelSize
                           );
    }

    return *this;
}


template <typename T>
inline CvImageRef<T>& CvImageRef<T>::create(const CvImageRef& Data,
                                            tSize Col,
                                            tSize Row,
                                            tSize Width,
                                            tSize Height,
                                            EMakeRef
                                            )
{
    detach();

    if( !Data.m_pImage )
    {
        return *this;
    }

    // Limit size of the image
    Width = mds::math::getMin(Col + Width, Data.m_pImage->width) - Col;
    Height = mds::math::getMin(Row + Height, Data.m_pImage->height) - Row;

    // Create reference to the original image
    m_pImage = cvCreateImageHeader(cvSize(Width, Height), getDepth(), getChannels());
    if( !m_pImage )
    {
        throw cv::CBadImageAlloc();
    }

    m_pImage->origin = Data.m_pImage->origin;
    m_pImage->imageDataOrigin = Data.m_pImage->imageDataOrigin;
    m_pImage->imageSize = Data.m_pImage->imageSize;
    m_pImage->imageData = Data.m_pImage->imageData;
    m_pImage->widthStep = Data.m_pImage->widthStep;
    
    static const int PixelSize = getPixelSize();
    m_pImage->imageData += Row * m_pImage->widthStep + Col * PixelSize;
    
    m_pRef = Data.m_pRef;
    m_pRef->addReference();

    return *this;
}


template <typename T>
inline CvImageRef<T>& CvImageRef<T>::create(const CvImageRef<T>& Data)
{
    detach();

    if( !Data.m_pImage )
    {
        return *this;
    }

    m_pImage = cvCloneImage(Data.m_pImage);
    if( !m_pImage )
    {
        throw cv::CBadImageAlloc();
    }
    m_pRef = new SRefInfo(1);

    return *this;
}


template <typename T>
inline CvImageRef<T>& CvImageRef<T>::create(IplImage *pImage)
{
    detach();

    m_pImage = pImage;
    m_pRef = m_pImage ? new SRefInfo(1) : 0;

    return *this;
}


template <typename T>
inline CvImageRef<T>& CvImageRef<T>::create(const CvImageRef<T>& Data, EMakeRef)
{
    detach();

    if( !Data.m_pImage )
    {
        return *this;
    }

    // Create reference to the original image
    m_pImage = cvCreateImageHeader(cvSize(Data.m_pImage->width, Data.m_pImage->height), getDepth(), getChannels());
    if( !m_pImage )
    {
        throw cv::CBadImageAlloc();
    }

    m_pImage->origin = Data.m_pImage->origin;
    m_pImage->imageData = Data.m_pImage->imageData;
    m_pImage->widthStep = Data.m_pImage->widthStep;
    m_pRef = Data.m_pRef;
    m_pRef->addReference();

    return *this;
}


template <typename T>
inline CvImageRef<T>& CvImageRef<T>::makeROI(int Col, int Row, int Width, int Height)
{
//    if( !m_pImage ) { return *this; }

    if( m_pImage->roi )
    {
        Col += m_pImage->roi->xOffset;
        Row += m_pImage->roi->yOffset;
    }
    cvSetImageROI(m_pImage, cvRect(Col, Row, Width, Height));

    return *this;
}


template <typename T>
inline CvImageRef<T>& CvImageRef<T>::resetROI()
{
//    if( !m_pImage ) { return *this; }

    cvResetImageROI(m_pImage);

    return *this;
}

