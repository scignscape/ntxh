//==============================================================================
/* This file comes from MDS
software and was modified for
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
 * Date:    2007/06/20                       
 *
 * Description:
 * - Serialization of objects (data entities) to/from XML.
 */


//==============================================================================
/*
 * Global definitions and functions.
 */

#pragma once
namespace XMLSerializer
{

//! MDSTk data entity identification.
const char XML_ROOT[]       = "MDSTk";
//! Is required for backward compatibility, where was root tag Tk.
const char XML_ROOT_OLD[]   = "Tk";

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

const int bufferSize = 500;

} // namespace XMLSerializer


//==============================================================================
/*
 * Implementation of the CXMLSerializer class.
 */

template <typename T>
void CXMLSerializer::writeRoot(T& object)
{
    VPL_STATIC_ASSERT(CSerializationTraits<T>::isSerializable, CANNOT_SERIALIZE_OBJECT);

    tProgressInitializer startProgress(*this);

    // Clear the XML document
    m_document.Clear();


    // Prepare the document root
    m_document.InsertEndChild(m_document.NewDeclaration("xml version=\"1.0\""));
    m_pGroup = m_document.NewElement(XMLSerializer::XML_ROOT);
    m_pGroup->SetAttribute(XMLSerializer::XML_VERSION, CSerializable::VERSION);
    m_document.LinkEndChild(m_pGroup);

    // Write the entity data
    object.serialize(*this);

    // Write the prepared XML document to the output channel
    if( !this->checkOption(Serializer::STREAM_XML) )
    {

        CXMLWriter printer(m_spChannel.get());
        m_document.Accept(&printer);
    }
    else
    {
        tinyxml2::XMLPrinter  printer(nullptr);
        m_document.Print(&printer);

        COStreamChannel stream(m_spChannel.get());
        stream.getStream() << printer.CStr();
    }

    // Clear the created document
    m_document.Clear();
}


template <typename T>
void CXMLSerializer::beginWrite(T& VPL_UNUSED(Object))
{
    VPL_STATIC_ASSERT(CSerializationTraits<T>::isSerializable, CANNOT_SERIALIZE_OBJECT);

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
    tinyxml2::XMLElement *pNewGroup = m_document.NewElement(ssClassName.c_str());
    if( !ssParam.empty() )
    {
        pNewGroup->SetAttribute(XMLSerializer::XML_TYPE, ssParam.c_str());
    }
    m_pGroup->LinkEndChild(pNewGroup);
    m_pGroup = pNewGroup;
}


template <typename T>
void CXMLSerializer::endWrite(T& VPL_UNUSED(Object))
{
    VPL_STATIC_ASSERT(CSerializationTraits<T>::isSerializable, CANNOT_SERIALIZE_OBJECT);
}


template <typename T>
inline void CXMLSerializer::write(const T&)
{
//    VPL_STATIC_ASSERT(false, CANNOT_SERIALIZE_VALUE);
}


template <>
inline void CXMLSerializer::write(const bool& value)
{
    if( !m_pGroup )
    {
        throw Serializer::CWriteFailed();
    }

    tinyxml2::XMLElement *pValue = m_document.NewElement(XMLSerializer::XML_VALUE);
    pValue->SetAttribute(XMLSerializer::XML_BOOL, int(value));
    m_pGroup->LinkEndChild(pValue);
}


template <>
inline void CXMLSerializer::write(const char& value)
{
    if( !m_pGroup )
    {
        throw Serializer::CWriteFailed();
    }

    tinyxml2::XMLElement *pValue = m_document.NewElement(XMLSerializer::XML_VALUE);
    pValue->SetAttribute(XMLSerializer::XML_CHAR, int(value));
    m_pGroup->LinkEndChild(pValue);
}


template <>
inline void CXMLSerializer::write(const unsigned char& value)
{
    if( !m_pGroup )
    {
        throw Serializer::CWriteFailed();
    }

    tinyxml2::XMLElement *pValue = m_document.NewElement(XMLSerializer::XML_VALUE);
    pValue->SetAttribute(XMLSerializer::XML_UCHAR, int(value));
    m_pGroup->LinkEndChild(pValue);
}


template <>
inline void CXMLSerializer::write(const int& value)
{
    if( !m_pGroup )
    {
        throw Serializer::CWriteFailed();
    }

    tinyxml2::XMLElement *pValue = m_document.NewElement(XMLSerializer::XML_VALUE);
    pValue->SetAttribute(XMLSerializer::XML_INT, value);
    m_pGroup->LinkEndChild(pValue);
}


