//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/11/11                          \n
 *
 * $Id: mdsArgv.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Simple command line arguments parser.
 */

#ifndef MDS_ARGV_H
#define MDS_ARGV_H

#include <MDSTk/Base/mdsSharedPtr.h>

#include "mdsModuleExport.h"

// STL
#include <string>
#include <vector>
#include <map>
#include <set>


namespace mds
{
namespace mod
{

//==============================================================================
/*!
 * Application command line arguments parser.
 * - Command line has the form
 *   [ -label value | -label | value ]*
 */
class MDS_MODULE_EXPORT CArgv : public mds::base::CObject
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    MDS_SHAREDPTR(CArgv);

public:
    //! Default constructor.
    //! - Method parse() must be called to parse command line arguments.
    CArgv() {}

    //! Constructor that parses a given command line.
    //! - Program command line (argc, argv).
    //! - Throws warning in case of failure.
    CArgv(int argc, char *argv[]);

    //! Default destructor.
    virtual ~CArgv();

    //! Parses a given command line.
    //! - Returns false on failure.
    bool parse(int argc, char *argv[]);

    //! Clears parsed command line.
    void clear();


    //! Returns the number of labelled arguments.
    int getNumOfValues() const { return (int)m_LArguments.size(); }

    //! Checks if only specified labelled arguments were given
    //! on the command line.
    //! - Names of allowed arguments are given in 'sArgs' string.
    //! - 'sArgs' contains names separated by character ':' (colon).
    bool check(const std::string& sArgs) const;

    //! Returns true if a labelled argument exists.
    bool exists(const std::string& sLabel) const;

    //! Reads the value of a labeled argument of appropriate type.
    //! - If the argument is unknown false will be returned.
    bool value(const std::string& sLabel, std::string& sValue) const;
    bool value(const std::string& sLabel, char& cValue) const;
    bool value(const std::string& sLabel, unsigned& uValue) const;
    bool value(const std::string& sLabel, int& iValue) const;
    bool value(const std::string& sLabel, double& dValue) const;


    //! Returns the number of string arguments at the end of the command line.
    int getNumOfSimpleValues() const { return (int)m_SArguments.size(); }

    //! Reads the string value of a simple argument.
    bool simpleValue(int i, std::string& sValue) const;

private:
    //! Index of labelled program arguments.
    typedef std::map<std::string, std::string> tLArguments;

    //! Simple arguments.
    typedef std::vector<std::string> tSArguments;

private:
    //! Index of labelled program arguments.
    tLArguments m_LArguments;

    //! Simple arguments.
    tSArguments m_SArguments;
};


//==============================================================================
/*!
 * Smart pointer to arguments parser.
 */
typedef CArgv::tSmartPtr    CArgvPtr;


} // namespace mod
} // namespace mds

#endif // MDS_ARGV_H

