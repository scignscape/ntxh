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

#include <VPL/Test/Utillities/genericValue.h>

namespace vpl {
namespace test {
GenericValue::GenericValue() :
    m_type(), m_integer(0), m_double(0), m_float(0), m_bool(false) {}

GenericValue::GenericValue(const char* cStrValue)
    : m_type(STRING), m_string(std::string(cStrValue)),
	m_integer(0), m_double(0), m_float(0), m_bool(false) {}

GenericValue::GenericValue(std::string stringValue)
    : m_type(STRING), m_string(std::move(stringValue)),
	m_integer(0), m_double(0), m_float(0), m_bool(false) {}

GenericValue::GenericValue(const int integerValue)
    : m_type(INTEGER), m_integer(integerValue), m_double(0), m_float(0), m_bool(false) {}

GenericValue::GenericValue(const double doubleValue)
    : m_type(DOUBLE), m_integer(0), m_double(doubleValue), m_float(0), m_bool(false) {}

GenericValue::GenericValue(const float floatValue)
    : m_type(FLOAT), m_integer(0), m_double(0), m_float(floatValue), m_bool(false) {}
GenericValue::GenericValue(const bool boolValue)
    : m_type(BOOL), m_integer(0), m_double(0), m_float(0), m_bool(boolValue) {}

GenericValue::contentType GenericValue::type() const
{
    return m_type;
}

std::string GenericValue::stringValue() const
{
    return m_string;
}

int GenericValue::integerValue() const
{
    return m_integer;
}

double GenericValue::doubleValue() const
{
    return m_double;
}

float GenericValue::floatValue() const
{
    return m_float;
}

bool GenericValue::boolValue() const
{
    return m_bool;
}
}
}

