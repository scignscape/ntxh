//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/06/14                          \n
 *
 * $Id: mdsVolumeBlending.h 1928 2010-11-07 13:11:14Z spanel $
 *
 * File description:
 * - Blending of two volumes into one.
 */

#ifndef MDS_VOLUMEBLENDING_H
#define MDS_VOLUMEBLENDING_H

#include <MDSTk/Base/mdsSetup.h>
#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Module blends two MDSTk volumes.
 */
class CVolumeBlending : public mds::mod::CModule
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    MDS_SHAREDPTR(CVolumeBlending);

public:
    //! Default constructor.
    CVolumeBlending(const std::string& sDescription);

    //! Virtual destructor.
    virtual ~CVolumeBlending();

protected:
    //! Virtual method called on startup.
    virtual bool startup();

    //! Virtual method called by the processing thread.
    virtual bool main();

    //! Called on console shutdown.
    virtual void shutdown();

    //! Called on writing a usage statement.
    virtual void writeExtendedUsage(std::ostream& Stream);

protected:
    //! Module command line parameters values.
    double m_dAlpha;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CVolumeBlending::tSmartPtr  CVolumeBlendingPtr;


#endif // MDS_VOLUMEBLENDING_H

