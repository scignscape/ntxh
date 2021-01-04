

#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

include($$ROOT_DIR/../preferred/sysr.pri)

INCLUDEPATH += $$SRC_DIR/gen

INCLUDEPATH += $$SRC_GROUP_DIR

INCLUDEPATH += $$SRC_DIR/


QT -= gui

CONFIG += c++14

QMAKE_EXT_CPP += c++


HEADERS += \
  $$SRC_DIR/any.h \
  $$SRC_DIR/arena.h \
  $$SRC_DIR/blob.h \
  $$SRC_DIR/c++.capnp.h \
  $$SRC_DIR/capability.h \
  $$SRC_DIR/common.h \
  $$SRC_DIR/compat/json.capnp.h \
  $$SRC_DIR/compat/json.h \
  $$SRC_DIR/compat/std-iterator.h \
  $$SRC_DIR/compiler/compiler.h \
  $$SRC_DIR/compiler/error-reporter.h \
  $$SRC_DIR/compiler/grammar.capnp.h \
  $$SRC_DIR/compiler/lexer.capnp.h \
  $$SRC_DIR/compiler/lexer.h \
  $$SRC_DIR/compiler/module-loader.h \
  $$SRC_DIR/compiler/node-translator.h \
  $$SRC_DIR/compiler/parser.h \
  $$SRC_DIR/compiler/type-id.h \
  $$SRC_DIR/dynamic.h \
  $$SRC_DIR/_endian.h \
  $$SRC_DIR/ez-rpc.h \
  $$SRC_DIR/generated-header-support.h \
  $$SRC_DIR/layout.h \
  $$SRC_DIR/list.h \
  $$SRC_DIR/membrane.h \
  $$SRC_DIR/message.h \
  $$SRC_DIR/orphan.h \
  $$SRC_DIR/persistent.capnp.h \
  $$SRC_DIR/pointer-helpers.h \
  $$SRC_DIR/pretty-print.h \
  $$SRC_DIR/raw-schema.h \
  $$SRC_DIR/reconnect.h \
  $$SRC_DIR/rpc-prelude.h \
  $$SRC_DIR/rpc-twoparty.capnp.h \
  $$SRC_DIR/rpc-twoparty.h \
  $$SRC_DIR/rpc.capnp.h \
  $$SRC_DIR/rpc.h \
  $$SRC_DIR/schema-lite.h \
  $$SRC_DIR/schema-loader.h \
  $$SRC_DIR/schema-parser.h \
  $$SRC_DIR/schema.capnp.h \
  $$SRC_DIR/schema.h \
  $$SRC_DIR/serialize-async.h \
  $$SRC_DIR/serialize-packed.h \
  $$SRC_DIR/serialize-text.h \
  $$SRC_DIR/serialize.h \
  $$SRC_DIR/stream.capnp.h \
  $$SRC_DIR/test-util.h


SOURCES += \
\#  $$SRC_DIR/afl-testcase.c++ \
  $$SRC_DIR/any-test.c++ \
  $$SRC_DIR/any.c++ \
  $$SRC_DIR/arena.c++ \
  $$SRC_DIR/blob-test.c++ \
  $$SRC_DIR/blob.c++ \
  $$SRC_DIR/c++.capnp.c++ \
  $$SRC_DIR/canonicalize-test.c++ \
  $$SRC_DIR/capability-test.c++ \
  $$SRC_DIR/capability.c++ \
  $$SRC_DIR/common-test.c++ \
  $$SRC_DIR/compat/json-test.c++ \
  $$SRC_DIR/compat/json.c++ \
  $$SRC_DIR/compat/json.capnp.c++ \
  $$SRC_DIR/compiler/capnp.c++ \
\#  $$SRC_DIR/compiler/capnpc-c++.c++ \
\#  $$SRC_DIR/compiler/capnpc-capnp.c++ \
  $$SRC_DIR/compiler/compiler.c++ \
  $$SRC_DIR/compiler/error-reporter.c++ \
\#  $$SRC_DIR/compiler/evolution-test.c++ \
  $$SRC_DIR/compiler/grammar.capnp.c++ \
  $$SRC_DIR/compiler/lexer-test.c++ \
  $$SRC_DIR/compiler/lexer.c++ \
  $$SRC_DIR/compiler/lexer.capnp.c++ \
  $$SRC_DIR/compiler/module-loader.c++ \
  $$SRC_DIR/compiler/node-translator.c++ \
  $$SRC_DIR/compiler/parser.c++ \
  $$SRC_DIR/compiler/type-id-test.c++ \
  $$SRC_DIR/compiler/type-id.c++ \
  $$SRC_DIR/dynamic-capability.c++ \
  $$SRC_DIR/dynamic-test.c++ \
  $$SRC_DIR/dynamic.c++ \
  $$SRC_DIR/encoding-test.c++ \
  $$SRC_DIR/endian-fallback-test.c++ \
  $$SRC_DIR/endian-reverse-test.c++ \
  $$SRC_DIR/endian-test.c++ \
  $$SRC_DIR/ez-rpc-test.c++ \
  $$SRC_DIR/ez-rpc.c++ \
  $$SRC_DIR/fuzz-test.c++ \
  $$SRC_DIR/layout-test.c++ \
  $$SRC_DIR/layout.c++ \
  $$SRC_DIR/list.c++ \
  $$SRC_DIR/membrane-test.c++ \
  $$SRC_DIR/membrane.c++ \
  $$SRC_DIR/message-test.c++ \
  $$SRC_DIR/message.c++ \
  $$SRC_DIR/orphan-test.c++ \
  $$SRC_DIR/persistent.capnp.c++ \
  $$SRC_DIR/reconnect-test.c++ \
  $$SRC_DIR/reconnect.c++ \
  $$SRC_DIR/rpc-test.c++ \
  $$SRC_DIR/rpc-twoparty-test.c++ \
  $$SRC_DIR/rpc-twoparty.c++ \
  $$SRC_DIR/rpc-twoparty.capnp.c++ \
  $$SRC_DIR/rpc.c++ \
  $$SRC_DIR/rpc.capnp.c++ \
  $$SRC_DIR/schema-loader-test.c++ \
  $$SRC_DIR/schema-loader.c++ \
  $$SRC_DIR/schema-parser-test.c++ \
  $$SRC_DIR/schema-parser.c++ \
  $$SRC_DIR/schema-test.c++ \
  $$SRC_DIR/schema.c++ \
  $$SRC_DIR/schema.capnp.c++ \
  $$SRC_DIR/serialize-async-test.c++ \
  $$SRC_DIR/serialize-async.c++ \
  $$SRC_DIR/serialize-packed-test.c++ \
  $$SRC_DIR/serialize-packed.c++ \
  $$SRC_DIR/serialize-test.c++ \
  $$SRC_DIR/serialize-text-test.c++ \
  $$SRC_DIR/serialize-text.c++ \
  $$SRC_DIR/serialize.c++ \
  $$SRC_DIR/stream.capnp.c++ \
  $$SRC_DIR/stringify-test.c++ \
  $$SRC_DIR/stringify.c++



message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
