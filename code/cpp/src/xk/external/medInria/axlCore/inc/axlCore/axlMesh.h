/* axlMesh.h ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 16:58:59 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Mon Dec  6 15:46:18 2010 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 21
 */

/* Commentary:
 * There is choice table for stock coordinate. But maybe that is not the good solution if algorithm behin use a lot of point.
 * In this case, we have to create three double directly instead of table
 */

/* Change log:
 *
 */

#ifndef AXLMESH_H
#define AXLMESH_H

#include "axlCoreExport.h"

#include <QtCore>

#include <axlCore/axlAbstractData.h>
#include <axlCore/axlPoint.h>

//class axlPoint;

class axlMeshPrivate;

//enum Intepolation{
//        FLAT,
//        GOURAUD,
//        PHONG
//    };

class AXLCORE_EXPORT axlMesh : public axlAbstractData
{
    Q_OBJECT
public:
    enum Intepolation{
        FLAT,
        GOURAUD,
        PHONG
    };
public:
    /// A point of the mesh is an axlPoint.
    typedef axlPoint        Point;

    /// An edge is represented by a sequence of vertices.
    typedef QVector<int>    Edge;

    /// A face is a polygon represented by a loop of vertices.
    typedef QVector<int>      Face;

    axlMesh(void);
    ~axlMesh(void);

    virtual QString description(void) const;
    virtual QString identifier(void) const;

//    QVector<int> selectedVertices(void);
//    void setSelectedVertices(QVector<int> selected);

//signals :
//    void verticesSelected(void);

public :

    int vertex_count(void) const;
    int color_count(void) const;
    int normal_count(void) const;
    int face_count(void) const;
    int edge_count(void) const;
    int all_edge_count(void) const;

    bool  vertex_show(void) const;
    bool& vertex_show();

    bool  normal_used(void) const;
    bool& normal_used(void);

    bool  color_used(void) const;
    bool& color_used(void);

    bool  edge_show(void) const;
    bool& edge_show(void);
    bool  face_show(void) const;
    bool& face_show(void);

    bool  isPlanar(void) const;
    bool& isPlanar(void);

    void setEpsilon(double epsilon);
    double espilon(void);

    int interpolation(void) const;
    void setInterpolation(int interpolation);

    //methods for vertices

    double vertexX(const int& ind) const;
    double vertexY(const int& ind) const;
    double vertexZ(const int& ind) const;

    void vertex(const int& ind, double vertex[3] );
    void vertex(int ind, axlPoint& point) const;
    void vertex(int ind, axlPoint *point) const;

    axlPoint operator[] (int i);
    axlPoint *vertex2(int ind, axlPoint *point) const;
    QVector<double> vertexSet(void) const;

    void push_back_vertex(const double &x,const double &y, const double &z);
    void push_back_vertex(const double vertex[3]);
    void push_back_vertex(const axlPoint& vertex);
    void push_back_vertex(axlPoint *vertex);

    void set_vertex(axlPoint* point, const int &ind);

    void setVertices(const QVector<axlPoint*>& pointSet);

    // methods for normals

    double normalX(const int& ind) const;
    double normalY(const int& ind) const;
    double normalZ(const int& ind) const;

    void normal(const int& ind, double normal[3]);
    void normal(int ind, axlPoint& normal);
    void normal(int ind, axlPoint *normal);
    axlPoint *normal2(int ind, axlPoint *normal);

    QVector<double> normalSet(void);

    void push_back_normal(axlPoint *normal);
    void setNormals(const QList<axlPoint*>& pointSet);

    void push_back_normal(const double &x,const double &y, const double &z);
    void push_back_normal(const double normal[3]);

    void clearNormals(void);

    // methods for colors

    int colorR(const int& ind);
    int colorG(const int& ind);
    int colorB(const int& ind);
    double colorRF(const int& ind);
    double colorGF(const int& ind);
    double colorBF(const int& ind);
    void getColor(const int& ind, int color[3] );
    void push_back_color(const int &r,const int &g, const int &b);
    void push_back_color(const int color[3]);

    //methods for edges

    Edge          edge(int ind) const;
    QVector<Edge> edgeSet(void) const;
    int edgePointIndex(int i, int j) const;
    int edgePointCount(int i) const;

    void push_back_edge(int, int);
    void push_back_edge(const Edge& e);
    int push_back_new_edge(void);
    void edgePushBack(int, int);

    // methods for faces

    Face face(int ind) const;
    QVector<Face> faceSet(void) const;
    int facePointIndex(int i, int j) const;
    int facePointCount(int i) const;

    void push_back_face(const Face& face);
    void insert_face(const Face& face) {this->push_back_face(face);}
    void push_back_face(int i1, int i2, int i3);

    // differents algorithms

    const QVector<double> boundingBoxVertex(void) const;
    double meshVertexScaleFactor() const;

    void append(axlMesh *mesh);
    void noDuplicateVertices(void);

    double distance(int ind1, int ind2);

public:
    // static axlMesh& fromCurve(axlAbstractCurveParametric *curve);
    static QVector<QSet<int> > neighborsFace(const axlMesh& mesh);
    static QVector<QSet<int> > VertexTofaceIndexes(const axlMesh &mesh);

    //IPC
    QVariantList convertDataToQVariant(void) const;
    int convertQVariantToData(const QVariantList &data);

private:
    axlMeshPrivate *d;
};

//to be registered to the data factory.
dtkAbstractData *createaxlMesh(void);

// /////////////////////////////////////////////////////////////////
// Debug operators
// /////////////////////////////////////////////////////////////////


#endif // AXLMESH_H
