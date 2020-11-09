/* axlMesh.cpp ---
 *
 * Author: Meriadeg Perrinel
 * Copyright (C) 2008 - Meriadeg Perrinel, Inria.
 * Created: Tue Nov  9 16:58:59 2010 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Nov  9 17:09:38 2010 (+0100)
 *           By: Meriadeg Perrinel
 *     Update #: 19
 */

/* Comments:
 *
 */

/* Change log:
 *
 */

#include "axlMesh.h"
#include "axlPoint.h"

#include <dtkCoreSupport/dtkGlobal.h>

// /////////////////////////////////////////////////////////////////
// axlMeshPrivate
// /////////////////////////////////////////////////////////////////

class axlMeshPrivate
{
public:
    int vertex_count;
    int color_count;
    int normal_count;
    int face_count;
    int edge_count;

    double epsilon;

    bool color_used;
    bool color_rgb;
    bool normal_used;

    bool vertex_show;
    bool face_show;
    bool edge_show;

    bool planar;

    QVector<double>          vertices;
    QVector<double>          normals;
    QVector<int>             colors;
    QVector<axlMesh::Edge>   edges;
    QVector<axlMesh::Face>   faces;

    QVector<int> selectedVertices;

    axlMesh::Intepolation interpolation;
};

// /////////////////////////////////////////////////////////////////
// axlMesh implementation
// /////////////////////////////////////////////////////////////////

//! Construct an axlMesh.
/*!
 * The list of points, edges, faces, colors, normals are empty.
 * The default precision parameter is 1.e-9.
 */
axlMesh::axlMesh(void) : axlAbstractData(), d(new axlMeshPrivate)
{
    this->setObjectName(this->identifier());

    d->vertex_count = 0;
    d->color_count = 0;
    d->normal_count = 0;
    d->face_count = 0;
    d->edge_count = 0;

    d->epsilon = 1.e-9;

    d->normal_used = false;
    d->color_used = false;

    d->vertex_show = false;
    d->face_show = true;
    d->edge_show = false;

    d->planar = false;

    d->interpolation = FLAT;
}

//! Destroy the axlMesh.
/*!
 *
 */
axlMesh::~axlMesh(void)
{
    delete d;
    d = NULL;
}


//QVector<int> axlMesh::selectedVertices(void){
//    return d->selectedVertices;
//}

//void axlMesh::setSelectedVertices(QVector<int> selected){

//    qDebug() << Q_FUNC_INFO;

//    if(!d->selectedVertices.isEmpty())
//        d->selectedVertices.clear();

//    d->selectedVertices = selected;

//    if(!d->selectedVertices.isEmpty())
//        emit verticesSelected();
//}

int axlMesh::vertex_count(void) const
{
    return d->vertex_count;
}

int axlMesh::color_count() const
{
    return d->color_count;
}

int axlMesh::normal_count(void) const
{
    return d->normal_count;
}


int axlMesh::face_count(void) const
{
    return d->face_count;
}

int axlMesh::edge_count(void) const
{
    return d->edge_count;
}

int axlMesh::all_edge_count(void) const {
    int res = 0;

    for (int k = 0; k < d->edge_count; k++) {
        res += d->edges.at(k).size() - 1;
    }

    return res;
}


bool axlMesh::vertex_show(void) const
{
    return d->vertex_show;
}

bool& axlMesh::vertex_show(void)
{
    return d->vertex_show;
}


bool axlMesh::normal_used(void) const
{
    return d->normal_used;
}

bool& axlMesh::normal_used(void)
{
    return d->normal_used;
}

bool axlMesh::color_used(void) const
{
    return d->color_used;
}

bool& axlMesh::color_used(void)
{
    return d->color_used;
}

bool axlMesh::edge_show(void) const
{
    return d->edge_show;
}

bool& axlMesh::edge_show(void)
{
    return d->edge_show;
}

bool axlMesh::face_show(void) const
{
    return d->face_show;
}

bool& axlMesh::face_show(void)
{
    return d->face_show;
}

bool axlMesh::isPlanar(void) const
{
    return d->planar;
}

bool& axlMesh::isPlanar(void)
{
    return d->planar;
}

int axlMesh::interpolation(void) const
{
    return d->interpolation;
}

void axlMesh::setInterpolation(int interpolation)
{
    d->interpolation = (axlMesh::Intepolation)interpolation;
}

