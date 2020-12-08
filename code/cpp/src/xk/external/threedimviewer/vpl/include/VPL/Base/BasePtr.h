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
 * Date:    2004/10/17                          \n
 *
 * Description:
 * - Just for backward compatibility...
 */

#ifndef VPL_BasePtr_H
#define VPL_BasePtr_H

#include "ScopedPtr.h"


//==============================================================================
/*
 * Global macros.
 */

//! Macro declares a class member tSmartPtr which can be later used to create
//! smart pointer to class T.
#define VPL_SCOPEDPTR(T) \
    typedef vpl::base::CScopedPtr<T> tSmartPtr; \
    friend class vpl::base::CScopedPtr<T>


#endif // VPL_BasePtr_H
