

QT += gui

CONFIG += no_keywords


QMAKE_CC = gcc-7
QMAKE_CXX = g++-7

CONFIG += c++17


INCLUDEPATH += \
  /usr/include/cairo \


INCLUDEPATH += \
  ../../src/server/_qmt_


DEFINES += QT_HOOK


INCLUDEPATH += \
  ../../src/_qlog_ \


INCLUDEPATH += \
  ../../include


HEADERS += \
  ../../src/_run-console_/qmt-shape-object.h \
  ../../src/_run-console_/qmt-painter.h \
  ../../src/_run-console_/qmt-paint-context.h \
  ../../src/_run-console_/qmt-render-broker.h \


SOURCES += \
 ../../src/_run-console_/main.cpp \
 ../../src/_run-console_/qmt-shape-object.cpp \
 ../../src/_run-console_/qmt-painter.cpp \
 ../../src/_run-console_/qmt-paint-context.cpp \
 ../../src/_run-console_/qmt-render-broker.cpp \


DESTDIR = ../target

ALACARTE_QLOG_DIR = ../../../alacarte-master/-qlog_

DEFINES += ALACARTE_QLOG_FOLDER=\\\"$${ALACARTE_QLOG_DIR}\\\"

DEFINES += ALACARTE_QLOG_FILE=\\\"$${ALACARTE_QLOG_DIR}/qlog.txt\\\"

DEFINES += ALACARTE_QLOG_IMAGES_FOLDER=\\\"$${ALACARTE_QLOG_DIR}/images\\\"


LIBS += -L$$DESTDIR -lalacarte-lib  -lalacarte-server-lib



LIBS += -lboost_program_options \
   -lboost_system  -lboost_filesystem \
   -lboost_serialization  -lboost_log  -lboost_thread \
   -lboost_log_setup -lboost_regex -lboost_iostreams \
   -lboost_chrono -lboost_date_time -lboost_atomic \
   -lboost_unit_test_framework \


LIBS += -lcairo



