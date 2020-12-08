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
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/04/20                       
 *
 * Description:
 * - Anisotropic filtering based on the diffusion process.
 */


//==============================================================================
/*
 * Methods templates.
 */

// Integration constant chosen according to the number of neighbours
template <class I>
//const double CAnisotropicFilter<I>::DT          = 0.2;
const double CAnisotropicFilter<I>::DT          = 0.125;

// Minimal allowed change of the 
template <class I>
//const double CAnisotropicFilter<I>::MIN_CHANGE  = 0.01;
const double CAnisotropicFilter<I>::MIN_CHANGE  = 0.1;


template <class I>
inline double CAnisotropicFilter<I>::getDiffusionStrength(double dGrad)
{
    // Magnitude of the image gradient
    double dMagnitude = vpl::math::getAbs(dGrad);
    
    // Evaluate the diffusion function
    double dTemp = m_dInvKappa * dMagnitude;
    return std::exp(-dTemp * dTemp);
}


// Image filtering method
template <class I>
bool CAnisotropicFilter<I>::operator()(const tImage& SrcImage, tImage& DstImage)
{
    static const double INV_SQRT2 = 1.0 / vpl::math::SQRT2;
    
    // Image size
    tSize XCount = vpl::math::getMin(SrcImage.getXSize(), DstImage.getXSize());
    tSize YCount = vpl::math::getMin(SrcImage.getYSize(), DstImage.getYSize());
    
    // Check the image margin
    tSize Margin = SrcImage.getMargin();
    if( Margin < 1 )
    {
        return false;
    }
    
    // Copy the source image
    DstImage = SrcImage;

    // Helper image
    CFImage FlowImage(XCount, YCount);

    // Initial value of the flow
    double dFlow = 1.0;

    // Diffusion process
    tSize x, y;
    for( tSize iter = 0; ; ++iter )
    {
        // Check the number of iterations
        if( m_NumOfIters > 0 && iter >= m_NumOfIters )
        {
            break;
        }
        
        // Clear the flow image
        FlowImage.fill(0);
       
        // Filter the image
#pragma omp parallel for schedule(static) default(shared)
        for( y = 0; y < YCount; ++y )
        {
            for( x = 0; x < XCount; ++x )
            {
                // Evaluate image derivatives
                double dGradDown = double(DstImage(x,y+1)) - double(DstImage(x,y));
                double dGradTop = double(DstImage(x,y)) - double(DstImage(x,y-1));
                double dGradRight = double(DstImage(x+1,y)) - double(DstImage(x,y)); 
                double dGradLeft = double(DstImage(x,y)) - double(DstImage(x-1,y));

                double dGradTL = INV_SQRT2 * (double(DstImage(x,y)) - double(DstImage(x-1,y-1))); 
                double dGradDR = INV_SQRT2 * (double(DstImage(x+1,y+1)) - double(DstImage(x,y))); 
                double dGradTR = INV_SQRT2 * (double(DstImage(x+1,y-1)) - double(DstImage(x,y))); 
                double dGradDL = INV_SQRT2 * (double(DstImage(x,y)) - double(DstImage(x-1,y+1))); 

                // Evaluate the diffusion function
                double dFlowDown = getDiffusionStrength(dGradDown) * dGradDown;  
                double dFlowTop = getDiffusionStrength(dGradTop) * dGradTop;
                double dFlowRight = getDiffusionStrength(dGradRight) * dGradRight;  
                double dFlowLeft = getDiffusionStrength(dGradLeft) * dGradLeft;  
                
                double dFlowTL = getDiffusionStrength(dGradTL) * dGradTL;  
                double dFlowDR = getDiffusionStrength(dGradDR) * dGradDR;
                double dFlowTR = getDiffusionStrength(dGradTR) * dGradTR;  
                double dFlowDL = getDiffusionStrength(dGradDL) * dGradDL;  

                // Calculate the flow
                double dDiff = double(SrcImage(x,y)) - double(DstImage(x,y));
                FlowImage(x,y) = tFloatPixel(DT * (dFlowRight - dFlowLeft + dFlowDown - dFlowTop + dFlowDR - dFlowTL + dFlowTR - dFlowDL + dDiff));
            }
        }
        
        // Modify the image and calculate the convergence criterion
        double dNewFlow = 0.0;
#pragma omp parallel for schedule(static) default(shared)
        for( y = 0; y < YCount; ++y )
        {
            for( x = 0; x < XCount; ++x )
            {
                DstImage(x,y) = tPixel(tFloatPixel(DstImage(x,y)) + FlowImage(x,y));
#pragma omp critical
                dNewFlow += vpl::math::getAbs(FlowImage(x,y));
            }
        }

		// No flow? Nothing to do.
		if (dNewFlow < std::numeric_limits<double>::min())
			break;

        // Estimate change of the image
        double dDelta = vpl::math::getAbs(dNewFlow / dFlow - 1.0);
        if( dDelta < MIN_CHANGE )
        {
            break;
        }
        dFlow = dNewFlow;
    }

    // O.K.
    return true;
}

