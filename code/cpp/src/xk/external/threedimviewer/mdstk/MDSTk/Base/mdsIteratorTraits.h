//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2010 by Michal Spanel          \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2010/01/25                          \n
 *
 * $Id: mdsIteratorTraits.h 2092 2012-02-15 12:50:59Z spanel $
 *
 * Description:
 * - Helper traits used to implement curiously recurring template pattern
 *   for iterators.
 */

#ifndef MDS_IteratorTraits_H
#define MDS_IteratorTraits_H

#include <MDSTk/Base/mdsTypeTraits.h>


namespace mds
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
//! - Make sure that you use this macro within the namespace mds!
#define MDS_ITERATOR_CLASS_TRAITS(Namespace, IteratorClass, ItemType) \
    namespace Namespace { class IteratorClass; } \
    template <> \
    struct CIteratorTraits<Namespace::IteratorClass> \
    { \
        typedef ItemType tItem; \
    };

//! Helper macro used to declare iterator traits before the iterator class.
//! - Make sure that you use this macro within the namespace mds!
#define MDS_ITERATOR_TEMPLATE_TRAITS(Namespace, IteratorClassTemplate) \
    namespace Namespace { template <class C, typename T> class IteratorClassTemplate; } \
    template <class C, typename T> \
    struct CIteratorTraits<Namespace::IteratorClassTemplate<C, T> > \
    { \
        typedef T tItem; \
    };


} // namespace mds

#endif // MDS_IteratorTraits_H
