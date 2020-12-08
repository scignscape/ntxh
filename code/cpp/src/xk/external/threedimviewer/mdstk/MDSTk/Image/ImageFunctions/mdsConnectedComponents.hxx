//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)            \n
 * Copyright (c) 2003-2008 by Michal Spanel             \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz          \n
 * Date:    2008/07/24                                  \n
 *
 * $Id: mdsConnectedComponents.hxx 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Connected Component Labeling algorithm.
 */


//==============================================================================
/*
 * Functions templates.
 */

template <class I1, class I2, class F>
inline bool findConnectedComponents(const CImageBase<I1>& SrcImage,
                                    CImageBase<I2>& LabelImage,
                                    F CompareFunc
                                    )
{
    typedef typename I1::tPixel tPixel1;
    typedef typename I2::tPixel tPixel2;
    const I1& SrcImpl = SrcImage.getImpl();
    I2& DstImpl = LabelImage.getImpl();

    tSize XCount = mds::math::getMin(SrcImpl.getXSize(), DstImpl.getXSize());
    tSize YCount = mds::math::getMin(SrcImpl.getYSize(), DstImpl.getYSize());
    
    // Create labeling and create a dummy label
    CBlobLabeling<int> Labeling;
    tPixel2 DummyLabel = tPixel2(Labeling.newLabel());

    // Initialize the top-left pixel
    DstImpl(0,0) = tPixel2(Labeling.newLabel());

    // Label the first row
    for( tSize i = 1; i < XCount; ++i )
    {
        if( CompareFunc(SrcImpl(i,0), SrcImpl(i-1,0)) )
        {
            DstImpl(i,0) = DstImpl(i-1,0);
        }
        else
        {
            DstImpl(i,0) = tPixel2(Labeling.newLabel());
        }
    }

    // Label all subsequent rows
    for( tSize j = 1; j < YCount; ++j )
    {
        // Label the first pixel on this row
        if( CompareFunc(SrcImpl(0,j), SrcImpl(0,j-1)) )
        {
            DstImpl(0,j) = DstImpl(0,j-1);
        }
        else
        {
            DstImpl(0,j) = tPixel2(Labeling.newLabel());
        }

        // Label remaining pixels on this row
        for( tSize i = 1; i < XCount; ++i )
        {
            // Pixel on the left
            tPixel2 Label = DummyLabel;
            if( CompareFunc(SrcImpl(i,j), SrcImpl(i-1,j)) )
            {
                Label = DstImpl(i-1,j);
            }
            
            // Check remaining neighbours (4-connectivity)
            // - If we are in the same blob, inherit value from the pixel
            // - Merge both blobs if the label has been already assigned
            if( CompareFunc(SrcImpl(i,j), SrcImpl(i-1,j-1)) )
            {
                if( Label != DummyLabel )
                {
                    Labeling.merge(int(Label), int(DstImpl(i-1,j-1)));
                }
                else
                {
                    Label = DstImpl(i-1,j-1);
                }
            }
            if( CompareFunc(SrcImpl(i,j), SrcImpl(i,j-1)) )
            {
                if( Label != DummyLabel )
                {
                    Labeling.merge(int(Label), int(DstImpl(i,j-1)));
                }
                else
                {
                    Label = DstImpl(i,j-1);
                }
            }
            if( CompareFunc(SrcImpl(i,j), SrcImpl(i+1,j-1)) )
            {
                if( Label != DummyLabel )
                {
                    Labeling.merge(int(Label), int(DstImpl(i+1,j-1)));
                }
                else
                {
                    Label = DstImpl(i+1,j-1);
                }
            }
            
            // Already existing blob or a new one?
            if( Label != DummyLabel )
            {
                DstImpl(i,j) = Label;
            }
            else
            {
                DstImpl(i,j) = tPixel2(Labeling.newLabel());
            }
        }
    }
    
    // Relabel the image
    Labeling.relabel(0);
    for( tSize j = 0; j < YCount; ++j )
    {
        for( tSize i = 0; i < XCount; ++i )
        {
            DstImpl(i,j) = Labeling.getLabel(int(DstImpl(i,j)));
        }
    }
    
    // O.K.
    return true;
}

