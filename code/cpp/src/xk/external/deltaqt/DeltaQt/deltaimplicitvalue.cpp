/*  Copyright 2012 Craig Robbins

    This file is part of DeltaQt.

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

#include "deltaimplicitvalue.h"

DeltaImplicitValue::DeltaImplicitValue()
{
    m_charNum = -1;
    m_s = m_t = -1;
}

DeltaImplicitValue::DeltaImplicitValue(int charNum, int s)
{
    set (charNum, s);
}

DeltaImplicitValue::DeltaImplicitValue(int charNum, int s, int t)
{
    set (charNum, s, t);
}


void DeltaImplicitValue::set(int charNum, int s, int t)
{
    m_charNum = charNum;
    m_s = s;
    m_t = t;
}
