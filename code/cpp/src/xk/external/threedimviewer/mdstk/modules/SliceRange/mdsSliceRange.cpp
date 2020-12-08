//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/12/22                          \n
 *
 * $Id: mdsSliceRange.cpp 2100 2012-02-17 07:36:55Z spanel $
 *
 * File description:
 * - Extends a given pixel value interval to the range 0..MAX.
 */

#include "mdsSliceRange.h"

// MDSTk
#include <MDSTk/Image/mdsSlice.h>
#include <MDSTk/Image/mdsImageFunctions.h>

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
const int DEFAULT_MIN   = mds::img::CPixelTraits<mds::img::tDensityPixel>::getPixelMin();
const int DEFAULT_MAX   = mds::img::CPixelTraits<mds::img::tDensityPixel>::getPixelMax();
const int ALLOWED_MIN   = -10000;
const int ALLOWED_MAX   = 10000;

//! Default final interval maximum
const int DEFAULT_FMIN  = mds::img::CPixelTraits<mds::img::tPixel8>::getPixelMin();
const int DEFAULT_FMAX  = mds::img::CPixelTraits<mds::img::tPixel8>::getPixelMax();


//==============================================================================
/*
 * Implementation of the class CSliceRange.
 */
CSliceRange::CSliceRange(const std::string& sDescription)
    : mds::mod::CModule(sDescription)
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
    MDS_LOG_NOTE("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        MDS_CERR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Parameters 'min', 'max' and 'MAX'
    m_iMin = DEFAULT_MIN;
    m_Arguments.value(MODULE_ARGUMENT_MIN, m_iMin);
    if( m_iMin > ALLOWED_MAX || m_iMin < ALLOWED_MIN )
    {
        MDS_CERR('<' << m_sFilename << "> Bad 'min' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Parameter 'max'
    m_iMax = DEFAULT_MAX;
    m_Arguments.value(MODULE_ARGUMENT_MAX, m_iMax);
    if( m_iMax < m_iMin || m_iMax > ALLOWED_MAX )
    {
        MDS_CERR('<' << m_sFilename << "> Bad 'max' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Parameter 'MAX'
    m_iMAX = DEFAULT_FMAX;
    m_Arguments.value(MODULE_ARGUMENT_FMAX, m_iMAX);
    if( m_iMAX > ALLOWED_MAX )
    {
        MDS_CERR('<' << m_sFilename << "> Bad 'MAX' parameter value: type -h for help" << std::endl);
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
    mds::img::CSlicePtr spSlice(new mds::img::CSlice());

    // Wait for data
    if( pIChannel->wait(1000) )
    {
        // Read slice from the input channel
        if( readInput(pIChannel, spSlice.get()) )
        {
            // Interpolated interval
            mds::img::CSlice::tPixel RMin, RMax;
            if( !m_bAuto )
            {
                RMin = (mds::img::CSlice::tPixel)m_iMin;
                RMax = (mds::img::CSlice::tPixel)m_iMax;
            }
            else
            {
                RMin = mds::img::getMin<mds::img::CSlice::tPixel>(*spSlice);
                RMax = mds::img::getMax<mds::img::CSlice::tPixel>(*spSlice);
            }

            // Minimal and maximal pixel values
            mds::img::CSlice::tPixel PMin = (mds::img::CSlice::tPixel)DEFAULT_FMIN;
            mds::img::CSlice::tPixel PMax = (mds::img::CSlice::tPixel)m_iMAX;

            // Interval size
            double dConst = double(PMax - PMin) / double(RMax - RMin);

            // Convert slice pixels
            for( mds::tSize j = 0; j < spSlice->getYSize(); ++j )
            {
                for( mds::tSize i = 0; i < spSlice->getXSize(); ++i )
                {
                    mds::img::CSlice::tPixel Value = spSlice->at(i, j);
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
                        spSlice->set(i, j, (mds::img::CSlice::tPixel)(double(Value - RMin) * dConst) + PMin);
                    }
                }
            }

            // Write it to the output channel
            if( !writeOutput(pOChannel, spSlice.get()) )
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


void CSliceRange::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");
}


void CSliceRange::writeExtendedUsage(std::ostream& MDS_UNUSED(Stream))
{
    MDS_CERR("Extended usage: [-min iValue] [-max iValue] [-MAX iValue] [-auto]" << std::endl);
    MDS_CERR("Options:" << std::endl);
    MDS_CERR("  -min  Lower boundary of interpolated interval." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -max  Higher interval boundary. The given interval is lineary" << std::endl);
    MDS_CERR("        interpolated to the range 0..MAX. Default <min, max>" << std::endl);
    MDS_CERR("        interval is <" << DEFAULT_MIN << ", " << DEFAULT_MAX << ">." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -MAX  Higher boundary of the final interval. Default value" << std::endl);
    MDS_CERR("        is " << DEFAULT_FMAX << "." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -auto  Interval boundaries are estimated automatically." << std::endl);
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
    CSliceRangePtr spModule(new CSliceRange(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

