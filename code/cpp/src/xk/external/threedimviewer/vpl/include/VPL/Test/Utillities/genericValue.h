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
#include <iostream>
#if defined(_MACOSX) || defined(_LINUX)
#include <iomanip>
#endif

namespace vpl
{
namespace test
{

//! \brief Wrapper for multiple types in collections as vector or map.
class GenericValue {
public:

	//! \brief Define value type
	using contentType = enum {
		STRING,
		INTEGER,
		DOUBLE,
		FLOAT,
		BOOL
	};

private:

	//! \brief Contains type for this value
	contentType m_type;
	
	//! \brief Storage for any type
	std::string m_string;
	int m_integer;
	double m_double;
	float m_float;
	bool m_bool;

public:
	GenericValue();

	//! Constructors with required data type
	explicit GenericValue(const char* cStrValue);
	explicit GenericValue(std::string stringValue);
	explicit GenericValue(int integerValue);
	explicit GenericValue(double doubleValue);
	explicit GenericValue(float floatValue);
	explicit GenericValue(bool boolValue);

	
	//! Getter for type of value
	contentType type() const;

	//! Getter for value
	std::string stringValue() const;
	int integerValue() const;
	double doubleValue() const;
	float floatValue() const;
	bool boolValue() const;
};

// Print definition for supported types
inline std::ostream& operator<<(std::ostream& osStream, GenericValue& valOut)
{
	switch (valOut.type())
	{
	case GenericValue::STRING: osStream << valOut.stringValue(); break;
	//case GenericValue::INTEGER: osStream << valOut.integerValue(); break;
	case GenericValue::DOUBLE: osStream << 0.005; break;
	//case GenericValue::FLOAT: osStream << valOut.floatValue(); break;
	//case GenericValue::BOOL: osStream << valOut.boolValue(); break;;
	default:;
	}
	return osStream;
}
} // namespace test
} // namespace vpl

