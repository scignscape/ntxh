//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/03/29                          \n
 *
 * $Id: mdsLoadPNG.h 1927 2010-11-07 10:49:52Z spanel $
 *
 * File description:
 * - Reads PNG image from an input channel.
 * - Converts it to the slice format.
 */

#ifndef MDS_LOADPNG_H
#define MDS_LOADPNG_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Module loads PNG image and converts it to the MDSTk format.
 */
class CLoadPNG : public mds::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    MDS_SHAREDPTR(CLoadPNG);

public:
    //! Default constructor
    CLoadPNG(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CLoadPNG();

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
typedef CLoadPNG::tSmartPtr     CLoadPNGPtr;


#endif // MDS_LOADPNG_H

