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

#ifndef DELTAATTRIBUTE_H
#define DELTAATTRIBUTE_H

#include <QString>
#include <QList>
#include <QVariant>
#include "deltavaluerange.h"


class DeltaAttributeValue
{
public:
    typedef enum {
        NOT_A_PSEUDOTYPE,
        VARIABLE,               // The attribute is Variable
        UNKNOWN,                // The attribute value is Unknown
        NOTAPPLICABLE           // The attribute is N/A for the charNum
    } PseudoValue;

    DeltaAttributeValue();
    DeltaAttributeValue(const DeltaValueRange& range);
    DeltaAttributeValue(const AnnotatedValue& value);
    DeltaAttributeValue(PseudoValue pvType, const QString& comment);

    DeltaValueRange range(void) const;
    AnnotatedValue value(void) const;

    bool setRange(const DeltaValueRange& range);
    bool setValue(const AnnotatedValue& value);

    bool isRange(void) const;
    bool isValid(void) const;
    bool isPseudoValue(void) const;

    QString pseudoValueString(void) const;

    QString toDeltaString(void) const;

private:
    bool m_isRange;
    PseudoValue m_pseudoType;
    DeltaValueRange m_range;    // use if m_range == true
    AnnotatedValue m_value;     // use if m_range == false
};

typedef QList<DeltaAttributeValue> DeltaAttributeValueList;


/* Keeping the values in "sets" (although they are strictly
 * speaking not sets because duplicate values are permitted) so that the
 * "logical" operators available in DELTA can be retained. Values within each
 * value set have an implied 'AND', and value sets (for the same attribute) are
 * combined by 'OR'.
 */
class DeltaAttributeValueSet
{
public:

    DeltaAttributeValueSet();

    void addValue(const DeltaAttributeValue& val);
    bool isEmpty(void) const;

    inline const DeltaAttributeValueList* valueList(void) const
        { return &m_values; }

    QString toDeltaString(void) const;

    inline void clear(void) { m_values.clear(); }

protected:
    DeltaAttributeValueList m_values;

};


typedef QList<DeltaAttributeValueSet> DeltaAttributeValueSetList;


class DeltaAttribute
{
public:
    DeltaAttribute();
    DeltaAttribute(int charNum);

    inline const DeltaAttributeValueSetList* attrValueSet(void) const
        { return &m_values; }

    int charNum(void) const;
    QString comment(void) const;
    const QString& origAttrValsStr(void) const;

    void addValueSet(const DeltaAttributeValueSet& attrVal);
    void addPseudoValue(DeltaAttributeValue::PseudoValue pvType,
                        const QString& comment);
    void setCharNum(int charNum);
    void setComment(const QString& comment);
    void setOrigAttrValsStr(const QString& str);
    void setValuesAreParsed(bool valuesAreParsed);  

    QString toDeltaString(void) const;

private:
    int m_charNum;
    QString m_comment;
    DeltaAttributeValueSetList m_values;
    QString m_origAttrValsStr;
    bool m_valuesAreParsed;
};

typedef QList<DeltaAttribute> DeltaAttributeList;

#endif // DELTAATTRIBUTE_H
