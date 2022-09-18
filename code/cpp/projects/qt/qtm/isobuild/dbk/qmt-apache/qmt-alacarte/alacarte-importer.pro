


QMAKE_CC = gcc-7
QMAKE_CXX = g++-7

CONFIG += c++17

DEFINES += BOOST_LOG_DYN_LINK


INCLUDEPATH += \
   ../../include/


HEADERS += \
 ../../include/importer/importer.hpp


SOURCES += \
 ../../src/alacarte_importer.cpp \
 ../../src/importer/importer.cpp



DESTDIR = ../target

# /quasihome/nlevisrael/osm/alacarte/new-jersey-latest.osm
# /quasihome/nlevisrael/osm/alacarte/nj-data.carte
# /quasihome/nlevisrael/osm/alacarte/district-of-columbia-latest.osm
# /quasihome/nlevisrael/osm/alacarte/dc-data.carte

# /quasihome/nlevisrael/osm/alacarte/sevastopol/sevastopol-latest.osm
# /quasihome/nlevisrael/osm/alacarte/sevastopol-data.carte

# /quasihome/nlevisrael/osm/alacarte/dc/district-of-columbia-latest.osm /quasihome/nlevisrael/osm/alacarte/dc/dc-data.carte

# /quasihome/nlevisrael/osm/alacarte/kherson/kherson_oblast-latest.osm

LIBS += -L$$DESTDIR -lalacarte-lib

LIBS += -lboost_program_options \
   -lboost_system  -lboost_filesystem \
   -lboost_serialization  -lboost_log \
   -lboost_log_setup -lboost_regex -lboost_iostreams \
   -lboost_chrono -lboost_date_time -lboost_atomic \
   -lboost_unit_test_framework \




