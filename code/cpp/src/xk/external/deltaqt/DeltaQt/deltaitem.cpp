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

#include "deltaitem.h"
#include "deltasymbols.h"

DeltaItem::DeltaItem()
{
}

DeltaItem::DeltaItem(const QString& name)
{
    m_name = name;
}

QString DeltaItem::name(void) const
{
    return m_name;
}

QString DeltaItem::comment(void) const
{
    return m_comment;
}

void DeltaItem::addAttribute(const DeltaAttribute& attr)
{
    m_attributes.append(attr);
}

void DeltaItem::setName(const QString& name)
{
    m_name = name;
}

void DeltaItem::setComment(const QString& comment)
{
    m_comment = comment;
}

QString DeltaItem::toDeltaString(void) const
{
    QString result;
    result = DELTA_DELIM_ITEMDESC_BEGIN;
    result += ' ';  // added to conform with CONFOR/DELFOR output
    result += name();
    result += DELTA_DELIM_ITEMNAME_END;
    result += "\n";

    for (int i = 0; i < m_attributes.count(); i++) {
        if (i != 0) result += DELTA_DELIM_ITEMATTR_SEPARATOR;
        result += m_attributes.at(i).toDeltaString();
    }

    return result;
}

DeltaAttributeList* DeltaItem::getAttrListNotConst(void)
{
    return &m_attributes;
}
