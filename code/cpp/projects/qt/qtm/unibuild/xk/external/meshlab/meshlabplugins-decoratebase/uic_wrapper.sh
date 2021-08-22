#!/bin/sh
LD_LIBRARY_PATH=/home/nlevisrael/qt514src/qt514-build/qtbase/lib${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}
export LD_LIBRARY_PATH
QT_PLUGIN_PATH=/home/nlevisrael/qt514src/qt514-build/qtbase/plugins${QT_PLUGIN_PATH:+:$QT_PLUGIN_PATH}
export QT_PLUGIN_PATH
exec /home/nlevisrael/qt514src/qt514-build/qtbase/bin/uic "$@"
