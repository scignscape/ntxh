///////////////////////////////////////////////////////////////////////////////
// $Id$
//
// 3DimViewer
// Lightweight 3D DICOM viewer.
//
// Copyright 2008-2016 3Dim Laboratory s.r.o.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef CSeries_H
#define CSeries_H

#include <VPL/Base/SharedPtr.h>
#include <VPL/ImageIO/DicomSlice.h>

#include <data/CDicomLoader.h>

// STL
#include <vector>
#include <map>
#include <set>

#if defined( TRIDIM_USE_GDCM )

#include <data/CDicomGDCM.h>

#else

#include <data/CDicomDCTk.h>

#endif    

//DCTK test
//#include <data/CDicomDCTk.h>

namespace data
{

///////////////////////////////////////////////////////////////////////////////
//! Struct encapsulates DICOM filename
struct SDCMTkFilename
{
public:
	vpl::sys::tString directory;
	std::string filename;
};

#ifdef WIN32 // for Windows file names that need to be in ACP
    std::string wcs2ACP(const std::wstring &wcsStr, bool bDoNotUseShortName = false);
    std::wstring ACP2wcs(const char *filename);
    std::wstring shortName(const std::wstring &filename);
    std::string shortName(const std::string &filename);
#endif

//! Struct encapsulates DICOM filename and pixel spacing (need for data preview)
struct SDCMTkFileNameAndPixelSpacing
{
public:
    SDCMTkFilename fileInfo;
    double pixelSpacing;
};

///////////////////////////////////////////////////////////////////////////////
//! Class encapsulates one serie of dicom files.

class CSerieInfo : public vpl::base::CObject 
{
public:
    //! Smart pointer declaration.
    VPL_SHAREDPTR( CSerieInfo );

    //! List of all dicom files belonging to this serie.
    //typedef std::vector< std::string > tDicomFileList;

    typedef std::vector< SDCMTkFilename > tDCMTkFileList;
	typedef std::vector<vpl::sys::tString> tDicomFileList;

    //! Set of dicom slice numbers.
    typedef std::set< double > tDicomNumSet;

	typedef std::map<double, SDCMTkFileNameAndPixelSpacing> tDicomNumToFileinfo;

public:
    //! Default constructor.
    CSerieInfo();

    //! Destructor.
    virtual ~CSerieInfo();

    //! Sets serie id string.
    void setId( const std::string & id );

    //! Returns serie id string.
    const std::string& getId() const;


    //! Returns number of frames (i.e. slices) in the serie.
    int	getNumOfSlices() const;

    //! Returns true if dicom slice exists within the serie.
    bool hasSlice( int number ) const;

    //! Adds dicom slice to the serie.
    bool addSlice(double id, double pixelSpacing = 0.0);

    //! Sets 8 bit data state
    void setHas8BitData(bool bHasThem) { m_bHas8BitData = bHasThem; }

    //! Returns whether contains image with 8 bit data
    bool has8BitData() const {return m_bHas8BitData; }

    //! Returns number of dicom files in the serie.
    int	getNumOfDicomFiles() const;

    //! Adds dicom slice to the serie.
    bool addDicomFile( const vpl::sys::tString & path );
	bool addDicomFile( const vpl::sys::tString &dir, const vpl::sys::tString &filename );

	//! Returns list of all dicom files in the serie.
    void getDicomFileList( tDicomFileList& Files );

    //! Loads a single frame (i.e. slice) from a specified dicom file. 
    bool loadDicomFile(int FileNum, vpl::img::CDicomSlice& Slice, sExtendedTags& tags, bool bLoadImageData = true);

    //! Loads all frames/slices from a specified dicom file.
    //! - Returns the number of succesfully read slices.
    int loadDicomFile(int FileNum, tDicomSlices& Slices, sExtendedTags& tags, bool bLoadImageData = true, bool bCompatibilityMode = false);

	//! Loads a single frame (i.e. slice) from a specified dicom file. 
	//! Maps fileIndex to sliceId, so the slices in preview should be sorted.
	bool loadDicomFileForPreview(int sliceIndex, vpl::img::CDicomSlice& Slice, sExtendedTags& tags, bool bLoadImageData = true, double pixelSpacing = 0.0);

	void sortFilenamesByNumber();

    //! Sets/ Gets flag whether serie should be loaded using custom load funcion 
    void setLoadBuggySerie(bool b){ m_loadBuggySerie = b; }
    bool getLoadBuggySerie() const { return m_loadBuggySerie; };

    //! Returns number of dicom files in the serie for preview.
    int getNumOfDicomFilesForPreview();

    //! Returns the most common pixel spacing of dicom files in the serie.
    double getTheMostCommonPixelSpacing();

protected:
    //! Set of all dicom files belonging to this serie.
    tDicomFileList m_DicomList;
	tDCMTkFileList m_DCMTkList;

    //! Set of all slice numbers belonging to this serie.
    tDicomNumSet m_DicomNumSet;

    //! Identifier of this dicom serie.
    std::string	m_sId;

    //! Info whether any dicom image was 8 bit (therefore it is not in HU)
    bool m_bHas8BitData;


    //! Flag indicating whether serie should be loaded using custom load funcion, in case
    //! GDCM reader fails
    bool m_loadBuggySerie;

	//! Mapping of slice numbers to filenames.
    tDicomNumToFileinfo m_DicomNumToFilenameMap;

    //! Pixel spacing of slices.
    std::vector<double> m_DicomPixelSpacing;
};

typedef CSerieInfo::tSmartPtr  CSerieInfoPtr;

///////////////////////////////////////////////////////////////////////////////
//! Table of series indexed by a unique serie Id.

class CSeries : public vpl::base::CObject
{
public:
    //! Smart pointer declaration.
    VPL_SHAREDPTR( CSeries );

public:
    //! Default constructor.
    CSeries();

    //! Destructor.
    virtual ~CSeries();

    //! Returns number of series contained.
    int	getNumSeries() const;

    //! Returns pointer to a CSerieInfo instance with specified id,
    //! or NULL if the serie was not found.
    CSerieInfo * getSerie( const std::string & id );

    //! Returns pointer to a CSerieInfo instance with specified number,
    //! or NULL if the serie was not found.
    CSerieInfo * getSerie( int number );

    //! Creates a new serie and returns pointer to it.
    //! - If the serie already exists, the function returns pointer
    //!   to the existing one.
    CSerieInfo * addSerie( const std::string & id );

    //! Adds new dicom file into corresponding serie.
    //! - Returns pointer to an existing or newly created one serie.
    CSerieInfo * addDicomFile( const vpl::sys::tString &path );
    CSerieInfo * addDicomFile( const vpl::sys::tString &dir, const vpl::sys::tString &filename );
    
protected:
    //! Internal list of series.
    typedef std::vector< CSerieInfo::tSmartPtr > tSerieList;

    //! Internal table of series.
    typedef std::map< std::string, CSerieInfo::tSmartPtr > tSerieTable;

    //! All series.
    tSerieList m_Series;

    //! Table of series indexed by unique id
    tSerieTable m_SerieTable;
    
};


} // namespace data

#endif // CSeries_H
