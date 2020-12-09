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

#ifndef PARSELOG_H
#define PARSELOG_H

#include <QString>
#include <QStringList>
#include <QList>

class LogEntry
{
public:

    typedef enum
    {
        Invalid  = 0,
        Info     = 1,
        Warning  = 2,
        Error    = 4
    } EntryType;

    typedef enum
    {
        Standard      = 1,
        Verbose       = 2,
        Summary       = 4

    } Detail;

    // Constructors
    LogEntry();
    LogEntry(EntryType type,
                  QString title,
                  QString msg,
                  Detail detail = Standard,
                  int line = -1
                  );

    EntryType type(void) const;
    Detail detail (void) const;
    QString title(void) const;
    QString msg(void) const;
    int line(void) const;
    QString toText(bool verbose = true, char delim = '\t') const;

    void set(EntryType type,
             QString title,
             QString msg,
             Detail detail = Standard,
             int line = -1
             );

    void setRefName(QString to);
    void setMsg(QString to);
    void setLine(int to);

    bool isValid(void) const;
protected:
    void setType(EntryType to);

    EntryType m_type;
    Detail m_detail;
    QString m_refName;
    QString m_msg;
    int m_line;
};




typedef QList <LogEntry> DeltaLogEntries;

class ParseLog
{
public:
    ParseLog();

    static const unsigned FILTER_ALLOWALL = ~0U;
    static const unsigned FILTER_ALLVALIDTYPES =
            ~0U ^ LogEntry::Invalid;
    static const unsigned FILTER_ONLY_ERRORS =
            LogEntry::Error;
    static const unsigned FILTER_ONLY_WARNINGS =
            LogEntry::Warning;

    static const unsigned DETAIL_ALLOW_ALL = ~0U;
    static const unsigned DETAIL_NOTVERBOSE =
            ~0U ^ LogEntry::Verbose;
    static const unsigned DETAIL_VERBOSE =
            ~0U;

    QStringList toStringArray(bool verbose = true,
                          unsigned detailFilter = DETAIL_ALLOW_ALL,
                          unsigned typeFilter = FILTER_ALLOWALL,
                          char delim = '\t') const;

    QString toString(bool verbose = true,
                              unsigned detailFilter = DETAIL_ALLOW_ALL,
                              unsigned typeFilter = FILTER_ALLOWALL,
                              char delim = '\t',
                              char eol = '\n') const;

    void append(LogEntry::EntryType type,
                QString refName,
                QString msg,
                LogEntry::Detail detail = LogEntry::Standard,
                int line = -1
                );

    inline void appendStdWarn(QString refName, QString msg, int line = -1)
    { append(LogEntry::Warning, refName, msg, LogEntry::Standard, line); }

    inline void appendVbsWarn(QString refName, QString msg, int line = -1)
    { append(LogEntry::Warning, refName, msg, LogEntry::Verbose, line); }

    inline void appendStdErr(QString refName, QString msg, int line = -1)
    { append(LogEntry::Error, refName, msg, LogEntry::Standard, line); }

    inline void appendVbsErr(QString refName, QString msg, int line = -1)
    { append(LogEntry::Error, refName, msg, LogEntry::Verbose, line); }

    inline void appendStdInfo(QString refName, QString msg, int line = -1)
    { append(LogEntry::Info, refName, msg, LogEntry::Standard, line); }

    inline void appendVbsInfo(QString refName, QString msg, int line = -1)
    { append(LogEntry::Info, refName, msg, LogEntry::Verbose, line); }

    void clear(void);

protected:
    DeltaLogEntries m_logEntries;
};

#endif // PARSELOG_H
