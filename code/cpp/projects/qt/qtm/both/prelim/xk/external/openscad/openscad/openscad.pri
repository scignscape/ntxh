

#           Copyright Nathaniel Christen 2021.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

QT += widgets
QT += network


exists($$ROOT_DIR/../preferred/sysr.pri): include($$ROOT_DIR/../preferred/sysr.pri)
exists($$ROOT_DIR/../preferred/gui.pri): include($$ROOT_DIR/../preferred/gui.pri)


#SOURCES += \
#  $$SRC_ROOT_DIR/add-minimize-frame.cpp \


#HEADERS += \
 

#SOURCES += \
#    $$SRC_DIR/mainwindow.cc \



# Environment variables which can be set to specify library locations:
# MPIRDIR
# MPFRDIR
# BOOSTDIR
# CGALDIR
# EIGENDIR
# GLEWDIR
# OPENCSGDIR
# OPENSCAD_LIBRARIES
#
# qmake Variables to define the installation:
#
#   PREFIX defines the base installation folder
#
#   SUFFIX defines an optional suffix for the binary and the
#   resource folder. E.g. using SUFFIX=-nightly will name the
#   resulting binary openscad-nightly.
#
# Please see the 'Building' sections of the OpenSCAD user manual
# for updated tips & workarounds.
#
# https://en.wikibooks.org/wiki/OpenSCAD_User_Manual

include($$SRC_DIR/defaults.pri)

# Local settings are read from local.pri
exists($$SRC_DIR/local.pri): include($$SRC_DIR/local.pri)



# Auto-include config_<variant>.pri if the VARIANT variable is given on the
# command-line, e.g. qmake VARIANT=mybuild
!isEmpty(VARIANT) {
  message("Variant: $${VARIANT}")
  exists($$SRC_DIR/config_$${VARIANT}.pri) {
    message("Including config_$${VARIANT}.pri")
    include($$SRC_DIR/config_$${VARIANT}.pri)
  }
}

debug {
  experimental {
    message("Building experimental debug version")
  }
  else {
    message("If you're building a development binary, consider adding CONFIG+=experimental")
  }
}

VERSION=2021.01
VERSIONDATE=2021.01.31
# If VERSION is not set, populate VERSION, VERSION_YEAR, VERSION_MONTH from system date
include($$SRC_DIR/version.pri)

debug: DEFINES += DEBUG

TEMPLATE = app

INCLUDEPATH += src
DEPENDPATH += src

# add CONFIG+=deploy to the qmake command-line to make a deployment build
deploy {
  message("Building deployment version")
  DEFINES += OPENSCAD_DEPLOY
  macx: {
    CONFIG += sparkle
    OBJECTIVE_SOURCES += $$SRC_DIR/src/SparkleAutoUpdater.mm
    QMAKE_RPATHDIR = @executable_path/../Frameworks
  }
}
snapshot {
  DEFINES += OPENSCAD_SNAPSHOT
}
# add CONFIG+=idprefix to the qmake command-line to debug node ID's in csg output
idprefix {
  DEFINES += IDPREFIX
  message("Setting IDPREFIX for csg debugging")
  warning("Setting IDPREFIX will negatively affect cache hits")
}
macx {
  TARGET = OpenSCAD
}
else {
  TARGET = openscad$${SUFFIX}
}
FULLNAME = openscad$${SUFFIX}
APPLICATIONID = org.openscad.OpenSCAD
!isEmpty(SUFFIX): DEFINES += INSTALL_SUFFIX="\"\\\"$${SUFFIX}\\\"\""

macx {
  snapshot {
    ICON = icons/icon-nightly.icns
  }
  else {
    ICON = icons/OpenSCAD.icns
  }
  QMAKE_INFO_PLIST = Info.plist
  APP_RESOURCES.path = Contents/Resources
  APP_RESOURCES.files = OpenSCAD.sdef dsa_pub.pem icons/SCAD.icns
  QMAKE_BUNDLE_DATA += APP_RESOURCES
  LIBS += -framework Cocoa -framework ApplicationServices
  QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.9
}

# Set same stack size for the linker and #define used in PlatformUtils.h
STACKSIZE = 8388608 # 8MB # github issue 116
QMAKE_CXXFLAGS += -DSTACKSIZE=$$STACKSIZE
DEFINES += STACKSIZE=$$STACKSIZE

win* {
  RC_FILE = openscad_win32.rc
  QMAKE_CXXFLAGS += -DNOGDI
  QMAKE_LFLAGS += -Wl,--stack,$$STACKSIZE
}

mingw* {
  # needed to prevent compilation error on MSYS2:
  # as.exe: objects/cgalutils.o: too many sections (76541)
  # using -Wa,-mbig-obj did not help
  debug: QMAKE_CXXFLAGS += -O1
}

CONFIG += qt object_parallel_to_source
QT += widgets concurrent multimedia network
CONFIG += scintilla

# for eigen ...
INCLUDEPATH += $$SRC_PROSET_DIR/CaPTk

# for glib ...
INCLUDEPATH += /usr/include/glib-2.0/
INCLUDEPATH += /usr/lib/x86_64-linux-gnu/glib-2.0/include

INCLUDEPATH += /usr/include/libxml2

