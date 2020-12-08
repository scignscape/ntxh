//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)          \n
 * Copyright (c) 2003-2009 by Michal Spanel           \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz        \n
 * Date:    2009/03/07                                \n
 *
 * $Id: mdsFunctional.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Miscellaneous LBP functions.
 */

#ifndef MDS_LBP_Functional_H
#define MDS_LBP_Functional_H

#include "mdsMapping.h"
#include "mdsOperators.h"

#include <MDSTk/Image/mdsImage.h>


namespace mds
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
inline Function forEach(mds::img::CImageBase<I>& Image, Function Func);


//=============================================================================
/*
 * Implementation...
 */
#include "mdsFunctional.hxx"


} // namespace lbp
} // namespace mds

#endif // MDS_LBP_Functional_H
