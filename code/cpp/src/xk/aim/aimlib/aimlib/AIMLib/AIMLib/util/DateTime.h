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

/*
These are simple classes to represent date and time.
It's assumed that the values are in the UTC form.
*/
#if !defined(_AIMLib_DATE_TIME_INCLUDED_)
#define _AIMLib_DATE_TIME_INCLUDED_

#include <ctime>
#include <string>

namespace aim_lib
{

	// Date
	class AIMLIB_API Date
	{
	public:
		explicit Date(int year = 1, int month = 1, int day = 1);
		Date(const Date& date);
		explicit Date(const time_t& t);
		explicit Date(const std::string& dicomDate);
		~Date();
		bool operator==(const Date& dateIn) const;
		bool operator!=(const Date& dateIn) const;

		int GetYear() const;
		int GetMonth() const;
		int GetDay() const;

		void SetYear(int year);
		void SetMonth(int month);
		void SetDay(int day);

		bool IsEmpty() const;

		static Date Today();
		std::string GetDicomFormatedDate() const;

	private:
		int _year;
		int _month; // [1, 12]
		int _day; // [1, 31]
	};

	// DateTime
	class AIMLIB_API DateTime
	{
	public:
		explicit DateTime(int year = 1, int month = 1, int day = 1, int hour = 0, int minute = 0, double second = 0.0);
		DateTime(const DateTime& dateTime);
		explicit DateTime(const time_t& t);
		explicit DateTime(const std::string& dicomDateTime);
		~DateTime(void);
		bool operator==(const DateTime& dateTimeIn) const;
		bool operator!=(const DateTime& dateTimeIn) const;

		int GetYear() const;
		int GetMonth() const;
		int GetDay() const;
		int GetHour() const;
		int GetMinute() const;
		double GetSecond() const;
		const Date& GetDate() const;

		void SetYear(int year);
		void SetMonth(int month);
		void SetDay(int day);
		void SetHour(int hour);
		void SetMinute(int minute);
		void SetSecond(double second);

		bool IsEmpty() const;

		static DateTime Now();
		std::string GetDicomFormatedDateTime() const;

	private:
		aim_lib::Date _date;
		int _hour; // [0, 23]
		int _min; // [0, 59]
		double _second; // [0.0, 59.999999]
	};


	// Time
	class AIMLIB_API Time
	{
	public:
		explicit Time(int hour = 0, int minute = 0, double second = 0.0);
		Time(const Time& time);
		explicit Time(const time_t& t);
		explicit Time(const std::string& dicomDateTime);
		~Time(void);
		bool operator==(const Time& timeIn) const;
		bool operator!=(const Time& timeIn) const;

		int GetHour() const;
		int GetMinute() const;
		double GetSecond() const;

		void SetHour(int hour);
		void SetMinute(int minute);
		void SetSecond(double second);

		bool IsEmpty() const;

		static Time Now();
		std::string GetDicomFormatedTime() const;

	private:
		int _hour; // [0, 23]
		int _min; // [0, 59]
		double _second; // [0.0, 59.999999]
	};
}
#endif // _AIMLib_DATE_TIME_INCLUDED_