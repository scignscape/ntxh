// Version: $Id: d143b3c87300a6bdd15c0e75c1bcd4608dbb367f $
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

#include "dtkComposerExtension.h"

class dtkComposerNodeFactory;

// -- Base nodes

class DTKCOMPOSER_EXPORT dtkComposerBaseExtension : public dtkComposerExtension
{
public:
     dtkComposerBaseExtension(void) {};
    ~dtkComposerBaseExtension(void) {};

public:
    void extend(dtkComposerNodeFactory *factory);
};

// -- Files nodes

class DTKCOMPOSER_EXPORT dtkComposerFileExtension : public dtkComposerExtension
{
public:
     dtkComposerFileExtension(void) {};
    ~dtkComposerFileExtension(void) {};

public:
    void extend(dtkComposerNodeFactory *factory);
};

// -- Distributed nodes

class DTKCOMPOSER_EXPORT dtkComposerDistributedExtension : public dtkComposerExtension
{
public:
     dtkComposerDistributedExtension(void) {};
    ~dtkComposerDistributedExtension(void) {};

public:
    void extend(dtkComposerNodeFactory *factory);
};

// -- Constants nodes

class DTKCOMPOSER_EXPORT dtkComposerConstantsExtension : public dtkComposerExtension
{
public:
     dtkComposerConstantsExtension(void) {};
    ~dtkComposerConstantsExtension(void) {};

public:
    void extend(dtkComposerNodeFactory *factory);
};

// -- Control nodes

class DTKCOMPOSER_EXPORT dtkComposerControlExtension : public dtkComposerExtension
{
public:
     dtkComposerControlExtension(void) {};
    ~dtkComposerControlExtension(void) {};

public:
    void extend(dtkComposerNodeFactory *factory);
};

// -- Boolean nodes

class DTKCOMPOSER_EXPORT dtkComposerBooleanExtension : public dtkComposerExtension
{
public:
     dtkComposerBooleanExtension(void) {};
    ~dtkComposerBooleanExtension(void) {};

public:
    void extend(dtkComposerNodeFactory *factory);
};

// -- Number nodes

class DTKCOMPOSER_EXPORT dtkComposerNumberExtension : public dtkComposerExtension
{
public:
     dtkComposerNumberExtension(void) {};
    ~dtkComposerNumberExtension(void) {};

public:
    void extend(dtkComposerNodeFactory *factory);
};

// -- String nodes

class DTKCOMPOSER_EXPORT dtkComposerStringExtension : public dtkComposerExtension
{
public:
     dtkComposerStringExtension(void) {};
    ~dtkComposerStringExtension(void) {};

public:
    void extend(dtkComposerNodeFactory *factory);
};

// -- Containers nodes

class DTKCOMPOSER_EXPORT dtkComposerContainerExtension : public dtkComposerExtension
{
public:
     dtkComposerContainerExtension(void) {};
    ~dtkComposerContainerExtension(void) {};

public:
    void extend(dtkComposerNodeFactory *factory);
};

//
// dtkComposerDefaultExtensions.h ends here
