
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


include(../build-group.pri)

#QT += gui  #opengl sql network xml testlib svg

include($$ROOT_DIR/../preferred/sysr.pri)

# this needs ncurses ... maybe it's not in a usual place
# include($$ROOT_DIR/../preferred/ncurses.pri)


HEADERS +=  \
  $$SRC_DIR/BioCoder.h \
  $$SRC_DIR/Graph.h \
  $$SRC_DIR/resource.h \


SOURCES +=  \
  $$SRC_DIR/BioCoder.cpp \
  $$SRC_DIR/Graph.cpp \


