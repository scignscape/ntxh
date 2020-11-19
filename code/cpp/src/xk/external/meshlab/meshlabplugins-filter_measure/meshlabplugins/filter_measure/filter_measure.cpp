/****************************************************************************
* MeshLab                                                           o o     *
* A versatile mesh processing toolbox                             o     o   *
*                                                                _   O  _   *
* Copyright(C) 2005                                                \/)\/    *
* Visual Computing Lab                                            /\/|      *
* ISTI - Italian National Research Council                           |      *
*                                                                    \      *
* All rights reserved.                                                      *
*                                                                           *
* This program is free software; you can redistribute it and/or modify      *   
* it under the terms of the GNU General Public License as published by      *
* the Free Software Foundation; either version 2 of the License, or         *
* (at your option) any later version.                                       *
*                                                                           *
* This program is distributed in the hope that it will be useful,           *
* but WITHOUT ANY WARRANTY; without even the implied warranty of            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
* GNU General Public License (http://www.gnu.org/licenses/gpl.txt)          *
* for more details.                                                         *
*                                                                           *
****************************************************************************/

#include "filter_measure.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <vcg/complex/algorithms/clean.h>
#include <vcg/complex/algorithms/inertia.h>
#include <vcg/complex/algorithms/stat.h>

#include <vcg/complex/algorithms/update/selection.h>
#include <vcg/complex/append.h>
#include <vcg/simplex/face/pos.h>
#include <vcg/complex/algorithms/bitquad_support.h>
#include <vcg/complex/algorithms/mesh_to_matrix.h>
#include <vcg/complex/algorithms/bitquad_optimization.h>

using namespace std;
using namespace vcg;

FilterMeasurePlugin::FilterMeasurePlugin()
{ 
	typeList << COMPUTE_TOPOLOGICAL_MEASURES
			 << COMPUTE_TOPOLOGICAL_MEASURES_QUAD_MESHES
			 << COMPUTE_GEOMETRIC_MEASURES
			 << COMPUTE_AREA_PERIMETER_SELECTION
			 << PER_VERTEX_QUALITY_STAT
			 << PER_FACE_QUALITY_STAT
			 << PER_VERTEX_QUALITY_HISTOGRAM
			 << PER_FACE_QUALITY_HISTOGRAM;

	for(FilterIDType tt : types())
		actionList << new QAction(filterName(tt), this);
}

QString FilterMeasurePlugin::pluginName() const
{
	return "FilterMeasure";
}

QString FilterMeasurePlugin::filterName(FilterIDType filterId) const
{
	switch (filterId) {
	case COMPUTE_TOPOLOGICAL_MEASURES:
		return "Compute Topological Measures";
		break;
	case COMPUTE_TOPOLOGICAL_MEASURES_QUAD_MESHES:
		return "Compute Topological Measures for Quad Meshes";
		break;
	case COMPUTE_GEOMETRIC_MEASURES:
		return "Compute Geometric Measures";
		break;
	case COMPUTE_AREA_PERIMETER_SELECTION:
		return "Compute Area/Perimeter of selection";
		break;
	case PER_VERTEX_QUALITY_STAT:
		return "Per Vertex Quality Stat";
		break;
	case PER_FACE_QUALITY_STAT:
		return "Per Face Quality Stat";
		break;
	case PER_VERTEX_QUALITY_HISTOGRAM:
		return "Per Vertex Quality Histogram";
		break;
	case PER_FACE_QUALITY_HISTOGRAM:
		return "Per Face Quality Histogram";
		break;
	default:
		assert(0);
		return "";
	}
}

 QString FilterMeasurePlugin::filterInfo(FilterIDType filterId) const
{
	switch (filterId) {
	case COMPUTE_TOPOLOGICAL_MEASURES:
		return "Compute a set of topological measures over a mesh.";
		break;
	case COMPUTE_TOPOLOGICAL_MEASURES_QUAD_MESHES:
		return "Compute a set of topological measures over a quad mesh.";
		break;
	case COMPUTE_GEOMETRIC_MEASURES:
		return "Compute a set of geometric measures of a mesh/pointcloud. Bounding box extents and diagonal, principal axis, thin shell barycenter (mesh only), vertex barycenter and quality-weighted barycenter (pointcloud only), surface area (mesh only), volume (closed mesh) and Inertia tensor Matrix (closed mesh). Open the layer dialog to see the results.";
		break;
	case COMPUTE_AREA_PERIMETER_SELECTION:
		return "Compute area and perimeter of the FACE selection. Open the layer dialog to see the results.";
		break;
	case PER_VERTEX_QUALITY_STAT:
		return "Compute some aggregate statistics over the per vertex quality, like Min, Max, Average, StdDev and Variance.";
		break;
	case PER_FACE_QUALITY_STAT:
		return "Compute some aggregate statistics over the per vertex quality, like Min, Max, Average, StdDev and Variance.";
		break;
	case PER_VERTEX_QUALITY_HISTOGRAM:
		return "Compute an histogram of the values of the per-vertex quality. It can be useful to evaluate the distribution of the quality value over the surface. It can be discrete (e.g. based on vertex count or area weighted).";
		break;
	case PER_FACE_QUALITY_HISTOGRAM:
		return "Compute an histogram of the values of the per-face quality.";
		break;
	default:
		assert(0);
		return "";
	}
}

