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
#include "deltacharactertype.h"
#include "globals.h"

const DeltaCharacterType::Def DeltaCharacterType::m_types[] =
{
    {DeltaCharacterType::DCT_UnorderedMultistate, "UM", "Multistate (Unordered)"},
    {DeltaCharacterType::DCT_OrderedMultistate,   "OM", "Multistate (Ordered)"},
    {DeltaCharacterType::DCT_IntegerNumeric,      "IN", "Numeric (Integer)"},
    {DeltaCharacterType::DCT_RealNumeric,         "RN", "Numeric (Real)"},
    {DeltaCharacterType::DCT_Text,                "TE", "Text"},

    {DeltaCharacterType::DCT_PT_Variable,       "V",  "Variable (Psuedo Type)"},
    {DeltaCharacterType::DCT_PT_Unknown,        "U",  "Unknown (Psuedo Type)"},
    {DeltaCharacterType::DCT_PT_NotApplicable,  "-",  "Not Applicable (Psuedo Type)"},
    {DeltaCharacterType::DCT_PT_ERROR,          "",  "ERROR (DeltaQt Pseudo Type)"}
};

DeltaCharacterType::DeltaCharacterType()
{
}

/** Returns the character type definition for the character with a TypeId of
  * <i>id</i>. If no definitions match <i>id</i> then NULL is returned.
  *
  * @see DeltaCharacterType::Def
  */
const DeltaCharacterType::Def* DeltaCharacterType::deltaCharType(TypeId id)
{
    unsigned i;

    for (i = 0; i < charTypesCount(); i++) {
        if (m_types[i].id == id) break;
    }
    return i < charTypesCount() ? &m_types[i]: NULL;
}

/** Returns the character type definition of the character with an abbreviated
  * name of <i>abbrev</i> (which is case-sensitive). If no character has an
  * abbreviation of <i>abbrev</i> NULL is returned.
  */
const DeltaCharacterType::Def* DeltaCharacterType::deltaCharType(QString abbrev)
{
    unsigned i;

    for (i = 0; i < charTypesCount(); i++) {
        if (m_types[i].abbr == abbrev) break;
    }
    return i < charTypesCount() ? &m_types[i] : NULL;
}

/** Returns the name of the character with TypeId <i>id</i>. If no character
  * matches <i>id</i> an empty string is returned.
  */
QString DeltaCharacterType::name(TypeId id)
{
    unsigned i;

    for (i = 0; i < charTypesCount(); i++) {
        if (m_types[i].id == id) break;
    }
    return i < charTypesCount() ? m_types[i].name : QString();
}

/** Returns the number of character types known by DeltaQt.
  */
unsigned DeltaCharacterType::charTypesCount(void)
{
    return sizeof (m_types) / sizeof (DeltaCharacterType::Def);
}


void DeltaCharacterType::debugOutputCharTypes(void)
{
#ifdef DELTAQT_DEBUG
    for (unsigned i = 0; i < charTypesCount(); i++) {
        qDebug() << "ID:" << (int)m_types[i].id
                 << "Abbr:" << QString(m_types[i].abbr)
                 << "Name:" << m_types[i].name;
    }
#endif
}

