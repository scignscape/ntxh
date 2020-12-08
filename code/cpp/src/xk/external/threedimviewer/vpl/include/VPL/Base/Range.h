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
 * Author:  info@3dim-labroatory.cz             \n
 * Date:    2012/01/01                          \n
 */

#ifndef VPL_Range_H
#define VPL_Range_H

#include <VPL/Base/BaseExport.h>
#include <VPL/Base/TypeTraits.h>
#include <VPL/Math/Base.h>


namespace vpl
{

//==============================================================================
/*!
* Class used to specify a span (or subsequence) of indices.
*/

class VPL_BASE_EXPORT CRange
{
public:
    //! Default constructor initializes range of a zero length.
    CRange() : m_Begin(0), m_End(0) {}

    //! Index of the first and the last item.
    CRange(tSize First, tSize Last) : m_Begin(First), m_End(++Last) {}

    //! Assignment operator.
    inline CRange& operator = (const CRange& r)
    {
        m_Begin = r.m_Begin;
        m_End = r.m_End;
        return *this;
    }

    //! Returns length of the range.
    tSize getSize() const { return (m_End - m_Begin); }

    //! Returns true if the range is empty.
    bool isEmpty() const { return (m_End == m_Begin); }

    //! Returns index of the first item.
    tSize getFirst() const { return m_Begin; }

    //! Returns index of the last item.
    tSize getLast() const { return (m_End - 1); }

    //! Returns index of the first item.
    tSize getBegin() const { return m_Begin; }

    //! Returns index of the item just after the last one.
    tSize getEnd() const { return m_End; }

    //! Returns a range representing all posible values.
    static CRange all()
    {
        return CRange(CTypeTraits<tSize>::getMin(), CTypeTraits<tSize>::getMax());
    }

    //! Comparison operator.
    inline bool operator == (const CRange& b)
    {
        return (m_Begin == b.m_Begin) && (m_End == b.m_End);
    }
    inline bool operator != (const CRange& b)
    {
        return (m_Begin != b.m_Begin) || (m_End != b.m_End);
    }

    //! Operator calculates intersection of two given ranges.
    inline CRange operator & (const CRange& b)
    {
        CRange r(vpl::math::getMax(m_Begin, b.m_Begin), vpl::math::getMin(b.m_End, b.m_End));
        r.m_End = vpl::math::getMax(r.m_Begin, r.m_End);
        return r;
    }
    inline CRange& operator &= (const CRange& r)
    {
        m_Begin = vpl::math::getMax(m_Begin, r.m_Begin);
        m_End = vpl::math::getMin(m_End, r.m_End);
        m_End = vpl::math::getMax(m_Begin, m_End);
        return *this;
    }

    //! Shifts the whole range.
    inline CRange operator + (tSize d)
    {
        return CRange(m_Begin + d, m_End + d);
    }
    inline CRange& operator += (tSize d)
    {
        m_Begin += d;
        m_End += d;
        return *this;
    }

    //! Shifts the whole range.
    inline CRange operator- (tSize d)
    {
        return CRange(m_Begin - d, m_End - d);
    }
    inline CRange& operator -= (tSize d)
    {
        m_Begin -= d;
        m_End -= d;
        return *this;
    }

public:
    //! Index of the first item.
    tSize m_Begin;

    //! Index of the item just after the last one.
    tSize m_End;
};


} // namespace vpl

#endif // VPL_Range_H
