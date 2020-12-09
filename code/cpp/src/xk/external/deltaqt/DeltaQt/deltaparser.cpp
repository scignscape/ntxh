/*  Copyright 2012 Craig Robbins

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
#include <QObject>
#include <QFileInfo>
#include "deltaparser.h"
#include "deltadirectives.h"
#include "deltasymbols.h"
#include "deltaparserphase2.h"
#include "globals.h"
#include "functions.h"


DeltaParser::DeltaParser()
{
    m_parseLogPointer = &m_log;
    m_phase2ParsingDone = false;
    m_currLineNum = 1;
    m_textCodecName = DELTAQT_DEFAULT_CHARENCODING;
}

/** Parse each of the files in <i>filenames</i> and the results are stored in
  * <i>dataset</i>
  *
  * <i>dataset</i> is cleared by this function regardless of whether
  * parse errors occur or not (to read more than one set of files use different
  * DeltaDataset objects).
  *
  * The files are parsed in the same order as they are in filenames.
  *
  * If <i>abortOnAnyReadError</i> == false (the default) then errors
  * occurring when parsing a file does not cause the processing of subsequent
  * files to be skipped, although the contents of the dataset may be
  * incorrect (if the errors are simply "file not found" then the data read
  * is correct).
  *
  * If <i>invokePhase2Parsing</i> == true (the default) then phase-2 of the
  * processing will be invoked (see PARSING_METHOD.txt in the distribution
  * package); usually you will want this to occur.
  *
  * The parse log is cleared when calling this function. If you need to retain
  * the parse log from prior calls make a copy of it first.
  *
  * Returns true on success, otherwise false. This function (currently) has
  * no other way of reporting errors apart from the parse log. @todo In future
  * releases it may be appropriate to report and/or store errors in a way
  * other than only the parse log (for the major errors at least).
  *
  * After each of the files in filenames is read, Phase2 parsing is invoked.
  *
  * @see class DeltaParserPhase2
  * @see parse(DeltaDataset* dataset, const QString& fname)
  */
bool DeltaParser::parse(DeltaDataset* dataset,
                       const QList<FilenameAndMeta>& files,
                       bool invokePhase2Parsing,
                       bool abortOnAnyReadError)
{
    bool r = true;

    m_log.clear();
    dataset->clear();

    for (int i = 0; i < files.count(); i++) {
        QByteArray cnameba = files.at(i).codecName().toLatin1(); //.toAscii();
        r = parse(dataset, files.at(i).filename(), cnameba);
        if (!r && abortOnAnyReadError) break;
    }

    m_readBuffer.close();

    if (invokePhase2Parsing) {
        r = doPhase2Processing();
    }

    return r;
}

bool DeltaParser::parse(DeltaDataset* dataset,
                       const QStringList& files,
                       bool invokePhase2Parsing,
                       bool abortOnAnyReadError)
{

    QList<FilenameAndMeta> filesWithMeta;

    for (int i = 0; i < files.count(); i++) {
        QString filename = files.at(i);
        QString encoding = deltafile_Encoding(filename);
        if (encoding.isEmpty()) encoding = DELTAQT_DEFAULT_CHARENCODING;
        filesWithMeta += FilenameAndMeta(filename, encoding);
    }

    return parse(dataset, filesWithMeta,invokePhase2Parsing,
                 abortOnAnyReadError);
}


/** Parse a single file, storing the result in <i>dataset</i>. In most
  * instances it is not necessary to directly call this function (use
  * parse(DeltaDataset* dataset, const QStringList& filenames,
  * bool abortOnAnyReadError). However, if this function is called directly,
  * the following points should be noted:
  * - This function does <b>not</b> clear the dataset before parsing
  * - The parse log is <b>not</b> cleared by this function before parsing
  * - This function does <b>not</b> invoke Phase2 parsing that, among other
  *   things, converts DELTA attribute strings to values.
  *
  * @see parse(DeltaDataset* dataset, const QStringList& filenames,
  *      bool abortOnAnyReadError)
  * @see class DeltaParserPhase2
  */
bool DeltaParser::parse(DeltaDataset* dataset,
                        const QString& fname,
                        const QByteArray& codecName)
{
    m_dataset = dataset;

    if (!m_readBuffer.useFile(fname, codecName)) {
        m_log.appendStdErr(fname, "Failed to open file");
        return false;
    }
    m_context.switchFileContext(fname);

    return parseFile();
}


bool DeltaParser::doPhase2Processing(void)
{
    DeltaParserPhase2 dpp2(m_dataset, &m_log);
    m_phase2ParsingDone = dpp2.finalParseItemAttributes();
    return m_phase2ParsingDone;
}


/** Returns a reference to the parse log. Make a copy of the contents if you
  * intend to use the log after subsequent calls to parse() as the contents
  * will change.
  *
  * @todo Perhaps it would be better to return a copy the
  * parseLog and create a separate function for getting a reference to it.
  */
const ParseLog& DeltaParser::parseLog(void) const
{
    return m_log;
}

