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

#ifndef DELTASYMBOLS_H
#define DELTASYMBOLS_H

/*
 * NOTE:    There is some reduncancy here (some of the delimiters are
 *          identical) however it should be left this way as they may become
 *          user-definable by some future revision of the DELTA Standard;
 *          (another reason to make a class for symbols: so they can be
 *          redefined at run-time)
 */

#define DELTA_DELIM_DIRECTIVE_BEGIN     '*'
#define DELTA_DELIM_DATABLOCKBEGIN      '#'

#define DELTA_DELIM_FEATUREDESC_BEGIN   '#'
#define DELTA_DELIM_CHARDESC_PARTEND    '/'

#define DELTA_DELIM_ITEMDESC_BEGIN      '#'
#define DELTA_DELIM_ITEMNAME_END        '/'
#define DELTA_DELIM_ITEMATTR_SEPARATOR  ' '
#define DELTA_DELIM_CHARVAL_SEPARATOR   ','
#define DELTA_DELIM_ITEMATTR_OR         '/'
#define DELTA_DELIM_ITEMATTR_AND        '&'
#define DELTA_DELIM_EXTREMEVAL_START    '('
#define DELTA_DELIM_EXTREMEVAL_END      ')'

#define DELTA_DELIM_CHARTYPE_SEPARATOR  ' '

#define DELTA_PSEUDOVAL_UNKNOWN         "U"
#define DELTA_PSEUDOVAL_VARIABLE        "V"
#define DELTA_PSEUDOVAL_NOTAPPLICABLE   "-"

#define DELTA_DELIM_CNOTES_BEGIN        '#'

#define DELTA_DELIM_STARTCOMMENT        '<'
#define DELTA_DELIM_ENDCOMMENT          '>'

#define DELTA_DELIM_COMMENTLEGALPRE     "\n<> "
#define DELTA_DELIM_COMMENTLEGALPOST    "\n<> /"

#define DELTA_DELIM_MANDCHAR_DELIM      ' '

#define DELTA_DELIM_IVAL_SEPARATOR     ' '
#define DELTA_DELIM_IVAL_PARTSEP       ','
#define DELTA_DELIM_IVAL_VALSEP        ':'

#define DELTA_DELIM_DEPCHAR_SEPARATOR  ' '
#define DELTA_DELIM_DEPCHAR_PARTSEP    ','
#define DELTA_DELIM_DEPCHAR_DEFSEP     ':'
#define DELTA_DELIM_DEPCHAR_STATEDELIM '/'
#define DELTA_DELIM_DEPCHAR_CHARDELIM  ':'


#define DELTA_DELIM_RANGE_OP            '-'

#endif // DELTASYMBOLS_H
