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
#include "delimitedbuffer.h"
#include "deltasymbols.h"

/****************************************************************************/

//const int DelimPairBoundary::Index_NotSet = -1;

DelimPairBoundary::DelimPairBoundary()
{
    m_level = 0;
    m_indexStart = m_indexEnd = -1;
    m_indexStartLineNum = -1;
}

DelimPairBoundary::DelimPairBoundary(
        int level,
        int indexStart,
        int indexEnd)
{
    m_level = level;
    m_indexStart = indexStart;
    m_indexEnd = indexEnd;
}

/****************************************************************************
  CLASS DelimitedBuffer
 ***************************************************************************/

/*---------------------------------------------------------------------------
  Constructors
  --------------------------------------------------------------------------*/

DelimitedBuffer::DelimitedBuffer()
    : QString()
{
    m_status = MAP_NOTINITIALISED;
}
DelimitedBuffer::DelimitedBuffer(QString& other)
    :QString(other)
{
    m_status = MAP_NOTINITIALISED;
}

DelimitedBuffer::DelimitedBuffer(const char* str)
    : QString(str)
{
    m_status = MAP_NOTINITIALISED;
}

DelimitedBuffer::DelimitedBuffer(const QString& other)
    : QString(other)
{
    m_status = MAP_NOTINITIALISED;
}


/** @internal
  * @see mapDelimBoundaries()
  */
DelimitedBuffer::DelimitedBuffer(
        const char* ba,
        char startDelim,
        char endDelim,
        QString legalPreChars,
        QString legalPostChars)
    : QString(ba)
{
    mapDelimBoundaries(startDelim, endDelim,
                           legalPreChars, legalPostChars);
}

/** @internal
  * @see mapDelimBoundaries()
  */
DelimitedBuffer::DelimitedBuffer(
        const QString& other,
        char startDelim,
        char endDelim,
        QString legalPreChars,
        QString legalPostChars)
    : QString(other)
{
        mapDelimBoundaries(startDelim, endDelim,
                           legalPreChars, legalPostChars);
}

/*---------------------------------------------------------------------------
  Non-mapping functions
  --------------------------------------------------------------------------*/

/** @internal
  * Returns true if initialised
  */
bool DelimitedBuffer::isMapped(void) const
{
    return m_status == MAP_OK;
}


/** @internal
  * Returns true if the index <i>idx</i> is between mapped
  * startDelim/endDelim pairs (or nested pairs)
  *
  * @pre: the 'map' must be initialised and valid
  */
bool DelimitedBuffer::indexIsBetweenDelims(int idx) const
{
    const DelimPairBoundary* cdelim;
    int i;
    bool r = false;

    Q_ASSERT(m_status == MAP_OK); // pre-condition

    for (i = 0; i < m_delimBoundaries.count(); i++) {
        cdelim = &m_delimBoundaries.at(i);;
        if (m_delimBoundaries.at(i).level() > 0 &&
                idx >= cdelim->indexStart() && idx <= cdelim->indexEnd()) {
            r = true;
            break;
        }
    }
    return r;
}

/** @internal
  * Returns the maximum number of nested levels mapped.
  */
int DelimitedBuffer::numLevels(void) const
{
    int max = 0;
    for (int i = 0; i < m_delimBoundaries.count(); i++) {
        if (m_delimBoundaries.at(i).level() > max) {
            max = m_delimBoundaries.at(i).level();
        }
    }
    return max;
}

/** @internal
  * Returns a copy of the mapped delimiter boundaries.
  */
DelimPairBoundaries DelimitedBuffer::getChunkBoundaries(void) const
{
    return m_delimBoundaries;
}

/** @internal
  * Clear any mapping and set the status to MAP_NOTINITIALISED.
  */
void DelimitedBuffer::clear()
{
    m_status = MAP_NOTINITIALISED;
    m_delimBoundaries.clear();
    QString::clear();
}

/** @internal
  * Returns a copy of the buffer with all whitespace removed.
  */
DelimitedBuffer DelimitedBuffer::noWhitespace(void) const
{
    DelimitedBuffer result;

    result.reserve(this->length());

    for (int i = 0; i < this->length(); i++) {
        if (!this->at(i).isSpace()) {
            result.append(this->at(i));
        }
    }
    return result;
}

