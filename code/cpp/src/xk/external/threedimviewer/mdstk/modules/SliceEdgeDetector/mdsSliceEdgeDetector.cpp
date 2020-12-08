//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/09/27                          \n
 *
 * $Id: mdsSliceEdgeDetector.cpp 2098 2012-02-16 23:50:36Z spanel $
 *
 * Description:
 * - Advanced image edge detection algorithms.
 */

#include "mdsSliceEdgeDetector.h"

// MDSTk
#include <MDSTk/Image/mdsSlice.h>
#include <MDSTk/Image/mdsImageEdgeDetection.h>

// STl
#include <iostream>
#include <string>


//==============================================================================
/*
 * Global constants.
 */

//! Module description
const std::string MODULE_DESCRIPTION    = "Module provides advanced image edge detection algorithms";

//! Additional command line arguments
const std::string MODULE_ARGUMENTS      = "detector:sigma:t1:t2:t";

//! Additional arguments
const std::string MODULE_ARG_DETECTOR   = "detector";
const std::string MODULE_ARG_SIGMA      = "sigma";
const std::string MODULE_ARG_T1         = "t1";
const std::string MODULE_ARG_T2         = "t2";
const std::string MODULE_ARG_T          = "t";

//! Default argument values
const double DEFAULT_SIGMA              = 1.0;
const double DEFAULT_T1                 = 0.2;
const double DEFAULT_T2                 = 0.1;
const double DEFAULT_T                  = 0.05;

//! Allowed argument values
const double MIN_SIGMA                  = 0.5;
const double MAX_SIGMA                  = 3.0;

const double MIN_T                      = 0.0;
const double MAX_T                      = 1.0;


//==============================================================================
/*
 * Implementation of the class CSliceFilter.
 */
CSliceEdgeDetector::CSliceEdgeDetector(const std::string& sDescription)
    : mds::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CSliceEdgeDetector::~CSliceEdgeDetector()
{
}


bool CSliceEdgeDetector::startup()
{
    // Note
    MDS_LOG_NOTE("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        MDS_CERR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Is a filter parameter given?
    if( !m_Arguments.exists(MODULE_ARG_DETECTOR) )
    {
        MDS_CERR('<' << m_sFilename << "> Detector was not specified: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Type of image filtering
    m_Arguments.value(MODULE_ARG_DETECTOR, m_ssDetectorName);

    // Parameter 'sigma'
    m_dSigma = DEFAULT_SIGMA;
    m_Arguments.value(MODULE_ARG_SIGMA, m_dSigma);
    if( m_dSigma > MAX_SIGMA || m_dSigma < MIN_SIGMA )
    {
        MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARG_SIGMA << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Parameter 't1'
    m_dT1 = DEFAULT_T1;
    m_Arguments.value(MODULE_ARG_T1, m_dT1);
    if( m_dT1 > MAX_T || m_dT1 < MIN_T )
    {
        MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARG_T1 << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Parameter 't2'
    m_dT2 = DEFAULT_T2;
    m_Arguments.value(MODULE_ARG_T2, m_dT2);
    if( m_dT2 > m_dT1 || m_dT2 < MIN_T )
    {
        MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARG_T2 << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Parameter 't'
    m_dT = DEFAULT_T;
    m_Arguments.value(MODULE_ARG_T, m_dT);
    if( m_dT > MAX_T || m_dT < MIN_T )
    {
        MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARG_T << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // O.K.
    return true;
}


bool CSliceEdgeDetector::main()
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
            // Pad image margin
            spSlice->mirrorMargin();

            // Create an output slice
            mds::img::CSlicePtr spFiltered(new mds::img::CSlice(*spSlice));

            // Edge detection
            if( m_ssDetectorName == std::string("canny") )
            {
                // Canny Edge Detector
                mds::img::CCanny<mds::img::CSlice> Detector(m_dSigma, m_dT1, m_dT2);
                Detector(*spSlice, *spFiltered);
            }
            else if( m_ssDetectorName == std::string("zerocross") )
            {
                // Zero Crossings of the Laplacian of Gaussian
                mds::img::CZeroCrossDetector<mds::img::CSlice> Detector(m_dSigma, m_dT);
                Detector(*spSlice, *spFiltered);
            }
            else
            {
                MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARG_DETECTOR << "' parameter value: type -h for help" << std::endl);
                printUsage();
                return false;
            }

            // Write it to the output channel
            if( !writeOutput(pOChannel, spFiltered.get()) )
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


void CSliceEdgeDetector::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");
}


void CSliceEdgeDetector::writeExtendedUsage(std::ostream& MDS_UNUSED(Stream))
{
    MDS_CERR("Extended usage: [-detector strType] [-sigma dValue] [-t1 dValue] [-t2 dValue]" << std::endl);
    MDS_CERR("Options:" << std::endl);
    MDS_CERR("  -detector  Specifies an edge detector that will be used for image" << std::endl);
    MDS_CERR("             filtering. Supported types are:" << std::endl);
    MDS_CERR("               canny" << std::endl);
    MDS_CERR("               zerocross (zero crossings of the LoG filter)" << std::endl);
    MDS_CERR("             at present." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -sigma  Standard deviation (\"sigma\" parameter) of the Canny" << std::endl);
    MDS_CERR("          edge detector. Allowed values are within the range" << std::endl);
    MDS_CERR("          " << MIN_SIGMA << ".." << MAX_SIGMA << " and default value" << std::endl);
    MDS_CERR("          is " << DEFAULT_SIGMA << "." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -t1 and -t2  Thresholds affecting the hysteresis provided by Canny" << std::endl);
    MDS_CERR("               edge detector. Values in the range " << MIN_T << ".." << MAX_T << std::endl);
    MDS_CERR("               can be given. Be sure of t1 value is greater than t2!" << std::endl);
    MDS_CERR("               Default values are t1 = " << DEFAULT_T1 << " and" << std::endl);
    MDS_CERR("               t2 = " << DEFAULT_T2 << "." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -t  Threshold of the magnitude of derivatives computed by zero" << std::endl);
    MDS_CERR("      crossing edge detector. Values in the range " << MIN_T << ".." << MAX_T << " can be given." << std::endl);
    MDS_CERR("      Default value is t = " << DEFAULT_T << "." << std::endl);
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
    CSliceEdgeDetectorPtr spModule(new CSliceEdgeDetector(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

