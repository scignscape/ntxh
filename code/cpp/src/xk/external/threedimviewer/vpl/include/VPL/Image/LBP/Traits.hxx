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


//=============================================================================
/*
 * Helper macro...
 */

#define VPL_IMPLEMENT_LBP_TRAITS(Type, Mapping, Samples, Radius, Min, Max) \
    template <> \
    inline int CLBPTraits<Type, Mapping>::getNumOfSamples() \
    { \
        return (Samples); \
    } \
    template <> \
    inline vpl::img::tCoordinate CLBPTraits<Type, Mapping>::getRadius() \
    { \
        return (Radius); \
    } \
    template <> \
    inline CLBPTraits<Type, Mapping>::tCode CLBPTraits<Type, Mapping>::getMin() \
    { \
        return (Min); \
    } \
    template <> \
    inline CLBPTraits<Type, Mapping>::tCode CLBPTraits<Type, Mapping>::getMax() \
    { \
        return (Max); \
    }


//=============================================================================
/*
 * Partial specialization for 8-bit LBP feature.
 */

VPL_IMPLEMENT_LBP_TRAITS(LBP8, Plain, 8, 1.0, 0, 255)
VPL_IMPLEMENT_LBP_TRAITS(LBP8, Uniform, 8, 1.0, 0, 255)
VPL_IMPLEMENT_LBP_TRAITS(LBP8, RotMin, 8, 1.0, 0, 255)
VPL_IMPLEMENT_LBP_TRAITS(LBP8, UniformRotMin, 8, 1.0, 0, 255)


//=============================================================================
/*
 * Partial specialization for 12-bit LBP feature.
 */

VPL_IMPLEMENT_LBP_TRAITS(LBP12, Plain, 12, 2.5, 0, 4095)
VPL_IMPLEMENT_LBP_TRAITS(LBP12, Uniform, 12, 2.5, 0, 4095)
VPL_IMPLEMENT_LBP_TRAITS(LBP12, RotMin, 12, 2.5, 0, 4095)
VPL_IMPLEMENT_LBP_TRAITS(LBP12, UniformRotMin, 12, 2.5, 0, 4095)


//=============================================================================
/*
 * Partial specialization for 16-bit LBP feature.
 */

VPL_IMPLEMENT_LBP_TRAITS(LBP16, Plain, 16, 4.0, 0, 65535)
VPL_IMPLEMENT_LBP_TRAITS(LBP16, Uniform, 16, 4.0, 0, 65535)
VPL_IMPLEMENT_LBP_TRAITS(LBP16, RotMin, 16, 4.0, 0, 65535)
VPL_IMPLEMENT_LBP_TRAITS(LBP16, UniformRotMin, 16, 4.0, 0, 65535)
