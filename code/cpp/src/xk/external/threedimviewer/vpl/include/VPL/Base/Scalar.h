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
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2012 by 3Dim Laboratory s.r.o. \n
 *
 * Author:  info@3dim-laboratory.cz             \n
 * Date:    2012/02/12                          \n
 *
 * Description:
 * - Wrapper for scalars.
 */

#ifndef VPL_Scalar_H
#define VPL_Scalar_H

#include "TypeTraits.h"
#include "Templates.h"


namespace vpl
{

//==============================================================================
/*!
 * Simple wrapper for scalars.
 */
template <typename T>
class CScalar
{
public:
    //! Type of the scalar
    typedef T tValue;

public:
    //! Default constructor.
    CScalar() : m_Value() {}

    //! Constructor.
    CScalar(tValue Value) : m_Value(Value) {}

    //! Copy constructor.
    CScalar(const CScalar& Scalar) : m_Value(Scalar.m_Value) {}

    //! Conversion to the original type.
    operator tValue() { return m_Value; }

    //! Returns the wrapped value.
    tValue& value()
    {
        return m_Value;
    }
    const tValue& value() const
    {
        return m_Value;
    }

protected:
    //! Wrapped scalar.
    tValue m_Value;
};


//==============================================================================
/*
 * Pre-defined types.
 */

typedef CScalar<int>        CScalari;
typedef CScalar<float>      CScalarf;
typedef CScalar<double>     CScalard;


} // namespace vpl

#endif // VPL_Scalar_H
