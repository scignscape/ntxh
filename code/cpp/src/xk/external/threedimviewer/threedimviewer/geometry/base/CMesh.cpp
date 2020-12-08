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


#ifdef _OPENMP
    #include <omp.h> // has to be included first, don't ask me why
#endif

#include "geometry/base/CMesh.h"
#include <geometry/base/functions.h>
#include <cmath>
// Debugging 
// #include <osg/dbout.h> // this dependency is not allowed
#include <VPL/System/Stopwatch.h>

// Eigen vectors computation
#include <VPL/Math/Vector.h>
#include <VPL/Math/MatrixFunctions.h>

// ati drivers (13.251.9001.1001 2014-07-04) end up with heap corruption when drawing extremely short lines, therefore drop them
#define OUTPUT_PRECISION 0.001

namespace geometry
{

////////////////////////////////////////////////////////////
/*!
 * Octree node for subdivison of mesh
 */
CMeshOctreeNode::CMeshOctreeNode()
{
    faceCount = 0;
    vertexCount = 0;
    for (int i = 0; i < 8; i++)
    {
        nodes[i] = -1;
    }
}

//
CMeshOctreeNode::CMeshOctreeNode(const CMeshOctreeNode &node)
{
    for (int i = 0; i < 8; i++)
    {
        nodes[i] = node.nodes[i];
    }

    boundingBox = node.boundingBox;
    faceCount = node.faceCount;
    faces = node.faces;
    vertexCount = node.vertexCount;
}

//
CMeshOctreeNode &CMeshOctreeNode::operator=(const CMeshOctreeNode &node)
{
    if (&node == this)
    {
        return *this;
    }

    for (int i = 0; i < 8; i++)
    {
        nodes[i] = node.nodes[i];
    }

    boundingBox = node.boundingBox;
    faceCount = node.faceCount;
    faces = node.faces;

    return *this;
}

//
CMeshOctreeNode::~CMeshOctreeNode()
{ }

////////////////////////////////////////////////////////////
/*!
 * Octree subdivison of mesh
 */
CMeshOctree::CMeshOctree()
    : m_initialized(false)
    , m_nextIndex(1)
{ }

//
CMeshOctree::CMeshOctree(const CMeshOctree &octree)
{
    m_initialized = octree.m_initialized;
    m_nodes = octree.m_nodes;
    m_nextIndex = octree.m_nextIndex;
}

//
CMeshOctree &CMeshOctree::operator=(const CMeshOctree &octree)
{
    if (&octree == this)
    {
        return *this;
    }

    m_initialized = octree.m_initialized;
    m_nodes = octree.m_nodes;
    m_nextIndex = octree.m_nextIndex;

    return *this;
}

//
bool CMeshOctree::initialize(int levels)
{
    m_initialized = false;

    m_nextIndex = 1;
    int nodeCount = calculateNodeCount(levels);
    m_nodes.resize(nodeCount);

    // resolve links for (levels-1) number of levels (last level's nodes are leaves and have no children)
    int countToResolve = calculateNodeCount(levels - 1);
    for (int i = 0; i < nodeCount; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            m_nodes[i].nodes[j] = i < countToResolve ? m_nextIndex++ : -1;
        }
    }

    m_initialized = true;

    return m_initialized;
}

//
void CMeshOctree::update(CMesh *mesh, osg::BoundingBox boundingBox)
{
    if (!m_initialized)
    {
        return;
    }

    initializeNode(m_nodes[0], boundingBox);
    fillFaceLists(mesh);
    fillVertexLists(mesh);
}

//
//std::vector<CMeshOctreeNode *> CMeshOctree::getIntersectedNodes(osg::Plane plane)
const std::vector<CMeshOctreeNode *>& CMeshOctree::getIntersectedNodes(osg::Plane plane)
{
    m_intersectedNodes.clear();
    intersect(m_nodes[0], plane);
    return m_intersectedNodes;
}

//
const std::vector<CMeshOctreeNode *>& CMeshOctree::getIntersectedNodes(osg::BoundingBox boundingBox)
{
    m_intersectedNodes.clear();
    intersect(m_nodes[0], boundingBox);
    return m_intersectedNodes;
}

const std::vector<CMeshOctreeNode*>& CMeshOctree::getIntersectedNodes(const osg::BoundingSphere& boundingSphere)
{
    m_intersectedNodes.clear();
    intersect(m_nodes[0], boundingSphere);
    return m_intersectedNodes;
}

//
void CMeshOctree::intersect(CMeshOctreeNode &node, osg::Plane plane)
{
    // skip if node is not intersected by a plane
    if (plane.intersect(node.boundingBox) != 0)
    {
        return;
    }

    // skip if node is intersected but has no faces
    if ((node.faceCount == 0) && (node.vertexCount == 0))
    {
        return;
    }

    // add node if it has assigned faces in it's own container
    if ((node.faces.size() > 0) || (node.vertices.size() > 0))
    {
        m_intersectedNodes.push_back(&node);
    }

    // add children if node is not leaf
    if (node.nodes[0] != -1)
    {
        for (int i = 0; i < 8; ++i)
        {
            intersect(m_nodes[node.nodes[i]], plane);
        }
    }
}

//
void CMeshOctree::intersect(CMeshOctreeNode &node, osg::BoundingBox boundingBox)
{
    // skip if node is not intersected by a plane
    if (!boundingBox.intersects(node.boundingBox))
    {
        return;
    }

    // skip if node is intersected but has no faces
    if ((node.faceCount == 0) && (node.vertexCount == 0))
    {
        return;
    }

    // add node if it has assigned faces in it's own container
    if ((node.faces.size() > 0) || (node.vertices.size() > 0))
    {
        m_intersectedNodes.push_back(&node);
    }

    // add children if node is not leaf
    if (node.nodes[0] != -1)
    {
        for (int i = 0; i < 8; ++i)
        {
            intersect(m_nodes[node.nodes[i]], boundingBox);
        }
    }
}

void CMeshOctree::intersect(CMeshOctreeNode & node, const osg::BoundingSphere& boundingSphere)
{
    // skip if node is not intersected by a plane
    if (!sphereBoundingBoxIntersection(node.boundingBox,boundingSphere))
    {
        return;
    }

    // skip if node is intersected but has no faces
    if ((node.faceCount == 0) && (node.vertexCount == 0))
    {
        return;
    }

    // add node if it has assigned faces in it's own container
    if ((node.faces.size() > 0) || (node.vertices.size() > 0))
    {
        m_intersectedNodes.push_back(&node);
    }

    // add children if node is not leaf
    if (node.nodes[0] != -1)
    {
        for (int i = 0; i < 8; ++i)
        {
            intersect(m_nodes[node.nodes[i]], boundingSphere);
        }
    }
}

//
CMeshOctree::~CMeshOctree()
{ }

//
void CMeshOctree::initializeNode(CMeshOctreeNode &node, osg::BoundingBox boundingBox)
{
    node.boundingBox = boundingBox;
    node.faces.clear();
    node.vertices.clear();

    if (node.nodes[0] == -1)
    {
        return;
    }

    for (int z = 0; z < 2; z++)
    {
        for (int y = 0; y < 2; y++)
        {
            for (int x = 0; x < 2; x++)
            {
                osg::Vec3 center = boundingBox.center();
                osg::Vec3 corner = boundingBox.corner(z * 4 + y * 2 + x);
                osg::BoundingBox bb;
                bb.expandBy(center);
                bb.expandBy(corner);
                initializeNode(m_nodes[node.nodes[z * 4 + y * 2 + x]], bb);
            }
        }
    }
}

//
void CMeshOctree::fillFaceLists(geometry::CMesh *mesh)
{
    for (geometry::CMesh::FaceIter fit = mesh->faces_sbegin(); fit != mesh->faces_end(); ++fit)
    {
        geometry::CMesh::FaceHandle face = fit;
        if (!face.is_valid())
            continue;

        osg::BoundingBox faceBoundingBox;
        for (geometry::CMesh::FaceVertexIter fvit = mesh->fv_begin(face); fvit != mesh->fv_end(face); ++fvit)
        {
            geometry::CMesh::Point point = mesh->point(fvit.handle());
            faceBoundingBox.expandBy(point[0], point[1], point[2]);
        }

        assignFace(m_nodes[0], 0, face, faceBoundingBox);
    }
}

//
void CMeshOctree::fillVertexLists(geometry::CMesh *mesh)
{
    for (geometry::CMesh::VertexIter vit = mesh->vertices_begin(); vit != mesh->vertices_end(); ++vit)
    {
        geometry::CMesh::VertexHandle vertex = vit.handle();
        geometry::CMesh::Point point = mesh->point(vertex);
        assignVertex(m_nodes[0], 0, vertex, osg::Vec3(point[0], point[1], point[2]));
    }
}

//
bool CMeshOctree::assignFace(CMeshOctreeNode &node, int level, geometry::CMesh::FaceHandle face, const osg::BoundingBox& faceBoundingBox)
{
    // test if triangle is entirely inside node's bounding box
    bool contains = false;
    if ((node.boundingBox.xMin() <= faceBoundingBox.xMin()) && (node.boundingBox.xMax() >= faceBoundingBox.xMax()) &&
        (node.boundingBox.yMin() <= faceBoundingBox.yMin()) && (node.boundingBox.yMax() >= faceBoundingBox.yMax()) &&
        (node.boundingBox.zMin() <= faceBoundingBox.zMin()) && (node.boundingBox.zMax() >= faceBoundingBox.zMax()))
    {
        contains = true;
    }

    // if not (and node is not root), tell parent that face cannot be assigned
    if ((!contains) && (level != 0))
    {
        return false;
    }

    // increment face count as the face will be assigned
    node.faceCount++;

    // if node is leaf, assign face
    if (node.nodes[0] == -1)
    {
        node.faces.push_back(face);
        return true;
    }

    // try to assign face to one of the children
    for (int i = 0; i < 8; ++i)
    {
        if (assignFace(m_nodes[node.nodes[i]], level + 1, face, faceBoundingBox))
        {
            return true;
        }
    }

    // if face was not assigned, it either intersects children or is out of them and face has to be assigned into this node
    node.faces.push_back(face);
    return true;
}

