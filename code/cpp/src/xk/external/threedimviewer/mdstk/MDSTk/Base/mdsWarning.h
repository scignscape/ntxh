//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/10/23                          \n
 *
 * $Id: mdsWarning.h 2092 2012-02-15 12:50:59Z spanel $
 *
 * Description:
 * - Warning class.
 */

#ifndef MDS_WARNING_H
#define MDS_WARNING_H

#include "mdsFullException.h"


namespace mds
{
namespace base
{

//==============================================================================
/*!
 * Class encapsulating an exception origin and description.
 */
class MDS_BASE_EXPORT CWarning : public CFullException
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
#define MDS_WARNING(Name)           mds::base::CWarning(Name, __FILE__, __LINE__)

//! Creates and throws warning with Name as a description.
//! - File and line parameters acquired from compiler.
#define MDS_THROW_WARNING(Name)     throw mds::base::CWarning(Name, __FILE__, __LINE__);

//! Catch block for handling the CWarning exception.
//! - Writes info about it to the global log and cerr.
//! - Doesn't terminate the running application!
#define MDS_CATCH_WARNING(ModuleName) \
    catch( const mds::base::CWarning& Warning ) \
    { \
        MDS_LOG(Warning); \
        MDS_CERR('<' << ModuleName << "> Warning: see log for details" << std::endl); \
    }


} // namespace base
} // namespace mds

#endif // MDS_WARNING_H

