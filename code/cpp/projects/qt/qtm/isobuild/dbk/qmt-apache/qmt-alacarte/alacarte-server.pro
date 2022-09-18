
QT += gui widgets


QMAKE_CC = gcc-7
QMAKE_CXX = g++-7

CONFIG += c++17

# http://localhost:11213/14/8529/5974.png
# http://localhost:11213/12/1205/1540.png
# http://localhost:11213/12/1171/1566.png
# http://localhost:11213/14/4685/6267.png

# http://localhost:11213/14/9676/5786.png
# https//localhost:11213/13/4837/2893.png

# http://localhost:11213/14/8529/5974.png

DESTDIR = ../target

#/home/nlevisrael/gits/osm/alacarte-master/-run-cmake_/install/etc/alacarte-maps.conf


INCLUDEPATH += \
  ../../include


INCLUDEPATH += \
  /usr/include/cairo \



DEFINES += BOOST_LOG_DYN_LINK


DEFINES += DEFAULT_PORT=\\\"11213\\\"  # a-l-a-c

ALACARTE_QLOG_DIR = /home/nlevisrael/gits/osm/alacarte-master/-qlog_

DEFINES += ALACARTE_QLOG_FOLDER=\\\"$${ALACARTE_QLOG_DIR}\\\"
DEFINES += ALACARTE_QLOG_FILE=\\\"$${ALACARTE_QLOG_DIR}/qlog.txt\\\"

DEFINES += ALACARTE_QLOG_IMAGES_FOLDER=\\\"$${ALACARTE_QLOG_DIR}/images\\\"


DISTFILES += \
  /home/nlevisrael/gits/osm/alacarte-master/-run-cmake_/install/share/alacarte-maps/styles/default.mapcss





HEADERS += \
 ../../include/server/cache.hpp \
 ../../include/server/eval/binary_operation_node.hpp \
 ../../include/server/eval/eval.hpp \
 ../../include/server/eval/eval_helpers.hpp \
 ../../include/server/eval/function_operation_node.hpp \
 ../../include/server/eval/stleaf.hpp \
 ../../include/server/eval/stnode.hpp \
 ../../include/server/eval/unary_operation_node.hpp \
 ../../include/server/http/request_parser.hpp \
 ../../include/server/http_request.hpp \
 ../../include/server/http_server.hpp \
 ../../include/server/job.hpp \
 ../../include/server/meta_identifier.hpp \
 ../../include/server/parser/color_grammar.hpp \
 ../../include/server/parser/comment_skipper.hpp \
 ../../include/server/parser/eval_grammar.hpp \
 ../../include/server/parser/mapcss_def.hpp \
 ../../include/server/parser/mapcss_grammar.hpp \
 ../../include/server/parser/mapcss_parser.hpp \
 ../../include/server/parser/parse_info.hpp \
 ../../include/server/parser/parse_info_parser.hpp \
 ../../include/server/parser/parser_logger.hpp \
 ../../include/server/render_attributes.hpp \
 ../../include/server/request_manager.hpp \
 ../../include/server/rule.hpp \
 ../../include/server/selectors/apply_selector.hpp \
 ../../include/server/selectors/area_selector.hpp \
 ../../include/server/selectors/childnodes_selector.hpp \
 ../../include/server/selectors/childways_selector.hpp \
 ../../include/server/selectors/hasnottag_selector.hpp \
 ../../include/server/selectors/hastag_selector.hpp \
 ../../include/server/selectors/line_selector.hpp \
 ../../include/server/selectors/selector.hpp \
 ../../include/server/selectors/selectors.hpp \
 ../../include/server/selectors/tagequals_selector.hpp \
 ../../include/server/selectors/taglarger_selector.hpp \
 ../../include/server/selectors/taglargerequals_selector.hpp \
 ../../include/server/selectors/tagmatches_selector.hpp \
 ../../include/server/selectors/tagsmaller_selector.hpp \
 ../../include/server/selectors/tagsmallerequals_selector.hpp \
 ../../include/server/selectors/tagunequals_selector.hpp \
 ../../include/server/style.hpp \
 ../../include/server/style_template.hpp \
 ../../include/server/stylesheet.hpp \
 ../../include/server/stylesheet_manager.hpp \
 ../../include/server/tile.hpp \
 ../../include/server/tile_identifier.hpp \
 ../../src/server/_qmt_/job-context.h \
 ../../src/server/_qmt_/qmt-accessors.h \
 ../../src/server/_qmt_/qmt-enum-macros.h \
 ../../src/server/_qmt_/qmt-global-macros.h \
 ../../src/server/_qmt_/qmt-global-types.h


