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

#pragma once
#include <string>
#include "VPL/Module/Argv.h"

namespace vpl {
namespace test {

//! Singleton wrapper on VPL CArgv.
class Arguments
{
public:

	//! Singleton getter
	static Arguments& get()
	{
		static Arguments instance;
		return instance;
	}
    
	//! Initialize and parse input arguments
    void init(int argc, char *argv[]);

	//! Allow argument
	//! Example:
	//!		allow("dir");
    void allow(const std::string& arg);

	//! Getter for value. For any type which support mod::CArgv
    bool value(const std::string& sLabel, std::string& sValue) const;
    bool value(const std::string& sLabel, char& cValue) const;
    bool value(const std::string& sLabel, unsigned& uValue) const;
    bool value(const std::string& sLabel, int& iValue) const;
    bool value(const std::string& sLabel, double& dValue) const;

#ifdef VPL_USE_64BIT_SIZE_TYPE
    bool value(const std::string& sLabel, tSize& Value) const;
#endif

private:
	//! Hidden costructor
	Arguments() = default;
	//! Allowed command line arguments.
    std::string m_sAllowedArguments;
    //! Parsed command line arguments.
    mod::CArgv m_arguments;
};
} // namespace test
} // namespace vpl