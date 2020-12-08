//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)	\n
 * Copyright (c) 2003-2009 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2008/12/19                          \n
 *
 * $Id: mdsSliceAffineTransform.h 1927 2010-11-07 10:49:52Z spanel $
 *
 * File description:
 * - Affine image transformation.
 */

#ifndef MDS_SliceAffineTransform_H
#define MDS_SliceAffineTransform_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Module provides geometric transformations of an input image.
 */
class CSliceAffineTransform : public mds::mod::CModule
{
public:
    //! Smart pointer type
    //! - Declares type tSmartPtr
    MDS_SHAREDPTR(CSliceAffineTransform);

public:
    //! Default constructor
    CSliceAffineTransform(const std::string& sDescription);

    //! Virtual destructor
    virtual ~CSliceAffineTransform();

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
    //! Module parameters.
    double m_dSX, m_dSY, m_dTX, m_dTY;
    bool m_bResize;
    int m_iMarginValue, m_iAlpha;
    std::string m_ssInterpolatorName;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceAffineTransform::tSmartPtr  CSliceAffineTransformPtr;


#endif // MDS_SliceAffineTransform_H

