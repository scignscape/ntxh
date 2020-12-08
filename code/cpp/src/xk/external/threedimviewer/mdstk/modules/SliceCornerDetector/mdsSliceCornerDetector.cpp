//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)      \n
 * Copyright (c) 2003-2007 by PGMed@FIT           \n
 *
 * Author:  Petr Hyna, xhynap00@stud.fit.vutbr.cz \n
 *          (modified by Michal Spanel)           \n
 * Date:    2007/04/12                            \n
 *
 * $Id: mdsSliceCornerDetector.cpp 2098 2012-02-16 23:50:36Z spanel $
 *
 * Description:
 * - Image corner detection algorithms.
 */

#include "mdsSliceCornerDetector.h"

// MDSTk
#include <MDSTk/Image/mdsSlice.h>
#include <MDSTk/Image/mdsImageCornerDetection.h>

// STl
#include <iostream>
#include <string>


//==============================================================================
/*
 * Global constants.
 */

//! Module description
const std::string MODULE_DESCRIPTION    = "Module provides image corner detection algorithms";

//! Additional command line arguments
const std::string MODULE_ARGUMENTS      = "detector:sigma:t:k:w";

//! Additional arguments
const std::string MODULE_ARG_DETECTOR   = "detector";
const std::string MODULE_ARG_SIGMA      = "sigma";
const std::string MODULE_ARG_T          = "t";
const std::string MODULE_ARG_K          = "k";
const std::string MODULE_ARG_W          = "w";

//! Default argument values
const double DEFAULT_SIGMA              = 1.2;
const double DEFAULT_T					= 0.1;      // Harris
//const double DEFAULT_T                  = 0.4;      // Susan
const double DEFAULT_K                  = 0.04;
const double DEFAULT_W                  = 20.0;

//! Allowed argument values
const double MIN_SIGMA                  = 0.5;
const double MAX_SIGMA                  = 3.0;

const double MIN_T						= 0.0;
const double MAX_T						= 1.0;

const double MIN_K                      = 0.01;
const double MAX_K                      = 0.25;


//==============================================================================
/*
 * Implementation of the class CSliceCornerDetector.
 */
CSliceCornerDetector::CSliceCornerDetector(const std::string& sDescription)
    : mds::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CSliceCornerDetector::~CSliceCornerDetector()
{
}


bool CSliceCornerDetector::startup()
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

    m_dSigma = DEFAULT_SIGMA;
    m_Arguments.value(MODULE_ARG_SIGMA, m_dSigma);
    if( m_dSigma > MAX_SIGMA || m_dSigma < MIN_SIGMA )
    {
        MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARG_SIGMA << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_dT = DEFAULT_T;
    m_Arguments.value(MODULE_ARG_T, m_dT);
    if( m_dT > MAX_T || m_dT < MIN_T )
    {
        MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARG_T << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_dK = DEFAULT_K;
    m_Arguments.value(MODULE_ARG_K, m_dK);
    if( m_dK > MAX_K || m_dK < MIN_K )
    {
        MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARG_K << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_dW = DEFAULT_W;
    m_Arguments.value(MODULE_ARG_W, m_dW);
    if( m_dW <= 0.0 )
    {
        MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARG_W << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // O.K.
    return true;
}


bool CSliceCornerDetector::main()
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
    mds::img::CSlicePtr spSlice;

    // Wait for data
    if( pIChannel->wait(1000) )
    {
        // Read slice from the input channel
        if( readInput(pIChannel, spSlice.get()) )
        {
            // Pad image margin
            spSlice->mirrorMargin();

            // Create an output slice
            mds::img::CSlicePtr spFiltered(new mds::img::CSlice(spSlice->getXSize(),
                                                                spSlice->getYSize()
                                                                ));
            spFiltered->fillEntire(mds::img::CPixelTraits<mds::img::tDensityPixel>::getPixelMin());

            // Corner detection
            if( m_ssDetectorName == std::string("harris") )
            {
                // Harris corner detector
                mds::img::CHarris<mds::img::CDImage> Detector(m_dSigma, m_dT, m_dK);
                Detector(*spSlice, *spFiltered);
            }
            else if( m_ssDetectorName == std::string("susan") )
            {
                // Susan corner detector
                mds::img::CSusanDetector<mds::img::CDImage> Detector(m_dT, m_dW);
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


void CSliceCornerDetector::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");
}


void CSliceCornerDetector::writeExtendedUsage(std::ostream& MDS_UNUSED(Stream))
{
    MDS_CERR("Extended usage: [-detector strValue] [-sigma dValue] [-t dValue]" << std::endl);
    MDS_CERR("                [-k dValue] [-w dValue]" << std::endl);
    MDS_CERR("Options:" << std::endl);
    MDS_CERR("  -detector  Specifies corner detector that will be used for detection." << std::endl);
    MDS_CERR("             Supported types are:" << std::endl);
    MDS_CERR("               harris" << std::endl);
    MDS_CERR("               susan" << std::endl);
    MDS_CERR("             at present." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -sigma  Size of the gaussian window used by the detector." << std::endl);
    MDS_CERR("          Values in the range " << MIN_SIGMA << ".." << MAX_SIGMA << std::endl);
    MDS_CERR("          are allowed. Default value is " << DEFAULT_SIGMA <<  std::endl);
    MDS_CERR(std::endl);
	MDS_CERR("  -t  Threshold used to suppress improbable corners." << std::endl);
    MDS_CERR("      Values in the range " << MIN_T << ".." << MAX_T << std::endl);
    MDS_CERR("      can be given. Default value is " << DEFAULT_T <<  std::endl);
    MDS_CERR("      Set the threshold to approximately 0.4 in case of the Susan detector." <<  std::endl);
    MDS_CERR(std::endl);
	MDS_CERR("  -k  Tuneable parameter of the Harris corner detector." << std::endl);
    MDS_CERR("      Values in the range " << MIN_K << ".." << MAX_K << " can be given." << std::endl);
    MDS_CERR("      Default value is " << DEFAULT_K << "." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -w  Parameter specific for the Susan corner detector." << std::endl);
    MDS_CERR("      Any value greater then zero may be given." << std::endl);
    MDS_CERR("      Default value is " << DEFAULT_W << "." << std::endl);
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
    CSliceCornerDetectorPtr spModule(new CSliceCornerDetector(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