/****************************************************************************
 Protected functions
 ***************************************************************************/

const QString& DeltaParser::currFilename(void) const
{
    return m_context.m_currFilenameNoPath;
}

const QString& DeltaParser::currFilenameAndPath(void) const
{
    return m_context.m_currFilename;
}

bool DeltaParser::parseFile(void)
{
    bool success = true;

    m_log.appendVbsInfo(currFilename(), "Begin importing");

    QString str;
    QString breakChars;
    QChar firstChar;

    breakChars += QString(DELTA_DELIM_DIRECTIVE_BEGIN)
                    +  DELTA_DELIM_DATABLOCKBEGIN;

    m_currLineNum = 1;

    while ( (m_readBuffer.readUntil(m_context,
                                    breakChars,
                                    &str,
                                    &firstChar)) != -1 ) {
        QString directiveData;

        str = str.trimmed();
        if (str.isEmpty()) continue;
        if (firstChar == DELTA_DELIM_DIRECTIVE_BEGIN) {
            success = parseNewDirective(str, &directiveData);
            if (!directiveData.isEmpty()) {
                success = parseData(directiveData);
            }
        } else if (firstChar == DELTA_DELIM_DATABLOCKBEGIN) {
            success = parseData(str);
        } else {
            /// @todo Log this instead
            qDebug() << "UNKNOWN FIRST CHARACTER! Aborting";
            success = false;
            break;
        }
        m_currLineNum = m_readBuffer.currentLineNum();
    }

    if (success) {
        m_log.appendStdInfo(currFilename(), "Import Succeeded");
    } else {
        m_log.appendStdWarn(currFilename(), "Import failed");
    }

    return success;
}


bool DeltaParser::parseNewDirective(const QString& str, QString* data)
{
    const DeltaDirectives::Def* dDef;

    dDef = DeltaDirectives::def(str);
    m_context.switchDirectiveCtxt(dDef);

    if (dDef->id == DeltaDirectives::PSEUDO_NONE
            || dDef->id == DeltaDirectives::PSEUDO_UNKNOWN) {
        m_log.appendVbsWarn(currFilename(),
                            "Unknown Directive: "
                            + str.mid(0, str.indexOf("\n")), m_currLineNum);
        return true;    // Unknown is not an error (just ignore)
    }

    *data = str.mid(dDef->controlPhrase.length()).trimmed();

    return true;
}


bool DeltaParser::parseData(const QString& str)
{
    bool result = true;
    const DeltaDirectives::Def* dDef;

    dDef = m_context.directiveCtxt();

    switch (dDef->id)
    {
    case DeltaDirectives::SHOW:
        m_log.appendVbsWarn(currFilename(), "Directive known, but ignored. ("
                            + dDef->controlPhrase + ")",
                            m_currLineNum);
        break;
    case DeltaDirectives::IMPLICITVALUES:
        result = parseImplicitValues(str.simplified());
        break;
    case DeltaDirectives::DEPENDENTCHARS:
        result = parseDependentChars(str.simplified());
        break;
    case DeltaDirectives::MANDATORYCHARS:
        result = parseMandatoryChars(str.simplified());
        break;
    case DeltaDirectives::COMMENT:
        break;
    case DeltaDirectives::CHARLIST:
        result = parseDataCharList(str);
        break;
    case DeltaDirectives::CHARNOTES:
        result = parseCharNote(str);
        break;
    case DeltaDirectives::CHARTYPES:
        result = parseDataCharTypes(str);
        break;
    case DeltaDirectives::ITEMDESCS:
        result = parseDataItemList(str);
        break;
    case DeltaDirectives::NUMBEROFCHARS:
        result = parseNumOfChars(str.simplified());
        break;
    case DeltaDirectives::MAXSTATES:
        result = parseMaxStates(str.simplified());
        break;
    case DeltaDirectives::MAXITEMS:
        result = parseMaxItems(str.simplified());
        break;
    case DeltaDirectives::NUMBERSOFSTATES:
        result = parseNumsOfStates(str.simplified());
        break;
    case DeltaDirectives::CHARIMAGES:
    case DeltaDirectives::TAXONIMAGES:
        // TODO Implement
        m_log.appendVbsWarn(currFilename(),
                            "Directive known, but not yet "
                            "implemented (" + dDef->controlPhrase + ")",
                            m_currLineNum);
        break;
    default:
        // Pseudo directives are handled by the calling function, so the default
        // case should never be entered...
        m_log.appendVbsErr(currFilename(),
                           "Internal error: Unhandled Directive ("
                           + QString(__FILE__) + ":" + QString(__LINE__));
        result = false;
        break;
    }

    return result;
}


/****************************************************************************
  CHARACTER LIST
 ***************************************************************************/

