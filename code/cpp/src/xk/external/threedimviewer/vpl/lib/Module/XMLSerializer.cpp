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
 * Author:  Michal Spanel, spanel@fit.vutbr.cz
 * Date:    2008/09/26                       
 *
 * Description:
 * - XML serialization of objects (data entities) over channels.
 */

#include <VPL/Module/XMLSerializer.h>

#ifdef VPL_USE_XML_SERIALIZER

namespace vpl
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
const char byte2CharTable1[] =
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
const char byte2CharTable2[] =
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
const unsigned char char2ByteTable1[] =
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
const unsigned char char2ByteTable2[] =
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


void CXMLSerializer::data2Str(const void *pData, const tSize length, std::string& ssData)
{
    const unsigned char *pcData = reinterpret_cast<const unsigned char *>(pData);

    ssData.resize(2 * std::string::size_type(length));

    for( tSize i = 0; i < length; ++i )
    {
        const std::string::size_type value = std::string::size_type(pcData[i]);
        ssData[2 * i] = byte2CharTable2[value];
        ssData[2 * i + 1] = byte2CharTable1[value];
    }
}


void CXMLSerializer::str2Data(const char *pcStr, void *pData, const tSize length)
{
    unsigned char *pcData = reinterpret_cast<unsigned char *>(pData);

    for( tSize i = 0; i < length; ++i )
    {
        pcData[i] = char2ByteTable2[int(pcStr[2 * i])] + char2ByteTable1[int(pcStr[2 * i + 1])];
    }
}


//==============================================================================
/*
 * Implementation of the CXMLWriter class.
 */

bool CXMLWriter::VisitEnter(const tinyxml2::XMLDocument& doc)
{
    if( !XMLPrinter::VisitEnter(doc) )
    {
        return false;
    }

    return flush();
}


bool CXMLWriter::VisitExit(const tinyxml2::XMLDocument& doc)
{
    if( !XMLPrinter::VisitExit(doc) )
    {
        return false;
    }

    return flush();
}


bool CXMLWriter::VisitEnter(const tinyxml2::XMLElement& element, const tinyxml2::XMLAttribute* firstAttribute)
{
    if( !XMLPrinter::VisitEnter(element, firstAttribute) )
    {
        return false;
    }

    return flush();
}


bool CXMLWriter::VisitExit(const tinyxml2::XMLElement& element)
{
    if( !XMLPrinter::VisitExit(element) )
    {
        return false;
    }
    return flush();
}


bool CXMLWriter::Visit(const tinyxml2::XMLText& text)
{
    if( !XMLPrinter::Visit(text) )
    {
        return false;
    }

    return flush();
}


bool CXMLWriter::Visit(const tinyxml2::XMLDeclaration& declaration)
{
    if( !XMLPrinter::Visit(declaration) )
    {
        return false;
    }

    return flush();
}


bool CXMLWriter::Visit(const tinyxml2::XMLComment& comment)
{
    if( !XMLPrinter::Visit(comment) )
    {
        return false;
    }

    return flush();
}


bool CXMLWriter::Visit(const tinyxml2::XMLUnknown& unknown)
{
    if( !XMLPrinter::Visit(unknown) )
    {
        return false;
    }

    return flush();
}


bool CXMLWriter::flush() 
{
    if(CStrSize() == 0 )
    {
        return true;
    }
    bool ret = m_spChannel->write(CStr(), tSize(CStrSize()-1));

    //! Issue with indentation, which is broken. It is caused by tinyXML2 function:
    //!     void ClearBuffer() {
    //!         _buffer.Clear();
    //!         _buffer.Push(0);
    //!         _firstElement = true; }
    //! Where this function also set _firstElement on true.
    //! Patch for this is new function in tinyXML2. These function is nearby function ClearBuffer() in class XMLPrinter.
    //!     void VPLClearBuffer() {
    //!         _buffer.Clear();
    //!         _buffer.Push(0); }
    //! When you have patched tinyXML2 enable VPL_USE_TINYXML2_WITH_INDENT_PATCH in cmake option.

#ifdef USE_TINYXML2_WITH_INDENT_PATCH
    VPLClearBuffer();
#else
    ClearBuffer();
#endif

    return ret;
}


} // namespace mod
} // namespace vpl

#endif // VPL_USE_XML_SERIALIZER

