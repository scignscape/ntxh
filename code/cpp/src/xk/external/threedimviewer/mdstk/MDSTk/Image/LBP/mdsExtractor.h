//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)          \n
 * Copyright (c) 2003-2009 by Michal Spanel           \n
 *
 * Author:  Jiri Hutarek, xhutar01@stud.fit.vutbr.cz  \n
 *          Michal Spanel, spanel@fit.vutbr.cz        \n
 * Date:    2009/03/03                                \n
 *
 * $Id: mdsExtractor.h 1893 2010-10-18 20:28:08Z spanel $
 *
 * Description:
 * - LBP extractor class.
 */

#ifndef MDS_LBP_Extractor_H
#define MDS_LBP_Extractor_H

#include <MDSTk/Image/FeatureExtraction/mdsFeatureExtractor.h>
#include <MDSTk/Base/mdsGlobalLog.h>

#include "mdsMapping.h"
#include "mdsOperators.h"
#include "mdsHistogram.h"


namespace mds
{
namespace lbp
{

//=============================================================================
/*!
 * LBP extractor class that extracts LBP codes from an image region
 * and makes histogram of them.
 * - Template parameter I is an image type.
 * - Type specifies a concrete LBP.
 * - Policy Mapping is used to normalize LBP codes.
 */
template <class I, ECodeType Type, template <ECodeType> class Mapping = CUniformRotMin>
class CLBPExtractor
    : public mds::img::CFeatureExtractor<CNormLBPHistogram<Mapping<Type>::Size> >
    , public Mapping<Type>
{
public:
    //! Base types.
    typedef mds::img::CFeatureExtractor<CNormLBPHistogram<Mapping<Type>::Size> > tBase;
    typedef typename tBase::tVector tVector;
    typedef typename tBase::tFeature tFeature;

    //! Mapping type.
    typedef Mapping<Type> tMapping;

    //! LBP code extractor.
    typedef CCodeExtractor<I,Type> tCodeExtractor;

    //! Image type.
    typedef typename tCodeExtractor::tImage tImage;

    //! Histogram of extracted LBP codes.
    typedef CLBPHistogram<Mapping<Type>::Size> tHistogram;

public:
    //! Default constructor.
    CLBPExtractor()
    {
        m_Hist.fill(0);
    }

    //! Copy constructor.
    CLBPExtractor(const CLBPExtractor& Extractor);

    //! Destructor.
    ~CLBPExtractor() {}

    //! Assignement operator.
    inline CLBPExtractor& operator =(const CLBPExtractor& Extractor);

    //! Sets the input image.
    CLBPExtractor& setImage(tImage *pImage)
    {
        m_CodeExt.setImage(pImage);
        return *this;
    }

    //! Returns reference to the current histogram of LBP codes.
    tHistogram& getHistogram() { return m_Hist; }
    const tHistogram& getHistogram() const { return m_Hist; }


    //! Extracts and acumulates LBP code at a given pixel position.
    inline void accumulate(tSize x, tSize y);

    //! Acumulates LBP codes from a given feature extractor.
    inline void accumulate(const CLBPExtractor& Extractor);

    //! Extracts and acumulates LBP codes from a given image.
    //! - This method calls the setImage() internally.
    inline void accumulate(tImage *pImage);

    //! Evaluates feature vector (normalized LBP histogram)
    //! according to the acumulated LBP codes.
    // - Throws CCannotEvaluate exception on failure.
    // - Changes internal state of the feature vector.
    void evaluate(tVector& Vector);

    //! Clears all internal statistics.
    inline void clear();

protected:
    //! Histogram of previously extracted LBP codes.
    tHistogram m_Hist;

    //! LBP extractor.
    tCodeExtractor m_CodeExt;
};


//=============================================================================
/*
 * Implementation...
 */
#include "mdsExtractor.hxx"


} // namespace lbp
} // namespace mds

#endif // MDS_LBP_Extractor_H
