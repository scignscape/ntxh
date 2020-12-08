//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/07/26                          \n
 *
 * $Id: mdsMakeVolume.cpp 2098 2012-02-16 23:50:36Z spanel $
 *
 * File description:
 * - Module makes a volume from several input slices.
 */

#include "mdsMakeVolume.h"

// MDSTk
#include <MDSTk/Image/mdsSlice.h>
#include <MDSTk/Image/mdsDensityVolume.h>

// STL
#include <vector>


//==============================================================================
/*
 * Global constants.
 */

//! Module description
const std::string MODULE_DESCRIPTION    = "Module makes volume from several input slices.";

//! Additional command line arguments
const std::string MODULE_ARGUMENTS      = "border:bvalue";

//! Additional arguments names
const std::string MODULE_ARG_BORDER     = "border";
const std::string MODULE_ARG_BVALUE     = "bvalue";

//! Default arguments values
const int DEFAULT_BORDER                = 0;
const int DEFAULT_BVALUE                = mds::img::CPixelTraits<mds::img::CDVolume::tVoxel>::getPixelMin();

//! Allowed arguments values
const int MIN_BORDER                    = 0;
const int MAX_BORDER                    = 64;
const int MIN_BVALUE                    = mds::img::CPixelTraits<mds::img::CDVolume::tVoxel>::getPixelMin();
const int MAX_BVALUE                    = mds::img::CPixelTraits<mds::img::CDVolume::tVoxel>::getPixelMax();


//==============================================================================
/*
 * Type definitions.
 */

//! Vector of all input slices
typedef std::vector<mds::img::CSlicePtr> tSlices;


//==============================================================================
/*
 * Global variables.
 */

//! Vector of all input slices
tSlices InputSlices;


//==============================================================================
/*
 * Global functions.
 */

//! Constructs volume from input Slices
bool makeVolume(tSlices& Slices,
                mds::img::CDensityVolume *pVolume,
                mds::tSize Border,
                mds::img::CDVolume::tVoxel BorderValue
                )
{
    MDS_CHECK(pVolume && (int)Slices.size() > 0, return false);

    // Collect information on volume from input Slices
    tSlices::iterator it = Slices.begin();
    tSlices::const_iterator itEnd = Slices.end();

    mds::tSize XSize = (*it)->getXSize();
    mds::tSize YSize = (*it)->getYSize();
    double dMinPos = (*it)->getPosition();
    double dMaxPos = (*it)->getPosition();

    for( ++it; it != itEnd; ++it )
    {
        XSize = mds::math::getMax(XSize, (*it)->getXSize());
        YSize = mds::math::getMax(YSize, (*it)->getYSize());
        dMinPos = mds::math::getMin(dMinPos, (*it)->getPosition());
        dMaxPos = mds::math::getMax(dMaxPos, (*it)->getPosition());
    }

    mds::tSize ZSize = mds::tSize(Slices.size());

    // Create the volume
    mds::tSize Borders = 2 * Border;
    pVolume->mds::img::CDVolume::create(XSize + Borders,
                                        YSize + Borders,
                                        ZSize + Borders
                                        );
    pVolume->fill(BorderValue);

    // Create helper reference volume
    mds::img::CDVolume VolumeRef(*pVolume,
                                 Border, Border, Border,
                                 XSize, YSize, ZSize,
                                 mds::REFERENCE
                                 );

    // Krok pro vkladani rezu
    double dStep = (dMaxPos - dMinPos) / double(Slices.size() - 1);
    double dInvStep = 1.0;
    if( dStep > 0.0 )
    {
        dInvStep = 1.0 / dStep;
    }

    // Put Slices in the pVolume
    it = Slices.begin();
    while( it != itEnd )
    {
        double dTemp = ((*it)->getPosition() - dMinPos) * dInvStep;
        VolumeRef.setPlaneXY(mds::tSize(mds::math::round2Int(dTemp)), *(*it));
        ++it;
    }

    // Set the voxel size
    pVolume->setVoxel(Slices[0]->getDX(),
                      Slices[0]->getDY(),
//                      Slices[0]->getThickness()
                      dStep
                      );

    // O.K.
    return true;
}


//==============================================================================
/*
 * Implementation of the class CMakeVolume.
 */
CMakeVolume::CMakeVolume(const std::string& sDescription)
    : mds::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CMakeVolume::~CMakeVolume()
{
}


bool CMakeVolume::startup()
{
    // Note
    MDS_LOG_NOTE("Module startup");

    // Test of existence of input and output channel
    if( getNumOfInputs() != 1 || getNumOfOutputs() != 1 )
    {
        MDS_CERR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    m_iBorder = DEFAULT_BORDER;
    m_Arguments.value(MODULE_ARG_BORDER, m_iBorder);
    if( m_iBorder < MIN_BORDER || m_iBorder > MAX_BORDER )
    {
        MDS_CERR('<' << m_sFilename << "> Bad " << MODULE_ARG_BORDER << " parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    m_iBorderValue = DEFAULT_BVALUE;
    m_Arguments.value(MODULE_ARG_BVALUE, m_iBorderValue);
    if( m_iBorderValue < MIN_BVALUE || m_iBorderValue > MAX_BVALUE )
    {
        MDS_CERR('<' << m_sFilename << "> Bad " << MODULE_ARG_BVALUE << " parameter value: type -h for help" << std::endl);
        printUsage();
        return false;
    }

    // O.K.
    return true;
}


bool CMakeVolume::main()
{
    // Note
    MDS_LOG_NOTE("Module main function");

    // I/O channels
    mds::mod::CChannel *pIChannel = getInput(0);
    mds::mod::CChannel *pOChannel = getOutput(0);

    // Is any input?
    if( !pIChannel->isConnected() )
    {
        // Smart pointer to a new volume
        mds::img::CDensityVolumePtr spVolume;

        // Make volume and write it to the output channel
        if( makeVolume(InputSlices,
                       spVolume,
                       mds::tSize(m_iBorder),
                       mds::img::CDVolume::tVoxel(m_iBorderValue)
                       ) )
        {
            if( !writeOutput(pOChannel, spVolume.get()) )
            {
                MDS_CERR('<' << m_sFilename << "> Failed to write the output volume" << std::endl);
            }
        }
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
            // Push slice to the vector
            InputSlices.push_back(spSlice);
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


void CMakeVolume::shutdown()
{
    // Note
    MDS_LOG_NOTE("Module shutdown");

    // Clear input slices
    InputSlices.clear();
}


void CMakeVolume::writeExtendedUsage(std::ostream& MDS_UNUSED(Stream))
{
    MDS_CERR("Extended usage: [-border uValue] [-bvalue iValue]" << std::endl);
    MDS_CERR("Options:" << std::endl);
    MDS_CERR("  -border  Size of the volume margin in voxels." << std::endl);
    MDS_CERR("           Values in the range <" << MIN_BORDER << ", " << MAX_BORDER << "> can be given." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -bvalue  Voxel value used to fill the margin." << std::endl);
    MDS_CERR("           Allowed voxel range is <" << MIN_BVALUE << ", " << MAX_BVALUE << ">." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("Input: sequence of MDSTk slices" << std::endl);
    MDS_CERR("Output: MDSTk volume" << std::endl);
}


//==============================================================================
/*
 * Function main() which creates and executes console application.
 */
int main(int argc, char *argv[])
{
    // Creation of a module using smart pointer
    CMakeVolumePtr spModule(new CMakeVolume(MODULE_DESCRIPTION));

    // Initialize and execute the module
    if( spModule->init(argc, argv) )
    {
        spModule->run();
    }

    // Console application finished
    return 0;
}

