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
 * Copyright (c) 2003-2008 by PGMed@FIT      
 *
 * Author:  Radek Barton, ibarton@fit.vutbr.cz  \n
 * Date:    2008/10/27                       
 *
 * File description:
 * - Volume subsampling using different algorithms.
 */

#include "VolumeSubsampling.h"

#include <VPL/Image/DensityVolume.h>

// STL
#include <string>

//==============================================================================
/*
 * Global constants.
 */

//! Module description
const std::string MODULE_DESCRIPTION = "Module creates a subsampled volume"
  " using specified algorithm.";

//! Additional command line arguments.
const std::string MODULE_ARGUMENTS = "algorithm:levels";

// Additional arguments.
const std::string MODULE_ARGUMENT_ALGORITHM = "algorithm";
const std::string MODULE_ARGUMENT_LEVELS     = "levels";

// Allowed 'algorithm' argument values.
const std::string ALG_NEAREST_NAME  = "nearest";
const std::string ALG_AVERAGE_NAME  = "average";

// Default arguments values.
const CVolumeSubsampling::ESubsamplingAlogorithm DEFAULT_ALGORITHM =
  CVolumeSubsampling::ALG_NEAREST;
const unsigned int DEFAULT_LEVELS = 2;

//==============================================================================
/*
 * Global variables.
 */

//! Subsampling algorithm.
CVolumeSubsampling::ESubsamplingAlogorithm eAlgorithm;

//==============================================================================
/*
 * Implementation of the class CVolumeSubsampling.
 */

CVolumeSubsampling::CVolumeSubsampling(const std::string & description):
  vpl::mod::CModule(description)
{
  // Specify allowed module arguments.
  this->allowArguments(MODULE_ARGUMENTS);
}

CVolumeSubsampling::~CVolumeSubsampling()
{
  // Nothing.
}

bool CVolumeSubsampling::startup()
{
  // Debug.
  VPL_LOG_INFO("Module startup");

  // Test of existence of input and output channel.
  if (this->getNumOfInputs() != 1 || this->getNumOfOutputs() != 1)
  {
    VPL_LOG_ERROR('<' << this->m_sFilename << "> Wrong number of input and output channels"
      << std::endl);
    return false;
  }

  // Read module arguments.
  this->m_Arguments.value(MODULE_ARGUMENT_ALGORITHM, this->algorithm);
  if (this->algorithm == ALG_NEAREST_NAME)
  {
    eAlgorithm = ALG_NEAREST;
  }
  else if (this->algorithm == ALG_AVERAGE_NAME)
  {
    eAlgorithm = ALG_AVERAGE;
  }
  else
  {
    eAlgorithm = DEFAULT_ALGORITHM;
  }

  this->levels = DEFAULT_LEVELS;
  this->m_Arguments.value(MODULE_ARGUMENT_LEVELS, this->levels);
  if( this->levels < 1 )
  {
    VPL_LOG_ERROR('<' << this->m_sFilename << "> Bad " << MODULE_ARGUMENT_LEVELS <<
      " parameter value: type -h for help" << std::endl);
    this->printUsage();
    return false;
  }

  // Arguments are OK.
  return true;
}