#INCLUDEPATH += /usr/include/boost/multiprecision

# for hb.h
INCLUDEPATH += /usr/include/harfbuzz/

INCLUDEPATH += /usr/include/freetype2

#DEFINES += NULLGL
DEFINES += ENABLE_OPENCSG

##?
DEFINES += ENABLE_CGAL


INCLUDEPATH += /home/nlevisrael/openscad/QScintilla_src-2.13.0/src


netbsd* {
   QMAKE_LFLAGS += -L/usr/X11R7/lib
   QMAKE_LFLAGS += -Wl,-R/usr/X11R7/lib
   QMAKE_LFLAGS += -Wl,-R/usr/pkg/lib
   # FIXME: Can the lines below be removed in favour of the OPENSCAD_LIBDIR handling above?
   !isEmpty(OPENSCAD_LIBDIR) {
     QMAKE_CFLAGS = -I$$OPENSCAD_LIBDIR/include $$QMAKE_CFLAGS
     QMAKE_CXXFLAGS = -I$$OPENSCAD_LIBDIR/include $$QMAKE_CXXFLAGS
     QMAKE_LFLAGS = -L$$OPENSCAD_LIBDIR/lib $$QMAKE_LFLAGS
     QMAKE_LFLAGS = -Wl,-R$$OPENSCAD_LIBDIR/lib $$QMAKE_LFLAGS
   }
}

# Prevent LD_LIBRARY_PATH problems when running the openscad binary
# on systems where uni-build-dependencies.sh was used.
# Will not affect 'normal' builds.
!isEmpty(OPENSCAD_LIBDIR) {
  unix:!macx {
    QMAKE_LFLAGS = -Wl,-R$$OPENSCAD_LIBDIR/lib $$QMAKE_LFLAGS
    # need /lib64 because GLEW installs itself there on 64 bit machines
    QMAKE_LFLAGS = -Wl,-R$$OPENSCAD_LIBDIR/lib64 $$QMAKE_LFLAGS
  }
}

# See Dec 2011 OpenSCAD mailing list, re: CGAL/GCC bugs.
*g++* {
  QMAKE_CXXFLAGS *= -fno-strict-aliasing
  QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-local-typedefs # ignored before 4.8

  # Disable attributes warnings on MSYS/MXE due to gcc bug spamming the logs: Issue #2771
  win* | CONFIG(mingw-cross-env)|CONFIG(mingw-cross-env-shared) {
    QMAKE_CXXFLAGS += -Wno-attributes
  }
}

*clang* {
  # http://llvm.org/bugs/show_bug.cgi?id=9182
  QMAKE_CXXFLAGS_WARN_ON += -Wno-overloaded-virtual
  # disable enormous amount of warnings about CGAL / boost / etc
  QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter
  QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-variable
  QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-function
  # gettext
  QMAKE_CXXFLAGS_WARN_ON += -Wno-format-security
  # might want to actually turn this on once in a while
  QMAKE_CXXFLAGS_WARN_ON += -Wno-sign-compare
}

skip-version-check {
  # force the use of outdated libraries
  DEFINES += OPENSCAD_SKIP_VERSION_CHECK
}

isEmpty(PKG_CONFIG):PKG_CONFIG = pkg-config

# Application configuration
CONFIG += c++std
CONFIG += cgal
CONFIG += opencsg
CONFIG += glew
CONFIG += boost
CONFIG += eigen
CONFIG += glib-2.0
CONFIG += harfbuzz
CONFIG += freetype
CONFIG += fontconfig
CONFIG += lib3mf
CONFIG += gettext
CONFIG += libxml2
CONFIG += libzip
CONFIG += hidapi
CONFIG += spnav
CONFIG += double-conversion
CONFIG += cairo

# Make experimental features available
experimental {
  DEFINES += ENABLE_EXPERIMENTAL
}

nogui {
  DEFINES += OPENSCAD_NOGUI
}

mdi {
  DEFINES += ENABLE_MDI
}

system("ccache -V >/dev/null 2>/dev/null") {
  CONFIG += ccache
  message("Using ccache")
}

include($$SRC_DIR/common.pri)

# mingw has to come after other items so OBJECT_DIRS will work properly
CONFIG(mingw-cross-env)|CONFIG(mingw-cross-env-shared) {
  include(mingw-cross-env.pri)
}

RESOURCES = $$SRC_DIR/openscad.qrc



INCLUDEPATH += $$SRC_DIR/src


# Qt5 removed access to the QMAKE_UIC variable, the following
# way works for both Qt4 and Qt5
load(uic)
uic.commands += -tr q_

FORMS   += $$SRC_DIR/src/MainWindow.ui \
           $$SRC_DIR/src/ErrorLog.ui \
           $$SRC_DIR/src/Preferences.ui \
           $$SRC_DIR/src/OpenCSGWarningDialog.ui \
           $$SRC_DIR/src/AboutDialog.ui \
           $$SRC_DIR/src/FontListDialog.ui \
           $$SRC_DIR/src/PrintInitDialog.ui \
           $$SRC_DIR/src/ProgressWidget.ui \
           $$SRC_DIR/src/launchingscreen.ui \
           $$SRC_DIR/src/LibraryInfoDialog.ui \
           $$SRC_DIR/src/Console.ui \
           $$SRC_DIR/src/parameter/ParameterWidget.ui \
           $$SRC_DIR/src/parameter/ParameterEntryWidget.ui \
           $$SRC_DIR/src/input/ButtonConfigWidget.ui \
           $$SRC_DIR/src/input/AxisConfigWidget.ui