//! Return the i th vertex of the mesh.
/*!
 *
 */
axlPoint axlMesh::operator [](int i) {
    return axlPoint(d->vertices[3 * i], d->vertices[3 * i + 1], d->vertices[3 * i + 2]);
}

//! Get values of vertex of index ind.
/*!
 *
 */
void axlMesh::vertex(int ind, axlPoint &point) const
{
    point.setCoordinates(d->vertices[3 * ind], d->vertices[3 * ind + 1], d->vertices[3 * ind + 2]);
}

//! Set vertex values of vertices with index ind.
/*!
 *
 */
void axlMesh::vertex(int ind, axlPoint *point) const
{
    point->setCoordinates(d->vertices[3 * ind], d->vertices[3 * ind + 1], d->vertices[3 * ind + 2]);
}

//! Set vertex values of vertices with index ind and return it.
/*!
 *
 */
axlPoint *axlMesh::vertex2(int ind, axlPoint *point) const
{
    point->setCoordinates(d->vertices[3 * ind], d->vertices[3 * ind + 1], d->vertices[3 * ind + 2]);
    return point;
}

QVector<double> axlMesh::vertexSet(void) const
{
    return d->vertices;
}

/**
 * @brief Set the precision parameter for point comparison.
 * @param epsilon the maximal distance between two identified points
 *
 * @sa axlMesh::noDuplicateVertices
 */
void axlMesh::setEpsilon(double epsilon)
{
    d->epsilon = epsilon;
}

/**
 * @brief Return the parameter used to identify points.
 * @sa axlMesh::setEpsilon, axlMesh::noDuplicateVertices,
 */
double axlMesh::espilon(void)
{
    return d->epsilon;
}

//! Return X coordinates of vertex with index ind.
/*!
 *
 */
double axlMesh::vertexX(const int &ind) const
{
    return d->vertices[3 * ind];
}

//! return Y coordinates of vertex with index ind.
/*!
 *
 */
double axlMesh::vertexY(const int &ind) const
{
    return d->vertices[3 * ind + 1];
}

//! return Z coordinates of vertex with index ind.
/*!
 *
 */
double axlMesh::vertexZ(const int &ind) const
{
    return d->vertices[3 * ind + 2];
}

//! set vertex values of vertices with index ind.
/*!
 *
 */
void axlMesh::vertex(const int &ind, double vertex[3])
{
    vertex[0] = d->vertices[3 * ind];
    vertex[1] = d->vertices[3 * ind + 1];
    vertex[2] = d->vertices[3 * ind + 2];
}

//! Add a new vertex to the mesh.
/*!
 *  The vertex is added at the end of the list.
 */
void axlMesh::push_back_vertex(const double &x, const double &y, const double &z)
{
    d->vertex_count++;
    d->vertices.push_back(x);
    d->vertices.push_back(y);
    d->vertices.push_back(z);
}

//! Add a new vertex to the mesh.
/*!
 *  The vertex is added at the end of the list.
 *  The coordinnates of the vertex are copied in the vertex array of the mesh.
 */
void axlMesh::push_back_vertex(const double vertex[])
{
    d->vertex_count++;
    d->vertices.push_back(vertex[0]);
    d->vertices.push_back(vertex[1]);
    d->vertices.push_back(vertex[2]);
}

//! Add a new vertex to the mesh.
/*!
 *  The vertex is added at the end of the list.
 *  The coordinnates of the vertex are copied in the vertex array of the mesh.
 */
void axlMesh::push_back_vertex(const axlPoint &vertex)
{
    d->vertex_count++;
    d->vertices.push_back(vertex.x());
    d->vertices.push_back(vertex.y());
    d->vertices.push_back(vertex.z());
}

//! Add a new vertex to the mesh.
/*!
 *  The vertex is added at the end of the list.
 *  The coordinnates of \c vertex are copied in the vertex array of the mesh.
 */
void axlMesh::push_back_vertex(axlPoint *vertex)
{
    d->vertex_count++;
    //dtkWarn()<<"mesh"<<vertex->x()<< vertex->y()<<vertex->y();
    d->vertices.push_back(vertex->x());
    d->vertices.push_back(vertex->y());
    d->vertices.push_back(vertex->z());
}