FilterMeasurePlugin::FilterClass FilterMeasurePlugin::getClass(const QAction *) const
{
	return FilterPluginInterface::Measure;
}

FilterPluginInterface::FILTER_ARITY FilterMeasurePlugin::filterArity(const QAction*) const
{
	return SINGLE_MESH;
}

int FilterMeasurePlugin::getPreConditions(const QAction* action) const
{
	switch (ID(action)) {
	case PER_VERTEX_QUALITY_STAT:
	case PER_VERTEX_QUALITY_HISTOGRAM:
		return MeshModel::MM_VERTQUALITY;
		break;
	case PER_FACE_QUALITY_STAT:
	case PER_FACE_QUALITY_HISTOGRAM:
		return  MeshModel::MM_FACEQUALITY;
		break;
	default:
		return  MeshModel::MM_NONE;
	}
}

void FilterMeasurePlugin::initParameterList(const QAction *action, MeshModel &m, RichParameterList & parlst)
{
	switch (ID(action)) {
	case PER_VERTEX_QUALITY_HISTOGRAM:
		parlst.addParam(RichFloat("HistMin", vcg::tri::Stat<CMeshO>::ComputePerVertexQualityMinMax(m.cm).first, "Hist Min", "The vertex are displaced of a vector whose norm is bounded by this value"));
		parlst.addParam(RichFloat("HistMax", vcg::tri::Stat<CMeshO>::ComputePerVertexQualityMinMax(m.cm).second, "Hist Max", "The vertex are displaced of a vector whose norm is bounded by this value"));
		parlst.addParam(RichBool("areaWeighted", false, "Area Weighted", "If false, the histogram will report the number of vertices with quality values falling in each bin of the histogram. If true each bin of the histogram will report the approximate area of the mesh with that range of values. Area is computed by assigning to each vertex one third of the area all the incident triangles."));
		parlst.addParam(RichInt("binNum", 20, "Bin number", "The number of bins of the histogram. E.g. the number of intervals in which the min..max range is subdivided into."));
		break;
	case PER_FACE_QUALITY_HISTOGRAM:
		parlst.addParam(RichFloat("HistMin", vcg::tri::Stat<CMeshO>::ComputePerFaceQualityMinMax(m.cm).first, "Hist Min", "The faces are displaced of a vector whose norm is bounded by this value"));
		parlst.addParam(RichFloat("HistMax", vcg::tri::Stat<CMeshO>::ComputePerFaceQualityMinMax(m.cm).second, "Hist Max", "The faces are displaced of a vector whose norm is bounded by this value"));
		parlst.addParam(RichBool("areaWeighted", false, "Area Weighted", "If false, the histogram will report the number of faces with quality values falling in each bin of the histogram. If true each bin of the histogram will report the approximate area of the mesh with that range of values."));
		parlst.addParam(RichInt("binNum", 20, "Bin number", "The number of bins of the histogram. E.g. the number of intervals in which the min..max range is subdivided into."));
		break;
	default:
		break;
	}
}

