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
 * Date:    2004/05/03                       
 *
 * Description:
 * - Lucas-Kanade optical flow estimation method.
 */

//=============================================================================
/*
 * Global definitions.
 */

namespace optflow
{
//! Default number of iterations during optical flow computation
const int ITERATIONS    = 3;

//! Constants used by optical flow estimation method.
//! - Defined by Simoncelli et al.
const double SIGMA1     = 0.08;
const double SIGMA2     = 1.0;
const double SIGMAP     = 2.0;
//const double EIG_TSH    = 10.0;
//const double EIG_TSH    = 4.0;
//const double EIG_TSH    = 2.0;
const double EIG_TSH    = 0.0001;
}


//=============================================================================
/*
 * Implementation of the vpl::image::COpticalFlow class template.
 */

//template <class I>
//const tSize COpticalFlow<I>::DEFAULT_WINDOW = 11;
template <class I>
const tSize COpticalFlow<I>::DEFAULT_WINDOW = 13;
//template <class I>
//const tSize COpticalFlow<I>::DEFAULT_WINDOW = 25;


template <class I>
COpticalFlow<I>::COpticalFlow(tSize WindowSize)
    : m_Point(0.0f, 0.0f)
    , m_Motion(0.0f, 0.0f)
    , m_WindowSize(WindowSize)
{
    VPL_ASSERT(m_WindowSize > 0 && (m_WindowSize % 2) == 1);

    // Allocate auxiliary matrixes
    m_Ix.resize(m_WindowSize, m_WindowSize);
    m_Iy.resize(m_WindowSize, m_WindowSize);
    m_It.resize(m_WindowSize, m_WindowSize);
}


template <class I>
COpticalFlow<I>::COpticalFlow(tCoordinate x,
                              tCoordinate y,
                              tSize WindowSize
                              )
    : m_Point(x, y)
    , m_Motion(0.0f, 0.0f)
    , m_WindowSize(WindowSize)
{
    VPL_ASSERT(m_WindowSize > 0 && (m_WindowSize % 2) == 1);

    // Allocate auxiliary matrixes
    m_Ix.resize(m_WindowSize, m_WindowSize);
    m_Iy.resize(m_WindowSize, m_WindowSize);
    m_It.resize(m_WindowSize, m_WindowSize);
}


