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

 
//! \brief 
//! \tparam T 
//! \tparam Object 
//! \tparam Accessor 
template <typename T, class Object, template <typename, class> class Accessor = AccessorAt1D>
class Compare1D : public CompareBase<Object>
{
public:
    typedef Accessor<T, Object> tAccessor;


    virtual ~Compare1D() = default;

    
    //! \brief Base contructor
    Compare1D() {}

    /**
    * \brief 
    * \tparam Type Type of single value - e.g tDensityPixel
    * \tparam Object Type Collection type - e.g CDImage
    * \param requiredData array of required values
    * \param data tested data
    * \param size count compared values
    * \param ulp decimal precision - ulp=1 => 0.1 eps
    * Example:
    *  type test[] = { 1,2,3 };
    compareValues1D<type, vpl::math::CVector<type>>(test, vector, 3);
    */


    void values(T* requiredData,const Object& data, int size, double ulp = defaults::ulp);

	/**
	*\brief Comparing 1D input with single required value
	* \tparam Type Type of single value - e.g tDensityPixel
	* \tparam Object Type Collection type - e.g CDImage
	* \param requiredValue Single value which is required
	* \param data tested data
	* \param size size count compared values
	* Example:
	*  compareValues1D<type, vpl::math::CVector<type>>(0, vector, 3);
	* \param ulp
	*/
	void values(T requiredValue, const Object& data, int size, double ulp = defaults::ulp);


    
	//! \brief Comparing 1D input with single string required value
    //! \param requiredData  array of required values
    //! \param data tested data
    //! \param size count compared values
    void valuesString(std::string* requiredData, Object& data, int size);

	//! \brief Comparing 1D input with single string required value
	//! \param requiredValue  Single value which is required
	//! \param data tested data
	//! \param size count compared values
    void valuesString(std::string requiredValue, Object & data, const int size);

	//! \brief Comparing 1D input, when values are sequence
	//! \tparam Type Type of single value - e.g tDensityPixel
	//! \tparam Object Type Collection type - e.g CVector
	//! \param firstValue Starting number in sequence
	//! \param data tested data
	//! \param size count of compared values
	//! \param step Step in sequence [-]decreasing / [+]increasing
	//! \param ulp decimal precision - ulp=1 => 0.1 eps
	void sequence(Object& data, int size, T firstValue, T step, double ulp = defaults::ulp);


    /**
    *\brief Comparing 1D input with single required value
    * \tparam Type Type of single value - e.g tDensityPixel
    * \tparam Object Type Collection type - e.g CDImage
    * \param requiredValue Single value which is required
    * \param data tested data
    * \param startPosition offset in tested data
    * \param offset count compared values
    * \param ulp
    */
    void range(T requiredValue, Object& data, int startPosition, int offset, double ulp = defaults::ulp);
    
private:
    tAccessor m_accessor;

};

// Include the file containing functions templates.
#include "compare1D.hxx"

} // namespace vpl
} // namespace test

