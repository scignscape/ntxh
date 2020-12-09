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

#ifndef DELTADEPENDENTCHARS_H
#define DELTADEPENDENTCHARS_H

#include <QList>

class DeltaDependentChars
{
public:
    DeltaDependentChars();

    void clear(void);
    void append(int stateNum, int dependentChar);
    inline int count(void) const { return m_deps.count(); }

private:
    struct pair {
        int stateNum;
        int dependentChar;
    };

    QList<struct pair> m_deps;
};

#endif // DELTADEPENDENTCHARS_H
