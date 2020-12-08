//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/09/06                          \n
 *
 * $Id: mdsIdentifier.cpp 1863 2010-08-31 20:40:15Z spanel $
 * 
 * Description:
 * - Identifier definition and creation.
 */

#include <MDSTk/Base/mdsIdentifier.h>


namespace mds
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


} // namespace mds

