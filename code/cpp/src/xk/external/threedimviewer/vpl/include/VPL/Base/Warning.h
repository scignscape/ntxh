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
 * Copyright (c) 2003-2005 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/10/23                       
 *
 * Description:
 * - Warning class.
 */

#ifndef VPL_WARNING_H
#define VPL_WARNING_H

#include "FullException.h"


namespace vpl
{
namespace base
{

//==============================================================================
/*!
 * Class encapsulating an exception origin and description.
 */
class VPL_BASE_EXPORT CWarning : public CFullException
{
public:
    //! Constructor.
    CWarning(const std::string& sReason,
             const std::string& sFilename,
             int iLine
             ) throw()
        : CFullException(sReason, sFilename, iLine)
    {}

    //! Exception copy constructor.
    CWarning(const CWarning& w) throw() : CFullException(w) {}

    //! Virtual destructor.
    virtual ~CWarning() throw() {}


    //! Writes warning description into the output stream
    //! in human readable form.
    virtual void print(std::ostream& Stream) const;

    //! Writes warning description into the output stream.
    friend std::ostream& operator <<(std::ostream& Stream, const CWarning& Warning);
};


//==============================================================================
/*
 * Several macro definitions.
 */

//! Macro that creates warning with Name as a description.
//! - File and line parameters acquired from compiler.
#define VPL_WARNING(Name)           vpl::base::CWarning(Name, __FILE__, __LINE__)

//! Creates and throws warning with Name as a description.
//! - File and line parameters acquired from compiler.
#define VPL_THROW_WARNING(Name)     throw vpl::base::CWarning(Name, __FILE__, __LINE__);

//! Catch block for handling the CWarning exception.
//! - Writes info about it to the global log and cerr.
//! - Doesn't terminate the running application!
#define VPL_CATCH_WARNING(ModuleName) \
    catch( const vpl::base::CWarning& Warning ) \
    { \
        VPL_LOG_INFO(Warning); \
        VPL_LOG_ERROR('<' << ModuleName << "> Warning: see log for details" << std::endl); \
    }


} // namespace base
} // namespace vpl

#endif // VPL_WARNING_H

