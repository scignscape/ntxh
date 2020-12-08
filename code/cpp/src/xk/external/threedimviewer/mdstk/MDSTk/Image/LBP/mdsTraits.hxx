//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)          \n
 * Copyright (c) 2003-2009 by Michal Spanel           \n
 *
 * Authors: Jiri Hutarek, xhutar01@stud.fit.vutbr.cz  \n
 *          Michal Spanel, spanel@fit.vutbr.cz        \n
 * Date:    2009/01/26                                \n
 *
 * $Id: mdsTraits.hxx 2100 2012-02-17 07:36:55Z spanel $
 *
 * Description:
 * - Basic definitions.
 */


//=============================================================================
/*
 * Helper macro...
 */

#define MDS_IMPLEMENT_LBP_TRAITS(Type, Mapping, Samples, Radius, Min, Max) \
    template <> \
    inline int CLBPTraits<Type, Mapping>::getNumOfSamples() \
    { \
        return (Samples); \
    } \
    template <> \
    inline mds::img::tCoordinate CLBPTraits<Type, Mapping>::getRadius() \
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

MDS_IMPLEMENT_LBP_TRAITS(LBP8, Plain, 8, 1.0, 0, 255)
MDS_IMPLEMENT_LBP_TRAITS(LBP8, Uniform, 8, 1.0, 0, 255)
MDS_IMPLEMENT_LBP_TRAITS(LBP8, RotMin, 8, 1.0, 0, 255)
MDS_IMPLEMENT_LBP_TRAITS(LBP8, UniformRotMin, 8, 1.0, 0, 255)


//=============================================================================
/*
 * Partial specialization for 12-bit LBP feature.
 */

MDS_IMPLEMENT_LBP_TRAITS(LBP12, Plain, 12, 2.5, 0, 4095)
MDS_IMPLEMENT_LBP_TRAITS(LBP12, Uniform, 12, 2.5, 0, 4095)
MDS_IMPLEMENT_LBP_TRAITS(LBP12, RotMin, 12, 2.5, 0, 4095)
MDS_IMPLEMENT_LBP_TRAITS(LBP12, UniformRotMin, 12, 2.5, 0, 4095)


//=============================================================================
/*
 * Partial specialization for 16-bit LBP feature.
 */

MDS_IMPLEMENT_LBP_TRAITS(LBP16, Plain, 16, 4.0, 0, 65535)
MDS_IMPLEMENT_LBP_TRAITS(LBP16, Uniform, 16, 4.0, 0, 65535)
MDS_IMPLEMENT_LBP_TRAITS(LBP16, RotMin, 16, 4.0, 0, 65535)
MDS_IMPLEMENT_LBP_TRAITS(LBP16, UniformRotMin, 16, 4.0, 0, 65535)
