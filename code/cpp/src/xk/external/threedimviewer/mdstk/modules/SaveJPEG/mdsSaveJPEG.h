//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/03/31                          \n
 *
 * $Id: mdsSaveJPEG.h 1927 2010-11-07 10:49:52Z spanel $
 *
 * File description:
 * - Converts an input slice to JPEG image format.
 */

#ifndef MDS_SAVEJPEG_H
#define MDS_SAVEJPEG_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Module converts an input slice to JPEG image.
 */
class CSaveJPEG : public mds::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    MDS_SHAREDPTR(CSaveJPEG);

public:
    //! Default constructor
    CSaveJPEG(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CSaveJPEG();

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
    int m_iQuality;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSaveJPEG::tSmartPtr    CSaveJPEGPtr;


#endif // MDS_SAVEJPEG_H