/**
* @brief Function to set a vertex
* @param axlPoint containing the 3 (x, y, z) wished coordinates to set
* @param index of the vertex to set in the mesh
* @return none
*/
void axlMesh::set_vertex(axlPoint* point, const int &ind)
{
    if(ind < 0 )
    {
        dtkError()<< "axlMesh : specified index must be positive integer !";
    }
    else
        if(ind > d->vertex_count-1 )
        {
            dtkError()<< "axlMesh : specified index out of mesh !";
        }
        else
        {
            d->vertices.replace(3*ind,point->x());
            d->vertices.replace(3*ind+1,point->y());
            d->vertices.replace(3*ind+2,point->z());
        }
}


//! return X coordinates of normal with index ind.
/*!
 *
 */
double axlMesh::normalX(const int &ind) const
{
    return d->normals[3 * ind];
}

//! return Y coordinates of normal with index ind.
/*!
 *
 */
double axlMesh::normalY(const int &ind) const
{
    return d->normals[3 * ind + 1];
}

//! return Z coordinates of normal with index ind.
/*!
 *
 */
double axlMesh::normalZ(const int &ind) const
{
    return d->normals[3 * ind + 2];
}

//! set normal values of normals with index ind.
/*!
 *
 */
void axlMesh::normal(const int &ind, double normal[3])
{
    normal[0] = d->normals[3 * ind];
    normal[1] = d->normals[3 * ind + 1];
    normal[2] = d->normals[3 * ind + 2];
}


//! add normal to the mesh.
/*!
 *
 */
void axlMesh::push_back_normal(const double &x, const double &y, const double &z)
{
    d->normal_count++;
    d->normals.push_back(x);
    d->normals.push_back(y);
    d->normals.push_back(z);
}

//! add normal to the mesh.
/*!
 *
 */
void axlMesh::push_back_normal(const double normal[3])
{
    d->normal_count++;
    d->normals.push_back(normal[0]);
    d->normals.push_back(normal[1]);
    d->normals.push_back(normal[2]);
}

//! return int Red component of color with index ind.
/*!
 *
 */
int axlMesh::colorR(const int &ind)
{
    return d->colors[3 * ind];
}

//! return double Red component of color with index ind.
/*!
 *
 */
double axlMesh::colorRF(const int &ind)
{
    return d->colors[3 * ind] / 255.0 ;
}

//! return int Green component of color with index ind.
/*!
 *
 */
int axlMesh::colorG(const int &ind)
{
    return d->colors[3 * ind + 1];
}

//! Return double Green component of color with index ind.
/*!
 *
 */
double axlMesh::colorGF(const int &ind)
{
    return d->colors[3 * ind + 1] / 255.0 ;
}


//! Return int Blue component of color with index ind.
/*!
 *
 */
int axlMesh::colorB(const int &ind)
{
    return d->colors[3 * ind + 2];
}

//! Return double Blue component of color with index ind.
/*!
 *
 */
double axlMesh::colorBF(const int &ind)
{
    return d->colors[3 * ind + 2] / 255.0 ;
}


//! Set color values of colors with index ind.
/*!
 *
 */
void axlMesh::getColor(const int &ind, int color[3])
{
    color[0] = d->colors[3 * ind];
    color[1] = d->colors[3 * ind + 1];
    color[2] = d->colors[3 * ind + 2];
}

//! Add color to the mesh.
/*!
 * The list of colors is extended by the color \c (r,g,b).
 * The color is attached to the point with the same index in the list of vertices.
 */
void axlMesh::push_back_color(const int &r, const int &g, const int &b)
{
    d->color_count++;
    d->colors.push_back(r);
    d->colors.push_back(g);
    d->colors.push_back(b);
}

//! Add color to the mesh.
/*!
 * The list of colors is extended by the color \c color.
 * The color is attached to the point with the same index in the list of vertices.
 */
void axlMesh::push_back_color(const int color[3])
{
    d->color_count++;
    d->colors.push_back(color[0]);
    d->colors.push_back(color[1]);
    d->colors.push_back(color[2]);
}


void axlMesh::setVertices(const QVector<axlPoint *> &pointSet)
{
    //    if(d->vertex_count > 0)
    //        qDebug()<< " this axlMesh instance already have one vertex at less. This method cannot be use now. See push_back_vertex";
    //    else
    //    {
    for (int i = 0 ; i < pointSet.size() ; i++)
    {
        this->push_back_vertex(pointSet.value(i));

    }
    //    }

}

