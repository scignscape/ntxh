//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2006 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/10/14                          \n
 *
 * $Id: mdsRandom.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Random number generators.
 */

#ifndef MDS_RANDOM_H
#define MDS_RANDOM_H

#include <MDSTk/Base/mdsAssert.h>
#include <MDSTk/Base/mdsTypes.h>

#include "mdsMathExport.h"

// STL
#include <cmath>


namespace mds
{
namespace math
{

//==============================================================================
/*!
 * Pseudo-Random Number Generator (PRNG) base class.
 * - Uses not very good Linear Congruential Method to generate random numbers.
 */
class MDS_MATH_EXPORT CPseudoRNG
{
public:
    //! Type of the PRNG seed.
    typedef mds::sys::tInt32 tSeed;

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
    double random()
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
class MDS_MATH_EXPORT CUniformPRNG : public CPseudoRNG
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
        MDS_ASSERT(Max >= Min);

        return (Min + (Max - Min) * CPseudoRNG::random());
    }
};


//=============================================================================
/*!
 * Pseudo-Random Number Generator (PRNG) having the normal
 * (gaussian) distribution.
 */
class MDS_MATH_EXPORT CNormalPRNG : public CPseudoRNG
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
} // namespace mds

#endif  // MDS_RANDOM_H

