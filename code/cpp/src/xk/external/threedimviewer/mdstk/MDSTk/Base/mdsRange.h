//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2012 by 3Dim Laboratory s.r.o. \n
 *
 * Author:  info@3dim-labroatory.cz             \n
 * Date:    2012/01/01                          \n
 *
 * $Id:$
 */

#ifndef MDS_Range_H
#define MDS_Range_H

#include <MDSTk/Base/mdsBaseExport.h>
#include <MDSTk/Base/mdsTypeTraits.h>
#include <MDSTk/Math/mdsBase.h>


namespace mds
{

//==============================================================================
/*!
 * Class used to specify a span (or subsequence) of indices.
 */

class MDS_BASE_EXPORT CRange
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
    int getFirst() const { return m_Begin; }

    //! Returns index of the last item.
    int getLast() const { return (m_End - 1); }

    //! Returns index of the first item.
    int getBegin() const { return m_Begin; }

    //! Returns index of the item just after the last one.
    int getEnd() const { return m_End; }

    //! Returns a range representing all posible values.
    static CRange all()
    {
        return CRange(CTypeTraits<tSize>::getMin(), CTypeTraits<tSize>::getMax());
    }

    //! Comparison operator.
    inline friend bool operator == (const CRange& a, const CRange& b)
    {
        return (a.m_Begin == b.m_Begin) && (a.m_End == b.m_End);
    }
    inline friend bool operator != (const CRange& a, const CRange& b)
    { 
        return (a.m_Begin != b.m_Begin) || (a.m_End != b.m_End);
    }

    //! Operator calculates intersection of two given ranges.
    inline friend CRange operator & (const CRange& a, const CRange& b)
    {
        CRange r(mds::math::getMax(a.m_Begin, b.m_Begin), mds::math::getMin(b.m_End, b.m_End));
        r.m_End = mds::math::getMax(r.m_Begin, r.m_End);
        return r;
    }
    inline CRange& operator &= (const CRange& r)
    {
        m_Begin = mds::math::getMax(m_Begin, r.m_Begin);
        m_End = mds::math::getMin(m_End, r.m_End);
        m_End = mds::math::getMax(m_Begin, m_End);
        return *this;
    }

    //! Shifts the whole range.
    inline friend CRange operator + (const CRange& r, tSize d)
    {
        return CRange(r.m_Begin + d, r.m_End + d);
    }
    inline CRange& operator += (tSize d)
    {
        m_Begin += d;
        m_End += d;
        return *this;
    }

    //! Shifts the whole range.
    inline friend CRange operator - (const CRange& r, tSize d)
    {
        return CRange(r.m_Begin - d, r.m_End - d);
    }
    inline CRange& operator -= (tSize d)
    {
        m_Begin -= d;
        m_End -= d;
        return *this;
    }

public:
    //! Index of the first item.
    int m_Begin;
    
    //! Index of the item just after the last one.
    int m_End;
};


} // namespace mds

#endif // MDS_Range_H
