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
 * Copyright (c) 2003-2009 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2008/12/19                       
 *
 * File description:
 * - Affine image transformation.
 */

#include "SliceAffineTransform.h"

// MDSTk
#include <VPL/Image/Slice.h>
#include <VPL/Image/ImageFunctions.h>
#include <VPL/Image/GeometricTransform/AffineTransform.h>
#include <VPL/Math/MatrixFunctions.h>

// STL
#include <climits>
#include <iostream>
#include <string>


//==============================================================================
/*
 * Global constants.
 */

//! Module description
const std::string MODULE_DESCRIPTION    = "Module provides geometric transformations of an input image";

//! Additional command line arguments
const std::string MODULE_ARGUMENTS      = "alpha:sx:sy:tx:ty:resize:fill:interpolator";

//! Additional arguments
const std::string MODULE_ARG_ALPHA      = "alpha";
const std::string MODULE_ARG_SX         = "sx";
const std::string MODULE_ARG_SY         = "sy";
const std::string MODULE_ARG_TX         = "tx";
const std::string MODULE_ARG_TY         = "ty";
const std::string MODULE_ARG_RESIZE     = "resize";
const std::string MODULE_ARG_FILL       = "fill";
const std::string MODULE_ARG_INTERPOL   = "interpolator";

//! Default values
const int PIXEL_MIN = vpl::img::CPixelTraits<vpl::img::tDensityPixel>::getPixelMin();
const int PIXEL_MAX = vpl::img::CPixelTraits<vpl::img::tDensityPixel>::getPixelMax();


//==============================================================================
/*
 * Implementation of the class CSliceAffineTransform.
 */
CSliceAffineTransform::CSliceAffineTransform(const std::string& sDescription)
    : vpl::mod::CModule(sDescription)
    , m_bResize(false)
{
    allowArguments(MODULE_ARGUMENTS);
}


CSliceAffineTransform::~CSliceAffineTransform()
{
}


