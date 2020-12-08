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

#include <data/CSlice.h>
#include <data/CDensityWindow.h>
#include <data/CRegionColoring.h>
#include <data/CMultiClassRegionColoring.h>
#include <data/CAppSettings.h>
#include <data/CDensityData.h>
#include <data/CColoringFunc.h>
#include <data/CVolumeOfInterestData.h>

#include <VPL/Image/ImageFunctions.h>
#include <VPL/Image/ImageFiltering.h>
#include <VPL/Image/VolumeHistogram.h>

namespace data
{

///////////////////////////////////////////////////////////////////////////////
//

CSlice::CSlice()
    : m_DensityData(INIT_SIZE, INIT_SIZE, 0)
    , m_RegionData(INIT_SIZE, INIT_SIZE, 0)
    , m_multiClassRegionData(INIT_SIZE, INIT_SIZE, 0)
    , m_RGBData(INIT_SIZE, INIT_SIZE, 0)
    , m_spImage(new osg::Image)
    , m_spTexture(new tTexture)
    , m_fTextureWidth(1.0f)
    , m_fTextureHeight(1.0f)
    , m_updateEnabled(true)
{
    init();
}

///////////////////////////////////////////////////////////////////////////////
//

void CSlice::init()
{
    // Initialize the image data
    m_DensityData.resize(INIT_SIZE, INIT_SIZE);
    m_RegionData.resize(INIT_SIZE, INIT_SIZE);
    m_multiClassRegionData.resize(INIT_SIZE, INIT_SIZE);
    m_RGBData.resize(INIT_SIZE, INIT_SIZE);

    m_DensityData.fillEntire(vpl::img::CPixelTraits<vpl::img::tDensityPixel>::getPixelMin());
    m_RegionData.fillEntire(vpl::img::CPixelTraits<vpl::img::tDensityPixel>::getPixelMin());
    m_multiClassRegionData.fillEntire(vpl::img::CPixelTraits<vpl::img::tDensityPixel>::getPixelMin());
    m_RGBData.fillEntire(vpl::img::CPixelTraits<vpl::img::tRGBPixel>::getPixelMin());

    // Protect from being optimized away as static state.
    m_spTexture->setDataVariance(osg::Object::DYNAMIC);
    m_spTexture->setImage(m_spImage.get());
    m_fTextureWidth = 1.0f;
    m_fTextureHeight = 1.0f;

    m_updateEnabled = true;

    // Texture properties
    setupTexture();

    // Generate texture
    updateTexture(true);
}

///////////////////////////////////////////////////////////////////////////////
//

//void CSlice::update(const CChangedEntries& Changes)
//{
//}

///////////////////////////////////////////////////////////////////////////////
//

CSlice::~CSlice()
{ }

void CSlice::disconnectProperties()
{
    CSlicePropertyContainer::tPropertyList propertyList = m_properties.propertyList();
    for (CSlicePropertyContainer::tPropertyList::iterator it = propertyList.begin(); it != propertyList.end(); ++it)
    {
        if (APP_STORAGE.isEntryValid((*it)->propertySourceStorageId()) && m_signalConnections.find((*it)->name()) != m_signalConnections.end())
        {
            APP_STORAGE.getEntrySignal((*it)->propertySourceStorageId()).disconnect(m_signalConnections[(*it)->name()]);
            m_signalConnections.erase((*it)->name());
        }
    }
}

///////////////////////////////////////////////////////////////////////////////
//

void CSlice::setupTexture()
{
    m_spTexture->setFilter(osg::Texture::MIN_FILTER, osg::Texture::LINEAR);
    m_spTexture->setFilter(osg::Texture::MAG_FILTER, osg::Texture::LINEAR);
    m_spTexture->setWrap(osg::Texture::WRAP_S, osg::Texture::CLAMP);
    m_spTexture->setWrap(osg::Texture::WRAP_T, osg::Texture::CLAMP);
    m_spTexture->setUseHardwareMipMapGeneration(false);
    m_spTexture->setMaxAnisotropy(1.0f);
    m_spTexture->setResizeNonPowerOfTwoHint(false); 
}

///////////////////////////////////////////////////////////////////////////////
//

void CSlice::estimateTextureSize(vpl::tSize& Width, vpl::tSize& Height)
{
    CObjectPtr<CAppSettings> spAppSettings( APP_STORAGE.getEntry(Storage::AppSettings::Id) );
    if (spAppSettings->getNPOTTextures())
    {   // align them to multiple of 4
        vpl::tSize newWidth = (Width + 3) & ~3;
        vpl::tSize newHeight = (Height + 3) & ~3;
        m_fTextureWidth = float(Width) / newWidth;
        m_fTextureHeight = float(Height) / newHeight;
        Width = newWidth;
        Height = newHeight;
    }
    else // create square textures with the size of power of two
    {
        // Greater value
        vpl::tSize Max = vpl::math::getMax(Width, Height);

        // Texture dimensions
    //    vpl::tSize TexSize = 128;
        vpl::tSize TexSize = 16;
        while( TexSize < Max )
        {
            TexSize <<= 1;
        }

        // Used texture size
        float fInvTexSize = 1.0f / float(TexSize);
        m_fTextureWidth = fInvTexSize * float(Width);
        m_fTextureHeight = fInvTexSize * float(Height);

        // Modify the image dimension
        Width = Height = TexSize;
    }
}

///////////////////////////////////////////////////////////////////////////////
//

//! Applies current selected filter on m_DensityData and returns backup of original data
vpl::img::CDImage* CSlice::applyFilterAndGetBackup(bool bEqualizeSlice, int rmin, int rmax)
{
    CObjectPtr<CAppSettings> spAppSettings( APP_STORAGE.getEntry(Storage::AppSettings::Id) );
    CAppSettings::ETextureFilter filter=spAppSettings->getFilter();
    if (filter==CAppSettings::Blur)
    {
        vpl::img::CDImage *pDataWithMargin = new vpl::img::CDImage(m_DensityData.getSize(),5);
        *pDataWithMargin = m_DensityData;
        pDataWithMargin->mirrorMargin();
        vpl::img::CGaussFilter<vpl::img::CDImage> Filter((vpl::tSize)5);
        Filter(*pDataWithMargin,m_DensityData);
        return pDataWithMargin;
    }
    if (filter==CAppSettings::Sharpen)
    {
        vpl::img::CDImage *pDataWithMargin = new vpl::img::CDImage(m_DensityData.getSize(),5);
        *pDataWithMargin = m_DensityData;
        pDataWithMargin->mirrorMargin();
        // blur
        vpl::img::CDImage tmp(m_DensityData);
        vpl::img::CGaussFilter<vpl::img::CDImage> Filter((vpl::tSize)5);
        Filter(*pDataWithMargin,tmp);
        // perform unsharp mask
        m_DensityData-=tmp;
        m_DensityData*=vpl::CScalari(3);
        m_DensityData+=*pDataWithMargin;
        return pDataWithMargin;
    }
    if (filter==CAppSettings::SmoothSharpen)
    {
        vpl::img::CDImage *pDataWithMargin = new vpl::img::CDImage(m_DensityData.getSize(),5);
        *pDataWithMargin = m_DensityData;
        pDataWithMargin->mirrorMargin();
        // blur
        vpl::img::CDImage tmp(m_DensityData.getSize(),5);
        tmp=m_DensityData;
        vpl::img::CGaussFilter<vpl::img::CDImage> Filter((vpl::tSize)5);
        Filter(*pDataWithMargin,m_DensityData);
        // perform unsharp mask
        tmp-=m_DensityData;
        tmp*=vpl::CScalari(4);
        tmp+=*pDataWithMargin;
        // blur the result
        tmp.mirrorMargin();
        Filter(tmp,m_DensityData);
        return pDataWithMargin;
    }
	if (filter==CAppSettings::Equalize)
	{
		if (bEqualizeSlice)
		{
			data::CObjectPtr<data::CDensityData> spVolume( APP_STORAGE.getEntry(data::Storage::PatientData::Id) );
			const vpl::img::tDensityPixel VOXEL_MIN = vpl::img::CPixelTraits<vpl::img::tDensityPixel>::getPixelMin();
			const vpl::img::tDensityPixel VOXEL_MAX = vpl::img::CPixelTraits<vpl::img::tDensityPixel>::getPixelMax();
			vpl::img::CDImageHistogram histogram(VOXEL_MIN, VOXEL_MAX);
			//vpl::img::CDVolumeHistogram histogram(VOXEL_MIN, VOXEL_MAX);
			if (histogram(m_DensityData))
			{
				// Compute the cumulative histogram
				histogram.cumulate();
				// Get the number of samples
				vpl::img::CDVolumeHistogram::tBin Max = histogram.getCount(histogram.getSize() - 1);
				if( Max > 0 )
				{
					vpl::img::CDImage *pDataWithMargin = new vpl::img::CDImage(m_DensityData.getSize(),5);
					*pDataWithMargin = m_DensityData;
					pDataWithMargin->mirrorMargin();

					int dwmin = rmin;
					int dwmax = rmax;

					// Histogram equalization
					int countZero = 0;
					{	// we don't care about differences in values below some value, make them all zero
						vpl::tSize Index = histogram.getIndex(rmin);
						countZero = histogram.getCount(Index);
					}

					double dNorm = double(dwmax - dwmin) / double(Max - countZero);
#pragma omp parallel for
					for( vpl::tSize j = 0; j < m_DensityData.getYSize(); ++j )
					{
						for( vpl::tSize i = 0; i < m_DensityData.getXSize(); ++i )
						{
							vpl::tSize Index = histogram.getIndex(m_DensityData(i, j));
							m_DensityData(i, j) = (dNorm * std::max(0,histogram.getCount(Index)-countZero) + dwmin);
						}
					}
					return pDataWithMargin;
				}			
			}

		}
		else
		{
			// TODO: compute the histogram once and cache it somewhere
			data::CObjectPtr<data::CDensityData> spVolume( APP_STORAGE.getEntry(data::Storage::PatientData::Id) );
			const vpl::img::tDensityPixel VOXEL_MIN = vpl::img::CPixelTraits<vpl::img::tDensityPixel>::getPixelMin();
			const vpl::img::tDensityPixel VOXEL_MAX = vpl::img::CPixelTraits<vpl::img::tDensityPixel>::getPixelMax();
			vpl::img::CDVolumeHistogram histogram(VOXEL_MIN, VOXEL_MAX);
			if (histogram(*spVolume.get()))
			{
				// Compute the cumulative histogram
				histogram.cumulate();
				// Get the number of samples
				vpl::img::CDVolumeHistogram::tBin Max = histogram.getCount(histogram.getSize() - 1);
				if( Max > 0 )
				{
					vpl::img::CDImage *pDataWithMargin = new vpl::img::CDImage(m_DensityData.getSize(),5);
					*pDataWithMargin = m_DensityData;
					pDataWithMargin->mirrorMargin();

					data::CObjectPtr<data::CDensityWindow> spWindow(APP_STORAGE.getEntry(data::Storage::DensityWindow::Id)); // for coloring info
					int dwmin = spWindow->getMin();
					int dwmax = spWindow->getMax();

					// Histogram equalization
					int countZero = 0;
					{	// we don't care about differences in values below -500, make them all zero
						vpl::tSize Index = histogram.getIndex(-500);
						countZero = histogram.getCount(Index);
					}

					double dNorm = double(dwmax - dwmin) / double(Max - countZero); //double dNorm = double(VOXEL_MAX - VOXEL_MIN) / double(Max);
	#pragma omp parallel for
					for( vpl::tSize j = 0; j < m_DensityData.getYSize(); ++j )
					{
						for( vpl::tSize i = 0; i < m_DensityData.getXSize(); ++i )
						{
							vpl::tSize Index = histogram.getIndex(m_DensityData(i, j));
							m_DensityData(i, j) = (dNorm * std::max(0,histogram.getCount(Index)-countZero) + dwmin);
						}
					}
					return pDataWithMargin;
				}			
			}
		}
	}
    return NULL;
}

//! Restores m_DensityData and deletes backup
void CSlice::restoreFromBackupAndFree(vpl::img::CDImage* pBackup)
{
    if (NULL!=pBackup)
    {
        m_DensityData = *pBackup;
        delete pBackup;
    }
}

///////////////////////////////////////////////////////////////////////////////
//
void CSlice::onPropertySourceChanged(data::CStorageEntry *entry)
{
    data::CChangedEntries changes;
    entry->getChanges(changes);
    //update(changes); //if anything doesn't work, ask Martin

	std::map<int,int> invalidateIds;
    CSlicePropertyContainer::tPropertyList propertyList = m_properties.propertyList();
    for (CSlicePropertyContainer::tPropertyList::iterator it = propertyList.begin(); it != propertyList.end(); ++it)
    {
        if (changes.hasChanged((*it)->propertySourceStorageId()))
        {            			
			invalidateIds[(*it)->sliceStorageId()] += (*it)->sliceInvalidationFlags(); 
        }
    }
    for (std::map<int,int>::iterator it = invalidateIds.begin(); it != invalidateIds.end(); ++it)
    {
		data::CPtrWrapper<data::CStorageEntry> spEntry(APP_STORAGE.getEntry(it->first));
		APP_STORAGE.invalidate(spEntry.get(), it->second);
    }
}

///////////////////////////////////////////////////////////////////////////////
//

bool CSlice::updateRGBData(bool bSizeChanged, int densityWindowId )
{
    // Has the size changed?
    if( bSizeChanged || m_DensityData.getXSize() != m_RGBData.getXSize() || m_DensityData.getYSize() != m_RGBData.getYSize() )
    {
        // Estimate optimal texture size
        vpl::tSize Width = m_DensityData.getXSize();
        vpl::tSize Height = m_DensityData.getYSize();
        estimateTextureSize(Width, Height);

        // Resize the RGB image
        m_RGBData.resize(Width, Height, 0);
        m_RGBData.fillEntire(vpl::img::CPixelTraits<vpl::img::tRGBPixel>::getPixelMin());
        bSizeChanged = true;
    }

    // Get the density window
    CObjectPtr<CDensityWindow> spDensityWindow( APP_STORAGE.getEntry(densityWindowId) );

    vpl::img::CDImage *pBackup = applyFilterAndGetBackup(false, 0, 0);

    // Is region coloring enabled?
    if( (m_DensityData.getXSize() != m_RegionData.getXSize() || m_DensityData.getYSize() != m_RegionData.getYSize()) && (m_DensityData.getXSize() != m_multiClassRegionData.getXSize() || m_DensityData.getYSize() != m_multiClassRegionData.getYSize()) )
    {
        spDensityWindow->colorize(m_RGBData, m_DensityData, m_properties, NULL != pBackup ? *pBackup : m_DensityData);
    }
    else
    {
        spDensityWindow->colorize(m_RGBData, m_DensityData, m_properties, NULL != pBackup ? *pBackup : m_DensityData);

        if (!spDensityWindow->getColoring()->overrideRegionColoring())
		{
            CObjectPtr<CMultiClassRegionData> spMultiClassRegionData(APP_STORAGE.getEntry(Storage::MultiClassRegionData::Id));
            if (spMultiClassRegionData->hasData())
            {
                CObjectPtr<CMultiClassRegionColoring> spMultiClassColoring(APP_STORAGE.getEntry(Storage::MultiClassRegionColoring::Id));
                spMultiClassColoring->colorize(m_RGBData, m_multiClassRegionData);
            }
            else
            {
                CObjectPtr<CRegionColoring> spColoring(APP_STORAGE.getEntry(Storage::RegionColoring::Id));
                spColoring->colorize(m_RGBData, m_RegionData);
            }
		}
    }

    // TODO: JS - VOI is set even if it shouldn't be and the arbitrary slice is colorized according to it
	/*CObjectPtr<CVolumeOfInterestData> spVOI(APP_STORAGE.getEntry(Storage::VolumeOfInterestData::Id));

	if (spVOI->isSet())
	{
#pragma omp parallel for
		for (int y = 0; y < m_RGBData.getYSize(); ++y)
		{
			for (int x = 0; x < m_RGBData.getXSize(); ++x)
			{
				if (x < m_minX || x > m_maxX || y < m_minY || y > m_maxY)
				{
					vpl::img::CRGBPixel pixel = m_RGBData(x, y);
					data::CColor4b prevColor = *(reinterpret_cast<data::CColor4b *>(&pixel));
					data::CColor4b currColor(255, 255, 0, 20);
					data::CColor4b newColor = blendColors(currColor, prevColor);
					m_RGBData(x, y) = *(reinterpret_cast<vpl::img::tRGBPixel *>(&newColor));
				}
			}
		}
	}*/
	
    restoreFromBackupAndFree(pBackup);

    return bSizeChanged;
}


///////////////////////////////////////////////////////////////////////////////
//

bool CSlice::updateRGBData2(bool bSizeChanged)
{
    // Size changed?
    if( bSizeChanged || m_DensityData.getXSize() != m_RGBData.getXSize() || m_DensityData.getYSize() != m_RGBData.getYSize() )
    {
        // Estimate optimal texture size
        vpl::tSize Width = m_DensityData.getXSize();
        vpl::tSize Height = m_DensityData.getYSize();
        estimateTextureSize(Width, Height);

        // Resize the RGB image
        m_RGBData.resize(Width, Height, 0);
        m_RGBData.fillEntire(vpl::img::CPixelTraits<vpl::img::tRGBPixel>::getPixelMin());
        bSizeChanged = true;
    }

    // Linear contrast enhancement
    vpl::img::tDensityPixel Min = 0;
    vpl::img::tDensityPixel Max = 32767;

    if(2==sizeof(vpl::img::tDensityPixel))
    {
        // compute histogram of all pixels that contain some data
        bool valid = false;
        int iCount = 0;
        int histogram[65536]={};
        vpl::img::tDensityPixel v0 = vpl::img::CPixelTraits<vpl::img::tDensityPixel>::getPixelMin();
        for( vpl::tSize j = 0; j < m_DensityData.getYSize(); ++j )
        {
            for( vpl::tSize i = 0; i < m_DensityData.getXSize(); ++i )
            {
                vpl::img::tDensityPixel Value = m_DensityData(i, j);

                // ignore useless values
                if (Value == vpl::img::CPixelTraits<vpl::img::tDensityPixel>::getPixelMin())
                {
                    continue;
                }

                // set reference value for validity consideration
                if (v0 == vpl::img::CPixelTraits<vpl::img::tDensityPixel>::getPixelMin())
                {
                    v0 = Value;
                }

                // check for validity of histogram
                if (Value != v0)
                {
                    valid = true;
                }

                histogram[(int)Value+32768]++; // because tDensityPixel is signed int
                ++iCount;
            }
        }
        // if any valid, find black and white point so tjat
        if (valid)
        {
            int nMin = 32768-1500;
            int nMax = 65535;
            int threshold = 0.02 * iCount; // 2% are clipped
            int sMin = histogram[nMin];
            while(sMin<threshold)
            {
                nMin++;
                sMin+=histogram[nMin];
            }

            int sMax = histogram[65535];
            while(sMax<threshold && nMax>Min)
            {
                nMax--;
                sMax+=histogram[nMax];
            }
            Min=nMin-32768;
            Max=nMax-32768;
        }
    }
    else
    {
        // original method which computes mean and squared variance
        int iCount = 0;
        double dSum = 0.0, dSumSqr = 0.0;
        for( vpl::tSize j = 0; j < m_DensityData.getYSize(); ++j )
        {
            for( vpl::tSize i = 0; i < m_DensityData.getXSize(); ++i )
            {
                vpl::img::tDensityPixel Value = m_DensityData(i, j);
                if( Value != m_DensityData(0, 0) )
                {
                    dSum += Value;
                    dSumSqr += double(Value) * Value;
                    ++iCount;
                }
            }
        }
        double dMean = 0.0, dVar = 0.0;
        if( iCount > 0 )
        {
            double dInvCount = 1.0 / iCount;
            dMean = dSum * dInvCount;
            dVar =  dSumSqr * dInvCount - (dMean * dMean);
        }
        double dWidth = 1.5 * std::sqrt(dVar) + 0.001;

        Min = vpl::img::tDensityPixel(dMean - dWidth);
        Max = vpl::img::tDensityPixel(dMean + dWidth);
    }

    // Normalization
    double dNorm = 255.0 / ((Max-Min) + 0.001);

    vpl::img::CDImage *pBackup = applyFilterAndGetBackup(true,Min,Max);

    // Prepare the RGB data
    for( vpl::tSize j = 0; j < m_DensityData.getYSize(); ++j )
    {
        for( vpl::tSize i = 0; i < m_DensityData.getXSize(); ++i )
        {
            vpl::img::tDensityPixel Value = m_DensityData(i,j);
            if( Value <= Min )
            {
                m_RGBData(i,j) = vpl::img::tRGBPixel(0, 0, 0);
            }
            else if( Value >= Max )
            {
                m_RGBData(i,j) = vpl::img::tRGBPixel(255, 255, 255);
            }
            else
            {
                vpl::img::tPixel8 NewValue = vpl::img::tPixel8(dNorm * (Value - Min));
                m_RGBData(i,j) = vpl::img::tRGBPixel(NewValue, NewValue, NewValue);
            }
        }
    }

    restoreFromBackupAndFree(pBackup);

    return bSizeChanged;
}

///////////////////////////////////////////////////////////////////////////////
//

void CSlice::updateTexture(bool bRecreateImage)
{
    // Check the data
    if( !bRecreateImage )
    {
        // Force osg::Texture to reload the image
        m_spImage->dirty();
        return;
    }
    
    // Change the data
    m_spImage->setImage(m_RGBData.getXSize(),
                        m_RGBData.getYSize(),
                        1,
                        4,
                        GL_RGBA,
                        GL_UNSIGNED_BYTE, 
                        (unsigned char *)m_RGBData.getPtr(0, 0),
                        osg::Image::NO_DELETE
                        );

    // Force osg::Texture to reload the image
    m_spImage->dirty();

    // Setup texture parameters
//    setupTexture();
    m_spTexture->dirtyTextureObject();
    m_spTexture->dirtyTextureParameters();
}

/**
 * \brief   Returns density value if inside, or -1000 if outside
 *
 * \return  The density.
 */
double CSlice::getDensity(int x, int y) const
{
    if(x < 0 || y < 0 || x >= m_DensityData.width() || y >= m_DensityData.height())
        return -1000.0;

    return m_DensityData.at(x, y);
}

void CSlice::setUpdatesEnabled(bool enabled)
{
    m_updateEnabled = enabled;
}

} // namespace data

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

