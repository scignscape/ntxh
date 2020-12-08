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
 * Date:    2004/07/11                       
 *
 * Description:
 * - Manipulation with the real volume data.
 */


//==============================================================================
/*
 * Implementation of the class vpl::img::CDensityVolume.
 */

template <class S>
void CDensityVolume::serialize(vpl::mod::CChannelSerializer<S>& Writer)
{
    // Serialize data of the parent class
    CDVolume::serialize(Writer);

    // Begin of data serialization block
    Writer.beginWrite(*this);

    // Extended volume info
    Writer.write(m_dDX);
    Writer.write(m_dDY);
    Writer.write(m_dDZ);

    // End of the block
    Writer.endWrite(*this);
}


template <class S>
void CDensityVolume::deserialize(vpl::mod::CChannelSerializer<S>& Reader)
{
    // Deserialize data of the parent class
    CDVolume::deserialize(Reader);

    // Begin of data deserialization block
    Reader.beginRead(*this);

    // Density volume info
    Reader.read(m_dDX);
    Reader.read(m_dDY);
    Reader.read(m_dDZ);

    // End of the block
    Reader.endRead(*this);
}

