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

#ifndef DELTAQT_GLOBAL_H
#define DELTAQT_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DELTAQT_LIBRARY)
#  define DELTAQTSHARED_EXPORT Q_DECL_EXPORT
#else
#  define DELTAQTSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // DELTAQT_GLOBAL_H
