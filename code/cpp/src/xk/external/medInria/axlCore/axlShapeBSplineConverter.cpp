#include "axlShapeBSplineConverter.h"

#include <axlCore/axlShapeBSpline.h>
#include <axlCore/axlMesh.h>

#include <dtkLog/dtkLog.h>
#include <dtkCoreSupport/dtkAbstractDataFactory.h>


class axlShapeBSplineConverterPrivate
{
public :
    axlShapeBSpline *shape_spline;
    axlMesh *output;
    //QMap<int,QString> labels;//to link labels selection to the geometry and its mesh ?

    QMap< QPair<int, int>,int> isOnEdge;
    QMap< QPair<int, int>,int> isOnFace;

    int nonInteriorEdgeIndices;

    QList<QString> labelsVertices;
    QList<QString> labelsLines;
    QList<QString> labelsTriangles;
};

axlShapeBSplineConverter::axlShapeBSplineConverter() : axlAbstractDataConverter(), d(new axlShapeBSplineConverterPrivate)
{
    d->shape_spline = NULL;
    d->output = new axlMesh;
}

axlShapeBSplineConverter::~axlShapeBSplineConverter()
{

}

void axlShapeBSplineConverter::setData(dtkAbstractData *data){
    if(axlShapeBSpline *axlData = dynamic_cast<axlShapeBSpline *>(data)){
        d->shape_spline = axlData;
        d->nonInteriorEdgeIndices = d->shape_spline->countBoundaryEdges();
    }
}
//
// dtkAbstractData *axlShapeBSplineConverter::data() const{
//     return d->output;
// }

bool axlShapeBSplineConverter::isContained(axlMesh *mesh){
    return false;
}

axlMesh *axlShapeBSplineConverter::toMesh(void)
{
    if (!d->shape_spline)
        return NULL;

    if(!d->output)
        d->output = new axlMesh;

    axlMesh *mesh = d->output;
    int s = mesh->vertex_count();

    int patch_count = d->shape_spline->countFaces();
    qDebug() << "Number of patches" << d->shape_spline->countFaces();

    // count the number of points
    qlonglong point_counter = 0;
    qlonglong n_u_tot = 0;
    qlonglong n_v_tot = 0;

    for (qlonglong p_idx = 0; p_idx < patch_count; ++p_idx) {
        axlPoint* current_point = new axlPoint(0.,0.,0.);

        double start_u = d->shape_spline->startParam_u(p_idx);
        double start_v = d->shape_spline->startParam_v(p_idx);
        double end_u = d->shape_spline->endParam_u(p_idx);
        double end_v = d->shape_spline->endParam_v(p_idx);

        double n_u = d->shape_spline->numSamples_u(p_idx);
        double n_v = d->shape_spline->numSamples_v(p_idx);

        double interval_u = (double)(end_u - start_u) / (n_u - 1);
        double interval_v = (double)(end_v - start_v) / (n_v - 1);
        double current_param_u = start_u;
        double current_param_v = start_v;

        //point_count += n_u*n_v;

        for (int j = 0; j < n_v; ++j) {
            for (int i = 0; i < n_u; ++i) {

                d->shape_spline->eval(current_point, current_param_u, current_param_v, p_idx);

                // skip interior edges if duplicated
                if (!( ((j == 0)) && (0 < p_idx) && (p_idx < patch_count) ))
                    mesh->push_back_vertex(current_point);

                qDebug() << point_counter << current_point;
                point_counter++;

                current_param_u += interval_u;
            }
            current_param_u = start_u;
            current_param_v += interval_v;
        }
        n_u_tot += n_u;
        n_v_tot += n_v;
    }

    // triangulate the domain
    qlonglong patch_begin_idx = 0;

    for (qlonglong p_idx = 0; p_idx < patch_count; ++p_idx) {

        qDebug() << "Meshing patch" << p_idx;
        int n_u = d->shape_spline->numSamples_u(p_idx);
        int n_v = d->shape_spline->numSamples_v(p_idx);

//        int idx_1 = 0;
//        int idx_2 = 0;

        for (int j = 0; j < n_v - 1; ++j) {
            for (int i = 0; i < n_u - 1; ++i) {
                int idx_1 = j * n_u + i + patch_begin_idx;
                int idx_2 = idx_1 + 1;
                int idx_3 = idx_1 + n_u;
                int idx_4 = idx_3 + 1;

                qDebug() << "idx_1" << idx_1;

                QVector<int> first_triangle;
                QVector<int> second_triangle;

                first_triangle.push_back(s + idx_1);
                first_triangle.push_back(s + idx_2);
                first_triangle.push_back(s + idx_3);

                second_triangle.push_back(s + idx_3);
                second_triangle.push_back(s + idx_2);
                second_triangle.push_back(s + idx_4);

                mesh->push_back_face(first_triangle);
                mesh->push_back_face(second_triangle);
            }
        }

        patch_begin_idx += (n_u)*(n_v) - n_u; // start from the second patch minus the dimension of the linked edge
    }
    qDebug() << "Finished meshing";

    // // mesh blindly knowing the points, not completely working, too much implicit assumptions
    // for (int i = 0; i < point_counter - (n_u_tot * 2); ++i) {
    //     int n_u = d->shape_spline->numSamples_u(0); // test

    //     int idx_1 = i;
    //     int idx_2 = i + 1;
    //     int idx_3 = i + n_v_tot;
    //     int idx_4 = i + n_v_tot + 1;

    //     QVector<int> first_triangle;
    //     QVector<int> second_triangle;

    //     first_triangle.push_back(s + idx_1);
    //     first_triangle.push_back(s + idx_2);
    //     first_triangle.push_back(s + idx_3);

    //     second_triangle.push_back(s + idx_2);
    //     second_triangle.push_back(s + idx_3);
    //     second_triangle.push_back(s + idx_4);

    //     if ((i % (n_u - 1)) == 0)
    //         qDebug() << "YES";

    //     if ( ((i % ((n_u - 1) * (n_u - 1))) != 0) ) {
    //         mesh->push_back_face(first_triangle);
    //         mesh->push_back_face(second_triangle);
    //     }
    // }

    return mesh;
}


