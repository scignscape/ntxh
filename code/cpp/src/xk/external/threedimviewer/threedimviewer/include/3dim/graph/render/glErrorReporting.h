///////////////////////////////////////////////////////////////////////////////
// $Id$
//
// This file comes from proprietary 3Dim Laboratory s.r.o. software
// and was modified for 
// 
// BlueSkyPlan version 3.x
// Diagnostic and implant planning software for dentistry.
// 
// The original license can be found below.
//
// Changes are Copyright 2012 Blue Sky Bio, LLC
// All rights reserved 
//
// Changelog:
//    [2012/mm/dd] - ...
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
// Copyright 2008-2012 3Dim Laboratory s.r.o. 
// All rights reserved 
//
///////////////////////////////////////////////////////////////////////////////

#ifndef GlErrorReporting_H
#define GlErrorReporting_H

#include <osg/GL>

#include <string>

//! Converts glGetError's value to string
std::string glErrorEnumString(GLenum value);

//! Converts glCheckFramebufferStatus's return value to string
std::string glFramebufferStatusString(GLenum value);

//! Creates sensible error message to put to log
std::string glGetErrors(std::string functionName);

bool isDebugContextEnabled();
bool isDebugMessageCallbackAvailable();

bool glGetErrorEnabled();

#define tridimGlR(name, glExp) glExp; { if(glGetErrorEnabled()){std::string errorString = glGetErrors(name); if (!errorString.empty()) VPL_LOG_ERROR(errorString);} }

#endif
