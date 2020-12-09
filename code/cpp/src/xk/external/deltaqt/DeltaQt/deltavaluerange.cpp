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


#include <QRegExp>
#include <QString>
#include <QStringList>
#include <QDebug>

#include "deltavaluerange.h"
#include "deltasymbols.h"


/* At a casual glance it seems that most of the functionality of this class
   could be handled by regular expressions. Indeed, if the input string was
   stripped of DELTA comments before passing it to this class (or if the class
   itself stripped the DELTA comments) then regualar expressions could be used.
   However, we want to retain the comments so that they can be associated with
   the value(s), so parsing the range is done the longer way (without
   regex). Since DELTA comments can contain any legal character and also be
   nested, regex is not going to work even for validation.
  */

/* NOTE:    Does not currently support the DELTA notation where ':' separates
            disjoint or multiple ranges; e.g. "2-3:5-8:13-21"; calling
            functions (currently) need to do the split themselves.
 */

DeltaValueRange::DeltaValueRange()
{
    m_placemarker = 1;
    m_isInitialised = false;
}

/** Returns true if the range has been initialised successfully.
  */
bool DeltaValueRange::isValid(void) const
{
    return m_isInitialised;
}

/** Clear all values.
  */
void DeltaValueRange::clear(void)
{
    m_normalValues.clear();
    m_rangeExtremeLow.clear();
    m_rangeExtremeHigh.clear();
    m_isInitialised = false;
}

/** Initialise the range using the DELTA formatted string stored in \a buff.
  * Errors, warnings and messages are appended to \a log
  */
bool DeltaValueRange::init(const QString& buff, ParseLog* log)
{
    /* - There may be at most two extreme values (CHECKED)
       - If is an extreme value given there can be at most 3 'normal' (those
            not in parenthesis) values (NOTE: This is NOT CHECKED; it will
            be checked by data validation when implemented)
     */

    DelimitedBuffer dbuff;
    DelimPairBoundaries delimBounds;
    bool success = true;

    clear();
    m_log = log;

    dbuff.append(buff);
    dbuff.mapDelimBoundaries(DELTA_DELIM_STARTCOMMENT,
                             DELTA_DELIM_ENDCOMMENT);
    delimBounds = dbuff.getChunkBoundaries();

    // Parse the text between each 'level-0' (non-comment) boundary
    for (int i = 0; i < delimBounds.count(); i++) {
        if (delimBounds[i].level() == 0) {
            QString comment;

            if (i < delimBounds.count()-1 && delimBounds[i+1].level() > 0) {
                comment = dbuff.getLevel1Comments();
            }

            success = parseRangeChunk(dbuff.getChunk(delimBounds[i]), comment);
            if (!success) break;
        }
    }

    m_isInitialised = success;
    return success;
}

/** Return all values as an expanded list. Extreme values are <b>ignored</b>.
  */
QList<AnnotatedValue> DeltaValueRange::getExpandedValueList(void) const
{
    QList<AnnotatedValue> result;

    if (m_normalValues.size() == 0) return result;

    for (int i = 0; i < m_normalValues.size(); i++) {
        // Convert the values to integers
        int from, to;
        bool ok;
        from = m_normalValues.at(i).value().toInt(&ok);

        if (!ok) {
            m_log->appendStdErr("Expanding range",
                                "Lower value could not be converted to int");
            result.clear(); return result; // return empty result
        }
        if (i < m_normalValues.size()-1) {
            to = m_normalValues.at(i+1).value().toInt(&ok);
            if (!ok) {
                m_log->appendStdErr("Expanding range",
                                    QString("Value could not be converted ")
                                    + "to int: "
                                    + m_normalValues[i+1].value().toString());
                result.clear(); return result; // return empty result
            }
        } else to = from;

        if (to == from && i < m_normalValues.size()-1) {
            m_log->appendVbsWarn("Expanding range",
                                 "Duplicate value: "
                                 + QString::number(to));
        }

        if (i < m_normalValues.size()-1) { // If not at the last value
            bool descend = from > to ? true : false;

            // Expand from current value to the next value
            for (int n = from; n != to; descend ? n-- : n++) {
                AnnotatedValue val;
                val.setValue(n);
                if (n == from) val.setNote(m_normalValues[i].note());
                result.append(val);
            }
        } else { // Process the last value
            // Processing on its own so that the note can be kept
            AnnotatedValue val;
            val.setValue(to);
            val.setNote(m_normalValues.at(i).note());
            result.append(val);
        }
    }
    return result;
}

