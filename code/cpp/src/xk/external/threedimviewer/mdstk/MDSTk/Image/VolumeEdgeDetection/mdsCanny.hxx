//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/04/24                          \n
 *
 * $Id: mdsCanny.hxx 2065 2012-02-02 23:29:38Z spanel $
 *
 * Description:
 * - Canny edge detector in 3D.
 */


//==============================================================================
/*
 * Methods of the class mds::img::CVolumeEdgeDetector<V, VED_CANNY>.
 */

// Canny edge detector
template <class V>
bool CVolumeCanny<V>::operator()(const tVolume& SrcVolume, tVolume& DstVolume)
{
    static const tVoxel Zero = CPixelTraits<tVoxel>::getZero();
    static const tVoxel Scale = CPixelTraits<tVoxel>::getPixelMax() - Zero;
    static const float fGray = CPixelTraits<tVoxel>::getGray();

    // Volume size
    tSize XSize = mds::math::getMin(SrcVolume.getXSize(), DstVolume.getXSize());
    tSize YSize = mds::math::getMin(SrcVolume.getYSize(), DstVolume.getYSize());
    tSize ZSize = mds::math::getMin(SrcVolume.getZSize(), DstVolume.getZSize());
    tSize Margin = SrcVolume.getMargin();

    // Check the margin
    MDS_CHECK(Margin >= 3, return false);

    // Size of the helper volume
    tSize BlockSize = BLOCK_SIZE + 6;

    // Helper volumes
    tVolume SmoothedVolume(BlockSize, BlockSize, BlockSize, Margin);
    tVolume GradVolumeX(BlockSize, BlockSize, BlockSize);
    tVolume GradVolumeY(BlockSize, BlockSize, BlockSize);
    tVolume GradVolumeZ(BlockSize, BlockSize, BlockSize);
    tVolume MagnitudeVolume(BlockSize, BlockSize, BlockSize);
    tVolume NonMaxMagnitudeVolume(BlockSize, BlockSize, BlockSize);

    // Clear the output image
    DstVolume.fillEntire(Zero);

    // Thresholds for the hystersis
    tVoxel T1 = tVoxel(m_dT1 * Scale);
    tVoxel T2 = tVoxel(m_dT2 * Scale);

    // Process input volume per blocks
    for( tSize K = 0; ZSize > 0; ZSize -= BLOCK_SIZE, K += BLOCK_SIZE )
    {
        tSize SZ = mds::math::getMin<tSize>(BLOCK_SIZE, ZSize);
        tSize sz = SZ;
        tSize k = K;
        tSize k2 = 0;
        if( K > 0 )
        {
            sz += 3;
            k -= 3;
            k2 += 3;
        }
        if( ZSize >= (BLOCK_SIZE + 3) )
        {
            sz += 3;
        }

        for( tSize J = 0, YCount = YSize; YCount > 0; YCount -= BLOCK_SIZE, J += BLOCK_SIZE )
        {
            tSize SY = mds::math::getMin<tSize>(BLOCK_SIZE, YCount);
            tSize sy = SY;
            tSize j = J;
            tSize j2 = 0;
            if( J > 0 )
            {
                sy += 3;
                j -= 3;
                j2 += 3;
            }
            if( YCount >= (BLOCK_SIZE + 3) )
            {
                sy += 3;
            }

            for( tSize I = 0, XCount = XSize; XCount > 0; XCount -= BLOCK_SIZE, I += BLOCK_SIZE )
            {
                tSize SX = mds::math::getMin<tSize>(BLOCK_SIZE, XCount);
                tSize sx = SX;
                tSize i = I;
                tSize i2 = 0;
                if( I > 0 )
                {
                    sx += 3;
                    i -= 3;
                    i2 += 3;
                }
                if( XCount >= (BLOCK_SIZE + 3) )
                {
                    sx += 3;
                }

                // Create block view of the original volume
                tVolume SrcVolumeRef(SrcVolume, i, j, k, sx, sy, sz, mds::REFERENCE);

                // Gaussian smoothing of the input image
//                SmoothedVolume.create(SrcVolumeRef);
//                m_GaussFilter(SrcVolumeRef, SmoothedVolume);
                SmoothedVolume.create(SrcVolumeRef);

                // TODO: Correct the gaussian smoothing because it causes that artefacts appear in the output data.

                // Compute gradient images
                m_SobelX(SmoothedVolume, GradVolumeX);
                m_SobelY(SmoothedVolume, GradVolumeY);
                m_SobelZ(SmoothedVolume, GradVolumeZ);

                // Compute the magnitude image
                for( tSize z = 0; z < sz; ++z )
                {
                    for( tSize y = 0; y < sy; ++y )
                    {
                        for( tSize x = 0; x < sx; ++x )
                        {
                            float fValue = mds::math::getAbs(float(GradVolumeX(x, y, z)) - fGray);
                            fValue += mds::math::getAbs(float(GradVolumeY(x, y, z)) - fGray);
                            fValue += mds::math::getAbs(float(GradVolumeZ(x, y, z)) - fGray);
                            MagnitudeVolume(x, y, z) = tVoxel(0.33f * fValue);
                        }
                    }
                }

                // Non-maxima suppression
                NonMaxMagnitudeVolume.fillEntire(Zero);
                nonMaxSuppression(GradVolumeX,
                                  GradVolumeY,
                                  GradVolumeZ,
                                  MagnitudeVolume,
                                  NonMaxMagnitudeVolume,
                                  i2, j2, k2,
                                  SX, SY, SZ
                                  );

                // Thresholds for the hystersis
/*              tVoxel MaxMagnitude = getMax<tVoxel>(NonMaxMagnitudeVolume);
                tVoxel T1 = tVoxel(m_dT1 * MaxMagnitude);
                tVoxel T2 = tVoxel(m_dT2 * MaxMagnitude);*/

                // Create block view of the destination volume
                tVolume DstVolumeRef(DstVolume, i, j, k, sx, sy, sz, mds::REFERENCE);

                // Hystersis
                hysteresis(NonMaxMagnitudeVolume,
                           DstVolumeRef,
                           i2, j2, k2,
                           SX, SY, SZ,
                           T1, T2
                           );
            }
        }
    }

    // O.K.
    return true;
}


