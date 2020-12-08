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
 * Copyright (c) 2004-2009 by PGMed@FIT      
 *
 * Author:  Radek Barton, ibarton@fit.vutbr.cz  \n
 * Date:    2008/12/03                       
 *
 * Description:
 * - Various compression predictor channels.
 */

#include <VPL/Base/Assert.h>
#include <VPL/Base/Logging.h>
#include <VPL/Module/Predictor.h>
#include <VPL/Image/PixelTraits.h>


namespace vpl
{
namespace mod
{

//=============================================================================
/*
 * Implementation of the class CDensityPredictor.
 */

tSize CDensityPredictor::read(char * data, tSize length)
{
    static const tValue Shift = vpl::img::CPixelTraits<tValue>::getPixelMax() - vpl::img::CPixelTraits<tValue>::getPixelMin();

    VPL_ASSERT(sizeof(tValue) == 2 && (length % 2) == 0 && length > 0);

    // Read data from underlying channel
    m_Buffer.resize(length);
    if( m_spChannel->read(reinterpret_cast<char *>(m_Buffer.getPtr()), length) != length )
    {
        return 0;
    }

    // Number of values
    tSize count = length / 2;

    // Initial value
    tValue *pValues = reinterpret_cast<tValue *>(data);
    tValue Last = 0;
    for( tSize i = 0; i < count; ++i )
    {
		int High = int(m_Buffer(i));
		int Low = int(m_Buffer(count + i));
        int Value = (High << 8) + Low - Shift;
        pValues[i] = tValue(Value) + Last;
        Last = pValues[i];
    }
    return length;
}


bool CDensityPredictor::write(const char * data, tSize length)
{
    static const tValue Shift = vpl::img::CPixelTraits<tValue>::getPixelMax() - vpl::img::CPixelTraits<tValue>::getPixelMin();

    VPL_ASSERT(sizeof(tValue) == 2 && (length % 2) == 0 && length > 0);

    // Prepare the buffer
    m_Buffer.resize(length);
    tSize count = length / 2;

    // Initial value
    const tValue *pValues = reinterpret_cast<const tValue *>(data);
    tValue Last = 0;
    for( tSize i = 0; i < count; ++i )
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
} // namespace vpl
