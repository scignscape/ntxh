//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2009 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2004/07/11                          \n
 *
 * $Id: mdsDensityVolume.hxx 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Manipulation with the real volume data.
 */


//==============================================================================
/*
 * Implementation of the class mds::img::CDensityVolume.
 */

template <class S>
void CDensityVolume::serialize(mds::mod::CChannelSerializer<S>& Writer)
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
void CDensityVolume::deserialize(mds::mod::CChannelSerializer<S>& Reader)
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

