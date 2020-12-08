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

#ifndef CVolumeRenderer_H
#define CVolumeRenderer_H

#include <coremedi/app/Signals.h>
#include <VPL/Image/DensityVolume.h>
#include <render/CLookupTable.h>

#include <functional>


#include <QSize> 

///////////////////////////////////////////////////////////////////////////////
//! Interface for volume renderer usable by plugins
//! - Plugins may want to use some custom volume and custom shader for
//!   visualization. This interface puts necessary requirements on renderer
//!   so that it can handle plugins' needs (this may not necessary mean, that
//!   renderer is capable doing all these things, but it is possible that it
//!   can - check renderer itself)
//! - Plugin can create custom volume and custom shader. Renderer can
//!   internally handle this in whatever way it needs but it has to return
//!   unique ID of volume/shader
//! - Because of memory limitations of hardware, there is only one volume
//!   stored in GPU at a single point of time. There is mechanism for switching
//!   custom volumes of different plugins:
//!   - plugin creates custom volume and shader
//!   - when some plugin need to store and use custom volume, owner of previous
//!     custom volume is notified (if it is registered to being notified) and
//!     it can grab current data from renderer
//!   - current custom volume is updated with data provided by plugin
//!   - current custom volume is rendered using current custom shader
//!   - plugin deletes custom volume and shader
//!   - plugin can register various callbacks if needed (called when renderer
//!     is destroyed, volume is replaced by data of another plugin, shader's
//!     data need to be updated)
class CVolumeRenderer
{
protected:
    //! possible types of custom volume
    enum EVolumeType
    {
        EVT_NONE = 0,
        EVT_BOOL,
        EVT_PIXEL8,
        EVT_PIXEL16,
        EVT_RGBPIXEL
    };

protected:
    //! connection of signal for returning pointer to renderer with necessary capabilities
    vpl::mod::tSignalConnection m_conGetRenderer;

    //! callback called when custom shader's data should be updated
    std::function<void()> m_shaderUpdateCallback;

protected:
    //! type of current custom volume
    EVolumeType m_currentType;

    //! containers for current custom volume
    vpl::img::CVolume<bool> m_volume_bool;
    vpl::img::CVolume<vpl::img::tPixel16> m_volume_tPixel16;
    vpl::img::CVolume<vpl::img::tPixel8> m_volume_tPixel8;
    vpl::img::CVolume<vpl::img::tRGBPixel> m_volume_tRGBPixel;
    vpl::img::CVolume<vpl::img::tPixel8> m_auxVolume;

    //! list of lookup tables
    std::map<std::string, CLookupTable> m_lookupTables;

public:
    //! Ctor
    CVolumeRenderer(): m_currentType(EVT_NONE)
    {
        m_conGetRenderer = VPL_SIGNAL(SigGetRenderer).connect(this, &CVolumeRenderer::getRenderer);
    }

    //! Dtor
    virtual ~CVolumeRenderer()
    {
        VPL_SIGNAL(SigGetRenderer).disconnect(m_conGetRenderer);
    }

    //! returns pointer to itself (called by signal invokation)
    CVolumeRenderer *getRenderer()
    {
        return this;
    }

private:
    //! notifies previous owner that it should grab current data from renderer
    void clearPreviousVolumeData(EVolumeType newVolumeType)
    {
        // clear current if new type is different
        if (newVolumeType != m_currentType)
        {
            switch (m_currentType)
            {
            case EVT_BOOL:
                m_volume_bool.resize(0, 0, 0);
                break;

            case EVT_PIXEL8:
                m_volume_tPixel8.resize(0, 0, 0);
                break;

            case EVT_PIXEL16:
                m_volume_tPixel16.resize(0, 0, 0);
                break;

            case EVT_RGBPIXEL:
                m_volume_tRGBPixel.resize(0, 0, 0);
                break;

            case EVT_NONE:
            default:
                break;
            }

            m_auxVolume.resize(0, 0, 0);
        }
    }

public:

    template<class T>
    static constexpr EVolumeType getVolumeType()
    {
        return EVT_NONE;
    }

