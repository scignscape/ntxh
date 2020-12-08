//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)          \n
 * Copyright (c) 2003-2009 by Michal Spanel           \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz        \n
 * Date:    2009/03/07                                \n
 *
 * $Id: mdsFunctional.hxx 2100 2012-02-17 07:36:55Z spanel $
 *
 * Description:
 * - Miscellaneous LBP functions.
 */


//=============================================================================
/*
 * Implementation...
 */

template <class I, ECodeType Type, template <ECodeType> class Mapping, class Function>
inline Function forEach(mds::img::CImageBase<I>& Image, Function Func)
{
    I& ImageImpl = Image.getImpl();

    // LBP code extractor
    typedef mds::lbp::CCodeExtractor<I,Type> tExtractor;
    typedef typename tExtractor::tCode tCode;

    // Prepare the extractor
    tExtractor Extractor;
    Extractor.setImage(&ImageImpl);

    // Code mapping
    Mapping<Type> Conv;

    // Process the image
    for( mds::tSize j = 0; j < ImageImpl.getYSize(); ++j )
    {
        for( mds::tSize i = 0; i < ImageImpl.getXSize(); ++i )
        {
            tCode Value = Conv.map(Extractor.extract(i, j));
            Func(i, j, Value);
        }
    }

    return Func;
}

