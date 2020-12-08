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
 * Date:    2004/05/03                       
 *
 * Description:
 * - Several image filtering functions.
 */

#include "SliceFilter.h"

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
const std::string MODULE_ARGUMENTS      = "filter:norm:sigma:size:sigma2:sigmad:kappa";

//! Additional arguments
const std::string MODULE_ARG_FILTER     = "filter";
const std::string MODULE_ARG_NORM       = "norm";
const std::string MODULE_ARG_SIGMA      = "sigma";
const std::string MODULE_ARG_SIZE       = "size";
const std::string MODULE_ARG_SIGMA2     = "sigma2";
const std::string MODULE_ARG_SIGMA_DENSITY = "sigmad";
const std::string MODULE_ARG_KAPPA      = "kappa";

//! Default argument values
const std::string DEFAULT_NORM          = "conv";
const double DEFAULT_SIGMA              = 1.0;
const int DEFAULT_SIZE                  = 3;
const double DEFAULT_SIGMA2             = 1.5;
const double DEFAULT_SIGMA_DENSITY      = 1.0;
const double DEFAULT_KAPPA              = 200.0;

//! Allowed argument values
const double MIN_SIGMA                  = 0.5;
const double MAX_SIGMA                  = 3.0;

const double MIN_SIGMA_DENSITY          = 1.0;
const double MAX_SIGMA_DENSITY          = vpl::img::CPixelTraits<vpl::img::tDensityPixel>::getMax() - vpl::img::CPixelTraits<vpl::img::tDensityPixel>::getMin();

const int MIN_SIZE                      = 3;
const int MAX_SIZE                      = 15;

const double MIN_KAPPA                  = 1.0;
const double MAX_KAPPA                  = vpl::img::CPixelTraits<vpl::img::tDensityPixel>::getPixelMax();


//==============================================================================
/*
 * Implementation of the class CSliceFilter.
 */
CSliceFilter::CSliceFilter(const std::string& sDescription)
    : vpl::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CSliceFilter::~CSliceFilter()
{
}


bool CSliceFilter::startup()
{
    // Note
    VPL_LOG_INFO("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Is a 'filter' parameter given?
    if( !m_Arguments.exists(MODULE_ARG_FILTER) )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Filter was not specified: type -h for help" << std::endl);
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
        m_NormFunc = vpl::img::CMakeAbs<vpl::img::tDensityPixel>::normalize;
    }
    else if( ssNormName == std::string("shift") )
    {
        m_NormFunc = vpl::img::CShiftZero2Gray<vpl::img::tDensityPixel>::normalize;
    }
    else if( ssNormName == std::string("pos") )
    {
        m_NormFunc = vpl::img::CDiscardNegative<vpl::img::tDensityPixel>::normalize;
    }
    else if( ssNormName == std::string("conv") )
    {
        m_NormFunc = vpl::img::CConvResponse<vpl::img::tDensityPixel>::normalize;
    }
    else
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad '" << MODULE_ARG_NORM << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Parameter 'sigma'
    m_dSigma = DEFAULT_SIGMA;
    m_Arguments.value(MODULE_ARG_SIGMA, m_dSigma);
    if( m_dSigma > MAX_SIGMA || m_dSigma < MIN_SIGMA )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad '" << MODULE_ARG_SIGMA << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Parameter 'sigma2'
    m_dSigma2 = DEFAULT_SIGMA2;
    m_Arguments.value(MODULE_ARG_SIGMA2, m_dSigma2);
    if( m_dSigma2 > MAX_SIGMA || m_dSigma2 < MIN_SIGMA )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad '" << MODULE_ARG_SIGMA2 << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Parameter 'sigmad'
    m_dSigmaDensity = DEFAULT_SIGMA_DENSITY;
    m_Arguments.value(MODULE_ARG_SIGMA_DENSITY, m_dSigmaDensity);
    if( m_dSigmaDensity > MAX_SIGMA_DENSITY || m_dSigmaDensity < MIN_SIGMA_DENSITY )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad '" << MODULE_ARG_SIGMA_DENSITY << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Parameter 'size'
    m_iSize = DEFAULT_SIZE;
    m_Arguments.value(MODULE_ARG_SIZE, m_iSize);
    if( m_iSize > MAX_SIZE || m_iSize < MIN_SIZE || (m_iSize % 2) == 0 )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad '" << MODULE_ARG_SIZE << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // Parameter 'kappa'
    m_dKappa = DEFAULT_KAPPA;
    m_Arguments.value(MODULE_ARG_KAPPA, m_dKappa);
    if( m_dKappa > MAX_KAPPA || m_dKappa < MIN_KAPPA )
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Bad '" << MODULE_ARG_KAPPA << "' parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // O.K.
    return true;
}


