#include <iostream>
#include <cstdio>

#include "structure/CPUGraph.h"
#include "traversal/GraphTraversal.h"

//?#include "Q.h"
#include "util/C.h"

#include <QDebug>

//?#include "GPUGraphTraversal.h"

#define LABEL_V "basic_vertex"
#define LABEL_E "basic_edge"
#define NAME "name"

Q_DECLARE_METATYPE(GraphTraversal*)
Q_DECLARE_METATYPE(Edge*)
Q_DECLARE_METATYPE(Vertex*)
Q_DECLARE_METATYPE(VertexProperty<QVariant>*)

/*
    Opens the edgelist file provided by the user and create a graph out of it.
*/
int main(int argc, char* argv[]) {
    CPUGraph graph;
    GraphTraversalSource* g = graph.traversal();

    QString filename = QString(argv[1]);
    FILE* f = fopen(filename.c_str(), "r");

    char id1[10];
    char id2[10];
    std::set<QString> names;
    while(2 == fscanf(f, "%s %s\n", id1, id2)) {
        qDebug() << id1 << ", " << id2 << "\n";
        Vertex* v1;
        Vertex* v2;

        if(0 == names.count(QString(id1)))
          v1 = QVariant_cast<Vertex*>(g->addV(LABEL_V)->property(NAME, QString(id1))->next());
        else v1 = QVariant_cast<Vertex*>(g->V()->has(NAME, QString(id1))->next());
        names.insert(QString(id1));
        qDebug() << QVariant_cast<uint64_t>(v1->id()) << " " << QVariant_cast<QString>(v1->property(NAME)->value()) << "\n";
        
        if(0 == names.count(QString(id2))) v2 = QVariant_cast<Vertex*>(g->addV(LABEL_V)->property(NAME, QString(id2))->next());
        else v2 = QVariant_cast<Vertex*>(g->V()->has(NAME, QString(id2))->next());
        names.insert(QString(id2));
        qDebug() << QVariant_cast<uint64_t>(v2->id()) << " " << QVariant_cast<QString>(v2->property(NAME)->value()) << "\n";

        qDebug() << QVariant_cast<uint64_t>(v1->id()) << " - - " << QVariant_cast<uint64_t>(v2->id()) << "\n";
        
        try {
            g->V(v1)->addE(LABEL_E)->to(v2)->iterate();
        } catch(const std::exception& err) {
            qDebug() << err.what() << "\n";
            return -1;
        }
    }

    fclose(f);

    g->V()->in()->forEachRemaining([](QVariant& v) {
        Vertex* vtx = QVariant_cast<Vertex*>(v);
        qDebug() << "id: " << QVariant_cast<QString>(vtx->property(NAME)->value()) << "\n";
    });

    qDebug() << "count: " << graph.edges().size() << "\n";
    for(Edge* e : graph.edges()) qDebug() << QVariant_cast<QString>(e->outV()->property(NAME)->value()) << " -> " << QVariant_cast<QString>(e->inV()->property(NAME)->value()) << "\n";

    try {
//        __->both()->id()->forEachRemaining([](QVariant& w) {
// Vertex* v = QVariant_cast<Vertex*>(w);
// QVariant a = v->property("cc")->value();
// qDebug() << QVariant_cast<QString>(v->property(NAME)->value());
// qDebug() << QVariant_cast<uint64_t>(v->property("cc")->value());
//         } );

        g->V()->property("cc", QVariant::fromValue((new GraphTraversal)->both()->id()))
          ->forEachRemaining([](QVariant& w) {
            Vertex* v = QVariant_cast<Vertex*>(w);
            QVariant a = v->property("cc")->value();
            //? qDebug() << a.type().name() << "\n";
            qDebug() << QVariant_cast<QString>(v->property(NAME)->value()) << "/" << QVariant_cast<uint64_t>(v->id()) << ": " << QVariant_cast<uint64_t>(v->property("cc")->value()) << "\n";
        });
    } catch(const std::exception& err) {
        qDebug() << err.what() << "\n";
        return -1;
    }

//    try {
////?
////        GPUGraphTraversal* gpu_trv = dynamic_cast<GPUGraphTraversal*>(dynamic_cast<CPUGraphTraversalSource*>(graph.traversal())->withGPU()->V()->id());
////        gpu_trv->filter(Q<uint64_t>::eq((uint64_t)1, gpu_trv))->iterate();
//    } catch(const std::exception& err) {
//        qDebug() << err.what() << "\n";
//        return -1;
//    }

//    try {
//        qDebug() << "min id: " << QVariant_cast<uint64_t>(graph.traversal()->V()->id()->min(C<uint64_t>::compare())->next()) << "\n";
//        dynamic_cast<CPUGraphTraversalSource*>(graph.traversal())->withGPU()->V()->id()->min(C<uint64_t>::compare())->iterate();
//    } catch(const std::exception& err) {
//        qDebug() << err.what() << "\n";
//        return -1;
//    }

    try {
        qDebug() << "coalesce:";// << std::endl;
        graph.traversal()->V()->coalesce({__->id(), __->id()})->forEachRemaining([](QVariant& i) {
            uint64_t id = QVariant_cast<uint64_t>(i);
            qDebug() << id;// << std::endl;
        });
        qDebug() << "\n";// std::endl;
    } catch(const std::exception& err) {
        qDebug() << err.what(); // << std::endl;
        return -1;
    }
}
