//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2009 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/12/14                          \n
 *
 * $Id: mdsSlice.hxx 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Density slice.
 */


//==============================================================================
/*
 * Implementation of the class mds::img::CSlice.
 */

template <class S>
void CSlice::serialize(mds::mod::CChannelSerializer<S>& Writer)
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
    Writer.write(m_iIndex);
    Writer.write(int(m_eOrientation));

    // End of the block
    Writer.endWrite(*this);
}


template <class S>
void CSlice::deserialize(mds::mod::CChannelSerializer<S>& Reader)
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
    Reader.read(m_iIndex);

    int iOrientation;
    Reader.read(iOrientation);
    m_eOrientation = EPlane(iOrientation);

    // End of the block
    Reader.endRead(*this);
}

