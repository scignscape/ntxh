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

#include "deltaqt.h"


DeltaQt::DeltaQt()
{
}

/** \mainpage DeltaQt

\section section_aims Aims

DeltaQt aims to provide a cross-platform library of C++ classes and functions
to enable parsing of DELTA (DEscription Language for TAxonomy) files. Core
functions (non-GUI) of the Qt framework are used extensively.

Support for all major data-related DELTA directives is planned. Typesetting
directives are beyond the scope of the project and support for them is not
planned. Note: support for RTF formatting within comments, notes, descriptions,
etc <i>is planned</i>.

\subsection section_coreDirectives DELTA directive support

Version 1.0.0 of the library will support the directives in the list below.
Support for additional directives will be implemented in future versions of the
library, although some additional directives may be implemented by
Version 1.0.0; <i>i.e.</i> the list below is the <i>minimum</i> support planned
for Version 1.0.0. The items in bold are currently supported.

\li CHARACTER IMAGES
<b>\li CHARACTER LIST</b>
<b>\li CHARACTER NOTES</b>
<b>\li CHARACTER TYPES</b>
<b>\li COMMENT</b>
\li DEPENDENT CHARACTERS
\li IMPLICIT VALUES
<b>\li ITEM DESCRIPTIONS</b>
\li MANDATORY CHARACTERS
<b>\li SHOW</b> <sup>\ref Partial</sup>
\li TAXON IMAGES

\anchor Partial <sup>Partial</sup>Is currently partially supported (recognised
but not parsed)

\section section_coreClasses Core library classes and functions

Interaction with the DeltaQt library from an application will typically centre
upon the classes DeltaDataset and DeltaParser. DeltaParser reads from the DELTA
input files into a DeltaDataset object. Once the input files are parsed, data
are then accessed using the DeltaDataset.

Example:
\code
DeltaDataset deltaData;
DeltaParser parser;
QStringList inputFiles;

inputFiles << "chars" << "items" << "specs" << "cnotes";
if (parser.parse(&deltaData, inputFiles)) {
        // Success! Interact with the parsed data through deltaData
}
\endcode

*/