# AST nodes
FLEXSOURCES += $$SRC_DIR/src/lexer.l
BISONSOURCES += $$SRC_DIR/src/parser.y

HEADERS += $$SRC_DIR/src/AST.h \
           $$SRC_DIR/src/ModuleInstantiation.h \
           $$SRC_DIR/src/Package.h \
           $$SRC_DIR/src/Assignment.h \
           $$SRC_DIR/src/expression.h \
           $$SRC_DIR/src/function.h \
           $$SRC_DIR/src/module.h \
           $$SRC_DIR/src/UserModule.h \

SOURCES += $$SRC_DIR/src/AST.cc \
           $$SRC_DIR/src/ModuleInstantiation.cc \
           $$SRC_DIR/src/Assignment.cc \
           $$SRC_DIR/src/export_pdf.cc \
           $$SRC_DIR/src/expr.cc \
           $$SRC_DIR/src/function.cc \
           $$SRC_DIR/src/module.cc \
           $$SRC_DIR/src/UserModule.cc \
           $$SRC_DIR/src/annotation.cc

# Comment parser
FLEXSOURCES += $$SRC_DIR/src/comment_lexer.l
BISONSOURCES += $$SRC_DIR/src/comment_parser.y

HEADERS += $$SRC_DIR/src/version_check.h \
           $$SRC_DIR/src/version_helper.h \
           $$SRC_DIR/src/ProgressWidget.h \
           $$SRC_DIR/src/parsersettings.h \
           $$SRC_DIR/src/renderer.h \
           $$SRC_DIR/src/settings.h \
           $$SRC_DIR/src/rendersettings.h \
           $$SRC_DIR/src/colormap.h \
           $$SRC_DIR/src/ThrownTogetherRenderer.h \
           $$SRC_DIR/src/CGAL_OGL_Polyhedron.h \
           $$SRC_DIR/src/QGLView.h \
           $$SRC_DIR/src/GLView.h \
           $$SRC_DIR/src/MainWindow.h \
           $$SRC_DIR/src/tabmanager.h \
           $$SRC_DIR/src/tabwidget.h \
           $$SRC_DIR/src/OpenSCADApp.h \
           $$SRC_DIR/src/WindowManager.h \
           $$SRC_DIR/src/initConfig.h \
           $$SRC_DIR/src/Preferences.h \
           $$SRC_DIR/src/SettingsWriter.h \
           $$SRC_DIR/src/OpenCSGWarningDialog.h \
           $$SRC_DIR/src/AboutDialog.h \
           $$SRC_DIR/src/FontListDialog.h \
           $$SRC_DIR/src/FontListTableView.h \
           $$SRC_DIR/src/GroupModule.h \
           $$SRC_DIR/src/FileModule.h \
           $$SRC_DIR/src/StatCache.h \
           $$SRC_DIR/src/scadapi.h \
           $$SRC_DIR/src/builtin.h \
           $$SRC_DIR/src/calc.h \
           $$SRC_DIR/src/context.h \
           $$SRC_DIR/src/builtincontext.h \
           $$SRC_DIR/src/modcontext.h \
           $$SRC_DIR/src/evalcontext.h \
           $$SRC_DIR/src/csgops.h \
           $$SRC_DIR/src/CSGTreeNormalizer.h \
           $$SRC_DIR/src/CSGTreeEvaluator.h \
           $$SRC_DIR/src/dxfdata.h \
           $$SRC_DIR/src/dxfdim.h \
           $$SRC_DIR/src/export.h \
           $$SRC_DIR/src/stackcheck.h \
           $$SRC_DIR/src/exceptions.h \
           $$SRC_DIR/src/grid.h \
           $$SRC_DIR/src/hash.h \
           $$SRC_DIR/src/localscope.h \
           $$SRC_DIR/src/feature.h \
           $$SRC_DIR/src/node.h \
           $$SRC_DIR/src/csgnode.h \
           $$SRC_DIR/src/offsetnode.h \
           $$SRC_DIR/src/linearextrudenode.h \
           $$SRC_DIR/src/rotateextrudenode.h \
           $$SRC_DIR/src/projectionnode.h \
           $$SRC_DIR/src/cgaladvnode.h \
           $$SRC_DIR/src/importnode.h \
           $$SRC_DIR/src/import.h \
           $$SRC_DIR/src/transformnode.h \
           $$SRC_DIR/src/colornode.h \
           $$SRC_DIR/src/rendernode.h \
           $$SRC_DIR/src/textnode.h \
           $$SRC_DIR/src/version.h \
           $$SRC_DIR/src/openscad.h \
           $$SRC_DIR/src/handle_dep.h \
           $$SRC_DIR/src/Geometry.h \
           $$SRC_DIR/src/Polygon2d.h \
           $$SRC_DIR/src/clipper-utils.h \
           $$SRC_DIR/src/GeometryUtils.h \
           $$SRC_DIR/src/polyset-utils.h \
           $$SRC_DIR/src/polyset.h \
           $$SRC_DIR/src/printutils.h \
           $$SRC_DIR/src/fileutils.h \
           $$SRC_DIR/src/value.h \
           $$SRC_DIR/src/progress.h \
           $$SRC_DIR/src/editor.h \
           $$SRC_DIR/src/NodeVisitor.h \
           $$SRC_DIR/src/state.h \
           $$SRC_DIR/src/nodecache.h \
           $$SRC_DIR/src/nodedumper.h \
           $$SRC_DIR/src/ModuleCache.h \
           $$SRC_DIR/src/GeometryCache.h \
           $$SRC_DIR/src/GeometryEvaluator.h \
           $$SRC_DIR/src/Tree.h \
           $$SRC_DIR/src/DrawingCallback.h \
           $$SRC_DIR/src/FreetypeRenderer.h \
           $$SRC_DIR/src/FontCache.h \
           $$SRC_DIR/src/memory.h \
           $$SRC_DIR/src/linalg.h \
           $$SRC_DIR/src/Camera.h \
           $$SRC_DIR/src/system-gl.h \
           $$SRC_DIR/src/boost-utils.h \
           $$SRC_DIR/src/LibraryInfo.h \
           $$SRC_DIR/src/RenderStatistic.h \
           $$SRC_DIR/src/svg.h \
           $$SRC_DIR/src/mouseselector.h \
           \
           $$SRC_DIR/src/OffscreenView.h \
           $$SRC_DIR/src/OffscreenContext.h \
           $$SRC_DIR/src/OffscreenContextAll.hpp \
           $$SRC_DIR/src/fbo.h \
           $$SRC_DIR/src/imageutils.h \
           $$SRC_DIR/src/system-gl.h \
           $$SRC_DIR/src/CsgInfo.h \
           \
           $$SRC_DIR/src/Dock.h \
           $$SRC_DIR/src/Console.h \
           $$SRC_DIR/src/ErrorLog.h \
           $$SRC_DIR/src/AutoUpdater.h \
           $$SRC_DIR/src/launchingscreen.h \
           $$SRC_DIR/src/LibraryInfoDialog.h \
           \
           $$SRC_DIR/src/comment.h\
           \
           $$SRC_DIR/src/parameter/ParameterWidget.h \
           $$SRC_DIR/src/parameter/parameterobject.h \
           $$SRC_DIR/src/parameter/parameterextractor.h \
           $$SRC_DIR/src/parameter/parametervirtualwidget.h \
           $$SRC_DIR/src/parameter/parameterspinbox.h \
           $$SRC_DIR/src/parameter/parametercombobox.h \
           $$SRC_DIR/src/parameter/parameterslider.h \
           $$SRC_DIR/src/parameter/parametercheckbox.h \
           $$SRC_DIR/src/parameter/parametertext.h \
           $$SRC_DIR/src/parameter/parametervector.h \
           $$SRC_DIR/src/parameter/groupwidget.h \
           $$SRC_DIR/src/parameter/parameterset.h \
           $$SRC_DIR/src/parameter/ignoreWheelWhenNotFocused.h \
           $$SRC_DIR/src/QWordSearchField.h \
           $$SRC_DIR/src/QSettingsCached.h \
           $$SRC_DIR/src/input/InputDriver.h \
           $$SRC_DIR/src/input/InputEventMapper.h \
           $$SRC_DIR/src/input/InputDriverManager.h \
           $$SRC_DIR/src/input/AxisConfigWidget.h \
           $$SRC_DIR/src/input/ButtonConfigWidget.h \
           $$SRC_DIR/src/input/WheelIgnorer.h