/** @internal
  * Returns the chunk defined by <i>boundary</i>. The characters on the
  * start and end of the boundary indexes are included in the result.
  */
QString DelimitedBuffer::getChunk(
        DelimPairBoundary boundary) const
{
    int startPos = boundary.indexStart();
    int endPos = boundary.indexEnd();
    int len;
    len = endPos - startPos + 1;

    return this->mid(startPos, len);
}

/** @internal
  * Returns the chunk between (and including) <i>startPos</i> and <i>endPos</i>.
  * If <i>endPos</i> == -1 the chunk will contain begin at <i>startPos</i> and
  * include the rest of the array.
  */
QString DelimitedBuffer::getChunk(int startPos,
                                     int endPos) const
{
    int len;
    if (startPos == -1) startPos = 0;
    len = (endPos == -1 ? -1 : endPos - startPos + 1);

    return this->mid(startPos, len);
}

/** @internal
  * @see DelimitedBuffer::MapStatus
  */
DelimitedBuffer::MapStatus DelimitedBuffer::status(void) const
{
    return this->m_status;
}


/*---------------------------------------------------------------------------
  Mapping functions
  --------------------------------------------------------------------------*/
/** @internal
  * Maps the byte array into sections that are within and not within a
  * a startDelim/endDelim pair.
  *
  * Sections that are outside of the given delimiters: these sections have a
  * 'level' (depth) of 0. Sections that are within the deliminiter pairs have a
  * level of 1 to n, which indicates the level of nesting for the given
  * section. E.g. If the delimiters are { and }, given a bytearray of "a{b c
  * {d}}}" 'a' has a level of 0, 'b' and 'c' level 1, and 'd' has a level of 2.
  *
  * If no delimiters are present withing the input array the entire array is
  * mapped as a level-0 item.
  *
  * If there is already a map, it will be cleared and replaced with a new
  * mapping.
  *
  * @warning   If the startDelim/endDelim pairs within the byte array are
  *            not balanced, the status of the mapping is undefined (check
  *            the return value or isValid() to determine if the mapping
  *            succeeeded.
  * @see       class DelimPairBoundary
  */
bool DelimitedBuffer::mapDelimBoundaries(
        QChar startDelim,
        QChar endDelim,
        QString legalPreChars,
        QString legalPostChars)
{
    QList<int> stack;
    DelimPairBoundaries* dest = &m_delimBoundaries;

    int spd, epd;           // start pos, end pos (delims)
    int slnd;               // start last non-deliminated
    int depth;

    dest->clear();

    depth = 0;
    slnd = 0;

    if (this->isEmpty()) {
        m_status = MAP_OK;      // OK, just empty
        return true;
    }

    spd = indexOf(startDelim);
    epd = indexOf(endDelim);

    // Special case before first iteration
    if (epd != -1 && epd < spd) {
        m_status = MAP_ERROR_UNBALANCED_DELIMS;
        return false;
    }

    while (spd != -1 || epd != -1) {

        if ((spd != -1 && spd < epd) || epd == -1) {

            // Append items outside of delims as a 'level-0' boundary
            if (depth == 0 && spd > slnd) {
                dest->append(DelimPairBoundary(0, slnd, spd - 1));
            }
            // Check legal pre-chars
            if (spd == 0 || preCharOk(this->at(spd-1), legalPreChars)) {
                stack.append(spd);
                depth++;
            }
            int newpos = spd + 1;
            spd = indexOf(startDelim, newpos);
        } else if (epd != -1) {
            // Check legal post-chars
            if (epd == this->count()-1
                    || postCharOk(this->at(epd+1), legalPostChars)) {
                if (stack.isEmpty()) {
                    m_status = MAP_ERROR_UNBALANCED_DELIMS;
                    return false;       // unmatched close delim
                }
                dest->append(DelimPairBoundary(depth,
                                               stack.takeLast(),
                                               epd));
                depth--;
                if (depth == 0) { // possible start of a new 'level-0' area
                    slnd = epd+1;
                }
            }
            int newpos = epd + 1;
            epd = indexOf(endDelim, newpos);
        }
    }

    if (depth != 0) {
        m_status = MAP_ERROR_UNBALANCED_DELIMS;
        return false;
    }
    // Append anything after the last close delim as a 'level-0' boundary.
    // This also handles the case when the input string had no delimiters
    // at all.
    if (slnd < this->length()) {
        dest->append(DelimPairBoundary(0, slnd, this->length()-1));
    }
    m_status = MAP_OK;

    return true;
}


