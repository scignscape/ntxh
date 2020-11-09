#include "axlShapeBSpline.h"

#include <axlCore/axlShape.h>
#include <axlCore/axlMesh.h>

#include <axlCore/axlPoint.h>

#include <dtkLog/dtkLog.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>


class axlShapeBSplinePrivate
{
public :
    QVector<axlShapeBSpline::ControlPoint *> points;
    QVector<axlShapeBSpline::Edge *> edges;
    QVector<axlShapeBSpline::Face *> faces;

    int sample;

    QMap<QPair<double, double>, double> scalar_values;
    QHash<int, QList<int> > connect;
};

axlShapeBSpline::axlShapeBSpline() : axlAbstractData(), d(new axlShapeBSplinePrivate)
{
    d->sample = 40;
}

axlShapeBSpline::~axlShapeBSpline()
{
}


// /**
// * @brief Emit a signal edgesSeleted
// * @param numEdge : the identifier of the Edge selected.
// */
// void axlShapeBSpline::emitEdgeSelected(int numEdge){

//     if(numEdge < 0 || numEdge >= d->edges.size()){
//         emit edgeSelected(-1, 0,0);
//     }else{

//         int previous = 0;
//         for(int i = 0; i < numEdge;i++){
//             previous = d->edges.at(i)->support->numSamples()-1 + previous;
//         }
//         int n = d->edges.at(numEdge)->support->numSamples();
//         emit edgeSelected(numEdge, previous,n);
//     }
// }


//! Registered the data in the data factory.
/*!
 *
 */
bool axlShapeBSpline::registered(void) {
    return dtkAbstractDataFactory::instance()->registerDataType("axlShapeBSpline", createaxlShapeBSpline);
}


//! Return the "axlShapeBSpline" identifier.Useful for data factory.
/*!
 *
 */
QString axlShapeBSpline::identifier(void) const{
    return "axlShapeBSpline";
}

//! Return a description of the surface.
/*!
 *
 */
QString axlShapeBSpline::description(void) const{
    QString description;
    description.append(identifier());
    description.append( "has ");
    description.append(QString::number(countControlPoints()));
    description.append("control points;");
    description.append(QString::number(countBoundaryEdges()));
    description.append("boundary edges and ");
    description.append(QString::number(d->faces.size()));
    description.append("faces");

    return description;
}

//! Return the order of the surface for the u parameter.
/*!
 *
 */
int axlShapeBSpline::order_u() const{
    if(d->faces.isEmpty())
        return -1;
    else
        return d->faces.first()->support->order_u();
}

//! Return the order of the surface for the v parameter.
/*!
 *
 */
int axlShapeBSpline::order_v() const{
    if(d->faces.isEmpty())
        return -1;
    else
        return d->faces.first()->support->order_v();
}


/**
* @brief Create an axlShapeBSpline from a set of axlAbstractSurfaceBSpline.
* @param dataSet : set of axlAbstractSurfaceBSpline.
*/
void axlShapeBSpline::createSurfaceFromBSplineDataSet(QList<axlAbstractSurfaceBSpline *> dataSet){

    //We suppose all bspline surfaces of dataSet have same orders.
    int order_u = dataSet.first()->order_u();
    int order_v = dataSet.first()->order_v();
    int nbEdges = 0;
    int nbFaces = dataSet.size();

    QVector< QVector<int> >pe;
    QVector< QVector<int> >pf;
    QVector< QPair<int,int> > npf;

    QList<axlPoint > p;
    for(int i = 0; i < dataSet.size(); i++){
        QPair<int, int> pair = QPair<int,int>(dataSet.at(i)->countControlPoints_u(),dataSet.at(i)->countControlPoints_v() );
        QVector<int> pf0;
        for(int j = 1; j <= dataSet.at(i)->countControlPoints();j++){
            const axlPoint& pointa = dataSet.at(i)->getCoef(j);
            if(!isContained(p, pointa, pf0)){
                p.append(pointa);
            }
        }
        pf.append(pf0);
        npf.append(pair);
    }

    int nbpoints = p.size();
    double *points = new double[3*nbpoints];

    for(int i = 0;i < p.size();i++){
        points[3*i] = p.at(i).x();
        points[3*i+1] = p.at(i).y();
        points[3*i+2] = p.at(i).z();
    }

    this->setSurface( order_u, order_v, nbpoints, nbEdges, nbFaces, points, pe, pf, npf );
}

