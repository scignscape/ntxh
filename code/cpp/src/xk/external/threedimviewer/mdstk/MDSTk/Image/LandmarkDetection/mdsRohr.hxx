//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)     \n
 * Copyright (c) 2003-2007 by Michal Spanel      \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz   \n
 * Date:    2007/07/03                           \n
 *
 * $Id: mdsRohr.hxx 2102 2012-02-17 09:12:21Z spanel $
 *
 * Description:
 * - 3D corner/landmark detector based on Rohr's 3D differential operators.
 * - Algorithm is partially similar to the well-known Harris image corner detector.
 */


//==============================================================================
/*
 * Methods of the class mds::img::CVolumeCornerDetector<V, VCD_ROHR>.
 */

template <class V>
bool CRohrLandmarks<V>::operator()(const tVolume& SrcVolume, tCorners& Corners)
{
    // Volume size
    tSize XSize = SrcVolume.getXSize();
    tSize YSize = SrcVolume.getYSize();
    tSize ZSize = SrcVolume.getZSize();
    tSize Margin = SrcVolume.getMargin();

    // Check the margin
    tSize HalfWindowSize = m_WindowSize >> 1;
    if( Margin < HalfWindowSize )
    {
        return false;
    }

    // Size of the helper volume
    tSize BlockSize = BLOCK_SIZE + 2 * HalfWindowSize;

    // Helper volumes
    CFVolume FloatSrcVolume(BlockSize, BlockSize, BlockSize, Margin);
    CFVolume IxxVolume(BlockSize, BlockSize, BlockSize, Margin);
    CFVolume IyyVolume(BlockSize, BlockSize, BlockSize, Margin);
    CFVolume IzzVolume(BlockSize, BlockSize, BlockSize, Margin);
    CFVolume IxyVolume(BlockSize, BlockSize, BlockSize, Margin);
    CFVolume IxzVolume(BlockSize, BlockSize, BlockSize, Margin);
    CFVolume IyzVolume(BlockSize, BlockSize, BlockSize, Margin);
    CFVolume CornerVolume(BlockSize, BlockSize, BlockSize, Margin);

    // Initialize volumes
    IxxVolume.fillEntire(0.0);
    IyyVolume.fillEntire(0.0);
    IzzVolume.fillEntire(0.0);
    IxyVolume.fillEntire(0.0);
    IxzVolume.fillEntire(0.0);
    IyzVolume.fillEntire(0.0);

    // Clear the output vector
    Corners.clear();

    // Process input volume per blocks
    for( tSize K = 0; ZSize > 0; ZSize -= BLOCK_SIZE, K += BLOCK_SIZE )
    {
        tSize SZ = mds::math::getMin<tSize>(BLOCK_SIZE, ZSize);
        tSize sz = SZ;
        tSize k = K;
        tSize k2 = 0;
        if( K > 0 )
        {
            sz += HalfWindowSize;
            k -= HalfWindowSize;
            k2 += HalfWindowSize;
        }
        if( ZSize > BLOCK_SIZE )
        {
            sz += HalfWindowSize;
        }

        for( tSize J = 0, YCount = YSize; YCount > 0; YCount -= BLOCK_SIZE, J += BLOCK_SIZE )
        {
            tSize SY = mds::math::getMin<tSize>(BLOCK_SIZE, YCount);
            tSize sy = SY;
            tSize j = J;
            tSize j2 = 0;
            if( J > 0 )
            {
                sy += HalfWindowSize;
                j -= HalfWindowSize;
                j2 += HalfWindowSize;
            }
            if( YCount > BLOCK_SIZE )
            {
                sy += HalfWindowSize;
            }

            for( tSize I = 0, XCount = XSize; XCount > 0; XCount -= BLOCK_SIZE, I += BLOCK_SIZE )
            {
                tSize SX = mds::math::getMin<tSize>(BLOCK_SIZE, XCount);
                tSize sx = SX;
                tSize i = I;
                tSize i2 = 0;
                if( I > 0 )
                {
                    sx += HalfWindowSize;
                    i -= HalfWindowSize;
                    i2 += HalfWindowSize;
                }
                if( XCount > BLOCK_SIZE )
                {
                    sx += HalfWindowSize;
                }

                // Create block view of the original volume
                tVolume SrcVolumeRef(SrcVolume, i, j, k, sx, sy, sz, mds::REFERENCE);

                // Convert volume to float
                FloatSrcVolume.convert(SrcVolumeRef);

                // Compute derivatives
                tSize x, y, z;
                for( z = 0; z < sz; ++z )
                {
                    for( y = 0; y < sy; ++y )
                    {
                        for( x = 0; x < sz; ++x )
                        {
                            // Derivatives                
                            tFloatPixel Ix = tFloatPixel(m_SobelX.getResponse(FloatSrcVolume, x, y, z));
                            tFloatPixel Iy = tFloatPixel(m_SobelY.getResponse(FloatSrcVolume, x, y, z));
                            tFloatPixel Iz = tFloatPixel(m_SobelZ.getResponse(FloatSrcVolume, x, y, z));
                            
                            // Fill helper volumes
                            IxxVolume(x,y,z) = Ix * Ix;
                            IyyVolume(x,y,z) = Iy * Iy;
                            IzzVolume(x,y,z) = Iz * Iz;
                            IxyVolume(x,y,z) = Ix * Iy;
                            IxzVolume(x,y,z) = Ix * Iz;
                            IyzVolume(x,y,z) = Iy * Iz;
                        }
                    }
                }
                
                // Mirror margins
                IxxVolume.mirrorMargin();
                IyyVolume.mirrorMargin();
                IzzVolume.mirrorMargin();
                IxyVolume.mirrorMargin();
                IxzVolume.mirrorMargin();
                IyzVolume.mirrorMargin();
                
                // Estimate cornerness
                for( z = 0; z < sz; ++z )
                {
                    for( y = 0; y < sy; ++y )
                    {
                        for( x = 0; x < sz; ++x )
                        {
                            // Sum derivatives over a small sub-window
                            mds::math::CDMatrix3x3 Matrix;
                            Matrix.fill(0.0);
                            tSize mwx = x + HalfWindowSize;
                            tSize mwy = y + HalfWindowSize;
                            tSize mwz = z + HalfWindowSize;
                            for( tSize wz = z - HalfWindowSize; wz <= mwz; ++wz )
                            {
                                for( tSize wy = y - HalfWindowSize; wy <= mwy; ++wy )
                                {
                                    for( tSize wx = x - HalfWindowSize; wx <= mwx; ++wx )
                                    {
                                        Matrix(0,0) += IxxVolume(wx,wy,wz);
                                        Matrix(0,1) += IxyVolume(wx,wy,wz);
                                        Matrix(0,2) += IxzVolume(wx,wy,wz);
                                        Matrix(1,1) += IyyVolume(wx,wy,wz);
                                        Matrix(1,2) += IyzVolume(wx,wy,wz);
                                        Matrix(2,2) += IzzVolume(wx,wy,wz);
                                    }
                                }
                            }
                            Matrix(1,0) = Matrix(0,1);
                            Matrix(2,0) = Matrix(0,2);
                            Matrix(2,1) = Matrix(1,2);
                            
//                            MDS_LOG_NOTE(Matrix);
                            
                            // Rohr's operator
                            double dTrace = mds::math::getTrace<double>(Matrix);
                            double dDeterminant = mds::math::getDeterminant<double>(Matrix);

                            // Check trace of the matrix
                            double dCornerness = 0.0;
                            if( dTrace > 0.000001 )
                            {
                                // Evaluate Rohr's cornerness operator
                                dCornerness = dDeterminant / dTrace;
    
                                // Suppress points on edges
                                double dTest = dDeterminant / (0.037037 * dTrace * dTrace * dTrace);
                                if( dTest < m_dEdgeThreshold )
                                {
                                    dCornerness = 0.0;
                                }
                            }

//                            MDS_LOG_NOTE(dCornerness);
                            
                            // Store estimated cornerness
                            CornerVolume(x,y,z) = tFloatPixel(mds::math::getAbs(dCornerness));
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
                            
                            // Check its minimal value
                            if( Value < m_dThreshold )
                            {
                                continue;
                            }
                            
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
bool CRohrLandmarks<V>::operator()(const tVolume& SrcVolume, tVolume& DstVolume)
{
    // Normalization of the cornerness function
//    static const tVoxel Min = CPixelTraits<tVoxel>::getPixelMin();
    static const tVoxel Max = CPixelTraits<tVoxel>::getPixelMax();
    static const double dOutputNorm = double(Max) / 1000.0;
    
    // Volume size
    tSize XSize = mds::math::getMin(SrcVolume.getXSize(), DstVolume.getXSize());
    tSize YSize = mds::math::getMin(SrcVolume.getYSize(), DstVolume.getYSize());
    tSize ZSize = mds::math::getMin(SrcVolume.getZSize(), DstVolume.getZSize());
    tSize Margin = SrcVolume.getMargin();

    // Check the margin
    tSize HalfWindowSize = m_WindowSize >> 1;
    if( Margin < HalfWindowSize )
    {
        return false;
    }

    // Size of the helper volume
    tSize BlockSize = BLOCK_SIZE + 2 * HalfWindowSize;

    // Helper volumes
    CFVolume FloatSrcVolume(BlockSize, BlockSize, BlockSize, Margin);
    CFVolume IxxVolume(BlockSize, BlockSize, BlockSize, Margin);
    CFVolume IyyVolume(BlockSize, BlockSize, BlockSize, Margin);
    CFVolume IzzVolume(BlockSize, BlockSize, BlockSize, Margin);
    CFVolume IxyVolume(BlockSize, BlockSize, BlockSize, Margin);
    CFVolume IxzVolume(BlockSize, BlockSize, BlockSize, Margin);
    CFVolume IyzVolume(BlockSize, BlockSize, BlockSize, Margin);

    // Initialize volumes
    IxxVolume.fillEntire(0.0);
    IyyVolume.fillEntire(0.0);
    IzzVolume.fillEntire(0.0);
    IxyVolume.fillEntire(0.0);
    IxzVolume.fillEntire(0.0);
    IyzVolume.fillEntire(0.0);

    // Clear the corner volume
    DstVolume.fillEntire(0);

    // Process input volume per blocks
    for( tSize K = 0; ZSize > 0; ZSize -= BLOCK_SIZE, K += BLOCK_SIZE )
    {
        tSize SZ = mds::math::getMin<tSize>(BLOCK_SIZE, ZSize);
        tSize sz = SZ;
        tSize k = K;
        tSize k2 = 0;
        if( K > 0 )
        {
            sz += HalfWindowSize;
            k -= HalfWindowSize;
            k2 += HalfWindowSize;
        }
        if( ZSize > BLOCK_SIZE )
        {
            sz += HalfWindowSize;
        }

        for( tSize J = 0, YCount = YSize; YCount > 0; YCount -= BLOCK_SIZE, J += BLOCK_SIZE )
        {
            tSize SY = mds::math::getMin<tSize>(BLOCK_SIZE, YCount);
            tSize sy = SY;
            tSize j = J;
            tSize j2 = 0;
            if( J > 0 )
            {
                sy += HalfWindowSize;
                j -= HalfWindowSize;
                j2 += HalfWindowSize;
            }
            if( YCount > BLOCK_SIZE )
            {
                sy += HalfWindowSize;
            }

            for( tSize I = 0, XCount = XSize; XCount > 0; XCount -= BLOCK_SIZE, I += BLOCK_SIZE )
            {
                tSize SX = mds::math::getMin<tSize>(BLOCK_SIZE, XCount);
                tSize sx = SX;
                tSize i = I;
                tSize i2 = 0;
                if( I > 0 )
                {
                    sx += HalfWindowSize;
                    i -= HalfWindowSize;
                    i2 += HalfWindowSize;
                }
                if( XCount > BLOCK_SIZE )
                {
                    sx += HalfWindowSize;
                }

                // Create block view of the original volume
                tVolume SrcVolumeRef(SrcVolume, i, j, k, sx, sy, sz, mds::REFERENCE);

                // Convert volume to float
                FloatSrcVolume.convert(SrcVolumeRef);

                // Compute derivatives
                tSize x, y, z;
                for( z = 0; z < sz; ++z )
                {
                    for( y = 0; y < sy; ++y )
                    {
                        for( x = 0; x < sz; ++x )
                        {
                            // Derivatives                
                            tFloatPixel Ix = tFloatPixel(m_SobelX.getResponse(FloatSrcVolume, x, y, z));
                            tFloatPixel Iy = tFloatPixel(m_SobelY.getResponse(FloatSrcVolume, x, y, z));
                            tFloatPixel Iz = tFloatPixel(m_SobelZ.getResponse(FloatSrcVolume, x, y, z));
                            
                            // Fill helper volumes
                            IxxVolume(x,y,z) = Ix * Ix;
                            IyyVolume(x,y,z) = Iy * Iy;
                            IzzVolume(x,y,z) = Iz * Iz;
                            IxyVolume(x,y,z) = Ix * Iy;
                            IxzVolume(x,y,z) = Ix * Iz;
                            IyzVolume(x,y,z) = Iy * Iz;
                        }
                    }
                }
                
                // Mirror margins
                IxxVolume.mirrorMargin();
                IyyVolume.mirrorMargin();
                IzzVolume.mirrorMargin();
                IxyVolume.mirrorMargin();
                IxzVolume.mirrorMargin();
                IyzVolume.mirrorMargin();
                
                // Estimate cornerness
                for( z = 0; z < sz; ++z )
                {
                    for( y = 0; y < sy; ++y )
                    {
                        for( x = 0; x < sz; ++x )
                        {
                            // Sum derivatives over a small sub-window
                            mds::math::CDMatrix3x3 Matrix;
                            Matrix.fill(0.0);
                            tSize mwx = x + HalfWindowSize;
                            tSize mwy = y + HalfWindowSize;
                            tSize mwz = z + HalfWindowSize;
                            for( tSize wz = z - HalfWindowSize; wz <= mwz; ++wz )
                            {
                                for( tSize wy = y - HalfWindowSize; wy <= mwy; ++wy )
                                {
                                    for( tSize wx = x - HalfWindowSize; wx <= mwx; ++wx )
                                    {
                                        Matrix(0,0) += IxxVolume(wx,wy,wz);
                                        Matrix(0,1) += IxyVolume(wx,wy,wz);
                                        Matrix(0,2) += IxzVolume(wx,wy,wz);
                                        Matrix(1,1) += IyyVolume(wx,wy,wz);
                                        Matrix(1,2) += IyzVolume(wx,wy,wz);
                                        Matrix(2,2) += IzzVolume(wx,wy,wz);
                                    }
                                }
                            }
                            Matrix(1,0) = Matrix(0,1);
                            Matrix(2,0) = Matrix(0,2);
                            Matrix(2,1) = Matrix(1,2);
                            
//                            MDS_LOG_NOTE(Matrix);
                            
                            // Rohr's operator
                            double dTrace = mds::math::getTrace<double>(Matrix);
                            double dDeterminant = mds::math::getDeterminant<double>(Matrix);
                            
                            // Check trace of the matrix
                            double dCornerness = 0.0;
                            if( dTrace > 0.000001 && dDeterminant > 0.0 )
                            {
                                // Evaluate Rohr's cornerness operator
                                dCornerness = dDeterminant / dTrace;
    
                                // Suppress points on edges
                                double dTest = dDeterminant / (0.037037 * dTrace * dTrace * dTrace);
                                if( dTest < m_dEdgeThreshold )
                                {
                                    dCornerness = 0.0;
                                }
                            }
                            
//                            MDS_LOG_NOTE(dCornerness);
//                            MDS_LOG_NOTE(dDeterminant);
                            
                            // Store estimated cornerness
                            dCornerness = dCornerness * dOutputNorm;
//                            double dCornerness = mds::math::getAbs(dDeterminant) * dOutputNorm;
                            DstVolume(i+x,j+y,k+z) = (dCornerness > Max) ? Max : tVoxel(dCornerness);
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
inline void CRohrLandmarks<V>::setThreshold(double dThreshold)
{
    MDS_ASSERT(dThreshold <= 1.0 && dThreshold >= 0.0);

    m_dThreshold = dThreshold;
}


template <class V>
inline void CRohrLandmarks<V>::setEdgeThreshold(double dEdgeThreshold)
{
    MDS_ASSERT(dEdgeThreshold <= 1.0 && dEdgeThreshold >= 0.0);

    m_dEdgeThreshold = dEdgeThreshold;
}


template <class V>
inline bool CRohrLandmarks<V>::checkNeighbours(CFVolume& Volume,
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

