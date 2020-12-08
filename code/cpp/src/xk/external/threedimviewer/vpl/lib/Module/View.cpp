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
 * Author:  Michal Spanel, spanel@fit.vutbr.cz
 * Date:    2003/12/21                       
 *
 * Description:
 * - Definition of a simple GLUT application used for an input visualization.
 */

#include <VPL/Module/View.h>

#include <VPL/Base/Assert.h>
#include <VPL/Base/Version.h>
#include <VPL/Base/BuildDate.h>
#include <VPL/System/Sleep.h>

// STL
#include <stdexcept>


namespace vpl
{
namespace mod
{

//==============================================================================
/*
 * Implementation of the class vpl::mod::CView.
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

    // Everything is OK so return true
    return true;
}


void CView::printUsage()
{
    std::cerr << LABEL << '-' << VERSION << ": " << m_sDescription << std::endl;
    std::cerr << "Usage: " << m_sFilename << " [-h] [-log sLog] [-logname sFilename] [-i sChannel(s)]" << std::endl;
}


void CView::printFullUsage()
{
    printUsage();

    std::cerr << "Options:" << std::endl;
    std::cerr << "  -h Shows this help." << std::endl;
    std::cerr << std::endl;
    std::cerr << "  -log Option selects a log type. Allowed values are:" << std::endl;
    std::cerr << "         " << console::LOG_NULL << " for no logging," << std::endl;
    std::cerr << "         " << console::LOG_STDERR << ',' << std::endl;
    std::cerr << "         " << console::LOG_FILE << " and" << std::endl;
    std::cerr << "         " << console::LOG_BOTH << '.' << std::endl;
    std::cerr << "        Default value is " << console::DEFAULT_LOG << '.' << std::endl;
    std::cerr << std::endl;
    std::cerr << "  -logname  Changes filename of the output log." << std::endl;
    std::cerr << std::endl;
    std::cerr << "  -i Specification of a module input channel. Channel is described" << std::endl;
    std::cerr << "     by a string of the form \"medium[:attrib1[:attrib2[...]]]\"." << std::endl;
    std::cerr << "     Allowed medium types are \"stdio\", \"file\" and \"pipe\". Stdio has" << std::endl;
    std::cerr << "     no attributes, file and pipe has only one attribute, filename." << std::endl;

    std::cerr << std::endl;
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
} // namespace vpl