bool DeltaParser::parseDataCharList(const QString& str)
{
    QList<QString> chunkList;
    DelimitedBuffer dbuff;
    DelimitedBuffer cDescChunk;
    DeltaCharacter dchar;
    bool result = true;

    int numCharsParsed = 0;

    dbuff.append(str);
    dbuff.getTokens(&chunkList,
                    DELTA_DELIM_FEATUREDESC_BEGIN,
                    DELTA_DELIM_STARTCOMMENT,
                    DELTA_DELIM_ENDCOMMENT,
                    m_context.determineLegalCommentPreChars(),
                    m_context.determineLegalCommentPostChars(),
                    true,      // '#' at start of line or preceded by space
                    false      // don't check characters following '#'
                    );

    for (int i = 0; i < chunkList.count(); i++) {

        cDescChunk = chunkList[i].trimmed();

        dchar.clear();
        result = parseCharDesc(cDescChunk, dchar);

        if (dchar.isValid()) {
            numCharsParsed++;
            m_dataset->addCharacter(dchar);
            emit sigNewCharacter(dchar.charNum(), dchar.name());
        }
    }

    return result;
}


bool DeltaParser::parseCharDesc(DelimitedBuffer& dbuff, DeltaCharacter& dchar)
{
    QList<QString> chunkList;
    QString chunk;
    DeltaCharacterType::TypeId ctypeId;
    bool r = true;

    /* Split by DELTA_CHAR_CHARDESC_PARTEND; Will not split on positions where
     * DELTA_CHAR_CHARDESC_PARTEND is not followed by EOL or a space.
     *
     * DELTA_CHAR_CHARDESC_PARTEND in the DELTA 2005 Std is the '/' character.
     */
    dbuff.getTokens(&chunkList,
                    DELTA_DELIM_CHARDESC_PARTEND,
                    DELTA_DELIM_STARTCOMMENT,
                    DELTA_DELIM_ENDCOMMENT,
                    m_context.determineLegalCommentPreChars(),
                    m_context.determineLegalCommentPostChars(),
                    false,      // Any characters preceding '/' are ok
                    true,       // '/' must be at EOL or followed by space
                    true        // remove '/' from start of line
                    );

    if (chunkList.isEmpty()) {
        return false;  // A (DELTA) character has to have at least a number
    }

    ctypeId = parseCharacter_inferType(chunkList);
    dchar.setCharType(ctypeId);

    /* First chunk is the 'feature description'
     */
    chunk = chunkList[0];
    if (chunk.at(0) == DELTA_DELIM_FEATUREDESC_BEGIN)
        chunk = chunk.mid(1).trimmed();

    if (chunk.isEmpty()) return false;

    if ((r = parseCharFeatureDesc(chunk, dchar)) == false)
        return r;

    // Parse the rest of the chunks ('state descriptions')
    for (int i = 1; i < chunkList.count(); i++) {
        r = parseCharStateDescs(chunkList[i].trimmed(), dchar);
    }

    return r;
}


DeltaCharacterType::TypeId
DeltaParser::parseCharacter_inferType(const QList<QString>& partList)
{
    /* Try and infer the character type (which may be reassigned by a
     * CHARTYPES directive).
     *
     * NOTE: What "directive level" is CHARTYPES and can it occur before
     * CHARLIST? If it _can_ occur before CHARLIST then this inference should
     * be ignored if the character already has a type assigned.
     */

    // Default to UnorderedMultistate (see Dallwitz & Paine 2005, p5)
    DeltaCharacterType::TypeId ctypeId
            = DeltaCharacterType::DCT_UnorderedMultistate;

    Q_ASSERT (partList.count() > 0);

    if (partList.count() > 1) {
        /* Single item multistates are allowable, so check if the first
         * state appears to represent a state; i.e. of the form "n. text"
         * where n is a number.
         */
        DelimitedBuffer part = partList[1];

        if (!part.isEmpty()) {
            int pos = part.indexOf('.');
            if (pos != -1) {
                QString numStr;
                bool ok;
                numStr = part.getChunk(0, pos - 1);
                // If numstr is empty, toInt() will fail
                numStr.toInt(&ok);
                ctypeId = ok ? DeltaCharacterType::DCT_UnorderedMultistate
                             : DeltaCharacterType::DCT_IntegerNumeric;
            } else {
                ctypeId = DeltaCharacterType::DCT_IntegerNumeric;
            }
        } else {
            Q_ASSERT_X (true,
                        "DeltaParser::parseCharacter_inferType()",
                        "Should never be here!");
        }
    }

    return ctypeId;
}


bool DeltaParser::parseCharFeatureDesc(
        const QString& str,
        DeltaCharacter& dchar)
{
    int chId;
    QString numStr;
    bool ok;

    int endPos = str.indexOf('.');
    if (endPos == -1) {
        m_log.appendVbsWarn(currFilename(),
                            "Syntax error (ignoring):" + str,
                            m_currLineNum);
        return false;
    }

    numStr = str.mid(0, endPos);
    chId = numStr.toInt(&ok);
    if (!ok) {
        m_log.appendVbsErr(currFilename(),
                           "Error converting character number: '" + str + "'",
                           m_currLineNum);
        return false;
    }
    dchar.setDeltaCharNum(chId);
    if (endPos < str.size() - 1) {
        // .simplify() to convert \n to spaces
        QString name = str.mid(endPos+1).simplified();
        if (!name.isEmpty()) {
            dchar.setName(name);
        }
    }
    if (dchar.name().isEmpty()) {
        m_log.appendVbsWarn(currFilename(),
                            "Character has no name. Char #"
                            + QString::number(dchar.charNum()),
                            m_currLineNum);
    }

    return true;
}


