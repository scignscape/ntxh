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

#ifndef DELTAPARSER_H
#define DELTAPARSER_H

#include <QString>
#include <QStringList>
#include <QFile>
#include <QList>
#include <QObject>
#include "parselog.h"
#include "deltaparserprivate.h"
#include "deltadirectives.h"
#include "delimitedbuffer.h"
#include "deltadataset.h"
#include "filenameandmeta.h"


class DeltaParser : public QObject
{
    Q_OBJECT

    friend class DeltaParserPhase2;

public:

    DeltaParser();

    bool parse(DeltaDataset* dataset,
               const QList<FilenameAndMeta>& files,
               bool invokePhase2Parsing = true,
               bool abortOnAnyReadError = false);

    bool parse(DeltaDataset* dataset,
               const QStringList& files,
               bool invokePhase2Parsing = true,
               bool abortOnAnyReadError = false);

    bool parse(DeltaDataset* dataset,
               const QString& fname,
               const QByteArray& codecName = DELTAQT_DEFAULT_CHARENCODING);

    bool doPhase2Processing(void);

    inline void setTextCodec(const char* codecName)
        { m_textCodecName = codecName; }
    inline const char* textCodec(void) const
        { return m_textCodecName; }

    // Misc
    const ParseLog& parseLog(void) const;

    ParseLog* parseLogPointer(void) { return m_parseLogPointer; }

protected:
    const QString& currFilename(void) const;
    const QString& currFilenameAndPath(void) const;

    bool parseFile(void);
    bool parse(DelimitedBuffer& dbuff);
    bool parseNewDirective(const QString& str, QString* data);
    bool parseData(const QString& str);

    // Characters
    bool parseDataCharList(const QString& str);
    bool parseCharDesc(DelimitedBuffer& dbuff, DeltaCharacter& dchar);
    DeltaCharacterType::TypeId parseCharacter_inferType(
            const QList<QString>& partList);
    bool parseCharFeatureDesc(const QString& str, DeltaCharacter& dchar);
    bool parseCharStateDescs(const QString& str, DeltaCharacter& dchar);
    bool parseDataCharTypes(const QString& str);

    // Items
    bool parseDataItemList(const QString& str);
    bool preParseItemAttrList(const QString& str, DeltaItem& dItem);
    bool preParseItemAttr(const QString& str, DeltaAttribute& dAttr);

    // Character notes
    bool parseCharNote(const QString& str);

    // Implicit values
    bool parseImplicitValues(const QString& str);
    bool parseImplicitVal(const QString& str);

    // Dependent characters
    bool parseDependentChars(const QString& str);
    bool parseDependents(const QString& str);
    DeltaCharacter* parseDepsControllingCh(const QString& str);
    bool parseDepsForChar(DeltaCharacter* dchar,
                          const QString& stateNumsStr,
                          const QString& charNumsStr);
    // Mandatory characters
    bool parseMandatoryChars(const QString& str);

    // Directives used for data validation
    bool parseNumOfChars(const QString& str);
    bool parseMaxStates(const QString& str);
    bool parseMaxItems(const QString& str);
    bool parseNumsOfStates(const QString& str);

signals:
    void sigDirectiveChanged(QString name);
    void sigNewCharacter(int cNum, QString name);
    void sigNewItem(QString name);

private:
    ParseLog m_log;
    ParseLog* m_parseLogPointer;   // pointer to m_parseLog
    DeltaDataset* m_dataset;
    DeltaParseContext m_context;
    DpReadBuffer m_readBuffer;
    bool m_phase2ParsingDone;
    int m_currLineNum;
    const char* m_textCodecName;
};


#endif // DELTAPARSER_H
