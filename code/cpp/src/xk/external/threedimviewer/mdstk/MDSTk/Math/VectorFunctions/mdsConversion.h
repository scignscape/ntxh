//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/09/15                          \n
 *
 * $Id: mdsConversion.h 1707 2010-05-05 11:00:46Z spanel $
 *
 * Description:
 * - Vector conversion functions.
 */

#ifndef MDS_VectorFunctions_Conversion_H
#define MDS_VectorFunctions_Conversion_H

#include <MDSTk/Base/mdsStaticAssert.h>
#include <MDSTk/Math/mdsStaticVector.h>


namespace mds
{
namespace math
{

//==============================================================================
/*
 * Helper definitions.
 */

//! Helper structure used to create vector from fundamental types.
struct SFundamentalType {};

//! Helper structure used to create vector from fundamental types.
struct SVectorType {};


//! Helper structure used to create vector from fundamental types.
template <typename T>
struct SMakeVector
{
    //! True if type T is fundamental.
    enum { isFundamental = mds::CTypeTraits<T>::isFundamental };

    //! Type of the operation.
    typedef typename SSelect<isFundamental, SFundamentalType, SVectorType>::RESULT tType;

    //! Result of the operation.
    typedef typename SSelect<isFundamental, CStaticVector<T,1>, T>::RESULT tResult;
};


//==============================================================================
/*
 * Global functions.
 */

//! Returns reference to a vector.
//! - If type T is a fundamental type, static vector of size 1 is returned.
template <typename T>
inline typename SMakeVector<T>::tResult makeVector(const T& Value);


//==============================================================================
/*
 * Functions templates.
 */

// Include the file containing functions templates.
#include "mdsConversion.hxx"


} // namespace math
} // namespace mds

#endif // MDS_VectorFunctions_Conversion_H

