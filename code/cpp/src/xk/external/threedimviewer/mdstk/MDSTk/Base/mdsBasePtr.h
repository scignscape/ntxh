//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/10/17                          \n
 *
 * $Id: mdsBasePtr.h 1707 2010-05-05 11:00:46Z spanel $
 *
 * Description:
 * - Just for backward compatibility...
 */

#ifndef MDS_BasePtr_H
#define MDS_BasePtr_H

#include "mdsScopedPtr.h"


//==============================================================================
/*
 * Global macros.
 */

//! Macro declares a class member tSmartPtr which can be later used to create
//! smart pointer to class T.
#define MDS_SCOPEDPTR(T) \
    typedef mds::base::CScopedPtr<T> tSmartPtr; \
    friend class mds::base::CScopedPtr<T>


#endif // MDS_BasePtr_H
