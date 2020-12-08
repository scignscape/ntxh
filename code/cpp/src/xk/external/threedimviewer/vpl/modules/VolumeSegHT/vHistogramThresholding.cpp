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
 * Copyright (c) 2003-2005 by Michal Spanel         
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz      
 *          Miroslav Svub, xsvubm00@stud.fit.vutbr.cz  \n
 * Date:    2005/01/25                              
 *
 * File description:
 * - Simple segmentation method based on histogram thresholding.
 */

#include "HistogramThresholding.h"

#include <cmath>


namespace vpl
{
namespace volseg
{

//==============================================================================
/*
 * Implementation of the class vpl::seg::CVolumeHistogramThresholding.
 */
double CVolumeHistogramThresholding::SColumn::getDistance(const CVolumeHistogramThresholding::SColumn& rhs)
{
    // Distance between two columns
    double dDistC = double(rhs.m_iCount - m_iCount);
    double dDistM = double(rhs.m_Min - m_Min);

    return sqrt(dDistC * dDistC + dDistM * dDistM);
}


bool CVolumeHistogramThresholding::operator()(const tVolume& SrcVolume, tVolume& DstVolume)
{
    // Volume dimensions
    tSize XDim = SrcVolume.getXSize();
    tSize YDim = SrcVolume.getYSize();
    tSize ZDim = SrcVolume.getZSize();

    // Check destination volume dimensions
    VPL_CHECK(XDim == DstVolume.getXSize() && YDim == DstVolume.getYSize() && ZDim == DstVolume.getZSize(), return false);
    VPL_CHECK(XDim > 0 && YDim > 0 && ZDim > 0, return false);

    // Clear the destination volume
    DstVolume.fill(0);

    // Minimal and maximal pixel value
    int iMinVal = (int)vpl::img::CPixelTraits<tVoxel>::getPixelMin();
    int iMaxVal = (int)vpl::img::CPixelTraits<tVoxel>::getPixelMax();

    // Statistics
    int iHistSize = iMaxVal - iMinVal + 1;
    int *pHist = new int[iHistSize];
    memset((void *)pHist, 0, sizeof(int) * iHistSize);

    // Build a histogram
    tSize x, y, z;
    for( z = 0; z < ZDim; ++z )
    {
        for( y = 0; y < YDim; ++y )
        {
            for( x = 0; x < XDim; ++x )
            {
                ++(pHist[SrcVolume(x, y, z) - iMinVal]);
            }
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
            Column.set(pHist[i - iMinVal], tVoxel(i), tVoxel(i + iCellSize - 1));
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
    for( z = 0; z < ZDim; ++z )
    {
        for( y = 0; y < YDim; ++y )
        {
            for( x = 0; x < XDim; ++x )
            {
                while( 1 )
                {
                    if( int(SrcVolume(x, y, z)) < pTresholds[t] )
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
                    DstVolume(x, y, z) = tVoxel(0);
                }
                else
                {
                    DstVolume(x, y, z) = tVoxel(t + 1);
                }
                t = 0;
            }
        }
    }

    // Clean up
    delete pTresholds;

    return true;
}


} // namespace volseg
} // namespace vpl

