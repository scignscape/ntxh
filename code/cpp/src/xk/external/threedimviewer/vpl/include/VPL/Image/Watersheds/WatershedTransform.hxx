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


//==============================================================================
/*
 * Type definitions.
 */

namespace WatershedTransform
{
    //! Pixel value used to mark pixels at the current intensity level.
    const vpl::img::tPixel32 MASK = vpl::img::tPixel32(1);

    //! Pixel value used to mark watersheds (boundaries between two catchment basins).
    const vpl::img::tPixel32 WSHED = vpl::img::tPixel32(2);

    //! First allowed region index.
    const vpl::img::tPixel32 MIN_LABEL = vpl::img::tPixel32(3);

    //! Maximal allowed region index.
    const vpl::img::tPixel32 MAX_LABEL = vpl::CTypeTraits<vpl::img::tPixel32>::getMax();
}


//==============================================================================
/*
 * Implementation of the class CWatershedTransform<I>.
 */

template <class I>
bool CWatershedTransform<I>::operator()(const tImage& SrcImage, tRegionImage& DstImage)
{
    static const tSize MARGIN = 1;
    static const tSize STOP_VALUE = -1;
    static const tPixelInfo STOP_PIXEL(STOP_VALUE, STOP_VALUE);

    tSize XDim = SrcImage.getXSize();
    tSize YDim = SrcImage.getYSize();

    // Check the image size
    VPL_CHECK(XDim * YDim > 0, return false);

    // Helper segmentation image
    m_RegionImage.resize(XDim, YDim, MARGIN);
    m_RegionImage.fillEntire(0);

    // Helper distance image (distance from the closest minimum)
    m_DistanceImage.resize(XDim, YDim, MARGIN);
    m_DistanceImage.fillEntire(0);

    // Queue of pixels
    tQueue Fifo;

    // Create pixel value histogram
    createHistogram(SrcImage);

    // Initialize the current region
    m_CurrentRegion = WatershedTransform::MIN_LABEL;

    // For every histogram column do
    for( int Level = 0; Level < int(m_Histogram.size()); ++Level )
    {
        // Prepare pixels of the current intensity level
        preparePixels(Fifo, Level);

        // Initialize the distance
        tDistance CurrentDistance = 1;

        // Enter the end mark
        Fifo.push_back(STOP_PIXEL);

        // Process all pixels in the queue until the end mark is found
//        while( !Fifo.empty() )
        for( ;; )
        {
            // Pop the first element from the queue
            tPixelInfo Point = Fifo.front();
            Fifo.pop_front();

            // Is it the end mark?
            if( Point.first == STOP_VALUE )
            {
                if( Fifo.empty() )
                {
                    break;
                }
                else
                {
                    // Increase the distance
                    Fifo.push_back(STOP_PIXEL);
                    ++CurrentDistance;

                    // Continue with the first pixel in the queue
                    Point = Fifo.front();
                    Fifo.pop_front();
                }
            }

            // Assign an image region to the current pixel
            assignRegionNumber(Point, Fifo, CurrentDistance);
        }

        // Find all new local minima at the current intensity level
        if( !checkNewMinima(Fifo, Level) )
        {
            break;
        }
    }

    // Clear the histogram
    clearHistogram();

    // Finalize the segmentation
    if( checkOption(WatershedTransform::WATERSHEDS) )
    {
        makeBorderPixels(DstImage);
    }
    else
    {
        clearBorderPixels(DstImage);
    }

    // Correct the final number of regions
    m_CurrentRegion -= WatershedTransform::MIN_LABEL;

    // O.K.
    return true;
}


template <class I>
void CWatershedTransform<I>::clearHistogram()
{
    static const tPixel Min = CPixelTraits<tPixel>::getPixelMin();
    static const tPixel Max = CPixelTraits<tPixel>::getPixelMax();

    m_Histogram.resize(tHistogram::size_type(Max - Min) + 1);

    tHistogram::iterator itEnd = m_Histogram.end();
    for( tHistogram::iterator it = m_Histogram.begin(); it != itEnd; ++it )
    {
        it->clear();
    }
}


