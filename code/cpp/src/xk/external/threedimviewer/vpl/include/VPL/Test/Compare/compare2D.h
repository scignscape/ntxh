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
#include <VPL/Test/Accessor/AccessorAt.h>

namespace vpl
{
namespace test
{

//! \brief Comparing 2D data
//! \tparam T Type of single value - e.g tDensityPixel
//! \tparam Object Type Collection type - e.g CDImage
//! \tparam Accessor 
template <typename T, class Object, template <typename, class> class Accessor = AccessorAt2D>
class Compare2D : public CompareBase<Object>
{
public:

    typedef Accessor<T, Object> tAccessor;


    virtual ~Compare2D() = default;


    //! \brief Base contructor
    Compare2D() = default;


    //! \brief Comparing 2D input data with multiple required values
    //! \tparam T Type of single value - e.g tDensityPixel
    //! \tparam Object Type Collection type - e.g CDImage
    //! \param requiredData
    //! \param data tested data
    //! \param xSize size in x axes
    //! \param ySize size in y axes
    //! \param ulp decimal precision
    void values(T* requiredData, Object& data, int xSize, int ySize, double ulp = defaults::ulp);

    //! \brief Comparing 2D input with single required value
    //! \tparam Type Type of single value - e.g tDensityPixel
    //! \tparam Object Type Collection type - e.g CDImage
    //! \param requiredValue Single value which is required
    //! \param data tested data
    //! \param xSize size in x axes
    //! \param ySize size in y axes
    //! \param ulp decimal precision
    void values(T requiredValue, Object& data, int xSize, int ySize, double ulp = defaults::ulp);

    //! \brief Comparing 2D input with reference object
    //! \param referenceObject Required data
    //! \param data tested data
    //! \param xSize size in x axes
    //! \param ySize size in y axes
    //! \param ulp decimal precision
    void valuesWithReference(const Object& referenceObject, const Object& data, int xSize, int ySize, double ulp = defaults::ulp);

    //! \brief Comparing 2D input, when values are sequence
    //! \tparam Type Type of single value - e.g tDensityPixel
    //! \tparam Object Type Collection type - e.g CDImage
    //! \param firstValue Starting number in sequence
    //! \param data tested data
    //! \param xSize size in x axes
    //! \param ySize size in y axes
    //! \param step Step in sequence [-]decreasing / [+]increasing
    //! \param ulp decimal precision
    void sequence(Object& data, int xSize, int ySize, T firstValue, T step, double ulp = defaults::ulp);

    //! \brief Comparing 2D input including margin with single required value
    //! \tparam Type Type of single value - e.g tDensityPixel
    //! \tparam Object Type Collection type - e.g CDImage
    //! \param requiredValue Single value which is required
    //! \param data tested data
    //! \param xSize size in x axes
    //! \param ySize size in y axes
    //! \param margin size of margin
    //! \param ulp decimal precision
    void valuesWithMargin(T requiredValue, Object& data, int xSize, int ySize, int margin,
        double ulp = defaults::ulp);

    //! \brief Comparing 2D input data including margin with multiple required values
    //! \tparam Type Type of single value - e.g tDensityPixel
    //! \tparam Object Type Collection type - e.g CDImage
    //! \param requiredData
    //! \param data tested data
    //! \param xSize size in x axes
    //! \param ySize size in y axes
    //! \param margin size of margin
    //! \param ulp decimal precision
    void valuesWithMargin(T* requiredData, Object& data, int xSize, int ySize, int margin,
        double ulp = defaults::ulp);
private:
    tAccessor m_accessor;
};

// Include the file containing functions templates.
#include "compare2D.hxx"

} // namespace vpl
} // namespace test

