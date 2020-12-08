#pragma once
#include "compareBase.h"
#include <VPL/Base/TypeTraits.h>
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



//==============================================================================
template<class Object>
std::string CompareBase<Object>::dataToString(const Object& data) const
{
    if (m_printData) return ::testing::PrintToString(data);
    return "";
}

template <class Object>
std::string CompareBase<Object>::getErrorMessage(const std::string& inMessage, const std::string& index,
    const std::string& dataString)
{
    std::string outMessage;
    outMessage += inMessage + " [" + index + "]\n";
    outMessage += (!dataString.empty()) ? "Input data: <" + dataString + ">" : "";
    return outMessage;
}

template <class Object>
CompareBase<Object>::CompareBase(): 
m_arrayOrder(ROW_MAJOR), m_accessType(XY_ACCESS), m_printData(false), m_caseSensitive(false), m_isAssertMode(false)
{}

template <class Object>
CompareBase<Object>::CompareBase(const bool printData): 
m_arrayOrder(ROW_MAJOR), m_accessType(XY_ACCESS), m_printData(printData), m_caseSensitive(false), m_isAssertMode(false)
{}

template <class Object>
void CompareBase<Object>::setArrayOrder(const ArrayOrder order)
{
    m_arrayOrder = order;
}

template <class Object>
void CompareBase<Object>::setAccessType(const AccessType access)
{
	m_accessType = access;
}

template <class Object>
void CompareBase<Object>::setErrorMessage(std::string message)
{
    m_errorMessage = message;
}
template <class Object>
void CompareBase<Object>::enablePrintData(const bool isPrinting)
{
    m_printData = isPrinting;
}

template <class Object>
void CompareBase<Object>::enableCaseSensitive(const bool isSensitive)
{
    m_caseSensitive = isSensitive;
}

template <class Object>
void CompareBase<Object>::enableAssert(const bool isEnabled)
{
	m_isAssertMode = isEnabled;
}


//==============================================================================
template <class Object>
template <typename Type>
void CompareBase<Object>::compareIntegral(Type requiredData, Type inputValue, std::string index, const std::string& dataString)
{
	if (m_isAssertMode)
	{
		ASSERT_EQ(requiredData, inputValue) << getErrorMessage(m_errorMessage, index, dataString);
	}
	else
	{
		EXPECT_EQ(requiredData, inputValue) << getErrorMessage(m_errorMessage, index, dataString);
	}
}

template <class Object>
void CompareBase<Object>::compareString(const char* requiredData, const char* inputValue, std::string index, const std::string& dataString) const
{
	if(m_isAssertMode)
	{
		if (m_caseSensitive)
		{
			ASSERT_STREQ(requiredData, inputValue); // << getErrorMessage(m_errorMessage, index, dataString);
		}
		else
		{
			ASSERT_STRCASEEQ(requiredData, inputValue); // << getErrorMessage(m_errorMessage, index, dataString);
		}
	}
	else
	{
        if (m_caseSensitive)
        {
            EXPECT_STREQ(requiredData, inputValue); // << getErrorMessage(m_errorMessage, index, dataString);
        }
        else
        {
            EXPECT_STRCASEEQ(requiredData, inputValue); // << getErrorMessage(m_errorMessage, index, dataString);
        }
    }
}

template <class Object>
template <typename Type>
void CompareBase<Object>::compareFloat(Type requiredData, Type inputValue, double ulp, std::string index, const std::string& dataString)
{
	if(m_isAssertMode)
	{
		ASSERT_NEAR(requiredData, inputValue, ulp) << getErrorMessage(m_errorMessage, index, dataString);
	}
	else
	{
        EXPECT_NEAR(requiredData, inputValue, ulp) << getErrorMessage(m_errorMessage, index, dataString);
    }
}

template <class Object>
template <typename Type>
void CompareBase<Object>::comparation(Type requiredData, Type inputValue, const std::string& index,
                                                   const std::string& dataString, double ulp)
{
    if(vpl::CTypeTraits<Type>::isIntegral)
    {
        compareIntegral(requiredData, inputValue, index, dataString);
    }
    else if(vpl::CTypeTraits<Type>::isFloat)
    {
        compareFloat(requiredData, inputValue, ulp, index, dataString);
    }
}

template<class Object>
 void CompareBase<Object>::comparationString(std::string requiredData, std::string inputValue, const std::string & index, const std::string & dataString, double ulp) const
{
     compareString(requiredData.c_str(), inputValue.c_str(), index, dataString);
}