template <>
inline void CXMLSerializer::write(const unsigned int& value)
{
    if( !m_pGroup )
    {
        throw Serializer::CWriteFailed();
    }

    tinyxml2::XMLElement *pValue = m_document.NewElement(XMLSerializer::XML_VALUE);
    pValue->SetAttribute(XMLSerializer::XML_UINT, int(value));
    m_pGroup->LinkEndChild(pValue);
}


template <>
inline void CXMLSerializer::write(const short& value)
{
    if( !m_pGroup )
    {
        throw Serializer::CWriteFailed();
    }

    tinyxml2::XMLElement *pValue = m_document.NewElement(XMLSerializer::XML_VALUE);
    pValue->SetAttribute(XMLSerializer::XML_SHORT, int(value));
    m_pGroup->LinkEndChild(pValue);
}


template <>
inline void CXMLSerializer::write(const unsigned short& value)
{
    if( !m_pGroup )
    {
        throw Serializer::CWriteFailed();
    }

    tinyxml2::XMLElement *pValue = m_document.NewElement(XMLSerializer::XML_VALUE);
    pValue->SetAttribute(XMLSerializer::XML_USHORT, int(value));
    m_pGroup->LinkEndChild(pValue);
}


template <>
inline void CXMLSerializer::write(const float& value)
{
    if( !m_pGroup )
    {
        throw Serializer::CWriteFailed();
    }

    tinyxml2::XMLElement *pValue = m_document.NewElement(XMLSerializer::XML_VALUE);
    pValue->SetAttribute(XMLSerializer::XML_FLOAT, double(value));
    m_pGroup->LinkEndChild(pValue);
}


template <>
inline void CXMLSerializer::write(const double& value)
{
    if( !m_pGroup )
    {
        throw Serializer::CWriteFailed();
    }

    tinyxml2::XMLElement *pValue = m_document.NewElement(XMLSerializer::XML_VALUE);
    pValue->SetAttribute(XMLSerializer::XML_DOUBLE, double(value));
    m_pGroup->LinkEndChild(pValue);
}


template <typename T>
void CXMLSerializer::write(const T *pData, tSize Length)
{
//    VPL_STATIC_ASSERT(vpl::CTypeTraits<T>::isFundamental, CANNOT_SERIALIZE_BLOCK_OF_DATA);

    if( !m_pGroup || !pData )
    {
        throw Serializer::CWriteFailed();
    }

    // Convert the data
    std::string ssData;
    data2Str(pData, Length * tSize(sizeof(T)), ssData);

    tinyxml2::XMLElement *pValue = m_document.NewElement(XMLSerializer::XML_BYTES);
    
    pValue->LinkEndChild(m_document.NewText(ssData.c_str()));
    pValue->SetAttribute(XMLSerializer::XML_SIZE, int(Length));
    m_pGroup->LinkEndChild(pValue);
}


template <typename T>
void CXMLSerializer::readRoot(T& object)
{
    VPL_STATIC_ASSERT(CSerializationTraits<T>::isSerializable, CANNOT_SERIALIZE_OBJECT);

    tProgressInitializer startProgress(*this);

    //! Clear the previously created document
    m_document.Clear();

    //! Read the document

    //! Allocated size for all input.
    int contentSize = XMLSerializer::bufferSize;

    //! Buffer for reading
    char buffer[XMLSerializer::bufferSize];
    sys::memZero(buffer, XMLSerializer::bufferSize);

    //! All content of file
    char* content = sys::memAlloc<char>(contentSize);

    //! Length of already readed input.
    int length = 0;
    while (const int readCount = m_spChannel->read(buffer, XMLSerializer::bufferSize))
    {
        sys::memCopy(content + length, buffer, XMLSerializer::bufferSize);
        sys::memZero(buffer, XMLSerializer::bufferSize);

        length += readCount;
        if (length + XMLSerializer::bufferSize >= contentSize)
        {
            contentSize *= 2;
            content = sys::memRealloc<char>(content, contentSize);
        }
    }
    if (length == contentSize)
    {
        content = sys::memRealloc<char>(content, contentSize + 1);
    }
    content[length + 1] = '\0';

    m_document.Parse(content);

    // Check the entity
    tinyxml2::XMLHandle handle(&m_document);
    m_pGroup = handle.FirstChildElement(XMLSerializer::XML_ROOT).ToElement();
    if( !m_pGroup )
    {
        m_pGroup = handle.FirstChildElement(XMLSerializer::XML_ROOT_OLD).ToElement();
        if(!m_pGroup)
        {
            throw Serializer::CReadFailed();
        }
    }

    // Check the version
    int iVersion = -1;
    if( m_pGroup->QueryIntAttribute(XMLSerializer::XML_VERSION, &iVersion) != tinyxml2::XML_SUCCESS
        || iVersion != CSerializable::VERSION )
    {
        throw Serializer::CReadFailed();
    }

    // Read the entity data
    object.deserialize(*this);

    // Clear the created document
    m_document.Clear();
}


