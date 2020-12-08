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

#ifndef VPL_LBP_Extractor_H
#define VPL_LBP_Extractor_H

#include <VPL/Image/FeatureExtraction/FeatureExtractor.h>
#include <VPL/Base/Logging.h>

#include "Mapping.h"
#include "Operators.h"
#include "Histogram.h"


namespace vpl
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
    : public vpl::img::CFeatureExtractor<CNormLBPHistogram<Mapping<Type>::Size> >
    , public Mapping<Type>
{
public:
    //! Base types.
    typedef vpl::img::CFeatureExtractor<CNormLBPHistogram<Mapping<Type>::Size> > tBase;
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
#include "Extractor.hxx"


} // namespace lbp
} // namespace vpl

#endif // VPL_LBP_Extractor_H
