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
 * Date:    2009/03/28                       
 *
 * Description:
 * - Serialization of objects (data entities) over channels.
 */

#ifndef VPL_Serialization_H
#define VPL_Serialization_H

#include "BinarySerializer.h"
#include "SHMSerializer.h"
#include "XMLSerializer.h"


namespace vpl
{
namespace mod
{

//==============================================================================
/*
 * Global functions.
 */


#ifndef SWIG

 //! Serializes a given object.
 //! - Returns false on failure.
    template <typename T, class S>
    bool write(T& Object, CChannelSerializer<S>& Writer);

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

#endif

//! Writes serializable object into a given channel.
//! - Creates serializer with respect to the channel type and given flags.
//! - Returns false on failure.
template <typename T>
bool write(T& Object, CChannel& Channel, int iFlags = 0);



//! Writes serializable object into a specified binary file.
//! - Creates serializer with respect to the channel type and flags.
//! - Returns false on failure.
template <typename T>
bool save(T& Object, const std::string& ssFilename, int iFlags = 0);


#ifndef SWIG

//! Deserializes a given object.
//! - Returns false on failure.
template <typename T, class S>
bool read(T& Object, CChannelSerializer<S>& Reader);

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
#endif

//! Reads serializable object from a specified input channel.
//! - Creates serializer with respect to the channel type.
//! - Returns false on failure.
template <typename T>
bool read(T& Object, CChannel& Channel, int iFlags = 0);



//! Reads serializable object from a specified binary file.
//! - Creates serializer with respect to the channel type.
//! - Returns false on failure.
template <typename T>
bool load(T& Object, const std::string& ssFilename, int iFlags = 0);


//==============================================================================
/*
 * Implementation...
 */
#include "Serialization.hxx"


} // namespace mod
} // namespace vpl

#endif // VPL_Serialization_H