//
bool CMeshOctree::assignVertex(CMeshOctreeNode &node, int level, geometry::CMesh::VertexHandle vertex, osg::Vec3 coordinates)
{
    // test if vertex is inside node's bounding box
    bool contains = node.boundingBox.contains(coordinates);

    // if not (and node is not root), tell parent that vertex cannot be assigned
    if ((!contains) && (level != 0))
    {
        return false;
    }

    // increment face count as the vertex will be assigned
    node.vertexCount++;

    // if node is leaf, assign face
    if (node.nodes[0] == -1)
    {
        node.vertices.push_back(vertex);
        return true;
    }

    // try to assign vertex to one of the children
    for (int i = 0; i < 8; ++i)
    {
        if (assignVertex(m_nodes[node.nodes[i]], level + 1, vertex, coordinates))
        {
            return true;
        }
    }

    // if vertex was not assigned, it either intersects children or is out of them and vertex has to be assigned into this node
    node.vertices.push_back(vertex);
    return true;
}

//
int CMeshOctree::calculateNodeCount(int numOfLevels)
{
    return (static_cast<int>(pow(8.0f, numOfLevels)) - 1) / (8 - 1);
}

bool CMeshOctree::sphereBoundingBoxIntersection(const osg::BoundingBox & boundingBox, const osg::BoundingSphere & boundingSphere)
{
    //Source: https://github.com/erich666/GraphicsGems/blob/master/gems/BoxSphere.c : Solid Box - Solid Sphere

    double dmin = 0;
    for (int i = 0; i < 3; i++)
    {
        if (boundingSphere._center[i] < boundingBox._min[i])
        {
            double d = (boundingSphere._center[i] - boundingBox._min[i]);
            dmin += d * d;
        }
        else if (boundingSphere._center[i] > boundingBox._max[i])
        {
            double d = (boundingSphere._center[i] - boundingBox._max[i]);
            dmin += d * d;
        }
    }

    if (dmin <= (boundingSphere._radius * boundingSphere._radius))
    {
        return true;
    }

    return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//!\brief   Gets a near points to the given point.
//!
//!\param   point               The point.
//!\param   maximal_distance    The maximal distance from point to the points.
//!
//!\return  null if it fails, else the near points.
////////////////////////////////////////////////////////////////////////////////////////////////////
const std::vector<CMeshOctreeNode *>& CMeshOctree::getNearPoints(const osg::Vec3 &point, double maximal_distance)
{
    //Original WRONG version using bounding box to find intersected nodes. If you want to use bounding boxes,
    //at least remove the division by 2.0!! By dividing by 2.0 you won't get nodes in maximal_distance from given point,
    //but only in half the maximal_distance!
#if 0
    osg::Vec3 hdist(maximal_distance / 2.0, maximal_distance / 2.0, maximal_distance / 2.0);
    osg::BoundingBox bb(point - hdist, point + hdist);

    return getIntersectedNodes(bb);
#else
    //New version using bounding spehere to get intersected nodes.
    osg::BoundingSphere boundingSphere(point, maximal_distance);
    return getIntersectedNodes(boundingSphere);
#endif // 0
}

/**
 * Gets the closest point handle
 *
 * \param   point               The point.
 * \param   maximal_distance    The maximal distance searched.
 * \param   mesh                The mesh.
 *
 * \return  The closest point handle.
 */

geometry::CMesh::VertexHandle CMeshOctree::getClosestPointHandle(const osg::Vec3& point, double maximal_distance,
    const geometry::CMesh& mesh)
{
    CMesh::VertexHandle returned_handle(CMesh::InvalidVertexHandle);
    double current_nearest_distance(std::numeric_limits<double>::max());


    const std::vector<CMeshOctreeNode *> &nodes(getNearPoints(point, maximal_distance));

    double dist_nearestsq(std::numeric_limits<double>::max());

    // For all returned nodes
    auto itn(nodes.begin()), itnEnd(nodes.end());
    size_t counter(0);
    for (; itn != itnEnd; ++itn, ++counter)
    {
        // For all node points
        std::vector<geometry::CMesh::VertexHandle>::const_iterator itvh((*itn)->vertices.begin()), itvhEnd((*itn)->vertices.end());
        for (; itvh != itvhEnd; ++itvh)
        {
            // Get point coordinates
            const geometry::CMesh::Point mp = mesh.point(*itvh);

            // Check distance
            double dx(point[0] - mp[0]), dy(point[1] - mp[1]), dz(point[2] - mp[2]);
            double dsq(dx*dx + dy * dy + dz * dz);
            if (dsq < current_nearest_distance)
            {
                current_nearest_distance = dsq;
                returned_handle = *itvh;
            }

        }
    }

    return returned_handle;
}

/**
    * Gets closest face handle to the given point
    *
    * \param   point               The point.
    * \param   maximal_distance    The maximal searched distance.
    * \param   mesh                The tested mesh.
    *
    * \return  The closest face handle.
    */

geometry::CMesh::FaceHandle CMeshOctree::getClosestFaceHandle(const osg::Vec3 &point, double maximal_distance, const geometry::CMesh &mesh)
{
    geometry::CMesh::VertexHandle nearestPointHandle(getClosestPointHandle(point, maximal_distance, mesh));

    if (!mesh.is_valid_handle(nearestPointHandle))
        return geometry::CMesh::InvalidFaceHandle;

    // Circulate point and find face with the centroid closest to our point
    double closest_distance(std::numeric_limits<double>::max());
    CMesh::FaceHandle closest_handle(CMesh::InvalidFaceHandle);
    CMesh::Point om_point(geometry::convert3<CMesh::Point, osg::Vec3>(point));

    for (CMesh::CVFIter vfit = mesh.cvf_begin(nearestPointHandle); vfit.is_valid(); ++vfit)
    {
        CMesh::Point centroid;
        mesh.calc_face_centroid(vfit.handle(), centroid);

        double distance((om_point - centroid).sqrnorm());
        if (distance < closest_distance)
        {
            closest_distance = distance;
            closest_handle = vfit.handle();
        }
    }

    return closest_handle;
}

////////////////////////////////////////////////////////////
/*!
 * geometry::CMesh and osg::Geometry cutter
 */
CMeshCutter::CMeshCutter()
{
    m_initialized = false;
    m_initializedOrtho = false;
    m_vertices = nullptr;
    m_indices = nullptr;
    m_planePosition = 0;
}

bool CMeshCutter::initialize(osg::Vec3Array *vertices, osg::DrawElementsUInt *indices, osg::Plane plane, osg::Matrix worldMatrix)
{
    if ((vertices == NULL) || (indices == NULL) || (!plane.valid()))
    {
        return m_initialized;
    }
    
    m_vertices = vertices;
    m_indices = indices;
    m_plane = plane;
    m_worldMatrix = worldMatrix;

    m_invWorldMatrix = osg::Matrix::inverse(m_worldMatrix);
    m_transformedPlane = m_plane;
    m_transformedPlane.transform(m_invWorldMatrix);
    m_transformedPlane.makeUnitLength();

    m_initialized = true;
    
    return m_initialized;
}

bool CMeshCutter::initialize(osg::Vec3Array *vertices, osg::DrawElementsUInt *indices, float planePosition)
{
    if ((vertices == NULL) || (indices == NULL))
    {
        return m_initializedOrtho;
    }
    
    m_vertices = vertices;
    m_indices = indices;
    m_planePosition = planePosition;

    m_initializedOrtho = true;
    
    return m_initializedOrtho;
}

//
CMeshCutter::~CMeshCutter()
{ }

//
void CMeshCutter::calculateDistancesX(geometry::CMesh *source, const std::vector<CMeshOctreeNode *> *intersectedNodes)
{
    OpenMesh::VPropHandleT<float> vProp_distance;
    source->get_property_handle(vProp_distance, "distance");

    if (intersectedNodes == NULL)
    {
        for (geometry::CMesh::VertexIter vit = source->vertices_sbegin(); vit != source->vertices_end(); ++vit)
        {
            geometry::CMesh::Point point = source->point(vit.handle());
            source->property(vProp_distance, vit) = m_planePosition - point[0];
        }
    }
    else
    {
        for (unsigned int i = 0; i < intersectedNodes->size(); ++i)
        {
            for (unsigned int f = 0; f < (*intersectedNodes)[i]->faces.size(); ++f)
            {
                const geometry::CMesh::FaceHandle face = (*intersectedNodes)[i]->faces[f];
                if (source->status(face).deleted())
                {
                    continue;
                }

                for (geometry::CMesh::FaceVertexIter fvit = source->fv_begin(face); fvit != source->fv_end(face); ++fvit)
                {
                    if (source->status(*fvit).deleted())
                    {
                        continue;
                    }

                    geometry::CMesh::Point point = source->point(fvit.handle());
                    source->property(vProp_distance, fvit) = m_planePosition - point[0];
                }
            }
        }
    }
}

//
void CMeshCutter::calculateDistancesY(geometry::CMesh *source, const std::vector<CMeshOctreeNode *> *intersectedNodes)
{
    OpenMesh::VPropHandleT<float> vProp_distance;
    source->get_property_handle(vProp_distance, "distance");
    
    if (intersectedNodes == NULL)
    {
        for (geometry::CMesh::VertexIter vit = source->vertices_sbegin(); vit != source->vertices_end(); ++vit)
        {
            geometry::CMesh::Point point = source->point(vit.handle());
            source->property(vProp_distance, vit) = m_planePosition - point[1];
        }
    }
    else
    {
        for (unsigned int i = 0; i < intersectedNodes->size(); ++i)
        {
            for (unsigned int f = 0; f < (*intersectedNodes)[i]->faces.size(); ++f)
            {
                const geometry::CMesh::FaceHandle face = (*intersectedNodes)[i]->faces[f];
                if (source->status(face).deleted())
                {
                    continue;
                }

                for (geometry::CMesh::FaceVertexIter fvit = source->fv_begin(face); fvit != source->fv_end(face); ++fvit)
                {
                    if (source->status(*fvit).deleted())
                    {
                        continue;
                    }

                    geometry::CMesh::Point point = source->point(fvit.handle());
                    source->property(vProp_distance, fvit) = m_planePosition - point[1];
                }
            }
        }
    }
}

//
void CMeshCutter::calculateDistancesZ(geometry::CMesh *source, const std::vector<CMeshOctreeNode *> *intersectedNodes)
{
    OpenMesh::VPropHandleT<float> vProp_distance;
    source->get_property_handle(vProp_distance, "distance");
    
    if (intersectedNodes == NULL)
    {
        for (geometry::CMesh::VertexIter vit = source->vertices_sbegin(); vit != source->vertices_end(); ++vit)
        {
            geometry::CMesh::Point point = source->point(vit.handle());
            source->property(vProp_distance, vit) = m_planePosition - point[2];
        }
    }
    else
    {
        for (unsigned int i = 0; i < intersectedNodes->size(); ++i)
        {
            for (unsigned int f = 0; f < (*intersectedNodes)[i]->faces.size(); ++f)
            {
                const geometry::CMesh::FaceHandle face = (*intersectedNodes)[i]->faces[f];
                if (source->status(face).deleted())
                {
                    continue;
                }

                for (geometry::CMesh::ConstFaceVertexCWIter fvit = source->cfv_cwbegin(face); fvit != source->cfv_cwend(face); ++fvit)
                {
                    const geometry::CMesh::VertexHandle vh = *fvit;
                    if (source->status(vh).deleted())
                    {
                        continue;
                    }

                    geometry::CMesh::Point point = source->point(vh);
                    source->property(vProp_distance, vh) = m_planePosition - point[2];
                }
            }
        }
    }
}

//
void CMeshCutter::calculateDistances(geometry::CMesh *source, const std::vector<CMeshOctreeNode *> *intersectedNodes)
{
    OpenMesh::VPropHandleT<float> vProp_distance;
    source->get_property_handle(vProp_distance, "distance");
    
    if (intersectedNodes == NULL)
    {
		for (geometry::CMesh::VertexIter vit = source->vertices_sbegin(); vit != source->vertices_end(); ++vit)
		{
			geometry::CMesh::Point point = source->point(vit.handle());
			source->property(vProp_distance, vit) = m_transformedPlane.distance(osg::Vec3(point[0], point[1], point[2]));
		}
    }
    else
    {
        for (int i = 0; i < (int)intersectedNodes->size(); ++i)
        {
            const long nFaces = (*intersectedNodes)[i]->faces.size();
#pragma omp parallel for
            for (long f = 0; f < nFaces; ++f)
            {
                const geometry::CMesh::FaceHandle face = (*intersectedNodes)[i]->faces[f];
                if (source->status(face).deleted())
                {
                    continue;
                }
                for (geometry::CMesh::ConstFaceVertexCWIter fvit = source->cfv_cwbegin(face); fvit != source->cfv_cwend(face); ++fvit)
                {
                    if (source->status(*fvit).deleted())
                    {
                        continue;
                    }        
                    float& prop = source->property(vProp_distance, *fvit);
                    if (0 == prop)
                    {
                        const geometry::CMesh::Point& point = source->point(*fvit);
                        prop = m_transformedPlane.distance(osg::Vec3(point[0], point[1], point[2]));
                    }
                }
            }
        }
    }
}

//
void CMeshCutter::cutX(geometry::CMesh *source)
{
    if (!m_initializedOrtho)
    {
        return;
    }

    vpl::sys::CStopwatch sw;
    sw.start();

    if (source->m_octree != NULL)
    {
        m_plane = osg::Plane(1.0f, 0.0f, 0.0f, -m_planePosition);
        m_transformedPlane = m_plane;
        m_transformedPlane.transform(m_invWorldMatrix);
        m_transformedPlane.makeUnitLength();

//        std::vector<CMeshOctreeNode *> intersectedNodes = source->m_octree->getIntersectedNodes(m_transformedPlane);
        const std::vector<CMeshOctreeNode *>& intersectedNodes = source->m_octree->getIntersectedNodes(m_transformedPlane);
        if (intersectedNodes.size() == 0)
        {
            return;
        }

        OpenMesh::VPropHandleT<float> vProp_distance;
        source->add_property(vProp_distance, "distance");

        calculateDistancesX(source, &intersectedNodes);
        performCut(source, &intersectedNodes);

        source->remove_property(vProp_distance);
    }
    else
    {
        OpenMesh::VPropHandleT<float> vProp_distance;
        source->add_property(vProp_distance, "distance");

        calculateDistancesX(source);
        performCut(source);

        source->remove_property(vProp_distance);
    }

//    unsigned long duration = sw.getDuration();
//    DBOUT("Cut X duration >>> " << duration);
}

//
void CMeshCutter::cutY(geometry::CMesh *source)
{
    if (!m_initializedOrtho)
    {
        return;
    }

    vpl::sys::CStopwatch sw;
    sw.start();

    if (source->m_octree != NULL)
    {
        m_plane = osg::Plane(0.0f, 1.0f, 0.0f, -m_planePosition);
        m_transformedPlane = m_plane;
        m_transformedPlane.transform(m_invWorldMatrix);
        m_transformedPlane.makeUnitLength();

//        std::vector<CMeshOctreeNode *> intersectedNodes = source->m_octree->getIntersectedNodes(m_transformedPlane);
        const std::vector<CMeshOctreeNode *>& intersectedNodes = source->m_octree->getIntersectedNodes(m_transformedPlane);
        if (intersectedNodes.size() == 0)
        {
            return;
        }

        OpenMesh::VPropHandleT<float> vProp_distance;
        source->add_property(vProp_distance, "distance");

        calculateDistancesY(source, &intersectedNodes);
        performCut(source, &intersectedNodes);

        source->remove_property(vProp_distance);
    }
    else
    {
        OpenMesh::VPropHandleT<float> vProp_distance;
        source->add_property(vProp_distance, "distance");

        calculateDistancesY(source);
        performCut(source);

        source->remove_property(vProp_distance);
    }

//    unsigned long duration = sw.getDuration();
//    DBOUT("Cut Y duration >>> " << duration);
}

//
void CMeshCutter::cutZ(geometry::CMesh *source)
{
    if (!m_initializedOrtho)
    {
        return;
    }

    vpl::sys::CStopwatch sw;
    sw.start();

    if (source->m_octree != NULL)
    {
        m_plane = osg::Plane(0.0f, 0.0f, 1.0f, -m_planePosition);
        m_transformedPlane = m_plane;
        m_transformedPlane.transform(m_invWorldMatrix);
        m_transformedPlane.makeUnitLength();

//        std::vector<CMeshOctreeNode *> intersectedNodes = source->m_octree->getIntersectedNodes(m_transformedPlane);
        const std::vector<CMeshOctreeNode *>& intersectedNodes = source->m_octree->getIntersectedNodes(m_transformedPlane);
        if (intersectedNodes.size() == 0)
        {
            return;
        }

        OpenMesh::VPropHandleT<float> vProp_distance;
        source->add_property(vProp_distance, "distance");

        calculateDistancesZ(source, &intersectedNodes);
        performCut(source, &intersectedNodes);

        source->remove_property(vProp_distance);
    }
    else
    {
        OpenMesh::VPropHandleT<float> vProp_distance;
        source->add_property(vProp_distance, "distance");

        calculateDistancesZ(source);
        performCut(source);

        source->remove_property(vProp_distance);
    }

//    unsigned long duration = sw.getDuration();
//    DBOUT("Cut Z duration >>> " << duration);
}

//
void CMeshCutter::cut(geometry::CMesh *source)
{
    if (!m_initialized)
    {
        return;
    }

    vpl::sys::CStopwatch sw;
    sw.start();

    if (source->m_octree != NULL)
    {
//        std::vector<CMeshOctreeNode *> intersectedNodes = source->m_octree->getIntersectedNodes(m_transformedPlane);
        const std::vector<CMeshOctreeNode *>& intersectedNodes = source->m_octree->getIntersectedNodes(m_transformedPlane);
        if (intersectedNodes.size() == 0)
        {
            return;
        }

        OpenMesh::VPropHandleT<float> vProp_distance;
        source->add_property(vProp_distance, "distance");

        calculateDistances(source, &intersectedNodes);
        performCut(source, &intersectedNodes);

        source->remove_property(vProp_distance);
    }
    else
    {
        OpenMesh::VPropHandleT<float> vProp_distance;
        source->add_property(vProp_distance, "distance");

        calculateDistances(source);
        performCut(source);

        source->remove_property(vProp_distance);
    }

//    unsigned long duration = sw.getDuration();
//    DBOUT("Cut duration >>> " << duration);
}

//#define omp_parallel
//void CMeshCutter::performCut(geometry::CMesh *source, std::vector<CMeshOctreeNode *> *intersectedNodes)
void CMeshCutter::performCut(geometry::CMesh *source, const std::vector<CMeshOctreeNode *> *intersectedNodes)
{
    OpenMesh::VPropHandleT<float> vProp_distance;
    source->get_property_handle(vProp_distance, "distance");

    if (intersectedNodes == NULL)
    {
//        #ifdef omp_parallel
//        #ifdef _OPENMP
        #if 0
        std::vector<CMesh::FaceIter> start;
        int parts = source->n_faces() / 4096 + 1;
        int partCount = source->n_faces() / parts;
        int index = 0;
        for (geometry::CMesh::FaceIter fit = source->faces_begin(); fit != source->faces_end(); ++fit)
        {
            if (index % partCount == 0)
            {
                start.push_back(fit);
            }
            index++;
        }
        start.push_back(source->faces_end());

        #pragma omp parallel for schedule(static)
        for (int i = 0; i < start.size() - 1; ++i)
        {
            geometry::CMesh::FaceIter fitstart = start[i];
            geometry::CMesh::FaceIter fitend = start[i + 1];

            for (geometry::CMesh::FaceIter fit = fitstart; fit != fitend; ++fit)
            {
                geometry::CMesh::FaceHandle face = fit.handle();
                std::vector<osg::Vec3> vertices;
                std::vector<float> distances;

                for (geometry::CMesh::FaceVertexIter fvit = source->fv_begin(face); fvit != source->fv_end(face); ++fvit)
                {
                    geometry::CMesh::Point vertex = source->point(fvit.handle());
                    vertices.push_back(osg::Vec3(vertex[0], vertex[1], vertex[2]));
                    distances.push_back(source->property(vProp_distance, fvit.handle()));
                }

                if (vertices.size() != 3)
                {
                    continue;
                }

#pragma omp critical
                this->operator()(vertices[0], vertices[1], vertices[2], distances[0], distances[1], distances[2]);
            }
        }
        #else
        for (geometry::CMesh::FaceIter fit = source->faces_begin(); fit != source->faces_end(); ++fit)
        {
            geometry::CMesh::FaceHandle face = fit.handle();

            int nVertices = 0;
            osg::Vec3 vertices[3];
            float distances[3] = {};
            for (geometry::CMesh::FaceVertexIter fvit = source->fv_begin(face); fvit != source->fv_end(face); ++fvit)
            {
                geometry::CMesh::Point vertex = source->point(fvit.handle());
                vertices[nVertices] = osg::Vec3(vertex[0], vertex[1], vertex[2]);
                distances[nVertices] = source->property(vProp_distance, fvit.handle());
                nVertices++;
            }

            if (nVertices != 3)
            {
                continue;
            }

            this->operator()(vertices[0], vertices[1], vertices[2], distances[0], distances[1], distances[2]);
        }
        #endif
    }
    else
    {   
        //int clk = clock();

#ifdef _OPENMP        

        // limit to 16 threads
        int nThreads=omp_get_max_threads( ); 
        if (nThreads>16)
            nThreads=16;
        
        std::vector<std::vector<osg::Vec3> > vLists[16]; // list of lists for every thread
                
        
#endif
        for( int i = 0; i < int(intersectedNodes->size()); ++i )
        {
            const int nNodeFaces = (int)((*intersectedNodes)[i]->faces.size());
#ifdef _OPENMP        
            #pragma omp parallel for schedule(dynamic) num_threads(nThreads)
#endif
            for( int f = 0; f < nNodeFaces; ++f)
            {
                geometry::CMesh::FaceHandle face = (*intersectedNodes)[i]->faces[f];
                int nVertices = 0;
                osg::Vec3 vertices[3];
                float distances[3] = {};

                for (geometry::CMesh::ConstFaceVertexCWIter fvit = source->cfv_cwbegin(face); fvit != source->cfv_cwend(face); ++fvit)
                {
                    geometry::CMesh::Point vertex = source->point(*fvit);
                    vertices[nVertices] = osg::Vec3(vertex[0], vertex[1], vertex[2]);
                    distances[nVertices] = source->property(vProp_distance, *fvit);
                    nVertices++;
                }

                if (nVertices != 3)
                {
                    continue;
                }

#ifndef _OPENMP
                // This acesses a shared resource so it cannot run in parallel!!!
                this->operator()(vertices[0], vertices[1], vertices[2], distances[0], distances[1], distances[2]);
#else
                int iThread = omp_get_thread_num(); // index of thread

                const osg::Vec3 &v1 = vertices[0]; 
                const osg::Vec3 &v2 = vertices[1]; 
                const osg::Vec3 &v3 = vertices[2];
                float d1 = distances[0];
                float d2 = distances[1];
                float d3 = distances[2];
                // completely above or completely below plane
                if ((sign(d1) == sign(d2)) && (sign(d1) == sign(d3)) && (sign(d1) != 0))
                {
                    continue;
                }

                std::vector<osg::Vec3> newVertices;
                newVertices.reserve(3);

                // find intersection between v1 and v2
                if (sign(d1) != sign(d2))
                {
                    float a1 = fabs(d1);
                    float a2 = fabs(d2);
                    float distance = a1 / (a1 + a2);
                    newVertices.push_back(v1 + (v2 - v1) * distance);
                }

                // find intersection between v2 and v3
                if (sign(d2) != sign(d3))
                {
                    float a2 = fabs(d2);
                    float a3 = fabs(d3);
                    float distance = a2 / (a2 + a3);
                    newVertices.push_back(v2 + (v3 - v2) * distance);
                }

                // find intersection between v1 and v3
                if (sign(d1) != sign(d3))
                {
                    float a1 = fabs(d1);
                    float a3 = fabs(d3);
                    float distance = a1 / (a1 + a3);
                    newVertices.push_back(v1 + (v3 - v1) * distance);
                }

                vLists[iThread].push_back(newVertices);
#endif
            }
        }
#ifdef _OPENMP
        // add new vertices to geometry
        for(int t = 0 ; t<nThreads; t++) // for every thread
        {
            int cnt=vLists[t].size();
            for(int l=0;l<cnt;l++) // for every list
            {
                const std::vector<osg::Vec3>&  newVertices = vLists[t].at(l);
                // input list can contain >2 vertices that are to be connected
                for (unsigned int i = 0; i < std::min<unsigned int>(2,(unsigned int)newVertices.size()); i++)
                {
                    // ati drivers (13.251.9001.1001 2014-07-04) end up with heap corruption when drawing extremely short lines, therefore drop them
                    if (i>0 && (newVertices[i]-m_vertices->back()).length()<OUTPUT_PRECISION)
                    {
                        m_vertices->pop_back();
                    }
                    else
                    {
                        m_vertices->push_back(newVertices[i]);
                    }
                }
            }
        }
        assert(m_vertices->size()%2==0);
        for(int i = 0; i < m_vertices->size(); i++)
        {
            m_indices->push_back(i);
        }
#endif

        m_vertices->dirty();
        m_indices->dirty();

#if(0)
        clk = clock() - clk;
        char sss[32];
        sprintf(sss,"cut: %d",clk);
        VPL_LOG_INFO(sss);
        OutputDebugStringA(sss);
#endif
    }
}

//
void CMeshCutter::operator()(const osg::Vec3 &v1, const osg::Vec3 &v2, const osg::Vec3 &v3, float d1, float d2, float d3)
{ 
    VPL_ASSERT(m_initialized || m_initializedOrtho);
    
    // completely above or completely below plane
    if ((sign(d1) == sign(d2)) && (sign(d1) == sign(d3)) && (sign(d1) != 0))
    {
        return;
    }

    std::vector<osg::Vec3> newVertices;

    // find intersection between v1 and v2
    if (sign(d1) != sign(d2))
    {
        float a1 = fabs(d1);
        float a2 = fabs(d2);
        float distance = a1 / (a1 + a2);
        newVertices.push_back(v1 + (v2 - v1) * distance);
    }

    // find intersection between v2 and v3
    if (sign(d2) != sign(d3))
    {
        float a2 = fabs(d2);
        float a3 = fabs(d3);
        float distance = a2 / (a2 + a3);
        newVertices.push_back(v2 + (v3 - v2) * distance);
    }

    // find intersection between v1 and v3
    if (sign(d1) != sign(d3))
    {
        float a1 = fabs(d1);
        float a3 = fabs(d3);
        float distance = a1 / (a1 + a3);
        newVertices.push_back(v1 + (v3 - v1) * distance);
    }

    // add new vertices to geometry
    const int startIndex = m_vertices->size();
    // input list can contain >2 vertices to be connected
    for (unsigned int i = 0; i < std::min<unsigned int>(2,(unsigned int)newVertices.size()); i++)
    {
        // ati drivers (13.251.9001.1001 2014-07-04) end up with heap corruption when drawing extremely short lines, therefore drop them
        if (i>0 && (newVertices[i]-m_vertices->back()).length()<OUTPUT_PRECISION)
        {
            m_vertices->pop_back();
        }
        else
        {
            m_vertices->push_back(newVertices[i]);
        }
    }
    for(int i = startIndex; i < m_vertices->size(); i++)
    {
        m_indices->push_back(i);
    }

    m_vertices->dirty();
    m_indices->dirty();
}

void CMeshCutter::operator()(const osg::Vec3 &v1, const osg::Vec3 &v2, const osg::Vec3 &v3)
{ 
    VPL_ASSERT(m_initialized);
    
    // calculate distances
    float d1 = m_transformedPlane.distance(osg::Vec3(v1[0], v1[1], v1[2]));
    float d2 = m_transformedPlane.distance(osg::Vec3(v2[0], v2[1], v2[2]));
    float d3 = m_transformedPlane.distance(osg::Vec3(v3[0], v3[1], v3[2]));

    // completely above or completely below plane
    if ((sign(d1) == sign(d2)) && (sign(d1) == sign(d3)) && (sign(d1) != 0))
    {
        return;
    }

    std::vector<osg::Vec3> newVertices;

    // find intersection between v1 and v2
    if (sign(d1) != sign(d2))
    {
        float a1 = fabs(d1);
        float a2 = fabs(d2);
        float distance = a1 / (a1 + a2);
        newVertices.push_back(v1 + (v2 - v1) * distance);
    }

    // find intersection between v2 and v3
    if (sign(d2) != sign(d3))
    {
        float a2 = fabs(d2);
        float a3 = fabs(d3);
        float distance = a2 / (a2 + a3);
        newVertices.push_back(v2 + (v3 - v2) * distance);
    }

    // find intersection between v1 and v3
    if (sign(d1) != sign(d3))
    {
        float a1 = fabs(d1);
        float a3 = fabs(d3);
        float distance = a1 / (a1 + a3);
        newVertices.push_back(v1 + (v3 - v1) * distance);
    }

    // add new vertices to geometry
    const int startIndex = m_vertices->size();
    // input list can contain >2 vertices to be connected
    for (unsigned int i = 0; i < std::min<unsigned int>(2,(unsigned int)newVertices.size()); i++)
    {
        // ati drivers (13.251.9001.1001 2014-07-04) end up with heap corruption when drawing extremely short lines, therefore drop them
        if (i>0 && (newVertices[i]-m_vertices->back()).length()<OUTPUT_PRECISION)
        {
            m_vertices->pop_back();
        }
        else
        {
            m_vertices->push_back(newVertices[i]);
        }
    }
    for(int i = startIndex; i < m_vertices->size(); i++)
    {
        m_indices->push_back(i);
    }

    m_vertices->dirty();
    m_indices->dirty();
}

////////////////////////////////////////////////////////////
/*!
 * Triangular mesh
 */
//! Ctor
CMesh::CMesh()
    : m_octree(NULL)
	, m_octreeVersion(0)
{
    m_pp.resize(PPT_VERTEX+1);
}

//! Copy constructor
CMesh::CMesh(const CMesh &mesh)
    : vpl::base::CObject()
    , CBaseMesh(mesh)
    , m_octree(NULL)
    , m_octreeVersion(0)
    , m_pp(mesh.m_pp)
{
    if (mesh.m_octree != NULL)
    {
        m_octree = new CMeshOctree();
        *m_octree = *mesh.m_octree;
    }

    request_face_normals();
}

//! Assignment operator
CMesh &CMesh::operator=(const CMesh &mesh)
{
    if (&mesh == this)
    {
        return *this;
    }

    CBaseMesh::operator=(mesh);

    if( m_octree )
    {
        delete m_octree;
        m_octree = NULL;
    }

    if (mesh.m_octree != NULL)
    {
        m_octree = new CMeshOctree();
        *m_octree = *mesh.m_octree;
    }

    m_octreeVersion = 0;

    m_pp.clear();
    m_pp.insert(m_pp.end(), mesh.m_pp.begin(), mesh.m_pp.end());

    request_face_normals();

    return *this;
}

//! Dtor
CMesh::~CMesh()
{
    if( m_octree )
    {
        delete m_octree;
    }
}

//! Updates octree of mesh
void CMesh::updateOctree() 
{
    if (m_octree == NULL)
    {
        m_octree = new CMeshOctree;
    }

    CMesh::Point min, max;
    calc_bounding_box(min, max);
    
    int faceCount = this->n_faces();
    int numOfLevels = std::pow(faceCount / 1024.0, 1.0 / 3.0);
    vpl::math::limit<int>(numOfLevels, 3, 6);

    m_octree->initialize(numOfLevels);
    m_octree->update(this, osg::BoundingBox(osg::Vec3(min[0], min[1], min[2]), osg::Vec3(max[0], max[1], max[2])));
	m_octreeVersion = 0;
}

//! updates octree of mesh
void CMesh::updateOctree(int version)
{
	if (m_octreeVersion==version)
		return;
	updateOctree();
	m_octreeVersion = version;
	
	/*if (this->n_vertices()>0)
	{
		std::stringstream ss;
		ss << m_octreeVersion;
		std::string s = ss.str();
		OutputDebugStringA(s.c_str());
	}*/
}

//! Cutting by plane
bool CMesh::cutByXPlane(geometry::CMesh *source, osg::Vec3Array *vertices, osg::DrawElementsUInt *indices, float planePosition)
{
    if ((source == NULL) || (vertices == NULL) || (indices == NULL))
    {
        return false;
    }

	if (0==source->n_vertices())
		return true;

    CMeshCutter meshCutter;
    meshCutter.initialize(vertices, indices, planePosition);
    meshCutter.cutX(source);

    return true;
}

//! Cutting by plane
bool CMesh::cutByYPlane(geometry::CMesh *source, osg::Vec3Array *vertices, osg::DrawElementsUInt *indices, float planePosition)
{
    if ((source == NULL) || (vertices == NULL) || (indices == NULL))
    {
        return false;
    }

	if (0==source->n_vertices())
		return true;

    CMeshCutter meshCutter;
    meshCutter.initialize(vertices, indices, planePosition);
    meshCutter.cutY(source);

    return true;
}

//! Cutting by plane
bool CMesh::cutByZPlane(geometry::CMesh *source, osg::Vec3Array *vertices, osg::DrawElementsUInt *indices, float planePosition) 
{
    if ((source == NULL) || (vertices == NULL) || (indices == NULL))
    {
        return false;
    }

	if (0==source->n_vertices())
		return true;

    CMeshCutter meshCutter;
    meshCutter.initialize(vertices, indices, planePosition);
    meshCutter.cutZ(source);

    return true;
}

//! Cutting by plane
bool CMesh::cutByPlane(geometry::CMesh *source, osg::Vec3Array *vertices, osg::DrawElementsUInt *indices, osg::Plane plane, osg::Matrix worldMatrix)
{
    if ((source == NULL) || (vertices == NULL) || (indices == NULL) || (!plane.valid()))
    {
        return false;
    }

	if (0==source->n_vertices())
		return true;

    CMeshCutter meshCutter;
    meshCutter.initialize(vertices, indices, plane, worldMatrix);
    meshCutter.cut(source);

    return true;
}

//! Cutting by plane
bool CMesh::cutByPlane(osg::Geometry *source, osg::Vec3Array *vertices, osg::DrawElementsUInt *indices, osg::Plane plane, osg::Matrix worldMatrix)
{
    if ((source == NULL) || (vertices == NULL) || (indices == NULL))
    {
        return false;
    }

    vpl::sys::CStopwatch sw;
    sw.start();

    osg::TriangleFunctor<CMeshCutter> meshCutter;
    meshCutter.initialize(vertices, indices, plane, worldMatrix);
    source->accept(meshCutter);

//    unsigned long duration = sw.getDuration();
//    DBOUT("Cut duration >>> " << duration);

    return true;
}

void CMesh::getVerticesInRange(std::vector<geometry::CMesh::VertexHandle> &vertices, std::vector<double> &distances, geometry::CMesh::Point referencePoint, double distance)
{
    vertices.clear();
    distances.clear();

    if (m_octree != NULL)
    {
        osg::Vec3 min = osg::Vec3(referencePoint[0] - distance, referencePoint[1] - distance, referencePoint[2] - distance);
        osg::Vec3 max = osg::Vec3(referencePoint[0] + distance, referencePoint[1] + distance, referencePoint[2] + distance);
        const std::vector<CMeshOctreeNode*>& intersectedNodes = m_octree->getIntersectedNodes(osg::BoundingBox(min, max));
        for (int i = 0; i < intersectedNodes.size(); ++i)
        {
            for (std::vector<geometry::CMesh::VertexHandle>::iterator vit = intersectedNodes[i]->vertices.begin(); vit != intersectedNodes[i]->vertices.end(); ++vit)
            {
                double currDistance = (referencePoint - point(*vit)).length();
                if (currDistance < distance)
                {
                    vertices.push_back(*vit);
                    distances.push_back(currDistance);
                }
            }
        }
    }
    else
    {
        for (geometry::CMesh::VertexIter vit = vertices_begin(); vit != vertices_end(); ++vit)
        {
            double currDistance = (referencePoint - point(*vit)).length();
            if (currDistance < distance)
            {
                vertices.push_back(vit.handle());
                distances.push_back(currDistance);
            }
        }
    }
}

void CMesh::merge(geometry::CMesh &mesh, bool swapSourceMeshFaceOrientation, const osg::Matrix &transformMatrix)
{
    if (mesh.n_vertices() == 0)
    {
        return;
    }

    // copy vertices and store (handle => new_handle) mapping
    std::map<geometry::CMesh::VertexHandle, geometry::CMesh::VertexHandle> vertexHandleMap;
    for (geometry::CMesh::VertexIter vit = mesh.vertices_begin(); vit != mesh.vertices_end(); ++vit)
    {
        geometry::CMesh::Point point = mesh.point(vit.handle());
        osg::Vec3 vertex(point[0], point[1], point[2]);
        vertex = vertex * transformMatrix;
        vertexHandleMap[vit.handle()] = add_vertex(geometry::CMesh::Point(vertex[0], vertex[1], vertex[2]));
    }

    // copy faces using handle map
    for (geometry::CMesh::FaceIter fit = mesh.faces_begin(); fit != mesh.faces_end(); ++fit)
    {
        geometry::CMesh::FaceHandle faceHandle = fit.handle();
        std::vector<geometry::CMesh::VertexHandle> vertexHandles;
        for (geometry::CMesh::FaceVertexIter fvit = mesh.fv_begin(faceHandle); fvit != mesh.fv_end(faceHandle); ++fvit)
        {
            vertexHandles.push_back(vertexHandleMap[fvit.handle()]);
        }

        assert(vertexHandles.size() == 3);

        if (swapSourceMeshFaceOrientation)
        {
            add_face(vertexHandles[0], vertexHandles[2], vertexHandles[1]);
        }
        else
        {
            add_face(vertexHandles[0], vertexHandles[1], vertexHandles[2]);
        }
    }
}

//! calculates quality of face
double CMesh::quality(geometry::CMesh::FaceHandle fh)
{
    double per = perimeter(fh);
    double max = max_edge_length(fh);
    return (per == 0.0 ? 0.0 : (per - 2.0 * max) / max);

    //double lengths[3];
    //int i = 0;
    //for (CMesh::FaceEdgeIter feit = this->fe_begin(fh); feit != this->fe_end(fh); ++feit)
    //{
    //    lengths[i] = this->calc_edge_length(feit.handle());
    //    i++;
    //}
    //double max = vpl::math::getMax<double>(lengths[0], lengths[1], lengths[2]);
    //double min = vpl::math::getMin<double>(lengths[0], lengths[1], lengths[2]);
    //return min / max;

    //return (12.0 * area(fh)) / (SQRT_3 * max_edge_length(fh) * perimeter(fh));
}

//double CMesh::quality(geometry::CMesh::Point p0, geometry::CMesh::Point p1, geometry::CMesh::Point p2)
/*double CMesh::quality(const geometry::CMesh::Point& p0, const geometry::CMesh::Point& p1, const geometry::CMesh::Point& p2)
{
    double per = perimeter(p0, p1, p2);
    double max = max_edge_length(p0, p1, p2);
    return (per - 2.0 * max) / max;
    
    //double max = vpl::math::getMax<double>((p0 - p1).length(), (p1 - p2).length(), (p2 - p0).length());
    //double min = vpl::math::getMin<double>((p0 - p1).length(), (p1 - p2).length(), (p2 - p0).length());
    //return min / max;
    
    //return (12.0 * area(p0, p1, p2)) / (SQRT_3 * max_edge_length(p0, p1, p2) * perimeter(p0, p1, p2));
}*/

//! calculates area that is covered by face
double CMesh::area(geometry::CMesh::FaceHandle fh)
{
    CMesh::Point vertices[3];
    int i = 0;
    for (CMesh::FaceVertexIter fvit = this->fv_begin(fh); fvit != this->fv_end(fh); ++fvit)
    {
        vertices[i] = this->point(fvit);
        i++;
    }
        
    OpenMesh::Vec3d vec0(vertices[1] - vertices[0]);
    OpenMesh::Vec3d vec1(vertices[2] - vertices[0]);        

    // area = 1/2 * cross_product(vec(u0, u1), vec2(u0, u2))
    return (vec0 % vec1).length() / 2;
}

//double CMesh::area(geometry::CMesh::Point p0, geometry::CMesh::Point p1, geometry::CMesh::Point p2)
/*double CMesh::area(const geometry::CMesh::Point& p0, const geometry::CMesh::Point& p1, const geometry::CMesh::Point& p2)
{
    // area = 1/2 * cross_product(vec(u0, u1), vec2(u0, u2))
    return ((p1 - p0) % (p2 - p0)).length() / 2;
}*/

//! calculates perimeter of face
double CMesh::perimeter(geometry::CMesh::FaceHandle fh)
{
    double result = 0.0;

    for (CMesh::FaceEdgeIter feit = this->fe_begin(fh); feit != this->fe_end(fh); ++feit)
    {
        result += this->calc_edge_length(feit.handle());
    }
        
    return result;
}

//! calculates length of longest edge
double CMesh::min_edge_length(geometry::CMesh::FaceHandle fh)
{
    double lengths[3] = {};
    int i = 0;
    for (CMesh::FaceEdgeIter feit = this->fe_begin(fh); feit != this->fe_end(fh); ++feit)
    {
        lengths[i] = this->calc_edge_length(feit.handle());
        i++;
    }

    return vpl::math::getMin<double>(lengths[0], lengths[1], lengths[2]);
}

//! calculates length of longest edge
double CMesh::max_edge_length(geometry::CMesh::FaceHandle fh)
{
    double lengths[3] = {};
    int i = 0;
    for (CMesh::FaceEdgeIter feit = this->fe_begin(fh); feit != this->fe_end(fh); ++feit)
    {
        lengths[i] = this->calc_edge_length(feit.handle());
        i++;
    }

    return vpl::math::getMax<double>(lengths[0], lengths[1], lengths[2]);
}

double CMesh::triangle_height(geometry::CMesh::FaceHandle fh, geometry::CMesh::EdgeHandle eh)
{
    return 2.0 * area(fh) / calc_edge_length(eh);
}

//! return shortest edge
geometry::CMesh::EdgeHandle CMesh::min_edge(geometry::CMesh::FaceHandle fh)
{
    geometry::CMesh::EdgeHandle minEdge;
    geometry::CMesh::EdgeHandle currEdge;
    double minLength = -1.0;
    double currLength;

    for (CMesh::FaceEdgeIter feit = this->fe_begin(fh); feit != this->fe_end(fh); ++feit)
    {
        currEdge = feit.handle();
        currLength = this->calc_edge_length(currEdge);

        if (currLength != -1 && currLength < minLength)
        {
            minLength = currLength;
            minEdge = currEdge;
        }
    }

    return minEdge;
}

//! return longest edge
geometry::CMesh::EdgeHandle CMesh::max_edge(geometry::CMesh::FaceHandle fh)
{
    geometry::CMesh::EdgeHandle maxEdge;
    geometry::CMesh::EdgeHandle currEdge;
    double maxLength = -1.0;
    double currLength;

    for (CMesh::FaceEdgeIter feit = this->fe_begin(fh); feit != this->fe_end(fh); ++feit)
    {
        currEdge = feit.handle();
        currLength = this->calc_edge_length(currEdge);

        if (currLength > maxLength)
        {
            maxLength = currLength;
            maxEdge = currEdge;
        }
    }

    return maxEdge;
}

//! returns face that shares specified edge
geometry::CMesh::FaceHandle CMesh::neighbour(geometry::CMesh::FaceHandle fh, geometry::CMesh::EdgeHandle eh)
{
    geometry::CMesh::FaceHandle retNeighbour;
    retNeighbour.invalidate();

    for (geometry::CMesh::FaceFaceIter ffit = this->ff_begin(fh); ffit != this->ff_end(fh); ++ffit)
    {
        geometry::CMesh::FaceHandle curr = ffit.handle();
        if (curr.is_valid())
        {
            for (geometry::CMesh::FaceEdgeIter feit = this->fe_begin(curr); feit != this->fe_end(curr); ++feit)
            {
                if (feit.handle() == eh)
                {
                    retNeighbour = curr;
                    break;
                }
            }
        }
    }

    return retNeighbour;
}

//! returns the remaining vertex of face
geometry::CMesh::VertexHandle CMesh::rest_vertex(geometry::CMesh::FaceHandle fh, geometry::CMesh::VertexHandle vh0, geometry::CMesh::VertexHandle vh1)
{
    geometry::CMesh::VertexHandle vertex;
    vertex.invalidate();
        
    for (geometry::CMesh::FaceVertexIter fvit = this->fv_begin(fh); fvit != this->fv_end(fh); ++fvit)
    {
        geometry::CMesh::VertexHandle curr = fvit.handle();
        if ((curr != vh0) && (curr != vh1))
        {
            vertex = curr;
            break;
        }
    }

    return vertex;
}

//! calculates normal of face
//geometry::CMesh::Normal CMesh::calc_face_normal(geometry::CMesh::Point p0, geometry::CMesh::Point p1, geometry::CMesh::Point p2)
/*geometry::CMesh::Normal CMesh::calc_face_normal(const geometry::CMesh::Point& p0, const geometry::CMesh::Point& p1, const geometry::CMesh::Point& p2)
{
    return PolyMesh::calc_face_normal(p0, p1, p2);
}*/

geometry::CMesh::Normal CMesh::calc_face_normal(geometry::CMesh::FaceHandle fh)
{
    return PolyMesh::calc_face_normal(fh);
}

//! Finds edge by two vertices
geometry::CMesh::EdgeHandle CMesh::find_edge(const geometry::CMesh::VertexHandle &vh0, const geometry::CMesh::VertexHandle &vh1)
{
    if (vh0 == vh1 || !vh0.is_valid() || !vh1.is_valid() || status(vh0).deleted() || status(vh1).deleted())
    {
        return geometry::CMesh::InvalidEdgeHandle;
    }

    geometry::CMesh::HalfedgeHandle heh = find_halfedge(vh0, vh1);
    if (!heh.is_valid())
    {
        heh = find_halfedge(vh1, vh0);
    }
    if (!heh.is_valid())
    {
        return geometry::CMesh::InvalidEdgeHandle;
    }

    return edge_handle(heh);
}

void CMesh::addMesh(const CMesh &added_mesh)
{
	// Nothing to do?
	if (added_mesh.n_vertices() == 0)
		return;

	// Create helper array of vertex handles and old-new mapping
	std::vector<CMesh::VHandle> vhandles(added_mesh.n_vertices());
	std::map<CMesh::VHandle, CMesh::VHandle> vertex_mapping;

	// Store vertices
	for (CMesh::ConstVertexIter vit = added_mesh.vertices_sbegin(); vit != added_mesh.vertices_end(); ++vit)
	{
		CMesh::VHandle new_handle = this->add_vertex(added_mesh.point(vit));
		vertex_mapping[vit.handle()] = new_handle;
	}

	std::vector<CMesh::VertexHandle> face; face.reserve(4);

	for (CMesh::ConstFaceIter fit = added_mesh.faces_sbegin(); fit != added_mesh.faces_end(); ++fit)
	{
		face.clear();
		for (CMesh::ConstFaceVertexIter fvit = added_mesh.cfv_iter(*fit); fvit.is_valid(); ++fvit)
			face.push_back(vertex_mapping.at(fvit.handle()));

		this->add_face(face);
	}
}

/**
 * \brief   Calculates the axis aligned bounding box.
 *
 * \param [in,out]  min The minimum.
 * \param [in,out]  max The maximum.
 *
 * \return  true if it succeeds, false if it fails.
 */
bool CMesh::calc_bounding_box(geometry::CMesh::Point &min, geometry::CMesh::Point &max) const
{
    bool first = true;

    for (CMesh::VertexIter vit = this->vertices_sbegin(); vit != this->vertices_end(); ++vit)
    {
        CMesh::Point point = this->point(vit.handle());
        if (geometry::isnan(geometry::convert3<geometry::Vec3, geometry::CMesh::Point>(point)))
        {
            continue;
        }
        
        if (first)
        {
            first = false;
            min = max = point;
        }
        else
        {
            min[0] = vpl::math::getMin<float>(min[0], point[0]);
            min[1] = vpl::math::getMin<float>(min[1], point[1]);
            min[2] = vpl::math::getMin<float>(min[2], point[2]);

            max[0] = vpl::math::getMax<float>(max[0], point[0]);
            max[1] = vpl::math::getMax<float>(max[1], point[1]);
            max[2] = vpl::math::getMax<float>(max[2], point[2]);
        }
    }

    return (!first);
}

bool CMesh::calc_average_vertex(geometry::CMesh::Point &average)
{
    if (this->n_vertices() == 0)
    {
        return false;
    }

    average = geometry::CMesh::Point(0.0, 0.0, 0.0);
    for (CMesh::VertexIter vit = this->vertices_sbegin(); vit != this->vertices_end(); ++vit)
    {
        average += this->point(vit.handle()) * (1.0 / this->n_vertices());
    }

    return true;
}

/**
 * Translates.
 *
 * \param   x   The x coordinate.
 * \param   y   The y coordinate.
 * \param   z   The z coordinate.
**/
void CMesh::translate( float x, float y, float z )
{
    CMesh::VertexIter v_it, v_end(vertices_end());
    for (v_it=vertices_sbegin(); v_it!=v_end; ++v_it)
    {
        Point p(point(v_it));
        p[0] += x; p[1] += y; p[2] += z;
        set_point(v_it, p);
    }
}

/**
 * Transforms.
 *
 * \param   tm  The transform matrix.
**/
void CMesh::transform( const Matrix &tm )
{
    CMesh::VertexIter v_it, v_end(vertices_end());
    for (v_it=vertices_sbegin(); v_it!=v_end; ++v_it)
    {
        // Transform to osg
        Vec3 tpoint(convert3<Vec3, CMesh::Point>(this->point(v_it.handle())));

        // Do transformation
        tpoint = tm * tpoint;

        set_point(v_it, convert3<CMesh::Point, Vec3>(tpoint));
    }

    // Normals should be updated. If normals are not requested yet this does nothing.
    update_normals();
}

/**
 * \brief   Calculates the oriented bounding box.
 *
 * \param [in,out]  tm  The transformation matrix .
 * \param [in,out]  min The minimum.
 * \param [in,out]  max The maximum.
 *
 * \return  true if it succeeds, false if it fails.
 */
bool CMesh::calc_oriented_bounding_box(Matrix &tm, Vec3 &extent)
{
	Point average;

	// Compute average vertex
	if(!calc_average_vertex(average))
		return false;

	// Get doubled parameters
	double	axx(average[0]*average[0]), 
			axy(average[0]*average[1]),
			axz(average[0]*average[2]),
			ayy(average[1]*average[1]),
			ayz(average[1]*average[2]),
			azz(average[2]*average[2]);

	// Compute covariance matrix parameters
	double cxx(0.0), cxy(0.0), cxz(0.0), cyy(0.0), cyz(0.0), czz(0.0);
	CMesh::VertexIter vit(this->vertices_begin()), vitEnd(this->vertices_end());
	for ( ; vit != vitEnd; ++vit)
	{
		// Get point reference
		const Point &p(this->point(vit.handle()));

		cxx += p[0]*p[0] - axx; 
		cxy += p[0]*p[1] - axy;
		cxz += p[0]*p[2] - axz;
		cyy += p[1]*p[1] - ayy;
		cyz += p[1]*p[2] - ayz;
		czz += p[2]*p[2] - azz;
	}

	// Build covariance matrix
	Matrix3x3 cm(construct3x3<Matrix3x3>(cxx, cxy, cxz,
                                         cxy, cyy, cyz,
                                         cxz, cyz, czz));
           
	// Compute bb
	return calc_obb_from_cm(cm, tm, extent);
}


bool CMesh::calc_oriented_bb_triangles(Matrix &tm, Vec3 &extent)
{
    CMesh::Point tsides[3], mu(0.0, 0.0, 0.0);

    double am(0.0);

    // Compute covariance matrix parameters
    double cxx(0.0), cxy(0.0), cxz(0.0), cyy(0.0), cyz(0.0), czz(0.0);

    // For all triangles
    CMesh::FaceIter fit(this->faces_sbegin()), fitEnd(this->faces_end());
    for(; fit != fitEnd; ++fit)
    {
        // Number of face vertices
        int nfv(0);

        // Face mean point
        Point mui(0.0, 0.0, 0.0);

        // For all face vertices
        CMesh::FaceVertexIter vit(this->fv_iter(fit));
        for(; vit; ++vit, ++nfv)
        {
            if(nfv < 3)
            {
                tsides[nfv] = this->point(vit.handle());
                mui += tsides[nfv];
            }
        }

        // Compute triangle area
        double ai(((tsides[1]-tsides[0]) % (tsides[2]-tsides[0])).length() * 0.5);
        am += ai;

        // Compute average point
        mui /= 3.0;
        mu += mui*ai;

        const CMesh::Point &p(tsides[0]), &q(tsides[1]), &r(tsides[2]);

        // Modify covariance matrix 
        cxx += ( 9.0*mui[0]*mui[0] + p[0]*p[0] + q[0]*q[0] + r[0]*r[0] )*(ai/12.0);
        cxy += ( 9.0*mui[0]*mui[1] + p[0]*p[1] + q[0]*q[1] + r[0]*r[1] )*(ai/12.0);
        cxz += ( 9.0*mui[0]*mui[2] + p[0]*p[2] + q[0]*q[2] + r[0]*r[2] )*(ai/12.0);
        cyy += ( 9.0*mui[1]*mui[1] + p[1]*p[1] + q[1]*q[1] + r[1]*r[1] )*(ai/12.0);
        cyz += ( 9.0*mui[1]*mui[2] + p[1]*p[2] + q[1]*q[2] + r[1]*r[2] )*(ai/12.0);
        czz += ( 9.0*mui[2]*mui[2] + p[2]*p[2] + q[2]*q[2] + r[2]*r[2] )*(ai/12.0);
    }

    // divide out the am fraction from the average position and covariance terms
    mu /= am;
    cxx /= am; cxy /= am; cxz /= am; cyy /= am; cyz /= am; czz /= am;

    // now subtract off the E[x]*E[x], E[x]*E[y], ... terms
    cxx -= mu[0]*mu[0]; cxy -= mu[0]*mu[1]; cxz -= mu[0]*mu[2];
    cyy -= mu[1]*mu[1]; cyz -= mu[1]*mu[2]; czz -= mu[2]*mu[2];

    // Build covariance matrix
    Matrix3x3 cm(construct3x3<Matrix3x3>(cxx, cxy, cxz,
                                         cxy, cyy, cyz,
                                         cxz, cyz, czz));

    // Compute bb
    return calc_obb_from_cm(cm, tm, extent);
}


/**
 * \brief   Calculates the oriented bounding box from covariance matrix.
 * 			Based on:
 * 			http://jamesgregson.blogspot.cz/2011/03/latex-test.html
 *
 * \param   cm          The input covariance matrix.
 * \param [in,out]  tm  The output matrix to transform aligned bb.
 * \param [in,out]  min The minimum of aligned bb.
 * \param [in,out]  max The maximum of aligned bb.
 *
 * \return  true if it succeeds, false if it fails.
 */
bool CMesh::calc_obb_from_cm(Matrix3x3 &cm, Matrix &tm, Vec3 &extent)
{
	// Eigenvalues output
	Vec3 ev;

	// Compute eigen values and vectors
	vpl::math::eig(cm, ev);

	// find the right, up and forward vectors from the eigenvectors
	Vec3 r( cm(0,0), cm(1,0), cm(2,0) );
	Vec3 u( cm(0,1), cm(1,1), cm(2,1) );
	Vec3 f( cm(0,2), cm(1,2), cm(2,2) );
	r.normalize(); u.normalize(), f.normalize();

	// set the rotation matrix using the eigven vectors
    tm.set(r[0], r[1], r[2], 0.0,
           u[0], u[1], u[2], 0.0,
           f[0], f[1], f[2], 0.0,
            0.0,  0.0,  0.0, 1.0);

	// now build the bounding box extents in the rotated frame
	Vec3 minim(1e10, 1e10, 1e10), maxim(-1e10, -1e10, -1e10);
	CMesh::VertexIter vit(this->vertices_begin()), vitEnd(this->vertices_end());
	for ( ; vit != vitEnd; ++vit)
	{
		// Get point reference
		const Point &p(this->point(vit.handle()));
		const Vec3 op(p[0], p[1], p[2]);

		// Compute transformed point
		Vec3 pp(r*op, u*op, f*op);

		// Get minimum and maximum
		for(int i = 0; i < 3; ++i)
		{
			minim[i] = vpl::math::getMin(pp[i], minim[i]);
            maxim[i] = vpl::math::getMax(pp[i], maxim[i]);
		}
	}

	// The center of the OBB is the average of the minimum and maximum
	Vec3 center((maxim+minim)*geometry::Scalar(0.5));

	// Modify transformation matrix
	tm.setTrans(center[0], center[1], center[2]);

	// the extents is half of the difference between the minimum and maximum
	extent = (maxim-minim)*geometry::Scalar(0.5);

	return true;
}

int ccw_tri_tri_intersection_2d(OpenMesh::Vec2f p1, OpenMesh::Vec2f q1, OpenMesh::Vec2f r1,
    OpenMesh::Vec2f p2, OpenMesh::Vec2f q2, OpenMesh::Vec2f r2);

int tri_tri_overlap_test_3d(CMesh::Point p1, CMesh::Point q1, CMesh::Point r1,
    CMesh::Point p2, CMesh::Point q2, CMesh::Point r2);

int tri_tri_overlap_test_2d(OpenMesh::Vec2f p1, OpenMesh::Vec2f q1, OpenMesh::Vec2f r1,
    OpenMesh::Vec2f p2, OpenMesh::Vec2f q2, OpenMesh::Vec2f r2);

int coplanar_tri_tri3d(CMesh::Point  p1, CMesh::Point  q1, CMesh::Point  r1,
    CMesh::Point  p2, CMesh::Point  q2, CMesh::Point  r2,
    CMesh::Normal  N1, CMesh::Normal  N2);

#define ORIENT_2D(a, b, c) ((a[0] - c[0]) * (b[1] - c[1]) - (a[1] - c[1]) * (b[0] - c[0]))

#define CHECK_MIN_MAX(p1,q1,r1,p2,q2,r2) \
{ \
    v1 = p2 -q1; \
    v2 = p1 -q1; \
    N1 = OpenMesh::cross(v1,v2); \
    v1 = q2 -q1; \
    if (OpenMesh::dot(v1,N1) > 0.0f) \
    { \
        return 0; \
    } \
    v1 = p2 - p1; \
    v2 = r1 - p1; \
    N1 = OpenMesh::cross(v1,v2); \
    v1 = r2 - p1; \
    if (OpenMesh::dot(v1,N1) > 0.0f) \
    { \
        return 0; \
    } \
    else \
    { \
        return 1; \
    } \
}

#define TRI_TRI_3D(p1,q1,r1,p2,q2,r2,dp2,dq2,dr2) \
{ \
    if (dp2 > 0.0f) \
    { \
        if (dq2 > 0.0f) CHECK_MIN_MAX(p1, r1, q1, r2, p2, q2) \
        else if (dr2 > 0.0f) CHECK_MIN_MAX(p1, r1, q1, q2, r2, p2) \
        else CHECK_MIN_MAX(p1, q1, r1, p2, q2, r2) \
    } \
    else if (dp2 < 0.0f) \
    { \
        if (dq2 < 0.0f) CHECK_MIN_MAX(p1, q1, r1, r2, p2, q2) \
        else if (dr2 < 0.0f) CHECK_MIN_MAX(p1, q1, r1, q2, r2, p2) \
        else CHECK_MIN_MAX(p1, r1, q1, p2, q2, r2) \
    } \
    else \
    { \
        if (dq2 < 0.0f) \
        { \
            if (dr2 >= 0.0f) CHECK_MIN_MAX(p1, r1, q1, q2, r2, p2) \
            else CHECK_MIN_MAX(p1, q1, r1, p2, q2, r2) \
        } \
        else if (dq2 > 0.0f) \
        { \
            if (dr2 > 0.0f) CHECK_MIN_MAX(p1, r1, q1, p2, q2, r2) \
            else CHECK_MIN_MAX(p1, q1, r1, q2, r2, p2) \
        } \
        else \
        { \
            if (dr2 > 0.0f) CHECK_MIN_MAX(p1, q1, r1, r2, p2, q2) \
            else if (dr2 < 0.0f) CHECK_MIN_MAX(p1, r1, q1, r2, p2, q2) \
            else return coplanar_tri_tri3d(p1, q1, r1, p2, q2, r2, N1, N2); \
        } \
    } \
}

#define INTERSECTION_TEST_VERTEX(P1, Q1, R1, P2, Q2, R2) {\
  if (ORIENT_2D(R2,P2,Q1) >= 0.0f)\
    if (ORIENT_2D(R2,Q2,Q1) <= 0.0f)\
      if (ORIENT_2D(P1,P2,Q1) > 0.0f) {\
  if (ORIENT_2D(P1,Q2,Q1) <= 0.0f) return 1; \
  else return 0;} else {\
  if (ORIENT_2D(P1,P2,R1) >= 0.0f)\
    if (ORIENT_2D(Q1,R1,P2) >= 0.0f) return 1; \
    else return 0;\
  else return 0;}\
    else \
      if (ORIENT_2D(P1,Q2,Q1) <= 0.0f)\
  if (ORIENT_2D(R2,Q2,R1) <= 0.0f)\
    if (ORIENT_2D(Q1,R1,Q2) >= 0.0f) return 1; \
    else return 0;\
  else return 0;\
      else return 0;\
  else\
    if (ORIENT_2D(R2,P2,R1) >= 0.0f) \
      if (ORIENT_2D(Q1,R1,R2) >= 0.0f)\
  if (ORIENT_2D(P1,P2,R1) >= 0.0f) return 1;\
  else return 0;\
      else \
  if (ORIENT_2D(Q1,R1,Q2) >= 0.0f) {\
    if (ORIENT_2D(R2,R1,Q2) >= 0.0f) return 1; \
    else return 0; }\
  else return 0; \
    else  return 0; \
 };

