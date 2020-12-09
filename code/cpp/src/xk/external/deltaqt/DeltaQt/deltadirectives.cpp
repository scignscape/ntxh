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

#include <QDebug>
#include <QString>
#include <QChar>
#include "deltadirectives.h"


static const unsigned IS_PARSED =
          DeltaDirectives::IsDeltaStd
        | DeltaDirectives::IsCSIRODeltaImplemented
        | DeltaDirectives::IsParsed;

static const unsigned IS_NOT_PARSED =
          DeltaDirectives::IsDeltaStd
        | DeltaDirectives::IsCSIRODeltaImplemented;

static const unsigned IS_IGNORED = IS_NOT_PARSED;

static const unsigned IS_PLANNED = IS_NOT_PARSED;

static const unsigned IS_STORED_UNPARSED =
          DeltaDirectives::IsDeltaStd
        | DeltaDirectives::IsCSIRODeltaImplemented
        | DeltaDirectives::IsStoredOnly;

static const unsigned INTERNAL_ONLY =
          DeltaDirectives::IsInteralUseOnly;


DeltaDirectives::DeltaDirectives()
{
}

const DeltaDirectives::Def DeltaDirectives::m_directives[] =
{
    { DeltaDirectives::SHOW, "SHOW", IS_IGNORED },
    { DeltaDirectives::CHARLIST, "CHARACTER LIST", IS_PARSED },
    { DeltaDirectives::CHARTYPES, "CHARACTER TYPES", IS_PARSED },
    { DeltaDirectives::CHARNOTES, "CHARACTER NOTES", IS_PARSED },
    { DeltaDirectives::CHARIMAGES, "CHARACTER IMAGES", IS_PLANNED },
    { DeltaDirectives::ITEMDESCS, "ITEM DESCRIPTIONS", IS_PARSED },
    { DeltaDirectives::TAXONIMAGES, "TAXON IMAGES", IS_PLANNED },
    { DeltaDirectives::IMPLICITVALUES, "IMPLICIT VALUES", IS_PARSED },
    { DeltaDirectives::DEPENDENTCHARS, "DEPENDENT CHARACTERS", IS_PARSED },
    { DeltaDirectives::MANDATORYCHARS, "MANDATORY CHARACTERS", IS_PARSED },
    { DeltaDirectives::COMMENT, "COMMENT", IS_IGNORED },

    // Parsed for data validation purposes
    { DeltaDirectives::NUMBEROFCHARS, "NUMBER OF CHARACTERS", IS_PARSED },
    { DeltaDirectives::MAXSTATES, "MAXIMUM NUMBER OF STATES", IS_PARSED },
    { DeltaDirectives::MAXITEMS,  "MAXIMUM NUMBER OF ITEMS", IS_PARSED },
    { DeltaDirectives::NUMBERSOFSTATES,  "NUMBERS OF STATES", IS_PARSED }

};

const DeltaDirectives::Def DeltaDirectives::m_pseudoDirectives[] =
{
    { DeltaDirectives::PSEUDO_UNKNOWN, "", INTERNAL_ONLY },
    { DeltaDirectives::PSEUDO_NONE, "", INTERNAL_ONLY }
};

static const int PseudoDirectiveUnknown_idx = 0;
static const int PseudoDirectiveNone_idx = 1;


/** Returns the number of defined directives (exclusing pseudo-directives)
  */
unsigned DeltaDirectives::count(void)
{
    return sizeof (m_directives) / sizeof (m_directives[0]);
}


/** Returns true if the given directive definition represents a known
  * directive (e.g. if it not a 'pseudo-directive').
  *
  * @pre:       directive != NULL
  */
bool DeltaDirectives::isKnown(const Def* directive)
{
    return directive->id != PSEUDO_UNKNOWN;
}

/** Returns true if the directive is a not a 'pseudo directive'
  *
  * @pre:       directive != NULL
  */
bool DeltaDirectives::isPsuedoDirective(const Def* directive)
{
    if (directive->id == PSEUDO_UNKNOWN
            || directive->id == PSEUDO_NONE) return true;
    return false;
}

/** Returns true if the given directive definition represents a known
  * directive (e.g. if it not a 'pseudo-directive').
  *
  * @note:      The string (str) should not begin with the leading
  *             DELTADIRECTIVE_DELIMITER character. Characters after the
  *             'control phrase' (name) of the directive are permitted.
  */
bool DeltaDirectives::isKnown(QString str)
{
    return isKnown(def(str));
}

/** Retrieve a directive definition by id. Returns a pointer to the
  * definition, or NULL if no match with id was found.
  */
const DeltaDirectives::Def* DeltaDirectives::def(DirectiveId id)
{
    unsigned i;

    for (i = 0; i < count(); i++) {
        if (m_directives[i].id == id) break;
    }

    return i < count() ? &m_directives[i] : NULL;
}


/** Retrieve, if possible, the directive definition that /str/ represents.
  * Note that /str/ can be any valid string and therefore this function
  * can also be used to check if the string is a directive or not. If a
  * directive directive is found, it is then possible to skip past the
  * 'control phrase' by simply adding the length.
  *
  * If the string does not represent a (known) directive control phrase,
  * then the a pointer to the 'pseudo-directive' definition for
  * DeltaDirectives::PSEUDO_UNKNOWN is returned.
  *
  * @note:      The string (passed as /str/) must be a possible control
  *             phrase /without/ the leading DELTADIRECTIVE_DELIMITER ('*').
  *             Characters after the 'control phrase' (name) of the directive
  *             are permitted.
  *
  */
const DeltaDirectives::Def* DeltaDirectives::def(QString str)
{
    unsigned i;

    unsigned sz = count();

    for (i = 0; i < sz; i++) {
        QString dname = m_directives[i].controlPhrase;
        int dLen = dname.length();
        QString cmp = str.left(dLen);

        if (dname == cmp) {
            if (dLen == str.length()) {
                break;
            }
            QChar ch_after = str.at(dLen);
            Q_ASSERT(str.length() >= dLen);
            // the next char must be EOL or a space
            if (dLen == str.length() || ch_after.isSpace()) {
                // found match
                break;
            }
        }
    }

    return i < count() ? &m_directives[i]
                       : &m_pseudoDirectives[PseudoDirectiveUnknown_idx];
}

/** Retrieve the directive definition for the pseudo directive matching id
  */
const DeltaDirectives::Def* DeltaDirectives::pseudoDef(DirectiveId id)
{
    unsigned i;

    for (i = 0; i < count(); i++) {
        if (m_pseudoDirectives[i].id == id) break;
    }

    return i < count() ? &m_directives[i] : NULL;
}

