//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2009 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2007/06/20                          \n
 *
 * $Id: mdsXMLSerializer.hxx 2098 2012-02-16 23:50:36Z spanel $
 *
 * Description:
 * - Serialization of objects (data entities) to/from XML.
 */


//==============================================================================
/*
 * Global definitions and functions.
 */

namespace XMLSerializer
{

//! MDSTk data entity identification.
const char XML_ROOT[]       = "MDSTk";

//! Data entity version attribute.
const char XML_VERSION[]    = "version";

//! Elements holding an value.
const char XML_VALUE[]      = "Value";
const char XML_BYTES[]      = "Data";

//! Element's attributes.
const char XML_BOOL[]       = "bool";
const char XML_CHAR[]       = "char";
const char XML_UCHAR[]      = "uchar";
const char XML_SHORT[]      = "short";
const char XML_USHORT[]     = "ushort";
const char XML_INT[]        = "int";
const char XML_UINT[]       = "uint";
const char XML_FLOAT[]      = "float";
const char XML_DOUBLE[]     = "double";
const char XML_SIZE[]       = "size";
const char XML_TYPE[]       = "type";

} // namespace XMLSerializer


//==============================================================================
/*
 * Implementation of the CXMLSerializer class.
 */

template <typename T>
void CXMLSerializer::writeRoot(T& Object)
{
    MDS_STATIC_ASSERT(CSerializationTraits<T>::isSerializable, CANNOT_SERIALIZE_OBJECT);

    tProgressInitializer StartProgress(*this);

    // Clear the XML document
    m_Document.Clear();

    // Prepare the document root
    m_Document.LinkEndChild(new TiXmlDeclaration("1.0", "", ""));
    m_pGroup = new TiXmlElement(XMLSerializer::XML_ROOT);
    m_pGroup->SetAttribute(XMLSerializer::XML_VERSION, CSerializable::VERSION);
    m_Document.LinkEndChild(m_pGroup);

    // Write the entity data
    Object.serialize(*this);

    // Write the prepared XML document to the output channel
    if( !this->checkOption(Serializer::STREAM_XML) )
    {
/*      TiXmlPrinter Printer;
        Printer.SetIndent("  ");
        m_Document.Accept(&Printer);
        if( !m_spChannel->write(Printer.CStr(), Printer.Size()) )
        {
            throw XMLSerializer::CWriteFailed();
        }*/
        CXMLWriter Printer(m_spChannel.get());
        Printer.SetIndent("  ");
        m_Document.Accept(&Printer);
    }
    else
    {
        COStreamChannel Stream(m_spChannel.get());
        Stream.getStream() << m_Document;
    }

    // Clear the created document
    m_Document.Clear();
}


template <typename T>
void CXMLSerializer::beginWrite(T& MDS_UNUSED(Object))
{
    MDS_STATIC_ASSERT(CSerializationTraits<T>::isSerializable, CANNOT_SERIALIZE_OBJECT);

    // Get the root element
    if( !m_pGroup )
    {
        throw Serializer::CWriteFailed();
    }

    static const char *pcName = CSerializationTraits<T>::getName();

    // Separate the class name and optional template parameter
    std::string ssClassName(pcName), ssParam;
    findTemplateParameter(ssClassName, ssParam);

    // Create a new element
    TiXmlElement *pNewGroup = new TiXmlElement(ssClassName);
    if( !ssParam.empty() )
    {
        pNewGroup->SetAttribute(XMLSerializer::XML_TYPE, ssParam.c_str());
    }
    m_pGroup->LinkEndChild(pNewGroup);
    m_pGroup = pNewGroup;
}


template <typename T>
void CXMLSerializer::endWrite(T& MDS_UNUSED(Object))
{
    MDS_STATIC_ASSERT(CSerializationTraits<T>::isSerializable, CANNOT_SERIALIZE_OBJECT);
}


template <typename T>
inline void CXMLSerializer::write(const T& Value)
{
    MDS_STATIC_ASSERT(false, CANNOT_SERIALIZE_VALUE);
}


template <>
inline void CXMLSerializer::write(const bool& Value)
{
    if( !m_pGroup )
    {
        throw Serializer::CWriteFailed();
    }

    TiXmlElement *pValue = new TiXmlElement(XMLSerializer::XML_VALUE);
    pValue->SetAttribute(XMLSerializer::XML_BOOL, int(Value));
    m_pGroup->LinkEndChild(pValue);
}


