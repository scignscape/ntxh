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
#include <QFileInfo>
#include <QTextCodec>
#include "deltaparserprivate.h"
#include "deltasymbols.h"


/****************************************************************************/

// Extreme minimum of m_defaultMinBuffSize is 1 (although not useful)
int DpReadBuffer::m_defaultMinBuffSize = 256;
int DpReadBuffer::m_defaultMaxBuffSize = 524487;

DpReadBuffer::DpReadBuffer()
{
    ctorCommonInit();
}

DpReadBuffer::~DpReadBuffer()
{
    close();
}


DpReadBuffer::DpReadBuffer(QString filename, const char* textCodec)
{
    ctorCommonInit();
    useFile(filename, textCodec);
}

DpReadBuffer::DpReadBuffer(QString filename,
                           const char* textCodec,
                           int maxBuffSize)
{
    ctorCommonInit();
    useFile(filename, textCodec, maxBuffSize);
}

void DpReadBuffer::ctorCommonInit(void)
{
    m_buff = NULL;
    m_file = NULL;
    m_stream = NULL;
    m_maxBuffSize = m_defaultMaxBuffSize;
    m_buffOffsetInFile = 0;
    m_startPosInBuff = 0;
    m_commentDepth = 0;
    m_currentLineNum = 1;
}

/* NOTE: if maxBuffSize < m_defaultMinBuffSize, m_defaultMinBuffSize will be
 *       used.
 */
bool DpReadBuffer::useFile(QString filename,
                           const char* textCodec,
                           int maxBuffSize)
{
    reset();

    m_maxBuffSize = maxBuffSize < m_defaultMinBuffSize
                                    ? m_defaultMaxBuffSize
                                    : maxBuffSize;

    m_buff = new QString;
    m_buff->reserve(m_maxBuffSize+10);
    m_file = new QFile;
    m_file->setFileName(filename);
    m_file->open(QIODevice::ReadOnly|QIODevice::Text);
    m_stream = new QTextStream(m_file);
    m_stream->setCodec(textCodec);
    fillBuffer();
    return m_file->isOpen();
}

bool DpReadBuffer::get(QChar* ch)
{
    if (m_startPosInBuff == m_buff->size()) fillBuffer();
    if (m_buff->isEmpty()) return false;
    *ch = m_buff->at(m_startPosInBuff);
    m_startPosInBuff++;
    if (*ch == '\n') m_currentLineNum++;
    return true;
}

/** @internal
  * Read into @param dest until one of the characters in @param seachChars
  * is encountered. If @param firstChar != NULL, the first non-whitepace
  * character encountered is stored in @param firstChar.
  *
  * This function modifies m_startPosInBuff (the <i>cursor position</i>;
  * i.e. subsequent calls wil begin searching in the buffer from
  * m_startPosInBuff. If other function that modify the <i>cursor position</i>
  * are called between subsequent calls to this function then the result may
  * not be as desired.
  *
  * @note This function takes into account DELTA comment delimiters.
  *
  */
int DpReadBuffer::readUntil(const DeltaParseContext& parseCtxt,
                            const QString& searchChars,
                            QString* dest,
                            QChar* firstChar)
{
    int i;
    int foundPosition = -1;

    dest->clear();

    if (m_buff->isEmpty()) return -1;    // At EOF

    /* Store the first non-whitespace character rather than check
     * it for a match with searchChars; this is to support the
     * parsing method with is delimited by the searchChars and on the one
     * hand we don't want the delim at the end of the string when we find
     * it; it wouldn't hurt to have it at the start, however because
     * each directive in delimited by the start of the next (if any)
     * directive this complicates things because either the first directive
     * search will stop at the firt '*' it encounters and thus return a
     * NULL string and the next directive will not have the leading '*'
     * but subsequent ones will. Keeping the ending delim rather than the
     * starting delim (in the returned string) poses the same problem but
     * in reverse.
     */
    while (QChar(m_buff->at(m_startPosInBuff)).isSpace()) {
        m_startPosInBuff++;
        if (m_startPosInBuff == m_buff->size()) {
            if (fillBuffer() == 0) // EOF
                return -1;
        }
        if (m_buff->at(m_startPosInBuff) == QChar('\n'))
            m_currentLineNum++;
    }
    if (firstChar) *firstChar = QChar(m_buff->at(m_startPosInBuff));
    m_startPosInBuff++;

    while (foundPosition == -1 && m_buff->size() > 0) {
        for (i = m_startPosInBuff; i < m_buff->size(); i++) {
            QChar cc = m_buff->at(i);
            QChar prevChar = i == 0 ? m_prevPageLastChar : m_buff->at(i-1);

            if (cc == QChar('\n'))
                m_currentLineNum++;

            if (parseCtxt.isCommentStart(cc, prevChar)) {
                m_commentDepth++;
            } else if (parseCtxt.isCommentEnd(cc, peek(i+1))) {
                m_commentDepth--;
            } else if (m_commentDepth < 1
                       && charInSearchChars(cc, searchChars)) {
                    foundPosition = i;
                    m_startPosInBuff = i;
                    break;
            }

            if (foundPosition == -1) dest->append(cc);
        }
        if (foundPosition == -1) {
            if (fillBuffer() == 0) // EOF
                foundPosition = i;
        }
    }
    return foundPosition;
}