/**
* @brief Create a surface.
* @param order_u : surface order for u parameter.
* @param order_v : surface order for v parameter.
* @param nbpoints : number of control points.
* @param nbEdges : number of edges.
* @param nbFaces : number of faces.
* @param points : points coordinates, size of points is equal to 3*nbpoints.
* @param pe : contains all set of indices to precise what points is owned by each edge.
* @param pf : contains all set of indices to precise what points is owned by each face.
* @param npf : contains all pair of size to precise how many control points for the u-direction and the v-direction, for each face.
*/
void axlShapeBSpline::setSurface(int order_u, int order_v,int nbpoints,int nbEdges, int nbFaces, double *points, QVector< QVector<int> > pe, QVector< QVector<int> >pf, QVector< QPair<int,int> > npf ){

    setControlPoints(nbpoints,points);

    for (int i = 0; i < nbEdges; i++) {
        setEdge(i, pe.at(i),order_u);
    }

    for(int j = 0; j < nbFaces; j++) {
        setFace(j, pf.at(j), order_u, order_v, npf.at(j).first, npf.at(j).second);
    }
}

/** @brief Add control points to the Surface. All points should be on the plane z =0;
* @param nbpoints : number of control points.
* @param points : points coordinates, size of points is equal to 3*nbpoints.
*/
void axlShapeBSpline::setControlPoints(int nbpoints, double *points)
{
    for(int i = 0; i < nbpoints;i++){
        //d->points.append(new ControlPoint(i,points[3*i], points[3*i+1], points[3*i+2]));
        d->points.append(new ControlPoint(i,points[3*i], points[3*i+1], 0));// same plane z = 0;
    }
}

/** @brief Add or modify a face to the Surface.
* @param i : face identifier.
* @param p : set of indices of control points owned by the surface support.
* @param order_u : surface support order for u parameter.
* @param order_v : surface support order for v parameter.
* @param nu : number of control point the u-direction.
* @param nv : number of control point the v-direction.
*/
void axlShapeBSpline::setFace(int i, QVector<int> p, int order_u, int order_v, int nu, int nv)
{
    axlAbstractSurfaceBSpline *surf = dynamic_cast<axlAbstractSurfaceBSpline *>(dtkAbstractDataFactory::instance()->create("goSurfaceBSpline"));
    double *points = fillCoordinates(p);
    double *knots_u = knots(nu,order_u);
    double *knots_v = knots(nv,order_v);
    surf->setSurface(nu,nv, order_u, order_v,3,knots_u, knots_v, points, false);
    surf->setNumSamples_u(d->sample);
    surf->setNumSamples_v(d->sample);
    d->faces.append(new Face(i,nu,nv,p,surf));
    updateFaceEdges(i);
}

/** @brief Add or modify an edge to the Surface.
* @param i : edge identifier.
* @param p : set of indices of control points owned by the face support.
* @param order : curve support order.
*/
void axlShapeBSpline::setEdge(int i,QVector<int> p, int order)
{
    axlAbstractCurveBSpline *curv = dynamic_cast<axlAbstractCurveBSpline *>(dtkAbstractDataFactory::instance()->create("goCurveBSpline"));
    double *points = fillCoordinates(p);
    double *knot = knots(p.size(),order);
    curv->setCurve(p.size(),order,3,knot, points, false);//rational=false, it is a bspline curve (non-rational one)
    curv->setNumSamples(d->sample);
    d->edges.append(new Edge(i,p,curv));
    for(int pts =0; pts < p.size(); pts++ ){
        d->points.at(p.at(pts))->addEdge(i);
    }
}

/** @brief Add or modify a face to the Surface.
* @param i : face identifier.
* @param p : set of indices of control points owned by the surface support.
* @param surf : surface support.
*/
void axlShapeBSpline::setFace(int i, QVector<int> p, axlAbstractSurfaceBSpline *surf)
{
    surf->setNumSamples_u(d->sample);
    surf->setNumSamples_v(d->sample);
    d->faces.append(new Face(i,surf->countControlPoints_u(), surf->countControlPoints_v(),p,surf));
    updateFaceEdges(i);
    for(int pts =0; pts < p.size(); pts++ ){
        d->points.at(p.at(pts))->addFace(i);
    }
}


/** @brief Add or modify an edge to the Surface.
* @param i : edge identifier.
* @param p : set of indices of control points owned by the face support.
* @param curv : curve support.
*/
void axlShapeBSpline::setEdge(int i, QVector<int> p, axlAbstractCurveBSpline *curv)
{
    curv->setNumSamples(d->sample);
    d->edges.append(new Edge(i,p,curv));
    for(int pts =0; pts < p.size(); pts++ ){
        d->points.at(p.at(pts))->addEdge(i);
    }
}

