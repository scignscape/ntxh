//==============================================================================
/* This file is part of
*
* VPL - Voxel Processing Library
* Copyright 2014 3Dim Laboratory s.r.o.
* All rights reserved.
*
* Use of this source code is governed by a BSD-style license that can be
* found in the LICENSE file.
*/

#include <gtest/gtest.h>
#include "VPL/Test/Utillities/arguments.h"

namespace vpl {
namespace test {


void Arguments::init(const int argc, char *argv[])
{
    // Parsing command line arguments
    m_arguments.parse(argc, argv);
}
void Arguments::allow(const std::string& arg)
{
    if (arg.length() > 0)
    {
        m_sAllowedArguments += std::string(":") + arg;
    }
}

bool Arguments::value(const std::string & sLabel, std::string & sValue) const
{
    return m_arguments.value(sLabel, sValue);
}

bool Arguments::value(const std::string & sLabel, char & cValue) const
{
    return m_arguments.value(sLabel, cValue);
}

bool Arguments::value(const std::string & sLabel, unsigned & uValue) const
{
    return m_arguments.value(sLabel, uValue);
}

bool Arguments::value(const std::string & sLabel, int & iValue) const
{
    return m_arguments.value(sLabel, iValue);
}

bool Arguments::value(const std::string & sLabel, double & dValue) const
{
    return m_arguments.value(sLabel, dValue);
}

#ifdef VPL_USE_64BIT_SIZE_TYPE

bool Arguments::value(const std::string& sLabel, tSize& Value) const
{
    return m_arguments.value(sLabel, Value);
}

#endif // VPL_USE_64BIT_SIZE_TYPE
} 
}