template <class I>
void CWatershedTransform<I>::createHistogram(const tImage& SrcImage)
{
    static const tPixel Min = CPixelTraits<tPixel>::getPixelMin();

    // Clear the histogram
    clearHistogram();

    // Fill the histogram
    for( tSize j = 0; j < SrcImage.getYSize(); ++j )
    {
        for( tSize i = 0; i < SrcImage.getXSize(); ++i )
        {
            m_Histogram[tHistogram::size_type(SrcImage(i,j) - Min)].push_back(tPixelInfo(i,j));
        }
    }
}


template <class I>
void CWatershedTransform<I>::preparePixels(tQueue& Fifo, int Level)
{
    tQueue::iterator it = m_Histogram[Level].begin();
    tQueue::iterator itEnd = m_Histogram[Level].end();
    for( ; it != itEnd; ++it )
    {
        tPixelInfo& Point = *it;
        m_RegionImage(Point.first, Point.second) = WatershedTransform::MASK;

        // Check if the pixel is not a new local minimum (one of the neighbours
        // is already initialized) -> insert point to the queue
        tRegionNumber Region1 = m_RegionImage(Point.first + 1, Point.second);
        tRegionNumber Region2 = m_RegionImage(Point.first - 1, Point.second);
        tRegionNumber Region3 = m_RegionImage(Point.first, Point.second + 1);
        tRegionNumber Region4 = m_RegionImage(Point.first, Point.second - 1);
        if( Region1 >= WatershedTransform::WSHED
            || Region2 >= WatershedTransform::WSHED
            || Region3 >= WatershedTransform::WSHED
            || Region4 >= WatershedTransform::WSHED )
        {
            m_DistanceImage(Point.first, Point.second) = 1;
            Fifo.push_back(Point);
        }
    }
}


template <class I>
void CWatershedTransform<I>::assignRegionNumber(const tPixelInfo& Point,
                                                tQueue& Fifo,
                                                tDistance CurrentDistance
                                                )
{
    static const tSize NeighbourX[4] = { -1, 1, 0, 0 };
    static const tSize NeighbourY[4] = { 0, 0, -1, 1 };

    // Current pixel's region
    tRegionNumber PixelRegion = m_RegionImage(Point.first, Point.second);

    // For all neighbouring pixels
    for( int i = 0; i < 4; ++i )
    {
        tSize x = Point.first + NeighbourX[i];
        tSize y = Point.second + NeighbourY[i];
        tDistance Distance = m_DistanceImage(x, y);
        tRegionNumber Region = m_RegionImage(x, y);

        if( Distance < CurrentDistance && Region >= WatershedTransform::WSHED )
        {
            if( Region >= WatershedTransform::MIN_LABEL )
            {
                if( PixelRegion == WatershedTransform::MASK || PixelRegion == WatershedTransform::WSHED )
                {
                    // Assign the point to same region as the neighbour's one
                    m_RegionImage(Point.first, Point.second) = Region;
                    PixelRegion = Region;
                }
                else if( PixelRegion != Region )
                {
                    // Region of the current point doesn't correspond to the neighbour's
                    // -> make the current point border.
                    m_RegionImage(Point.first, Point.second) = WatershedTransform::WSHED;
                    PixelRegion = WatershedTransform::WSHED;
                }
            }
            else if( PixelRegion == WatershedTransform::MASK )
            {
                // The current point is not assigned and is adjacent to a boundary pixel
                // -> make the current point border.
                m_RegionImage(Point.first, Point.second) = WatershedTransform::WSHED;
                PixelRegion = WatershedTransform::WSHED;
            }
        }
        else if( Region == WatershedTransform::MASK && Distance == 0 )
        {
            m_DistanceImage(x, y) = CurrentDistance + 1;
            Fifo.push_back(tPixelInfo(x, y));
        }
    }
}