// Compute velocity field using Lucas-Kanade method
template <class I>
bool COpticalFlow<I>::compute(const tPyramid& First, const tPyramid& Second)
{
    // Check pyramid levels
    VPL_CHECK(First.getLevels() == Second.getLevels(), return false);

    // Size and radius of the window
    tSize Size = m_WindowSize;
    tSize Radius = m_WindowSize / 2;

    // Normalization
    double dNorm = 1.0 / (Size * Size);

    // Matrix A and inverse matrix Ai
    vpl::math::CDMatrix2x2 A, Ai;

    // Vector B and vector of eigen values of the matrix A
    vpl::math::CDVector2 B, Eigens;

    // Clear the optical flow
    m_Motion.x() = 0.0f;
    m_Motion.y() = 0.0f;

    // Calculation of the flow using image pyramid
    for( tSize Level = First.getLevels() - 1; Level >= 0; --Level )
    {
        // Point position regarding the current pyramid level
        double dCoefficient = 1.0 / pow(double(First.getSubSampling()), Level);
        CPoint3D PointFirst(tCoordinate(m_Point.x() * dCoefficient),
                            tCoordinate(m_Point.y() * dCoefficient)
                            );

        // Get the image from image pyramid
        const tImage& FirstImage = First.getImage(Level);
        const tImage& SecondImage = Second.getImage(Level);

        // Compute Ix and Iy image derivatives
        tSize px, py;
        CPoint3D Point(0.0f, PointFirst.y() - Radius);
        double dMaxIx = 0.0, dMaxIy = 0.0;
        for( py = 0; py < Size; ++py )
        {
            Point.x() = PointFirst.x() - Radius;
            for( px = 0; px < Size; ++px )
            {
                m_Ix(py, px) = convolveX<double>(FirstImage, Point, K1D_DERIVATIVE);
                m_Iy(py, px) = convolveY<double>(FirstImage, Point, K1D_DERIVATIVE);
                dMaxIx = vpl::math::getMax(dMaxIx, m_Ix(py, px) * m_Ix(py, px));
                dMaxIy = vpl::math::getMax(dMaxIy, m_Iy(py, px) * m_Iy(py, px));
                Point.x() += 1.0f;
            }
            Point.y() += 1.0f;
        }
        double dDiv = 1.0 / (dMaxIx + dMaxIy + 0.000001);

        // Precompute A matrix
        A.zeros();
        for( py = 0; py < Size; ++py )
        {
            for( px = 0; px < Size; ++px )
            {
                double dIx = m_Ix(py, px);
                double dIy = m_Iy(py, px);

//                double dDiv = 1.0 / (optflow::SIGMA1 * (dIx * dIx + dIy * dIy) + optflow::SIGMA2);

                A(0, 0) += dIx * dIx * dDiv;
                A(1, 1) += dIy * dIy * dDiv;
                A(0, 1) += dIx * dIy * dDiv;
/*                A(0, 0) += dIx * dIx;// * dNorm;
                A(1, 1) += dIy * dIy;// * dNorm;
                A(0, 1) += dIx * dIy;// * dNorm;*/
            }
        }
        A(1, 0) = A(0, 1);
        A *= vpl::CScalard(dNorm);
//        A(0, 0) += 1.0 / optflow::SIGMAP;
//        A(1, 1) += 1.0 / optflow::SIGMAP;

        // Compute eigenvalues of the matrix A
        double dTemp = (A(0, 0) - A(1, 1)) * (A(0, 0) - A(1, 1)) + 4.0 * A(0, 1) * A(1, 0);
        if( dTemp < 0.0 )
        {
            return false;
        }
        dTemp = std::sqrt(dTemp);
        Eigens(0) = (A(0, 0) + A(1, 1) - dTemp) * 0.5;
        Eigens(1) = (A(0, 0) + A(1, 1) + dTemp) * 0.5;

        // Order eigenvalues according to value
        if( Eigens(0) < Eigens(1) )
        {
            dTemp = Eigens(0);
            Eigens(0) = Eigens(1);
            Eigens(1) = dTemp;
        }

//        VPL_LOG_INFO("Eigen values: " << Eigens(0) << ", " << Eigens(1));

        // Invert the A matrix
        double dDet = A(0, 0) * A(1, 1) - A(0, 1) * A(1, 0);
//        if ( vpl::math::getAbs(dDet) > 0.000001 )
        if ( vpl::math::getAbs(dDet) > 0.0001 )
        {
            double dInvDet = 1.0 / dDet;
            Ai(0, 0) = A(1, 1) * dInvDet;
            Ai(1, 1) = A(0, 0) * dInvDet;
            Ai(0, 1) = A(0, 1) * -dInvDet;
            Ai(1, 0) = A(1, 0) * -dInvDet;
        }
        else
        {
            return false;
        }

        // Iterate the linear system
        for( int iIteration = 0; iIteration < optflow::ITERATIONS; ++iIteration )
        {
            // Compute the temporal derivatives
            CPoint3D p1(0.0f, PointFirst.y() - Radius);
            CPoint3D p2(0.0f, p1.y() + m_Motion.y());
            for( py = 0; py < Size; ++py )
            {
                p1.x() = PointFirst.x() - Radius;
                p2.x() = p1.x() + m_Motion.x();
                for( px = 0; px < Size; ++px )
                {
                    m_It(py, px) = FirstImage.interpolate(p1) - SecondImage.interpolate(p2);
                    p1.x() += 1.0f;
                    p2.x() += 1.0f;
                }
                p1.y() += 1.0f;
                p2.y() += 1.0f;
            }

            // Compute over points in the spatiotemporal neighbourhood
            B.zeros();
            for( py = 0; py < Size; ++py )
            {
                for( px = 0; px < Size; ++px )
                {
                    double dIx = m_Ix(py, px);
                    double dIy = m_Iy(py, px);
                    double dIt = m_It(py, px);

//                    double dDiv = 1.0 / (optflow::SIGMA1 * (dIx * dIx + dIy * dIy) + optflow::SIGMA2);

                    B(0) += dIx * dIt * dDiv;
                    B(1) += dIy * dIt * dDiv;
//                    B(0) += dIx * dIt;// * dNorm;
//                    B(1) += dIy * dIt;// * dNorm;
                }
            }
            B *= vpl::CScalard(dNorm);

            // Estimate the optical flow
            if( Eigens(0) >= optflow::EIG_TSH && Eigens(1) >= optflow::EIG_TSH )
            {
                m_Motion.x() -= tCoordinate(Ai(0, 0) * B(0) + Ai(0, 1) * B(1));
                m_Motion.y() -= tCoordinate(Ai(1, 0) * B(0) + Ai(1, 1) * B(1));
            }

            // Estimate only normal of the optical flow
/*            else if( Eigens(0) >= optflow::EIG_TSH )
            {
                dTemp = m_Ix(Radius, Radius) * m_Ix(Radius, Radius);
                dTemp += m_Iy(Radius, Radius) * m_Iy(Radius, Radius);
                if( std::sqrt(dTemp) > 0.0 )
                {
                    m_Motion.x() -= m_It(Radius, Radius) * m_Ix(Radius, Radius) / dTemp;
                    m_Motion.y() -= m_It(Radius, Radius) * m_Iy(Radius, Radius) / dTemp;
                }
            }*/

            // Check the point position
            if( !FirstImage.checkPosition(tSize(PointFirst.x() + m_Motion.x()),
                                          tSize(PointFirst.y() + m_Motion.y())
                                          ) )
            {
/*                VPL_LOG_INFO("Point (" << tSize(PointFirst.x() + m_Motion.x())
                    << ", " << tSize(PointFirst.y() + m_Motion.x())
                    << ") is outside of the image!"
                    );*/
                return false;
            }
        }

        if( Level != 0 )
        {
            // Propagate estimated optical flow to a lower image pyramid level
            m_Motion.x() *= First.getSubSampling();
            m_Motion.y() *= First.getSubSampling();
        }
    }

    // O.K.
    return true;
}


template <class I>
inline void COpticalFlow<I>::warp()
{
    m_Point.x() += m_Motion.x();
    m_Point.y() += m_Motion.y();
}


template <class I>
inline void COpticalFlow<I>::clear()
{
    m_Point.x() = m_Point.y() = m_Point.z() = tCoordinate(0);
}


template <class I>
bool COpticalFlow<I>::visualize(tImage& Image)
{
    // Initial position
    tSize x1 = vpl::math::round2Int(m_Point.x());
    tSize y1 = vpl::math::round2Int(m_Point.y());

    // Final position
    tSize x2 = vpl::math::round2Int(m_Point.x() + m_Motion.x());
    tSize y2 = vpl::math::round2Int(m_Point.y() + m_Motion.y());

    // Check the line position
    VPL_CHECK(Image.checkPosition(x1, y1) && Image.checkPosition(x2, y2), return false);

    // Draw the line
    CLine Line(x1, y1, x2, y2, C_WHITE);

    // Draw the line
    Line.draw(Image);

    // O.K.
    return true;
}

