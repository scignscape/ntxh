//==============================================================================`
/*/*! \file
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
 */


//=============================================================================
/*
 * Implementation of the class template CSignal<>.
 */

template <typename R, typename P1, typename P2, typename P3, typename P4>
tSignalConnection CSignal<R,P1,P2,P3,P4>::connect(const tHandler& handler)
{
    tLock Lock(*this);

    tSignalConnection NewConnection(this, getUniqueId());
    m_Handlers[NewConnection.getConnectionId()] = SHandlerInfo(handler);
    return NewConnection;
}


template <typename R, typename P1, typename P2, typename P3, typename P4>
template <typename F>
tSignalConnection CSignal<R,P1,P2,P3,P4>::connect(F Func)
{
    tLock Lock(*this);

    tSignalConnection NewConnection(this, getUniqueId());
    m_Handlers[NewConnection.getConnectionId()] = SHandlerInfo(tHandler(Func));
    return NewConnection;
}


template <typename R, typename P1, typename P2, typename P3, typename P4>
template <class O, typename F>
tSignalConnection CSignal<R,P1,P2,P3,P4>::connect(const O& pObject, F pMemFunc)
{
    tLock Lock(*this);

    tSignalConnection NewConnection(this, getUniqueId());
    m_Handlers[NewConnection.getConnectionId()] = SHandlerInfo(tHandler(pObject, pMemFunc));
    return NewConnection;
}


template <typename R, typename P1, typename P2, typename P3, typename P4>
void CSignal<R,P1,P2,P3,P4>::disconnect(tSignalConnection& sc)
{
    if( sc.getSignalPtr() != this )
    {
        return;
    }

    tLock Lock(*this);

    typename tHandlers::iterator it = m_Handlers.find(sc.getConnectionId());
    if( it != m_Handlers.end() )
    {
        m_Handlers.erase(it);
    }
}


template <typename R, typename P1, typename P2, typename P3, typename P4>
void CSignal<R,P1,P2,P3,P4>::block(tSignalConnection& sc)
{
    if( sc.getSignalPtr() != this )
    {
        return;
    }

    tLock Lock(*this);

    typename tHandlers::iterator it = m_Handlers.find(sc.getConnectionId());
    if( it != m_Handlers.end() )
    {
        it->second.m_bBlocked = true;
    }
}


template <typename R, typename P1, typename P2, typename P3, typename P4>
void CSignal<R,P1,P2,P3,P4>::unblock(tSignalConnection& sc)
{
    if( sc.getSignalPtr() != this )
    {
        return;
    }

    tLock Lock(*this);

    typename tHandlers::iterator it = m_Handlers.find(sc.getConnectionId());
    if( it != m_Handlers.end() )
    {
        it->second.m_bBlocked = false;
    }
}


template <typename R, typename P1, typename P2, typename P3, typename P4>
bool CSignal<R,P1,P2,P3,P4>::isBlocked(tSignalConnection& sc)
{
    if( sc.getSignalPtr() != this )
    {
        return false;
    }

    typename tHandlers::iterator it = m_Handlers.find(sc.getConnectionId());
    if( it != m_Handlers.end() )
    {
        return it->second.m_bBlocked;
    }
    
    return false;
}


template <typename R, typename P1, typename P2, typename P3, typename P4>
void CSignal<R,P1,P2,P3,P4>::blockAllButThis(tSignalConnection& sc)
{
    if( sc.getSignalPtr() != this )
    {
        return;
    }

    tLock Lock(*this);

    typename tHandlers::iterator it = m_Handlers.begin();
    typename tHandlers::iterator itEnd = m_Handlers.end();
    for( ; it != itEnd; ++it )
    {
        if( it->first != sc.getConnectionId() )
        {
            it->second.m_bBlocked = true;
        }
    }
}


template <typename R, typename P1, typename P2, typename P3, typename P4>
void CSignal<R,P1,P2,P3,P4>::unblockAll()
{
    tLock Lock(*this);

    typename tHandlers::iterator it = m_Handlers.begin();
    typename tHandlers::iterator itEnd = m_Handlers.end();
    for( ; it != itEnd; ++it )
    {
        it->second.m_bBlocked = false;
    }
}


template <typename R, typename P1, typename P2, typename P3, typename P4>
void CSignal<R,P1,P2,P3,P4>::disconnectAll()
{
    tLock Lock(*this);

    m_Handlers.clear();
}


#undef VPL_SIGNAL_PARAMS
#define VPL_SIGNAL_INVOKE \
    typename tHandlers::iterator it = m_Handlers.begin(); \
    typename tHandlers::iterator itEnd = m_Handlers.end(); \
    for( ; it != itEnd; ++it ) \
    { \
        if( !it->second.m_bBlocked ) \
        { \
            it->second.m_Handler(VPL_SIGNAL_PARAMS); \
        } \
    }


template <typename R, typename P1, typename P2, typename P3, typename P4>
void CSignal<R,P1,P2,P3,P4>::invoke()
{
    VPL_STATIC_ASSERT(NUM_OF_PARAMS == 0, Bad_number_of_signal_parameters);

    tLock Lock(*this);

    #undef VPL_SIGNAL_PARAMS
    #define VPL_SIGNAL_PARAMS

    VPL_SIGNAL_INVOKE;
}