/** @brief Remove an edge.
* @param i : edge identifier.
*/
void axlShapeBSpline::removeEdge(int i)
{
    for(int j = 0; j < d->edges.at(i)->controlPointsIndices.size();j++){
        int index = getPoint(d->edges.at(i)->controlPointsIndices.at(j))->edges.indexOf(i);
        getPoint(d->edges.at(i)->controlPointsIndices.at(j))->edges.remove(index);
    }

    delete d->edges.at(i);
    //d->edges.at(i) = NULL;
    d->edges.remove(i);
}


/** @brief Get a coefficient of the surface.
* @param index : coefficient index.
* @return : return the index-th coefficient.
*/
//coefficients relatifs aux points de controle.
axlPoint axlShapeBSpline::getCoef(int index) const
{
    QVector<double> coord = d->points.at(index-1)->coordinates;
    return axlPoint(coord.first(), coord.at(1),coord.last());
}

/** @brief Modified a coefficient of the surface.
* @param index : coefficient index.
* @return  : return a boolean to know whether the coefficient was modified.
*/
bool axlShapeBSpline::setCoef(int index, double *newCoordinate)
{
    QVector<bool> interRes;

    d->points.at(index-1)->setCoord(newCoordinate);

    for(int i = 0; i < d->edges.size(); i++){
        if(d->edges.at(i)->containsControlPoint(index-1)){
            int ind = d->edges.at(i)->controlPointsIndices.indexOf(index-1);
            interRes.append(d->edges.at(i)->support->setCoef(ind+1, newCoordinate));
        }
    }

    for(int i = 0; i < d->faces.size(); i++){
        if(d->faces.at(i)->containsControlPoint(index-1)){
            int ind = d->faces.at(i)->controlPointsIndices.indexOf(index-1);
            interRes.append(d->faces.at(i)->support->setCoef(ind+1, newCoordinate));
        }
    }
    return !interRes.contains(false);
}

/** @brief Modified a coefficient of the surface.
* @param index : coefficient index.
* @return  : return a boolean to know whether the coefficient was modified.
*/
int axlShapeBSpline::countControlPoints() const
{
    return d->points.size();
}

//double axlShapeBSpline::startParam_u(void)
//{
//    DTK_DEFAULT_IMPLEMENTATION;

//    return 0.;
//}
//double axlShapeBSpline::startParam_v(void)
//{
//    DTK_DEFAULT_IMPLEMENTATION;

//    return 0.;
//}

//double axlShapeBSpline::endParam_u(void)
//{
//    DTK_DEFAULT_IMPLEMENTATION;
//    return 1.;
//}
//double axlShapeBSpline::endParam_v(void)
//{
//    DTK_DEFAULT_IMPLEMENTATION;
//    return 1.;
//}
//int axlShapeBSpline::numSamples_u(void)
//{
//    DTK_DEFAULT_IMPLEMENTATION;

//    return 0;
//}
//int axlShapeBSpline::numSamples_v(void)
//{
//    DTK_DEFAULT_IMPLEMENTATION;

//    return 0;
//}

void axlShapeBSpline::eval(axlPoint *point, double u, double v) {
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(point);
    DTK_UNUSED(u);
    DTK_UNUSED(v);
}

void axlShapeBSpline::normal(axlPoint *normal, double u, double v)
{
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(normal);
    DTK_UNUSED(u);
    DTK_UNUSED(v);
}
double axlShapeBSpline::scalarValue(double u, double v)
{
    return d->scalar_values.value(qMakePair<double, double>(u, v));
}

void axlShapeBSpline::setScalarValue(double u, double v, double value)
{
    d->scalar_values.insert(qMakePair<double, double>(u, v), value);
}

int axlShapeBSpline::stripes(void)
{
    DTK_DEFAULT_IMPLEMENTATION;

    return 0;
}

void axlShapeBSpline::setStripes(int stripes)
{
    DTK_DEFAULT_IMPLEMENTATION;
    DTK_UNUSED(stripes);
}

int axlShapeBSpline::countControlPoints_u(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}

int axlShapeBSpline::countControlPoints_v(void) const
{
    DTK_DEFAULT_IMPLEMENTATION;
    return 0;
}

QList<int> axlShapeBSpline::getControlPointConnection(int i)
{
    return d->connect.value(i);
}

//! Return true if control points connections were defined by developers. False if there are default connections visualization.
/*!
 *
 */
