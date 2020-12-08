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

///////////////////////////////////////////////////////////////////////////////
// include files

#include <data/CRegionData.h>
#include <data/CDensityData.h>

#ifdef _OPENMP
#    include <omp.h>
#endif


namespace data
{

///////////////////////////////////////////////////////////////////////////////
//

CRegionData::CRegionData()
    : vpl::img::CVolume16(1, 1, 1, DEFAULT_MARGIN )
    , m_bColoringEnabled(false)
    , m_bMakeDummy(false)
    , m_volumeUndo(NULL, data::Storage::RegionData::Id, true)
{
	m_volumeUndo.setVolumePtr( this );
}


///////////////////////////////////////////////////////////////////////////////
//
CRegionData::CRegionData(const CRegionData& Data)
    : vpl::img::CVolume16(Data)
    , m_bColoringEnabled(Data.m_bColoringEnabled)
    , m_bMakeDummy(Data.m_bMakeDummy)
{
	m_volumeUndo.setVolumePtr( this );
}


///////////////////////////////////////////////////////////////////////////////
//

CRegionData& CRegionData::enableColoring(bool bEnabled)
{
    m_bColoringEnabled = bEnabled;
    return *this;
}

CRegionData& CRegionData::makeDummy(bool dummy)
{
    m_bMakeDummy = dummy;
    return *this;
}


///////////////////////////////////////////////////////////////////////////////
//

CRegionData::~CRegionData()
{
}


////////////////////////////////////////////////////////////
//

bool CRegionData::checkDependency(CStorageEntry *pParent)
{
    return true;
}


////////////////////////////////////////////////////////////
//

void CRegionData::update(const CChangedEntries& Changes)
{
    if (Changes.checkFlagAny(data::Storage::STORAGE_RESET))
    {
        init();
    }
    else
    {
        // Get the patient data
        CObjectPtr<CDensityData> spData(APP_STORAGE.getEntry(Storage::PatientData::Id));

        // Re-initializes the data if density volume has changed its proportions.
        vpl::tSize XSize = spData->getXSize();
        vpl::tSize YSize = spData->getYSize();
        vpl::tSize ZSize = spData->getZSize();
        if (getXSize() != XSize || getYSize() != YSize || getZSize() != ZSize)
        {
            unsigned long rx = XSize;
            unsigned long ry = YSize;
            unsigned long rz = ZSize;
            unsigned long dx = spData->getXSize();
            unsigned long dy = spData->getYSize();
            unsigned long dz = spData->getZSize();

            if (rx * ry * rz < dx * dy * dz)
            {
                // Enforce data deallocation
                resize(0, 0, 0, 0);
            }

            resize(XSize, YSize, ZSize, vpl::math::getMax< vpl::tSize >(spData->getMargin(), DEFAULT_MARGIN));
            fillEntire(0);
        }
    }
}


////////////////////////////////////////////////////////////
//

void CRegionData::init()
{
    // Enforce data deallocation
    resize(0, 0, 0, 0);

    enableDummyMode(m_bMakeDummy);

    resize(INIT_SIZE, INIT_SIZE, INIT_SIZE, DEFAULT_MARGIN );

    fillEntire(0);

    m_bColoringEnabled = false;
}


///////////////////////////////////////////////////////////////////////////////
//

bool CRegionData::hasData()
{
    return (getXSize() > 1);
}


///////////////////////////////////////////////////////////////////////////////
//

//void CregionData::()
//{
//
//}


} // namespace data

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