bool FilterMeasurePlugin::applyFilter(const QAction* filter, MeshDocument& md, std::map<std::string, QVariant>&, unsigned int& /*postConditionMask*/, const RichParameterList& parlst, vcg::CallBackPos*)
{
	switch (ID(filter)) {
	case COMPUTE_TOPOLOGICAL_MEASURES:
		return computeTopologicalMeasures(md);
		break;
	case COMPUTE_TOPOLOGICAL_MEASURES_QUAD_MESHES:
		return computeTopologicalMeasuresForQuadMeshes(md);
		break;
	case COMPUTE_GEOMETRIC_MEASURES:
		return computeGeometricMeasures(md);
		break;
	case COMPUTE_AREA_PERIMETER_SELECTION:
		return computeAreaPerimeterOfSelection(md);
		break;
	case PER_VERTEX_QUALITY_STAT:
		return perVertexQualityStat(md);
		break;
	case PER_FACE_QUALITY_STAT:
		return perFaceQualityStat(md);
		break;
	case PER_VERTEX_QUALITY_HISTOGRAM:
		return perVertexQualityHistogram(md, parlst.getFloat("HistMin"), parlst.getFloat("HistMax"), parlst.getInt("binNum"), parlst.getBool("areaWeighted"));
		break;
	case PER_FACE_QUALITY_HISTOGRAM:
		return perFaceQualityHostogram(md, parlst.getFloat("HistMin"), parlst.getFloat("HistMax"), parlst.getInt("binNum"), parlst.getBool("areaWeighted"));
		break;
	default:
		assert(0);
		return false;
	}
}

int FilterMeasurePlugin::postCondition(const QAction*) const
{
	return MeshModel::MM_NONE;
}

bool FilterMeasurePlugin::computeTopologicalMeasures(MeshDocument& md)
{
	CMeshO &m = md.mm()->cm;
	tri::Allocator<CMeshO>::CompactFaceVector(m);
	tri::Allocator<CMeshO>::CompactVertexVector(m);
	md.mm()->updateDataMask(MeshModel::MM_FACEFACETOPO);
	md.mm()->updateDataMask(MeshModel::MM_VERTFACETOPO);

	int edgeNonManifFFNum = tri::Clean<CMeshO>::CountNonManifoldEdgeFF(m, true);
	int faceEdgeManif = tri::UpdateSelection<CMeshO>::FaceCount(m);
	tri::UpdateSelection<CMeshO>::VertexClear(m);
	tri::UpdateSelection<CMeshO>::FaceClear(m);

	int vertManifNum = tri::Clean<CMeshO>::CountNonManifoldVertexFF(m, true);
	tri::UpdateSelection<CMeshO>::FaceFromVertexLoose(m);
	int faceVertManif = tri::UpdateSelection<CMeshO>::FaceCount(m);
	int edgeNum = 0, edgeBorderNum = 0, edgeNonManifNum = 0;
	tri::Clean<CMeshO>::CountEdgeNum(m, edgeNum, edgeBorderNum, edgeNonManifNum);
	assert(edgeNonManifFFNum == edgeNonManifNum);
	int holeNum;
	log("V: %6i E: %6i F:%6i", m.vn, edgeNum, m.fn);
	int unrefVertNum = tri::Clean<CMeshO>::CountUnreferencedVertex(m);
	log("Unreferenced Vertices %i", unrefVertNum);
	log("Boundary Edges %i", edgeBorderNum);

	int connectedComponentsNum = tri::Clean<CMeshO>::CountConnectedComponents(m);
	log("Mesh is composed by %i connected component(s)\n", connectedComponentsNum);

	if (edgeNonManifFFNum == 0 && vertManifNum == 0){
		log("Mesh is two-manifold ");
	}

	if (edgeNonManifFFNum != 0) log("Mesh has %i non two manifold edges and %i faces are incident on these edges\n", edgeNonManifFFNum, faceEdgeManif);
	if (vertManifNum != 0) log("Mesh has %i non two manifold vertices and %i faces are incident on these vertices\n", vertManifNum, faceVertManif);

	// For Manifold meshes compute some other stuff
	if (vertManifNum == 0 && edgeNonManifFFNum == 0) {
		holeNum = tri::Clean<CMeshO>::CountHoles(m);
		log("Mesh has %i holes", holeNum);

		int genus = tri::Clean<CMeshO>::MeshGenus(m.vn - unrefVertNum, edgeNum, m.fn, holeNum, connectedComponentsNum);
		log("Genus is %i", genus);
	}
	else {
		log("Mesh has a undefined number of holes (non 2-manifold mesh)");
		log("Genus is undefined (non 2-manifold mesh)");
	}

	return true;
}

