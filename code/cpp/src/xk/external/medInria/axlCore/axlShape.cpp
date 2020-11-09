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

#include "axlShape.h"

#include "axlPoint.h"
#include "axlAbstractCurveParametric.h"
#include "axlAbstractSurfaceParametric.h"

#include <dtkCoreSupport/dtkGlobal.h>


// /////////////////////////////////////////////////////////////////
// axlShapePrivate
// /////////////////////////////////////////////////////////////////

class axlShapePrivate {
public:
    int vertexCount;
    int edgeCount;
    int faceCount;

    QVector<axlPoint*> vertices;
    QVector<axlShape::Edge*> edges;
    QVector<axlShape::Face*> faces;
};

// /////////////////////////////////////////////////////////////////
// axlShape implementation
// /////////////////////////////////////////////////////////////////

axlShape::axlShape(int vertexCount, int edgeCount, int faceCount, axlShape *parent) :
    axlAbstractData(parent),
    d(new axlShapePrivate) {

    d->vertexCount = vertexCount;
    d->edgeCount = edgeCount;
    d->faceCount = faceCount;

    d->vertices = QVector<axlPoint*>(vertexCount, NULL);
    d->edges = QVector<Edge*>(edgeCount, NULL);
    d->faces = QVector<Face*>(faceCount, NULL);

    this->setObjectName(this->identifier());
}

axlShape::~axlShape(void) {
    delete d;
    d = NULL;
}

QVector<axlPoint*> axlShape::getVertices(void) const {
    return d->vertices;
}

QVector<axlShape::Edge*> axlShape::getEdges(void) const {
    return d->edges;
}

QVector<axlShape::Face*> axlShape::getFaces(void) const {
    return d->faces;
}

int axlShape::getVertexCount(void) const {
    return d->vertexCount;
}

int axlShape::getEdgeCount(void) const {
    return d->edgeCount;
}

int axlShape::getFaceCount(void) const {
    return d->faceCount;
}

QString axlShape::description(void) const {
    QString desc = "axlShape:\n";
    desc += " #Vertices: " + QString::number(d->vertexCount) + "\n";
    desc += " #Edges: " + QString::number(d->edgeCount) + "\n";
    desc += " #Faces: " + QString::number(d->faceCount) + "\n\n";

    for (int k = 0; k < d->faceCount; k++) {

        int nbLoops = d->faces.at(k)->loops.size();
        desc += "\nFace\t#" + QString::number(k) + ":\t" + QString::number(nbLoops) + " loop(s)\n";
        for (int i = 0; i < nbLoops; i++) {
            int nbEdges = d->faces.at(k)->loops.at(i)->edges.size();
            desc += " Loop\t#" + QString::number(i) + ":\t" + QString::number(nbEdges) + " edge(s)\n";
            for (int j = 0; j < nbEdges; j++) {
                int currIndexEdge = d->faces.at(k)->loops.at(i)->edges.at(j);
                if (currIndexEdge > -1 && currIndexEdge < d->edges.size()) {
                    axlShape::Edge* edge = d->edges.at(currIndexEdge);
                    if (edge) {
                        axlAbstractCurveParametric* currCurve = edge->curve;
                        if (currCurve) {
                            desc += "  Edge\t#" + QString::number(j) + ":\t(" + currCurve->identifier() + ")\n";
                        } else
                            desc += "  Edge\t#" + QString::number(j) + ":\tcurve NULL\n";
                    } else {
                        desc += "  Edge\t#" + QString::number(j) + ":\tNULL\n";
                    }
                } else {
                    desc += "  Index of Edge out of range:" + QString::number(currIndexEdge) + "\n";
                }
            }
        }
        axlAbstractSurfaceParametric* currSurf = d->faces.at(k)->surface;
        if (currSurf)
            desc += " Surface\t:" + currSurf->identifier() + "\n";
        else
            desc += " Surface is NULL\n";
    }

    return desc;
}

QString axlShape::identifier(void) const {
    return "axlShape";
}

void axlShape::insert_vertex(axlPoint* vertex, int index) {
    d->vertices.replace(index, vertex);
}

void axlShape::insert_edge(Edge* edge, int index) {
    d->edges.replace(index, edge);
}

