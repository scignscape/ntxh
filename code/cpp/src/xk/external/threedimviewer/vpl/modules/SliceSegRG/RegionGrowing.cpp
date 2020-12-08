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
 *          Martin Skotnica, xskotn01@stud.fit.vutbr.cz  \n
 * File:    mdsRegionGrowing.cpp                      
 * Section: mSliceSegRG                               
 * Date:    2004/03/01                                
 *
 * Description:
 * - Simple segmentation method based on region growing and merging.
 */

#include "RegionGrowing.h"

#include <VPL/Base/Assert.h>
#include <VPL/Base/Logging.h>
#include <VPL/Image/ImageEdgeDetection.h>


namespace vpl
{
namespace imseg
{

//==============================================================================
/*
 * Implementation of the class vpl::seg::CRegionGrowing.
 */
CRegionGrowing::CRegionGrowing(double dDiffWeight,
                               double dEdgeWeight,
                               double dThreshold,
                               bool bMerge
                               )
    : m_dThreshold(dThreshold)
    , m_dDiffWeight(dDiffWeight)
    , m_dEdgeWeight(dEdgeWeight)
    , m_bMerge(bMerge)
{
}


void CRegionGrowing::createSeeds(SMySeed& Seed,
                                 CRegionGrowing::tImage& Image,
                                 int XDim,
                                 int YDim
                                 )
{
    SMySeed Temp(0, 0, Seed.m_iIndex);
    if( Seed.m_x > 0 )
    {
        Temp.m_x = Seed.m_x - 1;
        Temp.m_y = Seed.m_y;
        if( int(Image(Temp.m_x, Temp.m_y)) != Temp.m_iIndex )
        {
            m_Seeds.push_back(Temp);
        }
    }
    if( Seed.m_y > 0 )
    {
        Temp.m_x = Seed.m_x;
        Temp.m_y = Seed.m_y - 1;
        if( int(Image(Temp.m_x, Temp.m_y)) != Temp.m_iIndex )
        {
            m_Seeds.push_back(Temp);
        }
    }
    if( Seed.m_x < XDim - 1 )
    {
        Temp.m_x = Seed.m_x + 1;
        Temp.m_y = Seed.m_y;
        if( int(Image(Temp.m_x, Temp.m_y)) != Temp.m_iIndex )
        {
            m_Seeds.push_back(Temp);
        }
    }
    if( Seed.m_y < YDim - 1 )
    {
        Temp.m_x = Seed.m_x;
        Temp.m_y = Seed.m_y + 1;
        if( int(Image(Temp.m_x, Temp.m_y)) != Temp.m_iIndex )
        {
            m_Seeds.push_back(Temp);
        }
    }
}


bool CRegionGrowing::operator()(const tImage& SrcImage, tImage& DstImage)
{
    // Image dimensions
    tSize Xdim = SrcImage.getXSize();
    tSize Ydim = SrcImage.getYSize();
    tSize Margin = SrcImage.getMargin();

    // Check destination image dimensions
    VPL_CHECK(Xdim == DstImage.getXSize() && Ydim == DstImage.getYSize(), return false);
    VPL_CHECK(Xdim > 0 && Ydim > 0, return false);

    // Vyplni vystup cernou barvnou
    DstImage.fill(0);

    // Vypocet odezvy hranoveho detektoru
    tImage EdgeImage(Xdim, Ydim, Margin);
//    vpl::img::CCanny<tImage> Filter(1.0, 0.2, 0.1);
    vpl::img::CZeroCrossDetector<tImage> Filter(1.5, 0.1);
    Filter(SrcImage, EdgeImage);

    // Zruseni seminek
    m_Seeds.clear();

    // Cislovani regionu musi zacinat od 1
    m_Regions.clear();
//    int DummyLabel = m_Regions.newLabel();
    int iMaxLabel = int(vpl::CTypeTraits<tPixel>::getMax() - 1);

    SMySeed Seed;
    int iValue, iAssignedIndex;
    double dDiff, dResp, dResult;

    // Inicializace seminka
    tSize x = 0, y = 0;

    while( y < Ydim )
    {
        // Vyhledani seminka
        do {
            int iLabel = int(DstImage(x++, y));
            if( iLabel == 0 )
            {
                int iColor = m_Regions.newLabel(SMyRegion(long(SrcImage(x - 1, y))));
                if( iColor >= iMaxLabel )
                {
                    VPL_LOG_INFO("The number of regions exceeds an allowed range.");
                    break;
                }
                m_Seeds.push_back(SMySeed(x - 1, y, iColor));
            }
            else
            {
                if( ++x >= Xdim )
                {
                    x = 0;
                    ++y;
                }
            }
        } while( m_Seeds.empty() && y < Ydim );

        // Sireni ze seminka
        while( !m_Seeds.empty() )
        {
            // Odeber prvni seminko
            Seed = m_Seeds.front();
            m_Seeds.pop_front();

            // Vyhledani regionu kam seminko patri
            SMyRegion& Region = m_Regions.getData(Seed.m_iIndex);

            // Hodnota pixelu skryteho za seminkem
            iValue = int(SrcImage(Seed.m_x, Seed.m_y));
            iAssignedIndex = int(DstImage(Seed.m_x, Seed.m_y));

            // Je seminko neobarvene?
            if( iAssignedIndex == 0 )
            {
                // Diference stredni hodnoty a pixelu
                dDiff = vpl::math::getAbs(double(iValue) - Region.getMean());

                // Odezva filtru
                dResp = double(EdgeImage(Seed.m_x, Seed.m_y));

                // Kombinace obou vlastnosti
                dResult = m_dDiffWeight * dDiff + m_dEdgeWeight * dResp;

                // Je vysledek mensi nez povoleny prah?
                if( dResult < m_dThreshold )
                {
                    // Pridani pixelu do regionu
                    Region.insert(iValue);
                    DstImage(Seed.m_x, Seed.m_y) = tPixel(Seed.m_iIndex);

                    // Vytvoreni seminek ze sousedu
                    createSeeds(Seed, DstImage, Xdim, Ydim);
                }
            }

            // Seminko narazilo na jiny region
            else if ( iAssignedIndex != Seed.m_iIndex )
            {
                // Vyhledani regionu kam patri
                SMyRegion& Region2 = m_Regions.getData(iAssignedIndex);

                // Je-li rozdil regionu maly, sloucime je
                if( vpl::math::getAbs(Region.getMean() - Region2.getMean()) < (m_dDiffWeight * m_dThreshold) )
                {                   
                    // Prebarveni
                    m_Regions.merge(iAssignedIndex, Seed.m_iIndex);

                    // Slouceni statistik
                    Region.add(Region2.m_dTotal, Region2.m_liCount);
//                    Region2.m_dTotal = 0.0;
//                    Region2.m_liCount = 0;
                }
            }
        }
    }

    // Phase 2: Pripadne spojeni "podobnych" regionu
    if( m_bMerge )
    {
        for( int i = 1; i < m_Regions.getSize(); ++i )
        {
            // Vyhledani regionu kam seminko patri
            SMyRegion& Region1 = m_Regions.getData(i);

            for( int j = i + 1; j < m_Regions.getSize(); ++j )
            {
                // Vyhledani regionu kam seminko patri
                SMyRegion& Region2 = m_Regions.getData(j);

                // Je-li rozdil regionu maly, sloucime je
                if( vpl::math::getAbs(Region1.getMean() - Region2.getMean()) < (m_dDiffWeight * m_dThreshold) )
                {
                    // Prebarveni
                    m_Regions.merge(j, i);

                    // Slouceni statistik
                    Region1.add(Region2.m_dTotal, Region2.m_liCount);
//                    Region2.m_dTotal = 0.0;
//                    Region2.m_liCount = 0;
                }
            }
        }
    }

    // Phase 3: Serazeni indexu regionu a odstraneni prazdnych
    m_Regions.relabel();
    for( y = 0; y < Ydim; ++y )
    {
        for( x = 0; x < Xdim; ++x )
        {
            DstImage(x, y) = tPixel(m_Regions.getLabel(int(DstImage(x, y))));
        }
    }

    // Vymazani seminek a regionu
    m_Regions.clear();
    m_Seeds.clear();

    return true;
}


} // namespace imseg
} // namespace vpl

