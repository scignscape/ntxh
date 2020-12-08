//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2007 by PGMed@FIT         \n
 *
 * Author:  Miroslav Svub, svub@fit.vutbr.cz    \n
 * Date:    2007/04/01                          \n
 *
 * $Id: mdsUMFpack.h 1707 2010-05-05 11:00:46Z spanel $
 *
 * Description:
 * - UMFPACK functions.
 */

#ifndef MDS_UMFPACK_H
#define MDS_UMFPACK_H

#include <MDSTk/Base/mdsSetup.h>

#ifdef MDS_UMFPACK_ENABLED

// Include UMFPACK
//extern "C"
//{
#include <umfpack.h> 
//}

#endif // MDS_UMFPACK_ENABLED
#endif // MDS_UMFPACK_H

