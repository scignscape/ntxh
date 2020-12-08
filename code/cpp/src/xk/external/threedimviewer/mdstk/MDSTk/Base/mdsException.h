//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/10/23                          \n
 *
 * $Id: mdsException.h 2092 2012-02-15 12:50:59Z spanel $
 *
 * Description:
 * - Exception class.
 */

#ifndef MDS_EXCEPTION_H
#define MDS_EXCEPTION_H

#include "mdsSetup.h"
#include "mdsBaseExport.h"

// STL
#include <stdexcept>


namespace mds
{
namespace base
{

//==============================================================================
/*!
 * Base class for all MDSTk exceptions.
 */
struct MDS_BASE_EXPORT CException : public std::exception
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
//! from the mds::base::CException class.
#define MDS_DECLARE_EXCEPTION(ClassName, Description) \
    struct ClassName : public mds::base::CException \
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
MDS_DECLARE_EXCEPTION(CFunctionFailed, "Function has failed")

//! Exception thrown from a failed constructor.
MDS_DECLARE_EXCEPTION(CConstructorFailed, "Constructor has failed")

//! Exception thrown from a failed constructor.
MDS_DECLARE_EXCEPTION(CNotImplemented, "Function is not yet implemented")


} // namespace base
} // namespace mds

#endif // MDS_EXCEPTION_H

