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
 * Date:    2009/03/13                       
 *
 * Description:
 * - Object serialization traits.
 */

#ifndef VPL_SerializationTraits_H
#define VPL_SerializationTraits_H

#include <VPL/Base/TypeTraits.h>
#include <VPL/Base/Templates.h>
#include <VPL/Base/StaticAssert.h>

#include "Serializable.h"

// STL
#include <cstring>
#include <string>


namespace vpl
{
namespace mod
{

//==============================================================================
/*!
 * Template providing serialization specific information.
 */
template <typename T>
class CSerializationTraits
{
public:
    //! Current serialization interface version.
    enum { VERSION = CSerializable::VERSION };

    //! Is the T type serializable?
    enum { isSerializable = SIsDerived<T, CSerializable>::RESULT };

public:
    //! Returns interface version number.
    inline static int getVersion()
    {
        return VERSION;
    }

    //! Returns unique name of the T type.
    inline static const char *getName()
    {
        VPL_STATIC_ASSERT(isSerializable, CANNOT_SERIALIZE_OBJECT);

        return T::getName();
    }

    //! Returns the recommended compression method.
    inline static int getCompression()
    {
        VPL_STATIC_ASSERT(isSerializable, CANNOT_SERIALIZE_OBJECT);

        return T::getCompression();
    }

    //! Returns recommended binary block size.
    inline static int getBlockSize()
    {
        VPL_STATIC_ASSERT(isSerializable, CANNOT_SERIALIZE_OBJECT);

        return T::getBlockSize();
    }
};


} // namespace mod
} // namespace vpl

#endif // VPL_SerializationTraits_H
