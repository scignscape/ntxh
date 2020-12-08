//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)           \n
 * Copyright (c) 2003-2005 by Michal Spanel            \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz         \n
 *          Miroslav Svub, xsvubm00@stud.fit.vutbr.cz  \n
 * Date:    2004/10/24                                 \n
 *
 * $Id: mdsSliceSegHT.h 1927 2010-11-07 10:49:52Z spanel $
 *
 * File description:
 * - Simple segmentation method based on histogram thresholding.
 */

#ifndef MDS_SLICESEGHT_H
#define MDS_SLICESEGHT_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Module provides segmentation method based on histogram thresholding.
 */
class CSliceSegHT : public mds::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    MDS_SHAREDPTR(CSliceSegHT);

public:
    //! Default constructor
    CSliceSegHT(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CSliceSegHT();

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
typedef CSliceSegHT::tSmartPtr  CSliceSegHTPtr;


#endif // MDS_SLICESEGHT_H

