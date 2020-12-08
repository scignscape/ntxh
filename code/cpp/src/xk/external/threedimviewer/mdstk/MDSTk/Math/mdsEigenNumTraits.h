//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2010-2011 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2010/01/04                          \n
 *
 * $Id: mdsEigenNumTraits.h 2049 2012-01-09 13:04:08Z spanel $
 *
 * Description:
 * - MDSTk specific extension of Eigen::NumTraits<> template class.
 * - Don't use this file directly, instead include mdsEigenCore.h header!
 */

#ifndef MDS_EigenNumTraits_H
#define MDS_EigenNumTraits_H

#include <MDSTk/Math/mdsComplex.h>


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
struct NumTraits<mds::math::CComplex<_Real> > : GenericNumTraits<std::complex<_Real> >
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

#endif // MDS_EigenNumTraits_H
