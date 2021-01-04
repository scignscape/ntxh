

#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

include($$ROOT_DIR/../preferred/sysr.pri)

CONFIG += c++14

QMAKE_EXT_CPP += c++


INCLUDEPATH += $$SRC_GROUP_DIR



HEADERS += \
  $$SRC_DIR/arena.h \
  $$SRC_DIR/array.h \
  $$SRC_DIR/async-inl.h \
  $$SRC_DIR/async-io-internal.h \
  $$SRC_DIR/async-io.h \
  $$SRC_DIR/async-prelude.h \
  $$SRC_DIR/async-unix.h \
  $$SRC_DIR/async-win32.h \
  $$SRC_DIR/async.h \
  $$SRC_DIR/common.h \
  $$SRC_DIR/compat/gtest.h \
  $$SRC_DIR/compat/gzip.h \
  $$SRC_DIR/compat/http.h \
  $$SRC_DIR/compat/readiness-io.h \
  $$SRC_DIR/compat/tls.h \
  $$SRC_DIR/compat/url.h \
  $$SRC_DIR/debug.h \
  $$SRC_DIR/encoding.h \
  $$SRC_DIR/exception.h \
  $$SRC_DIR/filesystem.h \
  $$SRC_DIR/function.h \
  $$SRC_DIR/hash.h \
  $$SRC_DIR/io.h \
  $$SRC_DIR/main.h \
  $$SRC_DIR/map.h \
  $$SRC_DIR/memory.h \
  $$SRC_DIR/miniposix.h \
  $$SRC_DIR/mutex.h \
  $$SRC_DIR/one-of.h \
  $$SRC_DIR/parse/char.h \
  $$SRC_DIR/parse/common.h \
  $$SRC_DIR/refcount.h \
  $$SRC_DIR/std/iostream.h \
  $$SRC_DIR/string-tree.h \
  $$SRC_DIR/_string.h \
  $$SRC_DIR/table.h \
  $$SRC_DIR/test.h \
  $$SRC_DIR/thread.h \
  $$SRC_DIR/threadlocal.h \
  $$SRC_DIR/_time.h \
  $$SRC_DIR/timer.h \
  $$SRC_DIR/tuple.h \
  $$SRC_DIR/units.h \
  $$SRC_DIR/vector.h \
  $$SRC_DIR/win32-api-version.h \
  $$SRC_DIR/windows-sanity.h


SOURCES += \
  $$SRC_DIR/arena-test.c++ \
  $$SRC_DIR/arena.c++ \
  $$SRC_DIR/array-test.c++ \
  $$SRC_DIR/array.c++ \
  $$SRC_DIR/async-io-test.c++ \
  $$SRC_DIR/async-io-unix.c++ \
  $$SRC_DIR/async-io-win32.c++ \
  $$SRC_DIR/async-io.c++ \
  $$SRC_DIR/async-test.c++ \
  $$SRC_DIR/async-unix-test.c++ \
  $$SRC_DIR/async-unix-xthread-test.c++ \
  $$SRC_DIR/async-unix.c++ \
  $$SRC_DIR/async-win32-test.c++ \
  $$SRC_DIR/async-win32-xthread-test.c++ \
  $$SRC_DIR/async-win32.c++ \
  $$SRC_DIR/async-xthread-test.c++ \
  $$SRC_DIR/async.c++ \
  $$SRC_DIR/common-test.c++ \
  $$SRC_DIR/common.c++ \
  $$SRC_DIR/compat/gzip-test.c++ \
  $$SRC_DIR/compat/gzip.c++ \
  $$SRC_DIR/compat/http-socketpair-test.c++ \
  $$SRC_DIR/compat/http-test.c++ \
  $$SRC_DIR/compat/http.c++ \
  $$SRC_DIR/compat/readiness-io-test.c++ \
  $$SRC_DIR/compat/readiness-io.c++ \
  $$SRC_DIR/compat/tls-test.c++ \
  $$SRC_DIR/compat/tls.c++ \
  $$SRC_DIR/compat/url-test.c++ \
  $$SRC_DIR/compat/url.c++ \
  $$SRC_DIR/debug-test.c++ \
  $$SRC_DIR/debug.c++ \
  $$SRC_DIR/encoding-test.c++ \
  $$SRC_DIR/encoding.c++ \
  $$SRC_DIR/exception-test.c++ \
  $$SRC_DIR/exception.c++ \
  $$SRC_DIR/filesystem-disk-generic-test.c++ \
  $$SRC_DIR/filesystem-disk-old-kernel-test.c++ \
  $$SRC_DIR/filesystem-disk-test.c++ \
  $$SRC_DIR/filesystem-disk-unix.c++ \
  $$SRC_DIR/filesystem-disk-win32.c++ \
  $$SRC_DIR/filesystem-test.c++ \
  $$SRC_DIR/filesystem.c++ \
  $$SRC_DIR/function-test.c++ \
  $$SRC_DIR/hash.c++ \
  $$SRC_DIR/io-test.c++ \
  $$SRC_DIR/io.c++ \
  $$SRC_DIR/main.c++ \
  $$SRC_DIR/map-test.c++ \
  $$SRC_DIR/memory-test.c++ \
  $$SRC_DIR/memory.c++ \
  $$SRC_DIR/miniposix.c++ \
  $$SRC_DIR/mutex-test.c++ \
  $$SRC_DIR/mutex.c++ \
  $$SRC_DIR/one-of-test.c++ \
  $$SRC_DIR/parse/char-test.c++ \
  $$SRC_DIR/parse/char.c++ \
  $$SRC_DIR/parse/common-test.c++ \
  $$SRC_DIR/refcount-test.c++ \
  $$SRC_DIR/refcount.c++ \
  $$SRC_DIR/std/iostream-test.c++ \
  $$SRC_DIR/string-test.c++ \
  $$SRC_DIR/string-tree-test.c++ \
  $$SRC_DIR/string-tree.c++ \
  $$SRC_DIR/string.c++ \
  $$SRC_DIR/table-test.c++ \
  $$SRC_DIR/table.c++ \
  $$SRC_DIR/test-helpers.c++ \
  $$SRC_DIR/test-test.c++ \
  $$SRC_DIR/test.c++ \
  $$SRC_DIR/thread-test.c++ \
  $$SRC_DIR/thread.c++ \
  $$SRC_DIR/threadlocal-test.c++ \
  $$SRC_DIR/time-test.c++ \
  $$SRC_DIR/time.c++ \
  $$SRC_DIR/timer.c++ \
  $$SRC_DIR/tuple-test.c++ \
  $$SRC_DIR/units-test.c++ \
  $$SRC_DIR/units.c++


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