bool FilterMeasurePlugin::computeTopologicalMeasuresForQuadMeshes(MeshDocument& md)
{
	CMeshO &m = md.mm()->cm;
	md.mm()->updateDataMask(MeshModel::MM_FACEFACETOPO);
	md.mm()->updateDataMask(MeshModel::MM_FACEQUALITY);

	if (!tri::Clean<CMeshO>::IsFFAdjacencyConsistent(m)) {
		this->errorMessage = "Error: mesh has a not consistent FF adjacency";
		return false;
	}
	if (!tri::Clean<CMeshO>::HasConsistentPerFaceFauxFlag(m)) {
		this->errorMessage = "QuadMesh problem: mesh has a not consistent FauxEdge tagging";
		return false;
	}

	int nQuads = tri::Clean<CMeshO>::CountBitQuads(m);
	int nTris = tri::Clean<CMeshO>::CountBitTris(m);
	int nPolys = tri::Clean<CMeshO>::CountBitPolygons(m);
	int nLargePolys = tri::Clean<CMeshO>::CountBitLargePolygons(m);
	if (nLargePolys>0) nQuads = 0;

	log("Mesh has %8i triangles \n", nTris);
	log("         %8i quads \n", nQuads);
	log("         %8i polygons \n", nPolys);
	log("         %8i large polygons (with internal faux vertices)", nLargePolys);

	if (!tri::Clean<CMeshO>::IsBitTriQuadOnly(m)) {
		this->errorMessage = "QuadMesh problem: the mesh is not TriQuadOnly";
		return false;
	}

	//
	//   i
	//
	//
	//   i+1     i+2
	tri::UpdateFlags<CMeshO>::FaceClearV(m);
	Distribution<float> AngleD; // angle distribution
	Distribution<float> RatioD; // ratio distribution
	tri::UpdateFlags<CMeshO>::FaceClearV(m);
	for (CMeshO::FaceIterator fi = m.face.begin(); fi != m.face.end(); ++fi)
	if (!fi->IsV()) {
		fi->SetV();
		// Collect the vertices
		Point3m qv[4];
		bool quadFound = false;
		for (int i = 0; i<3; ++i) {
			if ((*fi).IsF(i) && !(*fi).IsF((i + 1) % 3) && !(*fi).IsF((i + 2) % 3)) {
				qv[0] = fi->V0(i)->P(),
					qv[1] = fi->FFp(i)->V2(fi->FFi(i))->P(),
					qv[2] = fi->V1(i)->P(),
					qv[3] = fi->V2(i)->P();
				quadFound = true;
			}
		}

		if (!quadFound) {
			errorMessage = "QuadMesh problem: current mesh doesn't contain quads.";
			return false;
		}

		for (int i = 0; i<4; ++i)
			AngleD.Add(fabs(90 - math::ToDeg(Angle(qv[(i + 0) % 4] - qv[(i + 1) % 4], qv[(i + 2) % 4] - qv[(i + 1) % 4]))));
		float edgeLen[4];

		for (int i = 0; i<4; ++i)
			edgeLen[i] = Distance(qv[(i + 0) % 4], qv[(i + 1) % 4]);
		std::sort(edgeLen, edgeLen + 4);
		RatioD.Add(edgeLen[0] / edgeLen[3]);
	}

	log("Right Angle Discrepancy  Avg %4.3f Min %4.3f Max %4.3f StdDev %4.3f Percentile 0.05 %4.3f percentile 95 %4.3f",
		AngleD.Avg(), AngleD.Min(), AngleD.Max(), AngleD.StandardDeviation(), AngleD.Percentile(0.05f), AngleD.Percentile(0.95f));

	log("Quad Ratio   Avg %4.3f Min %4.3f Max %4.3f", RatioD.Avg(), RatioD.Min(), RatioD.Max());
	return true;
}

