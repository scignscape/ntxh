///////////////////////////////////////////////////////////////////////////////
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

#include <data/CRegionsVisualizer.h>
#include <osg/Version>

namespace osg
{

///////////////////////////////////////////////////////////////////////////////
//
CRegionsVisualizer::CRegionsVisualizer(osg::Matrix matrix, OSGCanvas *canvas, bool autoPositioning)
{
	m_matrix = matrix;
	m_canvas = canvas;
    m_autoPositioning = autoPositioning;
    m_validData = false;

    m_geode = new osg::Geode;
    m_geometry = new osg::Geometry;
    m_vertices = new osg::Vec3Array;
    m_indices = new osg::DrawElementsUInt(osg::PrimitiveSet::LINES);
    
    osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;
    colors->push_back(osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f));

	m_geometry->setColorArray(colors, osg::Array::BIND_OVERALL);
    m_geometry->setVertexArray(m_vertices);
    m_geometry->addPrimitiveSet(m_indices);

    m_geode->addDrawable(m_geometry);

    // Disable depth testing so geometry is draw regardless of depth values
    // of geometry already drawn.
    m_geode->getOrCreateStateSet()->setMode(GL_DEPTH_TEST,osg::StateAttribute::OFF);
    m_geode->getOrCreateStateSet()->setRenderingHint( osg::StateSet::TRANSPARENT_BIN );

    // correction transform
    m_transform = new osg::MatrixTransform;
    addChild(m_transform.get());

    setVisibility(true);
}

//
CRegionsVisualizer::~CRegionsVisualizer()
{ }

//
void CRegionsVisualizer::setVisibility(bool show, bool forceRedraw)
{
    m_visible = show;
    m_transform->removeChild(m_geode);
    
    if (show)
    {
        if (!m_validData)
        {
            updateData();
        }

        if ((m_vertices->size() == 0) || (m_indices->size() == 0))
        {
            return;
        }

        m_transform->addChild(m_geode);
    }

    if (forceRedraw)
    {
        m_canvas->Refresh();
    }
}

//
void CRegionsVisualizer::updateData()
{ }

//
bool CRegionsVisualizer::isVisible()
{
    return m_visible;
}

void CRegionsVisualizer::setColor(const osg::Vec4 & color)
{
    osg::Vec4Array * ca = dynamic_cast< osg::Vec4Array *>(m_geometry->getColorArray());
    if( ca == 0 )
        return;

    // Set line color
    osg::Vec4 *c = &ca->operator[](0);
    *c = color;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace osg
