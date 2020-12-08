//==    ============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2010/11/01                          \n
 *
 * $Id: mdsLoadPNGDir.h 1928 2010-11-07 13:11:14Z spanel $
 *
 * File description:
 * - Loads all PNG images from a given directory.
 * - Converts them to the slice format.
 */

#ifndef MDS_LoadPNGDir_H
#define MDS_LoadPNGDir_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Module loads JPEG images from a specified directory and converts them
 * to the sequence of MDSTk images.
 */
class CLoadPNGDir : public mds::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    MDS_SHAREDPTR(CLoadPNGDir);

public:
    //! Default constructor
    CLoadPNGDir(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CLoadPNGDir();

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
    std::string m_ssFormat, m_ssDir, m_ssFileMask;

    //! Loads all images from a directory.
    //! - Returns the number of successfully loaded images.
    template <class ImageType>
    int loadImagesFromDir(ImageType& AuxImage);
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CLoadPNGDir::tSmartPtr    CLoadPNGDirPtr;


#endif // MDS_LoadPNGDir_H