//! Set normal values of vertices with index ind.
/*!
 *
 */
void axlMesh::normal(int ind, axlPoint& normal)
{
    normal.setCoordinates(d->normals[3 * ind], d->normals[3 * ind + 1], d->normals[3 * ind + 2]);
}

//! Set normal values of vertices with index ind.
/*!
 *
 */
void axlMesh::normal(int ind, axlPoint *normal)
{
    normal->setCoordinates(d->normals[3 * ind], d->normals[3 * ind + 1], d->normals[3 * ind + 2]);
}

//! Set normal values of vertices with index ind and return it.
/*!
 *
 */
axlPoint *axlMesh::normal2(int ind, axlPoint *normal)
{
    normal->setCoordinates(d->normals[3 * ind], d->normals[3 * ind + 1], d->normals[3 * ind + 2]);
    return normal;
}

QVector<double> axlMesh::normalSet(void)
{
    return d->normals;
}


void axlMesh::push_back_normal(axlPoint *normal)
{
    d->normal_count++;
    d->normals.push_back(normal->x());
    d->normals.push_back(normal->y());
    d->normals.push_back(normal->z());
}

void axlMesh::setNormals(const QList<axlPoint*>& pointSet)
{
    if(d->normal_count > 0)
        qDebug()<< " this axlMesh instance already have one vertex at less, This method cannot be use now. See push_back_vertex";
    else
    {
        for (int i = 0 ; i < pointSet.size() ; i++)
        {
            this->push_back_normal(pointSet.value(i));
        }
    }

}

void axlMesh::clearNormals(void){
    d->normals.clear();
    d->normal_count = 0;
}

axlMesh::Edge axlMesh::edge(int ind) const
{
    return d->edges.at(ind);
}

QVector< axlMesh::Edge > axlMesh::edgeSet(void) const
{
    return d->edges;
}


//! Returns the index of the j-th point of the i-th edge of the mesh.
/*!
 *
 */
int axlMesh::edgePointIndex(int i, int j) const{
    return d->edges.at(i).at(j);
}


//! Return the number of point contained in the i-th edge of the mesh.
/*!
 *
 */
int axlMesh::edgePointCount(int i) const{
    return d->edges.at(i).size();
}


void axlMesh::push_back_edge(int i1, int i2)
{
    d->edge_count++;
    Edge e; e<<i1 <<i2;
    d->edges.push_back(e);
}

//! Add an edge to the mesh.
/*!
 * The edge is pushed at the the end of the list of edges.
 */
void axlMesh::push_back_edge(const Edge& e)
{
    d->edge_count++;
    d->edges.push_back(e);
}

//! Add an empty edge to the mesh.
/*!
 * The edge is pushed at the the end of the list of edges.
 */
int axlMesh::push_back_new_edge(void)
{
    d->edge_count++;
    Edge e;
    d->edges.push_back(e);

    return d->edge_count-1;
}


//! Add to the edge \c i the index \c j.
/*!
 * The index \c j is pushed at the end of edge \c i.
 */
void axlMesh::edgePushBack(int i, int j)
{
    d->edges[i]<<j;
}

axlMesh::Face axlMesh::face(int ind) const
{
    return d->faces.at(ind);
}

QVector< axlMesh::Face > axlMesh::faceSet(void) const
{
    return d->faces;
}

//! Returns the index of the j-th point of the i-th face of the mesh.
/*!
 *
 */
int axlMesh::facePointIndex(int i, int j) const{
    return d->faces.at(i).at(j);
}

//! Returns the number of vertex of a mesh face
/*!
 *
 */
int axlMesh::facePointCount(int i) const{
    return d->faces.at(i).size();
}

void axlMesh::push_back_face(const Face &face)
{
    d->face_count++;
    d->faces.push_back(face);
}

void axlMesh::push_back_face(int i1, int i2, int i3)
{
    Face face; face<<i1<<i2<<i3;
    d->face_count++;
    d->faces.push_back(face);
}

//! Return the bounding box vector of the mesh.
/*!
 *  Only compute with vertices
 * bbox[0] will give min X value;
 * bbox[1] will give max X value;
 * bbox[2] will give min Y value;
 * bbox[3] will give max Y value;
 * bbox[4] will give min Z value;
 * bbox[5] will give max Z value;
 */
