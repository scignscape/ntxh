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
 * Date:    2003/11/11                       
 *
 * Description:
 * - Definition of a simple MDSTk module application.
 */

#include <VPL/Module/Module.h>

#include <VPL/Base/Assert.h>
#include <VPL/Base/Version.h>
#include <VPL/Base/BuildDate.h>
#include <VPL/System/Sleep.h>


namespace vpl
{
namespace mod
{

//==============================================================================
/*
 * Implementation of the class vpl::mod::CModule.
 */
CModule::CModule(const std::string& sDescription)
    : CConsole(sDescription)
    , m_bRawData(false)
{
    // Initialize default console arguments
#ifdef VPL_USE_XML_SERIALIZER
    allowArguments("i:o:raw:xml");
#else
    allowArguments("i:o:raw");
#endif // VPL_USE_XML_SERIALIZER
}


CModule::~CModule()
{
    // Input channels
    m_InputChannels.clear();

    // Output channels
    m_OutputChannels.clear();
}


bool CModule::init(int argc, char *argv[])
{
    // Init console
    if( !CConsole::init(argc, argv) )
    {
        return false;
    }

    // Modifiers
    m_bRawData = m_Arguments.exists(module::ARGUMENT_RAW);
    m_bXMLData = m_Arguments.exists(module::ARGUMENT_XML);

    // Temporary variables
    std::string sDesc;
    std::vector<std::string> Descs;

    // Creation of input channels
    if( m_Arguments.exists(module::ARGUMENT_INPUT) )
    {
        m_Arguments.value(module::ARGUMENT_INPUT, sDesc);
        CChannel::separate(sDesc, Descs);
        for( std::size_t i = 0; i < Descs.size(); ++i )
        {
            CChannel *pChannel;
            try {
                pChannel = CChannel::create(CH_IN, Descs[i]);
            }
            catch( const CChannel::CCannotCreate& )
            {
                std::cerr << '<' << m_sFilename << "> Bad input channel: type -h for help" << std::endl;
                printUsage();
                return false;
            }
            if( !pChannel->listen(CH_CONNECTION_TIMEOUT) )
            {
                std::cerr << '<' << m_sFilename << "> Cannot connect input channel" << std::endl;
                return false;
            }
            m_InputChannels.push_back(pChannel);
        }
    }
    else
    {
        // Default input channel is stdin
        CChannel *pChannel = new CStdChannel(CH_IN);
        VPL_ASSERT(pChannel);
        m_InputChannels.push_back(pChannel);
    }

    // Output channels
    if( m_Arguments.exists(module::ARGUMENT_OUTPUT) )
    {
        m_Arguments.value(module::ARGUMENT_OUTPUT, sDesc);
        CChannel::separate(sDesc, Descs);
        for( std::size_t i = 0; i < Descs.size(); ++i )
        {
            CChannel *pChannel;
            try {
                pChannel = CChannel::create(CH_OUT, Descs[i]);
            }
            catch( const CChannel::CCannotCreate& )
            {
                std::cerr << '<' << m_sFilename << "> Bad output channel: type -h for help" << std::endl;
                printUsage();
                return false;
            }
            if( !pChannel->connect(CH_CONNECTION_TIMEOUT) )
            {
                std::cerr << '<' << m_sFilename << "> Cannot connect output channel" << std::endl;
                return false;
            }
            m_OutputChannels.push_back(pChannel);
        }
    }
    else
    {
        // Default output channel is stdout
        CChannel *pChannel = new CStdChannel(CH_OUT);
        VPL_ASSERT(pChannel);
        m_OutputChannels.push_back(pChannel);
    }

    // Everything is OK so return true
    return true;
}


void CModule::printUsage()
{
    std::cerr << LABEL << '-' << VERSION << ": " << m_sDescription << std::endl;
    std::cerr << "Usage: " << m_sFilename << " [-h] [-log sLog] [-logname sFilename]" << std::endl;
    std::cerr << "                             [-i,o sChannel(s)] [-raw]" << std::endl;
}


void CModule::printFullUsage()
{
    printUsage();

    std::cerr << "Options:" << std::endl;
    std::cerr << "  -h Shows this help." << std::endl;
    std::cerr << std::endl;
    std::cerr << "  -log  Option selects a log type. Allowed values are:" << std::endl;
    std::cerr << "          " << console::LOG_NULL << " for no logging," << std::endl;
    std::cerr << "          " << console::LOG_STDERR << ',' << std::endl;
    std::cerr << "          " << console::LOG_FILE << " and" << std::endl;
    std::cerr << "          " << console::LOG_BOTH << '.' << std::endl;
    std::cerr << "        Default value is " << console::DEFAULT_LOG << '.' << std::endl;
    std::cerr << std::endl;
    std::cerr << "  -logname  Changes filename of the output log." << std::endl;
    std::cerr << std::endl;
    std::cerr << "  -i  Specification of a module input channel. Channel is described" << std::endl;
    std::cerr << "      by a string of the form \"medium[:attrib1[:attrib2[...]]]\"." << std::endl;
    std::cerr << "      Allowed medium types are \"stdio\", \"file\" and \"pipe\". Stdio has" << std::endl;
    std::cerr << "      no attributes, file and pipe has only one attribute, filename." << std::endl;
    std::cerr << std::endl;
    std::cerr << "  -o  Module output. Channel description is same as above." << std::endl;
    std::cerr << std::endl;
    std::cerr << "  -raw  Disables output compression and suppresses data headers." << std::endl;

#ifdef VPL_USE_XML_SERIALIZER
    std::cerr << std::endl;
    std::cerr << "  -xml  Experimental XML output." << std::endl;
#endif // VPL_USE_XML_SERIALIZER

    std::cerr << std::endl;
    this->writeExtendedUsage(std::cerr);
}


CChannel *CModule::getInput(int i)
{
    if( i >= getNumOfInputs() )
    {
        return NULL;
    }
    return m_InputChannels[i];
}


CChannel *CModule::getOutput(int i)
{
    if( i >= getNumOfOutputs() )
    {
        return NULL;
    }
    return m_OutputChannels[i];
}


} // namespace mod
} // namespace vpl

