//==============================================================================
/* This file comes from MDSTk software and was modified for
 * 
 * VPL - Voxel Processing Library
 * Changes are Copyright 2014 3Dim Laboratory s.r.o.
 * All rights reserved.
 * 
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 * 
 * The original MDSTk legal notice can be found below.
 * 
 * Medical Data Segmentation Toolkit (MDSTk) 
 * Copyright (c) 2003-2007 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/04/16                       
 *
 * Description:
 * - Base class for any histogram class.
 */

#ifndef VPL_HISTOGRAMBASE_H
#define VPL_HISTOGRAMBASE_H

#include <VPL/Math/Vector.h>


namespace vpl
{
namespace img
{

//==============================================================================
/*!
 * Base class for all histogram classes.
 * - Base class takes a template parameter H. This parameter is the type
 *   of the class which derives from it (so called curiously recurring template
 *   pattern).
 */
template <class H>
class CHistogramBase
{
public:
    //! Concrete histogram type.
    typedef H tHistogram;

public:
    //! Returns reference to the histogram implementation.
    tHistogram& getImpl()
    {
        return *static_cast<tHistogram *>(this);
    }
    const tHistogram& getImpl() const
    {
        return *static_cast<const tHistogram *>(this);
    }

protected:
    //! Default constructor.
    CHistogramBase() {}

    //! Copy constructor.
    CHistogramBase(const CHistogramBase&) {}

    //! Assignment operator.
    CHistogramBase& operator =(const CHistogramBase&) { return *this; }
};


} // namespace img
} // namespace vpl

#endif // VPL_HISTOGRAMBASE_H

