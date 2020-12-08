//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2010/11/05                          \n
 *
 * $Id: mdsSaveJPEGDir.h 1928 2010-11-07 13:11:14Z spanel $
 *
 * File description:
 * - Saves all input slices as JPEG images to a given directory.
 */

#ifndef MDS_SaveJPEGDir_H
#define MDS_SaveJPEGDir_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Module saves all input MDSTk images as JPEG images to a specified directory.
 */
class CSaveJPEGDir : public mds::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    MDS_SHAREDPTR(CSaveJPEGDir);

public:
    //! Default constructor
    CSaveJPEGDir(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CSaveJPEGDir();

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
    std::string m_ssFormat, m_ssDir;

    //! Loads all images from a directory.
    //! - Returns false on failure.
    template <class ImageType>
    bool saveImageToDir(ImageType& Image);
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSaveJPEGDir::tSmartPtr     CSaveJPEGDirPtr;


#endif // MDS_SaveJPEGDir_H
