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
#include "VPL/Image/Image.h"

namespace vpl
{
namespace test
{
namespace metrics
{

//! \brief AD comparation method
//! 
//! Warning: This method does not reflect the different data types.
//! \tparam T Pixel type
//! \param image1 First image
//! \param image2 Second image
//! \param value Reference return for comparation result value.
//! \return True - Comparation success | False - Comparation failure
template <typename T>
bool ad(img::CImage<T>& image1, img::CImage<T>& image2, double& value);

//! \brief MSE comparation method
//! 
//! Warning: This method does not reflect the different data types.
//! \tparam T Pixel type
//! \param image1 First image
//! \param image2 Second image
//! \param value Reference return for comparation result value.
//! \return True - Comparation success | False - Comparation failure

template <typename T>
bool mse(img::CImage<T>& image1, img::CImage<T>& image2, double& value);

//! \brief AD comparation method
//! 
//! Info: This method reflect the different data types.
//! \tparam T Pixel type
//! \param image1 First image
//! \param image2 Second image
//! \param value Reference return for comparation result value.
//! \return True - Comparation success | False - Comparation failure
template <typename T>
bool psnr(img::CImage<T>& image1, img::CImage<T>& image2, double& value);

}
} // namespace test
} // namespace vpl

  // Include the file containing functions templates.
#include "imageMetrics.hxx"
