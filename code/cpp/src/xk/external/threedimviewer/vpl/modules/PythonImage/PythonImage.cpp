//==============================================================================
/* This file is part of
*
* VPL - Voxel Processing Library
* Copyright 2017 3Dim Laboratory s.r.o.
* All rights reserved.
*
* Use of this source code is governed by a BSD-style license that can be
* found in the LICENSE file.
*/

#include "PythonImage.h"
#include <iostream>
#include <string>
#include <VPL\Image\Slice.h>
#include <PyLib\PythonInterpret.h>
#include <PyLib\runtime.h>
#include <PyLib\SwigType.h>
#include "VPL/Image/DensityVolume.h"

#ifdef _DEBUG
#undef _DEBUG
#include <python.h>
#define _DEBUG
#else
#include <python.h>
#endif

#ifdef _MSC_VER
#define PYTHON_INTERPRETER_NO_DEBUG
#endif

//==============================================================================
/*
* Global module constants.
*/

//! Module description
const std::string MODULE_DESCRIPTION = "Module run python script on PNG image data";

//! Additional command line arguments
const std::string MODULE_ARGUMENTS = "source";

//! Additional arguments
const std::string MODULE_ARG_SOURCE = "source";


//==============================================================================
/*
* Implementation of the class CPythonImage.
*/
CPythonImage::CPythonImage(const std::string& sDescription)
    : vpl::mod::CModule(sDescription)
{
    allowArguments(MODULE_ARGUMENTS);
}


CPythonImage::~CPythonImage()
{
}


bool CPythonImage::startup()
{
    // Note
    VPL_LOG_INFO("Module startup");

    // Test of existence of input and output channel
    if (getNumOfInputs() != 1 || getNumOfOutputs() != 1)
    {
        VPL_LOG_ERROR('<' << m_sFilename << "> Wrong number of input and output channels" << std::endl);
        return false;
    }

    // Python source
    m_Arguments.value(MODULE_ARG_SOURCE, m_ssSource);

    // O.K.
    return true;
}

const wchar_t *GetWC(const char *c) {
    const size_t cSize = strlen(c) + 1;
    std::wstring wc(cSize, L'#');
    mbstowcs(&wc[0], c, cSize);
    return wc.data();
}

bool CPythonImage::main()
{
    // Note
    VPL_LOG_INFO("Module main function");

    // I/O channels
    vpl::mod::CChannel *pIChannel = getInput(0);
    vpl::mod::CChannel *pOChannel = getOutput(0);


    // Is any input?
    if (!pIChannel->isConnected())
    {
        return false;
    }

 
    pylib::CPythonInterpret interpret;
    interpret.initilizeInterpretWithVPLSwig("C:/Users/melcer/3Dim/app/VPLPython/VPLSwig 20180220", "VPLSwig.Core.Core");
    
    vpl::mod::CProgress progress;
    pylib::CSwigType typeProgress("vpl::mod::CProgress");
    interpret.get()->addArgument(typeProgress.class2PyObject<vpl::mod::CProgress *>(&progress));
    
    /*
	pylib::CPython py;
    py.load("VPLSwig.Image.Image");
    py.load(m_ssSource);


    // Create a new slice
    vpl::img::CImage16Ptr spImage(new vpl::img::CImage16(100,100,10));

    // Wait for data
    if (pIChannel->wait(1000))
    {
        // Read slice from the input channel
        if (readInput(pIChannel, spImage.get()))
        {
            // Pad image margin
            spImage->mirrorMargin();
			pylib::CSwigType type("vpl::img::CImage", "vpl::img::tPixel16", DEFINE2STRING(VPL_IMAGE_DATA_ALLOCATOR));

			py.addArgument(type.class2PyObject<vpl::img::CImage16 *>(spImage.get()));

            PyObject* ret;
            py.call(m_ssSource, "method1", &ret);

            if (ret != nullptr)
            {
                vpl::img::CImage16Ptr spFiltered(type.pyObject2Class<vpl::img::CImage16 *>(ret));

                if (!writeOutput(pOChannel, spFiltered.get()))
                {
                    VPL_LOG_ERROR('<' << m_sFilename << "> Failed to write the output slice" << std::endl);
                    return false;
                }
            }
        }
       
    }




    //Py_Initialize();
    //py.class2python();

    /*PyObject *module = PyImport_ImportModule("VPLSwig.Image.Image");*/



    
    //argMap["ahoj"] = vpl::py::Type::Py_string;

    ////int argc = 3;
    //char * argv[3];

    //argv[0] = (char*)m_ssSource.c_str();
    //int med = pIChannel->getMedium();

    //std::string channelFilename;

    //channelFilename = pIChannel->getFileName();
    //std::string argValueIn = vpl::mod::CH_MEDIUM_TYPE[pIChannel->getMedium()];
    //if (channelFilename.length() > 0)
    //{
    //    argValueIn += ":" + channelFilename;
    //}
    //argv[1] = (char*)argValueIn.c_str(); // + ":" + pIChannel->getFileName()).c_str();

    //channelFilename = pOChannel->getFileName();

    //std::string argValueOut = vpl::mod::CH_MEDIUM_TYPE[pOChannel->getMedium()];
    //if (channelFilename.length() > 0)
    //{
    //    argValueOut += ":" + channelFilename;
    //}

    //argv[2] = (char*)argValueOut.c_str(); // + ":" + pOChannel->getFileName()).c_str();*/


    //vpl::py::Python py(argc, argv);

    //py.run_file("test.py");

    //Py_Initialize();
    
    

  /*  wchar_t* wargv[3];
    for (int i = 0; i < 3; i++)
    {
        size_t *t = (size_t*)malloc(sizeof(size_t)); ;
        *t = strlen(argv[i]);
        wargv[i] = Py_DecodeLocale(argv[i], t);
        free(t);
    }

    Py_SetProgramName(wargv[0]);
    PySys_SetArgv(argc, wargv);


    PyObject *obj = Py_BuildValue("s", "test.py");
    FILE *file = _Py_fopen("test.py", "r+");
    if (file != NULL) {
        PyRun_SimpleFile(file, "test.py");
    }
    Py_Finalize();
*/
   

// Returning 'true' means to continue processing the input channel
    return true;
}


