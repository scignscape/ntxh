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
 * Copyright (c) 2003-2007 by Michal Spanel   
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz
 * Date:    2007/07/03                        
 *
 * Description:
 * - Volume 3D corner/landmark detector based on Susan image corner detector.
 */


//==============================================================================
/*
 * Methods of the class vpl::img::CVolumeCornerDetector<V, VCD_SUSAN>.
 */

template <class V>
inline CSusanLandmarks<V>::CSusanLandmarks(double dThreshold, double dWidth)
    : m_dThreshold(dThreshold)
    , m_dWidth((dWidth > 0.0) ? dWidth : 1.0)
{
    VPL_ASSERT(dThreshold >= 0.0 && dThreshold <= 1.0 && dWidth > 0.0);

    m_dInvWidth = 1.0 / m_dWidth;

    initLUT();
}


template <class V>
bool CSusanLandmarks<V>::operator()(const tVolume& SrcVolume, tCorners& Corners)
{
    // Number of voxels in a cube corresponding to the sphere mask
    static const int iNumOfVoxels = 171;
    static const double dNorm = 1.0 / (iNumOfVoxels * MAX_LUT);
    static const int iRadiusThreshold = 11;

    // Volume size
    tSize XSize = SrcVolume.getXSize();
    tSize YSize = SrcVolume.getYSize();
    tSize ZSize = SrcVolume.getZSize();
    tSize Margin = SrcVolume.getMargin();

    // Check the margin
    if( Margin < 3 )
    {
        return false;
    }

    // Detection threshold
    int iThreshold = int(iNumOfVoxels * MAX_LUT * m_dThreshold);

    // Size of the helper volume
    tSize BlockSize = BLOCK_SIZE + 6;

    // Helper volumes
    CVolume8 HelperSrcVolume(BlockSize, BlockSize, BlockSize, Margin);
    CFVolume CornerVolume(BlockSize, BlockSize, BlockSize, Margin);

    // Clear the output vector
    Corners.clear();

    // Process input volume per blocks
    for( tSize K = 0; ZSize > 0; ZSize -= BLOCK_SIZE, K += BLOCK_SIZE )
    {
        tSize SZ = vpl::math::getMin<tSize>(BLOCK_SIZE, ZSize);
        tSize sz = SZ;
        tSize k = K;
        tSize k2 = 0;
        if( K > 0 )
        {
            sz += 3;
            k -= 3;
            k2 += 3;
        }
        if( ZSize > BLOCK_SIZE )
        {
            sz += 3;
        }

        for( tSize J = 0, YCount = YSize; YCount > 0; YCount -= BLOCK_SIZE, J += BLOCK_SIZE )
        {
            tSize SY = vpl::math::getMin<tSize>(BLOCK_SIZE, YCount);
            tSize sy = SY;
            tSize j = J;
            tSize j2 = 0;
            if( J > 0 )
            {
                sy += 3;
                j -= 3;
                j2 += 3;
            }
            if( YCount > BLOCK_SIZE )
            {
                sy += 3;
            }

            for( tSize I = 0, XCount = XSize; XCount > 0; XCount -= BLOCK_SIZE, I += BLOCK_SIZE )
            {
                tSize SX = vpl::math::getMin<tSize>(BLOCK_SIZE, XCount);
                tSize sx = SX;
                tSize i = I;
                tSize i2 = 0;
                if( I > 0 )
                {
                    sx += 3;
                    i -= 3;
                    i2 += 3;
                }
                if( XCount > BLOCK_SIZE )
                {
                    sx += 3;
                }

                // Create block view of the original volume
                tVolume SrcVolumeRef(SrcVolume, i, j, k, sx, sy, sz, vpl::REFERENCE);

                // Convert volume to Image8
                HelperSrcVolume.convert(SrcVolumeRef);

                // Clear the corner volume
                CornerVolume.fillEntire(0.0f);

                // Estimate cornerness
                tSize x, y, z;
                for( z = 0; z < sz; ++z )
                {
                    for( y = 0; y < sy; ++y )
                    {
                        for( x = 0; x < sx; ++x )
                        {
                            // Nucleus of the circle mask
                            tPixel8 Value = HelperSrcVolume(x,y,z);

                            // Center of gravity and cornerness
                            int cx = 0, cy = 0, cz = 0, iCornerness = 0;

                            // Count the difference of pixels from the nucleus
                            for( tSize wk = -3; wk <= 3; ++wk )
                            {
                                for( tSize wj = -3; wj <= 3; ++wj )
                                {
                                    int iSphere = wj * wj + wk * wk;
                                    if( iSphere <= iRadiusThreshold )
                                    {
                                        int iTemp = getDiff(HelperSrcVolume(x,y+wj,z+wk), Value);
                                        iCornerness += iTemp;
                                        cy += wj * iTemp;
                                        cz += wk * iTemp;
                                    }

                                    if( (iSphere + 1) <= iRadiusThreshold )
                                    {
                                        int iTemp = getDiff(HelperSrcVolume(x+1,y+wj,z+wk), Value);
                                        iCornerness += iTemp;
                                        cx += iTemp;
                                        cy += wj * iTemp;
                                        cz += wk * iTemp;

                                        iTemp = getDiff(HelperSrcVolume(x-1,y+wj,z+wk), Value);
                                        iCornerness += iTemp;
                                        cx -= iTemp;
                                        cy += wj * iTemp;
                                        cz += wk * iTemp;
                                    }

                                    if( (iSphere + 4) <= iRadiusThreshold )
                                    {
                                        int iTemp = getDiff(HelperSrcVolume(x+2,y+wj,z+wk), Value);
                                        iCornerness += iTemp;
                                        cx += 2 * iTemp;
                                        cy += wj * iTemp;
                                        cz += wk * iTemp;

                                        iTemp = getDiff(HelperSrcVolume(x-2,y+wj,z+wk), Value);
                                        iCornerness += iTemp;
                                        cx -= 2 * iTemp;
                                        cy += wj * iTemp;
                                        cz += wk * iTemp;
                                    }

                                    if( iCornerness > iThreshold )
                                    {
                                        break;
                                    }
                                }
                            }

                            // Compare cornerness against the threshold
                            if( iCornerness > iThreshold )
                            {
                                continue;
                            }

                            // Check distance of the center of gravity from the nucleus
                            // - The distance must be larger then 1/2
                            int cxx = cx * cx;
                            int cyy = cy * cy;
                            int czz = cz * cz;
                            if( 2 * (cxx + cyy + czz) < (iCornerness * iCornerness) )
                            {
                                continue;
                            }

                            // Check all pixels in the direction of the center of gravity
                            if( cxx >= cyy && cxx >= czz )
                            {
                                int dx = (cx > 0) ? 1 : -1;
                                double dy = double(cy) / vpl::math::getAbs(cx);
                                double dz = double(cz) / vpl::math::getAbs(cx);

                                int iValue = getDiff(HelperSrcVolume(x+dx,vpl::math::round2Int(y+dy),vpl::math::round2Int(z+dz)), Value);
                                iValue += getDiff(HelperSrcVolume(x+2*dx,vpl::math::round2Int(y+2*dy),vpl::math::round2Int(z+2*dz)), Value);
                                iValue += getDiff(HelperSrcVolume(x+3*dx,vpl::math::round2Int(y+3*dy),vpl::math::round2Int(z+3*dz)), Value);

                                if( iValue < DIFF_THRESHOLD )
                                {
                                    continue;
                                }
                            }
                            else if( cyy >= cxx && cyy >= czz )
                            {
                                double dx = double(cx) / vpl::math::getAbs(cy);
                                int dy = (cy > 0) ? 1 : -1;
                                double dz = double(cz) / vpl::math::getAbs(cy);

                                int iValue = getDiff(HelperSrcVolume(vpl::math::round2Int(x+dx),y+dy,vpl::math::round2Int(z+dz)), Value);
                                iValue += getDiff(HelperSrcVolume(vpl::math::round2Int(x+2*dx),y+2*dy,vpl::math::round2Int(z+2*dz)), Value);
                                iValue += getDiff(HelperSrcVolume(vpl::math::round2Int(x+3*dx),y+2*dy,vpl::math::round2Int(z+3*dz)), Value);

                                if( iValue < DIFF_THRESHOLD )
                                {
                                    continue;
                                }
                            }
                            else if( czz >= cxx && czz >= cyy )
                            {
                                double dx = double(cx) / vpl::math::getAbs(cz);
                                double dy = double(cy) / vpl::math::getAbs(cz);
                                int dz = (cz > 0) ? 1 : -1;

                                int iValue = getDiff(HelperSrcVolume(vpl::math::round2Int(x+dx),vpl::math::round2Int(y+dy),z+dz), Value);
                                iValue += getDiff(HelperSrcVolume(vpl::math::round2Int(x+2*dx),vpl::math::round2Int(y+2*dy),z+2*dz), Value);
                                iValue += getDiff(HelperSrcVolume(vpl::math::round2Int(x+3*dx),vpl::math::round2Int(y+3*dy),z+3*dz), Value);

                                if( iValue < DIFF_THRESHOLD )
                                {
                                    continue;
                                }
                            }
                            else
                            {
                                continue;
                            }

                            // Final cornerness
                            CornerVolume(x,y,z) = tFloatPixel(m_dThreshold - dNorm * iCornerness);
                        }
                    }
                }

                // Non-maxima suppression
                tSize MaxX = i2 + SX;
                tSize MaxY = j2 + SY;
                tSize MaxZ = k2 + SZ;
                for( z = k2; z < MaxZ; ++z )
                {
                    for( y = j2; y < MaxY; ++y )
                    {
                        for( x = i2; x < MaxX; ++x )
                        {
                            // Get cornerness
                            tFloatPixel Value = CornerVolume(x,y,z);

                            // Check the neighbours
                            if( !checkNeighbours(CornerVolume, x, y, z, Value) )
                            {
                                // New landmark found
                                Corners.push_back(CPoint3D(i + x, j + y, k + z));
                            }
                        }
                    }
                }
            }
        }
    }

    // O.K.
    return true;
}


