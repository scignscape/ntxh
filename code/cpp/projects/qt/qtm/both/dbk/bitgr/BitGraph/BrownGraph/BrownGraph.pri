
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

QT += core 

QT -= gui

DEFINES += USE_KANS

include($$ROOT_DIR/../preferred/sysr.pri)

include($$ROOT_DIR/../preferred/boost.pri)


#TEMPLATE = app

#INCLUDEPATH += $$SRC_PROSET_DIR/BitGraph

INCLUDEPATH += $$SRC_PROSET_DIR/Brownie/brownie
# .. \

INCLUDEPATH += $$RELAE_GRAPH_SRC_GROUP_DIR


HEADERS += \
  $$SRC_DIR/index/Index.h \
  $$SRC_DIR/step/BrownGraphStep.h \
  $$SRC_DIR/step/GPUFilterStep.h \
  $$SRC_DIR/step/HasWithIndexStep.h \
  $$SRC_DIR/step/IndexStep.h \
  $$SRC_DIR/strategy/BrownGraphStrategy.h \
  $$SRC_DIR/structure/BrownEdge.h \
  $$SRC_DIR/structure/BrownVertex.h \
  $$SRC_DIR/structure/BrownGraph.h \
  $$SRC_DIR/traversal/CPUGraphTraversal.h \
  $$SRC_DIR/traversal/CPUGraphTraversalSource.h \
  $$SRC_DIR/traversal/BrownTraverser.h \
  $$SRC_DIR/qmetas.h


SOURCES += \
  $$SRC_DIR/structure/BrownGraph.cpp \


HEADERS += \
  $$SRC_PROSET_DIR/Brownie/brownie/step/IdStep.h \
  $$SRC_PROSET_DIR/Brownie/brownie/step/InjectStep.h \
  $$SRC_PROSET_DIR/Brownie/brownie/step/TraversalStep.h \
  $$SRC_PROSET_DIR/Brownie/brownie/step/edge/AddEdgeStartStep.h \
  $$SRC_PROSET_DIR/Brownie/brownie/step/edge/AddEdgeStep.h \
  $$SRC_PROSET_DIR/Brownie/brownie/step/graph/GraphStep.h \
  $$SRC_PROSET_DIR/Brownie/brownie/step/logic/CoalesceStep.h \
  $$SRC_PROSET_DIR/Brownie/brownie/step/logic/IdentityStep.h \
  $$SRC_PROSET_DIR/Brownie/brownie/step/logic/NoOpStep.h \
  $$SRC_PROSET_DIR/Brownie/brownie/step/math/CountStep.h \
  $$SRC_PROSET_DIR/Brownie/brownie/step/math/MinStep.h \
  $$SRC_PROSET_DIR/Brownie/brownie/step/modulate/FromStep.h \
  $$SRC_PROSET_DIR/Brownie/brownie/step/modulate/ToStep.h \
  $$SRC_PROSET_DIR/Brownie/brownie/step/property/AddPropertyStep.h \
  $$SRC_PROSET_DIR/Brownie/brownie/step/property/HasStep.h \
  $$SRC_PROSET_DIR/Brownie/brownie/step/property/PropertyStep.h \
  $$SRC_PROSET_DIR/Brownie/brownie/step/vertex/AddVertexStartStep.h \
  $$SRC_PROSET_DIR/Brownie/brownie/step/vertex/AddVertexStep.h \
  $$SRC_PROSET_DIR/Brownie/brownie/step/vertex/VertexStep.h \
  $$SRC_PROSET_DIR/Brownie/brownie/strategy/AddEdgeStepCompletionStrategy.h \
  $$SRC_PROSET_DIR/Brownie/brownie/strategy/TraversalStrategy.h \
  $$SRC_PROSET_DIR/Brownie/brownie/structure/Direction.h \
  $$SRC_PROSET_DIR/Brownie/brownie/structure/Edge.h \
  $$SRC_PROSET_DIR/Brownie/brownie/structure/Element.h \
  $$SRC_PROSET_DIR/Brownie/brownie/structure/Graph.h \
  $$SRC_PROSET_DIR/Brownie/brownie/structure/Property.h \
  $$SRC_PROSET_DIR/Brownie/brownie/structure/Vertex.h \
  $$SRC_PROSET_DIR/Brownie/brownie/structure/VertexProperty.h \
  $$SRC_PROSET_DIR/Brownie/brownie/traversal/GraphTraversal.h \
  $$SRC_PROSET_DIR/Brownie/brownie/traversal/GraphTraversalSource.h \
  $$SRC_PROSET_DIR/Brownie/brownie/traversal/P.h \
  $$SRC_PROSET_DIR/Brownie/brownie/traversal/Scope.h \
  $$SRC_PROSET_DIR/Brownie/brownie/traversal/Traverser.h \
  $$SRC_PROSET_DIR/Brownie/brownie/util/C.h



QMAKE_CXXFLAGS += -fopenmp

LIBS += -fopenmp


#LIBS += -lOpenCL


