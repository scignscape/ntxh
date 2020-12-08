//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2004 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/03/31                          \n
 *
 * $Id: mdsLoadJPEG.h 1927 2010-11-07 10:49:52Z spanel $
 *
 * File description:
 * - Reads JPEG image from an input channel.
 * - Converts it to the slice format.
 */

#ifndef MDS_LOADJPEG_H
#define MDS_LOADJPEG_H

#include <MDSTk/Base/mdsSetup.h>
#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Module loads JPEG image and converts it to the MDSTk image.
 */
class CLoadJPEG : public mds::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    MDS_SHAREDPTR(CLoadJPEG);

public:
    //! Default constructor
    CLoadJPEG(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CLoadJPEG();

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
    //! Value of the image format argument.
    std::string m_ssFormat;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CLoadJPEG::tSmartPtr    CLoadJPEGPtr;


#endif // MDS_LOADJPEG_H

