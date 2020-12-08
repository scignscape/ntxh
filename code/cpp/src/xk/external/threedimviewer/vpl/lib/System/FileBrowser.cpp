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
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.c
 * Date:    2003/10/24                          \n
 *
 * Description:
 * - Class for walking through the file system.
 */

#include <VPL/System/FileBrowser.h>

#include <VPL/Base/Assert.h>
#include <VPL/Base/Error.h>
#include <VPL/Base/Warning.h>
#include <VPL/Base/Logging.h>

#include <limits.h>


namespace vpl
{
namespace sys
{

//==================================================================
/*!
 * Global constants.
 */

//! Maximal directory path length
const int FB_MAX_DIR_LENGHT = 512 + 1;


//==============================================================================
/*
 * Implementation of the class vpl::sys::CFileBrowser
 * - Windows version
 */

#ifdef _WIN32

CFileBrowser::CFileBrowser(const std::string& sDirectory)
    : m_hLastFound(0)
{
    if( !sDirectory.empty() )
    {
        setDirectory(sDirectory);
    }
}


CFileBrowser::~CFileBrowser()
{
    if( m_hLastFound )
    {
        FindClose(m_hLastFound);
    }
}


bool CFileBrowser::setDirectory(const std::string& sDirectory)
{
    return (SetCurrentDirectory(sDirectory.c_str()) != 0);
}


std::string CFileBrowser::getDirectory()
{
	char pcBuffer[FB_MAX_DIR_LENGHT] = {};

    if( GetCurrentDirectory(FB_MAX_DIR_LENGHT, pcBuffer) <= 0 )
    {
        VPL_LOG_WARN("Method CFileBrowser::getDirectory() failed");
    }

    return std::string(pcBuffer);
}


bool CFileBrowser::findFirst(const std::string& sName,
                             CFileBrowser::SFileAttr& Attributes
                            )
{
    if( m_hLastFound )
    {
        FindClose(m_hLastFound);
        m_hLastFound = 0;
    }
    WIN32_FIND_DATA FindData;
    m_hLastFound = FindFirstFile(sName.c_str(), &FindData);
    if( m_hLastFound != INVALID_HANDLE_VALUE )
    {
        Attributes.m_sName = FindData.cFileName;
        Attributes.m_bDirectory = ((FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0);
        return true;
    }

    return false;
}


bool CFileBrowser::findNext(CFileBrowser::SFileAttr& Attributes)
{
    if( !m_hLastFound )
    {
        return false;
    }

    WIN32_FIND_DATA FindData;
    if( FindNextFile(m_hLastFound, &FindData))
    {
        Attributes.m_sName = FindData.cFileName;
        Attributes.m_bDirectory = ((FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0);
        return true;
    }

    return false;
}

#endif // _WIN32


//==============================================================================
/*
 * Implementation of the class vpl::sys::CFileBrowser
 * - Linux and Mac version
 */

#if defined(_LINUX) || defined(_MACOSX)

CFileBrowser::CFileBrowser(const std::string& sDirectory)
    : m_pDir(NULL)
    , m_pEntry(NULL)
    , m_pRegex(NULL)
{
    // Allocate memory for the directory entry
    if( !m_pEntry )
    {
        m_pEntry = (struct dirent *)malloc(sizeof(*m_pEntry) + NAME_MAX + 1);
        VPL_ASSERT(m_pEntry);
    }

    if( !sDirectory.empty() )
    {
        setDirectory(sDirectory);
    }
}


CFileBrowser::~CFileBrowser()
{
    if( m_pDir )
    {
        if( closedir(m_pDir) == -1 )
        {
            VPL_LOG_WARN("Destructor CFileBrowser::~CFileBrowser() failed");
        }
    }

    // Free the allocated directory entry
    if( m_pEntry )
    {
        free((void *)m_pEntry);
    }

    // Free the regex pattern
    if( m_pRegex )
    {
        regfree(m_pRegex);
        delete m_pRegex;
    }
}


bool CFileBrowser::setDirectory(const std::string& sDirectory)
{
    // Change the current working directory
    if( chdir(sDirectory.c_str()) == -1 )
    {
        return false;
    }

    // Close the previously opened directory
    if( m_pDir )
    {
        if( closedir(m_pDir) == -1 )
        {
            VPL_LOG_WARN("Destructor CFileBrowser::~CFileBrowser() failed");
        }
    }

    // Open the directory
    m_pDir = opendir(sDirectory.c_str());
    if( !m_pDir )
    {
        return false;
    }

    return true;
}


std::string CFileBrowser::getDirectory()
{
	char pcBuffer[FB_MAX_DIR_LENGHT] = {};

    if( !getcwd(pcBuffer, (size_t)FB_MAX_DIR_LENGHT) )
    {
        VPL_LOG_WARN("Method CFileBrowser::getDirectory() failed");
    }

    return std::string(pcBuffer);
}


bool CFileBrowser::findFirst(const std::string& sName,
                             CFileBrowser::SFileAttr& Attributes
                            )
{
    if( !m_pDir || sName.empty() )
    {
        return false;
    }

    // Replace all occurences of the '.' with "\\."
    std::string sPattern = sName;
    std::string::size_type Pos = sPattern.find('.');
    while( Pos != std::string::npos )
    {
        sPattern.replace(Pos, 1, "\\.");
        Pos = sPattern.find('.', Pos + 2);
    }

    // Replace all occurences of the '*' with "[[:graph:]]*"
    Pos = sPattern.find('*');
    while( Pos != std::string::npos )
    {
        sPattern.replace(Pos, 1, "[[:graph:]]*");
        Pos = sPattern.find('*', Pos + 12);
    }

    // Replace all occurances of the '?' with "."
    Pos = sPattern.find('?');
    while( Pos != std::string::npos )
    {
        sPattern.replace(Pos, 1, ".");
        Pos = sPattern.find('?', Pos);
    }

    // Compile the regex regular expression
    if( !m_pRegex )
    {
        m_pRegex = new regex_t;
    }
    else
    {
        regfree(m_pRegex);
    }
    if( regcomp(m_pRegex, sPattern.c_str(), REG_NOSUB) != 0 )
    {
        VPL_LOG_WARN("Method CFileBrowser::findFirst() failed");
        return false;
    }

    struct dirent *pTemp = NULL;
    while( readdir_r(m_pDir, m_pEntry, &pTemp) == 0 && pTemp )
    {
        // Use regex to compare the filename and the pattern
        if( regexec(m_pRegex, m_pEntry->d_name, 0, NULL, 0) != 0 )
        {
            continue;
        }

        Attributes.m_sName = m_pEntry->d_name;

        struct stat Stat;
        if( stat(m_pEntry->d_name, &Stat) == 0 )
        {
            Attributes.m_bDirectory = (S_ISDIR(Stat.st_mode) ? true : false);
            return true;
        }
    }

    return false;
}


bool CFileBrowser::findNext(CFileBrowser::SFileAttr& Attributes)
{
    if( !m_pDir || !m_pRegex )
    {
        return false;
    }

    struct dirent *pTemp = NULL;
    while( readdir_r(m_pDir, m_pEntry, &pTemp) == 0 && pTemp )
    {
        // Use regex to compare the filename and the pattern
        if( regexec(m_pRegex, m_pEntry->d_name, 0, NULL, 0) != 0 )
        {
            continue;
        }

        Attributes.m_sName = m_pEntry->d_name;

        struct stat Stat;
        if( stat(m_pEntry->d_name, &Stat) == 0 )
        {
            Attributes.m_bDirectory = (S_ISDIR(Stat.st_mode) ? true : false);
            return true;
        }
    }

    return false;
}

#endif // _LINUX || _MACOSX


//==============================================================================
/*
 * Implementation of the class vpl::sys::CFileBrowserW
 * - Windows version
 */

#ifdef _WIN32

CFileBrowserU::CFileBrowserU(const tString& sDirectory)
    : m_hLastFound(0)
{
    if( !sDirectory.empty() )
    {
        setDirectory(sDirectory);
    }
}


CFileBrowserU::~CFileBrowserU()
{
    if( m_hLastFound )
    {
        FindClose(m_hLastFound);
    }
}


bool CFileBrowserU::setDirectory(const tString& sDirectory)
{
    return (SetCurrentDirectoryW(sDirectory.c_str()) != 0);
}


tString CFileBrowserU::getDirectory()
{
	tChar pcBuffer[FB_MAX_DIR_LENGHT] = {};

    if( GetCurrentDirectoryW(FB_MAX_DIR_LENGHT, pcBuffer) <= 0 )
    {
        VPL_LOG_WARN("Method CFileBrowserU::getDirectory() failed");
    }

    return tString(pcBuffer);
}


bool CFileBrowserU::findFirst(const tString& sName,
                             CFileBrowserU::SFileAttr& Attributes
                            )
{
	WIN32_FIND_DATAW FindData;
    m_hLastFound = FindFirstFileW(sName.c_str(), &FindData);
    if( m_hLastFound != INVALID_HANDLE_VALUE )
    {
        Attributes.m_sName = FindData.cFileName;
        Attributes.m_bDirectory = ((FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0);
        return true;
    }

    return false;
}


bool CFileBrowserU::findNext(CFileBrowserU::SFileAttr& Attributes)
{
    if( !m_hLastFound )
    {
        return false;
    }

    WIN32_FIND_DATAW FindData;
    if( FindNextFileW(m_hLastFound, &FindData))
    {
        Attributes.m_sName = FindData.cFileName;
        Attributes.m_bDirectory = ((FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0);
        return true;
    }

    return false;
}

#endif // _WIN32


//==============================================================================
/*
 * Implementation of the class vpl::sys::CFileBrowser
 * - Linux and Mac version
 */

#if defined(_LINUX) || defined(_MACOSX)

CFileBrowserU::CFileBrowserU(const tString& sDirectory)
    : m_pDir(NULL)
    , m_pEntry(NULL)
    , m_pRegex(NULL)
{
    // Allocate memory for the directory entry
    if( !m_pEntry )
    {
        m_pEntry = (struct dirent *)malloc(sizeof(*m_pEntry) + NAME_MAX + 1);
        VPL_ASSERT(m_pEntry);
    }

    if( !sDirectory.empty() )
    {
        setDirectory(sDirectory);
    }
}


CFileBrowserU::~CFileBrowserU()
{
    if( m_pDir )
    {
        if( closedir(m_pDir) == -1 )
        {
            VPL_LOG_WARN("Destructor CFileBrowserU::~CFileBrowserU() failed");
        }
    }

    // Free the allocated directory entry
    if( m_pEntry )
    {
        free((void *)m_pEntry);
    }

    // Free the regex pattern
    if( m_pRegex )
    {
        regfree(m_pRegex);
        delete m_pRegex;
    }
}


bool CFileBrowserU::setDirectory(const tString& sDirectory)
{
    // Change the current working directory
    if( chdir(sDirectory.c_str()) == -1 )
    {
        return false;
    }

    // Close the previously opened directory
    if( m_pDir )
    {
        if( closedir(m_pDir) == -1 )
        {
            VPL_LOG_WARN("Destructor CFileBrowserU::~CFileBrowserU() failed");
        }
    }

    // Open the directory
    m_pDir = opendir(sDirectory.c_str());
    if( !m_pDir )
    {
        return false;
    }

    return true;
}


tString CFileBrowserU::getDirectory()
{
	tChar pcBuffer[FB_MAX_DIR_LENGHT] = {};

    if( !getcwd(pcBuffer, (size_t)FB_MAX_DIR_LENGHT) )
    {
        VPL_LOG_WARN("Method CFileBrowserU::getDirectory() failed");
    }

    return tString(pcBuffer);
}


bool CFileBrowserU::findFirst(const tString& sName,
                             CFileBrowserU::SFileAttr& Attributes
                            )
{
    if( !m_pDir || sName.empty() )
    {
        return false;
    }

    // Replace all occurences of the '.' with "\\."
    tString sPattern = sName;
    tString::size_type Pos = sPattern.find('.');
    while( Pos != tString::npos )
    {
        sPattern.replace(Pos, 1, vplT("\\."));
        Pos = sPattern.find(vplT('.'), Pos + 2);
    }

    // Replace all occurences of the '*' with "[[:graph:]]*"
    Pos = sPattern.find('*');
    while( Pos != tString::npos )
    {
        sPattern.replace(Pos, 1, vplT("[[:graph:]]*"));
        Pos = sPattern.find(vplT('*'), Pos + 12);
    }

    // Replace all occurances of the '?' with "."
    Pos = sPattern.find(vplT('?'));
    while( Pos != tString::npos )
    {
        sPattern.replace(Pos, 1, vplT("."));
        Pos = sPattern.find(vplT('?'), Pos);
    }

    // Compile the regex regular expression
    if( !m_pRegex )
    {
        m_pRegex = new regex_t;
    }
    else
    {
        regfree(m_pRegex);
    }
    if( regcomp(m_pRegex, sPattern.c_str(), REG_NOSUB) != 0 )
    {
        VPL_LOG_WARN("Method CFileBrowserU::findFirst() failed");
        return false;
    }

    struct dirent *pTemp = NULL;
    while( readdir_r(m_pDir, m_pEntry, &pTemp) == 0 && pTemp )
    {
        // Use regex to compare the filename and the pattern
        if( regexec(m_pRegex, m_pEntry->d_name, 0, NULL, 0) != 0 )
        {
            continue;
        }

        Attributes.m_sName = m_pEntry->d_name;

        struct stat Stat;
        if( stat(m_pEntry->d_name, &Stat) == 0 )
        {
            Attributes.m_bDirectory = (S_ISDIR(Stat.st_mode) ? true : false);
            return true;
        }
    }

    return false;
}


bool CFileBrowserU::findNext(CFileBrowserU::SFileAttr& Attributes)
{
    if( !m_pDir || !m_pRegex )
    {
        return false;
    }

    struct dirent *pTemp = NULL;
    while( readdir_r(m_pDir, m_pEntry, &pTemp) == 0 && pTemp )
    {
        // Use regex to compare the filename and the pattern
        if( regexec(m_pRegex, m_pEntry->d_name, 0, NULL, 0) != 0 )
        {
            continue;
        }

        Attributes.m_sName = m_pEntry->d_name;

        struct stat Stat;
        if( stat(m_pEntry->d_name, &Stat) == 0 )
        {
            Attributes.m_bDirectory = (S_ISDIR(Stat.st_mode) ? true : false);
            return true;
        }
    }

    return false;
}

#endif // _LINUX || _MACOSX


}  // namespace sys
}  // namespace vpl

