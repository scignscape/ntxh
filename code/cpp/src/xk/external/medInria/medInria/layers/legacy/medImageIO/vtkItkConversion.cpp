/*=========================================================================

medInria

Copyright (c) INRIA 2013 - 2018. All rights reserved.
See LICENSE.txt for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.

=========================================================================*/

#include "vtkItkConversion.h"

#include <medAbstractData.h>

#include <itkRGBPixel.h>
#include <itkRGBAPixel.h>

typedef itk::RGBPixel<unsigned char>  RGBPixelType;
typedef itk::RGBAPixel<unsigned char> RGBAPixelType;
typedef itk::Vector<unsigned char, 3> UCharVector3Type;
typedef itk::Vector<float, 3> FloatVector3Type;

/**
* @brief  This function creates an instance of vtkItkConversion.
* @detail Create converter of 3D and 4D itk images on types : double ; float ; int ; unsigned int ; short ; unsigned short ; long ; unsigned long ; char ; unsigned char ; RGBPixelType ; RGBAPixelType ; UCharVector3Type ; FloatVector3Type.
* @param  pi_poData [in] is an input on a medAbstractData.
* @return a vtkItkConversionInterface pointer dynamically allocated. Behind a concrete well templated vtkItkConversion object.<br> null if it fails.
* @callgraph
*/
vtkItkConversionInterface * vtkItkConversionInterface::createInstance(medAbstractData *pi_poData)
{
    vtkItkConversionInterface *poRes = nullptr;

    itk::Object *pItkObjTmp = static_cast<itk::Object *>(pi_poData->data());

    if      ( dynamic_cast<itk::Image<double, 3> *>(pItkObjTmp))            { poRes = new vtkItkConversion<double, 3>(); }
    else if ( dynamic_cast<itk::Image<float, 3> *>(pItkObjTmp) )            { poRes = new vtkItkConversion< float,3 >(); }
    else if ( dynamic_cast<itk::Image<int, 3> *>(pItkObjTmp) )              { poRes = new vtkItkConversion< int,3 >(); }
    else if ( dynamic_cast<itk::Image<unsigned int, 3> *>(pItkObjTmp) )     { poRes = new vtkItkConversion<  unsigned int,3 >(); }
    else if ( dynamic_cast<itk::Image<short, 3> *>(pItkObjTmp) )            { poRes = new vtkItkConversion< short,3 >(); }
    else if ( dynamic_cast<itk::Image<unsigned short, 3> *>(pItkObjTmp) )   { poRes = new vtkItkConversion< unsigned short,3 >(); }
    else if ( dynamic_cast<itk::Image<long, 3> *>(pItkObjTmp) )             { poRes = new vtkItkConversion< long,3 >(); }
    else if ( dynamic_cast<itk::Image<unsigned long, 3> *>(pItkObjTmp) )    { poRes = new vtkItkConversion< unsigned long,3 >(); }
    else if ( dynamic_cast<itk::Image<char, 3> *>(pItkObjTmp) )             { poRes = new vtkItkConversion< char,3 >(); }
    else if ( dynamic_cast<itk::Image<unsigned char, 3> *>(pItkObjTmp) )    { poRes = new vtkItkConversion< unsigned char,3 >(); }
    else if ( dynamic_cast<itk::Image<RGBPixelType, 3> *>(pItkObjTmp) )     { poRes = new vtkItkConversion< RGBPixelType,3 >(); }
    else if ( dynamic_cast<itk::Image<RGBAPixelType, 3> *>(pItkObjTmp) )    { poRes = new vtkItkConversion< RGBAPixelType ,3 >(); }
    else if ( dynamic_cast<itk::Image<UCharVector3Type, 3> *>(pItkObjTmp) ) { poRes = new vtkItkConversion< UCharVector3Type ,3 >(); }
    else if ( dynamic_cast<itk::Image<FloatVector3Type, 3> *>(pItkObjTmp) ) { poRes = new vtkItkConversion< FloatVector3Type ,3 >(); }

    else if (dynamic_cast<itk::Image<double, 4> *>(pItkObjTmp))             { poRes = new vtkItkConversion< double,4 >(); }
    else if (dynamic_cast<itk::Image<float, 4> *>(pItkObjTmp))              { poRes = new vtkItkConversion< float,4 >(); }
    else if (dynamic_cast<itk::Image<int, 4> *>(pItkObjTmp))                { poRes = new vtkItkConversion< int,4 >(); }
    else if (dynamic_cast<itk::Image<unsigned int, 4> *>(pItkObjTmp))       { poRes = new vtkItkConversion< unsigned int,4 >(); }
    else if (dynamic_cast<itk::Image<short, 4> *>(pItkObjTmp))              { poRes = new vtkItkConversion< short,4 >(); }
    else if (dynamic_cast<itk::Image<unsigned short, 4> *>(pItkObjTmp))     { poRes = new vtkItkConversion< unsigned short,4 >(); }
    else if (dynamic_cast<itk::Image<long, 4> *>(pItkObjTmp))               { poRes = new vtkItkConversion< long,4 >(); }
    else if (dynamic_cast<itk::Image<unsigned long, 4> *>(pItkObjTmp))      { poRes = new vtkItkConversion< unsigned long ,4 >(); }
    else if (dynamic_cast<itk::Image<char, 4> *>(pItkObjTmp))               { poRes = new vtkItkConversion< char,4 >(); }
    else if (dynamic_cast<itk::Image<unsigned char, 4> *>(pItkObjTmp))      { poRes = new vtkItkConversion< unsigned char ,4 >(); }
    else if (dynamic_cast<itk::Image<RGBPixelType, 4> *>(pItkObjTmp))       { poRes = new vtkItkConversion< RGBPixelType,4 >(); }
    else if (dynamic_cast<itk::Image<RGBAPixelType, 4> *>(pItkObjTmp))      { poRes = new vtkItkConversion< RGBAPixelType ,4 >(); }

    return poRes;
}