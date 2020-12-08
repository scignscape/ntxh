//==============================================================================`
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2009 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2003/11/17                          \n
 *
 * $Id: mdsSerializable.h 2092 2012-02-15 12:50:59Z spanel $
 *
 * Description:
 * - Introduces a simple object serialization concept.
 */

#ifndef MDS_Serializable_H
#define MDS_Serializable_H

//#include "mdsSerializer.h"
#include "mdsCompressionMethods.h"
#include "mdsModuleExport.h"


namespace mds
{
namespace mod
{

//==============================================================================
/*
 * Several useful macros.
 */

//! Macro declares data entity name of a class used in the serialization concept.
//! - Parameter Name is a string literal.
#define MDS_ENTITY_NAME(Name) \
    inline static const char *getName() \
    { \
        return Name; \
    }

//! Macro declares data entity name of a class used in the serialization concept.
//! Returned name containes information about type
//! and concrete template parameter.
//! - Parameters Name and Param are string literals.
#define MDS_ENTITY_TEMPLATE_NAME(Name, Param) \
    inline static const char *getName() \
    { \
        static const std::string ssName = std::string(Name) + '<' + std::string(Param) + '>'; \
        return ssName.c_str(); \
    }

//! Macro used to declare compression method of a serializable class.
#define MDS_ENTITY_COMPRESSION(Compression) \
    inline static int getCompression() \
    { \
        return Compression; \
    }

//! Macro used to change block size of a serializable class.
#define MDS_ENTITY_BLOCK_SIZE(Size) \
    inline static int getBlockSize() \
    { \
        return Size; \
    }

//! Macro can be used to change compression method of a serializable class template
//! regarding a concrete template parameters.
//! - E.g. MDS_SPECIALIZE_ENTITY_COMPRESSION(mds::img::CImage<short>, CC_RLE16);
#define MDS_SPECIALIZE_ENTITY_COMPRESSION(Class, Compression) \
    template <> \
    inline int Class::getCompression() \
    { \
        return Compression; \
    }


//==============================================================================
/*!
 * Base class for all serializable objects further called data entities.
 * - Every data entity have to declare its name using the MDS_ENTITY_NAME() macro.
 * - Be aware of the maximal entity name length which is limited!
 */
class MDS_MODULE_EXPORT CSerializable
{
public:
    //! Templates that require members of the CSerializable class may use
    //! this enum to check the existence.
    enum { CLASS_SERIALIZABLE };

    //! Current serialization interface version.
    enum { VERSION = 0x33 };

    //! Maximal length of a data entity name in characters.
    enum { MAX_NAME_LENGTH = 32 };

    //! Default class name.
    MDS_ENTITY_NAME("unnamed");

    //! Default compression method.
    MDS_ENTITY_COMPRESSION(CC_RAW);

    //! Default block size.
    MDS_ENTITY_BLOCK_SIZE(4096);

public:
    // Serializes the entity via a given serializer.
    // - This method should be overloaded in each child class. Don't forget
    //   to call serialize() method of a parent class at the begining.
    // - Throws CSerializeFailed exception on failure.
//    template <class S>
//    void serialize(CChannelSerializer<S>& Writer);

    // Deserializes the entity data via a given serializer.
    // - This method should be overloaded in each child class. Don't forget
    //   to call deserialize() method of the parent class at the begining.
    // - Throws CDeserializeFailed on failure.
//    template <class S>
//    void deserialize(CChannelSerializer<S>& Reader);
};


} // namespace mod
} // namespace mds

#endif // MDS_Serializable_H

