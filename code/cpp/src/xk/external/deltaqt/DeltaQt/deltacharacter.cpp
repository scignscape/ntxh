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
#include <QChar>
#include <math.h>
#include "deltacharacter.h"

/****************************************************************************/

DeltaCharacterState::DeltaCharacterState()
{
    m_id = DeltaCharacterType::DCT_PT_NOTSET;
}


DeltaCharacterState::DeltaCharacterState(int id, const QString& name)
{
    set(id, name);
}

void DeltaCharacterState::set(int id, const QString& name)
{
    m_id = id;
    m_name = name;
}

/****************************************************************************/

DeltaCharacter::DeltaCharacter()
{
    m_initCommon();
}

DeltaCharacter::~DeltaCharacter()
{
}

DeltaCharacter::DeltaCharacter(DeltaCharacterType::TypeId typeId)
{
    m_initCommon();
    m_charType = typeId;
}

void DeltaCharacter::m_initCommon(void)
{
    m_setDefaults();
}

void DeltaCharacter::m_setDefaults(void)
{
    m_reliability = 5;
    m_charType = DeltaCharacterType::DCT_PT_NOTSET;
    m_deltaCharNum = -1;

}

bool DeltaCharacter::isValid(void) const
{
    return m_charType != DeltaCharacterType::DCT_PT_NOTSET
            && m_deltaCharNum != -1;
}

int DeltaCharacter::charNum(void) const
{
    return m_deltaCharNum;
}

QString DeltaCharacter::name(void) const
{
    return m_name;
}


DeltaCharacterType::TypeId DeltaCharacter::type(void) const
{
    return m_charType;
}


double DeltaCharacter::weight(void) const
{
    return pow(2, m_reliability - 5);
}


void DeltaCharacter::addNote(const QString& note)
{
    m_noteList.append(note);
}


void DeltaCharacter::addState(int id, const QString& name)
{
    DeltaCharacterState state(id, name);
    m_states.append(state);
}

void DeltaCharacter::addDependency(int stateNum, int depChar)
{
    // Pre: character is multistate
    Q_ASSERT (isMultistate());

    m_deps.append(stateNum, depChar);
}

void DeltaCharacter::clear(void)
{
    m_setDefaults();
    m_name = QString();
    m_units = QString();
    m_comment = QString();
    m_states.clear();
}

void DeltaCharacter::setCharType(DeltaCharacterType::TypeId type)
{
    m_charType = type;
}

int DeltaCharacter::setDeltaCharNum(int to)
{
    return m_deltaCharNum = to;
}

int DeltaCharacter::setReliability(int reliability)
{
    m_reliability = reliability;
    return reliability;
}

void DeltaCharacter::setUnits(const QString& to)
{
    m_units = to;
}

void DeltaCharacter::setName(const QString& to)
{
    m_name = to;
}

