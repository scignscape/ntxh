//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2009 by Michal Spanel          \n
 *
 * Authors: Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2009/01/15                          \n
 *
 * $Id: mdsPixelStatsExtractor.hxx 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Extraction of basic statistics from any set of image pixels.
 */


//==============================================================================
/*
 * Implementation of the class CPixelStatsExtractor.
 */

template <typename T>
inline CPixelStatsExtractor<T>& CPixelStatsExtractor<T>::operator =(const CPixelStatsExtractor& Extractor)
{
    m_dSum = Extractor.m_dSum;
    m_dSumSqr = Extractor.m_dSumSqr;
    m_iNumOfPixels = Extractor.m_iNumOfPixels;

    return *this;
}


template <typename T>
inline void CPixelStatsExtractor<T>::accumulate(tPixel Value)
{
    m_dSum += double(Value);
    m_dSumSqr += double(Value) * double(Value);
    ++m_iNumOfPixels;
}


template <typename T>
inline void CPixelStatsExtractor<T>::accumulate(const CPixelStatsExtractor& Extractor)
{
    m_dSum += Extractor.m_dSum;
    m_dSumSqr += Extractor.m_dSumSqr;
    m_iNumOfPixels += Extractor.m_iNumOfPixels;
}


template <typename T>
void CPixelStatsExtractor<T>::evaluate(tVector& Vector)
{
    // Clear the whole feature vector
    Vector.fill(0);

    // Set the number of pixels
    Vector.setNumOfSamples(m_iNumOfPixels);

    // Check the number of pixels
    double dInvCount = 1.0;
    if( m_iNumOfPixels > 0 )
    {
        dInvCount /= m_iNumOfPixels;
    }
    else
    {
        // Set the error code
        Vector.setState(FeatureVector::NOT_EVALUATED);

        // Throw exception
        throw FeatureVector::CCannotEvaluate();
    }

    double dMean = m_dSum * dInvCount;
    double dVariance = m_dSumSqr * dInvCount - (dMean * dMean);

    Vector.setMean(dMean);
//    Vector.setVariance(std::sqrt(dVariance));
    Vector.setVariance(dVariance);
}


template <typename T>
inline void CPixelStatsExtractor<T>::clear()
{
    m_dSum = 0.0;
    m_dSumSqr = 0.0;
    m_iNumOfPixels = 0;
}

