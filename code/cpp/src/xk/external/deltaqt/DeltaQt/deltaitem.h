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

#ifndef DELTAITEM_H
#define DELTAITEM_H

#include <QString>
#include <QList>
#include "deltaattribute.h"
#include "globals.h"

class DeltaItem
{
    friend class DeltaParserPhase2;

public:
    DeltaItem();
    DeltaItem(const QString& name);

    inline const DeltaAttributeList* attrList(void) const
        { return &m_attributes; }

    QString name(void) const;
    QString comment(void) const;

    void addAttribute(const DeltaAttribute& attr);
    void setName(const QString& name);
    void setComment(const QString& comment);

    QString toDeltaString(void) const;

protected:
    DeltaAttributeList* getAttrListNotConst(void);
private:
    QString m_name;
    QString m_comment;
    DeltaAttributeList m_attributes;
};

typedef QList<DeltaItem> DeltaItemList;

#endif // DELTAITEM_H
