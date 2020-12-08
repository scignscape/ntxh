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
 * Copyright (c) 2010 by Michal Spanel          \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2010/01/25                          \n
 *
 * Description:
 * - Helper traits used to implement curiously recurring template pattern
 *   for iterators.
 */

#ifndef VPL_IteratorTraits_H
#define VPL_IteratorTraits_H

#include <VPL/Base/TypeTraits.h>


namespace vpl
{

//==============================================================================
/*!
 * Traits used to implement curiously recurring template pattern for iterators.
 */
template <typename M>
struct CIteratorTraits
{
    //! Item type.
    typedef tNull tItem;   
};


//==============================================================================
/*
 * Helper macros.
 */

//! Helper macro used to declare iterator traits before the iterator class.
//! - Make sure that you use this macro within the namespace vpl!
#define VPL_ITERATOR_CLASS_TRAITS(Namespace, IteratorClass, ItemType) \
    namespace Namespace { class IteratorClass; } \
    template <> \
    struct CIteratorTraits<Namespace::IteratorClass> \
    { \
        typedef ItemType tItem; \
    };

//! Helper macro used to declare iterator traits before the iterator class.
//! - Make sure that you use this macro within the namespace vpl!
#define VPL_ITERATOR_TEMPLATE_TRAITS(Namespace, IteratorClassTemplate) \
    namespace Namespace { template <class C, typename T> class IteratorClassTemplate; } \
    template <class C, typename T> \
    struct CIteratorTraits<Namespace::IteratorClassTemplate<C, T> > \
    { \
        typedef T tItem; \
    };


} // namespace vpl

#endif // VPL_IteratorTraits_H