void CPythonImage::shutdown()
{
    // Note
    VPL_LOG_INFO("Module shutdown");
}


void CPythonImage::writeExtendedUsage(std::ostream& Stream)
{
    Stream << "Extended usage: [-source ssSource]" << std::endl;
    Stream << "Options:" << std::endl;
    Stream << "  -source  Specifies python source path." << std::endl;
    Stream << std::endl;
    Stream << "Input: VPL image" << std::endl;
    Stream << "Output: VPL image" << std::endl;
}


//==============================================================================
/*
* Function main() which creates and executes console application.
*/
int main(int argc, char *argv[])
{
    // Creation of a module using smart pointer
    /*CPythonImagePtr spModule(new CPythonImage(MODULE_DESCRIPTION));

    pylib::CPythonInterpret interpret;
    interpret.initilizeInterpretWithVPLSwig("C:/Users/melcer/3Dim/app/VPLPython/VPLSwig 20180220", "VPLSwig.Core.Core");

    vpl::mod::CProgress progress;
    pylib::CSwigType typeProgress("vpl::mod::CProgress");
    interpret.get()->addArgument(typeProgress.class2PyObject<vpl::mod::CProgress *>(&progress));

    /*

    pylib::CPythonInterpret interpret;
    interpret.initilizeInterpretWithVPLSwig("C:/Users/melcer/3Dim/app/VPLPython/VPLSwig 20180111", "VPLSwig.VPLPython");

    if (!interpret.loadModule("C:/Users/melcer/3Dim/app/VPLPython/VPLSwigTest 20180111", "processVolume"))
    {
        std::cerr << "Module not loaded";
    }

    vpl::img::CDensityVolume volume(10, 10, 50, 10);
    volume.fillEntire(0);
    std::cout << "volume: " << volume.at(5, 5, 5) << std::endl;


    pylib::CSwigType type("vpl::img::CDensityVolume");
    interpret.get()->addArgument(type.class2PyObject<vpl::img::CDensityVolume *>(&volume));

    if (!interpret.get()->call("processVolume", "processVolume"))
    {
        std::cerr << "Function failed";
    }
    std::cout << "volume: " << volume.at(5, 5, 5) << std::endl;*/
   /* // Initialize and execute the module
    if (spModule->init(argc, argv))
    {
        spModule->run();
    }*/

    pylib::CPythonInterpret interpret;
    std::string vplswigPath = "C:/Users/melcer/3Dim/app/VPLPython/VPLSwig 20180222";
    interpret.initilizeInterpretWithVPLSwig(vplswigPath, "VPLSwig.Core.Core");
    interpret.loadModule(vplswigPath, "VPLSwig.Volume.Volume");

    vpl::mod::CProgress progress;
    pylib::CSwigType typeProgress("vpl::mod::CProgress");
    interpret.get()->addArgument(typeProgress.class2PyObject<vpl::mod::CProgress *>(&progress));

    vpl::img::CDensityVolume volume(10, 10, 50, 10);
    pylib::CSwigType type("vpl::img::CDensityVolume");
    interpret.get()->addArgument(type.class2PyObject<vpl::img::CDensityVolume *>(&volume));
    
    // Console application finished
    return 0;
}

