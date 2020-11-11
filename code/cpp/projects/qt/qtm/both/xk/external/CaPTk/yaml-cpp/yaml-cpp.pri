
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


include(../build-group.pri)


include($$ROOT_DIR/../preferred/sysr.pri)


INCLUDEPATH += \
  $$SRC_DIR/include


HEADERS += \


SOURCES += \
  $$SRC_DIR/src/binary.cpp \
  $$SRC_DIR/src/convert.cpp \
  $$SRC_DIR/src/directives.cpp \
  $$SRC_DIR/src/emit.cpp \
  $$SRC_DIR/src/emitfromevents.cpp \
  $$SRC_DIR/src/emitter.cpp \
  $$SRC_DIR/src/emitterstate.cpp \
  $$SRC_DIR/src/emitterutils.cpp \
  $$SRC_DIR/src/exceptions.cpp \
  $$SRC_DIR/src/exp.cpp \
  $$SRC_DIR/src/memory.cpp \
  $$SRC_DIR/src/node.cpp \
  $$SRC_DIR/src/nodebuilder.cpp \
  $$SRC_DIR/src/node_data.cpp \
  $$SRC_DIR/src/nodeevents.cpp \
  $$SRC_DIR/src/null.cpp \
  $$SRC_DIR/src/ostream_wrapper.cpp \
  $$SRC_DIR/src/parse.cpp \
  $$SRC_DIR/src/parser.cpp \
  $$SRC_DIR/src/regex_yaml.cpp \
  $$SRC_DIR/src/scanner.cpp \
  $$SRC_DIR/src/scanscalar.cpp \
  $$SRC_DIR/src/scantag.cpp \
  $$SRC_DIR/src/scantoken.cpp \
  $$SRC_DIR/src/simplekey.cpp \
  $$SRC_DIR/src/singledocparser.cpp \
  $$SRC_DIR/src/stream.cpp \
  $$SRC_DIR/src/tag.cpp \
  $$SRC_DIR/src/contrib/graphbuilder.cpp \
  $$SRC_DIR/src/contrib/graphbuilderadapter.cpp \



