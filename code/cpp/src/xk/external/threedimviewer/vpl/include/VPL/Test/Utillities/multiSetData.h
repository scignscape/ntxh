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
#include <gtest/gtest.h>
#include <string>
#include <memory>

namespace vpl
{
namespace test
{
namespace auxiliary
{
//! \brief Define one item inside multi set.
//! \tparam T Type of single value.
template <typename T>
struct MultiSetItem
{
	explicit MultiSetItem(const T& value, const int count = 1) :
		value(value), quantity(count)
	{}

	//! Value in multiset
	T value;
	//! Quantity values in multiset
	int quantity;
};
} // namespace auxiliary

//! \brief Multi set collection of required values.
//! \tparam T Type of required values
template <typename T>
class MultiSetData
{

public:
	//! Base constructor
	MultiSetData() : m_precision(1){}

	//! \brief Checks value, when value is not required is failure also if quantity is not in required range.
	//! \param value 
	void checkValue(T value);

	//! \brief Checks if all values are all used in required quantity.
	//! \return True if all are used.
	void checkUsedAll();

	//! \brief Register value for testing, which is required.
	//! \param value Required value
	//! \param overwrite Should be value overwriten or increased quantity
	void require(T value, bool overwrite = false);

	//!\brief Register value for testing, which is required.
	//!\param value Required value
	//!\param quantity Count of this value
	//!\param overwrite Should be value overwriten or increased quantity
	void require(T value, int quantity, bool overwrite = false);

	//! \brief Clearing required data
	void reset();

	//! \brief Precision when coverting floating number to key
	//! \param precision number of decimal places, example: 2 = 0.01
	void setPrecision(int precision);

private:
	std::map<std::string, std::shared_ptr<auxiliary::MultiSetItem<T>>> m_map;

	int m_precision;

	//! \brief Converting value to string
	//! \param value required value
	//! \return string key
	std::string createKey(T value);
};


// Include the file containing functions templates.
#include "multiSetData.hxx"
} // namespace vpl
} // namespace test

