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
 * Date:    2009/01/26                             
 *
 * Description:
 * - Basic definitions.
 */

#ifndef VPL_LBP_Traits_H
#define VPL_LBP_Traits_H

#include <VPL/Base/Templates.h>


namespace vpl
{
namespace lbp
{

//=============================================================================
/*
 * Global definitions.
 */

//! Currently supported types of LBP features.
enum ECodeType
{
    LBP8    = 8,    //! Basic 8-bit LBP feature (8 samples, radius = 1).
    LBP12   = 12,   //! LBP feature (12 samples, radius = 2.5).
    LBP16   = 16    //! LBP feature (16 samples, radius = 4).
};


//! Currently supported LBP mappings.
enum EMappingType
{
    Plain           = 0,
    Uniform         = 1,
    RotMin          = 2,
    UniformRotMin   = Uniform | RotMin
};


//! Primary template.
//! - Parameter Type is a concrete LBP type.
//! - Parameter Mapping is a mapping type.
template <ECodeType Type, EMappingType Mapping>
//template <int Type, int Mapping>
struct SMappingSize
{
    enum { RESULT = 1 };
};


//! Macro to specialize LBP mapping size.
#define LBP_MAPPING_SIZE(T, M, Value) \
    template <> \
    struct SMappingSize<T,M> \
    { \
        enum { RESULT = Value }; \
    }


LBP_MAPPING_SIZE(LBP8, Plain, 256);
LBP_MAPPING_SIZE(LBP8, Uniform, 59);
LBP_MAPPING_SIZE(LBP8, RotMin, 36);
LBP_MAPPING_SIZE(LBP8, UniformRotMin, 10);

LBP_MAPPING_SIZE(LBP12, Plain, 4096);
LBP_MAPPING_SIZE(LBP12, Uniform, 135);
LBP_MAPPING_SIZE(LBP12, RotMin, 352);
LBP_MAPPING_SIZE(LBP12, UniformRotMin, 14);

LBP_MAPPING_SIZE(LBP16, Plain, 65536);
LBP_MAPPING_SIZE(LBP16, Uniform, 243);
LBP_MAPPING_SIZE(LBP16, RotMin, 4116);
LBP_MAPPING_SIZE(LBP16, UniformRotMin, 18);


//=============================================================================
/*!
 * Type traits for LBP features.
 * - Parameter Type corresponds to one of the predefined LBP features.
 * - Parameter Mapping is one of the predefined mapping type.
 */
//template <int Type, int Mapping = Plain>
template <ECodeType Type, EMappingType Mapping = UniformRotMin>
class CLBPTraits
{
public:
    //! Type used to store "raw" LBP code.
    typedef typename vpl::SSelect<Type == LBP8, unsigned char, unsigned int>::RESULT tCode;

    //! Size of the LBP code in bits (= number of samples).
    enum { NumOfSamples = Type };

    //! Number of distinct codes produced by the mapping.
    enum { NumOfCodes = SMappingSize<Type,Mapping>::RESULT };

public:
    //! Returns size of the LBP code.
    inline static int getNumOfSamples();

    //! Returns radius of the LBP feature.
    inline static vpl::img::tCoordinate getRadius();

    //! Returns minimal LBP code value.
    inline static tCode getMin();

    //! Returns maximal allowed LBP code value.
    inline static tCode getMax();
};


//=============================================================================
/*
 * Implementation...
 */

#include "Traits.hxx"


} // namespace lbp
} // namespace vpl

#endif // VPL_LBP_Traits_H