template <class I>
bool CWatershedTransform<I>::checkNewMinima(tQueue& Fifo, int Level)
{
    tQueue::iterator iterEnd = m_Histogram[Level].end();
    tQueue::iterator iter = m_Histogram[Level].begin();
    for( ; iter != iterEnd; ++iter )
    {
        tPixelInfo& Point = *iter;
        m_DistanceImage(Point.first, Point.second) = 0;

        // A new minimum/basin found?
        if( m_RegionImage(Point.first, Point.second) == WatershedTransform::MASK )
        {
            ++m_CurrentRegion;
            if( m_CurrentRegion == WatershedTransform::MAX_LABEL )
            {
                return false;
            }
            Fifo.push_back(Point);
            m_RegionImage(Point.first, Point.second) = m_CurrentRegion;

            // Flood the new basin
            while( !Fifo.empty() )
            {
                // Get the first point from the queue
                tPixelInfo tmpPoint = Fifo.front();
                Fifo.pop_front();

                tSize x = tmpPoint.first + 1;
                tSize y = tmpPoint.second;
                if( m_RegionImage(x, y) == WatershedTransform::MASK )
                {
                    Fifo.push_back(tPixelInfo(x, y));
                    m_RegionImage(x, y) = m_CurrentRegion;
                }

                x = tmpPoint.first - 1;
//                y = tmpPoint.second;
                if( m_RegionImage(x, y) == WatershedTransform::MASK )
                {
                    Fifo.push_back(tPixelInfo(x, y));
                    m_RegionImage(x, y) = m_CurrentRegion;
                }

                x = tmpPoint.first;
                y = tmpPoint.second + 1;
                if( m_RegionImage(x, y) == WatershedTransform::MASK )
                {
                    Fifo.push_back(tPixelInfo(x, y));
                    m_RegionImage(x, y) = m_CurrentRegion;
                }

//                x = tmpPoint.first;
                y = tmpPoint.second - 1;
                if( m_RegionImage(x, y) == WatershedTransform::MASK )
                {
                    Fifo.push_back(tPixelInfo(x, y));
                    m_RegionImage(x, y) = m_CurrentRegion;
                }
            }
        }
    }

    // O.K.
    return true;
}


template <class I>
void CWatershedTransform<I>::clearBorderPixels(tRegionImage& Image)
{
    // We expect that m_RegionImage contains only valid region labels (>0)
    // or WSHED values.

    // Find all watersheds
    tQueue Fifo;
    for( tSize j = 0; j < Image.getYSize(); ++j )
    {
        for( tSize i = 0; i < Image.getXSize(); ++i )
        {
            tRegionNumber Region = m_RegionImage(i, j);
//            if( Region == WatershedTransform::WSHED )
            if( Region < WatershedTransform::MIN_LABEL )
            {
                Fifo.push_back(tPixelInfo(i, j));
            }
            else
            {
                Image(i, j) = Region - WatershedTransform::MIN_LABEL;
            }
        }
    }

    while( !Fifo.empty() )
    {
        tPixelInfo Point = Fifo.front();
        Fifo.pop_front();

        tSize i = Point.first;
        tSize j = Point.second;
        tRegionNumber Region = m_RegionImage(i + 1, j);

        tRegionNumber Temp = m_RegionImage(i - 1, j);
        if( Region < WatershedTransform::MIN_LABEL || (Temp < Region && Temp >= WatershedTransform::MIN_LABEL) )
//        if( Temp < Region || Region == WatershedTransform::WSHED )
        {
            Region = Temp;
        }

        Temp = m_RegionImage(i, j + 1);
        if( Region < WatershedTransform::MIN_LABEL || (Temp < Region && Temp >= WatershedTransform::MIN_LABEL) )
//        if( Temp < Region || Region == WatershedTransform::WSHED )
        {
            Region = Temp;
        }

        Temp = m_RegionImage(i, j - 1);
        if( Region < WatershedTransform::MIN_LABEL || (Temp < Region && Temp >= WatershedTransform::MIN_LABEL) )
//        if( Temp < Region || Region == WatershedTransform::WSHED )
        {
            Region = Temp;
        }

        m_RegionImage(i, j) = Region;
        if( Region < WatershedTransform::MIN_LABEL )
        {
            Fifo.push_back(tPixelInfo(i, j));
        }
        else
        {
            Image(i, j) = Region - WatershedTransform::MIN_LABEL;
        }
    }
}


template <class I>
void CWatershedTransform<I>::makeBorderPixels(tRegionImage& Image)
{
    for( tSize j = 0; j < Image.getYSize(); ++j )
    {
        for( tSize i = 0; i < Image.getXSize(); ++i )
        {
            tRegionNumber Region = m_RegionImage(i, j);

            if( m_RegionImage(i + 1, j) < Region
                || m_RegionImage(i - 1, j) < Region
                || m_RegionImage(i, j + 1) < Region
                || m_RegionImage(i, j - 1) < Region )
            {
                Region = WatershedTransform::WSHED;
            }
            else
            {
                Region = 0;
            }

            Image(i, j) = Region;
        }
    }
}

