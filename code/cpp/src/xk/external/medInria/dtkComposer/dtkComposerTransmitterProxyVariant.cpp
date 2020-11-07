// Version: $Id: 4ff07b441f866ed158274d3bb4d27e0d1d0bde22 $
//
//

// Commentary:
//
//

// Change Log:
//
//

// Code:

#include "dtkComposerTransmitter_p.h"
#include "dtkComposerTransmitterProxyVariant.h"

// ///////////////////////////////////////////////////////////////////
// dtkComposerTransmitterProxyVariant implementation
// ///////////////////////////////////////////////////////////////////

dtkComposerTransmitterProxyVariant::dtkComposerTransmitterProxyVariant(dtkComposerNode *parent) : dtkComposerTransmitter(parent)
{
    m_transmitter = &m_receiver;
}

dtkComposerTransmitterProxyVariant::~dtkComposerTransmitterProxyVariant(void)
{

}

void dtkComposerTransmitterProxyVariant::enableReceiver(void)
{
    m_transmitter = &m_receiver;
}

void dtkComposerTransmitterProxyVariant::enableEmitter(void)
{
    m_transmitter = &m_emitter;
}

void dtkComposerTransmitterProxyVariant::clearData(void)
{
    m_emitter.clearData();
}

dtkComposerTransmitter::Kind dtkComposerTransmitterProxyVariant::kind(void) const
{
    return dtkComposerTransmitter::ProxyVariant;
}

QString dtkComposerTransmitterProxyVariant::kindName(void) const
{
    return "ProxyVariant";
}

bool dtkComposerTransmitterProxyVariant::isEmpty(void) const
{
    return m_receiver.isEmpty();
}

bool dtkComposerTransmitterProxyVariant::connect(dtkComposerTransmitter *transmitter)
{
    return m_receiver.connect(transmitter);
}

bool dtkComposerTransmitterProxyVariant::disconnect(dtkComposerTransmitter *transmitter)
{
    return m_receiver.disconnect(transmitter);
}

bool dtkComposerTransmitterProxyVariant::enableConnection(dtkComposerTransmitter *transmitter)
{
    return m_emitter.enableConnection(transmitter);
}

dtkComposerTransmitter::LinkMap dtkComposerTransmitterProxyVariant::leftLinks(dtkComposerTransmitter *transmitter, dtkComposerTransmitterLinkList list)
{
    return m_emitter.leftLinks(transmitter, list);
}

dtkComposerTransmitter::LinkMap dtkComposerTransmitterProxyVariant::rightLinks(dtkComposerTransmitter *transmitter, dtkComposerTransmitterLinkList list)
{
    return m_receiver.rightLinks(transmitter, list);
}

bool dtkComposerTransmitterProxyVariant::enableCopy(void)
{
    return m_transmitter->enableCopy();
}

QVariant dtkComposerTransmitterProxyVariant::variant(void)
{
    return m_transmitter->variant();
}

QVariantList dtkComposerTransmitterProxyVariant::allData(void)
{
    return m_transmitter->allData();
}

//
// dtkComposerTransmitterProxyVariant.cpp ends here
