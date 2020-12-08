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

#include <string>
#include <fstream>
#include "VPL/Test/Utillities/requiredData.h"
#include <VPL/Test/Utillities/genericValue.h>
#include <gtest/gtest.h>

namespace vpl
{
namespace test
{
RequiredData::RequiredData()
= default;

void RequiredData::require(const std::string& key, const std::string& value)
{
	const GenericValue gv(value);
	m_data[key] = gv;
}

void RequiredData::require(const std::string& key, const bool value)
{
	const GenericValue gv(value);
	m_data[key] = gv;
}

void RequiredData::require(const std::string& key, const int value)
{
	const GenericValue gv(value);
	m_data[key] = gv;
}

void RequiredData::require(const std::string& key, const float value)
{
	const GenericValue gv(value);
	m_data[key] = gv;
}

void RequiredData::require(const std::string& key, const double value)
{
	const GenericValue gv(value);
	m_data[key] = gv;
}

int RequiredData::count() const
{
	return m_data.size();
}

void RequiredData::clear()
{
	m_data.clear();
}

std::string RequiredData::getString(const std::string& key)
{
	checkKey(key);
    return m_data[key].stringValue();
}
bool RequiredData::getBool(const std::string& key)
{
	checkKey(key);
    return m_data[key].boolValue();
}

void RequiredData::checkKey(const std::string& key)
{
	if (m_data.find(key) == m_data.end())
	{
		EXPECT_TRUE(m_data.find(key) != m_data.end()) << "Key: " << key;
		throw RequiredDataFailed();
	}
}
}
}