void axlShape::insert_edge(axlAbstractCurveParametric* crv, int si, int ei, int index) {
    axlShape::Edge *edge = new axlShape::Edge(crv, si, ei);
    d->edges.replace(index, edge);
}

void axlShape::sortEdges(Loop* loop) {
    // Vector to store edges and orientation after sort
    QVector<int> edgesSorted;
    QVector<bool> orientationsSorted;

    // Get edges and orientation to sort
    QVector<int> edges = loop->edges;
    QVector<bool> orientations = loop->orientations;

    // First edge index and orientation variables
    int fstEdgeIndex;
    bool fstOrientation;

    // Browse every edges
    for (int k = 0; k < edges.size()-1; k++) {
        // Choose the first edge to start
        if (k == 0) {
            // Get first edge index and first orientation
            fstEdgeIndex = edges.at(k);
            fstOrientation = orientations.at(k);
            // Record first edge index and orientation inside sorted vectors
            edgesSorted << fstEdgeIndex;
            orientationsSorted << fstOrientation;
        }

        // Get real current first edge from index
        Edge* fstEdge = d->edges.at(fstEdgeIndex);

        // Record current first index into p1, depending on orientation boolean value
        int p1;
        if (fstOrientation)
            p1 = fstEdge->indexStartVertex;
        else
            p1 = fstEdge->indexEndVertex;

        // Second edge index and orientation variables
        int sndEdgeIndex;
        bool sndOrientation;

        // Browse every other edges, looking for second edge, according to orientation and current first edge
        for (int i = 1; i <= edges.size(); i++) {
            // Current index, modulo number of edge indices
            int currIndex = (k+i)%edges.size();
            // Current edge index among other ones
            sndEdgeIndex = edges.at(currIndex);

            // Get real current second edge from index
            Edge* sndEdge = d->edges.at(sndEdgeIndex);
            // Get corresponding second orientation
            sndOrientation = orientations.at(currIndex);


            // Record current second index into p2, depending on orientation boolean value
            int p2;
            if (sndOrientation)
                p2 = sndEdge->indexEndVertex;
            else
                p2 = sndEdge->indexStartVertex;

            // If p1 equals to p2, then the current second edge is the current first edge following one
            if (p1 == p2) {

                // Record second edge index and orientation inside sorted vectors
                edgesSorted << sndEdgeIndex;
                orientationsSorted << sndOrientation;
                // current first edge index and first orientation become the second ones for the next loop turn
                fstEdgeIndex = sndEdgeIndex;
                fstOrientation = sndOrientation;

                // No need to look for other edges
                break;

                // If p1 does not equal to p2, and we already tested every other ones, then we got a situation
            } else if (i == edges.size()) {
                dtkError() << "Error within void axlShape::sortEdges";
                return;
            }
        }
    }

    // Replace old vectors by sorted vectors
    loop->edges = edgesSorted;
    loop->orientations = orientationsSorted;
}

void axlShape::sortLoops(Face* face) {
    for (int k = 0; k < face->loops.size(); k++) {
        sortEdges(face->loops.at(k));
    }
}

void axlShape::insert_face(axlAbstractSurfaceParametric*surf, int *l, int *orient,int *loopsSize, int sizel,int nbLoops, int index) {
    axlShape::Face *face = new axlShape::Face;
    QVector<axlShape::Loop *> loops;
    face->surface = surf;
    for(int k = 0;k < nbLoops;k++){
        loops <<  new axlShape::Loop;
        for(int i=0;i < loopsSize[k];i++){
            if(k==0){
                loops.at(k)->edges << l[i];
                loops.at(k)->orientations << orient[i];
            }else{
                loops.at(k)->edges << l[i+loopsSize[k-1]];
                loops.at(k)->orientations << orient[i+loopsSize[k-1]];
            }
        }
    }
    face->loops << loops;
    sortLoops(face);
    d->faces.replace(index, face);
}

void axlShape::insert_face_with_no_sort(axlAbstractSurfaceParametric*surf, int *l, int *orient,int *loopsSize, int sizel,int nbLoops, int index) {
    axlShape::Face *face = new axlShape::Face;
    QVector<axlShape::Loop *> loops;
    face->surface = surf;
    for(int k = 0;k < nbLoops;k++){
        loops <<  new axlShape::Loop;
        for(int i=0;i < loopsSize[k];i++){
            if(k==0){
                loops.at(k)->edges << l[i];
                loops.at(k)->orientations << orient[i];
            }else{
                loops.at(k)->edges << l[i+loopsSize[k-1]];
                loops.at(k)->orientations << orient[i+loopsSize[k-1]];
            }
        }
    }
    face->loops << loops;
    d->faces.replace(index, face);
}

