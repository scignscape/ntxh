//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)          \n
 * Copyright (c) 2003-2009 by Michal Spanel           \n
 *
 * Authors: Jiri Hutarek, xhutar01@stud.fit.vutbr.cz  \n
 *          Michal Spanel, spanel@fit.vutbr.cz        \n
 * Date:    2008/01/27                                \n
 *
 * $Id: mdsSliceLBPExtract.h 1927 2010-11-07 10:49:52Z spanel $
 *
 * File description:
 * - Extracts LBP codes from an image.
 */

#ifndef MDS_SliceLBPExtract_H
#define MDS_SliceLBPExtract_H

#include <MDSTk/Base/mdsSetup.h>
#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Extracts LBP codes from an input slice.
 */
class CSliceLBPExtract : public mds::mod::CModule
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    MDS_SHAREDPTR(CSliceLBPExtract);

public:
    //! Default constructor.
    CSliceLBPExtract(const std::string& sDescription);

    //! Virtual destructor.
    virtual ~CSliceLBPExtract();

protected:
    //! Virtual method called on startup.
    virtual bool startup();

    //! Virtual method called by the processing thread.
    virtual bool main();

    //! Called on console shutdown.
    virtual void shutdown();

    //! Called on writing an usage statement.
    virtual void writeExtendedUsage(std::ostream& Stream);

protected:
    //! Command line arguments.
    std::string m_ssMapping;
    int m_X, m_Y, m_Width, m_Height, m_NumOfSamples;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceLBPExtract::tSmartPtr CSliceLBPExtractPtr;


#endif // MDS_SliceLBPExtract_H

