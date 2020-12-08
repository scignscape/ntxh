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
 * Date:    2003/10/27                          \n
 *
 * Description:
 * - Error exception.
 */

#ifndef VPL_ERROR_H
#define VPL_ERROR_H

#include "FullException.h"


namespace vpl
{
namespace base
{

//==============================================================================
/*!
 * Class encapsulating an error origin and description.
 */
class VPL_BASE_EXPORT CError : public CFullException
{
public:
    //! Error constructor.
    CError(const std::string& sReason,
           const std::string& sFileName,
           int iLine
           ) throw()
        : CFullException(sReason, sFileName, iLine)
    {}

    //! Copy constructor.
    CError(const CError& e) throw() : CFullException(e) {}

    //! Virtual destructor.
    virtual ~CError() throw() {}


    //! Writes error description into the output stream
    //! in human readable form.
    virtual void print(std::ostream& Stream) const;

    //! Writes error description into the output stream.
    friend std::ostream& operator <<(std::ostream& os, const CError& Error);
};


//==============================================================================
/*
 * Several useful macro definitions.
 */

//! Macro that creates an error object with 'Name' as an description.
//! - File and line parameters acquired from a compiler.
#define VPL_ERROR(Name)         vpl::base::CError(Name, __FILE__, __LINE__)

//! Creates and throws an error with 'Name' as an description.
//! - File and line parameters acquired from a compiler.
#define VPL_THROW_ERROR(Name)   throw vpl::base::CError(Name, __FILE__, __LINE__)

//! Catch block for handling the CError exception.
//! - Writes info about it to the global log and cerr.
//! - Terminates the program!
#define VPL_CATCH_ERROR(ModuleName) \
    catch( const vpl::base::CError& Error ) \
    { \
        VPL_LOG_INFO(Error); \
        VPL_LOG_ERROR('<' << ModuleName << "> Error: see log for details, termintating ..." << std::endl); \
        abort(); \
    }


} // namespace base
} // namespace vpl

#endif // VPL_ERROR_H

