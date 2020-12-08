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
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/10/14                          \n
 *
 * Description:
 * - Random number generators.
 */

#ifndef VPL_RANDOM_H
#define VPL_RANDOM_H

#include <VPL/Base/Assert.h>
#include <VPL/Base/Types.h>

#include "MathExport.h"

// STL
#include <cmath>


namespace vpl
{
namespace math
{

//==============================================================================
/*!
 * Pseudo-Random Number Generator (PRNG) base class.
 * - Uses not very good Linear Congruential Method to generate random numbers.
 */
class VPL_MATH_EXPORT CPseudoRNG
{
public:
    //! Type of the PRNG seed.
    typedef vpl::sys::tInt32 tSeed;

    //! Default seed.
    static const tSeed DEFAULT_SEED = 1537;

public:
    //! Constructor.
    CPseudoRNG(tSeed Seed = DEFAULT_SEED) : m_Seed(Seed) {}

    //! Destructor.
    virtual ~CPseudoRNG() {}

    //! Changes the PRNG seed.
    void changeSeed(tSeed Seed) { m_Seed = Seed; }

    //! Returns random value in the range <0..1).
#ifdef __APPLE__ // there is some optimization bug in compiler shipped with Xcode8 
    double random() __attribute__ ((optnone))
#else
    double random()
#endif
    {
        m_Seed *= MULTIPLE_CONST;
        if( m_Seed < 0 )
        {
            m_Seed ^= SIGN_BIT;
        }
        return (double(m_Seed) / MAX_VALUE);
    }

protected:
    //! Algorithm constants.
    static const tSeed MULTIPLE_CONST   = 1220703125;
    static const tSeed MAX_VALUE        = 0x7fffffff;
    static const tSeed SIGN_BIT         = 0x80000000;

protected:
    //! Current PRNG seed.
    tSeed m_Seed;
};


//=============================================================================
/*!
 * Pseudo-Random Number Generator (PRNG) having the uniform distribution.
 */
class VPL_MATH_EXPORT CUniformPRNG : public CPseudoRNG
{
public:
    //! Default constructor.
    CUniformPRNG() {}

    //! Constructor.
    CUniformPRNG(tSeed Seed) : CPseudoRNG(Seed) {}

    //! Destructor.
    virtual ~CUniformPRNG() {}

    //! Returns random value in the range <Min, Max)
    double random(double Min, double Max)
    {
        VPL_ASSERT(Max >= Min);

        return (Min + (Max - Min) * CPseudoRNG::random());
    }
};


//=============================================================================
/*!
 * Pseudo-Random Number Generator (PRNG) having the normal
 * (gaussian) distribution.
 */
class VPL_MATH_EXPORT CNormalPRNG : public CPseudoRNG
{
public:
    //! Default constructor.
    CNormalPRNG() {}

    //! Constructor.
    CNormalPRNG(tSeed Seed) : CPseudoRNG(Seed) {}

    //! Destructor.
    virtual ~CNormalPRNG() {}

    //! Returns random numbers having normal distribution.
    // - Mean value and standard deviation are given as parameters.
    double random(double dMean, double dSigma)
    {
        double dSum = 0.0;
        for( int i = 0; i < 12; ++i )
        {
            dSum += CPseudoRNG::random();
        }
        return ((dSum - 6.0) * dSigma + dMean);
    }
};


} // namespace math
} // namespace vpl

#endif  // VPL_RANDOM_H

