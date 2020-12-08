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
 * Date:    2003/10/24                       
 *
 * Description:
 * - Class for walking through the file system.
 */

#ifndef VPL_FILEBROWSER_H
#define VPL_FILEBROWSER_H

#include <VPL/Base/Setup.h>

// Windows version
#ifdef _WIN32
#    include <windows.h>
#endif

// Linux and Mac version
#if defined(_LINUX) || defined(_MACOSX)
#    include <stdlib.h>
#    include <unistd.h>
#    include <pthread.h>
#    include <limits.h>
#    include <sys/types.h>
#    include <sys/stat.h>
#    include <dirent.h>
#    include <errno.h>
#    include <regex.h>
#endif

#include <VPL/Base/SharedPtr.h>
#include <VPL/System/String.h>

#include "System.h"
#include "SystemExport.h"

// STL
#include <string>


namespace vpl
{
namespace sys
{

//==============================================================================
/*!
 * Class for walking through the file system.
 */
class VPL_SYSTEM_EXPORT CFileBrowser : public vpl::base::CObject
{
public:
    //! Smart pointer type.
    VPL_SHAREDPTR(CFileBrowser);

    //! File/Directory attributes.
    struct VPL_SYSTEM_EXPORT SFileAttr
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
#endif

#if defined(_LINUX) || defined(_MACOSX)
    //! Directory handle.
    DIR *m_pDir;

    //! Directory entry.
    struct dirent *m_pEntry;

    //! Compiled regular expression used by regex functions.
    regex_t *m_pRegex;
#endif

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
class VPL_SYSTEM_EXPORT CFileBrowserU : public vpl::base::CObject
{
public:
    //! Smart pointer type.
    VPL_SHAREDPTR(CFileBrowserU);

    //! File/Directory attributes.
    struct VPL_SYSTEM_EXPORT SFileAttr
    {
        //! Filename.
        tString m_sName;

        //! True if the structure describes a directory.
        bool m_bDirectory;
    };

public:
    //! Constructor.
    CFileBrowserU(const tString& sDirectory = tString(vplT("")));

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
#endif

#if defined(_LINUX) || defined(_MACOSX)
    //! Directory handle.
    DIR *m_pDir;

    //! Directory entry.
    struct dirent *m_pEntry;

    //! Compiled regular expression used by regex functions.
    regex_t *m_pRegex;
#endif

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
} // namespace vpl

#endif // VPL_FILEBROWSER_H

