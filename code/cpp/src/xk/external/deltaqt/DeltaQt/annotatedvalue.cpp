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

#include "annotatedvalue.h"

/** @internal   This could probably be a class inherited from QVariant, however
  *             at this point in time it is debatable whether implementing all
  *             the constructors is time well spent...
  */


/** Creates an empty value; i.e. isValid() == false
  */
AnnotatedValue::AnnotatedValue()
{
    m_isInitialised = false;
}


AnnotatedValue::AnnotatedValue(QVariant value, QString note)
{
    m_value = value;
    m_note = note;
    m_isInitialised = true;
}


/** @see: setValue()
  */
QVariant AnnotatedValue::value(void) const
{
    return m_value;
}

/** Get the note/annotation associated with the value. May be an empty string.
  */
QString AnnotatedValue::note(void) const
{
    return m_note;
}

/** Clear the value and annotation.
  */
void AnnotatedValue::clear(void)
{
    m_value = QVariant();
    m_note = QString();
    m_isInitialised = false;
}

/** Set the value to <i>value</i>.
  */
void AnnotatedValue::setValue(QVariant value)
{
    m_value = value;
    m_isInitialised = true;
}

/** Set the note to <i>note</i>.
  */
void AnnotatedValue::setNote(QString note)
{
    m_note = note;
    m_isInitialised = true;
}

/** Returns true if either the value is valid or there is an attached note.
  */
bool AnnotatedValue::isValid() const
{
    return m_isInitialised;
}

/** Attempts to convert the value to an int. If successful, the converted int
  * is returned, otherwise 0 is returned.
  *
  * If <i>ok</i> is not NULL, *ok is set to true if the value could be
  * converted to an int; otherwise *ok is set to false. It is advised that
  * <i>ok</i> is not NULL so that success or failure or the conversion can be
  * determined.
  */
int AnnotatedValue::toInt(bool* ok) const
{
    int val;
    bool isOk;
    if (!m_value.isValid()) {
        val = 0;
        isOk = false;
    } else
        val = m_value.toInt(&isOk);
    if (ok) *ok = isOk;
    return val;
}