void axlShape::insert_face(axlAbstractSurfaceParametric*surf, int *l, int *orient, int sizel,int sizeOrient, int index){
    axlShape::Face *face = new axlShape::Face;
    face->surface = surf;
    axlShape::Loop *loop = new axlShape::Loop;
    for(int i=0;i < sizel;i++){
        loop->edges << l[i];
    }
    for(int j=0;j < sizeOrient;j++){
        loop->orientations << orient[j];
    }
    face->loops << loop;
    sortLoops(face);
    d->faces.replace(index, face);
}

void axlShape::insert_face_with_no_sort(axlAbstractSurfaceParametric*surf, int *l, int *orient, int sizel,int sizeOrient, int index){
    axlShape::Face *face = new axlShape::Face;
    face->surface = surf;
    axlShape::Loop *loop = new axlShape::Loop;
    for(int i=0;i < sizel;i++){
        loop->edges << l[i];
    }
    for(int j=0;j < sizeOrient;j++){
        loop->orientations << orient[j];
    }
    face->loops << loop;
    d->faces.replace(index, face);
}

void axlShape::insert_face(Face* face, int index) {
    sortLoops(face);
    d->faces.replace(index, face);
}


QVariantList axlShape::convertDataToQVariant(void) const{
    QVariantList list;
    QVariant id = QVariant::fromValue(identifier());
    QVariant vertexCount = QVariant::fromValue(d->vertexCount);
    QVariant faceCount = QVariant::fromValue(d->faceCount);
    QVariant edgeCount = QVariant::fromValue(d->edgeCount);



    list.append(id);
    list.append(vertexCount);
    list.append(faceCount);
    list.append(edgeCount);

    //add vertices
    for(int i = 0; i< d->vertexCount;i++){
        list.append(d->vertices.at(i)->convertDataToQVariant());
    }

    //add edges
    for(int i = 0; i< d->edgeCount;i++){
        //list.append(d->edges.at(i));
    }

    //add faces
    for(int i = 0; i< d->faceCount;i++){
        //list.append(d->faces.at(i));
    }

    QVariant name = QVariant::fromValue(objectName());
    list.append(name);
    return list;

}

int axlShape::convertQVariantToData(const QVariantList &data){

    //    d->vertex_count = data.at(1).toInt();
    //    d->face_count = data.at(2).toInt();
    //    d->edge_count = data.at(3).toInt();

    int newBegin = 4;
    //fill vertices
    for(int i = 0; i< data.at(1).toInt();i++){
        //first index is for the identifier
        double x = data.at(4*i+1+newBegin).toDouble() ;
        double y = data.at(4*i+2+newBegin).toDouble();
        double z = data.at(4*i+3+newBegin).toDouble();
        axlPoint *point = new axlPoint(x,y,z);
        insert_vertex(point,i);
        delete point;
    }
    //A point is defined with four variables, its three coordinates table and its identifier
    newBegin = (4*d->vertexCount)+newBegin;


    //    //fill edges
    //    for(int i = 0; i< data.at(2).toInt();i++){
    //        int indiceEdge = newBegin+i;
    //        newBegin = newBegin+3;
    //    }

    //    newBegin = newBegin+ d->edgeCount;

    //    //fill faces
    //    for(int i = 0; i< data.at(3).toInt();i++){
    //        int indiceEdge = newBegin+i;
    //        int nb = data.at(indiceEdge).toInt();
    //        Face f;
    //        for(int j=1;j <= nb;j++){
    //            qDebug() << Q_FUNC_INFO << indiceEdge <<data.at(indiceEdge+j).toInt() ;
    //            f.append(data.at(indiceEdge+j).toInt());
    //        }
    //        push_back_face(f);
    //        newBegin = newBegin+nb;

    //    }

    setObjectName(data.last().toString());

    return 1;


}

////to be registered to the data factory.
//dtkAbstractData *createaxlShape(void)
//{
//    return new axlShape;
//}