QString axlShapeBSplineConverter::description (void) const{
    return "axlShapeBSplineConverter";
}

QStringList axlShapeBSplineConverter::fromTypes(void) const{
    return QStringList();
}

QString axlShapeBSplineConverter::toType (void) const{
    return "axlShapeBSplineConverter";
}

bool axlShapeBSplineConverter::registered(void){
    //return axlMesherPlugin::dataFactSingleton->registerDataConverterType("axlShapeBSplineConverter", QStringList(), "axlMesh", createaxlShapeBSplineConverter);
    return dtkAbstractDataFactory::instance()->registerDataConverterType("axlShapeBSplineConverter", QStringList(), "axlMesh", createaxlShapeBSplineConverter);
}

int axlShapeBSplineConverter::isInterior(int i, int n_u, int n_v){
    bool res = true;
    if(i < n_u || i%n_u == 0 || i >= (n_v-1)*(n_u) || i%n_u == (n_u-1))
        res = false;

    return res;
}

QPair<int,int > axlShapeBSplineConverter::whatEdge(int numFace, int i, int n_u, int n_v){

    if (i < n_u) {
        return QPair<int,int>(d->shape_spline->getFace(numFace)->edgesIndices.first(), i);
    } else if (i >= (n_v-1)*(n_u)) {
        return QPair<int,int>(d->shape_spline->getFace(numFace)->edgesIndices.last(), (i%((n_v-1)*(n_u))));
    } else if (i%n_u == 0 ){
        return QPair<int,int>(d->shape_spline->getFace(numFace)->edgesIndices.at(1), i/n_u);
    } else { //if(i%n_u == (n_u-1))
        return QPair<int,int>(d->shape_spline->getFace(numFace)->edgesIndices.at(2), (i+1)/n_u -1);
    }
}

void axlShapeBSplineConverter::insertEdge(axlMesh *mesh,int numEdge){

    //insert vertices different than first and last point of the mesh of the edge.
    int count = d->output->vertex_count();
    int n = d->shape_spline->getEdge(numEdge)->support->numSamples();
    axlPoint *point = new axlPoint();

    for (int i = 1; i < (n-1); i++) {
        d->output->push_back_vertex(mesh->vertex2(i,point));
        d->labelsVertices.append(d->shape_spline->getEdge(numEdge)->tag);
        d->isOnEdge.insert(QPair<int,int>(numEdge,i), i-1 + count);
    }

    delete point;
    point = NULL;

    if (numEdge < d->nonInteriorEdgeIndices) {
        //insert all edges but with the global indice
        for (int i = 0; i < mesh->edge_count(); i++) {

            int f = d->isOnEdge.value(QPair<int,int>(numEdge,mesh->edge(i).first()));
            int s = d->isOnEdge.value(QPair<int,int>(numEdge,mesh->edge(i).last()));

            d->output->push_back_edge(f,s);
            d->labelsLines.append(d->shape_spline->getEdge(numEdge)->tag);
        }
    }
}

void axlShapeBSplineConverter::insertFace(axlMesh *mesh, int numFace){

    int count = d->output->vertex_count();
    int nu = d->shape_spline->getFace(numFace)->support->numSamples_u();
    int nv = d->shape_spline->getFace(numFace)->support->numSamples_v();

    axlPoint *point = new axlPoint();

    for (int j = 1; j < nv-1; j++) {
        for (int i = 1; i < nu-1; i++) {
            int ind = j*nu+i;
            d->output->push_back_vertex(mesh->vertex2(ind, point));
            d->labelsVertices.append("interior");
            d->isOnFace.insert(QPair<int,int>(numFace,ind), count);
            count++;
        }
    }

    delete point;
    point = NULL;

    //insert all faces
    for (int i = 0; i < mesh->face_count(); i++) {

        int formerf = mesh->face(i).first();
        int formers = mesh->face(i).at(1);
        int formert = mesh->face(i).last();

        int f = 0;
        int s = 0;
        int t = 0;

        if (isInterior(formerf,nu,nv)) {
            f = d->isOnFace.value(QPair<int,int>(numFace, formerf));
        } else {
            QPair<int,int > numEdge = whatEdge(numFace, formerf, nu, nv);
            f = d->isOnEdge.value(numEdge);
        }

        if (isInterior(formers,nu,nv)) {
            s = d->isOnFace.value(QPair<int,int>(numFace, formers));
        } else {
            QPair<int,int > numEdge = whatEdge(numFace, formers, nu, nv);
            s = d->isOnEdge.value(numEdge);
        }

        if (isInterior(formert,nu,nv)) {
            t = d->isOnFace.value(QPair<int,int>(numFace, formert));
        } else {
            QPair<int,int > numEdge = whatEdge(numFace, formert, nu, nv);
            t = d->isOnEdge.value(numEdge);
        }

        d->output->push_back_face(f, s, t);
        d->labelsTriangles.append("interior");
    }
}

QList<QString> axlShapeBSplineConverter::getLabels(int i){
    if(i == 0)
        return d->labelsVertices;
    else if(i == 1)
        return d->labelsLines;
    else
        return d->labelsTriangles;
}

dtkAbstractDataConverter *createaxlShapeBSplineConverter(void){
    return new axlShapeBSplineConverter;
}