const QVector<double> axlMesh::boundingBoxVertex() const
{
    QVector<double> bbox;
    bbox.reserve(6);
    bbox[0] =  d->vertices[0];
    bbox[1] =  d->vertices[0];
    bbox[2] =  d->vertices[1];
    bbox[3] =  d->vertices[1];
    bbox[4] =  d->vertices[2];
    bbox[5] =  d->vertices[2];

    for(int i = 1 ; i < vertex_count(); i++)
    {
        if(bbox[0] >  d->vertices[3 * i])
            bbox[0] =  d->vertices[3 * i];

        if(bbox[1] < d->vertices[3 * i])
            bbox[1] = d->vertices[3 * i];

        if(bbox[2] > d->vertices[3 * i + 1])
            bbox[2] = d->vertices[3 * i + 1];

        if(bbox[3] < d->vertices[3 * i + 1])
            bbox[3] = d->vertices[3 * i + 1];

        if(bbox[4] > d->vertices[3 * i + 2])
            bbox[4] = d->vertices[3 * i + 2];

        if(bbox[5] < d->vertices[3 * i + 2])
            bbox[5] = d->vertices[3 * i + 2];
    }

    return bbox;
}


//! Return a scale factor based on the distance max founded with the bounding box.
/*!
 *  Usufull if you want to use an epsilon for the mesh
 */
double axlMesh::meshVertexScaleFactor() const
{
    QVector<double> bbox = this->boundingBoxVertex();
    double scale = bbox[1]- bbox[0];
    if(scale < bbox[3] - bbox[2])
        scale = bbox[3] - bbox[2];

    if(scale < bbox[5] - bbox[4])
        scale = bbox[5] - bbox[4];

    return scale;
}




void axlMesh::append(axlMesh *mesh)
{
    for (int i = 0 ; i < mesh->face_count() ; i++)
    {
        Face currentList = mesh->face(i);
        for (int j = 0 ; j < currentList.size() ; j ++)
            currentList.replace(j, currentList.at(j) + this->vertex_count());

        this->push_back_face(currentList);
    }

    for (int i = 0 ; i < mesh->edge_count() ; i++)
    {
        Edge currentEdge = mesh->edge(i);
        Edge newEdge;
        for (int j = 0; j< currentEdge.size(); j++)
            newEdge << (currentEdge.at(j) + this->vertex_count());
        this->push_back_edge(newEdge);
    }


    for (int i = 0 ; i < mesh->vertex_count() ; i++)
    {
        axlPoint currentPoint;
        mesh->vertex(i, &currentPoint);
        this->push_back_vertex(&currentPoint);
    }

    for (int i = 0 ; i < mesh->normal_count() ; i++)
    {
        axlPoint currentNormal;
        mesh->normal(i, &currentNormal);
        this->push_back_normal(&currentNormal);
    }

    //d->edge_count += mesh->edge_count();
}

/**
 * @brief Remove duplicated vertices.
 *
 * Identify all points which are within distance \c d->epsilon, keeping the point of smaller index.
 * Remove the redundant points and the degenerate edges and faces.
 *
 * \note The identification of points is based a naive quadratic algorithm.
 *   It envolves at most n*(n-1)/2 distance tests if n is the number of points.
 *
 * @sa axlMesh::setEpsilon
 */
