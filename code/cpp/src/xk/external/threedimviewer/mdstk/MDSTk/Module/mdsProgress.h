//==============================================================================`
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2008 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2008/04/22                          \n
 *
 * $Id: mdsProgress.h 2091 2012-02-14 11:26:36Z spanel $
 *
 * Description:
 * - Simple mechanism which can be used to observe current
 *   state of a running operation.
 */

#ifndef MDS_Progress_H
#define MDS_Progress_H

#include <MDSTk/Base/mdsFunctor.h>
#include <MDSTk/Base/mdsGlobalLog.h>

#include "mdsModuleExport.h"


namespace mds
{
namespace mod
{

//=============================================================================
/*!
 * Base class for all other classes able to inform calling processes
 * about progress of a running operation.
 * - It also allows to cancel the operation.
 */
class MDS_MODULE_EXPORT CProgress
{
public:    
    //! Progress observer (= functor).
    //! - You may return false from the observer if you want to terminate
    //!   the running operation.
    //! - Parameters describe current and final state of the pending
    //!   operation (counter and maximal value).
    //! - If the second parameter is equal to -1, termination
    //!   time cannot be determined, the current state is unknown.
    typedef mds::base::CFunctor<bool, int, int> tProgressFunc;

public:
    //! Constructor.
    CProgress() : m_iCount(0), m_iMax(-1), m_ProgressFunc(CProgress::emptyHandler) {}
    
    //! Copy constructor.
    CProgress(const CProgress& p)
        : m_iCount(p.m_iCount)
        , m_iMax(p.m_iMax)
        , m_ProgressFunc(p.m_ProgressFunc)
    {}

    //! Destructor.
    ~CProgress() {}


    //! Sets observer/functor called to inform a calling process
    //! about the current state of the running operation.
    //! - This function should be called before any operation starts.
    void registerProgressFunc(const tProgressFunc& Func) { m_ProgressFunc = Func; }
    
    //! Sets the default empty observer.
    void deregisterProgressFunc() { m_ProgressFunc = tProgressFunc(CProgress::emptyHandler); }


    //! Returns the maximum allowed value of the internal progress counter.
    int getProgressMax() const { return m_iMax; }
       
    //! Sets the maximal counter value.
    void setProgressMax(int iValue) { m_iMax = iValue; }

    //! Returns current value of the internal progress value.
    int getProgressCount() const { return m_iCount; }


    //! This function must be called by the class realizing an operation
    //! before it starts.
    void beginProgress() { m_iCount = 0; }
    
    //! The function must be called by the class realizing an operation
    //! every time the operation finishes.
    //! - Sets the default observer.
    void endProgress() { deregisterProgressFunc(); }
    
    //! Calls the registered observer.
    //! - Returns false if the running operation should be terminated
    //!   as soon as possible.
    //! - It must be called periodically by the class realizing
    //!   the operation.
    bool progress(int iIncrement = 1)
    {
        m_iCount += iIncrement;
        return m_ProgressFunc(m_iCount, m_iMax);
    }

public:
    //! Helper class used to call methods beginProgress()
    //! and endProgress() automatically.
    struct CProgressInitializer
    {
        //! Default constructor that calls the beginProgress() method.
        CProgressInitializer(CProgress& p) : m_Obj(p)
        {
            m_Obj.beginProgress();
        }
        
        //! Destructor calls the endProgress() method.
        ~CProgressInitializer()
        {
            m_Obj.endProgress();
        }
        
        //! Stored reference to the progress class.
        CProgress& m_Obj;
        
        //! Empty assignment operator...
        void operator =(const CProgressInitializer&) {}
    };
    
    //! Helper class which can be used to call methods beginProgress()
    //! and endProgress() automatically. Create static object of this
    //! type at the begining of a method that realizes an operation.
    typedef CProgressInitializer tProgressInitializer;

private:
    //! Internal progress counter.
    int m_iCount;

    //! Maximal counter value.
    int m_iMax;

    //! Registered progress observer.
    tProgressFunc m_ProgressFunc;

private:
    //! Empty progress handler.
    static bool emptyHandler(int MDS_UNUSED(iCount), int MDS_UNUSED(iMax))
    {
        return true;
    }
};


} // namespace mod
} // namespace mds

#endif // MDS_Progress_H
