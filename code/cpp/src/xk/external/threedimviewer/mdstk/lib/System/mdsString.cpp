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

#include <MDSTk/System/mdsString.h>

#include <cstdlib>
#include <cstring>
#include <cstdio>


namespace mds
{
namespace sys
{

static const unsigned int utf8_max[] = { 0x7f, 0x7ff, 0xffff, 0x1fffff, 0x3ffffff, 0x7fffffff, 0xffffffff };

//! Boundaries of the private use area we use to (temporarily) remap
//! characters invalid in the UTF-8 encoded strings.
static const unsigned int wxUnicodePUA = 0x100000;
static const unsigned int wxUnicodePUAEnd = wxUnicodePUA + 256;

//! This table gives the length of the UTF-8 encoding from its first character:
static const unsigned char tableUtf8Lengths[256] =
{
    // single-byte sequences (ASCII):
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // 00..0F
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // 10..1F
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // 20..2F
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // 30..3F
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // 40..4F
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // 50..5F
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // 60..6F
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  // 70..7F

    // these are invalid:
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  // 80..8F
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  // 90..9F
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  // A0..AF
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  // B0..BF
    0, 0,                                            // C0,C1

    // two-byte sequences:
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,  // C2..CF
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,  // D0..DF

    // three-byte sequences:
    3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,  // E0..EF

    // four-byte sequences:
    4, 4, 4, 4, 4,                                   // F0..F4

    // these are invalid again (5- or 6-byte
    // sequences and sequences for code points
    // above U+10FFFF, as restricted by RFC 3629):
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0   // F5..FF
};


int tStringConv::encode_utf16(unsigned int input, unsigned short *output)
{
	if (input <= 0xffff)
	{
		if (output)
			*output = (unsigned short) input;

		return 1;
	}
	else if (input >= 0x110000)
	{
		return -1;
	}
	else
	{
		if (output)
		{
			*output++ = (unsigned short) ((input >> 10) + 0xd7c0);
			*output = (unsigned short) ((input & 0x3ff) + 0xdc00);
		}

		return 2;
	}
}


int tStringConv::decode_utf16(const unsigned short* input, unsigned int& output)
{
	if ((*input < 0xd800) || (*input > 0xdfff))
	{
		output = *input;
		return 1;
	}
	else if ((input[1] < 0xdc00) || (input[1] > 0xdfff))
	{
		output = *input;
		return -1;
	}
	else
	{
		output = ((input[0] - 0xd7c0) << 10) + (input[1] - 0xdc00);
		return 2;
	}
}


int tStringConv::utw(wchar_t *dst, int dstLen, const char *src, int srcLen)
{
	wchar_t *out = dstLen ? dst : NULL;
	int written = 0;

	if ( srcLen == -1 )
		srcLen = strlen(src) + 1;

	for ( const char *p = src; ; p++ )
	{
		if ( (srcLen == -1 ? !*p : !srcLen) )
		{
			// all done successfully, just add the trailing NULL if we are not
			// using explicit length
			if ( srcLen == -1 )
			{
				if ( out )
				{
					if ( !dstLen )
						break;

					*out = L'\0';
				}

				written++;
			}

			return written;
		}

		if ( out && !dstLen-- )
			break;

		unsigned int code;
		unsigned char c = *p;

		if ( c < 0x80 )
		{
			if ( srcLen == 0 ) // the test works for wxNO_LEN too
				break;

			if ( srcLen != -1 )
				srcLen--;

			code = c;
		}
		else
		{
			int len = int(tableUtf8Lengths[c]);
			if ( !len )
				break;

			if ( srcLen < len ) // the test works for wxNO_LEN too
				break;

			if ( srcLen != -1 )
				srcLen -= len;

			//   Char. number range   |        UTF-8 octet sequence
			//      (hexadecimal)     |              (binary)
			//  ----------------------+----------------------------------------
			//  0000 0000 - 0000 007F | 0xxxxxxx
			//  0000 0080 - 0000 07FF | 110xxxxx 10xxxxxx
			//  0000 0800 - 0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
			//  0001 0000 - 0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
			//
			//  Code point value is stored in bits marked with 'x',
			//  lowest-order bit of the value on the right side in the diagram
			//  above.                                         (from RFC 3629)

			// mask to extract lead byte's value ('x' bits above), by sequence
			// length:
			static const unsigned char leadValueMask[] = { 0x7F, 0x1F, 0x0F, 0x07 };

			// mask and value of lead byte's most significant bits, by length:
			static const unsigned char leadMarkerMask[] = { 0x80, 0xE0, 0xF0, 0xF8 };
			static const unsigned char leadMarkerVal[] = { 0x00, 0xC0, 0xE0, 0xF0 };

			len--; // it's more convenient to work with 0-based length here

			// extract the lead byte's value bits:
			if ( (c & leadMarkerMask[len]) != leadMarkerVal[len] )
				break;

			code = c & leadValueMask[len];

			// all remaining bytes, if any, are handled in the same way
			// regardless of sequence's length:
			for ( ; len; --len )
			{
				c = *++p;
				if ( (c & 0xC0) != 0x80 )
					return -1;

				code <<= 6;
				code |= c & 0x3F;
			}
		}

#ifdef _WIN32
		// cast is ok because wchar_t == wxUint16 if WC_UTF16
		if ( encode_utf16(code, (unsigned short *)out) == 2 )
		{
			if ( out )
				out++;
			written++;
		}
#else // !WC_UTF16
		if ( out )
			*out = code;
#endif // WC_UTF16/!WC_UTF16

		if ( out )
			out++;

		written++;
	}

	return -1;
}


int tStringConv::wtu(char *dst, int dstLen, const wchar_t *src, int srcLen)
{
	char *out = dstLen ? dst : NULL;
	int written = 0;

	for ( const wchar_t *wp = src; ; wp++ )
	{
		if ( (srcLen == -1 ? !*wp : !srcLen) )
		{
			// all done successfully, just add the trailing NULL if we are not
			// using explicit length
			if ( srcLen == -1 )
			{
				if ( out )
				{
					if ( !dstLen )
						break;

					*out = '\0';
				}

				written++;
			}

			return written;
		}

		if ( srcLen != -1 )
			srcLen--;

		unsigned int code;
#ifdef _WIN32
		// cast is ok for WC_UTF16
		if ( decode_utf16((const unsigned short *)wp, code) == 2 )
		{
			// skip the next char too as we decoded a surrogate
			wp++;
		}
#else // wchar_t is UTF-32
		code = *wp & 0x7fffffff;
#endif

		int len;
		if ( code <= 0x7F )
		{
			len = 1;
			if ( out )
			{
				if ( dstLen < len )
					break;

				out[0] = (char)code;
			}
		}
		else if ( code <= 0x07FF )
		{
			len = 2;
			if ( out )
			{
				if ( dstLen < len )
					break;

				// NB: this line takes 6 least significant bits, encodes them as
				// 10xxxxxx and discards them so that the next byte can be encoded:
				out[1] = 0x80 | (code & 0x3F);  code >>= 6;
				out[0] = 0xC0 | code;
			}
		}
		else if ( code < 0xFFFF )
		{
			len = 3;
			if ( out )
			{
				if ( dstLen < len )
					break;

				out[2] = 0x80 | (code & 0x3F);  code >>= 6;
				out[1] = 0x80 | (code & 0x3F);  code >>= 6;
				out[0] = 0xE0 | code;
			}
		}
		else if ( code <= 0x10FFFF )
		{
			len = 4;
			if ( out )
			{
				if ( dstLen < len )
					break;

				out[3] = 0x80 | (code & 0x3F);  code >>= 6;
				out[2] = 0x80 | (code & 0x3F);  code >>= 6;
				out[1] = 0x80 | (code & 0x3F);  code >>= 6;
				out[0] = 0xF0 | code;
			}
		}
		else
		{
			break;
		}

		if ( out )
		{
			out += len;
			dstLen -= len;
		}

		written += len;
	}

	// we only get here if an error occurs during decoding
	return -1;
}


} // namespace sys
} // namespace mds
