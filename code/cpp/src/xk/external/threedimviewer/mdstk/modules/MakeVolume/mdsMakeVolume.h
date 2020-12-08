//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/07/26                          \n
 *
 * $Id: mdsMakeVolume.h 1927 2010-11-07 10:49:52Z spanel $
 *
 * File description:
 * - Module makes volume from several input slices.
 */

#ifndef MDS_MAKEVOLUME_H
#define MDS_MAKEVOLUME_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Module creates volume (3D image) from several input slices.
 */
class CMakeVolume : public mds::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    MDS_SHAREDPTR(CMakeVolume);

public:
    //! Default constructor
    CMakeVolume(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CMakeVolume();

protected:
    //! Virtual method called on startup
    virtual bool startup();

    //! Virtual method called by the processing thread
    virtual bool main();

    //! Called on console shutdown
    virtual void shutdown();

    //! Called on writing a usage statement
    virtual void writeExtendedUsage(std::ostream& Stream);

private:
    //! Command line arguments.
    int m_iBorder, m_iBorderValue;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CMakeVolume::tSmartPtr  CMakeVolumePtr;


#endif // MDS_MAKEVOLUME_H

