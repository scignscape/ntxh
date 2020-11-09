/* axlShape.h ---
 *
 * Author: Valentin Michelet
 * Copyright (C) 2008-2013 - Valentin Michelet, Inria.
 * Created: Wed Mar 20 03:47:23 2013 (+0100)
 * Version: $Id$
 */

/* Commentary:
 *
 */

/* Change log:
 *
 */

#ifndef AXLSHAPE_H
#define AXLSHAPE_H

#include "axlCoreExport.h"
#include "axlAbstractData.h"
#include "axlAbstractSurfaceParametric.h"
#include "axlAbstractCurveParametric.h"

#include <QtCore>

class axlShapePrivate;
class axlPoint;
class axlAbstractCurveParametric;

class AXLCORE_EXPORT axlShape : public axlAbstractData {
    Q_OBJECT

public:
    /**
     * @brief The edge structure.
     *
     * An edge is composed of a supporting  parametric curve and of the indices in the array of vertices of the starting
     * vertex and ending vertex.
    **/
    struct Edge {
        /// Index of the starting point of the edge in the array of vertices of the axlShape.
        int indexStartVertex;

        /// Index of the ending point of the edge in the array of vertices of the axlShape.
        int indexEndVertex;

        /// Pointer to the parametric curve supporting the edge, of type axlAbstractCurveParametric.
        axlAbstractCurveParametric* curve;

        Edge():indexStartVertex(0), indexEndVertex(1), curve(NULL) {};

        /// Constructor from a parametric curve pointer, the starting and ending indices;
        Edge(axlAbstractCurveParametric* crv, int si, int ei): indexStartVertex(si), indexEndVertex(ei), curve(crv) {};
    };

    /**
     * @brief The Loop structure.
     *
     * A loop is a set of edges with orientations, such the end point of one oriented edge is the starting point of the next one.
     */
    struct Loop {
        /// Vector of indices of the edges of the loop in the array of edges of the axlShape.
        QVector<int> edges;

        /// Vector of booleans of the same size as edges: true means the direct orientation, false is the reverse orientation.
        QVector<bool> orientations;
    };

    /**
     * @brief The Face structure.
     *
     * A face is composed of a vector of loops and a supporting parametric surface. By convention, the region of the face
     * on the supporting surface is on the left of the oriented edge.
     */
    struct Face {
        /// Vector of all the loops defining the face.
        QVector<Loop*> loops;

         /// Pointer to the supporting surface of type axlAbstractSurfaceParametric.
        axlAbstractSurfaceParametric* surface;
    };

public:

    /*!
     * Construct an axlShape with the corresponding number of vertices, edges and faces.
     *
     * The default values for the pointers is NULL.
     */
    axlShape(int vertexCount, int edgeCount, int faceCount, axlShape* parent = 0);
    /*!
     * Destructor
     */
    virtual ~axlShape(void);

    /*!
     * Get the vector of vertices.
     */
    QVector<axlPoint*> getVertices(void) const;

    /*!
     * Get the vector of edges.
     */
    QVector<Edge*> getEdges(void) const;

    /*!
     * Get the vector of faces.
     */
    QVector<Face*> getFaces(void) const;

    /*!
     * Get the number of vertices.
     */
    int getVertexCount(void) const;

    /*!
     * Get the number of edges.
     */
    int getEdgeCount(void) const;

    /*!
     * Get the number of faces.
     */
    int getFaceCount(void) const;

    /*!
     * Describe the object.
     */
    virtual QString description(void) const;
    /*!
     * Identify the object
     */
    virtual QString identifier(void) const;

    /*!
     * Insert vertex at index position. The number of allocated vertices should be stricktly bigger than the index.
     */
    void insert_vertex(axlPoint* vertex, int index);

    /*!
     * Insert edge at the index position. The number of allocated edges should be stricktly bigger than the index.
     */
    void insert_edge(Edge* edge, int index);
    void insert_edge(axlAbstractCurveParametric* crv, int si, int ei, int index);

    /*!
     * \brief Sort edges
     *
     * Edges among a loop are not ordered.
     * This function sort them to be adjacent.
     *
     * \param loop the loop to sort
     */
    void sortEdges(Loop* loop);

    /*!
     * \brief Sort loops
     *
     * Edges among a loop are not ordered.
     * This function sort every loop the face contains.
     *
     * \param face the face that contains loops to sort
     */
    void sortLoops(Face* face);

    /*!
     * Insert face at the index position. The number of allocated faces should be stricktly bigger than the index.
     */
    void insert_face(Face *face, int index);
    void insert_face(axlAbstractSurfaceParametric*surf, int *l, int *orient,int *loopsSize, int sizel,int nbLoops, int index);
    void insert_face(axlAbstractSurfaceParametric*surf, int *l, int *orient, int sizel,int sizeOrient, int index);
    void insert_face_with_no_sort(axlAbstractSurfaceParametric*surf, int *l, int *orient, int sizel,int sizeOrient, int index);
    void insert_face_with_no_sort(axlAbstractSurfaceParametric*surf, int *l, int *orient,int *loopsSize, int sizel,int nbLoops, int index);

    /*!
     * Convert an axlShape into a QVariantList. Useful for RPC protocol.
     */
    QVariantList convertDataToQVariant(void) const;
    /*!
     * Convert a QVariantList into an axlShape. Useful for RPC protocol.
     */
    int convertQVariantToData(const QVariantList &data);

public slots:

private:
    axlShapePrivate* d;
};

///*!
// * To be registered to the data factory.
// */
//dtkAbstractData *createaxlShape(void);

#endif // AXLSHAPE_H