void DpReadBuffer::reset(void)
{
    deallocateResources();
    ctorCommonInit();
}


/* Protected functions
 */
QChar DpReadBuffer::peek(int pos) const
{
    char nextChar;
    qint64 peekStatus;

    if (pos < m_buff->size() - 1)
        return m_buff->at(pos);

    peekStatus = m_stream->device()->peek(&nextChar, 1);
    if (peekStatus == -1 || peekStatus == 0)
        return QChar(); // EOF (or error if -1)

    return nextChar;
}

int DpReadBuffer::fillBuffer(void)
{
    if (m_buffOffsetInFile != 0)
        m_prevPageLastChar = m_buff->at(endOfBufferIdx());

    m_buffOffsetInFile += m_buff->size();
    *m_buff = m_stream->read(m_maxBuffSize);
    m_startPosInBuff = 0;
    return m_buff->size();
}

bool DpReadBuffer::charInSearchChars(QChar c, const QString& search)
{
    return search.isEmpty() ? true : search.indexOf(c) != -1;
}

void DpReadBuffer::deallocateResources(void)
{
    if (m_stream) {
        delete m_stream;
        m_stream = NULL;
    }
    if (m_file && m_file->isOpen()) {
        m_file->close();
        delete m_file;
        m_file = NULL;
    }
    if (m_buff) {
        delete m_buff;
        m_buff = NULL;
    }
}

/****************************************************************************/

DeltaParseContext::DeltaParseContext()
{
    m_currDirective = DeltaDirectives::pseudoDef(DeltaDirectives::PSEUDO_NONE);

}

DeltaParseContext::~DeltaParseContext()
{
}


bool DeltaParseContext::isCommentStart(QChar ch, QChar prevCh) const
{
    if (ch != DELTA_DELIM_STARTCOMMENT)
        return false;
    if (m_currDirective->id == DeltaDirectives::ITEMDESCS)
        return true;

    if (prevCh.isNull()) return true; // start of file

    // check for legal pre-comment-delim char
    return isLegalCommentPreChar(prevCh);
}


bool DeltaParseContext::isCommentEnd(QChar ch, QChar nextCh) const
{
    if (ch != DELTA_DELIM_ENDCOMMENT)
        return false;
    if (nextCh.isNull()) return true; // EOF
    if (m_currDirective->id == DeltaDirectives::ITEMDESCS)
        return true;

    // check for legal post-comment-delim char
    return isLegalCommentPostChar(nextCh);
}


QString DeltaParseContext::determineLegalCommentPreChars(void) const
{
    QString result;

    if (m_currDirective->id == DeltaDirectives::ITEMDESCS)
        return result;      // Empty string --> all characters valid

    result += ' ';
    result += DELTA_DELIM_STARTCOMMENT;
    result += DELTA_DELIM_ENDCOMMENT;

    return result;
}


QString DeltaParseContext::determineLegalCommentPostChars(void) const
{
    QString result;

    if (m_currDirective->id == DeltaDirectives::ITEMDESCS)
        return result;      // Empty string --> all characters valid

    result += ' ';
    result += DELTA_DELIM_STARTCOMMENT;
    result += DELTA_DELIM_ENDCOMMENT;
    result += DELTA_DELIM_ITEMNAME_END;

    return result;
}


void DeltaParseContext::clear(void)
{
    m_currDirective = DeltaDirectives::pseudoDef(DeltaDirectives::PSEUDO_NONE);
    m_currCommentDepth = 0;
    m_currFilename = m_currFilenameNoPath = QString();
    m_currLineNum = 0;
    m_currPosInFile = 0;
    m_legalCommentPreChars.clear();
    m_legalCommentPostChars.clear();
}


void DeltaParseContext::switchDirectiveCtxt(
        const DeltaDirectives::Def* directive)
{
    m_currDirective = directive;
    m_legalCommentPreChars = determineLegalCommentPreChars();
    m_legalCommentPostChars = determineLegalCommentPostChars();
}


void DeltaParseContext::switchFileContext(QString newFilename)
{
    clear();
    m_currFilename = newFilename;
    QFileInfo fi(newFilename);
    m_currFilenameNoPath = fi.baseName();
}

bool DeltaParseContext::isLegalCommentPreChar(QChar ch) const
{
    return isLegalCommentPreOrPostCh(ch, getLegalCommentPreChars());
}

bool DeltaParseContext::isLegalCommentPostChar(QChar ch) const
{
    return isLegalCommentPreOrPostCh(ch, getLegalCommentPostChars());
}

bool DeltaParseContext::isLegalCommentPreOrPostCh(
        QChar ch,
        const QString &legalChars) const
{
    bool result;

    if (legalChars.isEmpty()) return true;
    result = legalChars.indexOf(ch) == -1 ? false : true;

    // A ' ' character in legalChars is interpreted as /any/ whitespace
    if (!result && legalChars.indexOf(' ') != -1) {
        result = ch.isSpace();
    }

    return result;
}
