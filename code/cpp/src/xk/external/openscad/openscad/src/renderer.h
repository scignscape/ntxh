#pragma once

#include "GLView.h"
#include "system-gl.h"
#include "linalg.h"
#include "memory.h"
#include "colormap.h"
#include "enums.h"
#include "Geometry.h"

#ifdef _MSC_VER // NULL
#include <cstdlib>
#endif

class Renderer
{
public:
	Renderer();
	virtual ~Renderer() {}
	virtual void draw(bool showfaces, bool showedges) const = 0;
	virtual void draw_with_shader(const GLView::shaderinfo_t *) const  { this->draw(true, true); }
	virtual BoundingBox getBoundingBox() const = 0;

#define CSGMODE_DIFFERENCE_FLAG 0x10
	enum csgmode_e {
		CSGMODE_NONE                  = 0x00,
		CSGMODE_NORMAL                = 0x01,
		CSGMODE_DIFFERENCE            = CSGMODE_NORMAL | CSGMODE_DIFFERENCE_FLAG,
		CSGMODE_BACKGROUND            = 0x02,
		CSGMODE_BACKGROUND_DIFFERENCE = CSGMODE_BACKGROUND | CSGMODE_DIFFERENCE_FLAG,
		CSGMODE_HIGHLIGHT             = 0x03,
		CSGMODE_HIGHLIGHT_DIFFERENCE  = CSGMODE_HIGHLIGHT | CSGMODE_DIFFERENCE_FLAG
	};

	enum class ColorMode {
		NONE,
		MATERIAL,
		CUTOUT,
		HIGHLIGHT,
		BACKGROUND,
		MATERIAL_EDGES,
		CUTOUT_EDGES,
		HIGHLIGHT_EDGES,
		BACKGROUND_EDGES,
		CGAL_FACE_2D_COLOR,
		CGAL_EDGE_2D_COLOR,
		EMPTY_SPACE
	};

	virtual bool getColor(ColorMode colormode, Color4f &col) const;
	virtual void setColor(const float color[4], const GLView::shaderinfo_t *shaderinfo = nullptr) const;
	virtual void setColor(ColorMode colormode, const GLView::shaderinfo_t *shaderinfo = nullptr) const;
	virtual Color4f setColor(ColorMode colormode, const float color[4], const GLView::shaderinfo_t *shaderinfo = nullptr) const;
	virtual void setColorScheme(const ColorScheme &cs);

	virtual csgmode_e get_csgmode(const bool highlight_mode, const bool background_mode, const OpenSCADOperator type=OpenSCADOperator::UNION) const;
	virtual void render_surface(shared_ptr<const class Geometry> geom, csgmode_e csgmode, const Transform3d &m, const GLView::shaderinfo_t *shaderinfo = nullptr) const;
	virtual void render_edges(shared_ptr<const Geometry> geom, csgmode_e csgmode) const;

protected:
	std::map<ColorMode,Color4f> colormap;
	const ColorScheme *colorscheme;
};
