


QMAKE_CC = gcc-7
QMAKE_CXX = g++-7

CONFIG += c++17


TEMPLATE = lib

DEFINES += ALACARTE_QLOG_FILE=\\\"/home/nlevisrael/gits/osm/alacarte-master/-qlog_/qlog.txt\\\"


DESTDIR = ../target


DEFINES += QT_HOOK


DEFINES += BOOST_LOG_DYN_LINK


INCLUDEPATH += \
   ../../include/


INCLUDEPATH += \
  ../../src/_qlog_


HEADERS += \
  ../../src/_qlog_/qt-logger.h \


SOURCES += \
  ../../src/_qlog_/qt-logger.cpp \


SOURCES += \
 ../../src/general/configuration.cpp \
 ../../src/general/geo_object.cpp \
 ../../src/general/geodata.cpp \
 ../../src/general/node.cpp \
 ../../src/general/relation.cpp \
 ../../src/general/way.cpp \
 ../../src/precompiled_header.cpp \
 ../../src/utils/applications.cpp \
 ../../src/utils/archive.cpp \
 ../../src/utils/cached_string.cpp \
 ../../src/utils/colorTable.cpp \
 ../../src/utils/precached_strings.cpp \
 ../../src/utils/random.cpp \
 ../../src/utils/statistic.cpp \
 ../../src/utils/transform.cpp

HEADERS += \
 ../../include/general/configuration.hpp \
 ../../include/general/geo_object.hpp \
 ../../include/general/geodata.hpp \
 ../../include/general/node.hpp \
 ../../include/general/relation.hpp \
 ../../include/general/rtree.hpp \
 ../../include/general/way.hpp \
 ../../include/settings.hpp \
 ../../include/utils/application.hpp \
 ../../include/utils/archive.hpp \
 ../../include/utils/cached_string.hpp \
 ../../include/utils/color.hpp \
 ../../include/utils/colorTable.hpp \
 ../../include/utils/exceptions.hpp \
 ../../include/utils/obj_counter.hpp \
 ../../include/utils/point.hpp \
 ../../include/utils/precached_strings.hpp \
 ../../include/utils/random.hpp \
 ../../include/utils/rect.hpp \
 ../../include/utils/statistic.hpp \
 ../../include/utils/transform.hpp \
 ../../include/utils/typedId.hpp
