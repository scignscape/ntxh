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

#ifndef LOGMSGID_H
#define LOGMSGID_H

class LogMsgId
{

public:

    enum Id {
        LibFatalError,
        LibVersion,
        LibBuildDate,
        LibUnhandledDirective,
        LibUnknownDirective,
        LibUnknownCharType,
        LibUnhandledCharType,
        LibUnknownError,

        ImportingFile,
        ImportSuccess,
        ImportFail,
        ImportNumChars,
        ImportNumItems,
        ImportNumCharNotes,
        ImportNumErrors,
        ImportNumWarnings,

        FopenFailed,
        UnbalancedCommentDelims,
        IgnoringUnknDrctv,
        UnimplementedDrctv,

        UnknCType,
        ConversionError_CNum,
        ConversionError_StateNum,
        ConversionError_Int,
        ConversionError_Real,
        ConversionError_Value,

        NewCh_InvalidFeatureDesc,
        NewCh_NoCName,
        NewState_StateNotNumbered,
        NewState_NoName,

        Undefined_CNum,

        Range_DuplicateValue,
        Range_TooManyNormalValues,
        Range_ExtremeLowIsEmpty,
        Range_ExtremeHighIsEmpty,
        Range_ExtremeLowAlreadySet,
        Range_ExtremeHighAlreadySet
    };
};

#endif // LOGMSGID_H