/** @internal
  * If the delimiter boundaries have not been initalised (by calling init() or
  * one of the mapDelim...() member functions, an empty list will be returned.
  *
  * The parameter minLevel and maxLevel are used to filter the sections added
  * to the resulting string; if minLevel or maxLevel is -1 (the default) then
  * no filtering on that value is performed. If minLevel > maxLevel the
  * returned list will be empty. E.g. to get all sections of level 0 (those
  * not within a delim pair) set minLevel and maxLevel to 0; similarly to
  * get a list of all the level 1 items set minLevel and maxLevel both to 0.
  * It is not necessary that minLevel and maxLevel are the same, however the
  * values being the same is probably the most common intended use.
  */
QStringList DelimitedBuffer::getChunkStrings(
        int minLevel,
        int maxLevel) const
{
    QStringList result;
    const DelimPairBoundaries& bnd = m_delimBoundaries;

    if (minLevel > maxLevel && maxLevel != -1) return result;

    for (int i = 0; i < bnd.count(); i++) {

        if (bnd.at(i).level() >= minLevel &&
                    (maxLevel == -1 || bnd.at(i).level() <= maxLevel))
        {
            int chunkLen;
            chunkLen = bnd.at(i).indexEnd() - bnd.at(i).indexStart() + 1;
            result.append(this->mid(bnd.at(i).indexStart(), chunkLen));
        }
    }
    return result;
}


/** @internal
  * Returns a string of the mapped items, with each section (based on the
  * nesting level) separated by the 'delimWith' character.
  *
  * See getChunkStrings() for an explanation of minLevel and maxLevel.
  *
  * If simplify == true, then the string is simplified by removing leading
  * spaces, trailing spaces AND replaces sequences of 2 or more contiguous
  * spaces within the string itself with a single space.
  */
QString DelimitedBuffer::getStringsAppended(
        QChar delimWith,
        int minLevel,
        int maxLevel,
        bool simplify
        ) const
{
    QStringList list;
    QString r;

    list = getChunkStrings(minLevel, maxLevel);
    if (list.isEmpty()) return r;

    for (int i = 0; i < list.count(); i++) {
        QString tmp;
        tmp = list.at(i);
        tmp = tmp.trimmed();
        if (r != 0 && delimWith != -1) r += delimWith;
        r += tmp;
    }

    if (simplify) r = r.simplified();
    return r;
}


QString DelimitedBuffer::getLevel1Comments(void) const
{
    QString comment;
    comment = getStringsAppended(-1, 1, 1);
    comment = comment.mid(1);
    comment.chop(1);
    return comment;
}

/** @internal
  * Populates <i>dest</i> with the tokens/chunks delimited by <i>searchChar<i>
  * where <i>searchChar</i> is outside of the current mapped delimiter pairs;
  * i.e. level-0 chunks. @see findCharPositionsExcept() for more information
  * on how the splitting occurs.
  *
  * If <i>removeSearchCharFromStart</i> == true, the search character is
  * removed from the beginning of the tokens (if present).
  *
  * If <i>dest</i> is not empty, this function will clear it.
  *
  * @note mapDelimBoundaries() will be called to attempt to initialise
  *       if status != MAP_OK
  *
  * @see  mapDelimBoundaries()
  */