void axlMesh::noDuplicateVertices(void)
{
    QVector<int> verticesFirstIndexes;

    axlPoint p1;
    axlPoint p2;
    QVector<int> idx(d->vertex_count,0);

    int vertexUnique_count=0;

    for(int i = 0 ; i < d->vertex_count ; i++)
    {
        int j = 0;
        bool not_found = true;
        this->vertex(i, &p1);

        while(j < i && not_found)
        {
            this->vertex(j, &p2);
            if(axlPoint::distance(p1, p2) < d->epsilon) {
                not_found = false;
                idx[i]=j;
            }
            j++;
        }

        if(not_found)
        {
            idx[i]=i;
            vertexUnique_count ++;
            verticesFirstIndexes <<  i;
        }

    }//assossiation are done

    //update edge indexes
    if(vertexUnique_count< d->vertex_count) {

        QVector<double> new_vertices;

        for(int k=0; k< verticesFirstIndexes.size();k++)
            new_vertices << this->vertexX(verticesFirstIndexes.at(k))
                         << this->vertexY(verticesFirstIndexes.at(k))
                         << this->vertexZ(verticesFirstIndexes.at(k));

        d->vertices = new_vertices;


        if(d->vertex_count==d->normal_count) {
            QVector<double> new_normals;
            for(int k=0; k < verticesFirstIndexes.size();k++)
                new_normals << this->normalX(verticesFirstIndexes.at(k))
                            << this->normalY(verticesFirstIndexes.at(k))
                            << this->normalZ(verticesFirstIndexes.at(k));

            d->normals = new_normals;
            d->normal_count = new_normals.size()/3;
        }

        if(d->vertex_count==d->color_count) {
            QVector<int> new_colors;
            for(int k=0; k< verticesFirstIndexes.size();k++)
                new_colors << this->colorR(verticesFirstIndexes.at(k))
                           << this->colorG(verticesFirstIndexes.at(k))
                           << this->colorB(verticesFirstIndexes.at(k));

            d->colors = new_colors;
            d->color_count = new_colors.size()/3;
        }

        d->vertex_count =  new_vertices.size()/3;

        QVector<Edge> new_edges;
        int j1;
        for(int i = 0 ; i < d->edge_count ; i++)
        {
            Edge newEdge;
            for(int j=0;j<d->edges.at(i).size(); j++) {
                j1 = idx[d->edges.at(i).at(j)];
                if(j == 0 || (j1 != idx[d->edges.at(i).at(j-1)]))
                    newEdge<< j1;
            }

            if(newEdge.size()>1)
                new_edges << newEdge;
        }

        d->edges = new_edges;
        d->edge_count = new_edges.size();

        QVector<Face> new_faces;
        for(int i = 0 ; i < d->face_count ; i++)
        {
            QVector<int> face;
            for(int j = 0 ; j < d->faces.at(i).size() ; j ++) {
                j1 = idx[d->faces.at(i)[j]];
                if(!face.contains(j1))
                    face<< j1;
            }
            if(face.size()>2)
                new_faces << face;
        }
        d->faces = new_faces;
        d->face_count = new_faces.size();
    }
    //qDebug()<<"vertex"<<d->vertex_count;
}

//! Compute the distance in the 3d space between two points of indices ind1 and ind2.
/*!
 * If one of these indices if higher than this->vertex_count() -1, the function return -1.0
 */
double axlMesh::distance(int ind1, int ind2)
{
    if(ind1 >= d->vertex_count || ind2 >= d->vertex_count)
        return -1.0;

    return sqrt((d->vertices[3 * ind1]- d->vertices[3 * ind2]) * (d->vertices[3 * ind1]- d->vertices[3 * ind2]) + (d->vertices[3 * ind1 + 1]- d->vertices[3 * ind2 + 1]) * (d->vertices[3 * ind1 + 1]- d->vertices[3 * ind2 + 1]) + (d->vertices[3 * ind1 + 2]- d->vertices[3 * ind2 + 2]) * (d->vertices[3 * ind1 + 2]- d->vertices[3 * ind2 + 2]));
}



QString axlMesh::description(void) const
{
    QString result = "axlMesh";
    result.append("\nVertex count : "+QString::number(d->vertex_count));
    result.append("\nNormal count : "+QString::number(d->normal_count));
    result.append("\nEdge count : "+QString::number(d->edge_count));
    result.append("\nFace count : "+QString::number(d->face_count));
    result.append("\nVertex show : "+QString::number(d->vertex_show));
    result.append("\nNormal use : "+QString::number(d->normal_used));
    result.append("\nEdge show : "+QString::number(d->edge_show));
    result.append("\nFace show : "+QString::number(d->face_show));
    return result;

}

QString axlMesh::identifier(void) const
{
    return "axlMesh";
}

//! Construct neighbors of all points of the mesh.
/*!
 *  This method use only faces of the mesh and not edges
 */
