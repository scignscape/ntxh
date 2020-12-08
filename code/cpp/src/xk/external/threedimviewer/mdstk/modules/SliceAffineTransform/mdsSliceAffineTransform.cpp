//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2009 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2008/12/19                          \n
 *
 * $Id: mdsSliceAffineTransform.cpp 2098 2012-02-16 23:50:36Z spanel $
 *
 * File description:
 * - Affine image transformation.
 */

#include "mdsSliceAffineTransform.h"

// MDSTk
#include <MDSTk/Image/mdsSlice.h>
#include <MDSTk/Image/mdsImageFunctions.h>
#include <MDSTk/Image/GeometricTransform/mdsAffineTransform.h>
#include <MDSTk/Math/mdsMatrixFunctions.h>

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
const int PIXEL_MIN = mds::img::CPixelTraits<mds::img::tDensityPixel>::getPixelMin();
const int PIXEL_MAX = mds::img::CPixelTraits<mds::img::tDensityPixel>::getPixelMax();


//==============================================================================
/*
 * Implementation of the class CSliceAffineTransform.
 */
CSliceAffineTransform::CSliceAffineTransform(const std::string& sDescription)
    : mds::mod::CModule(sDescription)
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
    MDS_LOG_NOTE("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        MDS_CERR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Parameters
    m_iMarginValue = PIXEL_MIN;
    m_Arguments.value(MODULE_ARG_FILL, m_iMarginValue);
    if( m_iMarginValue > PIXEL_MAX || m_iMarginValue < PIXEL_MIN )
    {
        MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARG_FILL << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_dSX = 1.0;
    m_Arguments.value(MODULE_ARG_SX, m_dSX);
    if( m_dSX < -100 || m_dSX > 100 )
    {
        MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARG_SX << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_dSY = 1.0;
    m_Arguments.value(MODULE_ARG_SY, m_dSY);
    if( m_dSY < -100 || m_dSY > 100 )
    {
        MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARG_SY << "' parameter value: type -h for help" << std::endl);
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
        MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARG_ALPHA << "' parameter value: type -h for help" << std::endl);
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
    MDS_LOG_NOTE("Module main function");

    // I/O channels
    mds::mod::CChannel *pIChannel = getInput(0);
    mds::mod::CChannel *pOChannel = getOutput(0);

    // Is any input?
    if( !pIChannel->isConnected() )
    {
        return false;
    }

    // Create a new slice
    mds::img::CSlice Slice;

    // Wait for data
    if( pIChannel->wait(1000) )
    {
        // Read slice from the input channel
        if( readInput(pIChannel, &Slice) )
        {
            // Fill source image margin
            Slice.fillMargin(m_iMarginValue);

            // Create an output slice
            mds::img::CSlice DstSlice(Slice.getXSize(), Slice.getYSize());

            // Prepare transformation matrix
            mds::img::CAffineMatrix Matrix;
            Matrix.makeIdentity();
            double cx = 0.5 * Slice.getXSize();
            double cy = 0.5 * Slice.getYSize();
            Matrix.addTranslate(-cx, -cy);
            Matrix.addScale(m_dSX, m_dSY);
            Matrix.addRotate(mds::math::deg2Rad(m_iAlpha));
            Matrix.addTranslate(cx + m_dTX, cy + m_dTY);

            // Affine transformation
            if( m_ssInterpolatorName == std::string("nearest") )
            {
                mds::img::CAffineTransform<mds::img::CDImage, mds::img::CNearest> Transform;
                if( m_bResize )
                {
                    Transform.resize();
                }
                Transform.fillMargin(mds::img::tDensityPixel(m_iMarginValue));
                Transform.setMatrix(Matrix);
                Transform(Slice, DstSlice);
            }
            else if( m_ssInterpolatorName == std::string("bilinear") )
            {
                mds::img::CAffineTransform<mds::img::CDImage, mds::img::CBilinear> Transform;
                if( m_bResize )
                {
                    Transform.resize();
                }
                Transform.fillMargin(mds::img::tDensityPixel(m_iMarginValue));
                Transform.setMatrix(Matrix);
                Transform(Slice, DstSlice);
            }
            else if( m_ssInterpolatorName == std::string("bicubic") )
            {
                mds::img::CAffineTransform<mds::img::CDImage, mds::img::CBicubic> Transform;
                if( m_bResize )
                {
                    Transform.resize();
                }
                Transform.fillMargin(mds::img::tDensityPixel(m_iMarginValue));
                Transform.setMatrix(Matrix);
                Transform(Slice, DstSlice);
            }
            else if( m_ssInterpolatorName == std::string("sinc") )
            {
                mds::img::CAffineTransform<mds::img::CDImage, mds::img::CSinc> Transform;
                if( m_bResize )
                {
                    Transform.resize();
                }
                Transform.fillMargin(mds::img::tDensityPixel(m_iMarginValue));
                Transform.setMatrix(Matrix);
                Transform(Slice, DstSlice);
            }
            else
            {
                MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARG_INTERPOL << "' parameter value: type -h for help" << std::endl);
                printUsage();
                return false;
            }

            // Write it to the output channel
            if( !writeOutput(pOChannel, &DstSlice) )
            {
                MDS_CERR('<' << m_sFilename << "> Failed to write the output slice" << std::endl);
                return false;
            }
        }
        else
        {
            MDS_CERR('<' << m_sFilename << "> Failed to read input slice" << std::endl);
            return false;
        }
    }
    else
    {
        MDS_LOG_NOTE("Wait timeout");
    }

    // Returning 'true' means to continue processing the input channel
    return true;
}


void CSliceAffineTransform::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");
}


void CSliceAffineTransform::writeExtendedUsage(std::ostream& MDS_UNUSED(Stream))
{
    MDS_CERR("Extended usage: [-alpha iValue] [-sx dValue] [-sy dValue] [-tx dValue]" << std::endl);
    MDS_CERR("                [-ty dValue] [-iterpolator ssName] [-fill iValue] [-resize]" << std::endl);
    MDS_CERR("                [-resize]" << std::endl);
    MDS_CERR("Options:" << std::endl);
    MDS_CERR("  -interpolator  Specifies interpolation method." << std::endl);
    MDS_CERR("                 Supported methods are:" << std::endl);
    MDS_CERR("                   nearest" << std::endl);
    MDS_CERR("                   bilinear" << std::endl);
    MDS_CERR("                   bicubic" << std::endl);
    MDS_CERR("                   sinc" << std::endl);
    MDS_CERR("                 The parameter must be always given." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -alpha  Rotation angle in degrees." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -tx, -ty  Translation vector." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -sx, -sy  Scaling factors." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -fill  Pixel value used to fill image margin." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -resize  Estimates optimal size of the output image." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("Input: MDSTk slice" << std::endl);
    MDS_CERR("Output: MDSTk slice" << std::endl);
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

