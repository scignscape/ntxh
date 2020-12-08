//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2010/11/02                          \n
 *
 * $Id: mdsSavePNGDir.h 1928 2010-11-07 13:11:14Z spanel $
 *
 * File description:
 * - Saves all input slices as PNG images to a given directory.
 */

#ifndef MDS_SavePNGDir_H
#define MDS_SavePNGDir_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Module saves all input MDSTk images as PNG images to a specified directory.
 */
class CSavePNGDir : public mds::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    MDS_SHAREDPTR(CSavePNGDir);

public:
    //! Default constructor
    CSavePNGDir(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CSavePNGDir();

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
typedef CSavePNGDir::tSmartPtr     CSavePNGDirPtr;


#endif // MDS_SavePNGDir_H

