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
#include <map>
#include <vector>
#include <VPL/Test/Utillities/genericValue.h>
#include <VPL/Base/Exception.h>
namespace vpl
{
namespace test
{

//! \brief Helper for test where are required reference inputs.
//!
//! When is called load method is parsed json configuration files, with multiple defined tests.
//! "input" is image which will be loaded and then modifed by test code, 
//!	can be set globaly for all test or override for one test.
//! 
//! json example:
//!
//! {
//! 	"input": "lena.png",
//!		"nameOfTest1" :
//! 	{
//! 		"reference": "gauss/lenaGauss2.png",
//! 			"psnr" : 40,
//! 			"sigma" : 2
//! 	},
//!		"nameOfTest2":
//! 	{
//! 		"input": "test.png",
//! 		"reference" : "gauss/testGaus1.png",
//! 		"psnr" : 30,
//! 		"sigma" : 1
//! 	}
//! }
//! Other arguments is used for settings filters in test code.
//! 
//! Code example:
//! 
//! vpl::test::ReferenceData config;
//! config.load(dirPath, "gauss")
//! std::string commonInput;
//! if (config.getGlobalInput(commonInput))
//! {
//! 	LoadImage(*inImage, commonInput);
//! }
//! for (int i = 0; i < config.getTestCount(); i++)
//! {
//!		vpl::img::CImage16Ptr testImage(new vpl::img::CImage16(*inImage));
//!		std::string input;
//!		if (config.getInput(i, input))
//!		{
//!			const vpl::img::CImage16Ptr inputImage;
//!			LoadImage(*inputImage, input);
//!			testImage = inputImage;
//!		}
//! 	const std::string refImage = config.getString("reference", i);
//! 	const double sigma = config.getNumber<double>("sigma", i);
//! 	double psnrRequired = config.getNumber<double>("psnr", i);
//!		---- Do something with parameters ----
//! }
class ReferenceData
{
public:
    
    //! \brief Base Constructor
	ReferenceData();

    //! \brief Load and parse config file
    //! \param directory path to config file directory
    //! \param fileName name of config file
    //! \param extension extension of config file 
    //! \return True if parsing was success
	bool load(const std::string& directory, const std::string& fileName, const std::string& extension = "json");


    //! \brief Getter for string.
	//! \param tag Arguments in json
	//! \param testCase Test ID :: 1 to n
	//! \return converted value to required type
    std::string getString(const std::string& tag, const int testCase);
    
    //! \brief Getter for bool.
	//! \param tag Arguments in json
	//! \param testCase Test ID :: 1 to n
	//! \return converted value to required type
    bool getBool(const std::string& tag, const int testCase);

	//! \brief Getter for number type.
    //! \tparam T Number type: float, int, double ...
    //! \param tag Arguments in json
    //! \param testCase Test ID :: 1 to n
    //! \return converted value to required type
    template<typename T>
    T getNumber(const std::string& tag, const int testCase);

    //! \brief Getter for number of tests
    int getTestCount() const;

    //! \brief Getter for global input
    bool getGlobalInput(std::string& fileName) const;


    //! \brief Getter for input per test
    //! \param fileName Input filename
    //! \param testCase Test ID :: 1 to n
    //! \return True if test was defined with custom input.
    bool getInput(std::string & fileName, const int testCase);

private:
	//! Is tag in map?
	void checkKey(const std::string& tag);

	//! Data container
    std::map<std::string, std::map<int,GenericValue>> m_data;
    //! Test count
	int m_count;
	//! Global input filename
    std::string m_input;
};

 
template <typename T>
T ReferenceData::getNumber(const std::string& tag, const int testCase)
{
	assert(-1 < testCase && testCase < m_count);
	T ret;
	checkKey(tag);
	const GenericValue value = m_data[tag][testCase];
	switch (value.type())
	{
		case GenericValue::INTEGER: ret = static_cast<T>(value.integerValue()); break;
		case GenericValue::DOUBLE:Double: ret = static_cast<T>(value.doubleValue()); break;
		case GenericValue::FLOAT: ret = static_cast<T>(value.floatValue()); break;
		case GenericValue::BOOL: ret = static_cast<T>(value.boolValue()); break;

		default:;
	}
	return ret;
}

VPL_DECLARE_EXCEPTION(ReferenceDataKeyFailed, "Key was not found")


} // namespace test
} // namespace vpl