QVector<QSet<int> > axlMesh::neighborsFace(const axlMesh &mesh)
{
    QVector<QSet<int> > result(mesh.vertex_count());

    for(int i = 0 ; i < mesh.face_count(); i++)
    {
        // each face contains at least three vertices
        // two particular case
        int vfirst = mesh.face(i).first();
        int vatone = mesh.face(i).at(1);
        int vatlastminusone = mesh.face(i).at(mesh.face(i).count() -2);
        int vlast = mesh.face(i).last();

        if(vfirst != vatone)
            result[vfirst] << vatone;

        if(vfirst != vlast)
            result[vfirst] << vlast;

        if(vlast != vfirst)
            result[vlast] << vfirst;

        if(vlast != vatlastminusone)
            result[vlast] << vatlastminusone;

        //  result[vlast]<< vfirst << vatlastminusone;

        //generic case
        for (int j = 1 ; j < mesh.face(i).count() -1; j++)
        {
            vfirst = mesh.face(i).at(j-1);
            vatone = mesh.face(i).at(j);
            vlast = mesh.face(i).at(j+1);

            if(vatone != vfirst)
                result[vatone] << vfirst;

            if(vatone != vlast)
                result[vatone] << vlast;
            // result[mesh.face(i).at(j)]<< mesh.face(i).at(j-1) << mesh.face(i).at(j+1);

        }


    }

    return result;
}


//! Construct Faces Indexes Table.  of all points of the mesh.
/*!
 *  Store for feach point all faces Indexes where the point is one the face vertex
 */
QVector<QSet<int> > axlMesh::VertexTofaceIndexes(const axlMesh &mesh)
{
    QVector<QSet<int> > result(mesh.vertex_count());

    for(int i = 0 ; i < mesh.face_count(); i++)
    {
        // each face contains at least three vertices
        // two particular case

        result[mesh.face(i).first()] << i;
        result[mesh.face(i).last()]  << i;


        //  result[vlast]<< vfirst << vatlastminusone;

        //generic case
        for (int j = 1 ; j < mesh.face(i).count() -1; j++)
            result[mesh.face(i).at(j)] << i;

    }

    return result;

}


QVariantList axlMesh::convertDataToQVariant(void) const{
    QVariantList list;
    QVariant id = QVariant::fromValue(identifier());
    QVariant vertexCount = QVariant::fromValue(d->vertex_count);
    QVariant colorCount = QVariant::fromValue(d->color_count);
    QVariant normalCount = QVariant::fromValue(d->normal_count);
    QVariant faceCount = QVariant::fromValue(d->face_count);
    QVariant edgeCount = QVariant::fromValue(d->edge_count);
    QVariant epsilon = QVariant::fromValue(d->epsilon);
    QVariant colorUsed = QVariant::fromValue(d->color_used);
    QVariant colorRgb = QVariant::fromValue(d->color_rgb);
    QVariant normalUsed = QVariant::fromValue(d->normal_used);
    QVariant vertexShow = QVariant::fromValue(d->vertex_show);
    QVariant faceShow = QVariant::fromValue(d->face_show);
    QVariant edgeShow = QVariant::fromValue(d->edge_show);
    QVariant planar = QVariant::fromValue(d->planar);



    list.append(id);
    list.append(vertexCount);
    list.append(colorCount);
    list.append(normalCount);
    list.append(faceCount);
    list.append(edgeCount);
    list.append(epsilon);
    list.append(colorUsed);
    list.append(colorRgb);
    list.append(normalUsed);
    list.append(vertexShow);
    list.append(faceShow);
    list.append(edgeShow);
    list.append(planar);

    //add vertices
    for(int i = 0; i< d->vertex_count;i++){
        list.append(vertexX(i));
        list.append(vertexY(i));
        list.append(vertexZ(i));
    }

    //add normals
    for(int i = 0; i< d->normal_count;i++){
        list.append(normalX(i));
        list.append(normalY(i));
        list.append(normalZ(i));
    }

    //add color
    //    for(int i = 0; i< d->color_count;i++){
    //        list.append(col);
    //    }

    //add edges
    for(int i = 0; i< d->edge_count;i++){
        list.append(edgePointCount(i));
        for(int j =0;j < edgePointCount(i); j++){
            list.append(edge(i).at(j));
        }
    }

    //add faces
    for(int i = 0; i< d->face_count;i++){
        list.append(facePointCount(i));
        for(int j = 0;j < facePointCount(i);j++){
            list.append(face(i).at(j));
        }
    }

    QVariant name = QVariant::fromValue(objectName());
    list.append(name);

    return list;

}

