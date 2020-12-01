if hash git 2>/dev/null; then
  ar=`git rev-parse --show-toplevel`
else
  ar=../../..
fi
qm=`cat $ar/../preferred/preferred-qmake`
qtv=`$qm -query QT_VERSION`
qtv=`echo ${qtv/./-}`
qtv=`echo ${qtv/./-}`
echo $qtv
cmd=$1
shift
echo ./targets/targets-${qtv}-qmake-console/$cmd
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./targets/targets-${qtv}-qmake-console gdb --args ./targets/targets-${qtv}-qmake-console/$cmd $@
