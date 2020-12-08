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
 * Copyright (c) 2003-2005 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/05/18                       
 *
 * Description:
 * - Type specific information.
 */

#ifndef VPL_TYPETRAITS_H
#define VPL_TYPETRAITS_H

#include "Types.h"
#include "Templates.h"

// STL
#include <limits>


namespace vpl
{

//==============================================================================
/*
 * Templates for checking fundamental types.
 */

//! Primary template.
//! - In general T is not signed int type.
template <typename T>
struct SIsSignedInt
{
    enum { RESULT = false };
};


//! Macro to specialize signed int types.
#define SIGNED_INT_TYPE(T) \
    template <> \
    struct SIsSignedInt<T> \
    { \
        enum { RESULT = true }; \
    }


SIGNED_INT_TYPE(char);
SIGNED_INT_TYPE(signed char);
SIGNED_INT_TYPE(signed short);
SIGNED_INT_TYPE(signed int);
SIGNED_INT_TYPE(signed long);
SIGNED_INT_TYPE(signed long long);


//! Primary template.
//! - In general T is not unsigned int type.
template <typename T>
struct SIsUnsignedInt
{
    enum { RESULT = false };
};


//! Macro to specialize unsigned int types.
#define UNSIGNED_INT_TYPE(T) \
    template <> \
    struct SIsUnsignedInt<T> \
    { \
        enum { RESULT = true }; \
    }


UNSIGNED_INT_TYPE(unsigned char);
UNSIGNED_INT_TYPE(unsigned short);
UNSIGNED_INT_TYPE(unsigned int);
UNSIGNED_INT_TYPE(unsigned long);
UNSIGNED_INT_TYPE(unsigned long long);


//! Primary template.
//! - In general T is not other int type.
template <typename T>
struct SIsOtherInt
{
    enum { RESULT = false };
};


//! Macro to specialize other int types.
#define OTHER_INT_TYPE(T) \
    template <> \
    struct SIsOtherInt<T> \
    { \
        enum { RESULT = true }; \
    }


OTHER_INT_TYPE(bool);
OTHER_INT_TYPE(wchar_t);


//! Primary template.
//! - In general T is not other standard type.
template <typename T>
struct SIsOtherStd
{
    enum { RESULT = false };
};


//! Macro to specialize other standard types.
#define OTHER_STD_TYPE(T) \
    template <> \
    struct SIsOtherStd<T> \
    { \
        enum { RESULT = true }; \
    }


OTHER_STD_TYPE(void);


//! Primary template.
//! - In general T is not floating point type.
template <typename T>
struct SIsFloat
{
    enum { RESULT = false };
};


//! Macro to specialize floating point types.
#define FLOAT_TYPE(T) \
    template <> \
    struct SIsFloat<T> \
    { \
        enum { RESULT = true }; \
    }


FLOAT_TYPE(float);
FLOAT_TYPE(double);
FLOAT_TYPE(long double);


//! Primary template.
//! - In general T is converted to double.
template <typename T>
struct SConv2Float
{
    typedef double tFloat;
};


//! Macro to specialize conversion to real types.
#define CONV2FLOAT_TYPE(T, R) \
    template <> \
    struct SConv2Float<T> \
    { \
        typedef R tFloat; \
    }


CONV2FLOAT_TYPE(char, float);
CONV2FLOAT_TYPE(signed char, float);
CONV2FLOAT_TYPE(signed short, float);
CONV2FLOAT_TYPE(signed int, double);
CONV2FLOAT_TYPE(signed long, double);
CONV2FLOAT_TYPE(signed long long, long double);

CONV2FLOAT_TYPE(unsigned char, float);
CONV2FLOAT_TYPE(unsigned short, float);
CONV2FLOAT_TYPE(unsigned int, double);
CONV2FLOAT_TYPE(unsigned long, double);
CONV2FLOAT_TYPE(unsigned long long, long double);

CONV2FLOAT_TYPE(float, float);
CONV2FLOAT_TYPE(double, double);
CONV2FLOAT_TYPE(long double, long double);


//==============================================================================
/*
 * Templates for checking pointers and references.
 */

//! Primary template of a non-pointer type.
template <typename T>
struct SIsPointer
{
    enum { RESULT = false };

    typedef tNull tPointee;
};


//! Partial specialization for pointers.
template <typename T>
struct SIsPointer<T*>
{
    enum { RESULT = true };

    typedef T tPointee;
};


//! Primary template of a non-reference type.
template <typename T>
struct SIsReference
{
    enum { RESULT = false };

    typedef T tReferred;
};


//! Partial specialization for references.
template <typename T>
struct SIsReference<T&>
{
    enum { RESULT = true };

    typedef T tReferred;
};


//! Primary template of a non-pointer to member type.
template <typename T>
struct SIsMemberPointer
{
    enum { RESULT = false };
};


//! Partial specialization for pointers to member.
template <typename T, typename U>
struct SIsMemberPointer<T U::*>
{
    enum { RESULT = true };
};


//==============================================================================
/*
 * Templates for checking constant types.
 */

//! Primary template of a non-const type.
template <typename T>
struct SIsConst
{
    enum { RESULT = false };

    typedef T tNonConst;
};


//! Partial specialization for const types.
template <typename T>
struct SIsConst<const T>
{
    enum { RESULT = true };

    typedef T tNonConst;
};


//==============================================================================
/*!
 * Template providing type specific information.
 */
template <typename T>
class CTypeTraits
{
public:
    //! Simple type checks.
    enum { isPointer        = SIsPointer<T>::RESULT };
    enum { isReference      = SIsReference<T>::RESULT };
    enum { isMemberPointer  = SIsMemberPointer<T>::RESULT };
    enum { isUnsignedInt    = SIsUnsignedInt<T>::RESULT };
    enum { isSignedInt      = SIsSignedInt<T>::RESULT };
    enum { isFloat          = SIsFloat<T>::RESULT };
    enum { isConst          = SIsConst<T>::RESULT };
    enum { isIntegral       = isUnsignedInt || isSignedInt || SIsOtherInt<T>::RESULT };
    enum { isFundamental    = isIntegral || isFloat || SIsOtherStd<T>::RESULT };

    //! Pointee type if T is pointer.
    typedef typename SIsPointer<T>::tPointee tPointee;

    //! Referred type if T is reference.
    typedef typename SIsReference<T>::tReferred tReferred;

    //! Non-const type if T is constant.
    typedef typename SIsConst<T>::tNonConst tNonConst;

    //! Type used to pass type T as a function/method parameter.
    typedef typename SSelect<isFundamental || isPointer || isMemberPointer, T, tReferred&>::RESULT tParameter;

    //! Optimal float type to convert type T to.
    typedef typename SConv2Float<T>::tFloat tFloat;

public:
    //! Minimal value of the type T.
    inline static T getMin()
    {
        return (std::numeric_limits<T>::min)();
    }

    //! Maximal value of the type T.
    inline static T getMax()
    {
        return (std::numeric_limits<T>::max)();
    }

    //! Zero defined for the type T.
    inline static T getZero()
    {
        return T(0);
    }

    //! Returns size of the type T in bytes.
    inline static tSize getSize()
    {
        static const tSize Size = tSize(sizeof(T));

        return Size;
    }
};


//==============================================================================
/*
 * Include limits of the several basic types which are defined in the
 * header file mdsTypes.h
 */
#include "TypeTraits.hxx"


} // namespace vpl

#endif // VPL_TYPETRAITS_H

