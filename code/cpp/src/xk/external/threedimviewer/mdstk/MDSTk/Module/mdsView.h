//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/12/21                          \n
 *
 * $Id: mdsView.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Definition of a simple GLUT application used for an input visualization.
 */

#ifndef MDS_VIEW_H
#define MDS_VIEW_H

#include "mdsConsole.h"
#include "mdsArgv.h"
#include "mdsChannel.h"
#include "mdsSerializer.h"
#include "mdsSerialization.h"

// STL
#include <vector>


namespace mds
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
class MDS_MODULE_EXPORT CView : public mds::mod::CConsole
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    MDS_SHAREDPTR(CView);

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
    MDS_CHECK(pChannel && pObject, return false);

    return read(*pObject, *pChannel);
}


} // namespace mod
} // namespace mds

#endif // MDS_VIEW_H