bool DeltaParser::parseCharStateDescs(const QString& str,
                                      DeltaCharacter& dchar)
{
    int sId;
    int endPos;

    switch (dchar.type())
    {
    case DeltaCharacterType::DCT_IntegerNumeric:
    case DeltaCharacterType::DCT_RealNumeric:
        dchar.setUnits(str);
        break;
    case DeltaCharacterType::DCT_OrderedMultistate:
    case DeltaCharacterType::DCT_UnorderedMultistate:
        endPos = str.indexOf('.');
        if (endPos != -1) {
            QString numStr;
            bool ok;
            numStr = str.mid(0, endPos);
            sId = numStr.toInt(&ok);
            if (!ok) {
                m_log.appendVbsErr(currFilename(),
                                   "Could not convert state# to int. "
                                   "(Character # "
                                   + QString::number(dchar.charNum())
                                   + "). '" + str + "'",
                                   m_currLineNum);
                return false;
            }
            if (endPos < str.size() - 1) {
                QString name = str.mid(endPos+1).simplified();
                dchar.addState(sId, name);
                if (name.isEmpty()) {
                    m_log.appendVbsWarn(currFilename(),
                                        "No name for state# "
                                        + QString::number(sId)
                                        + "(Character # "
                                        + QString::number(dchar.charNum())
                                        + ")",
                                        m_currLineNum);
                }
            }
        } else {
            m_log.appendVbsErr(currFilename(),
                               "Multistate state without state num. "
                               "Character # "
                               + QString::number(dchar.charNum())
                               + "). '" + str + "'",
                               m_currLineNum);
        }
        break;
    default:
        const DeltaCharacterType::Def* ctdef
                = DeltaCharacterType::deltaCharType(dchar.type());
        if (ctdef == NULL) {
            m_log.appendVbsErr(currFilename(),
                               "Parsing state; unknown character type.",
                               m_currLineNum);
            return false;
        } else {
            m_log.appendVbsWarn(currFilename(),
                                "Parsing state; unhandled character type: "
                                + ctdef->name + " (" + ctdef->abbr + ")",
                                m_currLineNum);
        }
        break;
    }

    return true;
}


/****************************************************************************
  CHARACTER TYPES
 ***************************************************************************/

bool DeltaParser::parseDataCharTypes(const QString& str)
{
    DelimitedBuffer dbuff;
    QList<QString> chunkList;
    bool result = true;

    dbuff.append(str.simplified()); // want '\n' as space

    dbuff.getTokens(&chunkList,
                    DELTA_DELIM_CHARTYPE_SEPARATOR,
                    DELTA_DELIM_STARTCOMMENT,
                    DELTA_DELIM_ENDCOMMENT
                    );

    for (int i = 0; i < chunkList.count() && result == true; i++) {
        DelimitedBuffer element;
        QList<QString> elementItemChunks;

        element = chunkList[i];

        element.getTokens(&elementItemChunks,
                          ',',
                          DELTA_DELIM_STARTCOMMENT,
                          DELTA_DELIM_STARTCOMMENT,
                          QString(),
                          QString(),
                          false,
                          false,
                          true      // remove ',' from start of chunks
                          );

        if (elementItemChunks.count() != 2) {
            m_log.appendVbsErr(currFilename(),
                               "Invalid character type description: '"
                               + dbuff.simplified() + "'",
                               m_currLineNum);
            result = false;
        } else {
            const DeltaCharacterType::Def* typeDef;
            DelimitedBuffer cnumStr = elementItemChunks[0];
            QString typeStr = elementItemChunks[1];

            // Get the type definition associate with the abbrev (typeStr)
            typeDef = DeltaCharacterType::deltaCharType(typeStr);
            if (!typeDef) {
                m_log.appendVbsErr(currFilename(),
                                   "Invalid character type: '"
                                   + typeStr + "'",
                                   m_currLineNum);
                result = false;
            } else {
                DeltaValueRange dvr;
                QList<AnnotatedValue> charNums;

                // cnumStr is either a single number or a range
                dvr.init(cnumStr, &m_log);
                charNums = dvr.getExpandedValueList();

                for (int i2 = 0; i2 < charNums.count(); i2++) {
                    bool ok;
                    int val = charNums[i2].toInt(&ok);
                    if (!ok) {
                        m_log.appendStdErr(currFilename(),
                                           "Conversion error; could not "
                                           "convert character # to integer",
                                           m_currLineNum);
                    } else if (!m_dataset->setCharacterType(val, typeDef->id)) {
                        m_log.appendStdErr(currFilename(),
                                           "Character number does not exist:"
                                           + QString::number(val),
                                           m_currLineNum);
                        result = false;
                    }
                }
            }
        }
    }

    return result;
}