template <class V>
inline void CSusanLandmarks<V>::setThreshold(double dThreshold)
{
    VPL_ASSERT(dThreshold <= 1.0 && dThreshold >= 0.0);

    m_dThreshold = dThreshold;
}


template <class V>
inline void CSusanLandmarks<V>::setWidth(double dWidth)
{
    VPL_ASSERT(dWidth > 0.0);

    m_dWidth = (dWidth > 0.0) ? dWidth : 1.0;
    m_dInvWidth = 1.0 / m_dWidth;

    initLUT();
}


template <class V>
inline bool CSusanLandmarks<V>::checkNeighbours(CFVolume& Volume,
                                                tSize x,
                                                tSize y,
                                                tSize z,
                                                tFloatPixel T
                                                )
{
    // Volume properties
    tSize XOffset = Volume.getXOffset();
    tSize YOffset = Volume.getYOffset();
    tSize ZOffset = Volume.getZOffset();

    // Index of the center
    tSize idx = Volume.getIdx(x, y, z);

    // Check the neighbours
    return (Volume(idx + YOffset) >= T
            || Volume(idx - YOffset) >= T
            || Volume(idx + XOffset) >= T
            || Volume(idx + XOffset + YOffset) >= T
            || Volume(idx + XOffset - YOffset) >= T
            || Volume(idx - XOffset) >= T
            || Volume(idx - XOffset + YOffset) >= T
            || Volume(idx - XOffset - YOffset) >= T
            || Volume(idx + ZOffset) >= T
            || Volume(idx + ZOffset + YOffset) >= T
            || Volume(idx + ZOffset - YOffset) >= T
            || Volume(idx + ZOffset + XOffset) >= T
            || Volume(idx + ZOffset + XOffset + YOffset) >= T
            || Volume(idx + ZOffset + XOffset - YOffset) >= T
            || Volume(idx + ZOffset - XOffset) >= T
            || Volume(idx + ZOffset - XOffset + YOffset) >= T
            || Volume(idx + ZOffset - XOffset - YOffset) >= T
            || Volume(idx - ZOffset) >= T
            || Volume(idx - ZOffset + YOffset) >= T
            || Volume(idx - ZOffset - YOffset) >= T
            || Volume(idx - ZOffset + XOffset) >= T
            || Volume(idx - ZOffset + XOffset + YOffset) >= T
            || Volume(idx - ZOffset + XOffset - YOffset) >= T
            || Volume(idx - ZOffset - XOffset) >= T
            || Volume(idx - ZOffset - XOffset + YOffset) >= T
            || Volume(idx - ZOffset - XOffset - YOffset) >= T
           );
}


template <class V>
void CSusanLandmarks<V>::initLUT()
{
    for( tSize i = -MAX_LUT; i <= MAX_LUT; ++i )
    {
        double dTemp = m_dInvWidth * i;
        dTemp = dTemp * dTemp;
        m_LUT(i + MAX_LUT) = tPixel8(MAX_LUT * std::exp(-dTemp * dTemp * dTemp));
    }
}


template <class V>
inline int CSusanLandmarks<V>::getDiff(tPixel8 a, tPixel8 b)
{
    tSize Index = tSize(a) - tSize(b);
    return m_LUT(Index + MAX_LUT);
}