SOURCES += \
           $$SRC_DIR/src/libsvg/libsvg.cc \
           $$SRC_DIR/src/libsvg/circle.cc \
           $$SRC_DIR/src/libsvg/ellipse.cc \
           $$SRC_DIR/src/libsvg/line.cc \
           $$SRC_DIR/src/libsvg/text.cc \
           $$SRC_DIR/src/libsvg/tspan.cc \
           $$SRC_DIR/src/libsvg/data.cc \
           $$SRC_DIR/src/libsvg/polygon.cc \
           $$SRC_DIR/src/libsvg/polyline.cc \
           $$SRC_DIR/src/libsvg/rect.cc \
           $$SRC_DIR/src/libsvg/group.cc \
           $$SRC_DIR/src/libsvg/svgpage.cc \
           $$SRC_DIR/src/libsvg/path.cc \
           $$SRC_DIR/src/libsvg/shape.cc \
           $$SRC_DIR/src/libsvg/transformation.cc \
           $$SRC_DIR/src/libsvg/util.cc \
           \
           $$SRC_DIR/src/version_check.cc

SOURCES += \
           $$SRC_DIR/src/ProgressWidget.cc \
           $$SRC_DIR/src/linalg.cc \
           $$SRC_DIR/src/Camera.cc \
           $$SRC_DIR/src/handle_dep.cc \
           $$SRC_DIR/src/value.cc \
           $$SRC_DIR/src/degree_trig.cc \
           $$SRC_DIR/src/func.cc \
           $$SRC_DIR/src/localscope.cc \
           $$SRC_DIR/src/feature.cc \
           $$SRC_DIR/src/node.cc \
           $$SRC_DIR/src/context.cc \
           $$SRC_DIR/src/builtincontext.cc \
           $$SRC_DIR/src/modcontext.cc \
           $$SRC_DIR/src/evalcontext.cc \
           $$SRC_DIR/src/csgnode.cc \
           $$SRC_DIR/src/CSGTreeNormalizer.cc \
           $$SRC_DIR/src/CSGTreeEvaluator.cc \
           $$SRC_DIR/src/Geometry.cc \
           $$SRC_DIR/src/Polygon2d.cc \
           $$SRC_DIR/src/clipper-utils.cc \
           $$SRC_DIR/src/polyset-utils.cc \
           $$SRC_DIR/src/GeometryUtils.cc \
           $$SRC_DIR/src/polyset.cc \
           $$SRC_DIR/src/csgops.cc \
           $$SRC_DIR/src/transform.cc \
           $$SRC_DIR/src/color.cc \
           $$SRC_DIR/src/primitives.cc \
           $$SRC_DIR/src/projection.cc \
           $$SRC_DIR/src/cgaladv.cc \
           $$SRC_DIR/src/surface.cc \
           $$SRC_DIR/src/control.cc \
           $$SRC_DIR/src/render.cc \
           $$SRC_DIR/src/text.cc \
           $$SRC_DIR/src/dxfdata.cc \
           $$SRC_DIR/src/dxfdim.cc \
           $$SRC_DIR/src/offset.cc \
           $$SRC_DIR/src/linearextrude.cc \
           $$SRC_DIR/src/rotateextrude.cc \
           $$SRC_DIR/src/printutils.cc \
           $$SRC_DIR/src/fileutils.cc \
           $$SRC_DIR/src/progress.cc \
           $$SRC_DIR/src/parsersettings.cc \
           $$SRC_DIR/src/boost-utils.cc \
           $$SRC_DIR/src/PlatformUtils.cc \
           $$SRC_DIR/src/LibraryInfo.cc \
           $$SRC_DIR/src/RenderStatistic.cc \
           \
           $$SRC_DIR/src/nodedumper.cc \
           $$SRC_DIR/src/NodeVisitor.cc \
           $$SRC_DIR/src/GeometryEvaluator.cc \
           $$SRC_DIR/src/ModuleCache.cc \
           $$SRC_DIR/src/GeometryCache.cc \
           $$SRC_DIR/src/Tree.cc \
               $$SRC_DIR/src/DrawingCallback.cc \
               $$SRC_DIR/src/FreetypeRenderer.cc \
               $$SRC_DIR/src/FontCache.cc \
           \
           $$SRC_DIR/src/settings.cc \
           $$SRC_DIR/src/rendersettings.cc \
           $$SRC_DIR/src/initConfig.cc \
           $$SRC_DIR/src/Preferences.cc \
           $$SRC_DIR/src/SettingsWriter.cc \
           $$SRC_DIR/src/OpenCSGWarningDialog.cc \
           $$SRC_DIR/src/editor.cc \
           $$SRC_DIR/src/GLView.cc \
           $$SRC_DIR/src/QGLView.cc \
           $$SRC_DIR/src/AutoUpdater.cc \
           \
           $$SRC_DIR/src/hash.cc \
           $$SRC_DIR/src/GroupModule.cc \
           $$SRC_DIR/src/FileModule.cc \
           $$SRC_DIR/src/StatCache.cc \
           $$SRC_DIR/src/scadapi.cc \
           $$SRC_DIR/src/builtin.cc \
           $$SRC_DIR/src/calc.cc \
           $$SRC_DIR/src/export.cc \
           $$SRC_DIR/src/export_stl.cc \
           $$SRC_DIR/src/export_amf.cc \
           $$SRC_DIR/src/export_3mf.cc \
           $$SRC_DIR/src/export_off.cc \
           $$SRC_DIR/src/export_dxf.cc \
           $$SRC_DIR/src/export_svg.cc \
           $$SRC_DIR/src/export_nef.cc \
           $$SRC_DIR/src/export_png.cc \
           $$SRC_DIR/src/import.cc \
           $$SRC_DIR/src/import_stl.cc \
           $$SRC_DIR/src/import_off.cc \
           $$SRC_DIR/src/import_svg.cc \
           $$SRC_DIR/src/import_amf.cc \
           $$SRC_DIR/src/import_3mf.cc \
           $$SRC_DIR/src/renderer.cc \
           $$SRC_DIR/src/colormap.cc \
           $$SRC_DIR/src/ThrownTogetherRenderer.cc \
           $$SRC_DIR/src/svg.cc \
           $$SRC_DIR/src/OffscreenView.cc \
           $$SRC_DIR/src/fbo.cc \
           $$SRC_DIR/src/system-gl.cc \
           $$SRC_DIR/src/imageutils.cc \
           \
           $$SRC_DIR/src/version.cc \
           $$SRC_DIR/src/openscad.cc \
           $$SRC_DIR/src/mainwin.cc \
           $$SRC_DIR/src/tabmanager.cc \
           $$SRC_DIR/src/tabwidget.cc \
           $$SRC_DIR/src/OpenSCADApp.cc \
           $$SRC_DIR/src/WindowManager.cc \
           $$SRC_DIR/src/UIUtils.cc \
           $$SRC_DIR/src/Dock.cc \
           $$SRC_DIR/src/Console.cc \
           $$SRC_DIR/src/ErrorLog.cc \
           $$SRC_DIR/src/FontListDialog.cc \
           $$SRC_DIR/src/FontListTableView.cc \
           $$SRC_DIR/src/launchingscreen.cc \
           $$SRC_DIR/src/LibraryInfoDialog.cc\
           \
           $$SRC_DIR/src/comment.cpp \
           $$SRC_DIR/src/mouseselector.cc \
           \
           $$SRC_DIR/src/parameter/ParameterWidget.cc\
           $$SRC_DIR/src/parameter/parameterobject.cpp \
           $$SRC_DIR/src/parameter/parameterextractor.cpp \
           $$SRC_DIR/src/parameter/parameterspinbox.cpp \
           $$SRC_DIR/src/parameter/parametercombobox.cpp \
           $$SRC_DIR/src/parameter/parameterslider.cpp \
           $$SRC_DIR/src/parameter/parametercheckbox.cpp \
           $$SRC_DIR/src/parameter/parametertext.cpp \
           $$SRC_DIR/src/parameter/parametervector.cpp \
           $$SRC_DIR/src/parameter/groupwidget.cpp \
           $$SRC_DIR/src/parameter/parameterset.cpp \
           $$SRC_DIR/src/parameter/parametervirtualwidget.cpp \
           $$SRC_DIR/src/parameter/ignoreWheelWhenNotFocused.cpp \
           $$SRC_DIR/src/QWordSearchField.cc\
           $$SRC_DIR/src/QSettingsCached.cc \
           \
           $$SRC_DIR/src/input/InputDriver.cc \
           $$SRC_DIR/src/input/InputEventMapper.cc \
           $$SRC_DIR/src/input/InputDriverManager.cc \
           $$SRC_DIR/src/input/AxisConfigWidget.cc \
           $$SRC_DIR/src/input/ButtonConfigWidget.cc \
           $$SRC_DIR/src/input/WheelIgnorer.cc


