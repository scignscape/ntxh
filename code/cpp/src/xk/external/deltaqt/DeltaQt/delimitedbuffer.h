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

#ifndef DELIMITEDTEXT_H
#define DELIMITEDTEXT_H

#include <QString>
#include <QList>
#include <QChar>
#include <QString>
#include <QStringList>

class DelimPairBoundary
{
public:
    DelimPairBoundary();
    DelimPairBoundary(int level,
                      int indexStart,
                      int indexEnd);

    int level(void) const
    { return m_level; }

    int indexStart(void) const
    { return m_indexStart; }

    int indexEnd(void) const
    { return m_indexEnd; }

protected:
    int m_level;
    int m_indexStart;
    int m_indexEnd;
    int m_indexStartLineNum;
};


typedef QList<DelimPairBoundary>DelimPairBoundaries;


class DelimitedBuffer : public QString
{
public:
    typedef enum {
        MAP_NOTINITIALISED,
        MAP_OK,
        MAP_ERROR_UNBALANCED_DELIMS,
        MAP_ERROR_SPLIT_EXCEPT_INVALID_DELIM
    } MapStatus;


    /*
     * CONSTRUCTORS
     */
    DelimitedBuffer();
    DelimitedBuffer(QString& other);
    DelimitedBuffer(const char* str);
    DelimitedBuffer(const QString& other);

    DelimitedBuffer(
            const char* str,
            char startDelim,
            char endDelim,
            QString legalPreChars = QString(),
            QString legalPostChars = QString());

    DelimitedBuffer(
            const QString& other,
            char startDelim,
            char endDelim,
            QString legalPreChars = QString(),
            QString legalPostChars = QString());

    /*
     *  NON-MAPPING FUNCTIONS
     */
    bool isMapped(void) const;
    bool indexIsBetweenDelims(int idx) const;
    int numLevels(void) const;
    DelimPairBoundaries getChunkBoundaries(void) const;
    void clear();
    DelimitedBuffer noWhitespace(void) const;

    QString getChunk(DelimPairBoundary boundary) const;
    QString getChunk(int startPos, int endPos = -1) const;

    QStringList getChunkStrings(
            int minLevel = -1,
            int maxLevel = -1
            ) const;

    QString getStringsAppended(
            QChar delimWith,
            int minLevel = -1,
            int maxLevel = -1,
            bool simplify = true
            ) const;

    QString getLevel1Comments(void) const;

    DelimitedBuffer::MapStatus status(void) const;

    /*
     * MAPPING FUNCTIONS
     */
    bool initMap(
              QChar startDelim,
              QChar endDelim,
              QString legalPreChars = QString(),
              QString legalPostChars = QString());

    bool mapDelimBoundaries(
            QChar startDelim,
            QChar endDelim,
            QString legalPreChars = QString(),
            QString legalPostChars = QString());

    bool mapDelimBoundaries_EqDelims(
            QChar delim,
            QString legalPreChars = QString(),
            QString legalPostChars = QString());

    bool getTokens(
            QList<QString>* dest,
            char searchChar,
            QChar startDelim,
            QChar endDelim,
            QString legalPreChars = QString(),
            QString legalPostChars = QString(),
            bool splitOnPreIsSpace = false,
            bool splitOnPostIsSpace = false,
            bool removeSearchCharFromStart = false
            );
    /*
     * Operator overloads
     */
    QString operator =(const QString& other) {
        m_status = MAP_NOTINITIALISED;
        m_delimBoundaries.clear();
        return QString::operator =(other);
    }
    QString operator =(const char* other) {
        m_status = MAP_NOTINITIALISED;
        m_delimBoundaries.clear();
        return QString::operator =(other);
    }

    bool preCharOk(QChar c, QString legalPreChars);
    inline bool postCharOk(QChar c, QString legalPostChars)
    { return preCharOk(c, legalPostChars); }

private:

    QVector<int> findCharPositionsExcept(
            char searchChar,
            QChar startDelim,
            QChar endDelim,
            QString legalPreChars = QString(),
            QString legalPostChars = QString(),
            bool splitOnPreIsSpace = false,
            bool splitOnPostIsSpace = false
            );

    MapStatus m_status;
    DelimPairBoundaries m_delimBoundaries;

};

#endif // DELIMITEDTEXT_H
