//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2009 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2009/03/30                          \n
 *
 * $Id: mdsUserThread.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Thread control.
 */

#ifndef MDS_UserThread_H
#define MDS_UserThread_H

#include "mdsThread.h"


namespace mds
{
namespace sys
{

//==============================================================================
/*!
 * Thread encapsulation. Internal thread routine calls a virtual method
 * that may be overloaded.
 */
class MDS_SYSTEM_EXPORT CUserThread : public CThread
{
public:
    //! Smart pointer type.
    MDS_SHAREDPTR(CUserThread);

public:
    //! Default constructor.
    CUserThread(void *pData = NULL, bool bRun = true);

    //! Virtual destructor.
    virtual ~CUserThread();

    //! Entry point of the thread. This function is pure virtual and must
    //! be implemented by any derived class. The thread execution
    //! is going to start here.
    //! - Please, call the method isExitSignalled() periodically to check
    //!   if the function should be terminated, or use the MDS_THREAD_MAIN_LOOP macro
    //!   to implement this behaviour.
    //! - Returned value can be checked further.
    virtual int entry() = 0;

protected:
    //! Real thread routine.
    static MDS_THREAD_ROUTINE(threadRoutine);

private:
    //! Private copy constructor.
    CUserThread(const CUserThread&);

    //! Private assignment operator.
    void operator=(const CUserThread&);
};


//==============================================================================
/*!
 * Smart pointer to the user thread.
 */
typedef CUserThread::tSmartPtr  CUserThreadPtr;


} // namespace sys
} // namespace mds

#endif // MDS_UserThread_H

