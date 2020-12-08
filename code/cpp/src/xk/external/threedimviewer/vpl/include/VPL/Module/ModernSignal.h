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

#ifndef VPL_MODERN_SIGNAL_H
#define VPL_MODERN_SIGNAL_H

#define VPL_SLOT(receiver, slot)\
vpl::mod::signal::makeSlot(receiver, slot)

#define VPL_SIGNALS
#define VPL_SLOTS

// std
#include <functional>
#include <type_traits>
#include <utility>
#include <vector>
#include <queue>

// VPL
#include <VPL/Base/Lock.h>
#include <VPL/Base/ModernFunctor.h>

namespace vpl
{
namespace mod
{

//! \brief Connection handle.
class SignalConnection final
{
public:
    using Id = int;

    //! \brief Default constructor.
    SignalConnection();

    //! \brief Copy constructor.
    //! \param[in] arg Argument.
    SignalConnection(const SignalConnection& arg);

    //! \brief Constructor.
    //! \param[in] id Connection ID.
    //! \param[in] signal Signal.
    SignalConnection(const Id id, void* const signal);

    //! \brief Destructor.
    ~SignalConnection();

    //! \brief Assignment operator.
    //! \param[in] rhs Right-hand side.
    //! \return Reference to this.
    SignalConnection& operator =(const SignalConnection& rhs);

    //! \brief Return the connection ID.
    //! \return Stored connection ID.
    Id getConnectionId() const;

    //! \brief Return the signal address pointer.
    //! \return Signal address pointer.
    void* getSignalPtr();

    //! \brief Return the signal address const pointer.
    //! \return Signal address const pointer.
    const void* getSignalPtr() const;

private:
    //! \brief Connection ID.
    Id m_id;

    //! \brief Signal.
    void* m_signal;
};

//! \brief Single parameter template class to allow "R (Ts...)" syntax.
template <typename>
class Signal;

//! \brief Specialize the #Signal class.
//!
//! Example usage:
//! vpl::mod::Signal<int (const int, const int)> add;
//!
//! SignalConnection h = add.connect(&foobar, &Foobar::addition)
//! //SignalConnection h = (add += VPL_SLOT(this, &Foobar::addition));
//!
//! int Foobar::addition(const int a, const int b)
//! {
//!     return a + b;
//! }
//!
//! add(1, 2); // emit the signal
//!
//! add.disconnect(h);
template <typename R, typename... Ts>
class Signal<R (Ts...)> : public vpl::base::CLibraryLockableObject<Signal<R (Ts...)>>
{
public:
    //! \brief Function object.
	using Function = std::function<R (Ts...)>;

    //! \brief Class holding an information about a signal-slot connection.
    struct Slot
    {
        //! \brief Slot.
        Function callback;

        //! \brief Receiver address.
        const void* receiver;
    };

    //! \brief Default constructor.
    Signal();

    //! \brief Copy constructor.
    //! \param[in] arg Original.
    Signal(const Signal& arg);

    //! \brief Destructor.
    ~Signal();

    //! \brief Assignment operator.
    //! \param[in] rhs Right-hand side.
    //! \return Reference to this.
    Signal& operator =(const Signal& rhs);

    //! \brief Connect a new slot to the signal.
    //! \param[in] callback Callback.
    //! \return Signal connection information.
    SignalConnection operator +=(const Function& callback);

    //! \brief Connect a new slot to the signal.
    //! \param[in] connection Connection.
    //! \return Signal connection information.
    SignalConnection operator +=(const Slot& slot);

    //! \brief Disconnect a connection.
    //! \param[in] connection Connection.
    //! \return Reference to this.
    Signal& operator -=(const SignalConnection& connection);

    //! \brief Disconnect all connections associated with \p receiver.
    //! \param[in] receiver Receiver (must not be null for the function to take effect).
    //! \return Reference to this.
    template <typename T>
    Signal& operator -=(const T* const receiver);

    //! \brief Emit operator.
    //! \details Uses SFINAE to enable the correct overload based on the return type.
    //!          In this case R must be default-constructible to handle a case when
    //!          all connections are being blocked.
    //! \param[in] args Arguments.
    //! \return The last connected (non-blocked) slot's return value is returned.
    //!         If all connections were blocked or none exist, a default-constructed value is returned.
    template <typename U = R>
    typename std::enable_if_t<!std::is_void<U>::value, U> operator ()(Ts... args) const;

    //! \brief Emit operator.
    //! \details Uses SFINAE to enable the correct overload based on the return type.
    //! \param[in] args Arguments.
    template <typename U = R>
    typename std::enable_if_t<std::is_void<U>::value> operator ()(Ts... args) const;

    //! \brief Emit operator with aggregate functor to process all return values.
    //! \details Aggregate functor must overload its "R operator() (std::vector<R>& results)".
    //!          Aggregate functor can therefore also be a lambda.
    //! \param[in] args Arguments.
    //! \return Result of the aggregate function.
	template <typename A>
	R operator ()(Ts... args, A agg) const;

    //! \brief Connect a non-member function.
    //!        This can be a lambda or a functor as well.
    //! \param[in] slot Slot.
    //! \return Connection ID.
	SignalConnection connect(const Function& slot,
                             const unsigned priority = 0);

    //! \brief Connect a non-const member function.
    //! \param[in] receiver Receiver.
    //! \param[in] slot Slot.
    //! \return Connection ID.
	template <typename T>
	SignalConnection connect(T* const receiver,
                             R (T::*slot)(Ts...),
                             const unsigned priority = 0);