bool axlShapeBSpline::connectionsAreDefined(void){
    return !d->connect.isEmpty();
}

/** @brief Return the first u parameter value of a face.
* @param i : face identifier.
* @return  : the value of the first u parameter.
*/
double axlShapeBSpline::startParam_u(int i){
    return d->faces.at(i)->support->startParam_u();
}

/** @brief Return the first u parameter value of a face.
* @param i : face identifier.
* @return  : the value of the first u parameter.
*/
double axlShapeBSpline::startParam_v(int i){
    return d->faces.at(i)->support->startParam_v();
}

/** @brief Return the last u parameter value of a face.
* @param i : face identifier.
* @return  : the value of the last u parameter.
*/
double axlShapeBSpline::endParam_u(int i){
    return d->faces.at(i)->support->endParam_u();
}

/** @brief Return the last v parameter value of a face.
* @param i : face identifier.
* @return  : the value of the last v parameter.
*/
double axlShapeBSpline::endParam_v(int i){
    return d->faces.at(i)->support->endParam_v();
}

/** @brief Compute coordinates of a point of the Surface.
* @param point : point of the surface.
* @param u : value of the u-parameter.
* @param v : value of the v-parameter.
* @param i : face identifier.
*/
void axlShapeBSpline::eval(axlPoint *point, double u, double v,int i){
    d->faces.at(i)->support->eval(point, u,v);
    point->setCoordinates(point->x(), point->y(), point->z());
}

//! Return whether the surface have several faces.
/*!
 *
 */
bool axlShapeBSpline::hasFaces(void){
    return (d->faces.size()>0);
}

//! Return how many faces.
/*!
 *
 */
int axlShapeBSpline::countFaces(void){
    return d->faces.size();
}

//! Return how many edges.
/*!
 *
 */
int axlShapeBSpline::countBoundaryEdges() const{
    return d->edges.size();
}

/** @brief Return edge.
* @param i : edge identifier.
* @return : the i-th edge of the surface.
*/
axlShapeBSpline::Edge *axlShapeBSpline::getEdge(int i){
    return d->edges.at(i);
}

/** @brief Return face.
* @param i : face identifier.
* @return : the i-th face of the surface.
*/
axlShapeBSpline::Face *axlShapeBSpline::getFace(int i){
    return d->faces.at(i);
}

/** @brief Return control point.
* @param i : control point identifier.
* @return : the i-th control point of the surface.
*/
axlShapeBSpline::ControlPoint *axlShapeBSpline::getPoint(int i){
    return d->points.at(i);
}

/** @brief Mesh subdision on the u-direction.
* @param i : face identifier.
* @return  : number of points obtained by subdivision.
*/
int axlShapeBSpline::numSamples_u(int i){
    return d->faces.at(i)->support->numSamples_u();
}


/** @brief Mesh subdision on the v-direction.
* @param i : face identifier.
* @return  : number of points obtained by subdivision.
*/
int axlShapeBSpline::numSamples_v(int i){
    return d->faces.at(i)->support->numSamples_v();
}


/** @brief Modify mesh subdision on the v-direction. Same for all faces.
* @param numSamples : number of points for the subdivision.
*/
void axlShapeBSpline::setNumSamples_u(int numSamples){
    // axlAbstractSurfaceBSpline::setNumSamples_u(numSamples);

    for(int i = 0;i < d->edges.size();i++){
        d->edges.at(i)->support->setNumSamples(numSamples);
    }

    for(int i = 0;i < d->faces.size();i++){
        d->faces.at(i)->support->setNumSamples_u(numSamples);
    }
}

/** @brief Modify mesh subdision on the v-direction. Same for all faces.
* @param numSamples : number of points for the subdivision.
*/
void axlShapeBSpline::setNumSamples_v(int numSamples) {
    for(int i = 0; i < d->faces.size(); i++){
        d->faces.at(i)->support->setNumSamples_v(numSamples);
    }
}

/** @brief Compute normal.
* @param currentNormal : normal.
* @param paramCourant_u : value of the u-parameter.
* @param paramCourant_v : value of the v-parameter.
* @param indice : face identifier.
*/
void axlShapeBSpline::normal(axlPoint *currentNormal ,double paramCourant_u, double paramCourant_v,int indice){
    d->faces.at(indice)->support->normal(currentNormal,paramCourant_u,paramCourant_v);
}


