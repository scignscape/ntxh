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

namespace vpl {
namespace test {

//! Contains settings for data location for testing.
class TestingData
{
public:

    //! Register testing data argument -dir.
    static void allow();

    //! Register testing data argument -dir and initialize it.
    static void init(int argc, char *argv[]);

    //! Return path to directory with test data. 
    //! Path may have 4 values form function:
    //! 1. Value from -dir argument if is used.
    //! 2. Directory from environment variable [TEST_DATA]
    //! 3. If dir is mounted to T: disk this path is used. 
    //! 4. Other: current dir "./"
    static std::string getDirectoryPath();
};

} // namespace test
} // namespace vpl