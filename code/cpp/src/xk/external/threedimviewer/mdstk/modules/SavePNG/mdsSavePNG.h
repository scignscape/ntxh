//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/03/30                          \n
 *
 * $Id: mdsSavePNG.h 1927 2010-11-07 10:49:52Z spanel $
 *
 * File description:
 * - Converts an input slice to PNG image format.
 */

#ifndef MDS_SAVEPNG_H
#define MDS_SAVEPNG_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Module converts an input slice to the PNG image format.
 */
class CSavePNG : public mds::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    MDS_SHAREDPTR(CSavePNG);

public:
    //! Default constructor
    CSavePNG(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CSavePNG();

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
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSavePNG::tSmartPtr     CSavePNGPtr;


#endif // MDS_SAVEPNG_H