#define INTERSECTION_TEST_EDGE(P1, Q1, R1, P2, Q2, R2) { \
  if (ORIENT_2D(R2,P2,Q1) >= 0.0f) {\
    if (ORIENT_2D(P1,P2,Q1) >= 0.0f) { \
        if (ORIENT_2D(P1,Q1,R2) >= 0.0f) return 1; \
        else return 0;} else { \
      if (ORIENT_2D(Q1,R1,P2) >= 0.0f){ \
  if (ORIENT_2D(R1,P1,P2) >= 0.0f) return 1; else return 0;} \
      else return 0; } \
  } else {\
    if (ORIENT_2D(R2,P2,R1) >= 0.0f) {\
      if (ORIENT_2D(P1,P2,R1) >= 0.0f) {\
  if (ORIENT_2D(P1,R1,R2) >= 0.0f) return 1;  \
  else {\
    if (ORIENT_2D(Q1,R1,R2) >= 0.0f) return 1; else return 0;}}\
      else  return 0; }\
    else return 0; }}

int tri_tri_overlap_test_2d(OpenMesh::Vec2f p1, OpenMesh::Vec2f q1, OpenMesh::Vec2f r1,
                            OpenMesh::Vec2f p2, OpenMesh::Vec2f q2, OpenMesh::Vec2f r2)
{
    if (ORIENT_2D(p1, q1, r1) < 0.0f)
        if (ORIENT_2D(p2, q2, r2) < 0.0f)
            return ccw_tri_tri_intersection_2d(p1, r1, q1, p2, r2, q2);
        else
            return ccw_tri_tri_intersection_2d(p1, r1, q1, p2, q2, r2);
    else
        if (ORIENT_2D(p2, q2, r2) < 0.0f)
            return ccw_tri_tri_intersection_2d(p1, q1, r1, p2, r2, q2);
        else
            return ccw_tri_tri_intersection_2d(p1, q1, r1, p2, q2, r2);

}

