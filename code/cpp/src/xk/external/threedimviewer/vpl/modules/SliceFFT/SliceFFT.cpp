//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/08/09                          \n
 *
 * File description:
 * - Computes two-dimensional DFT of an input slice.
 */

#include "mdsSliceFFT.h"

// MDSTk
#include <MDSTk/Image/mdsSlice.h>
#include <MDSTk/Image/mdsImageFFT.h>
#include <MDSTk/Image/mdsImageFunctions.h>

// STL
#include <climits>
#include <iostream>
#include <string>


//==============================================================================
/*
 * Global constants.
 */

//! Module description.
const std::string MODULE_DESCRIPTION    = "Module computes two-dimensional DFT of input slice";

//! Additional command line arguments.
const std::string MODULE_ARGUMENTS      = "shift:result:logspectrum";

//! Additional arguments.
const std::string MODULE_ARG_SHIFT      = "shift";
const std::string MODULE_ARG_RESULT     = "result";
const std::string MODULE_ARG_LOG        = "logspectrum";

//! Allowed argument values.
const std::string RESULT_REAL_NAME      = "real";
const std::string RESULT_IMAG_NAME      = "imag";
const std::string RESULT_ABS_NAME       = "abs";
const std::string RESULT_ARG_NAME       = "arg";

//! Default argument values.
const std::string DEFAULT_RESULT        = RESULT_ABS_NAME;


//==============================================================================
/*
 * Implementation of the class CSliceFFT.
 */
CSliceFFT::CSliceFFT(const std::string& sDescription)
    : mds::mod::CModule(sDescription)
    , m_bShift(false)
    , m_bLog(false)
    , m_eResult(R_ABS)
{
    allowArguments(MODULE_ARGUMENTS);
}


CSliceFFT::~CSliceFFT()
{
}


bool CSliceFFT::startup()
{
    // Note
    MDS_LOG_NOTE("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        MDS_CERR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Command line parameters
    std::string ssResultName = DEFAULT_RESULT;
    m_Arguments.value(MODULE_ARG_RESULT, ssResultName);
    if( ssResultName == RESULT_REAL_NAME )
    {
        m_eResult = R_REAL;
    }
    else if( ssResultName == RESULT_IMAG_NAME )
    {
        m_eResult = R_IMAG;
    }
    else if( ssResultName == RESULT_ABS_NAME )
    {
        m_eResult = R_ABS;
    }
    else if( ssResultName == RESULT_ARG_NAME )
    {
        m_eResult = R_ARG;
    }
    else
    {
        MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARG_RESULT << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_bShift = m_Arguments.exists(MODULE_ARG_SHIFT);
    m_bLog = m_Arguments.exists(MODULE_ARG_LOG);

    // O.K.
    return true;
}


bool CSliceFFT::main()
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
            // Fill image margin
            spSlice->mirrorMargin();

            // Compute DFT of the input slice
            mds::img::CComplexImage Complex;
            if( !mds::img::fft(*spSlice, Complex) )
            {
                MDS_CERR('<' << m_sFilename << "> Failed to compute two-dimensional DFT" << std::endl);
                return false;
            }

            // Inverse DFT
            // - Only for testing purposes!
            // - Code for image normalization have to be commented!
/*            mds::img::CComplexImage Complex2(Complex);
            mds::img::ifft(Complex2, Complex);*/

            // Convert output complex image back to the float image
            mds::img::CFImage Float;
            switch( m_eResult )
            {
                case R_REAL:
                    mds::img::real(Complex, Float);
                    break;

                case R_IMAG:
                    mds::img::imag(Complex, Float);
                    break;

                case R_ARG:
                    mds::img::arg(Complex, Float);
                    break;

                default:
                    mds::img::abs(Complex, Float);
                    break;
            }

            // Normalize the float image
            if( m_bLog )
            {
                // Logarithmic operator
                mds::img::log(Float);
            }
            else
            {
                // Normalization
                Float *= mds::CScalarf(1.0f / (Float.getXSize() * Float.getYSize()));
            }

            // Shift the image
            if( m_bShift )
            {
                mds::img::fftShift(Float);
            }

            // Convert float image to the slice
            spSlice->convert(Float);

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


void CSliceFFT::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");
}


void CSliceFFT::writeExtendedUsage(std::ostream& MDS_UNUSED(Stream))
{
    MDS_CERR("Extended usage: [-result ssValue] [-shift] [-logspectrum]" << std::endl);
    MDS_CERR("Options:" << std::endl);
    MDS_CERR("  -result  Specifies conversion of the complex image produced by two-dimensional" << std::endl);
    MDS_CERR("           DFT to the output slice (grayscale image). Allowed types are:" << std::endl);
    MDS_CERR("             " << RESULT_REAL_NAME << std::endl);
    MDS_CERR("             " << RESULT_IMAG_NAME << std::endl);
    MDS_CERR("             " << RESULT_ABS_NAME << std::endl);
    MDS_CERR("             " << RESULT_ARG_NAME << std::endl);
    MDS_CERR("           Default value is " << DEFAULT_RESULT << '.' << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -shift  Shift zero-frequency component to the center of spectrum." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -logspectrum  Enables usage of the logarithmic operator for spectrum normalization." << std::endl);
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
    CSliceFFTPtr spModule(new CSliceFFT(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

