//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2007 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/04/16                          \n
 *
 * $Id: mdsHistogramBase.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Base class for any histogram class.
 */

#ifndef MDS_HISTOGRAMBASE_H
#define MDS_HISTOGRAMBASE_H

#include <MDSTk/Math/mdsVector.h>


namespace mds
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
} // namespace mds

#endif // MDS_HISTOGRAMBASE_H

