//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2010/11/01                          \n
 *
 * $Id: mdsLoadDicomDir.h 1928 2010-11-07 13:11:14Z spanel $
 *
 * File description:
 * - Loads all DICOM images from a given directory.
 */

#ifndef MDS_LoadDicomDir_H
#define MDS_LoadDicomDir_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Module loads DICOM images from a specified directory and converts them
 * to MDSTk slices.
 */
class CLoadDicomDir : public mds::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    MDS_SHAREDPTR(CLoadDicomDir);

public:
    //! Default constructor
    CLoadDicomDir(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CLoadDicomDir();

protected:
    //! Virtual method called on startup
    virtual bool startup();

    //! Virtual method called by the processing thread
    virtual bool main();

    //! Called on console shutdown
    virtual void shutdown();

    //! Called on writing a usage statement
    virtual void writeExtendedUsage(std::ostream& Stream);

protected:
    //! Arguments...
    std::string m_ssDir, m_ssFileMask;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CLoadDicomDir::tSmartPtr   CLoadDicomDirPtr;


#endif // MDS_LoadDicomDir_H

