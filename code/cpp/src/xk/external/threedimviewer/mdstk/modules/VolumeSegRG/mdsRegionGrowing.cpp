//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)              \n
 * Copyright (c) 2003-2005 by Michal Spanel               \n
 *
 * Author:   Michal Spanel, spanel@fit.vutbr.cz           \n
 *           Martin Skotnica, xskotn01@stud.fit.vutbr.cz  \n
 * File:     mdsRegionGrowing.cpp                         \n
 * Section:  mVolumeSegRG                                 \n
 * Date:     2005/01/25                                   \n
 *
 * $Id: mdsRegionGrowing.cpp 2102 2012-02-17 09:12:21Z spanel $
 *
 * File description:
 * - Simple segmentation method based on region growing and merging.
 */

#include "mdsRegionGrowing.h"

#include <MDSTk/Base/mdsGlobalLog.h>
#include <MDSTk/Image/mdsVolumeEdgeDetection.h>


namespace mds
{
namespace volseg
{

//==============================================================================
/*
 * Implementation of the class mds::seg::CVolumeRegionGrowing.
 */
CVolumeRegionGrowing::CVolumeRegionGrowing(double dDiffWeight,
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


void CVolumeRegionGrowing::createSeeds(const SMySeed& Seed,
                                       tVolume& Volume,
                                       int XDim,
                                       int YDim,
                                       int ZDim
                                       )
{
    SMySeed Temp(0, 0, 0, Seed.m_iIndex);
    if( Seed.m_x > 0 )
    {
        Temp.m_x = Seed.m_x - 1;
        Temp.m_y = Seed.m_y;
        Temp.m_z = Seed.m_z;
        if( int(Volume(Temp.m_x, Temp.m_y, Temp.m_z)) != Temp.m_iIndex )
        {
            m_Seeds.push_back(Temp);
        }
    }
    if( Seed.m_y > 0 )
    {
        Temp.m_x = Seed.m_x;
        Temp.m_y = Seed.m_y - 1;
        Temp.m_z = Seed.m_z;
        if( int(Volume(Temp.m_x, Temp.m_y, Temp.m_z)) != Temp.m_iIndex )
        {
            m_Seeds.push_back(Temp);
        }
    }
    if( Seed.m_z > 0 )
    {
        Temp.m_x = Seed.m_x;
        Temp.m_y = Seed.m_y;
        Temp.m_z = Seed.m_z - 1;
        if( int(Volume(Temp.m_x, Temp.m_y, Temp.m_z)) != Temp.m_iIndex )
        {
            m_Seeds.push_back(Temp);
        }
    }
    if( Seed.m_x < XDim - 1 )
    {
        Temp.m_x = Seed.m_x + 1;
        Temp.m_y = Seed.m_y;
        Temp.m_z = Seed.m_z;
        if( int(Volume(Temp.m_x, Temp.m_y, Temp.m_z)) != Temp.m_iIndex )
        {
            m_Seeds.push_back(Temp);
        }
    }
    if( Seed.m_y < YDim - 1 )
    {
        Temp.m_x = Seed.m_x;
        Temp.m_y = Seed.m_y + 1;
        Temp.m_z = Seed.m_z;
        if( int(Volume(Temp.m_x, Temp.m_y, Temp.m_z)) != Temp.m_iIndex )
        {
            m_Seeds.push_back(Temp);
        }
    }
    if( Seed.m_z < ZDim - 1 )
    {
        Temp.m_x = Seed.m_x;
        Temp.m_y = Seed.m_y;
        Temp.m_z = Seed.m_z + 1;
        if( int(Volume(Temp.m_x, Temp.m_y, Temp.m_z)) != Temp.m_iIndex )
        {
            m_Seeds.push_back(Temp);
        }
    }
}


bool CVolumeRegionGrowing::operator()(const tVolume& SrcVolume, tVolume& DstVolume)
{
    // Volume dimensions
    tSize Xdim = SrcVolume.getXSize();
    tSize Ydim = SrcVolume.getYSize();
    tSize Zdim = SrcVolume.getZSize();
    tSize Margin = SrcVolume.getMargin();

    // Check destination image dimensions
    MDS_CHECK(Xdim == DstVolume.getXSize() && Ydim == DstVolume.getYSize() && Zdim == DstVolume.getZSize(), return false);
    MDS_CHECK(Xdim > 0 && Ydim > 0 && Zdim > 0, return false);

    // Vyplni vystup
    DstVolume.fill(0);

    // Vypocet odezvy edge filtru
    tVolume EdgeVolume;
    if( m_dEdgeWeight > 0.0 )
    {
        EdgeVolume.create(Xdim, Ydim, Zdim, Margin);
        EdgeVolume.fill(0);
        mds::img::CVolumeCanny<tVolume> Filter(0.02, 0.005);
        Filter(SrcVolume, EdgeVolume);
    }

    // Zruseni seminek
    m_Seeds.clear();

    // Cislovani regionu musi zacinat od 1
    m_Regions.clear();
//    int DummyLabel = m_Regions.newLabel();
    int iMaxLabel = int(mds::CTypeTraits<tVoxel>::getMax() - 1);

    SMySeed Seed;
    int iValue, iAssignedIndex;
    double dDiff, dResult;
    double dResp = 0.0;

    // Inicializace seminka
    tSize x = 0, y = 0, z = 0;

    while( z < Zdim )
    {
        // Vyhledani seminka
        do {
            int iLabel = int(DstVolume(x++, y, z));
            if( iLabel == 0 )
            {
                int iNewLabel = m_Regions.newLabel(SMyRegion(long(SrcVolume(x - 1, y, z))));
                if( iNewLabel >= iMaxLabel )
                {
                    MDS_LOG_NOTE("The number of regions exceeds an allowed range.");
                    break;
                }
                m_Seeds.push_back(SMySeed(x - 1, y, z, iNewLabel));
            }
            else
            {
                if( x >= Xdim )
                {
                    x = 0;
                    if( ++y >= Ydim )
                    {
                        y = 0;
                        ++z;
                    }
                }
            }
        } while( m_Seeds.empty() && z < Zdim );

        // Sireni ze seminka
        while( !m_Seeds.empty() )
        {
            // Odeber prvni seminko
            Seed = m_Seeds.front();
            m_Seeds.pop_front();

            // Vyhledani regionu kam seminko patri
            SMyRegion& Region = m_Regions.getData(Seed.m_iIndex);

            // Hodnota pixelu skryteho za seminkem
            iValue = int(SrcVolume(Seed.m_x, Seed.m_y, Seed.m_z));
            iAssignedIndex = int(DstVolume(Seed.m_x, Seed.m_y, Seed.m_z));

            // Je seminko neobarvene?
            if( iAssignedIndex == 0 )
            {
                // Diference stredni hodnoty a pixelu
                dDiff = mds::math::getAbs(double(iValue) - Region.getMean());

                // Odezva LoG filtru
                if( m_dEdgeWeight > 0.0 )
                {
                    dResp = double(EdgeVolume(Seed.m_x, Seed.m_y, Seed.m_z));
                    MDS_LOG_NOTE(dResp << " " << Seed.m_x << " " << Seed.m_y << " " << Seed.m_z);
                }

                // Kombinace obou vlastnosti
                dResult = m_dDiffWeight * dDiff + m_dEdgeWeight * dResp;

                // Je vysledek mensi nez povoleny prah?
                if( dResult < m_dThreshold )
                {
                    // Pridani pixelu do regionu
                    Region.insert(iValue);
                    DstVolume(Seed.m_x, Seed.m_y, Seed.m_z) = tVoxel(Seed.m_iIndex);

                    // Vytvoreni seminek ze sousedu
                    createSeeds(Seed, DstVolume, Xdim, Ydim, Zdim);
                }
            }

            // Seminko narazilo na jiny region
            else if ( iAssignedIndex != Seed.m_iIndex )
            {
                // Vyhledani regionu kam patri
                SMyRegion& Region2 = m_Regions.getData(iAssignedIndex);

                // Je-li rozdil regionu maly, sloucime je
                if( mds::math::getAbs(Region.getMean() - Region2.getMean()) < (m_dDiffWeight * m_dThreshold) )
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
                if( mds::math::getAbs(Region1.getMean() - Region2.getMean()) < (m_dDiffWeight * m_dThreshold) )
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

    // Preindexovani
    for( z = 0; z < Zdim; ++z )
    {
        for( y = 0; y < Ydim; ++y )
        {
            for( x = 0; x < Xdim; ++x )
            {
                int iLabel = m_Regions.getLabel(int(DstVolume(x, y, z)));
                DstVolume(x, y, z) = tVoxel(iLabel);
            }
        }
    }

    // Vymazani seminek a regionu
    m_Regions.clear();
    m_Seeds.clear();

    return true;
}


} // namespace volseg
} // namespace mds

