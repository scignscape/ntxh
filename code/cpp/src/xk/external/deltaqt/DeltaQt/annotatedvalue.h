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

#ifndef ANNOTATEDVALUE_H
#define ANNOTATEDVALUE_H

#include <QVariant>
#include <QString>

class AnnotatedValue
{
public:
    AnnotatedValue();
    AnnotatedValue(QVariant value, QString note);

    QVariant value(void) const;
    QString note(void) const;

    void clear(void);
    void setValue(QVariant value);
    void setNote(QString note);

    bool isValid() const;

    int toInt(bool* ok) const;

private:
    bool m_isInitialised;
    QVariant m_value;
    QString m_note;
};

#endif // ANNOTATEDVALUE_H