/****************************************************************************
  ITEM DESCRIPTIONS
 ***************************************************************************/

bool DeltaParser::parseDataItemList(const QString& str)
{
    QList<QString> chunkList;
    DelimitedBuffer dbuff;
    DelimitedBuffer chunk;
    DeltaItem dItem;

    /* Dallwitz & Paine 2005, p5:
     "An item description consists of the item name followed by a set of
     attributes."

     "The item name is terminated by a slash (/), which must be at the
     end of a line or followed by a blank. A slash not followed by a blank or
     end of line is allowed, and does not constitute a terminating slash."
     */
    dbuff.append(str);
    dbuff.getTokens(&chunkList,
                    DELTA_DELIM_ITEMNAME_END,
                    DELTA_DELIM_STARTCOMMENT,
                    DELTA_DELIM_ENDCOMMENT,
                    m_context.determineLegalCommentPreChars(),
                    m_context.determineLegalCommentPostChars(),
                    false,
                    true,      // Must be followed by blank or EOL
                    true        // remove '/' from start of lines
                    );

    /* Must encounter at least one split point between name and data
     */
    if (chunkList.count() != 2) {
        qDebug() << "todo: log error" << __FILE__<< __LINE__;
        return false;
    }

    // Get item name
    DelimitedBuffer namePart;
    namePart = chunkList[0];

    if (namePart.isEmpty()) {
        m_log.appendVbsErr(currFilename(),
                           "Item is empty: '"
                           + dbuff.simplified() + "'",
                           m_currLineNum);
        return false;
    }

    dItem.setName(namePart);

    /* We want .simplified() here so that '\n' are converted to a space
     * as attributes are delimited by a space
     */
    QString dataPart = chunkList[1].simplified();

    if (!dataPart.isEmpty()) {
        preParseItemAttrList(dataPart, dItem);
    }

    m_dataset->addItem(dItem);
    emit sigNewItem(dItem.name());
    return true;

}


bool DeltaParser::preParseItemAttrList(const QString& str,
                                       DeltaItem& dItem)
{
    QList<QString> chunkList;
    DelimitedBuffer dbuff;
    QString chunk;

    dbuff.append(str);
    dbuff.getTokens(&chunkList,
                    DELTA_DELIM_ITEMATTR_SEPARATOR,
                    DELTA_DELIM_STARTCOMMENT,
                    DELTA_DELIM_ENDCOMMENT);

    for (int i = 0; i < chunkList.count(); i++) {
        DeltaAttribute dAttr;

        chunk = chunkList[i];//.trimmed();

        if (preParseItemAttr(chunk, dAttr))
            dItem.addAttribute(dAttr);
    }

    return true;
}


bool DeltaParser::preParseItemAttr(const QString& str,
                                   DeltaAttribute& dAttr)
{
    QList<QString> chunkList;
    int charNum;
    bool ok;
    DelimitedBuffer dbuff;
    DelimitedBuffer chunk;
    QString tmp_s;

    /* Separate by ','. The first item in the separated list is
     * the character number, followed by a list of attribute values
     */
    dbuff.append(str);
    dbuff.getTokens(&chunkList,
                    DELTA_DELIM_CHARVAL_SEPARATOR,
                    DELTA_DELIM_STARTCOMMENT,
                    DELTA_DELIM_ENDCOMMENT,
                    m_context.determineLegalCommentPreChars(),
                    m_context.determineLegalCommentPostChars(),
                    false,
                    false,
                    true
                    );

    if (chunkList.count() == 0) {
        // attribute with only comments
        chunkList.append(dbuff);    // whole string as charNum part
        chunkList.append("");       // no attributes
    }

    // chunkList[0] is the charnum
    // chunkList[1] is the attribute list

    // map comments so we can store them
    chunk = chunkList[0];
    chunk.mapDelimBoundaries(DELTA_DELIM_STARTCOMMENT,
                             DELTA_DELIM_ENDCOMMENT);
        // chunk without comments
    tmp_s = chunk.getStringsAppended(',', 0 ,0, false);
    charNum = tmp_s.toInt(&ok);
        // comments
    tmp_s = chunk.getStringsAppended(',', 1, 1, false);

    if (!ok) {
        m_log.appendVbsErr(currFilename(),
                           "Invalid attribute character #: '"
                           + tmp_s,
                           m_currLineNum);
        return false;
    } else {
        dAttr.setCharNum(charNum);
        if (!tmp_s.isEmpty()) {
            Q_ASSERT (tmp_s[0] == DELTA_DELIM_STARTCOMMENT
                      && tmp_s[tmp_s.length()-1] == DELTA_DELIM_ENDCOMMENT);
            // Remove the comment delimiters
            tmp_s.chop(1);
            tmp_s = tmp_s.mid(1).trimmed();
        }
        dAttr.setComment(tmp_s);
        dAttr.setValuesAreParsed(false);
        if (chunkList.count() == 2) {
            dAttr.setOrigAttrValsStr(chunkList[1]);
        } // else no values (e.g. if the attribute was entirely of comments)
    }
    return true;
}

