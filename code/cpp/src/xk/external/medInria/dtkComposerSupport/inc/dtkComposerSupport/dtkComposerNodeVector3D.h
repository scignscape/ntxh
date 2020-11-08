/* dtkComposerNodeVector3D.h ---
 *
 * Author: tkloczko
 * Copyright (C) 2011 - Thibaud Kloczko, Inria.
 * Created: Thu Apr 26 10:10:43 2012 (+0200)
 * Version: $Id: bd41258fb844155c3d1f421dc75f27801f691ef5 $
 * Last-Updated: Fri Apr 27 17:54:19 2012 (+0200)
 *           By: Julien Wintz
 *     Update #: 9
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef DTKCOMPOSERNODEVECTOR3D_H
#define DTKCOMPOSERNODEVECTOR3D_H

#include <dtkComposerSupportExport.h>
#include "dtkComposerNodeLeaf.h"

class dtkComposerNodeVector3DPrivate;

class DTKCOMPOSERSUPPORT_EXPORT dtkComposerNodeVector3D : public dtkComposerNodeLeaf
{
public:
    dtkComposerNodeVector3D(void);
    ~dtkComposerNodeVector3D(void);

public:
    void run(void);

public:
    inline QString type(void) {
        return "vector3D";
    }

    inline QString titleHint(void) {
        return "Vector3D";
    }

public:
    QString  inputLabelHint(int port);
    QString outputLabelHint(int port);

private:
    dtkComposerNodeVector3DPrivate *d;
};

#endif
