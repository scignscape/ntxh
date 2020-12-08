//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/05/03                          \n
 *
 * $Id: mdsSliceFilter.cpp 2099 2012-02-17 00:24:16Z spanel $
 *
 * Description:
 * - Several image filtering functions.
 */

#include "mdsSliceFilter.h"

// STl
#include <iostream>
#include <string>


//==============================================================================
/*
 * Global constants.
 */

//! Module description
const std::string MODULE_DESCRIPTION    = "Module provides several image filtering methods.";

//! Additional command line arguments
const std::string MODULE_ARGUMENTS      = "filter:norm:sigma:size:sigma2:kappa";

//! Additional arguments
const std::string MODULE_ARG_FILTER     = "filter";
const std::string MODULE_ARG_NORM       = "norm";
const std::string MODULE_ARG_SIGMA      = "sigma";
const std::string MODULE_ARG_SIZE       = "size";
const std::string MODULE_ARG_SIGMA2     = "sigma2";
const std::string MODULE_ARG_KAPPA      = "kappa";

//! Default argument values
const std::string DEFAULT_NORM          = "conv";
const double DEFAULT_SIGMA              = 1.0;
const int DEFAULT_SIZE                  = 3;
const double DEFAULT_SIGMA2             = 1.5;
const double DEFAULT_KAPPA              = 200.0;

//! Allowed argument values
const double MIN_SIGMA                  = 0.5;
const double MAX_SIGMA                  = 3.0;

const int MIN_SIZE                      = 3;
const int MAX_SIZE                      = 15;

const double MIN_KAPPA                  = 1.0;
const double MAX_KAPPA                  = mds::img::CPixelTraits<mds::img::tDensityPixel>::getPixelMax();


//==============================================================================
/*
 * Implementation of the class CSliceFilter.
 */
CSliceFilter::CSliceFilter(const std::string& sDescription)
    : mds::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CSliceFilter::~CSliceFilter()
{
}


