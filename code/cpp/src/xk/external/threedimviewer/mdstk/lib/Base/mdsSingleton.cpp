//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/10/17                          \n
 *
 * $Id: mdsSingleton.cpp 1863 2010-08-31 20:40:15Z spanel $
 * 
 * This code is based on The Loki Library which accompanies
 * the famous book:
 * Alexandrescu, Andrei. "Modern C++ Design: Generic Programming and Design
 *     Patterns Applied". Copyright (c) 2001. Addison-Wesley.
 *
 * The Loki Library
 * Copyright (c) 2001 by Andrei Alexandrescu
 * Permission to use, copy, modify, distribute and sell this software for any
 *     purpose is hereby granted without fee, provided that the above copyright
 *     notice appear in all copies and that both that copyright notice and this
 *     permission notice appear in supporting documentation.
 *
 * Description:
 * - Template definition of a singleton.
 * - The singleton has only one instance which is initialized
 *   at the first call to ::getInstance() method.
 */

#include <MDSTk/Base/mdsSingleton.h>


namespace mds
{
namespace base
{

//==============================================================================
/*
 * Global variables.
 */

//! Vector of all created singleton instances.
//tSingletonTracker pSingletonTracker     = 0;
tSingletonTracker *pSingletonTracker    = 0;

//! The number of elements in the array.
//unsigned int uElements                  = 0;


//==============================================================================
/*
 * Global functions.
 */

//! Ensures proper destruction of objects with longevity
void atExitFunction()
{
/*    MDS_ASSERT(uElements > 0 && pSingletonTracker != 0);

    // Pick the element at the top of the stack
    CSingletonLifetime *pTop = pSingletonTracker[uElements - 1];

    // Remove that object off the stack
    // Don't check errors - realloc with less memory can't fail
    pSingletonTracker = static_cast<tSingletonTracker>(
                            std::realloc(pSingletonTracker, sizeof(*pSingletonTracker) * --uElements)
                            );

    // Destroy the element
    delete pTop;*/

    MDS_ASSERT(pSingletonTracker && !pSingletonTracker->empty());

    // Pick the element at the top of the stack
    CSingletonLifetime* pTop = pSingletonTracker->back();

    // Remove that object off the stack before deleting pTop
    pSingletonTracker->pop_back();

    // Destroy the element
    delete pTop;

    // Destroy stack when it's empty _after_ deleting pTop
    if( pSingletonTracker->empty() )
    {
        delete pSingletonTracker;
        pSingletonTracker = 0;
    }
}


} // namespace base
} // namespace mds

