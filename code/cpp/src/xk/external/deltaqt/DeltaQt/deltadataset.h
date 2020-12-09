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

#ifndef DELTADATASET_H
#define DELTADATASET_H

#include <QStringList>
#include <QList>
#include <QMap>
#include "deltacharacter.h"
#include "deltaitem.h"
#include "annotatedvalue.h"
#include "globals.h"
#include "deltaimplicitvalue.h"

class DeltaDataset
{
    friend class DeltaParserPhase2;
    friend class DeltaParser;

public:
    DeltaDataset();

    void addCharacter(const DeltaCharacter& dChar);
    void addItem(const DeltaItem& dItem);
    void addMandatoryChar(int charNum);
    void addImplicitValue(const DeltaImplicitValue& iVal);

    bool attachNoteToChar(int charNum, const QString& note);
    void clear(void);
    bool setCharacterType(int charNum, DeltaCharacterType::TypeId type);

    QStringList dumpAsText(int maxLineWidth = DEF_TEXTOUT_MAXLINEWIDTH) const;
    QString genChars(int maxLineWidth = DEF_TEXTOUT_MAXLINEWIDTH) const;
    QString genItems(int maxLineWidth = DEF_TEXTOUT_MAXLINEWIDTH) const;

    inline int charCount(void) const { return m_characters.count(); }
    inline int charStateCount(int charNum) const;
    inline int itemCount(void) const { return m_items.count(); }

    inline int expectedCharCount(void) const { return m_expectedCharCount; }
    inline int expectedMaxStates(void) const { return m_expectedMaxStates; }
    inline int expectedMaxItems(void) const { return m_expectedMaxItems; }

    DeltaItemList* getItemList(void);
    DeltaCharacterList* getCharacterList(void);
    DeltaCharacter* getCharacter(int charNum);
    const DeltaCharacter* getCharacter_const(int charNum) const;
    QMap<int, int> getExpectedStatesPerChar(void) const;

    int maxCharacterStates(void) const;

protected:
    void dumpAsText_chars(QStringList* dest, int maxLineWidth) const;
    void dumpAsText_items(QStringList* dest, int maxLineWidth) const;

private:

    DeltaCharacterList m_characters;
    DeltaItemList m_items;
    QList<int> m_mandatoryChars;
    QList<DeltaImplicitValue> m_implicitValues;

    int m_expectedCharCount;    // From 'specs' for data validation
    int m_expectedMaxStates;    // From 'specs' for data validation
    int m_expectedMaxItems;    // From 'specs' for data validation
    QMap<int, int> m_expectedStatesPerChar; // From 'specs' for data validation
};

#endif // DELTADATASET_H
