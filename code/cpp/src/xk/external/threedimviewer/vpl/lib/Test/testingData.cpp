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

#include <VPL/Test/Utillities/testingData.h>
#include <VPL/Test/Utillities/arguments.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstdlib>
#include <iostream>

namespace vpl {
namespace test {

namespace settings
{
const char* diskPathWithTestData = "T:/";
}

void TestingData::allow()
{
    vpl::test::Arguments& testArgv = vpl::test::Arguments::get();
    testArgv.allow("dir");
}

void TestingData::init(int argc, char *argv[])
{
    vpl::test::Arguments& testArgv = vpl::test::Arguments::get();
    testArgv.allow("dir");
    testArgv.init(argc, argv);
}

std::string TestingData::getDirectoryPath()
{
    std::string dirPath;

    if (const char* envVariable = std::getenv("TEST_DATA"))
    {
        dirPath = envVariable;
    }
    else
    {
        struct stat info {};
        //! Not mounted data to disk, use current directory
        if (stat(settings::diskPathWithTestData, &info) != 0)
        {
            dirPath = "./";
        }
        //! Disk is mounted use it.
        else if (info.st_mode & S_IFDIR)
        {
            dirPath = settings::diskPathWithTestData;
        }
    }

    //! Check dir argument
    Arguments& testArgv = Arguments::get();
    testArgv.value("dir", dirPath);

    return dirPath;
}

} 
}