SOURCES += $$SRC_GROUP_DIR/mosaic/mosaic-menubar.cpp


DEFINES += DEFAULT_SCREENSHOT_FOLDER=\\\"$$ROOT_DIR/../dev/openscad/screenshots\\\"
#DEFINES += QMenuBar=Mosaic_Menubar

INCLUDEPATH += $$SRC_GROUP_DIR/mosaic


HEADERS += \
  $$SRC_DIR/src/scintillaeditor.h \


SOURCES += \
  $$SRC_DIR/src/scintillaeditor.cpp \
  $$SRC_DIR/src/scadlexer.cpp \


# CGAL
HEADERS += $$SRC_DIR/src/ext/CGAL/OGL_helper.h \
           $$SRC_DIR/src/ext/CGAL/CGAL_workaround_Mark_bounded_volumes.h

# LodePNG
SOURCES += $$SRC_DIR/src/ext/lodepng/lodepng.cpp
HEADERS += $$SRC_DIR/src/ext/lodepng/lodepng.h

# ClipperLib
SOURCES += $$SRC_DIR/src/ext/polyclipping/clipper.cpp
HEADERS += $$SRC_DIR/src/ext/polyclipping/clipper.hpp

# libtess2
INCLUDEPATH += $$SRC_DIR/src/ext/libtess2/Include
SOURCES += $$SRC_DIR/src/ext/libtess2/Source/bucketalloc.c \
           $$SRC_DIR/src/ext/libtess2/Source/dict.c \
           $$SRC_DIR/src/ext/libtess2/Source/geom.c \
           $$SRC_DIR/src/ext/libtess2/Source/mesh.c \
           $$SRC_DIR/src/ext/libtess2/Source/priorityq.c \
           $$SRC_DIR/src/ext/libtess2/Source/sweep.c \
           $$SRC_DIR/src/ext/libtess2/Source/tess.c
