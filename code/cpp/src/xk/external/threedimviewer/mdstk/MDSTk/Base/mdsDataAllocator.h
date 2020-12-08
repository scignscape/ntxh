//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2011 by Michal Spanel          \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2011/05/29                          \n
 *
 * $Id:$
 *
 * Description:
 * - Data allocator policy.
 */

#ifndef MDS_DataAllocator_H
#define MDS_DataAllocator_H

#include "mdsAssert.h"
#include "mdsTypes.h"
#include "mdsMemory.h"
#include "mdsException.h"
#include "mdsMeta.h"
#include "mdsEmptyConst.h"


namespace mds
{
namespace base
{

//==============================================================================
/*!
 * Base class for all filter response normalization policies.
 * - Parameter T is a pixel type.
 */
template <typename T>
struct CDataAllocator
{
    //! Data type.
    typedef T tData;

    //! Pointer to the data.
    typedef T *tDataPtr;

    //! Const data type.
    typedef const T tConstData;

    //! Pointer to the constant data.
    typedef const T *tConstDataPtr;
};


} // namespace base
} // namespace mds

#endif // MDS_DataAllocator_H