    template<class T>
    vpl::img::CVolume<T>& getCustomVolumeData()
    {
        return vpl::img::CVolume<T>();
    }

    template<class T>
    void setDataToCustomVolume(vpl::img::CVolume<T>& volume, vpl::img::CVolume<vpl::img::tPixel8>& auxVolume)
    {
        clearPreviousVolumeData(getVolumeType<T>());

        m_currentType = getVolumeType<T>();

        getCustomVolumeData<T>().copy(volume);
        m_auxVolume.copy(auxVolume);

        internalSetDataToCustomVolume();
    }

    void createCustomShader(std::string vertexShaderSource, std::string fragmentShaderSource, std::function<void()> shaderUpdateCallback)
    {
        internalCreateCustomShader(vertexShaderSource, fragmentShaderSource);

        m_shaderUpdateCallback = shaderUpdateCallback;
    }


    //! returns list of lookup tables
    std::map<std::string, CLookupTable> &getLookupTables()
    {
        return m_lookupTables;
    }

protected:
    //! executes appropriate callback when data of active custom shader should be updated
    void shaderUpdateCallback()
    {
        if (m_shaderUpdateCallback)
        {
            m_shaderUpdateCallback();
        }
    }

public:
    //! initializes VR if it is possible
    virtual bool init() = 0;
    //! returns flag if VR is enabled
    virtual bool isEnabled() const = 0;
    //! enables/disables VR
    virtual void enable(bool bEnable = true) = 0;
    //! disables VR
    void disable() { enable(false); }

    //! forces renderer to redraw itself
    virtual void redraw(bool bEraseBackground = false) = 0;
    //! returns current size of renderer's window
    virtual QSize getWindowSize() = 0;

    //! returns world matrix of volume
    virtual osg::Matrix getWorldMatrix() = 0;
    //! returns view matrix used for rendering volume
    virtual osg::Matrix getViewMatrix() = 0;
    //! returns projection matrix used for rendering volume
    virtual osg::Matrix getProjectionMatrix() = 0;
    //! returns world-to-screen matrix (world * view * projection)
    virtual osg::Matrix getTransformMatrix() = 0;

    //! resets lookup tables
    virtual void resetLookupTables() = 0;
    //! updates internal representation of LUTs
    virtual void updateLookupTables(std::string lutName = "") = 0;

protected:
    //! internal method for creating custom volume, should return unique ID as it is used later
    virtual void internalSetDataToCustomVolume() = 0;

    //! internal method for creating custom shader, should return unique ID as it is used later
    virtual void internalCreateCustomShader(std::string vertexShaderSource, std::string fragmentShaderSource) = 0;
};

template<>
inline constexpr CVolumeRenderer::EVolumeType CVolumeRenderer::getVolumeType<bool>()
{
    return EVT_BOOL;
}

template<>
inline  constexpr CVolumeRenderer::EVolumeType CVolumeRenderer::getVolumeType<vpl::img::tPixel8>()
{
    return EVT_PIXEL8;
}

template<>
inline constexpr CVolumeRenderer::EVolumeType CVolumeRenderer::getVolumeType<vpl::img::tPixel16>()
{
    return EVT_PIXEL16;
}

template<>
inline constexpr CVolumeRenderer::EVolumeType CVolumeRenderer::getVolumeType<vpl::img::tRGBPixel>()
{
    return EVT_RGBPIXEL;
}

template<>
inline vpl::img::CVolume<bool>& CVolumeRenderer::getCustomVolumeData<bool>()
{
    return m_volume_bool;
}

template<>
inline vpl::img::CVolume<vpl::img::tPixel8>& CVolumeRenderer::getCustomVolumeData<vpl::img::tPixel8>()
{
    return m_volume_tPixel8;
}

template<>
inline vpl::img::CVolume<vpl::img::tPixel16>& CVolumeRenderer::getCustomVolumeData<vpl::img::tPixel16>()
{
    return m_volume_tPixel16;
}

template<>
inline vpl::img::CVolume<vpl::img::tRGBPixel>& CVolumeRenderer::getCustomVolumeData<vpl::img::tRGBPixel>()
{
    return m_volume_tRGBPixel;
}


#endif // CVolumeRenderer_H
