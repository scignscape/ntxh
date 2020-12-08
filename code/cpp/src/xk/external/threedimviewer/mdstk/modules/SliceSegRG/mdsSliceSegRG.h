//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)             \n
 * Copyright (c) 2003-2005 by Michal Spanel              \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz           \n
 *          Martin Skotnica, xskotn01@stud.fit.vutbr.cz  \n
 * Date:    2004/03/01                                   \n
 *
 * $Id: mdsSliceSegRG.h 1927 2010-11-07 10:49:52Z spanel $
 *
 * Description:
 * - Simple region growing slice segmentation.
 */

#ifndef MDS_SLICESEGRG_H
#define MDS_SLICESEGRG_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Module providing simple region growing slice segmentation.
 */
class CSliceSegRG : public mds::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    MDS_SHAREDPTR(CSliceSegRG);

public:
    //! Default constructor
    CSliceSegRG(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CSliceSegRG();

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
typedef CSliceSegRG::tSmartPtr  CSliceSegRGPtr;


#endif // MDS_SLICESEGRG_H

