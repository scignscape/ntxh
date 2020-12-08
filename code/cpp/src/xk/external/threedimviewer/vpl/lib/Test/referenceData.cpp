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
#include <gtest/gtest.h>
#include <document.h>
#include <istreamwrapper.h>
#include "VPL/Test/Utillities/referenceData.h"
#include <VPL/Test/Utillities/genericValue.h>

using rapidjson::Document;
using rapidjson::IStreamWrapper;

namespace vpl
{
namespace test
{

namespace settings
{
    const char* inputTokenName = "input";
    const char* testNameToken = "name";
}

ReferenceData::ReferenceData() : m_count(0) {}


bool ReferenceData::load(const std::string& directory, const std::string& fileName, const std::string& extension)
{
    const std::string path = directory + "/" + fileName + "." + extension;

    std::ifstream ifs(path);

	if(!ifs.is_open())
	{
		return false;
	}
    IStreamWrapper isw(ifs);
    Document document;
    document.ParseStream(isw);

    assert(document.IsObject());
    if (document.HasMember(settings::inputTokenName))
    {
        assert(document[settings::inputTokenName].IsString());
        m_input = document[settings::inputTokenName].GetString();
    }
    m_count = 0;

	int index = -1;
    for (rapidjson::Value::ConstMemberIterator itr = document.MemberBegin();
        itr != document.MemberEnd(); ++itr)
    {
        if (itr->value.IsObject())
        {
			index++;
			m_count++;

            const GenericValue name(itr->name.GetString());
            m_data[settings::testNameToken][index] = name;
            {
                const std::string input = itr->value.HasMember(settings::inputTokenName) ? 
                    itr->value[settings::inputTokenName].GetString() : "";
                GenericValue v(input);
                m_data[settings::inputTokenName][index] = v;
            }
            for (rapidjson::Value::ConstMemberIterator child = itr->value.MemberBegin();
                child != itr->value.MemberEnd(); ++child)
            {
                std::string s = child->name.GetString();
                if(std::string(settings::inputTokenName) == child->name.GetString())
                { 
                    continue;
                }

                GenericValue v;
                if (child->value.IsString())
                {
                    v = GenericValue(child->value.GetString());
                }
                else if (child->value.IsBool())
                {
                    v = GenericValue(child->value.GetBool());
                }
                else if (child->value.IsFloat())
                {
                    v = GenericValue(child->value.GetFloat());
                }
                else if (child->value.IsDouble())
                {
                    v = GenericValue(child->value.GetDouble());
                }
                else if (child->value.IsInt())
                {
                    v = GenericValue(child->value.GetInt());
                }
                else
                {
                    return false;
                }
                m_data[child->name.GetString()][index] = v;
            }
        }
    }
    return true;
}

int ReferenceData::getTestCount() const
{
    return m_count;
}

bool ReferenceData::getGlobalInput(std::string& fileName) const
{
    fileName = m_input;
    return !fileName.empty();
}
bool ReferenceData::getInput(std::string & fileName, const int testCase)
{
	assert(-1 < testCase && testCase < m_count);

    GenericValue v = m_data[settings::inputTokenName].at(testCase);
    fileName = v.stringValue();
    return !fileName.empty();
}

std::string ReferenceData::getString(const std::string& tag, const int testCase)
{
	assert(-1 < testCase && testCase < m_count);
	checkKey(tag);
    return m_data[tag][testCase].stringValue();
}
bool ReferenceData::getBool(const std::string& tag, const int testCase)
{
	assert(-1 < testCase && testCase < m_count);
	checkKey(tag);
    return m_data[tag][testCase].boolValue();
}

void ReferenceData::checkKey(const std::string& tag)
{
	if (m_data.find(tag) == m_data.end())
	{
		EXPECT_TRUE(m_data.find(tag) != m_data.end()) << "Tag: " << tag;
		throw ReferenceDataKeyFailed();
	}
}
}
}

