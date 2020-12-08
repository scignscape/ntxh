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
#include <gtest/gtest.h>
#include <string>

namespace vpl
{
namespace test
{
namespace defaults
{
const double ulp = 0.0001;
} // namespace defaults


//! Required array data order of test array with required data.
enum ArrayOrder
{
    COLUMN_MAJOR,
    ROW_MAJOR,
};

//! Define access to data in comparation, when function use diferent order  f(x,y)|f(y,x)
enum AccessType
{
    XY_ACCESS,
    YX_ACCESS
};


//! \brief Base class for comparing values, using GTEST methods. 
//! \tparam T Type of single value - e.g tDensityPixel
//! \tparam Object Collection type - e.g CDVolume
template <class Object>
class CompareBase
{
public:
    //! \brief Base contructor
    CompareBase();

    //! \brief Base contructor
    //! \param printData Enable output of data when test failed.
    CompareBase(bool printData);


    //! \brief Settings for data array order.
    //! \param order Row/Collumn order
    void setArrayOrder(ArrayOrder order);

    //! \brief Settings for data array order.
    //! \param access order f(x,y) or f(y,x) 
    void setAccessType(AccessType access);

    //! \brief Settings which define message which will be printed if error ocured.
    //! \param message Error text.
    void setErrorMessage(std::string message);

    //! \brief Settings which enable case sensitive in stringsS
    //! \param isSensitive When true comparation is caseSensitive
    void enableCaseSensitive(bool isSensitive);

    //! \brief Settings which toogle ASSERT/EXCEPT methods, when checks values.
    //! \param isEnabled Switch between ASSERT or EXCEPT gtest test mode.
    void enableAssert(bool isEnabled);

    //! \brief Settings which Disable or Enable output of data when test failed.
    //! \param isPrinting  True = data is printed.
    void enablePrintData(bool isPrinting);


protected:

    ArrayOrder m_arrayOrder;
    AccessType m_accessType;
    bool m_isAssertMode;

    //! \brief 
    //! \tparam Type 
    //! \param requiredData 
    //! \param inputValue 
    //! \param index 
    //! \param dataString 
    //! \param ulp 
    template <typename Type>
    void comparation(Type requiredData, Type inputValue,
        const std::string& index, const std::string& dataString, double ulp = defaults::ulp);

    void comparationString(std::string requiredData, std::string inputValue,
        const std::string& index, const std::string& dataString, double ulp = defaults::ulp) const;

    //! \brief 
    //! \param data 
    //! \return 
    std::string dataToString(const Object& data) const;

private:



    bool m_printData;
    bool m_caseSensitive;
    std::string m_errorMessage;




    //! \brief  Merge multiple parts of error message to one.
    //! \param inMessage What message should be printed
    //! \param index Error position in data
    //! \param dataString Serialized input data
    //! \return merged error message
    static std::string getErrorMessage(const std::string& inMessage, const std::string& index,
        const std::string& dataString);


    //! Integral type comparation
    template <typename Type>
    void compareIntegral(Type requiredData, Type inputValue, std::string index, const std::string& dataString);

    //! \brief 
    //! \param requiredData 
    //! \param inputValue 
    //! \param index 
    //! \param dataString 
    void compareString(const char* requiredData, const char* inputValue, std::string index,
        const std::string& dataString) const;


    //! Comparation of floating number by Near gtest function
    template <typename Type>
    void compareFloat(Type requiredData, Type inputValue, double ulp, std::string index, const std::string& dataString);
};


// Include the file containing functions templates.
#include "compareBase.hxx"

} // namespace vpl
} // namespace test