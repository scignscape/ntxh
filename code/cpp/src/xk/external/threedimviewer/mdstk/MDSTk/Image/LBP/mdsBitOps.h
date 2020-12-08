//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)          \n
 * Copyright (c) 2003-2009 by Michal Spanel           \n
 *
 * Authors: Jiri Hutarek, xhutar01@stud.fit.vutbr.cz  \n
 *          Michal Spanel, spanel@fit.vutbr.cz        \n
 * Date:    2008/03/09                                \n
 *
 * $Id: mdsBitOps.h 1863 2010-08-31 20:40:15Z spanel $
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
 * - Various routines for manipulating bits in integers.
 */

#ifndef MDS_LBP_BitOps_H
#define MDS_LBP_BitOps_H

#include <MDSTk/Base/mdsTypeTraits.h>

// STL
#include <cstddef>
#include <string>


namespace mds
{
namespace lbp
{

//=============================================================================
/*!
 * Various routines for manipulating bits in integers.
 * - Template argument should be an unsigned integer type.
 * - Considers only <N> rightmost bits.
 */
template <typename T, unsigned int N = 8>
class CBitOps
{
public:
    //! User defined number of used rightmost bits.
    enum { VALID_BITS = N };

    //! Size of the T type in bits.
    enum { NUM_OF_BITS = sizeof(T) * 8 };

    //! The number of unused bits.
    enum { UNUSED_BITS = NUM_OF_BITS - N };

    //! Test if a given type is valid.
    enum { isValid = mds::CTypeTraits<T>::isIntegral };

public:
    //! Returns number of bits in template type (considering 8-bit per byte).
    static unsigned int getNumOfBits()
    {
        return sizeof(T) * 8;
    }

    //! Returns the user defined number of valid rightmost bits.
    static unsigned int getNumOfValidBits()
    {
        return N;
    }

    //! Returns mask of valid rightmost bits.
    static T getMask()
    {
        static const T Mask = ~T(0) >> UNUSED_BITS;
        return Mask;
    }

    //! Rotates a binary number right by n positions.
    static T rotateRight(T Value, unsigned int n)
    {
        Value &= getMask();
        return (Value >> n) | ((Value << (N - n)) & getMask());
    }

    //! Rotates a binary number left by n positions.
    static T rotateLeft(T Value, unsigned int n)
    {
        Value &= getMask();
        return ((Value << n) & getMask()) | (Value >> (N - n));
    }

    //! Returns the number of ones in a binary number.
    static unsigned int getNumOfOnes(T Value)
    {
        unsigned Count = 0;
        for( unsigned i = 0; i < N; ++i )
        {
            Count += Value & 1;
            Value >>= 1;
        }
        return Count;
    }

    //! Returns the number of 0-to-1 or 1-to-0 transitions in a binary number.
    static unsigned int getNumOfTransitions(T Value)
    {
        unsigned int First = Value & 1, Last = First;
        Value >>= 1;

        unsigned int Changes = 0;
        for( unsigned int i = 1; i < N; ++i )
        {
            Changes += (Value & 1) ^ Last;
            Last = Value & 1;
            Value >>= 1;
        }
        Changes += Last ^ First;
        return Changes;
    }

    //! Rotates a binary number to the minimum possible value.
    static T rotate2Min(T Value)
    {
        Value &= getMask();
        T Min = Value;
        for( unsigned i = 1; i < N; ++i )
        {
            Value = (Value >> 1) | ((Value << (N - 1)) & getMask());
            if( Value < Min )
            {
                Min = Value;
            }
        }
        return Min;
    }

