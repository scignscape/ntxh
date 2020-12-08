//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2008 by Michal Spanel          \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2008/04/24                          \n
 *
 * $Id: mdsFullException.h 2092 2012-02-15 12:50:59Z spanel $
 *
 * Description:
 * - More complex exception class detailing its origin and reason.
 */

#ifndef MDS_FullException_H
#define MDS_FullException_H

#include "mdsException.h"

// STL
#include <string>
#include <iostream>


namespace mds
{
namespace base
{

//==============================================================================
/*!
 * More complex exception class encapsulating information about its origin
 * and description.
 */
class MDS_BASE_EXPORT CFullException : public CException
{
public:
    //! Exception constructor.
    CFullException(const std::string& sReason,
                   const std::string& sFilename,
                   int iLine
                   ) throw();

    //! Exception copy constructor.
    CFullException(const CFullException& e) throw();

    //! Virtual destructor.
    virtual ~CFullException() throw() {}


    //! Returns description of exception reason.
    virtual const char *what( ) const throw();

    //! Returns description of exception reason.
    const std::string& getReason() const throw() { return m_sReason; }

    //! Returns concrete filename.
    const std::string& getFilename() const throw() { return m_sFilename; }

    //! Returns concrete line.
    int getLine() const throw() { return m_iLine; }


    //! Writes exception description into the output stream
    //! in a human readable form.
    virtual void print(std::ostream& Stream) const;

    //! Writes exception description into the output stream.
    friend std::ostream& operator <<(std::ostream& Stream, const CFullException& Exception);

protected:
    //! Exception reason.
    std::string m_sReason;

    //! File in which exception has risen.
    std::string m_sFilename;

    //! Line on which exception has risen.
    int m_iLine;
};


//==============================================================================
/*
 * Several macro definitions.
 */

//! Macro that creates an exception with a given name as a description.
//! - File and line parameters acquired from compiler.
#define MDS_EXCEPTION(Name)         mds::base::CFullException(Name, __FILE__, __LINE__)

//! Creates and throws an exception with a given name as a description.
//! - File and line parameters acquired from compiler.
#define MDS_THROW_EXCEPTION(Name)   throw mds::base::CFullException(Name, __FILE__, __LINE__);


} // namespace base
} // namespace mds

#endif // MDS_FullException_H