int coplanar_tri_tri3d(CMesh::Point  p1, CMesh::Point  q1, CMesh::Point  r1,
                       CMesh::Point  p2, CMesh::Point  q2, CMesh::Point  r2,
                       CMesh::Normal  N1, CMesh::Normal  N2)
{

    OpenMesh::Vec2f P1, Q1, R1;
    OpenMesh::Vec2f P2, Q2, R2;

    CMesh::Scalar n_x, n_y, n_z;

    n_x = ((N1[0]<0) ? -N1[0] : N1[0]);
    n_y = ((N1[1]<0) ? -N1[1] : N1[1]);
    n_z = ((N1[2]<0) ? -N1[2] : N1[2]);


    /* Projection of the triangles in 3D onto 2D such that the area of
    the projection is maximized. */


    if ((n_x > n_z) && (n_x >= n_y)) {
        // Project onto plane YZ

        P1[0] = q1[2]; P1[1] = q1[1];
        Q1[0] = p1[2]; Q1[1] = p1[1];
        R1[0] = r1[2]; R1[1] = r1[1];

        P2[0] = q2[2]; P2[1] = q2[1];
        Q2[0] = p2[2]; Q2[1] = p2[1];
        R2[0] = r2[2]; R2[1] = r2[1];

    }
    else if ((n_y > n_z) && (n_y >= n_x)) {
        // Project onto plane XZ

        P1[0] = q1[0]; P1[1] = q1[2];
        Q1[0] = p1[0]; Q1[1] = p1[2];
        R1[0] = r1[0]; R1[1] = r1[2];

        P2[0] = q2[0]; P2[1] = q2[2];
        Q2[0] = p2[0]; Q2[1] = p2[2];
        R2[0] = r2[0]; R2[1] = r2[2];

    }
    else {
        // Project onto plane XY

        P1[0] = p1[0]; P1[1] = p1[1];
        Q1[0] = q1[0]; Q1[1] = q1[1];
        R1[0] = r1[0]; R1[1] = r1[1];

        P2[0] = p2[0]; P2[1] = p2[1];
        Q2[0] = q2[0]; Q2[1] = q2[1];
        R2[0] = r2[0]; R2[1] = r2[1];
    }

    return tri_tri_overlap_test_2d(P1, Q1, R1, P2, Q2, R2);
}

