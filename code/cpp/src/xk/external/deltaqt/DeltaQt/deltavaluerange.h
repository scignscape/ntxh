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

#ifndef DELTAVALUERANGE_H
#define DELTAVALUERANGE_H

#include <QVariant>
#include <QList>
#include <QString>
#include <QHash>

#include "annotatedvalue.h"
#include "delimitedbuffer.h"
#include "parselog.h"


class DeltaValueRange
{
public:
    DeltaValueRange();

    bool isValid(void) const;
    void clear(void);

    bool init(const QString& buff, ParseLog* log);

    QList<AnnotatedValue> getExpandedValueList(void) const;
    QList<int> getExpandedIntList(void) const;

    QString toDeltaString(void) const;

    inline int normalValueCount(void) const { return m_normalValues.count(); }

    inline const AnnotatedValue& at(int idx) const
        { return m_normalValues.at(idx); }

protected:
    bool setPlacemarker(const QString& chunk);
    bool parseRangeChunk(const DelimitedBuffer& chunk,
                         const QString& comment);
    bool parseCompactedChunk(const DelimitedBuffer& chunk,
                             const QString& comment);
    bool parseChunkPart(const QString& chunk, const QString& comment);
    bool parseExtremePart(const QString& chunk, const QString& comment);
private:
    bool m_isInitialised;

    AnnotatedValue m_rangeExtremeLow;
    AnnotatedValue m_rangeExtremeHigh;
    QList<AnnotatedValue> m_normalValues;

    char m_placemarker;
    ParseLog* m_log;
};


#endif // DELTAVALUERANGE_H
