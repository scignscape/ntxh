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
 * Copyright (c) 2010-2011 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2010/01/04                          \n
 *
 * Description:
 * - MDSTk specific extension of Eigen::NumTraits<> template class.
 * - Don't use this file directly, instead include mdsEigenCore.h header!
 */

#ifndef VPL_EigenNumTraits_H
#define VPL_EigenNumTraits_H

#include <VPL/Math/Complex.h>


namespace Eigen
{

/*template<> struct NumTraits<unsigned int>
{
  typedef unsigned int Real;
  typedef double FloatingPoint;
  enum {
    IsComplex = 0,
    HasFloatingPoint = 0,
    ReadCost = 1,
    AddCost = 1,
    MulCost = 1
  };
};

template<> struct NumTraits<short>
{
  typedef short Real;
  typedef double FloatingPoint;
  enum {
    IsComplex = 0,
    HasFloatingPoint = 0,
    ReadCost = 1,
    AddCost = 1,
    MulCost = 1
  };
};

template<> struct NumTraits<unsigned short>
{
  typedef unsigned short Real;
  typedef double FloatingPoint;
  enum {
    IsComplex = 0,
    HasFloatingPoint = 0,
    ReadCost = 1,
    AddCost = 1,
    MulCost = 1
  };
};

template<> struct NumTraits<long>
{
  typedef long Real;
  typedef double FloatingPoint;
  enum {
    IsComplex = 0,
    HasFloatingPoint = 0,
    ReadCost = 1,
    AddCost = 1,
    MulCost = 1
  };
};

template<> struct NumTraits<unsigned long>
{
  typedef unsigned long Real;
  typedef double FloatingPoint;
  enum {
    IsComplex = 0,
    HasFloatingPoint = 0,
    ReadCost = 1,
    AddCost = 1,
    MulCost = 1
  };
};*/

template <typename _Real>
struct NumTraits<vpl::math::CComplex<_Real> > : GenericNumTraits<std::complex<_Real> >
{
    typedef _Real Real;
    enum {
        IsComplex = 1,
        RequireInitialization = NumTraits<_Real>::RequireInitialization,
        ReadCost = 2 * NumTraits<_Real>::ReadCost,
        AddCost = 2 * NumTraits<Real>::AddCost,
        MulCost = 4 * NumTraits<Real>::MulCost + 2 * NumTraits<Real>::AddCost
    };

    inline static Real epsilon() { return NumTraits<Real>::epsilon(); }
    inline static Real dummy_precision() { return NumTraits<Real>::dummy_precision(); }
};


} // namespace Eigen

#endif // VPL_EigenNumTraits_H
