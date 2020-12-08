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
 * Copyright (c) 2003-2010 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2006/02/12                       
 *
 * Description:
 * - Base class for all vectors.
 */

#ifndef VPL_VECTORBASE_H
#define VPL_VECTORBASE_H

#include <VPL/Base/Setup.h>
#include <VPL/Base/Scalar.h>


namespace vpl
{
namespace math
{

//==============================================================================
/*!
 * Traits used to implement curiously recurring template pattern for vectors.
 */
template <typename M>
struct CVectorTraits
{
    //! Vector coefficient type.
    typedef tNull tElement;   
};


//! Helper macro used to declare vector traits before a vector class template.
#define VPL_VECTOR_TRAITS(VectorClass) \
    template <typename T> class VectorClass; \
    template <typename T> \
    struct CVectorTraits<VectorClass<T> > \
    { \
        typedef T tElement; \
    };


//! Helper macro used to declare vector traits before a vector class template.
#define VPL_STATIC_VECTOR_TRAITS(VectorClass) \
    template <typename T, tSize M> class VectorClass; \
    template <typename T, tSize M> \
    struct CVectorTraits<VectorClass<T,M> > \
    { \
        typedef T tElement; \
    };


//==============================================================================
/*!
 * Base class for all vectors.
 * - Base class takes a template parameter V. This parameter is the type
 *   of the class which derives from it (so called curiously recurring template
 *   pattern).
 */
template <class V>
class CVectorBase
{
public:
    //! Vector type.
    typedef V tVector;
    
    //! Element tyoe.
    typedef typename CVectorTraits<V>::tElement tElement;

public:
    //! Returns reference to the vector implementation.
    tVector& getImpl()
    {
        return *static_cast<tVector *>(this);
    }
    const tVector& getImpl() const
    {
        return *static_cast<const tVector *>(this);
    }

public:
    //! Returns the vector size.
    tSize getSize() const { return getImpl().getSize(); }

    //! Returns the vector size.
    tSize size() const { return getImpl().size(); }

    //! Returns stride between two neigbouring vector elements.
    tSize getStride() const { return getImpl().getStride(); }


    //! Returns reference to the element [i].
    tElement& at(tSize i)
    {
        return getImpl().at(i);
    }
    const tElement& at(tSize i) const
    {
        return getImpl().at(i);
    }

    //! Returns reference to the subscripted element [i].
    tElement& operator ()(tSize i)
    {
        return getImpl().at(i);
    }
    const tElement& operator ()(tSize i) const
    {
        return getImpl().at(i);
    }

    //! Sets the vector element at the position [i].
    tVector& set(tSize i, const tElement& Value)
    {
        return getImpl().set(i, Value);
    }


    //! Calls a function object for every vector element.
    template <class Function>
    inline Function forEach(Function Func)
    {
        return getImpl().forEach(Func);
    }

    //! Calls a function object for every vector element.
    template <class Function>
    inline Function forEach(Function Func) const
    {
        return getImpl().forEach(Func);
    }

protected:
    //! Default constructor.
    CVectorBase() {}

    //! Copy constructor.
    CVectorBase(const CVectorBase&) {}

    //! Assignment operator.
    CVectorBase& operator =(const CVectorBase&) {}
};


} // namespace math
} // namespace vpl

#endif // VPL_VECTORBASE_H

