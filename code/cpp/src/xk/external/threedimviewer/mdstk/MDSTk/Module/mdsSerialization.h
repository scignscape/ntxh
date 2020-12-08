//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2009 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2009/03/28                          \n
 *
 * $Id: mdsSerialization.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Serialization of objects (data entities) over channels.
 */

#ifndef MDS_Serialization_H
#define MDS_Serialization_H

#include "mdsBinarySerializer.h"
#include "mdsSHMSerializer.h"
#include "mdsXMLSerializer.h"


namespace mds
{
namespace mod
{

//==============================================================================
/*
 * Global functions.
 */

//! Serializes a given object.
//! - Returns false on failure.
template <typename T, class S>
bool write(T& Object, CChannelSerializer<S>& Writer);

//! Writes serializable object into a given channel.
//! - Creates serializer with respect to the channel type and given flags.
//! - Returns false on failure.
template <typename T>
bool write(T& Object, CChannel& Channel, int iFlags = 0);

//! Writes serializable object into a given channel.
//! - Creates serializer with respect to the channel type and given flags.
//! - Calls a given functor to notify a waiting process about the progress.
//! - Returns false on failure.
template <typename T>
bool write(T& Object,
           CChannel& Channel,
           CProgress::tProgressFunc& Progress,
           int iFlags = 0
           );

//! Writes serializable object into a specified binary file.
//! - Creates serializer with respect to the channel type and flags.
//! - Returns false on failure.
template <typename T>
bool save(T& Object, const std::string& ssFilename, int iFlags = 0);


//! Deserializes a given object.
//! - Returns false on failure.
template <typename T, class S>
bool read(T& Object, CChannelSerializer<S>& Reader);

//! Reads serializable object from a specified input channel.
//! - Creates serializer with respect to the channel type.
//! - Returns false on failure.
template <typename T>
bool read(T& Object, CChannel& Channel, int iFlags = 0);

//! Reads serializable object from a specified input channel.
//! - Creates serializer with respect to the channel type.
//! - Returns false on failure.
//! - Calls a given functor to notify a waiting process about the progress.
template <typename T>
bool read(T& Object,
          CChannel& Channel,
          CProgress::tProgressFunc& Progress,
          int iFlags = 0
          );

//! Reads serializable object from a specified binary file.
//! - Creates serializer with respect to the channel type.
//! - Returns false on failure.
template <typename T>
bool load(T& Object, const std::string& ssFilename, int iFlags = 0);


//==============================================================================
/*
 * Implementation...
 */
#include "mdsSerialization.hxx"


} // namespace mod
} // namespace mds

#endif // MDS_Serialization_H

