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
 * Date:    2005/01/26                       
 *
 * Description:
 * - Several volume filtering functions.
 */

#include "VolumeFilter.h"

// STl
#include <iostream>
#include <string>


//==============================================================================
/*
 * Global constants.
 */

//! Module description
const std::string MODULE_DESCRIPTION    = "Module providing basic volume filtering methods";

//! Additional command line arguments
const std::string MODULE_ARGUMENTS      = "filter:norm:size:sigma:sigmad:kappa";

//! Additional arguments
const std::string MODULE_ARG_FILTER     = "filter";
const std::string MODULE_ARG_NORM       = "norm";
const std::string MODULE_ARG_SIZE       = "size";
const std::string MODULE_ARG_SIGMA      = "sigma";
const std::string MODULE_ARG_SIGMA_DENSITY      = "sigmad";
const std::string MODULE_ARG_KAPPA      = "kappa";

//! Default argument values
const std::string DEFAULT_NORM          = "conv";
const double DEFAULT_SIGMA              = 1.0;
const double DEFAULT_SIGMA_DENSITY      = 1.0;
const int DEFAULT_SIZE                  = 3;
const double DEFAULT_KAPPA              = 200.0;

//! Allowed argument values
const double MIN_SIGMA                  = 0.5;
const double MAX_SIGMA                  = 3.0;

//! Allowed argument values
const double MIN_SIGMA_DENSITY          = 1.0;
const double MAX_SIGMA_DENSITY          = vpl::img::CPixelTraits<vpl::img::tDensityPixel>::getMax() - vpl::img::CPixelTraits<vpl::img::tDensityPixel>::getMin();

//! Allowed argument values
const int MIN_SIZE                      = 3;
const int MAX_SIZE                      = 15;

const double MIN_KAPPA                  = 1.0;
const double MAX_KAPPA                  = vpl::img::CPixelTraits<vpl::img::tDensityPixel>::getPixelMax();


//==============================================================================
/*
 * Implementation of the class CVolumeFilter.
 */
CVolumeFilter::CVolumeFilter(const std::string& sDescription)
    : vpl::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CVolumeFilter::~CVolumeFilter()
{
}


bool CVolumeFilter::startup()
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

    // Type of volume filtering
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

    // Parameter 'sigmad'
    m_dSigmaS = DEFAULT_SIGMA_DENSITY;
    m_Arguments.value(MODULE_ARG_SIGMA_DENSITY, m_dSigmaS);
    if( m_dSigmaS > MAX_SIGMA_DENSITY || m_dSigmaS < MIN_SIGMA_DENSITY )
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