template <>
inline void CXMLSerializer::write(const char& Value)
{
    if( !m_pGroup )
    {
        throw Serializer::CWriteFailed();
    }

    TiXmlElement *pValue = new TiXmlElement(XMLSerializer::XML_VALUE);
    pValue->SetAttribute(XMLSerializer::XML_CHAR, int(Value));
    m_pGroup->LinkEndChild(pValue);
}


template <>
inline void CXMLSerializer::write(const unsigned char& Value)
{
    if( !m_pGroup )
    {
        throw Serializer::CWriteFailed();
    }

    TiXmlElement *pValue = new TiXmlElement(XMLSerializer::XML_VALUE);
    pValue->SetAttribute(XMLSerializer::XML_UCHAR, int(Value));
    m_pGroup->LinkEndChild(pValue);
}


template <>
inline void CXMLSerializer::write(const int& Value)
{
    if( !m_pGroup )
    {
        throw Serializer::CWriteFailed();
    }

    TiXmlElement *pValue = new TiXmlElement(XMLSerializer::XML_VALUE);
    pValue->SetAttribute(XMLSerializer::XML_INT, Value);
    m_pGroup->LinkEndChild(pValue);
}


template <>
inline void CXMLSerializer::write(const unsigned int& Value)
{
    if( !m_pGroup )
    {
        throw Serializer::CWriteFailed();
    }

    TiXmlElement *pValue = new TiXmlElement(XMLSerializer::XML_VALUE);
    pValue->SetAttribute(XMLSerializer::XML_UINT, int(Value));
    m_pGroup->LinkEndChild(pValue);
}


template <>
inline void CXMLSerializer::write(const short& Value)
{
    if( !m_pGroup )
    {
        throw Serializer::CWriteFailed();
    }

    TiXmlElement *pValue = new TiXmlElement(XMLSerializer::XML_VALUE);
    pValue->SetAttribute(XMLSerializer::XML_SHORT, int(Value));
    m_pGroup->LinkEndChild(pValue);
}


template <>
inline void CXMLSerializer::write(const unsigned short& Value)
{
    if( !m_pGroup )
    {
        throw Serializer::CWriteFailed();
    }

    TiXmlElement *pValue = new TiXmlElement(XMLSerializer::XML_VALUE);
    pValue->SetAttribute(XMLSerializer::XML_USHORT, int(Value));
    m_pGroup->LinkEndChild(pValue);
}


template <>
inline void CXMLSerializer::write(const float& Value)
{
    if( !m_pGroup )
    {
        throw Serializer::CWriteFailed();
    }

    TiXmlElement *pValue = new TiXmlElement(XMLSerializer::XML_VALUE);
    pValue->SetDoubleAttribute(XMLSerializer::XML_FLOAT, double(Value));
    m_pGroup->LinkEndChild(pValue);
}


template <>
inline void CXMLSerializer::write(const double& Value)
{
    if( !m_pGroup )
    {
        throw Serializer::CWriteFailed();
    }

    TiXmlElement *pValue = new TiXmlElement(XMLSerializer::XML_VALUE);
    pValue->SetDoubleAttribute(XMLSerializer::XML_DOUBLE, double(Value));
    m_pGroup->LinkEndChild(pValue);
}


template <typename T>
void CXMLSerializer::write(const T *pData, tSize Length)
{
//    MDS_STATIC_ASSERT(mds::CTypeTraits<T>::isFundamental, CANNOT_SERIALIZE_BLOCK_OF_DATA);

    if( !m_pGroup || !pData )
    {
        throw Serializer::CWriteFailed();
    }

    // Convert the data
    std::string ssData;
    data2Str(pData, Length * (int)sizeof(T), ssData);

    TiXmlElement *pValue = new TiXmlElement(XMLSerializer::XML_BYTES);
    pValue->LinkEndChild(new TiXmlText(ssData));
    pValue->SetAttribute(XMLSerializer::XML_SIZE, int(Length));
    m_pGroup->LinkEndChild(pValue);
}