int axlMesh::convertQVariantToData(const QVariantList &data){

    //    d->vertex_count = data.at(1).toInt();
    //    d->color_count = data.at(2).toInt();
    //    d->normal_count = data.at(3).toInt();
    //    d->face_count = data.at(4).toInt();
    //    d->edge_count = data.at(5).toInt();
    d->epsilon = data.at(6).toDouble();
    d->color_used = data.at(7).toBool();
    d->color_rgb = data.at(8).toBool();
    d->normal_used = data.at(9).toBool();
    d->vertex_show = data.at(10).toBool();
    d->face_show = data.at(11).toBool();
    d->edge_show = data.at(12).toBool();
    d->planar = data.at(13).toBool();


    int newBegin = 14;
    //fill vertices
    for(int i = 0; i< data.at(1).toInt();i++){
        double x = data.at(3*i+newBegin).toDouble() ;
        double y = data.at(3*i+1+newBegin).toDouble();
        double z = data.at(3*i+2+newBegin).toDouble();
        push_back_vertex(x,y,z);
    }
    newBegin = (3*d->vertex_count)+newBegin;

    if(!d->normals.isEmpty()){
        //fill normals
        for(int i = 0; i< d->normal_count;i++){
            double x = data.at(3*i+newBegin).toDouble() ;
            double y = data.at(3*i+1+newBegin).toDouble();
            double z = data.at(3*i+2+newBegin).toDouble();
            push_back_normal(x,y,z);
        }

        newBegin = (3*d->normal_count) + newBegin;
    }

    //fill color
    //    for(int i = 0; i< d->color_count;i++){
    //        list.append(col);
    //    }

    //fill edges
    for(int i = 0; i< data.at(5).toInt();i++){
        int indiceEdge = newBegin+i;
        int nb = data.at(indiceEdge).toInt();
        push_back_edge(data.at(indiceEdge+1).toInt(), data.at(indiceEdge+2).toInt());
        newBegin = newBegin+nb;
    }

    newBegin = newBegin+ d->edge_count;

    //fill faces
    for(int i = 0; i< data.at(4).toInt();i++){
        int indiceEdge = newBegin+i;
        int nb = data.at(indiceEdge).toInt();
        Face f;
        for(int j=1;j <= nb;j++){
            f.append(data.at(indiceEdge+j).toInt());
        }
        push_back_face(f);
        newBegin = newBegin+nb;

    }
    setObjectName(data.last().toString());
    return 1;


}

//to be registered to the data factory.
dtkAbstractData *createaxlMesh(void)
{
    return new axlMesh;
}


// /////////////////////////////////////////////////////////////////
// axlMesh documentation
// /////////////////////////////////////////////////////////////////

/*! \class axlMesh
 *
 *  \brief Class axlMesh defines a piecewise-linear 3D object.
 *
 *  This class enables to represent and manipulate piecewise-linear 3D object.
 *
 *  A mesh is composed of
 *   - a list of vertices,
 *   - a list of edges (axlMesh::Edge) that can be empty,
 *   - a list of faces (axlMesh::Face) that can be empty,
 *   - a list of normals that can be empty,
 *   - a list of colors that can be empty.
 *
 *  An edge is a list of indices of vertices, describing a polygonal line from the first point to the
 *  last point.
 *
 *  A face is a list of indices of vertices, describing a polygon. The last point of the list is connected
 *  to the first point.
 *
 * \note If the list of colors (resp. normals) is provided,  it should have the same size
 *  as the vertex list. The color (resp. normal) of index i in the color list corresponds
 *  to the point of index i in the vertex list.
 *
 * A mesh can be used  to represent for instance
 *   - a point set (vertex list),
 *   - a polygonal curve (vertex list and list of edges),
 *   - a polygonal surface (vertex list and face list),
 *   - a polygonal surface with additional polygonal curves (vertex list, edge list, face list).
 *
 *
 * Example:
 *  \code
 *   axlMesh *mesh = new axlMesh;
 *   axlPoint pt;
 *   mesh->push_back_vertex(pt);
 *   mesh->push_back_vertex(1,0,0);
 *   mesh->push_back_vertex(0,1,0);
 *   mesh->push_back_vertex(1,1,1);
 *
 *   mesh->push_back_edge(0,1);
 *   mesh->push_back_edge(1,3);
 *   mesh->push_back_edge(3,2);
 *   mesh->push_back_edge(2,1);
 *
 *   mesh->push_back_face(0,1,2);
 *   mesh->push_back_face(1,2,3);
 *  \endcode
 */