HEADERS += $$SRC_DIR/src/ext/libtess2/Include/tesselator.h \
           $$SRC_DIR/src/ext/libtess2/Source/bucketalloc.h \
           $$SRC_DIR/src/ext/libtess2/Source/dict.h \
           $$SRC_DIR/src/ext/libtess2/Source/geom.h \
           $$SRC_DIR/src/ext/libtess2/Source/mesh.h \
           $$SRC_DIR/src/ext/libtess2/Source/priorityq.h \
           $$SRC_DIR/src/ext/libtess2/Source/sweep.h \
           $$SRC_DIR/src/ext/libtess2/Source/tess.h

has_qt5 {
  HEADERS += $$SRC_DIR/src/Network.h $$SRC_DIR/src/NetworkSignal.h $$SRC_DIR/src/PrintService.h $$SRC_DIR/src/OctoPrint.h $$SRC_DIR/src/PrintInitDialog.h
  SOURCES += $$SRC_DIR/src/PrintService.cc $$SRC_DIR/src/OctoPrint.cc $$SRC_DIR/src/PrintInitDialog.cc
}

has_qt5:unix:!macx {
  QT += dbus
  DEFINES += ENABLE_DBUS
  DBUS_ADAPTORS += $$SRC_DIR/org.openscad.OpenSCAD.xml
  DBUS_INTERFACES += $$SRC_DIR/org.openscad.OpenSCAD.xml

  HEADERS += $$SRC_DIR/src/input/DBusInputDriver.h
  SOURCES += $$SRC_DIR/src/input/DBusInputDriver.cc
}

