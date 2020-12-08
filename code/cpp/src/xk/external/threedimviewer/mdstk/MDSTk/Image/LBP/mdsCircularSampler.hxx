//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)          \n
 * Copyright (c) 2003-2009 by Michal Spanel           \n
 *
 * Authors: Jiri Hutarek, xhutar01@stud.fit.vutbr.cz  \n
 *          Michal Spanel, spanel@fit.vutbr.cz        \n
 * Date:    2008/03/09                                \n
 *
 * $Id: mdsCircularSampler.hxx 2100 2012-02-17 07:36:55Z spanel $
 *
 * This code is partially based on the free software
 * Cpplibs C++ libraries and PRAPI - The Pattern Recognition Application
 *   Programmer's Interface.
 *
 * The Cpplibs and PRAPI suite
 * Copyright (C) 2001 Topi M�enp�� and Jaakko Viertola
 * All rights reserved.
 * Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions
 *   are met:
 *
 *       1.Redistributions of source code must retain all copyright
 *         notices, this list of conditions and the following disclaimer.
 *       2.Redistributions in binary form must reproduce the above
 *         copyright notice, this list of conditions and the following
 *         disclaimer in the documentation and/or other materials provided
 *         with the distribution.
 *       3.The name(s) of the author(s) may not be used to endorse or
 *         promote products derived from this software without specific
 *         prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS
 *   OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 *   WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *   DISCLAIMED. IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT,
 *   INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 *   (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 *   SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 *   HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 *   STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 *   IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *   POSSIBILITY OF SUCH DAMAGE.
 *
 * Description:
 * - Circle sampling of image pixels given a radius and a number of samples.
 */


//=============================================================================
/*
 * Implementation of the class CCircularSampler<T>.
 */

template <class I>
inline bool CCircularSampler<I>::getSamples(tSize x, tSize y, tSamples& Result)
{
    if( !m_spImage.get() )
    {
        return false;
    }

    MDS_ASSERT(m_spImage->checkPosition(x, y));

    Result.resize(m_NumOfSamples);

    for( int i = 0; i < m_NumOfSamples; ++i )
    {
        Result[i] = m_spImage->interpolate(mds::img::CPoint3D(m_Coords[i].x() + x, m_Coords[i].y() + y));
    }

    // O.K.
    return true;
}


template <class I>
inline typename CCircularSampler<I>::tPixel CCircularSampler<I>::getCenter(tSize x, tSize y)
{
//    return (m_spImage.get()) ? m_spImage->get(x, y) : tPixel(0);

    MDS_ASSERT(m_spImage.get() && m_spImage->checkPosition(x, y));

    return m_spImage->at(x, y);
}


template <class I>
template <class Function>
inline Function CCircularSampler<I>::forEach(tSize x, tSize y, Function Func)
{
//    if( m_spImage.get() && m_spImage->checkPosition(x, y) )
    {
        MDS_ASSERT(m_spImage.get() && m_spImage->checkPosition(x, y));

        for( int i = 0; i < m_NumOfSamples; ++i )
        {
            Func(m_spImage->interpolate(mds::img::CPoint3D(m_Coords[i].x() + x, m_Coords[i].y() + y)));
        }
    }
    return Func;
}


template <class I>
inline void CCircularSampler<I>::updateCoords()
{
    m_Coords.resize(m_NumOfSamples);

    if( m_NumOfSamples == 8 && m_Radius == 1.0 )
    {
        // Set original LBP values (no interpolated samples)
        m_Coords[0] = mds::img::CPoint3D(1.0, 0.0);
        m_Coords[1] = mds::img::CPoint3D(1.0, 1.0);
        m_Coords[2] = mds::img::CPoint3D(0.0, 1.0);
        m_Coords[3] = mds::img::CPoint3D(-1.0, 1.0);
        m_Coords[4] = mds::img::CPoint3D(-1.0, 0.0);
        m_Coords[5] = mds::img::CPoint3D(-1.0, -1.0);
        m_Coords[6] = mds::img::CPoint3D(0.0, -1.0);
        m_Coords[7] = mds::img::CPoint3D(1.0, -1.0);
    }
    else
    {
        // Angle between two samples
        double dAngle = mds::math::TWO_PI / double(m_NumOfSamples);
        m_Coords[0] = mds::img::CPoint3D(m_Radius, 0.0);

        // Other samples, CCW
        for( int i = 1; i < m_NumOfSamples; ++i )
        {
            m_Coords[i] = mds::img::CPoint3D(m_Radius * std::cos(i * dAngle), m_Radius * std::sin(i * dAngle));
        }
    }
}

