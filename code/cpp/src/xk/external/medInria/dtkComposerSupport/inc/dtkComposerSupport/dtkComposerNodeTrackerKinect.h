/* dtkComposerNodeTrackerKinect.h ---
 *
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Thu Apr 26 10:25:11 2012 (+0200)
 * Version: $Id: a0ce508d62b6c38f5d4c974c5deb2e4a2377de95 $
 * Last-Updated: Thu Apr 26 13:22:04 2012 (+0200)
 *           By: Julien Wintz
 *     Update #: 18
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef DTKCOMPOSERNODETRACKERKINECT_H
#define DTKCOMPOSERNODETRACKERKINECT_H

#include <dtkComposerSupportExport.h>
#include "dtkComposerNodeLeaf.h"

class dtkComposerNodeTrackerKinectPrivate;

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerNodeTrackerKinect : public dtkComposerNodeLeaf
{
public:
    dtkComposerNodeTrackerKinect(void);
    ~dtkComposerNodeTrackerKinect(void);

public:
    void run(void);

public:
    inline QString type(void) {
        return "kinectTracker";
    }

    inline QString titleHint(void) {
        return "KinectTracker";
    }

    inline QString outputLabelHint(int port) {
        if (port == 0)
            return "head position";

        if (port == 1)
            return "head orientation";

        return dtkComposerNodeLeaf::outputLabelHint(port);
    }

private:
    dtkComposerNodeTrackerKinectPrivate *d;
};

#endif
