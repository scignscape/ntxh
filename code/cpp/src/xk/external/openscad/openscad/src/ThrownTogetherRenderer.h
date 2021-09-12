#pragma once

#include "renderer.h"
#include "csgnode.h"
#include <unordered_map>
#include <boost/functional/hash.hpp>

class ThrownTogetherRenderer : public Renderer
{
public:
	ThrownTogetherRenderer(shared_ptr<class CSGProducts> root_products,
												 shared_ptr<CSGProducts> highlight_products,
												 shared_ptr<CSGProducts> background_products);
	void draw(bool showfaces, bool showedges) const override;
	void draw_with_shader(const GLView::shaderinfo_t *shaderinfo) const override {
		this->draw_with_shader(shaderinfo, false);
	}
	void draw_with_shader(const GLView::shaderinfo_t *, bool showedges) const;

	BoundingBox getBoundingBox() const override;
private:
	void renderCSGProducts(const CSGProducts &products, const GLView::shaderinfo_t *, bool highlight_mode, bool background_mode, bool showedges,
											bool fberror) const;
	void renderChainObject(const class CSGChainObject &csgobj, const GLView::shaderinfo_t *, bool highlight_mode,
												 bool background_mode, bool showedges, bool fberror, OpenSCADOperator type) const;

	shared_ptr<CSGProducts> root_products;
	shared_ptr<CSGProducts> highlight_products;
	shared_ptr<CSGProducts> background_products;
	mutable std::unordered_map<std::pair<const Geometry*,const Transform3d*>,
														 int,
														 boost::hash<std::pair<const Geometry*,const Transform3d*>>> geomVisitMark;
};
