
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


include(../build-group.pri)

QT += gui widgets # concurrent opengl  svg #opengl sql network xml testlib

QT += printsupport


include($$ROOT_DIR/../preferred/sysr.pri)
include($$ROOT_DIR/../preferred/gui.pri)

#include($$ROOT_DIR/../preferred/medInria-external.pri)

INCLUDEPATH += $$SRC_GROUP_DIR/qwt

#DEFINES += DTKLOGEXPORT


#INCLUDEPATH += $$SRC_DIR/inc/dtkMeta

HEADERS +=  \
  $$SRC_DIR/qwt_abstract_slider.h \
  $$SRC_DIR/qwt_abstract_scale.h \
  $$SRC_DIR/qwt_arrow_button.h \
  $$SRC_DIR/qwt_analog_clock.h \
  $$SRC_DIR/qwt_compass.h \
  $$SRC_DIR/qwt_compass_rose.h \
  $$SRC_DIR/qwt_counter.h \
  $$SRC_DIR/qwt_dial.h \
  $$SRC_DIR/qwt_dial_needle.h \
  $$SRC_DIR/qwt_knob.h \
  $$SRC_DIR/qwt_slider.h \
  $$SRC_DIR/qwt_thermo.h \
  $$SRC_DIR/qwt_wheel.h


SOURCES +=  \
  $$SRC_DIR/qwt_abstract_slider.cpp \
  $$SRC_DIR/qwt_abstract_scale.cpp \
  $$SRC_DIR/qwt_arrow_button.cpp \
  $$SRC_DIR/qwt_analog_clock.cpp \
  $$SRC_DIR/qwt_compass.cpp \
  $$SRC_DIR/qwt_compass_rose.cpp \
  $$SRC_DIR/qwt_counter.cpp \
  $$SRC_DIR/qwt_dial.cpp \
  $$SRC_DIR/qwt_dial_needle.cpp \
  $$SRC_DIR/qwt_knob.cpp \
  $$SRC_DIR/qwt_slider.cpp \
  $$SRC_DIR/qwt_thermo.cpp \
  $$SRC_DIR/qwt_wheel.cpp
