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

#include <VPL/Base/LogLayout.h>
#include <iomanip> 

/**
 * Writes a record to the stream.
 *
 * \param	lr			  	The log record.
 * \param [in,out]	stream	The stream.
 * \param	addEndl		  	true if to add endl.
**/
void vpl::base::CLogLayoutBase::writeRecord( const CLogRecord &lr, std::ostream &stream, bool addEndl /*= true*/ )
{
	if(stream)
	{ 
		stream << lr.getMessage(); 
		if(addEndl) 
			stream << std::endl;
	}
}

/**
 * @brief   Writes a record level in the string format to the output stream.
 *
 * @param   lr              The lr.
 * @param [in,out]  stream  The stream.
 */

void vpl::base::CLogLayoutBase::writeLevel(const CLogRecord &lr, std::ostream &stream, bool bUpperCase)
{
    if(bUpperCase)
    {
        switch(lr.getLevel())
        {
        case LL_TRACE: stream << "TRACE"; break;
        case LL_DEBUG: stream << "DEBUG"; break;
        case LL_INFO:  stream << "INFO"; break;
        case LL_WARN:  stream << "WARNING"; break;
        case LL_ERROR: stream << "ERROR"; break;
        case LL_FATAL: stream << "FATAL"; break;
        default:
            stream << "UNKNOWN LEVEL";
        }
    }
    else
    {
        switch(lr.getLevel())
        {
        case LL_TRACE: stream << "trace"; break;
        case LL_DEBUG: stream << "debug"; break;
        case LL_INFO:  stream << "info"; break;
        case LL_WARN:  stream << "warning"; break;
        case LL_ERROR: stream << "error"; break;
        case LL_FATAL: stream << "fatal"; break;
        default:
            stream << "UNKNOWN LEVEL";
        }
    }
}

/**
 * Constructor.
 *
 * \param	bUseId			Identifier of the record.
 * \param	bUseDate		Should be date information be used.
 * \param	bUseTime		Should be time information be used.
 * \param	bUseFileLine	Should be file and line information be used.
**/
vpl::base::CLogLayoutSimple::CLogLayoutSimple( bool bUseId /*= false*/, bool bUseDate /*= false*/, bool bUseTime /*= true*/, bool bUseFileLine /*= true*/ )
	: m_bUseId(bUseId)
	, m_bUseDate(bUseDate)
	, m_bUseTime(bUseTime)
	, m_bUseFileLine(bUseFileLine)
{

}

/**
 * Writes a record to the output stream.
 *
 * \param	lr			  	The log record.
 * \param [in,out]	stream	The stream.
**/
void vpl::base::CLogLayoutSimple::writeRecord( const CLogRecord &lr, std::ostream &stream, bool addEndl /*= true*/ )
{

	{
		if(!stream)
			return;

        // No decorations for raw record
        if(!lr.isRaw())
        {
            unsigned int year, month, dow, day, hour, minute, second, milliseconds;
            lr.getTime(year, month, dow, day, hour, minute, second, milliseconds);

            if(m_bUseId)
                stream << "[" << lr.getId() << "] ";
            if(m_bUseDate)
            {
                stream << "[" << year << "-" << month << "-" << day;
                if(m_bUseTime)
                    stream << " ";
                else
                    stream << "]";
            }
            if(m_bUseTime)
            {
                if(!m_bUseDate)
                    stream << "[";

                stream << hour << ":" << minute << ":" << second << "] ";
            }

            stream << "[";
            writeLevel(lr, stream, true);
            stream << "] ";

            if(m_bUseFileLine)
                stream << "[" << lr.getFileName() << ":" << lr.getLineNumber() << "] ";
        }

		stream << "[thread ID: " << lr.getThreadId() << "] ";

		stream << lr.getMessage();

		if(addEndl)
			stream << std::endl;
	}
}

/**
 * @brief   Writes a record.
 *
 * @param   lr              The log record.
 * @param [in,out]  stream  The output stream.
 * @param   addEndl         true to add endl on the end of log record.
 */
