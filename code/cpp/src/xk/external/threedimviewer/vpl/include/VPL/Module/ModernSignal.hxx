//==============================================================================`
/* This file comes from MDSTk software and was modified for
 *
 * VPL - Voxel Processing Library
 * Changes are Copyright 2018 3Dim Laboratory s.r.o.
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
 * Authors: Ján Brída brida@t3d.team
 * Date:    2018/05/04
 *
 * Description:
 * - Simple signals and callback invocation mechanism exploiting C++11 features.
 */

#include <limits>
#include <vector>
#include <algorithm>

namespace vpl
{
namespace mod
{

//______________________________________________________________________________
inline SignalConnection::SignalConnection() :
    m_id{},
    m_signal{nullptr}
{
}

//______________________________________________________________________________
inline SignalConnection::SignalConnection(const SignalConnection& arg) :
    m_id{arg.m_id},
    m_signal{arg.m_signal}
{
}

//______________________________________________________________________________
inline SignalConnection::SignalConnection(const Id id, void* const signal) :
    m_id{id},
    m_signal{signal}
{
}

//______________________________________________________________________________
inline SignalConnection::~SignalConnection()
{
}

//______________________________________________________________________________
inline SignalConnection& SignalConnection::operator =(const SignalConnection& rhs)
{
    m_id = rhs.m_id;
    m_signal = rhs.m_signal;

    return *this;
}

//______________________________________________________________________________
inline SignalConnection::Id SignalConnection::getConnectionId() const
{
    return m_id;
}

//______________________________________________________________________________
inline void* SignalConnection::getSignalPtr()
{
    return m_signal;
}

//______________________________________________________________________________
inline const void* SignalConnection::getSignalPtr() const
{
    return m_signal;
}

//______________________________________________________________________________
template <typename R, typename... Ts>
inline Signal<R (Ts...)>::Signal() :
    m_counter{std::numeric_limits<SignalConnection::Id>::min()},
    m_tempCounter{0},
    m_connections{},
    m_queueModifications{0},
    m_newConnects{},
    m_newDisconnects{}
{
}

//______________________________________________________________________________
template <typename R, typename... Ts>
inline Signal<R (Ts...)>::Signal(const Signal& arg) :
    m_counter{arg.m_counter},
    m_tempCounter{arg.m_tempCounter},
    m_connections{arg.m_connections},
    m_queueModifications{arg.m_queueModifications},
    m_newConnects{arg.m_newConnects},
    m_newDisconnects{arg.m_newDisconnects}
{
}

//______________________________________________________________________________
template <typename R, typename... Ts>
inline Signal<R (Ts...)>::~Signal()
{
}

//______________________________________________________________________________
template <typename R, typename... Ts>
inline Signal<R (Ts...)>& Signal<R (Ts...)>::operator =(const Signal& rhs)
{
    m_counter = rhs.m_counter;
    m_tempCounter = rhs.m_tempCounter;
    m_connections = rhs.m_connections;
    m_queueModifications = rhs.m_queueModifications;
    m_newConnects = rhs.m_newConnects;
    m_newDisconnects = rhs.m_newDisconnects;

    return *this;
}

//______________________________________________________________________________
template <typename R, typename... Ts>
SignalConnection Signal<R (Ts...)>::operator +=(const Function& callback)
{
    return connect(callback);
}

//______________________________________________________________________________
template <typename R, typename... Ts>
SignalConnection Signal<R (Ts...)>::operator +=(const Slot& slot)
{
    return connect(slot, 0);
}

//______________________________________________________________________________
template <typename R, typename... Ts>
Signal<R (Ts...)>& Signal<R (Ts...)>::operator -=(const SignalConnection& connection)
{
    disconnect(connection);

    return *this;
}

//______________________________________________________________________________
template <typename R, typename... Ts>
template <typename T>
Signal<R (Ts...)>& Signal<R (Ts...)>::operator -=(const T* const receiver)
{
    disconnect(receiver);

    return *this;
}

//______________________________________________________________________________
template <typename R, typename... Ts>
template <typename U>
typename std::enable_if_t<!std::is_void<U>::value, U>
Signal<R (Ts...)>::operator ()(Ts... args) const
{
    static_assert(std::is_default_constructible<R>::value,
                  "The return type R must be default-constructible!");

    Signal& self = const_cast<Signal&>(*this);
    Lock lock{self};

    R ret{};

    self.prepareModifications();
    for (const Connection& c : m_connections)
    {
        if (!c.blocked && !c.disconnected)
        {
            ret = c.slot.callback(std::forward<Ts>(args)...);
        }
    }
    self.handleModifications();

    return ret;
}

//______________________________________________________________________________
template <typename R, typename... Ts>
template <typename U>
typename std::enable_if_t<std::is_void<U>::value>
Signal<R (Ts...)>::operator ()(Ts... args) const
{
    Signal& self = const_cast<Signal&>(*this);
    Lock lock{self};

    self.prepareModifications();
    for (const Connection& c : m_connections)
    {
        if (!c.blocked && !c.disconnected)
        {
            c.slot.callback(std::forward<Ts>(args)...);
        }
    }
    self.handleModifications();
}

//______________________________________________________________________________
template <typename R, typename... Ts>
template <typename A>
R Signal<R (Ts...)>::operator ()(Ts... args, A agg) const
{
    static_assert(!std::is_void<R>(), "Return type R cannot be void");

    Signal& self = const_cast<Signal&>(*this);
    Lock lock{self};

	std::vector<R> results;

    self.prepareModifications();
    for (const Connection& c : m_connections)
    {
        if (!c.blocked && !c.disconnected)
        {
            results.push_back(c.slot.callback(std::forward<Ts>(args)...));
        }
    }
    self.handleModifications();

	return agg(std::move(results));
}

//______________________________________________________________________________
template <typename R, typename... Ts>
inline SignalConnection Signal<R (Ts...)>::connect(const Function& slot,
                                                   const unsigned priority)
{
    return connect(Slot{slot}, priority);
}

//______________________________________________________________________________
template <typename R, typename... Ts>
template <typename T>
inline SignalConnection Signal<R (Ts...)>::connect(T* const receiver,
                                                   R (T::*slot)(Ts...),
                                                   const unsigned priority)
{
	return connect(signal::makeSlot(receiver, slot), priority);
}

//______________________________________________________________________________
template <typename R, typename... Ts>
template <typename T>
inline SignalConnection Signal<R (Ts...)>::connect(const T* const receiver,
                                                   R (T::*slot)(Ts...) const,
                                                   const unsigned priority)
{
	return connect(signal::makeSlot(receiver, slot), priority);
}

//______________________________________________________________________________
template <typename R, typename... Ts>
inline SignalConnection Signal<R (Ts...)>::connect(const vpl::base::Functor<R (Ts...)>& functor,
                                                   const unsigned priority)
{
    return connect(functor.getImpl(), priority);
}

//______________________________________________________________________________
template <typename R, typename... Ts>
inline void Signal<R (Ts...)>::disconnectAll()
{
    Lock lock{*this};

    if (m_queueModifications)
    {
        for (typename Connections::iterator it = m_connections.begin(); it != m_connections.end(); ++it)
        {
            it->blocked = true;
            it->disconnected = true;
            m_newDisconnects.push({it->id, this});
        }
    }
    else
    {
        m_connections.clear();
    }
}

//______________________________________________________________________________
template <typename R, typename... Ts>
inline bool Signal<R (Ts...)>::disconnect(const SignalConnection& connection)
{
    bool disconnected = false;

    if (connection.getSignalPtr() == this)
    {
        Lock lock{*this};

        for (typename Connections::iterator it = m_connections.begin();
             it != m_connections.end();)
        {
            if (it->id == connection.getConnectionId())
            {
                if (m_queueModifications && !it->disconnected)
                {
                    it->blocked = true;
                    it->disconnected = true;
                    m_newDisconnects.push(connection);
                    ++it;
                }
                else if (!m_queueModifications && !it->disconnected)
                {
                    it = m_connections.erase(it);
                }
                disconnected = true; // it is already in the m_newDisconnects queue
                break;
            }
            else
            {
                ++it;
            }
        }
    }

    return disconnected;
}

//______________________________________________________________________________
template <typename R, typename... Ts>
template <typename T>
inline std::vector<SignalConnection> Signal<R (Ts...)>::disconnect(const T* const receiver)
{
    std::vector<SignalConnection> disconnected;

    if (receiver) // let's not do this with nullptr
    {
        Lock lock{*this};

        for (typename Connections::iterator it = m_connections.begin();
             it != m_connections.end();)
        {
            if (it->slot.receiver == receiver)
            {
                if (m_queueModifications && !it->disconnected)
                {
                    disconnected.push_back({it->id, this});
                    it->blocked = true;
                    it->disconnected = true;
                    m_newDisconnects.push({it->id, this});
                    ++it;
                }
                else if (!m_queueModifications && !it->disconnected)
                {
                    disconnected.push_back({it->id, this});
                    it = m_connections.erase(it);
                }
                else
                {
                    ++it;
                }
            }
            else
            {
                ++it;
            }
        }
    }

    return disconnected;
}

//______________________________________________________________________________
template <typename R, typename... Ts>
inline void Signal<R (Ts...)>::blockAll()
{
    Lock lock{*this};

    for (Connection& c : m_connections)
    {
        c.blocked = true;
    }
}

//______________________________________________________________________________
template <typename R, typename... Ts>
inline void Signal<R (Ts...)>::block(const SignalConnection& connection)
{
    if (connection.getSignalPtr() == this)
    {
        Lock lock{*this};

        for (Connection& c : m_connections)
        {
            if (c.id == connection.getConnectionId())
            {
                c.blocked = true;
                break;
            }
        }
    }
}

//______________________________________________________________________________
template <typename R, typename... Ts>
inline void Signal<R (Ts...)>::block(const void* const receiver)
{
    if (receiver) // let's not do this with nullptr
    {
        Lock lock{*this};

        for (Connection& c : m_connections)
        {
            if (c.slot.receiver == receiver)
            {
                c.blocked = true;
            }
        }
    }
}

//______________________________________________________________________________
template <typename R, typename... Ts>
inline void Signal<R (Ts...)>::blockAllButThis(const SignalConnection& connection)
{
    if (connection.getSignalPtr() == this)
    {
        Lock lock{*this};

        for (const Connection& c : m_connections)
        {
            if (c.id != connection.getConnectionId())
            {
                c.blocked = true;
            }
        }
    }
}

//______________________________________________________________________________
template <typename R, typename... Ts>
inline void Signal<R (Ts...)>::unblockAll()
{
    Lock lock{*this};

    for (Connection& c : m_connections)
    {
        if (!c.disconnected)
        {
            c.blocked = false;
        }
    }
}

//______________________________________________________________________________
template <typename R, typename... Ts>
inline void Signal<R (Ts...)>::unblock(const SignalConnection& connection)
{
    if (connection.getSignalPtr() == this)
    {
        Lock lock{*this};

        for (Connection& c : m_connections)
        {
            if (c.id == connection.getConnectionId() && !c.disconnected)
            {
                c.blocked = false;
                break;
            }
        }
    }
}

//______________________________________________________________________________
template <typename R, typename... Ts>
inline void Signal<R (Ts...)>::unblock(const void* const receiver)
{
    if (receiver) // let's not do this with nullptr
    {
        Lock lock{*this};

        for (Connection& c : m_connections)
        {
            if (c.slot.receiver == receiver && !c.disconnected)
            {
                c.blocked = false;
            }
        }
    }
}

//______________________________________________________________________________
template <typename R, typename... Ts>
bool Signal<R (Ts...)>::isBlocked(const SignalConnection& connection) const
{
    bool isBlocked = false;

    if (connection.getSignalPtr() == this)
    {
        Lock lock{*this};

        for (Connection& c : m_connections)
        {
            if (c.id == connection.getConnectionId())
            {
                isBlocked = c.blocked;
                break;
            }
        }
    }

    return isBlocked;
}

//______________________________________________________________________________
template <typename R, typename... Ts>
size_t Signal<R (Ts...)>::getNumOfConnections() const
{
    return m_connections.size();
}

//______________________________________________________________________________
template <typename R, typename... Ts>
unsigned Signal<R (Ts...)>::getHighestPriority() const
{
    unsigned priority = 0;

    if (!m_connections.empty())
    {
        priority = m_connections.front().priority;
    }

    return priority;
}

//______________________________________________________________________________
template <typename R, typename... Ts>
SignalConnection Signal<R (Ts...)>::connect(const Slot& slot,
                                            const unsigned priority)
{
    Lock lock{*this};

    SignalConnection id{};
    if (!m_queueModifications)
    {
        const Connection connection{m_counter++, slot, false, false, priority};
        auto it = std::upper_bound(
            m_connections.begin(),
            m_connections.end(),
            connection,
            [] (const Connection& a, const Connection& b)
            {
                return a.priority > b.priority;
            }
        );

        id = {m_connections.insert(it, connection)->id, this};
    }
    else
    {
        id = {m_tempCounter++, this};
        m_newConnects.push({slot, priority});
    }

    return id;
}

//______________________________________________________________________________
template <typename R, typename... Ts>
void Signal<R (Ts...)>::prepareModifications()
{
    if (!m_queueModifications++)
    {
        m_tempCounter = m_counter;
    }
}

//______________________________________________________________________________
template <typename R, typename... Ts>
void Signal<R (Ts...)>::handleModifications()
{
    if (m_queueModifications && !--m_queueModifications)
    {
        while (!m_newConnects.empty())
        {
            const std::pair<Slot, unsigned>& c = m_newConnects.front();
            connect(c.first, c.second);
            m_newConnects.pop();
        }
        while (!m_newDisconnects.empty())
        {
            disconnect(m_newDisconnects.front());
            m_newDisconnects.pop();
        }
    }
}

namespace signal
{

//______________________________________________________________________________
template <typename T, typename R, typename... Ts>
typename Signal<R (Ts...)>::Slot makeSlot(T* const receiver,
                                          R (T::*slot)(Ts...))
{
    return {[receiver = receiver, slot = slot] (Ts... args) -> R
            { return static_cast<R>((receiver->*slot)(args...)); },
            receiver};
}

//______________________________________________________________________________
template <typename T, typename R, typename... Ts>
typename Signal<R (Ts...)>::Slot makeSlot(const T* const receiver,
                                          R (T::*slot)(Ts...) const)
{
    return {[receiver = receiver, slot = slot] (Ts... args) -> R
            { return static_cast<R>((receiver->*slot)(args...)); },
            receiver};
}

}// namespace signal

//______________________________________________________________________________
template <typename R, typename... Ts>
inline SignalWrapper<R, Ts...>::SignalWrapper() : Signal<R (Ts...)>{}
{
}

//______________________________________________________________________________
template <typename R, typename... Ts>
inline SignalWrapper<R, Ts...>::SignalWrapper(const SignalWrapper& arg) :
                                              Signal<R (Ts...)>{arg}
{
}

//______________________________________________________________________________
template <typename R, typename... Ts>
inline SignalWrapper<R, Ts...>::~SignalWrapper()
{
}

//______________________________________________________________________________
template <typename R, typename... Ts>
SignalWrapper<R, Ts...>& SignalWrapper<R, Ts...>::operator =(SignalWrapper& rhs)
{
    Signal<R (Ts...)>::operator =(rhs);

    return *this;
}

//______________________________________________________________________________
template <typename R, typename... Ts>
inline void SignalWrapper<R, Ts...>::invoke(Ts... args)
{
    Signal<R (Ts...)>::operator ()(args...);
}

//______________________________________________________________________________
template <typename R, typename... Ts>
R SignalWrapper<R, Ts...>::invoke2(Ts... args)
{
    return Signal<R (Ts...)>::operator ()(args...);
}

//______________________________________________________________________________
template <typename R, typename... Ts>
template <typename T>
SignalConnection SignalWrapper<R, Ts...>::connect(T& receiver,
                                                  R (T::*slot)(Ts...),
                                                  const unsigned priority)
{
    return connect(&receiver, slot, priority);
}

//______________________________________________________________________________
template <typename R, typename... Ts>
template <typename T>
SignalConnection SignalWrapper<R, Ts...>::connect(const T& receiver,
                                                  R (T::*slot)(Ts...) const,
                                                  const unsigned priority)
{
    return connect(&receiver, slot, priority);
}

//______________________________________________________________________________
template <typename R, typename... Ts>
SignalConnection SignalWrapper<R, Ts...>::connect(const vpl::base::FunctorWrapper<R, Ts...>& functor,
                                                  const unsigned priority)
{
    return connect(functor.getImpl(), priority);
}

}// namespace mod
}// namespace vpl
