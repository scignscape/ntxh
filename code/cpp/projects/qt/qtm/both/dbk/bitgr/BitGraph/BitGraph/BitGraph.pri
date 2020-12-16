
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

QT += core 

QT -= gui

DEFINES += USE_KANS

include($$ROOT_DIR/../preferred/sysr.pri)

include($$ROOT_DIR/../preferred/boost.pri)


TEMPLATE = app

INCLUDEPATH += $$SRC_PROSET_DIR/BitGraph

INCLUDEPATH += $$SRC_PROSET_DIR/Gremlin/gremlin
# .. \


HEADERS += \
  $$SRC_DIR/index/Index.h \
  $$SRC_DIR/step/BitGraphStep.h \
  $$SRC_DIR/step/GPUFilterStep.h \
  $$SRC_DIR/step/HasWithIndexStep.h \
  $$SRC_DIR/step/IndexStep.h \
  $$SRC_DIR/strategy/BitGraphStrategy.h \
  $$SRC_DIR/structure/BitEdge.h \
  $$SRC_DIR/structure/BitVertex.h \
  $$SRC_DIR/structure/CPUGraph.h \
  $$SRC_DIR/traversal/CPUGraphTraversal.h \
  $$SRC_DIR/traversal/CPUGraphTraversalSource.h \



HEADERS += \
  $$SRC_PROSET_DIR/Gremlin/gremlin/step/IdStep.h \
  $$SRC_PROSET_DIR/Gremlin/gremlin/step/InjectStep.h \
  $$SRC_PROSET_DIR/Gremlin/gremlin/step/TraversalStep.h \
  $$SRC_PROSET_DIR/Gremlin/gremlin/step/edge/AddEdgeStartStep.h \
  $$SRC_PROSET_DIR/Gremlin/gremlin/step/edge/AddEdgeStep.h \
  $$SRC_PROSET_DIR/Gremlin/gremlin/step/graph/GraphStep.h \
  $$SRC_PROSET_DIR/Gremlin/gremlin/step/logic/CoalesceStep.h \
  $$SRC_PROSET_DIR/Gremlin/gremlin/step/logic/IdentityStep.h \
  $$SRC_PROSET_DIR/Gremlin/gremlin/step/logic/NoOpStep.h \
  $$SRC_PROSET_DIR/Gremlin/gremlin/step/math/CountStep.h \
  $$SRC_PROSET_DIR/Gremlin/gremlin/step/math/MinStep.h \
  $$SRC_PROSET_DIR/Gremlin/gremlin/step/modulate/FromStep.h \
  $$SRC_PROSET_DIR/Gremlin/gremlin/step/modulate/ToStep.h \
  $$SRC_PROSET_DIR/Gremlin/gremlin/step/property/AddPropertyStep.h \
  $$SRC_PROSET_DIR/Gremlin/gremlin/step/property/HasStep.h \
  $$SRC_PROSET_DIR/Gremlin/gremlin/step/property/PropertyStep.h \
  $$SRC_PROSET_DIR/Gremlin/gremlin/step/vertex/AddVertexStartStep.h \
  $$SRC_PROSET_DIR/Gremlin/gremlin/step/vertex/AddVertexStep.h \
  $$SRC_PROSET_DIR/Gremlin/gremlin/step/vertex/VertexStep.h \
  $$SRC_PROSET_DIR/Gremlin/gremlin/strategy/AddEdgeStepCompletionStrategy.h \
  $$SRC_PROSET_DIR/Gremlin/gremlin/strategy/TraversalStrategy.h \
  $$SRC_PROSET_DIR/Gremlin/gremlin/structure/Direction.h \
  $$SRC_PROSET_DIR/Gremlin/gremlin/structure/Edge.h \
  $$SRC_PROSET_DIR/Gremlin/gremlin/structure/Element.h \
  $$SRC_PROSET_DIR/Gremlin/gremlin/structure/Graph.h \
  $$SRC_PROSET_DIR/Gremlin/gremlin/structure/Property.h \
  $$SRC_PROSET_DIR/Gremlin/gremlin/structure/Vertex.h \
  $$SRC_PROSET_DIR/Gremlin/gremlin/structure/VertexProperty.h \
  $$SRC_PROSET_DIR/Gremlin/gremlin/traversal/GraphTraversal.h \
  $$SRC_PROSET_DIR/Gremlin/gremlin/traversal/GraphTraversalSource.h \
  $$SRC_PROSET_DIR/Gremlin/gremlin/traversal/P.h \
  $$SRC_PROSET_DIR/Gremlin/gremlin/traversal/Scope.h \
  $$SRC_PROSET_DIR/Gremlin/gremlin/traversal/Traverser.h \
  $$SRC_PROSET_DIR/Gremlin/gremlin/util/C.h


#SOURCES += \
#  $$SRC_DIR/components.cpp \


SOURCES += \
  $$SRC_DIR/ingest_simple.cpp \



#LIBS += -lOpenCL


