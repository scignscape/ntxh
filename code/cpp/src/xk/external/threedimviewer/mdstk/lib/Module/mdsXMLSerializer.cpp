//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2008 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2008/09/26                          \n
 *
 * $Id: mdsXMLSerializer.cpp 2091 2012-02-14 11:26:36Z spanel $
 *
 * Description:
 * - XML serialization of objects (data entities) over channels.
 */

#include <MDSTk/Module/mdsXMLSerializer.h>

#ifdef MDS_USE_XML_SERIALIZER

// STL
#include <cstring>


namespace mds
{
namespace mod
{

//==============================================================================
/*
 * Implementation of the CXMLSerializer class.
 */

void CXMLSerializer::findTemplateParameter(std::string& ssClassName, std::string& ssParam)
{
    std::string::size_type i = ssClassName.find('<');
    if( i == std::string::npos )
    {
        return;
    }

    ssParam = ssClassName.substr(i + 1, std::string::npos);
    ssClassName.resize(i);

    i = ssParam.find('>');
    if( i != std::string::npos )
    {
        ssParam.resize(i);
    }
}


//! Auxiliary conversion table (byte -> lower/right character).
const char Byte2CharTable1[] =
    "0123456789ABCDEF"
    "0123456789ABCDEF"
    "0123456789ABCDEF"
    "0123456789ABCDEF"
    "0123456789ABCDEF"
    "0123456789ABCDEF"
    "0123456789ABCDEF"
    "0123456789ABCDEF"
    "0123456789ABCDEF"
    "0123456789ABCDEF"
    "0123456789ABCDEF"
    "0123456789ABCDEF"
    "0123456789ABCDEF"
    "0123456789ABCDEF"
    "0123456789ABCDEF"
    "0123456789ABCDEF";

//! Auxiliary conversion table (byte -> higher/left character).
const char Byte2CharTable2[] =
    "0000000000000000"
    "1111111111111111"
    "2222222222222222"
    "3333333333333333"
    "4444444444444444"
    "5555555555555555"
    "6666666666666666"
    "7777777777777777"
    "8888888888888888"
    "9999999999999999"
    "AAAAAAAAAAAAAAAA"
    "BBBBBBBBBBBBBBBB"
    "CCCCCCCCCCCCCCCC"
    "DDDDDDDDDDDDDDDD"
    "EEEEEEEEEEEEEEEE"
    "FFFFFFFFFFFFFFFF";

//! Auxiliary conversion table (char -> lower part).
const unsigned char Char2ByteTable1[] =
{
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,          // 0-25
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2,          // 25-50
    3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0, 0, 0, 10, 11, 12, 13, 14, 15, 0, 0, 0, 0, 0,    // ...
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0
};

//! Auxiliary conversion table (char -> higher part).
const unsigned char Char2ByteTable2[] =
{
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,          // 0-25
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 32,        // 25-50
    48, 64, 80, 96, 112, 128, 144, 0, 0, 0, 0, 0, 0, 0, 160, 176, 192, 208, 224, 240, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0
};


void CXMLSerializer::data2Str(const void *pData, tSize Length, std::string& ssData)
{
    const unsigned char *pcData = reinterpret_cast<const unsigned char *>(pData);

    ssData.resize(2 * std::string::size_type(Length));

    for( tSize i = 0; i < Length; ++i )
    {
        std::string::size_type Value = std::string::size_type(pcData[i]);
        ssData[2 * i] = Byte2CharTable2[Value];
        ssData[2 * i + 1] = Byte2CharTable1[Value];
    }
}


void CXMLSerializer::str2Data(const char *pcStr, void *pData, tSize Length)
{
    unsigned char *pcData = reinterpret_cast<unsigned char *>(pData);

    for( tSize i = 0; i < Length; ++i )
    {
        pcData[i] = Char2ByteTable2[int(pcStr[2 * i])] + Char2ByteTable1[int(pcStr[2 * i + 1])];
    }
}


//==============================================================================
/*
 * Implementation of the CXMLWriter class.
 */

bool CXMLWriter::VisitEnter(const TiXmlDocument& doc)
{
    if( !TiXmlPrinter::VisitEnter(doc) )
    {
        return false;
    }

    return flush();
}


bool CXMLWriter::VisitExit(const TiXmlDocument& doc)
{
    if( !TiXmlPrinter::VisitExit(doc) )
    {
        return false;
    }

    return flush();
}


bool CXMLWriter::VisitEnter(const TiXmlElement& element, const TiXmlAttribute* firstAttribute)
{
    if( !TiXmlPrinter::VisitEnter(element, firstAttribute) )
    {
        return false;
    }

    return flush();
}


bool CXMLWriter::VisitExit(const TiXmlElement& element)
{
    if( !TiXmlPrinter::VisitExit(element) )
    {
        return false;
    }

    return flush();
}


bool CXMLWriter::Visit(const TiXmlText& text)
{
    if( !TiXmlPrinter::Visit(text) )
    {
        return false;
    }

    return flush();
}


bool CXMLWriter::Visit(const TiXmlDeclaration& declaration)
{
    if( !TiXmlPrinter::Visit(declaration) )
    {
        return false;
    }

    return flush();
}


bool CXMLWriter::Visit(const TiXmlComment& comment)
{
    if( !TiXmlPrinter::Visit(comment) )
    {
        return false;
    }

    return flush();
}


bool CXMLWriter::Visit(const TiXmlUnknown& unknown)
{
    if( !TiXmlPrinter::Visit(unknown) )
    {
        return false;
    }

    return flush();
}


bool CXMLWriter::flush()
{
    if( Size() == 0 )
    {
        return true;
    }

    if( !m_spChannel->write(CStr(), int(Size())) )
    {
        return false;
    }

    const_cast<std::string&>(Str()).clear();
    return true;
}


} // namespace mod
} // namespace mds

#endif // MDS_USE_XML_SERIALIZER

