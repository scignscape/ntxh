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
 * Copyright (c) 2003-2009 by Michal Spanel        
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz     
 * Date:    2009/03/07                             
 *
 * Description:
 * - Miscellaneous LBP functions.
 */

#ifndef VPL_LBP_Functional_H
#define VPL_LBP_Functional_H

#include "Mapping.h"
#include "Operators.h"

#include <VPL/Image/Image.h>


namespace vpl
{
namespace lbp
{

//=============================================================================
/*!
 * Function calls a given functor for every extracted LBP code.
 * - Prepare a functor having the method void operator() (tSize x, tSize y, tCode Value).
 * - Template parameter I is an image type.
 * - Type specifies a concrete LBP.
 * - Policy Mapping is used to normalize LBP codes.
 */
template <class I, ECodeType Type, template <ECodeType> class Mapping, class Function>
inline Function forEach(vpl::img::CImageBase<I>& Image, Function Func);


//=============================================================================
/*
 * Implementation...
 */
#include "Functional.hxx"


} // namespace lbp
} // namespace vpl

#endif // VPL_LBP_Functional_H
