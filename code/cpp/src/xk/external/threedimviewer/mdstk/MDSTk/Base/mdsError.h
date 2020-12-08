//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/10/27                          \n
 *
 * $Id: mdsError.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Error exception.
 */

#ifndef MDS_ERROR_H
#define MDS_ERROR_H

#include "mdsFullException.h"


namespace mds
{
namespace base
{

//==============================================================================
/*!
 * Class encapsulating an error origin and description.
 */
class MDS_BASE_EXPORT CError : public CFullException
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
#define MDS_ERROR(Name)         mds::base::CError(Name, __FILE__, __LINE__)

//! Creates and throws an error with 'Name' as an description.
//! - File and line parameters acquired from a compiler.
#define MDS_THROW_ERROR(Name)   throw mds::base::CError(Name, __FILE__, __LINE__)

//! Catch block for handling the CError exception.
//! - Writes info about it to the global log and cerr.
//! - Terminates the program!
#define MDS_CATCH_ERROR(ModuleName) \
    catch( const mds::base::CError& Error ) \
    { \
        MDS_LOG(Error); \
        MDS_CERR('<' << ModuleName << "> Error: see log for details, termintating ..." << std::endl); \
        abort(); \
    }


} // namespace base
} // namespace mds

#endif // MDS_ERROR_H

