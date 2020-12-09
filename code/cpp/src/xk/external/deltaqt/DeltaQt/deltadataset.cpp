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
#include "deltadataset.h"
#include "functions.h"

DeltaDataset::DeltaDataset()
{
    m_expectedCharCount = -1;
    m_expectedMaxStates = -1;
    m_expectedMaxItems = -1;
}

/** Adds the character <i>dChar</i> to the dataset. No check is made whether
  * or not <i>dChar</i> is a duplicate.
  */
void DeltaDataset::addCharacter(const DeltaCharacter& dChar)
{
    m_characters.append(dChar);
}


/** Adds <i>dItem</i> to the item list. No check is made for duplicates.
  */
void DeltaDataset::addItem(const DeltaItem& dItem)
{
    m_items.append(dItem);
}

/** Adds \a mandChar to the mandatory character list. No check is made for
  * duplicates.
  */
void DeltaDataset::addMandatoryChar(int charNum)
{
    m_mandatoryChars.append(charNum);
}

/** Adds \a iVal to the implicit values list. No check is made for
  * duplicates.
  */
void DeltaDataset::addImplicitValue(const DeltaImplicitValue& iVal)
{
    m_implicitValues.append(iVal);
}

/** Attaches the note <i>note</i> to character <i>charNum</i>. False
  * is returned if a character corresponding to <i>charNum</i>
  * could not be found, otherwise true.

  */
bool DeltaDataset::attachNoteToChar(int charNum, const QString& note)
{
    DeltaCharacter *dchar;
    dchar = getCharacter(charNum);
    if (dchar) {
        dchar->addNote(note);
    }
    return dchar != NULL;
}



/** Clears all characters and items from the dataset.
  */
void DeltaDataset::clear(void)
{
    m_characters.clear();
    m_items.clear();
    m_mandatoryChars.clear();
    m_expectedStatesPerChar.clear();
    m_expectedCharCount = -1;
    m_expectedMaxStates = -1;
    m_expectedMaxItems = -1;
}

/** Set (change) the DeltaCharacterType::TypeId type of the character
  * corresponding to <i>charNum</i>. If no character with a character number
  * of <i>charNum</i> can be found, this function does nothing and returns
  * false.
  */
bool DeltaDataset::setCharacterType(
        int charNum,
        DeltaCharacterType::TypeId type)
{
    DeltaCharacter *dchar;
    dchar = getCharacter(charNum);
    if (dchar) {
        dchar->setCharType(type);
    }
    return dchar != NULL;
}

/** Returns a list of strings (in DELTA format) representing the dataset.
  *
  * @note This function is not yet fully implemented and currently only
  * returns character and item descriptions
  */
QStringList DeltaDataset::dumpAsText(int maxLineWidth) const
{
    QStringList result;

    dumpAsText_chars(&result, maxLineWidth);
    dumpAsText_items(&result, maxLineWidth);

    return result;
}

QString DeltaDataset::genChars(int maxLineWidth) const
{
    QStringList strings;
    QString result;

    dumpAsText_chars(&strings, maxLineWidth);

    for (int i = 0; i < strings.count(); i++) {
        result += strings.at(i);
        if (strings.at(i) != "\n") result += "\n";
    }
    return result;
}

QString DeltaDataset::genItems(int maxLineWidth) const
{
    QStringList strings;
    QString result;

    dumpAsText_items(&strings, maxLineWidth);

    for (int i = 0; i < strings.count(); i++) {
        result += strings.at(i);
        if (strings.at(i) != "\n") result += "\n";
    }
    return result;
}

void DeltaDataset::dumpAsText_chars(QStringList* dest, int maxLineWidth) const
{
    QString tmpStr;

    dest->append("*CHARACTER LIST\n");
    for (int i = 0; i < m_characters.count(); i++) {
        QStringList rewrappedStrings;
        const DeltaCharacter* cdc = &m_characters[i];
        tmpStr = "#" + QString::number(cdc->charNum())
                + ". " + cdc->name() + "/";
        rewrappedStrings = breakStrToLineLen(tmpStr,
                                             maxLineWidth,
                                             0, 10);
        for (int cs = 0; cs < rewrappedStrings.count(); cs++) {
            dest->append(rewrappedStrings.at(cs));
        }

        if (cdc->type() == DeltaCharacterType::DCT_IntegerNumeric
                || cdc->type() == DeltaCharacterType::DCT_RealNumeric) {
            if (!cdc->units().isEmpty()) {
                tmpStr = cdc->units() + "/";
                rewrappedStrings = breakStrToLineLen(tmpStr,
                                                     maxLineWidth,
                                                     7, 10);
                for (int cs = 0; cs < rewrappedStrings.count(); cs++) {
                    dest->append(rewrappedStrings.at(cs));
                }
            }
        } else {
            /* Character states */
            DeltaCharacterStates states = cdc->states();
            for (int si = 0; si < states.count(); si++) {
                DeltaCharacterState *cs = &states[si];
                tmpStr = QString::number(cs->id()) + ". " + cs->name()
                        + "/";
                rewrappedStrings = breakStrToLineLen(tmpStr,
                                                     maxLineWidth,
                                                     7, 10);
                for (int cs = 0; cs < rewrappedStrings.count(); cs++) {
                    dest->append(rewrappedStrings.at(cs));
                }
            }
        }

        if (i < m_characters.count()-1) dest->append("\n");
    }
}

void DeltaDataset::dumpAsText_items(QStringList* dest, int maxLineWidth) const
{
    dest->append("*ITEM DESCRIPTIONS\n");
    for (int i = 0; i < m_items.count(); i++) {
        QString itemStr;
        QStringList rewrappedStrings;
        if (i != 0) dest->append("\n");
        itemStr = m_items.at(i).toDeltaString();
        rewrappedStrings = breakStrToLineLen(itemStr,
                                             maxLineWidth,
                                             0,0);//0, 4);
        for (int cs = 0; cs < rewrappedStrings.count(); cs++) {
            dest->append(rewrappedStrings.at(cs));
        }
    }
}

DeltaItemList* DeltaDataset::getItemList(void)
{
    return &m_items;
}

DeltaCharacterList* DeltaDataset::getCharacterList(void)
{
    return &m_characters;
}

DeltaCharacter* DeltaDataset::getCharacter(int charNum)
{
    int i;
    for (i = 0; i < m_characters.count(); i++) {
        if (m_characters.at(i).charNum() == charNum)
            break;
    }
    return i < m_characters.count() ? &m_characters[i] : NULL;
}

const DeltaCharacter* DeltaDataset::getCharacter_const(int charNum) const
{
    int i;
    for (i = 0; i < m_characters.count(); i++) {
        if (m_characters.at(i).charNum() == charNum)
            break;
    }
    return i < m_characters.count() ? &m_characters[i] : NULL;
}

QMap<int, int> DeltaDataset::getExpectedStatesPerChar(void) const
{
    return m_expectedStatesPerChar;
}


int DeltaDataset::maxCharacterStates(void) const
{
    int maxStateCount = 0;

    for (int i = 0; i < m_characters.count(); i++) {
        if (m_characters.at(i).stateCount() > maxStateCount) {
            maxStateCount = m_characters.at(i).stateCount();
        }
    }
    return maxStateCount;
}