QList<int> DeltaValueRange::getExpandedIntList(void) const
{
    QList<int> result;
    QList<AnnotatedValue> vList = getExpandedValueList();

    for (int i = 0; i < vList.count(); i++) {
        int val;
        bool ok;
        val = vList.at(i).toInt(&ok);
        if (ok)
            result.append(val);
        else {
            m_log->appendStdErr("Expanding range",
                                "Could not convert value to integer: "
                                + val);
        }
    }
    return result;
}

QString DeltaValueRange::toDeltaString(void) const
{
    QString result;

    if (m_rangeExtremeLow.isValid()) {
        result += DELTA_DELIM_EXTREMEVAL_START;
        result += m_rangeExtremeLow.value().toString();
        result += "-";
        result += DELTA_DELIM_EXTREMEVAL_END;
    }

    for (int i = 0; i < m_normalValues.count(); i++) {
        if (i != 0) result += "-";
        result += m_normalValues.at(i).value().toString();
        if (!m_normalValues.at(i).note().isEmpty()) {
            result += DELTA_DELIM_STARTCOMMENT;
            result += m_normalValues.at(i).note();
            result += DELTA_DELIM_ENDCOMMENT;
        }
    }

    if (m_rangeExtremeHigh.isValid()) {
        result += DELTA_DELIM_EXTREMEVAL_START;
        result += "-";
        result += m_rangeExtremeHigh.value().toString();
        result += DELTA_DELIM_EXTREMEVAL_END;
        if (!m_rangeExtremeHigh.note().isEmpty()) {
            result += DELTA_DELIM_STARTCOMMENT;
            result += m_rangeExtremeHigh.note();
            result += DELTA_DELIM_ENDCOMMENT;
        }
    }

    return result;
}

/*---------------------------------------------------------------------------
  Protected functions
  --------------------------------------------------------------------------*/

bool DeltaValueRange::setPlacemarker(const QString& chunk)
{
    int i;
    bool r;
    for (i = 1; i < 256; i++) {
        if (!chunk.contains(i)) break;
    }
    r = i == 256 ? false : true;
    if (r) m_placemarker = i;
    return r;
}

bool DeltaValueRange::parseRangeChunk(const DelimitedBuffer& chunk,
                                      const QString& comment)
{
    QString compacted;
    bool success = true;

    compacted = chunk.noWhitespace();
    if(compacted.isEmpty()) return true; // Empty is not an error; ignore

    // NOTE: Might be able to use regex from this point on

    if (!(setPlacemarker(compacted))) {
        m_log->appendVbsErr("Internal Error. Could not find a suitable",
                            " placemarker for parsing negative range values");
        return false;
    }

    compacted.replace("--", QString(QChar(m_placemarker)));

    success = parseCompactedChunk(compacted, comment);

    return success;
}