template <class V>
inline void CVolumeCanny<V>::getThresholds(double& dT1, double& dT2)
{
    dT1 = m_dT1;
    dT2 = m_dT2;
}


template <class V>
inline void CVolumeCanny<V>::setThresholds(double dT1, double dT2)
{
    MDS_ASSERT(dT1 <= 1.0 && dT2 <= dT1 && dT2 >= 0.0);

    m_dT1 = dT1;
    m_dT2 = dT2;
}


template <class V>
void CVolumeCanny<V>::nonMaxSuppression(const tVolume& GradVolumeX,
                                        const tVolume& GradVolumeY,
                                        const tVolume& GradVolumeZ,
                                        tVolume& MagnitudeVolume,
                                        tVolume& Volume,
                                        tSize x,
                                        tSize y,
                                        tSize z,
                                        tSize XSize,
                                        tSize YSize,
                                        tSize ZSize
                                        )
{
    static const tVoxel Zero = tVoxel(0);
    static const tCoordinate Gray = CPixelTraits<tVoxel>::getGray();

    // Maximum
    tSize XMax = x + XSize;
    tSize YMax = y + YSize;
    tSize ZMax = z + ZSize;

    // For each voxel
    for( tSize k = z; k < ZMax; ++k )
    {
        for( tSize j = y; j < YMax; ++j )
        {
            for( tSize i = x; i < XMax; ++i )
            {
                // Check the voxel value
                tVoxel Value = MagnitudeVolume(i, j, k);
                if( Value > Zero )
                {
                    // Derivatives in x,y and z direction
                    tCoordinate cx = tCoordinate(GradVolumeX(i, j, k)) - Gray;
                    tCoordinate cy = tCoordinate(GradVolumeY(i, j, k)) - Gray;
                    tCoordinate cz = tCoordinate(GradVolumeZ(i, j, k)) - Gray;
//                    if( mds::math::getAbs(cx) < 100
//                        && mds::math::getAbs(cy) < 100
//                        && mds::math::getAbs(cz) < 100 )
                    if( mds::math::getAbs(cx) < 10
                        && mds::math::getAbs(cy) < 10
                        && mds::math::getAbs(cz) < 10 )
                    {
                        Volume.set(i, j, k, Value);
                        continue;
                    }

                    // Estimate orientation of the edge
                    CVector3D Orient(cx, cy, cz);
                    Orient.normalize();
                    Orient *= 0.75;

                    // Voxel neighbours
                    CPoint3D Left(i + Orient.x(), j + Orient.y(), k + Orient.z());
                    CPoint3D Right(i - Orient.x(), j - Orient.y(), k - Orient.z());

                    // Interpolate voxel value in place of neighbours
                    tVoxel LeftValue = MagnitudeVolume.interpolate(Left);
                    tVoxel RightValue = MagnitudeVolume.interpolate(Right);

                    // Check if the voxel is local maximum
                    if( Value >= LeftValue && Value >= RightValue )
                    {
                        Volume.set(i, j, k, Value);
                    }
                }
            }
        }
    }
}


template <class V>
void CVolumeCanny<V>::hysteresis(tVolume& MagnitudeVolume,
                                 tVolume& Volume,
                                 tSize x,
                                 tSize y,
                                 tSize z,
                                 tSize XSize,
                                 tSize YSize,
                                 tSize ZSize,
                                 tVoxel T1,
                                 tVoxel T2
                                 )
{
    // Maximum
    tSize XMax = x + XSize;
    tSize YMax = y + YSize;
    tSize ZMax = z + ZSize;

    // Accept all pixels whose magnitude exceeds the T1 threshold
    tSize i, j, k;
    for( k = z; k < ZMax; ++k )
    {
        for( j = y; j < YMax; ++j )
        {
            for( i = x; i < XMax; ++i )
            {
                tVoxel Value = MagnitudeVolume(i, j, k);
                if( Value >= T1 )
                {
                    Volume.set(i, j, k, Value);
                }
            }
        }
    }

    // The number of new edge pixels
    int iCount;

    // Until stability is achieved
    do {
        // Reset the number of new edge pixels
        iCount = 0;

        // For each pixel
        for( k = z; k < ZMax; ++k )
        {
            for( j = y; j < YMax; ++j )
            {
                for( i = x; i < XMax; ++i )
                {
                    // Check the pixel value
                    tVoxel Value = MagnitudeVolume(i, j, k);
                    if( Value >= T2 && Value < T1 )
                    {
                        // Check the neighbours
                        if( checkNeighbours(MagnitudeVolume, i, j, k, T1) )
                        {
                            Volume.set(i, j, k, Value);
                            MagnitudeVolume.set(i, j, k, T1);
                            ++iCount;
                        }
                    }
                }
            }
        }
    } while( iCount > 0 );
}


template <class V>
bool CVolumeCanny<V>::checkNeighbours(tVolume& Volume,
                                      tSize x,
                                      tSize y,
                                      tSize z,
                                      tVoxel T
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
