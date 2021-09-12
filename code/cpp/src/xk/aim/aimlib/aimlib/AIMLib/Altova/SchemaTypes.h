/*
Copyright (c) 2008-2013, Northwestern University
All rights reserved.
 
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
 
  Redistributions of source code must retain the above copyright notice,
  this list of conditions and the following disclaimer.
 
  Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.
 
  Neither the name of the Northwestern University nor the names of its contributors
  may be used to endorse or promote products derived from this software
  without specific prior written permission.
 
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

////////////////////////////////////////////////////////////////////////
//
// SchemaTypes.h
//
// This file was generated by XMLSpy 2012r2sp1 Enterprise Edition.
//
// YOU SHOULD NOT MODIFY THIS FILE, BECAUSE IT WILL BE
// OVERWRITTEN WHEN YOU RE-RUN CODE GENERATION.
//
// Refer to the XMLSpy Documentation for further details.
// http://www.altova.com/xmlspy
//
////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef ALTOVA_SCHEMATYPES_H_INCLUDED
#define ALTOVA_SCHEMATYPES_H_INCLUDED

#include <vector>

#include "StructInfo.h"
#include "xs-datetime.h"

namespace altova
{
	namespace mapforce
	{
		class IMFNode;
	}
	
	class ALTOVA_DECLSPECIFIER QName
	{
		public:
			string_type Uri;
			string_type Prefix;
			string_type LocalName;

			QName() : Uri(_T("")), Prefix(_T("")), LocalName(_T("")) {}
		
			QName(const string_type& uri, const string_type& prefix, const string_type& localname) 
				: Uri(uri), Prefix(prefix), LocalName(localname)
			{}

			QName(const string_type& uri, const string_type& localname) 
				: Uri(uri), Prefix(_T("")), LocalName(localname)
			{
				size_t i = localname.find(_T(":"));
				if (i == string_type::npos)
					return;

				Prefix = localname.substr(0, i);
				LocalName = localname.substr(i+1);
			}

			QName(const string_type& value) 
				: Uri(_T("")), Prefix(_T("")), LocalName(value)
			{
				size_t i = value.find(_T('{'));
				size_t j = value.find(_T('}'));

				if (i == 0 && j > i)
				{
					Uri = value.substr(1, j-1);
					LocalName = value.substr(j+1);
				}
			}
			
			string_type ToString() const { return Prefix.empty() ? LocalName : Prefix + _T(":") + LocalName; }
	};
	
	class ALTOVA_DECLSPECIFIER CoreTypes
	{
	public:		
		static int CastToInt(int i);
		static int CastToInt(unsigned int i);
		static int CastToInt(double d);
		static int CastToInt(const string_type& s);
		static int CastToInt(__int64 i);
		static int CastToInt(unsigned __int64 i);

		static unsigned CastToUInt(int i);
		static unsigned CastToUInt(unsigned int i);
		static unsigned CastToUInt(double d);
		static unsigned CastToUInt(const string_type& s);
		static unsigned CastToUInt(__int64 i);
		static unsigned CastToUInt(unsigned __int64 i);

		static __int64 CastToInt64(int i);
		static __int64 CastToInt64(unsigned int i);
		static __int64 CastToInt64(double d);
		static __int64 CastToInt64(const string_type& s);
		static __int64 CastToInt64(__int64 i);
		static __int64 CastToInt64(unsigned __int64 i);

		static unsigned __int64 CastToUInt64(int i);
		static unsigned __int64 CastToUInt64(unsigned int i);
		static unsigned __int64 CastToUInt64(double d);
		static unsigned __int64 CastToUInt64(const string_type& s);
		static unsigned __int64 CastToUInt64(__int64 i);
		static unsigned __int64 CastToUInt64(unsigned __int64 i);

		static double CastToDouble(int i);
		static double CastToDouble(unsigned i);
		static double CastToDouble(__int64 i);
		static double CastToDouble(unsigned __int64 i);
		static double CastToDouble(double d);
		static double CastToDouble(const string_type& s);

		static string_type CastToString(int i);
		static string_type CastToString(unsigned int i);
		static string_type CastToString(__int64 i);
		static string_type CastToString(unsigned __int64 i);
		static string_type CastToString(double d);
		static string_type CastToString(const string_type& s);
		static string_type CastToString(const char_type* s);
		static string_type CastToString(bool b);
		static string_type CastToString(altova::DateTime dt);
		static string_type CastToString(altova::Duration dur);
		static string_type CastToString(altova::DayTimeDuration dt);
		static string_type CastToString(altova::YearMonthDuration dur);
		static string_type CastToString(const std::vector<unsigned char>& v);
		static string_type CastToString(const altova::QName& qn);
		static altova::QName CastToQName(const string_type& s);
		static altova::QName CastToQName(const altova::QName& qn);

		static string_type FormatBase64(const std::vector<unsigned char>& s);

		enum DateTimeFormat
		{
			/* Format as schema dateTime */
			DateTimeFormat_W3_dateTime,

			/* Format as schema date */
			DateTimeFormat_W3_date,

			/* Format as schema time */
			DateTimeFormat_W3_time,

			/* Format as schema gYear */
			DateTimeFormat_W3_gYear,

			/* Format as schema gYearMonth */
			DateTimeFormat_W3_gYearMonth,

			/* Format as schema gMonth */
			DateTimeFormat_W3_gMonth,

			/* Format as schema gMonthDay */
			DateTimeFormat_W3_gMonthDay,

			/* Format as schema gDay */
			DateTimeFormat_W3_gDay,

			/* Format as standard DateTime "YYYY-MM-DD HH:MM:SS" */
			DateTimeFormat_S_DateTime,

			/* Format as number of seconds since epoch */
			DateTimeFormat_S_Seconds,

			/* Format as number of days since epoch */
			DateTimeFormat_S_Days,
		};

		static string_type CastToString(const altova::DateTime& dt, DateTimeFormat format);
		static altova::DateTime CastToDateTime(const altova::DateTime& dt, DateTimeFormat format);

		static altova::DateTime CastToDateTime(const string_type& s);
		static altova::Duration CastToDuration(const string_type& s);
		static altova::YearMonthDuration CastToYearMonthDuration(const string_type& s);
		static altova::DayTimeDuration CastToDayTimeDuration(const string_type& s);

		static altova::DateTime CastToDateTime(const altova::DateTime& s);
		static altova::Duration CastToDuration(const altova::Duration& s);
		static altova::YearMonthDuration CastToYearMonthDuration(const altova::YearMonthDuration& s);
		static altova::DayTimeDuration CastToDayTimeDuration(const altova::DayTimeDuration& s);

		static bool CastToBool(bool b);
		static bool CastToBool(int i);
		static bool CastToBool(unsigned i);
		static bool CastToBool(__int64 i);
		static bool CastToBool(unsigned __int64 i);
		static bool CastToBool(double d);
		static bool CastToBool(const string_type& s);
		static bool CastToBool(const char_type* s);

		static bool CastToBool(const bool* v);
		static int CastToInt(const int* v);
		static unsigned CastToUInt(const unsigned* v);
		static __int64 CastToInt64(const __int64* v);
		static unsigned __int64 CastToUInt64(const unsigned __int64* v);
		static string_type CastToString(const string_type* v);
		static altova::DateTime CastToDateTime(const altova::DateTime* v);
		static altova::Duration CastToDuration(const altova::Duration* v);
		static double CastToDouble(const double* v);

		static std::vector<unsigned char> CastToBinary(const std::vector<unsigned char>& v);

		enum ParseDateTimeFlags
		{
			ParseDateTimeFlag_RequireYear = (1 << 0),
			ParseDateTimeFlag_RequireMonth = (1 << 1),
			ParseDateTimeFlag_RequireDay = (1 << 2),
			ParseDateTimeFlag_RequireDate = ParseDateTimeFlag_RequireYear|ParseDateTimeFlag_RequireMonth|ParseDateTimeFlag_RequireDay,
			ParseDateTimeFlag_RequireTime = (1 << 3),
			ParseDateTimeFlag_AllowYear = (1 << 4),
			ParseDateTimeFlag_AllowMonth = (1 << 5),
			ParseDateTimeFlag_AllowDay = (1 << 6),
			ParseDateTimeFlag_AllowDate = ParseDateTimeFlag_AllowYear|ParseDateTimeFlag_AllowMonth|ParseDateTimeFlag_AllowDay,
			ParseDateTimeFlag_AllowTime = (1 << 7),
			ParseDateTimeFlag_OptionalTimezoneMinute = (1 << 8),
		};

		// new type system casts
		static altova::DateTime ParseDateTime(const string_type& v) { return CastToDateTime(v); }
		static altova::DateTime ParseDate(const string_type& v) { return CastToDateTime(v); }
		static altova::DateTime ParseTime(const string_type& v) { return CastToDateTime(v); }
		static altova::DateTime ParseTime(const string_type& v, unsigned addendumFlags );
		static altova::DateTime ParseGYear(const string_type& v) { return CastToDateTime(v); }
		static altova::DateTime ParseGYearMonth(const string_type& v) { return CastToDateTime(v); }
		static altova::DateTime ParseGMonth(const string_type& v) { return CastToDateTime(v); }
		static altova::DateTime ParseGMonthDay(const string_type& v) { return CastToDateTime(v); }
		static altova::DateTime ParseGDay(const string_type& v) { return CastToDateTime(v); }
		static altova::Duration ParseDuration(const string_type& v) { return CastToDuration(v); }
		static bool ParseBoolean(const string_type& v) { return CastToBool(v); }
		static double ParseDouble(const string_type& v) { return CastToDouble(v); }
		static string_type DoubleToString(double v) { return CastToString(v); }
		static string_type LongToString(__int64 v) { return CastToString(v); }
		static string_type ULongToString(unsigned __int64 v) { return CastToString(v); }
		static string_type DateTimeToString(const altova::DateTime& v) { return CastToString(v, DateTimeFormat_W3_dateTime);}
		static string_type DateToString(const altova::DateTime& v) { return CastToString(v, DateTimeFormat_W3_date); }
		static string_type TimeToString(const altova::DateTime& v) { return CastToString(v, DateTimeFormat_W3_time); }
		static string_type GYearToString(const altova::DateTime& v) { return CastToString(v, DateTimeFormat_W3_gYear);}
		static string_type GMonthToString(const altova::DateTime& v) { return CastToString(v, DateTimeFormat_W3_gMonth); }
		static string_type GDayToString(const altova::DateTime& v) { return CastToString(v, DateTimeFormat_W3_gDay); }
		static string_type GYearMonthToString(const altova::DateTime& v) { return CastToString(v, DateTimeFormat_W3_gYearMonth); }
		static string_type GMonthDayToString(const altova::DateTime& v) { return CastToString(v, DateTimeFormat_W3_gMonthDay); }
		static string_type DurationToString(const altova::Duration& v) { return CastToString(v); }
		static string_type BinaryToBase64String(const std::vector<unsigned char>& v);
		static const std::vector<unsigned char> ParseBase64Binary(const string_type& v);
		static string_type BinaryToHexString(const std::vector<unsigned char>& v);
		static const std::vector<unsigned char> ParseHexBinary(const string_type& v);
		static string_type BooleanToString(bool v) { return CastToString(v); };
		static __int64 ParseLong(const string_type& v) { return CastToInt64(v); }
		static unsigned __int64 ParseULong(const string_type& v) { return CastToUInt64(v); }
		static __int64 DoubleToLong(double v) { return CastToInt64(v); }
		static unsigned __int64 DoubleToULong(double v) { return CastToUInt64(v); }
		static double LongToDouble(__int64 v) { return CastToDouble(v); }
		static double ULongToDouble(unsigned __int64 v) { return CastToDouble(v); }
		static __int64 ULongToLong(unsigned __int64 v) { return CastToInt64(v); }
		static unsigned __int64 LongToULong(__int64 v) { return CastToUInt64(v); }
		static string_type QNameToString(const altova::QName& v) { return CastToString(v); }
		static altova::QName StringToQName(const string_type& s) { return CastToQName(s); } 
		static bool StringToBoolean(const string_type& v) { return CastToBool(v); }
		static __int64 IntToLong(int v) { return CastToInt64(v); }
		static int LongToInt(__int64 v) { return CastToInt(v); }
		static double BooleanToDouble(bool v) { return CastToDouble(v); }
		static __int64 BooleanToLong(bool v) { return CastToInt64(v); }
		static unsigned __int64 BooleanToULong(bool v) { return CastToUInt64(v); }
		static int BooleanToInt(bool v) { return CastToInt(v);}	
		static bool DoubleToBoolean(double v) { return CastToBool(v); }
		static long GYearToLong(const altova::DateTime& v) { return v.Year(); }


		// helper methods for various formatters
		static void FormatNumber(string_type& result, unsigned value, unsigned minDigits);
		static void FormatTimezone(string_type& result, short value);
		static void FormatFraction(string_type& result, unsigned value, unsigned precision);
		static bool IsNumber(const string_type& str);

		static int* Box(int);
		static bool* Box(bool);
		static unsigned* Box(unsigned);
		static __int64* Box(__int64);
		static unsigned __int64* Box(unsigned __int64);
		static string_type* Box(const string_type&);
		static altova::DateTime* Box(const altova::DateTime&);
		static altova::Duration* Box(const altova::Duration&);
		static double* Box(double);

		static int* Box(int*);
		static bool* Box(bool*);
		static unsigned* Box(unsigned*);
		static __int64* Box(__int64*);
		static unsigned __int64* Box(unsigned __int64*);
		static string_type* Box(string_type*);
		static altova::DateTime* Box(altova::DateTime*);
		static altova::Duration* Box(altova::Duration*);
		static double* Box(double*);

		static int Unbox(int*);
		static bool Unbox(bool*);
		static unsigned Unbox(unsigned*);
		static __int64 Unbox(__int64*);
		static unsigned __int64 Unbox(unsigned __int64*);
		static string_type Unbox(string_type*);
		static altova::DateTime Unbox(altova::DateTime*);
		static altova::Duration Unbox(altova::Duration*);
		static double Unbox(double*);
	};


}






#endif // ALTOVA_SCHEMATYPES_H_INCLUDED
