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

#include <QFile>
#include <QTextCodec>
#include "globals.h"
#include "functions.h"
#include "deltasymbols.h"

static const char* m_VersionStr = DELTAQT_VERSION_STR;
static const char* m_buildDate = __DATE__;
static const char* m_buildTime = __TIME__;

/* Private function declarations
 */
static int splitPointDeltaAware(const QString& str, int maxLineLen);


QString libVersion(void)
{
    return m_VersionStr;
}

QString libBuildDate(void)
{
    return m_buildDate;
}

QString libBuildTime(void)
{
    return m_buildTime;
}

/** @internal
  * Break up <i>str</i> into a list of strings each with a maximum
  * length of <i>maxLineLen</i>
  */
QStringList breakStrToLineLen(const QString& str,
                              int maxLineLen,
                              unsigned indentLen_firstLine,
                              unsigned indentLen_subsequentLines,
                              bool splitOnWholeWords)
{
    QStringList result;
    QString working = str;
    QString subStr;
    int lineCount = 0;

    if (indentLen_subsequentLines == 0 && indentLen_firstLine > 0)
        indentLen_subsequentLines = indentLen_firstLine;

    int effectiveMaxLineLen = maxLineLen - indentLen_firstLine;

    if (maxLineLen == -1) { // If no max line length
        if (indentLen_firstLine > 0)
            subStr = QString(" ").repeated(indentLen_firstLine);
        subStr += str;
        result.append(subStr);
        return result;
    }

    while (working.length() > effectiveMaxLineLen) {
        int endPos;
        int indentLen = lineCount == 0 ? indentLen_firstLine
                                       : indentLen_subsequentLines;
        int newlineIdx = working.indexOf("\n");
        if (newlineIdx != -1 && newlineIdx < effectiveMaxLineLen) {
            if (newlineIdx == 0) newlineIdx--; // If newline at start of line
            endPos = newlineIdx;
        } else if (splitOnWholeWords) {
            int i = effectiveMaxLineLen > working.length()
                            ? working.length()-1
                            : effectiveMaxLineLen;
            for ( ; i >= 0; i--) {
                if (working.at(i).isSpace()) break;
            }

            if (i == -1) {
                // Try to get an alternative split point (other than on whole
                // word)
                i = splitPointDeltaAware(working, effectiveMaxLineLen);
            }
            if (i == -1) {
                endPos =  effectiveMaxLineLen-1;
            } else {
                endPos = i;
            }
        } else endPos = effectiveMaxLineLen-1;
        if (indentLen > 0) subStr = QString(" ").repeated(indentLen);
        else subStr = "";
        subStr += working.mid(0, endPos+1);
        trimTrailingWhitespace(&subStr);
        result += subStr;
        working = working.mid(endPos+1, -1);
        lineCount++;
        effectiveMaxLineLen = maxLineLen - indentLen_subsequentLines;
    }
    // append the last sub str (that is < maxLineLen)
    int indentLen = lineCount == 0 ? indentLen_firstLine
                                   : indentLen_subsequentLines;
    if (indentLen > 0) {
        subStr = QString(" ").repeated(indentLen);
    }
    else subStr = "";
    subStr += working;

    trimTrailingWhitespace(&subStr);

    result += subStr;
    return result;
}

// pre: str contains no whitespace before maxLineLen
static int splitPointDeltaAware(const QString& str, int maxLineLen)
{
    int i;

    /* Since there are no spaces to split on, it is safe to split on
       DELTA_DELIM_ENDCOMMENT if it's present, because the specifications
       for DELTA_DELIM_ENDCOMMENT (i.e. in current spec '>') mention nothing
       about what must precede the end comment delimiter; i.e. any preceding
       character is ok. There is no whitespace in the line (by pre-condition)
       so an extra '\n' is going to be in the output. It appears that this is
       how DELFOR also handles the problem, so...
     */

    i = maxLineLen < str.length() ? maxLineLen + 1 : maxLineLen;
    for (; i >= 0; i--) {
        if (str.at(i) == DELTA_DELIM_ENDCOMMENT
                || str.at(i) == '\\' /* rtf */) {
            i--;
            break;
        }
    }

    if (i == -1) {
        /* Still found nothing to split on. Try going forward; this will
           result in a line whose length is > maxLineLen, however this is
           safer than trying to split on a '/' (for example)
         */
        for (i = maxLineLen; i < str.length(); i++) {
            if (str.at(i).isSpace()
                    || str.at(i) == DELTA_DELIM_ENDCOMMENT
                    || str.at(i) == '\\' /* rtf */) {
                i--;
                break;
            }
        }
    }
    return i;
}

/** @internal
  * Determine DELTA input file encoding based on first line in file
  *
  * This function has no way of reporting errors; if an empty string is
  * returned then either the file couldn't be opened, there was no
  * @encoding 'meta-directive', or there was no match for the @encoding
  * specified.
  */
QString deltafile_Encoding(QString filename)
{
    QFile f;
    QString encoding;

    f.setFileName(filename);

    if (!f.open(QIODevice::ReadOnly|QIODevice::Text))
        return encoding;        // empty string

    encoding = deltafile_Encoding(&f);
    f.close();
    return encoding;
}

/** @internal
  * Determine DELTA input file encoding based on first line in file
  * Resets file position to location prior to calling this function
  *
  * This function has no way of reporting errors; if an empty string is
  * returned then either the file couldn't be opened, there was no
  * @encoding 'meta-directive', or there was no match for the @encoding
  * specified.
  */
QString deltafile_Encoding(QFile *file)
{
    qint64 cFilePos;
    QByteArray line;
    QString cmd = "*COMMENT @ENCODING";     // Going to convert input to ucase
    QString encoding;
    QTextCodec* codec;
    int startpos;

    cFilePos = file->pos();
    file->seek(0);
    line = file->readLine();
    line = line.simplified().toUpper();
    if (line.isEmpty()) goto finish;   // Error or no data

    startpos = line.indexOf(cmd);
    if (startpos == -1) goto finish;   // No 'meta-directive'

    startpos += cmd.length();
    encoding = line.mid(startpos,-1).trimmed();

finish:
    file->seek(cFilePos);

//    codec = QTextCodec::codecForName(encoding.toAscii().constData());
    codec = QTextCodec::codecForName(encoding.toLatin1().constData());
    if (codec) {
        encoding = codec->name();
    }
    return encoding;
}


/** @internal
  * Remove trailing whitespace from the string \a str.
  * If the string is a blank line (i.e. only contains a newline)
  * then this function does nothing.
  */
void trimTrailingWhitespace(QString* str)
{
    if (str->length() == 1 && str->at(0) == '\n') return;

    while (!str->isEmpty() && str->at(str->length()-1).isSpace())
        str->chop(1);
}
