//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2005/09/06                          \n
 *
 * $Id: mdsIdentifier.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Template identifier definition and creation.
 */

#ifndef MDS_IDENTIFIER_H
#define MDS_IDENTIFIER_H

#include "mdsSetup.h"
#include "mdsNamedObject.h"

// STL
#include <string>


namespace mds
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
#define MDS_DECLARE_ID(Id)      struct Id { MDS_STATIC_NAME(#Id); }


} // namespace mds

#endif // MDS_IDENTIFIER_H

