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

#include <string>
#include <map>
#include <vector>
#include <VPL/Test/Utillities/genericValue.h>
#include <VPL/Base/Exception.h>
namespace vpl
{
namespace test
{


//! Collection for specify requied property for testing. 
//! Used in BaseTest/sharedPtrTest
class RequiredData
{
public:
    
    //! \brief Base Constructor
	RequiredData();

	
	//! Register require value with key.
	void require(const std::string& key, const std::string& value);
	void require(const std::string& key, const bool value);
	void require(const std::string& key, const int value);
	void require(const std::string& key, const float value);
	void require(const std::string& key, const double value);

	//! Getter of count required values.
	int count() const;

	//! Remove all registered values.
	void clear();

    //! \brief Getter for string.
	//! \param key Name of required values 
	//! \return converted value to required type
    std::string getString(const std::string& key);
    
    //! \brief Getter for bool.
	//! \param key Name of required values 
	//! \return converted value to required type
    bool getBool(const std::string& key);
    
    //! \brief Getter for number type.
    //! \tparam T Number type: float, int, double ...
    //! \param key Name of required values 
    //! \return converted value to required type
    template<typename T>
    T getNumber(const std::string& key);

private:
	//! Data container
    std::map<std::string, GenericValue> m_data;

	//! Is key in map?
	void checkKey(const std::string& key);
};

 
template <typename T>
T RequiredData::getNumber(const std::string& key)
{
	checkKey(key);

	T ret;
	const GenericValue value = m_data[key];
	switch (value.type())
	{
		case GenericValue::INTEGER: ret = static_cast<T>(value.integerValue()); break;
		case GenericValue::DOUBLE:Double: ret = static_cast<T>(value.doubleValue()); break;
		case GenericValue::FLOAT: ret = static_cast<T>(value.floatValue()); break;

		default:;
	}
	return ret;
}

VPL_DECLARE_EXCEPTION(RequiredDataFailed, "Key was not found")


} // namespace test
} // namespace vpl