bool CSliceFilter::main()
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
            // Pad image margin
            spSlice->mirrorMargin();

            // Create an output slice
            vpl::img::CSlicePtr spFiltered(new vpl::img::CSlice(*spSlice));

            // Filter the slice
            if( m_ssFilterName == std::string("median") )
            {
                // Median filter
                vpl::img::CMedianFilter<vpl::img::CSlice> Filter(m_iSize);
                Filter(*spSlice, *spFiltered);
            }
            else if( m_ssFilterName == std::string("min") )
            {
                // Min filter
                vpl::img::CMinFilter<vpl::img::CSlice> Filter(m_iSize);
                Filter(*spSlice, *spFiltered);
            }
            else if( m_ssFilterName == std::string("max") )
            {
                // Max filter
                vpl::img::CMaxFilter<vpl::img::CSlice> Filter(m_iSize);
                Filter(*spSlice, *spFiltered);
            }
            else if( m_ssFilterName == std::string("gauss") )
            {
                // Gaussian filter
                vpl::img::CGaussFilter<vpl::img::CSlice> Filter(m_dSigma);

                // Get filter size and compute needed margin
                vpl::tSize margin(Filter.getSize() >> 1);
                
                // If current source margin is too small, create new slice
                if(spSlice->getMargin() < margin)
                {
                    vpl::tSize sx(spSlice->getXSize()), sy(spSlice->getYSize());

                    // Create data
                    vpl::img::CSlicePtr s(new vpl::img::CSlice(sx, sy, margin));

                    // Copy source
                    for(vpl::tSize y = 0; y < sy; ++y)
                        for(vpl::tSize x = 0; x < sx; ++x)
                            s->set(x, y, spSlice->at(x, y));

                    // Create margin
                    s->mirrorMargin();

                    // Store slice
                    spSlice = s;
                }

                Filter(*spSlice, *spFiltered);
            }
            else if( m_ssFilterName == std::string("bilateral") )
            {
                // Bilateral filter
                vpl::img::CBilateralFilter<vpl::img::CSlice> Filter(m_dSigmaDensity, m_dSigma);

                // Get filter size and compute needed margin
                vpl::tSize margin(Filter.getSize() >> 1);

                // If current source margin is too small, create new slice
                if(spSlice->getMargin() < margin)
                {
                    vpl::tSize sx(spSlice->getXSize()), sy(spSlice->getYSize());

                    // Create data
                    vpl::img::CSlicePtr s(new vpl::img::CSlice(sx, sy, margin));

                    // Copy source
                    for(vpl::tSize y = 0; y < sy; ++y)
                        for(vpl::tSize x = 0; x < sx; ++x)
                            s->set(x, y, spSlice->at(x, y));

                    // Create margin
                    s->mirrorMargin();

                    // Store slice
                    spSlice = s;
                }

                Filter(*spSlice, *spFiltered);
            }
            else if( m_ssFilterName == std::string("log") )
            {
                // Laplacian of Gaussian filter
                vpl::img::CLoGFilter<vpl::img::CSlice, vpl::img::CUserFunc> Filter(m_dSigma);
                Filter.setNormFunc(m_NormFunc);
                Filter(*spSlice, *spFiltered);
            }
            else if( m_ssFilterName == std::string("dog") )
            {
                // Difference of Gaussians
                vpl::img::CDoGFilter<vpl::img::CSlice, vpl::img::CUserFunc> Filter(m_dSigma, m_dSigma2);
                Filter.setNormFunc(m_NormFunc);
                Filter(*spSlice, *spFiltered);
            }
            else if( m_ssFilterName == std::string("laplace0") )
            {
                // Laplacian
                vpl::img::CLaplaceFilter0<vpl::img::CSlice, vpl::img::CUserFunc> Filter;
                Filter.setNormFunc(m_NormFunc);
                Filter(*spSlice, *spFiltered);
            }
            else if( m_ssFilterName == std::string("laplace1") )
            {
                // Laplacian
                vpl::img::CLaplaceFilter1<vpl::img::CSlice, vpl::img::CUserFunc> Filter;
                Filter.setNormFunc(m_NormFunc);
                Filter(*spSlice, *spFiltered);
            }
            else if( m_ssFilterName == std::string("laplace2") )
            {
                // Laplacian
                vpl::img::CLaplaceFilter2<vpl::img::CSlice, vpl::img::CUserFunc> Filter;
                Filter.setNormFunc(m_NormFunc);
                Filter(*spSlice, *spFiltered);
            }
            else if( m_ssFilterName == std::string("laplace5") )
            {
                // Laplacian
                vpl::img::CLaplaceFilter5<vpl::img::CSlice, vpl::img::CUserFunc> Filter;
                Filter.setNormFunc(m_NormFunc);
                Filter(*spSlice, *spFiltered);
            }
            else if( m_ssFilterName == std::string("prewitx") )
            {
                // Prewit
                vpl::img::CPrewitX<vpl::img::CSlice, vpl::img::CUserFunc> Filter;
                Filter.setNormFunc(m_NormFunc);
                Filter(*spSlice, *spFiltered);
            }
            else if( m_ssFilterName == std::string("prewity") )
            {
                // Prewit
                vpl::img::CPrewitY<vpl::img::CSlice, vpl::img::CUserFunc> Filter;
                Filter.setNormFunc(m_NormFunc);
                Filter(*spSlice, *spFiltered);
            }
            else if( m_ssFilterName == std::string("sobelx") )
            {
                // Sobel operator
                vpl::img::CSobelX<vpl::img::CSlice, vpl::img::CUserFunc> Filter;
                Filter.setNormFunc(m_NormFunc);
                Filter(*spSlice, *spFiltered);
            }
            else if( m_ssFilterName == std::string("sobely") )
            {
                // Sobel operator
                vpl::img::CSobelY<vpl::img::CSlice, vpl::img::CUserFunc> Filter;
                Filter.setNormFunc(m_NormFunc);
                Filter(*spSlice, *spFiltered);
            }
            else if( m_ssFilterName == std::string("robertsx") )
            {
                // Roberts
                vpl::img::CRobertsX<vpl::img::CSlice, vpl::img::CUserFunc> Filter;
                Filter.setNormFunc(m_NormFunc);
                Filter(*spSlice, *spFiltered);
            }
            else if( m_ssFilterName == std::string("robertsy") )
            {
                // Roberts
                vpl::img::CRobertsY<vpl::img::CSlice, vpl::img::CUserFunc> Filter;
                Filter.setNormFunc(m_NormFunc);
                Filter(*spSlice, *spFiltered);
            }
            else if( m_ssFilterName == std::string("avg3") )
            {
                // Averaging
                vpl::img::CAvg3Filter<vpl::img::CSlice> Filter;
                Filter(*spSlice, *spFiltered);
            }
            else if( m_ssFilterName == std::string("avg5") )
            {
                // Averaging
                vpl::img::CAvg5Filter<vpl::img::CSlice> Filter;
                Filter(*spSlice, *spFiltered);
            }
            else if( m_ssFilterName == std::string("avg7") )
            {
                // Averaging
                vpl::img::CAvg7Filter<vpl::img::CSlice> Filter;
                Filter(*spSlice, *spFiltered);
            }
            else if( m_ssFilterName == std::string("anisotropic") )
            {
                // Anisotropic filtering
                vpl::img::CAnisotropicFilter<vpl::img::CSlice> Filter(m_dKappa);
                Filter(*spSlice, *spFiltered);
            }
            else
            {
                VPL_LOG_ERROR('<' << m_sFilename << "> Bad '" << MODULE_ARG_FILTER << "' parameter value: type -h for help" << std::endl);
                printUsage();
                return false;
            }

            // Write it to the output channel
            if( !writeOutput(pOChannel, spFiltered.get()) )
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


