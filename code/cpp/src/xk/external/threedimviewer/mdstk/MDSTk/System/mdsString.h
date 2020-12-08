//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2012 3Dim Laboratory s.r.o.    \n
 *
 * Author:  info@3dim-laboratory.cz				\n
 * Date:    2011/01/17                          \n
 *
 * $Id:$
 *
 * Description:
 * - Multi-platform Unicode string.
 */

#ifndef MDS_String_H
#define MDS_String_H

#include <MDSTk/Base/mdsData.h>

// STL
#include <string>
#include <cstdlib>
#include <cstring>
#include <cstdio>

#ifdef _WIN32
#   include <wchar.h>
#endif // _WIN32


namespace mds
{
namespace sys
{

//==============================================================================
/*
 * String able to encode Unicode filename.
 */

// Windows version (wchar_t encoding)
#ifdef _WIN32
    //! Single character (char type on Linux, wchar_t on windows).
    typedef wchar_t         tChar;
	
    //! STL-based string able to represent Unicode filename (std::string on Linux, std::wstring on windows).
    typedef std::wstring    tString;

    //! Helper macro used to declare a string literal.
    #define mdsT(s)         L##s
#endif // _WIN32


// Linux version (utf8 encoding)
#ifdef _LINUX
    //! Single character (char type on Linux, wchar_t on windows).
	typedef char            tChar;
	
    //! STL-based string able to represent Unicode filename (std::string on Linux, std::wstring on windows).
    typedef std::string     tString;
    
    //! Helper macro used to declare a string literal.
    #define mdsT(s)         s
#endif // _LINUX


//==============================================================================
/*!
 * Class providing functions to convert between various string encodings.
 */
class tStringConv
{
public:
    //! Converts MDSTk string to the UTF8 encoding.
	static std::string toUtf8(const tString &str)
	{
#ifdef _WIN32
        return WCharToUtf8(str);
#else
        return str;
#endif
	}

    //! Converts MDSTk string to the std::wstring encoding.
	static std::wstring toWChar(const tString &str)
	{
#ifdef _WIN32
        return str;
#else
        return Utf8ToWChar(str);
#endif
	}

    //! Converts UTF8 string to the MDSTk string.
	static tString fromUtf8(const std::string &str)
	{
#ifdef _WIN32
        return Utf8ToWChar(str);
#else
        return str;
#endif
	}

    //! Converts std::wstring to the MDSTk string.
	static tString fromWChar(const std::wstring &str)
	{
#ifdef _WIN32
        return str;
#else
        return WCharToUtf8(str);
#endif
	}

    //! Converts std::wstring to the UTF8 string.
	static std::string WCharToUtf8(const std::wstring &str)
	{
        typedef mds::base::CData<char> tCharBuffer;

        size_t newsize = wtu(NULL, 0, str.c_str(), str.length());
        tCharBuffer newstring(mds::tSize(newsize + 1));
		newstring.at(newsize) = '\0';

		if (wtu(newstring.getPtr(), newsize, str.c_str(), str.length()) != -1)
		{
            return std::string(newstring.getPtr());
		}

		return std::string();
	}

    //! Converts UTF8 string to the std::wstring.
	static std::wstring Utf8ToWChar(const std::string &str)
	{
        typedef mds::base::CData<wchar_t> tWCharBuffer;

        size_t newsize = utw(NULL, 0, str.c_str(), str.length());
        tWCharBuffer newstring(mds::tSize(newsize + 1));
		newstring.at(newsize) = '\0';

        if (utw(newstring.getPtr(), newsize, str.c_str(), str.length()) != -1)
		{
			return std::wstring(newstring.getPtr());
		}
		
		return std::wstring();
	}

private:
	//! ?
//    static size_t encode_utf16(unsigned int input, unsigned short *output);
	static int encode_utf16(unsigned int input, unsigned short *output);

    //! ?
//    static size_t decode_utf16(const unsigned short* input, unsigned int& output);
	static int decode_utf16(const unsigned short* input, unsigned int& output);

	//! ?
//	static size_t utw(wchar_t *dst, size_t dstLen, const char *src, size_t srcLen);
	static int utw(wchar_t *dst, int dstLen, const char *src, int srcLen);

	//! ?
//	static size_t wtu(char *dst, size_t dstLen, const wchar_t *src, size_t srcLen);
    static int wtu(char *dst, int dstLen, const wchar_t *src, int srcLen);
};


//==============================================================================
/*
 * Global functions.
 */

//! Unicode alternative to the common fopen() function.
//! - The parameter filename is a Unicode string.
inline FILE *fopenU(tString filename, tString mode)
{
#ifdef _WIN32
	return _wfopen(filename.c_str(), mode.c_str());
#endif // _WIN32

#ifdef _LINUX
	return fopen(filename.c_str(), mode.c_str());
#endif // _LINUX
}


} // namespace sys
} // namespace mds

#endif // MDS_String_H
