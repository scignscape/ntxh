/*  Copyright 2012 Craig Robbins

    This file is part of DeltaQt

    DeltaQt is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    DeltaQt is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with DeltaQt.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <QDebug>
#include "parselog.h"

LogEntry::LogEntry()
{
    m_type = LogEntry::Invalid;
    m_line = -1;
    m_detail = Verbose;
}

LogEntry::LogEntry(EntryType type,
                             QString refName,
                             QString msg,
                             Detail detail,
                             int line
                             )
{
    set(type, refName, msg, detail, line);
}


LogEntry::EntryType LogEntry::type(void) const
{
    return m_type;
}

LogEntry::Detail LogEntry::detail (void) const
{
    return m_detail;
}

QString LogEntry::title(void) const
{
    return m_refName;
}

QString LogEntry::msg(void) const
{
    return m_msg;
}

int LogEntry::line(void) const
{
    return m_line;
}


QString LogEntry::toText(bool verbose, char delim) const
{
    if (m_type == Invalid) {
        return QString ("ERROR: Invalid log entry");
    }

    QString result;

    switch (m_type)
    {
    case Info:
        result += ("INFO");
        break;
    case Warning:
        result += ("WARNING");
        break;
    case Error:
        result += ("ERROR");
        break;
    default:
        qDebug() << "DeltaLogEntry: Type not dealt with."
                 << __FILE__ << __LINE__;
        break;
    }

    result += QChar(delim);

    if (!m_refName.isEmpty()) {
        result += m_refName;
        result += QChar(delim);
    }
    result += m_msg;

    if (verbose && m_line != -1) {
        result += QChar(delim);
        if (m_line != -1) {
            result += "Line: ";
            result += QString::number(m_line);
        }
    }

    return result;
}

void LogEntry::set(
         EntryType type,
         QString refName,
         QString msg,
         Detail detail,
         int line
         )
{
    m_type = type;
    m_refName = refName;
    m_msg = msg;
    m_detail = detail;
    m_line = line;
}

void LogEntry::setType(EntryType to)
{
    m_type = to;
}

void LogEntry::setRefName(QString to)
{
    m_refName = to;
}

void LogEntry::setMsg(QString to)
{
    m_msg = to;
}

void LogEntry::setLine(int to)
{
    m_line = to;
}

bool LogEntry::isValid(void) const
{
    return m_type != Invalid;
}
/****************************************************************************/



/****************************************************************************/

ParseLog::ParseLog()
{
}

/** @internal
  * Returns a list of all the log messages
  */
QStringList ParseLog::toStringArray(bool verbose,
                                     unsigned detailFilter,
                                     unsigned typeFilter,
                                     char delim) const
{
    QStringList result;

    for (int i = 0; i < m_logEntries.count(); i++) {
        if (m_logEntries[i].isValid()
                && (m_logEntries[i].type() & typeFilter)
                && (m_logEntries[i].detail() & detailFilter))
        {
            result.append(m_logEntries[i].toText(verbose, delim));
        }
    }
    return result;
}

/** @internal
  * Appends the strings returned by toStringArray() into a single string
  */
QString ParseLog::toString(
        bool verbose,
        unsigned detailFilter,
        unsigned typeFilter,
        char delim,
        char eol) const
{
    QString result;
    QStringList items = toStringArray(verbose, detailFilter, typeFilter, delim);

    for (int i = 0; i < items.count(); i++) {
        if (i != 0) result.append(eol);
        result.append(items[i]);
    }
    return result;
}

void ParseLog::append(LogEntry::EntryType type,
                   QString refName,
                   QString msg,
                   LogEntry::Detail detail,
                   int line
                   )
{
    m_logEntries.append(LogEntry(type, refName, msg, detail, line));
}

void ParseLog::clear(void)
{
    m_logEntries.clear();
}


