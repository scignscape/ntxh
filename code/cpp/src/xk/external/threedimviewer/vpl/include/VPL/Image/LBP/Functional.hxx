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


//=============================================================================
/*
 * Implementation...
 */

template <class I, ECodeType Type, template <ECodeType> class Mapping, class Function>
inline Function forEach(vpl::img::CImageBase<I>& Image, Function Func)
{
    I& ImageImpl = Image.getImpl();

    // LBP code extractor
    typedef vpl::lbp::CCodeExtractor<I,Type> tExtractor;
    typedef typename tExtractor::tCode tCode;

    // Prepare the extractor
    tExtractor Extractor;
    Extractor.setImage(&ImageImpl);

    // Code mapping
    Mapping<Type> Conv;

    // Process the image
    for( vpl::tSize j = 0; j < ImageImpl.getYSize(); ++j )
    {
        for( vpl::tSize i = 0; i < ImageImpl.getXSize(); ++i )
        {
            tCode Value = Conv.map(Extractor.extract(i, j));
            Func(i, j, Value);
        }
    }

    return Func;
}