bool DeltaValueRange::parseCompactedChunk(const DelimitedBuffer& chunk,
                                          const QString& comment)
{

    DelimitedBuffer partsBuff;
    QStringList partStrings;
    partsBuff = chunk;
    bool success = true;

    success = partsBuff.mapDelimBoundaries(DELTA_DELIM_EXTREMEVAL_START,
                                           DELTA_DELIM_EXTREMEVAL_END);
    if (!success) {
        m_log->appendVbsErr("Range",
                            QString("Invalid input; unbalanced '")
                            + DELTA_DELIM_EXTREMEVAL_START + "' and '"
                            + DELTA_DELIM_EXTREMEVAL_END + "'");
        return false;
    }

    partStrings = partsBuff.getChunkStrings();

    for (int i = 0; i < partStrings.count(); i++) {
        success = parseChunkPart(partStrings.at(i), comment);
        if (!success) break;
    }

    if (success && !comment.isEmpty()) {
        if (m_rangeExtremeHigh.isValid()) {
            m_rangeExtremeHigh.setNote(comment);
        } else if (!m_normalValues.isEmpty()) {
            m_normalValues.last().setNote(comment);
        }
    }

    return success;
}

bool DeltaValueRange::parseChunkPart(const QString& chunk,
                                     const QString& comment)
{
    QString part;
    QString splitDelim;
    QStringList splitParts;

    Q_ASSERT (!chunk.isEmpty());

    if (chunk[0] == DELTA_DELIM_EXTREMEVAL_START) {
        // Parse as an extreme value
        return parseExtremePart(chunk, comment);
    }
    else {
        part = chunk;
    }

    /* Parse as 'normal' (non-extreme) values
     */
    splitDelim = "-";
    splitParts = part.split(splitDelim);

    bool firstNumIsNegative = part.at(0) == '-' ? true : false;

    for (int i = 0; i < splitParts.count(); i++) {
        if (!splitParts.at(i).isEmpty()) {
            DelimitedBuffer dbuff;
            QList<QString> values;
            dbuff.append(splitParts.at(i));

            dbuff.getTokens(&values,
                            m_placemarker,
                            '<', '>'); /* The start and end
                                          delims are not important
                                          here as the string has
                                          none in it anyway (we just want
                                          the tokens mapped) */
            for (int v = 0; v < values.count(); v++) {
                AnnotatedValue val;
                QString valStr = values.at(v);
                valStr.replace(m_placemarker, '-');
                if (v == 0 && firstNumIsNegative) {
                    valStr = "-" + valStr;
                }
                val.setValue(valStr);

                m_normalValues.append(val);
            }
        }
    }


    return m_normalValues.count() != 0
            || m_rangeExtremeLow.isValid()
            || m_rangeExtremeHigh.isValid() ? true : false;
}


bool DeltaValueRange::parseExtremePart(const QString& chunk,
                                       const QString& comment)
{
    bool isExtremeLow = false;
    bool isExtremeHigh = false;
    QString part = chunk;

    // Process extreme value
    if (chunk[chunk.length()-1] != DELTA_DELIM_EXTREMEVAL_END) {
        m_log->appendVbsErr("Range",
                            QString("Extreme value missing closing '")
                            + DELTA_DELIM_EXTREMEVAL_END + "'");
        return false;
    }
    part = chunk.mid(1, -1);
    part.chop(1);
    if (part.isEmpty()) {
        m_log->appendVbsWarn("Range", "Extreme value is blank");
        return false;
    }
    if (part.length() == 1 && part[0] == '-') {
        m_log->appendVbsWarn("Range", "Extreme value is blank");
        return false;
    }
    if (part[part.length()-1] == '-') {
        isExtremeLow = true;
        part.chop(1);   // don't need the '-' suffix now
    }
    else {
        isExtremeHigh = true;
        part = part.mid(1); // skip the '-' prefix
    }

    part.replace(m_placemarker, "-");
    if (isExtremeLow) {
        if (m_rangeExtremeLow.isValid()) {
            m_log->appendVbsWarn("Range",
                                 QString("Extreme low value is already set. ")
                                 + "Ignoring new value: " + part);
        } else {
            m_rangeExtremeLow.setValue(part);
        }
    } else {
        if (m_rangeExtremeHigh.isValid()) {
            m_log->appendVbsWarn("Range",
                                 QString("Extreme high value is already set. ")
                                 + "Ignoring new value: " + part);
        } else {
            m_rangeExtremeHigh.setValue(part);
        }
    }

    return true;
}