    //! Returns a textual representation of a binary number.
    static std::string conv2String(T Value)
    {
        std::string ssResult(N, '0');
        for( unsigned i = N; i > 0; --i )
        {
            ssResult[i - 1] = '0' + char(Value & 1);
            Value >>= 1;
        }
        return ssResult;
    }
};


//=============================================================================
/*
 * Specialization for the unsigned char value.
 */

template <>
inline unsigned int CBitOps<unsigned char, 8>::getNumOfBits()
{
    return 8;
}


template <>
inline unsigned int CBitOps<unsigned char, 8>::getNumOfValidBits()
{
    return 8;
}


template <>
inline unsigned char CBitOps<unsigned char, 8>::getMask()
{
    return 0xff;
}


template <>
inline unsigned char CBitOps<unsigned char, 8>::rotateRight(unsigned char Value, unsigned int n)
{
    return (Value >> n) | (Value << (8 - n));
}


template <>
inline unsigned char CBitOps<unsigned char, 8>::rotateLeft(unsigned char Value, unsigned int n)
{
    return (Value << n) | (Value >> (8 - n));
}


template <>
inline unsigned int CBitOps<unsigned char, 8>::getNumOfOnes(unsigned char Value)
{
    static const unsigned int Table[256] = {
        0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,
        1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
        1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
        2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
        1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
        2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
        2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
        3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
        1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
        2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
        2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
        3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
        2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
        3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
        3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
        4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8
        };

    return Table[Value];
}


template <>
inline unsigned int CBitOps<unsigned char, 8>::getNumOfTransitions(unsigned char Value)
{
    static const unsigned int Table[256] = {
        0, 2, 2, 2, 2, 4, 2, 2, 2, 4, 4, 4, 2, 4, 2, 2,
        2, 4, 4, 4, 4, 6, 4, 4, 2, 4, 4, 4, 2, 4, 2, 2,
        2, 4, 4, 4, 4, 6, 4, 4, 4, 6, 6, 6, 4, 6, 4, 4,
        2, 4, 4, 4, 4, 6, 4, 4, 2, 4, 4, 4, 2, 4, 2, 2,
        2, 4, 4, 4, 4, 6, 4, 4, 4, 6, 6, 6, 4, 6, 4, 4,
        4, 6, 6, 6, 6, 8, 6, 6, 4, 6, 6, 6, 4, 6, 4, 4,
        2, 4, 4, 4, 4, 6, 4, 4, 4, 6, 6, 6, 4, 6, 4, 4,
        2, 4, 4, 4, 4, 6, 4, 4, 2, 4, 4, 4, 2, 4, 2, 2,
        2, 2, 4, 2, 4, 4, 4, 2, 4, 4, 6, 4, 4, 4, 4, 2,
        4, 4, 6, 4, 6, 6, 6, 4, 4, 4, 6, 4, 4, 4, 4, 2,
        4, 4, 6, 4, 6, 6, 6, 4, 6, 6, 8, 6, 6, 6, 6, 4,
        4, 4, 6, 4, 6, 6, 6, 4, 4, 4, 6, 4, 4, 4, 4, 2,
        2, 2, 4, 2, 4, 4, 4, 2, 4, 4, 6, 4, 4, 4, 4, 2,
        4, 4, 6, 4, 6, 6, 6, 4, 4, 4, 6, 4, 4, 4, 4, 2,
        2, 2, 4, 2, 4, 4, 4, 2, 4, 4, 6, 4, 4, 4, 4, 2,
        2, 2, 4, 2, 4, 4, 4, 2, 2, 2, 4, 2, 2, 2, 2, 0,
        };

    return Table[Value];
}


template <>
inline unsigned char CBitOps<unsigned char, 8>::rotate2Min(unsigned char Value)
{
    static const unsigned int Table[256] = {
        0, 1, 1, 3, 1, 5, 3, 7, 1, 9, 5, 11, 3, 13, 7, 15,
        1, 17, 9, 19, 5, 21, 11, 23, 3, 25, 13, 27, 7, 29, 15, 31,
        1, 9, 17, 25, 9, 37, 19, 39, 5, 37, 21, 43, 11, 45, 23, 47,
        3, 19, 25, 51, 13, 53, 27, 55, 7, 39, 29, 59, 15, 61, 31, 63,
        1, 5, 9, 13, 17, 21, 25, 29, 9, 37, 37, 45, 19, 53, 39, 61,
        5, 21, 37, 53, 21, 85, 43, 87, 11, 43, 45, 91, 23, 87, 47, 95,
        3, 11, 19, 27, 25, 43, 51, 59, 13, 45, 53, 91, 27, 91, 55, 111,
        7, 23, 39, 55, 29, 87, 59, 119, 15, 47, 61, 111, 31, 95, 63, 127,
        1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31,
        9, 25, 37, 39, 37, 43, 45, 47, 19, 51, 53, 55, 39, 59, 61, 63,
        5, 13, 21, 29, 37, 45, 53, 61, 21, 53, 85, 87, 43, 91, 87, 95,
        11, 27, 43, 59, 45, 91, 91, 111, 23, 55, 87, 119, 47, 111, 95, 127,
        3, 7, 11, 15, 19, 23, 27, 31, 25, 39, 43, 47, 51, 55, 59, 63,
        13, 29, 45, 61, 53, 87, 91, 95, 27, 59, 91, 111, 55, 119, 111, 127,
        7, 15, 23, 31, 39, 47, 55, 63, 29, 61, 87, 95, 59, 111, 119, 127,
        15, 31, 47, 63, 61, 95, 111, 127, 31, 63, 95, 127, 63, 127, 127, 255
        };

    return Table[Value];
}


} // namespace lbp
} // namespace mds

#endif // MDS_LBP_BitOps_H