bool FilterMeasurePlugin::computeGeometricMeasures(MeshDocument& md)
{
	CMeshO &m = md.mm()->cm;
	bool watertight = false;
	bool pointcloud = false;

	// the mesh has to be correctly transformed
	if (m.Tr != Matrix44m::Identity()) {
		log("BEWARE: Measures are calculated considering the current transformation matrix");
		tri::UpdatePosition<CMeshO>::Matrix(m, m.Tr, true);
	}

	// bounding box
	log("Mesh Bounding Box Size %f  %f  %f", m.bbox.DimX(), m.bbox.DimY(), m.bbox.DimZ());
	log("Mesh Bounding Box Diag %f ", m.bbox.Diag());
	log("Mesh Bounding Box min %f  %f  %f", m.bbox.min[0], m.bbox.min[1], m.bbox.min[2]);
	log("Mesh Bounding Box max %f  %f  %f", m.bbox.max[0], m.bbox.max[1], m.bbox.max[2]);

	// is pointcloud?
	if ((m.fn == 0) && (m.vn != 0))
		pointcloud = true;

	if (pointcloud) {
		// cloud barycenter
		Point3m bc = tri::Stat<CMeshO>::ComputeCloudBarycenter(m, false);
		log("Pointcloud (vertex) barycenter  %9.6f  %9.6f  %9.6f", bc[0], bc[1], bc[2]);

		// if there is vertex quality, also provide weighted barycenter
		if (tri::HasPerVertexQuality(m))
		{
			bc = tri::Stat<CMeshO>::ComputeCloudBarycenter(m, true);
			log("Pointcloud (vertex) barycenter, weighted by verytex quality:");
			log("  %9.6f  %9.6f  %9.6f", bc[0], bc[1], bc[2]);
		}

		// principal axis
		Matrix33m PCA;
		PCA = computePrincipalAxisCloud(m);
		log("Principal Axes are :");
		log("    | %9.6f  %9.6f  %9.6f |", PCA[0][0], PCA[0][1], PCA[0][2]);
		log("    | %9.6f  %9.6f  %9.6f |", PCA[1][0], PCA[1][1], PCA[1][2]);
		log("    | %9.6f  %9.6f  %9.6f |", PCA[2][0], PCA[2][1], PCA[2][2]);
	}
	else {
		// area
		float Area = tri::Stat<CMeshO>::ComputeMeshArea(m);
		log("Mesh Surface Area is %f", Area);

		// edges
		Distribution<float> eDist;
		tri::Stat<CMeshO>::ComputeFaceEdgeLengthDistribution(m, eDist, false);
		log("Mesh Total Len of %i Edges is %f Avg Len %f", int(eDist.Cnt()), eDist.Sum(), eDist.Avg());
		tri::Stat<CMeshO>::ComputeFaceEdgeLengthDistribution(m, eDist, true);
		log("Mesh Total Len of %i Edges is %f Avg Len %f (including faux edges))", int(eDist.Cnt()), eDist.Sum(), eDist.Avg());

		// Thin shell barycenter
		Point3m bc = tri::Stat<CMeshO>::ComputeShellBarycenter(m);
		log("Thin shell (faces) barycenter:  %9.6f  %9.6f  %9.6f", bc[0], bc[1], bc[2]);

		// cloud barycenter
		bc = tri::Stat<CMeshO>::ComputeCloudBarycenter(m, false);
		log("Vertices barycenter  %9.6f  %9.6f  %9.6f", bc[0], bc[1], bc[2]);

		// is watertight?
		int edgeNum = 0, edgeBorderNum = 0, edgeNonManifNum = 0;
		tri::Clean<CMeshO>::CountEdgeNum(m, edgeNum, edgeBorderNum, edgeNonManifNum);
		watertight = (edgeBorderNum == 0) && (edgeNonManifNum == 0);
		if (watertight) {
			tri::Inertia<CMeshO> I(m);

			// volume
			float Volume = I.Mass();
			log("Mesh Volume  is %f", Volume);

			// center of mass
			log("Center of Mass  is %f %f %f", I.CenterOfMass()[0], I.CenterOfMass()[1], I.CenterOfMass()[2]);

			// inertia tensor
			Matrix33m IT;
			I.InertiaTensor(IT);
			log("Inertia Tensor is :");
			log("    | %9.6f  %9.6f  %9.6f |", IT[0][0], IT[0][1], IT[0][2]);
			log("    | %9.6f  %9.6f  %9.6f |", IT[1][0], IT[1][1], IT[1][2]);
			log("    | %9.6f  %9.6f  %9.6f |", IT[2][0], IT[2][1], IT[2][2]);

			// principal axis
			Matrix33m PCA;
			Point3m pcav;
			I.InertiaTensorEigen(PCA, pcav);
			log("Principal axes are :");
			log("    | %9.6f  %9.6f  %9.6f |", PCA[0][0], PCA[0][1], PCA[0][2]);
			log("    | %9.6f  %9.6f  %9.6f |", PCA[1][0], PCA[1][1], PCA[1][2]);
			log("    | %9.6f  %9.6f  %9.6f |", PCA[2][0], PCA[2][1], PCA[2][2]);

			log("axis momenta are :");
			log("    | %9.6f  %9.6f  %9.6f |", pcav[0], pcav[1], pcav[2]);

		}
		else {
			log("Mesh is not 'watertight', no information on volume, barycenter and inertia tensor.");

			// principal axis
			Matrix33m PCA;
			PCA = computePrincipalAxisCloud(m);
			log("Principal axes are :");
			log("    | %9.6f  %9.6f  %9.6f |", PCA[0][0], PCA[0][1], PCA[0][2]);
			log("    | %9.6f  %9.6f  %9.6f |", PCA[1][0], PCA[1][1], PCA[1][2]);
			log("    | %9.6f  %9.6f  %9.6f |", PCA[2][0], PCA[2][1], PCA[2][2]);
		}

	}

	// the mesh has to return to its original position
	if (m.Tr != Matrix44m::Identity())
		tri::UpdatePosition<CMeshO>::Matrix(m, Inverse(m.Tr), true);

	return true;
}

