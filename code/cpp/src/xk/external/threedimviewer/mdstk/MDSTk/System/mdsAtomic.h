//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2009 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2009/03/30                          \n
 *
 * $Id: mdsAtomic.h 1864 2010-09-01 09:07:40Z spanel $
 *
 * Description:
 * - Atomic operations.
 */

#ifndef MDS_Atomic_H
#define MDS_Atomic_H

#include <MDSTk/Base/mdsSetup.h>

// Windows version
#ifdef _WIN32
#    include <Windows.h>
#    include <WinNT.h>
#endif // _WIN32

// Linux version
#ifdef _LINUX
#    include <cstdlib>
#endif // _LINUX

#include <MDSTk/Base/mdsSharedPtr.h>

#include "mdsSystemExport.h"


namespace mds
{
namespace sys
{

//==============================================================================
/*!
 * An atomic increment and decrement operation.
 */
class MDS_SYSTEM_EXPORT CAtomic : public mds::base::CObject
{
public:
    //! Smart pointer type.
    MDS_SHAREDPTR(CAtomic);

public:
    //! Constructor.
    inline CAtomic(unsigned Value = 0);

    //! Standard destructor.
    ~CAtomic() {}


    //! Returns the current value.
    inline unsigned get();

    //! Changes the value.
    //! - Returns the previous value!
    inline unsigned set(unsigned Value);

    //! Incrementes the value.
    //! - Returns the previous value!
    inline unsigned add(unsigned Value = 1);

    //! Decrementes the value.
    //! - Returns the previous value!
    inline unsigned sub(unsigned Value = 1);


    //! Returns the incremented value.
    inline unsigned operator++();

    //! Returns the decremented value.
    inline unsigned operator--();

    //! Conversion to the integer (returns the current value).
    inline operator unsigned();

protected:
#ifdef _WIN32
    volatile long m_Value;
#endif // _WIN32

#ifdef _LINUX
    volatile unsigned m_Value;
#endif // _LINUX

private:
    //! Private copy constructor.
    CAtomic(const CAtomic&);

    //! Private assignment operator.
    void operator=(const CAtomic&);
};


//==============================================================================
/*!
 * Smart pointer to the Atomic.
 */
typedef CAtomic::tSmartPtr   CAtomicPtr;


//==============================================================================
/*
 * Implementation...
 */
#include "mdsAtomic.hxx"


} // namespace sys
} // namespace mds

#endif // MDS_Atomic_H

