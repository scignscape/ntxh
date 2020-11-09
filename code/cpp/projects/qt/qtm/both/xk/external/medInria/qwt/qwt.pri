
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


include(../build-group.pri)

QT += gui widgets  svg # concurrent opengl  svg #opengl sql network xml testlib

QT += printsupport


include($$ROOT_DIR/../preferred/sysr.pri)
include($$ROOT_DIR/../preferred/gui.pri)

#include($$ROOT_DIR/../preferred/medInria-external.pri)


HEADERS +=  \
  $$SRC_DIR/qwt.h \
  $$SRC_DIR/qwt_event_pattern.h \
  $$SRC_DIR/qwt_abstract_scale_draw.h \
  $$SRC_DIR/qwt_clipper.h \
  $$SRC_DIR/qwt_color_map.h \
  $$SRC_DIR/qwt_compat.h \
  $$SRC_DIR/qwt_column_symbol.h \
  $$SRC_DIR/qwt_date.h \
  $$SRC_DIR/qwt_date_scale_draw.h \
  $$SRC_DIR/qwt_date_scale_engine.h \
  $$SRC_DIR/qwt_dyngrid_layout.h \
  $$SRC_DIR/qwt_global.h \
  $$SRC_DIR/qwt_graphic.h \
  $$SRC_DIR/qwt_interval.h \
  $$SRC_DIR/qwt_interval_symbol.h \
  $$SRC_DIR/qwt_math.h \
  $$SRC_DIR/qwt_magnifier.h \
  $$SRC_DIR/qwt_null_paintdevice.h \
  $$SRC_DIR/qwt_painter.h \
  $$SRC_DIR/qwt_painter_command.h \
  $$SRC_DIR/qwt_panner.h \
  $$SRC_DIR/qwt_picker.h \
  $$SRC_DIR/qwt_picker_machine.h \
  $$SRC_DIR/qwt_pixel_matrix.h \
  $$SRC_DIR/qwt_point_3d.h \
  $$SRC_DIR/qwt_point_polar.h \
  $$SRC_DIR/qwt_round_scale_draw.h \
  $$SRC_DIR/qwt_scale_div.h \
  $$SRC_DIR/qwt_scale_draw.h \
  $$SRC_DIR/qwt_scale_engine.h \
  $$SRC_DIR/qwt_scale_map.h \
  $$SRC_DIR/qwt_spline.h \
  $$SRC_DIR/qwt_symbol.h \
  $$SRC_DIR/qwt_system_clock.h \
  $$SRC_DIR/qwt_text_engine.h \
  $$SRC_DIR/qwt_text_label.h \
  $$SRC_DIR/qwt_text.h \
  $$SRC_DIR/qwt_transform.h \
  $$SRC_DIR/qwt_widget_overlay.h


SOURCES +=  \
  $$SRC_DIR/qwt_abstract_scale_draw.cpp \
  $$SRC_DIR/qwt_clipper.cpp \
  $$SRC_DIR/qwt_color_map.cpp \
  $$SRC_DIR/qwt_column_symbol.cpp \
  $$SRC_DIR/qwt_date.cpp \
  $$SRC_DIR/qwt_date_scale_draw.cpp \
  $$SRC_DIR/qwt_date_scale_engine.cpp \
  $$SRC_DIR/qwt_dyngrid_layout.cpp \
  $$SRC_DIR/qwt_event_pattern.cpp \
  $$SRC_DIR/qwt_graphic.cpp \
  $$SRC_DIR/qwt_interval.cpp \
  $$SRC_DIR/qwt_interval_symbol.cpp \
  $$SRC_DIR/qwt_math.cpp \
  $$SRC_DIR/qwt_magnifier.cpp \
  $$SRC_DIR/qwt_null_paintdevice.cpp \
  $$SRC_DIR/qwt_painter.cpp \
  $$SRC_DIR/qwt_painter_command.cpp \
  $$SRC_DIR/qwt_panner.cpp \
  $$SRC_DIR/qwt_picker.cpp \
  $$SRC_DIR/qwt_picker_machine.cpp \
  $$SRC_DIR/qwt_pixel_matrix.cpp \
  $$SRC_DIR/qwt_point_3d.cpp \
  $$SRC_DIR/qwt_point_polar.cpp \
  $$SRC_DIR/qwt_round_scale_draw.cpp \
  $$SRC_DIR/qwt_scale_div.cpp \
  $$SRC_DIR/qwt_scale_draw.cpp \
  $$SRC_DIR/qwt_scale_map.cpp \
  $$SRC_DIR/qwt_spline.cpp \
  $$SRC_DIR/qwt_scale_engine.cpp \
  $$SRC_DIR/qwt_symbol.cpp \
  $$SRC_DIR/qwt_system_clock.cpp \
  $$SRC_DIR/qwt_text_engine.cpp \
  $$SRC_DIR/qwt_text_label.cpp \
  $$SRC_DIR/qwt_text.cpp \
  $$SRC_DIR/qwt_transform.cpp \
  $$SRC_DIR/qwt_widget_overlay.cpp



