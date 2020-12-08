#pragma once
#include "compare1D.h"
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

template <typename T, class Object, template <typename, class> class Accessor>
void Compare1D<T, Object, Accessor>::values(T* requiredData,const Object& data, const int size, double ulp)
{
    std::string dataContent = CompareBase<Object>::dataToString(data);

    for (int index = 0; index < size; index++)
    {
        T requiredValue = requiredData[index];
        T inputValue = m_accessor(data, index);
        CompareBase<Object>::comparation(requiredValue, inputValue, std::to_string(index), dataContent, ulp);
    }
}

template<typename T, class Object, template <typename, class> class Accessor>
void Compare1D<T, Object, Accessor>::valuesString(std::string* requiredData, Object & data, const int size)
{
    std::string dataContent;// = dataToString(data);

    for (int index = 0; index < size; index++)
    {
        std::string requiredValue = requiredData[index];
        const std::string inputValue = m_accessor(data, index);
        CompareBase<Object>::comparationString(requiredValue, inputValue, std::to_string(index), dataContent);
    }
}

template<typename T, class Object, template <typename, class> class Accessor>
void Compare1D<T, Object, Accessor>::valuesString(std::string requiredValue, Object & data, const int size)
{
    std::string dataContent;// = dataToString(data);

    for (int index = 0; index < size; index++)
    {
        const std::string inputValue = m_accessor(data, index);
        CompareBase<Object>::comparationString(requiredValue, inputValue, std::to_string(index), dataContent);
    }
}

template <typename T, class Object, template <typename, class> class Accessor>
void Compare1D<T, Object, Accessor>::sequence(Object& data, int size, T firstValue, T step, double ulp)
{
	const std::string dataString = CompareBase<Object>::dataToString(data);
	T requiredValue = firstValue;
	for (int index = 0; index < size; index++)
	{
		T inputValue;
		
		inputValue = m_accessor(data, index);
		CompareBase<Object>::comparation(requiredValue, inputValue,
			std::to_string(index), dataString, ulp);
		requiredValue += step;

	}
}


template <typename T, class Object, template <typename, class> class Accessor>
void Compare1D<T, Object, Accessor>::values(T requiredValue, const Object& data, const int size, double ulp)
{
    const std::string dataContent = CompareBase<Object>::dataToString(data);

    for (int index = 0; index < size; index++)
    {
        T inputValue = m_accessor(data,index);
        CompareBase<Object>::comparation(requiredValue, inputValue, std::to_string(index), dataContent, ulp);
    }
}

template <typename T, class Object, template <typename, class> class Accessor>
void Compare1D<T, Object, Accessor>::range(T requiredValue, Object& data, const int startPosition, const int offset, double ulp)
{
    std::string dataContent = CompareBase<Object>::dataToString(data);

    for (int index = startPosition; index < startPosition + offset; index++)
    {
        T inputValue = m_accessor(data, index);
        CompareBase<Object>::comparation(requiredValue, inputValue, std::to_string(index), dataContent, ulp);
    }
}
