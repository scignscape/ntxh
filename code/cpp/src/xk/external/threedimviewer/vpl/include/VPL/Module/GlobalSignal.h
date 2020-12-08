//==============================================================================`
/*/*! \file
 * Medical Data Segmentation Toolkit (MDSTk) 
 * Copyright (c) 2003-2008 by PGMed          
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2008/02/25                       
 *
 * Description:
 * - Definition of a global signal helpful for distribution of global events
 *   within an application.
 */

#ifndef VPL_GlobalSignal_H
#define VPL_GlobalSignal_H

#include "Signal.h"

#include <VPL/Base/Singleton.h>


namespace vpl
{
namespace mod
{

//=============================================================================
/*!
 * Global signal helpful for distribution of global events within
 * an application.
 * - Parameter Id allows you to identify different global signals.
 * - Remaining parameters represent signal parameters.
 */
template <int Id, typename R,
          typename P1 = tNull, typename P2 = tNull,
          typename P3 = tNull, typename P4 = tNull
          >
class CGlobalSignal
    : public CSignal<R, P1, P2, P3, P4>
    , public vpl::base::CLibrarySingleton
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    VPL_SHAREDPTR(CGlobalSignal);

    //! Signal identification.
    enum { ID = Id };

    //! Encapsulated signal.
    typedef CSignal<R, P1, P2, P3, P4> tSignal;

public:
    //! Destructor.
    ~CGlobalSignal() {}

    //! Returns global signal identifier.
    int getId() const { return ID; }

private:
    //! Private constructor.
    CGlobalSignal() {}

    //! Allow instantiation using the singleton.
    VPL_PRIVATE_SINGLETON(CGlobalSignal);
};


//==============================================================================
/*
 * Helpful macros.
 */

//! Declares a new global signal with no parameters.
#define VPL_DECLARE_SIGNAL_0(Id, R, tName) \
    typedef ::vpl::mod::CGlobalSignal<Id, R> tName

//!  Declares a new global signal with one parameter.
#define VPL_DECLARE_SIGNAL_1(Id, R, P1, tName) \
    typedef ::vpl::mod::CGlobalSignal<Id, R, P1> tName

//!  Declares a new global signal with two parameter.
#define VPL_DECLARE_SIGNAL_2(Id, R, P1, P2, tName) \
    typedef ::vpl::mod::CGlobalSignal<Id, R, P1, P2> tName

//!  Declares a new global signal with three parameter.
#define VPL_DECLARE_SIGNAL_3(Id, R, P1, P2, P3, tName) \
    typedef ::vpl::mod::CGlobalSignal<Id, R, P1, P2, P3> tName

//!  Declares a new global signal with four parameter.
#define VPL_DECLARE_SIGNAL_4(Id, R, P1, P2, P3, P4, tName) \
    typedef ::vpl::mod::CGlobalSignal<Id, R, P1, P2, P3, P4> tName

//! Returns reference to a global signal specified by its type.
#define VPL_SIGNAL(tName)   VPL_SINGLETON(tName)


} // namespace mod
} // namespace vpl

#endif // VPL_GlobalSignal_H
