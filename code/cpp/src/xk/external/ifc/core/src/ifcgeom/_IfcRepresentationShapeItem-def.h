

#ifndef SEENVEC
#define SEENVEC
	class IFC_GEOM_API IfcRepresentationShapeItem {
	private:
		int id;
		gp_GTrsf placement;
		TopoDS_Shape shape;
		const SurfaceStyle* style;
	public:
		IfcRepresentationShapeItem(int id, const gp_GTrsf& placement, const TopoDS_Shape& shape, const SurfaceStyle* style)
			: id(id), placement(placement), shape(shape), style(style) {}
		IfcRepresentationShapeItem(int id, const gp_GTrsf& placement, const TopoDS_Shape& shape)
			: id(id), placement(placement), shape(shape), style(0) {}
		IfcRepresentationShapeItem(int id, const TopoDS_Shape& shape, const SurfaceStyle* style)
			: id(id), shape(shape), style(style) {}
		IfcRepresentationShapeItem(int id, const TopoDS_Shape& shape)
			: id(id), shape(shape), style(0) {}
		void append(const gp_GTrsf& trsf) { placement.Multiply(trsf); }
		void prepend(const gp_GTrsf& trsf) { placement.PreMultiply(trsf); }
		const TopoDS_Shape& Shape() const { return shape; }
		const gp_GTrsf& Placement() const { return placement; }
		bool hasStyle() const { return style != 0; }
		const SurfaceStyle& Style() const { return *style; }
		void setStyle(const SurfaceStyle* newStyle) { style = newStyle; }
		int ItemId() const { return id; }
	};

#endif
