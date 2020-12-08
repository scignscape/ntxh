//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/10/24                          \n
 *
 * $Id: mdsFileBrowser.h 2061 2012-01-23 23:54:07Z spanel $
 *
 * Description:
 * - Class for walking through the file system.
 */

#ifndef MDS_FILEBROWSER_H
#define MDS_FILEBROWSER_H

#include <MDSTk/Base/mdsSetup.h>

// Windows version
#ifdef _WIN32
#    include <windows.h>
#endif // _WIN32

// Linux version
#ifdef _LINUX
#    include <stdlib.h>
#    include <unistd.h>
#    include <pthread.h>
#    include <limits.h>
#    include <sys/types.h>
#    include <sys/stat.h>
#    include <dirent.h>
#    include <errno.h>
#    include <regex.h>
#endif // _LINUX

#include <MDSTk/Base/mdsSharedPtr.h>
#include <MDSTk/System/mdsString.h>

#include "mdsSystem.h"
#include "mdsSystemExport.h"

// STL
#include <string>


namespace mds
{
namespace sys
{

//==============================================================================
/*!
 * Class for walking through the file system.
 */
class MDS_SYSTEM_EXPORT CFileBrowser : public mds::base::CObject
{
public:
    //! Smart pointer type.
    MDS_SHAREDPTR(CFileBrowser);

    //! File/Directory attributes.
    struct MDS_SYSTEM_EXPORT SFileAttr
    {
        //! Filename.
        std::string m_sName;

        //! True if the structure describes a directory.
        bool m_bDirectory;
    };

public:
    //! Constructor.
    CFileBrowser(const std::string& sDirectory = std::string(""));

    //! Destructor.
    virtual ~CFileBrowser();

    //! Sets the current working directory.
    bool setDirectory(const std::string& sDirectory);

    //! Returns current working directory.
    std::string getDirectory();

    //! Look up the first item in a current working directory.
    //! - Special charakters '?' and '*' can be used for mathing.
    bool findFirst(const std::string& sName, SFileAttr& Attributes);

    //! Finds next item.
    bool findNext(SFileAttr& Attributes);

private:
#ifdef _WIN32
    //! Windows handle.
    HANDLE m_hLastFound;
#endif // _WIN32

#ifdef _LINUX
    //! Directory handle.
    DIR *m_pDir;

    //! Directory entry.
    struct dirent *m_pEntry;

    //! Compiled regular expression used by regex functions.
    regex_t *m_pRegex;
#endif // _LINUX

private:
    //! Private copy constructor.
    CFileBrowser(const CFileBrowser&);

    //! Private assignment operator.
    void operator=(const CFileBrowser&);
};


//==============================================================================
/*!
 * Smart pointer to the file browser.
 */
typedef CFileBrowser::tSmartPtr     CFileBrowserPtr;


//==============================================================================
/*!
 * Class for walking through the file system.
 */
class MDS_SYSTEM_EXPORT CFileBrowserU : public mds::base::CObject
{
public:
    //! Smart pointer type.
    MDS_SHAREDPTR(CFileBrowserU);

    //! File/Directory attributes.
    struct MDS_SYSTEM_EXPORT SFileAttr
    {
        //! Filename.
        tString m_sName;

        //! True if the structure describes a directory.
        bool m_bDirectory;
    };

public:
    //! Constructor.
    CFileBrowserU(const tString& sDirectory = tString(mdsT("")));

    //! Destructor.
    virtual ~CFileBrowserU();

    //! Sets the current working directory.
    bool setDirectory(const tString& sDirectory);

    //! Returns current working directory.
    tString getDirectory();

    //! Look up the first item in a current working directory.
    //! - Special charakters '?' and '*' can be used for mathing.
    bool findFirst(const tString& sName, SFileAttr& Attributes);

    //! Finds next item.
    bool findNext(SFileAttr& Attributes);

private:
#ifdef _WIN32
    //! Windows handle.
    HANDLE m_hLastFound;
#endif // _WIN32

#ifdef _LINUX
    //! Directory handle.
    DIR *m_pDir;

    //! Directory entry.
    struct dirent *m_pEntry;

    //! Compiled regular expression used by regex functions.
    regex_t *m_pRegex;
#endif // _LINUX

private:
    //! Private copy constructor.
    CFileBrowserU(const CFileBrowserU&);

    //! Private assignment operator.
    void operator=(const CFileBrowserU&);
};


//==============================================================================
/*!
 * Smart pointer to the file browser.
 */
typedef CFileBrowserU::tSmartPtr     CFileBrowserUPtr;


} // namespace sys
} // namespace mds

#endif // MDS_FILEBROWSER_H

