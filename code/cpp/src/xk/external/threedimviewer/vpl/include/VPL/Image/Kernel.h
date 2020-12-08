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
 * Copyright (c) 2003-2005 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/04/19                       
 * 
 * Description:
 * - Convolution kernel definition.
 */

#ifndef VPL_KERNEL_H
#define VPL_KERNEL_H

#include <VPL/Base/Assert.h>
#include <VPL/Base/Types.h>
#include <VPL/Base/Data.h>

#include "ImageTypes.h"
#include "ImageExport.h"


namespace vpl
{
namespace img
{

//==============================================================================
/*!
 * Class containing a 1D convolution kernel.
 * - Kernel width must be an odd number.
 */
class VPL_IMAGE_EXPORT CKernel1D : private vpl::base::CData<tConvKernelData>
{
public:
    //! Kernel data.
    typedef vpl::base::CData<tConvKernelData> data;
    typedef data::tData tData;
    typedef data::tDataPtr tDataPtr;
    typedef data::tConstDataPtr tConstDataPtr;

public:
    //! Constructor that creates a new 1D convolution kernel.
    CKernel1D(tSize Size);

    //! Constructor.
    CKernel1D(tConstDataPtr pData, tSize Size);

    //! Copy constructor.
    CKernel1D(const CKernel1D& k);

    //! Virtual destructor.
    virtual ~CKernel1D() {}

    //! Creates a new 1D convolution kernel.
    void resize(tSize Size);

    //! Assignment operator.
    CKernel1D& operator =(const CKernel1D& k);


    //! Returns the kernel size.
    tSize getSize() const { return m_Size; }

    //! Returns subscripted kernel coefficient [i].
    //! - Kernel data are viewed as one dimensional.
    tData& operator ()(tSize i) { return *(m_pData + i); }
    const tData& operator ()(tSize i) const { return *(m_pData + i); }

    //! Returns reference to the kernel coefficient [i].
    //! - Kernel data are viewed as one dimensional.
    tData& at(tSize i) { return *(m_pData + i); }
    const tData& at(tSize i) const { return *(m_pData + i); }

    //! Sets the kernel data.
    void set(tSize i, const tData& Value) { *(m_pData + i) = Value; }

    //! Returns pointer to the kernel data.
    tDataPtr getPtr(tSize i) { return (m_pData + i); }
    tConstDataPtr getPtr(tSize i) const { return (m_pData + i); }

    //! Returns pointer to the kernel data.
    tDataPtr getPtr() { return m_pData; }
    tConstDataPtr getPtr() const { return m_pData; }

    //! Normalizes kernel (sum of weight will be 1.0)
    void normalize();

protected:
    //! Default constructor.
    //! - It does no allocation of the kernel data.
    //! - Be sure that the method init(...) is used somewhere.
    //! - Avoid of using it!
    CKernel1D() {}

    //! Allocates data of a given size.
    //! - This method is primarily designed for kernel data allocation
    //!   when the default constructor was used.
    //! - Provides no checking of the existing data and its (de,re)allocation.
    //! - Avoid of using it!
    void init(tSize Size)
    {
        VPL_ASSERT((Size % 2) == 1);

        data::resize(Size);
    }
};


//==============================================================================
/*!
 * Class encapsulating a 2D convolution kernel.
 */
class VPL_IMAGE_EXPORT CKernel2D : private vpl::base::CData<tConvKernelData>
{
public:
    //! Data base.
    typedef vpl::base::CData<tConvKernelData> data;
    typedef data::tData tData;
    typedef data::tDataPtr tDataPtr;
    typedef data::tConstDataPtr tConstDataPtr;

public:
    //! Constructor that creates a new 2D convolution kernel.
    CKernel2D(tSize Size);

    //! Constructor.
    CKernel2D(tConstDataPtr pData, tSize Size);

    //! Copy constructor.
    CKernel2D(const CKernel2D& k);

    //! Virtual destructor.
    virtual ~CKernel2D() {}

    //! Creates a new 2D convolution kernel.
    void resize(tSize Size);

    //! Assignment operator.
    CKernel2D& operator =(const CKernel2D& k);


    //! Returns the kernel size.
    tSize getSize() const { return m_YOffset; }

    //! Returns reference to the kernel coefficient [x][y].
    //! - Kernel data are viewed as two dimensional.
    tData& operator ()(tSize x, tSize y)
    {
        return *(m_pData + y * m_YOffset + x);
    }
    const tData& operator ()(tSize x, tSize y) const
    {
        return *(m_pData + y * m_YOffset + x);
    }

    //! Returns reference to the kernel coefficient [x][y].
    //! - Kernel data viewed as two dimensional array.
    tData& at(tSize x, tSize y)
    {
        return *(m_pData + y * m_YOffset + x);
    }
    const tData& at(tSize x, tSize y) const
    {
        return *(m_pData + y * m_YOffset + x);
    }