linux: {
  DEFINES += ENABLE_JOYSTICK

  HEADERS += $$SRC_DIR/src/input/JoystickInputDriver.h
  SOURCES += $$SRC_DIR/src/input/JoystickInputDriver.cc
}

!lessThan(QT_MAJOR_VERSION, 5) {
  qtHaveModule(gamepad) {
    QT += gamepad
    DEFINES += ENABLE_QGAMEPAD
    HEADERS += $$SRC_DIR/src/input/QGamepadInputDriver.h
    SOURCES += $$SRC_DIR/src/input/QGamepadInputDriver.cc
  }
}

unix:!macx {
  SOURCES += $$SRC_DIR/src/imageutils-lodepng.cc
  SOURCES += $$SRC_DIR/src/OffscreenContextGLX.cc
}
macx {
  SOURCES += $$SRC_DIR/src/imageutils-macosx.cc
  OBJECTIVE_SOURCES += $$SRC_DIR/src/OffscreenContextCGL.mm
}
win* {
  SOURCES += $$SRC_DIR/src/imageutils-lodepng.cc
  SOURCES += $$SRC_DIR/src/OffscreenContextWGL.cc
}

opencsg {
  HEADERS += $$SRC_DIR/src/OpenCSGRenderer.h
  SOURCES += $$SRC_DIR/src/OpenCSGRenderer.cc
}

cgal {
HEADERS += $$SRC_DIR/src/cgal.h \
           $$SRC_DIR/src/cgalutils.h \
           $$SRC_DIR/src/Reindexer.h \
           $$SRC_DIR/src/CGALCache.h \
           $$SRC_DIR/src/CGALRenderer.h \
           $$SRC_DIR/src/CGAL_Nef_polyhedron.h \
           $$SRC_DIR/src/cgalworker.h \
           $$SRC_DIR/src/Polygon2d-CGAL.h

SOURCES += $$SRC_DIR/src/cgalutils.cc \
           $$SRC_DIR/src/cgalutils-applyops.cc \
           $$SRC_DIR/src/cgalutils-project.cc \
           $$SRC_DIR/src/cgalutils-tess.cc \
           $$SRC_DIR/src/cgalutils-polyhedron.cc \
           $$SRC_DIR/src/CGALCache.cc \
           $$SRC_DIR/src/CGALRenderer.cc \
           $$SRC_DIR/src/CGAL_Nef_polyhedron.cc \
           $$SRC_DIR/src/cgalworker.cc \
           $$SRC_DIR/src/Polygon2d-CGAL.cc \
           $$SRC_DIR/src/import_nef.cc
}

macx {
  HEADERS += $$SRC_DIR/src/AppleEvents.h \
             $$SRC_DIR/src/EventFilter.h \
             $$SRC_DIR/src/CocoaUtils.h
  SOURCES += $$SRC_DIR/src/AppleEvents.cc
  OBJECTIVE_SOURCES += $$SRC_DIR/src/CocoaUtils.mm \
                       $$SRC_DIR/src/PlatformUtils-mac.mm
}
unix:!macx {
  SOURCES += $$SRC_DIR/src/PlatformUtils-posix.cc
}
win* {
  HEADERS += $$SRC_DIR/src/findversion.h
  SOURCES += $$SRC_DIR/src/PlatformUtils-win.cc
}

isEmpty(PREFIX):PREFIX = /usr/local

target.path = $$PREFIX/bin/
INSTALLS += target


# Run translation update scripts as last step after linking the target
## QMAKE_POST_LINK += "'$$PWD/scripts/translation-make.sh'"
## skip this ...


# Create install targets for the languages defined in LINGUAS
LINGUAS = $$cat(locale/LINGUAS)
LOCALE_PREFIX = "$$PREFIX/share/$${FULLNAME}/locale"
for(language, LINGUAS) {
  catalogdir = locale/$$language/LC_MESSAGES
  exists(locale/$${language}.po) {
    # Use .extra and copy manually as the source path might not exist,
    # e.g. on a clean checkout. In that case qmake would not create
    # the needed targets in the generated Makefile.
    translation_path = translation_$${language}.path
    translation_extra = translation_$${language}.extra
    translation_depends = translation_$${language}.depends
    $$translation_path = $$LOCALE_PREFIX/$$language/LC_MESSAGES/
    $$translation_extra = cp -f $${catalogdir}/openscad.mo \"\$(INSTALL_ROOT)$$LOCALE_PREFIX/$$language/LC_MESSAGES/openscad.mo\"
    $$translation_depends = locale/$${language}.po
    INSTALLS += translation_$$language
  }
}

