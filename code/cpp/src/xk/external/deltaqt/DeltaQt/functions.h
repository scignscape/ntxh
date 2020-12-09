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

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QString>
#include <QStringList>
#include <QFile>
#include "globals.h"

QString libVersion(void);
QString libBuildDate(void);
QString libBuildTime(void);

QStringList breakStrToLineLen(const QString& str,
                              int maxLineLen = DEF_TEXTOUT_MAXLINEWIDTH,
                              unsigned indentLen_firstLine = 0,
                              unsigned indentLen_subsequentLines = 0,
                              bool splitOnWholeWords = true
                              );

QString deltafile_Encoding(QString filename);
QString deltafile_Encoding(QFile *file);

void trimTrailingWhitespace(QString* str);

#endif // FUNCTIONS_H
