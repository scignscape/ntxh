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
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/10/23                          \n
 *
 * Description:
 * - Exception class.
 */

#ifndef VPL_EXCEPTION_H
#define VPL_EXCEPTION_H

#include "Setup.h"
#include "BaseExport.h"

// STL
#include <stdexcept>


namespace vpl
{
namespace base
{

//==============================================================================
/*!
 * Base class for all MDSTk exceptions.
 */
struct VPL_BASE_EXPORT CException : public std::exception
{
    //! Exception constructor.
    CException() throw() {}

    //! Virtual destructor.
    virtual ~CException() throw() {}

    //! Returns description of exception reason.
    virtual const char *what( ) const throw() { return "Unknown exception"; }
};


//==============================================================================
/*
 * Useful macros.
 */

//! Helper macro declares a new exception derived
//! from the vpl::base::CException class.
#define VPL_DECLARE_EXCEPTION(ClassName, Description) \
    struct ClassName : public vpl::base::CException \
    { \
        ClassName() throw() {} \
        virtual ~ClassName() throw() {} \
        virtual const char *what() const throw() { return Description; } \
    };


//==============================================================================
/*
 * Basic run-time exceptions.
 */

//! Sample exception thrown from a failed function.
VPL_DECLARE_EXCEPTION(CFunctionFailed, "Function has failed")

//! Exception thrown from a failed constructor.
VPL_DECLARE_EXCEPTION(CConstructorFailed, "Constructor has failed")

//! Exception thrown from a failed constructor.
VPL_DECLARE_EXCEPTION(CNotImplemented, "Function is not yet implemented")


} // namespace base
} // namespace vpl

#endif // VPL_EXCEPTION_H