template <typename T>
void CXMLSerializer::beginRead(T& VPL_UNUSED(Object))
{
    VPL_STATIC_ASSERT(CSerializationTraits<T>::isSerializable, CANNOT_SERIALIZE_OBJECT);

    static const char *pcName = CSerializationTraits<T>::getName();

    std::string ssClassName(pcName), ssParam;
    findTemplateParameter(ssClassName, ssParam);

    tinyxml2::XMLHandle handle(m_pGroup);
    m_pGroup = handle.FirstChildElement(ssClassName.c_str()).ToElement();
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
void CXMLSerializer::endRead(T& VPL_UNUSED(Object))
{
    VPL_STATIC_ASSERT(CSerializationTraits<T>::isSerializable, CANNOT_SERIALIZE_OBJECT);
}


template <typename T>
inline void CXMLSerializer::read(T&)
{
//    VPL_STATIC_ASSERT(false, CANNOT_SERIALIZE_VALUE);
}


template <>
inline void CXMLSerializer::read(bool& value)
{
    if( !m_pGroup )
    {
        throw Serializer::CReadFailed();
    }

    tinyxml2::XMLNode *pValue = m_pGroup->FirstChildElement(XMLSerializer::XML_VALUE);
    if( !pValue )
    {
        throw Serializer::CReadFailed();
    }

    int iValue;
    if( pValue->ToElement()->QueryIntAttribute(XMLSerializer::XML_BOOL, &iValue) != tinyxml2::XML_SUCCESS )
    {
        throw Serializer::CReadFailed();
    }

    m_pGroup->DeleteChild(pValue);

    value = vpl::math::conv2Bool<int>(iValue);
}


template <>
inline void CXMLSerializer::read(char& value)
{
    if( !m_pGroup )
    {
        throw Serializer::CReadFailed();
    }

    tinyxml2::XMLNode *pValue = m_pGroup->FirstChildElement(XMLSerializer::XML_VALUE);
    if( !pValue )
    {
        throw Serializer::CReadFailed();
    }

    int iValue;
    if( pValue->ToElement()->QueryIntAttribute(XMLSerializer::XML_CHAR, &iValue) != tinyxml2::XML_SUCCESS)
    {
        throw Serializer::CReadFailed();
    }

    m_pGroup->DeleteChild(pValue);

    value = char(iValue);
}


template <>
inline void CXMLSerializer::read(unsigned char& value)
{
    if( !m_pGroup )
    {
        throw Serializer::CReadFailed();
    }

    tinyxml2::XMLNode *pValue = m_pGroup->FirstChildElement(XMLSerializer::XML_VALUE);
    if( !pValue )
    {
        throw Serializer::CReadFailed();
    }

    int iValue;
    if( pValue->ToElement()->QueryIntAttribute(XMLSerializer::XML_UCHAR, &iValue) != tinyxml2::XML_SUCCESS)
    {
        throw Serializer::CReadFailed();
    }

    m_pGroup->DeleteChild(pValue);

    value = (unsigned char)(iValue);
}


template <>
inline void CXMLSerializer::read(int& value)
{
    if( !m_pGroup )
    {
        throw Serializer::CReadFailed();
    }

    tinyxml2::XMLNode *pValue = m_pGroup->FirstChildElement(XMLSerializer::XML_VALUE);
    if( !pValue )
    {
        throw Serializer::CReadFailed();
    }

    if( pValue->ToElement()->QueryIntAttribute(XMLSerializer::XML_INT, &value) != tinyxml2::XML_SUCCESS)
    {
        throw Serializer::CReadFailed();
    }

    m_pGroup->DeleteChild(pValue);
}


template <>
inline void CXMLSerializer::read(unsigned int& value)
{
    if( !m_pGroup )
    {
        throw Serializer::CReadFailed();
    }

    tinyxml2::XMLNode *pValue = m_pGroup->FirstChildElement(XMLSerializer::XML_VALUE);
    if( !pValue )
    {
        throw Serializer::CReadFailed();
    }

    int iValue;
    if( pValue->ToElement()->QueryIntAttribute(XMLSerializer::XML_UINT, &iValue) != tinyxml2::XML_SUCCESS)
    {
        throw Serializer::CReadFailed();
    }

    m_pGroup->DeleteChild(pValue);

    value = (unsigned int)(iValue);
}


template <>
inline void CXMLSerializer::read(short& value)
{
    if( !m_pGroup )
    {
        throw Serializer::CReadFailed();
    }

    tinyxml2::XMLNode *pValue = m_pGroup->FirstChildElement(XMLSerializer::XML_VALUE);
    if( !pValue )
    {
        throw Serializer::CReadFailed();
    }

    int iValue;
    if( pValue->ToElement()->QueryIntAttribute(XMLSerializer::XML_SHORT, &iValue) != tinyxml2::XML_SUCCESS)
    {
        throw Serializer::CReadFailed();
    }

    m_pGroup->DeleteChild(pValue);

    value = short(iValue);
}


template <>
inline void CXMLSerializer::read(unsigned short& value)
{
    if( !m_pGroup )
    {
        throw Serializer::CReadFailed();
    }

    tinyxml2::XMLNode *pValue = m_pGroup->FirstChildElement(XMLSerializer::XML_VALUE);
    if( !pValue )
    {
        throw Serializer::CReadFailed();
    }

    int iValue;
    if( pValue->ToElement()->QueryIntAttribute(XMLSerializer::XML_USHORT, &iValue) != tinyxml2::XML_SUCCESS)
    {
        throw Serializer::CReadFailed();
    }

    m_pGroup->DeleteChild(pValue);

    value = (unsigned short)(iValue);
}


template <>
inline void CXMLSerializer::read(float& value)
{
    if( !m_pGroup )
    {
        throw Serializer::CReadFailed();
    }

    tinyxml2::XMLNode *pValue = m_pGroup->FirstChildElement(XMLSerializer::XML_VALUE);
    if( !pValue )
    {
        throw Serializer::CReadFailed();
    }

    double dValue;
    if( pValue->ToElement()->QueryDoubleAttribute(XMLSerializer::XML_FLOAT, &dValue) != tinyxml2::XML_SUCCESS)
    {
        throw Serializer::CReadFailed();
    }

    m_pGroup->DeleteChild(pValue);

    value = float(dValue);
}


template <>
inline void CXMLSerializer::read(double& value)
{
    if( !m_pGroup )
    {
        throw Serializer::CReadFailed();
    }

    tinyxml2::XMLNode *pValue = m_pGroup->FirstChildElement(XMLSerializer::XML_VALUE);
    if( !pValue )
    {
        throw Serializer::CReadFailed();
    }

    if( pValue->ToElement()->QueryDoubleAttribute(XMLSerializer::XML_DOUBLE, &value) != tinyxml2::XML_SUCCESS )
    {
        throw Serializer::CReadFailed();
    }

    m_pGroup->DeleteChild(pValue);
}


template <typename T>
void CXMLSerializer::read(T *pData, tSize Length)
{
//    VPL_STATIC_ASSERT(vpl::CTypeTraits<T>::isFundamental, CANNOT_SERIALIZE_DATA);

    if( !m_pGroup || !pData )
    {
        throw Serializer::CReadFailed();
    }

    tinyxml2::XMLNode *pValue = m_pGroup->FirstChildElement(XMLSerializer::XML_BYTES);
    if( !pValue )
    {
        throw Serializer::CReadFailed();
    }

    int iValue;
    if( pValue->ToElement()->QueryIntAttribute(XMLSerializer::XML_SIZE, &iValue) != tinyxml2::XML_SUCCESS)
    {
        throw Serializer::CReadFailed();
    }

    const tSize valueSize = tSize(sizeof(T)) * 2;
    // Get encoded data
    const char *pcStr = pValue->ToElement()->GetText();
    if (!pcStr || tSize(iValue) != Length || tSize(strlen(pcStr)) != Length * valueSize)
    {
        throw Serializer::CReadFailed();
    }

    // Encode the data
	str2Data(pcStr, pData, Length * tSize(sizeof(T)));

    m_pGroup->DeleteChild(pValue);
}

