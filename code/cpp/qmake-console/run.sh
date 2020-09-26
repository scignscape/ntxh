#ar=`git rev-parse --show-toplevel`
ar=../../..
qm=`cat $ar/../preferred/preferred-qmake`
qtv=`$qm -query QT_VERSION`
qtv=`echo ${qtv/./-}`
qtv=`echo ${qtv/./-}`
echo $qtv
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./targets/targets-${qtv}-qmake-console ./targets/targets-${qtv}-qmake-console/$1