void CSliceFilter::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");
}


void CSliceFilter::writeExtendedUsage(std::ostream& Stream)
{
    Stream << "Extended usage: [-filter Type]" << std::endl;
    Stream << "Options:" << std::endl;
    Stream << "  -filter  Specifies a filter that will be used for convolution image" << std::endl;
    Stream << "           filtering. Allowed filter types are:" << std::endl;
    Stream << "             median" << std::endl;
    Stream << "             min" << std::endl;
    Stream << "             max" << std::endl;
    Stream << "             bilateral" << std::endl;
    Stream << "             gauss" << std::endl;
    Stream << "             log (Laplacian of Gaussian)" << std::endl;
    Stream << "             laplace0, laplace1, laplace2 (Laplacian filters 3x3)" << std::endl;
    Stream << "             laplace5 (Laplacian 5x5)" << std::endl;
    Stream << "             prewitx" << std::endl;
    Stream << "             prewity" << std::endl;
    Stream << "             sobelx" << std::endl;
    Stream << "             sobely" << std::endl;
    Stream << "             robertsx" << std::endl;
    Stream << "             robertsy" << std::endl;
    Stream << "             avg3, avg5, avg7 (Averaging filters)" << std::endl;
    Stream << "             anisotropic" << std::endl;
    Stream << "           at present. See other documentation for details." << std::endl;
    Stream << std::endl;
    Stream << "  -norm  Type of the filter response normalization. Supported" << std::endl;
    Stream << "         values are:" << std::endl;
    Stream << "             conv" << std::endl;
    Stream << "             abs" << std::endl;
    Stream << "             pos" << std::endl;
    Stream << "             shift" << std::endl;
    Stream << "           for now. See other documentation for details." << std::endl;
    Stream << std::endl;
    Stream << "  -sigma  Standard deviation (\"sigma\" parameter) of the Gaussian" << std::endl;
    Stream << "          and LoG filters. Is used as distance sigma value of the Bilateral filter. " << std::endl;
    Stream << "          Allowed values are within the range" << std::endl;
    Stream << "          " << MIN_SIGMA << ".." << MAX_SIGMA << " and default value" << std::endl;
    Stream << "          is " << DEFAULT_SIGMA << "." << std::endl;
    Stream << "  -sigmad  Standard deviation in the range (density) domain of the Bilateral filter" << std::endl;
    Stream << "          Allowed values are within the range" << std::endl;
    Stream << "          " << MIN_SIGMA_DENSITY << ".." << MAX_SIGMA_DENSITY << " and default value" << std::endl;
    Stream << "          is " << DEFAULT_SIGMA_DENSITY << "." << std::endl;
    Stream << "  -size  Size of the Median, Min and Max filter. Only an odd number within the" << std::endl;
    Stream << "         range " << MIN_SIZE << ".." << MAX_SIZE << " can be given. Default" << std::endl;
    Stream << "         value of the parameter is " << DEFAULT_SIZE << "." << std::endl;
    Stream << std::endl;
    Stream << "  -sigma2  Standard deviation of the second Gaussian used by the DoG" << std::endl;
    Stream << "           (Difference of Gaussians) filter. Allowed values are within" << std::endl;
    Stream << "           same range as the 'sigma' parameter. Default value is " << DEFAULT_SIGMA2 << "." << std::endl;
    Stream << std::endl;
    Stream << "  -kappa  Parameter of the anisotropic filter. The value may be chosen" << std::endl;
    Stream << "          according to noise level and edge strength in the image." << std::endl;
    Stream << "          Default value is " << DEFAULT_KAPPA << "." << std::endl;
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
    CSliceFilterPtr spModule(new CSliceFilter(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

