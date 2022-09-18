/*
Copyright (c) 2008-2013, Northwestern University
All rights reserved.
 
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
 
  Redistributions of source code must retain the above copyright notice,
  this list of conditions and the following disclaimer.
 
  Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.
 
  Neither the name of the Northwestern University nor the names of its contributors
  may be used to endorse or promote products derived from this software
  without specific prior written permission.
 
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

// AIMConverter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <string>

// AIM includes
#include "../AIMLib/AimHeaders.h"

#include "../AIMLib/operations/BaseModel.h"
#include "../AIMLib/operations/DcmModel.h"
#include "../AIMLib/operations/XmlModel.h"

#include "AIMConverter.h"

#include <stdexcept>
#include <iostream>
#include <fstream>

using namespace std;

#include "ConverterUtil.h"

static const std::string CONVERTER_PARAM_SR = std::string("SR");
static const std::string CONVERTER_PARAM_XML = std::string("XML");
static const std::string CONVERTER_PARAM_CDA = std::string("CDA");

AIMConverter::AIMConverter()
{
}

AIMConverter::~AIMConverter()
{
}

int main(int argc, char* argv[])
{
	string err; // error(s) to report

	if (argc > 6)
	{
		string arg;
		string inFileName, outFileName;
		AIMConverter::AIM_FILE_TYPE inputType = AIMConverter::AFT_UNKNOWN;
		AIMConverter::AIM_FILE_TYPE outputType = AIMConverter::AFT_UNKNOWN;

		int argIdx = 1;
		while (argIdx < 4 && err.empty()) // check the first two parameters with their arguments
		{
			// Input file type
			arg.assign(argv[argIdx]);
			if (ConverterUtil::nocase_cmp(arg, "-i") == 0 || ConverterUtil::nocase_cmp(arg, "-input") == 0 )
			{
				arg.assign(argv[argIdx + 1]);
				if (ConverterUtil::nocase_cmp(arg, CONVERTER_PARAM_XML) == 0)
					inputType = AIMConverter::AFT_AIM_XML;
				else if (ConverterUtil::nocase_cmp(arg, CONVERTER_PARAM_SR) == 0)
					inputType = AIMConverter::AFT_DICOM_SR;
				else if (ConverterUtil::nocase_cmp(arg, CONVERTER_PARAM_CDA) == 0)
					inputType = AIMConverter::AFT_HL7_CDA;
				else
					err.assign("Unknown input type \"").append(arg).append("\"");
			}
			// Output file type
			else if (ConverterUtil::nocase_cmp(arg, "-o") == 0 || ConverterUtil::nocase_cmp(arg, "-output") == 0 )
			{
				arg.assign(argv[argIdx + 1]);
				if (ConverterUtil::nocase_cmp(arg, CONVERTER_PARAM_XML) == 0)
					outputType = AIMConverter::AFT_AIM_XML;
				else if (ConverterUtil::nocase_cmp(arg, CONVERTER_PARAM_SR) == 0)
					outputType = AIMConverter::AFT_DICOM_SR;
				else if (ConverterUtil::nocase_cmp(arg, CONVERTER_PARAM_CDA) == 0)
					outputType = AIMConverter::AFT_HL7_CDA;
				else
					err.assign("Unknown output type \"").append(arg).append("\"");
			}
			argIdx += 2;
		}

		if (inputType == AIMConverter::AFT_UNKNOWN || outputType == AIMConverter::AFT_UNKNOWN || !err.empty())
			goto USAGE;

		inFileName.assign(argv[5]);
		outFileName.assign(argv[6]);

		// Do Conversion
		AIMConverter aimConverter;
		err = aimConverter.DoConversion(inFileName, inputType, outFileName, outputType);

		if (err.empty())
			return 0;

		// Fall through
	}

USAGE:
	// Usage:
	// converter -i[nput] XML|SR|CDA -o[utput] XML|SR|CDA input_file_name output_file_name

	if (!err.empty())
		cout << "Error: " << err << endl;

	cout << "Usage:" << endl;
	string progName = argv[0];
	string::size_type pos = progName.find_last_of("\\");
	if (pos != string::npos)
		progName = progName.substr(pos + 1);
	pos = progName.find_last_of("/");
	if (pos != string::npos)
		progName = progName.substr(pos + 1);
	const static std::string params(CONVERTER_PARAM_XML + "|" + CONVERTER_PARAM_SR + "|" + CONVERTER_PARAM_CDA); // "XML|SR|CDA"
	cout << progName << " -i[nput] " << params << " -o[utput] " << params << " input_file output_file" << endl;

	return -1;
}

string AIMConverter::DoConversion(const string& inFileName, AIM_FILE_TYPE inFileType, const string& outFileName, AIM_FILE_TYPE outFileType)
{
	string err;

	// 1. Input/Output file types are the same
	// Do simple file copy
	if (inFileType == outFileType)
	{
		ifstream infile(inFileName.c_str());
		if (infile)
		{
			ofstream outfile(outFileName.c_str());
			if (outfile)
			{
				outfile << infile.rdbuf();
				outfile.flush();
				outfile.close();
				infile.close();
			}
			else
			{
				err.assign("Output file \"").append(outFileName).append("\" cannot be open for writing");
			}
		}
		else
		{
			err.assign("Input file \"").append(inFileName).append("\" cannot be open for reading");
		}

		return err;
	}

	// 2. Input/output file types are different.

	aim_lib::AnnotationCollection* pAnnotationCollection = NULL;
	aim_lib::BaseModel* pInputModel = NULL;

	// Create input document model
	try
	{
		err = this->CreateModel(inFileType, &pInputModel);
	}
	catch(exception& ex)
	{
		err.assign("Failed to create input file model for file \"" + inFileName + "\"\nError:\n").append(ex.what());
	}

	if (!err.empty())
	{
		delete pInputModel;
		pInputModel = NULL;
		return err;
	}

	if (pInputModel == NULL)
		return "Failed to create input file model. Out of memory?";

	// Read all annotations into memory
	try
	{
		pAnnotationCollection = pInputModel->ReadAnnotationCollectionFromFile(inFileName);
	}
	catch(exception& ex)
	{
		err.assign("Error reading annotation(s) from file \"").append(inFileName).append("\":\n").append(ex.what());
	}

	delete pInputModel;
	pInputModel = NULL;

	if (!pAnnotationCollection)
	{
		return err.empty() ? "No annotation was read from file \"" + inFileName + "\". Does the file exist?" : err;
	}

	// Create output document model
	aim_lib::BaseModel* pOutputModel = NULL;
	try
	{
		err = this->CreateModel(outFileType, &pOutputModel);
	}
	catch(exception& ex)
	{
		err.assign("Failed to create output file model for file \"" + outFileName + "\"\nError:\n").append(ex.what());
	}

	if (err.empty())
	{
		if (pOutputModel)
		{
			// Write annotation(s) to file
			try
			{
				pOutputModel->WriteAnnotationCollectionToFile(pAnnotationCollection, outFileName);
			}
			catch(exception& ex)
			{
				err.assign("Error writing annotation(s) to file \"").append(outFileName).append("\":\n").append(ex.what());
			}
		}
		else
			err.assign("Failed to create output file model. Out of memory?");
	}

	delete pOutputModel;
	pOutputModel = NULL;

	delete pAnnotationCollection;
	pAnnotationCollection = NULL;

	return err;
}

std::string AIMConverter::CreateModel(AIM_FILE_TYPE modelType, aim_lib::BaseModel** pModel)
{
	std::string err;

	switch(modelType)
	{
	case AFT_AIM_XML:
		try
		{
			*pModel = new aim_lib::XmlModel();
		}
		catch(...){}
		break;
	case AFT_DICOM_SR:
		try
		{
			*pModel = new aim_lib::DcmModel();
		}
		catch(...){}
		break;
	case AFT_HL7_CDA:
		err.assign("HL7 CDA model is not supported");
		//try
		//{
		//	*pModel = new aim_lib::CdaModel();
		//}
		//catch(...){}
		break;
	default:
		err.assign("Unknown input file type");
		break;
	}

	return err;
}
