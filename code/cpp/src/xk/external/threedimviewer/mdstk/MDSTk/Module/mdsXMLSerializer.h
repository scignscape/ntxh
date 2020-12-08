//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2008 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2008/09/26                          \n
 *
 * $Id: mdsXMLSerializer.h 2091 2012-02-14 11:26:36Z spanel $
 *
 * Description:
 * - XML serialization of objects (data entities) over channels.
 */

#ifndef MDS_XMLSerializer_H
#define MDS_XMLSerializer_H

#include <MDSTk/Base/mdsTypeTraits.h>
#include <MDSTk/Math/mdsBase.h>
#include <MDSTk/Module/mdsStreamChannel.h>

#if defined(MDS_XML_ENABLED) && defined(TIXML_USE_STL)

//! This macro is defined if XML serializer is avaliable...
#define MDS_USE_XML_SERIALIZER

#include <TinyXML/tinyxml.h>

#include "mdsSerializer.h"
#include "mdsModuleExport.h"


namespace mds
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
class MDS_MODULE_EXPORT CXMLSerializer
    : public mds::base::CObject
    , public CChannelSerializer<CXMLSerializer>
{
public:
    //! Base class.
    typedef CChannelSerializer<CXMLSerializer> tBase;

    //! Smart pointer type.
    //! - Declares type tSmartPtr.
    MDS_SHAREDPTR(CXMLSerializer);

public:
    //! Default constructor.
    CXMLSerializer(CChannel *pChannel, int iFlags = 0)
        : tBase(pChannel, iFlags | Serializer::XML)
        , m_pGroup(NULL)
    {}

    //! Destructor.
    ~CXMLSerializer()
    {
        m_Document.Clear();
    }


    //! Serializes a given data entity.
    //! - Throws exception on failure.
    template <typename T>
    void writeRoot(T& Object);

    //! Creates a new logical group of class members in the serialized data.
    //! - Properties of the group, such as compression method, are chosen according
    //!   to the serialization traits.
    //! - Must be called before any write() method.
    //! - Throws exception on failure.
    template <typename T>
    void beginWrite(T& Object);

    //! End of the logical group.
    //! - Throws exception on failure.
    template <typename T>
    void endWrite(T& Object);

    //! Serializes a given fundamental value.
    //! - Throws exception on failure.
    template <typename T>
    inline void write(const T& Value);

    //! Serializes a given block of data.
    //! - Throws exception on failure.
    template <typename T>
    void write(const T *pData, tSize Length);


    //! Deserializes a given data entity.
    //! - Throws exception on failure.
    template <typename T>
    void readRoot(T& Object);

    //! Reads information on logical group of class members from the serialized data.
    //! - Must be called before any read() method.
    //! - Throws exception on failure.
    template <typename T>
    void beginRead(T& Object);

    //! Reads end of the logical group.
    //! - Throws exception on failure.
    template <typename T>
    void endRead(T& Object);

    //! Deserializes a given fundamental value.
    //! - Throws exception on failure.
    template <typename T>
    inline void read(T& Value);

    //! Deserializes a given block of data.
    //! - Throws exception on failure.
    template <typename T>
    void read(T *pData, tSize Length);

protected:
    //! Parsed XML document.
    TiXmlDocument m_Document;

    //! Pointer to the last added logical group.
    TiXmlElement *m_pGroup;

protected:
    //! Checks if a given string ssClassName has the 'ClassName<ParamName>'
    //! format and separates the optional parameter name.
    static void findTemplateParameter(std::string& ssClassName, std::string& ssParam);

    //! Encodes data to its string representation.
    static void data2Str(const void *pData, tSize Length, std::string& ssData);

    //! Decodes data from the string.
    static void str2Data(const char *pcStr, void *pData, tSize Length);
};


//==============================================================================
/*!
 * Smart pointer to binary serializer.
 */
typedef CXMLSerializer::tSmartPtr   CXMLSerializerPtr;


//==============================================================================
/*!
 * Class able to serialize an XML document to any output channel.
 */
class MDS_MODULE_EXPORT CXMLWriter : public TiXmlPrinter
{
public:
    //! Constructor.
    CXMLWriter(CChannel *pChannel) : m_spChannel(pChannel)
    {
        MDS_ASSERT(pChannel);
    }

    //! Destructor.
    virtual ~CXMLWriter() {}

    // Implementation of virtual methods...
    virtual bool VisitEnter(const TiXmlDocument& doc);
    virtual bool VisitExit(const TiXmlDocument& doc);

    virtual bool VisitEnter(const TiXmlElement& element, const TiXmlAttribute* firstAttribute);
    virtual bool VisitExit(const TiXmlElement& element);

    virtual bool Visit(const TiXmlDeclaration& declaration);
    virtual bool Visit(const TiXmlText& text);
    virtual bool Visit(const TiXmlComment& comment);
    virtual bool Visit(const TiXmlUnknown& unknown);

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
#include "mdsXMLSerializer.hxx"


} // namespace mod
} // namespace mds

#endif // defined(MDS_XML_ENABLED) && defined(TIXML_USE_STL)

#endif // MDS_XMLSerializer_H

