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
#include "deltaattribute.h"
#include "deltasymbols.h"


/****************************************************************************/

DeltaAttributeValue::DeltaAttributeValue()
{
    m_pseudoType = NOT_A_PSEUDOTYPE;
    m_isRange = false;
}

DeltaAttributeValue::DeltaAttributeValue(const DeltaValueRange& range)
{
    m_pseudoType = NOT_A_PSEUDOTYPE;
    m_isRange = true;
    m_range = range;
}

DeltaAttributeValue::DeltaAttributeValue(const AnnotatedValue& value)
{
    m_pseudoType = NOT_A_PSEUDOTYPE;
    m_isRange = false;
    m_value = value;
}

DeltaAttributeValue::DeltaAttributeValue(PseudoValue pvType,
                                         const QString& comment)
{
    m_pseudoType = pvType;
    m_isRange = false;
    m_value.clear();
    m_value.setNote(comment);
}

bool DeltaAttributeValue::isRange(void) const
{
    return m_isRange;
}

bool DeltaAttributeValue::isValid(void) const
{
    return m_range.isValid()
            || m_value.isValid()
            || isPseudoValue();
}

bool DeltaAttributeValue::isPseudoValue(void) const
{
    return m_pseudoType != NOT_A_PSEUDOTYPE;
}

QString DeltaAttributeValue::pseudoValueString(void) const
{
    QString tmp;

    switch (m_pseudoType)
    {
    case VARIABLE:
        tmp = DELTA_PSEUDOVAL_VARIABLE;
        break;
    case UNKNOWN:
        tmp = DELTA_PSEUDOVAL_UNKNOWN;
        break;
    case NOTAPPLICABLE:
        tmp = DELTA_PSEUDOVAL_NOTAPPLICABLE;
        break;
    default:
        break;
    }

    return tmp;
}

DeltaValueRange DeltaAttributeValue::range(void) const
{
    return m_range;
}

AnnotatedValue DeltaAttributeValue::value(void) const
{
    return m_value;
}

bool DeltaAttributeValue::setRange(const DeltaValueRange& range)
{
    if (m_value.isValid()) {
        qDebug() << "Warning: DeltaAttributeValue() called to set range"
                 << "but value already set";
    }
    m_isRange = true;
    m_range = range;
    return true;
}

bool DeltaAttributeValue::setValue(const AnnotatedValue& value)
{
    if (m_range.isValid()) {
        qDebug() << "Warning: DeltaAttributeValue() called to set range"
                 << "but value already set";
    }
    m_isRange = false;
    m_value = value;
    return true;
}

QString DeltaAttributeValue::toDeltaString(void) const
{
    QString result;
    if (isRange()) {
        result = m_range.toDeltaString();
    } else if (isPseudoValue()) {
        result = this->pseudoValueString();
    } else
        result = m_value.value().toString();

    if (!this->value().note().isEmpty()) {
        result += DELTA_DELIM_STARTCOMMENT;
        result += this->value().note();
        result += DELTA_DELIM_ENDCOMMENT;
    }

    return result;
}

/****************************************************************************/

DeltaAttributeValueSet::DeltaAttributeValueSet()
{
}

void DeltaAttributeValueSet::addValue(const DeltaAttributeValue& val)
{
    m_values.append(val);
}

bool DeltaAttributeValueSet::isEmpty(void) const
{
    return m_values.isEmpty();
}

QString DeltaAttributeValueSet::toDeltaString(void) const
{
    QString result;
    for (int i = 0; i < m_values.size(); i++) {
        if (i != 0) result += DELTA_DELIM_ITEMATTR_AND;
        result += m_values.at(i).toDeltaString();
    }
    return result;
}

/****************************************************************************/

DeltaAttribute::DeltaAttribute()
{
    m_valuesAreParsed = false;
}

DeltaAttribute::DeltaAttribute(int charNum)
{
    m_charNum = charNum;
    m_valuesAreParsed = false;
}

int DeltaAttribute::charNum(void) const
{
    return m_charNum;
}

QString DeltaAttribute::comment(void) const
{
    return m_comment;
}

const QString& DeltaAttribute::origAttrValsStr(void) const
{
    return m_origAttrValsStr;
}

void DeltaAttribute::addValueSet(const DeltaAttributeValueSet& attrVal)
{
    this->m_values.append(attrVal);
}

void DeltaAttribute::addPseudoValue(DeltaAttributeValue::PseudoValue pvType,
                                    const QString& comment)
{
    DeltaAttributeValueSet valSet;

    valSet.addValue(DeltaAttributeValue(pvType, comment));
    m_values.append(valSet);
}


void DeltaAttribute::setCharNum(int charNum)
{
    m_charNum = charNum;
}

void DeltaAttribute::setComment(const QString& comment)
{
    m_comment = comment;
}


void DeltaAttribute::setOrigAttrValsStr(const QString& str)
{
    m_origAttrValsStr = str;
}

void DeltaAttribute::setValuesAreParsed(bool valuesAreParsed)
{
    m_valuesAreParsed = valuesAreParsed;
}

QString DeltaAttribute::toDeltaString(void) const
{
    QString result;
    QString tmp;

    if (!m_valuesAreParsed) {
        return m_origAttrValsStr;
    }

    result = QString::number(charNum());

    if (!comment().isEmpty()) {
        result += DELTA_DELIM_STARTCOMMENT;
        result += comment();
        result += DELTA_DELIM_ENDCOMMENT;
    }

    if (m_values.size() > 0) {
        result += DELTA_DELIM_CHARVAL_SEPARATOR;
        for (int i = 0; i < m_values.size(); i++) {
            if (i != 0) result += DELTA_DELIM_ITEMATTR_OR;
            result += m_values.at(i).toDeltaString();
        }
    }
    return result;
}
