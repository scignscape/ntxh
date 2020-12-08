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
 * Medical Data Segmentation Toolkit (MDSTk)          \n
 * Copyright (c) 2003-2009 by Michal Spanel           \n
 *
 * Authors: Jiri Hutarek, xhutar01@stud.fit.vutbr.cz  \n
 *          Michal Spanel, spanel@fit.vutbr.cz        \n
 * Date:    2008/03/09                                \n
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
 * - Mappings of LBP codes.
 */


//=============================================================================
/*
 * Implementation...
 */

template <ECodeType Type>
void CUniform<Type>::initMapping()
{
//    static const unsigned Min = CLBPTraits<Type>::getMin();
    static const unsigned Max = CLBPTraits<Type>::getMax();

//    m_Map.resize(tSize(Max - Min) + 1);
    m_Map.resize(tSize(Max) + 1);
    m_Map.fill(getDummyValue());

    tIndex Index = 0;
//    for( unsigned i = Min; i <= Max; ++i )
    for( unsigned i = 0; i <= Max; ++i )
    {
        if( CBitOps<tCode,Type>::getNumOfTransitions(tCode(i)) <= 2 )
        {
            m_Map(tSize(i)) = Index++;
        }
    }
}


template <ECodeType Type>
void CRotMin<Type>::initMapping()
{
//    static const unsigned Min = CLBPTraits<Type>::getMin();
    static const unsigned Max = CLBPTraits<Type>::getMax();

//    m_Map.resize(tSize(Max - Min) + 1);
    m_Map.resize(tSize(Max) + 1);
    m_Map.fill(getDummyValue());

    // Helper vector
    vpl::math::CVector<tIndex> Helper;
    Helper.resize(1 << CLBPTraits<Type>::getNumOfSamples());
    Helper.fill(tIndex(-1));

    tIndex Index = 0;
//    for( unsigned i = Min; i <= Max; ++i )
    for( unsigned i = 0; i <= Max; ++i )
    {
        tCode r = CBitOps<tCode,Type>::rotate2Min(tCode(i));
        if( Helper(tSize(r)) == tIndex(-1) )
        {
            Helper(tSize(r)) = Index++;
        }
        m_Map(tSize(i)) = Helper(tSize(r));
    }
    m_Size = Index;
}


template <ECodeType Type>
void CUniformRotMin<Type>::initMapping()
{
//    static const unsigned Min = CLBPTraits<Type>::getMin();
    static const unsigned Max = CLBPTraits<Type>::getMax();

//    m_Map.resize(tSize(Max - Min) + 1);
    m_Map.resize(tSize(Max) + 1);
    m_Map.fill(getDummyValue());

//    for( unsigned i = Min; i <= Max; ++i )
    for( unsigned i = 0; i <= Max; ++i )
    {
        if( CBitOps<tCode,Type>::getNumOfTransitions(tCode(i)) <= 2 )
        {
            m_Map(tSize(i)) = CBitOps<tCode,Type>::getNumOfOnes(tCode(i));
        }
    }
}

