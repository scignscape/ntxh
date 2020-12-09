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

#ifndef DELTACHARACTERTYPE_H
#define DELTACHARACTERTYPE_H

#include <QString>

class DeltaCharacterType
{
public:

    // DCT = Delta Character Type
    // PT  = Pseudo Type
    typedef enum
    {
        DCT_UnorderedMultistate,
        DCT_OrderedMultistate,
        DCT_IntegerNumeric,
        DCT_RealNumeric,
        DCT_Text,

        DCT_PT_Variable,            ///< DELTA "Pseudo Type"
        DCT_PT_Unknown,             ///< DELTA "Pseudo Type"
        DCT_PT_NotApplicable,       ///< DELTA "Pseudo Type"

        DCT_PT_ERROR,               ///< Not DELTA type (used internally)
        DCT_PT_NOTSET               ///< Not DELTA type (used internally)
    } TypeId;

    typedef struct
    {
        TypeId id;      ///< Character type id (@see CharTypeId)
        QString abbr;   ///< Abbreviation for the char type used in DELTA files
        QString name;   ///< Non-abbreviated name
    } Def;


    DeltaCharacterType();

    static const Def* deltaCharType(TypeId id);

    static const Def* deltaCharType(QString abbrev);

    static QString name(TypeId id);

    static unsigned charTypesCount(void);


    /* ----------------------------------------------------------------------
     * Debugging functions
     */
    static void debugOutputCharTypes(void);

private:
    static const DeltaCharacterType::Def m_types[];

};

#endif // DELTACHARACTERTYPE_H
