//==============================================================================
/* This file is part of
*
* VPL - Voxel Processing Library
* Copyright 2014 3Dim Laboratory s.r.o.
* All rights reserved.
*
* Use of this source code is governed by a BSD-style license that can be
* found in the LICENSE file.
*/

#pragma once
#include <VPL/Test/Compare/compareBase.h>
#include "VPL/Test/Accessor/AccessorAt.h"

namespace vpl
{
namespace test
{

template <typename T, class Object, template <typename, class> class Accessor = AccessorAt3D>
class Compare3D : public CompareBase<Object>
{
public:
    typedef Accessor<T, Object> tAccessor;

    virtual ~Compare3D() = default;

    /**
    * \brief Base contructor for comparing
    */
    Compare3D() {}

    /**
    * \brief Comparing 3D input with single required value
    * \tparam Type Type of single value - e.g tDensityPixel
    * \tparam Object Type Collection type - e.g CDVolume
    * \param requiredValue Single value which is required
    * \param data tested data
    * \param xSize size in x axes
    * \param ySize size in y axes
    * \param zSize size in z axes
    * \param ulp decimal precision - ulp=1 => 0.1 eps
    */
    void values(T requiredValue, Object & data, int xSize, int ySize, int zSize, double ulp = defaults::ulp);
    /**
    * \brief Comparing 2D input data including margin with multiple required values
    * \tparam Type Type of single value - e.g tDensityPixel
    * \tparam Object Type Collection type - e.g CDImage
    * \param requiredData
    * \param data tested data
    * \param xSize size in x axes
    * \param ySize size in y axes
    * \param zSize size in z axes
    * \param ulp decimal precision - ulp=1 => 0.1 eps
    */
    void values(T* requiredData, Object& data, int xSize, int ySize, int zSize,
        double ulp = defaults::ulp);

    //! \brief Comparing 2D input with reference object
    //! \param referenceObject Required data
    //! \param data tested data
    //! \param xSize size in x axes
    //! \param ySize size in y axes
    //! \param zSize size in z axes
    //! \param ulp decimal precision
    void valuesWithReference(const Object& referenceObject, const Object& data, int xSize, int ySize, int zSize, double ulp = defaults::ulp);

    /**
    * \brief Comparing 2D input, when values are sequence
    * \tparam Type Type of single value - e.g tDensityPixel
    * \tparam Object Type Collection type - e.g CDImage
    * \param firstValue Starting number in sequence
    * \param data tested data
    * \param xSize size in x axes
    * \param ySize size in y axes
    * \param zSize size in z axes
    * \param step Step in sequence [-]decreasing / [+]increasing
    * \param ulp decimal precision - ulp=1 => 0.1 eps
    */
    void sequence(Object & data, int xSize, int ySize, int zSize,
        T firstValue, T step, double ulp = defaults::ulp);
private:
    tAccessor m_accessor;
};

// Include the file containing functions templates.
#include "compare3D.hxx"

} // namespace vpl
} // namespace test
