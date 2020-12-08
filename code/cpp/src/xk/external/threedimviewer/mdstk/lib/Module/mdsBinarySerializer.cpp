//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2009 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/06/20                          \n
 *
 * $Id: mdsBinarySerializer.cpp 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Serialization of objects (data entities) via channels.
 */

#include <MDSTk/Module/mdsBinarySerializer.h>


namespace mds
{
namespace mod
{

//==============================================================================
/*
 * Global definitions and functions.
 */

namespace BinarySerializer
{

//! Data entity magic number.
const mds::sys::tUInt32 MAGIC       = 0x53444d;

//! Name of empty terminal data block.
const char TERMINAL_BLOCK_NAME[]    = "TerminalBlock";

//! Alignment of data entity header.
const int HEADER_ALIGNMENT          = 256;


//! Padding of data entity header.
const int ENTITY_HEADER_PADDING = HEADER_ALIGNMENT - 8;

//! Data entity header.
struct SEntityHeader
{
    //! Magic number.
    mds::sys::tUInt32 m_Magic;

    //! Version of the data entity format.
    mds::sys::tInt32 m_Version;

    //! Reserved bytes for later use.
    mds::sys::tInt8 m_pcReserved[ENTITY_HEADER_PADDING];
};


//! Padding of entity part header.
const int GROUP_HEADER_PADDING = HEADER_ALIGNMENT - CSerializable::MAX_NAME_LENGTH - 8;

//! Entity part header.
struct SGroupHeader
{
    //! Data block name.
    char m_pcName[CSerializable::MAX_NAME_LENGTH];

    //! Used data compression method.
    mds::sys::tInt32 m_Compression;

    //! Size of the data block.
    mds::sys::tInt32 m_BlockSize;

    //! Reserved bytes for later use.
    mds::sys::tInt8 m_pcReserved[GROUP_HEADER_PADDING];
};


//! Compares two entity names.
//! - Returns true if both names are similar.
bool compareEntityNames(const char *pcName1, const char *pcName2)
{
    for( int i = 0; i < CSerializable::MAX_NAME_LENGTH; ++i )
    {
        if( pcName1[i] != pcName2[i] )
        {
            return false;
        }
        else if ( pcName1[i] == '\0' )
        {
            break;
        }
    }

    return true;
}


//! Writes data entity header to a binary channel.
//! - Returns false on failure.
bool writeEntityHeader(CChannel& Channel)
{
    // Initialize data entity header
    SEntityHeader Header;
    Header.m_Magic = MAGIC;
    Header.m_Version = mds::sys::tInt32(CSerializable::VERSION);
    memset(Header.m_pcReserved, 0, ENTITY_HEADER_PADDING);

    // Write the header
    return Channel.write((char *)&Header, (int)sizeof(Header));
}


//! Reads and checks the data entity header.
//! - Returns false on failure.
bool readEntityHeader(CChannel& Channel)
{
    // Read the data entity header
    SEntityHeader Header;
    int iHeaderSize = (int)sizeof(Header);
    if( Channel.read((char *)&Header, iHeaderSize) != iHeaderSize )
    {
        return false;
    }

    // Check the entity magic number and version
    return (Header.m_Magic == MAGIC && Header.m_Version == mds::sys::tInt32(CSerializable::VERSION));
}


//! Writes header of data entity logical group.
//! - Returns false on failure.
bool writeGroupHeader(CChannel& Channel,
                      const char *pcName,
                      int Compression,
                      tSize BlockSize
                      )
{
    // Initialize part header
    SGroupHeader Header;
    strncpy(Header.m_pcName, pcName, CSerializable::MAX_NAME_LENGTH);
    Header.m_Compression = mds::sys::tInt32(Compression);
    Header.m_BlockSize = mds::sys::tInt32(BlockSize);
    memset(Header.m_pcReserved, 0, GROUP_HEADER_PADDING);

    // Write the header
    return Channel.write((char *)&Header, (int)sizeof(Header));
}


//! Reads and decodes header of data entity group.
//! - Returns false on failure.
bool readGroupHeader(CChannel& Channel,
                     const char *pcName,
                     int& Compression,
                     tSize& BlockSize
                     )
{
    // Data part header and its size
    SGroupHeader Header;
    int iHeaderSize = (int)sizeof(Header);

lRead:
    // Read the part header
    if( Channel.read((char *)&Header, iHeaderSize) != iHeaderSize )
    {
        return false;
    }

    // Check the part name
    if( !compareEntityNames(Header.m_pcName, pcName) )
    {
        // Check if the part is terminal
        if( compareEntityNames(Header.m_pcName, TERMINAL_BLOCK_NAME) )
        {
            // Failed to read required data part
            return false;
        }

        // Check the block size
        if( Header.m_BlockSize > 0 )
        {
            // Skip data of the part
            CBlockChannel BlockChannel(Header.m_BlockSize, &Channel);
            BlockChannel.flush();
        }

        // Try next part
        goto lRead;
    }

    // Compression method
    Compression = int(Header.m_Compression);

    // Size of the block
    BlockSize = tSize(Header.m_BlockSize);

    // O.K.
    return true;
}


//! Writes terminal to a binary channel.
//! - Returns false on failure.
bool writeTerminal(CChannel& Channel)
{
    return writeGroupHeader(Channel, TERMINAL_BLOCK_NAME, CC_RAW, 0);
}


//! Finds and reads terminal.
//! - Returns false on failure.
bool readTerminal(CChannel& Channel)
{
    // Data part header
    SGroupHeader Header;
    int iHeaderSize = (int)sizeof(Header);

lRead:
    // Read the part header
    if( Channel.read((char *)&Header, iHeaderSize) != iHeaderSize )
    {
        return false;
    }

    // Check the part name
    if( !compareEntityNames(Header.m_pcName, TERMINAL_BLOCK_NAME) )
    {
        // Check the block size
        if( Header.m_BlockSize > 0 )
        {
            // Skip data of the part
            CBlockChannel BlockChannel(Header.m_BlockSize, &Channel);
            BlockChannel.flush();
        }

        // Try next part
        goto lRead;
    }

    // Terminal has been found
    return true;
}

} // namespace BinarySerializer


} // namespace mod
} // namespace mds

