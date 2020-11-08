/* dtkComposerNodeArrayDataExtractor.h ---
 *
 * Author: tkloczko
 * Copyright (C) 2011 - Thibaud Kloczko, Inria.
 * Created: Wed Jul  4 12:05:59 2012 (+0200)
 * Version: $Id: 139eb2cc48d764f2f68cbb165b97ff5026cad9bb $
 * Last-Updated: Wed Jul  4 12:07:01 2012 (+0200)
 *           By: tkloczko
 *     Update #: 1
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef DTKCOMPOSERNODEARRAYDATAEXTRACTOR_H
#define DTKCOMPOSERNODEARRAYDATAEXTRACTOR_H

#include <dtkComposerSupportExport.h>
#include "dtkComposerNodeLeaf.h"

class dtkComposerNodeArrayDataExtractorPrivate;

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeArrayDataExtractor interface
// /////////////////////////////////////////////////////////////////

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerNodeArrayDataExtractor : public dtkComposerNodeLeaf
{
public:
    dtkComposerNodeArrayDataExtractor(void);
    ~dtkComposerNodeArrayDataExtractor(void);

public:
    void run(void);

public:
    inline QString type(void) {
        return "array_data_extractor";
    }

    inline QString titleHint(void) {
        return "Data array extract";
    }

public:
    QString  inputLabelHint(int port);
    QString outputLabelHint(int port);

private:
    dtkComposerNodeArrayDataExtractorPrivate *d;
};

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeArrayDataExtractorSubArray interface
// /////////////////////////////////////////////////////////////////

class dtkComposerNodeArrayDataExtractorSubArrayPrivate;

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerNodeArrayDataExtractorSubArray : public dtkComposerNodeLeaf
{
public:
    dtkComposerNodeArrayDataExtractorSubArray(void);
    ~dtkComposerNodeArrayDataExtractorSubArray(void);

public:
    void run(void);

public:
    inline QString type(void) {
        return "array_data_extractor_subarray";
    }

    inline QString titleHint(void) {
        return "Data array : extract subarray";
    }

public:
    QString  inputLabelHint(int port);
    QString outputLabelHint(int port);

private:
    dtkComposerNodeArrayDataExtractorSubArrayPrivate *d;
};

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeArrayDataExtractorArrayPart interface
// /////////////////////////////////////////////////////////////////

class dtkComposerNodeArrayDataExtractorArrayPartPrivate;

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerNodeArrayDataExtractorArrayPart : public dtkComposerNodeLeaf
{
public:
    dtkComposerNodeArrayDataExtractorArrayPart(void);
    ~dtkComposerNodeArrayDataExtractorArrayPart(void);

public:
    void run(void);

public:
    inline QString type(void) {
        return "array_data_extractor_array_part";
    }

    inline QString titleHint(void) {
        return "Data array : extract array part";
    }

public:
    QString  inputLabelHint(int port);
    QString outputLabelHint(int port);

private:
    dtkComposerNodeArrayDataExtractorArrayPartPrivate *d;
};

#endif

