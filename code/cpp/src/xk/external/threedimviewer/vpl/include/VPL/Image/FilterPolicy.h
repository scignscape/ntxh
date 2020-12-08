//==============================================================================
/* This file comes from MDSTk software and was modified for
 * 
 * VPL - Voxel Processing Library
 * Changes are Copyright 2014 3Dim Laboratory s.r.o.
 * All rights reserved.
 * 
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 * 
 * The original MDSTk legal notice can be found below.
 * 
 * Medical Data Segmentation Toolkit (MDSTk) 
 * Copyright (c) 2003-2008 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/10/04                       
 *
 * Description:
 * - Policy for image filter response normalization.
 */

#ifndef VPL_FilterPolicy_H
#define VPL_FilterPolicy_H

#include <VPL/Base/Assert.h>
#include <VPL/Math/Base.h>

#include "ImageTypes.h"
#include "PixelTraits.h"


namespace vpl
{
namespace img
{

//==============================================================================
/*!
 * Base class for all filter response normalization policies.
 * - Parameter T is a pixel type.
 */
template <typename T>
struct CFilterPolicy
{
    //! Pixel type.
    typedef T tPixel;

    //! Filter response type.
    typedef typename CPixelTraits<tPixel>::tFilterResponse tFilterResponse;
};


//==============================================================================
/*!
 * Policy for image filter response normalization.
 * - Simple conversion to a pixel value.
 * - Parameter T is a pixel type.
 */
template <typename T>
class CConvResponse : public CFilterPolicy<T>
{
public:
    //! Base types
    typedef CFilterPolicy<T> tBase;
    typedef typename tBase::tPixel tPixel;
    typedef typename tBase::tFilterResponse tFilterResponse;

public:   
    //! Filter response normalization function.
    static tPixel normalize(tFilterResponse Value)
    {
        return tPixel(Value);
    }
};


//==============================================================================
/*!
 * Policy for image filter response normalization.
 * - Absolute value of the filter response.
 * - Parameter T is a pixel type.
 */
template <typename T>
class CMakeAbs : public CFilterPolicy<T>
{
public:
    //! Base types
    typedef CFilterPolicy<T> tBase;
    typedef typename tBase::tPixel tPixel;
    typedef typename tBase::tFilterResponse tFilterResponse;

public:
    //! Static point response normalization function.
    static tPixel normalize(tFilterResponse Value)
    {
        return tPixel(vpl::math::getAbs(Value));
    }
};


//==============================================================================
/*!
 * Policy for image filter response normalization.
 * - Makes zero response equal to gray (mean pixel value).
 * - Parameter T is a pixel type.
 */
template <typename T>
class CShiftZero2Gray : public CFilterPolicy<T>
{
public:
    //! Base types
    typedef CFilterPolicy<T> tBase;
    typedef typename tBase::tPixel tPixel;
    typedef typename tBase::tFilterResponse tFilterResponse;

public:
    //! Filter point response normalization function.
    static tPixel normalize(tFilterResponse Value)
    {
        return tPixel(Value + CPixelTraits<tPixel>::getGray());
    }
};


//==============================================================================
/*!
 * Policy for image filter response normalization.
 * - Only the positive filter response is accepted.
 * - Parameter T is a pixel type.
 */
template <typename T>
class CDiscardNegative : public CFilterPolicy<T>
{
public:
    //! Base types
    typedef CFilterPolicy<T> tBase;
    typedef typename tBase::tPixel tPixel;
    typedef typename tBase::tFilterResponse tFilterResponse;

public:
    //! Point response normalization function.
    static tPixel normalize(tFilterResponse Value)
    {
        return (Value > tFilterResponse()) ? tPixel(Value) : CPixelTraits<tPixel>::getZero();
    }
};


//==============================================================================
/*!
 * Policy for image filter response normalization.
 * - Calls a specific user function to convert the response.
 */
template <typename T>
class CUserFunc : public CFilterPolicy<T>
{
public:
    //! Base types
    typedef CFilterPolicy<T> tBase;
    typedef typename tBase::tPixel tPixel;
    typedef typename tBase::tFilterResponse tFilterResponse;

    //! Type of the normalization function.
    typedef tPixel (*tNormFunc)(tFilterResponse);

public:
    //! Default constructor.
    CUserFunc(tNormFunc Func = CConvResponse<T>::normalize) : m_NormFunc(Func)
    {
        VPL_ASSERT(Func);
    }

    //! Point response normalization function.
    tPixel normalize(tFilterResponse Value)
    {
        return m_NormFunc(Value);
    }

    //! Sets the normalization function.
    void setNormFunc(tNormFunc Func)
    {
        VPL_ASSERT(Func);

        m_NormFunc = Func;
    }

protected:
    //! Pointer to the concrete normalization function.
    tNormFunc m_NormFunc;
};


//==============================================================================
/*!
 * Default policy for image filter response normalization.
 */
template <typename T>
struct CDefaultFilterPolicy : public CConvResponse<T>
{
    typedef CConvResponse<T> tBase;
    typedef typename tBase::tPixel tPixel;
    typedef typename tBase::tFilterResponse tFilterResponse;
    using tBase::normalize;
};


} // namespace img
} // namespace vpl

#endif // VPL_FilterPolicy_H

