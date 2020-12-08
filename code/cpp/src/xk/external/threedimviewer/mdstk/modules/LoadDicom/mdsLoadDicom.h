//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/12/18                          \n
 *
 * $Id: mdsLoadDicom.h 1927 2010-11-07 10:49:52Z spanel $
 *
 * File description:
 * - Reads DICOM data from an input channel.
 * - Converts it to the image slice.
 */

#ifndef MDS_LOADDICOM_H
#define MDS_LOADDICOM_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Module loads an image in DICOM format and converts it to the MDSTk image
 * - the mds::img::CSlice class.
 */
class CLoadDicom : public mds::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    MDS_SHAREDPTR(CLoadDicom);

public:
    //! Default constructor
    CLoadDicom(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CLoadDicom();

protected:
    //! Virtual method called on startup
    virtual bool startup();

    //! Virtual method called by the processing thread
    virtual bool main();

    //! Called on console shutdown
    virtual void shutdown();

    //! Called on writing a usage statement
    virtual void writeExtendedUsage(std::ostream& Stream);
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CLoadDicom::tSmartPtr   CLoadDicomPtr;


#endif // MDS_LOADDICOM_H

