
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)


QT += xml widgets opengl network


include($$ROOT_DIR/../preferred/sysr.pri)


DEFINES += MESHLAB_SCALAR=float
DEFINES += setResizeMode=setSectionResizeMode



INCLUDEPATH += $$SRC_GROUP_DIR  

INCLUDEPATH += $$SRC_GROUP_DIR/external/easyexif  


VCGDIR = $$SRC_GROUP_DIR/vcglib
INCLUDEPATH += $$SRC_GROUP_DIR/vcglib 


INCLUDEPATH += $$SRC_PROSET_DIR/CaPTk \


HEADERS += \
  $$SRC_DIR/mainwindow.h \
  $$SRC_DIR/glarea.h \
  $$SRC_DIR/meshlab_settings/meshlabsettingsdialog.h \
  $$SRC_DIR/meshlab_settings/settingdialog.h \
  $$SRC_DIR/multiViewer_Container.h \
  $$SRC_DIR/glarea_setting.h \
  $$SRC_DIR/plugindialog.h \
  $$SRC_DIR/filterScriptDialog.h \
  $$SRC_DIR/saveSnapshotDialog.h \
  $$SRC_DIR/savemaskexporter.h \
  $$SRC_DIR/changetexturename.h \
  $$SRC_DIR/layerDialog.h \
  $$SRC_DIR/ml_std_par_dialog.h \
  $$SRC_DIR/additionalgui.h \
  $$SRC_DIR/snapshotsetting.h \
  $$SRC_DIR/ml_render_gui.h \
  $$SRC_DIR/ml_rendering_actions.h \
  $$SRC_DIR/ml_default_decorators.h \
  $$VCGDIR/wrap/gui/trackball.h \
  $$VCGDIR/wrap/gui/trackmode.h \
  $$VCGDIR/wrap/gl/trimesh.h \
  $$SRC_DIR/rich_parameter_gui/richparameterlistdialog.h \
  $$SRC_DIR/rich_parameter_gui/richparameterlistframe.h \
  $$SRC_DIR/rich_parameter_gui/richparameterwidgets.h


#  $$SRC_DIR/main.cpp \


SOURCES += \
  $$SRC_DIR/mainwindow_Init.cpp \
  $$SRC_DIR/mainwindow_RunTime.cpp \
  $$SRC_DIR/glarea.cpp \
  $$SRC_DIR/meshlab_settings/meshlabsettingsdialog.cpp \
  $$SRC_DIR/meshlab_settings/settingdialog.cpp \
  $$SRC_DIR/multiViewer_Container.cpp \
  $$SRC_DIR/plugindialog.cpp \
  $$SRC_DIR/filterScriptDialog.cpp \
  $$SRC_DIR/saveSnapshotDialog.cpp \
  $$SRC_DIR/layerDialog.cpp \
  $$SRC_DIR/savemaskexporter.cpp \
  $$SRC_DIR/changetexturename.cpp \
  $$SRC_DIR/ml_std_par_dialog.cpp \
  $$SRC_DIR/additionalgui.cpp \
  $$SRC_DIR/ml_render_gui.cpp \
  $$SRC_DIR/ml_rendering_actions.cpp \
  $$SRC_DIR/ml_default_decorators.cpp \
  $$VCGDIR/wrap/gui/trackball.cpp \
  $$VCGDIR/wrap/gui/trackmode.cpp \
  $$VCGDIR/wrap/gui/coordinateframe.cpp \
  $$SRC_DIR/glarea_setting.cpp \
  $$SRC_DIR/rich_parameter_gui/richparameterlistdialog.cpp \
  $$SRC_DIR/rich_parameter_gui/richparameterlistframe.cpp \
  $$SRC_DIR/rich_parameter_gui/richparameterwidgets.cpp 

FORMS += \
  $$SRC_DIR/ui/layerDialog.ui \
  $$SRC_DIR/ui/filterScriptDialog.ui \
  $$SRC_DIR/ui/savesnapshotDialog.ui \
  $$SRC_DIR/ui/aboutDialog.ui \
  $$SRC_DIR/ui/renametexture.ui \
  $$SRC_DIR/ui/savemaskexporter.ui \
  $$SRC_DIR/ui/congratsDialog.ui \
  $$SRC_DIR/ui/filtergui.ui


RESOURCES += \
  $$SRC_DIR/meshlab.qrc



