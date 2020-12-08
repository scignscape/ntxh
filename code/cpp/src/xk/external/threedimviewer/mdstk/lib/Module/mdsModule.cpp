//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/11/11                          \n
 *
 * $Id: mdsModule.cpp 2065 2012-02-02 23:29:38Z spanel $
 *
 * Description:
 * - Definition of a simple MDSTk module application.
 */

#include <MDSTk/Module/mdsModule.h>

#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Base/mdsVersion.h>
#include <MDSTk/Base/mdsBuildDate.h>
#include <MDSTk/System/mdsSleep.h>


namespace mds
{
namespace mod
{

//==============================================================================
/*
 * Implementation of the class mds::mod::CModule.
 */
CModule::CModule(const std::string& sDescription)
    : CConsole(sDescription)
    , m_bRawData(false)
{
    // Initialize default console arguments
#ifdef MDS_USE_XML_SERIALIZER
    allowArguments("i:o:raw:xml");
#else
    allowArguments("i:o:raw");
#endif // MDS_USE_XML_SERIALIZER
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
        for( int i = 0; i < (int)Descs.size(); ++i )
        {
            CChannel *pChannel;
            try {
                pChannel = CChannel::create(CH_IN, Descs[i]);
            }
            catch( const CChannel::CCannotCreate& )
            {
                MDS_CERR('<' << m_sFilename << "> Bad input channel: type -h for help" << std::endl);
                printUsage();
                return false;
            }
            if( !pChannel->listen(CH_CONNECTION_TIMEOUT) )
            {
                MDS_CERR('<' << m_sFilename << "> Cannot connect input channel" << std::endl);
                return false;
            }
            m_InputChannels.push_back(pChannel);
        }
    }
    else
    {
        // Default input channel is stdin
        CChannel *pChannel = new CStdChannel(CH_IN);
        MDS_ASSERT(pChannel);
        m_InputChannels.push_back(pChannel);
    }

    // Output channels
    if( m_Arguments.exists(module::ARGUMENT_OUTPUT) )
    {
        m_Arguments.value(module::ARGUMENT_OUTPUT, sDesc);
        CChannel::separate(sDesc, Descs);
        for( int i = 0; i < (int)Descs.size(); ++i )
        {
            CChannel *pChannel;
            try {
                pChannel = CChannel::create(CH_OUT, Descs[i]);
            }
            catch( const CChannel::CCannotCreate& )
            {
                MDS_CERR('<' << m_sFilename << "> Bad output channel: type -h for help" << std::endl);
                printUsage();
                return false;
            }
            if( !pChannel->connect(CH_CONNECTION_TIMEOUT) )
            {
                MDS_CERR('<' << m_sFilename << "> Cannot connect output channel" << std::endl);
                return false;
            }
            m_OutputChannels.push_back(pChannel);
        }
    }
    else
    {
        // Default output channel is stdout
        CChannel *pChannel = new CStdChannel(CH_OUT);
        MDS_ASSERT(pChannel);
        m_OutputChannels.push_back(pChannel);
    }

    // Everything is OK so return true
    return true;
}


void CModule::printUsage()
{
    MDS_CERR(LABEL << '-' << VERSION << ": " << m_sDescription << std::endl);
    MDS_CERR("Usage: " << m_sFilename << " [-h] [-log sLog] [-logname sFilename]" << std::endl);
    MDS_CERR("                             [-i,o sChannel(s)] [-raw]" << std::endl);
}


void CModule::printFullUsage()
{
    printUsage();

    MDS_CERR("Options:" << std::endl);
    MDS_CERR("  -h Shows this help." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -log  Option selects a log type. Allowed values are:" << std::endl);
    MDS_CERR("          " << console::LOG_NULL << " for no logging," << std::endl);
    MDS_CERR("          " << console::LOG_STDERR << ',' << std::endl);
    MDS_CERR("          " << console::LOG_FILE << " and" << std::endl);
    MDS_CERR("          " << console::LOG_BOTH << '.' << std::endl);
    MDS_CERR("        Default value is " << console::DEFAULT_LOG << '.' << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -logname  Changes filename of the output log." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -i  Specification of a module input channel. Channel is described" << std::endl);
    MDS_CERR("      by a string of the form \"medium[:attrib1[:attrib2[...]]]\"." << std::endl);
    MDS_CERR("      Allowed medium types are \"stdio\", \"file\" and \"pipe\". Stdio has" << std::endl);
    MDS_CERR("      no attributes, file and pipe has only one attribute, filename." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -o  Module output. Channel description is same as above." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -raw  Disables output compression and suppresses data headers." << std::endl);

#ifdef MDS_USE_XML_SERIALIZER
    MDS_CERR(std::endl);
    MDS_CERR("  -xml  Experimental XML output." << std::endl);
#endif // MDS_USE_XML_SERIALIZER

    MDS_CERR(std::endl);
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
} // namespace mds

