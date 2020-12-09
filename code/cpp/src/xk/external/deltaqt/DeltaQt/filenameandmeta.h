/*  Copyright 2012 Craig Robbins

    This file is part of DeltaQt.

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

#ifndef FILENAMEANDMETA_H
#define FILENAMEANDMETA_H

#include <QString>
#include <QTextCodec>

class FilenameAndMeta
{
public:

    FilenameAndMeta()
        { setCodec("Windows-1252"); }

    FilenameAndMeta(const QString& fname, const QString& codecName)
        { m_filename = fname; setCodec(codecName); }

    inline QString filename(void) const
        { return m_filename; }

    inline QString codecName(void) const
        { return m_codecName; }

    inline const QTextCodec* codec(void) const
        { return m_codec; }

    inline void setFilename(const QString& filename)
        { m_filename = filename; }

    inline void setCodec(const QString& codecName)
        {
            m_codecName = codecName;
//            m_codec = QTextCodec::codecForName(codecName.toAscii());
//? now its ...
            m_codec = QTextCodec::codecForName(codecName.toLatin1());
        }

private:
    QString m_filename;
    QString m_codecName;
    const QTextCodec* m_codec;
};

#endif // FILENAMEANDMETA_H
