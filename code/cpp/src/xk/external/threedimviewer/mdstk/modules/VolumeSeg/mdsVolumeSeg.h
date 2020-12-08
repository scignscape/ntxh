//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)     \n
 * Copyright (c) 2003-2005 by Michal Spanel      \n
 *
 * Author:   Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:     2005/01/25                          \n
 *
 * File description:
 * - Sample volume segmentation module.
 */

#ifndef MDS_VOLUMESEG_H
#define MDS_VOLUMESEG_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Example module providing a volume segmentation method.
 */
class CVolumeSeg : public mds::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    MDS_SHAREDPTR(CVolumeSeg);

public:
    //! Default constructor
    CVolumeSeg(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CVolumeSeg();

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
    //! Sample command line argument
    int m_iA;

    //! Sample command line argument
    bool m_bB;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CVolumeSeg::tSmartPtr   CVolumeSegPtr;


#endif // MDS_VOLUMESEG_H

