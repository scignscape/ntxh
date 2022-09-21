/*
 *  OpenSCAD (www.openscad.org)
 *  Copyright (C) 2009-2011 Clifford Wolf <clifford@clifford.at> and
 *                          Marius Kintel <marius@kintel.net>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  As a special exception, you have permission to link this program
 *  with the CGAL library and distribute executables, as long as you
 *  follow the requirements of the GNU GPL in regard to all of the
 *  software in the executable aside from CGAL.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#ifdef _MSC_VER 
// Boost conflicts with MPFR under MSVC (google it)
#include <mpfr.h>
#endif

// dxfdata.h must come first for Eigen SIMD alignment issues
#include "dxfdata.h"
#include "polyset.h"
#include "polyset-utils.h"
#include "printutils.h"

#include "CGALRenderer.h"
#include "CGAL_OGL_Polyhedron.h"
#include "CGAL_Nef_polyhedron.h"
#include "cgal.h"

//#include "Preferences.h"

CGALRenderer::CGALRenderer(shared_ptr<const class Geometry> geom)
{
	this->addGeometry(geom);
}

void CGALRenderer::addGeometry(const shared_ptr<const Geometry> &geom)
{
	if (const auto geomlist = dynamic_pointer_cast<const GeometryList>(geom)) {
		for (const auto &item : geomlist->getChildren()) {
			this->addGeometry(item.second);
		}
	}
	else if (const auto ps = dynamic_pointer_cast<const PolySet>(geom)) {
		assert(ps->getDimension() == 3);
		// We need to tessellate here, in case the generated PolySet contains concave polygons
    // See testdata/scad/3D/features/polyhedron-concave-test.scad
		auto ps_tri = new PolySet(3, ps->convexValue());
		ps_tri->setConvexity(ps->getConvexity());
		PolysetUtils::tessellate_faces(*ps, *ps_tri);
		this->polysets.push_back(shared_ptr<const PolySet>(ps_tri));
	}
	else if (const auto poly = dynamic_pointer_cast<const Polygon2d>(geom)) {
		this->polysets.push_back(shared_ptr<const PolySet>(poly->tessellate()));
	}
	else if (const auto new_N = dynamic_pointer_cast<const CGAL_Nef_polyhedron>(geom)) {
		assert(new_N->getDimension() == 3);
		if (!new_N->isEmpty()) {
			this->nefPolyhedrons.push_back(new_N);
		}
	}
}

CGALRenderer::~CGALRenderer()
{
}

const std::list<shared_ptr<class CGAL_OGL_Polyhedron> > &CGALRenderer::getPolyhedrons() const
{
	if (!this->nefPolyhedrons.empty() && this->polyhedrons.empty()) buildPolyhedrons();
	return this->polyhedrons;
}

void CGALRenderer::buildPolyhedrons() const
{
	PRINTD("buildPolyhedrons");
	this->polyhedrons.clear();

	for(const auto &N : this->nefPolyhedrons) {
		auto p = new CGAL_OGL_Polyhedron(*this->colorscheme);
		CGAL::OGL::Nef3_Converter<CGAL_Nef_polyhedron3>::convert_to_OGLPolyhedron(*N->p3, p);
		// CGAL_NEF3_MARKED_FACET_COLOR <- CGAL_FACE_BACK_COLOR
		// CGAL_NEF3_UNMARKED_FACET_COLOR <- CGAL_FACE_FRONT_COLOR
		p->init();
		this->polyhedrons.push_back(shared_ptr<CGAL_OGL_Polyhedron>(p));
	}
	PRINTD("buildPolyhedrons() end");
}

// Overridden from Renderer
void CGALRenderer::setColorScheme(const ColorScheme &cs)
{
	PRINTD("setColorScheme");
	Renderer::setColorScheme(cs);
	colormap[ColorMode::CGAL_FACE_2D_COLOR] = ColorMap::getColor(cs, RenderColor::CGAL_FACE_2D_COLOR);
	colormap[ColorMode::CGAL_EDGE_2D_COLOR] = ColorMap::getColor(cs, RenderColor::CGAL_EDGE_2D_COLOR);
	this->polyhedrons.clear(); // Mark as dirty
	PRINTD("setColorScheme done");
}

void CGALRenderer::draw(bool showfaces, bool showedges) const
{
	PRINTD("draw()");
	for (const auto &polyset : this->polysets) {
		PRINTD("draw() polyset");
		if (polyset->getDimension() == 2) {
			// Draw 2D polygons
			glDisable(GL_LIGHTING);
			setColor(ColorMode::CGAL_FACE_2D_COLOR);
			
			for (const auto &polygon : polyset->polygons) {
				glBegin(GL_POLYGON);
				for (const auto &p : polygon) {
					glVertex3d(p[0], p[1], 0);
				}
				glEnd();
			}

			// Draw 2D edges
			glDisable(GL_DEPTH_TEST);

			glLineWidth(2);
			setColor(ColorMode::CGAL_EDGE_2D_COLOR);
			this->render_edges(polyset, CSGMODE_NONE);
			glEnable(GL_DEPTH_TEST);
		}
		else {
			// Draw 3D polygons
			setColor(ColorMode::MATERIAL);
			this->render_surface(polyset, CSGMODE_NORMAL, Transform3d::Identity(), nullptr);
		}
	}

	for (const auto &p : this->getPolyhedrons()) {
		if (showfaces) p->set_style(SNC_BOUNDARY);
		else p->set_style(SNC_SKELETON);
		p->draw(showfaces && showedges);
	}

	PRINTD("draw() end");
}

BoundingBox CGALRenderer::getBoundingBox() const
{
	BoundingBox bbox;

  	for (const auto &p : this->getPolyhedrons()) {
		CGAL::Bbox_3 cgalbbox = p->bbox();
		bbox.extend(BoundingBox(
			Vector3d(cgalbbox.xmin(), cgalbbox.ymin(), cgalbbox.zmin()),
			Vector3d(cgalbbox.xmax(), cgalbbox.ymax(), cgalbbox.zmax())));
	}
	for (const auto &ps : this->polysets) {
		bbox.extend(ps->getBoundingBox());
	}
	return bbox;
}
