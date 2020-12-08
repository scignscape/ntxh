#pragma once
#include <VPL/Image/Image.h>
#include "VPL/Image/Volume.h"
#include <VPL/Math/Matrix.h>

//! Define operator<< for printing of several classes. 
//! Is required for nice output of input data.
namespace vpl
{
namespace img
{
template <typename T, template <typename> class Allocator = VPL_IMAGE_DATA_ALLOCATOR>
inline ::std::ostream& operator<<(::std::ostream& os, const CImage<T, Allocator>& image)
{
    os << std::endl;

    for (int y = 0; y < image.getYSize(); y++)
    {
        for (int x = 0; x < image.getXSize(); x++)
        {
            os << image(x, y) << " ";
        }
        os << std::endl;
    }
    os << std::endl;


    os << std::endl;
    return os;
}

template <class T>
::std::ostream& operator<<(::std::ostream& os, const CVolume<T>& volume)
{
    os << std::endl;
    for (int z = 0; z < volume.getZSize(); z++)
    {
        os << "#############" << std::endl;
        for (int y = 0; y < volume.getYSize(); y++)
        {
            for (int x = 0; x < volume.getXSize(); x++)
            {
                os << volume(x, y, z) << " ";
            }
            os << std::endl;
        }
        os << std::endl;
    }

    os << std::endl;
    return os;
}
} // namespace img

namespace math
{
template <class T>
::std::ostream& operator<<(::std::ostream& os, const vpl::math::CVector<T>& v) {
	for (vpl::tSize i = 0; i < v.getSize(); i++)
	{
		os << v(i) << " ";
	}
	return os;
}
template <class T>
::std::ostream& operator<<(::std::ostream& os, const vpl::math::CMatrix<T>& m)
{
    os << std::endl;
    for (vpl::tSize i = 0; i < m.getNumOfRows(); i++)
    {
        for (vpl::tSize j = 0; j < m.getNumOfCols(); j++)
        {
            os << m(i, j) << " ";
        }
        os << std::endl;
    }
    return os;
}
template <typename T, tSize M, tSize N>
::std::ostream& operator<<(::std::ostream& os, const vpl::math::CStaticMatrix<T, M, N>& m)
{
    os << std::endl;
    for (vpl::tSize i = 0; i < m.getNumOfRows(); i++)
    {
        for (vpl::tSize j = 0; j < m.getNumOfCols(); j++)
        {
            os << m(i, j) << " ";
        }
        os << std::endl;
    }
    return os;
}
} // namespace math
} // namespace vpl
