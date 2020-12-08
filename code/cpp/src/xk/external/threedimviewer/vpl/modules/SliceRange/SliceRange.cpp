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
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/12/22                       
 *
 * File description:
 * - Extends a given pixel value interval to the range 0..MAX.
 */

#include "SliceRange.h"

// MDSTk
#include <VPL/Image/Slice.h>
#include <VPL/Image/ImageFunctions.h>

// STL
#include <climits>
#include <iostream>
#include <string>


//==============================================================================
/*
 * Global constants.
 */

//! Module description
const std::string MODULE_DESCRIPTION    = "Module extends a given interval of pixel values to the range 0..MAX";

//! Additional command line arguments
const std::string MODULE_ARGUMENTS      = "min:max:MAX:auto";

//! Additional arguments
const std::string MODULE_ARGUMENT_MIN   = "min";
const std::string MODULE_ARGUMENT_MAX   = "max";
const std::string MODULE_ARGUMENT_FMAX  = "MAX";
const std::string MODULE_ARGUMENT_AUTO  = "auto";

//! Default 'min' and 'max' values
const int DEFAULT_MIN   = vpl::img::CPixelTraits<vpl::img::tDensityPixel>::getPixelMin();
const int DEFAULT_MAX   = vpl::img::CPixelTraits<vpl::img::tDensityPixel>::getPixelMax();
const int ALLOWED_MIN   = -10000;
const int ALLOWED_MAX   = 10000;

//! Default final interval maximum
const int DEFAULT_FMIN  = vpl::img::CPixelTraits<vpl::img::tPixel8>::getPixelMin();
const int DEFAULT_FMAX  = vpl::img::CPixelTraits<vpl::img::tPixel8>::getPixelMax();


//==============================================================================
/*
 * Implementation of the class CSliceRange.
 */
CSliceRange::CSliceRange(const std::string& sDescription)
    : vpl::mod::CModule(sDescription)
    , m_bAuto(false)
{
    allowArguments(MODULE_ARGUMENTS);
}


CSliceRange::~CSliceRange()
{
}


bool CSliceRange::startup()
{
    // Note
    VPL_LOG_INFO("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Parameters 'min', 'max' and 'MAX'
    m_iMin = DEFAULT_MIN;
    m_Arguments.value(MODULE_ARGUMENT_MIN, m_iMin);
    if( m_iMin > ALLOWED_MAX || m_iMin < ALLOWED_MIN )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad 'min' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Parameter 'max'
    m_iMax = DEFAULT_MAX;
    m_Arguments.value(MODULE_ARGUMENT_MAX, m_iMax);
    if( m_iMax < m_iMin || m_iMax > ALLOWED_MAX )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad 'max' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Parameter 'MAX'
    m_iMAX = DEFAULT_FMAX;
    m_Arguments.value(MODULE_ARGUMENT_FMAX, m_iMAX);
    if( m_iMAX > ALLOWED_MAX )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad 'MAX' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_bAuto = m_Arguments.exists(MODULE_ARGUMENT_AUTO);

    // O.K.
    return true;
}


bool CSliceRange::main()
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
    vpl::img::CSlicePtr spSlice(new vpl::img::CSlice());

    // Wait for data
    if( pIChannel->wait(1000) )
    {
        // Read slice from the input channel
        if( readInput(pIChannel, spSlice.get()) )
        {
            // Interpolated interval
            vpl::img::CSlice::tPixel RMin, RMax;
            if( !m_bAuto )
            {
                RMin = (vpl::img::CSlice::tPixel)m_iMin;
                RMax = (vpl::img::CSlice::tPixel)m_iMax;
            }
            else
            {
                RMin = vpl::img::getMin<vpl::img::CSlice::tPixel>(*spSlice);
                RMax = vpl::img::getMax<vpl::img::CSlice::tPixel>(*spSlice);
            }

            // Minimal and maximal pixel values
            vpl::img::CSlice::tPixel PMin = (vpl::img::CSlice::tPixel)DEFAULT_FMIN;
            vpl::img::CSlice::tPixel PMax = (vpl::img::CSlice::tPixel)m_iMAX;

            // Interval size
            double dConst = double(PMax - PMin) / double(RMax - RMin);

            // Convert slice pixels
            for( vpl::tSize j = 0; j < spSlice->getYSize(); ++j )
            {
                for( vpl::tSize i = 0; i < spSlice->getXSize(); ++i )
                {
                    vpl::img::CSlice::tPixel Value = spSlice->at(i, j);
                    if( Value > RMax )
                    {
                        spSlice->set(i, j, PMax);
                    }
                    else if( Value < RMin )
                    {
                        spSlice->set(i, j, PMin);
                    }
                    else
                    {
                        spSlice->set(i, j, (vpl::img::CSlice::tPixel)(double(Value - RMin) * dConst) + PMin);
                    }
                }
            }

            // Write it to the output channel
            if( !writeOutput(pOChannel, spSlice.get()) )
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


void CSliceRange::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");
}


void CSliceRange::writeExtendedUsage(std::ostream& Stream)
{
    Stream << "Extended usage: [-min iValue] [-max iValue] [-MAX iValue] [-auto]" << std::endl;
    Stream << "Options:" << std::endl;
    Stream << "  -min  Lower boundary of interpolated interval." << std::endl;
    Stream << std::endl;
    Stream << "  -max  Higher interval boundary. The given interval is lineary" << std::endl;
    Stream << "        interpolated to the range 0..MAX. Default <min, max>" << std::endl;
    Stream << "        interval is <" << DEFAULT_MIN << ", " << DEFAULT_MAX << ">." << std::endl;
    Stream << std::endl;
    Stream << "  -MAX  Higher boundary of the final interval. Default value" << std::endl;
    Stream << "        is " << DEFAULT_FMAX << "." << std::endl;
    Stream << std::endl;
    Stream << "  -auto  Interval boundaries are estimated automatically." << std::endl;
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
    CSliceRangePtr spModule(new CSliceRange(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

