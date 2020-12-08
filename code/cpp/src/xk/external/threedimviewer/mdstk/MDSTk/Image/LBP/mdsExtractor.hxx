//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)          \n
 * Copyright (c) 2003-2009 by Michal Spanel           \n
 *
 * Author:  Jiri Hutarek, xhutar01@stud.fit.vutbr.cz  \n
 *          Michal Spanel, spanel@fit.vutbr.cz        \n
 * Date:    2009/03/03                                \n
 *
 * $Id: mdsExtractor.hxx 1863 2010-08-31 20:40:15Z spanel $
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

