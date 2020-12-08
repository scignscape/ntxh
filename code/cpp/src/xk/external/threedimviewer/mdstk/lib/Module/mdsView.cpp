//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/12/21                          \n
 *
 * $Id: mdsView.cpp 2065 2012-02-02 23:29:38Z spanel $
 *
 * Description:
 * - Definition of a simple GLUT application used for an input visualization.
 */

#include <MDSTk/Module/mdsView.h>

#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Base/mdsVersion.h>
#include <MDSTk/Base/mdsBuildDate.h>
#include <MDSTk/System/mdsSleep.h>

// STL
#include <stdexcept>


namespace mds
{
namespace mod
{

//==============================================================================
/*
 * Implementation of the class mds::mod::CView.
 */
CView::CView(const std::string& sDescription)
    : CConsole(sDescription)
{
    // Initialize default console arguments
    allowArguments("i");
}


CView::~CView()
{
    // Input channels
    m_InputChannels.clear();
}


bool CView::init(int argc, char *argv[])
{
    // Init console
    if( !CConsole::init(argc, argv) )
    {
        return false;
    }

    // Temporary variables
    std::string sDesc;
    std::vector<std::string> Descs;

    // Creation of input channels
    if( m_Arguments.exists(view::ARGUMENT_INPUT) )
    {
        m_Arguments.value(view::ARGUMENT_INPUT, sDesc);
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
//            if( !pChannel->connect(CH_CONNECTION_TIMEOUT) )
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

    // Everything is OK so return true
    return true;
}


void CView::printUsage()
{
    MDS_CERR(LABEL << '-' << VERSION << ": " << m_sDescription << std::endl);
    MDS_CERR("Usage: " << m_sFilename << " [-h] [-log sLog] [-logname sFilename] [-i sChannel(s)]" << std::endl);
}


void CView::printFullUsage()
{
    printUsage();

    MDS_CERR("Options:" << std::endl);
    MDS_CERR("  -h Shows this help." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -log Option selects a log type. Allowed values are:" << std::endl);
    MDS_CERR("         " << console::LOG_NULL << " for no logging," << std::endl);
    MDS_CERR("         " << console::LOG_STDERR << ',' << std::endl);
    MDS_CERR("         " << console::LOG_FILE << " and" << std::endl);
    MDS_CERR("         " << console::LOG_BOTH << '.' << std::endl);
    MDS_CERR("        Default value is " << console::DEFAULT_LOG << '.' << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -logname  Changes filename of the output log." << std::endl);
    MDS_CERR(std::endl);
    MDS_CERR("  -i Specification of a module input channel. Channel is described" << std::endl);
    MDS_CERR("     by a string of the form \"medium[:attrib1[:attrib2[...]]]\"." << std::endl);
    MDS_CERR("     Allowed medium types are \"stdio\", \"file\" and \"pipe\". Stdio has" << std::endl);
    MDS_CERR("     no attributes, file and pipe has only one attribute, filename." << std::endl);

    MDS_CERR(std::endl);
    this->writeExtendedUsage(std::cerr);
}


CChannel *CView::getInput(int i)
{
    if( i >= getNumOfInputs() )
    {
        return NULL;
    }
    return m_InputChannels[i];
}


} // namespace mod
} // namespace mds

