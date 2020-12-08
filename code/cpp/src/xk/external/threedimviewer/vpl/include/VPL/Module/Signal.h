//==============================================================================`
/* This file comes from MDSTk software and was modified for
 *
 * VPL - Voxel Processing Library
 * Changes are Copyright 2017 3Dim Laboratory s.r.o.
 * All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 *
 * The original MDSTk legal notice can be found below.
 *
 * Medical Data Segmentation Toolkit (MDSTk) 
 * Copyright (c) 2003-2008 by PGMed          
 *
 * Authors: Premysl Krsek, krsek@fit.vutbr.cz
 *          Michal Spanel, spanel@fit.vutbr.cz  \n
 *          Vit Stancl, stancl@fit.vutbr.cz  
 * Date:    2008/02/25                       
 *
 * Description:
 * - Simple signals and callback invocation mechanism.
 * - The concept was partially inspired with the Boost library.
 */

#ifndef VPL_Signal_H
#define VPL_Signal_H

#include <VPL/Base/SharedPtr.h>
#include <VPL/Base/TypeTraits.h>
#include <VPL/Base/Functor.h>
#include <VPL/Base/Lock.h>
#include <VPL/Base/StaticAssert.h>

// STL
#include <map>


namespace vpl
{
namespace mod
{

//=============================================================================
/*!
 * Unique signal connection identifier.
 */
class CSignalConnection
{
public:
    //! Signal-unique connection identifier.
    typedef int tConnectionId;

public:
    //! Default constructor.
    CSignalConnection() : m_pSignal(NULL) {}

    //! Constructor.
    CSignalConnection(void *pSignal, tConnectionId Id)
        : m_pSignal(pSignal)
        , m_ConnectionId(Id)
    {}

    //! Copy constructor.
    CSignalConnection(const CSignalConnection& sc)
        : m_pSignal(sc.m_pSignal)
        , m_ConnectionId(sc.m_ConnectionId)
    {}

    //! Assignment operator.
    CSignalConnection& operator= (const CSignalConnection& sc)
    {
        m_pSignal = sc.m_pSignal;
        m_ConnectionId = sc.m_ConnectionId;
        return *this;
    }

    //! Returns pointer to the signal.
    void *getSignalPtr() const { return m_pSignal; }

    //! Returns unique connection number.
    tConnectionId getConnectionId() const { return m_ConnectionId; }

protected:
    //! Pointer to the signal object.
    void *m_pSignal;

    //! Connection identifier.
    tConnectionId m_ConnectionId;
};

//! Unique signal connection identifier.
typedef CSignalConnection tSignalConnection;


//=============================================================================
/*!
 * Class provides simple communication and data transfer mechanism
 * between different classes. It encapsulates a group of registered handlers,
 * which are invoked when the signal is sent.
 * - Up to four arguments allowed.
 */
template <typename R,
          typename P1 = tNull, typename P2 = tNull,
          typename P3 = tNull, typename P4 = tNull
          >
class CSignal
    : public vpl::base::CObject
    , public vpl::base::CLibraryLockableObject<CSignal<R, P1, P2, P3, P4> >
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    VPL_SHAREDPTR(CSignal);

    //! Handler type.
    typedef vpl::base::CFunctor<R, P1, P2, P3, P4> tHandler;

    //! Handler parameters.
    typedef typename tHandler::tResult tResult;
    typedef typename tHandler::tParam1 tParam1;
    typedef typename tHandler::tParam2 tParam2;
    typedef typename tHandler::tParam3 tParam3;
    typedef typename tHandler::tParam4 tParam4;

    //! Number of handler parameters.
    enum { NUM_OF_PARAMS = tHandler::NUM_OF_PARAMS };

    //! Lock that may be used to provide mutual access.
    typedef typename vpl::base::CLibraryLockableObject<CSignal>::CLock tLock;

public:
    //! Default constructor.
    CSignal() : m_NextId(0) {}

    //! Destructor of the class.
    ~CSignal() {}


    //! Registers a new signal handler.
    //! - Returns unique connection identifier.
    tSignalConnection connect(const tHandler& handler);

    //! Registers a new signal handler.
    //! - Returns unique connection identifier.
    //! - Parameter F is a function type.
    template <typename F>
    tSignalConnection connect(F Func);

    //! Constructor creates functor encapsulating pointer to member function.
    //! - Parameter O is pointer to an object.
    //! - M is pointer to the object member function.
    template <class O, typename F>
    tSignalConnection connect(const O& pObject, F pMemFunc);

    //! Returns the number of registered handlers.
    int getNumOfConnections() { return int(m_Handlers.size()); }

    //! Unregisters an existing signal handler.
    void disconnect(tSignalConnection& sc);

    //! Unregisters all existing signal handlers.
    void disconnectAll();

    //! Blocks a given signal handler.
    void block(tSignalConnection& sc);

    //! Unblocks a given signal handler.
    void unblock(tSignalConnection& sc);

    //! Returns true if a given signal is blocked.
    bool isBlocked(tSignalConnection& sc);

    //! Blocks all others signal handlers.
    void blockAllButThis(tSignalConnection& sc);

    //! Unblocks all signal handlers.
    void unblockAll();


    //! Invokes the signal.
    //! - Use method with appropriate number of parameters!
    void invoke();
    void invoke(tParam1 p1);
    void invoke(tParam1 p1, tParam2 p2);
    void invoke(tParam1 p1, tParam2 p2, tParam3 p3);
    void invoke(tParam1 p1, tParam2 p2, tParam3 p3, tParam4 p4);

    //! Invokes the signal and returns value obtained by combining
    //! all values returned by individual handlers.
    //! - Use method with appropriate number of parameters!
    //! - Allowed only for non-void return types!
    tResult invoke2();
    tResult invoke2(tParam1 p1);
    tResult invoke2(tParam1 p1, tParam2 p2);
    tResult invoke2(tParam1 p1, tParam2 p2, tParam3 p3);
    tResult invoke2(tParam1 p1, tParam2 p2, tParam3 p3, tParam4 p4);

protected:
    //! Connection identifier.
    typedef CSignalConnection::tConnectionId tConnectionId;

    //! Helper structure containing info about signal handler.
    struct SHandlerInfo
    {
        //! Registered handler.
        tHandler m_Handler;

        //! Is the signal is blocked?
        bool m_bBlocked;

        //! Default constructor.
        SHandlerInfo() : m_bBlocked(false) {}

        //! Constructor
        SHandlerInfo(const tHandler& Handler)
            : m_Handler(Handler)
            , m_bBlocked(false)
        {}

        //! Copy constructor.
        SHandlerInfo(const SHandlerInfo& Info)
            : m_Handler(Info.m_Handler)
            , m_bBlocked(Info.m_bBlocked)
        {}
    };

    //! Map of registered signal handlers.
    typedef std::map<tConnectionId, SHandlerInfo> tHandlers;

protected:
    //! All registered signal handlers.
    tHandlers m_Handlers;

    //! Next free connection identifier.
    tConnectionId m_NextId;

protected:
    //! Creates a new unique connection number.
    tConnectionId getUniqueId()
    {
        return ++m_NextId;
    }

private:
    //! Private copy constructor.
    CSignal(const CSignal&);

    //! Private assignment operator.
    CSignal& operator=(const CSignal&);
};


//=============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates.
#include "Signal.hxx"


} // namespace mod
} // namespace vpl

#endif // VPL_Signal_H
