if hash git 2>/dev/null; then
  ar=`git rev-parse --show-toplevel`
else
  ar=../../../../../..
fi
`cat $ar/../preferred/preferred-qmake` "QMAKE_CONSOLE_TARGET_DIR=@/code/cpp/qmake-console/targets" $ar/code/cpp/projects/qt/qtm/isobuild/xk/external/IQmol/IQmol-Grid/IQmol-Grid.pro
