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

#ifndef DELTAPARSERPHASE2_H
#define DELTAPARSERPHASE2_H

#include "deltadataset.h"
#include "delimitedbuffer.h"
#include "parselog.h"

class DeltaParserPhase2
{
public:
    DeltaParserPhase2();
    DeltaParserPhase2(DeltaDataset* dataset, ParseLog* log);

    bool finalParseItemAttributes(void);
protected:

    bool parseItemAttributes(DeltaAttribute& dAttr);
    bool parseAttributeValues(DeltaAttribute& dAttr);
    bool parseAttributeValueSet(DeltaCharacterType::TypeId cTypeId,
                                const DelimitedBuffer& elementSetStr,
                                DeltaAttribute& attr,
                                DeltaAttributeValueSet& dAttrValueSet);

    bool tryParseAsPseudoValue(const QString& valStr,
                               DeltaAttribute& attr);
private:
    DeltaDataset* m_dataset;
    ParseLog* m_log;
};

#endif // DELTAPARSERPHASE2_H