template <typename T>
void CXMLSerializer::readRoot(T& Object)
{
    MDS_STATIC_ASSERT(CSerializationTraits<T>::isSerializable, CANNOT_SERIALIZE_OBJECT);

    tProgressInitializer StartProgress(*this);

    // Clear the previously created document
    m_Document.Clear();

    // Read the document
    CIStreamChannel Stream(m_spChannel.get());
    Stream.getStream() >> m_Document;

    // Check the entity
    TiXmlHandle Handle(&m_Document);
    m_pGroup = Handle.FirstChild(XMLSerializer::XML_ROOT).ToElement();
    if( !m_pGroup )
    {
        throw Serializer::CReadFailed();
    }

    // Check the version
    int iVersion = -1;
    if( m_pGroup->QueryIntAttribute(XMLSerializer::XML_VERSION, &iVersion) != TIXML_SUCCESS
        || iVersion != CSerializable::VERSION )
    {
        throw Serializer::CReadFailed();
    }

    // Read the entity data
    Object.deserialize(*this);

    // Clear the created document
    m_Document.Clear();
}


template <typename T>
void CXMLSerializer::beginRead(T& MDS_UNUSED(Object))
{
    MDS_STATIC_ASSERT(CSerializationTraits<T>::isSerializable, CANNOT_SERIALIZE_OBJECT);

    static const char *pcName = CSerializationTraits<T>::getName();

    std::string ssClassName(pcName), ssParam;
    findTemplateParameter(ssClassName, ssParam);

    TiXmlHandle Handle(m_pGroup);
    m_pGroup = Handle.FirstChild(ssClassName).ToElement();
    if( !m_pGroup )
    {
        throw Serializer::CReadFailed();
    }

    if( !ssParam.empty() )
    {
        const char *pcParam = m_pGroup->Attribute(XMLSerializer::XML_TYPE);
        if( !pcParam || ssParam != std::string(pcParam) )
        {
            throw Serializer::CReadFailed();
        }
    }
}


template <typename T>
void CXMLSerializer::endRead(T& MDS_UNUSED(Object))
{
    MDS_STATIC_ASSERT(CSerializationTraits<T>::isSerializable, CANNOT_SERIALIZE_OBJECT);
}


template <typename T>
inline void CXMLSerializer::read(T& Value)
{
    MDS_STATIC_ASSERT(false, CANNOT_SERIALIZE_VALUE);
}


template <>
inline void CXMLSerializer::read(bool& Value)
{
    if( !m_pGroup )
    {
        throw Serializer::CReadFailed();
    }

    TiXmlNode *pValue = m_pGroup->FirstChild(XMLSerializer::XML_VALUE);
    if( !pValue )
    {
        throw Serializer::CReadFailed();
    }

    int iValue;
    if( pValue->ToElement()->QueryIntAttribute(XMLSerializer::XML_BOOL, &iValue) != TIXML_SUCCESS )
    {
        throw Serializer::CReadFailed();
    }

    m_pGroup->RemoveChild(pValue);

    Value = mds::math::conv2Bool<int>(iValue);
}


template <>
inline void CXMLSerializer::read(char& Value)
{
    if( !m_pGroup )
    {
        throw Serializer::CReadFailed();
    }

    TiXmlNode *pValue = m_pGroup->FirstChild(XMLSerializer::XML_VALUE);
    if( !pValue )
    {
        throw Serializer::CReadFailed();
    }

    int iValue;
    if( pValue->ToElement()->QueryIntAttribute(XMLSerializer::XML_CHAR, &iValue) != TIXML_SUCCESS )
    {
        throw Serializer::CReadFailed();
    }

    m_pGroup->RemoveChild(pValue);

    Value = char(iValue);
}


template <>
inline void CXMLSerializer::read(unsigned char& Value)
{
    if( !m_pGroup )
    {
        throw Serializer::CReadFailed();
    }

    TiXmlNode *pValue = m_pGroup->FirstChild(XMLSerializer::XML_VALUE);
    if( !pValue )
    {
        throw Serializer::CReadFailed();
    }

    int iValue;
    if( pValue->ToElement()->QueryIntAttribute(XMLSerializer::XML_UCHAR, &iValue) != TIXML_SUCCESS )
    {
        throw Serializer::CReadFailed();
    }

    m_pGroup->RemoveChild(pValue);

    Value = (unsigned char)(iValue);
}


template <>
inline void CXMLSerializer::read(int& Value)
{
    if( !m_pGroup )
    {
        throw Serializer::CReadFailed();
    }

    TiXmlNode *pValue = m_pGroup->FirstChild(XMLSerializer::XML_VALUE);
    if( !pValue )
    {
        throw Serializer::CReadFailed();
    }

    if( pValue->ToElement()->QueryIntAttribute(XMLSerializer::XML_INT, &Value) != TIXML_SUCCESS )
    {
        throw Serializer::CReadFailed();
    }

    m_pGroup->RemoveChild(pValue);
}