bool CVolumeFilter::main()
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

    // Create a new volume
    vpl::img::CDensityVolumePtr spVolume(new vpl::img::CDensityVolume());

    // Wait for data
    if( pIChannel->wait(1000) )
    {
        // Read volume from the input channel
        if( readInput(pIChannel, spVolume.get()) )
        {
            // Pad volume margin
            spVolume->mirrorMargin();

            // Create an output slice
            vpl::img::CDensityVolumePtr spFiltered(new vpl::img::CDensityVolume(spVolume->getXSize(),
                                                                                spVolume->getYSize(),
                                                                                spVolume->getZSize()
                                                                                ));
            spFiltered->fillEntire(vpl::img::CPixelTraits<vpl::img::tDensityPixel>::getPixelMin());

            // Set properties of the output volume
            spFiltered->setVoxel(spVolume->getDX(),
                                 spVolume->getDY(),
                                 spVolume->getDZ()
                                 );

            // Filter the volume
            if( m_ssFilterName == std::string("median") )
            {
                // Median filter
                vpl::img::CVolumeMedianFilter<vpl::img::CDensityVolume> Filter(m_iSize);
                Filter(*spVolume, *spFiltered);
            }
            else if( m_ssFilterName == std::string("min") )
            {
                // Min filter
                vpl::img::CVolumeMinFilter<vpl::img::CDensityVolume> Filter(m_iSize);
                Filter(*spVolume, *spFiltered);
            }
            else if( m_ssFilterName == std::string("max") )
            {
                // Max filter
                vpl::img::CVolumeMaxFilter<vpl::img::CDensityVolume> Filter(m_iSize);
                Filter(*spVolume, *spFiltered);
            }
            else if( m_ssFilterName == std::string("laplace0") )
            {
                // Laplacian
                vpl::img::CVolumeLaplaceFilter0<vpl::img::CDensityVolume, vpl::img::CUserFunc> Filter;
                Filter.setNormFunc(m_NormFunc);
                Filter(*spVolume, *spFiltered);
            }
            else if( m_ssFilterName == std::string("laplace1") )
            {
                // Laplacian
                vpl::img::CVolumeLaplaceFilter1<vpl::img::CDensityVolume, vpl::img::CUserFunc> Filter;
                Filter.setNormFunc(m_NormFunc);
                Filter(*spVolume, *spFiltered);
            }
            else if( m_ssFilterName == std::string("prewitx") )
            {
                // Prewit
                vpl::img::CVolumePrewitX<vpl::img::CDensityVolume, vpl::img::CUserFunc> Filter;
                Filter.setNormFunc(m_NormFunc);
                Filter(*spVolume, *spFiltered);
            }
            else if( m_ssFilterName == std::string("prewity") )
            {
                // Prewit
                vpl::img::CVolumePrewitY<vpl::img::CDensityVolume, vpl::img::CUserFunc> Filter;
                Filter.setNormFunc(m_NormFunc);
                Filter(*spVolume, *spFiltered);
            }
            else if( m_ssFilterName == std::string("prewitz") )
            {
                // Prewit
                vpl::img::CVolumePrewitZ<vpl::img::CDensityVolume, vpl::img::CUserFunc> Filter;
                Filter.setNormFunc(m_NormFunc);
                Filter(*spVolume, *spFiltered);
            }
            else if( m_ssFilterName == std::string("sobelx") )
            {
                // Sobel operator
                vpl::img::CVolumeSobelX<vpl::img::CDensityVolume, vpl::img::CUserFunc> Filter;
                Filter.setNormFunc(m_NormFunc);
                Filter(*spVolume, *spFiltered);
            }
            else if( m_ssFilterName == std::string("sobely") )
            {
                // Sobel operator
                vpl::img::CVolumeSobelY<vpl::img::CDensityVolume, vpl::img::CUserFunc> Filter;
                Filter.setNormFunc(m_NormFunc);
                Filter(*spVolume, *spFiltered);
            }
            else if( m_ssFilterName == std::string("sobelz") )
            {
                // Sobel operator
                vpl::img::CVolumeSobelZ<vpl::img::CDensityVolume, vpl::img::CUserFunc> Filter;
                Filter.setNormFunc(m_NormFunc);
                Filter(*spVolume, *spFiltered);
            }
            else if( m_ssFilterName == std::string("avg3") )
            {
                // Averaging
                vpl::img::CVolumeAvg3Filter<vpl::img::CDensityVolume> Filter;
                Filter(*spVolume, *spFiltered);
            }
            else if( m_ssFilterName == std::string("gauss3") )
            {
                // Gaussian 3x3
                vpl::img::CVolumeGauss3Filter<vpl::img::CDensityVolume> Filter;
                Filter(*spVolume, *spFiltered);
            }
            else if( m_ssFilterName == std::string("gauss") )
            {
                // Gaussian
                vpl::img::CVolumeGaussFilter<vpl::img::CDensityVolume> Filter(m_dSigma);
                if( Filter.getSize() > 3 )
                {
                    vpl::img::CDensityVolume Aux;
                    Aux.copy(*spVolume, Filter.getNeededMargin()).mirrorMargin();
                    Filter(Aux, *spFiltered);
                }
                else
                {
                    Filter(*spVolume, *spFiltered);
                }
            }
            else if( m_ssFilterName == std::string("bilateral") )
            {
                // Bilateral
                vpl::img::CVolumeBilateralFilter<vpl::img::CDensityVolume> Filter(m_dSigmaS, m_dSigma);
                if( Filter.getSize() > 3 )
                {
                    vpl::img::CDensityVolume Aux;
                    Aux.copy(*spVolume, Filter.getNeededMargin()).mirrorMargin();
                    Filter(Aux, *spFiltered);
                }
                else
                {
                    Filter(*spVolume, *spFiltered);
                }
            }
            else if( m_ssFilterName == std::string("anisotropic") )
            {
                // Anisotropic filtering
                vpl::img::CVolumeAnisotropicFilter<vpl::img::CDensityVolume> Filter(m_dKappa);
                Filter(*spVolume, *spFiltered);
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


void CVolumeFilter::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");
}


void CVolumeFilter::writeExtendedUsage(std::ostream& Stream)
{
    Stream << "Extended usage: [-filter sType]" << std::endl;
    Stream << "Options:" << std::endl;
    Stream << "  -filter  Specifies a filter that will be used for image" << std::endl;
    Stream << "           filtering. Allowed filter types are:" << std::endl;
    Stream << "             median" << std::endl;
    Stream << "             min" << std::endl;
    Stream << "             max" << std::endl;
    Stream << "             gauss, gauss3" << std::endl;
    Stream << "             bilateral" << std::endl;
    Stream << "             laplace0, laplace1 (Laplacian of Gaussian filters)" << std::endl;
    Stream << "             prewitx" << std::endl;
    Stream << "             prewity" << std::endl;
    Stream << "             prewitz" << std::endl;
    Stream << "             sobelx" << std::endl;
    Stream << "             sobely" << std::endl;
    Stream << "             sobelz" << std::endl;
    Stream << "             avg3 (Averaging filter 3x3x3)" << std::endl;
    Stream << "             anisotropic" << std::endl;
    Stream << "           at present. See other documentation for details." << std::endl;
    Stream << std::endl;
    Stream << "  -norm  Type of the filter response normalization. Supported" << std::endl;
    Stream << "         types are:" << std::endl;
    Stream << "             conv" << std::endl;
    Stream << "             abs" << std::endl;
    Stream << "             shift" << std::endl;
    Stream << "             pos" << std::endl;
    Stream << "           for now. See other documentation for details." << std::endl;
    Stream << std::endl;
    Stream << "  -sigma  Standard deviation (\"sigma\" parameter) of the Gaussian" << std::endl;
    Stream << "          filter. Allowed values are within the range" << std::endl;
    Stream << "          " << MIN_SIGMA << ".." << MAX_SIGMA << " and default value" << std::endl;
    Stream << "          is " << DEFAULT_SIGMA << "." << std::endl;
    Stream << "  -sigmad  Standard deviation (\"sigma\" parameter) in the density domain" << std::endl;
    Stream << "          of the Bilateral filter. Allowed values are within the range" << std::endl;
    Stream << "          " << MIN_SIGMA_DENSITY << ".." << MAX_SIGMA_DENSITY << " and default value" << std::endl;
    Stream << "          is " << DEFAULT_SIGMA_DENSITY << "." << std::endl;    Stream << std::endl;
    Stream << "  -size  Size of the Median filter. Only an odd number within the" << std::endl;
    Stream << "         range " << MIN_SIZE << ".." << MAX_SIZE << " can be given. Default" << std::endl;
    Stream << "         value of the parameter is " << DEFAULT_SIZE << "." << std::endl;
    Stream << std::endl;
    Stream << "  -kappa  Parameter of the anisotropic filter. The value may be chosen" << std::endl;
    Stream << "          according to noise level and edge strength in the image." << std::endl;
    Stream << "          Default value is " << DEFAULT_KAPPA << "." << std::endl;
    Stream << std::endl;
    Stream << "Input: MDSTk volume" << std::endl;
    Stream << "Output: MDSTk volume" << std::endl;
}


//==============================================================================
/*
 * Function main() which creates and executes console application.
 */
int main(int argc, char *argv[])
{
    // Creation of a module using smart pointer
    CVolumeFilterPtr spModule(new CVolumeFilter(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