    //! Sets the kernel data.
    void set(tSize x, tSize y, const tData& Value)
    {
        *(m_pData + y * m_YOffset + x) = Value;
    }

    //! Returns pointer to a specified kernel coefficient [x][y].
    tDataPtr getPtr(tSize x, tSize y)
    {
        return (m_pData + y * m_YOffset + x);
    }
    tConstDataPtr getPtr(tSize x, tSize y) const
    {
        return (m_pData + y * m_YOffset + x);
    }

    //! Returns pointer to the kernel data.
    tDataPtr getPtr() { return m_pData; }
    tConstDataPtr getPtr() const { return m_pData; }

protected:
    //! Kernel size in y-dimension.
    tSize m_YOffset;

protected:
    //! Default constructor.
    //! - It does no allocation of the kernel data.
    //! - Be sure that the method init(...) is used somewhere.
    //! - Avoid of using it!
    CKernel2D() {}

    //! Allocates data of a given size.
    //! - This method is primarily designed for kernel data allocation
    //!   when the default constructor was used.
    //! - Provides no checking of the existing data and its (de,re)allocation.
    //! - Avoid of using it!
    void init(tSize Size)
    {
        VPL_ASSERT((Size % 2) == 1);

        data::resize(Size * Size);
        m_YOffset = Size;
    }
};


//==============================================================================
/*!
 * Class encapsulating a 3D convolution kernel.
 */
class VPL_IMAGE_EXPORT CKernel3D : private vpl::base::CData<tConvKernelData>
{
public:
    //! Data base.
    typedef vpl::base::CData<tConvKernelData> data;
    typedef data::tData tData;
    typedef data::tDataPtr tDataPtr;
    typedef data::tConstDataPtr tConstDataPtr;

public:
    //! Constructor that creates a new 3D convolution kernel.
    CKernel3D(tSize Size);

    //! Constructor.
    CKernel3D(tConstDataPtr pData, tSize Size);

    //! Copy constructor.
    CKernel3D(const CKernel3D& k);

    //! Virtual destructor.
    virtual ~CKernel3D() {}

    //! Creates a new 2D convolution kernel.
    void resize(tSize Size);

    //! Assignment operator.
    CKernel3D& operator =(const CKernel3D& k);


    //! Returns the kernel size.
    tSize getSize() const { return m_YOffset; }

    //! Returns the subscripted kernel coefficient [x][y][z].
    //! - Kernel data are viewed as three dimensional.
    tData& operator ()(tSize x, tSize y, tSize z)
    {
        return *(m_pData + z * m_ZOffset + y * m_YOffset + x);
    }
    const tData& operator ()(tSize x, tSize y, tSize z) const
    {
        return *(m_pData + z * m_ZOffset + y * m_YOffset + x);
    }

    //! Returns reference to the kernel coefficient [x][y][z].
    //! - Kernel data are viewed as three dimensional.
    tData& at(tSize x, tSize y, tSize z)
    {
        return *(m_pData + z * m_ZOffset + y * m_YOffset + x);
    }
    const tData& at(tSize x, tSize y, tSize z) const
    {
        return *(m_pData + z * m_ZOffset + y * m_YOffset + x);
    }

    //! Sets the kernel data.
    //! - 3D version.
    void set(tSize x, tSize y, tSize z, const tData& Value)
    {
        *(m_pData + z * m_ZOffset + y * m_YOffset + x) = Value;
    }

    //! Returns pointer to a given kernel data [x][y][z].
    //! - 3D version.
    tDataPtr getPtr(tSize x, tSize y, tSize z)
    {
        return (m_pData + z * m_ZOffset + y * m_YOffset + x);
    }
    tConstDataPtr getPtr(tSize x, tSize y, tSize z) const
    {
        return (m_pData + z * m_ZOffset + y * m_YOffset + x);
    }

    //! Returns pointer to the kernel data.
    tDataPtr getPtr() { return m_pData; }
    tConstDataPtr getPtr() const { return m_pData; }

protected:
    //! Kernel size.
    tSize m_YOffset, m_ZOffset;

protected:
    //! Default constructor.
    //! - It does no allocation of the kernel data.
    //! - Be sure that the method init(...) is used somewhere.
    //! - Avoid of using it!
    CKernel3D() {}

    //! Allocates data of a given size.
    //! - This method is primarily designed for kernel data allocation
    //!   when the default constructor was used.
    //! - Provides no checking of the existing data and its (de,re)allocation.
    //! - Avoid of using it!
    void init(tSize Size)
    {
        VPL_ASSERT((Size % 2) == 1);

        data::resize(Size * Size * Size);
        m_YOffset = Size;
        m_ZOffset = Size * Size;
    }
};


} // namespace img
} // namespace vpl

#endif // VPL_KERNEL_H

