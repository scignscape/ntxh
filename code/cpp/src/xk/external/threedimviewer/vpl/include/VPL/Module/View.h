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
 * Date:    2003/12/21                       
 *
 * Description:
 * - Definition of a simple GLUT application used for an input visualization.
 */

#ifndef VPL_VIEW_H
#define VPL_VIEW_H

#include "Console.h"
#include "Argv.h"
#include "Channel.h"
#include "Serializer.h"
#include "Serialization.h"

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

//! Namespace containing constants used by the CView class.
namespace view
{

//! Command line arguments.
const std::string ARGUMENT_INPUT    = "i";

} // namespace view


//==============================================================================
/*!
 * The class encapsulating input and visualization functions.
 * - Also supports log files and logging.
 * - Command line parsing.
 * - Input channels.
 */
class VPL_MODULE_EXPORT CView : public vpl::mod::CConsole
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    VPL_SHAREDPTR(CView);

public:
    //! Default constructor.
    CView(const std::string& sDescription);

    //! Virtual destructor.
    virtual ~CView();


    //! Initializes application and parses a given command line.
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


    //! Reads a data entity from the input channel.
    //! - Returns true on success.
    template <typename T>
    bool readInput(CChannel *pChannel, T *pObject);


    //! Virtual method called on startup.
    //! - Expected to be overriden.
    //! - Has to return false on startup failure.
    virtual bool startup() = 0;

    //! Virtual method called by the processing thread.
    virtual bool main() = 0;

    //! Called on console shutdown.
    virtual void shutdown() = 0;

    //! Called on writing a usage statement.
    virtual void writeExtendedUsage(std::ostream& Stream) = 0;

protected:
    //! Vector of i/o channels.
    typedef std::vector<CChannelPtr> tChannels;

protected:
    //! Application input channels.
    tChannels m_InputChannels;
};


//==============================================================================
/*!
 * Smart pointer to view.
 */
typedef CView::tSmartPtr    CViewPtr;


//==============================================================================
/*
 * Implementation...
 */

template <typename T>
bool CView::readInput(CChannel *pChannel, T *pObject)
{
    VPL_CHECK(pChannel && pObject, return false);

    return read(*pObject, *pChannel);
}


} // namespace mod
} // namespace vpl

#endif // VPL_VIEW_H