examples.path = "$$PREFIX/share/$${FULLNAME}/examples/"
examples.files = examples/*
INSTALLS += examples

libraries.path = "$$PREFIX/share/$${FULLNAME}/libraries/"
libraries.files = libraries/*
INSTALLS += libraries

fonts.path = "$$PREFIX/share/$${FULLNAME}/fonts/"
fonts.files = fonts/*
INSTALLS += fonts

colorschemes.path = "$$PREFIX/share/$${FULLNAME}/color-schemes/"
colorschemes.files = color-schemes/*
INSTALLS += colorschemes

templates.path = "$$PREFIX/share/$${FULLNAME}/templates/"
templates.files = templates/*
INSTALLS += templates

applications.path = $$PREFIX/share/applications
applications.extra = mkdir -p \"\$(INSTALL_ROOT)$${applications.path}\" && cat icons/openscad.desktop | sed -e \"'s/^Icon=openscad/Icon=$${FULLNAME}/; s/^Exec=openscad/Exec=$${FULLNAME}/'\" > \"\$(INSTALL_ROOT)$${applications.path}/$${FULLNAME}.desktop\"
INSTALLS += applications

mimexml.path = $$PREFIX/share/mime/packages
mimexml.extra = cp -f icons/openscad.xml \"\$(INSTALL_ROOT)$${mimexml.path}/$${FULLNAME}.xml\"
INSTALLS += mimexml

appdata.path = $$PREFIX/share/metainfo
appdata.extra = mkdir -p \"\$(INSTALL_ROOT)$${appdata.path}\" && cat openscad.appdata.xml | sed -e \"'s/$${APPLICATIONID}/$${APPLICATIONID}$${SUFFIX}/; s/openscad.desktop/openscad$${SUFFIX}.desktop/; s/openscad.png/openscad$${SUFFIX}.png/'\" > \"\$(INSTALL_ROOT)$${appdata.path}/$${APPLICATIONID}$${SUFFIX}.appdata.xml\"
INSTALLS += appdata

icon48.path = $$PREFIX/share/icons/hicolor/48x48/apps
icon48.extra = test -f icons/$${FULLNAME}-48.png && cp -f icons/$${FULLNAME}-48.png \"\$(INSTALL_ROOT)$${icon48.path}/$${FULLNAME}.png\" || cp -f icons/openscad-48.png \"\$(INSTALL_ROOT)$${icon48.path}/$${FULLNAME}.png\"
icon64.path = $$PREFIX/share/icons/hicolor/64x64/apps
icon64.extra = test -f icons/$${FULLNAME}-64.png && cp -f icons/$${FULLNAME}-64.png \"\$(INSTALL_ROOT)$${icon64.path}/$${FULLNAME}.png\" || cp -f icons/openscad-64.png \"\$(INSTALL_ROOT)$${icon64.path}/$${FULLNAME}.png\"
icon128.path = $$PREFIX/share/icons/hicolor/128x128/apps
icon128.extra = test -f icons/$${FULLNAME}-128.png && cp -f icons/$${FULLNAME}-128.png \"\$(INSTALL_ROOT)$${icon128.path}/$${FULLNAME}.png\" || cp -f icons/openscad-128.png \"\$(INSTALL_ROOT)$${icon128.path}/$${FULLNAME}.png\"
icon256.path = $$PREFIX/share/icons/hicolor/256x256/apps
icon256.extra = test -f icons/$${FULLNAME}-256.png && cp -f icons/$${FULLNAME}-256.png \"\$(INSTALL_ROOT)$${icon256.path}/$${FULLNAME}.png\" || cp -f icons/openscad-256.png \"\$(INSTALL_ROOT)$${icon256.path}/$${FULLNAME}.png\"
icon512.path = $$PREFIX/share/icons/hicolor/512x512/apps
icon512.extra = test -f icons/$${FULLNAME}-512.png && cp -f icons/$${FULLNAME}-512.png \"\$(INSTALL_ROOT)$${icon512.path}/$${FULLNAME}.png\" || cp -f icons/openscad-512.png \"\$(INSTALL_ROOT)$${icon512.path}/$${FULLNAME}.png\"
INSTALLS += icon48 icon64 icon128 icon256 icon512

man.path = $$PREFIX/share/man/man1
man.extra = cp -f doc/openscad.1 \"\$(INSTALL_ROOT)$${man.path}/$${FULLNAME}.1\"
INSTALLS += man

info: {
    include(info.pri)
}

DISTFILES += \
    sounds/complete.wav


##?
#LIBS += -lGLU

LIBS += -lglib-2.0

LIBS += \
 -lboost_program_options \
 -lboost_system \
 -lboost_filesystem \
 -lboost_regex \
 -lboost_thread \
 -lboost_date_time \
 -lboost_chrono \
 -lboost_atomic \
 -lpthread \
 -lxml2 \


LIBS += /usr/lib/x86_64-linux-gnu/libdouble-conversion.a
LIBS += /usr/lib/x86_64-linux-gnu/libCGAL.a

LIBS += -lharfbuzz
LIBS += -lfreetype -lfontconfig

LIBS += -lopencsg -lGLEW -lgmp -lmpfr

#
LIBS += -L$$TARGETSDIR -lqscintilla # here called just qscintilla, not qscintilla2_qt5

#LIBS += -L
#LIBS += -L/home/nlevisrael/openscad/build -lqscintilla2_qt5

message(DESTDIR: $$DESTDIR)


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
