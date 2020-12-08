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

#ifndef CConvertToGeometry_H
#define CConvertToGeometry_H

#include <osg/Texture2D>
#include <VPL/Image/Image.h>

namespace geometry
{
    class CMesh;
}

#define BUFFER_INDEX_PROPERTY "bufferIndex"

namespace osg
{
    class Geometry;
    class Texture2D;

    struct MeshConversionParams
    {
        MeshConversionParams() {}

        static MeshConversionParams FlatShading();
        static MeshConversionParams SimpleWhite();
        static MeshConversionParams JustVertices();
        static MeshConversionParams WithoutColor();
        static MeshConversionParams WithTexture();

        // DrawElements vs DrawArrays
        bool sharedVertices = true;
        // Add normals, either vertex normal or face normals depending on "sharedVertices" param
        bool useNormals = true;
        // Add overall color
        bool useColor = true;
        // Copy texture coords
        bool useTexCoords = false;
        // Copy vertex colors
        bool useVertexColors = false;

        // Used when "useColor" is true
        osg::Vec4 color = osg::Vec4(1.0, 1.0, 1.0, 1.0);
    };

    class CConvertToGeometry
    {
    public:
        // Creates OSG geometry from loaded OpenMesh data structure
        static osg::Geometry* convert(geometry::CMesh& mesh, MeshConversionParams params);

        static osg::Texture2D* convert(const vpl::img::CRGBAImage::tSmartPtr& image);
    };
}
#endif