/****************************************************************************
  CHARACTER NOTES
 ***************************************************************************/

/* TODO: chunkList.count() always == 1? (CHECK) If so get rid of loop */
bool DeltaParser::parseCharNote(const QString& str)
{
    QList<QString> chunkList;
    DelimitedBuffer dbuff;
    DelimitedBuffer chunk;
    int numSetEndPos;

    dbuff.append(str);

    dbuff.getTokens(&chunkList,
                    DELTA_DELIM_CNOTES_BEGIN,
                    DELTA_DELIM_STARTCOMMENT,
                    DELTA_DELIM_ENDCOMMENT,
                    QString(),
                    QString(),
                    true,   // prev char must be whitespace to be start of note
                    false,
                    true    // remove '#' from start of chunks
                    );

    for (int i = 0; i < chunkList.count(); i++) {

        chunk = chunkList[i].trimmed(); // \n is allowed in the notes

        if (chunk.isEmpty()) continue;

        /* Dallwitz, Paine & Zurcher 2008, p15:
          #si. ti
          where si is a set of character numbers and ti is any text.
          si takes the form
          c1:c2:...cj:...
          where cj is a character number or range of numbers.
         */
        numSetEndPos = chunk.indexOf('.');
        // If missing character number just ignore
        if (numSetEndPos < 1 || numSetEndPos == chunk.length()-1) {
            m_log.appendStdWarn(currFilename(),
                                QString("Non-fatal syntax error - Parsing ")
                                + "CHARACTER NOTES'"
                                + chunk + "'",
                                m_currLineNum);
        } else {

            QList<QString> numSet;
            QList<int> charNums;
            // 'split' further (on ':')
            numSet = chunk.getChunk(0, numSetEndPos).split(':');
            for (int i = 0; i < numSet.count(); i++) {
                QString numStr = numSet[i];
                if (numStr.isEmpty()) continue;
                if (numStr.right(1) == ".") numStr.chop(1);
                if (!numStr.isEmpty()) {
                    QString noteText;
                    DeltaValueRange dvr;
                    DelimitedBuffer numStrBuff; // FIXME When DelimitedBuffer is rewritten/replaced
                    numStrBuff.append(numStr);  // FIXME When DelimitedBuffer is rewritten/replaced
                    dvr.init(numStrBuff, &m_log);

                    noteText = chunk.getChunk(numSetEndPos+1).trimmed();
                    charNums = dvr.getExpandedIntList();

                    // Add note to characters
                    for (int i2 = 0; i2 < charNums.count(); i2++) {
                        m_dataset->attachNoteToChar(charNums[i2], noteText);
                    }
                }
            }
        }
    }

    return true;
}

/****************************************************************************
  IMPLICIT VALUES
 ***************************************************************************/
bool DeltaParser::parseImplicitValues(const QString& str)
{
    QList<QString> chunkList;
    DelimitedBuffer dbuff;
    QString chunk;

    // Format: c1,s1:t1 c2,s2:t2...ci,si:ti...

    dbuff.append(str);
    dbuff.getTokens(&chunkList,
                    DELTA_DELIM_IVAL_SEPARATOR,
                    DELTA_DELIM_STARTCOMMENT,
                    DELTA_DELIM_ENDCOMMENT);

    for (int i = 0; i < chunkList.count(); i++) {
        // Chunk format: c1,s1:t1
        chunk = chunkList.at(i);
        parseImplicitVal(chunk);
    }

    return true;
}

bool DeltaParser::parseImplicitVal(const QString& str)
{
    QStringList parts;
    QStringList valStrings;
    bool ok;
    int s;
    int t = -1; // default to 'not set'

    // Format: c,s:t
    // c can be a single value, or range of values
    parts = str.split(DELTA_DELIM_IVAL_PARTSEP);
    if (parts.count() != 2) {
        m_log.appendStdErr(currFilename(),
                           "Syntax error: malformed implicit value: "
                           + str);
        return false;
    }

    // parts[0] is char number or range
    QList<int> charNums;
    DeltaValueRange dvr;
    dvr.init(parts.at(0), &m_log);
    charNums = dvr.getExpandedIntList();

    if (charNums.count() == 0) {
        m_log.appendStdErr(currFilename(),
                           "Syntax error: no character number(s) for implicit"
                           " values: "
                           + str);
        return false;
    }

    // parts[1] is 's' or 's:t'
    valStrings = parts.at(1).split(DELTA_DELIM_IVAL_VALSEP);
    if (valStrings.count() != 1 && valStrings.count() != 2 ) {
        m_log.appendStdErr(currFilename(),
                           "Syntax error: malformed implicit value: "
                           + str);
        return false;
    }

    s = valStrings.at(0).toInt(&ok);
    if (!ok) {
        m_log.appendStdErr(currFilename(),
                           "Implicit value, could not convert value"
                           " to integer: "
                           + str);
        return false;
    }
    if (valStrings.count() == 2) {
        t = valStrings.at(1).toInt(&ok);
        if (!ok) {
            m_log.appendStdErr(currFilename(),
                               "Implicit value, could not convert value"
                               " to integer: "
                               + str);
            return false;
        }
    }

    for (int i = 0; i < charNums.count(); i++) {
        DeltaImplicitValue ival(charNums.at(i), s, t);
        m_dataset->addImplicitValue(ival);
    }

    return true;
}

