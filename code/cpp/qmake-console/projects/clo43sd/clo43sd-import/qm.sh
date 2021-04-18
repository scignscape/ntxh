if hash git 2>/dev/null; then
  ar=`git rev-parse --show-toplevel`
else
  ar=../../../../../..
fi
preferred_qmake=`cat $ar/../preferred/preferred-qmake`
preferred_qmake=${preferred_qmake/\~/$HOME/}
echo $preferred_qmake
$preferred_qmake  "QMAKE_CONSOLE_TARGET_DIR=@/code/cpp/qmake-console/targets" $ar/code/cpp/projects/qt/qtm/isobuild/dbk/dgdb/clo43sd/clo43sd-import/clo43sd-import.pro

