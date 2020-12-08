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
 * Date:    2005/09/06                       
 * 
 * Description:
 * - Identifier definition and creation.
 */

#include <VPL/Base/Identifier.h>


namespace vpl
{

//=============================================================================
/*
 * Global definitions.
 */

//! Hash function parameters
const unsigned int SHIFT    = 6U;
const unsigned int MASK     = ~0U << (16U - SHIFT);


//=============================================================================
/*
 * Functions implementation.
 */
unsigned int convertId(const std::string& ssName)
{
    // String conversion
    unsigned int uiHash = 0;
    for( std::string::size_type i = 0; i < ssName.length(); ++i )
    {
        uiHash = (uiHash & MASK) ^ (uiHash << SHIFT) ^ ssName[i];
    }

    // Return the hash
    return unsigned(uiHash & 0xffff);
}


} // namespace vpl

