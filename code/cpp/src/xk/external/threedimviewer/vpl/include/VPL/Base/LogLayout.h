//==============================================================================
/* This file is part of
 *
 * VPL - Voxel Processing Library
 * Copyright 2014 3Dim Laboratory s.r.o.
 * All rights reserved.
 * 
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef VPL_LogLayout_H
#define VPL_LogLayout_H

#include "LogRecord.h"
#include "SharedPtr.h"
#include <iostream>

namespace vpl
{
namespace base
{

/**
 * Log layout interface declaration. 
 *
 * Layout defines graphical representation of information in the output medium (see http://en.wikipedia.org/wiki/Page_layout).
 * Layout classes transform log records (information) into the text form (output stored by log appenders). 
 * Every log appender uses one and only layout class (see CLogLayout::setLayout method).
 * CLogLayoutBase is (as expected) base class of all layout classes. It defines common interface.
**/
class CLogLayoutBase : public CObject
{
public:
	VPL_SHAREDPTR(CLogLayoutBase);

public:
	//! Parse input record and write to the output stream
	virtual void writeRecord(const CLogRecord &lr, std::ostream &stream, bool addEndl = true);

	//! Write level in string format
	virtual void writeLevel(const CLogRecord &lr, std::ostream &stream, bool bUpperCase);
};

typedef CLogLayoutBase::tSmartPtr CLogLayoutBasePtr;

/**
 * Log layout simple version. 
 *
 * Simple to use layout class. Its output is driven by switches. Every switch only enables/disables
 * writing part of log information into the output. Internal arrangement cannot be modified.
**/
class CLogLayoutSimple : public CLogLayoutBase
{
public:
	VPL_SHAREDPTR(CLogLayoutSimple);

public:
	//! Constructor
	CLogLayoutSimple(bool bUseId = false, bool bUseDate = false, bool bUseTime = true, bool bUseFileLine = true);

	//! Parse input record and write to the output stream
	virtual void writeRecord(const CLogRecord &lr, std::ostream &stream, bool addEndl = true);

    //! Set logging parameters
    void setParameters(bool bUseId, bool bUseDate, bool bUseTime, bool bUseFileLine)
    {
        m_bUseId = bUseId; m_bUseDate = bUseDate; m_bUseTime = bUseTime; m_bUseFileLine = bUseFileLine;
    }

    //! Use ID parameter?
    void useId(bool bUse) { m_bUseId = bUse; }

    //! Use date parameter?
    void useDate(bool bUse) { m_bUseDate = bUse; }

    //! Use time parameter?
    void useTime(bool bUse) { m_bUseTime = bUse; }

    //! Use file and line parameters?
    void useFileLine(bool bUse) { m_bUseFileLine = bUse; }

protected:
	//! Write record id to the log?
	bool m_bUseId;

	//! Write record date to the log?
	bool m_bUseDate;

	//! Write record time to the log?
	bool m_bUseTime;

	//! Write record file and line information to the log?
	bool m_bUseFileLine;
};

typedef CLogLayoutSimple::tSmartPtr CLogLayoutSimplePtr;

/**
 * @brief   Log layout formatted.
 *
 * The most modifiable version of layout class. Output is driven by format string.
 * Format string is composited from text and commands. Every command is separated by '%' character.
 * Possible commands are:
 *
 *      %       - writes '%' into the output. 
 *      T       - write time
 *      D       - write date
 *      M       - write log record message (CLogRecord::getMessage)
 *      C       - write category
 *      H       - write thread id
 *      N       - new line
 *      G       - write tag (CLogRecord::getTag)
 *      S       - write level in the string form 
 *      F       - write file name (CLogRecord::getFileName)
 *      L       - write line number (CLogRecord::getLineNumber)
 *      E       - write level in the numerical form
 *      I       - write log record id number
 *
 * The default is: 
 * "[%i] %d %t %f : %l %m"
 * This leads to something like this (just an example):
 * [13] 17-11-2014 10:20 CLogLayout.h : 120 This is log message body example.
 *
 * Time format can be modified by setting time format string (use setTimeFormat method). 
 * As usual all commands are started by '%' character. Possible commands are:
 *
 *      %       - write '%' int the output
 *      H       - write hour
 *      M       - write minute
 *      S       - write second
 *      I       - write milliseconds if possible on current platform
 *
 * The default is:
 * "%h:%m:%s:%i"
 * This leads to:
 * 10:20:33:720
 *
 * Date format can be changed by setting the date format string (use setDateFormat method). Commands are 
 * separated by '%' character. Possible commands are:
 * 
 *      %       - write '%' int the output
 *      Y       - write year
 *      M       - write month
 *      D       - write day
 *
 * The default is:
 * "%y-%m-%d"
 * This leads to:
 * 17-11-2014
 */

class CLogLayoutFormatted : public CLogLayoutBase
{
public:
    VPL_SHAREDPTR(CLogLayoutFormatted);

    //! Simple constructor
    CLogLayoutFormatted() : m_format("") {}

    //! Constructor with format string
    CLogLayoutFormatted(const std::string &format) : m_format(format) {}

    //! Parse input record and write to the output stream
    virtual void writeRecord(const CLogRecord &lr, std::ostream &stream, bool addEndl = true);

    //! Set default strings
    virtual void setDefaultStrings();

    //! Set time format string
    virtual void setTimeFormat(const std::string &format) {m_timeFormat = format;}

    //! Set date format string
    virtual void setDateFormat(const std::string &format) {m_dateFormat = format;}

    //! Set log layout format string
    virtual void setFormatString(const std::string &format) {m_format = format;}

protected:
    //! Write time
    virtual void writeTime(const CLogRecord &lr, std::ostream &stream);

    //! Write date
    virtual void writeDate(const CLogRecord &lr, std::ostream &stream);

protected:
    //! Parsing automata states
    enum EFormatParseState
    {
        FPS_NORMAL,
        FPS_COMMAND
    };

protected:
    //! Format string
    std::string m_format;

    //! Time format string
    std::string m_timeFormat;

    //! Date format string
    std::string m_dateFormat;

}; // class CLogLayoutFormatted

typedef CLogLayoutFormatted::tSmartPtr CLogLayoutFormattedPtr;

}
}

#endif // VPL_LogLayout_H

