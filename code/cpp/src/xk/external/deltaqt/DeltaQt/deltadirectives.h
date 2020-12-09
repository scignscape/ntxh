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

#ifndef DELTADIRECTIVES_H
#define DELTADIRECTIVES_H

#include <QString>

class DeltaDirectives
{
public:
    typedef enum
    {
        SHOW,
        CHARLIST,
        CHARTYPES,
        CHARNOTES,
        CHARIMAGES,
        ITEMDESCS,
        TAXONIMAGES,
        IMPLICITVALUES,
        DEPENDENTCHARS,
        MANDATORYCHARS,
        COMMENT,

        // Parsed for data validation purposes
        NUMBEROFCHARS,
        MAXSTATES,
        MAXITEMS,
        NUMBERSOFSTATES,

        PSEUDO_UNKNOWN,         // Not a Delta Directive (used internally)
        PSEUDO_NONE             // Not a Delta Directive (used internally)
    } DirectiveId;

    /* Bitwise enum */
    typedef enum
    {
        /// Documented in the DELTA Standard or User Guide
        IsDeltaStd          =   1,

        // Implemented by CSIRO DELTA suite of programs as of 2011
        IsCSIRODeltaImplemented =   2,

        // Implemented/recognised by this implementation and parsed
        IsParsed                =   4,

        // Recognised by this implementation stored only (not parsed)
        IsStoredOnly            =   8,

        /* The "directive" is used within this implementation only.
         * E.g. it is an ID used for parsing, error checking, etc
         */
        IsInteralUseOnly        =   16
    } Flags;

    typedef struct
    {
        DirectiveId id;
        QString controlPhrase;
        unsigned flags;
    } Def;

    DeltaDirectives();

    static QString abbrevName(void);

    static unsigned count(void);

    static bool isKnown(const Def* directive);
    static bool isKnown(QString str);
    static bool isPsuedoDirective(const Def* directive);

    static const Def* def(DirectiveId id);
    static const Def* def(QString str);

    static const Def* pseudoDef(DirectiveId id);

private:
    static const DeltaDirectives::Def m_directives[];
    static const DeltaDirectives::Def m_pseudoDirectives[];

};

#endif // DELTADIRECTIVES_H