/*
*
*  Three-dimensional Triangle-Triangle Overlap Test
*
*/
int tri_tri_overlap_test_3d(CMesh::Point p1, CMesh::Point q1, CMesh::Point r1,
                            CMesh::Point p2, CMesh::Point q2, CMesh::Point r2)
{
    CMesh::Scalar dp1, dq1, dr1, dp2, dq2, dr2;
    OpenMesh::Vec3f v1, v2;
    CMesh::Normal N1, N2;

    /* Compute distance signs  of p1, q1 and r1 to the plane of
    triangle(p2,q2,r2) */

    v1 = p2 - r2;
    v2 = q2 - r2;
    N2 = OpenMesh::cross(v1, v2);

    v1 = p1 - r2;
    dp1 = OpenMesh::dot(v1, N2);

    v1 = q1 - r2;
    dq1 = OpenMesh::dot(v1, N2);

    v1 = r1 - r2;
    dr1 = OpenMesh::dot(v1, N2);

    if (((dp1 * dq1) > 0.0f) && ((dp1 * dr1) > 0.0f))  return 0;

    /* Compute distance signs  of p2, q2 and r2 to the plane of
    triangle(p1,q1,r1) */


    v1 = q1 - p1;
    v2 = r1 - p1;
    N1 = OpenMesh::cross(v1, v2);

    v1 = p2 - r1;
    dp2 = OpenMesh::dot(v1, N1);
    v1 = q2 - r1;
    dq2 = OpenMesh::dot(v1, N1);
    v1 = r2 - r1;
    dr2 = OpenMesh::dot(v1, N1);

    if (((dp2 * dq2) > 0.0f) && ((dp2 * dr2) > 0.0f)) return 0;

    /* Permutation in a canonical form of T1's vertices */


    if (dp1 > 0.0f) {
        if (dq1 > 0.0f) TRI_TRI_3D(r1, p1, q1, p2, r2, q2, dp2, dr2, dq2)
        else if (dr1 > 0.0f) TRI_TRI_3D(q1, r1, p1, p2, r2, q2, dp2, dr2, dq2)
        else TRI_TRI_3D(p1, q1, r1, p2, q2, r2, dp2, dq2, dr2)
    }
    else if (dp1 < 0.0f) {
        if (dq1 < 0.0f) TRI_TRI_3D(r1, p1, q1, p2, q2, r2, dp2, dq2, dr2)
        else if (dr1 < 0.0f) TRI_TRI_3D(q1, r1, p1, p2, q2, r2, dp2, dq2, dr2)
        else TRI_TRI_3D(p1, q1, r1, p2, r2, q2, dp2, dr2, dq2)
    }
    else {
        if (dq1 < 0.0f) {
            if (dr1 >= 0.0f) TRI_TRI_3D(q1, r1, p1, p2, r2, q2, dp2, dr2, dq2)
            else TRI_TRI_3D(p1, q1, r1, p2, q2, r2, dp2, dq2, dr2)
        }
        else if (dq1 > 0.0f) {
            if (dr1 > 0.0f) TRI_TRI_3D(p1, q1, r1, p2, r2, q2, dp2, dr2, dq2)
            else TRI_TRI_3D(q1, r1, p1, p2, q2, r2, dp2, dq2, dr2)
        }
        else {
            if (dr1 > 0.0f) TRI_TRI_3D(r1, p1, q1, p2, q2, r2, dp2, dq2, dr2)
            else if (dr1 < 0.0f) TRI_TRI_3D(r1, p1, q1, p2, r2, q2, dp2, dr2, dq2)
            else return coplanar_tri_tri3d(p1, q1, r1, p2, q2, r2, N1, N2);
        }
    }
}

