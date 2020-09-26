#ar=`git rev-parse --show-toplevel`
ar=../../../../../..
`cat $ar/../preferred/preferred-qmake` "QMAKE_CONSOLE_TARGET_DIR=@/code/cpp/qmake-console/targets" $ar/code/cpp/projects/qt/qtm/isobuild/apk/gtagml/gtagml/gtagml-console/gtagml-console.pro

