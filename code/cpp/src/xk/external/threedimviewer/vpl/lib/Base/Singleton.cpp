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
 * Date:    2004/10/17                       
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

#include <VPL/Base/Singleton.h>


namespace vpl
{
namespace base
{

//==============================================================================
/*
 * Global variables.
 */

//! Vector of all created singleton instances.
tSingletonTracker *pSingletonTracker    = 0;


//==============================================================================
/*
 * Global functions.
 */

void destroyAllSingletons()
{
    // Already destroyed?
    if( !pSingletonTracker )
    {
        return;
    }

    // Delete all the singleton instances starting from those with the shortest longevity
    while( !pSingletonTracker->empty() )
    {
        // Pick the element at the top of the stack
        CSingletonLifetime* pTop = pSingletonTracker->back();

        // Remove that object off the stack before deleting pTop
        pSingletonTracker->pop_back();

        // Destroy the element
        delete pTop;
    }

    // Destroy stack when it's empty
    delete pSingletonTracker;
    pSingletonTracker = 0;
}


//! Ensures proper destruction of objects with longevity
void atExitFunction()
{
    // Destroy all the singletons
    destroyAllSingletons();

/*    VPL_ASSERT(pSingletonTracker && !pSingletonTracker->empty());

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
    }*/
}


} // namespace base
} // namespace vpl

