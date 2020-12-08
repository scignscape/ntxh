//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2005 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/10/26                          \n
 *
 * $Id: mdsSystem.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Definition of various system constants and macros.
 */

#ifndef MDS_SYSTEM_H
#define MDS_SYSTEM_H


//=============================================================================
/*
 * Global definitions.
 * - Windows version.
 */

#ifdef _WIN32

//! Slash used in path.
#define SLASHC                  '\\'
#define SLASHSTR                "\\"

//! Infinite waiting.
#define MDS_WAIT_INFINITE       INFINITE

#endif // _WIN32


//=============================================================================
/*
 * Global definitions.
 * - Linux version
 */

#ifdef _LINUX

//! Slash used in path.
#define SLASHC                  '/'
#define SLASHSTR                "/"

//! Infinite waiting.
#define MDS_WAIT_INFINITE       0xFFFFFF

#endif // _LINUX


#endif // MDS_SYSTEM_H