template <typename R, typename P1, typename P2, typename P3, typename P4>
void CSignal<R,P1,P2,P3,P4>::invoke(tParam1 p1)
{
    VPL_STATIC_ASSERT(NUM_OF_PARAMS == 1, Bad_number_of_signal_parameters);

    tLock Lock(*this);

    #undef VPL_SIGNAL_PARAMS
    #define VPL_SIGNAL_PARAMS p1

    VPL_SIGNAL_INVOKE;
}


template <typename R, typename P1, typename P2, typename P3, typename P4>
void CSignal<R,P1,P2,P3,P4>::invoke(tParam1 p1, tParam2 p2)
{
    VPL_STATIC_ASSERT(NUM_OF_PARAMS == 2, Bad_number_of_signal_parameters);

    tLock Lock(*this);

    #undef VPL_SIGNAL_PARAMS
    #define VPL_SIGNAL_PARAMS p1, p2

    VPL_SIGNAL_INVOKE;
}


template <typename R, typename P1, typename P2, typename P3, typename P4>
void CSignal<R,P1,P2,P3,P4>::invoke(tParam1 p1, tParam2 p2, tParam3 p3)
{
    VPL_STATIC_ASSERT(NUM_OF_PARAMS == 3, Bad_number_of_signal_parameters);

    tLock Lock(*this);

    #undef VPL_SIGNAL_PARAMS
    #define VPL_SIGNAL_PARAMS p1, p2, p3

    VPL_SIGNAL_INVOKE;
}


template <typename R, typename P1, typename P2, typename P3, typename P4>
void CSignal<R,P1,P2,P3,P4>::invoke(tParam1 p1, tParam2 p2, tParam3 p3, tParam4 p4)
{
    VPL_STATIC_ASSERT(NUM_OF_PARAMS == 4, Bad_number_of_signal_parameters);

    tLock Lock(*this);

    #undef VPL_SIGNAL_PARAMS
    #define VPL_SIGNAL_PARAMS p1, p2, p3, p4

    VPL_SIGNAL_INVOKE;
}


/*template <typename T>
struct SCombiner
{
    T m_Value;

    SCombiner() : m_Value(T()) {}

    SCombiner& operator <<(T const& Value)
    {
        m_Value = Value;
        return *this;
    }

    T operator() { return m_Value; }
};*/


#undef VPL_SIGNAL_INVOKE
#define VPL_SIGNAL_INVOKE \
    tResult Result = tResult(); \
    typename tHandlers::iterator it = m_Handlers.begin(); \
    typename tHandlers::iterator itEnd = m_Handlers.end(); \
    for( ; it != itEnd; ++it ) \
    { \
        if( !it->second.m_bBlocked ) \
        { \
            Result = it->second.m_Handler(VPL_SIGNAL_PARAMS); \
        } \
    } \
    return Result


template <typename R, typename P1, typename P2, typename P3, typename P4>
typename CSignal<R,P1,P2,P3,P4>::tResult CSignal<R,P1,P2,P3,P4>::invoke2()
{
    VPL_STATIC_ASSERT(NUM_OF_PARAMS == 0, Bad_number_of_signal_parameters);

    tLock Lock(*this);

    #undef VPL_SIGNAL_PARAMS
    #define VPL_SIGNAL_PARAMS

    VPL_SIGNAL_INVOKE;
}


template <typename R, typename P1, typename P2, typename P3, typename P4>
typename CSignal<R,P1,P2,P3,P4>::tResult CSignal<R,P1,P2,P3,P4>::invoke2(tParam1 p1)
{
    VPL_STATIC_ASSERT(NUM_OF_PARAMS == 1, Bad_number_of_signal_parameters);

    tLock Lock(*this);

    #undef VPL_SIGNAL_PARAMS
    #define VPL_SIGNAL_PARAMS p1

    VPL_SIGNAL_INVOKE;
}


template <typename R, typename P1, typename P2, typename P3, typename P4>
typename CSignal<R,P1,P2,P3,P4>::tResult CSignal<R,P1,P2,P3,P4>::invoke2(tParam1 p1, tParam2 p2)
{
    VPL_STATIC_ASSERT(NUM_OF_PARAMS == 2, Bad_number_of_signal_parameters);

    tLock Lock(*this);

    #undef VPL_SIGNAL_PARAMS
    #define VPL_SIGNAL_PARAMS p1, p2

    VPL_SIGNAL_INVOKE;
}


template <typename R, typename P1, typename P2, typename P3, typename P4>
typename CSignal<R,P1,P2,P3,P4>::tResult CSignal<R,P1,P2,P3,P4>::invoke2(tParam1 p1, tParam2 p2, tParam3 p3)
{
    VPL_STATIC_ASSERT(NUM_OF_PARAMS == 3, Bad_number_of_signal_parameters);

    tLock Lock(*this);

    #undef VPL_SIGNAL_PARAMS
    #define VPL_SIGNAL_PARAMS p1, p2, p3

    VPL_SIGNAL_INVOKE;
}


template <typename R, typename P1, typename P2, typename P3, typename P4>
typename CSignal<R,P1,P2,P3,P4>::tResult CSignal<R,P1,P2,P3,P4>::invoke2(tParam1 p1, tParam2 p2, tParam3 p3, tParam4 p4)
{
    VPL_STATIC_ASSERT(NUM_OF_PARAMS == 4, Bad_number_of_signal_parameters);

    tLock Lock(*this);

    #undef VPL_SIGNAL_PARAMS
    #define VPL_SIGNAL_PARAMS p1, p2, p3, p4

    VPL_SIGNAL_INVOKE;
}


#undef VPL_SIGNAL_PARAMS
#undef VPL_SIGNAL_INVOKE
