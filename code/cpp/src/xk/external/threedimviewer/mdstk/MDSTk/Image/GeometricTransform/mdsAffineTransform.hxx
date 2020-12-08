//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2009 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2008/12/16                          \n
 *
 * $Id: mdsAffineTransform.hxx 2084 2012-02-13 10:23:58Z spanel $
 *
 * Description:
 * - Geometrical image transformations.
 */


//==============================================================================
/*
 * Implementation of the class CAffineTransform<I>.
 */

template <class I, template <typename> class Interpolator>
bool CAffineTransform<I,Interpolator>::operator()(const tImage& SrcImage, tImage& DstImage)
{
    // Displacement of the target image
    tCoordinate ShiftX = 0, ShiftY = 0;

    // Target image size
    tSize SizeX = DstImage.getXSize();
    tSize SizeY = DstImage.getYSize();

    // Resize the destination image
    if( this->checkOption(ImageTransform::RESIZE) )
    {
        // Minimal and maximal coordinates
        tCoordinate MinX = 0, MinY = 0;
        tCoordinate MaxX = 0, MaxY = 0;

        // Transform four corners of the source image
        tCoordinate SrcMaxX = tCoordinate(SrcImage.getXSize());
        tCoordinate SrcMaxY = tCoordinate(SrcImage.getYSize());
        tCoordinate CornerX[4] = { 0, 0, SrcMaxX, SrcMaxX };
        tCoordinate CornerY[4] = { 0, SrcMaxY, 0, SrcMaxY };
        for( int i = 0; i < 4; ++i )
        {
            mds::img::CPoint3D Corner(CornerX[i], CornerY[i], 1);
            warp2(Corner);
            MinX = mds::math::getMin(MinX, Corner.x());
            MinY = mds::math::getMin(MinY, Corner.y());
            MaxX = mds::math::getMax(MaxX, Corner.x());
            MaxY = mds::math::getMax(MaxY, Corner.y());
        }

        // Calculate new size of the image
        SizeX = mds::math::round2Int(MaxX - MinX) + 1;
        SizeY = mds::math::round2Int(MaxY - MinY) + 1;

        // Resize the image
        DstImage.create(SizeX, SizeY, DstImage.getMargin());
        ShiftX = MinX;
        ShiftY = MinY;

        // Fill the image
        DstImage.fillEntire(this->m_MarginValue);
    }

    // Clear the image
    else if( this->checkOption(ImageTransform::FILL_MARGIN) )
    {
        DstImage.fillEntire(this->m_MarginValue);
    }

    // Image warping
#pragma omp parallel for schedule(static) default(shared)
    for( tSize y = 0; y < SizeY; ++y )
    {
        mds::img::CPoint3D Point(ShiftX, ShiftY + y, 1);
        for( tSize x = 0; x < SizeX; ++x, Point.x() += 1 )
        {
            mds::img::CPoint3D p = warpBack(Point);
            if( SrcImage.checkPosition(tSize(p.x()), tSize(p.y())) )
            {
                DstImage(x,y) = interpolate(SrcImage, p.x(), p.y());
            }
        }
    }

    // O.K.
    return true;
}

