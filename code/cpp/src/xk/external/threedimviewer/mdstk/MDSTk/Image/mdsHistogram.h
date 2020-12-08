//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/02/10                          \n
 *
 * $Id: mdsHistogram.h 2096 2012-02-16 19:34:46Z spanel $
 *
 * Description:
 * - Histogram computation.
 */

#ifndef MDS_HISTOGRAM_H
#define MDS_HISTOGRAM_H

#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Base/mdsStaticAssert.h>
#include <MDSTk/Base/mdsTypeTraits.h>
#include <MDSTk/Math/mdsVector.h>
#include <MDSTk/Math/mdsVectorFunctions.h>

#include "mdsHistogramBase.h"


namespace mds
{
namespace img
{

//==============================================================================
/*!
 * Quantized histogram having predefined number of bins/columns.
 * - Parameter C is a container type whose items will be counted.
 * - Only fundamental types (int, long, float, etc.) of container items
 *   are allowed.
 */
template <typename C>
class CHistogram : public CHistogramBase<CHistogram<C> >
{
public:
    //! Check that C has an iterator declared. You will see name of this enum somewhere
    //! in compiler error message if the type C can't be used with iterators.
    enum { NO_ITERATOR_IS_DECLARED_FOR_TEMPLATE_PARAMETER = C::ITERATOR_DECLARED };

    //! Container type.
    typedef C tContainer;

    //! Container iterator type.
    typedef typename C::tConstIterator tContainerIterator;

    //! Container item type.
//    typedef typename CTypeTraits<typename tContainerIterator::tItem>::tNonConst tItem;
    typedef typename C::tIterator::tItem tItem;

    //! Histogram bin type.
//    typedef unsigned long tBin;
    typedef int tBin;

    //! Internal histogram representation.
    typedef mds::math::CVector<tBin> tVector;

    //! Default number of bins in the histogram.
    static const int DEFAULT_NUM_OF_BINS = 64;

public:
    //! Constructor that creates a new empty histogram.
    //! - Parameter Size specifies the number of histogram bins.
    //! - Min and Max gives range of item values.
    inline CHistogram(tSize NumOfBins = DEFAULT_NUM_OF_BINS,
                      tItem Min = CTypeTraits<tItem>::getMin(),
                      tItem Max = CTypeTraits<tItem>::getMax()
                      );

    //! Destructor.
    ~CHistogram() {}


    //! Returns the number of histogram bins.
    tSize getSize() const { return m_Histogram.getSize(); }

    //! Computes and returns histogram bin index.
    tSize getIndex(tItem Value) const { return tSize((Value - m_Min) / m_BinSize); }

    //! Returns value of a given histogram bin.
    tBin getCount(tSize Index) const { return m_Histogram.at(Index); }

    //! Returns sum of all histogram bins.
    tBin getTotalCount() const { return mds::math::getSum<tBin>(m_Histogram); }

    //! Returns lower bound of item value of a specified histogram bin.
    tItem getLowerBound(tSize Index) const { return (m_Min + tItem(Index * m_BinSize)); }

    //! Returns maximal histogram value.
    tBin getMax() const { return mds::math::getMax<tBin>(m_Histogram); }

    //! Returns vector representing the computed histogram.
    const tVector& getHistogram() const { return m_Histogram; }


    //! Computes histogram of all container items.
    //! - Returns false on failure.
    bool operator()(const tContainer& Container);

    //! Creates the cumulative histogram.
    void cumulate();

protected:
    //! Minimal and maximal allowed container item value.
    tItem m_Min, m_Max;

    //! Histogram bin size.
    tItem m_BinSize;

    //! Histogram.
    tVector m_Histogram;
};


//==============================================================================
/*!
 * Histogram having number of bins/columns corresponding to a number of possible
 * item values.
 * - Parameter C is a container type whose items will be counted.
 * - Only fundamental integral types (int, long, etc.) of container items
 *   are allowed.
 */
template <typename C>
class CFullHistogram : public CHistogramBase<CFullHistogram<C> >
{
public:
    //! Check that C has an iterator declared. You will see name of this enum somewhere
    //! in compiler error message if the type C can't be used with iterators.
    enum { NO_ITERATOR_IS_DECLARED_FOR_TEMPLATE_PARAMETER = C::ITERATOR_DECLARED };

    //! Container type.
    typedef C tContainer;

    //! Container iterator type.
    typedef typename C::tConstIterator tContainerIterator;

    //! Container item type.
    typedef typename CTypeTraits<typename tContainerIterator::tItem>::tNonConst tItem;

    //! Histogram bin type.
//    typedef unsigned long tBin;
    typedef int tBin;

    //! Internal histogram representation.
    typedef mds::math::CVector<tBin> tVector;

public:
    //! Constructor that creates a new empty histogram.
    //! - Min and Max gives range of item values.
    inline CFullHistogram(tItem Min = CTypeTraits<tItem>::getMin(),
                          tItem Max = CTypeTraits<tItem>::getMax()
                          );

    //! Destructor.
    ~CFullHistogram() {}


    //! Returns the number of histogram bins.
    tSize getSize() const { return m_Histogram.getSize(); }

    //! Computes and returns histogram bin index.
    tSize getIndex(tItem Value) const { return tSize(Value - m_Min); }

    //! Returns value of a given histogram bin.
    tBin getCount(tSize Index) const { return m_Histogram.at(Index); }

    //! Returns sum of all histogram bins.
    tBin getTotalCount() const { return mds::math::getSum<tBin>(m_Histogram); }

    //! Returns lower bound of item value of a specified histogram bin.
    tItem getLowerBound(tSize Index) const { return (m_Min + tItem(Index)); }

    //! Returns maximal histogram value.
    tBin getMax() const { return mds::math::getMax<tBin>(m_Histogram); }

    //! Returns vector representing the computed histogram.
    const tVector& getHistogram() const { return m_Histogram; }


    //! Computes histogram of all container items.
    //! - Returns false on failure.
    bool operator()(const tContainer& Container);

    //! Creates the cumulative histogram.
    void cumulate();

protected:
    //! Minimal and maximal allowed container item value.
    tItem m_Min, m_Max;

    //! Histogram.
    tVector m_Histogram;
};


//==============================================================================
/*
 * Methods templates.
 */

// Include file containing methods templates
#include "mdsHistogram.hxx"


} // namespace img
} // namespace mds

#endif // MDS_HISTOGRAM_H