HEADERS += \
 ../../include/server/renderer/node_renderer.hpp \
 ../../include/server/renderer/object_renderer.hpp \
 ../../include/server/renderer/relation_renderer.hpp \
 ../../include/server/renderer/way_renderer.hpp


#HEADERS += \
# ../../src/server/renderer/node_renderer.hpp \
# ../../src/server/renderer/object_renderer.hpp \
# ../../src/server/renderer/relation_renderer.hpp \
# ../../src/server/renderer/way_renderer.hpp


#HEADERS += \
#  ../../src/server/qlog/qt-logger.h
#

SOURCES += \
  ../../src/alacarte_server.cpp \
  ../../src/server/_qmt_/job-context.cpp \
  ../../src/server/_qmt_/single-job-context.cpp \
  ../../src/server/_qmt_/qmt-tile-object.cpp \


HEADERS += \
  ../../src/server/_qmt_/job-context.h \
  ../../src/server/_qmt_/single-job-context.h \
  ../../src/server/_qmt_/qmt-tile-object.h \


DEFINES += QT_HOOK



INCLUDEPATH += \
  ../../src/_qlog_


SOURCES += \
 ../../src/server/cache.cpp \
 ../../src/server/eval/binary_operation_node.cpp \
 ../../src/server/eval/eval.cpp \
 ../../src/server/eval/eval_helpers.cpp \
 ../../src/server/eval/function_operation_node.cpp \
 ../../src/server/eval/stleaf.cpp \
 ../../src/server/eval/unary_operation_node.cpp \
 ../../src/server/http/request_parser.cpp \
 ../../src/server/http_request.cpp \
 ../../src/server/http_server.cpp \
 ../../src/server/job.cpp \
 ../../src/server/meta_identifier.cpp \
 ../../src/server/parser/color_grammar.cpp \
 ../../src/server/parser/comment_skipper.cpp \
 ../../src/server/parser/eval_grammar.cpp \
 ../../src/server/parser/mapcss_grammar.cpp \
 ../../src/server/parser/mapcss_parser.cpp \
 ../../src/server/parser/parser_logger.cpp \
 ../../src/server/renderer/node_renderer.cpp \
 ../../src/server/renderer/object_renderer.cpp \
 ../../src/server/renderer/relation_renderer.cpp \
 ../../src/server/renderer/render_canvas.cpp \
 ../../src/server/renderer/renderer.cpp \
 ../../src/server/renderer/way_renderer.cpp \
 ../../src/server/request_manager.cpp \
 ../../src/server/rule.cpp \
 ../../src/server/selectors/apply_selector.cpp \
 ../../src/server/selectors/area_selector.cpp \
 ../../src/server/selectors/childnodes_selector.cpp \
 ../../src/server/selectors/childways_selector.cpp \
 ../../src/server/selectors/hasnottag_selector.cpp \
 ../../src/server/selectors/hastag_selector.cpp \
 ../../src/server/selectors/line_selector.cpp \
 ../../src/server/selectors/selector.cpp \
 ../../src/server/selectors/tagequals_selector.cpp \
 ../../src/server/selectors/taglarger_selector.cpp \
 ../../src/server/selectors/taglargerequals_selector.cpp \
 ../../src/server/selectors/tagmatches_selector.cpp \
 ../../src/server/selectors/tagsmaller_selector.cpp \
 ../../src/server/selectors/tagsmallerequals_selector.cpp \
 ../../src/server/selectors/tagunequals_selector.cpp \
 ../../src/server/style.cpp \
 ../../src/server/style_template.cpp \
 ../../src/server/stylesheet.cpp \
 ../../src/server/stylesheet_manager.cpp \
 ../../src/server/tile.cpp \
 ../../src/server/tile_identifier.cpp


#SOURCES += \
#  ../../src/server/qlog/qt-logger.cpp


LIBS += -L$$DESTDIR -lalacarte-lib


LIBS += -lboost_program_options \
   -lboost_system  -lboost_filesystem \
   -lboost_serialization  -lboost_log  -lboost_thread \
   -lboost_log_setup -lboost_regex -lboost_iostreams \
   -lboost_chrono -lboost_date_time -lboost_atomic \
   -lboost_unit_test_framework \


LIBS += -lcairo



