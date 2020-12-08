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
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/12/14                       
 *
 * Description:
 * - Density slice.
 */


//==============================================================================
/*
 * Implementation of the class vpl::img::CSlice.
 */

template <class S>
void CSlice::serialize(vpl::mod::CChannelSerializer<S>& Writer)
{
    // Serialize data of the parent class
    CDImage::serialize(Writer);

    // Begin of data serialization block
    Writer.beginWrite(*this);

    // Extended slice info
    Writer.write(m_dDX);
    Writer.write(m_dDY);
    Writer.write(m_dThickness);
    Writer.write(m_dPosition);
    Writer.write(vpl::sys::tInt32(m_Index));
	Writer.write(vpl::sys::tInt32(m_eOrientation));

    // End of the block
    Writer.endWrite(*this);
}


template <class S>
void CSlice::deserialize(vpl::mod::CChannelSerializer<S>& Reader)
{
    // Deserialize data of the parent class
    CDImage::deserialize(Reader);

    // Begin of data deserialization block
    Reader.beginRead(*this);

    // Read the extended slice info struct
    Reader.read(m_dDX);
    Reader.read(m_dDY);
    Reader.read(m_dThickness);
    Reader.read(m_dPosition);

	vpl::sys::tInt32 Index;
	Reader.read(Index);
	m_Index = tSize(Index);

    vpl::sys::tInt32 Orientation;
    Reader.read(Orientation);
    m_eOrientation = EPlane(Orientation);

    // End of the block
    Reader.endRead(*this);
}

