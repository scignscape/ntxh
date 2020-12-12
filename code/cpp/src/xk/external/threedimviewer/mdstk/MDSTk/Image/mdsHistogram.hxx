//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/02/10                          \n
 *
 * $Id: mdsHistogram.hxx 2100 2012-02-17 07:36:55Z spanel $
 * 
 * Description:
 * - Histogram computation.
 */


//==============================================================================
/*
 * Methods templates.
 */

// Estimates quantized histogram of a given container
template <typename C>
inline CHistogram<C>::CHistogram(tSize NumOfBins,
                                 tItem Min,
                                 tItem Max
                                 )
    : m_Min(Min)
    , m_Max(Max)
    , m_Histogram(NumOfBins)
{
	// Check whether the container item is a fundamental type,
	// e.g. float, int and so on
	MDS_STATIC_ASSERT(CTypeTraits<tItem>::isFundamental,
	                  HISTOGRAM_ITEM_IS_NOT_A_FUNDAMENTAL_TYPE
	                  );

    // Check histogram size and allowed range
    MDS_ASSERT(NumOfBins > 0 && Max >= Min);

    // Initialize the histogram
    m_Histogram.fill(tBin(0));

    // Compute the bin size
    tItem Span = m_Max - m_Min;
    m_BinSize =  Span / tItem(NumOfBins);
    if( (m_BinSize * tItem(NumOfBins)) < Span )
    {
        m_BinSize += tItem(1);
    }
}


// Estimates quantized histogram of a given container
template <typename C>
bool CHistogram<C>::operator ()(const tContainer& Container)
{
    // Compute per item statistics
    for( tContainerIterator it(Container); it; ++it )
    {
        tItem Value = *it;
        if( Value >= m_Min && Value <= m_Max )
        {
            ++m_Histogram(getIndex(Value));
        }
    }

    // O.K.
    return true;
}


// Estimates cumulative histogram
template <typename C>
void CHistogram<C>::cumulate()
{
    // Compute per item statistics
    for( tSize i = 1; i < m_Histogram.getSize(); ++i )
    {
        m_Histogram(i) += m_Histogram(i - 1);
    }
}


// Estimates full histogram of a given container
template <typename C>
inline CFullHistogram<C>::CFullHistogram(tItem Min, tItem Max)
    : m_Min(Min)
    , m_Max(Max)
    , m_Histogram(Max - Min + 1)
{
	// Check whether the container item is a fundamental integral type
	MDS_STATIC_ASSERT(CTypeTraits<tItem>::isFundamental && CTypeTraits<tItem>::isIntegral,
	                  HISTOGRAM_ITEM_IS_NOT_A_FUNDAMENTAL_INTEGRAL_TYPE
	                  );

    // Check allowed range
    MDS_ASSERT(Max >= Min);

    // Initialize the histogram
    m_Histogram.fill(tBin(0));
}


// Estimates histogram of a given image
template <typename C>
bool CFullHistogram<C>::operator ()(const tContainer& Container)
{
    // Compute per item statistics
    for( tContainerIterator it(Container); it; ++it )
    {
        tItem Value = *it;
        if( Value >= m_Min && Value <= m_Max )
        {
            ++m_Histogram(getIndex(Value));
        }
    }

    // O.K.
    return true;
}


// Estimates cumulative histogram
template <typename C>
void CFullHistogram<C>::cumulate()
{
    // Compute per item statistics
    for( tSize i = 1; i < m_Histogram.getSize(); ++i )
    {
        m_Histogram(i) += m_Histogram(i - 1);
    }
}
