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

#include <data/CVolumeOfInterestData.h>
#include <data/CDensityData.h>

#ifdef _OPENMP
#    include <omp.h>
#endif


namespace data
{

////////////////////////////////////////////////////////////
//

bool CVolumeOfInterestData::checkDependency(CStorageEntry *pParent)
{
	return true;
}


////////////////////////////////////////////////////////////
//

void CVolumeOfInterestData::update(const CChangedEntries& Changes)
{
	//init();
}

////////////////////////////////////////////////////////////
//

void CVolumeOfInterestData::init()
{
	CObjectPtr< CDensityData> spVolume(APP_STORAGE.getEntry(Storage::PatientData::Id));

	m_minX = 0;
	m_maxX = spVolume->getXSize() - 1;
	m_minY = 0;
	m_maxY = spVolume->getYSize() - 1;
	m_minZ = 0;
	m_maxZ = spVolume->getZSize() - 1;

	m_isVOISet = false;
}

///////////////////////////////////////////////////////////////////////////////
//

bool CVolumeOfInterestData::hasData()
{
	return true;
}

void CVolumeOfInterestData::setLimits(vpl::tSize minX, vpl::tSize minY, vpl::tSize minZ, vpl::tSize maxX, vpl::tSize maxY, vpl::tSize maxZ)
{
	m_minX = minX;
	m_maxX = maxX;
	m_minY = minY;
	m_maxY = maxY;
	m_minZ = minZ;
	m_maxZ = maxZ;

	m_isVOISet = true;
}

bool CVolumeOfInterestData::isInside(vpl::tSize x, vpl::tSize y, vpl::tSize z)
{
	return(x >= m_minX && x <= m_maxX && y >= m_minY && y <= m_maxY && z >= m_minZ && z <= m_maxZ);
}

} // namespace data
