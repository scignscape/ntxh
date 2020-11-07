/* dtkComposerNodeBooleanOperator.cpp ---
 *
 * Author: tkloczko
 * Copyright (C) 2011 - Thibaud Kloczko, Inria.
 * Created: Wed Feb 15 09:52:45 2012 (+0100)
 * Version: $Id: 982584be4d3ab9ec6fbe0c75a41a6f589651d76a $
 * Last-Updated: 2012 Wed Dec 12 15:30:22 (+0100)
 *           By: Thibaud Kloczko
 *     Update #: 163
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#include "dtkComposerNodeBooleanOperator.h"
#include "dtkComposerTransmitterEmitter.h"
#include "dtkComposerTransmitterReceiver.h"

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeBooleanOperatorUnary
// /////////////////////////////////////////////////////////////////

class dtkComposerNodeBooleanOperatorUnaryPrivate
{
public:
    dtkComposerTransmitterReceiver<bool> receiver;

public:
    dtkComposerTransmitterEmitter<bool> emitter;
};

dtkComposerNodeBooleanOperatorUnary::dtkComposerNodeBooleanOperatorUnary(void) : dtkComposerNodeLeaf(), d(new dtkComposerNodeBooleanOperatorUnaryPrivate)
{
    this->appendReceiver(&(d->receiver));

    this->appendEmitter(&(d->emitter));
}

dtkComposerNodeBooleanOperatorUnary::~dtkComposerNodeBooleanOperatorUnary(void)
{
    delete d;

    d = NULL;
}

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeBooleanOperatorBinary
// /////////////////////////////////////////////////////////////////

class dtkComposerNodeBooleanOperatorBinaryPrivate
{
public:
    dtkComposerTransmitterReceiver<bool> receiver_lhs;
    dtkComposerTransmitterReceiver<bool> receiver_rhs;

public:
    dtkComposerTransmitterEmitter<bool> emitter;
};

dtkComposerNodeBooleanOperatorBinary::dtkComposerNodeBooleanOperatorBinary(void) : dtkComposerNodeLeaf(), d(new dtkComposerNodeBooleanOperatorBinaryPrivate)
{
    this->appendReceiver(&(d->receiver_lhs));
    this->appendReceiver(&(d->receiver_rhs));

    this->appendEmitter(&(d->emitter));
}

dtkComposerNodeBooleanOperatorBinary::~dtkComposerNodeBooleanOperatorBinary(void)
{
    delete d;

    d = NULL;
}

// /////////////////////////////////////////////////////////////////
// Unary boolean operator - NOT
// /////////////////////////////////////////////////////////////////

void dtkComposerNodeBooleanOperatorUnaryNot::run(void)
{
    d->emitter.setData(!(d->receiver.data()));
}

// /////////////////////////////////////////////////////////////////
// Binary boolean operator - AND
// /////////////////////////////////////////////////////////////////

void dtkComposerNodeBooleanOperatorBinaryAnd::run(void)
{
    bool a = d->receiver_lhs.data();
    bool b = d->receiver_rhs.data();

    d->emitter.setData(a && b);
}

// /////////////////////////////////////////////////////////////////
// Binary boolean operator - OR
// /////////////////////////////////////////////////////////////////

void dtkComposerNodeBooleanOperatorBinaryOr::run(void)
{
    bool a = d->receiver_lhs.data();
    bool b = d->receiver_rhs.data();

    d->emitter.setData(a || b);
}

// /////////////////////////////////////////////////////////////////
// Binary boolean operator - XOR
// /////////////////////////////////////////////////////////////////

void dtkComposerNodeBooleanOperatorBinaryXor::run(void)
{
    bool a = d->receiver_lhs.data();
    bool b = d->receiver_rhs.data();

    d->emitter.setData( (a && !b) || (!a && b) );
}

// /////////////////////////////////////////////////////////////////
// Binary boolean operator - NAND
// /////////////////////////////////////////////////////////////////

void dtkComposerNodeBooleanOperatorBinaryNand::run(void)
{
    bool a = d->receiver_lhs.data();
    bool b = d->receiver_rhs.data();

    d->emitter.setData( !(a && b) );
}

// /////////////////////////////////////////////////////////////////
// Binary boolean operator - NOR
// /////////////////////////////////////////////////////////////////

void dtkComposerNodeBooleanOperatorBinaryNor::run(void)
{
    bool a = d->receiver_lhs.data();
    bool b = d->receiver_rhs.data();

    d->emitter.setData( !(a || b) );
}

// /////////////////////////////////////////////////////////////////
// Binary boolean operator - XNOR
// /////////////////////////////////////////////////////////////////

void dtkComposerNodeBooleanOperatorBinaryXnor::run(void)
{
    bool a = d->receiver_lhs.data();
    bool b = d->receiver_rhs.data();

    d->emitter.setData( (a && b) || (!a && !b) );
}

// /////////////////////////////////////////////////////////////////
// Binary boolean operator - IMP
// /////////////////////////////////////////////////////////////////

void dtkComposerNodeBooleanOperatorBinaryImp::run(void)
{
    bool a = d->receiver_lhs.data();
    bool b = d->receiver_rhs.data();

    d->emitter.setData( !a || b );
}

// /////////////////////////////////////////////////////////////////
// Binary boolean operator - NIMP
// /////////////////////////////////////////////////////////////////

void dtkComposerNodeBooleanOperatorBinaryNimp::run(void)
{
    bool a = d->receiver_lhs.data();
    bool b = d->receiver_rhs.data();

    d->emitter.setData( a && !b );
}