/****************************************************************************
  DEPENDENT CHARACTERS
 ***************************************************************************/
bool DeltaParser::parseDependentChars(const QString& str)
{
    // Format: c1,s1:d1 c2,s2:d2...ci,si:di...

    // Assuming comments are not allowed (does not appear so according to the
    // DELTA documentation)

    QStringList chunks = str.split(DELTA_DELIM_DEPCHAR_SEPARATOR);
    for (int i = 0; i < chunks.count(); i++) {
        parseDependents(chunks.at(i));
    }

    return true;
}

bool DeltaParser::parseDependents(const QString& str)
{
    // Format: c,s:d
    // c is the 'controlling character'
    // Format s: t1/t2/...tj/...
    // Format d: e1:e2:...ek:...
    // s is a set of state numbers (tj is a single value)
    // d is a set of character numbers (dependent characters)
    //      (ek is a single value or range)

    DeltaCharacter* dchar;

    QStringList parts = str.split(DELTA_DELIM_DEPCHAR_PARTSEP);
    if (parts.count() != 2) {
        m_log.appendStdErr(currFilename(),
                           "Syntax error: malformed dependent char decl: "
                           + str);
        return true;    // not fatal
    }

    dchar = parseDepsControllingCh(parts.at(0));
    if (!dchar) return true;    // not fatal

    // Find the first ':' and split on that
    int splitPoint = parts.at(1).indexOf(DELTA_DELIM_DEPCHAR_DEFSEP);
    if (splitPoint == -1 || splitPoint == str.length()-1) {
        m_log.appendStdErr(currFilename(),
                           "Syntax error: malformed dependent char decl: "
                           + str);
        return true;    // not fatal
    }

    Q_ASSERT (splitPoint < parts.at(1).length()-1);
    QString stateNumsStr = parts.at(1).mid(0, splitPoint).trimmed();
    QString charNumsStr = parts.at(1).mid(splitPoint+1, -1).trimmed();
    if (stateNumsStr.isEmpty() || charNumsStr.isEmpty()) {
        m_log.appendStdErr(currFilename(),
                           "Syntax error: malformed dependent char decl: "
                           + str);
        return true;    // not fatal
    }

    return parseDepsForChar(dchar, stateNumsStr, charNumsStr);

}

DeltaCharacter* DeltaParser::parseDepsControllingCh(const QString& str)
{
    int cnum;
    DeltaCharacter* dchar;
    bool ok;

    cnum = str.toInt(&ok);
    if (!ok) {
        m_log.appendStdErr(currFilename(),
                           "Dependent char, could not convert controlling"
                           "character number to integer: "
                           + str);
        return NULL;    // not fatal
    }

    dchar = m_dataset->getCharacter(cnum);
    if (!dchar) {
        m_log.appendStdErr(currFilename(),
                           "Parsing dependent characters, controlling"
                           "character does not exist (ignoring): "
                           + QString::number(cnum));
        return NULL;    // not fatal
    }
    if (!dchar->isMultistate()) {
        m_log.appendStdErr(currFilename(),
                            "Parsing dependent characters, controlling"
                            "character is not multistate (ignoring): "
                            + QString::number(cnum));
       return NULL;    // not fatal
    }

    return dchar;
}


bool DeltaParser::parseDepsForChar(DeltaCharacter* dchar,
                                   const QString& stateNumsStr,
                                   const QString& charNumsStr)
{
    // Format s: t1/t2/...tj/...
    // Format d: e1:e2:...ek:...
    // s is a set of state numbers (tj is a single value)
    // d is a set of character numbers (dependent characters)
    //      (ek is a single value or range)
    // stateNumsStr is 's'
    // charNumsStr is 'd'

    QStringList stateNumsStrList;
    QList<int> stateNums;
    QStringList charNumsStrList;
    QList<int> charNums;

    Q_ASSERT (!stateNumsStr.isEmpty());
    Q_ASSERT (!charNumsStr.isEmpty());

    stateNumsStrList = stateNumsStr.split(DELTA_DELIM_DEPCHAR_STATEDELIM);
    for (int i = 0; i < stateNumsStrList.count(); i++) {
        int s;
        bool ok;
        s = stateNumsStrList.at(i).toInt(&ok);
        if (!ok) {
            m_log.appendStdErr(currFilename(),
                               "Dependent char, could not convert state"
                               " number to integes: "
                               + stateNumsStrList.at(i));
            return true;    // not fatal
        }
        stateNums.append(s);
    }

    charNumsStrList = charNumsStr.split(DELTA_DELIM_DEPCHAR_CHARDELIM);
    for (int i = 0; i < charNumsStrList.count(); i++) {
        // May be a single value, or a range
        QList<int> chNums;
        DeltaValueRange dvr;
        dvr.init(charNumsStrList.at(i), &m_log);
        chNums = dvr.getExpandedIntList();
        charNums.append(chNums);
    }

    for (int s = 0; s < stateNums.count(); s++) {
        for (int d = 0; d < charNums.count(); d++) {
            dchar->addDependency(stateNums.at(s), charNums.at(d));
        }
    }

    return true;
}


