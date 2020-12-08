#pragma once
#include <VPL/Image/Image.h>
namespace vpl
{
namespace test
{
namespace metrics
{
namespace settings
{
const double eps = 0.00001;
}

//! Checks for same image size.
template <typename T>
bool checkInputs(img::CImage<T>& image1, img::CImage<T>& image2)
{
	return !static_cast<bool>(image1.getXSize() != image2.getXSize() || image1.getYSize() != image2.getYSize());
}

template <typename T>
bool ad(img::CImage<T>& image1, img::CImage<T>& image2, double& value)
{
    if(!checkInputs(image1, image2))
    {
        return false;
    }

    const int xSize = image1.getXSize();
    const int ySize = image1.getYSize();

    double error = 0.0;
    for (int y = 0; y < ySize; y++)
    {
        for (int x = 0; x < xSize; x++)
        {
            const double currentError = abs(image1.at(x, y) - image2.at(x, y));
            if (error < currentError)
            {
                error = currentError;
            }
        }
    }
    value = error;
    return true;
}
template <typename T>
bool mse(img::CImage<T>& image1, img::CImage<T>& image2,double& value)
{
    if (!checkInputs(image1, image2))
    {
        return false;
    }

    const int xSize = image1.getXSize();
    const int ySize = image1.getYSize();

    double error = 0.0;
    const int countPixels = xSize * ySize;

    for (int y = 0; y < ySize; y++)
    {
        for (int x = 0; x < xSize; x++)
        {
            error += pow(image1.at(x, y) - image2.at(x, y), 2);
        }
    }
    error /= countPixels;
    value = error;
    return true;
}

template <typename T>
bool psnr(img::CImage<T>& image1, img::CImage<T>& image2,double& value)
{
    double ret = INFINITY;

    double mseValue;
    
    if (!mse(image1, image2, mseValue))
    {
        return false;
    }

    double maxValue = img::CPixelTraits<T>::getPixelMax();
    if (abs(mseValue) > settings::eps)
    {
        ret = 10 * log10(maxValue * maxValue / mseValue);
    }
    value = ret;
    return true;
}
}
}
}