bool DelimitedBuffer::getTokens(
        QList<QString>* dest,
        char searchChar,
        QChar startDelim,
        QChar endDelim,
        QString legalPreChars,
        QString legalPostChars,
        bool splitOnPreIsSpace,
        bool splitOnPostIsSpace,
        bool removeSearchCharFromStart)
{
    QVector<int> charPositions;

    charPositions = findCharPositionsExcept(
                        searchChar,
                        startDelim,
                        endDelim,
                        legalPreChars,
                        legalPostChars,
                        splitOnPreIsSpace,
                        splitOnPostIsSpace);

    if (m_status != MAP_OK) return false;

    dest->clear();

    if (charPositions.isEmpty()) {
        if (!this->isEmpty()) {
            dest->append(getChunk(0));      // append whole string
            return true;
        } else
            return false;
    }
    if (charPositions.at(0) != 0) {
        charPositions.insert(0, 0);     // prepend start of buffer
    }
    for (int i = 0; i < charPositions.count(); i++) {
        int sp, ep;
        QString chunk;

        sp = charPositions.at(i);
        ep = i < charPositions.count() - 1 ? charPositions.at(i+1)
                                           : -1;

        if (ep != -1 && i < charPositions.count() - 1)
            chunk = getChunk(sp, ep - 1);  // get chunk WITHOUT the last char
        else
            chunk = getChunk(sp, ep);

        chunk = chunk.trimmed();
        if (removeSearchCharFromStart) {
            if (chunk.at(0) == searchChar) chunk = chunk.mid(1).trimmed();
            if (!chunk.isEmpty()) dest->append(chunk);
        }
        else
            dest->append(chunk);
    }
    return true;
}

/** @internal
  * Returns true if <i>c</i> is in <i>legalPreChars</i>. If <i>legalPreChars</i>
  * contains a space (' ') isSpace() is used instead of comparing to the
  * actual space character.
  */
bool DelimitedBuffer::preCharOk(QChar c, QString legalPreChars)
{
    int i;

    if (legalPreChars.count() == 0) return true;
    for (i = 0; i < legalPreChars.count(); i++) {
        if (legalPreChars.at(i).isSpace() && c.isSpace()) break;
        if (legalPreChars.at(i) == c) break;
    }

    return i < legalPreChars.count();
}

 /** @internal
   * Returns a list of indexes where the character 'splitOn' occurs
   * outside of startDelim/endDelim pairs (or nested pairs).
   *
   * If the map is not currently defined (i.e. status() != MAP_OK), it will be
   * created using <i>startDelim</i>, <i>endDelim</i>, <i>legalPreChars</i> and
   * <i>legalPostChars</i> (@see mapDelimBoundaries()).
   *
   * If <i>splitOnPreIsSpace</i> == true, the character before searchChar must
   * be a space for a split to occur; if <i>splitOnPostSpace</i> == true then
   * the character following searchChar must be a space or EOL for a split to
   * occur.

   * @note mapDelimBoundaries() will be called to attempt to initialise
   *       if status != MAP_OK;
   */
QVector<int> DelimitedBuffer::findCharPositionsExcept(
        char searchChar,
        QChar startDelim,
        QChar endDelim,
        QString legalPreChars,
        QString legalPostChars,
        bool splitOnPreIsSpace,
        bool splitOnPostIsSpace)
{
    QVector<int> result;
    int pos;

    if (searchChar == startDelim || searchChar == endDelim) {
        m_status = MAP_ERROR_SPLIT_EXCEPT_INVALID_DELIM;
        return result;
    }

    // Create the map of the startDelim/endDelim pairs
    if (m_status != MAP_OK && !mapDelimBoundaries(startDelim, endDelim,
                            legalPreChars, legalPostChars)) {
        return result;
    }

    /* Find delim characters within the buffer that are not within a startDelim
     * and endDelim pair and add them to the split positions
     */
    pos = 0;
    while ( (pos = indexOf(searchChar, pos)) != -1 ) {
        if (!indexIsBetweenDelims(pos)) {
            bool doAppend = true;
            if (splitOnPreIsSpace != false) {
                // splitOn must be at start of a line, or preceded by a space
                if (!(pos == 0
                        || this->at(pos-1) == '\n'
                        || this->at(pos-1).isSpace()))
                {
                    doAppend = false;
                }
            }
            if (splitOnPostIsSpace != false) {
                // splitOn must be at the end of a line, or followed by a space
                if (!(pos == this->size()-1
                        || this->at(pos+1) == '\n'
                        || this->at(pos+1).isSpace()))
                {
                    doAppend = false;
                }
            }

            if (doAppend) {
                result.append(pos);
            }
        }
        pos++;
    }

    return result;

}

