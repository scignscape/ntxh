//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2009 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2009/03/13                          \n
 *
 * $Id: mdsSerializationTraits.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Object serialization traits.
 */

#ifndef MDS_SerializationTraits_H
#define MDS_SerializationTraits_H

#include <MDSTk/Base/mdsTypeTraits.h>
#include <MDSTk/Base/mdsTemplates.h>
#include <MDSTk/Base/mdsStaticAssert.h>

#include "mdsSerializable.h"

// STL
#include <cstring>
#include <string>


namespace mds
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
        MDS_STATIC_ASSERT(isSerializable, CANNOT_SERIALIZE_OBJECT);

        return T::getName();
    }

    //! Returns the recommended compression method.
    inline static int getCompression()
    {
        MDS_STATIC_ASSERT(isSerializable, CANNOT_SERIALIZE_OBJECT);

        return T::getCompression();
    }

    //! Returns recommended binary block size.
    inline static int getBlockSize()
    {
        MDS_STATIC_ASSERT(isSerializable, CANNOT_SERIALIZE_OBJECT);

        return T::getBlockSize();
    }
};


} // namespace mod
} // namespace mds

#endif // MDS_SerializationTraits_H