bool FilterMeasurePlugin::computeAreaPerimeterOfSelection(MeshDocument& md)
{
	CMeshO &m = md.mm()->cm;
	if (m.sfn == 0) {// no face selected, fail
		errorMessage = "Cannot apply: there is no face selection";
		log("Cannot apply: there is no face selection");
		return false;
	}

	log("Selection is %i triangles", m.sfn);
	if (m.Tr != Matrix44m::Identity())
		log("BEWARE: Area and Perimeter are calculated considering the current transformation matrix");

	double fArea = 0.0;
	double sArea=0;
	for (CMeshO::FaceIterator fi = m.face.begin(); fi != m.face.end(); ++fi)
	if (!(*fi).IsD())
	if ((*fi).IsS()) {
		// this line calculates the doublearea, I took the code from Triangle3.h (DoubleArea) and modified to use transformation
		fArea = (((m.Tr * (*fi).cP(1)) - (m.Tr * (*fi).cP(0))) ^ ((m.Tr * (*fi).cP(2)) - (m.Tr * (*fi).cP(0)))).Norm();
		sArea += fArea / 2.0;
	}
	log("Selection Surface Area is %f", sArea);

	int ePerimeter = 0;
	double sPerimeter = 0.0;
	md.mm()->updateDataMask(MeshModel::MM_FACEFACETOPO);
	for (CMeshO::FaceIterator fi = m.face.begin(); fi != m.face.end(); ++fi)
	if (!(*fi).IsD())
	if ((*fi).IsS()) {
		for (int ei = 0; ei < 3; ei++) {
			CMeshO::FacePointer adjf = (*fi).FFp(ei);

			if (adjf == &(*fi) || !(adjf->IsS())) {
				ePerimeter += 1;
				sPerimeter += ((m.Tr * (*fi).V(ei)->P()) - (m.Tr * (*fi).V((ei + 1) % 3)->P())).Norm();
			}
		}
	}

	log("Selection border is %i edges", ePerimeter);
	log("Perimeter is %f", sPerimeter);

	return true;
}

