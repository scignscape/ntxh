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

#ifndef VPL_DICOMSLICELOADERVPL_H
#define VPL_DICOMSLICELOADERVPL_H

//VPL
#include <VPL/Base/Setup.h>
#include "DicomSliceLoader.h"

namespace vpl
{
namespace img
{

//==============================================================================
/*!
* Loads DICOM image using native VPL implementation.
*/
class VPL_IMAGEIO_EXPORT CDicomSliceLoaderVPL : public vpl::img::CDicomSliceLoader
{
public:
    //! Default constructor.
    CDicomSliceLoaderVPL(){}

    //! Default destructor.
    ~CDicomSliceLoaderVPL(){}

    //! Loads data from DICOM file, including image data, patient information, etc.
    virtual bool loadDicom(std::string fileName, CDicomSlice &dicomSlice, bool load_image_data = true) override;
    
    //! Reads specified tag from DICOM file
    //! -Returns value as string
    virtual std::string readTag(unsigned int groupNum, unsigned int elemNum) override;

    //! Loads multiframe dicom file, into vector of slices
    virtual bool loadMultiframeDicom(std::string fileName, tSlices &slices, bool load_image_data = true) override;

    //! Loads only one frame from multiframe dicom file into given slice
    virtual bool loadMultiframeDicom(std::string fileName, CDicomSlice &dicomSlice, unsigned int index, bool load_image_data = true) override;

private:
    //! Reads and checks DICOM header.
    //! - Based on P. Krsek's code.
    bool readDicomHeader(vpl::mod::CChannel *pChannel, CDicomSlice &dicomSlice);

    //! Reads DICOM slice data.
    bool readDicom(vpl::mod::CChannel *pChannel, CDicomSlice &dicomSlice, bool load_image_data);

    //! Reads DICOM data element with VR = SQ, jump across, do not take data
    bool readSQDataElement(vpl::mod::CChannel *pChannel, CDicomSlice &dicomSlice);

    //! Internal load method
    bool loadDicom(vpl::mod::CChannel *pChannel, CDicomSlice &dicomSlice, bool load_image_data);
   
    //! Gets element tag group and element.
    bool readElementTag(vpl::mod::CChannel *pChannel,
        unsigned short *pusGroup,
        unsigned short *pusElem
        );

    //! Reads the element tag value length.
    bool readValueLength(vpl::mod::CChannel *pChannel,
        char *pcType,
        bool bExplicit,
        unsigned long *pulLength,
        unsigned long *pulOffset
        );

    //! Reads the element data.
    char *readValueData(vpl::mod::CChannel *pChannel, unsigned long ulLength);
};

} // namespace img
} // namespace vpl

#endif // VPL_DICOMSLICELOADERVPL_H