bool CVolumeSubsampling::main()
{
  // Debug.
  VPL_LOG_INFO("Module main function");

  // Get input and output channels.
  vpl::mod::CChannel * input_channel = getInput(0);
  vpl::mod::CChannel * output_channel = getOutput(0);

  // Check input channel.
  if (!input_channel->isConnected())
  {
    return false;
  }

  vpl::img::CDensityVolumePtr volume;
  vpl::img::CDensityVolumePtr new_volume;

  // Wait for data.
  if (input_channel->wait(1000))
  {
    // Read slice from the input channel.
    if (this->readInput(input_channel, volume.get()))
    {
      switch (eAlgorithm)
      {
        case ALG_NEAREST:
        {
          VPL_LOG_INFO("Nearest pixel algorithm choosen");

          // Compute dimenions of subsampled volume.
          vpl::tSize width = volume->getXSize();
          vpl::tSize height = volume->getYSize();
          vpl::tSize depth = volume->getZSize();
          vpl::tSize new_width = width >> (this->levels - 1);
          vpl::tSize new_height = height >> (this->levels - 1);
          vpl::tSize new_depth = depth >> (this->levels - 1);
          vpl::tSize step = 0x01 << (this->levels - 1);

          // Create new volume.
          new_volume = new vpl::img::CDensityVolume(new_width, new_height, new_depth);

          // Fill it with nearest values from original volume.
          for (vpl::tSize Z = 0; Z < new_depth; ++Z)
          {
            for (vpl::tSize Y = 0; Y < new_height; ++Y)
            {
              for (vpl::tSize X = 0; X < new_width; ++X)
              {
                const vpl::img::tDensityPixel & pixel = volume->at(X * step,
                  Y * step, Z * step);
                new_volume->set(X, Y, Z, pixel);
              }
            }
          }
        }
        break;
        case ALG_AVERAGE:
        {
          VPL_LOG_INFO("Average algorithm choosen");

          // Compute dimentions of subsampled volume.
          vpl::tSize width = volume->getXSize();
          vpl::tSize height = volume->getYSize();
          vpl::tSize depth = volume->getZSize();
          vpl::tSize new_width = width >> (this->levels - 1);
          vpl::tSize new_height = height >> (this->levels - 1);
          vpl::tSize new_depth = depth >> (this->levels - 1);
          vpl::tSize step = 0x01 << (this->levels - 1);
          vpl::tSize count = step * step * step;

          // Create new volume.
          new_volume = new vpl::img::CDensityVolume(new_width, new_height,
            new_depth);

          // Fill it with average values from original volume.
          for (vpl::tSize Z = 0; Z < new_depth; ++Z)
          {
            for (vpl::tSize Y = 0; Y < new_height; ++Y)
            {
              for (vpl::tSize X = 0; X < new_width; ++X)
              {
                // Compute average.
                long long int pixel = 0;
                for (vpl::tSize avg_Z = 0; avg_Z < step; avg_Z++)
                {
                  for (vpl::tSize avg_Y = 0; avg_Y < step; avg_Y++)
                  {
                    for (vpl::tSize avg_X = 0; avg_X < step; avg_X++)
                    {
                      pixel += volume->at((X * step) + avg_X, (Y * step) +
                        avg_Y, (Z * step) + avg_Z);
                    }
                  }
                }
                new_volume->set(X, Y, Z, vpl::img::tDensityPixel(pixel / count));
              }
            }
          }
        }
        break;
        default:
        {
          // Nothing.
        }
      }

      // Copy metadata.
      new_volume->setVoxel(volume->getDX(), volume->getDY(), volume->getDZ());

      // Write subsapled volume to the output channel.
      if (!this->writeOutput(output_channel, new_volume.get()))
      {
        VPL_LOG_ERROR('<' << this->m_sFilename << "> Failed to write the output slice"
          << std::endl);
        return false;
      }
    }
    else
    {
      VPL_LOG_ERROR('<' << this->m_sFilename << "> Failed to read input slice" <<
        std::endl);
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


void CVolumeSubsampling::shutdown()
{
  // Debug.
  VPL_LOG_INFO("Module shutdown");
}


void CVolumeSubsampling::writeExtendedUsage(std::ostream& Stream)
{
  Stream << "Extended usage: [-algorithm sValue] [-levels uValue]" << std::endl;
  Stream << "Options:" << std::endl;
  Stream << "  -algorithms  Subsampling algorithms (nearest|average)." << std::endl;
  Stream << "  -levels  The number of level of subsampling." << std::endl;
}


//==============================================================================
/*
 * Function main() which creates and executes console application.
 */
int main(int argc, char *argv[])
{
  // Creation of a module using smart pointer,
  CVolumeSubsamplingPtr module(new CVolumeSubsampling(MODULE_DESCRIPTION));

  // Initialize and execute the module
  if (module->init(argc, argv))
  {
    module->run();
  }

  // Console application finished.
  return EXIT_SUCCESS;
}
