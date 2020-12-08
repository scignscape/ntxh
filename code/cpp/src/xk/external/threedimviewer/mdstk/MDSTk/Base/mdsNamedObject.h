//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2003-2009 by Michal Spanel     \n
 *
 * Author:  Michal Spanel, spanel@fit.vutbr.cz  \n
 * Date:    2009/11/22                          \n
 *
 * $Id: mdsNamedObject.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Definition of a named object.
 */

#ifndef MDS_Named_H
#define MDS_Named_H

#include "mdsSetup.h"
#include "mdsBaseExport.h"


namespace mds
{

//==============================================================================
/*
 * Several useful macros.
 */

//! Macro used to add virtual method getClassName() to a class.
//! - Parameter Name is a string literal.
#define MDS_CLASS_NAME(name) \
    virtual const char *getClassName() const \
    { \
        return name; \
    }

//! Special macro used to add virtual method getClassName() to a class template.
//! Name contains information about concrete template parameters.
//! - Parameters Name and Type are string literals or C/STL strings.
#define MDS_TEMPLATE_NAME(Name, Type) \
    virtual const char *getClassName() const \
    { \
        static const std::string ssName = std::string(Name) + '<' + std::string(Type) + '>'; \
        return ssName.c_str(); \
    }

//! Macro used to add static method getClassName() to a class.
//! - Parameters Name is a string literal.
#define MDS_STATIC_NAME(name) \
    static const char *getClassName() \
    { \
        return name; \
    }

//! Special macro used to add static method getClassName() to a class template.
//! Name contains information about concrete template parameters.
//! - Parameters Name and Type are string literals or C/STL strings.
#define MDS_STATIC_TEMPLATE_NAME(Name, Type) \
    static const char *getClassName() \
    { \
        static const std::string ssName = std::string(Name) + '<' + std::string(Type) + '>'; \
        return ssName.c_str(); \
    }


//==============================================================================
/*!
 * Base class for all named objects.
 */
class MDS_BASE_EXPORT CNamed
{
public:
    //! Templates that require members of the CNamed class can use
    //! this enum to check the existence.
    enum { CLASS_NAMED_OBJECT };

    //! Declares standard method getClassName()!
    MDS_CLASS_NAME("CNamed");

public:
    //! Default constructor.
    CNamed() {}

    //! Virtual destructor.
    virtual ~CNamed() {}
};


} // namespace mds

#endif // MDS_Named_H

