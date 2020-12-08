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
 * Date:    2005/09/06                          \n
 *
 * Description:
 * - Template identifier definition and creation.
 */

#ifndef VPL_IDENTIFIER_H
#define VPL_IDENTIFIER_H

#include "Setup.h"
#include "NamedObject.h"

// STL
#include <string>


namespace vpl
{

//==============================================================================
/*
 * Global definitions.
 */

//! Identifier type used to declare templates whose instances
//! are specialized by using identifiers.
#define tIdentifier             typename


//==============================================================================
/*
 * Several usefull macros.
 */

//! Declares an identifier.
//! - Parameter 'Id' is a name of the identifier.
#define VPL_DECLARE_ID(Id)      struct Id { VPL_STATIC_NAME(#Id); }


} // namespace vpl

#endif // VPL_IDENTIFIER_H

