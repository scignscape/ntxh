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

#ifndef DELTACHARACTER_H
#define DELTACHARACTER_H

#include <QString>
#include <QList>
#include "globals.h"
#include "deltacharactertype.h"
#include "deltadependentchars.h"


class DeltaCharacterState
{
public:
    DeltaCharacterState();
    DeltaCharacterState(int id, const QString& name);

    inline int id (void) const { return m_id; }

    inline QString name(void) const { return m_name; }

    void set(int id, const QString& name);

protected:
    int m_id;
    QString m_name;
};

typedef QList<DeltaCharacterState> DeltaCharacterStates;

/****************************************************************************/

/* Different types of DELTA characters probably should be inherited from the
 * base class DeltaCharacter, rather than having their extended attributes
 * embedded within DeltaCharacter, however this introduces some problems when
 * parsing DELTA text files. When parsing the text files, the character type
 * is often 'inferred' and reassigned at a later point in the parsing
 * process (e.g. if the CHARLIST directive is processes before the CHARTYPES
 * directive; the chars file is read before the specs file).
 */
class DeltaCharacter
{
public:
    DeltaCharacter();
    ~DeltaCharacter();
    DeltaCharacter(DeltaCharacterType::TypeId typeId);

    bool isValid(void) const;

    int charNum(void) const;
    QString name(void) const;
    inline const DeltaCharacterStates states(void) const { return m_states; }
    inline QString units(void) const { return m_units; }

    DeltaCharacterType::TypeId type(void) const;
    double weight(void) const;

    void addNote(const QString& note);
    void addState(int id, const QString& name);
    void addDependency(int stateNum, int depChar);
    void clear(void);
    void setCharType(DeltaCharacterType::TypeId type);
    int setDeltaCharNum(int to);
    int setReliability(int reliability);
    void setUnits(const QString& to);
    void setName(const QString& to);

    inline bool isMultistate(void) const
        { return m_charType == DeltaCharacterType::DCT_OrderedMultistate
                || m_charType == DeltaCharacterType::DCT_UnorderedMultistate; }

    inline bool depsAreInitalised(void) const
        { return m_deps.count() != 0; }

    inline int stateCount(void) const { return m_states.count(); }

protected:
    void m_initCommon(void);
    void m_setDefaults(void);

    DeltaCharacterType::TypeId m_charType;

    // Attributes common to all types
    int m_deltaCharNum;
    QString m_name;
    QList<QString> m_noteList;
    QString m_comment;
    int m_reliability; ///< Constraint: 1 <= n <= 10 (Dallwitz p80)

    // Multistate
    DeltaCharacterStates m_states;
    DeltaDependentChars m_deps;

    // Numeric attributes
    QString m_units;

};

typedef QList<DeltaCharacter> DeltaCharacterList;

#endif // DELTACHARACTER_H
