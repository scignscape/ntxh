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
 * Copyright (c) 2003-2005 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * File:    mdsLine.hxx                      
 * Section: libImage                         
 * Date:    2004/04/21                       
 * 
 * Description:
 * - Graphic primitive line definition.
 */


//==============================================================================
/*
 * Implementation of the vpl::CLine class.
 */
template <class I>
void CLine::draw(CImageBase<I>& Image)
{
    typedef typename I::tPixel tPixel;
    I& ImageImpl = Image.getImpl();

    // Convert the line color to image pixel
    tPixel Pixel = ImageImpl.color2Pixel(m_Color);

    // Round the line end-point positions
    int iX1 = vpl::math::round2Int(m_Points[0].x());
    int iY1 = vpl::math::round2Int(m_Points[0].y());
    int iX2 = vpl::math::round2Int(m_Points[1].x());
    int iY2 = vpl::math::round2Int(m_Points[1].y());

    // Difference in x and y axes
    int dx = vpl::math::getAbs(iX2 - iX1);
    int dy = vpl::math::getAbs(iY2 - iY1);

    // Exchange x and y axes
    bool bSwapXY = (dy > dx);
    if( bSwapXY )
    {
        vpl::math::swap2(iX1, iY1);
        vpl::math::swap2(iX2, iY2);
        vpl::math::swap2(dx, dy);
    }

    // Exchange line end-points
    if( iX1 > iX2 )
    {
        vpl::math::swap2(iX1, iX2);
        vpl::math::swap2(iY1, iY2);
    }

    // Step in y axis
    int iStepY;
    if( iY1 > iY2 )
    {
        iStepY = -1;
    }
    else
    {
        iStepY = 1;
    }

    // Bresenham's algorithm
    int k1 = 2 * dy;
    int k2 = 2 * (dy - dx);
    int p  = 2 * dy - dx;

    // Starting point
    int x = iX1;
    int y = iY1;

    // Draw the line
    if( !bSwapXY )
    {
        while( x <= iX2 )
        {
            if( ImageImpl.checkPosition(x, y) )
            {
                ImageImpl(x, y) =  Pixel;
            }
            ++x;
            if (p < 0)
            {
                p += k1;
            }
            else
            {
                p += k2;
                y += iStepY;
            }
        }
    }
    else
    {
        while( x <= iX2 )
        {
            if( ImageImpl.checkPosition(y, x) )
            {
                ImageImpl(y, x) = Pixel;
            }
            ++x;
            if (p < 0)
            {
                p += k1;
            }
            else
            {
                p += k2;
                y += iStepY;
            }
        }
    }
}


template <class V>
void CLine::draw(CVolumeBase<V>& Volume)
{
    typedef typename V::tVoxel tVoxel;
    V& VolumeImpl = Volume.getImpl();

    // Convert the line color to image pixel
    tVoxel Voxel = VolumeImpl.color2Voxel(m_Color);

    // Round the line end-point positions
    int iX1 = vpl::math::round2Int(m_Points[0].x());
    int iY1 = vpl::math::round2Int(m_Points[0].y());
    int iZ1 = vpl::math::round2Int(m_Points[0].z());
    int iX2 = vpl::math::round2Int(m_Points[1].x());
    int iY2 = vpl::math::round2Int(m_Points[1].y());
    int iZ2 = vpl::math::round2Int(m_Points[1].z());

    // Difference in x, y and z axes
    int dx = vpl::math::getAbs(iX2 - iX1);
    int dy = vpl::math::getAbs(iY2 - iY1);
    int dz = vpl::math::getAbs(iZ2 - iZ1);

    // Starting point
    int x, y, z;

    // Exchange x and y axes
    int *px, *py, *pz;
    if( dy >= dx && dy >= dz )
    {
        px = &y;
        py = &x;
        pz = &z;

        vpl::math::swap2(iX1, iY1);
        vpl::math::swap2(iX2, iY2);
        vpl::math::swap2(dx, dy);
    }
    else if ( dz >= dx && dz >= dy )
    {
        px = &z;
        py = &y;
        pz = &x;

        vpl::math::swap2(iX1, iZ1);
        vpl::math::swap2(iX2, iZ2);
        vpl::math::swap2(dx, dz);
    }
    else
    {
        px = &x;
        py = &y;
        pz = &z;
    }

    // Exchange line end-points
    if( iX1 > iX2 )
    {
        vpl::math::swap2(iX1, iX2);
        vpl::math::swap2(iY1, iY2);
    }

    // Step in y axis
    int iStepY;
    if( iY1 > iY2 )
    {
        iStepY = -1;
    }
    else
    {
        iStepY = 1;
    }

    // Step in z axis
    int iStepZ;
    if( iZ1 > iZ2 )
    {
        iStepZ = -1;
    }
    else
    {
        iStepZ = 1;
    }

    // Bresenham's algorithm
    int k1y = 2 * dy;
    int k2y = 2 * (dy - dx);
    int pry = 2 * dy - dx;

    int k1z = 2 * dz;
    int k2z = 2 * (dz - dx);
    int prz = 2 * dz - dx;

    // Starting point
    x = iX1;
    y = iY1;
    z = iZ1;

    // Draw the line
    while( x <= iX2 )
    {
        if( VolumeImpl.checkPosition(*px, *py, *pz) )
        {
            VolumeImpl(*px, *py, *pz) = Voxel;
        }
        ++x;
        if (pry < 0)
        {
            pry += k1y;
        }
        else
        {
            pry += k2y;
            y += iStepY;
        }
        if (prz < 0)
        {
            prz += k1z;
        }
        else
        {
            prz += k2z;
            z += iStepZ;
        }
    }
}

