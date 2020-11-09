#ifndef axlShapeBSpline_H
#define axlShapeBSpline_H

#include "axlCoreExport.h"
#include <axlCore/axlAbstractSurfaceBSpline.h>
#include <axlCore/axlAbstractCurveBSpline.h>

#include <list>

class AXLCORE_EXPORT axlShapeBSplinePrivate;

class AXLCORE_EXPORT axlShapeBSpline : public axlAbstractData
{
    Q_OBJECT

public :

    struct ControlPoint {
        int index;
        QVector<double> coordinates;
        QVector<int> edges;
        QVector<int> faces;

        ControlPoint(int ind, double x =0.0 , double y = 0.0, double z = 0.0) {
            index = ind;
            coordinates << x << y << z;
        }

        void setCoord(double *newCoordinate){
            coordinates.replace(0,newCoordinate[0]);
            coordinates.replace(1,newCoordinate[1]);
            coordinates.replace(2,newCoordinate[2]);
        }

        void addEdge(int numEdge ){
            edges.append(numEdge);
        }

        void addFace(int numFace ){
            faces.append(numFace);
        }

    };

    struct Edge {
        int index;
        QVector<int> controlPointsIndices;
        axlAbstractCurveBSpline *support;
        QString tag;

        Edge(int ind, QVector<int> p, axlAbstractCurveBSpline *curv){
            index = ind;
            controlPointsIndices = p;
            support = curv;
            tag = "interior";
        }

        void setTag(QString t){
            tag = t;
        }

        bool containsControlPoint(int i){
            return controlPointsIndices.contains(i);
        }

        int firstPoint(void){
            return controlPointsIndices.first();
        }

        int lastPoint(void){
            return controlPointsIndices.last();
        }
    };

    struct Face {
        int index;
        QVector<int> controlPointsIndices;
        QVector<int> edgesIndices;
        axlAbstractSurfaceBSpline *support;
        int nbpts_u;
        int nbpts_v;


        Face(int ind, int nu,int nv, QVector<int> p, axlAbstractSurfaceBSpline *surf){
            index = ind;
            controlPointsIndices = p;
            sortControlPoints();
            support = surf;
            nbpts_u = nu;
            nbpts_v = nv;
        }

        bool containsControlPoint(int i){
            return controlPointsIndices.contains(i);
        }

        void sortControlPoints(void){
            std::list<int> l;
            l = controlPointsIndices.toList().toStdList();
            l.sort();
            controlPointsIndices = QVector<int>::fromList(QList<int>::fromStdList(l));

        }
    };

public:
    axlShapeBSpline();
    ~axlShapeBSpline();

public :
    static bool registered(void);
    QString description(void) const;
    QString identifier(void) const;

public:
    // using axlAbstractSurfaceBSpline::setSurface;
    void setSurface(int order_u, int order_v,int nbpoints,int nbEdges, int nbFaces, double *points, QVector< QVector<int> > pe, QVector< QVector<int> >pf, QVector< QPair<int,int> >npf);
    void setControlPoints(int nbpoints,double *points);
    void setFace(int i, QVector<int> p, int order_u, int order_v, int nu, int nv);
    void setFace(int i, QVector<int> p, axlAbstractSurfaceBSpline *surf);
    void setEdge(int i, QVector<int> p, int order);
    void setEdge(int i, QVector<int> p, axlAbstractCurveBSpline *curv);
    void removeEdge(int i);

    void createSurfaceFromBSplineDataSet(QList<axlAbstractSurfaceBSpline *> dataSet);

    //getters
    Edge *getEdge(int i);
    Face *getFace(int i);
    ControlPoint *getPoint(int i);

    //ControlPoints
    axlPoint getCoef(int index) const;
    bool setCoef(int index, double * newCoordinate);

    int countControlPoints() const;
    int countBoundaryEdges() const;

    int order_u() const;
    int order_v() const;

    int numSamples_u(int numCell);
    int numSamples_v(int numCell);
    void setNumSamples_u(int numSamples);
    void setNumSamples_v(int numSamples);

    // -------------------------------
//    int numSamples_u(void);
//    int numSamples_v(void);
//    double startParam_u(void);
//    double startParam_v(void);
//    double endParam_u(void);
//    double endParam_v(void);

    int stripes(void);
    void setStripes(int stripes);
    void normal(axlPoint *normal, double u,double v);
    void eval(axlPoint *point, double u,double v);

    bool connectionsAreDefined(void);
    QList<int> getControlPointConnection(int i); // give all the connections that are still to be made for the ith coefficient.

    int countControlPoints_u(void) const;
    int countControlPoints_v(void) const;

    void selectIndex(int i) { emit indexSelected(i); }
    // -------------------------------
    // Scalar values proof of concept
    double scalarValue(double u, double v);
    void setScalarValue(double u, double v, double value);
    // -------------------------------

    double startParam_u(int i);
    double startParam_v(int i);
    double endParam_u(int i);
    double endParam_v(int i);
    void eval(axlPoint *point, double u, double v,int i);
    void normal(axlPoint *currentNormal, double paramCourant_u, double paramCourant_v,int indice);

    bool hasFaces(void);
    int countFaces(void);

    void insert_point(double x, double y, double z);
    void insert_point(axlPoint *point);
    void insert_edge(Edge *edge);
    void insert_face(Face *face);

    void updateFaceEdges(int numFace);

    void emitEdgeSelected(int numEdge);

// ----------------------
signals:
    void indexSelected(int i);

private :
    double *fillCoordinates(QVector<int> p);
    double *knots(int pointsCount, int order);
    bool isContained(QList<axlPoint> list, axlPoint p, QVector<int>& pf);


private :
    axlShapeBSplinePrivate *d;
};

dtkAbstractData *createaxlShapeBSpline(void);

#endif // axlShapeBSpline_H
