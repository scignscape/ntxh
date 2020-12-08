//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2007 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/05/03                          \n
 *
 * $Id: mdsAnisotropic.hxx 2106 2012-02-18 21:55:47Z spanel $
 *
 * Description:
 * - Anisotropic filtering based on the diffusion process.
 */


//==============================================================================
/*
 * Methods templates.
 */

// Integration constant chosen according to the number of neighbours
template <class V>
const double CVolumeAnisotropicFilter<V>::DT          = 0.166666666666667;

// Minimal allowed change of the 
template <class V>
const double CVolumeAnisotropicFilter<V>::MIN_CHANGE  = 0.1;


template <class V>
inline double CVolumeAnisotropicFilter<V>::getDiffusionStrength(double dGrad)
{
    // Magnitude of the image gradient
    double dMagnitude = mds::math::getAbs(dGrad);
    
    // Evaluate the diffusion function
    double dTemp = m_dInvKappa * dMagnitude;
    return std::exp(-dTemp * dTemp);
}


// Image filtering method
template <class V>
bool CVolumeAnisotropicFilter<V>::operator()(const tVolume& SrcVolume, tVolume& DstVolume)
{   
    CProgress::tProgressInitializer StartProgress(*this);

    // Volume size
    tSize XSize = mds::math::getMin(SrcVolume.getXSize(), DstVolume.getXSize());
    tSize YSize = mds::math::getMin(SrcVolume.getYSize(), DstVolume.getYSize());
    tSize ZSize = mds::math::getMin(SrcVolume.getZSize(), DstVolume.getZSize());
    tSize Margin = SrcVolume.getMargin();

    // Check the margin
    MDS_CHECK(Margin >= 1, return false);

    // Copy the source volume
    DstVolume = SrcVolume;

    // Initial value of the flow
    double dFlow = 1.0;

    // Local copy of the destination volume
    tVolume DstCopy(XSize, YSize, ZSize, Margin);
    DstCopy.fillEntire(0);

    // Initialize the progress observer
    CProgress::setProgressMax(m_NumOfIters);

    // Diffusion process
    for( tSize iter = 0; ; ++iter )
    {
        // Check the number of iterations
        if( m_NumOfIters > 0 && iter >= m_NumOfIters )
        {
            break;
        }
        
        // Create a local copy of the DstVolume
        DstCopy = DstVolume;

        // Filter the volume
        double dNewFlow = 0.0;
#pragma omp parallel for schedule(static) default(shared)
        for( tSize z = 0; z < ZSize; ++z )
        {
            for( tSize y = 0; y < YSize; ++y )
            {
                for( tSize x = 0; x < XSize; ++x )
                {
                    // Evaluate volume derivatives
                    double dGradDown = double(DstCopy(x,y+1,z)) - double(DstCopy(x,y,z));
                    double dGradTop = double(DstCopy(x,y,z)) - double(DstCopy(x,y-1,z));
                    double dGradRight = double(DstCopy(x+1,y,z)) - double(DstCopy(x,y,z));
                    double dGradLeft = double(DstCopy(x,y,z)) - double(DstCopy(x-1,y,z));
                    double dGradFront = double(DstCopy(x,y,z+1)) - double(DstCopy(x,y,z));
                    double dGradBack = double(DstCopy(x,y,z)) - double(DstCopy(x,y,z-1));

                    // Evaluate the diffusion function
                    double dFlowDown = getDiffusionStrength(dGradDown) * dGradDown;
                    double dFlowTop = getDiffusionStrength(dGradTop) * dGradTop;
                    double dFlowRight = getDiffusionStrength(dGradRight) * dGradRight;
                    double dFlowLeft = getDiffusionStrength(dGradLeft) * dGradLeft;
                    double dFlowFront = getDiffusionStrength(dGradFront) * dGradFront;
                    double dFlowBack = getDiffusionStrength(dGradBack) * dGradBack;     

                    // Calculate the flow
                    double dDiff = double(SrcVolume(x,y,z)) - double(DstCopy(x,y,z));
                    double dDelta = DT * (dFlowRight - dFlowLeft + dFlowDown - dFlowTop + dFlowFront - dFlowBack + dDiff);
                    DstVolume(x,y,z) = tVoxel(double(DstVolume(x,y,z)) + dDelta);

#pragma omp critical
                    dNewFlow += mds::math::getAbs(dDelta);
                }
            }
        }
        
        // Estimate change of the volume
        double dDelta = mds::math::getAbs(dNewFlow / dFlow - 1.0);
        if( dDelta < MIN_CHANGE )
        {
            break;
        }
        dFlow = dNewFlow;

        // Notify progress observers...
        if( !CProgress::progress() )
        {
            return false;
        }
    }

    // O.K.
    return true;
}

