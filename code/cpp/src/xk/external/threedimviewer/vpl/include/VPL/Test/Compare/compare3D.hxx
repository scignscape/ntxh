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
void Compare3D<T, Object, Accessor>::values(T requiredValue, Object& data, const int xSize, const int ySize,
    const int zSize, double ulp)
{
    const std::string dataString = CompareBase<Object>::dataToString(data);

    for (int z = 0; z < zSize; z++)
    {
        for (int y = 0; y < ySize; y++)
        {
            for (int x = 0; x < xSize; x++)
            {
                T inputValue;
                if (CompareBase<Object>::m_accessType == XY_ACCESS)
                {
                    inputValue = m_accessor(data, x, y, z);
                }
                else
                {
                    inputValue = m_accessor(data, y, x, z);
                }
                CompareBase<Object>::comparation(requiredValue, inputValue, std::to_string(x) + "," +
                    std::to_string(y) + "," + std::to_string(z), dataString, ulp);
            }
        }
    }
}

template <typename T, class Object, template <typename, class> class Accessor>
inline void Compare3D<T, Object, Accessor>::valuesWithReference(const Object& referenceObject, const Object & data, int xSize, int ySize, int zSize, double ulp)
{
    const std::string dataString = CompareBase<Object>::dataToString(data);
    for (int z = 0; z < zSize; z++)
    {
        for (int y = 0; y < ySize; y++)
        {
            for (int x = 0; x < xSize; x++)
            {
                T inputValue;
                T requiredValue;

                if (CompareBase<Object>::m_accessType == XY_ACCESS)
                {
                    requiredValue = m_accessor(referenceObject, x, y, z);
                    inputValue = m_accessor(data, x, y, z);
                }
                else
                {
                    requiredValue = m_accessor(referenceObject, y, x, z);
                    inputValue = m_accessor(data, y, x, z);
                }
                CompareBase<Object>::comparation(requiredValue, inputValue,
                    std::to_string(x) + "," +
                    std::to_string(y) + "," + std::to_string(z), dataString, ulp);
                if (CompareBase<Object>::m_isAssertMode)
                {
                    if (::testing::Test::HasFatalFailure()) return;
                }
            }
        }
    }
}

template <typename T, class Object, template <typename, class> class Accessor>
void Compare3D<T, Object, Accessor>::values(T* requiredData, Object& data, const int xSize, const int ySize,
    const int zSize, double ulp)
{
    const std::string dataString = CompareBase<Object>::dataToString(data);

    for (int z = 0; z < zSize; z++)
    {
        for (int y = 0; y < ySize; y++)
        {
            for (int x = 0; x < xSize; x++)
            {
                int index;
                if (CompareBase<Object>::m_arrayOrder == ROW_MAJOR)
                {
                    index = y * xSize + x + z * xSize*zSize;
                }
                else
                {
                    index = x * ySize + y + z * ySize * zSize;
                }
                T requiredValue = requiredData[index];
                T inputValue;
                if (CompareBase<Object>::m_accessType == XY_ACCESS)
                {
                    inputValue = m_accessor(data, x, y, z);
                }
                else
                {
                    inputValue = m_accessor(data, y, x, z);
                }
                CompareBase<Object>::comparation(requiredValue, inputValue, std::to_string(x) + "," +
                    std::to_string(y) + "," + std::to_string(z), dataString, ulp);
            }
        }
    }
}

template <typename T, class Object, template <typename, class> class Accessor>
void Compare3D<T, Object, Accessor>::sequence(Object& data, const int xSize, const int ySize, const int zSize,
    T firstValue, T step, double ulp)
{
    const std::string dataString = CompareBase<Object>::dataToString(data);
    T requiredValue = firstValue;
    for (int z = 0; z < zSize; z++)
    {
        for (int y = 0; y < ySize; y++)
        {
            for (int x = 0; x < xSize; x++)
            {
                T inputValue;
                if (CompareBase<Object>::m_accessType == XY_ACCESS)
                {
                    inputValue = m_accessor(data, x, y, z);
                }
                else
                {
                    inputValue = m_accessor(data, y, x, z);
                }

                CompareBase<Object>::comparation(requiredValue, inputValue, std::to_string(x) + "," +
                    std::to_string(y) + "," + std::to_string(z), dataString, ulp);
                requiredValue += step;
            }
        }
    }
}
