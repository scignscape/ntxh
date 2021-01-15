
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

QT -= gui

include($$ROOT_DIR/../preferred/sysr.pri)

INCLUDEPATH += $$SRC_GROUP_DIR  $$SRC_DIR/thirdparty/yaml-cpp/include

message($$SRC_DIR)

HEADERS += \
  $$SRC_DIR/include/cbicaCmdParser.h \
  $$SRC_DIR/thirdparty/yaml-cpp/include/yaml-cpp/anchor.h \
  $$SRC_DIR/thirdparty/yaml-cpp/include/yaml-cpp/binary.h \
  $$SRC_DIR/thirdparty/yaml-cpp/include/yaml-cpp/emitter.h \
  $$SRC_DIR/thirdparty/yaml-cpp/include/yaml-cpp/emitterdef.h \
  $$SRC_DIR/thirdparty/yaml-cpp/include/yaml-cpp/eventhandler.h \
  $$SRC_DIR/thirdparty/yaml-cpp/include/yaml-cpp/exceptions.h \
  $$SRC_DIR/thirdparty/yaml-cpp/include/yaml-cpp/null.h \
  $$SRC_DIR/thirdparty/yaml-cpp/include/yaml-cpp/ostream_wrapper.h \
  $$SRC_DIR/thirdparty/yaml-cpp/include/yaml-cpp/traits.h \
  $$SRC_DIR/thirdparty/yaml-cpp/include/yaml-cpp/yaml.h \
  $$SRC_DIR/thirdparty/yaml-cpp/include/yaml-cpp/dll.h \
  $$SRC_DIR/thirdparty/yaml-cpp/include/yaml-cpp/emitfromevents.h \
  $$SRC_DIR/thirdparty/yaml-cpp/include/yaml-cpp/emittermanip.h \
  $$SRC_DIR/thirdparty/yaml-cpp/include/yaml-cpp/emitterstyle.h \
  $$SRC_DIR/thirdparty/yaml-cpp/include/yaml-cpp/mark.h \
  $$SRC_DIR/thirdparty/yaml-cpp/include/yaml-cpp/noncopyable.h \
  $$SRC_DIR/thirdparty/yaml-cpp/include/yaml-cpp/parser.h \
  $$SRC_DIR/thirdparty/yaml-cpp/include/yaml-cpp/stlemitter.h \
  $$SRC_DIR/thirdparty/yaml-cpp/include/yaml-cpp/node/convert.h \
  $$SRC_DIR/thirdparty/yaml-cpp/include/yaml-cpp/node/emit.h \
  $$SRC_DIR/thirdparty/yaml-cpp/include/yaml-cpp/node/impl.h \
  $$SRC_DIR/thirdparty/yaml-cpp/include/yaml-cpp/node/node.h \
  $$SRC_DIR/thirdparty/yaml-cpp/include/yaml-cpp/node/parse.h \
  $$SRC_DIR/thirdparty/yaml-cpp/include/yaml-cpp/node/ptr.h \
  $$SRC_DIR/thirdparty/yaml-cpp/include/yaml-cpp/node/iterator.h \
  $$SRC_DIR/thirdparty/yaml-cpp/include/yaml-cpp/node/type.h \
  $$SRC_DIR/thirdparty/yaml-cpp/include/yaml-cpp/node/detail/bool_type.h \
  $$SRC_DIR/thirdparty/yaml-cpp/include/yaml-cpp/node/detail/impl.h \
  $$SRC_DIR/thirdparty/yaml-cpp/include/yaml-cpp/node/detail/iterator.h \
  $$SRC_DIR/thirdparty/yaml-cpp/include/yaml-cpp/node/detail/iterator_fwd.h \
  $$SRC_DIR/thirdparty/yaml-cpp/include/yaml-cpp/node/detail/memory.h \
  $$SRC_DIR/thirdparty/yaml-cpp/include/yaml-cpp/node/detail/node.h \
  $$SRC_DIR/thirdparty/yaml-cpp/include/yaml-cpp/node/detail/node_data.h \
  $$SRC_DIR/thirdparty/yaml-cpp/include/yaml-cpp/node/detail/node_iterator.h \
  $$SRC_DIR/thirdparty/yaml-cpp/include/yaml-cpp/node/detail/node_ref.h \
  $$SRC_DIR/thirdparty/yaml-cpp/include/yaml-cpp/contrib/anchordict.h \
  $$SRC_DIR/thirdparty/yaml-cpp/include/yaml-cpp/contrib/graphbuilder.h \



SOURCES += \
  $$SRC_DIR/include/cbicaCmdParser.cpp \
  $$SRC_DIR/thirdparty/yaml-cpp/src/binary.cpp \
  $$SRC_DIR/thirdparty/yaml-cpp/src/convert.cpp \
  $$SRC_DIR/thirdparty/yaml-cpp/src/directives.cpp \
  $$SRC_DIR/thirdparty/yaml-cpp/src/emit.cpp \
  $$SRC_DIR/thirdparty/yaml-cpp/src/emitfromevents.cpp \
  $$SRC_DIR/thirdparty/yaml-cpp/src/emitter.cpp \
  $$SRC_DIR/thirdparty/yaml-cpp/src/emitterstate.cpp \
  $$SRC_DIR/thirdparty/yaml-cpp/src/emitterutils.cpp \
  $$SRC_DIR/thirdparty/yaml-cpp/src/exceptions.cpp \
  $$SRC_DIR/thirdparty/yaml-cpp/src/exp.cpp \
  $$SRC_DIR/thirdparty/yaml-cpp/src/memory.cpp \
  $$SRC_DIR/thirdparty/yaml-cpp/src/node.cpp \
  $$SRC_DIR/thirdparty/yaml-cpp/src/nodebuilder.cpp \
  $$SRC_DIR/thirdparty/yaml-cpp/src/node_data.cpp \
  $$SRC_DIR/thirdparty/yaml-cpp/src/nodeevents.cpp \
  $$SRC_DIR/thirdparty/yaml-cpp/src/null.cpp \
  $$SRC_DIR/thirdparty/yaml-cpp/src/ostream_wrapper.cpp \
  $$SRC_DIR/thirdparty/yaml-cpp/src/parse.cpp \
  $$SRC_DIR/thirdparty/yaml-cpp/src/parser.cpp \
  $$SRC_DIR/thirdparty/yaml-cpp/src/regex_yaml.cpp \
  $$SRC_DIR/thirdparty/yaml-cpp/src/scanner.cpp \
  $$SRC_DIR/thirdparty/yaml-cpp/src/scanscalar.cpp \
  $$SRC_DIR/thirdparty/yaml-cpp/src/scantag.cpp \
  $$SRC_DIR/thirdparty/yaml-cpp/src/scantoken.cpp \
  $$SRC_DIR/thirdparty/yaml-cpp/src/simplekey.cpp \
  $$SRC_DIR/thirdparty/yaml-cpp/src/singledocparser.cpp \
  $$SRC_DIR/thirdparty/yaml-cpp/src/stream.cpp \
  $$SRC_DIR/thirdparty/yaml-cpp/src/tag.cpp \