    //! \brief Connect a const member function.
    //! \param[in] receiver Receiver.
    //! \param[in] slot Slot.
    //! \return Connection ID.
	template <typename T>
	SignalConnection connect(const T* const receiver,
                             R (T::*slot)(Ts...) const,
                             const unsigned priority = 0);

    //! \brief Connect a VPL functor.
    //! \param[in] functor Functor.
    //! \return Connection ID.
    SignalConnection connect(const vpl::base::Functor<R (Ts...)>& functor,
                             const unsigned priority = 0);

    //! \brief Disconnect all connections.
	void disconnectAll();

    //! \brief Disconnect a slot.
    //! \details If the connection ID is non-existent or the signal pointer does not match, nothing happens.
    //! \param[in] connection Connection.
	bool disconnect(const SignalConnection& connection);

    //! \brief Disconnect all slots with the receiver \p receiver.
    //!
    //! \param[in] receiver Receiver.
    template <typename T>
	std::vector<SignalConnection> disconnect(const T* const receiver);

    //! \brief Block all connections.
    void blockAll();

    //! \brief Block a connection.
    //! \details If the connection ID is non-existent or the signal pointer does not match, nothing happens.
    //! \param[in] connection Connection.
    void block(const SignalConnection& connection);

    //! \brief Block all connections with on the receiver address \p receiver.
    //! \details If the receiver is not found in the connections container, nothing happens.
    //! \param[in] receiver Receiver.
    void block(const void* const receiver);

    //! \brief Block all connections except \p connection.
    //! \details If the signal pointer does not match, nothing happens.
    //!          If the connection ID is non-existent all other connections are still blocked!
    //! \param[in] connection Connection.
    void blockAllButThis(const SignalConnection& connection);

    //! \brief Unblock all connections.
    void unblockAll();

    //! \brief Unblock a connection.
    //! \details If the connection ID is non-existent or the signal pointer does not match, nothing happens.
    //! \param[in] connection Connection.
    void unblock(const SignalConnection& connection);

    //! \brief Block a connection based on the receiver address.
    //! \details If the receiver is not found in the connections container, nothing happens.
    //! \param[in] receiver Receiver.
    void unblock(const void* const receiver);

    //! \brief Test if a given connection is blocked.
    //! \param[in] connection Connection to test.
    //! \return True if the connection is blocked,
    //!         false if not or the connection ID is not found
    //!         in the connections container.
    bool isBlocked(const SignalConnection& connection) const;

    //! \brief Return the toal number of connections.
    //! \return Number of connections.
    size_t getNumOfConnections() const;

    unsigned getHighestPriority() const;

private:
    struct Connection
    {
        SignalConnection::Id id;

        Slot slot;

        bool blocked;

        bool disconnected;

        //! \brief Priority.
        unsigned priority;
    };

    //! \brief Lockable object alias.
    using Lock = typename vpl::base::CLibraryLockableObject<Signal>::CLock;

    //! \brief Connection list type.
	using Connections = std::vector<Connection>;

    //! \brief Connect logic implementation.
    SignalConnection connect(const Slot& slot,
                             const unsigned priority);

    void prepareModifications();

    void handleModifications();

    //! \brief ID counter for assigning new IDs.
    SignalConnection::Id m_counter,
                         m_tempCounter;

    //! \brief Connection map of signal-slot connections.
	Connections m_connections;

    size_t m_queueModifications;

    std::queue<std::pair<Slot, unsigned>> m_newConnects;

    std::queue<SignalConnection> m_newDisconnects;
};

namespace signal
{

//! \brief Create a slot from a member function.
template <typename T, typename R, typename... Ts>
typename Signal<R (Ts...)>::Slot makeSlot(T* const receiver, R (T::*slot)(Ts...));

//! \brief Create a slot from a const member function.
template <typename T, typename R, typename... Ts>
typename Signal<R (Ts...)>::Slot makeSlot(const T* const receiver, R (T::*slot)(Ts...) const);

}// namespace signal

//! \brief Wrapper for the class #Signal to maintain compatibility
//!        with code using vpl::mod::CSignal.
template <typename R, typename... Ts>
class SignalWrapper : public Signal<R (Ts...)>
{
public:
    using tHandler = vpl::base::FunctorWrapper<R, Ts...>;

    enum { NUM_OF_PARAMS = sizeof...(Ts) };

    //! \brief Default constructor.
    SignalWrapper();

    //! \brief Copy constructor.
    SignalWrapper(const SignalWrapper& arg);

    //! \brief Destructor.
    ~SignalWrapper();

    SignalWrapper& operator =(SignalWrapper& rhs);

    //! \brief Invocation method.
    void invoke(Ts... args);

    //! \brief Invocation method with return type R.
    R invoke2(Ts... args);

    //! \brief Allow connect overload resolution to
    //!        consider base class overloads as well.
    using Signal<R (Ts...)>::connect;

    //! \brief Connect a member function.
    //! \param[in] receiver Receiver.
    //! \param[in] slot Slot.
    //! \return Connection ID.
    template <typename T>
    SignalConnection connect(T& receiver,
                             R (T::*slot)(Ts...),
                             const unsigned priority = 0);

    //! \brief Connect a const member function.
    //! \param[in] receiver Receiver.
    //! \param[in] slot Slot.
    //! \return Connection ID.
    template <typename T>
    SignalConnection connect(const T& receiver,
                             R (T::*slot)(Ts...) const,
                             const unsigned priority = 0);

    //! \brief Connect a VPL functor.
    //! \param[in] functor Functor.
    //! \return Connection ID.
    SignalConnection connect(const vpl::base::FunctorWrapper<R, Ts...>& functor,
                             const unsigned priority = 0);
};

}// namespace mod
}// namespace vpl

#include "ModernSignal.hxx"

#endif