/****************************************************************************
  MANDATORY CHARACTERS
 ***************************************************************************/
bool DeltaParser::parseMandatoryChars(const QString& str)
{
    QList<QString> chunkList;
    DelimitedBuffer dbuff;
    QString chunk;

    /** @internal @todo if mandatory chars can't have comments in them, then
      * modifiy this code to use QString::split() instead of DelimitedBuffer
      */
    dbuff.append(str);
    dbuff.getTokens(&chunkList,
                    DELTA_DELIM_MANDCHAR_DELIM,
                    DELTA_DELIM_STARTCOMMENT,
                    DELTA_DELIM_ENDCOMMENT);

    for (int i = 0; i < chunkList.count(); i++) {
        chunk = chunkList.at(i);
        if (chunk.contains(DELTA_DELIM_RANGE_OP)) {
            // range of values
            QList<int> charNums;
            DeltaValueRange dvr;
            dvr.init(chunk, &m_log);
            charNums = dvr.getExpandedIntList();
            for (int cn = 0; cn < charNums.count(); cn++) {
                m_dataset->addMandatoryChar(charNums.at(cn));
            }
        } else {
            // single value
            bool ok;
            int val = chunk.toInt(&ok);
            if (!ok) {
                m_log.appendStdErr(currFilename(),
                                   "Parsing mandatory character, could not "
                                   "convert to integer: " + chunk);
            } else {
                m_dataset->addMandatoryChar(val);
            }
        }
    }

    return true;
}

/****************************************************************************
  NUMBER OF CHARACTERS, MAXIMUM NUMBER OF STATES, MAXIMUM NUMBER OF ITEMS
 ***************************************************************************/
bool DeltaParser::parseNumOfChars(const QString& str)
{
    bool ok;
    int num;
    num = str.toInt(&ok);
    if (!ok) {
        m_log.appendStdErr(currFilename(),
                           "Parsing number of characters directive. Could not"
                           " convert to integer: " + str);
    } else {
        m_dataset->m_expectedCharCount = num;
    }

    return ok;
}

bool DeltaParser::parseMaxStates(const QString& str)
{
    bool ok;
    int num;
    num = str.toInt(&ok);
    if (!ok) {
        m_log.appendStdErr(currFilename(),
                           "Parsing maximum number of states directive. Could"
                           " not convert to integer: " + str);
    } else {
        m_dataset->m_expectedMaxStates = num;
    }

    return ok;
}

bool DeltaParser::parseMaxItems(const QString& str)
{
    bool ok;
    int num;
    num = str.toInt(&ok);
    if (!ok) {
        m_log.appendStdErr(currFilename(),
                           "Parsing maximum number of items directive. Could"
                           " not convert to integer: " + str);
    } else {
        m_dataset->m_expectedMaxItems = num;
    }

    return ok;
}

bool DeltaParser::parseNumsOfStates(const QString& str)
{
    QStringList pairs;
    bool r = true;

    pairs = str.split(" ");

    for (int i = 0; i < pairs.count(); i++) {
        QStringList vals;
        QString pairTrimmed = pairs.at(i).trimmed();
        if (pairTrimmed.isEmpty()) continue;
        vals = pairTrimmed.split(",");
        if (vals.count() != 2) {
            m_log.appendStdErr(currFilename(),
                               "Parsing maximum number of state directive."
                               " Item is not a pair: " + pairTrimmed);
            r = false;
            break;
        }
        // format c,s
        // where c is a character number or range and s is the number of states
        int numStates;
        bool ok;
        numStates = vals.at(1).toInt(&ok);
        if (!ok) {
            m_log.appendStdErr(currFilename(),
                               "Parsing maximum number of state directive."
                               " Could not convert to integer: " + pairTrimmed);
            r = false;
            break;
        }

        DeltaValueRange dvr;

        dvr.init(vals.at(0), &m_log);
        QList<int> cnums = dvr.getExpandedIntList();
        for (int c = 0; c < cnums.count(); c++) {
            /// @todo Check for duplicates!
            m_dataset->m_expectedStatesPerChar[cnums.at(c)] = numStates;
        }
    }
    // if an error occurred, the whole set is useless
    if (!r) m_dataset->m_expectedStatesPerChar.clear();

    return true;    // All errors a non-fatal
}