bool CSliceAffineTransform::startup()
{
    // Note
    VPL_LOG_INFO("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Parameters
    m_iMarginValue = PIXEL_MIN;
    m_Arguments.value(MODULE_ARG_FILL, m_iMarginValue);
    if( m_iMarginValue > PIXEL_MAX || m_iMarginValue < PIXEL_MIN )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad '" << MODULE_ARG_FILL << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_dSX = 1.0;
    m_Arguments.value(MODULE_ARG_SX, m_dSX);
    if( m_dSX < -100 || m_dSX > 100 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad '" << MODULE_ARG_SX << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_dSY = 1.0;
    m_Arguments.value(MODULE_ARG_SY, m_dSY);
    if( m_dSY < -100 || m_dSY > 100 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad '" << MODULE_ARG_SY << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_dTX = 0.0;
    m_Arguments.value(MODULE_ARG_TX, m_dTX);

    m_dTY = 0.0;
    m_Arguments.value(MODULE_ARG_TY, m_dTY);

    m_iAlpha = 0;
    m_Arguments.value(MODULE_ARG_ALPHA, m_iAlpha);
    if( m_iAlpha < -360 || m_iAlpha > 360 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad '" << MODULE_ARG_ALPHA << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_bResize = m_Arguments.exists(MODULE_ARG_RESIZE);

    m_Arguments.value(MODULE_ARG_INTERPOL, m_ssInterpolatorName);

    // O.K.
    return true;
}


bool CSliceAffineTransform::main()
{
    // Note
    VPL_LOG_INFO("Module main function");

    // I/O channels
    vpl::mod::CChannel *pIChannel = getInput(0);
    vpl::mod::CChannel *pOChannel = getOutput(0);

    // Is any input?
    if( !pIChannel->isConnected() )
    {
        return false;
    }

    // Create a new slice
    vpl::img::CSlice Slice;

    // Wait for data
    if( pIChannel->wait(1000) )
    {
        // Read slice from the input channel
        if( readInput(pIChannel, &Slice) )
        {
            // Fill source image margin
            Slice.fillMargin(m_iMarginValue);

            // Create an output slice
            vpl::img::CSlice DstSlice(Slice.getXSize(), Slice.getYSize());

            // Prepare transformation matrix
            vpl::img::CAffineMatrix Matrix;
            Matrix.makeIdentity();
            double cx = 0.5 * Slice.getXSize();
            double cy = 0.5 * Slice.getYSize();
            Matrix.addTranslate(-cx, -cy);
            Matrix.addScale(m_dSX, m_dSY);
            Matrix.addRotate(vpl::math::deg2Rad(m_iAlpha));
            Matrix.addTranslate(cx + m_dTX, cy + m_dTY);

            // Affine transformation
            if( m_ssInterpolatorName == std::string("nearest") )
            {
                vpl::img::CAffineTransform<vpl::img::CDImage, vpl::img::CNearest> Transform;
                if( m_bResize )
                {
                    Transform.resize();
                }
                Transform.fillMargin(vpl::img::tDensityPixel(m_iMarginValue));
                Transform.setMatrix(Matrix);
                Transform(Slice, DstSlice);
            }
            else if( m_ssInterpolatorName == std::string("bilinear") )
            {
                vpl::img::CAffineTransform<vpl::img::CDImage, vpl::img::CBilinear> Transform;
                if( m_bResize )
                {
                    Transform.resize();
                }
                Transform.fillMargin(vpl::img::tDensityPixel(m_iMarginValue));
                Transform.setMatrix(Matrix);
                Transform(Slice, DstSlice);
            }
            else if( m_ssInterpolatorName == std::string("bicubic") )
            {
                vpl::img::CAffineTransform<vpl::img::CDImage, vpl::img::CBicubic> Transform;
                if( m_bResize )
                {
                    Transform.resize();
                }
                Transform.fillMargin(vpl::img::tDensityPixel(m_iMarginValue));
                Transform.setMatrix(Matrix);
                Transform(Slice, DstSlice);
            }
            else if( m_ssInterpolatorName == std::string("sinc") )
            {
                vpl::img::CAffineTransform<vpl::img::CDImage, vpl::img::CSinc> Transform;
                if( m_bResize )
                {
                    Transform.resize();
                }
                Transform.fillMargin(vpl::img::tDensityPixel(m_iMarginValue));
                Transform.setMatrix(Matrix);
                Transform(Slice, DstSlice);
            }
            else
            {
                VPL_LOG_ERROR('<' << m_sFilename << "> Bad '" << MODULE_ARG_INTERPOL << "' parameter value: type -h for help" << std::endl);
                printUsage();
                return false;
            }

            // Write it to the output channel
            if( !writeOutput(pOChannel, &DstSlice) )
            {
                VPL_LOG_ERROR('<' << m_sFilename << "> Failed to write the output slice" << std::endl);
                return false;
            }
        }
        else
        {
            VPL_LOG_ERROR('<' << m_sFilename << "> Failed to read input slice" << std::endl);
            return false;
        }
    }
    else
    {
        VPL_LOG_INFO("Wait timeout");
    }

    // Returning 'true' means to continue processing the input channel
    return true;
}


void CSliceAffineTransform::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");
}


void CSliceAffineTransform::writeExtendedUsage(std::ostream& Stream)
{
    Stream << "Extended usage: [-alpha iValue] [-sx dValue] [-sy dValue] [-tx dValue]" << std::endl;
    Stream << "                [-ty dValue] [-iterpolator ssName] [-fill iValue] [-resize]" << std::endl;
    Stream << "                [-resize]" << std::endl;
    Stream << "Options:" << std::endl;
    Stream << "  -interpolator  Specifies interpolation method." << std::endl;
    Stream << "                 Supported methods are:" << std::endl;
    Stream << "                   nearest" << std::endl;
    Stream << "                   bilinear" << std::endl;
    Stream << "                   bicubic" << std::endl;
    Stream << "                   sinc" << std::endl;
    Stream << "                 The parameter must be always given." << std::endl;
    Stream << std::endl;
    Stream << "  -alpha  Rotation angle in degrees." << std::endl;
    Stream << std::endl;
    Stream << "  -tx, -ty  Translation vector." << std::endl;
    Stream << std::endl;
    Stream << "  -sx, -sy  Scaling factors." << std::endl;
    Stream << std::endl;
    Stream << "  -fill  Pixel value used to fill image margin." << std::endl;
    Stream << std::endl;
    Stream << "  -resize  Estimates optimal size of the output image." << std::endl;
    Stream << std::endl;
    Stream << "Input: MDSTk slice" << std::endl;
    Stream << "Output: MDSTk slice" << std::endl;
}


//==============================================================================
/*
 * Function main() which creates and executes console application.
 */
int main(int argc, char *argv[])
{
    // Creation of a module using smart pointer
    CSliceAffineTransformPtr spModule(new CSliceAffineTransform(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

