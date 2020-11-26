
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


include(../build-group.pri)

QT += gui widgets concurrent opengl  svg #opengl sql network xml testlib

QT += printsupport


include($$ROOT_DIR/../preferred/sysr.pri)
include($$ROOT_DIR/../preferred/gui.pri)

#include($$ROOT_DIR/../preferred/medInria-external.pri)



INCLUDEPATH += $$SRC_GROUP_DIR/qwt




#DEFINES += DTKLOGEXPORT


#INCLUDEPATH += $$SRC_DIR/inc/dtkMeta



HEADERS +=  \
  $$SRC_DIR/qwt_curve_fitter.h \
  $$SRC_DIR/qwt_abstract_legend.h \
  $$SRC_DIR/qwt_legend.h \
  $$SRC_DIR/qwt_legend_data.h \
  $$SRC_DIR/qwt_legend_label.h \
  $$SRC_DIR/qwt_plot.h \
  $$SRC_DIR/qwt_plot_renderer.h \
  $$SRC_DIR/qwt_plot_curve.h \
  $$SRC_DIR/qwt_plot_dict.h \
  $$SRC_DIR/qwt_plot_directpainter.h \
  $$SRC_DIR/qwt_plot_grid.h \
  $$SRC_DIR/qwt_plot_histogram.h \
  $$SRC_DIR/qwt_plot_item.h \
  $$SRC_DIR/qwt_plot_abstract_barchart.h \
  $$SRC_DIR/qwt_plot_barchart.h \
  $$SRC_DIR/qwt_plot_multi_barchart.h \
  $$SRC_DIR/qwt_plot_intervalcurve.h \
  $$SRC_DIR/qwt_plot_tradingcurve.h \
  $$SRC_DIR/qwt_plot_layout.h \
  $$SRC_DIR/qwt_plot_marker.h \
  $$SRC_DIR/qwt_plot_zoneitem.h \
  $$SRC_DIR/qwt_plot_textlabel.h \
  $$SRC_DIR/qwt_plot_rasteritem.h \
  $$SRC_DIR/qwt_plot_spectrogram.h \
  $$SRC_DIR/qwt_plot_spectrocurve.h \
  $$SRC_DIR/qwt_plot_scaleitem.h \
  $$SRC_DIR/qwt_plot_legenditem.h \
  $$SRC_DIR/qwt_plot_seriesitem.h \
  $$SRC_DIR/qwt_plot_shapeitem.h \
  $$SRC_DIR/qwt_plot_canvas.h \
  $$SRC_DIR/qwt_plot_panner.h \
  $$SRC_DIR/qwt_plot_picker.h \
  $$SRC_DIR/qwt_plot_zoomer.h \
  $$SRC_DIR/qwt_plot_magnifier.h \
  $$SRC_DIR/qwt_plot_rescaler.h \
  $$SRC_DIR/qwt_point_mapper.h \
  $$SRC_DIR/qwt_raster_data.h \
  $$SRC_DIR/qwt_matrix_raster_data.h \
  $$SRC_DIR/qwt_sampling_thread.h \
  $$SRC_DIR/qwt_samples.h \
  $$SRC_DIR/qwt_series_data.h \
  $$SRC_DIR/qwt_series_store.h \
  $$SRC_DIR/qwt_point_data.h \
  $$SRC_DIR/qwt_scale_widget.h 


SOURCES +=  \
  $$SRC_DIR/qwt_curve_fitter.cpp \
  $$SRC_DIR/qwt_abstract_legend.cpp \
  $$SRC_DIR/qwt_legend.cpp \
  $$SRC_DIR/qwt_legend_data.cpp \
  $$SRC_DIR/qwt_legend_label.cpp \
  $$SRC_DIR/qwt_plot.cpp \
  $$SRC_DIR/qwt_plot_renderer.cpp \
  $$SRC_DIR/qwt_plot_xml.cpp \
  $$SRC_DIR/qwt_plot_axis.cpp \
  $$SRC_DIR/qwt_plot_curve.cpp \
  $$SRC_DIR/qwt_plot_dict.cpp \
  $$SRC_DIR/qwt_plot_directpainter.cpp \
  $$SRC_DIR/qwt_plot_grid.cpp \
  $$SRC_DIR/qwt_plot_histogram.cpp \
  $$SRC_DIR/qwt_plot_item.cpp \
  $$SRC_DIR/qwt_plot_abstract_barchart.cpp \
  $$SRC_DIR/qwt_plot_barchart.cpp \
  $$SRC_DIR/qwt_plot_multi_barchart.cpp \
  $$SRC_DIR/qwt_plot_intervalcurve.cpp \
  $$SRC_DIR/qwt_plot_zoneitem.cpp \
  $$SRC_DIR/qwt_plot_tradingcurve.cpp \
  $$SRC_DIR/qwt_plot_spectrogram.cpp \
  $$SRC_DIR/qwt_plot_spectrocurve.cpp \
  $$SRC_DIR/qwt_plot_scaleitem.cpp \
  $$SRC_DIR/qwt_plot_legenditem.cpp \
  $$SRC_DIR/qwt_plot_seriesitem.cpp \
  $$SRC_DIR/qwt_plot_shapeitem.cpp \
  $$SRC_DIR/qwt_plot_marker.cpp \
  $$SRC_DIR/qwt_plot_textlabel.cpp \
  $$SRC_DIR/qwt_plot_layout.cpp \
  $$SRC_DIR/qwt_plot_canvas.cpp \
  $$SRC_DIR/qwt_plot_panner.cpp \
  $$SRC_DIR/qwt_plot_rasteritem.cpp \
  $$SRC_DIR/qwt_plot_picker.cpp \
  $$SRC_DIR/qwt_plot_zoomer.cpp \
  $$SRC_DIR/qwt_plot_magnifier.cpp \
  $$SRC_DIR/qwt_plot_rescaler.cpp \
  $$SRC_DIR/qwt_point_mapper.cpp \
  $$SRC_DIR/qwt_raster_data.cpp \
  $$SRC_DIR/qwt_matrix_raster_data.cpp \
  $$SRC_DIR/qwt_sampling_thread.cpp \
  $$SRC_DIR/qwt_series_data.cpp \
  $$SRC_DIR/qwt_point_data.cpp \
  $$SRC_DIR/qwt_scale_widget.cpp


HEADERS += \
  $$SRC_DIR/qwt_plot_svgitem.h

SOURCES += \
  $$SRC_DIR/qwt_plot_svgitem.cpp


HEADERS += \
  $$SRC_DIR/qwt_plot_glcanvas.h

SOURCES += \
  $$SRC_DIR/qwt_plot_glcanvas.cpp


LIBS += -L$$TARGETSDIR -lqwt




