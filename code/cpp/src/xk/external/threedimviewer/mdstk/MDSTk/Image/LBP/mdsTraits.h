//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)          \n
 * Copyright (c) 2003-2009 by Michal Spanel           \n
 *
 * Authors: Jiri Hutarek, xhutar01@stud.fit.vutbr.cz  \n
 *          Michal Spanel, spanel@fit.vutbr.cz        \n
 * Date:    2009/01/26                                \n
 *
 * $Id: mdsTraits.h 2100 2012-02-17 07:36:55Z spanel $
 *
 * Description:
 * - Basic definitions.
 */

#ifndef MDS_LBP_Traits_H
#define MDS_LBP_Traits_H

#include <MDSTk/Base/mdsTemplates.h>


namespace mds
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
    typedef typename mds::SSelect<Type == LBP8, unsigned char, unsigned int>::RESULT tCode;

    //! Size of the LBP code in bits (= number of samples).
    enum { NumOfSamples = Type };

    //! Number of distinct codes produced by the mapping.
    enum { NumOfCodes = SMappingSize<Type,Mapping>::RESULT };

public:
    //! Returns size of the LBP code.
    inline static int getNumOfSamples();

    //! Returns radius of the LBP feature.
    inline static mds::img::tCoordinate getRadius();

    //! Returns minimal LBP code value.
    inline static tCode getMin();

    //! Returns maximal allowed LBP code value.
    inline static tCode getMax();
};


//=============================================================================
/*
 * Implementation...
 */

#include "mdsTraits.hxx"


} // namespace lbp
} // namespace mds

#endif // MDS_LBP_Traits_H
