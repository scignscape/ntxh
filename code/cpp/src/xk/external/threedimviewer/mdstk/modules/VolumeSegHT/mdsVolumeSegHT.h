//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)           \n
 * Copyright (c) 2003-2005 by Michal Spanel            \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz         \n
 *          Miroslav Svub, xsvubm00@stud.fit.vutbr.cz  \n
 * Date:    2005/01/25                                 \n
 *
 * $Id: mdsVolumeSegHT.h 1928 2010-11-07 13:11:14Z spanel $
 *
 * File description:
 * - Simple segmentation method based on histogram thresholding.
 */

#ifndef MDS_VOLUMESEGHT_H
#define MDS_VOLUMESEGHT_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Module providing segmentation method based on histogram thresholding.
 */
class CVolumeSegHT : public mds::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    MDS_SHAREDPTR(CVolumeSegHT);

public:
    //! Default constructor
    CVolumeSegHT(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CVolumeSegHT();

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
    //! Command line argument
    int m_iThresholds;

    //! Command line argument
    int m_iColumns;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CVolumeSegHT::tSmartPtr     CVolumeSegHTPtr;


#endif // MDS_VOLUMESEGHT_H

