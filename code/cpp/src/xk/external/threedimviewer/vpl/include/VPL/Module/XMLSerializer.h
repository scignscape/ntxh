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
 * Copyright (c) 2003-2008 by Michal Spanel  
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2008/09/26                       
 *
 * Description:
 * - XML serialization of objects (data entities) over channels.
 */

#ifndef VPL_XMLSerializer_H
#define VPL_XMLSerializer_H

#include <VPL/Base/TypeTraits.h>
#include <VPL/Math/Base.h>
#include <VPL/Module/StreamChannel.h>

#if defined(VPL_XML_ENABLED)

//! This macro is defined if XML serializer is avaliable...
#define VPL_USE_XML_SERIALIZER


#include "Serializer.h"
#include "ModuleExport.h"

#include <set>
#include <tinyxml2.h>

namespace vpl
{
namespace mod
{

//==============================================================================
/*
 * Various definitions.
 */

namespace Serializer
{

    //! Additional serializer flags.
    enum EXMLOptions
    {
        //! Enables XML input/output (the default tag which is always present).
        XML         = 1 << 3,

        //! Enables the stream XML mode (XML without any tabs and line breaks).
        STREAM_XML  = 1 << 4
    };

} // namespace Serializer


//==============================================================================
/*!
 * Serializer of data entities and their members to/from XML files.
 */
class VPL_MODULE_EXPORT CXMLSerializer
    : public vpl::base::CObject
    , public CChannelSerializer<CXMLSerializer>
{
public:
    //! Base class.
    typedef CChannelSerializer<CXMLSerializer> tBase;

    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    VPL_SHAREDPTR(CXMLSerializer);

public:
    //! Default constructor.
    CXMLSerializer(CChannel *pChannel, int iFlags = 0)
        : tBase(pChannel, iFlags | Serializer::XML)
        , m_pGroup(NULL)
    {}

    //! Destructor.
    ~CXMLSerializer()
    {
        m_document.Clear();
    }


    //! Serializes a given data entity.
    //! - Throws exception on failure.
    template <typename T>
    void writeRoot(T& object);

    //! Creates a new logical group of class members in the serialized data.
    //! - Properties of the group, such as compression method, are chosen according
    //!   to the serialization traits.
    //! - Must be called before any write() method.
    //! - Throws exception on failure.
    template <typename T>
    void beginWrite(T& object);

    //! End of the logical group.
    //! - Throws exception on failure.
    template <typename T>
    void endWrite(T& object);

    //! Serializes a given fundamental value.
    //! - Throws exception on failure.
    template <typename T>
    inline void write(const T& value);

    //! Serializes a given block of data.
    //! - Throws exception on failure.
    template <typename T>
    void write(const T *pData, tSize length);

    //! Serializes vector of values
    //! - Throws exception on failure.
    CONTAINER_WRITE( std::vector )
    
    //! Serializes basic string
    //! - Throws exception on failure.
    CONTAINER_WRITE( std::basic_string )

    //! Serializes set of values
    //! - Throws exception on failure.
    template < typename T >
    void write( const std::set<T> & set )
    {
        getImpl().write( set.size() );
        typename std::set<T>::const_iterator it, itEnd( set.end() );
        for( it = set.begin(); it != itEnd; ++it )
        {
            getImpl().write( *it );
        }
    }


    //! Deserializes a given data entity.
    //! - Throws exception on failure.
    template <typename T>
    void readRoot(T& object);

    //! Reads information on logical group of class members from the serialized data.
    //! - Must be called before any read() method.
    //! - Throws exception on failure.
    template <typename T>
    void beginRead(T& object);

    //! Reads end of the logical group.
    //! - Throws exception on failure.
    template <typename T>
    void endRead(T& object);

    //! Deserializes a given fundamental value.
    //! - Throws exception on failure.
    template <typename T>
    inline void read(T& value);

    //! Deserializes a given block of data.
    //! - Throws exception on failure.
    template <typename T>
    void read(T *pData, tSize length);

    //! Deserializes vector of values
    //! - Throws exception on failure.
    CONTAINER_READ( std::vector )
    
    //! Deserializes basic string
    //! - Throws exception on failure.
    CONTAINER_READ( std::basic_string )

    //! Deserializes set of values
    //! - Throws exception on failure.
    template <typename T>
    void read( std::set<T> & set )
    {
        typename std::set<T>::size_type size, i;
        getImpl().read(size);
        for( i = 0; i < size; ++i )
        {
            T aux;
            getImpl().read(aux);
            set.insert(aux);
        }
    }

protected:
    //! Parsed XML document.
    tinyxml2::XMLDocument m_document;

    //! Pointer to the last added logical group.
    tinyxml2::XMLElement *m_pGroup;

protected:
    //! Checks if a given string ssClassName has the 'ClassName<ParamName>'
    //! format and separates the optional parameter name.
    static void findTemplateParameter(std::string& ssClassName, std::string& ssParam);

    //! Encodes data to its string representation.
    static void data2Str(const void *pData, tSize length, std::string& ssData);

    //! Decodes data from the string.
    static void str2Data(const char *pcStr, void *pData, tSize length);
};


//==============================================================================
/*!
 * Smart pointer to binary serializer.
 */
typedef CXMLSerializer::tSmartPtr   CXMLSerializerPtr;


//==============================================================================
/*!
 * Class able to serialize an XML document to any output channel.
 * Warning: In tinyXML2 is issue with indentation. This can be fixed by patch tinyXML2. 
 *  More info see comment inside function flush().
 *  When you have patched tinyXML2 enable VPL_USE_TINYXML2_WITH_INDENT_PATCH in cmake option.
 */
class VPL_MODULE_EXPORT CXMLWriter : public tinyxml2::XMLPrinter
{
public:
    //! Constructor.
    CXMLWriter(CChannel *pChannel) : m_spChannel(pChannel)
    {
        VPL_ASSERT(pChannel);
    }

    //! Destructor.
    virtual ~CXMLWriter() {}

    // Implementation of virtual methods...
    virtual bool VisitEnter(const tinyxml2::XMLDocument& doc);
    virtual bool VisitExit(const tinyxml2::XMLDocument& doc);

    virtual bool VisitEnter(const tinyxml2::XMLElement& element, const tinyxml2::XMLAttribute* firstAttribute);
    virtual bool VisitExit(const tinyxml2::XMLElement& element);

    virtual bool Visit(const tinyxml2::XMLDeclaration& declaration);
    virtual bool Visit(const tinyxml2::XMLText& text);
    virtual bool Visit(const tinyxml2::XMLComment& comment);
    virtual bool Visit(const tinyxml2::XMLUnknown& unknown);

protected:
    //! Output channel.
    CChannelPtr m_spChannel;

protected:
    //! Writes current content of the internal buffer to the output channel.
    bool flush();
};


//==============================================================================
/*
 * Implementation...
 */
#include "XMLSerializer.hxx"


} // namespace mod
} // namespace vpl

#endif // defined(VPL_XML_ENABLED)

#endif // VPL_XMLSerializer_H

