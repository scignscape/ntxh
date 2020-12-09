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

#include "deltaparserphase2.h"
#include "deltasymbols.h"

DeltaParserPhase2::DeltaParserPhase2()
{
    m_dataset = NULL;
    m_log = NULL;
}

DeltaParserPhase2::DeltaParserPhase2(DeltaDataset* dataset,
                                     ParseLog* log)
{
    m_dataset = dataset;
    m_log = log;
}

/** Finalise parsing of the DELTA data. This function (and class) works on
  * the in-memory structures created by the DeltaParser::parse() family of
  * functions.
  *
  * @note This function is called by <i>DeltaParser::parse(DeltaDataset* dataset,
  * const QStringList& filenames, bool abortOnAnyReadError = false)</i>
  * so normally there is no reason to call this function in user code.
  * However, if the user code used <i>DeltaParser::parse(DeltaDataset* dataset,
  * const QString& fname)</i> instead, then this function will need to
  * be called by user code directly.
  *
  * @note This function is called AFTER all the input files have been parsed;
  *         I.e. Item attribute values have been pre-parsed using
  *         preParseItemAttribute()  (called during Phase-1 parsing)
  */
bool DeltaParserPhase2::finalParseItemAttributes(void)
{
    DeltaItemList* items;
    DeltaAttributeList* attrs;
    bool r = true;

    Q_ASSERT(m_dataset != NULL && m_log != NULL);

    items = m_dataset->getItemList();
    for (int i = 0; i < items->count(); i++) {
        attrs = (*items)[i].getAttrListNotConst();
        for (int a = 0; a < attrs->count(); a++) {
            r = parseItemAttributes((*attrs)[a]);
        }
    }
    return r;
}

bool DeltaParserPhase2::parseItemAttributes(DeltaAttribute& dAttr)
{
    bool r;

    r = parseAttributeValues(dAttr);
    if (r) dAttr.setValuesAreParsed(true);

    return r;
}


bool DeltaParserPhase2::parseAttributeValues(DeltaAttribute& dAttr)
{
    DelimitedBuffer origValStr;
    QList<QString> chunkList;
    bool r = true;
    DeltaAttributeValueSet dAttrValueSet;

    origValStr.append(dAttr.origAttrValsStr());

    /* Giving logical OR lower precedence for DELTA values...*/
    if (origValStr.contains(DELTA_DELIM_ITEMATTR_OR)) {
        origValStr.getTokens(&chunkList,
                        DELTA_DELIM_ITEMATTR_OR,
                        DELTA_DELIM_STARTCOMMENT,
                        DELTA_DELIM_ENDCOMMENT,
                        QString(),
                        QString(),
                        false,
                        false,
                        true  // remove leading DELTA_DELIM_ITEMATTR_OR chars
                        );
    } else {
        chunkList.append(origValStr.trimmed());
    }
    for (int i = 0; i < chunkList.count(); i++) {
        DelimitedBuffer elementSetStr;
        const DeltaCharacter* dChar;

        // Check the attribute is referring to a valid delta character
        dChar = m_dataset->getCharacter(dAttr.charNum());
        if (!dChar) {
            m_log->appendVbsErr("Parse Phase-2",
                                "Parsing attributes: Unknown character #: "
                                + QString::number(dAttr.charNum()));
            return false;
        }

        elementSetStr = chunkList.at(i).trimmed();
        if (!elementSetStr.isEmpty()) {
            r = parseAttributeValueSet(dChar->type(),
                                       elementSetStr,
                                       dAttr,
                                       dAttrValueSet);
            if (!r) break;
        }
        if (r && !dAttrValueSet.isEmpty()) {
            dAttr.addValueSet(dAttrValueSet);
            dAttrValueSet.clear();
        }
    }

    return r;
}

bool DeltaParserPhase2::parseAttributeValueSet(
            DeltaCharacterType::TypeId cTypeId,
            const DelimitedBuffer& elementSetStr,
            DeltaAttribute& attr,
            DeltaAttributeValueSet& dAttrValueSet)
{

    QList<QString> chunkList;
    DelimitedBuffer input;
    DeltaValueRange range;
    AnnotatedValue val;

    input = elementSetStr;

    input.getTokens(&chunkList,
                    DELTA_DELIM_ITEMATTR_AND,
                    DELTA_DELIM_STARTCOMMENT,
                    DELTA_DELIM_ENDCOMMENT,
                    QString(),
                    QString(),
                    false,
                    false,
                    true  // remove leading DELTA_DELIM_ITEMATTR_AND chars
                    );

    for (int i = 0; i < chunkList.count(); i++) {
        switch (cTypeId)
        {
        case DeltaCharacterType::DCT_UnorderedMultistate:
        case DeltaCharacterType::DCT_OrderedMultistate:
            if (range.init(chunkList.at(i).trimmed(), m_log)) {
                // Not checking for extreme values here, just the number of
                // 'normal' values, because there should be no extreme values
                // for multistate types
                if (range.normalValueCount() == 1) {
                    dAttrValueSet.addValue(range.at(0));
                } else {
                    dAttrValueSet.addValue(range);
                }
            } else {
                tryParseAsPseudoValue(chunkList.at(i), attr);
            }
            break;
        case DeltaCharacterType::DCT_IntegerNumeric:
        case DeltaCharacterType::DCT_RealNumeric:
            if (range.init(chunkList.at(i).trimmed(), m_log)) {
                dAttrValueSet.addValue(range);
            } else {
                tryParseAsPseudoValue(chunkList.at(i), attr);
            }

            break;
        case DeltaCharacterType::DCT_Text:
            val.setValue(chunkList[i].trimmed());
            dAttrValueSet.addValue(val);
            break;
        default:
            m_log->appendVbsErr("Internal Error, Parse Phase-2",
                                " unhandled character type");
        }
    }
    return true;
}


bool DeltaParserPhase2::tryParseAsPseudoValue(
            const QString& valueStr,
            DeltaAttribute& attr)
{
    DelimitedBuffer origValStr;
    QString origValStrNC;       // orignal string with no comments
    bool r = false;
    QString comment;

    origValStr.append(valueStr);

    origValStr.mapDelimBoundaries(DELTA_DELIM_STARTCOMMENT,
                                  DELTA_DELIM_ENDCOMMENT);
    origValStrNC = origValStr.getStringsAppended(-1, 0, 0);

    if (origValStrNC == DELTA_PSEUDOVAL_UNKNOWN) {
        comment = origValStr.getLevel1Comments();
        attr.addPseudoValue(DeltaAttributeValue::UNKNOWN, comment);
        r = true;
    }
    else if (origValStrNC == DELTA_PSEUDOVAL_VARIABLE) {
        comment = origValStr.getLevel1Comments();
        attr.addPseudoValue(DeltaAttributeValue::VARIABLE, comment);
        r = true;
    }
    else if (origValStrNC == DELTA_PSEUDOVAL_NOTAPPLICABLE) {
        comment = origValStr.getLevel1Comments();
        attr.addPseudoValue(DeltaAttributeValue::NOTAPPLICABLE, comment);
        r = true;
    }

    return r;
}
