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
 * Copyright (c) 2003-2009 by Michal Spanel        
 *
 * Authors: Jiri Hutarek, xhutar01@stud.fit.vutbr.cz  \n
 *          Michal Spanel, spanel@fit.vutbr.cz     
 * Date:    2008/03/09                             
 *
 * This code is partially based on the free software
 * Cpplibs C++ libraries and PRAPI - The Pattern Recognition Application
 *   Programmer's Interface.
 *
 * The Cpplibs and PRAPI suite
 * Copyright (C) 2001 Topi M‰enp‰‰ and Jaakko Viertola
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

#ifndef VPL_LBP_Mapping_H
#define VPL_LBP_Mapping_H

#include "Traits.h"
#include "BitOps.h"

#include <VPL/Math/Vector.h>
#include <VPL/Base/Logging.h>


namespace vpl
{
namespace lbp
{

//=============================================================================
/*!
 * Base class for implementation of different LBP mapping policies.
 */
template <ECodeType Type, EMappingType Mapping>
struct CMappingBase
{
    //! Type representing the LBP code.
    typedef typename CLBPTraits<Type>::tCode tCode;

    //! Type representing the output index.
    typedef unsigned int tIndex;

    //! Number of distinct values produced by the mapping.
    enum { Size = CLBPTraits<Type,Mapping>::NumOfCodes };
};


//=============================================================================
/*!
 * Plain LBP mapping - values are mapped to themselves.
 */
template <ECodeType Type>
class CPlain : public CMappingBase<Type, Plain>
{
public:
    // Base types.
    typedef CMappingBase<Type, Plain> tBase;
    typedef typename tBase::tCode tCode;
    typedef typename tBase::tIndex tIndex;

public:
    //! Returns the index the particular LBP code should be mapped to.
    static tIndex map(tCode Value)
    {
        return tIndex(Value);
    }

    //! Returns the dummy value which doesn't occur normally.
    static tIndex getDummyValue()
    {
        return tIndex(-1);
    }

    //! Returns the number of distinct values the mapping can
    //! produce. This is useful in determining the length of the
    //! resulting feature vector when the mapping is in use.
    static tIndex getSize()
    {
//        return (1u << CLBPTraits<Type>::getNumOfSamples());
        return tIndex(tBase::Size);
    }
};


//=============================================================================
/*!
 * Uniform LBP mapping - a LBP code is mapped to an index, if it contains
 * at most two 1->0 or 0->1 transitions. Otherwise, it is mapped to a dummy
 * value which doesn't occur normally.
 * - Parameter Mapping is a mapping type.
 */
template <ECodeType Type>
class CUniform : public CMappingBase<Type, Uniform>
{
public:
    // Base types.
    typedef CMappingBase<Type, Uniform> tBase;
    typedef typename tBase::tCode tCode;
    typedef typename tBase::tIndex tIndex;

public:
    //! Default constructor.
    CUniform() { initMapping(); }

    //! Returns the index the particular LBP code should be mapped to.
    tIndex map(tCode Value)
    {
        return m_Map(tSize(Value));
    }

    //! Returns the dummy value which doesn't occur normally.
    static tIndex getDummyValue()
    {
        static const tIndex Dummy = tIndex(getSize() - 1);
        return Dummy;
    }

    //! Returns the number of distinct values the mapping can
    //! produce. This is useful in determining the length of the
    //! resulting feature vector when the mapping is in use.
    static tIndex getSize()
    {
//        static const tIndex Samples = tIndex(CLBPTraits<Type>::getNumOfSamples());
//        return Samples * (Samples - 1) + 3;
        return tIndex(tBase::Size);
    }

protected:
    //! Lookup table.
    vpl::math::CVector<tIndex> m_Map;

protected:
    //! Initalizes the mapping table.
    void initMapping();
};


//=============================================================================
/*!
 * Rotation invariant LBP mapping.
 * - LBP codes are binary rotated to get a minimal value.
 * - Parameter Mapping is a mapping type.
 */
template <ECodeType Type>
class CRotMin : public CMappingBase<Type, RotMin>
{
public:
    // Base types.
    typedef CMappingBase<Type, RotMin> tBase;
    typedef typename tBase::tCode tCode;
    typedef typename tBase::tIndex tIndex;

public:
    //! Default constructor.
    CRotMin() { initMapping(); }

    //! Returns the index the particular LBP code should be mapped to.
    tIndex map(tCode Value)
    {
        return m_Map(tSize(Value));
    }

    //! Returns the dummy value which doesn't occur normally.
    tIndex getDummyValue()
    {
        static const tIndex Dummy = tIndex(getSize() - 1);
        return Dummy;
    }

    //! Returns the number of distinct values the mapping can
    //! produce. This is useful in determining the length of the
    //! resulting feature vector when the mapping is in use.
    tIndex getSize()
    {
//        return tIndex(tBase::Size);
        return m_Size;
    }

protected:
    //! Lookup table.
    vpl::math::CVector<tIndex> m_Map;

    //! Number of distinct values.
    tIndex m_Size;

protected:
    //! Initalizes the mapping table.
    void initMapping();
};


//=============================================================================
/*!
 * Uniform rotation invariant LBP mapping.
 * - Only the uniform codes are taken into account.
 * - LBP codes are binary rotated to get a minimal value.
 * - Parameter Mapping is a mapping type.
 */
template <ECodeType Type>
class CUniformRotMin : public CMappingBase<Type, UniformRotMin>
{
public:
    // Base types.
    typedef CMappingBase<Type, UniformRotMin> tBase;
    typedef typename tBase::tCode tCode;
    typedef typename tBase::tIndex tIndex;

public:
    //! Default constructor.
    CUniformRotMin() { initMapping(); }

    //! Returns the index the particular LBP code should be mapped to.
    tIndex map(tCode Value)
    {
//        VPL_LOG_INFO(unsigned(Value) << "->" << m_Map(tSize(Value)));
        return m_Map(tSize(Value));
    }

    //! Returns the dummy value which doesn't occur normally.
    static tIndex getDummyValue()
    {
        static const tIndex Dummy = tIndex(getSize() - 1);
        return Dummy;
    }

    //! Returns the number of distinct values the mapping can
    //! produce. This is useful in determining the length of the
    //! resulting feature vector when the mapping is in use.
    static tIndex getSize()
    {
//        static const tIndex Samples = tIndex(CLBPTraits<Type>::getNumOfSamples());
//        return Samples + 2;
        return tIndex(tBase::Size);
    }

protected:
    //! Lookup table.
    vpl::math::CVector<tIndex> m_Map;

protected:
    //! Initalizes the mapping table.
    void initMapping();
};


//=============================================================================
/*
 * Implementation...
 */

#include "Mapping.hxx"


} // namespace lbp
} // namespace vpl

#endif // VPL_LBP_Mapping_H
