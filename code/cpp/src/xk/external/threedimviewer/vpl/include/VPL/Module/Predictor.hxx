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

//=============================================================================
/*
 * Implementation of the class CByteTranspose.
 */

template <typename T>
tSize CByteTranspose<T>::read(char * data, tSize length)
{
    VPL_STATIC_ASSERT(vpl::CTypeTraits<T>::isFundamental, A_given_type_is_not_fundamental);

    VPL_ASSERT((length % sizeof(tValue)) == 0);

    // Read data from underlying channel
    m_Buffer.resize(length);
    if( m_spChannel->read(m_Buffer.getPtr(), length) != length )
    {
        return 0;
    }

    // Transpose the data
    tSize count = length / sizeof(tValue);
    for( int i = 0; i < count; ++i )
    {
        for( int j = 0; j < sizeof(tValue); ++j )
        {
            data[i * sizeof(tValue) + j] = m_Buffer(j * count + i);
        }
    }
    return length;
}


template <typename T>
bool CByteTranspose<T>::write(const char * data, tSize length)
{
    VPL_STATIC_ASSERT(vpl::CTypeTraits<T>::isFundamental, A_given_type_is_not_fundamental);

    VPL_ASSERT((length % sizeof(tValue)) == 0);

    // Transpose the data
    m_Buffer.resize(length);
    tSize count = length / sizeof(tValue);
    for( int i = 0; i < count; ++i )
    {
        for( int j = 0; j < sizeof(tValue); ++j )
        {
            m_Buffer(j * count + i) = data[i * sizeof(tValue) + j];
        }
    }

    // Write the data
    return m_spChannel->write(m_Buffer.getPtr(), length);
}

