//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)          \n
 * Copyright (c) 2003-2009 by Michal Spanel           \n
 *
 * Authors: Jiri Hutarek, xhutar01@stud.fit.vutbr.cz  \n
 *          Michal Spanel, spanel@fit.vutbr.cz        \n
 * Date:    2008/03/09                                \n
 *
 * $Id: mdsOperators.h 2100 2012-02-17 07:36:55Z spanel $
 *
 * Description:
 * - Basic LBP extractor/operator.
 */

#ifndef MDS_LBP_Operators_H
#define MDS_LBP_Operators_H

#include "mdsCircularSampler.h"
#include "mdsTraits.h"

#include <MDSTk/Base/mdsGlobalLog.h>


namespace mds
{
namespace lbp
{

//=============================================================================
/*!
 * Compares one LBP sample with a center value.
 */
template <typename R, int Shift>
struct CIsGreater
{
    //! Compares one LBP sample with a given center.
    //! - Returns (1 << Shift) if sample value is greater then the center.
    template <typename T>
    inline static R compare(const T& Center, const T& Value)
    {
        static const R One = R(1) << Shift;
        static const R Zero = R(0);

        return (Value > Center) ? One : Zero;
    }

    //! Specialization of the method.
    inline static R compare(const mds::img::tPixel8& Center, const mds::img::tPixel8& Value)
    {
        return R(((Center - Value) & 0x80) >> (7 - Shift));
    }

    //! Specialization of the method.
    inline static R compare(const mds::img::tDensityPixel& Center, const mds::img::tDensityPixel& Value)
    {
        return R(((Center - Value) & 0x8000) >> (15 - Shift));
    }
};


//=============================================================================
/*!
 * Functor creates LBP code from samples.
 * - Parameter T is an image pixel type.
 * - Parameter Type specifies concrete LBP type.
 */
template <typename T, ECodeType Type>
class CCodeAccumulator
{
public:
    //! Type representing LBP code.
    typedef typename CLBPTraits<Type>::tCode tCode;

public:
    //! Default constructor.
    CCodeAccumulator(const T& Center) : m_Code(0), m_Center(Center) {}

    //! Copy constructor.
    CCodeAccumulator(const CCodeAccumulator& Acc)
        : m_Code(Acc.m_Code)
        , m_Center(Acc.m_Center)
    {}

    //! Accumulates one sample.
    void operator ()(const T& Value)
    {
        m_Code <<= 1;
        m_Code |= CIsGreater<tCode,0>::compare(m_Center, Value);
    }

    //! Returns the final LBP code.
    tCode getValue() const
    {
        return m_Code;
    }

    //! Sets the center value and clears the code.
    CCodeAccumulator& setCenter(const T& Center)
    {
        m_Center = Center;
        m_Code = 0;
        return *this;
    }

protected:
    //! Extracted LBP code.
    tCode m_Code;

    //! Value of the LBP center.
    T m_Center;
};


//=============================================================================
/*!
 * Base class for all classes that extract LBP code from a concrete
 * image position.
 * - Parameter I is an image type.
 * - LBP feature type must be specified as template parameter.
 */
template <class I, ECodeType Type>
struct CCodeExtractorBase
{
    //! Check that I is an image. You will see name of this enum somewhere
    //! in compiler error message if the type I is not image.
    enum { TEMPLATE_PARAMETER_IS_NOT_IMAGE = I::CLASS_IMAGE };

    //! Image type.
    typedef typename I::tImage tImage;

    //! Image pixel type.
    typedef typename I::tPixel tPixel;

    //! Type representing LBP code.
    typedef typename CLBPTraits<Type>::tCode tCode;
};


//=============================================================================
/*!
 * Class extracts LBP code from a concrete image position.
 * - Parameter I is an image type.
 * - LBP feature type must be specified as template parameter.
 */
template <class I, ECodeType Type>
class CCodeExtractor : public CCodeExtractorBase<I,Type>
{
public:
    // Base types.
    typedef CCodeExtractorBase<I,Type> tBase;
    typedef typename tBase::tImage tImage;
    typedef typename tBase::tPixel tPixel;
    typedef typename tBase::tCode tCode;

public:
    //! Default constructor.
    CCodeExtractor() : m_Sampler(CLBPTraits<Type>::getNumOfSamples(), CLBPTraits<Type>::getRadius()) {}

    //! Sets the input image.
    CCodeExtractor& setImage(tImage *pImage)
    {
        m_Sampler.setImage(pImage);
        return *this;
    }

    //! Returns pointer to the input image.
    tImage *getImage()
    {
        return m_Sampler.getImage();
    }

    //! Extracts LBP code at a specified position.
    //! - Image must be set!
    tCode extract(tSize x, tSize y)
    {
        return m_Sampler.forEach(x, y, CCodeAccumulator<tPixel,Type>(m_Sampler.getCenter(x, y))).getValue();
    }

public:
    //! Circular sampler.
    CCircularSampler<tImage> m_Sampler;
};


//=============================================================================
/*!
 * Class extracts LBP code from a concrete image position.
 * - Parameter I is an image type.
 * - Partial specialization for 8-bit LBP feature.
 */
template <class I>
class CCodeExtractor<I,LBP8> : public CCodeExtractorBase<I,LBP8>
{
public:
    // Base types.
    typedef CCodeExtractorBase<I,LBP8> tBase;
    typedef typename tBase::tImage tImage;
    typedef typename tBase::tPixel tPixel;
    typedef typename tBase::tCode tCode;

public:
    //! Default constructor.
    CCodeExtractor() : m_spImage(NULL) {}

    //! Sets input image.
    CCodeExtractor& setImage(tImage *pImage)
    {
        MDS_ASSERT(pImage && pImage->getMargin() > 0);

        m_spImage = pImage;
        return *this;
    }

    //! Returns the input image.
    tImage *getImage() const
    {
        return m_spImage.get();
    }

    //! Extracts LBP code at a specified position.
    //! - Image must be set!
    tCode extract(tSize x, tSize y)
    {
        MDS_ASSERT(m_spImage.get() && m_spImage->checkPosition(x, y));

        tCode Value = 0;
        tPixel Center = m_spImage->at(x, y);

        Value |= CIsGreater<tCode,7>::compare(Center, m_spImage->at(x, y - 1));
        Value |= CIsGreater<tCode,6>::compare(Center, m_spImage->at(x - 1, y - 1));
        Value |= CIsGreater<tCode,5>::compare(Center, m_spImage->at(x - 1, y));
        Value |= CIsGreater<tCode,4>::compare(Center, m_spImage->at(x - 1, y + 1));
        Value |= CIsGreater<tCode,3>::compare(Center, m_spImage->at(x, y + 1));
        Value |= CIsGreater<tCode,2>::compare(Center, m_spImage->at(x + 1, y + 1));
        Value |= CIsGreater<tCode,1>::compare(Center, m_spImage->at(x + 1, y));
        Value |= CIsGreater<tCode,0>::compare(Center, m_spImage->at(x + 1, y - 1));

        return Value;
    }

public:
    //! Input image.
    typename tImage::tSmartPtr m_spImage;
};


} // namespace lbp
} // namespace mds

#endif // MDS_LBP_Operators_H
