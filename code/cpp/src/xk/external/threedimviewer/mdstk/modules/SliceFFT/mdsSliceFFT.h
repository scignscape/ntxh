//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)	\n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/08/09                          \n
 *
 * $Id: mdsSliceFFT.h 1927 2010-11-07 10:49:52Z spanel $
 *
 * File description:
 * - Computes two-dimensional DFT of an input slice.
 */

#ifndef MDS_SLICEFFT_H
#define MDS_SLICEFFT_H

#include <MDSTk/Module/mdsModule.h>


//==============================================================================
/*!
 * Module computes DFT of an input slice.
 */
class CSliceFFT : public mds::mod::CModule
{
public:
    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    MDS_SHAREDPTR(CSliceFFT);

public:
    //! Default constructor.
    CSliceFFT(const std::string& sDescription);

    //! Virtual destructor.
    virtual ~CSliceFFT();

protected:
    //! Virtual method called on startup.
    virtual bool startup();

    //! Virtual method called by the processing thread.
    virtual bool main();

    //! Called on console shutdown.
    virtual void shutdown();

    //! Called on writing a usage statement.
    virtual void writeExtendedUsage(std::ostream& Stream);

protected:
    //! Output of the module.
    enum EResultType
    {
        R_REAL, R_IMAG, R_ABS, R_ARG
    };

protected:
    //! Module parameters.
    bool m_bShift, m_bLog;
    EResultType m_eResult;
};


//==============================================================================
/*!
 * Smart pointer to console application.
 */
typedef CSliceFFT::tSmartPtr  CSliceFFTPtr;


#endif // MDS_SLICEFFT_H

