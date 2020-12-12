//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2010 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2010/08/29                          \n
 *
 * $Id: mdsMathExport.h 1928 2010-11-07 13:11:14Z spanel $
 *
 * Description:
 * - Dynamic library export settings.
 */

#ifndef MDS_MathExport_H
#define MDS_MathExport_H


//=============================================================================
/*
 * Setup export settings.
 * - MDS_LIBRARY_STATIC ~ using static library
 * - MDS_LIBRARY_SHARED + MDS_MAKING_MATH_LIBRARY ~ making dynamic library
 * - MDS_LIBRARY_SHARED ~ using dynamic library
 */

#ifdef _WIN32
#   if defined( MDS_LIBRARY_SHARED )
#       ifdef MDS_MAKING_MATH_LIBRARY
#           define MDS_MATH_EXPORT __declspec(dllexport)
#       else
#           define MDS_MATH_EXPORT __declspec(dllimport)
#       endif
#   else
#       define MDS_MATH_EXPORT
#   endif
#else
#   define MDS_MATH_EXPORT
#endif


#endif // MDS_MathExport_H
