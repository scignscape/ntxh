#include "compare2D.h"
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
template <typename T, class Object, template <typename, class> class Accessor>
void Compare2D<T, Object, Accessor>::values(T* requiredData, Object& data, const int xSize, const int ySize, double ulp)
{
    const std::string dataString = CompareBase<Object>::dataToString(data);

    for (int y = 0; y < ySize; y++)
    {
        for (int x = 0; x < xSize; x++)
        {
            T requiredValue;
            if (CompareBase<Object>::m_arrayOrder == ROW_MAJOR)
            {
                requiredValue = requiredData[y*xSize + x];
            }
            else
            {
                requiredValue = requiredData[x*ySize + y];
            }
            T inputValue;
            if (CompareBase<Object>::m_accessType == XY_ACCESS)
            {
                inputValue = m_accessor(data, x, y);
            }
            else
            {
                inputValue = m_accessor(data, y, x);
            }
            CompareBase<Object>::comparation(requiredValue, inputValue,
                std::to_string(x) + "," + std::to_string(y), dataString, ulp);
        }
    }
}

template <typename T, class Object, template <typename, class> class Accessor>
void Compare2D<T, Object, Accessor>::values(T requiredValue, Object& data, const int xSize, const int ySize, double ulp)
{
    const std::string dataString = CompareBase<Object>::dataToString(data);

    for (int y = 0; y < ySize; y++)
    {
        for (int x = 0; x < xSize; x++)
        {
            T inputValue;
            if (CompareBase<Object>::m_accessType == XY_ACCESS)
            {
                inputValue = m_accessor(data, x, y);
            }
            else
            {
                inputValue = m_accessor(data, y, x);
            }
            CompareBase<Object>::comparation(requiredValue, inputValue,
                std::to_string(x) + "," + std::to_string(y), dataString, ulp);
        }
    }
}

template <typename T, class Object, template <typename, class> class Accessor>
inline void Compare2D<T, Object, Accessor>::valuesWithReference(const Object& referenceObject, const Object & data, int xSize, int ySize, double ulp)
{
    const std::string dataString = CompareBase<Object>::dataToString(data);

    for (int y = 0; y < ySize; y++)
    {
        for (int x = 0; x < xSize; x++)
        {
            T inputValue;
            T requiredValue;

            if (CompareBase<Object>::m_accessType == XY_ACCESS)
            {
                requiredValue = m_accessor(referenceObject, x, y);
                inputValue = m_accessor(data, x, y);
            }
            else
            {
                requiredValue = m_accessor(referenceObject, y, x);
                inputValue = m_accessor(data, y, x);
            }
            CompareBase<Object>::comparation(requiredValue, inputValue,
                std::to_string(x) + "," + std::to_string(y), dataString, ulp);
            if (CompareBase<Object>::m_isAssertMode)
            {
                if (::testing::Test::HasFatalFailure()) return;
            }
        }
    }
}



template <typename T, class Object, template <typename, class> class Accessor>
void Compare2D<T, Object, Accessor>::valuesWithMargin(T requiredValue, Object& data, const int xSize,
    const int ySize, const int margin, const double ulp)
{
    const std::string dataString = CompareBase<Object>::dataToString(data);

    for (int y = -margin; y < ySize + margin; y++)
    {
        for (int x = -margin; x < xSize + margin; x++)
        {
            T inputValue;
            if (CompareBase<Object>::m_accessType == XY_ACCESS)
            {
                inputValue = m_accessor(data, x, y);
            }
            else
            {
                inputValue = m_accessor(data, y, x);
            }
            CompareBase<Object>::comparation(requiredValue, inputValue,
                std::to_string(x) + "," + std::to_string(y), dataString, ulp);
        }
    }
}

template <typename T, class Object, template <typename, class> class Accessor>
void Compare2D<T, Object, Accessor>::valuesWithMargin(T* requiredData, Object& data, const int xSize,
    const int ySize, const int margin, const double ulp)
{
    const std::string dataString = CompareBase<Object>::dataToString(data);

    const int offsetSize = margin << 1;

    for (int y = -margin; y < ySize + margin; y++)
    {
        for (int x = -margin; x < xSize + margin; x++)
        {
            T requiredValue;
            if (CompareBase<Object>::m_arrayOrder == ROW_MAJOR)
            {
                requiredValue = requiredData[(y + margin)*(xSize + offsetSize) + x + margin];
            }
            else
            {
                requiredValue = requiredData[(x + margin)*(ySize + offsetSize) + y + margin];
            }

            T inputValue;
            if (CompareBase<Object>::m_accessType == XY_ACCESS)
            {
                inputValue = m_accessor(data, x, y);
            }
            else
            {
                inputValue = m_accessor(data, y, x);
            }
            CompareBase<Object>::comparation(requiredValue, inputValue,
                std::to_string(x) + "," + std::to_string(y), dataString, ulp);
        }
    }
}

template <typename T, class Object, template <typename, class> class Accessor>
void Compare2D<T, Object, Accessor>::sequence(Object& data, const int xSize, const int ySize, const T firstValue,
                                              const T step, const double ulp)
{
    const std::string dataString = CompareBase<Object>::dataToString(data);
    T requiredValue = firstValue;
    for (int y = 0; y < ySize; y++)
    {
        for (int x = 0; x < xSize; x++)
        {
            T inputValue;
            if (CompareBase<Object>::m_accessType == XY_ACCESS)
            {
                inputValue = m_accessor(data, x, y);
            }
            else
            {
                inputValue = m_accessor(data, y, x);
            }
            CompareBase<Object>::comparation(requiredValue, inputValue,
                std::to_string(x) + "," + std::to_string(y), dataString, ulp);
            requiredValue += step;
        }
    }
}