void vpl::base::CLogLayoutFormatted::writeRecord(const CLogRecord &lr, std::ostream &stream, bool addEndl /*= true*/)
{
    // No formating for raw messages
    if(lr.isRaw())
    {
        stream << lr.getMessage();
        if(addEndl) 
            stream << std::endl;
        return;
    }

    if(m_format.size() == 0)
        return;

    EFormatParseState state(FPS_NORMAL);

    std::string::const_iterator itf(m_format.begin()), itfEnd(m_format.end());
    for(; itf != itfEnd; ++itf)
    {
        
        const int c(*itf), u(toupper(*itf));

        switch (state)
        {
        case FPS_NORMAL:
            if(c == '%')
                state = FPS_COMMAND;
            else
            {
                stream << char(c);
            }
        	break;

        case FPS_COMMAND:
            {
                switch(u)
                {
                case '%':
                    stream << '%';
                    break;

                case 'T':
                    writeTime(lr, stream);
                    state = FPS_NORMAL;
                    break;

                case 'D':
                    writeDate(lr, stream);
                    state = FPS_NORMAL;
                    break;

                case 'M':
                    stream << lr.getMessage();
                    state = FPS_NORMAL;
                    break;

                case 'C':
                    stream << lr.getCategory();
                    state = FPS_NORMAL;
                    break;

                case 'H':
                    stream << lr.getThreadId();
                    state = FPS_NORMAL;
                    break;

                case 'N':
                    stream << std::endl;
                    state = FPS_NORMAL;
                    break;

                case 'G':
                    stream << lr.getTag();
                    state = FPS_NORMAL;
                    break;

                case 'S':
                    writeLevel(lr, stream, c == 'S');
                    state = FPS_NORMAL;
                    break;

                case 'F':
                    stream << lr.getFileName();
                    state = FPS_NORMAL;
                    break;

                case 'L':
                    stream << lr.getLineNumber();
                    state = FPS_NORMAL;
                    break;

                case 'E':
                    stream << lr.getLevel();
                    state = FPS_NORMAL;
                    break;

                case 'I':
                    stream << lr.getId();
                    state = FPS_NORMAL;
                    break;

                default:
                    #ifdef __APPLE__ 
                        stream << "[LOGGING ERROR: LogLayoutFormatted - Unknown format option '%" << c << "'" << "]" << std::endl; 
                    #else 
                        stream << "[LOGGING ERROR: LogLayoutFormatted - Unknown format option '%" << c << "' on format string position " << std::distance<std::string::const_iterator>(m_format.begin(), itf) << "]" << std::endl; 
                    #endif 
                    state = FPS_NORMAL;
                    break;                 
                }  // switch u
            } // case FPS_COMMAND
            break;

        default:
            ;
        } // switch state
    } // for all elements in the format string

    if (addEndl)
        stream << std::endl;
}

/**
 * @brief   Writes a time.
 *
 * @param   lr              The lr.
 * @param [in,out]  stream  The stream.
 */

void vpl::base::CLogLayoutFormatted::writeTime(const CLogRecord &lr, std::ostream &stream)
{
    if(m_timeFormat.size() == 0)
        return;

    // Get current date and time values
    unsigned int year, month, dow, day, hour, minute, second, milliseconds;
    lr.getTime(year, month, dow, day, hour, minute, second, milliseconds);

    EFormatParseState state(FPS_NORMAL);

    std::string::const_iterator itf(m_timeFormat.begin()), itfEnd(m_timeFormat.end());
    for(; itf != itfEnd; ++itf)
    {
        const int c(*itf), u(toupper(*itf));

        switch (state)
        {
        case FPS_NORMAL:
            if(c == '%')
                state = FPS_COMMAND;
            else
            {
                stream << char(c);
            }
            break;

        case FPS_COMMAND:
            switch(u)
            {
            case '%':
                stream << '%';
                break;

            case 'H':
                stream << std::setw(2) << std::setfill('0') << hour;
                state = FPS_NORMAL;
                break;

            case 'M':
                stream << std::setw(2) << std::setfill('0') << minute;
                state = FPS_NORMAL;
                break;

            case 'S':
                stream << std::setw(2) << std::setfill('0') << second;
                state = FPS_NORMAL;
                break;

            case 'I':
                stream << std::setw(3) << std::setfill('0') << milliseconds;
                state = FPS_NORMAL;
                break;

            default:
                state = FPS_NORMAL;
                ;
            }

        default:
            ;
        }
    }
}

/**
 * @brief   Writes a date.
 *
 * @param   lr              The lr.
 * @param [in,out]  stream  The stream.
 */

void vpl::base::CLogLayoutFormatted::writeDate(const CLogRecord &lr, std::ostream &stream)
{
    if(m_dateFormat.size() == 0)
        return;

    // Get current date and time values
    unsigned int year, month, dow, day, hour, minute, second, milliseconds;
    lr.getTime(year, month, dow, day, hour, minute, second, milliseconds);

    EFormatParseState state(FPS_NORMAL);

    std::string::const_iterator itf(m_dateFormat.begin()), itfEnd(m_dateFormat.end());
    for(; itf != itfEnd; ++itf)
    {
        const int c(*itf), u(toupper(*itf));

        switch (state)
        {
        case FPS_NORMAL:
            if(c == '%')
                state = FPS_COMMAND;
            else
            {
                stream << char(c);
            }
            break;

        case FPS_COMMAND:
            switch(u)
            {
            case '%':
                stream << '%';
                break;

            case 'D':
                stream << std::setw(2) << std::setfill('0') << day;
                state = FPS_NORMAL;
                break;

            case 'M':
                stream << std::setw(2) << std::setfill('0') << month;
                state = FPS_NORMAL;
                break;

            case 'Y':
                stream << std::setw(2) << std::setfill('0') << year;
                state = FPS_NORMAL;
                break;

            default:
                state = FPS_NORMAL;
                ;
            }

        default:
            ;
        }
    }
}


/**
 * @brief   Sets the default strings.
 */
void vpl::base::CLogLayoutFormatted::setDefaultStrings()
{
    m_format = "[%i] %d %t %f : %l %m";
    m_dateFormat = "%y-%m-%d";
    m_timeFormat = "%h:%m:%s:%i";
}