bool CSliceFilter::startup()
{
    // Note
    MDS_LOG_NOTE("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        MDS_CERR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Is a 'filter' parameter given?
    if( !m_Arguments.exists(MODULE_ARG_FILTER) )
    {
        MDS_CERR('<' << m_sFilename << "> Filter was not specified: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Type of image filtering
    m_Arguments.value(MODULE_ARG_FILTER, m_ssFilterName);

    // Type of filter response normalization
    std::string ssNormName = DEFAULT_NORM;
    m_Arguments.value(MODULE_ARG_NORM, ssNormName);
    if( ssNormName == std::string("abs") )
    {
        m_NormFunc = mds::img::CMakeAbs<mds::img::tDensityPixel>::normalize;
    }
    else if( ssNormName == std::string("shift") )
    {
        m_NormFunc = mds::img::CShiftZero2Gray<mds::img::tDensityPixel>::normalize;
    }
    else if( ssNormName == std::string("pos") )
    {
        m_NormFunc = mds::img::CDiscardNegative<mds::img::tDensityPixel>::normalize;
    }
    else if( ssNormName == std::string("conv") )
    {
        m_NormFunc = mds::img::CConvResponse<mds::img::tDensityPixel>::normalize;
    }
    else
    {
        MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARG_NORM << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Parameter 'sigma'
    m_dSigma = DEFAULT_SIGMA;
    m_Arguments.value(MODULE_ARG_SIGMA, m_dSigma);
    if( m_dSigma > MAX_SIGMA || m_dSigma < MIN_SIGMA )
    {
        MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARG_SIGMA << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Parameter 'sigma2'
    m_dSigma2 = DEFAULT_SIGMA2;
    m_Arguments.value(MODULE_ARG_SIGMA2, m_dSigma2);
    if( m_dSigma2 > MAX_SIGMA || m_dSigma2 < MIN_SIGMA )
    {
        MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARG_SIGMA2 << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Parameter 'size'
    m_iSize = DEFAULT_SIZE;
    m_Arguments.value(MODULE_ARG_SIZE, m_iSize);
    if( m_iSize > MAX_SIZE || m_iSize < MIN_SIZE || (m_iSize % 2) == 0 )
    {
        MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARG_SIZE << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Parameter 'kappa'
    m_dKappa = DEFAULT_KAPPA;
    m_Arguments.value(MODULE_ARG_KAPPA, m_dKappa);
    if( m_dKappa > MAX_KAPPA || m_dKappa < MIN_KAPPA )
    {
        MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARG_KAPPA << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // O.K.
    return true;
}


bool CSliceFilter::main()
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

            // Filter the slice
            if( m_ssFilterName == std::string("median") )
            {
                // Median filter
                mds::img::CMedianFilter<mds::img::CSlice> Filter(m_iSize);
                Filter(*spSlice, *spFiltered);
            }
            else if( m_ssFilterName == std::string("min") )
            {
                // Min filter
                mds::img::CMinFilter<mds::img::CSlice> Filter(m_iSize);
                Filter(*spSlice, *spFiltered);
            }
            else if( m_ssFilterName == std::string("max") )
            {
                // Max filter
                mds::img::CMaxFilter<mds::img::CSlice> Filter(m_iSize);
                Filter(*spSlice, *spFiltered);
            }
            else if( m_ssFilterName == std::string("gauss") )
            {
                // Gaussian filter
                mds::img::CGaussFilter<mds::img::CSlice> Filter(m_dSigma);
                Filter(*spSlice, *spFiltered);
            }
            else if( m_ssFilterName == std::string("log") )
            {
                // Laplacian of Gaussian filter
                mds::img::CLoGFilter<mds::img::CSlice, mds::img::CUserFunc> Filter(m_dSigma);
                Filter.setNormFunc(m_NormFunc);
                Filter(*spSlice, *spFiltered);
            }
            else if( m_ssFilterName == std::string("dog") )
            {
                // Difference of Gaussians
                mds::img::CDoGFilter<mds::img::CSlice, mds::img::CUserFunc> Filter(m_dSigma, m_dSigma2);
                Filter.setNormFunc(m_NormFunc);
                Filter(*spSlice, *spFiltered);
            }
            else if( m_ssFilterName == std::string("laplace0") )
            {
                // Laplacian
                mds::img::CLaplaceFilter0<mds::img::CSlice, mds::img::CUserFunc> Filter;
                Filter.setNormFunc(m_NormFunc);
                Filter(*spSlice, *spFiltered);
            }
            else if( m_ssFilterName == std::string("laplace1") )
            {
                // Laplacian
                mds::img::CLaplaceFilter1<mds::img::CSlice, mds::img::CUserFunc> Filter;
                Filter.setNormFunc(m_NormFunc);
                Filter(*spSlice, *spFiltered);
            }
            else if( m_ssFilterName == std::string("laplace2") )
            {
                // Laplacian
                mds::img::CLaplaceFilter2<mds::img::CSlice, mds::img::CUserFunc> Filter;
                Filter.setNormFunc(m_NormFunc);
                Filter(*spSlice, *spFiltered);
            }
            else if( m_ssFilterName == std::string("laplace5") )
            {
                // Laplacian
                mds::img::CLaplaceFilter5<mds::img::CSlice, mds::img::CUserFunc> Filter;
                Filter.setNormFunc(m_NormFunc);
                Filter(*spSlice, *spFiltered);
            }
            else if( m_ssFilterName == std::string("prewitx") )
            {
                // Prewit
                mds::img::CPrewitX<mds::img::CSlice, mds::img::CUserFunc> Filter;
                Filter.setNormFunc(m_NormFunc);
                Filter(*spSlice, *spFiltered);
            }
            else if( m_ssFilterName == std::string("prewity") )
            {
                // Prewit
                mds::img::CPrewitY<mds::img::CSlice, mds::img::CUserFunc> Filter;
                Filter.setNormFunc(m_NormFunc);
                Filter(*spSlice, *spFiltered);
            }
            else if( m_ssFilterName == std::string("sobelx") )
            {
                // Sobel operator
                mds::img::CSobelX<mds::img::CSlice, mds::img::CUserFunc> Filter;
                Filter.setNormFunc(m_NormFunc);
                Filter(*spSlice, *spFiltered);
            }
            else if( m_ssFilterName == std::string("sobely") )
            {
                // Sobel operator
                mds::img::CSobelY<mds::img::CSlice, mds::img::CUserFunc> Filter;
                Filter.setNormFunc(m_NormFunc);
                Filter(*spSlice, *spFiltered);
            }
            else if( m_ssFilterName == std::string("robertsx") )
            {
                // Roberts
                mds::img::CRobertsX<mds::img::CSlice, mds::img::CUserFunc> Filter;
                Filter.setNormFunc(m_NormFunc);
                Filter(*spSlice, *spFiltered);
            }
            else if( m_ssFilterName == std::string("robertsy") )
            {
                // Roberts
                mds::img::CRobertsY<mds::img::CSlice, mds::img::CUserFunc> Filter;
                Filter.setNormFunc(m_NormFunc);
                Filter(*spSlice, *spFiltered);
            }
            else if( m_ssFilterName == std::string("avg3") )
            {
                // Averaging
                mds::img::CAvg3Filter<mds::img::CSlice> Filter;
                Filter(*spSlice, *spFiltered);
            }
            else if( m_ssFilterName == std::string("avg5") )
            {
                // Averaging
                mds::img::CAvg5Filter<mds::img::CSlice> Filter;
                Filter(*spSlice, *spFiltered);
            }
            else if( m_ssFilterName == std::string("avg7") )
            {
                // Averaging
                mds::img::CAvg7Filter<mds::img::CSlice> Filter;
                Filter(*spSlice, *spFiltered);
            }
            else if( m_ssFilterName == std::string("anisotropic") )
            {
                // Anisotropic filtering
                mds::img::CAnisotropicFilter<mds::img::CSlice> Filter(m_dKappa);
                Filter(*spSlice, *spFiltered);
            }
            else
            {
                MDS_CERR('<' << m_sFilename << "> Bad '" << MODULE_ARG_FILTER << "' parameter value: type -h for help" << std::endl);
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


void CSliceFilter::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");
}


void CSliceFilter::writeExtendedUsage(std::ostream& MDS_UNUSED(Stream))
{
    MDS_CERR("Extended usage: [-filter Type]" << std::endl);
    MDS_CERR("Options:" << std::endl);
    MDS_CERR("  -filter  Specifies a filter that will be used for convolution image" << std::endl);
    MDS_CERR("           filtering. Allowed filter types are:" << std::endl);
    MDS_CERR("             median" << std::endl);
    MDS_CERR("             min" << std::endl);
    MDS_CERR("             max" << std::endl);
    MDS_CERR("             gauss" << std::endl);
    MDS_CERR("             log (Laplacian of Gaussian)" << std::endl);
    MDS_CERR("             laplace0, laplace1, laplace2 (Laplacian filters 3x3)" << std::endl);
    MDS_CERR("             laplace5 (Laplacian 5x5)" << std::endl);
    MDS_CERR("             prewitx" << std::endl);
    MDS_CERR("             prewity" << std::endl);
    MDS_CERR("             sobelx" << std::endl);
    MDS_CERR("             sobely" << std::endl);
    MDS_CERR("             robertsx" << std::endl);
    MDS_CERR("             robertsy" << std::endl);
    MDS_CERR("             avg3, avg5, avg7 (Averaging filters)" << std::endl);
    MDS_CERR("             anisotropic" << std::endl);
    MDS_CERR("           at present. See other documentation for details." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -norm  Type of the filter response normalization. Supported" << std::endl);
    MDS_CERR("         values are:" << std::endl);
    MDS_CERR("             conv" << std::endl);
    MDS_CERR("             abs" << std::endl);
    MDS_CERR("             pos" << std::endl);
    MDS_CERR("             shift" << std::endl);
    MDS_CERR("           for now. See other documentation for details." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -sigma  Standard deviation (\"sigma\" parameter) of the Gaussian" << std::endl);
    MDS_CERR("          and LoG filters. Allowed values are within the range" << std::endl);
    MDS_CERR("          " << MIN_SIGMA << ".." << MAX_SIGMA << " and default value" << std::endl);
    MDS_CERR("          is " << DEFAULT_SIGMA << "." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -size  Size of the Median, Min and Max filter. Only an odd number within the" << std::endl);
    MDS_CERR("         range " << MIN_SIZE << ".." << MAX_SIZE << " can be given. Default" << std::endl);
    MDS_CERR("         value of the parameter is " << DEFAULT_SIZE << "." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -sigma2  Standard deviation of the second Gaussian used by the DoG" << std::endl);
    MDS_CERR("           (Difference of Gaussians) filter. Allowed values are within" << std::endl);
    MDS_CERR("           same range as the 'sigma' parameter. Default value is " << DEFAULT_SIGMA2 << "." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -kappa  Parameter of the anisotropic filter. The value may be chosen" << std::endl);
    MDS_CERR("          according to noise level and edge strength in the image." << std::endl);
    MDS_CERR("          Default value is " << DEFAULT_KAPPA << "." << std::endl);
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
    CSliceFilterPtr spModule(new CSliceFilter(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