template <>
inline void CXMLSerializer::read(unsigned int& Value)
{
    if( !m_pGroup )
    {
        throw Serializer::CReadFailed();
    }

    TiXmlNode *pValue = m_pGroup->FirstChild(XMLSerializer::XML_VALUE);
    if( !pValue )
    {
        throw Serializer::CReadFailed();
    }

    int iValue;
    if( pValue->ToElement()->QueryIntAttribute(XMLSerializer::XML_UINT, &iValue) != TIXML_SUCCESS )
    {
        throw Serializer::CReadFailed();
    }

    m_pGroup->RemoveChild(pValue);

    Value = (unsigned int)(iValue);
}


template <>
inline void CXMLSerializer::read(short& Value)
{
    if( !m_pGroup )
    {
        throw Serializer::CReadFailed();
    }

    TiXmlNode *pValue = m_pGroup->FirstChild(XMLSerializer::XML_VALUE);
    if( !pValue )
    {
        throw Serializer::CReadFailed();
    }

    int iValue;
    if( pValue->ToElement()->QueryIntAttribute(XMLSerializer::XML_SHORT, &iValue) != TIXML_SUCCESS )
    {
        throw Serializer::CReadFailed();
    }

    m_pGroup->RemoveChild(pValue);

    Value = short(iValue);
}


template <>
inline void CXMLSerializer::read(unsigned short& Value)
{
    if( !m_pGroup )
    {
        throw Serializer::CReadFailed();
    }

    TiXmlNode *pValue = m_pGroup->FirstChild(XMLSerializer::XML_VALUE);
    if( !pValue )
    {
        throw Serializer::CReadFailed();
    }

    int iValue;
    if( pValue->ToElement()->QueryIntAttribute(XMLSerializer::XML_USHORT, &iValue) != TIXML_SUCCESS )
    {
        throw Serializer::CReadFailed();
    }

    m_pGroup->RemoveChild(pValue);

    Value = (unsigned short)(iValue);
}


template <>
inline void CXMLSerializer::read(float& Value)
{
    if( !m_pGroup )
    {
        throw Serializer::CReadFailed();
    }

    TiXmlNode *pValue = m_pGroup->FirstChild(XMLSerializer::XML_VALUE);
    if( !pValue )
    {
        throw Serializer::CReadFailed();
    }

    double dValue;
    if( pValue->ToElement()->QueryDoubleAttribute(XMLSerializer::XML_FLOAT, &dValue) != TIXML_SUCCESS )
    {
        throw Serializer::CReadFailed();
    }

    m_pGroup->RemoveChild(pValue);

    Value = float(dValue);
}


template <>
inline void CXMLSerializer::read(double& Value)
{
    if( !m_pGroup )
    {
        throw Serializer::CReadFailed();
    }

    TiXmlNode *pValue = m_pGroup->FirstChild(XMLSerializer::XML_VALUE);
    if( !pValue )
    {
        throw Serializer::CReadFailed();
    }

    if( pValue->ToElement()->QueryDoubleAttribute(XMLSerializer::XML_DOUBLE, &Value) != TIXML_SUCCESS )
    {
        throw Serializer::CReadFailed();
    }

    m_pGroup->RemoveChild(pValue);
}


template <typename T>
void CXMLSerializer::read(T *pData, tSize Length)
{
//    MDS_STATIC_ASSERT(mds::CTypeTraits<T>::isFundamental, CANNOT_SERIALIZE_DATA);

    if( !m_pGroup || !pData )
    {
        throw Serializer::CReadFailed();
    }

    TiXmlNode *pValue = m_pGroup->FirstChild(XMLSerializer::XML_BYTES);
    if( !pValue )
    {
        throw Serializer::CReadFailed();
    }

    int iValue;
    if( pValue->ToElement()->QueryIntAttribute(XMLSerializer::XML_SIZE, &iValue) != TIXML_SUCCESS )
    {
        throw Serializer::CReadFailed();
    }

    // Get encoded data
    const char *pcStr = pValue->ToElement()->GetText();
    if( !pcStr || tSize(iValue) != Length || tSize(strlen(pcStr)) != Length )
    {
        throw Serializer::CReadFailed();
    }

    // Encode the data
    str2Data(pcStr, pData, Length * (int)sizeof(T));

    m_pGroup->RemoveChild(pValue);
}

