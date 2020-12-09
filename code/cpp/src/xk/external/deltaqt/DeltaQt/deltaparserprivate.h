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

#ifndef DELTAPARSERPRIVATE_H
#define DELTAPARSERPRIVATE_H

#include <QString>
#include <QChar>
#include <QFile>
#include <QTextStream>

#include "deltadirectives.h"

class DeltaParseContext; // fwd decl

class DpReadBuffer
{
    friend class DeltaParseContext;
public:
    DpReadBuffer();
    ~DpReadBuffer();
    DpReadBuffer(QString filename, const char* textCodec);
    DpReadBuffer(QString filename, const char* textCodec, int maxBuffSize);

    inline bool isReady(void) const { return m_file->isOpen(); }

    bool useFile(QString filename, const char* textCodec, int maxBuffSize = -1);

    bool get(QChar* ch);

    int readUntil(const DeltaParseContext& parseCtxt,
                  const QString& searchChars,
                  QString* dest,
                  QChar* firstChar = NULL);

    inline void close(void) { reset(); }

    inline int currentLineNum(void) { return m_currentLineNum; }

    void reset(void);

protected:
    void ctorCommonInit(void);
    QChar peek(int after) const;
    int fillBuffer(void);

    void deallocateResources(void);

private:
    inline int endOfBufferIdx(void) const { return m_buff->count()-1; }
    bool charInSearchChars(QChar ch, const QString& searchChars);


    int m_maxBuffSize;
    int m_buffOffsetInFile;
    int m_startPosInBuff;
    int m_commentDepth;
    int m_currentLineNum;
    QChar m_prevPageLastChar;

    QString* m_buff;
    QFile* m_file;
    QTextStream* m_stream;

    static int m_defaultMinBuffSize;
    static int m_defaultMaxBuffSize;

};


class DeltaParseContext
{
    friend class DeltaParser;

public:
    DeltaParseContext();
    ~DeltaParseContext();

    inline const DeltaDirectives::Def* directiveCtxt(void) const
        { return m_currDirective; }

    /* Because the DELTA spec defines different rules for allowed for
       characters before and after the comment deliminters depending on
       context (i.e. the rules are different when parsing attributes)
       these functions return a result based not only on the character at
       pos, but also the current 'parse context'
     */
    bool isCommentStart(QChar ch, QChar prevCh) const;
    bool isCommentEnd(QChar ch, QChar nextCh) const;

    // context-based legal pre/post comment delim character strings
    QString determineLegalCommentPreChars(void) const;
    QString determineLegalCommentPostChars(void) const;
    inline QString getLegalCommentPreChars(void) const
        { return m_legalCommentPreChars; }
    inline QString getLegalCommentPostChars(void) const
        { return m_legalCommentPostChars; }

    void clear(void);
    void switchDirectiveCtxt(const DeltaDirectives::Def* directive);
    void switchFileContext(QString newFilename);

private:
    bool isLegalCommentPreChar(QChar ch) const;
    bool isLegalCommentPostChar(QChar ch) const;
    bool isLegalCommentPreOrPostCh(QChar ch, const QString &legalChars) const;

    const DeltaDirectives::Def* m_currDirective;
    int m_currCommentDepth;
    QString m_currFilename;
    QString m_currFilenameNoPath;
    int m_currLineNum;
    int m_currPosInFile;
    QString m_legalCommentPreChars;
    QString m_legalCommentPostChars;
};

#endif // DELTAPARSERPRIVATE_H
