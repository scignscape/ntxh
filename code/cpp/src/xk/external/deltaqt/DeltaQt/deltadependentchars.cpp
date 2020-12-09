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

#include "deltadependentchars.h"

DeltaDependentChars::DeltaDependentChars()
{
}

void DeltaDependentChars::clear(void)
{
    m_deps.clear();
}

/** @internal
  * @note No check is made for duplicates; the calling function should do this
  * before appending a new item
  */
void DeltaDependentChars::append(int stateNum, int dependentChar)
{
    struct pair item;
    item.stateNum = stateNum;
    item.dependentChar = dependentChar;
    m_deps.append(item);
}
