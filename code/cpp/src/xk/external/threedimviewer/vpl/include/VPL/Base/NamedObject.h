//==============================================================================
/* This file comes from MDSTk software and was modified for
 * 
 * VPL - Voxel Processing Library
 * Changes are Copyright 2014 3Dim Laboratory s.r.o.
 * All rights reserved.
 * 
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 * 
 * The original MDSTk legal notice can be found below.
 *
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2009 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2009/11/22                          \n
 *
 * Description:
 * - Definition of a named object.
 */

#ifndef VPL_Named_H
#define VPL_Named_H

#include "Setup.h"
#include "BaseExport.h"


namespace vpl
{

//==============================================================================
/*
 * Several useful macros.
 */

//! Macro used to add virtual method getClassName() to a class.
//! - Parameter Name is a string literal.
#define VPL_CLASS_NAME(name) \
    virtual const char *getClassName() const \
    { \
        return name; \
    }

//! Special macro used to add virtual method getClassName() to a class template.
//! Name contains information about concrete template parameters.
//! - Parameters Name and Type are string literals or C/STL strings.
#define VPL_TEMPLATE_NAME(Name, Type) \
    virtual const char *getClassName() const \
    { \
        static const std::string ssName = std::string(Name) + '<' + std::string(Type) + '>'; \
        return ssName.c_str(); \
    }

//! Macro used to add static method getClassName() to a class.
//! - Parameters Name is a string literal.
#define VPL_STATIC_NAME(name) \
    static const char *getClassName() \
    { \
        return name; \
    }

//! Special macro used to add static method getClassName() to a class template.
//! Name contains information about concrete template parameters.
//! - Parameters Name and Type are string literals or C/STL strings.
#define VPL_STATIC_TEMPLATE_NAME(Name, Type) \
    static const char *getClassName() \
    { \
        static const std::string ssName = std::string(Name) + '<' + std::string(Type) + '>'; \
        return ssName.c_str(); \
    }


//==============================================================================
/*!
 * Base class for all named objects.
 */
class VPL_BASE_EXPORT CNamed
{
public:
    //! Templates that require members of the CNamed class can use
    //! this enum to check the existence.
    enum { CLASS_NAMED_OBJECT };

    //! Declares standard method getClassName()!
    VPL_CLASS_NAME("CNamed");

public:
    //! Default constructor.
    CNamed() {}

    //! Virtual destructor.
    virtual ~CNamed() {}
};


} // namespace vpl

#endif // VPL_Named_H

