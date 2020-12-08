//==============================================================================`
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2008 by PGMed             \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2008/02/25                          \n
 *
 * $Id: mdsGlobalSignal.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Definition of a global signal helpful for distribution of global events
 *   within an application.
 */

#ifndef MDS_GlobalSignal_H
#define MDS_GlobalSignal_H

#include "mdsSignal.h"

#include <MDSTk/Base/mdsSingleton.h>


namespace mds
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
    , public mds::base::CLibrarySingleton
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    MDS_SHAREDPTR(CGlobalSignal);

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
    MDS_PRIVATE_SINGLETON(CGlobalSignal);
};


//==============================================================================
/*
 * Helpful macros.
 */

//! Declares a new global signal with no parameters.
#define MDS_DECLARE_SIGNAL_0(Id, R, tName) \
    typedef ::mds::mod::CGlobalSignal<Id, R> tName

//!  Declares a new global signal with one parameter.
#define MDS_DECLARE_SIGNAL_1(Id, R, P1, tName) \
    typedef ::mds::mod::CGlobalSignal<Id, R, P1> tName

//!  Declares a new global signal with two parameter.
#define MDS_DECLARE_SIGNAL_2(Id, R, P1, P2, tName) \
    typedef ::mds::mod::CGlobalSignal<Id, R, P1, P2> tName

//!  Declares a new global signal with three parameter.
#define MDS_DECLARE_SIGNAL_3(Id, R, P1, P2, P3, tName) \
    typedef ::mds::mod::CGlobalSignal<Id, R, P1, P2, P3> tName

//!  Declares a new global signal with four parameter.
#define MDS_DECLARE_SIGNAL_4(Id, R, P1, P2, P3, P4, tName) \
    typedef ::mds::mod::CGlobalSignal<Id, R, P1, P2, P3, P4> tName

//! Returns reference to a global signal specified by its type.
#define MDS_SIGNAL(tName)   MDS_SINGLETON(tName)


} // namespace mod
} // namespace mds

#endif // MDS_GlobalSignal_H
