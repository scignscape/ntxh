/* axlInspectorUtils.cpp ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 16:58:59 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Nov  9 17:09:38 2010 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 19
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */


#include "axlInspectorUtils.h"

bool caseInsensitiveLessThan(const QString &s1, const QString &s2)
{
    return s1.toLower() < s2.toLower();
}
