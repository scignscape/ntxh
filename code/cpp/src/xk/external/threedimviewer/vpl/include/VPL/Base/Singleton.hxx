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
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * File:    mdsSingleton.hxx                    \n
 * Section: libBase                             \n
 * Date:    2004/10/17                          \n
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

//==============================================================================
/*
 * Global variables and declarations.
 */

//! Vector of all created singleton instances
typedef std::list<CSingletonLifetime *> tSingletonTracker;

//! Extern vector of all created singleton instances
extern tSingletonTracker *pSingletonTracker;

// Declaration needed below
void atExitFunction();


//=============================================================================
/*
 * Data templates.
 */
template <typename T>
typename CSingletonHolder<T>::tPointer CSingletonHolder<T>::m_pInstance = 0;

template <typename T>
bool CSingletonHolder<T>::m_bDestroyed = false;


//=============================================================================
/*
 * Methods templates.
 */
template <typename T>
inline T& CSingletonHolder<T>::getInstance()
{
    if( !m_pInstance )
    {
        tLock Lock;
        (void)Lock;

        if( !m_pInstance )
        {
            createInstance();
        }
    }

    return *m_pInstance;
}


template <typename T>
void CSingletonHolder<T>::createInstance()
{
    VPL_ASSERT(!m_bDestroyed);

    // Manage lifetime of singletons
    if( !pSingletonTracker )
    {
        // List of singletons ordered according to their lifetime
        pSingletonTracker = new tSingletonTracker;

        // Register a single call to atexit() function that will delete all the singletons
        std::atexit(atExitFunction);
    }

    // Create the object instance
    m_pInstance = new tPointee;

    // Create singleton destroyer
    CSingletonDestroyer<T> *pDestroyer = new CSingletonDestroyer<T>(m_pInstance,
                                                                    LONGEVITY,
                                                                    &destroyInstance
                                                                    );

    // Find correct position
    tSingletonTracker::iterator pos = std::upper_bound(pSingletonTracker->begin(),
                                                       pSingletonTracker->end(),
                                                       pDestroyer,
                                                       CSingletonLifetime::compare
                                                       );

    // Insert the pointer to the singleton destroyer into the queue
    pSingletonTracker->insert(pos, pDestroyer);

    // Register a call to atexit() function - one call for every singleton
//    std::atexit(atExitFunction);
}


template <typename T>
void CSingletonHolder<T>::destroyInstance()
{
    VPL_ASSERT(!m_bDestroyed);

    delete m_pInstance;
    m_pInstance = 0;
    m_bDestroyed = true;
}

