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
 * Author:  Jiri Hutarek, xhutar01@stud.fit.vutbr.cz  \n
 *          Michal Spanel, spanel@fit.vutbr.cz     
 * Date:    2009/03/03                             
 *
 * Description:
 * - LBP extractor class.
 */


//=============================================================================
/*
 * Implementation of the CLBExtractor<> class.
 */

template <class I, ECodeType Type, template <ECodeType> class Mapping>
CLBPExtractor<I,Type,Mapping>::CLBPExtractor(const CLBPExtractor& Extractor)
    : m_Hist(Extractor.m_Hist)
{
    m_CodeExt.setImage(Extractor.m_CodeExt.getImage());
}


template <class I, ECodeType Type, template <ECodeType> class Mapping>
inline CLBPExtractor<I,Type,Mapping>& CLBPExtractor<I,Type,Mapping>::operator =(const CLBPExtractor& Extractor)
{
    m_Hist = Extractor.m_Hist;
    setImage(Extractor.getImage());
    return *this;
}


template <class I, ECodeType Type, template <ECodeType> class Mapping>
inline void CLBPExtractor<I,Type,Mapping>::accumulate(tSize x, tSize y)
{
    ++m_Hist(tMapping::map(m_CodeExt.extract(x, y)));
    m_Hist.addPoints(1);
}


template <class I, ECodeType Type, template <ECodeType> class Mapping>
inline void CLBPExtractor<I,Type,Mapping>::accumulate(tImage *pImage)
{
    if( !pImage )
    {
        return;
    }

    this->setImage(pImage);

    for( tSize j = 0; j < pImage->getYSize(); ++j )
    {
        for( tSize i = 0; i < pImage->getXSize(); ++i )
        {
            this->accumulate(i, j);
        }
    }
}


template <class I, ECodeType Type, template <ECodeType> class Mapping>
inline void CLBPExtractor<I,Type,Mapping>::accumulate(const CLBPExtractor& Extractor)
{
    m_Hist += Extractor.m_Hist;
    m_Hist.addPoints(Extractor.m_Hist.getNumOfPoints());
}


template <class I, ECodeType Type, template <ECodeType> class Mapping>
void CLBPExtractor<I,Type,Mapping>::evaluate(tVector& Vector)
{
    m_Hist.normalize(Vector);
}


template <class I, ECodeType Type, template <ECodeType> class Mapping>
inline void CLBPExtractor<I,Type,Mapping>::clear()
{
    m_Hist.fill(0);
    m_Hist.setNumOfPoints(0);
}

