/* axlRpc.i --- Core layer swig interface definition
 *
 * Author: Anais Ducoffe
 * Copyright (C) 2014 - Anais Ducoffe, Inria.
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLRPC_I
#define AXLRPC_I

%module axlrpc
%include "dtkCore.i"

%{

#include <axlRpc/axlClient.h>

%}

// /////////////////////////////////////////////////////////////////
// Undefine preprocessing macros
// /////////////////////////////////////////////////////////////////
#undef  AXLRPC_EXPORT
#define AXLRPC_EXPORT


// /////////////////////////////////////////////////////////////////
// Wrapper input
// /////////////////////////////////////////////////////////////////

%include "axlClient.h"

#endif
