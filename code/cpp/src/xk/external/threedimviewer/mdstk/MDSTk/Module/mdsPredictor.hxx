//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2004-2009 by PGMed@FIT         \n
 *
 * Author:  Radek Barton, ibarton@fit.vutbr.cz  \n
 * Date:    2008/12/03                          \n
 *
 * $Id: mdsPredictor.hxx 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Various compression predictor channels.
 */

//=============================================================================
/*
 * Implementation of the class CByteTranspose.
 */

template <typename T>
int CByteTranspose<T>::read(char * data, int length)
{
    MDS_STATIC_ASSERT(mds::CTypeTraits<T>::isFundamental, A_given_type_is_not_fundamental);

    MDS_ASSERT((length % sizeof(tValue)) == 0);

    // Read data from underlying channel
    m_Buffer.create(length);
    if( m_spChannel->read(m_Buffer.getPtr(), length) != length )
    {
        return 0;
    }

    // Transpose the data
    int count = length / sizeof(tValue);
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
bool CByteTranspose<T>::write(const char * data, int length)
{
    MDS_STATIC_ASSERT(mds::CTypeTraits<T>::isFundamental, A_given_type_is_not_fundamental);

    MDS_ASSERT((length % sizeof(tValue)) == 0);

    // Transpose the data
    m_Buffer.create(length);
    int count = length / sizeof(tValue);
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

