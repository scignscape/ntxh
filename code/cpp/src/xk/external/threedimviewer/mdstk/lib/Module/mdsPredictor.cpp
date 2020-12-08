//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2004-2009 by PGMed@FIT         \n
 *
 * Author:  Radek Barton, ibarton@fit.vutbr.cz  \n
 * Date:    2008/12/03                          \n
 *
 * $Id: mdsPredictor.cpp 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Various compression predictor channels.
 */

#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Base/mdsGlobalLog.h>
#include <MDSTk/Module/mdsPredictor.h>
#include <MDSTk/Image/mdsPixelTraits.h>


namespace mds
{
namespace mod
{

//=============================================================================
/*
 * Implementation of the class CDensityPredictor.
 */

int CDensityPredictor::read(char * data, int length)
{
    static const tValue Shift = mds::img::CPixelTraits<tValue>::getPixelMax() - mds::img::CPixelTraits<tValue>::getPixelMin();

    MDS_ASSERT(sizeof(tValue) == 2 && (length % 2) == 0 && length > 0);

    // Read data from underlying channel
    m_Buffer.create(length);
    if( m_spChannel->read(reinterpret_cast<char *>(m_Buffer.getPtr()), length) != length )
    {
        return 0;
    }

    // Number of values
    int count = length / 2;

    // Initial value
    tValue *pValues = reinterpret_cast<tValue *>(data);
    tValue Last = 0;
    for( int i = 0; i < count; ++i )
    {
        int High = int(m_Buffer(i));
        int Low = int(m_Buffer(count + i));
        int Value = (High << 8) + Low - Shift;
        pValues[i] = tValue(Value) + Last;
        Last = pValues[i];
    }
    return length;
}


bool CDensityPredictor::write(const char * data, int length)
{
    static const tValue Shift = mds::img::CPixelTraits<tValue>::getPixelMax() - mds::img::CPixelTraits<tValue>::getPixelMin();

    MDS_ASSERT(sizeof(tValue) == 2 && (length % 2) == 0 && length > 0);

    // Prepare the buffer
    m_Buffer.create(length);
    int count = length / 2;

    // Initial value
    const tValue *pValues = reinterpret_cast<const tValue *>(data);
    tValue Last = 0;
    for( int i = 0; i < count; ++i )
    {
        // Calculate the difference
        int Diff = int(pValues[i] - Last) + Shift;
        Last = pValues[i];

        // Shift the data
        m_Buffer(i) = (unsigned char)((Diff >> 8) & 255);
        m_Buffer(count + i) = (unsigned char)(Diff & 255);
    }

    // Write the data
    return m_spChannel->write(reinterpret_cast<char *>(m_Buffer.getPtr()), length);
}


} // namespace mod
} // namespace mds
