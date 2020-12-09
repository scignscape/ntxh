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

#ifndef DELTAIMPLICITVALUE_H
#define DELTAIMPLICITVALUE_H

class DeltaImplicitValue
{
public:
    DeltaImplicitValue();
    DeltaImplicitValue(int charNum, int s);
    DeltaImplicitValue(int charNum, int s, int t);

    void set(int charNum, int s, int t = -1);

    inline int charNum(void) const { return m_charNum; }
    inline int s(void) const { return m_s; }
    inline int t(void) const { return m_t; }

private:
    int m_charNum;
    int m_s;        // See DELTA User Guide
    int m_t;        // See DELTA User Guide
};

#endif // DELTAIMPLICITVALUE_H