bool FilterMeasurePlugin::perVertexQualityStat(MeshDocument& md)
{
	CMeshO &m = md.mm()->cm;
	Distribution<float> DD;
	tri::Stat<CMeshO>::ComputePerVertexQualityDistribution(m, DD, false);

	log("   Min %f Max %f", DD.Min(), DD.Max());
	log("   Avg %f Med %f", DD.Avg(), DD.Percentile(0.5f));
	log("   StdDev     %f", DD.StandardDeviation());
	log("   Variance   %f", DD.Variance());
	return true;
}

bool FilterMeasurePlugin::perFaceQualityStat(MeshDocument& md)
{
	CMeshO &m = md.mm()->cm;
	Distribution<float> DD;
	tri::Stat<CMeshO>::ComputePerFaceQualityDistribution(m, DD, false);

	log("   Min %f Max %f", DD.Min(), DD.Max());
	log("   Avg %f Med %f", DD.Avg(), DD.Percentile(0.5f));
	log("   StdDev     %f", DD.StandardDeviation());
	log("   Variance   %f", DD.Variance());
	return true;
}

bool FilterMeasurePlugin::perVertexQualityHistogram(MeshDocument& md, float RangeMin, float RangeMax, int binNum, bool areaFlag)
{
	CMeshO &m = md.mm()->cm;
	tri::Allocator<CMeshO>::CompactEveryVector(m);

	Histogramf H;
	H.SetRange(RangeMin, RangeMax, binNum);
	vector<Scalarm> aVec(m.vn, 1.0);
	if (areaFlag)
		tri::MeshToMatrix<CMeshO>::PerVertexArea(m, aVec);

	for (int i = 0; i<m.vn; ++i)
		H.Add(m.vert[i].Q(), aVec[i]);

	if (areaFlag) {
		log("(         -inf..%15.7f) : %15.7f", RangeMin, H.BinCountInd(0));
		for (int i = 1; i <= binNum; ++i)
			log("[%15.7f..%15.7f) : %15.7f", H.BinLowerBound(i), H.BinUpperBound(i), H.BinCountInd(i));
		log("[%15.7f..             +inf) : %15.7f", RangeMax, H.BinCountInd(binNum + 1));
	}
	else {
		log("(         -inf..%15.7f) : %4.0f", RangeMin, H.BinCountInd(0));
		for (int i = 1; i <= binNum; ++i)
			log("[%15.7f..%15.7f) : %4.0f", H.BinLowerBound(i), H.BinUpperBound(i), H.BinCountInd(i));
		log("[%15.7f..             +inf) : %4.0f", RangeMax, H.BinCountInd(binNum + 1));
	}

	aVec = vector<Scalarm>(m.vn, 1.0);
	if (areaFlag)
		tri::MeshToMatrix<CMeshO>::PerVertexArea(m, aVec);

	for (int i = 0; i<m.vn; ++i)
		H.Add(m.vert[i].Q(), aVec[i]);
	if (areaFlag) {
		log("(         -inf..%15.7f) : %15.7f", RangeMin, H.BinCountInd(0));
		for (int i = 1; i <= binNum; ++i)
			log("[%15.7f..%15.7f) : %15.7f", H.BinLowerBound(i), H.BinUpperBound(i), H.BinCountInd(i));
		log("[%15.7f..             +inf) : %15.7f", RangeMax, H.BinCountInd(binNum + 1));
	}
	else {
		log("(         -inf..%15.7f) : %4.0f", RangeMin, H.BinCountInd(0));
		for (int i = 1; i <= binNum; ++i)
			log("[%15.7f..%15.7f) : %4.0f", H.BinLowerBound(i), H.BinUpperBound(i), H.BinCountInd(i));
		log("[%15.7f..             +inf) : %4.0f", RangeMax, H.BinCountInd(binNum + 1));
	}
	return true;
}

