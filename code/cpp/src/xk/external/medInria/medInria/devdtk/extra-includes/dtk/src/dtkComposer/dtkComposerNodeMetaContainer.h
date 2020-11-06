// Version: $Id: a7d873910326f34d7d73c49ad47c14c69698d17e $
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

#include "dtkComposerNodeLeaf.h"

class dtkComposerNodeMetaContainerPrivate;

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeMetaContainer interface
// /////////////////////////////////////////////////////////////////

class DTKCOMPOSER_EXPORT dtkComposerNodeMetaContainer : public dtkComposerNodeLeaf
{
public:
    dtkComposerNodeMetaContainer(void);
    ~dtkComposerNodeMetaContainer(void);

public:
    void run(void);

private:
    dtkComposerNodeMetaContainerPrivate *d;
};


// /////////////////////////////////////////////////////////////////
// dtkComposerNodeMetaContainerAppend interface
// /////////////////////////////////////////////////////////////////

class dtkComposerNodeMetaContainerAppendPrivate;

class DTKCOMPOSER_EXPORT dtkComposerNodeMetaContainerAppend : public dtkComposerNodeLeaf
{
public:
    dtkComposerNodeMetaContainerAppend(void);
    ~dtkComposerNodeMetaContainerAppend(void);

public:
    void run(void);

private:
    dtkComposerNodeMetaContainerAppendPrivate *d;
};


// /////////////////////////////////////////////////////////////////
// dtkComposerNodeMetaContainerSize interface
// /////////////////////////////////////////////////////////////////

class dtkComposerNodeMetaContainerSizePrivate;

class DTKCOMPOSER_EXPORT dtkComposerNodeMetaContainerSize : public dtkComposerNodeLeaf
{
public:
    dtkComposerNodeMetaContainerSize(void);
    ~dtkComposerNodeMetaContainerSize(void);

public:
    void run(void);

private:
    dtkComposerNodeMetaContainerSizePrivate *d;
};

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeMetaContainerSize interface
// /////////////////////////////////////////////////////////////////

class dtkComposerNodeMetaContainerAtPrivate;

class DTKCOMPOSER_EXPORT dtkComposerNodeMetaContainerAt : public dtkComposerNodeLeaf
{
public:
    dtkComposerNodeMetaContainerAt(void);
    ~dtkComposerNodeMetaContainerAt(void);

public:
    void run(void);

private:
    dtkComposerNodeMetaContainerAtPrivate *d;
};


// /////////////////////////////////////////////////////////////////
// dtkComposerNodeMetaContainerSetAt interface
// /////////////////////////////////////////////////////////////////

class dtkComposerNodeMetaContainerSetAtPrivate;

class DTKCOMPOSER_EXPORT dtkComposerNodeMetaContainerSetAt : public dtkComposerNodeLeaf
{
public:
    dtkComposerNodeMetaContainerSetAt(void);
    ~dtkComposerNodeMetaContainerSetAt(void);

public:
    void run(void);

private:
    dtkComposerNodeMetaContainerSetAtPrivate *d;
};

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeMetaContainerRemoveAt interface
// /////////////////////////////////////////////////////////////////

class dtkComposerNodeMetaContainerRemoveAtPrivate;

class DTKCOMPOSER_EXPORT dtkComposerNodeMetaContainerRemoveAt : public dtkComposerNodeLeaf
{
public:
    dtkComposerNodeMetaContainerRemoveAt(void);
    ~dtkComposerNodeMetaContainerRemoveAt(void);

public:
    void run(void);

private:
    dtkComposerNodeMetaContainerRemoveAtPrivate *d;
};


// /////////////////////////////////////////////////////////////////
// dtkComposerNodeMetaContainerTakeAt interface
// /////////////////////////////////////////////////////////////////

class dtkComposerNodeMetaContainerTakeAtPrivate;

class DTKCOMPOSER_EXPORT dtkComposerNodeMetaContainerTakeAt : public dtkComposerNodeLeaf
{
public:
    dtkComposerNodeMetaContainerTakeAt(void);
    ~dtkComposerNodeMetaContainerTakeAt(void);

public:
    void run(void);

private:
    dtkComposerNodeMetaContainerTakeAtPrivate *d;
};

// /////////////////////////////////////////////////////////////////
// dtkComposerNodeMetaContainerInsert interface
// /////////////////////////////////////////////////////////////////

class dtkComposerNodeMetaContainerInsertPrivate;

class DTKCOMPOSER_EXPORT dtkComposerNodeMetaContainerInsert : public dtkComposerNodeLeaf
{
public:
    dtkComposerNodeMetaContainerInsert(void);
    ~dtkComposerNodeMetaContainerInsert(void);

public:
    void run(void);

private:
    dtkComposerNodeMetaContainerInsertPrivate *d;
};


// /////////////////////////////////////////////////////////////////
// dtkComposerNodeMetaContainerPrepend interface
// /////////////////////////////////////////////////////////////////

class dtkComposerNodeMetaContainerPrependPrivate;

class DTKCOMPOSER_EXPORT dtkComposerNodeMetaContainerPrepend : public dtkComposerNodeLeaf
{
public:
    dtkComposerNodeMetaContainerPrepend(void);
    ~dtkComposerNodeMetaContainerPrepend(void);

public:
    void run(void);

private:
    dtkComposerNodeMetaContainerPrependPrivate *d;
};


// /////////////////////////////////////////////////////////////////
// dtkComposerNodeMetaContainerResize interface
// /////////////////////////////////////////////////////////////////

class dtkComposerNodeMetaContainerResizePrivate;

class DTKCOMPOSER_EXPORT dtkComposerNodeMetaContainerResize : public dtkComposerNodeLeaf
{
public:
    dtkComposerNodeMetaContainerResize(void);
    ~dtkComposerNodeMetaContainerResize(void);

public:
    void run(void);

private:
    dtkComposerNodeMetaContainerResizePrivate *d;
};
//
// dtkComposerNodeMetaContainer.h ends here
