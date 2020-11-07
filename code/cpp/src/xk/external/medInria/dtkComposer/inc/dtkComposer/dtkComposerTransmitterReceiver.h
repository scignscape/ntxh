// Version: $Id: 573e76e2d49c33043949d13757023def09836cd0 $
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
// dtkComposerTransmitterReceiverBase
// /////////////////////////////////////////////////////////////////

class DTKCOMPOSER_EXPORT dtkComposerTransmitterReceiverBase : public dtkComposerTransmitter
{
public:
    dtkComposerTransmitterReceiverBase(dtkComposerNode *parent = 0);
    virtual ~dtkComposerTransmitterReceiverBase(void);

public:
    dtkComposerTransmitter::Kind kind(void) const;

    QString kindName(void) const;

public:
    bool enableCopy(void);

public:
    QVariant variant(void);

public:
    QVariantList allData(void);

public:
    bool    connect(dtkComposerTransmitter *transmitter);
    bool disconnect(dtkComposerTransmitter *transmitter);

public:
    LinkMap rightLinks(dtkComposerTransmitter *transmitter, dtkComposerTransmitterLinkList list);
};

// /////////////////////////////////////////////////////////////////
// dtkComposerTransmitterReceiverVariant
// /////////////////////////////////////////////////////////////////

class DTKCOMPOSER_EXPORT dtkComposerTransmitterReceiverVariant : public dtkComposerTransmitterReceiverBase
{
public:
    dtkComposerTransmitterReceiverVariant(dtkComposerNode *parent = 0);
    ~dtkComposerTransmitterReceiverVariant(void);

public:
    QVariant data(void);

public:
    template <typename T> T      data(void);
    template <typename T> T constData(void);
};

// /////////////////////////////////////////////////////////////////
// dtkComposerTransmitterReceiver
// /////////////////////////////////////////////////////////////////

template <typename T> class dtkComposerTransmitterReceiver : public dtkComposerTransmitterReceiverBase
{
public:
    dtkComposerTransmitterReceiver(dtkComposerNode *parent = 0);
    ~dtkComposerTransmitterReceiver(void);

public:
    T      data(void);
    T constData(void);

public:
    int type(void) const;

private:
    void setTypeList(const TypeList&);

private:
    using dtkComposerTransmitterReceiverBase::d;
};

// ///////////////////////////////////////////////////////////////////
// Implementations
// ///////////////////////////////////////////////////////////////////

#include "dtkComposerTransmitterReceiver.tpp"

// ///////////////////////////////////////////////////////////////////
// Alias for support layer
// ///////////////////////////////////////////////////////////////////

template <typename T> using dtkComposerTransmitterReceiverSupport = dtkComposerTransmitterReceiver<T *>;

//
// dtkComposerTransmitterReceiver.h ends here
