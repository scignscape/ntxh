// Version: $Id: 583deea6fa3ca1f42e7b10a69b857a4bf44a09e9 $
//
//

// Commentary:
//
//

// Change Log:
//
//

// Code:


#pragma once

#include <dtkComposerExport.h>

#include "dtkComposerTransmitter.h"

// /////////////////////////////////////////////////////////////////
// dtkComposerTransmitterProxy
// /////////////////////////////////////////////////////////////////

class DTKCOMPOSER_EXPORT dtkComposerTransmitterProxy : public dtkComposerTransmitter
{
public:
    dtkComposerTransmitterProxy(dtkComposerNode *parent = 0);
    ~dtkComposerTransmitterProxy(void);

public:
    Kind kind(void) const;

    QString kindName(void) const;

public:
    void setActive(bool active);

public:
    LinkMap  leftLinks(dtkComposerTransmitter *transmitter, dtkComposerTransmitterLinkList list);
    LinkMap rightLinks(dtkComposerTransmitter *transmitter, dtkComposerTransmitterLinkList list);
};

//
// dtkComposerTransmitterProxy.h ends here
