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
 * Copyright (c) 2003-2006 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/11/08                       
 *
 * Description:
 * - Definition of a simple MDSTk module application.
 */

#ifndef VPL_MODULE_H
#define VPL_MODULE_H

#include "Console.h"
#include "Channel.h"
#include "Serializer.h"
#include "Serialization.h"
#include "XMLSerializer.h"

// STL
#include <vector>


namespace vpl
{
namespace mod
{

//==============================================================================
/*
 * Names of command line arguments.
 */

//! Namespace containing constants used by the CModule class.
namespace module
{

//! Command line arguments.
const std::string ARGUMENT_INPUT    = "i";
const std::string ARGUMENT_OUTPUT   = "o";
const std::string ARGUMENT_RAW      = "raw";
const std::string ARGUMENT_XML      = "xml";

} // namespace module


//==============================================================================
/*!
 * Class encapsulating a single MDSTk module.
 * - Supports log files and logging.
 * - Provides command line arguments parsing.
 * - I/O channels.
 */
class VPL_MODULE_EXPORT CModule : public vpl::mod::CConsole
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    VPL_SHAREDPTR(CModule);

public:
    //! Default constructor.
    CModule(const std::string& sDescription);

    //! Virtual destructor.
    virtual ~CModule();


    //! Initializes module and parses a given command line.
    //! - Returns false on failure.
    bool init(int argc, char *argv[]);

    //! Writes a simple usage to the given stream.
    void printUsage();

    //! Writes a full help.
    void printFullUsage();


    //! Returns a number of input channels.
    int getNumOfInputs() const { return (int)m_InputChannels.size(); }

    //! Retreives an i-th input channel.
    //! - Returns NULL if a channel doesn't exist.
    CChannel *getInput(int i);

    //! Number of output channels.
    int getNumOfOutputs() const { return (int)m_OutputChannels.size(); }

    //! Retreives an i-th output channel.
    //! - Returns NULL if there is no i-th channel.
    CChannel *getOutput(int i);


    //! Writes a given data entity to the channel.
    //! - Returns true on success.
    template <typename T>
    bool writeOutput(CChannel *pChannel, T *pObject);

    //! Reads a data entity from the input channel.
    //! - Returns true on success.
    template <typename T>
    bool readInput(CChannel *pChannel, T *pObject);


    //! Virtual method called on module startup.
    //! - Expected to be overriden.
    //! - Has to return false on startup failure.
    virtual bool startup() = 0;

    //! Virtual method repeatedly called by the processing thread.
    //! - When you need to stop the execution just return false.
    virtual bool main() = 0;

    //! Called on module shutdown.
    virtual void shutdown() = 0;

    //! Called on writing a full usage statement.
    virtual void writeExtendedUsage(std::ostream& Stream) = 0;

protected:
    //! Vector of i/o channels.
    typedef std::vector<CChannelPtr> tChannels;

protected:
    //! Application input channels.
    tChannels m_InputChannels;

    //! Output channels.
    tChannels m_OutputChannels;

    //! Write raw data.
    bool m_bRawData;

    //! Experimental XML output.
    bool m_bXMLData;
};


//==============================================================================
/*!
 * Smart pointer to module.
 */
typedef CModule::tSmartPtr  CModulePtr;


//==============================================================================
/*
 * Implementation...
 */

template <typename T>
bool CModule::writeOutput(CChannel *pChannel, T *pObject)
{
    VPL_ASSERT(pObject && pChannel);

    unsigned uiFlags = (m_bRawData) ? Serializer::RAW_DATA : 0;

#ifdef VPL_USE_XML_SERIALIZER
    if( m_bXMLData )
    {
        uiFlags |= Serializer::XML;
    }
#endif // VPL_USE_XML_SERIALIZER

    return write(*pObject, *pChannel, uiFlags);
}


template <typename T>
bool CModule::readInput(CChannel *pChannel, T *pObject)
{
    VPL_ASSERT(pObject && pChannel);

    return read(*pObject, *pChannel);
}


} // namespace mod
} // namespace vpl

#endif // VPL_MODULE_H

