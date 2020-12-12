//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)           \n
 * Copyright (c) 2003-2005 by Michal Spanel            \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz         \n
 *          Miroslav Svub, xsvubm00@stud.fit.vutbr.cz  \n
 * File:    mdsHistogramThresholding.cpp               \n
 * Section: mSliceSegHT                                \n
 * Date:    2004/10/24                                 \n
 *
 * $Id: mdsHistogramThresholding.cpp 967 2008-07-28 15:05:19Z spanel $
 *
 * File description:
 * - Simple segmentation method based on histogram thresholding.
 */

#include "mdsHistogramThresholding.h"

#include <MDSTk/Base/mdsLog.h>

#include <cmath>


namespace mds
{
namespace imseg
{

//==============================================================================
/*
 * Implementation of the class mds::seg::CHistogramThresholding.
 */
double CHistogramThresholding::SColumn::getDistance(const CHistogramThresholding::SColumn& rhs)
{
    // Distance between two columns
    double dDistC = double(rhs.m_iCount - m_iCount);
    double dDistM = double(rhs.m_Min - m_Min);

    return sqrt(dDistC * dDistC + dDistM * dDistM);
}


bool CHistogramThresholding::operator()(const tImage& SrcImage, tImage& DstImage)
{
    // Image dimensions
    tSize XDim = SrcImage.getXSize();
    tSize YDim = SrcImage.getYSize();

    // Check destination image dimensions
    MDS_CHECK(XDim == DstImage.getXSize() && YDim == DstImage.getYSize(), return false);
    MDS_CHECK(XDim > 0 && YDim > 0, return false);

    // Clear the destination image
    DstImage.fill(0);

    // Minimal and maximal pixel value
    int iMinVal = (int)mds::img::CPixelTraits<tPixel>::getPixelMin();
    int iMaxVal = (int)mds::img::CPixelTraits<tPixel>::getPixelMax();
    
    // Statistics
    int iHistSize = iMaxVal - iMinVal + 1;
    int *pHist = new int[iHistSize];
    memset((void *)pHist, 0, sizeof(int) * iHistSize);

    // Build histogram
    tSize x, y;
    for( y = 0; y < YDim; ++y )
    {
        for( x = 0; x < XDim; ++x )
        {
            pHist[SrcImage(x, y) - iMinVal]++;
        }
    }

    // Compute size of the column
    int iCellSize = iHistSize / m_iColumns;

    // Create an empty histogram
    tHistList MainHist;
    SColumn Column;

    // Fill the histogram columns
    tHistList::iterator it = MainHist.begin();
    for( int i = iMinVal; i <= iMaxVal; ++i )
    {
        if( ((i - iMinVal) % iCellSize) == 0 )
        {
            Column.set(pHist[i - iMinVal], i, i + iCellSize - 1);
            MainHist.push_back(Column);
            ++it;
        }
        else
        {
            it->add(pHist[i - iMinVal]);
        }
    }

    // Clean up
    delete pHist;

    // Compute DCE
    tHistList::iterator itMark;
    SColumn c1, c2, c3;
    double dDiff;
    double dDiffMark;
    while( (int)MainHist.size() > (m_iTresholds * 3) )
    {
        itMark = MainHist.begin();
        ++itMark;
        it = itMark;
        ++itMark;

        c1 = (*it);    // triplet value
        ++it;
        c2 = (*it);
        ++it;
        c3 = (*it);

        dDiffMark = c1.getDistance(c2) + c2.getDistance(c3) - c1.getDistance(c3);

        tHistList::const_iterator itEnd = MainHist.end();
        while( it != itEnd )
        {
            c1 = (*it);    // triplet value
            it++;
            c2 = (*it);
            it++;
            c3 = (*it);
            dDiff = c1.getDistance(c2) + c2.getDistance(c3) - c1.getDistance(c3);
            --it;
            if( dDiff < dDiffMark )
            {
                itMark = it;
                dDiffMark = dDiff;
            }
        }
        MainHist.erase(itMark);
    }

    int iTresholdCursor = 0;
    int iInitTrend;
    int iTrend;

    itMark = it = MainHist.begin();
    ++it;
    if( itMark->m_iCount >= it->m_iCount )
    {
        iInitTrend = -1;
    }
    else
    {
        iInitTrend = 1;
    }

    // Find tresholds in local minima
    int *pTresholds = new int[m_iTresholds];
    do {
        ++itMark;
        ++it;
        if( itMark->m_iCount >= it->m_iCount )
        {
            iTrend = -1;
        }
        else
        {
            iTrend = 1;
        }
        if( (iInitTrend == -1) && (iTrend == 1) )
        {
            pTresholds[iTresholdCursor] = itMark->m_Min;
            ++iTresholdCursor;
            if( iTresholdCursor == m_iTresholds )
            {
                break;
            }
        }
        iInitTrend = iTrend;
    } while( (it != MainHist.end()) && (itMark != MainHist.end()) );

    int t = 0; // treshold

    // Performs tresholding
    for( y = 0; y < YDim; ++y )
    {
        for( x = 0; x < XDim; ++x )
        {
            while( 1 )
            {
                if( int(SrcImage(x, y)) < pTresholds[t] )
                {
                    break;
                }
                ++t;
                if( t == iTresholdCursor )
                {
                    break;
                }
            }
            if( t == iTresholdCursor )
            {
                DstImage.set(x, y, tPixel(0));
            }
            else
            {
                DstImage.set(x, y, tPixel(t + 1));
            }
            t = 0;
        }
    }

    // Clean up
    delete pTresholds;

    return true;
}


} // namespace imseg
} // namespace mds
