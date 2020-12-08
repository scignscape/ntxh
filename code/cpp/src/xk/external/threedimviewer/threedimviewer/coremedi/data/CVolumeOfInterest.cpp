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

#include <data/CVolumeOfInterest.h>
#include <data/CSlice.h>
#include <data/CDensityData.h>
#include <VPL/Base/Logging.h>


namespace data
{

///////////////////////////////////////////////////////////////////////////////

void CVolumeOfInterest::update(const CChangedEntries& Changes)
{
//    if( !Changes.isParentValid() )
//    {
//        return;
//    }

	typedef CObjectHolder<CDensityData> tObjectHolder;
	int id = APP_STORAGE.findEntryId<tObjectHolder>(Changes);
	if (id != Storage::UNKNOWN)
	{
		CObjectPtr<CDensityData> spVolume( APP_STORAGE.getEntry(id) /* APP_STORAGE.findObject<CDensityData>(Changes) */ );
		m_Limits.m_MinX = m_Limits.m_MinY = m_Limits.m_MinZ = 0;
		m_Limits.m_MaxX = spVolume->getXSize() - 1;
		m_Limits.m_MaxY = spVolume->getYSize() - 1;
		m_Limits.m_MaxZ = spVolume->getZSize() - 1;
	}
}


///////////////////////////////////////////////////////////////////////////////

void CVolumeOfInterest::init()
{
    m_Limits.m_MinX = m_Limits.m_MinY = m_Limits.m_MinZ = 0;
    m_Limits.m_MaxX = CSlice::INIT_SIZE;
    m_Limits.m_MaxY = CSlice::INIT_SIZE;
    m_Limits.m_MaxZ = CSlice::INIT_SIZE;
}


} // namespace data
