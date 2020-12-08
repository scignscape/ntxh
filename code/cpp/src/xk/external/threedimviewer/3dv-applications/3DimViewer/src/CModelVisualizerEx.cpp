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

#include "CModelVisualizerEx.h"

#include <osg/CPseudoMaterial.h>
#include <osg/PolygonMode>


void osg::CModelVisualizerEx::setModelVisualization(EModelVisualization modelVisualization)
{
    m_modelVisualization = modelVisualization;
    osg::Geode *pMesh = m_pMesh->getMeshGeode();
    if (NULL == pMesh)
    {
        return;
    }

    osg::StateSet * stateSet = pMesh->getOrCreateStateSet();
    osg::PolygonMode *polyModeObj = dynamic_cast<osg::PolygonMode *>(stateSet->getAttribute(osg::StateAttribute::POLYGONMODE));
    if (!polyModeObj)
    {
        polyModeObj = new osg::PolygonMode;
        stateSet->setAttribute(polyModeObj);
    }
    stateSet->setAttributeAndModes(polyModeObj, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE | osg::StateAttribute::PROTECTED);
    switch (m_modelVisualization)
    {
    case EMV_SMOOTH:
    {
        m_pMesh->useNormals(osg::CTriMesh::ENU_VERTEX);
        m_materialRegular->setFlatShading(false);
        m_materialSelected->setFlatShading(false);
        polyModeObj->setMode(osg::PolygonMode::FRONT_AND_BACK, osg::PolygonMode::FILL);
    }
    break;

    case EMV_FLAT:
    {
        m_pMesh->useNormals(osg::CTriMesh::ENU_VERTEX);
        m_materialRegular->setFlatShading(true);
        m_materialSelected->setFlatShading(true);
        polyModeObj->setMode(osg::PolygonMode::FRONT_AND_BACK, osg::PolygonMode::FILL);
    }
    break;

    case EMV_WIRE:
    {
        m_pMesh->useNormals(osg::CTriMesh::ENU_VERTEX);
        m_materialRegular->setFlatShading(false);
        m_materialSelected->setFlatShading(false);
        polyModeObj->setMode(osg::PolygonMode::FRONT_AND_BACK, osg::PolygonMode::LINE);
    }
    break;
    }

    m_pMesh->applyMaterials();
}