int ccw_tri_tri_intersection_2d(OpenMesh::Vec2f p1, OpenMesh::Vec2f q1, OpenMesh::Vec2f r1,
    OpenMesh::Vec2f p2, OpenMesh::Vec2f q2, OpenMesh::Vec2f r2)
{
    if (ORIENT_2D(p2, q2, p1) >= 0.0f)
    {
        if (ORIENT_2D(q2, r2, p1) >= 0.0f)
        {
            if (ORIENT_2D(r2, p2, p1) >= 0.0f) return 1;
            else INTERSECTION_TEST_EDGE(p1, q1, r1, p2, q2, r2)
        }
        else
        {
            if (ORIENT_2D(r2, p2, p1) >= 0.0f)
                INTERSECTION_TEST_EDGE(p1, q1, r1, r2, p2, q2)
            else INTERSECTION_TEST_VERTEX(p1, q1, r1, p2, q2, r2)
        }
    }
    else
    {
        if (ORIENT_2D(q2, r2, p1) >= 0.0f)
        {
            if (ORIENT_2D(r2, p2, p1) >= 0.0f)
                INTERSECTION_TEST_EDGE(p1, q1, r1, q2, r2, p2)
            else  INTERSECTION_TEST_VERTEX(p1, q1, r1, q2, r2, p2)
        }
        else INTERSECTION_TEST_VERTEX(p1, q1, r1, r2, p2, q2)
    }
}