bool FilterMeasurePlugin::perFaceQualityHostogram(MeshDocument& md, float RangeMin, float RangeMax, int binNum, bool areaFlag)
{
	CMeshO &m = md.mm()->cm;
	tri::Allocator<CMeshO>::CompactEveryVector(m);

	Histogramf H;
	H.SetRange(RangeMin, RangeMax, binNum);

	vector<Scalarm> aVec(m.fn, 1.0);
	if (areaFlag)
		tri::MeshToMatrix<CMeshO>::PerFaceArea(m, aVec);

	for (int i = 0; i<m.fn; ++i)
		H.Add(m.face[i].Q(), aVec[i]);
	if (areaFlag) {
		log("(         -inf..%15.7f) : %15.7f", RangeMin, H.BinCountInd(0));
		for (int i = 1; i <= binNum; ++i)
			log("[%15.7f..%15.7f) : %15.7f", H.BinLowerBound(i), H.BinUpperBound(i), H.BinCountInd(i));
		log("[%15.7f..             +inf) : %15.7f", RangeMax, H.BinCountInd(binNum + 1));
	}
	else {
		log("(         -inf..%15.7f) : %4.0f", RangeMin, H.BinCountInd(0));
		for (int i = 1; i <= binNum; ++i)
			log("[%15.7f..%15.7f) : %4.0f", H.BinLowerBound(i), H.BinUpperBound(i), H.BinCountInd(i));
		log("[%15.7f..             +inf) : %4.0f", RangeMax, H.BinCountInd(binNum + 1));
	}

	aVec = vector<Scalarm>(m.fn, 1.0);
	if (areaFlag)
		tri::MeshToMatrix<CMeshO>::PerFaceArea(m, aVec);

	for (int i = 0; i<m.fn; ++i)
		H.Add(m.face[i].Q(), aVec[i]);
	if (areaFlag) {
		log("(         -inf..%15.7f) : %15.7f", RangeMin, H.BinCountInd(0));
		for (int i = 1; i <= binNum; ++i)
			log("[%15.7f..%15.7f) : %15.7f", H.BinLowerBound(i), H.BinUpperBound(i), H.BinCountInd(i));
		log("[%15.7f..             +inf) : %15.7f", RangeMax, H.BinCountInd(binNum + 1));
	}
	else {
		log("(         -inf..%15.7f) : %4.0f", RangeMin, H.BinCountInd(0));
		for (int i = 1; i <= binNum; ++i)
			log("[%15.7f..%15.7f) : %4.0f", H.BinLowerBound(i), H.BinUpperBound(i), H.BinCountInd(i));
		log("[%15.7f..             +inf) : %4.0f", RangeMax, H.BinCountInd(binNum + 1));
	}
	return true;
}

Matrix33m FilterMeasurePlugin::computePrincipalAxisCloud(CMeshO& m)
{
	Matrix33m cov;
	Point3m bp(0, 0, 0);
	std::vector<Point3m> PtVec;
	for (CMeshO::VertexIterator vi = m.vert.begin(); vi != m.vert.end(); ++vi)
	if (!(*vi).IsD()) {
		PtVec.push_back((*vi).cP());
		bp += (*vi).cP();
	}

	bp /= m.vn;

	cov.Covariance(PtVec, bp);

	Matrix33m eigenvecMatrix;
	Eigen::Matrix3d em;
	cov.ToEigenMatrix(em);
	Eigen::SelfAdjointEigenSolver<Eigen::Matrix3d> eig(em);
	Eigen::Matrix3d c_vec = eig.eigenvectors();
	eigenvecMatrix.FromEigenMatrix(c_vec);

	return eigenvecMatrix;
}

MESHLAB_PLUGIN_NAME_EXPORTER(FilterMeasurePlugin)