/** @brief Update indices list of the face edges.
* @param numFace : face identifier.
*/
void axlShapeBSpline::updateFaceEdges(int numFace){

    if(!d->faces.at(numFace)->edgesIndices.isEmpty())
        d->faces.at(numFace)->edgesIndices.clear();

    QVector<int>e;
    QVector<int> p = d->faces.at(numFace)->controlPointsIndices;

    for(int ip =0; ip < p.size(); ip++){
        if(d->points.at(p.at(ip))->edges.size() == 1 ){
            if(!e.contains(d->points.at(p.at(ip))->edges.first())){
                e.push_back(d->points.at(p.at(ip))->edges.first());
            }
        }
    }
    d->faces.at(numFace)->edgesIndices = e;

}

// PRIVATE

/** @brief Create a double tab which contains all coordinates of specified indices point.
* @param p : list of indices of control points.
* @return : list of coordinates of points.
*/
double *axlShapeBSpline::fillCoordinates(QVector<int> p){
    double *point = new double[3*p.size()];
    int ind = 0;

    for(int i= 0; i < p.size();i++){
        point[3*ind] =  d->points.at(p.at(i))->coordinates.first();
        point[3*ind+1] =  d->points.at(p.at(i))->coordinates.at(1);
        point[3*ind+2] =  d->points.at(p.at(i))->coordinates.last();

        ind++;
    }

    return point;
}


/** @brief Create a double tab which contains surface nodes.
* @param pointsCount : number of control points in the current parameter direction.
* @param order : order of the current parameter direction.
* @return : tab of nodes.
*/
double *axlShapeBSpline::knots(int pointsCount, int order)
{
    double *knots = new double[pointsCount + order];
    int knot_number = 1 ;



    for(int i = 0 ; i < order ; i++ )
        knots[i] = 0.0 ;

    for(int i = order ; i < pointsCount ; i++)
        knots[i] = knot_number++ ;

    for(int i = pointsCount ; i < pointsCount + order ; i++)
        knots[i] = knot_number ;



    //        for(int i = 0 ; i < pointsCount + order ; i++)
    //            knots[i] = i ;


    return knots;
}

/** @brief Check is a point was already inserted in a list. Give it an indice.
* @param list : list of points.
* @param p : point to be inserted.
* @param pf : list of point indices.
* @return : boolean to say whether it is contained.
*/
bool axlShapeBSpline::isContained(QList<axlPoint > list, axlPoint p, QVector<int>& pf){
    bool res = false;

    for(int i = 0;i <list.size(); i++){
        axlPoint listP = list.at(i);
        if(listP.x() == p.x() && listP.y()==p.y() && listP.z()==p.z()){
            pf.append(i);
            res = true;
        }
    }

    if(!res){
        int s = pf.size();
        pf.append(s);
    }


    return res;
}


/** @brief Add a point to the control point set of the surface
* @param point : a point.
*/
void axlShapeBSpline::insert_point(axlPoint *point){
    ControlPoint *control = new ControlPoint(d->points.size(),point->x(),point->y(),point->z());
    d->points.append(control);
}


/** @brief Add a point to the control point set of the surface
* @param x : x-coordinate.
* @param y : y-coordinate
* @param z : z-coordinate
*/
void axlShapeBSpline::insert_point(double x, double y, double z){
    ControlPoint *control = new ControlPoint(d->points.size(),x,y,z);
    d->points.append(control);
}


/** @brief Add an edge to the surface
* @param edge : edge of type axlShapeBSpline::Edge.
*/
void axlShapeBSpline::insert_edge(Edge *edge){
    d->edges.append(edge);
}


/** @brief Add a face to the surface
* @param face : face of type axlShapeBSpline::Face.
*/
void axlShapeBSpline::insert_face(Face *face){
    d->faces.append(face);
}

dtkAbstractData *createaxlShapeBSpline(void){
    return new axlShapeBSpline;
}

// /////////////////////////////////////////////////////////////////
// axlDataDynamic documentation
// /////////////////////////////////////////////////////////////////

/*! \class axlShapeBSpline
 *
 *  \brief Class axlShapeBSpline defines a set of boundary curves (Edges) and bspline surface patches (Face).
 *
 *  To build each Edge and Face of an axlShapeBSpline, control points must be specified as their supports are respectively bspline curves and
 *  bspline surfaces. To be sure a control point is shared by different element and not duplicated, control point point must be defines one, even if
 *  it is shared by several Faces and/or Edges.
 *  This type of object is used in mesherplugin, which connect Axel and Num3sis simulator, as a geometry of a problem.
 *  Edges are useful to determine where to apply boundary conditions of a physical problem. Faces are useful for meshing by divided the geometry into
 *  several domains.
 *
 */
