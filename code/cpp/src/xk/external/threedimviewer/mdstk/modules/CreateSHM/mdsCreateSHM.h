//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/04/07                          \n
 *
 * $Id: mdsCreateSHM.h 1927 2010-11-07 10:49:52Z spanel $
 *
 * File description:
 * - Console utility allocates a new shared memory block.
 * - Only for testing!
 */

#ifndef MDS_CREATESHM_H
#define MDS_CREATESHM_H

#include <MDSTk/Module/mdsConsole.h>
#include <MDSTk/System/mdsSharedMem.h>
#include <MDSTk/System/mdsSemaphore.h>


//==============================================================================
/*!
 * This console utility allocates a new named shared memory block
 * of a specified size. The utility must be running in the background
 * in order to use shared memory channel.
 */
class CCreateSHM : public mds::mod::CConsole
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    MDS_SHAREDPTR(CCreateSHM);

public:
    //! Default constructor.
    CCreateSHM(const std::string& sDescription);

    //! Virtual destructor.
    virtual ~CCreateSHM();

protected:
    //! Virtual method called on startup.
    virtual bool startup();

    //! Virtual method called by the processing thread.
    virtual bool main();

    //! Called on console shutdown.
    virtual void shutdown();

    //! Called on writing a usage statement.
    virtual void writeExtendedUsage(std::ostream& Stream);

protected:
    //! Module parameters.
    std::string m_ssName;
    int m_iSize;

    //! Pointer to the shared memory
    mds::sys::CSemaphore *m_pSemaphore;

    //! Pointer to the shared memory
    mds::sys::CSharedMem *m_pSharedMem;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CCreateSHM::tSmartPtr   CCreateSHMPtr;


#endif // MDS_CREATESHM_H

