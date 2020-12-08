//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)              \n
 * Copyright (c) 2003-2005 by Michal Spanel               \n
 *
 * Author:   Michal Spanel, spanel@fit.vutbr.cz           \n
 *           Martin Skotnica, xskotn01@stud.fit.vutbr.cz  \n
 * Date:     2005/01/25                                   \n
 *
 * $Id: mdsVolumeSegRG.h 1928 2010-11-07 13:11:14Z spanel $
 *
 * File description:
 * - Simple region growing volume segmentation.
 */

#ifndef MDS_VOLUMESEGRG_H
#define MDS_VOLUMESEGRG_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Module providing simple region growing slice segmentation.
 */
class CVolumeSegRG : public mds::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    MDS_SHAREDPTR(CVolumeSegRG);

public:
    //! Default constructor
    CVolumeSegRG(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CVolumeSegRG();

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
    int m_iThreshold;

    //! Command line argument
    double m_dWeightDiff;

    //! Command line argument
    double m_dWeightEdge;

    //! Command line argument
    bool m_bMerge;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CVolumeSegRG::tSmartPtr     CVolumeSegRGPtr;


#endif // MDS_VOLUMESEGRG_H

