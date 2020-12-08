//==============================================================================
/* This file comes from MDSTk software and was modified for
 * 
 * VPL - Voxel Processing Library
 * Changes are Copyright 2014 3Dim Laboratory s.r.o.
 * All rights reserved.
 * 
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 * 
 * The original MDSTk legal notice can be found below.
 * 
 * Medical Data Segmentation Toolkit (MDSTk) 
 * Copyright (c) 2003-2009 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2009/03/30                       
 */

#ifndef VPL_Atomic_H
#define VPL_Atomic_H

#include <VPL/Base/Setup.h>

// Windows version
#ifdef _WIN32
#    include <Windows.h>
#    include <WinNT.h>
#endif

// Linux and Mac version
#if defined(_LINUX) || defined(_MACOSX)
#    include <cstdlib>
#endif

#include "SystemExport.h"


namespace vpl
{
namespace sys
{

//==============================================================================
/*!
 * An atomic increment and decrement operation.
 */
class VPL_SYSTEM_EXPORT CAtomic
{
public:
    //! Constructor.
    inline CAtomic(unsigned Value = 0);

    //! Standard destructor.
    ~CAtomic() {}


    //! Returns the current value.
    inline unsigned load();

    //! Replaces the value of the atomic object and obtains the value held previously.
    inline unsigned exchange(unsigned Value);

    //! Incrementes the value and returns the previous value.
    inline unsigned fetchAdd(unsigned Value = 1);

    //! Decrementes the value and returns the previous value.
    inline unsigned fetchSub(unsigned Value = 1);


    //! Replaces the value of the atomic object.
    inline void operator=(unsigned Value);

    //! Returns the incremented value.
    inline unsigned operator++();

    //! Returns the decremented value.
    inline unsigned operator--();

    //! Conversion to the integer (returns the current value).
    inline operator unsigned();

protected:
#ifdef _WIN32
    volatile long m_Value;
#endif

#if defined(_LINUX) || defined(_MACOSX)
    volatile unsigned m_Value;
#endif

private:
    //! Private copy constructor.
    CAtomic(const CAtomic&);

    //! Private assignment operator.
    void operator=(const CAtomic&);
};

//==============================================================================
/*
 * Implementation...
 */
#include "Atomic.hxx"


} // namespace sys
} // namespace vpl

#endif // VPL_Atomic_H