bool CMesh::guigueDevillersTriTriTest(CMesh::FaceHandle f1, CMesh::FaceHandle f2)
{
    CMesh::FaceVertexIter fv_it1(this->cfv_iter(f1));
    CMesh::Point p0 = this->point(*fv_it1);
    ++fv_it1;
    CMesh::Point p1 = this->point(*fv_it1);
    ++fv_it1;
    CMesh::Point p2 = this->point(*fv_it1);
    CMesh::Normal n1 = this->normal(f1);

    CMesh::FaceVertexIter fv_it2(this->cfv_iter(f2));
    CMesh::Point q0 = this->point(*fv_it2);
    ++fv_it2;
    CMesh::Point q1 = this->point(*fv_it2);
    ++fv_it2;
    CMesh::Point q2 = this->point(*fv_it2);
    CMesh::Normal n2 = this->normal(f2);

    return (tri_tri_overlap_test_3d(p0, p1, p2, q0, q1, q2) == 1);
}

void CMesh::safe_update_normals()
{
    // Face normals are required to compute the vertex and the halfedge normals
    if (has_face_normals())
    {
        safe_update_face_normals();

        if (has_vertex_normals())
        {
            safe_update_vertex_normals();
        }

        if (has_halfedge_normals())
        {
            safe_update_halfedge_normals();
        }
    }
}

void CMesh::safe_update_face_normals()
{
    FaceIter f_it(faces_sbegin()), f_end(faces_end());

    for (; f_it != f_end; ++f_it)
    {
        if (this->status(*f_it).deleted())
        {
            continue;
        }
        this->set_normal(*f_it, calc_face_normal(*f_it));
    }
}

void CMesh::safe_update_halfedge_normals(const double _feature_angle)
{
    HalfedgeIter h_it(halfedges_begin()), h_end(halfedges_end());

    for (; h_it != h_end; ++h_it)
    {
        if (this->status(*h_it).deleted())
        {
            continue;
        }
        this->set_normal(*h_it, calc_halfedge_normal(*h_it, _feature_angle));
    }
}

void CMesh::safe_update_vertex_normals()
{
    VertexIter  v_it(vertices_begin()), v_end(vertices_end());

    for (; v_it != v_end; ++v_it)
    {
        if (this->status(*v_it).deleted())
        {
            continue;
        }
        this->set_normal(*v_it, calc_vertex_normal(*v_it));
    }
}

} // namespace data
